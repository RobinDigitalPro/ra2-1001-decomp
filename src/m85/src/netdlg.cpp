/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2025 Electronic Arts Inc.
 * Copyright 2026 OpenTS contributors
 *
 * Contains material derived from Electronic Arts source code.
 * Modified by OpenTS contributors, 2026.
 * EA's GPLv3 Section 7 additional terms and supplemental warranty
 * disclaimers apply; see LICENSE.md.
 ******************************************************************************/

/*
**	RA2: the network setup helpers of Tiberian Sun's NETDLG.CPP that RA2 still has at 0x005BB540:
**	starting and stopping the packet transport, dropping a player's connection, the CRC of a game
**	name and clearing a list box. RA2 moved the dialogs of that file to netdlg2.cpp.
*/

#include "always.h" // RA2: the includes this file needs
#include <string.h> // RA2: the includes this file needs
#include <stdio.h> // RA2: the includes this file needs
#include <wchar.h> // RA2: the includes this file needs
#undef LoadString // RA2: as above
#include "_map.h" // RA2: the includes this file needs
#include "_rules.h" // RA2: the includes this file needs
#include "dbgprint.h" // RA2: the includes this file needs
#include "event.h" // RA2: the includes this file needs
#include "globals.h" // RA2: the includes this file needs
#include "house.h" // RA2: the includes this file needs
#include "houstype.h" // RA2: the includes this file needs
#include "ipxmgr.h" // RA2: the includes this file needs
#include "list.h" // RA2: the includes this file needs
#include "msglist.h" // RA2: the includes this file needs
#include "netdlg.h"
#include "ownertalk.h" // RA2: OwnerTalk
#include "queue.h" // RA2: Add_CRC and OutList
#include "rules.h" // RA2: the includes this file needs
#include "session.h" // RA2: the includes this file needs
#include "stringtable.h" // RA2: the includes this file needs
#include "wonline.h" // RA2: WestwoodOnline_Tournament
#include "wsproto.h" // RA2: PacketTransport, deleted by Shutdown_Network







/// <summary>
/// Computes the CRC of an upper-cased name (a narrow game name).
/// </summary>
unsigned int Compute_Name_CRC(char *name)
{
	char buf[80];
	unsigned int crc = 0L;
	int i;

	strcpy(buf, name);
	_strupr(buf);

	for (i = 0; (unsigned)i < strlen(buf); i++) {
		Add_CRC(&crc, (unsigned int)buf[i]);
	}

	return(crc);
}

/// <summary>
/// Computes the CRC of an upper-cased name (a wide game name, which is what the session keeps).
/// </summary>
unsigned int __fastcall Compute_Name_CRC(wchar_t const * name) // RA2: the wide form, 0x005BBA50 (the other files declare it with this prototype)
{
	wchar_t buf[80]; // RA2: 80 wchar_t
	unsigned int crc = 0L;
	unsigned int i;

	wcscpy(buf, name); // RA2: as above
	_wcsupr(buf); // RA2: as above

	for (i = 0; i < wcslen(buf); i++) { // RA2: i is unsigned, the compare is unsigned (jb)
		Add_CRC(&crc, (unsigned int)buf[i]); // RA2: the 16 bit character is zero extended (no sign extension as in the narrow form)
	}

	return(crc);
}


