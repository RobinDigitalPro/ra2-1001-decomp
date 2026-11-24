// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _map.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: Map 0x81a820 (initializer 0xd060, atexit destructor 0xd080); the GAMECONST block of this unit is claimed by src/ra2/unnamed/TU_40CE90.cpp

#include "always.h"
#include "_map.h"

MouseClass Map;

// level-2 1.001: initializer 0xd0d0 / atexit destructor 0xd0f0 of the pointer global 0x81a7f0. The destructor is
// `if (p) p->Release();` (vtable slot +8) and nothing else in GAME.EXE references the global, so the interface
// type is unknown; ATL CComPtr<IUnknown> gives identical code. The include stands here so that the
// initializer numbers of Map (_$E87/_$E85) do not shift.
#include <atlbase.h>

CComPtr<IUnknown> ComPtr_81A7F0;
