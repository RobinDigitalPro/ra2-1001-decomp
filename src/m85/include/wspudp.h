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

/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                     $Archive:: /Sun/WSPUDP.h                                               $*
 *                                                                                             *
 *                      $Author:: Joe_b                                                       $*
 *                                                                                             *
 *                     $Modtime:: 8/05/97 6:45p                                               $*
 *                                                                                             *
 *                    $Revision:: 3                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#pragma once

#include "wsproto.h"

#include <nspapi.h>


/*
**	Class to allow access to UDP specific portions of the Winsock interface.
**
*/
class UDPInterfaceClass : public WinsockInterfaceClass {
		typedef WinsockInterfaceClass BASECLASS;

	public:

		UDPInterfaceClass (void);
		virtual ~UDPInterfaceClass(void) override;

		virtual void WriteTo (void *buffer, int buffer_len, void *address, int address_len, bool alternate, bool flag) override; // RA2; level-2 1.001: no port (0x758710 ends with ret 0x18)
		virtual void Broadcast (void *buffer, int buffer_len, bool alternate) override;
		// level-2 1.001: no Start_Listening/Stop_Listening overrides (vtable 0x79a964 slots 7/8 are the base 0x756fb0/0x757030)
		virtual void Set_Broadcast_Address ( char const * address ) override; // level-2 1.001: address only (0x758340)
		virtual void Clear_Broadcast_Addresses(void) override;

		virtual ProtocolEnum Get_Protocol (void) override;
		virtual int Protocol_Event_Message (SOCKET socketnum) override;
		virtual bool Open_Socket ( SOCKET socketnum ) override;
		virtual int Message_Handler(HWND window, UINT message, UINT wParam, LONG lParam) override;
		virtual int Get_Num_Local_Addresses(void) override;
		virtual unsigned char *Get_Local_Address(int index) override;

		// level-2 1.001: the 1.006 port machinery (OpenSocket, Get_Port, Init_Ports, Open_Port_Socket,
		// Close_Port_Socket, Close_All_Port_Sockets, Select_Port_Socket, Add_Peer, Is_Reachable) is absent:
		// the 1.001 vtable 0x79a964 has the base's 23 slots only, and no caller remains.

		static int UDPListenPort; // RA2: the port broadcasts go to when none is given; level-2 1.001: 0x7df968 (1234), bound by Open_Socket

	private:

		// level-2 1.001: no Port, PortSockets, PortNumbers, PortCount or SelectedSocket; BroadcastAddresses
		// directly follows the base at +0x43AFC (constructor 0x758120).

		/*
		**	Address to use when broadcasting a packet.
		*/
		DynamicVectorClass <unsigned char *> BroadcastAddresses; // +0x43AFC
		// level-2 1.001: no BroadcastPorts

		/*
		**	List of local addresses.
		*/
		DynamicVectorClass <unsigned char *> LocalAddresses; // +0x43B14

		// level-2 1.001: no PeerCount, PeerAddresses or PeerPorts (the class ends at +0x43B2C)
};

/*
**	RA2: the ports of the alternate socket and the loopback port of the host in an
**	internet game, and whether a malformed packet was reported yet.
*/
extern int AlternateSendPort; // level-2 1.001: 0x7df96c (1235)
extern int AlternateListenPort; // level-2 1.001: 0x7df970 (1236)
extern int LoopbackPort; // level-2 1.001: 0x7df974 (1237)
extern bool IsMalformedPacketReported;
