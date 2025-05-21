#include "ganon_boss_scene.h"


/**
 * Header Child Day (Default)
*/
SceneCmd ganon_boss_scene_header00[] = {
    SCENE_CMD_COL_HEADER(&ganon_boss_scene_collisionHeader),
    SCENE_CMD_ROOM_LIST(1, ganon_boss_scene_roomList),
    SCENE_CMD_SOUND_SETTINGS(6, 0x13, 46),
    SCENE_CMD_MISC_SETTINGS(0x00, 0x15),
    SCENE_CMD_SPECIAL_FILES(NAVI_QUEST_HINTS_DUNGEON, OBJECT_INVALID),
    SCENE_CMD_SKYBOX_SETTINGS(0x1D, 0x00, false),
    SCENE_CMD_ENV_LIGHT_SETTINGS(17, ganon_boss_scene_header00_lightSettings),
    SCENE_CMD_TRANSITION_ACTOR_LIST(1, ganon_boss_scene_header00_transitionActors),
    SCENE_CMD_ENTRANCE_LIST(ganon_boss_scene_header00_entranceList),
    SCENE_CMD_SPAWN_LIST(1, ganon_boss_scene_header00_playerEntryList),
    SCENE_CMD_EXIT_LIST(ganon_boss_scene_header00_exitList),
    SCENE_CMD_END(),
};

RomFile ganon_boss_scene_roomList[] = {
    { (uintptr_t)_ganon_boss_room_0SegmentRomStart, (uintptr_t)_ganon_boss_room_0SegmentRomEnd },
};

ActorEntry ganon_boss_scene_header00_playerEntryList[] = {
    // Link / Spawn point
    {
        /* Actor ID   */ ACTOR_PLAYER,
        /* Position   */ { -13, 0, 92 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(180.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0DFF
    },
};

Spawn ganon_boss_scene_header00_entranceList[] = {
    // { Spawn Actor List Index, Room Index }
    { 0, 0 },
};

TransitionActorEntry ganon_boss_scene_header00_transitionActors[] = {
    // Lifting Wooden Door
    {
        /* Room & Cam Index (Front, Back) */ { 0, 255, 0, 255 },
        /* Actor ID                       */ ACTOR_DOOR_SHUTTER,
        /* Position                       */ { 0, 0, 500 },
        /* Rotation Y                     */ DEG_TO_BINANG(0.000),
        /* Parameters                     */ 0x0154
    },
};

u16 ganon_boss_scene_header00_exitList[2] = {
    ENTR_GANONS_TOWER_2,
    ENTR_DEKU_TREE_0,
};

EnvLightSettings ganon_boss_scene_header00_lightSettings[17] = {
    // Custom No. 1 Lighting
    {
        {    30,    20,     0 },   // Ambient Color
        {    73,   -73,    73 },   // Diffuse0 Direction
        {   255,   205,    50 },   // Diffuse0 Color
        {   -73,    73,   -73 },   // Diffuse1 Direction
        {    50,     0,     0 },   // Diffuse1 Color
        {   210,   110,    10 },   // Fog Color
        ((1 << 10) | 980),         // Blend Rate & Fog Near
        4000,                      // Fog Far
    },
    // Custom No. 2 Lighting
    {
        {     0,    10,     0 },   // Ambient Color
        {     0,   120,    40 },   // Diffuse0 Direction
        {   255,   255,   255 },   // Diffuse0 Color
        {   -42,   112,   -42 },   // Diffuse1 Direction
        {   255,   255,   255 },   // Diffuse1 Color
        {     0,    10,     0 },   // Fog Color
        ((1 << 10) | 985),         // Blend Rate & Fog Near
        1300,                      // Fog Far
    },
    // Custom No. 3 Lighting
    {
        {     0,     0,     0 },   // Ambient Color
        {    42,   112,    42 },   // Diffuse0 Direction
        {   255,   255,   255 },   // Diffuse0 Color
        {   -42,   112,   -42 },   // Diffuse1 Direction
        {   123,     0,   178 },   // Diffuse1 Color
        {   255,   255,   255 },   // Fog Color
        ((1 << 10) | 980),         // Blend Rate & Fog Near
        1300,                      // Fog Far
    },
    // Custom No. 4 Lighting
    {
        {    65,    30,     0 },   // Ambient Color
        {   117,    48,     0 },   // Diffuse0 Direction
        {   255,   225,    60 },   // Diffuse0 Color
        {   116,    47,   -15 },   // Diffuse1 Direction
        {   255,   225,    60 },   // Diffuse1 Color
        {   210,   110,    10 },   // Fog Color
        ((1 << 10) | 910),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 5 Lighting
    {
        {    65,    30,     0 },   // Ambient Color
        {    77,   -85,    53 },   // Diffuse0 Direction
        {   255,   225,    60 },   // Diffuse0 Color
        {    82,    68,   -68 },   // Diffuse1 Direction
        {   255,   225,    60 },   // Diffuse1 Color
        {   210,   110,    10 },   // Fog Color
        ((1 << 10) | 910),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 6 Lighting
    {
        {     0,     0,     0 },   // Ambient Color
        {     0,  -101,   -76 },   // Diffuse0 Direction
        {   155,   155,   105 },   // Diffuse0 Color
        {    12,  -124,   -24 },   // Diffuse1 Direction
        {   155,   155,    55 },   // Diffuse1 Color
        {    56,    25,     0 },   // Fog Color
        ((1 << 10) | 900),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 7 Lighting
    {
        {     0,     0,     0 },   // Ambient Color
        {   -35,   -35,  -116 },   // Diffuse0 Direction
        {   255,   255,   255 },   // Diffuse0 Color
        {   -35,   -35,  -116 },   // Diffuse1 Direction
        {   255,   255,   255 },   // Diffuse1 Color
        {   255,   210,   100 },   // Fog Color
        ((1 << 10) | 880),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 8 Lighting
    {
        {    30,    30,     0 },   // Ambient Color
        {    22,   -88,    88 },   // Diffuse0 Direction
        {    55,   205,   205 },   // Diffuse0 Color
        {    73,   -73,    73 },   // Diffuse1 Direction
        {    55,   255,   255 },   // Diffuse1 Color
        {     0,    10,     5 },   // Fog Color
        ((1 << 10) | 750),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 9 Lighting
    {
        {   150,    90,    50 },   // Ambient Color
        {    59,    59,    95 },   // Diffuse0 Direction
        {   255,   255,   255 },   // Diffuse0 Color
        {    42,   -84,    84 },   // Diffuse1 Direction
        {   255,   255,   255 },   // Diffuse1 Color
        {   255,   210,   100 },   // Fog Color
        ((1 << 10) | 620),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 10 Lighting
    {
        {     0,     0,     0 },   // Ambient Color
        {  -117,     0,    47 },   // Diffuse0 Direction
        {   155,   255,   255 },   // Diffuse0 Color
        {  -108,     0,    65 },   // Diffuse1 Direction
        {    55,   255,   255 },   // Diffuse1 Color
        {     0,    15,     3 },   // Fog Color
        ((1 << 10) | 790),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 11 Lighting
    {
        {    50,    50,    50 },   // Ambient Color
        {  -108,     0,    65 },   // Diffuse0 Direction
        {   255,   255,   255 },   // Diffuse0 Color
        {   -99,     0,    79 },   // Diffuse1 Direction
        {   255,   255,   255 },   // Diffuse1 Color
        {   255,   210,   100 },   // Fog Color
        ((1 << 10) | 890),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 12 Lighting
    {
        {   140,     0,    80 },   // Ambient Color
        {    73,   -73,    73 },   // Diffuse0 Direction
        {     0,     0,     0 },   // Diffuse0 Color
        {   -73,    73,   -73 },   // Diffuse1 Direction
        {     0,     0,     0 },   // Diffuse1 Color
        {     0,     5,     0 },   // Fog Color
        ((1 << 10) | 960),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 13 Lighting
    {
        {    60,     0,   100 },   // Ambient Color
        {    73,   -73,    73 },   // Diffuse0 Direction
        {     0,     0,     0 },   // Diffuse0 Color
        {   -73,    73,   -73 },   // Diffuse1 Direction
        {     0,     0,     0 },   // Diffuse1 Color
        {     0,     5,     0 },   // Fog Color
        ((1 << 10) | 920),         // Blend Rate & Fog Near
        1700,                      // Fog Far
    },
    // Custom No. 14 Lighting
    {
        {    20,    20,    20 },   // Ambient Color
        {    97,   -70,    40 },   // Diffuse0 Direction
        {    55,   255,   225 },   // Diffuse0 Color
        {     0,   -43,  -119 },   // Diffuse1 Direction
        {   100,   255,   225 },   // Diffuse1 Color
        {     0,    15,     0 },   // Fog Color
        ((1 << 10) | 910),         // Blend Rate & Fog Near
        4000,                      // Fog Far
    },
    // Custom No. 15 Lighting
    {
        {    20,    20,    20 },   // Ambient Color
        {    80,   -92,    33 },   // Diffuse0 Direction
        {    55,   255,   225 },   // Diffuse0 Color
        {    80,   -92,   -33 },   // Diffuse1 Direction
        {   100,   255,   225 },   // Diffuse1 Color
        {     0,    15,     0 },   // Fog Color
        ((1 << 10) | 910),         // Blend Rate & Fog Near
        4000,                      // Fog Far
    },
    // Custom No. 16 Lighting
    {
        {    60,    60,    10 },   // Ambient Color
        {     0,  -123,   -30 },   // Diffuse0 Direction
        {   255,   205,    50 },   // Diffuse0 Color
        {     0,  -123,   -30 },   // Diffuse1 Direction
        {   255,   205,    50 },   // Diffuse1 Color
        {   255,   240,   130 },   // Fog Color
        ((1 << 10) | 970),         // Blend Rate & Fog Near
        4000,                      // Fog Far
    },
    // Custom No. 17 Lighting
    {
        {    60,    60,    10 },   // Ambient Color
        {     0,  -123,   -30 },   // Diffuse0 Direction
        {   255,   205,    50 },   // Diffuse0 Color
        {     0,  -123,   -30 },   // Diffuse1 Direction
        {   255,   205,    50 },   // Diffuse1 Color
        {   255,   240,   130 },   // Fog Color
        ((1 << 10) | 850),         // Blend Rate & Fog Near
        4000,                      // Fog Far
    },
};

