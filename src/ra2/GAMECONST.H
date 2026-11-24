// Shared constants with internal linkage: every including translation unit gets its own copy and
// its own dynamic initializers (GAME.EXE e.g. 0x103b0..0x10571 for AbsType.cpp).
// The original header name and the variable names are not known; names here are provisional.
#pragma once
#include <math.h>
#include "COORD.H"
#include "FASTMATH.H"

static const double FRAMES = 60.0;
static const double DEG_TO_RAD = 0.017453292519943295;
static double const CellDiagonal = Fast_Sqrt(pow(256.0, 2.0) * 2);
static double const A2 = CellDiagonal / FRAMES;
static double const A3 = 1.0 / A2;
static double const Rad45 = DEG_TO_RAD * 45.0;
static double const Rad60 = DEG_TO_RAD * 60.0;
static double const Rad90 = DEG_TO_RAD * 90.0;
static int const I7 = (int)(Fast_Sin(Rad90 - Rad60) * CellDiagonal * 0.5);
static double const A8 = Fast_Arcsin(I7 / 256.0);
static double const A9 = Fast_Arcsin((I7 * 2) / CellDiagonal);
static int const I10 = (int)(I7 * 4 + 0.5);
static CellStruct const EmptyCell(0, 0);
static CoordStruct const EmptyCoord(0, 0, 0);
