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

/* $Header: /CounterStrike/WARHEAD.CPP 1     3/03/97 10:26a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : WARHEAD.CPP                                                  *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 05/20/96                                                     *
 *                                                                                             *
 *                  Last Update : July 19, 1996 [JLB]                                          *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   WarheadTypeClass::As_Pointer -- Convert a warhead type number into a pointer.             *
 *   WarheadTypeClass::Read_INI -- Fetches the warhead data from the INI database.             *
 *   WarheadTypeClass::WarheadTypeClass -- Default constructor for warhead objects.            *
 *   WarheadTypeClass::operator delete -- Returns warhead object back to special memory pool.  *
 *   WarheadTypeClass::operator new -- Allocate a warhead object from the special heap.        *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define INCLUDE_COM
#include "always.h"

#include "warhead.h"

#include "_warhead.h"
#include "animtype.h"
#include "ccini.h"
#include "findmake.h"
#include "globals.h"
#include "partsys.h"
#include "psystype.h"
#include "session.h"
#include "stimer.h"
#include "sun.h"
#include "swizzle.h"
#include "tracker.h"
#include "vector.h"


/// <summary>
/// Converts a percentage string into a fractional multiplier.
/// This routine is used when reading the warhead's armor modifier list, where each value
/// may be written either as a percentage or as a plain fraction.
/// </summary>
/// <param name="string">The text to convert.</param>
/// <returns>Returns with the value as a fraction, such that "100%" becomes one.</returns>
float _Parse_Percentage(const char * string)
{
	if (strchr(string, '%')) {
		return((double)atoi(string) / 100);
	}

	return(atof(string));
}


/***********************************************************************************************
 * WarheadTypeClass::WarheadTypeClass -- Default constructor for warhead objects.              *
 *                                                                                             *
 *    This default constructor for a warhead object will fill in all the default values        *
 *    for a warhead. It is presumed that these values will be normal unless specifically       *
 *    overridden by the INI database.                                                          *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/19/1996 JLB : Created.                                                                 *
 *=============================================================================================*/



/// <summary>
/// Constructor for warhead objects that skips initialization.
/// Use this routine when the warhead is about to be filled in from a save game, since
/// every value would only be overwritten by the data read from the stream.
/// </summary>
WarheadTypeClass::WarheadTypeClass(NoInitClass const & x) :
	BASECLASS(x)
{
}





/***********************************************************************************************
 * WarheadTypeClass::Read_INI -- Fetches the warhead data from the INI database.               *
 *                                                                                             *
 *    Use this routine to retrieve the data specific to this warhead type class object from    *
 *    the INI database specified. Typical use of this is when processing the rules.ini         *
 *    file.                                                                                    *
 *                                                                                             *
 * INPUT:   ini   -- Reference to the INI database to fetch the values from.                   *
 *                                                                                             *
 * OUTPUT:  bool; Was the warhead entry found and the data retrieved?                          *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/19/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool WarheadTypeClass::Read_INI(CCINIClass const & ini)
{
	if (ini.Is_Present(Name())) {
		SpreadFactor = ini.Get_Float(Name(), "CellSpread", SpreadFactor);
		CellInset = ini.Get_Float(Name(), "CellInset", CellInset);
		PercentAtMax = ini.Get_Float(Name(), "PercentAtMax", PercentAtMax);
		CausesDelayKill = ini.Get_Bool(Name(), "CausesDelayKill", CausesDelayKill);
		DelayKillFrames = ini.Get_Int(Name(), "DelayKillFrames", DelayKillFrames);
		DelayKillAtMax = ini.Get_Float(Name(), "DelayKillAtMax", DelayKillAtMax);
		CombatLightSize = ini.Get_Float(Name(), "CombatLightSize", CombatLightSize);
		Particle = TGet_Class(ini, Name(), "Particle", Particle);

		IsConventional = ini.Get_Bool(Name(), "Conventional", IsConventional);
		IsWallDestroyer = ini.Get_Bool(Name(), "Wall", IsWallDestroyer);
		WallAbsoluteDestroyer = ini.Get_Bool(Name(), "WallAbsoluteDestroyer", WallAbsoluteDestroyer);
		IsWoodDestroyer = ini.Get_Bool(Name(), "Wood", IsWoodDestroyer);
		IsTiberiumDestroyer = ini.Get_Bool(Name(), "Tiberium", IsTiberiumDestroyer);
		IsSparky = ini.Get_Bool(Name(), "Sparky", IsSparky);
		Sonic = ini.Get_Bool(Name(), "Sonic", Sonic);
		IsRocker = ini.Get_Bool(Name(), "Rocker", IsRocker);
		IsFire = ini.Get_Bool(Name(), "Fire", IsFire);
		IsBright = ini.Get_Bool(Name(), "Bright", IsBright);
		CLDisableRed = ini.Get_Bool(Name(), "CLDisableRed", CLDisableRed);
		CLDisableGreen = ini.Get_Bool(Name(), "CLDisableGreen", CLDisableGreen);
		CLDisableBlue = ini.Get_Bool(Name(), "CLDisableBlue", CLDisableBlue);

		ExplosionSet = TGet_TypeList<AnimTypeClass>(ini, Name(), "AnimList", ExplosionSet);

		InfantryDeath = ini.Get_Int(Name(), "InfDeath", InfantryDeath);

		Deform = ini.Get_Float(Name(), "Deform", Deform);
		DeformThreshhold = ini.Get_Int(Name(), "DeformThreshhold", DeformThreshhold);

		IsEMEffect = ini.Get_Bool(Name(), "EMEffect", IsEMEffect);
		MindControl = ini.Get_Bool(Name(), "MindControl", MindControl);
		IvanBomb = ini.Get_Bool(Name(), "IvanBomb", IvanBomb);
		ElectricAssault = ini.Get_Bool(Name(), "ElectricAssault", ElectricAssault);
		Parasite = ini.Get_Bool(Name(), "Parasite", Parasite);
		Temporal = ini.Get_Bool(Name(), "Temporal", Temporal);
		BombDisarm = ini.Get_Bool(Name(), "BombDisarm", BombDisarm);
		Paralyzes = ini.Get_Int(Name(), "Paralyzes", Paralyzes);
		Culling = ini.Get_Bool(Name(), "Culling", Culling);
		MakesDisguise = ini.Get_Bool(Name(), "MakesDisguise", MakesDisguise);
		NukeMaker = ini.Get_Bool(Name(), "NukeMaker", NukeMaker);

		ProneDamage = ini.Get_Float(Name(), "ProneDamage", ProneDamage);
		Radiation = ini.Get_Bool(Name(), "Radiation", Radiation);
		PsychicDamage = ini.Get_Bool(Name(), "PsychicDamage", PsychicDamage);
		Bullets = ini.Get_Bool(Name(), "Bullets", Bullets);
		IsVeinhole = ini.Get_Bool(Name(), "Veinhole", IsVeinhole);

		ShakeXlo = ini.Get_Int(Name(), "ShakeXlo", ShakeXlo);
		ShakeXhi = ini.Get_Int(Name(), "ShakeXhi", ShakeXhi);
		ShakeYlo = ini.Get_Int(Name(), "ShakeYlo", ShakeYlo);
		ShakeYhi = ini.Get_Int(Name(), "ShakeYhi", ShakeYhi);

		char buffer[128];
		if (ini.Get_String(Name(), "Verses", "100%%,100%%,100%%,100%%,100%%,100%%,100%%,100%%,100%%,100%%,100%%", buffer, sizeof(buffer))) {
			char * aval = strtok(buffer, ",");
			for (int armor = ARMOR_FIRST; armor < ARMOR_COUNT; armor++) {
				Modifier[armor] = _Parse_Percentage(aval);
				aval = strtok(NULL, ",");
			}
		}

		IsOrganic = (Modifier[ARMOR_MEDIUM] == 0 && Modifier[ARMOR_WOOD] == 0);

		return(true);
	}
	return(false);
}

















/// <summary>
/// Removes any reference this warhead holds to the specified object.
/// This routine is called when an object is about to be destroyed so that the warhead
/// will not be left pointing at it.
/// </summary>
void WarheadTypeClass::Detach(AbstractClass const * target, bool all)
{
	if (target == (AbstractClass *)Particle) {
		Particle = NULL;
	}
	ExplosionSet.Delete((AnimTypeClass *)target);
}





/// <summary>
/// Fetches the size this object occupies within a save game.
/// This routine is used by the load code to cope with save games that were written before
/// the web and limpet data was added to the warhead.
/// </summary>
/// <param name="oldsave">Is the size for the older save game layout wanted?</param>
/// <returns>Returns with the number of bytes the object occupies in the save file.</returns>
int WarheadTypeClass::Fetch_Object_Size(void) const // RA2: no argument
{
	return(sizeof(*this));
}


/// <summary>
/// Fetches the RTTI type of this object.
/// </summary>
/// <returns>Returns with the RTTI identifier that marks this object as a warhead type.</returns>
RTTIType WarheadTypeClass::Fetch_RTTI(void) const
{
	return(RTTI_WARHEADTYPE);
}
