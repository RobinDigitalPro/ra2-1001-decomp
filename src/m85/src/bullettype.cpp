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

/* $Header: /CounterStrike/BBDATA.CPP 1     3/03/97 10:24a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : BBDATA.CPP                                                   *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : May 23, 1994                                                 *
 *                                                                                             *
 *                  Last Update : July 19, 1996 [JLB]                                          *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   BulletTypeClass::As_Reference -- Returns with a reference to the bullet type object specif*
 *   BulletTypeClass::BulletTypeClass -- Constructor for bullet type objects.                  *
 *   BulletTypeClass::Init_Heap -- Initialize the heap objects for the bullet type.            *
 *   BulletTypeClass::Load_Shapes -- Load shape data for bullet types.                         *
 *   BulletTypeClass::One_Time -- Performs the one time processing for bullets.                *
 *   BulletTypeClass::Read_INI -- Fetch the bullet type data from the INI database.            *
 *   BulletTypeClass::operator delete -- Deletes a bullet type object from the special heap.   *
 *   BulletTypeClass::operator new -- Allocates a bullet type object from the special heap.    *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define INCLUDE_COM
#include "always.h"

#include "bullettype.h"

#include "_map.h"
#include "_rules.h"
#include "animtype.h"
#include "findmake.h"
#include "globals.h"
#include "incdec.h"
#include "rules.h"
#include "scheme.h"
#include "sun.h"
#include "swizzle.h"
#include "tracker.h"
#include "vector.h"
#include "weapon.h"


/***********************************************************************************************
 * BulletTypeClass::BulletTypeClass -- Constructor for bullet type objects.                    *
 *                                                                                             *
 *    This is basically a constructor for static type objects used by bullets. All bullets     *
 *    are of a type constructed by this routine at game initialization time.                   *
 *                                                                                             *
 * INPUT:   see below...                                                                       *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   10/17/1994 JLB : Created.                                                                 *
 *   07/17/1996 JLB : Uses correct default values.                                             *
 *=============================================================================================*/



/// <summary>
/// Constructs a bullet type object, leaving its data untouched.
/// This constructor is used by the load process, which is about to overwrite the object
/// with the data it reads from the save game file.
/// </summary>
BulletTypeClass::BulletTypeClass(NoInitClass const & x) :
	BASECLASS(x)
{
}





/***********************************************************************************************
 * BulletTypeClass::Read_INI -- Fetch the bullet type data from the INI database.              *
 *                                                                                             *
 *    Use this routine to fetch override information about this bullet type class object       *
 *    from the INI database specified.                                                         *
 *                                                                                             *
 * INPUT:   ini   -- Reference to the INI database to examine.                                 *
 *                                                                                             *
 * OUTPUT:  bool; Was the section for this bullet found and the data extracted?                *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/19/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool BulletTypeClass::Read_INI(CCINIClass const & ini)
{
	if (BASECLASS::Read_INI(ini)) {

		Arming = ini.Get_Int(Name(), "Arm", Arming);
		ROT = ini.Get_Int(Name(), "ROT", ROT);
		CourseLockDuration = ini.Get_Int(Name(), "CourseLockDuration", CourseLockDuration);
		Elasticity = ini.Get_Float(Name(), "Elasticity", Elasticity);
		Acceleration = ini.Get_Int(Name(), "Acceleration", Acceleration);
		Color = ini.Get_Scheme_Index(Name(), "Color", Color);
		IsArcing = ini.Get_Bool(Name(), "Arcing", IsArcing);
		IsFloater = ini.Get_Bool(Name(), "Floater", IsFloater);
		SubjectToCliffs = ini.Get_Bool(Name(), "SubjectToCliffs", SubjectToCliffs);
		SubjectToElevation = ini.Get_Bool(Name(), "SubjectToElevation", SubjectToElevation);
		SubjectToWalls = ini.Get_Bool(Name(), "SubjectToWalls", SubjectToWalls);
		IsVeryHigh = ini.Get_Bool(Name(), "VeryHigh", IsVeryHigh);
		IsShadow = ini.Get_Bool(Name(), "Shadow", IsShadow);
		IsDropping = ini.Get_Bool(Name(), "Dropping", IsDropping);
		Level = ini.Get_Bool(Name(), "Level", Level);
		IsInvisible = ini.Get_Bool(Name(), "Inviso", IsInvisible);
		IsProximityArmed = ini.Get_Bool(Name(), "Proximity", IsProximityArmed);
		IsFueled = ini.Get_Bool(Name(), "Ranged", IsFueled);
		IsInaccurate = ini.Get_Bool(Name(), "Inaccurate", IsInaccurate);
		FlakScatter = ini.Get_Bool(Name(), "FlakScatter", FlakScatter);
		IsAntiAircraft = ini.Get_Bool(Name(), "AA", IsAntiAircraft);
		IsAntiGround = ini.Get_Bool(Name(), "AG", IsAntiGround);
		IsDegenerate = ini.Get_Bool(Name(), "Degenerates", IsDegenerate);
		IsBouncy = ini.Get_Bool(Name(), "Bouncy", IsBouncy);
		IsAirburst = ini.Get_Bool(Name(), "Airburst", IsAirburst);
		Cluster = ini.Get_Int(Name(), "Cluster", Cluster);
		Scalable = ini.Get_Bool(Name(), "Scalable", Scalable);

		if (ini.Get_String(Name(), "Image", "", GraphicName, GraphicName.Size()) > 0) {
			Trailer = TGet_Class(ArtINI, Graphic_Name(), "Trailer", Trailer);
			SpawnDelay = ArtINI.Get_Int(Graphic_Name(), "SpawnDelay", SpawnDelay);
			IsFaceless = !ArtINI.Get_Bool(Graphic_Name(), "Rotates", !IsFaceless);
			Flat = ArtINI.Get_Bool(Graphic_Name(), "Flat", Flat);
		}

		AirburstWeapon = TGet_Class(ini, Name(), "AirburstWeapon", AirburstWeapon);
		ShrapnelWeapon = TGet_Class(ini, Name(), "ShrapnelWeapon", ShrapnelWeapon);
		ShrapnelCount = ini.Get_Int(Name(), "ShrapnelCount", ShrapnelCount);
		DetonationAltitude = ini.Get_Int(Name(), "DetonationAltitude", DetonationAltitude);
		Vertical = ini.Get_Bool(Name(), "Vertical", Vertical);
		FirersPalette = ini.Get_Bool(Name(), "FirersPalette", FirersPalette);

		AnimLow = ArtINI.Get_Int(Graphic_Name(), "AnimLow", AnimLow);
		AnimHigh = ArtINI.Get_Int(Graphic_Name(), "AnimHigh", AnimHigh);
		AnimRate = ArtINI.Get_Int(Graphic_Name(), "AnimRate", AnimRate);

		IsAnimPalette = ArtINI.Get_Bool(Graphic_Name(), "AnimPalette", IsAnimPalette);

		if (!IsInvisible) {
			Fetch_Normal_Image();
		}
		if (IsVoxel) {
			Fetch_Voxel_Image();
		}

		return(true);
	}
	return(false);
}


/// <summary>
/// Converts an ASCII bullet name into a bullet type number.
/// This routine is used by the rules parser. A name that is not already known will be
/// added to the bullet database rather than rejected.
/// </summary>
/// <param name="name">Pointer to the ASCII name of the bullet type.</param>
/// <returns>Returns with the bullet type of that name. If no name was supplied, or the
/// name is the "none" placeholder, then BULLET_NONE is returned.</returns>
BulletType BulletTypeClass::From_Name(char const * name)
{
	if (stricmp(name, "<none>")) {
		for (int index = BULLET_FIRST; index < BulletTypes.Count(); index++) {
			if (stricmp(name, BulletTypes[index]->Name()) == 0) {
				return(BulletType(index));
			}
		}
		BulletTypeClass *ptr = new BulletTypeClass(name);
		return(BulletType(BulletTypes.ID(ptr)));

	}
	return(BULLET_NONE);
}


/// <summary>
/// Converts a bullet type number into its ASCII name.
/// </summary>
/// <param name="bullet">The bullet type to fetch the name of.</param>
/// <returns>Returns with the name of the bullet type. If the type is not a legal one,
/// then NULL is returned.</returns>
const char * BulletTypeClass::Name_From(BulletType bullet)
{
	if ((unsigned)bullet < (unsigned)BulletTypes.Count()) {
		return(BulletTypes[bullet]->Name());
	}
	return(NULL);
}


/// <summary>
/// Adjusts a coordinate so that it is legal for a bullet of this type.
/// This routine lifts the coordinate clear of the terrain, so that a bullet is never
/// created or moved to a spot buried in the landscape.
/// </summary>
/// <param name="coord">The coordinate to be adjusted.</param>
/// <returns>Returns with the adjusted coordinate.</returns>
Coord const BulletTypeClass::Coord_Fixup(Coord const & coord) const
{
	Coord c = coord;
	int height = Map.Get_Height_GL(c);
	int z = c.Z;
	if (z <= height) {
		z = Map.Get_Height_GL(c) + 1;
	}
	c.Z = z;
	return(c);
}

















/// <summary>
/// Removes any reference this bullet type holds to the object specified.
/// This routine is called when an object is about to leave the game, so that no bullet
/// type is left pointing at it.
/// </summary>
/// <param name="target">Pointer to the object that is going away.</param>
void BulletTypeClass::Detach(AbstractClass const * target, bool all)
{
	if (target == Trailer) {
		Trailer = NULL;
	}
}


/**
 *  RA2: Sets the spawn delay scaled for the bullet's speed.
 */
void BulletTypeClass::SetScaledSpawnDelay(int delay)
{
	ScaledSpawnDelay = delay;
}


/// <summary>
/// Fetches the run time type of this object.
/// </summary>
/// <returns>Returns with RTTI_BULLETTYPE.</returns>
RTTIType BulletTypeClass::Fetch_RTTI(void) const
{
	return(RTTI_BULLETTYPE);
}


/// <summary>
/// Fetches the size this object occupies in a save game file.
/// This routine is used by the load process, which must know how much smaller a bullet
/// type was in save games written before the later members were added.
/// </summary>
/// <param name="oldsave">Is the size wanted for the older save game layout?</param>
/// <returns>Returns with the number of bytes this object occupies in the save file.</returns>
int BulletTypeClass::Fetch_Object_Size(void) const
{
	return(sizeof(*this));
}
