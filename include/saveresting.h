#ifndef SAVERESTING_H
#define SAVERESTING_H 1

void Interface_SaveResting_Init(PlayState* play);
void Interface_SaveResting_Start(PlayState* play);
void Interface_SaveResting_CheckAlpha(PlayState* play);
void Interface_SaveResting_ApproachTargetAlpha(PlayState* play);
void Interface_SaveResting_Update(PlayState* play);
void Interface_SaveResting_Draw(PlayState* play);
void Interface_SaveResting_TakeInput(PlayState* play);
void Interface_SaveResting_DrawDebug(PlayState* play, GraphicsContext* gfxCtx);

#define SAVEREST_UNREACHABLE 256
#define SAVEREST_APPROACH(min, max) ((this->alpha > this->targetAlpha) ? MAX(this->alpha - this->alphaStep, min) : (this->alpha < this->targetAlpha) ? MIN(this->alpha + this->alphaStep, max) : this->alpha)

#define SAVEREST_SETCOLOR(sel)                                      \
    switch(this->selection) {                                       \
            case sel:                                               \
                GfxPrint_SetColor(&printer, 255, 255, 0, 255);      \
                break;                                              \
            default:                                                \
                GfxPrint_SetColor(&printer, 255, 255, 255, 255);    \
                break;                                              \
                                                                    \
        }                                                           

#endif