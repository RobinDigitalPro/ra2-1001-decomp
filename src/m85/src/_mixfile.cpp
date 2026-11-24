// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _mixfile.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: ExpandMix 0x81f790 (0xd210/0xd250), ScenarioMixFiles 0x81f7c0 (0xd290/0xd2d0; startup.cpp calls it MixList_81F7C0), MapsMixLocal 0x81f7a8 (0xd310/0xd350), MoviesMixLocal 0x81f7e0 (0xd390/0xd3d0), in the 1.001 initializer order

#include "always.h"
#include "vector.h"
#include "_mixfile.h"

DynamicVectorClass<MFCD *> ExpandMix;
DynamicVectorClass<MFCD *> ScenarioMixFiles;
DynamicVectorClass<MFCD *> MapsMixLocal;
DynamicVectorClass<MFCD *> MoviesMixLocal;
