/*
 * File: z_demonsdoor.c
 * Overlay: ovl_DemonsDoor
 * Description: Doors used in the Trial of Courage
 */

#include "z_demonsdoor.h"
#include "assets/objects/object_demonsdoor/object_demonsdoor.h"
#include "overlays/actors/ovl_PowerTrialHandler/z_powertrialhandler.h"

#define FLAGS 0

void DemonsDoor_Init(Actor* thisx, PlayState* play);
void DemonsDoor_Destroy(Actor* thisx, PlayState* play);
void DemonsDoor_Update(Actor* thisx, PlayState* play);
void DemonsDoor_Draw(Actor* thisx, PlayState* play);

void DemonsDoor_DoNothing(DemonsDoor* this, PlayState* play);

static PowerTrialHandler* sPowerTrialHandler = NULL;

ActorInit DemonsDoor_InitVars = {
    ACTOR_DEMONSDOOR,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_DEMONSDOOR,
    sizeof(DemonsDoor),
    DemonsDoor_Init,
    DemonsDoor_Destroy,
    DemonsDoor_Update,
    DemonsDoor_Draw,
};

static InitChainEntry sInitChain[] = {
    ICHAIN_F32(uncullZoneScale, 32767, ICHAIN_STOP),
};

static Vec3f sCloseDoorNext = {73.0f, 109.0f, 715.0f};
static Vec3f sOpenDoorNext = {74.0f, 79.0f, 523.0f};

static Vec3f sOpenDoorLast = {68.0f, 2.0f, -570.0f};
static Vec3f sCloseDoorLast = {68.0f, 204.0f, -570.0f};

void DemonsDoor_Init(Actor* thisx, PlayState* play) {
    DemonsDoor* this = (DemonsDoor*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);

    DynaPolyActor_Init(&this->dyna, 0);
    CollisionHeader_GetVirtual((this->dyna.actor.params == 0x0001 ? &gDemonsDoorLast_collisionHeader : &gDemonsDoorNext_collisionHeader), &colHeader);

    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);

    Actor_SetScale(&this->dyna.actor, 0.1f);

    Math_Vec3f_Copy(&this->dyna.actor.world.pos, (this->dyna.actor.params == 0x0001 ? &sOpenDoorLast : &sOpenDoorNext));

    this->timer = 0;
    this->actionFunc = DemonsDoor_WaitToClose;

}

void DemonsDoor_Destroy(Actor* thisx, PlayState* play) {
    DemonsDoor* this = (DemonsDoor*)thisx;

    DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);

}

void DemonsDoor_Update(Actor* thisx, PlayState* play) {
    DemonsDoor* this = (DemonsDoor*)thisx;

    switch(this->request) {
        case 1:
            this->request = 0;
            this->timer = 0;
            this->actionFunc = DemonsDoor_Open;
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_STONE_STATUE_OPEN);
            break;

        case 2:
            this->request = 0;
            this->timer = 0;
            this->actionFunc = DemonsDoor_Close;
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_STONE_STATUE_OPEN);
            break;

        default:
            break;

    }

    if(this->actionFunc != NULL) this->actionFunc(this, play);

    if(sPowerTrialHandler == NULL) sPowerTrialHandler = (PowerTrialHandler*)Actor_Find(&play->actorCtx, ACTOR_POWERTRIAL_HANDLER, ACTORCAT_MISC);
    else {
        if(sPowerTrialHandler->doorNext == NULL && this->dyna.actor.params == 0x0000) sPowerTrialHandler->doorNext = this;
        if(sPowerTrialHandler->doorLast == NULL && this->dyna.actor.params == 0x0001) sPowerTrialHandler->doorLast = this;

    }

}

void DemonsDoor_WaitToClose(DemonsDoor* this, PlayState* play) {
    if(this->timer >= 20) {
        this->timer = 0;

        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_STONE_STATUE_OPEN);
        this->actionFunc = DemonsDoor_Close;
        return;

    }

    this->timer++;

}

f32 DemonsDoor_FrameLerp(DemonsDoor* this, f32 offset, f32 frames) {
    f32 lerp = ((f32)this->timer - offset) * (1.0f / frames);
    return CLAMP(lerp, 0.0f, 1.0f);

}

f32 DemonsDoor_EaseOutQuad(f32 x) {
    f32 temp = (1.0f - x);
    return 1.0f - temp * temp;

}

void DemonsDoor_Close(DemonsDoor* this, PlayState* play) {
    Vec3f* pos = &this->dyna.actor.world.pos;
    Vec3f* oldPos = (this->dyna.actor.params == 0x0001 ? &sOpenDoorLast : &sOpenDoorNext);
    Vec3f* targetPos = (this->dyna.actor.params == 0x0001 ? &sCloseDoorLast : &sCloseDoorNext);

    this->timer++;

    f32 lerp = DemonsDoor_EaseOutQuad(DemonsDoor_FrameLerp(this, 0.0f, 14.0f));
    pos->x = F32_LERP(oldPos->x, targetPos->x, lerp);
    pos->y = F32_LERP(oldPos->y, targetPos->y, lerp);
    pos->z = F32_LERP(oldPos->z, targetPos->z, lerp);

    if(lerp >= 1.0f) {
        Audio_StopSfxById(NA_SE_EV_STONE_STATUE_OPEN);
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_STONE_BOUND);
        this->actionFunc = DemonsDoor_DoNothing;

    }

}

void DemonsDoor_WaitToOpen(DemonsDoor* this, PlayState* play) {
}

void DemonsDoor_Open(DemonsDoor* this, PlayState* play) {
    Vec3f* pos = &this->dyna.actor.world.pos;
    Vec3f* oldPos = (this->dyna.actor.params == 0x0001 ? &sCloseDoorLast : &sCloseDoorNext);
    Vec3f* targetPos = (this->dyna.actor.params == 0x0001 ? &sOpenDoorLast : &sOpenDoorNext);

    this->timer++;

    f32 lerp = DemonsDoor_FrameLerp(this, 0.0f, 20.0f);
    pos->x = F32_LERP(oldPos->x, targetPos->x, lerp);
    pos->y = F32_LERP(oldPos->y, targetPos->y, lerp);
    pos->z = F32_LERP(oldPos->z, targetPos->z, lerp);

    if(lerp >= 1.0f) {
        Audio_StopSfxById(NA_SE_EV_STONE_STATUE_OPEN);
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_STONE_BOUND);
        this->actionFunc = DemonsDoor_DoNothing;

    }

}

void DemonsDoor_DoNothing(DemonsDoor* this, PlayState* play) {
}

void DemonsDoor_Draw(Actor* thisx, PlayState* play) {
    OPEN_DISPS_AUTO(play);

    Gfx_SetupDL_25Opa(play->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(play->state.gfxCtx, __FILE__, __LINE__),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_OPA_DISP++, (thisx->params == 0x0001 ? gDemonsDoorLast : gDemonsDoorNext));

    CLOSE_DISPS_AUTO(play);

}