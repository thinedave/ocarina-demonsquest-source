#ifndef Z_POWERTRIALHANDLER_H
#define Z_POWERTRIALHANDLER_H 1

#include "ultra64.h"
#include "global.h"
#include "overlays/actors/ovl_DemonsDoor/z_demonsdoor.h"

struct PowerTrialHandler;

typedef struct PowerTrialHandler {
    Actor actor;
    s16 csCamIndex;
    u8 state;
    u16 timer;
    DemonsDoor* doorLast;
    DemonsDoor* doorNext;
} PowerTrialHandler;

#endif
