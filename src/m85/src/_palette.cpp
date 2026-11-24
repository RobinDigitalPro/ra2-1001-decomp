// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2026 ra2-decomp contributors
// Copyright 2025 Electronic Arts Inc.; 2026 OpenTS contributors
// Derived from Electronic Arts source code; EA's GPL Section 7 terms apply (COPYING.md).
// Adapted from gibbo101/ra2-decomp src/_palette.cpp (commit in W/analysis/references_gpl_20261118/provenance.json)

#include "always.h"

#include "palette.h"
#include "pk.h"
#include "random.h"

// level-2: adopted from gibbo101 _palette.cpp (the global objects of this object file; 1.001 initializers 0x40D770..0x40D8D0)
PaletteClass CCPalette;
PaletteClass GamePalette;
PaletteClass SchemePalette;
PaletteClass BlackPalette(RGBClass(0, 0, 0));
PaletteClass WhitePalette(RGBClass(RGBClass::MAX_VALUE, RGBClass::MAX_VALUE, RGBClass::MAX_VALUE));
PaletteClass OriginalPalette;
PaletteClass ScorePalette;
PaletteClass VoxelPalette;
PaletteClass WaypointPalette;

PKey FastKey;

Random2Class NonCriticalRandomNumber; // level-2 1.001: 0x40D8C0 constructs it with the default seed (gibbo101 names it Randomizer::Global)
