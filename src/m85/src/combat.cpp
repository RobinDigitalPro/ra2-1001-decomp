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

/* $Header: /CounterStrike/COMBAT.CPP 1     3/03/97 10:24a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : COMBAT.CPP                                                   *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : September 19, 1994                                           *
 *                                                                                             *
 *                  Last Update : July 26, 1996 [JLB]                                          *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   Combat_Anim -- Determines explosion animation to play.                                    *
 *   Explosion_Damage -- Inflict an explosion damage affect.                                   *
 *   Modify_Damage -- Adjusts damage to reflect the nature of the target.                      *
 *   Wide_Area_Damage -- Apply wide area damage to the map.                                    *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"
#include "geoconst1.h" // level-2 1.001: per-module geometry constants (combat's own BRIDGE_LEPTON_HEIGHT copy at 0x839018, LEVEL_LEPTON_H at 0x839028)

#include "combat.h"

#include "_map.h"
#include "_rtti.h"
#include "_rules.h"
#include "_tactica.h"
#include "aircraft.h"
#include "anim.h"
#include "bound.h"
#include "building.h"
#include "builtype.h"
#include "ccrand.h"
#include "cell.h"
#include "globals.h"
#include "goptions.h" // RA2: Options.DetailLevel gates the combat light
#include "incdec.h"
#include "infantry.h"
#include "infatype.h"
#include "inline.h"
#include "isotype.h"
#include "mouse.h"
#include "overtype.h"
#include "ovrlight.h"
#include "partsys.h"
#include "psystype.h"
#include "rules.h"
#include "scenario.h"
#include "stimer.h"
#include "tactical.h"
#include "team.h"
#include "teamtype.h"
#include "tiberium.h"
#include "tracker.h" // level-2 1.001: Explosion_Damage gathers aircraft through the AircraftTracker
#include "unit.h"
#include "unittype.h"
#include "vanim.h"
#include "vein.h"
#include "warhead.h"

#include "mph.hh"
#include "geoconst2.h" // level-2 1.001: this module holds its own copy (per-TU constant addresses; GAMECONST block initializers 0x7dbd0..0x7dda0, now in TU_47DBF0)

#include <windef.h>
inline static int Explosion_Distance(Coord const & coord1, Coord const & coord2); // RA2: defined after its first caller

namespace FPSCounter { extern unsigned CurrentFrameRate; }
namespace Detail { unsigned GetMinFrameRate(void); }

/*
**	level-2 1.001: Explosion_Damage keeps one {object, distance} group per object in its
**	damage list (YR name DamageGroup), so each distance is measured while the list is built.
*/
struct DamageGroup
{
	ObjectClass * Object;
	int Distance;
};

static inline bool Is_Curtained_Techno(ObjectClass * object) // level-2 1.001: the Is_Techno test is read into a byte temporary
{
	if (object == NULL) return(false);
	bool const & techno = (object->AbstractFlags & 1);
	return(techno && ((TechnoClass *)object)->Unknown_Virtual_32C());
}



/***********************************************************************************************
 * Modify_Damage -- Adjusts damage to reflect the nature of the target.                        *
 *                                                                                             *
 *    This routine is the core of combat tactics. It implements the                            *
 *    affect various armor types have against various weapon types. By                         *
 *    careful exploitation of this table, tactical advantage can be                            *
 *    obtained.                                                                                *
 *                                                                                             *
 * INPUT:   damage   -- The damage points to process.                                          *
 *                                                                                             *
 *          warhead  -- The source of the damage points.                                       *
 *                                                                                             *
 *          armor    -- The type of armor defending against the damage.                        *
 *                                                                                             *
 *          distance -- The distance (in leptons) from the source of the damage.               *
 *                                                                                             *
 * OUTPUT:  Returns with the adjusted damage points to inflict upon the                        *
 *          target.                                                                            *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   04/16/1994 JLB : Created.                                                                 *
 *   04/17/1994 JLB : Always does a minimum of damage.                                         *
 *   01/01/1995 JLB : Takes into account distance from damage source.                          *
 *   04/11/1996 JLB : Changed damage fall-off formula for less damage fall-off.                *
 *=============================================================================================*/
int Modify_Damage(int damage, WarheadTypeClass const * warhead, ArmorType armor, int distance)
{
	if (!damage || Scen->Special.IsInert || warhead == NULL) return(0);

	if (damage < 0) {
		if (distance < 8) return(damage); // RA2: Modify_Damage at 0x47E1C0 matches only so
		return(0);
	}

	float fdamage = (float)damage; // RA2: as above
	float fmin = fdamage * warhead->PercentAtMax; // RA2: as above
	int spread = (int)(warhead->SpreadFactor * 256.0f); // RA2: as above
	if (fmin != fdamage && spread) { // RA2: as above
		damage = (int)((fdamage - fmin) * (spread - distance) / spread + fmin); // RA2: as above
	}

	damage = MAX(damage, 0); // RA2: as above
	damage = (int)(damage * warhead->Modifier[armor]); // RA2: as above
	return(MIN(damage, Rule->MaxDamage)); // RA2: as above
} // RA2: Modify_Damage at 0x47E1C0 has no Bound, MAX, Rule and 3 more


/// <summary>
/// Handles the chain reaction of a tiberium field.
/// This routine is called when a cell of chain reactive growth is disturbed. The tiberium
/// there goes up, damaging whatever is standing in the blast, and the neighboring growth
/// is set off in turn so that the reaction ripples across the field.
/// </summary>
/// <param name="cell">The cell whose growth should be set off.</param>
void Chain_Reaction_Damage(Cell const & cell)
{
	// RA2: empty in RA2 (a bare ret at 0x47E2B0)
}


/***********************************************************************************************
 * Explosion_Damage -- Inflict an explosion damage affect.                                     *
 *                                                                                             *
 *    Processes the collateral damage affects typically caused by an                           *
 *    explosion.                                                                               *
 *                                                                                             *
 * INPUT:   coord    -- The coordinate of ground zero.                                         *
 *                                                                                             *
 *          strength -- Raw damage points at ground zero.                                      *
 *                                                                                             *
 *          source   -- Source of the explosion (who is responsible).                          *
 *                                                                                             *
 *          warhead  -- The kind of explosion to process.                                      *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   This routine can consume some time and will affect the AI                       *
 *             of nearby enemy units (possibly).                                               *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   08/16/1991 JLB : Created.                                                                 *
 *   11/30/1991 JLB : Uses coordinate system.                                                  *
 *   12/27/1991 JLB : Radius of explosion damage effect.                                       *
 *   04/13/1994 JLB : Streamlined.                                                             *
 *   04/16/1994 JLB : Warhead damage type modifier.                                            *
 *   04/17/1994 JLB : Cleaned up.                                                              *
 *   06/20/1994 JLB : Uses object pointers to distribute damage.                               *
 *   06/20/1994 JLB : Source is a pointer.                                                     *
 *   06/18/1996 JLB : Strength could be negative for healing effects.                          *
 *=============================================================================================*/
int Explosion_Damage(Coord const & coord, int strength, TechnoClass * source, WarheadTypeClass const * warhead, bool dochainreaction) // level-2 1.001: returns 0 (hit), 1 (missed) or 2 (nullified)
{
	DynamicVectorClass<DamageGroup *>	groups;		// The objects that will have damage assessed upon them.
	ObjectClass *						object;		// Working object pointer.
	int									distance;	// Distance to unit.
	int									range;		// Damage effect radius.

	if (!strength || Scen->Special.IsInert || warhead == NULL) return(1); // level-2 1.001

	range = (int)(warhead->SpreadFactor * CELL_LEPTON_W); // level-2 1.001: the range is the warhead's CellSpread
	Cell cell = coord.As_Cell();
	CellClass * cellptr = &Map[cell];

	bool isbridge = false;
	bool damaged = false;
	bool nullified = false;
	bool pinpoint = (warhead->SpreadFactor <= 0.5f); // level-2 1.001

	/*
	**	level-2 1.001: aircraft above the explosion are gathered through the aircraft tracker.
	*/
	if (Map.Get_Height_GL(cell) < coord.Z) {
		AircraftTracker.Append_Radius_Bins(cellptr, (int)warhead->SpreadFactor);
		for (FootClass * aircraft = AircraftTracker.Get(); aircraft != NULL; aircraft = AircraftTracker.Get()) {
			if (aircraft->IsActive && aircraft->IsDown && aircraft->Strength > 0) {
				distance = coord.Distance_To(aircraft->PositionCoord);
				if (distance <= range) {
					if (pinpoint && distance < CELL_LEPTON_W/3 && aircraft->Unknown_Virtual_32C()) {
						nullified = true;
					}
					DamageGroup * group = new DamageGroup;
					group->Object = aircraft;
					group->Distance = coord.Distance_To(aircraft->PositionCoord);
					groups.Add(group);
				}
			}
		}
	}

	if (cellptr->IsUnderBridge && coord.Z > Map.Get_Height_GL(coord) + BRIDGE_LEPTON_HEIGHT / 2) {
		isbridge = true;
	}

	/*
	**	Fill the list of objects that will have damage assessed upon them. The
	**	cells are scanned outward through the warhead's spread.
	*/
	int spread = (int)(warhead->SpreadFactor + 0.99); // level-2 1.001
	for (int i = 0; i < MapClass::RadiusCount[spread]; i++) {
		TPoint2D<short> tcell = cell + MapClass::RadiusOffset[i]; // level-2 1.001: the sum is a named TPoint2D (two objects: cell X added first, then the copy to the Map[] Cell); INFERRED form, cf. gibbo101 YR 'Cell tcell = cell + CellSpreadTable[m]' (src/combat.cpp @719fcc7)
		cellptr = &Map[tcell];

		/*
		**	If there is a wall present at this location, it may be destroyed. Check to
		**	make sure that the warhead is of the kind that can destroy walls.
		*/
		if (cellptr->Overlay != OVERLAY_NONE) {
			OverlayTypeClass const * optr = OverlayTypes[cellptr->Overlay];

			if (optr->IsChainReaction && (!optr->IsTiberium || warhead->IsTiberiumDestroyer) && dochainreaction) {
				cellptr->Reduce_Tiberium(strength / 10);
			}

			if (optr->IsWall) {
				if (warhead->WallAbsoluteDestroyer) {
					cellptr->Reduce_Wall(-1);
				} else if (warhead->IsWallDestroyer || (warhead->IsWoodDestroyer && optr->Armor == ARMOR_WOOD)) {
					cellptr->Reduce_Wall(strength);
				}
			}

			if (cellptr->Overlay == OVERLAY_NONE) {
				TechnoClass::Remove_Target(cellptr);
			}
		}

		for (object = cellptr->Cell_Occupier(isbridge); object != NULL; object = object->Next) {
			if (object != source && object->IsActive) {
				if (object->RTTI == RTTI_UNIT && Scen->Special.IsHarvesterImmune && Rule->HarvesterUnit.Is_In_List((UnitTypeClass *)object->Class_Of())) continue;

				if (pinpoint && i == 0 && Is_Curtained_Techno(object)) {
					nullified = true;
				}

				DamageGroup * group = new DamageGroup;
				group->Object = object;
				if (object->RTTI == RTTI_BUILDING) {
					if (i == 0) {
						if (coord.Z - cellptr->Center_Coord().Z > LEVEL_LEPTON_H * 2) {
							group->Distance = coord.Distance_To(cellptr->Center_Coord()) - LEVEL_LEPTON_H * 2;
						} else {
							group->Distance = 0;
						}
					} else {
						group->Distance = coord.Distance_To(cellptr->Center_Coord());
					}
				} else {
					group->Distance = coord.Distance_To(object->Target_Coord());
				}
				groups.Add(group);
			}
		}
	}

	/*
	**	Sweep through the objects to be damaged and damage them.
	*/
	for (int index = 0; index < groups.Count(); index++) {
		object = groups[index]->Object;
		distance = groups[index]->Distance;

		if (object->IsActive && (object->RTTI != RTTI_BUILDING || !((BuildingClass *)object)->Class->IsInvisibleInGame)) {
			if (nullified && !Is_Curtained_Techno(object)) continue;

			if (object->RTTI == RTTI_AIRCRAFT && object->In_Air()) {
				distance /= 2;
			}
			if (object->Strength > 0 && object->IsDown && !object->IsInLimbo && distance <= range) {
				int damage = strength;
				object->Take_Damage(damage, distance, warhead, source);
				damaged = true;
			}
		}
	}

	for (int g = 0; g < groups.Count(); g++) {
		delete groups[g];
	}
	groups.Delete_All();

	if (nullified) return(2); // level-2 1.001

	double rocking_force = MIN(strength * 0.01, 4.0);
	if (warhead->IsRocker && rocking_force > 0.3) {
		for (int x = cell.X - 3; x <= cell.X + 3; x++) {
			for (int y = cell.Y - 3; y <= cell.Y + 3; y++) {
				// level-2 1.001: a loop-scoped occupier (gives the 1.001 code of the building Distance_To)
				for (ObjectClass * occupier = isbridge ? Map[Cell(x, y)].Cell_Bridge_Occupier() : Map[Cell(x, y)].Cell_Occupier(false); occupier != NULL; occupier = occupier->Next) { // level-2 1.001: the bridge arm uses Cell_Bridge_Occupier() (as gibbo101 YR src/combat.cpp @719fcc7); keeps the occupier in EAX
					TechnoClass * techno = Dynamic_Cast<TechnoClass *>(occupier);
					if (techno != NULL) {
						if (Cell(x, y) == cell && source) {
							Coord tcoord = techno->PositionCoord;

							Coord scoord = source->PositionCoord;
							TPoint3D<float> rockdirf((float)(scoord.X - tcoord.X), (float)(scoord.Y - tcoord.Y), (float)(scoord.Z - tcoord.Z));
							rockdirf = rockdirf.Normalize() * 10;

							tcoord += Coord(rockdirf.X, rockdirf.Y, rockdirf.Z);
							techno->Rock(tcoord, rocking_force);
						} else {
							techno->Rock(coord, rocking_force);
						}
					}
				}
			}
		}
	}

	/*
	**	If there is a bridge at this location, then it may be destroyed by the
	**	combat damage.
	*/
	bool ion_cannon = warhead == Rule->IonCannonWarhead;
	if (Scen->Special.IsDestroyBridges && warhead->IsWallDestroyer) {

		IsometricTileType ittype1 = IsometricTileType(cellptr->ITType - IsometricTileTypeClass::BridgeSet + 1);
		CellClass * bridge_deck = NULL; // level-2 1.001: written out in place (not Get_Bridge_Deck_CellClass); both deck Cell temporaries then share one frame slot as in 1.001
		if (cellptr->IsUnderBridge) {
			if (cellptr->IsBridgeDeck) {
				bridge_deck = &Map[cellptr->Fetch_CellID()];
			} else {
				bridge_deck = &Map[cellptr->BridgeDeckCell->Fetch_CellID()];
			}
		}

		if (bridge_deck && bridge_deck->Is_Overlay_Bridge() ||
			ittype1 == IsometricTileTypeClass::BridgeMiddle1 + 0 || ittype1 == IsometricTileTypeClass::BridgeMiddle1 + 1 ||
			ittype1 == IsometricTileTypeClass::BridgeMiddle1 + 2 || ittype1 == IsometricTileTypeClass::BridgeMiddle1 + 3 ||
			ittype1 == IsometricTileTypeClass::BridgeMiddle2 + 0 || ittype1 == IsometricTileTypeClass::BridgeMiddle2 + 1 ||
			ittype1 == IsometricTileTypeClass::BridgeMiddle2 + 2 || ittype1 == IsometricTileTypeClass::BridgeMiddle2 + 3) {
			if (!cellptr->IsUnderBridge || coord.Z <= BRIDGE_LEPTON_HEIGHT + LEVEL_LEPTON_H * (cellptr->Height + 1) && coord.Z > BRIDGE_LEPTON_HEIGHT + LEVEL_LEPTON_H * (cellptr->Height - 2)) {
				if (warhead->IsWallDestroyer && (warhead == Rule->IonCannonWarhead || Random_Pick(1, Rule->BridgeStrength) < strength)) {
					bool bridge_damaged = false;
					int tries=4;
					do {
						bridge_damaged = Map.Damage_Bridge(cell);
						tries--;
						if (bridge_damaged) {
							break;
						}
					} while (ion_cannon && tries > 0);

					if (bridge_damaged) {
						TechnoClass::Remove_Target(cellptr);
					}
					Point2D point;
					TacticalMap->Coord_To_Pixel(coord, point);
					TacticalMap->Register_Dirty_Area(Rect(point.X - 128, point.Y - 128, 256, 256), false);
				}
			}
		}

		IsometricTileType ittype2 = IsometricTileType(cellptr->ITType - IsometricTileTypeClass::TrainBridgeSet + 1);

		if (bridge_deck && bridge_deck->Is_Overlay_Rail_Bridge() || // level-2 1.001: the rail bridge overlays are 0xED/0xEE (cell.h)
			ittype2 == IsometricTileTypeClass::BridgeMiddle1 + 0 || ittype2 == IsometricTileTypeClass::BridgeMiddle1 + 1 ||
			ittype2 == IsometricTileTypeClass::BridgeMiddle1 + 2 || ittype2 == IsometricTileTypeClass::BridgeMiddle1 + 3 ||
			ittype2 == IsometricTileTypeClass::BridgeMiddle2 + 0 || ittype2 == IsometricTileTypeClass::BridgeMiddle2 + 1 ||
			ittype2 == IsometricTileTypeClass::BridgeMiddle2 + 2 || ittype2 == IsometricTileTypeClass::BridgeMiddle2 + 3) {
			if (!cellptr->IsUnderBridge || coord.Z <= BRIDGE_LEPTON_HEIGHT + LEVEL_LEPTON_H * (cellptr->Height + 1) && coord.Z > BRIDGE_LEPTON_HEIGHT + LEVEL_LEPTON_H * (cellptr->Height - 2)) {
				if (warhead->IsWallDestroyer && (warhead == Rule->IonCannonWarhead || Random_Pick(1, Rule->BridgeStrength) < strength)) {
					bool bridge_damaged = false;
					int tries=4;
					do {
						bridge_damaged = Map.Damage_Bridge(cell);
						tries--;
						if (bridge_damaged) {
							break;
						}
					} while (ion_cannon && tries > 0);

					if (bridge_damaged) {
						TechnoClass::Remove_Target(cellptr);
					}
					Point2D point;
					TacticalMap->Coord_To_Pixel(coord, point);
					TacticalMap->Register_Dirty_Area(Rect(point.X - 96, point.Y - 96, 192, 192), false);
				}
			}
		}

		if (cellptr->Overlay >= OVERLAY_LOWBRIDGE_01 && cellptr->Overlay <= OVERLAY_LOWBRIDGE_26) {
			if (warhead == Rule->IonCannonWarhead || Random_Pick(1, Rule->BridgeStrength) < strength) {
				bool destroyed = Map.Damage_Low_Bridge(cell);
				Map.Damage_Low_Bridge(cell);
				if (destroyed) {
					TechnoClass::Remove_Target(cellptr);
				}
			}
		}

		if (cellptr->Overlay >= OVERLAY_LOWBRIDGE2_01 && cellptr->Overlay <= OVERLAY_LOWBRIDGE2_01 + 25) { // level-2 1.001: the second low bridge kind
			if (warhead == Rule->IonCannonWarhead || Random_Pick(1, Rule->BridgeStrength) < strength) {
				bool destroyed = Map.Damage_Low_Bridge2(cell);
				Map.Damage_Low_Bridge2(cell);
				if (destroyed) {
					TechnoClass::Remove_Target(cellptr);
				}
			}
		}
	}

	if (cellptr->Overlay != OVERLAY_NONE && OverlayTypes[cellptr->Overlay]->IsExplosive) {
		cellptr->Register_For_Redraw();
		cellptr->Overlay = OVERLAY_NONE;
		cellptr->Recalc_Attributes();
		Map.Update_Cell_Zone(cellptr->CellID);
		Map.Update_Cell_Subzones(cellptr->CellID);
		TechnoClass::Remove_Target(cellptr);

		new AnimClass(Rule->BarrelExplode, coord);
		Explosion_Damage(coord, Rule->AmmoCrateDamage, NULL, Rule->C4Warhead, true);
		for (int i = 0; i < Rule->BarrelDebris.Count(); i++) {
			if (Percent_Chance(15)) {
				new VoxelAnimClass(Rule->BarrelDebris[i], coord);
				break;
			}
		}
		if (Percent_Chance(25)) {
			ParticleSystemClass * psys = new ParticleSystemClass(Rule->BarrelParticle, coord);
			psys->Spawn_Held_Particle(coord, coord);
		}
	} // level-2 1.001: no fire on adjacent explosive overlays, no terrain deform, cliff collapse or ice cracking

	if (warhead->Particle) {
		ParticleSystemClass * psys;
		if (warhead->Particle->BehavesLike == PSYS_BEHAVIOR_GAS) {
			psys = GasSystem;
		} else {
			psys = new ParticleSystemClass(warhead->Particle, coord);
		}
		psys->Spawn_Held_Particle(coord, coord);
	}

	return(!damaged); // level-2 1.001
}


/***********************************************************************************************
 * Combat_Anim -- Determines explosion animation to play.                                      *
 *                                                                                             *
 *    This routine is called when a projectile impacts. This routine will determine what       *
 *    animation should be played.                                                              *
 *                                                                                             *
 * INPUT:   damage   -- The amount of damage this warhead possess (warhead size).              *
 *                                                                                             *
 *          warhead  -- The type of warhead.                                                   *
 *                                                                                             *
 *          land     -- The land type that this explosion is over. Sometimes, this makes       *
 *                      a difference (especially over water).                                  *
 *                                                                                             *
 * OUTPUT:  Returns with the animation to play. If no animation is to be played, then          *
 *          ANIM_NONE is returned.                                                             *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/19/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
AnimTypeClass const * Combat_Anim(int damage, WarheadTypeClass const * warhead, LandType land, Coord const & coord)
{
	if (damage == 0 || warhead == NULL) { // RA2: Combat_Anim at 0x47F4D0 has no enum {
		return(NULL);
	}

	if (land == LAND_WATER && warhead->IsConventional && !Map[coord].IsUnderBridge && coord.Z < Map.Get_Height_GL(coord) + LEVEL_LEPTON_H * 2) { // RA2: Combat_Anim at 0x47F4D0 matches only so
		if (Rule->SplashList.Count()) {
			int val = MIN(damage, 35 * Rule->SplashList.Count() - 1); // RA2: as above
			return(Rule->SplashList[val / 35]); // RA2: as above
		}
		return(NULL);
	}

	if (warhead == Rule->LightningWarhead) { // RA2: as above
		return(Rule->WeatherConBoltExplosion); // RA2: as above
	}

	if (warhead->ExplosionSet.Count()) {
		if (warhead->IsEMEffect) {
			return(warhead->ExplosionSet[Random_Pick(0, warhead->ExplosionSet.Count() - 1)]);
		}
		int val = MIN(damage, 25 * warhead->ExplosionSet.Count() - 1); // RA2: as above
		return(warhead->ExplosionSet[val / 25]); // RA2: as above
	}

	return(NULL);
}


/// <summary>
/// Creates the lighting flash of an explosion.
/// This routine is called alongside the explosion animation so that a bright warhead
/// briefly lights up the terrain around the blast.
/// </summary>
/// <param name="coord">The coordinate the blast is centered upon.</param>
/// <param name="damage">The strength of the blast, which governs the size of the flash.</param>
/// <param name="forced">Should the flash occur even if the warhead is not a bright one?</param>
void Combat_Lighting(Coord coord, int damage, WarheadTypeClass const * warhead, int forced, int flags) // RA2: 0x47F600 takes the forced flag as an int and a fifth argument, the light kind flags
{
	if ((Options.DetailLevel != 0 && FPSCounter::CurrentFrameRate >= Detail::GetMinFrameRate()) || (flags & 0xF) != 0) { // RA2: the detail level and frame rate gate, bypassed by the flags
		if ((char)forced || warhead != NULL && warhead->IsBright) { // RA2: forced is tested by its low byte
			int size; // RA2: as above
			float light = warhead->CombatLightSize; // RA2: the warhead's own light size takes precedence
			if (light > 0.0f) { // RA2: as above
				if (light > 1.0f) { // RA2: as above
					light = 1.0f; // RA2: as above
				}
				size = (int)(light * 63.0f); // RA2: as above
			} else { // RA2: as above
				damage *= 64; // RA2: as above
				size = damage >> 8; // RA2: as above
				if (size >= 63) { // RA2: as above
					size = 63; // RA2: as above
				} else if (size <= 21) { // RA2: as above
					size = 21; // RA2: as above
				}
			}

			SpotLightClass * spot = new SpotLightClass(coord, size); // RA2: the light is kept to set its flags
			spot->Disable(flags); // RA2: the flags are ORed into the light
		}
	}
}




/***********************************************************************************************
 * Wide_Area_Damage -- Apply wide area damage to the map.                                      *
 *                                                                                             *
 *    This routine will apply damage to a very wide area on the map. The damage will be        *
 *    spread out from the coordinate specified by the radius specified. The amount of damage   *
 *    will attenuate according to the distance from center.                                    *
 *                                                                                             *
 * INPUT:   coord    -- The coordinate that the explosion damage will center about.            *
 *                                                                                             *
 *          radius   -- The radius of the explosion.                                           *
 *                                                                                             *
 *          damage   -- The amount of damage to apply at the center location.                  *
 *                                                                                             *
 *          source   -- Pointer to the purpetrator of the damage (if any).                     *
 *                                                                                             *
 *          warhead  -- The type of warhead that is causing the damage.                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/26/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void Wide_Area_Damage(Coord const & coord, LEPTON radius, int rawdamage, TechnoClass * source, WarheadTypeClass const * warhead)
{
	if (warhead == NULL) return;

	int cell_radius = (radius + CELL_LEPTON_W-1) / CELL_LEPTON_W;
	Cell cell = coord.As_Cell();

	for (int x = -cell_radius; x <= cell_radius; x++) { // RA2: Wide_Area_Damage at 0x47F6E0 has no DeformThreshhold, Deform, Map
		for (int y = -cell_radius; y <= cell_radius; y++) {
			int xpos = cell.X + x;
			int ypos = cell.Y + y;
			if ((unsigned)xpos > MAP_CELL_W) {
				continue;
			}
			if ((unsigned)ypos > MAP_CELL_H) {
				continue;
			}
			Cell tcell = Cell(xpos, ypos);
			if (!Map.In_Radar(tcell)) continue;

			int dist_from_center = Distance(Coord(x+cell_radius, y+cell_radius), Coord(cell_radius, cell_radius));
			double damagemod = 1;
			if (dist_from_center > 0) {
				damagemod = 1.0 / ((double)cell_radius / dist_from_center);
			}
			Coord tcoord(tcell, coord.Z); // RA2: Wide_Area_Damage at 0x47F6E0 matches only so
			Explosion_Damage(tcoord, rawdamage * damagemod, source, warhead);
		}
	}
}


/// <summary>
/// Determines the pitch to launch a ballistic projectile at.
/// This is the routine the weapon code calls when it wants to lob something at a target.
/// It takes the solution from Calculate_Projectile_Angle and turns it into a pitch the launcher
/// can be aimed with, correcting the flat solution when it would send the shot skyward.
/// </summary>
/// <param name="high_arc">Should the shot be lobbed rather than fired flat?</param>
/// <param name="speed">The speed the projectile will be launched at.</param>
/// <param name="distance">The horizontal distance to the target.</param>
/// <param name="height">The height of the target relative to the launch point.</param>
/// <param name="gravity">The gravity that will act upon the projectile.</param>
/// <param name="pitch">Reference to the pitch to be filled in.</param>
/// <returns>bool; Was a firing solution found?</returns>
bool Calculate_Projectile_Pitch(bool high_arc, int speed, int distance, int height, double gravity, DirType & pitch)
{
	double angle;
	if (Calculate_Projectile_Angle(high_arc, speed, distance, height, gravity, angle)) {
		if (high_arc) {
			pitch = DirType(angle);
			return(true);
		}

		double test;
		Calculate_Projectile_Angle(false, speed, distance + 1, height, gravity, test);
		if (test < angle) {
			pitch = DirType(-angle);
		} else {
			pitch = DirType(angle);
		}
		return(true);
	}
	return(false);
}


/// <summary>
/// Determines the elevation angle for a ballistic shot.
/// This routine solves the projectile equation for the angle that will drop the shot onto
/// the target. A reachable target usually has two answers -- a flat fast one and a lobbed
/// one -- and the caller says which of them it wants.
/// </summary>
/// <param name="high_arc">Should the lobbed solution be returned rather than the flat one?</param>
/// <param name="speed">The speed the projectile will be launched at.</param>
/// <param name="distance">The horizontal distance to the target.</param>
/// <param name="height">The height of the target relative to the launch point.</param>
/// <param name="gravity">The gravity that will act upon the projectile.</param>
/// <param name="angle">Reference to the angle, in radians, to be filled in.</param>
/// <returns>bool; Was a firing solution found?</returns>
bool Calculate_Projectile_Angle(bool high_arc, int speed, int distance, int height, double gravity, double & angle)
{
	if (height > 0) { // RA2: Calculate_Projectile_Angle at 0x47F9B0 matches only so
		angle = 0.7853822499999998; // RA2: as above
		return(true); // RA2: as above
	}

	if ((double)distance == 0.0) {
		distance = 0;
	}

	double dx = (double)distance;
	double velocity = (double)speed; // RA2: as above
	double dy = (double)height;
	double v = velocity; // RA2: as above

	double vsq = v * v; // RA2: Calculate_Projectile_Angle at 0x47F9B0 has no double dy2 = dy * dy;
	double base = vsq - ((double)height * gravity); // RA2: as above
	double g2 = gravity * gravity;
	double dx2 = (dx * dx); // RA2: as above

	double value = (v * v * vsq)
				 - (2 * vsq * dy * gravity)
				 - (g2 * dx2);

	double denominator = (((dy * dy) / dx2) + 1.0) * 2; // RA2: as above

	if (value < 0.0 || denominator == 0.0) {
		return(false); // RA2: as above
	}

	double numerator = !high_arc ? base + fastmath::sqrt(value)
								  : base - fastmath::sqrt(value);

	value = numerator / denominator;

	if (value >= 0.0) {
		angle = fastmath::acos(fastmath::sqrt(value) / v);
		return(true);
	}
	return(false);
}


/// <summary>
/// RA2
/// </summary>
bool Calculate_Projectile_Dir(int speed, int distance, int height, double gravity, DirType & dir)
{
	double angle;
	if (Calculate_Projectile_Angle(false, speed, distance, height, gravity, angle)) {
		if (angle < 0.0) {
			angle += M_PI * 2;
		}
		dir = DirType(angle);
		return(true);
	}
	return(false);
}


/// <summary>
/// Determines the launch speed needed to cover a range.
/// This routine is used by artillery style weapons to pick a muzzle velocity that will
/// carry the shot out as far as the target sits.
/// </summary>
/// <param name="range">The distance the projectile must cover.</param>
/// <param name="gravity">The gravity that will act upon the projectile.</param>
/// <returns>Returns with the speed to launch the projectile at.</returns>
MPHType Calculate_Projectile_Speed(int range, double gravity)
{
	return((MPHType)(int)fastmath::sqrt((double)range * gravity * 1.2));
}


/// <summary>
/// Can a ballistic projectile reach the target at all?
/// This routine is used before a lobbed weapon is allowed to fire so that the object does
/// not line up a shot that gravity will never let it complete.
/// </summary>
/// <param name="speed">The speed the projectile would be launched at.</param>
/// <param name="distance">The horizontal distance to the target.</param>
/// <param name="height">The height of the target relative to the launch point.</param>
/// <param name="gravity">The gravity that will act upon the projectile.</param>
/// <returns>bool; Does a firing solution exist?</returns>
bool Is_Projectile_Trajectory_Valid(int speed, int distance, int height, double gravity)
{
	double v = (double)speed;
	double dx = (double)distance;
	if (dx == 0.0) dx = 0.001; // RA2: Is_Projectile_Trajectory_Valid at 0x47FBA0 matches only so
	double dy = (double)height;

	double y2 = dy * dy;
	double vsq = v * v;
	double g2 = gravity * gravity;
	double x2 = dx * dx;

	double discriminant = (v * v * vsq)
						- (2 * vsq * dy * gravity)
						- (g2 * x2);

	if (discriminant < 0.0) {
		return(false);
	}

	double denominator = 2 * ((y2 / x2) + 1.0);
	if (denominator == 0.0) {
		return(false); // RA2: as above
	}

	double base = vsq - (dy * gravity);

	if (((base + fastmath::sqrt(discriminant)) / denominator) >= 0.0 ||
		((base - fastmath::sqrt(discriminant)) / denominator) >= 0.0) {
		return(true); // RA2: as above
	}
	return(false); // RA2: as above
}


/// <summary>
/// Fetches the Z adjustment to display an explosion with.
/// Explosion animations are nudged toward the viewer so that the blast draws over the
/// object it is consuming instead of disappearing behind it.
/// </summary>
/// <returns>Returns with the Z adjustment to hand to the animation.</returns>
int Get_Explosion_Z(Coord coord)
{
	return(-15);
}


/// <summary>
/// Fetches the gravity that acts upon a floating projectile.
/// Bullets marked as floaters drift toward their target rather than plummeting, so the
/// firing and trajectory routines use this gentler pull in place of the rule gravity.
/// </summary>
/// <returns>Returns with the gravity to use for a floating projectile.</returns>
double Get_Floater_Gravity(void)
{
	return(Rule->Gravity * 0.5);
}


/// <summary>
/// Determines the distance between two points, ignoring a slight height difference.
/// This routine is used when explosion damage is being dealt out, so that a victim
/// perched a fraction of a level above or below the blast is not judged to be further
/// away than one standing level with it.
/// </summary>
/// <returns>Returns with the distance between the two coordinates.</returns>
inline static int Explosion_Distance(Coord const & coord1, Coord const & coord2)
{
	int z1 = coord1.Z;
	int z2 = coord2.Z;
	if (abs(z2 - z1) < LEVEL_LEPTON_H) {
		z2 = coord1.Z;
	}
	return(Coord(coord1.X - coord2.X, coord1.Y - coord2.Y, z1 - z2).Length());
}

