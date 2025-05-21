#include "global.h"
#include "message_data_static.h"

void func_8006EE50(Font* font, u16 arg1, u16 arg2) {
}

/**
 * Loads a texture from nes_font_static for the requested `character` into the character texture buffer
 * at `codePointIndex`. The value of `character` is the ASCII codepoint subtract ' '/0x20.
 */
void Font_LoadChar(Font* font, u8 character, u16 codePointIndex) {
    DmaMgr_RequestSyncDebug(&font->charTexBuf[codePointIndex],
                            (uintptr_t)_nes_font_staticSegmentRomStart + character * FONT_CHAR_TEX_SIZE,
                            FONT_CHAR_TEX_SIZE, "../z_kanfont.c", 93);
}

/**
 * Loads a message box icon from message_static, such as the ending triangle/square or choice arrow into the
 * icon buffer.
 * The different icons are given in the MessageBoxIcon enum.
 */
void Font_LoadMessageBoxIcon(Font* font, u16 icon) {
    DmaMgr_RequestSyncDebug(font->iconBuf,
                            (uintptr_t)_message_staticSegmentRomStart + 4 * MESSAGE_STATIC_TEX_SIZE +
                                icon * FONT_CHAR_TEX_SIZE,
                            FONT_CHAR_TEX_SIZE, "../z_kanfont.c", 100);
}

void Font_LoadAll(Font* font) {
    DmaMgr_RequestSyncDebug(&font->charTexBuf,
                            (uintptr_t)_nes_font_staticSegmentRomStart, (uintptr_t)_nes_font_staticSegmentRomEnd - (uintptr_t)_nes_font_staticSegmentRomStart, __FILE__, __LINE__);

}