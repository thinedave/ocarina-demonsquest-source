/*
 * File: z_savespot.c
 * Overlay: ovl_Savespot
 * Description: Savespot
 */

#include "z_savespot.h"
#include "assets/objects/object_warp1/object_warp1.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void Savespot_Init(Actor* thisx, PlayState* play);
void Savespot_Destroy(Actor* thisx, PlayState* play);
void Savespot_Update(Actor* thisx, PlayState* play);
void Savespot_Draw(Actor* thisx, PlayState* play);

void Savespot_Nothing(Savespot* this, PlayState* play);
void Savespot_DrawSpot(Savespot* this, PlayState* play);

ActorInit Savespot_InitVars = {
    ACTOR_SAVESPOT,
    ACTORCAT_ITEMACTION,
    FLAGS,
    OBJECT_WARP1,
    sizeof(Savespot),
    (ActorFunc)Savespot_Init,
    (ActorFunc)Savespot_Destroy,
    (ActorFunc)Savespot_Update,
    (ActorFunc)Savespot_Draw,
};

void Savespot_SetupAction(Savespot* this, SavespotActionFunc actionFunc) {
    this->actionFunc = actionFunc;
}

void Savespot_Init(Actor* thisx, PlayState* play) {
    Savespot* this = (Savespot*)thisx;

    this->active = false;
    Savespot_SetupAction(this, Savespot_Nothing);
    this->r = 0;
    this->g = 255;
    this->b = 255;
    this->activationEventTimer = 0;

    if (gSaveContext.save.info.savePoint == this->actor.params) {
        this->active = true;
    }
}

void Savespot_Destroy(Actor* thisx, PlayState* play) {
    Savespot* this = (Savespot*)thisx;
}

void Savespot_Nothing(Savespot* this, PlayState* play) {

}

void ShowSavespot(Savespot* this, PlayState* play) {
    Math_SmoothStepToF(&this->lightRayAlpha, 128.0f, 0.2f, 2.0f, 0.1f);
    Math_SmoothStepToF(&this->warpAlpha, 128.0f, 0.2f, 2.0f, 0.1f);

    if (this->active == true)
    {
        if (this->activationEventTimer < 5) {
            Math_StepToS(&this->r, 255, 100);
            Math_StepToS(&this->g, 255, 100);
            Math_StepToS(&this->b, 255, 100);
            this->activationEventTimer++;
        }
        else {
            Math_StepToS(&this->r, 255, 30);
            Math_StepToS(&this->g, 200, 30);
            Math_StepToS(&this->b, 0, 30);
        }
    }
    else {
        Math_StepToS(&this->r, 0, 20);
        Math_StepToS(&this->g, 255, 20);
        Math_StepToS(&this->b, 255, 20);
    }

    if (this->actor.xyzDistToPlayerSq < 1200.0f) {
        Math_StepToF(&this->unk_194, 0.3f, 0.004f); // length
        Math_StepToF(&this->unk_198, 0.5f, 0.004f);
        Actor_PlaySfx(&this->actor, NA_SE_EV_WARP_HOLE - SFX_FLAG);
    }
    else {
        Math_StepToF(&this->unk_194, 0.1f, 0.008f); // length
        Math_StepToF(&this->unk_198, 0.2f, 0.008f);
    }
}

void Savespot_Update(Actor* thisx, PlayState* play) {
    Savespot* this = (Savespot*)thisx;
    ShowSavespot(this, play);
}

void Savespot_Draw(Actor* thisx, PlayState* play) {
    Savespot* this = (Savespot*)thisx;
    Savespot_DrawSpot(this, play);
}

void Savespot_DrawSpot(Savespot* this, PlayState* play) {
    s32 pad;
    u32 pad1;
    u32 spEC = play->state.frames * 10;
    f32 spE8 = (this->unk_194 >= 1.0f) ? 0.0f : 1.0f - this->unk_194;
    f32 spE4 = (this->unk_198 >= 1.0f) ? 0.0f : 1.0f - this->unk_198;
    f32 xzScale;

    OPEN_DISPS(play->state.gfxCtx, "../z_savespot.c", 2173);

    Gfx_SetupDL_25Xlu(play->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x80, 255, 255, 255, (u8)this->warpAlpha); // prim 1
    gDPSetEnvColor(POLY_XLU_DISP++, this->r, this->g, this->b, 255); // env 1
    gDPSetColorDither(POLY_XLU_DISP++, G_CD_DISABLE);
    gDPSetColorDither(POLY_XLU_DISP++, G_AD_NOTPATTERN | G_CD_MAGICSQ);

    Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y + 1.0f, this->actor.world.pos.z, MTXMODE_NEW);
    gSPSegment(POLY_XLU_DISP++, 0x0A, Matrix_NewMtx(play->state.gfxCtx, "../z_door_warp1.c", 2247));
    Matrix_Push();

    gSPSegment(POLY_XLU_DISP++, 0x08,
        Gfx_TwoTexScroll(play->state.gfxCtx, G_TX_RENDERTILE, spEC & 0xFF,
            -((s16)(this->unk_19C + this->unk_19C) & 511), 0x100, 0x100, 1, spEC & 0xFF,
            -((s16)(this->unk_19C + this->unk_19C) & 511), 0x100, 0x100));

    Matrix_Translate(0.0f, this->unk_194 * 230.0f, 0.0f, MTXMODE_APPLY);
    xzScale = (((f32)this->unk_1AE * spE8) / 100.0f) + 1.0f;
    Matrix_Scale(xzScale, 1.0f, xzScale, MTXMODE_APPLY);
    gSPSegment(POLY_XLU_DISP++, 0x09, Matrix_NewMtx(play->state.gfxCtx, "../z_door_warp1.c", 2267));
    gSPDisplayList(POLY_XLU_DISP++, gWarpPortalDL);
    Matrix_Pop();

    if (this->lightRayAlpha > 0.0f) {
        gDPSetPrimColor(POLY_XLU_DISP++, 0x00, 0x80, 255, 255, 255, (u8)this->lightRayAlpha); // prim 2
        gDPSetEnvColor(POLY_XLU_DISP++, this->r, this->g, this->b, 255); // env 2
        spEC *= 2;

        gSPSegment(POLY_XLU_DISP++, 0x08,
            Gfx_TwoTexScroll(play->state.gfxCtx, G_TX_RENDERTILE, spEC & 0xFF, -((s16)this->unk_19C & 511),
                0x100, 0x100, 1, spEC & 0xFF, -((s16)this->unk_19C & 511), 0x100, 0x100));

        Matrix_Translate(0.0f, this->unk_198 * 60.0f, 0.0f, MTXMODE_APPLY);

        xzScale = (((f32)this->unk_1B0 * spE4) / 100.0f) + 1.0f;
        Matrix_Scale(xzScale, 1.0f, xzScale, MTXMODE_APPLY);

        gSPSegment(POLY_XLU_DISP++, 0x09, Matrix_NewMtx(play->state.gfxCtx, "../z_door_warp1.c", 2336));
        gSPDisplayList(POLY_XLU_DISP++, gWarpPortalDL);
    }

    CLOSE_DISPS(play->state.gfxCtx, "../z_savespot.c", 2340);
}