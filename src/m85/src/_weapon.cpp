// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _weapon.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: Weapons 0x821ed0 (initializer 0xf8f0, atexit destructor 0xf930); the GAMECONST block of this unit is claimed by src/ra2/unnamed/TU_40F720.cpp

#include "always.h"
#include "vector.h"
#include "_weapon.h"

DynamicVectorClass<WeaponTypeClass *> Weapons;
