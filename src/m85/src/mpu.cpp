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

/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                     $Archive:: /Commando/Code/wwlib/mpu.cpp                                $*
 *                                                                                             *
 *                      $Author:: Denzil_l                                                    $*
 *                                                                                             *
 *                     $Modtime:: 8/23/01 5:07p                                               $*
 *                                                                                             *
 *                    $Revision:: 4                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   Get_CPU_Rate -- Fetch the rate of CPU ticks per second.                                   *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "mpu.h"

#include "win.h"

#include <math.h>

typedef union {
	LARGE_INTEGER LargeInt;
	struct QuadPart {
		unsigned int LowPart;
		unsigned int HighPart;
	} QuadPart;
} QuadValue;


/***********************************************************************************************
 * Get_CPU_Rate -- Fetch the rate of CPU ticks per second.                                     *
 *                                                                                             *
 *    This routine will query the CPU to determine how many clock per second it is.            *
 *                                                                                             *
 * INPUT:   high  -- Reference to the location that will be filled with the upper 32 bits      *
 *                   of the result.                                                            *
 *                                                                                             *
 * OUTPUT:  Returns with the lower 32 bits of the result.                                      *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/20/1997 JLB : Created.                                                                 *
 *=============================================================================================*/
unsigned int Get_CPU_Rate(unsigned int & high)
{
	union {
		LARGE_INTEGER LargeInt;
		struct {
			unsigned int LowPart;
			unsigned int HighPart;
		} QuadPart;
	} value;

	if (QueryPerformanceFrequency(&value.LargeInt)) {
		high = value.QuadPart.HighPart;
		return(value.QuadPart.LowPart);
	}
	high = 0;
	return(0);
}


#if 0
/***********************************************************************************************
 * Get_CPU_Clock -- Fetches the current CPU clock time.                                        *
 *                                                                                             *
 *    This routine will return the internal Pentium clock accumulator. This accumulator is     *
 *    incremented every clock tick. Since this clock value can get very very large, the value  *
 *    returned is in 64 bits. The low half is returned directly, the high half is stored in    *
 *    location specified.                                                                      *
 *                                                                                             *
 * INPUT:   high  -- Reference to the high value of the 64 bit clock number.                   *
 *                                                                                             *
 * OUTPUT:  Returns with the low half of the CPU clock value.                                  *
 *                                                                                             *
 * WARNINGS:   This instruction is only available on Pentium or later processors.              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/17/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
unsigned int Get_CPU_Clock(unsigned int & high)
{
	int h;
	int l;
	__asm {
		_emit 0Fh
		_emit 31h
		mov	[h],edx
		mov	[l],eax
	}
	high = h;
	return(l);
}
#endif


/*
 * Based on code released by Intel
 * http://db.zmitac.aei.polsl.pl/Electronics_Firm_Docs/PENTIUMIII/pentium/cpuinfo.zip
 */

/*
**
** Cut and paste job from an intel example.
**
**
**
**
**
**
*/

#define ASM_RDTSC _asm _emit 0x0f _asm _emit 0x31

// Max # of samplings to allow before giving up and returning current average.
#define MAX_TRIES			20
#define ROUND_THRESHOLD		6

// # of MHz to allow samplings to deviate from average of samplings.
#define TOLERANCE			1

static unsigned long TSC_Low;
static unsigned long TSC_High;

/// <summary>
/// Samples the processor's time stamp counter.
/// This routine executes the RDTSC opcode and stashes the two halves of the 64 bit cycle
/// count in the module's time stamp globals, where the timing code can pick them up.
/// </summary>
/// <remarks>Only call this routine on a processor that supports the RDTSC opcode.</remarks>
void RDTSC(void)
{
	_asm
	{
		ASM_RDTSC;
		mov	TSC_Low, eax
		mov	TSC_High, edx
	}
}





