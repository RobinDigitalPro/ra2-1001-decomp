// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _milsectmr.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: MillisecondTimer 0x81f788 (initializer 0xd1e0, atexit destructor 0xd200)

#include "always.h"
#include "milsectmr.h"
#include "_milsectmr.h"

MillisecondTimerClass MillisecondTimer;
