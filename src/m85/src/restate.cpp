// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2026 ra2-decomp contributors
// Copyright 2025 Electronic Arts Inc.; 2026 OpenTS contributors
// Derived from Electronic Arts source code; EA's GPL Section 7 terms apply (COPYING.md).

#include "always.h"
#include <windows.h>
#undef LoadString
#include "_keyboar.h"
#include "_map.h"
#include "ccfile.h"
#include "ccini.h"
#include "globals.h"
#include "keyboard.h"
#include "ownrdraw.h"
#include "scenario.h"
#include "stringtable.h"

char const * MissionININame = "MISSION.INI"; // RA2
char const * BriefingKey = "Briefing"; // RA2
static wchar_t const * RestateText; // RA2: the briefing text the dialog shows

int CALLBACK Restate_Mission_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam);



int CALLBACK Restate_Mission_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	int rc = OwnerDraw::Default_Dialog_Proc(window, message, wparam, lparam);
	if (rc != 0) {
		return rc;
	}
	switch (message) {
		case WM_COMMAND:
			if (GetDlgCtrlID((HWND)lparam) == 0x423 && HIWORD(wparam) == 0) {
				*(int *)GetWindowLong(window, DWL_USER) = 0x423;
			}
			break;
		case 0x497:
			{
				HWND item = GetDlgItem(window, 0x6e7);
				SendMessage(item, 0x4b2, 0, (LPARAM)RestateText);
			}
			break;
	}
	return 0;
}
