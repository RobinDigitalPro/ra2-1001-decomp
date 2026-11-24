/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2025 Electronic Arts Inc.
 * Copyright 2026 OpenTS contributors
 * Copyright 2026 ra2-decomp contributors
 *
 * Contains material derived from Electronic Arts source code.
 * Modified by OpenTS contributors, 2026.
 * EA's GPLv3 Section 7 additional terms and supplemental warranty
 * disclaimers apply; see LICENSE.md.
 ******************************************************************************/

#include "always.h"

#include "diskswap.h"

#include "assert.h"
#include "cdfile.h"
#include "globals.h"
#include "playcd.h"
#include "stimer.h"
#include "timer.h"

/***********************************************************************************************
 * Get_CD_Index -- returns the volume type of the CD in the given drive                        *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    drive number                                                                      *
 *           timeout                                                                           *
 *                                                                                             *
 * OUTPUT:   0 = gdi                                                                           *
 *           1 = nod                                                                           *
 *           2 = covert or CS                                                                  *
 *           3 = Aftermath
 *           5 = DVD
 *          -1 = non C&C                                                                       *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    5/21/96 5:27PM ST : Created                                                              *
 *    01/20/97 V.Grippi added CS support                                                       *
 *=============================================================================================*/
// level-2 1.001: the shipped (repacked) bytes of this function are reconstructed in asm/repack_nocd.asm (repack no-CD delta); this is the original unpatched logic




/***********************************************************************************************
 * Force_CD_Available -- Ensures that specified CD is available.                               *
 *                                                                                             *
 *    Call this routine when you need to ensure that the specified CD is actually in the       *
 *    CD-ROM drive.                                                                            *
 *                                                                                             *
 * INPUT:   cd    -- The CD that must be available. This will either be "0" for the GDI CD, or *
 *                   "1" for the Nod CD. If either CD will qualify, then pass in "-1".         *
 *                0  = CD1
 *                1  = CD2
 *                2  = Counterstrike
 *                3  = Aftermath
 *                4  = Counterstrike or Aftermath
 *                5  = DVD
 *                -1 = Any CD
 *                -2 = Local Harddisk
 *                                                                                             *
 * OUTPUT:  Is the CD inserted and available? If false is returned, then this indicates that   *
 *          the player pressed <CANCEL>.                                                       *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/11/1995 JLB : Created.                                                                 *
 *   05/22/1996  ST : Handles multiple CD drives / CD changers                                 *
 *   01/20/1997 V.Grippi added expansion cd message
 *=============================================================================================*/
// level-2 1.001: the shipped (repacked) bytes of this function are reconstructed in asm/repack_nocd.asm (repack no-CD delta); this is the original unpatched logic



/// <summary>
/// Handles the switch over to a newly inserted disc.
/// This is the placeholder implementation and does no more than put a system message box on
/// the screen. Derived classes override this routine to do the real work of rebinding the
/// game's mix files to the disc that has just been supplied.
/// </summary>
/// <param name="disk">The disc being switched to.</param>
/// <returns>bool; Was the switch accepted?</returns>
bool DiskSwap::Swap(DiskID disk)
{
	char str[256];

	sprintf(str, "Please insert disk %d", disk);
	if (MessageBox(NULL, str, "Hey!", MB_OKCANCEL) == IDOK) {
		return(true);
	}
	return(false);
}


/// <summary>
/// Asks the player to insert the disc that is needed.
/// This is the placeholder implementation and merely reports success. Derived classes
/// override this routine to put up the real disc request dialog and to let the player give
/// up on finding the disc.
/// </summary>
/// <param name="disk">The disc to ask the player for.</param>
/// <returns>bool; Should the search continue? A false return means the player gave
/// up.</returns>
bool DiskSwap::Request_Disk(DiskID disk)
{
	return(true);
}
