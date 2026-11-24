// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2026 ra2-decomp contributors
// Copyright 2025 Electronic Arts Inc.; 2026 OpenTS contributors
// Derived from Electronic Arts source code; EA's GPL Section 7 terms apply (COPYING.md).
// Adapted from gibbo101/ra2-decomp src/_script.cpp (commit in W/analysis/references_gpl_20261118/provenance.json)

#include "always.h"
#include "geometry.h"
#include "_script.h"
#include "vector.h"
#include "stimer.h"
#include "mstimer.h"
#include "timer.h"

// level-2: adopted from gibbo101 _script.cpp (script list and frame timer).
DynamicVectorClass<ScriptClass *> Scripts;

// level-2 1.001: initializers at 0x40E970, 0x40E9B0 and 0x40E9F0, in CRT table order.
CDTimerClass<SystemTimerClass> FrameTimer;
CDTimerClass<MillisecondSystemTimerClass> NetFrameTimer;
TTimerClass<SystemTimerClass> TickCount;
