// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _vanim.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: VoxelAnims 0x821d10 (initializer 0xec40, atexit destructor 0xec80); the GAMECONST block of this unit is claimed by src/ra2/unnamed/TU_40EA50.cpp

#include "always.h"
#include "vector.h"
#include "_vanim.h"

DynamicVectorClass<VoxelAnimClass *> VoxelAnims;
