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

/* $Header: /CounterStrike/COMBUF.CPP 1     3/03/97 10:24a Joe_bostic $ */
/***************************************************************************
 **   C O N F I D E N T I A L --- W E S T W O O D    S T U D I O S        **
 ***************************************************************************
 *                                                                         *
 *                 Project Name : Command & Conquer                        *
 *                                                                         *
 *                    File Name : COMBUF.CPP                               *
 *                                                                         *
 *                   Programmer : Bill Randolph                            *
 *                                                                         *
 *                   Start Date : December 19, 1994                        *
 *                                                                         *
 *                  Last Update : October 23, 1995 [BRR]                   *
 *                                                                         *
 *-------------------------------------------------------------------------*
 * Functions:                                                              *
 *   CommBufferClass::CommBufferClass -- class constructor                 *
 *   CommBufferClass::~CommBufferClass -- class destructor                 *
 *   CommBufferClass::Init -- initializes this queue                       *
 *   CommBufferClass::Init_Send_Queue -- Clears the send queue             *
 *   CommBufferClass::Queue_Send -- queues a message for sending           *
 *   CommBufferClass::UnQueue_Send -- removes next entry from send queue   *
 *   CommBufferClass::Get_Send -- gets ptr to queue entry                  *
 *   CommBufferClass::Queue_Receive -- queues a received message           *
 *   CommBufferClass::UnQueue_Receive -- removes next entry from send queue*
 *   CommBufferClass::Get_Receive -- gets ptr to queue entry               *
 *   CommBufferClass::Add_Delay -- adds a new delay value for response time*
 *   CommBufferClass::Avg_Response_Time -- returns average response time   *
 *   CommBufferClass::Max_Response_Time -- returns max response time       *
 *   CommBufferClass::Reset_Response_Time -- resets computations           *
 *   Mono_Debug_Print -- Debug output routine                              *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "combuf.h"

#include "_timer.h"

#include "_mono.h"
#include "connect.h" // for command names for debug output
#include "dbgprint.h"
#include "mono.h" // to enable mono output

#include <cstdio>
#include <cstring>

#if _MSC_VER > 1200
static_assert(static_cast<unsigned char>('Ú') == 0xDA, "combuf.cpp must be encoded in CP437");
#endif


/***************************************************************************
 * CommBufferClass::CommBufferClass -- class constructor                   *
 *                                                                         *
 * INPUT:                                                                  *
 *      numsend      # queue entries for sending                           *
 *      numreceive   # queue entries for receiving                         *
 *      maxlen      maximum desired packet length, in bytes                *
 *      extralen      max size of app-specific extra bytes (optional)      *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/19/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of CommBufferClass */


/***************************************************************************
 * CommBufferClass::~CommBufferClass -- class destructor                   *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/19/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of ~CommBufferClass */


/***************************************************************************
 * CommBufferClass::Init -- initializes this queue                         *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/20/1995 BR : Created.                                              *
 *=========================================================================*/
	/* end of Init */


/***************************************************************************
 * CommBufferClass::Init_Send_Queue -- Clears the send queue               *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   10/23/1995 BRR : Created.                                             *
 *=========================================================================*/
	/* end of Init_Send_Queue */


/***************************************************************************
 * CommBufferClass::Queue_Send -- queues a message for sending             *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         buffer containing the message                          *
 *      buflen      length of 'buf'                                        *
 *      extrabuf      buffer containing extra data (optional)              *
 *      extralen      length of extra data (optional)                      *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK, 0 = no room in the queue                                   *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Queue_Send */


/***************************************************************************
 * CommBufferClass::UnQueue_Send -- removes next entry from send queue     *
 *                                                                         *
 * Frees the given entry; the index given by the caller is the "active"    *
 * index value (ie the "nth" active entry), not the actual index in the    *
 * array.                                                                  *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         buffer to store entry's data in; if NULL, it's discarded*
 *      buflen      filled in with length of entry retrieved               *
 *      index         "index" of entry to un-queue                         *
 *      extrabuf      buffer for extra data (optional)                     *
 *      extralen      ptr to length of extra data (optional)               *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK, 0 = no entry to retrieve                                   *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of UnQueue_Send */


/***************************************************************************
 * CommBufferClass::Get_Send -- gets ptr to queue entry                    *
 *                                                                         *
 * This routine gets a pointer to the indicated queue entry.  The index    *
 * value is relative to the next-accessible queue entry; 0 = get the       *
 * next available queue entry, 1 = get the one behind that, etc.           *
 *                                                                         *
 * INPUT:                                                                  *
 *      index      index of entry to get (0 = 1st available)               *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      ptr to entry                                                       *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/21/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Get_Send */


/***************************************************************************
 * CommBufferClass::Queue_Receive -- queues a received message             *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         buffer containing the message                          *
 *      buflen      length of 'buf'                                        *
 *      extrabuf      buffer containing extra data (optional)              *
 *      extralen      length of extra data (optional)                      *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK, 0 = no room in the queue                                   *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Queue_Receive */


/***************************************************************************
 * CommBufferClass::UnQueue_Receive -- removes next entry from send queue  *
 *                                                                         *
 * Frees the given entry; the index given by the caller is the "active"    *
 * index value (ie the "nth" active entry), not the actual index in the    *
 * array.                                                                  *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         buffer to store entry's data in; if NULL, it's discarded*
 *      buflen      filled in with length of entry retrieved               *
 *      index         index of entry to un-queue                           *
 *      extrabuf      buffer for extra data (optional)                     *
 *      extralen      ptr to length of extra data (optional)               *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK, 0 = no entry to retrieve                                   *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of UnQueue_Receive */


/***************************************************************************
 * CommBufferClass::Get_Receive -- gets ptr to queue entry                 *
 *                                                                         *
 * This routine gets a pointer to the indicated queue entry.  The index    *
 * value is relative to the next-accessible queue entry; 0 = get the       *
 * next available queue entry, 1 = get the one behind that, etc.           *
 *                                                                         *
 * INPUT:                                                                  *
 *      index      index of entry to get (0 = 1st available)               *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      ptr to entry                                                       *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/21/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Get_Receive */


/***************************************************************************
 * CommBufferClass::Add_Delay -- adds a new delay value for response time  *
 *                                                                         *
 * This routine updates the average response time for this queue.  The     *
 * computation is based on the average of the last 'n' delay values given, *
 * It computes a running total of the last n delay values, then divides    *
 * that by n to compute the average.                                       *
 *                                                                         *
 * When the number of values given exceeds the max, the mean is subtracted *
 * off the total, then the new value is added in.  Thus, any single delay  *
 * value will have an effect on the total that approaches 0 over time, and *
 * the new delay value contributes to 1/n of the mean.                     *
 *                                                                         *
 * INPUT:                                                                  *
 *      delay         value to add into the response time computation      *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/19/1995 BR : Created.                                              *
 *=========================================================================*/
void CommBufferClass::Add_Delay(unsigned int delay)
{
	int roundoff = 0;

	if (NumDelay==256) {
		DelaySum -= MeanDelay;
		DelaySum += delay;
		if ( (DelaySum & 0x00ff) > 127)
			roundoff = 1;
		MeanDelay = (DelaySum >> 8) + roundoff;
	}
	else {
		NumDelay++;
		DelaySum += delay;
		MeanDelay = DelaySum / NumDelay;
	}

	if (delay > MaxDelay) {
		MaxDelay = delay;
	}

}	/* end of Add_Delay */


/***************************************************************************
 * CommBufferClass::Avg_Response_Time -- returns average response time     *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      latest computed average response time                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/19/1995 BR : Created.                                              *
 *=========================================================================*/
unsigned int CommBufferClass::Avg_Response_Time(void)
{
	return(MeanDelay);

}	/* end of Avg_Response_Time */


/***************************************************************************
 * CommBufferClass::Max_Response_Time -- returns max response time         *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      latest computed average response time                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/19/1995 BR : Created.                                              *
 *=========================================================================*/
unsigned int CommBufferClass::Max_Response_Time(void)
{
	return(MaxDelay);

}	/* end of Max_Response_Time */


/***************************************************************************
 * CommBufferClass::Reset_Response_Time -- resets computations             *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/19/1995 BR : Created.                                              *
 *=========================================================================*/
	/* end of Reset_Response_Time */


/***************************************************************************
 * CommBufferClass::Configure_Debug -- sets up special debug values        *
 *                                                                         *
 * Mono_Debug_Print2() can look into a packet to pull out a particular     *
 * ID, and can print both that ID and a string corresponding to            *
 * that ID.  This routine configures these values so it can find           *
 * and decode the ID.  This ID is used in addition to the normal           *
 * CommHeaderType values.                                                  *
 *                                                                         *
 * INPUT:                                                                  *
 *      type_offset      ID's byte offset into packet                      *
 *      type_size      size of ID, in bytes; 0 if none                     *
 *      names            ptr to array of names; use ID as an index into this*
 *      maxnames         max # in the names array; 0 if none.              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      Names shouldn't be longer than 12 characters.                      *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/31/1995 BRR : Created.                                             *
 *=========================================================================*/
	/* end of Configure_Debug */


/***************************************************************************
 * Mono_Debug_Print -- Debug output routine                                *
 *                                                                         *
 * This routine leaves 5 lines at the top for the caller's use.            *
 *                                                                         *
 * INPUT:                                                                  *
 *      refresh      1 = clear screen & completely refresh                 *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/02/1995 BRR : Created.                                             *
 *=========================================================================*/
	/* end of Mono_Debug_Print */


/***************************************************************************
 * CommBufferClass::Mono_Debug_Print2 -- Debug output; alternate format    *
 *                                                                         *
 * This routine prints more information than the other version; it's       *
 * called only if the number of queue entries is small enough to support   *
 * this format.                                                            *
 *                                                                         *
 * INPUT:                                                                  *
 *      refresh      1 = clear screen & completely refresh                 *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/31/1995 BRR : Created.                                             *
 *=========================================================================*/
	/* end of Mono_Debug_Print2 */


/************************** end of combuf.cpp ******************************/
