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

/* $Header: /CounterStrike/CONNECT.CPP 1     3/03/97 10:24a Joe_bostic $ */
/***************************************************************************
 **   C O N F I D E N T I A L --- W E S T W O O D    S T U D I O S        **
 ***************************************************************************
 *                                                                         *
 *                 Project Name : Command & Conquer                        *
 *                                                                         *
 *                    File Name : CONNECT.CPP                              *
 *                                                                         *
 *                   Programmer : Bill Randolph                            *
 *                                                                         *
 *                   Start Date : December 20, 1994                        *
 *                                                                         *
 *                  Last Update : May 31, 1995 [BRR]                       *
 *-------------------------------------------------------------------------*
 * Functions:                                                              *
 *   ConnectionClass::ConnectionClass -- class constructor                 *
 *   ConnectionClass::~ConnectionClass -- class destructor                 *
 *   ConnectionClass::Init -- Initializes connection queue to empty        *
 *   ConnectionClass::Send_Packet -- adds a packet to the send queue       *
 *   ConnectionClass::Receive_Packet -- adds packet to receive queue       *
 *   ConnectionClass::Get_Packet -- gets a packet from receive queue       *
 *   ConnectionClass::Service -- main polling routine; services packets    *
 *   ConnectionClass::Service_Send_Queue -- services the send queue        *
 *   ConnectionClass::Service_Receive_Queue -- services receive queue      *
 *   ConnectionClass::Time -- gets current time                            *
 *   ConnectionClass::Command_Name -- returns name for a packet command    *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "connect.h"

#include "_timer.h"
#include "dbgprint.h"

#include <cstdio>
#include <cstring>
#include <sys\timeb.h>
#include "session.h"

/*
**	RA2: the original path of this source file, passed with its debug messages.
*/
#define RA2_SOURCE "C:\\RA2\\Connect.CPP"



/*
********************************* Globals ***********************************
*/
char const * ConnectionClass::Commands[PACKET_COUNT] = {
	"ADATA",
	"NDATA",
	"ACK"
};


/***************************************************************************
 * ConnectionClass::ConnectionClass -- class constructor                   *
 *                                                                         *
 * INPUT:                                                                  *
 *      numsend         desired # of entries for the send queue            *
 *      numreceive      desired # of entries for the receive queue         *
 *      maxlen         max length of an application packet                 *
 *      magicnum         the packet "magic number" for this connection     *
 *      retry_delta      the time to wait between sends                    *
 *      max_retries      the max # of retries allowed for a packet         *
 *                     (-1 means retry forever, based on this parameter)   *
 *      timeout         the max amount of time before we give up on a packet*
 *                     (-1 means retry forever, based on this parameter)   *
 *      extralen         max size of app-specific extra bytes (optional)   *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
ConnectionClass::ConnectionClass (int numsend, int numreceive,
	int maxlen, unsigned short magicnum, unsigned int retry_delta,
	unsigned int max_retries, unsigned int timeout, int extralen)
{
	/*------------------------------------------------------------------------
	Compute our maximum packet length
	------------------------------------------------------------------------*/
	MaxPacketLen = maxlen + sizeof(CommHeaderType);

	/*------------------------------------------------------------------------
	Assign the magic number
	------------------------------------------------------------------------*/
	MagicNum = magicnum;

	/*------------------------------------------------------------------------
	Initialize the retry time.  This is the time that t2 - t1 must be greater
	than before a retry will occur.
	------------------------------------------------------------------------*/
	RetryDelta = retry_delta;

	/*------------------------------------------------------------------------
	Set the maximum allowable retries.
	------------------------------------------------------------------------*/
	MaxRetries = max_retries;

	/*------------------------------------------------------------------------
	Set the timeout for this connection.
	------------------------------------------------------------------------*/
	Timeout = timeout;

	/*------------------------------------------------------------------------
	Allocate the packet staging buffer.  This will be used to
	------------------------------------------------------------------------*/
	PacketBuf = new char[ MaxPacketLen ];

	/*------------------------------------------------------------------------
	Allocate the packet Queue.  This will store incoming packets (placed there
	by Receive_Packet), and outgoing packets (placed there by Send_Packet).
	It can optionally store "extra" bytes, which are stored along with each
	packet, but aren't transmitted as part of the packet.  If 'extralen'
	is 0, the CommBufferClass ignores this parameter.
	------------------------------------------------------------------------*/
	Queue = new CommBufferClass (numsend, numreceive, MaxPacketLen, extralen);

}	/* end of ConnectionClass */


/***************************************************************************
 * ConnectionClass::~ConnectionClass -- class destructor                   *
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
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of ~ConnectionClass */


/***************************************************************************
 * ConnectionClass::Init -- Initializes connection queue to empty          *
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
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Init */


/***************************************************************************
 * ConnectionClass::Send_Packet -- adds a packet to the send queue         *
 *                                                                         *
 * This routine prefixes the given buffer with a CommHeaderType and        *
 * queues the resulting packet into the Send Queue.  (It's actually the    *
 * Service() routine that handles the hardware-dependent Send of the data).*
 * The packet's MagicNumber, Code, and PacketID are set here.              *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         buffer to send                                         *
 *      buflen      length of buffer                                       *
 *      ack_req      1 = ACK is required for this packet; 0 = isn't        *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = packet was queue'd OK, 0 = wasn't                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
int ConnectionClass::Send_Packet (void * buf, int buflen, int ack_req, int extra) // RA2: extra is the forward mask
{
	/*------------------------------------------------------------------------
	Set the magic # for the packet
	------------------------------------------------------------------------*/
	((CommHeaderType *)PacketBuf)->MagicNumber = MagicNum;

	/*------------------------------------------------------------------------
	Set the packet Code: DATA_ACK if it requires an ACK, NOACK if it doesn't
	Set the packet ID to the appropriate counter value.
	------------------------------------------------------------------------*/
	if (ack_req) {
		((CommHeaderType *)PacketBuf)->Code = PACKET_DATA_ACK;
		((CommHeaderType *)PacketBuf)->PacketID = NumSendAck;
		DebugString("NumSendAck = %d\n", NumSendAck); // RA2
	} else {
		((CommHeaderType *)PacketBuf)->Code = PACKET_DATA_NOACK;
		((CommHeaderType *)PacketBuf)->PacketID = NumSendNoAck;
	}
	if (Session.Type == GAME_INTERNET && Session.ViaPacketRouter) { // RA2: routed packets carry their forward mask
		((CommHeaderType *)PacketBuf)->ForwardMask = extra;
	}
	if (MaxPacketLen < buflen) { // RA2
		DebugString("MaxPacketLen = %d\n", MaxPacketLen);
		DebugString("buflen = %d\n", buflen);
		return(0);
	}

	/*------------------------------------------------------------------------
	Now build the packet
	------------------------------------------------------------------------*/
	memcpy(PacketBuf + sizeof(CommHeaderType), buf, buflen);

	/*------------------------------------------------------------------------
	Add it to the queue; don't add any extra data with it.
	------------------------------------------------------------------------*/
	if (Queue->Queue_Send(PacketBuf,buflen + sizeof(CommHeaderType), NULL, 0)) {
		if (ack_req) {
			NumSendAck++;
		} else {
			NumSendNoAck++;
		}
		return(1);
	} else {
		return(0);
	}

}	/* end of Send_Packet */


/***************************************************************************
 * ConnectionClass::Receive_Packet -- adds packet to receive queue         *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf      buffer to process (already includes CommHeaderType)       *
 *      buflen   length of buffer to process                               *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = packet was processed OK, 0 = error                             *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Receive_Packet */


/***************************************************************************
 * ConnectionClass::Get_Packet -- gets a packet from receive queue         *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf      location to store buffer                                  *
 *      buflen   filled in with length of 'buf'                            *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = packet was read, 0 = wasn't                                    *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Get_Packet */


/***************************************************************************
 * ConnectionClass::Service -- main polling routine; services packets      *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK, 0 = error (connection is broken!)                          *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Service */


/***************************************************************************
 * ConnectionClass::Service_Send_Queue -- services the send queue          *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK, 0 = error                                                  *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Service_Send_Queue */


/// <summary>
/// Handles a connection that has failed its service pass.
/// This routine is the do-nothing default for connections that cannot clog. The
/// connection manager calls it when Service reports failure, giving a derived
/// connection the chance to throw away whatever is blocking its queues.
/// </summary>
/// <returns>Returns with the number of entries discarded, none at this level.</returns>
int ConnectionClass::Discard_Undeliverable_Packets(void)
{
	return(0);
}

/***************************************************************************
 * ConnectionClass::Service_Receive_Queue -- services receive queue        *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK, 0 = error                                                  *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Service_Receive_Queue */


/***************************************************************************
 * ConnectionClass::Time -- gets current time                              *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
unsigned int ConnectionClass::Time (void)
{
	return(TickCount);
}	/* end of Time */


/***************************************************************************
 * ConnectionClass::Command_Name -- returns name for given packet command  *
 *                                                                         *
 * INPUT:                                                                  *
 *      command      packet Command value to get name for                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      ptr to command name, NULL if invalid                               *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/31/1995 BRR : Created.                                             *
 *=========================================================================*/
const char *ConnectionClass::Command_Name(int command)
{
	if (command >= 0 && command < PACKET_COUNT) {
		return(Commands[command]);
	} else {
		return(NULL);
	}

}	/* end of Command_Name */

/************************** end of connect.cpp *****************************/
