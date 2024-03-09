#include "global.h"
//#include "overlays/gamestates/ovl_hmsplash/z_hmsplash.c"

typedef enum {
    NORMAL,
    MAP_SELECT,
    KNUCKLE_DEMO,

} StartupMode;

const StartupMode STARTUP_MODE = MAP_SELECT;

void Setup_InitImpl(SetupState* this) {
    osSyncPrintf("Zelda common data initalization\n"); // "Zelda common data initalization"

    if(osMemSize <= 0x400000) {
        this->state.running = false;
        SET_NEXT_GAMESTATE(&this->state, MemPakNotice_Init, MemPakNoticeState);
        return;

    }

    SaveContext_Init();

    switch(STARTUP_MODE) {
        case NORMAL:
            this->state.running = false;
            osSyncPrintf("ATTEMPTING LOAD SPLASH\n");
            SET_NEXT_GAMESTATE(&this->state, HMSplash_Init, HMSplashState);
            break;
        
        case MAP_SELECT:
            this->state.running = false;
            gSaveContext.save.linkAge = LINK_AGE_ADULT;
            Sram_InitDebugSave();
            gSaveContext.save.dayTime = CLOCK_TIME(12, 0);
            gSaveContext.save.entranceIndex = ENTR_HYRULE_FIELD_0;
            gSaveContext.respawnFlag = 0;
            gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex = ENTR_LOAD_OPENING;
            gSaveContext.gameMode = GAMEMODE_NORMAL;
            SET_NEXT_GAMESTATE(&this->state, MapSelect_Init, MapSelectState);
            break;

        case KNUCKLE_DEMO:
            Sram_InitDebugSave();

            gSaveContext.save.linkAge = LINK_AGE_ADULT;
            gSaveContext.save.dayTime = CLOCK_TIME(12, 0);
            gSaveContext.save.entranceIndex = ENTR_SPIRIT_TEMPLE_BOSS_0;

            gSaveContext.respawnFlag = 0;
            gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex = ENTR_LOAD_OPENING;

            // Have the magic meter load correctly
            gSaveContext.magicFillTarget = gSaveContext.save.info.playerData.magic;
            gSaveContext.magicCapacity = 0;
            gSaveContext.save.info.playerData.magic = 0;
            gSaveContext.save.info.playerData.magicLevel = 0;

            gSaveContext.save.info.saveRespawnPoint.entranceIndex = ENTR_SPIRIT_TEMPLE_BOSS_0;
            //gSaveContext.save.info.saveRespawnPoint.roomIndex = play->roomCtx.curRoom.num;

            // Load Play state
            gSaveContext.gameMode = GAMEMODE_NORMAL;
            this->state.running = false;
            SET_NEXT_GAMESTATE(&this->state, Play_Init, PlayState);
            break;

    }

}

/* vanilla
void Setup_InitImpl(SetupState* this) {
    osSyncPrintf("ゼルダ共通データ初期化\n"); // "Zelda common data initalization"
    SaveContext_Init();
    this->state.running = false;
    SET_NEXT_GAMESTATE(&this->state, ConsoleLogo_Init, ConsoleLogoState);
}
*/

void Setup_Destroy(GameState* thisx) {
}

void Setup_Init(GameState* thisx) {
    SetupState* this = (SetupState*)thisx;

    this->state.destroy = Setup_Destroy;
    Setup_InitImpl(this);
}
