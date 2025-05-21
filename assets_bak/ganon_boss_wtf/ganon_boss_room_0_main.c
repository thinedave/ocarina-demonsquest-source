#include "ganon_boss_scene.h"


/**
 * Header Child Day (Default)
*/
#define LENGTH_GANON_BOSS_ROOM_0_HEADER00_OBJECTLIST 9
#define LENGTH_GANON_BOSS_ROOM_0_HEADER00_ACTORLIST 65
SceneCmd ganon_boss_room_0_header00[] = {
    SCENE_CMD_ROOM_SHAPE(&ganon_boss_room_0_shapeHeader),
    SCENE_CMD_ECHO_SETTINGS(7),
    SCENE_CMD_ROOM_BEHAVIOR(0x01, 0x00, false, false),
    SCENE_CMD_SKYBOX_DISABLES(false, false),
    SCENE_CMD_TIME_SETTINGS(255, 255, 127),
    SCENE_CMD_OBJECT_LIST(LENGTH_GANON_BOSS_ROOM_0_HEADER00_OBJECTLIST, ganon_boss_room_0_header00_objectList),
    SCENE_CMD_ACTOR_LIST(LENGTH_GANON_BOSS_ROOM_0_HEADER00_ACTORLIST, ganon_boss_room_0_header00_actorList),
    SCENE_CMD_END(),
};

s16 ganon_boss_room_0_header00_objectList[LENGTH_GANON_BOSS_ROOM_0_HEADER00_OBJECTLIST] = {
    OBJECT_GANON,
    OBJECT_ZL2_ANIME2,
    OBJECT_GANON_ANIME1,
    OBJECT_GANON_ANIME2,
    OBJECT_ZL2,
    OBJECT_WARP1,
    OBJECT_GT,
    OBJECT_TSUBO,
    OBJECT_BDOOR,
};

ActorEntry ganon_boss_room_0_header00_actorList[LENGTH_GANON_BOSS_ROOM_0_HEADER00_ACTORLIST] = {
    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 0, -1000, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0023
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -420, 0, 180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -420, 0, 60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -420, 0, -60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -420, 0, -180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -300, 0, 180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -300, 0, 60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -300, 0, -60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -300, 0, -180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -180, 0, -420 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -180, 0, -300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -180, 0, -180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -180, 0, 180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -180, 0, 300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -180, 0, 420 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -180, 0, -60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -180, 0, 60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -60, 0, -420 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -60, 0, -300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -60, 0, -180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -60, 0, 180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -60, 0, 300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { -60, 0, 420 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 60, 0, -420 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 60, 0, -300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 60, 0, -180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 60, 0, 180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 60, 0, 300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 60, 0, 420 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 180, 0, -420 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 180, 0, -300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 180, 0, -180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 180, 0, 180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 180, 0, 300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 180, 0, 420 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 180, 0, 60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 180, 0, -60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 300, 0, -180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 300, 0, -60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 300, 0, 60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 300, 0, 180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 420, 0, 180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 420, 0, 60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 420, 0, -60 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Floor of Ganondorf's Room
    {
        /* Actor ID   */ ACTOR_BG_GANON_OTYUKA,
        /* Position   */ { 420, 0, -180 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Boss Ganondorf
    {
        /* Actor ID   */ ACTOR_BOSS_GANON,
        /* Position   */ { -5, 0, 2 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0xFFFF
    },

    // Ambient Sound Effects
    {
        /* Actor ID   */ ACTOR_EN_RIVER_SOUND,
        /* Position   */ { -7, 0, -7 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x00F8
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { -422, -720, -258 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x410E
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { -382, -720, -300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x4303
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { -382, -720, -259 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x4B09
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { -342, -720, -341 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x450F
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { -342, -720, -300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x4D09
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { -301, -720, -341 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x4F03
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { -298, -720, -383 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x470F
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { -258, -720, -383 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x513F
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { -257, -720, -424 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x4903
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { 418, -720, -261 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x533F
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { 377, -720, -301 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x5509
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { 338, -720, -340 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x5709
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { 300, -720, -380 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x5903
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { 260, -720, -420 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x5B03
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { 378, -720, -261 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x5D03
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { 337, -720, -300 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x5F3F
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { 299, -720, -340 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x613F
    },

    // Breakable Pot
    {
        /* Actor ID   */ ACTOR_OBJ_TSUBO,
        /* Position   */ { 260, -720, -380 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x6309
    },
};

