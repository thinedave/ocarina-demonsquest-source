#include "global.h"

// Linker symbol declarations (used in the table below)
#define DEFINE_GAMESTATE(typeName, enumName, name) DECLARE_OVERLAY_SEGMENT(name)
#define DEFINE_GAMESTATE_INTERNAL(typeName, enumName)

#include "tables/gamestate_table.h"

#undef DEFINE_GAMESTATE
#undef DEFINE_GAMESTATE_INTERNAL

// Gamestate Overlay Table definition
#define DEFINE_GAMESTATE_INTERNAL(typeName, enumName) \
    { NULL, 0, 0, NULL, NULL, NULL, typeName##_Init, typeName##_Destroy, NULL, NULL, 0, sizeof(typeName##State) },

#define DEFINE_GAMESTATE(typeName, enumName, name) \
    { NULL,                                        \
      (uintptr_t)_ovl_##name##SegmentRomStart,     \
      (uintptr_t)_ovl_##name##SegmentRomEnd,       \
      _ovl_##name##SegmentStart,                   \
      _ovl_##name##SegmentEnd,                     \
      NULL,                                        \
      typeName##_Init,                             \
      typeName##_Destroy,                          \
      NULL,                                        \
      NULL,                                        \
      0,                                           \
      sizeof(typeName##State) },

GameStateOverlay gGameStateOverlayTable[] = {
<<<<<<< HEAD
    GAMESTATE_OVERLAY_INTERNAL(Setup_Init, Setup_Destroy, sizeof(SetupState)),
    GAMESTATE_OVERLAY(select, MapSelect_Init, MapSelect_Destroy, sizeof(MapSelectState)),
    GAMESTATE_OVERLAY(title, ConsoleLogo_Init, ConsoleLogo_Destroy, sizeof(ConsoleLogoState)),
    GAMESTATE_OVERLAY_INTERNAL(Play_Init, Play_Destroy, sizeof(PlayState)),
    GAMESTATE_OVERLAY(opening, TitleSetup_Init, TitleSetup_Destroy, sizeof(TitleSetupState)),
    GAMESTATE_OVERLAY(file_choose, FileSelect_Init, FileSelect_Destroy, sizeof(FileSelectState)),
    GAMESTATE_OVERLAY(hmsplash, HMSplash_Init, HMSplash_Destroy, sizeof(HMSplashState)),
=======
#include "tables/gamestate_table.h"
>>>>>>> 0ce03133425867723dd81fc66f57bbb8d40aaf7a
};

#undef DEFINE_GAMESTATE
#undef DEFINE_GAMESTATE_INTERNAL
