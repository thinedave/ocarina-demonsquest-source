/*
 * File: z_xpdrop.c
 * Overlay: ovl_XPDrops
 * Description: Environmental Effects
 */

#include "z_xpdrop.h"
#include "assets/objects/object_demo_kekkai/object_demo_kekkai.h"
#include "assets/objects/gameplay_keep/gameplay_keep.h"
#include "assets/objects/object_spot02_objects/object_spot02_objects.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5 | ACTOR_FLAG_25)

void XPDrop_Init(Actor* thisx, PlayState* play);
void XPDrop_Destroy(Actor* thisx, PlayState* play);
void XPDrop_Update(Actor* thisx, PlayState* play);
void XPDrop_Draw(Actor* thisx, PlayState* play);

void XPDrop_SetupAction(XPDrop* this, XPDropActionFunc action);
void XPDrop_Effect(XPDrop* this, PlayState* play);

void XPDrop_DrawEffect(Actor* thisx, PlayState* play2);

ActorInit XPDrop_InitVars = {
    /**/ ACTOR_XPDROP,
    /**/ ACTORCAT_ITEMACTION,
    /**/ FLAGS,
    /**/ OBJECT_GAMEPLAY_KEEP,
    /**/ sizeof(XPDrop),
    /**/ XPDrop_Init,
    /**/ XPDrop_Destroy,
    /**/ XPDrop_Update,
    /**/ XPDrop_Draw,
};

void XPDrop_SetupAction(XPDrop* this, XPDropActionFunc action) {
    this->actionFunc = action;
}

void XPDrop_Init(Actor* thisx, PlayState* play) {
    XPDrop* this = (XPDrop*)thisx;

    osSyncPrintf("INIT XPDROP\n");

    this->activeEffects = 0;

    for (s16 i = 0; i < ARRAY_COUNT(this->effects); i++) {
        this->effects[i].state = 0;

    }

    this->state = 0;
    this->timer = 0;
    XPDrop_SetupAction(this, XPDrop_Effect);

}

void XPDrop_Destroy(Actor* thisx, PlayState* play) {
    Audio_StopSfxById(NA_SE_EV_NAVY_FLY);
    Actor_Kill(thisx);
}

void XPDrop_Effect_State0(XPDrop* this, PlayState* play) {
    this->timer = 0;
    this->state = 1;

    Audio_PlaySfxTransposed(&GET_PLAYER(play)->actor.world.pos, NA_SE_EV_NAVY_FLY, -7);

}

void XPDrop_TimerAddEffects(XPDrop* this) {
    if(this->activeEffects >= 64) return;

    this->timer++;

    if(this->timer >= 1) {
        this->timer = 0;
        this->effects[this->activeEffects].state = 1;
        this->activeEffects++;

    }

}

f32 XPDrop_EaseInQuad(f32 num) {
    return num * num;

}

void XPDrop_HandleEffects(XPDrop* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    for (u8 i = 0; i < this->activeEffects; i++) {
        XPDropEffect* effect = &this->effects[i];

        switch (effect->state) {
            case 0: // this should never happen and if it does we're all screwed
                break;
            case 1: // init
                effect->base.x = this->actor.world.pos.x;
                effect->base.y = this->actor.world.pos.y;
                effect->base.z = this->actor.world.pos.z;
                effect->initBase.x = this->actor.world.pos.x;
                effect->initBase.y = this->actor.world.pos.y;
                effect->initBase.z = this->actor.world.pos.z;

                effect->pos.x = 0.0f;
                effect->pos.y = 0.0f;
                effect->pos.z = 0.0f;
                effect->targetSpeed = Rand_ZeroOne() * 30.6f + 10.5f;
                effect->alpha = 0;
                effect->alphaTimer = Rand_ZeroOne() * 65535.0f;
                effect->size = 0.2f;
                effect->dirPhase.x = Rand_ZeroOne() * 180.0f;
                effect->dirPhase.y = Rand_ZeroOne() * 180.0f;
                effect->dirPhase.z = Rand_ZeroOne() * 180.0f;
                effect->state++;
                effect->timer = 0;
                break;

            case 2: // blinking fairies / inactive fairy trails
                if (Rand_ZeroOne() < 0.5f) {
                    effect->angleVel = (s16)(Rand_ZeroOne() * 200.0f) + 200;
                } else {
                    effect->angleVel = -((s16)(Rand_ZeroOne() * 200.0f) + 200);
                }

                effect->flightRadius = (s16)(Rand_ZeroOne() * 10.0f) + 30;

                // uniformly scales the length and height of the wave that the lead fairy flies in
                // lower numbers have a larger amplitude and period
                effect->amplitude = (Rand_ZeroOne() * 4.0f + 4.0f) * 0.01f;

                f32 random = Rand_ZeroOne();
                if (random < 0.2f) {
                    this->trailingFairies = 1;
                } else if (random < 0.2f) {
                    // unreachable
                    this->trailingFairies = 3;
                } else if (random < 0.4f) {
                    this->trailingFairies = 7;
                } else {
                    this->trailingFairies = 15;
                }

                if ((i & this->trailingFairies) == 0) {
                    effect->pos.y = 0.0f;
                }

                effect->state = 3;
                effect->targetSpeed = 0.0f;

                Math_SmoothStepToF(&effect->size, 0.0f, 0.50f, 0.001f, 0.00001f);
                Math_SmoothStepToF(&effect->speed, effect->targetSpeed, 0.5f, 0.2f, 0.02f);

                effect->pos.x += sinf(effect->dirPhase.x) * effect->speed;
                effect->pos.y += sinf(effect->dirPhase.y) * effect->speed;
                effect->pos.z += sinf(effect->dirPhase.z) * effect->speed;

                switch ((i >> 1) & 3) {
                    case 0:
                        effect->dirPhase.x += 0.008f;
                        effect->dirPhase.y += 0.05f * Rand_ZeroOne();
                        effect->dirPhase.z += 0.015f;
                        break;

                    case 1:
                        effect->dirPhase.x += 0.01f * Rand_ZeroOne();
                        effect->dirPhase.y += 0.05f * Rand_ZeroOne();
                        effect->dirPhase.z += 0.005f * Rand_ZeroOne();
                        break;

                    case 2:
                        effect->dirPhase.x += 0.01f * Rand_ZeroOne();
                        effect->dirPhase.y += 0.4f * Rand_ZeroOne();
                        effect->dirPhase.z += 0.004f * Rand_ZeroOne();
                        break;

                    case 3:
                        effect->dirPhase.x += 0.01 * Rand_ZeroOne();
                        effect->dirPhase.y += 0.08f * Rand_ZeroOne();
                        effect->dirPhase.z += 0.05f * Rand_ZeroOne();
                        break;

                    default:
                        break;
                }

                break;
            case 3: // fairy trails
                effect->alphaTimer++;
                effect->prevPos.x = effect->base.x;
                effect->prevPos.y = effect->base.y;
                effect->prevPos.z = effect->base.z;

                effect->timer++;
                f32 frac = CLAMP(XPDrop_EaseInQuad((f32)(effect->timer)/25.0f), 0.0f, 1.0f);

                Math_SmoothStepToF(&effect->size, 0.25f, 0.1f, 0.001f, 0.00001f);

                effect->base.x = F32_LERP(effect->initBase.x, player->actor.world.pos.x, frac);
                effect->base.y = F32_LERP(effect->initBase.y, player->actor.world.pos.y + (LINK_IS_ADULT ? 50.0f : 25.0f), frac);
                effect->base.z = F32_LERP(effect->initBase.z, player->actor.world.pos.z, frac);
                //Math_SmoothStepToF(&effect->base.x, player->actor.world.pos.x, 0.5f, 2.5f, 3.5f);
                //Math_SmoothStepToF(&effect->base.y, player->actor.world.pos.y + 50.0f, 0.5f, 1.0f, 2.5f);
                //Math_SmoothStepToF(&effect->base.z, player->actor.world.pos.z, 0.5f, 2.5f, 3.5f);

                // results unused
                /*Math_SmoothStepToF(&effect->pos.x,
                                   Math_SinS(effect->angle - 0x8000) * effect->flightRadius,
                                   0.5f, 2.0f, 0.2f);
                Math_SmoothStepToF(&effect->pos.z,
                                   Math_CosS(effect->angle - 0x8000) * effect->flightRadius,
                                   0.5f, 2.0f, 0.2f);*/

                // the lead fairy's y position approximately follows a sine wave with `amplitude` as angular
                // frequency and `1 / amplitude` as amplitude
                effect->angle += effect->angleVel;
                effect->pos.x = F32_LERP(effect->pos.x + (sinf(effect->dirPhase.x) * 1.75f), 0.0f, frac);
                effect->pos.y = F32_LERP(effect->pos.y + (sinf(effect->dirPhase.y) * 1.75f), 0.0f, frac);
                effect->pos.z = F32_LERP(effect->pos.z + (sinf(effect->dirPhase.z) * 1.75f), 0.0f, frac);

                effect->dirPhase.x += 0.6f * Rand_ZeroOne();
                effect->dirPhase.y += effect->amplitude;
                effect->dirPhase.z += 0.35f * Rand_ZeroOne();

                /*// circle around the player
                effect->pos.x =
                    Math_SinS(effect->angle - 0x8000) * effect->flightRadius;
                effect->pos.z =
                    Math_CosS(effect->angle - 0x8000) * effect->flightRadius;*/

                if(frac >= 1) {
                    effect->timer = 0;
                    effect->state++;

                }

                break;

            case 4:
                break;

            default:
                break;

        }

    }

}

void XPDrop_Effect_State1(XPDrop* this, PlayState* play) {
    XPDrop_HandleEffects(this, play);
    XPDrop_TimerAddEffects(this);

}

void XPDrop_Effect(XPDrop* this, PlayState* play) {
    switch(this->state) {
        case 0:
            XPDrop_Effect_State0(this, play);
            break;
        case 1:
            XPDrop_Effect_State1(this, play);
            break;

    }

}

void XPDrop_Update(Actor* thisx, PlayState* play) {
    XPDrop* this = (XPDrop*)thisx;

    this->actionFunc(this, play);

    Player* player = GET_PLAYER(play);

    //osSyncPrintf("xDist: %.2f, yDist: %.2f, zDist: %.2f\n", xDist, yDist, zDist);

    if(this->effects[63].state == 4) {
        Audio_StopSfxById(NA_SE_EV_NAVY_FLY);
        Audio_PlaySfxTransposed(&player->actor.world.pos, NA_SE_EV_NAVY_VANISH, -16);
        Actor_Kill(&this->actor);

    }

}

void XPDrop_Draw(Actor* thisx, PlayState* play) {
    XPDrop_DrawEffect(thisx, play);

}

void XPDrop_DrawEffect(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    XPDrop* this = (XPDrop*)thisx;
    f32 alphaScale;
    Vec3f vec1 = { 0.0f, 0.0f, 0.0f };
    Vec3f vec2 = { 0.0f, 0.0f, 0.0f };
    s16 i;

    OPEN_DISPS_AUTO(play);
    POLY_XLU_DISP = Gfx_SetupDL(POLY_XLU_DISP, SETUPDL_20);
    gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(gSun1Tex));
    gSPDisplayList(POLY_XLU_DISP++, gKokiriDustMoteMaterialDL);

    for (i = 0; i < this->activeEffects; i++) {
        XPDropEffect* effect = &this->effects[i];
        if(effect->state == 0 || effect->state == 4) continue;

        Matrix_Translate(effect->base.x + effect->pos.x,
                         effect->base.y + effect->pos.y,
                         effect->base.z + effect->pos.z, MTXMODE_NEW);

        // scale when fading in or out
        alphaScale = effect->alpha / 50.0f;
        if (alphaScale > 1.0f) {
            alphaScale = 1.0f;
        }

        Matrix_Scale(effect->size * alphaScale, effect->size * alphaScale,
                     effect->size * alphaScale, MTXMODE_APPLY);
        if (i < 32) {
            if (effect->state != 2) {
                if (effect->alpha > 0) {
                    effect->alpha--;
                }
            } else {
                if (effect->alpha < 100) {
                    effect->alpha++;
                }
            }
        } else {
            if (effect->state != 2) {
                if ((effect->alphaTimer & 0x1F) < 16) {
                    if (effect->alpha < 235) {
                        effect->alpha += 20;
                    }
                } else {
                    if (effect->alpha > 20) {
                        effect->alpha -= 20;
                    }
                }
            } else {
                // unreachable
                if ((effect->alphaTimer & 0xF) < 8) {
                    if (effect->alpha < 255) {
                        effect->alpha += 100;
                    }
                } else {
                    if (effect->alpha > 10) {
                        effect->alpha -= 10;
                    }
                }
            }
        }

        gDPPipeSync(POLY_XLU_DISP++);

        switch (i & 1) {
            case 0:
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 155, effect->alpha);
                gDPSetEnvColor(POLY_XLU_DISP++, 180, 180, 180, effect->alpha);
                break;

            case 1:
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, effect->alpha);
                gDPSetEnvColor(POLY_XLU_DISP++, 100, 100, 100, effect->alpha);
                break;
        }

        Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
        Matrix_RotateZ(DEG_TO_RAD(play->state.frames * 20.0f), MTXMODE_APPLY);
        gSPMatrix(POLY_XLU_DISP++, Matrix_NewMtx(play->state.gfxCtx, __FILE__, __LINE__), G_MTX_LOAD);
        gSPDisplayList(POLY_XLU_DISP++, gKokiriDustMoteModelDL);
    }

    CLOSE_DISPS_AUTO(play);

}

