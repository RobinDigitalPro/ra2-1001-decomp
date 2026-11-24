// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _convert.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: TileDrawers 0x81a6d8 (initializer 0xc0c0, atexit destructor 0xc100); RTTI vtable 0x78585c

#include "always.h"
#include "vector.h"
#include "_convert.h"

DynamicVectorClass<LightConvertClass *> TileDrawers;
