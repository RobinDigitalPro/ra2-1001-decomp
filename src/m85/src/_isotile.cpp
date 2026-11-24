// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _isotile.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: IsometricTiles 0x81a788 (initializer 0xc690, atexit destructor 0xc6d0); the GAMECONST block of this unit is claimed by src/ra2/unnamed/TU_40C4A0.cpp

#include "always.h"
#include "vector.h"
#include "_isotile.h"

DynamicVectorClass<IsometricTileClass *> IsometricTiles;
