/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#define RA2_GEOMETRY_H // RA2: geometry.h follows the includes, as its constants take their initializers after the rectangle below (the thirteen initializers at 0x00593680-0x00593850)
#include "always.h" // RA2: as above

#include "missile.h" // RA2: as above

#include "_map.h" // RA2: as above
#include "cell.h" // RA2: as above
#include "coord.h" // RA2: as above
#include "face.h" // RA2: as above
#include "globals.h" // RA2: as above
#include "mouse.h" // RA2: as above
#include "velocity.h" // RA2: as above


#include "geometry.h" // RA2: this module holds its own copy of the geometry constants (initialized after MissileRect, from 0x005936A0)


/// <summary>
/// Handles one frame of guided missile flight.
/// This routine is used by the bullet logic to fly a homing projectile. It advances the
/// projectile along its current velocity, swings that velocity toward the target by no more
/// than the allowed turn rate, and flies the missile over the intervening terrain so that it
/// clears hills and bridges before it stoops onto its target.
/// </summary>
/// <param name="coord">The projectile position; advanced to its new position.</param>
/// <param name="velocity">The projectile velocity; steered toward the target.</param>
/// <param name="target_coord">The coordinate to home on, or COORD_NONE to merely level
/// out.</param>
/// <param name="rot">The greatest amount the projectile may turn during this frame.</param>
/// <param name="aircraft">Is the projectile chasing an aircraft?</param>
/// <param name="airburst">Should the projectile detonate in the air rather than stoop?</param>
/// <param name="veryhigh">Should the projectile cruise at extra altitude?</param>
/// <param name="level">Does the projectile fly level, never climbing or diving on its own?</param>
/// <returns>Returns with the distance still to be covered, with the vertical component
/// discounted. A projectile with nothing to home on returns its own speed.</returns>
// level-2 1.001: body adopted from gibbo101/ra2-decomp src/missile.cpp @94adbad041a96d176a6e5758da3916aa9b60980a
// (GPL-3.0-or-later, YR 1.001). The function-level `DirType desired_pitch;` gives 1.001's 0x8c frame (b29).
// level-2 1.001: 51 bytes differ at two instruction-scheduling sites (batch 46).
int Projectile_Motion(Coord & coord, TVelocity3D<double> & velocity, Coord const & target_coord, DirType const & rot, bool aircraft, bool airburst, bool veryhigh, bool level)
{
	DirType desired_pitch;
	if (target_coord == COORD_NONE) {
		desired_pitch = velocity.Get_Pitch();
		desired_pitch.Turn(DirType(DIR_NE), rot);
		velocity.Set_Pitch(desired_pitch);
		TVelocity3D<double> frame_velocity(velocity);
		coord = coord + Point3D(frame_velocity.X, frame_velocity.Y, frame_velocity.Z);
		return(velocity.Speed());
	} else {
		TVelocity3D<double> frame_velocity(velocity);
		coord = coord + Point3D(frame_velocity.X, frame_velocity.Y, frame_velocity.Z);
		int target_distance = coord.Distance_To(target_coord);
		int horizontal_distance = Point2D(coord).Distance_To(Point2D(target_coord));

		Coord delta = target_coord - coord;

		TVelocity3D<double> target_direction;
		TVelocity3D<double> dir = TVelocity3D<double>(delta.X, delta.Y, delta.Z);
		target_direction = TVelocity3D<double>(dir); // level-2 1.001: STEERING keep the measured copy-constructor expansion.

		DirType desired_yaw = velocity.Get_Yaw();
		desired_yaw.Turn(target_direction.Get_Yaw(), rot);
		velocity.Set_Yaw(desired_yaw);

		desired_pitch = velocity.Get_Pitch();

		if (!aircraft && (airburst || horizontal_distance > ((veryhigh ? 6 : 3) * CELL_LEPTON)) && rot.As_Dir256() > 1) {
			TVelocity3D<double> lookahead_velocity(velocity);
			Coord lookahead_coord = coord + Point3D(lookahead_velocity.X, lookahead_velocity.Y, lookahead_velocity.Z) * 6;

			int terrain_height = Map.Get_Height_GL(lookahead_coord);
			if (Map[lookahead_coord].IsUnderBridge) {
				terrain_height += BRIDGE_LEPTON_HEIGHT;
			}

			int cell_distance = target_distance / CELL_LEPTON;
			if (airburst || veryhigh) {
				cell_distance = 10;
			} else if (cell_distance >= 5) {
				cell_distance = 5;
			}

			if (!level) {
				int height_delta = coord.Z - LEVEL_LEPTON_H * cell_distance - terrain_height;
				if (height_delta < -20) {
					coord.Z += 18;
				} else if (height_delta > 20) {
					coord.Z -= 18;
				}

				if (height_delta < -(LEVEL_LEPTON_H / 2)) {
					desired_pitch.Turn(DirType(DIR_NE), rot / 2);
				} else if (height_delta > LEVEL_LEPTON_H / 2) {
					desired_pitch.Turn(DirType(Dir256(DIR_E + DIR_STEP_32)), rot / 2);
				} else {
					desired_pitch.Turn(DIR_E, rot / 2);
				}
			}
		} else if (!level) {
			desired_pitch.Turn(target_direction.Get_Pitch(), (rot + DirType(256)) / 2);
		}

		velocity.Set_Pitch(desired_pitch);

		if (airburst) {
			delta.Z = 0;
		} else {
			delta.Z /= 4;
		}

		return(delta.Length());
	}
}


// level-2: adopted from gibbo101 missile.cpp (explicit instantiation of TVelocity3D<double>; 1.001 keeps the out-of-line operator+= at 0x63ED0)
template class TVelocity3D<double>;
