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

/* $Header: /CounterStrike/IPXGCONN.CPP 3     10/13/97 2:20p Steve_t $ */
/***************************************************************************
 **   C O N F I D E N T I A L --- W E S T W O O D    S T U D I O S        **
 ***************************************************************************
 *                                                                         *
 *                 Project Name : Command & Conquer                        *
 *                                                                         *
 *                    File Name : IPXGCONN.CPP                             *
 *                                                                         *
 *                   Programmer : Bill Randolph                            *
 *                                                                         *
 *                   Start Date : December 20, 1994                        *
 *                                                                         *
 *                  Last Update : July 6, 1995 [BRR]                       *
 *-------------------------------------------------------------------------*
 * Functions:                                                              *
 *   IPXGlobalConnClass::IPXGlobalConnClass -- class constructor           *
 *   IPXGlobalConnClass::~IPXGlobalConnClass -- class destructor           *
 *   IPXGlobalConnClass::Send_Packet -- adds a packet to the send queue    *
 *   IPXGlobalConnClass::Receive_Packet -- adds packet to the receive queue*
 *   IPXGlobalConnClass::Get_Packet -- gets a packet from the receive queue*
 *   IPXGlobalConnClass::Send -- sends a packet                            *
 *   IPXGlobalConnClass::Service_Receive_Queue -- services receive queue   *
 *   IPXGlobalConnClass::Set_Bridge -- Sets up connection to cross a bridge*
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "ipxgconn.h"

#include "_timer.h"
#include "_wsproto.h"
#include "dbgprint.h"
#include "globals.h"
#include "ipxmgr.h"
#include "ownertalk.h"
#include "session.h"
#include "wspudp.h"

#include <cstdio>
#include <cstring>


/***************************************************************************
 * IPXGlobalConnClass::IPXGlobalConnClass -- class constructor             *
 *                                                                         *
 * This routine chains to the parent constructor, but it adjusts the size  *
 * of the packet by the added bytes in the GlobalHeaderType structure.     *
 * This forces the parent classes to allocate the proper sized PacketBuf   *
 * for outgoing packets, and to set MaxPacketLen to the proper value.      *
 *                                                                         *
 * INPUT:                                                                  *
 *      numsend         desired # of entries for the send queue            *
 *      numreceive      desired # of entries for the receive queue         *
 *      maxlen         max length of an application packet                 *
 *      product_id      unique ID for this product                         *
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
IPXGlobalConnClass::IPXGlobalConnClass (int numsend, int numreceive,
	int maxlen, unsigned short product_id, unsigned short magicnum) : // RA2: magic number
	BASECLASS (numsend, numreceive,
		maxlen + sizeof(GlobalHeaderType) - sizeof(CommHeaderType),
		magicnum,                   // RA2: magic number for this connection
		NULL,                       // IPX Address (none)
		0,                          // Connection ID
		L"",                        // Connection Name
		sizeof (IPXAddressClass))   // extra storage for the sender's address
{

	ProductID = product_id;
	IsBridge = 0;
	IsRouted = true; // RA2
	MaxRXIndex = numreceive;
	LastPacketID = new unsigned int[MaxRXIndex];
	LastAddress = new IPXAddressClass[MaxRXIndex];

	for (int i = 0; i < MaxRXIndex; i++) {
		LastPacketID[i] = 0xffffffff;
	}

	LastRXIndex = 0;

}	/* end of IPXGlobalConnClass */


/// <summary>
/// Destroys the global connection.
/// The record of recently received packets, which the connection keeps in order to
/// recognize resends, is thrown away along with it.
/// </summary>
IPXGlobalConnClass::~IPXGlobalConnClass(void)
{
	if (LastPacketID) {
		delete [] LastPacketID;
		LastPacketID = NULL;
	}
	if (LastAddress) {
		delete [] LastAddress;
		LastAddress = NULL;
	}
}


/***************************************************************************
 * IPXGlobalConnClass::Send_Packet -- adds a packet to the send queue      *
 *                                                                         *
 * This routine prefixes the given buffer with a GlobalHeaderType and      *
 * queues the resulting packet into the Send Queue.  The packet's          *
 * MagicNumber, Code, PacketID, destination Address and ProductID are set  *
 * here.                                                                   *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         buffer to send                                         *
 *      buflen      length of buffer                                       *
 *      address      address to send the packet to (NULL = Broadcast)      *
 *      ack_req      1 = ACK is required for this packet; 0 = isn't        *
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
int IPXGlobalConnClass::Send_Packet (void * buf, int buflen,
	IPXAddressClass *address, int ack_req) // level-2 1.001: no port/packet ID
{
	IPXAddressClass dest_addr;

	/*------------------------------------------------------------------------
	Store the packet's Magic Number
	------------------------------------------------------------------------*/
	// level-2 1.001: no ForwardAddress/ForwardPort fields
	((GlobalHeaderType *)PacketBuf)->Header.MagicNumber = MagicNum;

	/*------------------------------------------------------------------------
	If this is a ACK-required packet, sent to a specific system, mark it as
	ACK-required; otherwise, mark as no-ACK-required.
	------------------------------------------------------------------------*/
	if (ack_req && address != NULL) {
		((GlobalHeaderType *)PacketBuf)->Header.Code = PACKET_DATA_ACK;
	}
	else {
		((GlobalHeaderType *)PacketBuf)->Header.Code = PACKET_DATA_NOACK;
	}

	/*------------------------------------------------------------------------
	Fill in the packet ID.  This will have very limited meaning; it only
	allows us to determine if an ACK packet we receive later goes with this
	packet; it doesn't let us detect re-sends of other systems' packets.
	------------------------------------------------------------------------*/
	((GlobalHeaderType *)PacketBuf)->Header.PacketID = Queue->Send_Total();

	/*------------------------------------------------------------------------
	Set the product ID for this packet.
	------------------------------------------------------------------------*/
	// level-2 1.001: no caller-given packet ID
	((GlobalHeaderType *)PacketBuf)->ProductID = ProductID;

	/*------------------------------------------------------------------------
	Set this packet's destination address.  If no address is specified, use
	a Broadcast address (which IPXAddressClass's default constructor creates).
	------------------------------------------------------------------------*/
	((GlobalHeaderType *)PacketBuf)->Header.ForwardMask = 0; // RA2
	if (address != NULL) {
		dest_addr = (*address);
	}

	/*------------------------------------------------------------------------
	Copy the application's data
	------------------------------------------------------------------------*/
	memcpy(PacketBuf + sizeof(GlobalHeaderType), buf, buflen);

	/*------------------------------------------------------------------------
	Queue it, along with the destination address
	------------------------------------------------------------------------*/
	return(Queue->Queue_Send(PacketBuf,buflen + sizeof(GlobalHeaderType),
		&dest_addr, sizeof (IPXAddressClass))); // level-2 1.001: no port

}	/* end of Send_Packet */


/***************************************************************************
 * IPXGlobalConnClass::Receive_Packet -- adds packet to the receive queue  *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf      buffer to process (already includes GlobalHeaderType)     *
 *      buflen   length of buffer to process                               *
 *      address   the address of the sender (the IPX Manager class must    *
 *               extract this from the IPX Header of the received packet.) *
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
int IPXGlobalConnClass::Receive_Packet (void * buf, int buflen,
	IPXAddressClass *address) // level-2 1.001: no port
{
	GlobalHeaderType *packet;       // ptr to this packet
	SendQueueType *send_entry;      // ptr to send entry header
	GlobalHeaderType *entry_data;   // ptr to queue entry data
	GlobalHeaderType ackpacket;     // ACK packet to send
	int i;
	int resend;

	/*------------------------------------------------------------------------
	Check the magic #
	------------------------------------------------------------------------*/
	packet = (GlobalHeaderType *)buf;
	if (packet->Header.MagicNumber!=MagicNum) {
		return(0);
	}

	/*------------------------------------------------------------------------
	Process the packet based on its Code
	------------------------------------------------------------------------*/
	switch (packet->Header.Code) {
		//.....................................................................
		// DATA_ACK: Check for a resend by comparing the source address &
		// ID of this packet with our last 4 received packets.
		// Send an ACK for the packet, regardless of whether it's a resend
		// or not.
		//.....................................................................
		case PACKET_DATA_ACK:
			//..................................................................
			// Check for a resend
			//..................................................................
			resend = 0;
			for (i = 0; i < MaxRXIndex; i++) {
				if ((unsigned)i >= Queue->Receive_Total()) {
					break;
				}
				if ((*address)==LastAddress[i] &&
					packet->Header.PacketID==LastPacketID[i]) {
					resend = 1;
					break;
				}
			}

			//..................................................................
			// If it's not a resend, queue it; then, record the sender's address
			// & the packet ID for future resend detection.
			//..................................................................
			{
			bool send_ack = true;

			if (!resend) {
				if (Queue->Queue_Receive (buf, buflen, address, sizeof(IPXAddressClass))) {
					LastAddress[LastRXIndex] = (*address);
					LastPacketID[LastRXIndex] = packet->Header.PacketID;
					LastRXIndex++;
					if (LastRXIndex >= MaxRXIndex) {
						LastRXIndex = 0;
					}
				}else{
					//..................................................................
					// Don't send an ack if we didn't have room to store the packet.
					//..................................................................
					send_ack = false;
					DebugString("Failed to queue incoming packet. Ack not sent\n");
				}
			}

			//..................................................................
			// Send an ACK for this packet
			//..................................................................
			if (send_ack) {
				ackpacket.Header.MagicNumber = MagicNum;
				ackpacket.Header.Code = PACKET_ACK;
				ackpacket.Header.ForwardMask = 0; // RA2
				ackpacket.Header.PacketID = packet->Header.PacketID;
				ConnectionClass *router = PacketRouterConnection;
				ackpacket.ProductID = ProductID;
				if (!Send ((char *)&ackpacket, sizeof(GlobalHeaderType),
					address, sizeof(IPXAddressClass), this == router)) { // RA2: router flag; level-2 1.001: no port
					DebugString("Failed to ack global packet\n");
				}
			}
			}
			break;

		/*.....................................................................
		DATA_NOACK: Queue this message, along with the sender's address.
		Don't bother checking for a Re-Send, since the other system will only
		send this packet once.
		.....................................................................*/
		case PACKET_DATA_NOACK:
			Queue->Queue_Receive (buf, buflen, address, sizeof(IPXAddressClass)); // level-2 1.001: the sender's address as given
			break;

		/*.....................................................................
		ACK: If this ACK is for any of my packets, mark that packet as
		acknowledged, then throw this packet away.  Otherwise, ignore the ACK
		(if we re-sent before we received the other system's first ACK, this
		ACK will be a leftover)
		.....................................................................*/
		case PACKET_ACK:
			for (i = 0; i < Queue->Num_Send(); i++) {
				/*...............................................................
				Get queue entry ptr
				...............................................................*/
				send_entry = Queue->Get_Send(i);

				/*...............................................................
				If ptr is valid, get ptr to its data
				...............................................................*/
				entry_data = (GlobalHeaderType *)(send_entry->Buffer);

				/*...............................................................
				If ACK is for this entry, mark it
				...............................................................*/
				if (packet->Header.PacketID==entry_data->Header.PacketID &&
					entry_data->Header.Code == PACKET_DATA_ACK) {
					send_entry->IsACK = 1;
					break;
				}
			}
			break;

		/*.....................................................................
		Default: ignore the packet
		.....................................................................*/
		default:
			break;
	}

	return(1);

}	/* end of Receive_Packet */


/***************************************************************************
 * IPXGlobalConnClass::Get_Packet -- gets a packet from the receive queue  *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         location to store buffer                               *
 *      buflen      filled in with length of 'buf'                         *
 *      address      filled in with sender's address                       *
 *      product_id   filled in with sender's ProductID                     *
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
int IPXGlobalConnClass::Get_Packet (void * buf, int *buflen,
	IPXAddressClass *address, unsigned short *product_id)
{
	ReceiveQueueType *rec_entry;					// ptr to receive entry header
	GlobalHeaderType *packet;
	int packetlen;										// size of received packet

	/*------------------------------------------------------------------------
	Return if nothing to do
	------------------------------------------------------------------------*/
	if (Queue->Num_Receive() == 0) {
		return(0);
	}

	/*------------------------------------------------------------------------
	Get ptr to the next available entry
	------------------------------------------------------------------------*/
	rec_entry = Queue->Get_Receive(0);

	/*------------------------------------------------------------------------
	Read it if it's un-read
	------------------------------------------------------------------------*/
	if (rec_entry!=NULL && rec_entry->IsRead==0) {

		/*.....................................................................
		Mark as read
		.....................................................................*/
		rec_entry->IsRead = 1;

		/*.....................................................................
		Copy data packet
		.....................................................................*/
		packet = (GlobalHeaderType *)(rec_entry->Buffer);
		packetlen = rec_entry->BufLen - sizeof(GlobalHeaderType);
		if (packetlen > 0) {
			memcpy(buf, rec_entry->Buffer + sizeof(GlobalHeaderType), packetlen);
		}
		(*buflen) = packetlen;
		(*product_id) = packet->ProductID;
		(*address) = (*((IPXAddressClass *)(rec_entry->ExtraBuffer)));

		return(1);
	}

	return(0);

}	/* end of Get_Packet */


/// <summary>
/// RA2: Fetches the packet at the index of the receive queue without removing it.
/// </summary>
int IPXGlobalConnClass::Peek_Packet(int index, int buf, int buflen, int address, int product_id, int packet_id)
{
	ReceiveQueueType *rec_entry;
	GlobalHeaderType *packet;
	int packetlen;

	if (Queue->Num_Receive() >= index) {
		rec_entry = Queue->Get_Receive(index);

		if (rec_entry != NULL && rec_entry->IsRead == 0) {
			packet = (GlobalHeaderType *)(rec_entry->Buffer);
			packetlen = rec_entry->BufLen - sizeof(GlobalHeaderType);
			if (packetlen > 0) {
				memcpy((void *)buf, rec_entry->Buffer + sizeof(GlobalHeaderType), packetlen);
			}
			*(int *)buflen = packetlen;
			*(unsigned short *)product_id = packet->ProductID;
			*(IPXAddressClass *)address = *((IPXAddressClass *)(rec_entry->ExtraBuffer));
			if (packet_id != 0) {
				*(unsigned int *)packet_id = packet->Header.PacketID;
			}
			return(1);
		}
	}

	return(0);
}


/// <summary>
/// RA2: Marks the packet at the index of the receive queue as read.
/// </summary>
void IPXGlobalConnClass::Mark_Packet_Read(int index)
{
	if (index < Queue->Num_Receive()) {
		Queue->Get_Receive(index)->IsRead = 1;
	}
}


/***************************************************************************
 * IPXGlobalConnClass::Send -- sends a packet                              *
 *                                                                         *
 * This routine gets invoked by NonSequencedConn, when it's processing     *
 * the Send & Receive Queues.  The buffer provided will already have the   *
 * GlobalHeaderType header embedded in it.                                 *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         buffer to send                                         *
 *      buflen      length of buffer                                       *
 *      extrabuf      extra buffer to send                                 *
 *      extralen      length of extra buffer                               *
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
int IPXGlobalConnClass::Send(char *buf, int buflen, void *extrabuf, int extralen, bool flag) // level-2 1.001: no port
{
	IPXAddressClass *addr = (IPXAddressClass *)extrabuf;

	if (addr->Is_Broadcast()) {
		return(Broadcast (buf, buflen));
	}

	if (IsBridge && !memcmp (addr, BridgeNet, 4)) { // level-2 1.001: no game type test
		return(Send_To (buf, buflen, addr, BridgeNode, flag));
	}
	return(Send_To (buf, buflen, addr, NULL, flag));
}


/***************************************************************************
 * IPXGlobalConnClass::Service_Receive_Queue -- services the receive queue *
 *                                                                         *
 * This routine is necessary because the regular ConnectionClass checks    *
 * for sequential packet ID's before removing them from the receive queue; *
 * this class cannot do that.                                              *
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
int IPXGlobalConnClass::Service_Receive_Queue (void)
{
	int i;
	ReceiveQueueType *rec_entry;					// ptr to receive entry header

	//------------------------------------------------------------------------
	// Remove all dead packets:  If a packet's been read, throw it away.
	//------------------------------------------------------------------------
	for (i = 0; i < Queue->Num_Receive(); i++) {
		rec_entry = Queue->Get_Receive(i);

		if (rec_entry->IsRead) {
			Queue->UnQueue_Receive(NULL,NULL,i,NULL,NULL);
			i--;
		}
	}

	return(1);

} 	/* end of Service_Receive_Queue */


// level-2 1.001: no Discard_Old_Packets (1.006 only; no function between Service_Receive_Queue 0x523990 and Set_Bridge 0x5239d0).


/***************************************************************************
 * Set_Bridge -- Sets up connection to cross a bridge                      *
 *                                                                         *
 * This routine is designed to prevent the connection from having to       *
 * call Get_Local_Target, except the minimum number of times, since that   *
 * routine is buggy & goes away for long periods sometimes.                *
 *                                                                         *
 * INPUT:                                                                  *
 *      bridge      network number of the destination bridge               *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none                                                               *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/06/1995 BRR : Created.                                             *
 *=========================================================================*/
void IPXGlobalConnClass::Set_Bridge(NetNumType bridge)
{
	if (Configured) {
		IsBridge = 0;
	}
} 	/* end of Set_Bridge */


/// <summary>
/// Throws away the outgoing packets that will never be acknowledged.
/// The IPX manager calls this routine when the global channel reports that it has gone
/// bad, so that a single packet nobody ever answers cannot clog the channel forever.
/// Only packets that have already given up on their acknowledgement are discarded.
/// </summary>
/// <returns>Returns with the number of packets thrown away.</returns>
int IPXGlobalConnClass::Discard_Undeliverable_Packets(void)
{
	int num = 0;

	for (int i = 0; i < Queue->Num_Send(); i++) {
		SendQueueType *send_entry = Queue->Get_Send(i);

		if (send_entry->IsUndeliverable && !send_entry->IsACK) {

			IPXAddressClass address;
			char buf[1024];
			int buflen;

			int address_size = sizeof(address);
			Queue->UnQueue_Send(buf, &buflen, i, &address, &address_size); // level-2 1.001: no port
			i--;
			num++;
		}
	}

	return(num);
}


// level-2 1.001: no Discard_Packets_To (1.006 only; Send 0x523900 directly follows Discard_Undeliverable_Packets 0x5239f0 in vtable order, no code for it).


/// <summary>
/// RA2: Sends a global packet; through the packet router in an internet game routed by it.
/// </summary>
int IPXGlobalConnClass::Send_To(char *buf, int buflen, IPXAddressClass *address,
	NetNodeType immed, bool flag) // level-2 1.001: no port
{
	IPXAddressClass dest;

	dest = *address;
	if (immed) {
		NetNodeType node; // level-2 1.001: block-local, as in IPXConnClass::Send_To
		NetNumType net;
		address->Get_Address(net, node);
		memcpy(net, immed, 4);
		dest.Set_Address(net, node);
	}

	/*
	**	level-2 1.001: a routed packet of a game through the packet router carries the mask of
	**	the connection with the destination address and goes to the router (no game type test,
	**	no ports).
	*/
	if (!flag && Session.ViaPacketRouter && IsRouted) {
		if (!((GlobalHeaderType *)buf)->Header.ForwardMask) {
			char result = OwnerTalk.Mask_From_Address(&dest);
			if (!result) {
				return(0);
			}
			((GlobalHeaderType *)buf)->Header.ForwardMask = result;
		}
		dest = Session.PacketRouterAddress;
	}

	if (PacketTransport) {
		PacketTransport->WriteTo(buf, buflen, &dest, sizeof(dest), flag, IsRouted == 0); // level-2 1.001: WriteTo has no port
	}
	return(1);
}


/// <summary>
/// Adds a packet to the send queue.
/// This is the plain form inherited from the base connection; the global channel's own
/// version also takes the address to send the packet to.
/// </summary>
/// <param name="ack_req">Should the receiver be required to acknowledge this packet?</param>
/// <returns>Returns with non-zero if the packet was queued for sending.</returns>
int IPXGlobalConnClass::Send_Packet (void * buf, int buflen, int ack_req, int extra)
{
	return BASECLASS::Send_Packet(buf, buflen, ack_req, extra);
}


/***************************************************************************
 * IPXGlobalConnClass::Receive_Packet -- adds packet to the receive queue  *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf      buffer to process (already includes GlobalHeaderType)     *
 *      buflen   length of buffer to process                               *
 *      address   the address of the sender (the IPX Manager class must    *
 *               extract this from the IPX Header of the received packet.) *
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
int IPXGlobalConnClass::Receive_Packet (void * buf, int buflen)
{
	return BASECLASS::Receive_Packet(buf, buflen);
}


/// <summary>
/// Fetches the next packet from the receive queue.
/// This is the plain form inherited from the base connection; the global channel's own
/// version also reports the address the packet came from and the product that sent it.
/// </summary>
/// <param name="buflen">Pointer to the value to fill in with the length of the packet.</param>
/// <returns>Returns with non-zero if a packet was pulled off the queue.</returns>
int IPXGlobalConnClass::Get_Packet (void * buf, int * buflen)
{
	return BASECLASS::Get_Packet(buf, buflen);
}



/************************** end of ipxgconn.cpp ****************************/
