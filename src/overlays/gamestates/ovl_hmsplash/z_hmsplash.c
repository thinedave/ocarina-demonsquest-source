#include "global.h"
#include "alloca.h"
#include "assets/textures/hmsplash_static/hmsplash_static.h"

void HMSplash_TextureRGBA32(Gfx** gfxp, s16 centerX, s16 centerY, u8* source, u32 width, u32 height) {
    Gfx* gfx = *gfxp;
    u8* curTexture;
    s32 textureCount;
    u32 rectLeft;
    u32 rectTop;
    u32 textureHeight;
    s32 remainingSize;
    s32 textureSize;
    s32 pad;
    s32 i;

    Gfx_SetupDL_56Ptr(&gfx);

    curTexture = source;
    rectLeft = centerX - (width / 2);
    rectTop = centerY - (height / 2);
    textureHeight = 4096 / (width << 2);
    remainingSize = (width * height) << 2;
    textureSize = (width * textureHeight) << 2;
    textureCount = remainingSize / textureSize;
    if ((remainingSize % textureSize) != 0) {
        textureCount += 1;
    }

    gDPSetTileCustom(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, textureHeight, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                     G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    remainingSize -= textureSize;

    for (i = 0; i < textureCount; i++) {
        gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, curTexture);

        gDPLoadSync(gfx++);
        gDPLoadTile(gfx++, G_TX_LOADTILE, 0, 0, (width - 1) << 2, (textureHeight - 1) << 2);

        gSPTextureRectangle(gfx++, rectLeft << 2, rectTop << 2, (rectLeft + (s32)width) << 2,
                            (rectTop + textureHeight) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

        curTexture += textureSize;
        rectTop += textureHeight;

        if ((remainingSize - textureSize) < 0) {
            if (remainingSize > 0) {
                textureHeight = remainingSize / (s32)(width << 2);
                remainingSize -= textureSize;

                gDPSetTileCustom(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, textureHeight, 0,
                                 G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                 G_TX_NOLOD, G_TX_NOLOD);
            }
        } else {
            remainingSize -= textureSize;
        }
    }

    *gfxp = gfx;
}

void HMSplash_Draw(HMSplashState* this) {
    OPEN_DISPS_AUTO(this);

    gSPSegment(POLY_OPA_DISP++, 0, NULL);
    gSPSegment(POLY_OPA_DISP++, 1, this->staticSegment);
    Gfx_SetupFrame(this->state.gfxCtx, 0, 0, 0);

    Gfx_SetupDL_39Opa(this->state.gfxCtx);
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, this->logoAlpha);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 255, 255, 255);
    HMSplash_TextureRGBA32(&POLY_OPA_DISP, 160, 120, (u8*)gHylianModdingLogoTex, 320, 240);

    CLOSE_DISPS_AUTO(this);

}

void HMSplash_Main(GameState* thisx) {
    HMSplashState* this = (HMSplashState*)thisx;

    this->timer++;

    if(this->timer >= 30 && this->timer <= 50) {
        Math_SmoothStepToS(&this->logoAlpha, 255, 1, 15, 0);

    } else if(this->timer >= 500) {
        Math_SmoothStepToS(&this->logoAlpha, 0, 1, 15, 0);

        if(this->timer >= 570)
            this->exit = true;

    }

    if(this->timer >= 45 && CHECK_BTN_ANY(thisx->input[0].cur.button, BTN_A | BTN_B | BTN_L | BTN_R | BTN_Z | BTN_START | BTN_CUP | BTN_CLEFT | BTN_CRIGHT | BTN_CDOWN | BTN_DUP | BTN_DDOWN | BTN_DLEFT | BTN_DRIGHT))
        this->exit = true;

    OPEN_DISPS_AUTO(this);

    HMSplash_Draw(this);

    if (this->exit) {
        this->state.running = false;
        SET_NEXT_GAMESTATE(&this->state, ConsoleLogo_Init, ConsoleLogoState);

    }

    CLOSE_DISPS_AUTO(this);

}

void HMSplash_Destroy(GameState* thisx) {
    HMSplashState* this = (HMSplashState*)thisx;

}

void HMSplash_Init(GameState* thisx) {
    osSyncPrintf("z_hmsplash.c\n");

    u32 size = (uintptr_t)_hmsplash_staticSegmentRomEnd - (uintptr_t)_hmsplash_staticSegmentRomStart;
    HMSplashState* this = (HMSplashState*)thisx;

    this->staticSegment = GameState_Alloc(&this->state, size, __FILE__, __LINE__);

    ASSERT(this->staticSegment != NULL, "this->staticSegment != NULL", __FILE__, __LINE__);
    DmaMgr_RequestSyncDebug(this->staticSegment, (uintptr_t)_hmsplash_staticSegmentRomStart, size, __FILE__, __LINE__);

    //set fps to 60
    R_UPDATE_RATE = UPDATE_RATE_60;

    //init HMSplash
    this->logoAlpha = 0;
    this->timer = 0;

    //init GameState view
    Matrix_Init(&this->state);
    View_Init(&this->view, this->state.gfxCtx);

    //set GameState functions
    this->state.main = HMSplash_Main;
    this->state.destroy = HMSplash_Destroy;
    this->exit = false;

}