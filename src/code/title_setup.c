#include "global.h"

typedef enum {
    NORMAL,
    MAP_SELECT,
    KNUCKLE_DEMO,

} StartupMode;

const StartupMode STARTUP_MODE = MAP_SELECT;

void Setup_InitImpl(SetupState* this) {
    osSyncPrintf("ゼルダ共通データ初期化\n"); // "Zelda common data initalization"
    SaveContext_Init();

    switch(STARTUP_MODE) {
        case NORMAL:
            this->state.running = false;
            SET_NEXT_GAMESTATE(&this->state, ConsoleLogo_Init, ConsoleLogoState);
            break;
        
        case MAP_SELECT:
            this->state.running = false;
            gSaveContext.linkAge = LINK_AGE_ADULT;
            Sram_InitDebugSave();
            gSaveContext.dayTime = CLOCK_TIME(12, 0);
            gSaveContext.entranceIndex = ENTR_HYRULE_FIELD_0;
            gSaveContext.respawnFlag = 0;
            gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex = ENTR_LOAD_OPENING;
            gSaveContext.gameMode = GAMEMODE_NORMAL;
            SET_NEXT_GAMESTATE(&this->state, MapSelect_Init, MapSelectState);
            break;

        case KNUCKLE_DEMO:
            Sram_InitDebugSave();

            gSaveContext.linkAge = LINK_AGE_ADULT;
            gSaveContext.dayTime = CLOCK_TIME(12, 0);
            gSaveContext.entranceIndex = ENTR_SPIRIT_TEMPLE_BOSS_0;

            gSaveContext.respawnFlag = 0;
            gSaveContext.respawn[RESPAWN_MODE_DOWN].entranceIndex = ENTR_LOAD_OPENING;

            // Have the magic meter load correctly
            gSaveContext.magicFillTarget = gSaveContext.magic;
            gSaveContext.magicCapacity = 0;
            gSaveContext.magic = 0;
            gSaveContext.magicLevel = 0;

            gSaveContext.saveRespawnPoint.entranceIndex = ENTR_SPIRIT_TEMPLE_BOSS_0;
            //gSaveContext.saveRespawnPoint.roomIndex = play->roomCtx.curRoom.num;

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
