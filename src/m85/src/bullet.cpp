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

/* $Header: /CounterStrike/BULLET.CPP 1     3/03/97 10:24a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : BULLET.CPP                                                   *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : April 23, 1994                                               *
 *                                                                                             *
 *                  Last Update : October 10, 1996 [JLB]                                       *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   BulletClass::AI -- Logic processing for bullet.                                           *
 *   BulletClass::BulletClass -- Bullet constructor.                                           *
 *   BulletClass::Bullet_Explodes -- Performs bullet explosion logic.                          *
 *   BulletClass::Detach -- Removes specified target from this bullet's targeting system.      *
 *   BulletClass::Draw_It -- Displays the bullet at location specified.                        *
 *   BulletClass::In_Which_Layer -- Fetches the layer that the bullet resides in.              *
 *   BulletClass::Init -- Clears the bullets array for scenario preparation.                   *
 *   BulletClass::Is_Forced_To_Explode -- Checks if bullet should explode NOW.                 *
 *   BulletClass::Mark -- Performs related map refreshing under bullet.                        *
 *   BulletClass::Occupy_List -- Determines the bullet occupation list.                        *
 *   BulletClass::Shape_Number -- Fetches the shape number for the bullet object.              *
 *   BulletClass::Sort_Y -- Sort coordinate for bullet rendering.                              *
 *   BulletClass::Target_Coord -- Fetches coordinate to use when firing on this object.        *
 *   BulletClass::Unlimbo -- Transitions a bullet object into the game render/logic system.    *
 *   BulletClass::delete -- Bullet memory delete.                                              *
 *   BulletClass::new -- Allocates memory for bullet object.                                   *
 *   BulletClass::~BulletClass -- Destructor for bullet objects.                               *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define INCLUDE_COM
#include "always.h"
#include "geoconst1.h" // level-2 1.001: per-module geometry constants

#include "bullet.h"

#include "_convert.h"
#include "_map.h"
#include "_rules.h"
#include "_surface.h"
#include "_tactica.h"
#include "aircraft.h"
#include "anim.h"
#include "building.h"
#include "bullettype.h"
#include "ccrand.h"
#include "cell.h"
#include "combat.h"
#include "convert.h"
#include "draw.h"
#include "empulse.h"
#include "fly.h"
#include "house.h"
#include "houstype.h"
#include "infantry.h"
#include "inline.h"
#include "lightcon.h"
#include "map.h"
#include "missile.h"
#include "overtype.h"
#include "partsys.h"
#include "rules.h"
#include "scheme.h"
#include "stimer.h"
#include "sun.h"
#include "swizzle.h"
#include "tactical.h"
#include "techno.h"
#include "tracker.h"
#include "unit.h"
#include "voxdrsys.h"
#include "warhead.h"
#include "weapon.h"
#include "radsite.h" // RA2
#include "trajhelp.h" // RA2: TrajectoryHelper::GetObstacle
#include "bomblist.h" // level-2 1.001: Detonate
#include "bomb.h" // level-2 1.001: Detonate
#include "capmgr.h" // level-2 1.001: Detonate
#include "parasite.h" // level-2 1.001: Detonate
#include "temporal.h" // level-2 1.001: Detonate
#include "unittype.h" // level-2 1.001: Detonate
#include "geoconst2.h" // level-2 1.001: this module holds its own copy (per-TU constant addresses)


// ---- local declarations (to be moved to headers by the integrator) ----
class LightningStormClass // level-2 1.001: src/ra2/Ion.cpp; only the routine BulletClass::AI calls
{
	public:
		static void Flash_Start(void);
};


DynamicVectorClass<BulletClass *> BulletClass::ScalableBullets; // RA2: 0x008502F8 (YR name), the Scalable bullets in flight; level-2 1.001: a static member (initializer 0x5ef80, atexit 0x5efc0)


extern ULONG COMRefCount;


/***********************************************************************************************
 * BulletClass::BulletClass -- Bullet constructor.                                             *
 *                                                                                             *
 *    This is the constructor for the bullet class. It handles all                             *
 *    initialization of the bullet and starting it in motion toward its                        *
 *    target.                                                                                  *
 *                                                                                             *
 * INPUT:   id       -- The type of bullet this is (could be missile).                         *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/02/1994 JLB : Created.                                                                 *
 *   06/20/1994 JLB : Firer is a base class pointer.                                           *
 *   12/10/1994 JLB : Auto calculate range optional.                                           *
 *   12/12/1994 JLB : Handles small arms as an instantaneous effect.                           *
 *   12/23/1994 JLB : Fixed scatter algorithm for non-homing projectiles.                      *
 *   12/31/1994 JLB : Removed range parameter (not needed).                                    *
 *=============================================================================================*/
BulletClass::BulletClass(void) :
	BASECLASS(),
	Class(NULL),
	Payback(NULL),
	IsInaccurate(false),
	Fuse(),
	field_A4(true),
	IsLaunching(true),
	IsBright(false),
	BounceCount(0),
	CourseLockCounter(0), // level-2 1.001: the 1.001 constructor also sets these (as gibbo101's YR ctor)
	TarCom(NULL),
	MaxSpeed(0),
	InheritedColor(-1), // level-2 1.001: as above
	ClosureSamples(0),
	SmoothedClosure(0),
	Warhead(NULL),
	AnimFrame(0),
	AnimRate(0),
	WeaponType(NULL), // level-2 1.001: as above
	LastMapCoords(-1, -1), // level-2 1.001: as above
	NextAnim(NULL), // level-2 1.001: as above
	SpawnNextAnim(false) // level-2 1.001: as above
{
	Create_ID();
	SourceCoords.X = 0; // level-2 1.001: the coordinates are cleared in the body
	SourceCoords.Y = 0;
	SourceCoords.Z = 0;
	TargetCoords.X = 0;
	TargetCoords.Y = 0;
	TargetCoords.Z = 0;
	Bullets.Add(this);
}


/// <summary>
/// Fills in the firing data for a newly created projectile.
/// This routine is used by Create_Bullet to tell the projectile everything it must know
/// about the shot -- what it is, what it was aimed at, and who is to be credited for the
/// damage it causes.
/// </summary>
/// <param name="payback">The object that fired the shot. It receives credit for any kill.</param>
/// <param name="strength">The damage the projectile will inflict when it detonates.</param>
/// <param name="bright">Should the impact throw off a lighting flash?</param>
void BulletClass::Set_Bullet_Data(BulletTypeClass const *type, AbstractClass *target, TechnoClass *payback, int strength, WarheadTypeClass const *warhead, int max_speed, bool bright) // RA2: no range (YR's Construct), at 0x45F4F0
{
	Class = (BulletTypeClass *)type;
	Payback = payback;
	TarCom = target;
	MaxSpeed = max_speed;
	Warhead = (WarheadTypeClass *)warhead;
	IsBright = bright;
	Strength = strength;
	AnimFrame = 0;
	AnimRate = Class->AnimRate;
	if (Class->FirersPalette && Payback != NULL) {
		InheritedColor = Payback->House->Scheme;
	} else {
		InheritedColor = -1;
	}
	DamageMultiplier = 256;
	NextAnim = NULL;
	SpawnNextAnim = false;
}





/***********************************************************************************************
 * BulletClass::~BulletClass -- Destructor for bullet objects.                                 *
 *                                                                                             *
 *    The bullet destructor must detect if a dog has been attached to this bullet. If so,      *
 *    then the attached dog must be unlimboed back onto the map. This operation is necessary   *
 *    because, unlike other objects, the dog flies with the bullet it fires.                   *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
BulletClass::~BulletClass(void)
{
	Detach_This_From_All(this, true);

	if (SpawnNextAnim) { // RA2: a bullet with an anim was tracked in AnimPtrTracker (inlined Delete at 0x45F5C0)
		AnimPtrTracker.Delete(this); // RA2: as above
	}

	if (GameActive) {
		BulletClass::Limbo();
	}

	Class=0;
	Payback=0;
	NextAnim = NULL; // RA2: also forgets the anim (+0x13C)
	Bullets.Delete(this);
}



/***********************************************************************************************
 * BulletClass::Occupy_List -- Determines the bullet occupation list.                          *
 *                                                                                             *
 *    This function will determine the cell occupation list and return a pointer to it. Most   *
 *    bullets are small and the list is usually short, but on occasion, it can be a list that  *
 *    rivals the size of regular vehicles.                                                     *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with a pointer to the cell offset list that covers all the cells a bullet  *
 *          is over.                                                                           *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   06/20/1994 JLB : Created.                                                                 *
 *   01/05/1995 JLB : Handles projectiles with altitude.                                       *
 *=============================================================================================*/
Cell const * BulletClass::Occupy_List(bool) const
{
	static Cell const _list[] = { REFRESH_EOL };

	return(_list);
}


/***********************************************************************************************
 * BulletClass::Mark -- Performs related map refreshing under bullet.                          *
 *                                                                                             *
 *    This routine marks the objects under the bullet so that they will                        *
 *    be redrawn. This is necessary as the bullet moves -- objects under                       *
 *    its path need to be restored.                                                            *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/02/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
bool BulletClass::Mark(MarkType mark)
{
	if (BASECLASS::Mark(mark)) {
		return(true);
	}
	return(false);
}


/*
 * level-2 1.001: INFERRED one inline ballistic step (as bounce.cpp / particle.cpp Ballistic_Step, here on
 * the double velocities): gravity, the move, the bridge / obstacle classification and the slope bounce.
 * Returns true when the projectile struck a surface.
 */
static inline bool Ballistic_Step(TVelocity3D<double> & position, TVelocity3D<double> & velocity, double gravity, TechnoClass * payback, double elasticity)
{
	/*
	 * Pull the projectile down by gravity and then step it forward along
	 * its arc.
	 */
	velocity.Z -= gravity;

	Coord old_coord(position.X, position.Y, position.Z);
	position += velocity;

	Coord new_coord = Coord(position.X, position.Y, position.Z);
	int height = Map.Get_Height_GL(new_coord);
	int bridge_height = height + BRIDGE_LEPTON_HEIGHT;

	CellClass * cellptr = &Map[new_coord];

	/*
	 * See if the arc carried the projectile through the deck of a bridge,
	 * either dropping onto it from above or rising into it from below.
	 */
	bool fell_through_bridge = false;
	bool rose_through_bridge = false;
	if (cellptr->IsUnderBridge || Map[old_coord].IsUnderBridge) {
		if (new_coord.Z >= bridge_height) {
			if (old_coord.Z < bridge_height) {
				rose_through_bridge = true;
			}
		} else if (old_coord.Z >= bridge_height) {
			fell_through_bridge = true;
		}
	}

	/*
	 * Otherwise see if the projectile ran into a wall or a building on the
	 * way. The firer's own building, a dormant laser fence, a vehicle that
	 * happens to be deployed, and anything belonging to an ally are all
	 * passed through harmlessly.
	 */
	bool hit_obstacle = false;
	if (!fell_through_bridge && !rose_through_bridge) {
		if (position.Z >= height && position.Z - 150 < height) {
			BuildingClass * building = cellptr->Cell_Building();
			if (building != NULL || cellptr->Has_Wall_Or_Gate()) {
				hit_obstacle = true;
				if (building != NULL) {
					if (building == payback || building->Class->IsLaserFence && building->LaserFenceFrame >= 8) {
						hit_obstacle = false;
					}
					if (building->Considered_Vehicle()) {
						hit_obstacle = false;
					}
					if (payback != NULL && payback->House->Is_Ally(building)) {
						hit_obstacle = false;
					}
				}
			}
		}
	}

	/*
	 * The projectile strikes something unless it is still clear of the
	 * ground and has struck nothing along the way.
	 */
	if (position.Z < height || fell_through_bridge || rose_through_bridge || hit_obstacle) {
		if (payback == NULL) { // level-2 1.001: only a projectile without a firer is bounced off the slope
			/*
			 * Bring the projectile back to the surface it struck -- the deck it
			 * dropped onto, the underside of the deck it rose into, or the
			 * ground itself.
			 */
			if (fell_through_bridge) {
				position.Z = bridge_height;
			} else if (rose_through_bridge) {
				position.Z = bridge_height - 20;
			} else if (height - 100 < position.Z) {
				position.Z = height;
			}

			/*
			 * Bounce the projectile off that surface. Its velocity is rotated
			 * into the frame of reference of the ground slope, damped by the
			 * projectile's elasticity, reflected in Z, and then rotated back
			 * out again.
			 */
			Matrix3D slope_matrix; // level-2 1.001: one full expression (1.001 keeps both Matrix3D return temporaries apart and copies each)
			Matrix3D slope_matrix_inv = Matrix3D::Orthogonal_Inverse(slope_matrix = Get_Slope_Matrix(TacticalMap->Get_Cell_Ramp(new_coord)));
			Vector3 vec(velocity.X, -velocity.Y, velocity.Z);
			vec = slope_matrix_inv.Rotate_Vector(vec);
			vec *= elasticity;
			vec.Z = -vec.Z;
			vec = slope_matrix.Rotate_Vector(vec);
			velocity.X = vec.X;
			velocity.Y = -vec.Y;
			velocity.Z = vec.Z;
			return(true);
		}
		if (fell_through_bridge) {
			position.Z = bridge_height;
			return(true);
		}
		if (rose_through_bridge) {
			position.Z = bridge_height - 20;
			return(true);
		}
	}
	return(false);
}

/***********************************************************************************************
 * BulletClass::AI -- Logic processing for bullet.                                             *
 *                                                                                             *
 *    This routine will perform all logic (flight) logic on the bullet.                        *
 *    Primarily this is motion, fuse tracking, and detonation logic. Call                      *
 *    this routine no more than once per bullet per game tick.                                 *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/02/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
void BulletClass::AI(void) // level-2 1.001: rebuilt from the 1.001 disassembly at 0x45F380
{
	/*
	 * This is how many frames the closure detector spends warming up, and also
	 * the closure value beneath which a homing projectile is judged to have
	 * stopped gaining on its target.
	 */
	static const int _limit = 4 * TICKS_PER_SECOND;

	Cell target_cell; // level-2 1.001: STEERING reuse the cell temporary for the final map update
	Coord	coord;
	int		distance;

	BASECLASS::AI();

	if (!IsActive) return;

	/*
	 * level-2 1.001: a nuclear projectile that has already gone off waits here for its
	 * explosion animation to finish, then detonates and goes away.
	 */
	if (SpawnNextAnim) {
		if (NextAnim != NULL) return;
		AnimPtrTracker.Delete(this);
		SpawnNextAnim = false;
		Bullet_Explodes(false);
		Delete_Me();
		return;
	}

	/*
	**	Ballistic objects are handled here.
	*/
	bool collided = false;
	bool forced = false;			// Forced explosion.

	/*
	 * A dropping projectile that has finished its fall has arrived and must
	 * detonate.
	 */
	if (Class->IsDropping && !IsFalling) {
		forced = true;
	}

	/*
	 * Projectiles that carry an animation cycle through their frames here,
	 * looping back to the start of the sequence when the end is passed.
	 */
	if (Class->AnimLow || Class->AnimHigh) {
		AnimRate--;
		if (AnimRate == 0) {
			AnimRate = Class->AnimRate;
			AnimFrame++;
			if (AnimFrame > Class->AnimHigh) {
				AnimFrame = Class->AnimLow;
			}
		}
	}

	/*
	**	Move the projectile forward according to its speed
	**	and direction.
	*/
	coord = PositionCoord;

	/*
	 * Projectiles that leave a trail behind them drop one puff of it every so
	 * many frames. level-2 1.001: the spacing comes from the projectile type, the
	 * scaled delay taking precedence over the normal one.
	 */
	if (Class->Trailer != NULL) {
		if (Class->ScaledSpawnDelay) {
			if (!(Frame % Class->ScaledSpawnDelay)) {
				new AnimClass(Class->Trailer, coord, 1, 1);
			}
		} else if (!(Frame % Class->SpawnDelay)) {
			new AnimClass(Class->Trailer, coord, 1, 1);
		}
	}

	ImpactType impact = IMPACT_NONE;

	/*
	 * There are two flight models. A projectile that has a rate of turn is
	 * flown by the missile autopilot, which steers it toward its target and
	 * over any terrain in the way. Everything else merely follows the arc it
	 * was launched along.
	 */
	if (Class->ROT > 0) {
		int max_speed = MaxSpeed;
		double speed = Velocity.Speed();

		/*
		 * The projectile stays in its launch phase until it has worked up to
		 * cruising speed. A fast projectile is given no launch phase at all.
		 * level-2 1.001: a projectile type with a course lock instead keeps its
		 * launch course for that many frames.
		 */
		if (Class->CourseLockDuration == 0) {
			if (MaxSpeed >= 40 || speed + 0.5 >= max_speed) {
				IsLaunching = false;
			}
		} else if (CourseLockCounter < Class->CourseLockDuration) {
			CourseLockCounter++;
			if (CourseLockCounter >= Class->CourseLockDuration) {
				IsLaunching = false;
			}
		}

		int acceleration = Class->Acceleration;

		/*
		**	Homing projectiles constantly change facing to face toward the target but
		**	they only do so every other game frame (improves game speed and makes
		**	missiles not so deadly).
		*/
		if (IsLaunching && Class->CourseLockDuration == 0) {
			acceleration = (Frame % 2 == 0) ? 1 : 0;
		}

		/*
		 * Work the projectile's speed toward its maximum, accelerating while it
		 * is flying too slowly and coasting down while it is flying too fast.
		 */
		if (speed < max_speed) {
			speed += acceleration;
			if (speed >= max_speed) {
				speed = max_speed;
			}
			Velocity.Set_Speed(speed);
		} else if (speed > max_speed) {
			speed -= acceleration / 2;
			if (speed <= 0) {
				speed = 0;
			}
			Velocity.Set_Speed(speed);
		}

		TVelocity3D<double> velocity = Velocity; // level-2 1.001: STEERING materialize motion inputs before the coordinate update

		/*
		 * Fetch the point to home on. An object is aimed at through its target
		 * coordinate so that the projectile strikes the body of the victim
		 * rather than the ground it happens to be standing on.
		 */
		Coord target_coord; // level-2 1.001: STEERING keep the homing target live across the branch
		if (TarCom != NULL) { // level-2 1.001: STEERING preserve the recovered frame and branch layout
			target_coord = TarCom->As_Coord(); // level-2 1.001: STEERING keep the homing target live across the branch
		} else {
			target_coord = COORD_NONE; // level-2 1.001: STEERING keep the homing target live across the branch
		}
		if (TarCom != NULL && (TarCom->AbstractFlags & 2)) { // level-2 1.001: the object flag (+0x14 bit 1) instead of a dynamic cast
			target_coord = ((ObjectClass *)TarCom)->Target_Coord();
		}

		/*
		 * Swing the rate of turn above and below its nominal value over a
		 * fifteen frame cycle. This is what gives a missile its weaving flight
		 * path. The projectile's ID is mixed into the cycle so that missiles
		 * fired together do not all weave in unison.
		 */
		double & rotvar = Rule->MissileROTVar;
		double phase = ((Frame + Fetch_ID()) % TICKS_PER_SECOND) * (1.0 / TICKS_PER_SECOND);
		int rot = (fastmath::sin(phase * DEG_TO_RAD(360)) * rotvar + (rotvar + 1)) * Class->ROT;

		/*
		 * Allow a sharper turn over the last cell of the approach so that the
		 * projectile can still catch a target that dodges at the last moment.
		 */
		if (Center_Coord().Distance_To(target_coord) < CELL_LEPTON) {
			rot *= 1.5;
		}

		/*
		 * A projectile chasing an aircraft flies straight at its quarry rather
		 * than hugging the terrain on the way, since there is no ground between
		 * the two of them that needs clearing.
		 */
		bool is_aircraft = false;
		if (TarCom != NULL) { // level-2 1.001: STEERING materialize the guarded aircraft test before the motion call
			is_aircraft = TarCom->RTTI == RTTI_AIRCRAFT;
		}

		Coord old_coord = coord; // level-2 1.001: STEERING place the snapshot next to the motion call
		DirType heading((Dir256)(IsLaunching ? 0 : rot)); // level-2 1.001: STEERING materialize the launch heading before the motion call
		distance = Projectile_Motion(coord, velocity, target_coord, heading, is_aircraft, Class->IsAirburst, Class->IsVeryHigh, Class->Level); // RA2: the eighth argument (BulletTypeClass +0x26D) is pushed at 0x0045FD0E; level-2 1.001: STEERING materialize motion inputs before the coordinate update
		CellClass * cellptr = &Map[coord];
		Velocity = velocity;

		/*
		 * The projectile has arrived once it is within half a frame's travel of
		 * its target or it has flown into the ground. One that arrives while
		 * still airborne is snapped onto the target first so that the explosion
		 * is seen on the victim. An airburst projectile is left where it is,
		 * since it is meant to go off overhead.
		 */
		double half_speed = Velocity.Speed() * 0.5;
		if (distance <= half_speed || HeightAGL <= 0) {
			forced = true;
			impact = IMPACT_NORMAL;
			if (HeightAGL > 0 && target_coord != COORD_NONE && !Class->IsAirburst) { // level-2 1.001: not without a target; level-2 1.001: STEERING keep the homing target live across the branch
				coord = target_coord;
			}
		}

		/*
		 * level-2 1.001: a projectile without a point to home on detonates once it
		 * has climbed to the missile safety altitude.
		 */
		if (target_coord == COORD_NONE && HeightAGL >= Rule->MissileSafetyAltitude) {
			forced = true;
			impact = IMPACT_NORMAL;
		}

		/*
		 * Keep a smoothed measure of how quickly the projectile is gaining on
		 * its target. The first sixty frames are merely accumulated; after that
		 * the measure decays toward the closure of the moment. Should it fall
		 * away to nearly nothing, then the projectile is circling its target
		 * instead of closing on it and is forced to detonate rather than fly
		 * forever. Airburst and very high projectiles are exempt, since they
		 * come down on their targets from above.
		 */
		Point3D next_offset; // level-2 1.001: STEERING materialize the components separately so both lengths sum X and Y before Z
		next_offset.Y = coord.Y - target_coord.Y; // level-2 1.001: STEERING retain the native square-add order
		next_offset.X = coord.X - target_coord.X; // level-2 1.001: STEERING retain the native square-add order
		next_offset.Z = coord.Z - target_coord.Z; // level-2 1.001: STEERING retain the native square-add order
		Point3D previous_offset = old_coord - target_coord; // level-2 1.001: STEERING keep both distance vectors live across the length calculations
		int delta = previous_offset.Length() - next_offset.Length(); // level-2 1.001: the 3D distances (1.001 calls TPoint3D<int>::Length 0x41b780 twice); level-2 1.001: STEERING preserve the recovered frame and branch layout

		if (!IsLaunching) {
			if (ClosureSamples < _limit) {
				ClosureSamples++;
				SmoothedClosure += delta;
			} else {
				SmoothedClosure = SmoothedClosure * ((4 * TICKS_PER_SECOND - 1.0) / (4 * TICKS_PER_SECOND)) + delta;
				if (SmoothedClosure >= 0 && SmoothedClosure < _limit) {
					if (!Class->IsAirburst && !Class->IsVeryHigh) {
						forced = true;
						impact = IMPACT_NORMAL;
					}
				}
			}
		}

		/*
		 * A projectile that crossed the plane of a bridge deck during this step,
		 * from either side, strikes the bridge instead of passing through it.
		 */
		if (impact == IMPACT_NONE && (cellptr->IsUnderBridge || Map[old_coord].IsUnderBridge)) {
			int bridge_height = Map.Get_Height_GL(coord) + BRIDGE_LEPTON_HEIGHT;
			if (coord.Z > bridge_height && old_coord.Z < bridge_height || coord.Z < bridge_height && old_coord.Z > bridge_height) {
				impact = IMPACT_NORMAL;
				coord.Z = bridge_height;
				forced = true;
			}
		}
	} else {
		/*
		 * The position local briefly holds the current velocity: it seeds the
		 * two velocity locals and the slow-speed check before being reused as
		 * the floating point position for the flight step below.
		 */
		TVelocity3D<double> position = Velocity;
		TVelocity3D<double> new_velocity = position;
		TVelocity3D<double> velocity;
		velocity.Set(position.X, position.Y, position.Z);

		/*
		 * A projectile that is barely moving at all has nothing left to do but
		 * land.
		 */
		if (position.Speed() < 8) {
			impact = IMPACT_NORMAL;
		}
		position.Set(coord.X, coord.Y, coord.Z); // level-2 1.001: through Set (closer inlining)

		/*
		 * Floating projectiles fall at half gravity, which is what gives them
		 * their lazy drifting arc.
		 */
		double gravity = Rule->Gravity;
		if (Class->IsFloater) {
			gravity = Get_Floater_Gravity();
		}

		if (Class->Vertical) {
			/*
			 * level-2 1.001: a vertical projectile flies straight along its velocity,
			 * accelerating up to its maximum speed, and detonates once it climbs past
			 * its detonation altitude, drops below the ground or crosses a bridge deck.
			 */
			int speed = Velocity.Speed();
			if (speed < MaxSpeed) {
				Velocity.Set_Speed(Class->Acceleration + speed);
			}
			TVelocity3D<double> step = Velocity; // level-2 1.001: STEERING snapshot vertical velocity before the integer step
			Coord delta(step.X, step.Y, step.Z); // level-2 1.001: STEERING convert all step components together
			Coord old_coord = coord;
			coord = coord + delta; // level-2 1.001: closer to the original's inlining than three adds; level-2 1.001: STEERING preserve the recovered frame and branch layout
			if (coord.Z > Class->DetonationAltitude) {
				impact = IMPACT_NORMAL;
				forced = true;
			} else if (HeightAGL < 0) {
				impact = IMPACT_NORMAL;
				forced = true;
			} else {
				int bridge_height = Map.Get_Height_GL(coord) + BRIDGE_LEPTON_HEIGHT;
				if (Map[coord].IsUnderBridge || Map[old_coord].IsUnderBridge) {
					if (coord.Z >= bridge_height) {
						if (old_coord.Z < bridge_height) {
							impact = IMPACT_NORMAL;
							forced = true;
						}
					} else if (old_coord.Z >= bridge_height) {
						impact = IMPACT_NORMAL;
						forced = true;
					}
				}
			}
		} else {
			TechnoClass * payback = Payback;
			double elasticity = Class->Elasticity;
			if (Ballistic_Step(position, velocity, gravity, payback, elasticity)) { // level-2 1.001: INFERRED the inline step (1.001 calls its nested inlines out of line)
				impact = IMPACT_NORMAL;
				forced = true;
			}

			int x = (int)position.X;
			int y = (int)position.Y;
			int z = (int)position.Z;
			coord = Coord(x, y, z);
		}

		/*
		 * level-2 1.001: a projectile that comes down low in the cell of its target,
		 * or on the building that holds its target, has reached it.
		 */
		target_cell = TargetCoords.As_Cell(); // level-2 1.001: STEERING order the two cell temporaries before collision checks
		Cell cell = coord.As_Cell();
		if (cell == target_cell && !Class->Vertical && HeightAGL < LEVEL_LEPTON_H * 2) {
			forced = true; // level-2 1.001: STEERING order the independent impact locals
			impact = IMPACT_NORMAL;
			collided = true;
		} else {
			CellClass * cellptr = &Map[cell];
			CellClass * target_cellptr = &Map[target_cell];
			BuildingClass * building = cellptr->Cell_Building();
			BuildingClass * target_building = target_cellptr->Cell_Building();
			if (building != NULL && !Class->Vertical && building == target_building && HeightAGL < LEVEL_LEPTON_H * 2) {
				forced = true; // level-2 1.001: STEERING order the independent impact locals
				impact = IMPACT_NORMAL;
				collided = true;
			} else {
				/*
				 * A projectile that is still flying detonates anyway if it passed close
				 * enough to somebody to count as a hit. The firer and its allies are
				 * ignored.
				 */
				TechnoClass * techno = Map[coord].Cell_Techno();
				bool is_payback = Payback != NULL && techno == Payback;
				bool is_ally = techno != NULL && Payback != NULL && Payback->House->Is_Ally(techno);
				bool is_close = techno != NULL && coord.Distance_To(techno->PositionCoord) < CELL_LEPTON / 2; // level-2 1.001: through the Get_Coord copy
				if (!is_payback && !is_ally && is_close) {
					forced = true; // level-2 1.001: STEERING order the independent impact locals
					impact = IMPACT_NORMAL;
					if (!Class->IsInaccurate) {
						coord = techno->Position;
					}
				} else if (!Map.In_Radar(coord)) {
					/*
					 * A projectile that has flown off the edge of the world is left at its
					 * last known position and vanishes.
					 */
					impact = IMPACT_EDGE;
					forced = true;
					coord = Position;
				} else {
					new_velocity.X = velocity.X;
					new_velocity.Y = velocity.Y;
					if (!Class->Vertical) {
						Velocity = TVelocity3D<double>(new_velocity.X, new_velocity.Y, velocity.Z);
					}

					/*
					 * A projectile that is barely moving and lying close to the ground has
					 * finished bouncing and settles where it is.
					 */
					if (Velocity.Speed() < 10 && HeightAGL < 10) {
						impact = IMPACT_NORMAL;
						forced = true;
					}
				}
			}
		}
	}

	switch (impact) {
		/*
		**	When a projectile reaches the edge of the world, it
		**	vanishes from existence -- presumed to explode off
		**	map.
		*/
		case IMPACT_EDGE:
			Mark();
			Delete_Me();
			break;

		default:
		case IMPACT_NONE:

		/*
		**	The projectile has moved. Check its fuse. If detonation
		**	is signaled, then do so. Otherwise, just move.
		*/
		case IMPACT_NORMAL: {
			Mark();
			PositionCoord = coord;

			/*
			 * A projectile that flies into an active firestorm wall is consumed
			 * by it. The wall lets its owner's own fire through, as it does any
			 * projectile built to ignore firestorms.
			 */
			BuildingClass * building = Map[coord].Cell_Building();
			if (building != NULL && building->Class->IsFirestormWall && building->House->FirestormDefenseActivated) {
				if (Payback == NULL || building->House != Payback->House) {
					if (Class_Of() != NULL && !Class_Of()->IsIgnoresFirestorm) {
						building->Crossing_Firestorm(this, false);
						Delete_Me();
						break;
					}
				}
			}

			/*
			**	See if the bullet should be forced to explode now in spite of what
			**	the fuse would otherwise indicate. Maybe the bullet hit a wall?
			*/
			if (!forced) {
				Coord cur_coord = PositionCoord;
				forced = Is_Forced_To_Explode(cur_coord);
				PositionCoord = cur_coord;
			}
			if (forced && HeightAGL < 0) { // level-2 1.001: a projectile does not go off below the ground
				HeightAGL = 0;
			}

			/*
			**	If the bullet is not to explode, then perform normal flight
			**	maintenance (usually nothing). Otherwise, explode and then
			**	delete the bullet.
			*/
			FuseResultType fuse = FUSE_WAIT; // level-2 1.001: STEERING order impact tests to retain the recovered case layout
			if (Class->ROT > 0 || Class->IsFueled) { // level-2 1.001: STEERING order impact tests to retain the recovered case layout
				fuse = Fuse.Fuse_Checkup(coord); // level-2 1.001: STEERING order impact tests to retain the recovered case layout
			} // level-2 1.001: fueled projectiles check the fuse too
			if (Payback != NULL && Payback->TClass->JumpJet && fuse == FUSE_EXPLODE_FAR) { // level-2 1.001: shots of a jump jet go off close; level-2 1.001: STEERING order impact tests to retain the recovered case layout
				fuse = FUSE_EXPLODE_CLOSE;
			}
			if (!forced && (fuse == FUSE_WAIT || Class->IsDropping)) { // level-2 1.001: STEERING order impact tests to retain the recovered case layout
				/*
				**	Certain projectiles lose strength when they travel.
				*/
				if (Strength > 5 && Class->IsDegenerate) { // level-2 1.001: STEERING test strength first in the maintenance path
					Strength--;
				}

			} else {
				/*
				 * Nudge the detonation onto the target itself when the
				 * projectile went off close by, so that the explosion is seen
				 * to strike the victim rather than the air alongside it. A
				 * collision is judged three times as generously as a mere fuse
				 * expiry, and an airburst or inaccurate projectile is always
				 * left where it went off.
				 */
				if (TarCom != NULL) {
					if (!Class->IsAirburst && !Class->IsInaccurate && (fuse == FUSE_EXPLODE_CLOSE || collided)) { // level-2 1.001: STEERING order impact tests to retain the recovered case layout
						Coord midpoint = coord;
						Coord target_coord = TarCom->As_Coord();
						midpoint.Z = (midpoint.Z + target_coord.Z) / 2;
						int target_distance = midpoint.Distance_To(target_coord);
						if (collided) {
							target_distance /= 3;
						}

						if (fuse == FUSE_EXPLODE_CLOSE || target_distance <= MAX(CELL_LEPTON / 2, Velocity.Speed() * 2)) {
							PositionCoord = TarCom->Center_Coord();
						}
					}
				}

				/*
				 * level-2 1.001: a nuclear warhead first flashes the screen and plays its
				 * explosion animation; the projectile detonates once that has finished
				 * (see the top of this routine).
				 */
				if (*Warhead == "NUKE") {
					if (HeightAGL < 0) {
						HeightAGL = 0;
					}
					LightningStormClass::Flash_Start();
					AnimType anim = AnimTypeClass::From_Name("NUKEBALL");
					if (anim != ANIM_NONE) {
						AnimTypeClass * animtype = AnimTypes[anim];
						if (animtype != NULL) {
							NextAnim = new AnimClass(animtype, PositionCoord, 0, 1, ShapeFlags_Type(0x2600), Get_Explosion_Z(PositionCoord)); // level-2 1.001: flags 0x2600 as pushed
							SpawnNextAnim = true;
							AnimPtrTracker.Add(this);
							break;
						}
					}
				}
				Bullet_Explodes(forced);
				Delete_Me();
			}
			break;
		}
	}
	target_cell = coord.As_Cell();
	LastMapCoords = target_cell; // level-2 1.001: remembers the cell the projectile is over
}


/***********************************************************************************************
 * BulletClass::Shape_Number -- Fetches the shape number for the bullet object.                *
 *                                                                                             *
 *    Use this routine to fetch a shape number to use for this bullet object.                  *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the shape number to use when drawing this bullet.                     *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   08/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int BulletClass::Shape_Number(void) const
{
	int shapenum = 0;

	if (!Class->IsFaceless) {
		shapenum = UnitClass::BodyShape[DirType(fastmath::atan2(-Velocity.Y, Velocity.X)).As_Dir32()];
	}

	if (Class->AnimLow || Class->AnimHigh) {
		shapenum = AnimFrame;
	}

	return(shapenum);
}


/***********************************************************************************************
 * BulletClass::Draw_It -- Displays the bullet at location specified.                          *
 *                                                                                             *
 *    This routine displays the bullet visual at the location specified.                       *
 *                                                                                             *
 * INPUT:   x,y   -- The center coordinate to render the bullet at.                            *
 *                                                                                             *
 *          window   -- The window to clip to.                                                 *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   06/20/1994 JLB : Created.                                                                 *
 *   06/27/1994 JLB : Takes a window clipping parameter.                                       *
 *   01/08/1995 JLB : Handles translucent colors if necessary.                                 *
 *=============================================================================================*/
void BulletClass::Draw_It(Point2D const & point, Rect const & cliprect) const
{
	if (Scen->Special.IsFogOfWar && Map.Is_Fogged(Get_Coord())) return; // RA2: Draw_It at 0x4610D0 matches only so

	if (Class->IsInvisible) return;

	if (SpawnNextAnim) return; // RA2: as above

	if (Class->IsVoxel) {
		Matrix3D matrix(true);
		matrix.Rotate_Z(Velocity.Get_Yaw().As_Radian32());
		matrix.Rotate_Y(-Velocity.Get_Pitch().As_Radian32());
		Draw_Voxel(Class->Voxel, Get_Isometric_View_Matrix() * matrix, point, cliprect, 0, SHAPE_ALPHA, NORMAL_LIGHT);

	} else {
		ShapeSet const * shapeptr = (ShapeSet const *)Get_Image_Data();
		if (shapeptr == NULL) return;

		int shapenum = Shape_Number();

		int height_agl = HeightAGL;
		int height_gl = Map.Get_Height_GL(Get_Coord()); // RA2: as above

		if (!IsOnBridge && Map[Get_Coord()].IsUnderBridge && height_agl >= BRIDGE_LEPTON_HEIGHT) { // RA2: as above
			height_agl -= BRIDGE_LEPTON_HEIGHT;
			height_gl += BRIDGE_LEPTON_HEIGHT;
		}

		if (height_agl > 0 && Class->IsShadow) { // RA2: as above
			Point2D shadowpoint = point + Point2D(0, TacticalMap->Z_Lepton_To_Pixel(height_agl));
			Draw_Shape(*LogicalSurface, *NormalDrawer, shapeptr, shapenum, shadowpoint, cliprect, ShapeFlags_Type(SHAPE_DARKEN|SHAPE_CENTER|SHAPE_WIN_REL|SHAPE_ZGRAD), 0, -10 - TacticalMap->Z_Lepton_To_Pixel(height_gl));
		}

		ConvertClass * drawer = NormalDrawer;
		if (Class->IsAnimPalette) {
			drawer = AnimDrawer;
		} else if (Class->FirersPalette) { // RA2: as above
			if (InheritedColor != -1) { // RA2: as above
				drawer = ColorSchemes[InheritedColor]->Converter; // RA2: as above
			} else {
				drawer = ColorSchemes[PlayerPtr->Scheme]->Converter; // RA2: as above
			}
		}
		Draw_Shape(*LogicalSurface, *drawer, shapeptr, shapenum, point, cliprect, ShapeFlags_Type(SHAPE_CENTER|SHAPE_WIN_REL|SHAPE_ALPHA|SHAPE_ZGRAD), 0, -30 - TacticalMap->Z_Lepton_To_Pixel(Height));
	}
}


/// <summary>
/// RA2: retargets the bullet at the cell under its target (no target while the scenario is set up, for
/// a target in the air, or at the zero cell).
/// </summary>
void BulletClass::LoseTarget(void) // RA2: at 0x461470
{
	Cell cell(TarCom->Center_Coord());
	if (!ScenarioInit && !TarCom->In_Air() && cell != CELL_NONE) {
		TarCom = &Map[cell];
	} else {
		TarCom = NULL;
	}
}






/***********************************************************************************************
 * BulletClass::Detach -- Removes specified target from this bullet's targeting system.        *
 *                                                                                             *
 *    When an object is removed from the game system, it must be removed all targeting and     *
 *    tracking systems as well. This routine is used to remove the specified object from the   *
 *    bullet. If the object isn't part of this bullet's tracking system, then no action is     *
 *    performed.                                                                               *
 *                                                                                             *
 * INPUT:   target   -- The target to remove from this tracking system.                        *
 *                                                                                             *
 *          all      -- Is the target going away for good as opposed to just cloaking/hiding?  *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   09/24/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
void BulletClass::Detach(AbstractClass const * target, bool all)
{
	BASECLASS::Detach(target, all);

	if (Payback == target) {
		Payback = NULL;
	}
	if (TarCom == target) {
		LoseTarget(); // RA2: retargets at the cell under the target instead of dropping the target (inlined LoseTarget, 0x461549)
	}
	if (Class == target) {
		Class = NULL;
	}
	if (WeaponType == target) { // RA2: also the weapon type (+0x118)
		WeaponType = NULL; // RA2: as above
	}
	if (NextAnim == target) { // RA2: also the anim (+0x13C)
		NextAnim = NULL; // RA2: as above
	}
	if (all && target->Fetch_RTTI() == RTTI_BULLET) { // RA2: a Scalable bullet that goes leaves the list of those in flight
		BulletClass * bullet = (BulletClass *)target; // RA2: as above
		if (bullet->Class->Scalable) { // RA2: as above
			for (int index = 0; index < ScalableBullets.Count(); index++) { // RA2: as above
				if (bullet == ScalableBullets[index]) { // RA2: as above
					ScalableBullets.Delete(bullet); // RA2: as above
					return; // RA2: as above
				}
			}
		}
	}
}



/***********************************************************************************************
 * BulletClass::Unlimbo -- Transitions a bullet object into the game render/logic system.      *
 *                                                                                             *
 *    This routine is used to take a bullet object that is in limbo and transition it to the   *
 *    game system. A bullet object so transitioned, will be drawn and logic processing         *
 *    performed. In effect, it comes into existence.                                           *
 *                                                                                             *
 * INPUT:   coord -- The location where the bullet object is to appear.                        *
 *                                                                                             *
 *          dir   -- The initial facing for the bullet object.                                 *
 *                                                                                             *
 * OUTPUT:  bool; Was the unlimbo successful?                                                  *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   01/10/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
bool BulletClass::Unlimbo(Coord const & coord, TVelocity3D<double> const & velocity)
{
	/*
	**	Try to unlimbo the bullet as far as the base class is concerned. Use the already
	**	set direction and strength if the "punt" values were passed in. This allows a bullet
	**	to be setup prior to being launched.
	*/
	if (BASECLASS::Unlimbo(coord)) {
		Velocity = velocity;
		SourceCoords = coord; // RA2: remembers where the bullet started ...
		LastMapCoords = SourceCoords.As_Cell(); // RA2: ... and its cell
		Map.Remove(this);

		Coord tcoord = TarCom->As_Coord();
		TargetCoords = tcoord; // RA2: remembers where it is going

		/*
		**	RA2: a flak bullet that is invisible is scattered around the target the farther it flies, up to
		**	the ballistic scatter of the rules.
		*/
		if (Class->FlakScatter && Class->IsInvisible) { // RA2: as above
			TPoint3D<float> delta(coord.X - tcoord.X, tcoord.Y - coord.Y, coord.Z - tcoord.Z); // level-2 1.001: a float point (1.001 stores X and Y as floats; target minus source in Y)
			float distance = delta.Length(); // RA2: the distance to fly
			int max_scatter = Rule->BallisticScatter * 2; // level-2 1.001: the bound is a named value (Scen in edx, the bound in eax, as at 0x461423; Unlimbo 11 -> 2 masked hunks)
			int scatter = Scen->RandomNumber(0, max_scatter); // RA2: as above
			int radius = scatter; // level-2 1.001: built up in steps (closer register use than one expression; not yet byte-identical)
			radius *= (int)distance;
			radius /= WeaponType->Range;
			double random = Scen->RandomNumber(0, 0x7FFFFFFE) * 4.656612877414201e-10; // level-2 1.001: the two scale factors are not folded
			DirType dir(random * 6.283185307179586); // level-2 1.001: the scatter heading through DirType(double) and As_Radian (m85 wrote both conversions out; Unlimbo 0x4612E0 2 hunks -> 0)
			double angle = dir.As_Radian(); // level-2 1.001: as above
			int z = tcoord.Z; // RA2: as above
			int y = (int)(tcoord.Y - fastmath::sin(angle) * radius); // RA2: as above
			int x = (int)(fastmath::cos(angle) * radius + tcoord.X); // RA2: as above
			tcoord = Coord(x, y, z); // RA2: as above
		}

		/*
		**	For very fast and invisible projectiles, just make the projectile exist at the target
		**	location and dispense with the actual flight.
		*/
		if (Class->IsInvisible) {
			HouseClass * house = Payback != NULL ? Payback->House : NULL; // RA2: as above
			Coord firestorm_coord = Map.Firestorm_On_Path(coord, tcoord, house);
			if (firestorm_coord != COORD_NONE) { // RA2: a firestorm on the way takes the bullet there
				firestorm_coord.Z = Map.Get_Height_GL(firestorm_coord);
				Set_Coord(firestorm_coord);
				BuildingClass * bptr = Map[firestorm_coord].Cell_Building();
				bptr->Crossing_Firestorm(this, false);
				Delete_Me();
			} else {
				CellClass * blocking = TrajectoryHelper::FindFirstObstacle(coord, tcoord, Class, house); // RA2: a bullet that is stopped by an obstacle on the way lands there
				if (blocking != NULL) { // RA2: as above
					Set_Coord(blocking->Center_Coord()); // RA2: as above
				} else {
					Set_Coord(tcoord); // RA2: as above
				}
				Set_Coord(tcoord); // RA2: as above
				MaxSpeed = 0;
				Velocity.Set_Speed(0);
			}
		}

		/*
		**	Arm the fuse.
		*/
		Fuse.Arm_Fuse(PositionCoord, tcoord, (TarCom != NULL && TarCom->Fetch_RTTI() == RTTI_AIRCRAFT) ? 0 : Class->Arming); // RA2: as above

		if (Class->ROT > 0) { // RA2: a homing bullet
			Velocity.Set_Speed(1);
		}

		if (IsActive) {
			Map.Submit(this);
		}
		return(true);
	}
	return(false);
}



/***********************************************************************************************
 * BulletClass::In_Which_Layer -- Fetches the layer that the bullet resides in.                *
 *                                                                                             *
 *    This examines the bullet to determine what rendering layer it should be in. The          *
 *    normal logic applies unless this is a torpedo. A torpedo is always in the surface        *
 *    layer.                                                                                   *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the render layer that this bullet should reside in.                   *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   10/10/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
LayerType BulletClass::In_Which_Layer(void) const
{
	return(Class->Flat ? LAYER_SURFACE : LAYER_AIR); // RA2: In_Which_Layer at 0x461BF0 matches only so
}


/***********************************************************************************************
 * BulletClass::Is_Forced_To_Explode -- Checks if bullet should explode NOW.                   *
 *                                                                                             *
 *    This routine will examine the bullet and where it is travelling in order to determine    *
 *    if it should prematurely explode. Typical of this would be when a bullet hits a wall     *
 *    or a torpedo hits a ship -- regardless of where the projectile was originally aimed.     *
 *                                                                                             *
 * INPUT:   coord -- The new coordinate to place the bullet at presuming it is forced to       *
 *                   explode and a modification of the bullet's coordinate is needed.          *
 *                   Otherwise, the coordinate is not modified.                                *
 *                                                                                             *
 * OUTPUT:  bool; Should the bullet explode now?                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   10/10/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool BulletClass::Is_Forced_To_Explode(Coord & coord) const
{
	coord = PositionCoord;
	CellClass * cellptr = &Map[coord];

	/*
	**	RA2: a bullet that cannot cross cliffs or walls explodes at the obstacle on its way from the
	**	source to the target cell (TrajectoryHelper::GetObstacle at 0x4BBAF0).
	*/
	if (Class->SubjectToCliffs || Class->SubjectToWalls) { // RA2: as above
		CellClass * source = &Map[SourceCoords]; // RA2: as above
		CellClass * destination = &Map[TargetCoords]; // RA2: as above
		CellClass * previous = &Map[LastMapCoords]; // RA2: as above
		if (TrajectoryHelper::GetObstacle(source, destination, previous, coord, Class, Payback == NULL ? NULL : Payback->House)) { // RA2: as above
			return(true); // RA2: as above
		}
	}

	if (HeightAGL <= -LEVEL_LEPTON_H * 4) { // RA2: far below the ground
		return(true);
	}

	if (TarCom != NULL && Class->FlakScatter) { // RA2: a flak bullet that is lower than its target explodes
		Coord current = PositionCoord; // RA2: as above
		if (current.Z < TarCom->As_Coord().Z && HeightAGL < 0) { // RA2: as above
			return(true); // RA2: as above
		}
	}

	if (Class->Level && cellptr->On_Ground()) { // RA2: a level bullet that reaches the ground
		return(true);
	}

	/*
	**	Bullets are generally more effective when they are fired at aircraft.
	*/
	if (Class->IsAntiAircraft && TarCom != NULL && TarCom->In_Air() && Distance(TarCom) < CELL_LEPTON / 2) { // RA2: no jumpjet test
		return(true);
	}

	return(false);
}



/// <summary>
/// RA2
/// </summary>
static inline int Coord_Dist(Coord const & a, Coord const & b)
{
	Coord c = a - b;
	return(c.Length());
}


/***********************************************************************************************
 * BulletClass::Bullet_Explodes -- Performs bullet explosion logic.                            *
 *                                                                                             *
 *    This handles the exploding bullet action. It will generate the animation and the         *
 *    damage as necessary.                                                                     *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   The bullet should be deleted after this routine is called.                      *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   10/10/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void BulletClass::Bullet_Explodes(bool forced)
{
	Coord coord = PositionCoord;
	TechnoClass * target = NULL; // RA2: Bullet_Explodes at 0x461DE0 matches only so
	if (TarCom != NULL && TarCom->In_Air()) {
		target = (TechnoClass *)TarCom;
	}

	if (!Class->IsInaccurate) { // RA2: as above
		if (TarCom != NULL) { // RA2: as above
			if (Coord_Dist(coord, TarCom->Center_Coord()) < 32 && !Class->IsAirburst && !Class->IsInaccurate) { // RA2: as above
				coord = TarCom->Center_Coord();
			}
		}

		if (!Warhead->IsEMEffect && !Class->IsAirburst) { // RA2: as above
			if (!forced && !Class->IsArcing && !Is_Homing() && Fuse.Fuse_Target() != COORD_NONE) {
				coord = Fuse.Fuse_Target();
			}

			if (target != NULL && target->In_Which_Layer() != LAYER_GROUND) {
				if (Distance(TarCom) < 128) { // RA2: as above
					coord = target->Target_Coord();
				}
			} else if (TarCom != NULL && Distance(TarCom) < 42) { // RA2: as above
				coord = TarCom->As_Coord(); // RA2: as above
				if (TarCom->Fetch_RTTI() == RTTI_BUILDING) { // RA2: as above
					Point3D const & offset = ((BuildingClass *)TarCom)->Class->TargetCoordOffset; // RA2: as above
					if (offset.X != 0 || offset.Y != 0 || offset.Z != 0) { // RA2: as above
						coord = ((ObjectClass *)TarCom)->Target_Coord(); // RA2: as above
					}
				}
			}
		}
	}

	if (!Class->IsAirburst) { // RA2: as above
		Coord newcoord = coord;
		for (int i = 0; i < Class->Cluster; i++) {
			Detonate(coord);
			if (!IsActive) {
				break;
			}
			coord = Coord_Scatter(newcoord, Random_Pick(CELL_LEPTON, CELL_LEPTON * 2));
		}
	} else {
		Detonate(coord);
	}
}


/// <summary>
/// RA2
/// </summary>
static inline ObjectClass * Object_Of(AbstractClass * target)
{
	return(target == NULL ? NULL : ((target->AbstractFlags & 2) ? (ObjectClass *)target : NULL));
}


/// <summary>
/// RA2
/// </summary>
static inline bool Is_Foot_Object(AbstractClass const * target)
{
	return(target != NULL && (target->AbstractFlags & 4));
}


/// <summary>
/// RA2
/// </summary>
static inline Vector3 Normalize_Dir(const Vector3 & vec)
{
	float len = (float)fastmath::sqrt(vec.Z*vec.Z + vec.Y*vec.Y + vec.X*vec.X);
	if (len != 0.0) {
		return(vec / len);
	}
	return(vec);
}


/// <summary>
/// Performs the projectile's damage effect at the location specified.
/// This routine applies whatever the warhead calls for -- an electromagnetic pulse, a
/// tiberium web, or ordinary blast damage -- and then spawns the impact animation and any
/// lighting flash. Cluster projectiles use this moment to choose their sub-targets and
/// launch their bomblets.
/// </summary>
/// <param name="coord">The location that the projectile detonates at.</param>
/*
**	level-2 1.001: the inline object tests Detonate expands (the flag bit casts of the target and firer).
*/
static inline ObjectClass * Detonate_Object(AbstractClass * target)
{
	if (target == NULL) return(NULL);
	return((target->AbstractFlags & 2) ? (ObjectClass *)target : NULL);
}

static inline TechnoClass * Detonate_Techno(AbstractClass * target)
{
	if (target == NULL) return(NULL);
	return((target->AbstractFlags & 1) ? (TechnoClass *)target : NULL);
}

static inline FootClass * Detonate_Foot(AbstractClass * target)
{
	if (target == NULL) return(NULL);
	return((target->AbstractFlags & 4) ? (FootClass *)target : NULL);
}

void BulletClass::Detonate(Coord const & coord) // level-2 1.001: rewritten from the 1.001 disassembly (YR-like warhead dispatch)
{
	int result = 1;
	bool nullified = false;

	/*
	**	Shake the screen.
	*/
	if (Warhead->ShakeXlo != 0 || Warhead->ShakeXhi != 0) {
		Map.ScreenX = Sim_Random_Pick(Warhead->ShakeXlo, Warhead->ShakeXhi);
	}
	if (Warhead->ShakeYlo != 0 || Warhead->ShakeYhi != 0) {
		Map.ScreenY = Sim_Random_Pick(Warhead->ShakeYlo, Warhead->ShakeYhi);
	}

	/*
	**	Leave radiation behind.
	*/
	if (WeaponType != NULL && WeaponType->RadLevel > 0) {
		ApplyRadiationToCell(coord.As_Cell(), (int)WeaponType->WarheadPtr->SpreadFactor, WeaponType->RadLevel);
	}

	if (Warhead->MindControl) {
		if (Payback != NULL && Payback->CaptureManager != NULL) {
			ObjectClass * object = Detonate_Object(TarCom);
			bool player = (TarCom != NULL && (TarCom->AbstractFlags & 1) && ((TechnoClass *)TarCom)->House->Is_Player_Control());
			if (object != NULL && object->IsActive && object->Tag != NULL) {
				object->Tag->Spring(TEventType(6), object, CELL_NONE, false, Payback);
				object->Tag->Spring(TEventType(44), object, CELL_NONE, false, Payback);
			}
			if (Payback->CaptureManager->Capture((TechnoClass *)TarCom) && Rule->YuriMindControlSound != -1) {
				if (Payback->House->Is_Player_Control() || player) {
					VocClass::PlayAt(Rule->YuriMindControlSound, object->Get_Coord());
				}
			}
		}
	} else if (Warhead->IvanBomb) {
		BombList.Plant(Payback, Detonate_Techno(TarCom));
	} else if (Warhead->ElectricAssault) {
		if (TarCom != NULL && TarCom->Fetch_RTTI() == RTTI_BUILDING && Payback != NULL && Payback->Fetch_RTTI() == RTTI_INFANTRY) {
			((BuildingClass *)TarCom)->Rotate_Overpowerer((InfantryClass *)Payback);
		}
	} else if (Warhead->Parasite) {
		if (Payback != NULL) {
			((FootClass *)Payback)->ParasiteImUsing->TryInfect(Detonate_Foot(TarCom));
		}
	} else if (Warhead->Temporal) {
		if (Payback != NULL && TarCom != NULL) {
			Payback->TemporalImUsing->Fire(Detonate_Techno(TarCom));
		}
	} else if (Warhead->BombDisarm) {
		if (TarCom != NULL && (TarCom->AbstractFlags & 2) && ((ObjectClass *)TarCom)->AttachedBomb != NULL) {
			((ObjectClass *)TarCom)->AttachedBomb->Disarm();
		}
	} else if (Warhead->MakesDisguise) {
		if (Payback != NULL) {
			Payback->DisguiseAs(TarCom);
		}
	} else if (Warhead->NukeMaker) {
		NukeMaker();
	} else {
		if (Class->ShrapnelWeapon != NULL) {
			Shrapnel();
		}
		int damage = (DamageMultiplier * Strength) >> 8;
		result = Explosion_Damage(coord, damage, Payback, Warhead, true); // level-2 1.001: Explosion_Damage returns its result (2 = nullified)
		if (!IsActive) return;
		if (result == 2) {
			nullified = true;
		}
	}

	Coord blast = coord;

	/*
	**	For projectiles that are invisible while travelling toward the target,
	**	allow scatter effect for the impact animation.
	*/
	if (Class->IsInvisible) {
		blast = Coord_Scatter(blast, CELL_LEPTON / 8);
	}

	/*
	**	Fetch the land type that the explosion will be upon. A naval unit on the
	**	surface takes the hit itself.
	*/
	LandType land = LAND_NONE;
	if (HeightAGL < 2 * LEVEL_LEPTON_H) {
		land = Map[Get_Coord()].Land_Type();
		if (land == LAND_WATER && result == 0) {
			ObjectClass * occupier = Map[Get_Coord()].Cell_Occupier();
			if (occupier != NULL && occupier->Fetch_RTTI() == RTTI_UNIT) {
				UnitTypeClass const * utype = ((UnitClass *)occupier)->Class;
				if (utype->Naval && !utype->Underwater) {
					land = LAND_NONE;
				}
			}
		}
	}

	AnimTypeClass const * anim = Combat_Anim(Strength, Warhead, land, Get_Coord());

	if (IsBright && !nullified) {
		int flags = 0;
		if (Warhead->CLDisableRed) flags = 2;
		if (Warhead->CLDisableGreen) flags |= 4;
		if (Warhead->CLDisableBlue) flags |= 8;
		Combat_Lighting(blast, Strength, Warhead, true, flags);
	}

	if (nullified) {
		AnimTypeClass const * nullanim = Rule->WeaponNullifyAnim;
		if (nullanim != NULL) {
			new AnimClass(nullanim, blast, 0, 1, ShapeFlags_Type(SHAPE_ZGRAD|SHAPE_WIN_REL|SHAPE_CENTER), Get_Explosion_Z(blast));
		}
		return;
	}

	if (anim != NULL) {
		AnimClass * aptr = new AnimClass(anim, blast, 0, 1, ShapeFlags_Type(SHAPE_ZGRAD|SHAPE_WIN_REL|SHAPE_CENTER), Get_Explosion_Z(blast));
		/*
		**	Special case trap: if they're making the nuclear explosion,
		**	and no anim is available, force the nuclear damage anyway
		**	because nuke damage is done in the middle of the animation
		**	and if there's no animation, there won't be any damage.
		*/
		if (!aptr && Warhead == Rule->NukeWarhead) {
			HousesType house = HOUSE_NONE;
			if (Payback) {
				house = Payback->House->Class->House;
			}
			AnimClass::Do_Atom_Damage(house, blast.As_Cell());
		}
	}

	/*
	**	An airburst projectile showers the eight cells around it and its own cell.
	*/
	if (Class->IsAirburst) {
		WeaponTypeClass * weapon = Class->AirburstWeapon;
		BulletTypeClass const * btype = weapon->Bullet;
		FacingType face = FACING_N;
		CellClass * cell = Get_Cell_Ptr();
		for (int i = 8; i != 0; i--) {
			CellClass * adjacent = (CellClass *)&cell->Adjacent_Cell(face);
			face = FacingType((face + 1) & 7);
			BulletClass * bullet = btype->Create_Bullet(adjacent, Payback, weapon->Attack, weapon->WarheadPtr, 50, false);
			if (bullet != NULL) {
				TVelocity3D<double> velocity(DirType((Dir256)Random_Pick(0, 32)), DirType(DIR_S), weapon->MaxSpeed / 10);
				bullet->Unlimbo(PositionCoord, velocity);
			}
		}

		BulletClass * bullet = btype->Create_Bullet(cell, Payback, weapon->Attack, weapon->WarheadPtr, 50, false);
		if (bullet != NULL) {
			TVelocity3D<double> velocity(DirType((Dir256)Random_Pick(0, 32)), DirType(DIR_S), weapon->MaxSpeed / 10);
			bullet->Unlimbo(PositionCoord, velocity);
		}
	}
}


/// <summary>
/// RA2: the type's shrapnel: up to ShrapnelCount fragments of its ShrapnelWeapon at the enemies around the
/// impact, ring by ring within the weapon's range, and the rest at random cells nearby (a negative count:
/// fewer the farther the impact is from the firer). Ported from meastes 0x462C50.
/// </summary>
void BulletClass::Shrapnel(void) // RA2: at 0x462C50; level-2 1.001: the body of gibbo101/ra2-decomp @94adbad src/bullet.cpp (YR 0x46A310) with the RA2 names
{
	int configured = Class->ShrapnelCount;
	int count;
	if (configured < 0) {
		if (Payback == NULL) {
			count = 3;
		} else {
			count = -configured - ::Distance(Payback->Center_Coord(), PositionCoord) / CELL_LEPTON_W;
			if (count <= 0) {
				return;
			}
		}
	} else {
		count = configured;
	}

	if (Get_Cell_Ptr()->Cell_Occupier() == NULL ||
		Get_Cell_Ptr()->Cell_Occupier()->Fetch_RTTI() == RTTI_BUILDING) {
		return;
	}

	WeaponTypeClass const * weapon = Class->ShrapnelWeapon;
	BulletTypeClass const * type = weapon->Bullet;
	Cell center = Get_Cell();
	int range = weapon->Range / CELL_LEPTON_W;
	int fired = 0;
	TVelocity3D<double> velocity;
	for (int radius = 1; radius <= range; radius++) {
		int end = MapClass::RadiusCount[radius];
		for (int index = MapClass::RadiusCount[radius - 1]; index < end; index++) {
			CellClass * cellptr = &Map[center + MapClass::RadiusOffset[index]];
			ObjectClass * object = cellptr->Cell_Occupier();
			if (object != NULL && object != Payback && Payback != NULL &&
				!Payback->House->Is_Ally(object)) {
				BulletClass * bullet = type->Create_Bullet(object, Payback,
					weapon->Attack, weapon->WarheadPtr, weapon->MaxSpeed, weapon->IsBright);
				if (bullet != NULL) {
					velocity.Set(0, 0, 0);
					velocity.Set_Yaw(::Direction(PositionCoord, object->Center_Coord()));
					velocity.Set_Pitch(DirType(DIR_NE));
					velocity.Set_Speed(weapon->MaxSpeed);
					bullet->Unlimbo(PositionCoord, velocity);
					Coord source;
					source = PositionCoord;
					if (weapon->IsLaser && Payback != NULL) {
						Payback->Laser_Zap(object, 0, weapon, source);
					}
					if (weapon->IsElectricBolt && Payback != NULL) {
						Payback->Electric_Zap(object, weapon, source);
					}
				}
				fired++;
				if (fired == count) {
					return;
				}
			}
		}
	}

	for (; fired < count; fired++) {
		Cell cell = Get_Cell();
		cell.X += Random_Pick(-2, 2);
		cell.Y += Random_Pick(-2, 2);
		BulletClass * bullet = type->Create_Bullet(&Map[cell], Payback,
			weapon->Attack, weapon->WarheadPtr, weapon->MaxSpeed, weapon->IsBright);
		if (bullet != NULL) {
			velocity.Set(0, 0, 0);
			CellClass & destination = Map[cell];
			velocity.Set_Yaw(::Direction(PositionCoord, destination.Center_Coord()));
			velocity.Set_Speed(weapon->MaxSpeed);
			velocity.Set_Pitch(DirType(DIR_NE));
			bullet->Unlimbo(PositionCoord, velocity);
			Coord source;
			source = PositionCoord;
			if (weapon->IsLaser && Payback != NULL) {
				Payback->Laser_Zap(&Map[cell], 0, weapon, source);
			}
			if (weapon->IsElectricBolt && Payback != NULL) {
				Payback->Electric_Zap(&Map[cell], weapon, source);
			}
		}
	}
}



/// <summary>
/// RA2: leaves radiation in the cell: a new radiation site there, or more for the one it has.
/// </summary>
void BulletClass::ApplyRadiationToCell(Cell cell, int radius, int amount) // RA2: at 0x463720
{
	CellClass * cptr = &Map[cell];
	RadSiteClass * site = cptr->Get_Rad_Site();
	if (site == NULL) {
		site = new RadSiteClass();
		site->SetBaseCell(&cell);
		site->SetSpread(radius);
		site->SetRadLevel(amount);
		site->Activate();
		cptr->Set_Rad_Site(site);
	} else {
		site->Add(amount);
	}
}





/// <summary>
/// Reads this projectile back in from a save game stream.
/// This routine restores the virtual table and then swizzles the saved pointers so that they
/// refer to the objects they pointed at when the game was saved.
/// </summary>
/// <returns>Returns with S_OK if the projectile was loaded successfully.</returns>
HRESULT STDMETHODCALLTYPE BulletClass::Load(IStream * stream)
{
	HRESULT result = BASECLASS::Load(stream);
	if (SUCCEEDED(result)) {
		new (this) BulletClass(NoInitClass());

		if (NextAnim) { // RA2: a bullet with an anim is tracked again in AnimPtrTracker (inlined Add at 0x463847)
			AnimPtrTracker.Add(this); // RA2: as above
		}
		Swizzle_Pointer(&Class);
		Swizzle_Pointer(&Payback);
		Swizzle_Pointer(&Warhead);
		Swizzle_Pointer(&TarCom);
		Swizzle_Pointer(&WeaponType); // RA2: also the weapon type (+0x118) ...
		Swizzle_Pointer(&NextAnim); // RA2: ... and the anim (+0x13C)
	}
	return(result);
}



/// <summary>
/// Writes this projectile out to a save game stream.
/// </summary>
/// <param name="cleardirty">Should the object be marked as clean once it has been written?</param>
/// <returns>Returns with S_OK if the projectile was saved successfully.</returns>
HRESULT STDMETHODCALLTYPE BulletClass::Save(IStream * stream, BOOL cleardirty)
{
	return(BASECLASS::Save(stream, cleardirty));
}


/// <summary>
/// Takes out a reference on this projectile.
/// This is the IUnknown implementation used by the COM machinery that owns projectiles.
/// </summary>
/// <returns>Returns with the number of references now outstanding.</returns>
ULONG STDMETHODCALLTYPE BulletClass::AddRef(void)
{
	COMRefCount++;
	return(InterlockedIncrement(&RefCount));
}


/// <summary>
/// Drops a reference to this projectile.
/// This is the IUnknown implementation. The projectile deletes itself when the last
/// reference to it is released.
/// </summary>
/// <returns>Returns with the number of references still outstanding.</returns>
ULONG STDMETHODCALLTYPE BulletClass::Release(void)
{
	COMRefCount--;
	ULONG count = InterlockedDecrement(&RefCount);
	if (count == 0) {
		delete this;
	}
	return(count);
}


/// <summary>
/// Can this projectile steer toward its target?
/// The flight logic calls this routine to decide whether the projectile should be turned
/// toward its target each game frame or simply left to follow its launch trajectory.
/// </summary>
/// <returns>bool; Is this projectile a homing type?</returns>
bool BulletClass::Is_Homing(void) const
{
	if (Class->ROT > 0) {
		return(true);
	}
	return(false);
}


/// <summary>
/// Creates a projectile and fills in the data for the shot.
/// This routine is used by the weapon firing code in place of a bare new -- projectiles are
/// COM objects, so the instance must come from the class factory. The projectile is inert
/// until it is unlimboed with a starting position and velocity.
/// </summary>
/// <param name="payback">The object that fired the shot. It receives credit for any kill.</param>
/// <param name="strength">The damage the projectile will inflict when it detonates.</param>
/// <param name="bright">Should the impact throw off a lighting flash?</param>
/// <returns>Returns with a pointer to the projectile created, or NULL if one could not be
/// made.</returns>
BulletClass * __fastcall BulletTypeClass::Create_Bullet(AbstractClass * target, TechnoClass * payback, int strength, WarheadTypeClass const * warhead, int speed, bool bright) const // RA2: a member, no range, at 0x463990
{
	LPVOID unk = NULL;
	if (FAILED(CoCreateInstance(CLSID_BulletClass, NULL, CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER|CLSCTX_LOCAL_SERVER, IID_IUnknown, &unk))) {
		return(NULL);
	}

	BulletClass * bullet = (BulletClass *)unk;
	bullet->Set_Bullet_Data(this, target, payback, strength, warhead, speed, bright);
	return(bullet);
}


/// <summary>
/// Draws the voxel model for this projectile.
/// This routine poses every layer of the model, renders it through the voxel draw system,
/// and then blits the result to the logical surface in the projectile's own color scheme.
/// </summary>
/// <param name="voxeldata">The voxel and motion libraries to draw the projectile with.</param>
/// <param name="cliprect">The clipping rectangle to draw within.</param>
/// <param name="frame">The motion library frame to pose the model with.</param>
void BulletClass::Draw_Voxel(VoxelDataStruct const & voxeldata, Matrix3D const & transform, Point2D const & drawpoint, Rect const & cliprect, int frame, ShapeFlags_Type flags, int brightness) const
{
	VoxelLibrary * voxlib = voxeldata.VoxLib;
	MotionLibrary * motlib = voxeldata.MotLib;

	VoxelDrawSystem::Precalculate_Light(voxlib, 0, 0, transform, VoxelLightSource);
	VoxelDrawSystem::Reset();

	for (unsigned int i = 0; i < voxlib->Get_Layer_Count(); i++) {
		Matrix3D matrix;
		/// Without a motion library the matrix is left uninitialized and used as it stands.
		if (motlib != NULL) {
			Matrix3D hva_transform = motlib->Get_Layer_Matrix(i, frame);
			matrix = transform * hva_transform;
		}
		VoxelDrawSystem::Prep_For_Object(voxlib, i, 0, VoxelCameraMatrix * matrix);
	}

	SurfaceRegion region = VoxelDrawSystem::Render();
	static int flat_height_offset = -65; // RA2: a Flat bullet is drawn at a fixed height offset, read from memory (0x7D11A4)
	int height_offset = 0; // RA2: as above
	ShapeFlags_Type draw_flags = ShapeFlags_Type(flags & ~SHAPE_REMAP); // RA2: a local for the flags
	if (Class->Flat) { // RA2: as above
		height_offset = flat_height_offset; // RA2: as above
		draw_flags = ShapeFlags_Type(draw_flags | SHAPE_ZGRAD); // RA2: ... and with the z gradient
	}
	Blit_Block(*LogicalSurface, *ColorSchemes[Class->Color]->Converter, *VoxelDrawSystem::Get_Surface(), region.Bounds, region.Point + drawpoint, cliprect, NULL, ColorSchemes[Class->Color]->Converter->Blitter_From_Flags(draw_flags), height_offset, Class->Flat ? ZGRAD_GROUND : ZGRAD_90DEG, brightness, 0); // RA2: the full argument list
}



/// <summary>
/// RA2
/// </summary>
void BulletClass::Set_Weapon_Type(WeaponTypeClass * weapon)
{
	WeaponType = weapon;
}


/// <summary>
/// RA2
/// </summary>
WeaponTypeClass * BulletClass::Get_Weapon_Type(void) const // RA2: at 0x463BB0
{
	return(WeaponType);
}


/// <summary>
/// RA2: counts the bullet among the Scalable ones in flight; the more there are, the later the type spawns.
/// </summary>
void BulletClass::InitScalable(void) // RA2: at 0x463BC0
{
	ScalableBullets.Add(this);
	int extra = ScalableBullets.Count() - 5;
	if (extra < 0) {
		extra = 0;
	}
	Class->SetScaledSpawnDelay(Class->SpawnDelay + extra / 3);
}


/// <summary>
/// RA2: a NukeMaker warhead's payload: a NukePayload bullet dropped straight down on the target's cell.
/// </summary>
void BulletClass::NukeMaker(void) // RA2: at 0x463C50
{
	AbstractClass * target = TarCom;
	CellClass * cptr = &Map[target->Center_Coord().As_Cell()];
	WeaponTypeClass * weapon = Weapons[WeaponTypeClass::From_Name("NukePayload")];

	BulletTypeClass const * type = weapon->Bullet;
	WarheadTypeClass const * warhead = weapon->WarheadPtr;
	int speed = weapon->MaxSpeed;
	BulletClass * bullet = type->Create_Bullet(target, Payback, weapon->Attack, warhead, speed, true);
	if (bullet != NULL) {
		bullet->Limbo();
		bullet->WeaponType = weapon;
		Coord coord = cptr->Center_Coord();
		coord = coord + Coord(0, 0, WeaponType->Bullet->DetonationAltitude);
		double angle = DirType(DIR_N).As_Radian(); // RA2: straight down; Y is built first (sin before any cos), then X, where the TVelocity3D constructors compute X first
		double y = fastmath::sin(angle); // RA2: as above
		y *= fastmath::cos(angle); // RA2: as above
		y *= -1.0; // RA2: as above
		TVelocity2D<double> planar(fastmath::cos(angle) * fastmath::cos(angle) * -1.0, y); // RA2: as above
		TVelocity3D<double> velocity; // RA2: as above
		static_cast<TVelocity2D<double> &>(velocity) = planar; // RA2: as above, X and Y copied together
		velocity.Z = fastmath::sin(angle) * -1.0; // RA2: as above
		bullet->Unlimbo(coord, velocity);
	}
}


/// <summary>
/// Fetches the storage size of this object.
/// This routine is used by the save game machinery to know how many bytes of the object
/// must be written out.
/// </summary>
/// <returns>Returns with the number of bytes this projectile occupies.</returns>
int BulletClass::Fetch_Object_Size(void) const // RA2: no argument
{
	return(sizeof(*this));
}


/// <summary>
/// Fetches the run time type of this object.
/// </summary>
RTTIType BulletClass::Fetch_RTTI(void) const
{
	return(RTTI_BULLET);
}











/// <summary>
/// Fetches the class identifier for this projectile.
/// This is the IPersist implementation the save and load machinery uses to recognize which
/// kind of object it is about to read back from the stream.
/// </summary>
/// <returns>Returns with S_OK, or E_POINTER if no destination was supplied.</returns>
HRESULT STDMETHODCALLTYPE BulletClass::GetClassID(CLSID * retval)
{
	if (retval == NULL) return(E_POINTER);
	*retval = CLSID_BulletClass;
	return(S_OK);
}


/// <summary>
/// Assigns a new target for this projectile.
/// This routine is used when the launcher wants the projectile to chase something other than
/// what it was originally fired at. Only homing projectiles will act on the change.
/// </summary>
void BulletClass::Assign_Target(AbstractClass * target)
{
	TarCom = target;
}


/// <summary>
/// Fetches the type class object for this projectile.
/// </summary>
/// <returns>Returns with a pointer to the bullet type this projectile was created from.</returns>
ObjectTypeClass const * BulletClass::Class_Of(void) const
{
	return((ObjectTypeClass const *)Class);
}

