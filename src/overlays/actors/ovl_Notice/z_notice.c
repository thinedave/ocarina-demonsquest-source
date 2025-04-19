/*
 * File: z_notice.c
 * Overlay: ovl_Notice
 * Description: Notice plaques
 */

#include "z_notice.h"
#include "assets/objects/object_notice/object_notice.h"

#define FLAGS (ACTOR_FLAG_0)

void BgNotice_Init(Actor* thisx, PlayState* play);
void BgNotice_Destroy(Actor* thisx, PlayState* play);
void BgNotice_Update(Actor* thisx, PlayState* play);
void BgNotice_Draw(Actor* thisx, PlayState* play);

void BgNotice_DoNothing(BgNotice* this, PlayState* play);

void BgNotice_SetupFall(BgNotice* this, PlayState* play);
void BgNotice_Fall(BgNotice* this, PlayState* play);

void BgNotice_Wait(BgNotice* this, PlayState* play);

ActorInit Notice_InitVars = {
    ACTOR_NOTICE,
    ACTORCAT_PROP,
    FLAGS,
    OBJECT_NOTICE,
    sizeof(BgNotice),
    BgNotice_Init,
    BgNotice_Destroy,
    BgNotice_Update,
    BgNotice_Draw,
};

void BgNotice_Init(Actor* thisx, PlayState* play) {
    BgNotice* this = (BgNotice*)thisx;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    CollisionHeader_GetVirtual(&gNoticePlaqueDL_collisionHeader, &colHeader);

    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);

    this->dyna.actor.textId = 0xFFFF;

    Actor_SetScale(&this->dyna.actor, 0.1f);
    Actor_SetFocus(&this->dyna.actor, 10.0f);

}

void BgNotice_Destroy(Actor* thisx, PlayState* play) {
    BgNotice* this = (BgNotice*)thisx;

    DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);

}

void BgNotice_NoticeExit(GameState* state, Actor* storedActor) {
    PlayState* play = (PlayState*)state;

    Player_SetCsActionWithHaltedActors(play, storedActor, PLAYER_CSACTION_7);

    storedActor->flags &= ~ACTOR_FLAG_TALK;

}

void BgNotice_Update(Actor* thisx, PlayState* play) {
    BgNotice* this = (BgNotice*)thisx;

    if(this->dyna.actor.flags & ACTOR_FLAG_TALK && !Message_NoticeActive()) {
        Message_SendNotice(&play->state, this->dyna.actor.params, false, BgNotice_NoticeExit, &this->dyna.actor);

    } else {
        Actor_OfferTalk(&this->dyna.actor, play, 55.0f);

    }

}

void BgNotice_Draw(Actor* thisx, PlayState* play) {
    OPEN_DISPS_AUTO(play);

    Gfx_SetupDL_25Opa(play->state.gfxCtx);

    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(play->state.gfxCtx, __FILE__, __LINE__),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(POLY_OPA_DISP++, gNoticePlaqueDL);

    CLOSE_DISPS_AUTO(play);

}