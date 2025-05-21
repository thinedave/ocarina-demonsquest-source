#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "object_demonsdoor.h"

CollisionHeader gDemonsDoorLast_collisionHeader = {
    { -910, -1238, -51 },
    { 910, 619, 26 },
    ARRAY_COUNT(gDemonsDoorLast_vertices), gDemonsDoorLast_vertices,
    ARRAY_COUNT(gDemonsDoorLast_polygons), gDemonsDoorLast_polygons,
    gDemonsDoorLast_polygonTypes,
    NULL,
    0, NULL
};

SurfaceType gDemonsDoorLast_polygonTypes[1] = {
    { SURFACETYPE0(0, 0, 0x00, 0, 0x00, 0x00, 0, 0), SURFACETYPE1(0x00, 0x00, 0, 0, 0, 0, 0, 0) },
};

Vec3s gDemonsDoorLast_vertices[6] = {
    {    910,  -1238,     26 },
    {    910,    619,     26 },
    {   -910,    619,     26 },
    {   -910,  -1238,     26 },
    {    910,    619,    -51 },
    {   -910,    619,    -51 },
};

CollisionPoly gDemonsDoorLast_polygons[4] = {
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(1, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(2), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(4.333967140723871e-08), COLPOLY_SNORMAL(1.0) }, 65510 },
    { 0, COLPOLY_VTX(0, COLPOLY_IGNORE_NONE), COLPOLY_VTX(2, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(3), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(4.333967140723871e-08), COLPOLY_SNORMAL(1.0) }, 65510 },
    { 0, COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX(5, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(2), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(0.0) }, 64917 },
    { 0, COLPOLY_VTX(4, COLPOLY_IGNORE_NONE), COLPOLY_VTX(2, COLPOLY_IGNORE_NONE), COLPOLY_VTX_INDEX(1), { COLPOLY_SNORMAL(0.0), COLPOLY_SNORMAL(1.0), COLPOLY_SNORMAL(0.0) }, 64917 },
};

