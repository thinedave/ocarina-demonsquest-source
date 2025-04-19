#include "global.h"
#include "assets/textures/mempak_static/mempak_static.h"

void MemPakNotice_TextureRGBA32(Gfx** gfxp, s16 centerX, s16 centerY, u8* source, u32 width, u32 height) {
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

void MemPakNotice_Draw(GameState* thisx) {
    MemPakNoticeState* this = (MemPakNoticeState*)thisx;

    OPEN_DISPS_AUTO(this);

    gSPSegment(POLY_OPA_DISP++, 0, NULL);
    gSPSegment(POLY_OPA_DISP++, 1, this->staticSegment);
    Gfx_SetupFrame(this->state.gfxCtx, 0, 0, 0);

    Gfx_SetupDL_39Opa(this->state.gfxCtx);
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 255, 255, 255);
    MemPakNotice_TextureRGBA32(&POLY_OPA_DISP, 160, 120, (u8*)gMemPakNoticeTex, 320, 240);

    CLOSE_DISPS_AUTO(this);

}

void MemPakNotice_Main(GameState* thisx) {
    MemPakNotice_Draw(thisx);

}

void MemPakNotice_Destroy(GameState* thisx) {
    MemPakNoticeState* this = (MemPakNoticeState*)thisx;

}
void MemPakNotice_Init(GameState* thisx) {
    MemPakNoticeState* this = (MemPakNoticeState*)thisx;

    osSyncPrintf("z_mempak.c\n");

    u32 size = (uintptr_t)_mempak_staticSegmentRomEnd - (uintptr_t)_mempak_staticSegmentRomStart;
    this->staticSegment = GameState_Alloc(&this->state, size, __FILE__, __LINE__);

    ASSERT(this->staticSegment != NULL, "this->staticSegment != NULL", __FILE__, __LINE__);
    DmaMgr_RequestSyncDebug(this->staticSegment, (uintptr_t)_mempak_staticSegmentRomStart, size, __FILE__, __LINE__);

    //set fps to 60
    R_UPDATE_RATE = UPDATE_RATE_60;

    //init GameState view
    Matrix_Init(&this->state);
    View_Init(&this->view, this->state.gfxCtx);

    //set GameState functions
    this->state.main = MemPakNotice_Main;
    this->state.destroy = MemPakNotice_Destroy;
    this->exit = false;

    Audio_PlaySfxGeneral(NA_SE_SY_DD_ERROR, &gSfxDefaultPos, 4,
        &gSfxDefaultFreqAndVolScale, &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);

}

//NA_SE_EV_FIVE_COUNT_LUPY