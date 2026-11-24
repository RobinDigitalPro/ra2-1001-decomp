// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _voxel.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: RECT_NONE initializer 0xf020; three empty initializers 0xf040/0xf050/0xf060 (VoxelShadowLightVector, VoxelLightSource and VoxelCameraMatrix have constructors without code; which of the no-init globals of the header they are is an assumption); VoxelStaticBuffer 0x821de0 (initializer 0xf070, atexit destructor 0xf090)

#include "always.h"
#include "rect.h"
#include "index.h"
#include "_voxel.h"

Vector3 VoxelShadowLightVector;
Vector3 VoxelLightSource;
Matrix3D VoxelCameraMatrix;
StaticBufferClass VoxelStaticBuffer(4000000);
