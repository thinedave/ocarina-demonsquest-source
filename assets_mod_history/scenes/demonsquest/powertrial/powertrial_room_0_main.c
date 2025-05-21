#include "powertrial_scene.h"


/**
 * Header Child Day (Default)
*/
#define LENGTH_POWERTRIAL_ROOM_0_HEADER00_OBJECTLIST 1
#define LENGTH_POWERTRIAL_ROOM_0_HEADER00_ACTORLIST 3
#define COURAGETRIAL_OBJECT_ENTRY_MAGIC 213
SceneCmd powertrial_room_0_header00[] = {
    SCENE_CMD_ROOM_SHAPE(&powertrial_room_0_shapeHeader),
    SCENE_CMD_ECHO_SETTINGS(0x00),
    SCENE_CMD_ROOM_BEHAVIOR(0x01, 0x00, false, false),
    SCENE_CMD_SKYBOX_DISABLES(true, true),
    SCENE_CMD_TIME_SETTINGS(255, 255, 0),
    SCENE_CMD_OBJECT_LIST(COURAGETRIAL_OBJECT_ENTRY_MAGIC, powertrial_room_0_header00_objectList),
    SCENE_CMD_ACTOR_LIST(LENGTH_POWERTRIAL_ROOM_0_HEADER00_ACTORLIST, powertrial_room_0_header00_actorList),
    SCENE_CMD_END(),
};

s16 powertrial_room_0_header00_objectList[LENGTH_POWERTRIAL_ROOM_0_HEADER00_OBJECTLIST] = {
    OBJECT_HUMAN,
};

ActorEntry powertrial_room_0_header00_actorList[LENGTH_POWERTRIAL_ROOM_0_HEADER00_ACTORLIST] = {
    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DEMONSDOOR,
        /* Position   */ { 73, 109, 715 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_DEMONSDOOR,
        /* Position   */ { 68, 204, -570 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0001
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_POWERTRIAL_HANDLER,
        /* Position   */ { 0, 100, 0 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0000
    },
};

