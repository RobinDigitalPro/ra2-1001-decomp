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

/* $Header: /CounterStrike/IPXADDR.H 1     3/03/97 10:24a Joe_bostic $ */
/***************************************************************************
 **   C O N F I D E N T I A L --- W E S T W O O D    S T U D I O S        **
 ***************************************************************************
 *                                                                         *
 *                 Project Name : Command & Conquer                        *
 *                                                                         *
 *                    File Name : IPXADDR.H                                *
 *                                                                         *
 *                   Programmer : Bill Randolph                            *
 *                                                                         *
 *                   Start Date : December 19, 1994                        *
 *                                                                         *
 *                  Last Update : December 19, 1994   [BR]                 *
 *                                                                         *
 * This class is useful for any IPX-related code.  It's just a utility     *
 * to help manage those annoying IPX address fields.  This class lets you  *
 * compare addresses, copy addresses to & from the IPX header, etc.        *
 *                                                                         *
 * The class has no virtual functions, so you can treat this class just    *
 * like a data structure; it can be loaded & saved, and even transmitted   *
 * across the net.                                                         *
 *                                                                         *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#pragma once

#include "ipx.h" // for NetNumType & NetNodeType


/*
***************************** Class Declaration *****************************
*/
class IPXAddressClass
{
	/*
	---------------------------- Public Interface ----------------------------
	*/
	public:
		/*.....................................................................
		Constructors:
		.....................................................................*/
		IPXAddressClass(void);
		IPXAddressClass(NetNumType net, NetNodeType node); // level-2 1.001: 0x00522980
		IPXAddressClass(NetNumType net, NetNodeType node, unsigned short port); // RA2: 1.006 only, no 1.001 definition (unadapted callers)
		IPXAddressClass(IPXHeaderType *header); // level-2 1.001: 0x005229B0

		/*.....................................................................
		Set the address from explicit variables, or from the SOURCE values
		in an IPX packet header.
		.....................................................................*/
		void Set_Address(NetNumType net, NetNodeType node); // level-2 1.001: 0x005229E0
		void Set_Address(NetNumType net, NetNodeType node, unsigned short port); // RA2: 1.006 only, no 1.001 definition (unadapted callers)
		void Set_Address(IPXHeaderType *header); // level-2 1.001: 0x00522A00
		/*.....................................................................
		Get the address values explicitly, or copy them into the DESTINATION
		values in an IPX packet header.
		.....................................................................*/
		void Get_Address (NetNumType net, NetNodeType node); // level-2 1.001: 0x00522A60
		void Get_Address(NetNumType net, NetNodeType node, unsigned short * port); // RA2: 1.006 only, no 1.001 definition (unadapted callers)
		void Get_Node(NetNodeType node); // RA2: 1.006 only, as above
		void Set_Node(NetNodeType node); // RA2: 1.006 only, as above
		void Set_Port(unsigned short port); // RA2: only for UDP addresses; 1.006 only, as above
		unsigned short Get_Port(void) { return *(unsigned short *)NetworkNumber; } // RA2: the port of a UDP address
		bool Is_Same_Node(IPXAddressClass & addr); // RA2: compares the node addresses only; 1.006 only, as above
		void Get_Address(IPXHeaderType *header); // level-2 1.001: 0x00522A80

		/*.....................................................................
		Tells if this address is a broadcast address
		.....................................................................*/
		int Is_Broadcast(void);

		/*.....................................................................
		Overloaded operators:
		.....................................................................*/
		bool operator == (IPXAddressClass & addr);
		bool operator != (IPXAddressClass & addr);
		bool operator > (IPXAddressClass &addr);
		bool operator < (IPXAddressClass &addr);
		bool operator >= (IPXAddressClass &addr);
		bool operator <= (IPXAddressClass &addr);

		/*.....................................................................
		Convert address to human readable string
		.....................................................................*/
		const char *As_String(void); // level-2 1.001: 0x00522CA0 takes no argument (1.006: As_String(IPXAddressClass * address = NULL))

	/*
	-------------------------- Protected Interface ---------------------------
	*/
	protected:
	/*
	--------------------------- Private Interface ----------------------------
	*/
	private:
		NetNumType NetworkNumber;
		NetNodeType NodeAddress;
		// level-2 1.001: no Unused_A member; the class is 0xA bytes with byte alignment in 1.001
		// (SessionClass ctor 0x664f70: MessageAddress +0x1E74 is followed by the chat flags at +0x1E7E;
		// router addresses at +0x290D/+0x2917). 1.006 had: unsigned short Unused_A; // +0xA, never accessed
};


/*
**	RA2: which protocol the addresses are for: 1 for IPX; 2 for UDP, where the network number field holds the port.
*/
extern int AddressProtocol; // level-2 1.001: 1.006 only (1.001 asks PacketTransport->Get_Protocol())
void Set_Address_Protocol(int protocol); // level-2 1.001: 1.006 only


/**************************** end of ipxaddr.h *****************************/
