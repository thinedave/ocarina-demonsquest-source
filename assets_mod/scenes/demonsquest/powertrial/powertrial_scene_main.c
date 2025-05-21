#include "powertrial_scene.h"


/**
 * Header Child Day (Default)
*/
SceneCmd powertrial_scene_header00[] = {
    SCENE_CMD_COL_HEADER(&powertrial_scene_collisionHeader),
    SCENE_CMD_ROOM_LIST(1, powertrial_scene_roomList),
    SCENE_CMD_SOUND_SETTINGS(0x00, 0x13, NA_BGM_INSIDE_DEKU_TREE),
    SCENE_CMD_MISC_SETTINGS(0x00, 0x0F),
    SCENE_CMD_SPECIAL_FILES(0x00, OBJECT_GAMEPLAY_DANGEON_KEEP),
    SCENE_CMD_SKYBOX_SETTINGS(0x00, 0x00, LIGHT_MODE_SETTINGS),
    SCENE_CMD_ENV_LIGHT_SETTINGS(1, powertrial_scene_header00_lightSettings),
    SCENE_CMD_ENTRANCE_LIST(powertrial_scene_header00_entranceList),
    SCENE_CMD_SPAWN_LIST(1, powertrial_scene_header00_playerEntryList),
    SCENE_CMD_EXIT_LIST(powertrial_scene_header00_exitList),
    SCENE_CMD_END(),
};

RomFile powertrial_scene_roomList[] = {
    { (uintptr_t)_powertrial_room_0SegmentRomStart, (uintptr_t)_powertrial_room_0SegmentRomEnd },
};

ActorEntry powertrial_scene_header00_playerEntryList[] = {
    // Link / Spawn point
    {
        /* Actor ID   */ ACTOR_PLAYER,
        /* Position   */ { 68, 93, -541 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0FFF
    },
};

Spawn powertrial_scene_header00_entranceList[] = {
    // { Spawn Actor List Index, Room Index }
    { 0, 0 },
};

u16 powertrial_scene_header00_exitList[2] = {
    ENTR_POWERTRIAL_0,
    ENTR_HYRULE_CASTLE_2,
};

EnvLightSettings powertrial_scene_header00_lightSettings[1] = {
    // Indoor No. 1 Lighting
    {
        {    74,    60,    53 },   // Ambient Color
        {    73,   -73,    73 },   // Diffuse0 Direction
        {   170,   158,   151 },   // Diffuse0 Color
        {   -73,    73,   -73 },   // Diffuse1 Direction
        {    83,    65,    70 },   // Diffuse1 Color
        {   196,   182,   175 },   // Fog Color
        ((1 << 10) | 1023),        // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
};

