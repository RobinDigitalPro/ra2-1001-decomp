// unidentified translation unit before Egos.CPP (GAMECONST.H initializers at 0xb2c60) (level-2 reconstruction of GAME.EXE 1.001)
// Code moved by the integrator from the Egos.CPP agent result (2026-11-18).
#include "../GAMECONST.H"
#include "../RECT.H"
// Needs GAMECONST.H and RECT.H.
// Compiled here it gave equal bytes for the initializers 0xb2c60..0xb2e50.
// C6 (2026-11-23): the bodies at 0xb2e70 and 0xb30c0 that stood here as Build_Fading_Table /
// Build_Translucent_Table are m85 effects.cpp Conquer_Build_Fading_Table / Conquer_Build_Translucent_Table
// (claims moved by plan g2_effects_conquer).  They are removed here together with their provisional
// RGBClass / PaletteClass / TLucentType declarations, so that a whole-exe link has one definition of
// ?Build_Fading_Table@@YIPAXABVPaletteClass@@PAXHH@Z and ?Build_Translucent_Table@@... (effects.cpp).
static RectangleStruct const ZeroRectB(0, 0, 0, 0);     // 0x83b3c8, initializer 0xb2e30
static RectangleStruct const ZeroRectC(0, 0, 0, 0);     // 0x83b438, initializer 0xb2e50
