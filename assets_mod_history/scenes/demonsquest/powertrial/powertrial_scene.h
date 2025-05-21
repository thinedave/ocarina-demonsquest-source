#ifndef POWERTRIAL_SCENE_H
#define POWERTRIAL_SCENE_H

#include "ultra64.h"
#include "macros.h"
#include "z64.h"


extern SceneCmd powertrial_scene_header00[];
extern RomFile powertrial_scene_roomList[];
extern u8 _powertrial_room_0SegmentRomStart[];
extern u8 _powertrial_room_0SegmentRomEnd[];
extern ActorEntry powertrial_scene_header00_playerEntryList[];
extern Spawn powertrial_scene_header00_entranceList[];
extern u16 powertrial_scene_header00_exitList[2];
extern EnvLightSettings powertrial_scene_header00_lightSettings[1];
extern CollisionHeader powertrial_scene_collisionHeader;
extern SurfaceType powertrial_scene_polygonTypes[3];
extern Vec3s powertrial_scene_vertices[554];
extern CollisionPoly powertrial_scene_polygons[855];
extern SceneCmd powertrial_room_0_header00[];
extern s16 powertrial_room_0_header00_objectList[];
extern ActorEntry powertrial_room_0_header00_actorList[];
extern Gfx powertrial_room_0_shapeHeader_entry_0_opaque[];
extern Gfx powertrial_room_0_shapeHeader_entry_0_transparent[];
extern u64 powertrial_room_0_dl_cavepillar_ci8[];
extern u64 powertrial_room_0_dl_cavepillar_pal_rgba16[];
extern u64 powertrial_room_0_dl_caverocky_ci8[];
extern u64 powertrial_room_0_dl_caverocky_pal_rgba16[];
extern u64 powertrial_room_0_dl_cavegrass_ci8[];
extern u64 powertrial_room_0_dl_cavegrass_pal_rgba16[];
extern u64 powertrial_room_0_dl_cavewater_ci8[];
extern u64 powertrial_room_0_dl_cavewater_x_cavewater_pal_rgba16[];
extern u64 powertrial_room_0_dl_cavewater_ci8_copy[];
extern Vtx powertrial_room_0_dl_room_mesh_layer_Opaque_vtx_cull[8];
extern Vtx powertrial_room_0_dl_room_mesh_layer_Opaque_vtx_0[1388];
extern Gfx powertrial_room_0_dl_room_mesh_layer_Opaque_tri_0[];
extern Vtx powertrial_room_0_dl_room_mesh_layer_Opaque_vtx_1[222];
extern Gfx powertrial_room_0_dl_room_mesh_layer_Opaque_tri_1[];
extern Vtx powertrial_room_0_dl_room_mesh_layer_Opaque_vtx_2[151];
extern Gfx powertrial_room_0_dl_room_mesh_layer_Opaque_tri_2[];
extern Vtx powertrial_room_0_dl_room_mesh_layer_Transparent_vtx_cull[8];
extern Vtx powertrial_room_0_dl_room_mesh_layer_Transparent_vtx_0[14];
extern Gfx powertrial_room_0_dl_room_mesh_layer_Transparent_tri_0[];
extern Gfx mat_powertrial_room_0_dl_f3dlite_material_087_layerOpaque[];
extern Gfx mat_powertrial_room_0_dl_f3dlite_material_084_layerOpaque[];
extern Gfx mat_powertrial_room_0_dl_f3dlite_material_085_layerOpaque[];
extern Gfx mat_powertrial_room_0_dl_f3dlite_material_layerTransparent[];
extern Gfx powertrial_room_0_dl_room_mesh_layer_Opaque[];
extern Gfx powertrial_room_0_dl_room_mesh_layer_Transparent[];
extern RoomShapeNormal powertrial_room_0_shapeHeader;
extern RoomShapeDListsEntry powertrial_room_0_shapeDListsEntry[1];

#endif
