#ifndef Z_SAVESPOT_H
#define Z_SAVESPOT_H

#include "ultra64.h"
#include "global.h"

struct Savespot;

typedef void (*SavespotActionFunc)(struct Savespot*, struct PlayState*);

typedef struct Savespot {
    /* 0x0000 */ Actor actor;
    /* 0x0204 */ SavespotActionFunc actionFunc;
    bool active;
    s16 r;
    s16 g;
    s16 b;
    s16 activationEventTimer;

    // warp spot stuff.
    /* 0x0194 */ f32 unk_194;
    /* 0x0198 */ f32 unk_198;
    /* 0x019C */ f32 unk_19C;
    /* 0x01A0 */ f32 lightRayAlpha;
    /* 0x01A4 */ f32 warpAlpha;
    /* 0x01AE */ s16 unk_1AE;
    /* 0x01B0 */ s16 unk_1B0;

} Savespot; // size = 0x0208


#endif
