// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _command.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: RECT_NONE initializer 0xbc60; HotkeyCommands 0x81a6c0 (0xbc80, atexit 0xbcb0); AllCommands 0x81a698 (0xbce0, atexit 0xbd20)

#include "always.h"
#include "rect.h"
#include "vector.h"
#include "index.h"
#include "_command.h"

IndexClass<int, CommandClass const *> HotkeyCommands;
DynamicVectorClass<CommandClass const *> AllCommands;
