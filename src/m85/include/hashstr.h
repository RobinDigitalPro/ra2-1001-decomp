/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2025 Electronic Arts Inc.
 * Copyright 2026 OpenTS contributors
 * Copyright 2026 ra2-decomp contributors
 *
 * Contains material derived from Electronic Arts source code.
 * EA's GPLv3 Section 7 additional terms and supplemental warranty
 * disclaimers apply; see LICENSE.md.
 *
 * level-2 1.001: new shared header. The class was file-local in palette.cpp
 * (mischa85/RedAlert2, commit 0132d217); the shape of the declaration follows
 * gibbo101/ra2-decomp include/hashstr.h. The members are defined in
 * gscreen.cpp, the module that emits them in GAME.EXE 1.001
 * (0x004E07C0 to 0x004E0930).
 ******************************************************************************/

#pragma once

class HashString { // RA2: the table key, a 256 byte name
	public: // RA2: as above
		HashString(void); // RA2: 0x004E1130; 1.001: 0x004E07C0
		HashString(char const * str); // RA2: 0x004E1140; 1.001: 0x004E07D0
		HashString(HashString const & that); // RA2: 0x004E1180; 1.001: 0x004E0810
		HashString & operator = (HashString const & that); // RA2: 0x004E11C0; 1.001: 0x004E0850
		bool operator == (HashString const & that); // RA2: 0x004E11F0; level-2 1.001: non-const, 0x4E0880 (as gibbo101 hashstr.h)
		bool operator != (HashString const & that); // level-2 1.001: out of line, 0x4E08D0 (as gibbo101 hashstr.h)
		bool operator ! (void) const; // RA2: 0x004E11B0, true for an empty name; 1.001: 0x004E0840

		char Str[256]; // RA2: +0x0
};
bool operator == (HashString const & a, HashString const & b); // level-2 1.001: 0x4E0920 (as gibbo101 hashstr.h); the table's entries compare their keys through it
bool operator != (HashString const & a, HashString const & b); // level-2 1.001: 0x4E0930
