/*
 * File: z_en_ganon_sword.c
 * Overlay: ovl_En_Ganon_Sword
 * Description: Ganondorf's Thrown Sword
 */

#include "z_en_ganon_sword.h"
#include "assets/objects/object_ganon/object_ganon.h"
#include "overlays/actors/ovl_Boss_Ganon/z_boss_ganon.h"

#define FLAGS (ACTOR_FLAG_4)

void EnGanonSword_Init(Actor* thisx, PlayState* play);
void EnGanonSword_Destroy(Actor* thisx, PlayState* play);
void EnGanonSword_Update(Actor* thisx, PlayState* play);
void EnGanonSword_Draw(Actor* thisx, PlayState* play);

void EnGanonSword_Thrown(EnGanonSword* this, PlayState* play);
void EnGanonSword_Pull(EnGanonSword* this, PlayState* play);

#define BGANON_JNTSPH \
    { \
        ELEMTYPE_UNK0, \
        { 0xFFCFFFFF, 0x00, 15 }, \
        { 0x00000000, 0x00, 0x00 }, \
        TOUCH_ON | TOUCH_SFX_HARD, \
        BUMP_NONE, \
        OCELEM_NONE, \
    }

static ColliderJntSphElementInit sJntSphElementInit[6] = {
    {
        BGANON_JNTSPH,
        {0, {{682, 16, -1733}, 800}, 10},
    },
    
};

static ColliderJntSphInit sJntSphInit = {
    {
        COLTYPE_HIT0,
        AT_ON | AT_TYPE_ENEMY,
        AC_NONE,
        OC1_NONE,
        OC2_NONE,
        COLSHAPE_JNTSPH,
    },
    1,
    sJntSphElementInit,

};

ActorInit En_Ganon_Sword_InitVars = {
    /**/ ACTOR_EN_GANON_SWORD,
    /**/ ACTORCAT_BG,
    /**/ FLAGS,
    /**/ OBJECT_GANON,
    /**/ sizeof(EnGanonSword),
    /**/ EnGanonSword_Init,
    /**/ EnGanonSword_Destroy,
    /**/ EnGanonSword_Update,
    /**/ EnGanonSword_Draw,
};

/*
static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 32767, ICHAIN_STOP),
};
*/

void EnGanonSword_Init(Actor* thisx, PlayState* play) {
    EnGanonSword* this = (EnGanonSword*)thisx;

    //Actor_ProcessInitChain(&this->actor, sInitChain);

    ActorShape_Init(&this->actor.shape, 0.0f, NULL, 0.0f);

    Collider_InitJntSph(play, &this->collider);
    Collider_SetJntSph(play, &this->collider, thisx, &sJntSphInit, this->swordSphs);

    this->actor.shape.rot.z = 0x4000;
    this->swordAT = true;

    this->actionFunc = EnGanonSword_Thrown;

}

void EnGanonSword_Destroy(Actor* thisx, PlayState* play) {
    EnGanonSword* this = (EnGanonSword*)thisx;

    Collider_DestroyJntSph(play, &this->collider);

}

void EnGanonSword_Thrown(EnGanonSword* this, PlayState* play) {
    if(this->actor.parent == NULL) return;

    if(!(this->actor.bgCheckFlags & BGCHECKFLAG_WALL)) {
        if(this->sfxTimer < 5) this->sfxTimer++;
        else if(this->sfxTimer == 5) {
            this->sfxTimer++;
            Actor_PlaySfx(&this->actor, NA_SE_EV_NALE_MAGIC);
            Actor_RequestQuake(play, 10, 20);
            CollisionCheck_SpawnShieldParticlesMetalSfx(play, &this->actor.world.pos, &this->actor.world.pos);
            this->swordAT = false;

        }

        this->actor.speed = 40.0f;
        this->actor.gravity = 0.0f;

        Actor_MoveXZGravity(&this->actor);

    }

    Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, 35.0f, 0.0f, UPDBGCHECKINFO_FLAG_0);

    if(this->actor.bgCheckFlags & BGCHECKFLAG_WALL) this->actor.shape.rot.x = DEG_TO_BINANG(200.0f);
    else this->actor.shape.rot.x += DEG_TO_BINANG(45.0f);

}

void EnGanonSword_Pull(EnGanonSword* this, PlayState* play) {
    if(this->actor.parent == NULL) return;

    BossGanon* ganon = (BossGanon*)this->actor.parent;
    this->actor.world.rot.y = Math_Vec3f_Yaw(&this->actor.world.pos, &ganon->rightHandPos);
    this->actor.world.rot.x = Math_Vec3f_Pitch(&this->actor.world.pos, &ganon->rightHandPos);

    this->actor.speed = 40.0f;
    this->actor.gravity = 0.0f;

    Actor_MoveXYZ(&this->actor);

    this->actor.shape.rot.x -= DEG_TO_BINANG(45.0f);

    if(Math_Vec3f_DistXZ(&this->actor.world.pos, &ganon->rightHandPos) <= 40.0f) {
        ganon->swordCaught = true;
        Actor_Kill(&this->actor);

    }

}

void EnGanonSword_Update(Actor* thisx, PlayState* play) {
    EnGanonSword* this = (EnGanonSword*)thisx;

    if(this->actor.parent != NULL) {
        BossGanon* ganon = (BossGanon*)this->actor.parent;

        if(!this->setY) {
            this->setY = true;
            this->actor.shape.rot.y = ganon->actor.shape.rot.y;

        }

        if(ganon->pullSword) {
            this->swordAT = true;
            this->actionFunc = EnGanonSword_Pull;

        }

    }

    this->actionFunc(this, play);

}

void EnGanonSword_Draw(Actor* thisx, PlayState* play) {
    EnGanonSword* this = (EnGanonSword*)thisx;

    OPEN_DISPS_AUTO(play);
    Gfx_SetupDL_25Opa(play->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(play->state.gfxCtx, __FILE__, __LINE__),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, GanondorfSword);

    if(this->swordAT) {
        Collider_UpdateSpheres(0, &this->collider);
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);

    }
    
    CLOSE_DISPS_AUTO(play);

}
