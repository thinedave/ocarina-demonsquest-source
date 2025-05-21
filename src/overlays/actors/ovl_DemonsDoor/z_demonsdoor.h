#ifndef Z_DEMONSDOOR_H
#define Z_DEMONSDOOR_H 1

#include "ultra64.h"
#include "global.h"

struct DemonsDoor;
typedef void (*DemonsDoorActionFunc)(struct DemonsDoor*, PlayState*);

typedef struct DemonsDoor {
    DynaPolyActor dyna;
    u16 timer;
    DemonsDoorActionFunc actionFunc;
    u8 request;
} DemonsDoor;

void DemonsDoor_WaitToClose(DemonsDoor* this, PlayState* play);
void DemonsDoor_Close(DemonsDoor* this, PlayState* play);

void DemonsDoor_WaitToOpen(DemonsDoor* this, PlayState* play);
void DemonsDoor_Open(DemonsDoor* this, PlayState* play);

#endif
