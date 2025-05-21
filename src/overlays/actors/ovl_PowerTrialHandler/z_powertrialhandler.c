/*
 * File: z_powertrialhandler.c
 * Overlay: ovl_PowerTrialHandler
 * Description: General handler for the Trial of Courage
 */

#include "z_powertrialhandler.h"
#include "overlays/actors/ovl_DemonsDoor/z_demonsdoor.h"
#include "overlays/actors/ovl_En_Am/z_en_am.h"
#include "overlays/actors/ovl_En_Firefly/z_en_firefly.h"
#include "overlays/actors/ovl_En_Tite/z_en_tite.h"
#include "overlays/actors/ovl_En_Poh/z_en_poh.h"
#include "overlays/actors/ovl_En_Ik/z_en_ik.h"
#include "overlays/actors/ovl_En_Bb/z_en_bb.h"

#define FLAGS 0

void PowerTrialHandler_Init(Actor* thisx, PlayState* play);
void PowerTrialHandler_Destroy(Actor* thisx, PlayState* play);
void PowerTrialHandler_Update(Actor* thisx, PlayState* play);
void PowerTrialHandler_Draw(Actor* thisx, PlayState* play);

typedef struct {
    ActorID id;
    Vec3f pos;
    Vec3s rot;
    s16 params;
} PowerTrialActorEntry;

typedef struct {
    u8 length;
    PowerTrialActorEntry entries[16];
} PowerTrialActorEntryList;

static PowerTrialActorEntryList sPowerTrialLevels[] = {
    {
        1,
        {
            {ACTOR_SAVESPOT, {70.0f, 105.0f, 0.0f}, {0x0000, 0x0000, 0xFFFF}, 0x001D},
        }
    },
    {
        7,
        {
            {ACTOR_EN_DEKUNUTS, {294.0f, 96.0f, 248.0f}, {0x0000, 0x93EE, 0x0000}, 0x0000},
            {ACTOR_EN_DEKUNUTS, {-165.0f, 99.0f, 181.0f}, {0x0000, 0x713A, 0x0000}, 0x0000},
            {ACTOR_EN_DEKUNUTS, {-98.0f, 103.0f, 421.0f}, {0x0000, 0x60CC, 0x0000}, 0x0000},
            {ACTOR_EN_DEKUBABA, {344.0f, 105.0f, -33.0f}, {0x0000, 0xB57D, 0x0000}, 0x0000},
            {ACTOR_EN_DEKUBABA, {-183.0f, 105.0f, -140.0f}, {0x0000, 0x521E, 0x0000}, 0x0000},
            {ACTOR_EN_DEKUBABA, {-33.0f, 105.0f, -92.0f}, {0x0000, 0x81E2, 0x0000}, 0x0000},
            {ACTOR_EN_DEKUBABA, {102.0f, 104.0f, -41.0f}, {0x0000, 0x81E2, 0x0000}, 0x0000},
        }
    },
    {
        8,
        {
            {ACTOR_EN_DODONGO, {264.0f, 104.0f, 82.0f}, {0x0000, 0x93AB, 0x0000}, 0x0000},
            {ACTOR_EN_DODONGO, {77.0f, 105.0f, 20.0f}, {0x0000, 0x812E, 0x0000}, 0x0000},
            {ACTOR_EN_DODONGO, {-107.0f, 106.0f, -46.0f}, {0x0000, 0x664B, 0x0000}, 0x0000},
            {ACTOR_EN_DODONGO, {-169.0f, 97.0f, 241.0f}, {0x0000, 0x83D7, 0x0000}, 0x0000},
            {ACTOR_EN_DODONGO, {234.0f, 101.0f, 289.0f}, {0x0000, 0x83D7, 0x0000}, 0x0000},
            {ACTOR_EN_VM, {70.0f, 104.0f, 84.0f}, {0x0000, 0x7FB5, 0x0000}, 0x0F00},
            {ACTOR_EN_AM, {190.0f, 99.0f, 515.0f}, {0x0000, 0x8C25, 0x0000}, ARMOS_ENEMY},
            {ACTOR_EN_AM, {-23.0f, 101.0f, 502.0f}, {0x0000, 0x8C25, 0x0000}, ARMOS_ENEMY},
        }
    },
    {
        8,
        {
            {ACTOR_EN_SKB, {314.0f, 100.0f, 219.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_SKB, {74.0f, 105.0f, 222.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_SKB, {-147.0f, 97.0f, 295.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_SKB, {248.0f, 100.0f, 151.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_SKB, {-97.0f, 103.0f, 153.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_SKB, {-192.0f, 105.0f, -37.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_SKB, {312.0f, 105.0f, -34.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_SKB, {69.0f, 103.0f, -124.0f}, {0x0000, 0x8000, 0x0000}, 0x0005},
        }
    },
    {
        13,
        {
            {ACTOR_EN_BILI, {-142.0f, 217.0f, -187.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_BILI, {227.0f, 217.0f, -180.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_BILI, {70.0f, 217.0f, -70.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_BILI, {-190.0f, 217.0f, 178.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_BILI, {289.0f, 217.0f, -183.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_BILI, {70.0f, 217.0f, 262.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_TITE, {290.0f, 105.0f, 205.0f}, {0x0000, 0x8000, 0x0000}, TEKTITE_BLUE},
            {ACTOR_EN_TITE, {71.0f, 99.0f, 205.0f}, {0x0000, 0x8000, 0x0000}, TEKTITE_BLUE},
            {ACTOR_EN_TITE, {-154.0f, 105.0f, 243.0f}, {0x0000, 0x8000, 0x0000}, TEKTITE_BLUE},
            {ACTOR_EN_TITE, {83.0f, 105.0f, 43.0f}, {0x0000, 0x8000, 0x0000}, TEKTITE_BLUE},
            {ACTOR_EN_TITE, {343.0f, 98.0f, -262.0f}, {0x0000, 0x8000, 0x0000}, TEKTITE_BLUE},
            {ACTOR_EN_TITE, {-162.0f, 102.0f, -330.0f}, {0x0000, 0x8000, 0x0000}, TEKTITE_BLUE},
            {ACTOR_EN_TITE, {70.0f, 101.0f, -229.0f}, {0x0000, 0x8000, 0x0000}, TEKTITE_BLUE},
        }
    },
    {
        12,
        {
            {ACTOR_EN_RD, {293.0f, 105.0f, -77.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_RD, {-243.0f, 105.0f, -65.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_RD, {-194.0f, 98.0f, 250.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_RD, {224.0f, 100.0f, 243.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_RD, {222.0f, 105.0f, -77.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_RD, {-60.0f, 103.0f, -91.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_RD, {147.0f, 105.0f, 217.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_RD, {-8.0f, 105.0f, 222.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_RD, {-244.0f, 101.0f, -350.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_RD, {281.0f, 101.0f, -316.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
            {ACTOR_EN_TEST, {-27.0f, 105.0f, 33.0f}, {0x0000, 0x8000, 0x0000}, 0x0005},
            {ACTOR_EN_TEST, {137.0f, 105.0f, 31.0f}, {0x0000, 0x8000, 0x0000}, 0x0005},
        }
    },
    {
        7,
        {
            {ACTOR_EN_WF, {-81.0f, 105.0f, -133.0f}, {0x0000, 0x8000, 0x0000}, 0xFF01},
            {ACTOR_EN_WF, {175.0f, 105.0f, -126.0f}, {0x0000, 0x8000, 0x0000}, 0xFF01},
            {ACTOR_EN_WF, {276.0f, 105.0f, -18.0f}, {0x0000, 0x8000, 0x0000}, 0xFF01},
            {ACTOR_EN_WF, {-173.0f, 106.0f, -18.0f}, {0x0000, 0x8000, 0x0000}, 0xFF01},
            {ACTOR_EN_FIREFLY, {307.0f, 217.0f, -230.0f}, {0x0000, 0x8000, 0x0000}, KEESE_ICE_FLY},
            {ACTOR_EN_FIREFLY, {69.0f, 217.0f, -164.0f}, {0x0000, 0x8000, 0x0000}, KEESE_ICE_FLY},
            {ACTOR_EN_FIREFLY, {-211.0f, 217.0f, -232.0f}, {0x0000, 0x8000, 0x0000}, KEESE_ICE_FLY},
        }
    },
    {
        1,
        {
            {ACTOR_EN_FD, {70.0f, 104.0f, 0.0f}, {0x0000, 0x8000, 0x0000}, 0x0000},
        }
    },
    {
        7,
        {
            {ACTOR_EN_DHA, {298, 101, -153}, {0, 0x8000, 0}, 0xFFFF},
            {ACTOR_EN_DHA, {-196, 105, -156}, {0, 0x8000, 0}, 0xFFFF},
            {ACTOR_EN_DHA, {-131, 104, 53}, {0, 0x8000, 0}, 0xFFFF},
            {ACTOR_EN_DHA, {227, 105, 70}, {0, 0x8000, 0}, 0xFFFF},
            {ACTOR_EN_DHA, {339, 98, 237}, {0, 0x8000, 0}, 0xFFFF},
            {ACTOR_EN_DHA, {-169, 99, 237}, {0, 0x8000, 0}, 0xFFFF},
            {ACTOR_EN_DH,  {70, 105, 60}, {0, 0x8000, 0}, 0xFFFF},
        }
    },
    {
        7,
        {
            {ACTOR_EN_POH, {-159, 120, -194}, {0, 0x8000, 0}, EN_POH_NORMAL},
            {ACTOR_EN_POH, {241, 120, -194}, {0, 0x8000, 0}, EN_POH_NORMAL},
            {ACTOR_EN_POH, {-64, 120, 60}, {0, 0x8000, 0}, EN_POH_NORMAL},
            {ACTOR_EN_POH, {224, 120, 60}, {0, 0x8000, 0}, EN_POH_NORMAL},
            {ACTOR_EN_POH, {-192, 120, 280}, {0, 0x8000, 0}, EN_POH_NORMAL},
            {ACTOR_EN_POH, {319, 120, 280}, {0, 0x8000, 0}, EN_POH_NORMAL},
            {ACTOR_EN_POH,  {70, 120, 412}, {0, 0x8000, 0}, EN_POH_NORMAL},
        }
    },
    {
        4,
        {
            {ACTOR_EN_IK, {10, 105, -194}, {0, 0x8000, 0}, 0xFF01},
            {ACTOR_EN_IK, {136, 105, -194}, {0, 0x8000, 0}, 0xFF01},
            {ACTOR_EN_BB, {-175, 120, -207}, {0, 0x8000, 0}, ENBB_BLUE},
            {ACTOR_EN_BB, {261, 120, -207}, {0, 0x8000, 0}, ENBB_BLUE},
        }
    },
};

ActorInit PowerTrialHandler_InitVars = {
    ACTOR_POWERTRIAL_HANDLER,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(PowerTrialHandler),
    PowerTrialHandler_Init,
    PowerTrialHandler_Destroy,
    PowerTrialHandler_Update,
    PowerTrialHandler_Draw,
};

static f32 sTalkerVol = 1.0f;
static f32 sTalkerFreq = 0.4f;

void PowerTrialHandler_Init(Actor* thisx, PlayState* play) {
    PowerTrialHandler* this = (PowerTrialHandler*)thisx;

    this->state = 0;
    this->timer = 0;
    sTalkerVol = 1.0f;

    osSyncPrintf("gSaveContext.courageTrialLevel = %i\n", gSaveContext.courageTrialLevel);

    if(gSaveContext.courageTrialLevel == 0) {
        PowerTrialActorEntryList actorEntries = sPowerTrialLevels[0];
        for(u8 i = 0; i < actorEntries.length; i++) {
            Actor_Spawn(&play->actorCtx, play, actorEntries.entries[i].id, actorEntries.entries[i].pos.x, actorEntries.entries[i].pos.y, actorEntries.entries[i].pos.z, actorEntries.entries[i].rot.x, actorEntries.entries[i].rot.y, actorEntries.entries[i].rot.z, actorEntries.entries[i].params)->xpValue = 0;
        
        }
    }

}

void PowerTrialHandler_Destroy(Actor* thisx, PlayState* play) {
}

void PowerTrialHandler_HandleEntrance(PowerTrialHandler* this, Player* player, PlayState* play) {
    switch(this->state) {
        case 0:
            if(player->actor.world.pos.z >= -324.0f) {
                this->state = 1;
                this->timer = 0;
                Message_StartTextbox(play, (gSaveContext.save.info.playerData.isDoubleDefenseAcquired ? 0x71B7 : 0x71B5), NULL);
                Player_SetCsAction(play, &this->actor, PLAYER_CSACTION_57);
                
                Audio_PlaySfxGeneral(NA_SE_EV_SPIRIT_STONE, &gSfxDefaultPos, 4, &sTalkerFreq, &sTalkerVol, &gSfxDefaultReverb);

            }

            break;

        case 1:
            if(Message_GetState(&play->msgCtx) == TEXT_STATE_NONE) {
                this->state = 2;
                Player_SetCsAction(play, &this->actor, PLAYER_CSACTION_7);

                this->doorLast->request = 1;
                this->doorNext->request = 1;

            }

            break;

        case 2:
            if(Math_StepToF(&sTalkerVol, 0.0f, 0.005f)) {
                Audio_StopSfxById(NA_SE_EV_SPIRIT_STONE);
                this->state = 3;

            }

            break;

    }

}

void PowerTrialHandler_HandleLevels(PowerTrialHandler* this, Player* player, PlayState* play) {
    switch(this->state) {
        case 0:
            this->timer++;
            if(this->timer >= 0) {
                this->state = 1;

                Flags_UnsetTempClear(play, this->actor.room);

                PowerTrialActorEntryList actorEntries = sPowerTrialLevels[gSaveContext.courageTrialLevel];
                for(u8 i = 0; i < actorEntries.length; i++) {
                    Actor_Spawn(&play->actorCtx, play, actorEntries.entries[i].id, actorEntries.entries[i].pos.x, actorEntries.entries[i].pos.y, actorEntries.entries[i].pos.z, actorEntries.entries[i].rot.x, actorEntries.entries[i].rot.y, actorEntries.entries[i].rot.z, actorEntries.entries[i].params)->xpValue = 0;

                }

            }

            break;

        case 1:
            if(Flags_GetTempClear(play, this->actor.room)) {
                this->doorLast->request = 1;
                this->doorNext->request = 1;

                if(gSaveContext.courageTrialLevel == 10) {
                    Message_StartTextbox(play, 0x71B6, NULL);
                    Player_SetCsAction(play, &this->actor, PLAYER_CSACTION_57);
                    
                    Audio_PlaySfxGeneral(NA_SE_EV_SPIRIT_STONE, &gSfxDefaultPos, 4, &sTalkerFreq, &sTalkerVol, &gSfxDefaultReverb);

                    this->state = 3;

                } else this->state = 2;

            }

            break;

        case 2: break;
        case 3:
            if(Message_GetState(&play->msgCtx) == TEXT_STATE_NONE) {
                this->state = 4;
                Player_SetCsAction(play, &this->actor, PLAYER_CSACTION_7);

            }

            break;

        case 4:
            if(Math_StepToF(&sTalkerVol, 0.0f, 0.005f)) {
                Audio_StopSfxById(NA_SE_EV_SPIRIT_STONE);
                this->state = 5;

            }

            break;

    }

}

void PowerTrialHandler_Update(Actor* thisx, PlayState* play) {
    PowerTrialHandler* this = (PowerTrialHandler*)thisx;
    Player* player = GET_PLAYER(play);
    
    switch(gSaveContext.courageTrialLevel) {
        case 0:
            PowerTrialHandler_HandleEntrance(this, player, play);
            break;

        default:
            PowerTrialHandler_HandleLevels(this, player, play);
            break;

    }

}

void PowerTrialHandler_Draw(Actor* thisx, PlayState* play) {
}