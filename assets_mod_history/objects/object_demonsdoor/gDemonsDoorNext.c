#include "ultra64.h"
#include "global.h"
#include "object_demonsdoor.h"

Vtx gDemonsDoorNext_gDemonsDoorNext_mesh_layer_Opaque_vtx_cull[8] = {
	{{ {-894, -116, -1373}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-894, -116, 692}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-894, 152, 692}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-894, 152, -1373}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {894, -116, -1373}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {894, -116, 692}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {894, 152, 692}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {894, 152, -1373}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx gDemonsDoorNext_gDemonsDoorNext_mesh_layer_Opaque_vtx_0[8] = {
	{{ {-894, -116, -1373}, 0, {987, 814}, {144, 134, 134, 0} }},
	{{ {-894, 40, 681}, 0, {994, 124}, {138, 126, 126, 0} }},
	{{ {894, 152, 681}, 0, {-3, 107}, {138, 126, 126, 0} }},
	{{ {894, -116, -1373}, 0, {-4, 822}, {138, 126, 126, 0} }},
	{{ {-894, -36, 692}, 0, {1044, -139}, {138, 126, 126, 0} }},
	{{ {894, 76, 692}, 0, {-14, 24}, {138, 126, 126, 0} }},
	{{ {894, 152, 681}, 0, {-8, 100}, {138, 126, 126, 0} }},
	{{ {-894, 40, 681}, 0, {1028, -43}, {138, 126, 126, 0} }},
};

Gfx gDemonsDoorNext_gDemonsDoorNext_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(gDemonsDoorNext_gDemonsDoorNext_mesh_layer_Opaque_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Gfx mat_gDemonsDoorNext_f3dlite_material_001_layerOpaque[] = {
	gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_SHADING_SMOOTH),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_ZS_PIXEL | G_RM_FOG_SHADE_A | G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, gDemonsDoorNext_cavepillar_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 51),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, gDemonsDoorNext_cavepillar_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx gDemonsDoorNext[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(gDemonsDoorNext_gDemonsDoorNext_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_gDemonsDoorNext_f3dlite_material_001_layerOpaque),
	gsSPDisplayList(gDemonsDoorNext_gDemonsDoorNext_mesh_layer_Opaque_tri_0),
	gsSPEndDisplayList(),
};

