// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2026 ra2-decomp contributors

#include <stdlib.h>
#include "always.h"
#include "pixelfx.h"







void PixelFXClass::Update(int frames)
{
	Phase += Rate * frames;
	if (Phase > 0x2000) {
		Phase = 0x2000;
	}
	int t = Phase & 0xFFF;
	if (Phase & 0x1000) {
		t = 0x1000 - t;
	}
	Current[0] = (ColorB[0] * (0x1000 - t) + ColorA[0] * t) >> 12;
	Current[1] = (ColorB[1] * (0x1000 - t) + ColorA[1] * t) >> 12;
	Current[2] = (ColorB[2] * (0x1000 - t) + ColorA[2] * t) >> 12;
}

bool PixelFXClass::Expire(int frames)
{
	Life -= frames;
	if (Life <= 0) {
		Life = 0;
		return true;
	}
	return false;
}




