// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2026 ra2-decomp contributors
// Copyright 2025 Electronic Arts Inc.; 2026 OpenTS contributors
// Derived from Electronic Arts source code; EA's GPL Section 7 terms apply (COPYING.md).
// Adapted from gibbo101/ra2-decomp src/combuf2.cpp (commit in W/analysis/references_gpl_20261118/provenance.json)

#include "always.h"
#include <stddef.h>
#include <stdlib.h>
#include "_command.h"
#include "command.h"
#include "index.h"
#include "keyboard.h"

bool __fastcall FUN_0048BB40(CommandClass const * command, int key);
bool __fastcall FUN_0048BB60(int key);

// level-2: adopted from gibbo101 combuf2.cpp (1.001: 0x480DC0)
bool __fastcall FUN_0048BB40(CommandClass const * command, int key)
{
	key &= ~KN_RLSE_BIT;
	int plain = key & ~(WWKEY_SHIFT_BIT|WWKEY_ALT_BIT|WWKEY_CTRL_BIT|WWKEY_VK_BIT);
	if (key != plain) {
		return !command->PreventCombinationOverride(key);
	}
	return true;
}

// level-2: adopted from gibbo101 combuf2.cpp (1.001: 0x480DE0)
bool __fastcall FUN_0048BB60(int input)
{
	int key = input & ~KN_RLSE_BIT;
	int plain = key & ~(WWKEY_SHIFT_BIT|WWKEY_ALT_BIT|WWKEY_CTRL_BIT|WWKEY_VK_BIT);
	CommandClass const * command = HotkeyCommands[plain];
	if (command == NULL) {
		return true;
	}
	return !command->PreventCombinationOverride(key);
}

// level-2: adopted from gibbo101 combuf2.cpp (explicit instantiation of the hotkey index)
template class IndexClass<int, CommandClass const *>;
