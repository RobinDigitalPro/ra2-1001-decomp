

// SPDX-License-Identifier: GPL-3.0-or-later
// refcount.cpp (level-2 reconstruction of GAME.EXE 1.001; file name provisional, after include/refcount.h)
// Contents: the out-of-line members of ReferenceCounted, 0x230cb0..0x230d10 (between readline.cpp and the
// next unit). Class name from RTTI (.?AVReferenceCounted@@, vtable 0x793cd4, slots 0x230cf0 / 0x230ce0 /
// 0x230cc0). Written from the 1.001 disassembly; no m85/gibbo body exists for these functions.
#include "refcount.h"

// 0x230cb0
ReferenceCounted::~ReferenceCounted(void)
{
}

// 0x230cc0: drops a reference, deleting the object with the last one.
void ReferenceCounted::Release(void)
{
	if (--Count == 0) {
		delete this;
	}
}

// 0x230ce0: vtable +0x4; always false here, its name is not known.
bool ReferenceCounted::Unknown_Virtual_4(int)
{
	return false;
}
