#include "powertrial_scene.h"


RoomShapeNormal powertrial_room_0_shapeHeader = {
    ROOM_SHAPE_TYPE_NORMAL,
    ARRAY_COUNT(powertrial_room_0_shapeDListsEntry),
    powertrial_room_0_shapeDListsEntry,
    powertrial_room_0_shapeDListsEntry + ARRAY_COUNT(powertrial_room_0_shapeDListsEntry)
};

RoomShapeDListsEntry powertrial_room_0_shapeDListsEntry[1] = {
    { powertrial_room_0_shapeHeader_entry_0_opaque, powertrial_room_0_shapeHeader_entry_0_transparent }
};

