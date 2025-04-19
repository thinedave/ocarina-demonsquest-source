#ifndef Z_XPDROP_H
#define Z_XPDROP_H

#include "ultra64.h"
#include "global.h"

struct XPDrop;

typedef void (*XPDropActionFunc)(struct XPDrop*, PlayState*);

typedef struct XPDropEffect {
    /* 0x00 */ u8 state;
    /* 0x04 */ Vec3f pos; // relative to base
    /* 0x10 */ Vec3f prevPos;
    /* 0x1C */ Vec3f base;
    /* 0x28 */ Vec3f dirPhase; // input to sin/cos for movement direction
    /* 0x34 */ f32 speed;
    /* 0x38 */ f32 targetSpeed;
    /* 0x3C */ u16 alphaTimer;
    /* 0x3E */ u16 angle;
    /* 0x40 */ u8 alpha;
    /* 0x44 */ f32 size;
    /* 0x48 */ u16 angleVel;
    /* 0x4A */ u16 flightRadius;
    /* 0x4C */ f32 amplitude;
    /* 0x50 */ u16 timer;
    Vec3f initBase;
} XPDropEffect; // size = 0x54

typedef struct XPDrop {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ XPDropEffect effects[64];
    /* 0x164C */ Vec3f prevEyePos;
    /* 0x1658 */ u8 requiredObjectSlot;
    /* 0x1659 */ u8 requiredObjectLoaded;
    /* 0x165C */ XPDropActionFunc actionFunc;
    s16 trailingFairies;
    u8 state;
    u16 timer;
    u8 activeEffects;
} XPDrop; // size = 0x1660

#endif
