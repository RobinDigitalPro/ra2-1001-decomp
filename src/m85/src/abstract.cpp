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

/* $Header: /CounterStrike/ABSTRACT.CPP 1     3/03/97 10:24a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : ABSTRACT.CPP                                                 *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 01/26/95                                                     *
 *                                                                                             *
 *                  Last Update : July 10, 1996 [JLB]                                          *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   AbstractClass::Debug_Dump -- Display debug information to mono screen.                    *
 *   AbstractClass::Distance -- Determines distance to target.                                 *
 *   AbstractTypeClass::AbstractTypeClass -- Constructor for abstract type objects.            *
 *   AbstractTypeClass::Coord_Fixup -- Performs custom adjustments to location coordinate.     *
 *   AbstractTypeClass::Full_Name -- Returns the full name (number) of this object type.       *
 *   AbstractTypeClass::Get_Ownable -- Fetch the ownable bits for this object.                 *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "abstract.h"

#include "_rtti.h"
#include "assert.h"
#include "coord.h"
#include "crc.h"
#include "globals.h"
#include "noinit.h"
#include "scenario.h"
#include "swizzle.h"
#include "vector.h"




/// <summary>
/// No-initialization constructor for abstract objects.
/// Use this constructor when the object is about to be overwritten wholesale by
/// the load process. It deliberately leaves every member untouched.
/// </summary>
AbstractClass::AbstractClass(NoInitClass const & x)
{
	x(); /// referenced so the compiler does not warn about it
}



































/// <summary>
/// Determines if this object is inactive.
/// The bare abstract object is never a participant in the game, so it always
/// reports inactive. Objects that can be placed in the world override this.
/// </summary>
/// <returns>bool; Is the object inactive?</returns>
bool AbstractClass::Is_Inactive(void) const
{
	assert(this != NULL);

	return(true);
}


// RA2: Is_Techno is not defined here: Is_Inactive (0x004101E0) is directly followed by IsDirty (0x004101F0).








/// <summary>
/// Severs any references this object holds to the target.
/// This routine is called on every object when one of them is about to be
/// destroyed, so that nothing is left pointing at the corpse.
/// </summary>
/// <param name="target">The object that is about to disappear.</param>
/// <param name="all">Should every reference be severed, including cargo and radio links?</param>
void AbstractClass::Detach(AbstractClass const * target, bool all)
{
	assert(this != NULL);

}


// RA2: Get_Object_Size_Delta is not in RA2's vtables (see abstract.h).


/// <summary>
/// Fetches the house that owns this object.
/// The bare abstract object belongs to nobody. Ownable objects override this.
/// </summary>
/// <returns>Returns with the owning house, or HOUSE_NONE when the object is unowned.</returns>
HousesType AbstractClass::Owner(void) const
{
	assert(this != NULL);

	return(HOUSE_NONE);
}


/// <summary>
/// Fetches the house object that owns this object.
/// </summary>
/// <returns>Returns with a pointer to the owning house, or NULL when the object
/// is unowned.</returns>
HouseClass *AbstractClass::Owner_HouseClass(void) const
{
	assert(this != NULL);

	return(NULL);
}


/// <summary>
/// Fetches this object's index within its heap.
/// </summary>
/// <returns>Returns with the heap index, or zero for an object that does not
/// live in a heap.</returns>
int AbstractClass::Fetch_Heap_ID(void) const
{
	assert(this != NULL);

	return(0);
}


/***********************************************************************************************
 * ObjectClass::Center_Coord -- Fetches the center coordinate for the object.                  *
 *                                                                                             *
 *    This routine will return the center coordinate for the object. The center coordinate is  *
 *    typically the coordinate recorded in the object structure. Exceptions to this include    *
 *    the trees and other terrain elements.                                                    *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns the coordinate that is considered the center point of this object.         *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   09/21/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
Coord AbstractClass::Center_Coord(void) const
{
	assert(this != NULL);

	return(COORD_NONE);
}


/// <summary>
/// Fetches the coordinate that others should move toward.
/// Objects with a distinguished approach point -- a building's entry cell, say --
/// override this. By default an object is approached at its center.
/// </summary>
/// <returns>Returns with the coordinate another object should head for.</returns>
Coord AbstractClass::Destination_Coord(TechnoClass * docker) const // RA2: see abstract.h
{
	assert(this != NULL);

	return(Center_Coord());
}


/// <summary>
/// Determines if this object is resting on the ground.
/// </summary>
/// <returns>bool; Is the object on the ground?</returns>
bool AbstractClass::On_Ground(void) const
{
	return(false);
}


/// <summary>
/// Determines if this object is airborne.
/// </summary>
/// <returns>bool; Is the object in the air?</returns>
bool AbstractClass::In_Air(void) const
{
	return(false);
}


/// <summary>
/// Fetches this object's coordinate.
/// Defaults to the center coordinate; objects that are located by some other
/// reference point override this.
/// </summary>
/// <returns>Returns with the object's coordinate.</returns>
Coord AbstractClass::As_Coord(void) const
{
	assert(this != NULL);

	return(Center_Coord());
}





bool AbstractClass::Unknown_Virtual_0(int, int) // RA2: see INoticeSink (abstract.h)
{
	return(false); // RA2: AbstractClass's version is xor al, al; ret 8
}


void AbstractClass::Unknown_Virtual_0(int) // RA2: see INoticeSource (abstract.h); AbstractClass's version is ret 4
{
}
