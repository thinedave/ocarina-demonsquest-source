#include "ganon_boss_scene.h"


RoomShapeNormal ganon_boss_room_0_shapeHeader = {
    ROOM_SHAPE_TYPE_NORMAL,
    ARRAY_COUNT(ganon_boss_room_0_shapeDListsEntry),
    ganon_boss_room_0_shapeDListsEntry,
    ganon_boss_room_0_shapeDListsEntry + ARRAY_COUNT(ganon_boss_room_0_shapeDListsEntry)
};

RoomShapeDListsEntry ganon_boss_room_0_shapeDListsEntry[1] = {
    { ganon_boss_room_0_shapeHeader_entry_0_opaque, NULL }
};

