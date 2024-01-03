#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "savetest_scene.h"
#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

/**
 * Header Child Day (Default)
*/
SceneCmd savetest_scene_header00[] = {
    SCENE_CMD_SOUND_SETTINGS(0x00, 0x00, 0x2E),
    SCENE_CMD_ROOM_LIST(1, savetest_scene_roomList),
    SCENE_CMD_MISC_SETTINGS(0x00, 0x00),
    SCENE_CMD_COL_HEADER(&savetest_collisionHeader),
    SCENE_CMD_SPECIAL_FILES(0x00, OBJECT_GAMEPLAY_FIELD_KEEP),
    SCENE_CMD_SKYBOX_SETTINGS(0x01, 0x00, LIGHT_MODE_TIME),
    SCENE_CMD_ENTRANCE_LIST(savetest_scene_header00_entranceList),
    SCENE_CMD_SPAWN_LIST(1, savetest_scene_header00_playerEntryList),
    SCENE_CMD_ENV_LIGHT_SETTINGS(4, savetest_scene_header00_lightSettings),
    SCENE_CMD_END(),
};

RomFile savetest_scene_roomList[] = {
    { (u32)_savetest_room_0SegmentRomStart, (u32)_savetest_room_0SegmentRomEnd },
};

ActorEntry savetest_scene_header00_playerEntryList[] = {
    {
        /* Actor ID   */ ACTOR_PLAYER,
        /* Position   */ { 82, 10, 11 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0FFF
    },
};

Spawn savetest_scene_header00_entranceList[] = {
    // { Spawn Actor List Index, Room Index }
    { 0, 0 },
};

EnvLightSettings savetest_scene_header00_lightSettings[4] = {
    // Custom No. 1 Lighting
    {
        {    70,    45,    57 },   // Ambient Color
        {    73,    73,    73 },   // Diffuse0 Direction
        {   180,   154,   138 },   // Diffuse0 Color
        {   -73,   -73,   -73 },   // Diffuse1 Direction
        {    79,    79,   133 },   // Diffuse1 Color
        {   140,   120,   100 },   // Fog Color
        ((1 << 10) | 993),         // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
    // Custom No. 2 Lighting
    {
        {   105,    90,    90 },   // Ambient Color
        {    73,    73,    73 },   // Diffuse0 Direction
        {   255,   255,   240 },   // Diffuse0 Color
        {   -73,   -73,   -73 },   // Diffuse1 Direction
        {    79,    79,   133 },   // Diffuse1 Color
        {   100,   100,   120 },   // Fog Color
        ((1 << 10) | 996),         // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
    // Custom No. 3 Lighting
    {
        {   120,    90,     0 },   // Ambient Color
        {    73,    73,    73 },   // Diffuse0 Direction
        {   250,   135,    50 },   // Diffuse0 Color
        {   -73,   -73,   -73 },   // Diffuse1 Direction
        {    79,    79,   133 },   // Diffuse1 Color
        {   120,    70,    50 },   // Fog Color
        ((1 << 10) | 995),         // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
    // Custom No. 4 Lighting
    {
        {    40,    70,   100 },   // Ambient Color
        {    73,    73,    73 },   // Diffuse0 Direction
        {    20,    20,    35 },   // Diffuse0 Color
        {   -73,   -73,   -73 },   // Diffuse1 Direction
        {    79,    79,   133 },   // Diffuse1 Color
        {     0,     0,    30 },   // Fog Color
        ((1 << 10) | 992),         // Blend Rate & Fog Near
        12800,                     // Fog Far
    },
};

Vec3s savetest_camPosData[3] = {
	{ 0, 0, 0 },
	{ 4223, 655, 0 },
	{ 3960, -1, -1 },
};

BgCamInfo savetest_camData[1] = {
	{ CAM_SET_NORMAL0, 3, &savetest_camPosData[0] },
};

SurfaceType savetest_polygonTypes[] = {
	{ 0x00000000, 0x00000000 },
};

CollisionPoly savetest_polygons[] = {
	{ 0x0000, 0x0000, 0x0001, 0x0002, COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(-1.9714923382707639e-07), 0x0000 },
	{ 0x0000, 0x0000, 0x0002, 0x0003, COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(-1.9714923382707639e-07), 0x0000 },
};

Vec3s savetest_vertices[4] = {
	{ -300, 0, 300 },
	{ 300, 0, 300 },
	{ 300, 0, -300 },
	{ -300, 0, -300 },
};

CollisionHeader savetest_collisionHeader = {
	-300,
	0,
	-300,
	300,
	0,
	300,
	4,
	savetest_vertices,
	2,
	savetest_polygons,
	savetest_polygonTypes,
	savetest_camData,
	0,
	0
};

