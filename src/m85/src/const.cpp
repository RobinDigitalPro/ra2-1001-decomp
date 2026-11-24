// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2026 ra2-decomp contributors
// Copyright 2025 Electronic Arts Inc.; 2026 OpenTS contributors
// Derived from Electronic Arts source code; EA's GPL Section 7 terms apply (COPYING.md).
// Adapted from gibbo101/ra2-decomp src/const.cpp (commit in W/analysis/references_gpl_20261118/provenance.json)

#include "always.h"
#include "geometry.h"
#include "rect.h"
#include <math.h>
#include "coord.h"
#include "globals.h"

// level-2: adopted from gibbo101 const.cpp (1.001 initializer 0x483170)
Coord const StoppingCoordAbs[5] = {
	Coord(CELL_LEPTON_W / 2,     CELL_LEPTON_H / 2, 0),
	Coord(CELL_LEPTON_W / 4,     CELL_LEPTON_H / 4, 0),
	Coord(3 * CELL_LEPTON_W / 4, CELL_LEPTON_H / 4, 0),
	Coord(CELL_LEPTON_W / 4,     3 * CELL_LEPTON_H / 4, 0),
	Coord(3 * CELL_LEPTON_W / 4, 3 * CELL_LEPTON_H / 4, 0)
};
