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

/* $Header: /counterstrike/NULLMGR.CPP 2     3/07/97 6:40p Steve_tall $ */
/***************************************************************************
 **   C O N F I D E N T I A L --- W E S T W O O D    S T U D I O S        **
 ***************************************************************************
 *                                                                         *
 *                 Project Name : Command & Conquer                        *
 *                                                                         *
 *                    File Name : NULLMGR.CPP                              *
 *                                                                         *
 *                   Programmer : Bill Randolph                            *
 *                                                                         *
 *                   Start Date : April 5, 1995                            *
 *                                                                         *
 *                  Last Update : May 1, 1995 [BRR]                        *
 *                                                                         *
 *-------------------------------------------------------------------------*
 * Functions:                                                              *
 *   NullModemClass::NullModemClass -- class constructor                   *
 *   NullModemClass::~NullModemClass -- class destructor                   *
 *   NullModemClass::Init -- initialization                                *
 *   NullModemClass::Send_Message -- sends a message                       *
 *   NullModemClass::Get_Message -- polls the Queue for a message          *
 *   NullModemClass::Service -- main polling routine                       *
 *   NullModemClass::Num_Send -- Returns # of unACK'd send entries         *
 *   NullModemClass::Num_Receive -- Returns # entries in the receive queue *
 *   NullModemClass::Response_Time -- Returns Queue's avg response time    *
 *   NullModemClass::Reset_Response_Time -- Resets response time computatio*
 *   NullModemClass::Oldest_Send -- Returns ptr to oldest unACK'd send buf *
 *   NullModemClass::Detect_Modem -- Detects and initializes the modem     *
 *   NullModemClass::Dial_Modem -- dials a number passed                   *
 *   NullModemClass::Answer_Modem -- waits for call and answers            *
 *   NullModemClass::Hangup_Modem -- hangs up the modem                    *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "nullmgr.h"

#include "_keyboar.h"
#include "conquer.h"
#include "data.h"
#include "dbgprint.h"
#include "init.h"
#include "language\language.h"
#include "misc.h"
#include "modemreg.h"
#include "msgbox.h"
#include "msgloop.h"
#include "ownrdraw.h"
#include "session.h"
#include "wincomm.h"
#include "stringtable.h"

/*
**	RA2: the original path of this file, passed with each string table lookup (see stringtable.h).
*/
#define RA2_SOURCE "C:\\RA2\\NullMgr.CPP"


// the following line was taken from Greenleaf's <ibmkeys.h> <asciidef.h>
// because of other define conflicts

#define ESC		         27
#define NOKEY           0xffff
#define INIT_COMMAND_RETRIES	2

// this time is in milliseconds

#define DEFAULT_TIMEOUT		90
#define DETECT_DEFAULT_TIMEOUT		180

/*
**	Ugly hack: this string stores the string received from the modem
*/
char ModemRXString[80];

bool ModemDialogIsOpen;

char _send_resp[NullModemClass::MODEM_CMD_0+1][20] = {
	"MODEM_CMD_TIMEOUT",
	"MODEM_CMD_ERROR",
	"MODEM_CMD_OK",
	"MODEM_CMD_0",
};

/***************************************************************************
 * NullModemClass::NullModemClass -- class constructor                     *
 *                                                                         *
 * INPUT:                                                                  *
 *      numsend         # desired entries for the send queue               *
 *      numreceive      # desired entries for the receive queue            *
 *      maxlen         application's max packet length                     *
 *      magicnum         application-specific magic # (so we don't         *
 *                     accidentally end up talking to another one of our own*
 *                     products using the same protocol)                   *
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
NullModemClass::NullModemClass (int numsend, int numreceive, int maxlen,
	unsigned short magicnum) :
	BASECLASS(),
	NumSend(numsend),
	NumReceive(numreceive),
	MaxLen(maxlen),
	MagicNum(magicnum),
	ModemGuardTime(60),
	RetryDelta(60)
{
	/*------------------------------------------------------------------------
	Init Port to NULL; we haven't opened Greenleaf yet.
	------------------------------------------------------------------------*/
	PortHandle = INVALID_HANDLE_VALUE;

	Connection = NULL;

	NumSend = numsend;
	NumReceive = numreceive;
	MaxLen = maxlen;
	MagicNum = magicnum;

	RXBuf = 0;
	BuildBuf = 0;

	EchoSize = 500;
	EchoBuf = 0;

	OldIRQPri = -1;

	ModemVerboseOn = false;     // default true
	ModemEchoOn = false;        // default true
	ModemWaitCarrier = 3000;    // default 50 * 1000ms = 50 secs
//	ModemCarrierDetect = 600;				// default 6  * 100ms  = .6 secs
//	ModemCarrierLoss = 1400;				// default 14 * 100ms  = 1.4 secs
	ModemHangupDelay = 1200;				// default 20 * 1000ms = 20 secs
	ModemGuardTime = 60;					// default 50 * 20ms   = 1 sec
	ModemEscapeCode = '+';					// default ASCII 43

	SendOverflows = 0;
	ReceiveOverflows = 0;
	CRCErrors = 0;

	NumConnections = 0;

	/*------------------------------------------------------------------------
	Init timing parameters
	------------------------------------------------------------------------*/
	RetryDelta = TIMER_SECOND;       // 60 ticks between retries
	MaxRetries = -1;                 // disregard # retries
	Timeout = 20 * TIMER_SECOND;     // report bad connection after 20 seconds

	ModemRegistry = NULL;

}	/* end of NullModemClass */


/***************************************************************************
 * NullModemClass::~NullModemClass -- class destructor                     *
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
	/* end of ~NullModemClass */


/***************************************************************************
 * NullModemClass::Init -- initialization                                  *
 *                                                                         *
 * INPUT:                                                                  *
 *      port            address                                            *
 *      irq            2-15                                                *
 *     dev_name         name of communications device (win32 only)         *
 *      baud            300, 1200, 9600, etc                               *
 *      parity         'O' (odd), 'E' (even), 'N' (none), 'S' (space),     *
 *                     'M' (mark)                                          *
 *      wordlength      5, 6, 7, or 8                                      *
 *      stopbits         1 or 2                                            *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK, 0 = error                                                  *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *   10/9/1996  ST : Modified to take device name in win32                 *
 *=========================================================================*/



/***********************************************************************************************
 * NMC::Num_Connections -- returns NumConnections member                                       *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   NumConnections                                                                    *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 11:44AM ST : Documented / Win32 support                                           *
 *=============================================================================================*/



/***********************************************************************************************
 * NMC::Delete_Connection -- removes the connection                                            *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   true                                                                              *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 11:44AM ST : Documented / Win32 support                                           *
 *=============================================================================================*/
	/* end of Delete_Connection */



/***********************************************************************************************
 * NMC::Init_Send_Queue -- Initialises the connections send queue                              *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   true                                                                              *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 11:46AM ST : Documented / Win32 support                                           *
 *=============================================================================================*/



/***********************************************************************************************
 * NMC::Detect_Port -- Checks that the specified com port exists                               *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    ptr to SerialSettingsType                                                         *
 *                                                                                             *
 * OUTPUT:   true if port is valid                                                             *
 *                                                                                             *
 * WARNINGS: Win32 version always returns true as win95 shouldnt allow us to open the          *
 *           port if it doesnt exist or is in use by the mouse                                 *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 11:47AM ST : Documented / Win32 support                                           *
 *=============================================================================================*/
DetectPortType NullModemClass::Detect_Port( SerialSettingsType *settings )
{
	static char com_ids[9][5]={
		"COM1",
		"COM2",
		"COM3",
		"COM4",
		"COM5",
		"COM6",
		"COM7",
		"COM8",
		"COM9"
	};

	int	i;

	/*
	**	Create a new modem class for our com port
	*/
	if (!SerialPort) {
		SerialPort = new WinModemClass;
	}else{
		SerialPort->Serial_Port_Close();
	}

	/*
	**	Shift up the baud rate to sensible values
	*/
	int baud = settings->Baud;
//	if (baud == 14400) baud = 19200;
//	if (baud == 28800) baud = 38400;


	/*
	**	Translate the port address into a usable device name
	*/
	char *device;

	switch ( settings->Port ) {

		case 0x3f8:
			device = com_ids[0];
			break;

		case 0x2f8:
			device = com_ids[1];
			break;

		case 0x3e8:
			device = com_ids[2];
			break;

		case 0x2e8:
			device = com_ids[3];
			break;

		case 1:
			/*
			**	1 is a special value. It means use the device name not the port address.
			*/
			device = settings->ModemName;

			/*
			**	If we can match a registry entry with the device name then use that, otherwise use
			**	the device name directly to open the port with.
			*/
			if (ModemRegistry){
				delete ModemRegistry;
				ModemRegistry = NULL;
			}
			for ( i=0 ; i<10 ; i++){
				ModemRegistry = new ModemRegistryEntryClass (i);
				if (ModemRegistry->Get_Modem_Name()){
					if (!strcmp (device, ModemRegistry->Get_Modem_Name() )){
						/*
						**	Got a match. Break out leaving the registry info intact.
						*/
						device = ModemRegistry->Get_Modem_Device_Name();
						break;
					}
				}
				delete ModemRegistry;
				ModemRegistry = NULL;
			}
			break;

		default:
			return(PORT_INVALID);
	}

	/*
	**	Open the com port
	*/
	HANDLE porthandle = SerialPort->Serial_Port_Open (device, baud, 0, 8, 1);

	if (porthandle == INVALID_HANDLE_VALUE){
		return(PORT_INVALID);
	}

	SerialPort->Serial_Port_Close();
	return(PORT_VALID);
}


/***********************************************************************************************
 * NullModemClass::ShutDown -- Closes serial port and removes the connection                   *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 11:43AM ST : Documented / Win32 support                                           *
 *=============================================================================================*/
	/* end of Shutdown */


/***************************************************************************
 * NullModemClass::Set_Timing -- sets timing for all connections           *
 *                                                                         *
 * This will set the timing parameters.  This allows an application to     *
 * measure the Response_Time while running, and adjust timing accordingly. *
 *                                                                         *
 * INPUT:                                                                  *
 *      retrydelta   value to set for retry delta                          *
 *      maxretries   value to set for max # retries                        *
 *      timeout      value to set for connection timeout                   *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      none.                                                              *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   08/07/1995 DRD : Created.                                             *
 *=========================================================================*/
void NullModemClass::Set_Timing (unsigned int retrydelta,
	unsigned int maxretries, unsigned int timeout, bool)
{
	RetryDelta = retrydelta;
	MaxRetries = maxretries;
	Timeout = timeout;

	Connection->Set_Retry_Delta (RetryDelta);
	Connection->Set_Max_Retries (MaxRetries);
	Connection->Set_TimeOut (Timeout);

}	/* end of Set_Timing */


/***************************************************************************
 * NullModemClass::Send_Message -- sends a message                         *
 *                                                                         *
 * For clarity's sake, here's what happens to the buffer passed in:        *
 * - It gets passed to the Connection's Send_Packet() routine              *
 * - The CommHeaderType header gets tacked onto it                         *
 * - The resulting buffer gets added to the Connection's Send Queue        *
 * - When Service() determines that it needs to send the data, it          *
 *   copies the entire packet (CommHeaderType and all) into its local      *
 *   SendBuf, adds the packet start ID, length, and CRC, then sends it out.*
 *                                                                         *
 * The ack_req argument will almost always be '1' (the default).  The only *
 * reason to use 0 is if you don't know whether the other system is        *
 * ready or not, so you have to periodically send out a query packet,      *
 * and wait for a response.  (Using the connection's built-in retry        *
 * system would just blast out useless data if the other system isn't      *
 * even there.)                                                            *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         buffer to send                                         *
 *      buflen      length of buffer                                       *
 *      ack_req      1 = ACK is required; 0 = not                          *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK; 0 = error                                                  *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/
	/* end of Send_Message */


/***************************************************************************
 * NullModemClass::Get_Message -- polls the Queue for a message            *
 *                                                                         *
 * INPUT:                                                                  *
 *      buf         buffer to store message in                             *
 *      buflen      ptr filled in with length of message                   *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = message was received; 0 = wasn't                               *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *=========================================================================*/



/***************************************************************************
 * NullModemClass::Service -- main polling routine                         *
 *                                                                         *
 * INPUT:                                                                  *
 *      none.                                                              *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      1 = OK, 0 = connection has gone bad                                *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   12/20/1994 BR : Created.                                              *
 *   8/2/96     ST : Win32 support                                         *
 *=========================================================================*/
	/* end of Service */


/***************************************************************************
 * NullModemClass::Num_Send -- Returns # of unACK'd send entries           *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/01/1995 BRR : Created.                                             *
 *=========================================================================*/
	/* end of Num_Send */


/***************************************************************************
 * NullModemClass::Num_Receive -- Returns # entries in the receive queue   *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/01/1995 BRR : Created.                                             *
 *=========================================================================*/
	/* end of Num_Receive */


/***************************************************************************
 * NullModemClass::Response_Time -- Returns Queue's avg response time      *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/01/1995 BRR : Created.                                             *
 *=========================================================================*/
unsigned int NullModemClass::Response_Time(void)
{
	if (Connection)
		return( Connection->Queue->Avg_Response_Time() );
	else
		return(0);

}	/* end of Response_Time */


/***************************************************************************
 * NullModemClass::Reset_Response_Time -- Resets response time computation *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/01/1995 BRR : Created.                                             *
 *=========================================================================*/
void NullModemClass::Reset_Response_Time(bool zero)
{
	if (Connection)
		Connection->Queue->Reset_Response_Time(true);

}	/* end of Reset_Response_Time */


/***************************************************************************
 * Oldest_Send -- Returns ptr to oldest unACK'd send buffer                *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/01/1995 BRR : Created.                                             *
 *=========================================================================*/
	/* end of Oldest_Send */


/***************************************************************************
 * NullModemClass::Configure_Debug -- sets up special debug values         *
 *                                                                         *
 * Mono_Debug_Print2() can look into a packet to pull out a particular     *
 * ID, and can print both that ID and a string corresponding to            *
 * that ID.  This routine configures these values so it can find           *
 * and decode the ID.  This ID is used in addition to the normal           *
 * CommHeaderType values.                                                  *
 *                                                                         *
 * INPUT:                                                                  *
 *      index         (not used)                                           *
 *      type_offset      ID's byte offset into packet                      *
 *      type_size      size of ID, in bytes; 0 if none                     *
 *      names            ptr to array of names; use ID as an index into this*
 *      namestart      numerical start of the 1st name value               *
 *      namecount      # in the names array; 0 if none.                    *
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


#ifdef _DEBUG
/***************************************************************************
 * Mono_Debug_Print -- Debug output routine                                *
 *                                                                         *
 * INPUT:                                                                  *
 *      index         (not used)                                           *
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
void NullModemClass::Mono_Debug_Print(int,int refresh)
{

#if 0
	if (!Connection)
		return;

	Connection->Queue->Mono_Debug_Print (refresh);

	if (refresh) {
		Mono_Set_Cursor (31,1);
		Mono_Printf ("Serial Port Queues");

		Mono_Set_Cursor (9,2);
		Mono_Printf ("Average Response Time:");

		Mono_Set_Cursor (20,3);
		Mono_Printf ("CRC Errors:");

		Mono_Set_Cursor (43,2);
		Mono_Printf ("Send Overflows:");

		Mono_Set_Cursor (40,3);
		Mono_Printf ("Receive Overflows:");
	}

	Mono_Set_Cursor (32,2);
	Mono_Printf ("%d  ", Connection->Queue->Avg_Response_Time());

	Mono_Set_Cursor (32,3);
	Mono_Printf ("%d  ", CRCErrors);

	Mono_Set_Cursor (59,2);
	Mono_Printf ("%d  ", SendOverflows);

	Mono_Set_Cursor (59,3);
	Mono_Printf ("%d  ", ReceiveOverflows);

	Mono_Set_Cursor (2,5);
	Mono_Printf ("%d  ", Num_Send());

	Mono_Set_Cursor (41,5);
	Mono_Printf ("%d  ", Num_Receive());
#endif

}	/* end of Mono_Debug_Print */
#endif


/***************************************************************************
 * NullModemClass::Detect_Modem -- Detects and initializes the modem       *
 *                                                                         *
 * INPUT:                                                                  *
 *      settings      ptr to SerialSettings structure                      *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      -1            init string invalid                                  *
 *      0            no modem found                                        *
 *      1            modem found                                           *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/02/1995 DRD : Created.                                             *
 *   8/2/96      ST : Added Win32 support                                  *
 *=========================================================================*/
bool NullModemClass::Detect_Modem( SerialSettingsType *settings, bool reconnect )
{
	/*------------------------------------------------------------------------
	Button Enumerations
	------------------------------------------------------------------------*/
	int status;
	int error_count = 0;

	char buffer[80*3];

	DebugString("Detecting modem\n");

	if (SerialPort->Enter_Failsafe_Mode()) {

		/*------------------------------------------------------------------------
		Determine the dimensions of the text to be used for the dialog box.
		These dimensions will control how the dialog box looks.
		------------------------------------------------------------------------*/
		HWND dialog = OwnerDraw::Custom_Message_Box( StringTable::LoadString("TXT_INITIALIZING_MODEM", NULL, RA2_SOURCE, 1134) );

		if (dialog != NULL) {

			/*------------------------------------------------------------------------
			Draw the dialog
			------------------------------------------------------------------------*/
			OwnerDraw::Display_Dialog(dialog);


			/*
			**	OK, lets not mess about any more. Just turn on echo, verbose, and result codes
			**	before we even begin. At least this way when we get an error later on we have already
			**	removed all the steps we use to try and recover.
			**	The timeouts need to be quite small in case the modem is turned off.
			*/

			/*
			**	Turn on echo.
			*/
			DebugString("Sending echo on command\n");
			status = Send_Modem_Command ( "ATE1", '\r', buffer, 81, DETECT_DEFAULT_TIMEOUT / 2, 2);
			DebugString("Command response was %s\n", _send_resp[status]);

			/*
			**	Turn on result codes.
			*/
			DebugString("Sending result codes on command\n");
			status = Send_Modem_Command ( "ATQ0", '\r', buffer, 81, DETECT_DEFAULT_TIMEOUT / 2, 2);
			DebugString("Command response was %s\n", _send_resp[status]);

			/*
			**	Make result codes verbose.
			*/
			DebugString("Sending verbose result codes command\n");
			status = Send_Modem_Command ( "ATV1", '\r', buffer, 81, DETECT_DEFAULT_TIMEOUT / 2, 2);
			DebugString("Command response was %s\n", _send_resp[status]);

			ModemVerboseOn = true;
			ModemEchoOn = true;

			/*
			**	Try sending a plain old AT command to the modem. Now that we have theoretically
			**	turned on verbose result codes we should get an 'OK' back.
			**
			*/
			status = Send_Modem_Command( "AT", '\r', buffer, 81, DETECT_DEFAULT_TIMEOUT, 2 );

			if (status < MODEM_CMD_OK) {
				DebugString("Modem failed to respond to 'AT' command\n");
				OwnerDraw::End_Dialog(dialog);
				SerialPort->Leave_Failsafe_Mode();
				return(false);
			}

			/*
			**	Send the user supplied modem init string
			*/
			if (settings->InitStringIndex == -1) {
				status = Send_Modem_Command( "", '\r', buffer, 81, 5 * TIMER_SECOND, 1 );
			} else {
				DebugString("Sending init strings\n");

				/*
				**	Split up the init string into seperate strings if it contains one or more '|' characters.
				**	This character acts as a carriage return/pause.
				*/
				char *istr = new char [2 + strlen( Session.InitStrings [settings->InitStringIndex] )];
				char *tokenptr;
				strcpy (istr, Session.InitStrings [settings->InitStringIndex] );

				/*
				**	Tokenise the string and send it in chunks
				*/
				tokenptr = strtok ( istr, "|" );
				while ( tokenptr ) {
					DebugString("Sending %s\n", tokenptr);
					status = Send_Modem_Command( tokenptr, '\r', buffer, 81, 90, 1 );
					DebugString("Command response was %s\n", _send_resp[status]);

					/*
					**	Handle error case.
					*/
					if (status < MODEM_CMD_OK) {
						if (WWMessageBox().Process(StringTable::LoadString("TXT_ERROR_NO_INIT", NULL, RA2_SOURCE, 1215), StringTable::LoadString("TXT_IGNORE", NULL, RA2_SOURCE, 1215), StringTable::LoadString("TXT_CANCEL", NULL, RA2_SOURCE, 1215), NULL)) {
							delete istr;
							OwnerDraw::End_Dialog(dialog);
							SerialPort->Leave_Failsafe_Mode();
							return( false );
						}
						error_count++;
						break;
					}

					tokenptr = strtok ( NULL, "|");

				}
				delete [] istr;
			}

			if (settings->Port == 1 && ModemRegistry) {
				/*
				**	Send the init strings from the registry if available
				*/
				char send_string[256] = {"AT"};

				/*
				**	Send the init string for hardware flow control
				*/
				if (ModemRegistry->Get_Modem_Hardware_Flow_Control()) {
					DebugString("Sending flow control init\n");
					strcpy (&send_string[2], ModemRegistry->Get_Modem_Hardware_Flow_Control());
					status = Send_Modem_Command (send_string, '\r', buffer, 81, TIMER_SECOND, 1);
					DebugString("Command response was %s\n", _send_resp[status]);

					if (status != MODEM_CMD_OK && status != MODEM_CMD_0) {
						if (WWMessageBox().Process(StringTable::LoadString("TXT_NO_FLOW_CONTROL_RESPONSE", NULL, RA2_SOURCE, 1247), StringTable::LoadString("TXT_IGNORE", NULL, RA2_SOURCE, 1247), StringTable::LoadString("TXT_CANCEL", NULL, RA2_SOURCE, 1247), NULL)) {
							OwnerDraw::End_Dialog(dialog);
							SerialPort->Leave_Failsafe_Mode();
							return( false );
						}
					}
				}


				/*
				**	Send the string for data compresseion
				*/
				if (settings->Compression){

					if (ModemRegistry->Get_Modem_Compression_Enable()) {
						DebugString("Sending data compression enable init\n");
						strcpy (&send_string[2], ModemRegistry->Get_Modem_Compression_Enable());
						Send_Modem_Command (send_string, '\r', buffer, 81, TIMER_SECOND, 1);
						DebugString("Command response was %s\n", _send_resp[status]);

						if (status != MODEM_CMD_OK && status != MODEM_CMD_0) {
							if (WWMessageBox().Process(StringTable::LoadString("TXT_NO_COMP_ENABLE_RESPONSE", NULL, RA2_SOURCE, 1266), StringTable::LoadString("TXT_IGNORE", NULL, RA2_SOURCE, 1266), StringTable::LoadString("TXT_CANCEL", NULL, RA2_SOURCE, 1266), NULL)) {
								OwnerDraw::End_Dialog(dialog);
								SerialPort->Leave_Failsafe_Mode();
								return( false );
							}
						}
					}
				}else{

					if (ModemRegistry->Get_Modem_Compression_Disable()) {
						DebugString("Sending data compression disable init\n");
						strcpy (&send_string[2], ModemRegistry->Get_Modem_Compression_Disable());
						Send_Modem_Command (send_string, '\r', buffer, 81, TIMER_SECOND, 1);
						DebugString("Command response was %s\n", _send_resp[status]);

						if (status != MODEM_CMD_OK && status != MODEM_CMD_0) {
							if (WWMessageBox().Process(StringTable::LoadString("TXT_NO_COMP_DISABLE_RESPONSE", NULL, RA2_SOURCE, 1281), StringTable::LoadString("TXT_IGNORE", NULL, RA2_SOURCE, 1281), StringTable::LoadString("TXT_CANCEL", NULL, RA2_SOURCE, 1281), NULL)) {
								OwnerDraw::End_Dialog(dialog);
								SerialPort->Leave_Failsafe_Mode();
								return( false );
							}
						}
					}
				}


				/*
				**	Send the string for error correction
				*/
				if (settings->ErrorCorrection){

					if (ModemRegistry->Get_Modem_Error_Correction_Enable()) {
						DebugString("Sending error correction enable init\n");
						strcpy (&send_string[2], ModemRegistry->Get_Modem_Error_Correction_Enable());
						Send_Modem_Command (send_string, '\r', buffer, 81, TIMER_SECOND, 1);
						DebugString("Command response was %s\n", _send_resp[status]);

						if (status != MODEM_CMD_OK && status != MODEM_CMD_0) {
							if (WWMessageBox().Process(StringTable::LoadString("TXT_NO_EC_ENABLE_RESPONSE", NULL, RA2_SOURCE, 1301), StringTable::LoadString("TXT_IGNORE", NULL, RA2_SOURCE, 1301), StringTable::LoadString("TXT_CANCEL", NULL, RA2_SOURCE, 1301), NULL)) {
								OwnerDraw::End_Dialog(dialog);
								SerialPort->Leave_Failsafe_Mode();
								return( false );
							}
						}
					}
				}else{
					if (ModemRegistry->Get_Modem_Error_Correction_Disable()) {
						DebugString("Sending error correction disable init\n");
						strcpy (&send_string[2], ModemRegistry->Get_Modem_Error_Correction_Disable());
						Send_Modem_Command (send_string, '\r', buffer, 81, TIMER_SECOND, 1);
						DebugString("Command response was %s\n", _send_resp[status]);

						if (status != MODEM_CMD_OK && status != MODEM_CMD_0) {
							if (WWMessageBox().Process(StringTable::LoadString("TXT_NO_EC_DISABLE_RESPONSE", NULL, RA2_SOURCE, 1316), StringTable::LoadString("TXT_IGNORE", NULL, RA2_SOURCE, 1316), StringTable::LoadString("TXT_CANCEL", NULL, RA2_SOURCE, 1316), NULL)) {
								OwnerDraw::End_Dialog(dialog);
								SerialPort->Leave_Failsafe_Mode();
								return( false );
							}
						}
					}
				}
			}

			/*
			**	We require that auto-answer be disabled so turn it off now.
			*/
			DebugString("Sending disable auto-answer\n");
			status = Send_Modem_Command( "ATS0=0", '\r', buffer, 81, DETECT_DEFAULT_TIMEOUT / 2, 2 );
			DebugString("Command response was %s\n", _send_resp[status]);

			if (status != MODEM_CMD_OK) {
				if (WWMessageBox().Process(StringTable::LoadString("TXT_ERROR_NO_DISABLE", NULL, RA2_SOURCE, 1334), StringTable::LoadString("TXT_IGNORE", NULL, RA2_SOURCE, 1334), StringTable::LoadString("TXT_CANCEL", NULL, RA2_SOURCE, 1334), NULL)) {
					OwnerDraw::End_Dialog(dialog);
					SerialPort->Leave_Failsafe_Mode();
					return( false );
				}
				error_count++;
			}

			/*
			**	If we had an unreasonable number of ignored errors then return failure
			*/
			if (error_count >= 3) {
				WWMessageBox().Process(StringTable::LoadString("TXT_ERROR_TOO_MANY", NULL, RA2_SOURCE, 1347), StringTable::LoadString("TXT_OK", NULL, RA2_SOURCE, 1347), NULL, NULL);
				OwnerDraw::End_Dialog(dialog);
				SerialPort->Leave_Failsafe_Mode();
				return(false);
			}

			OwnerDraw::End_Dialog(dialog);
			DebugString("Modem detected OK\n");
			SerialPort->Leave_Failsafe_Mode();

			status = Send_Modem_Command("AT", '\r', buffer, 81, DETECT_DEFAULT_TIMEOUT / 2, 2);
			if (status < 2) {
				DebugString("Modem failed to respond to 'AT' command\n");
				return(false);
			}

			return( true );
		} else {
			SerialPort->Leave_Failsafe_Mode();
		}
	}
	return( false );
}


/***************************************************************************
 * NullModemClass::Dial_Modem -- dials a number passed                     *
 *                                                                         *
 * INPUT:                                                                  *
 *      settings      ptr to SerialSettings structure                      *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      status      DialStatus                                             *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/02/1995 DRD : Created.                                             *
 *   8/2/96      ST : Win32 support                                        *
 *=========================================================================*/
DialStatusType NullModemClass::Dial_Modem( char *string, DialMethodType method, bool reconnect )
{
	/*------------------------------------------------------------------------
	Dialog variables
	------------------------------------------------------------------------*/
	bool process = true;						// process while true
	int delay;
	DialStatusType dialstatus = DIAL_ERROR;
	wchar_t const * text_buffer;
	char buffer[80*3];

	DebugString("Dial_Modem\n");

	/*------------------------------------------------------------------------
	Determine the dimensions of the text to be used for the dialog box.
	These dimensions will control how the dialog box looks.
	------------------------------------------------------------------------*/
	if (reconnect == true) {
		text_buffer = StringTable::LoadString("TXT_MODEM_CONNERR_REDIALING", NULL, RA2_SOURCE, 1409);
	} else {
		text_buffer = StringTable::LoadString("TXT_DIALING", NULL, RA2_SOURCE, 1411);
	}
	ModemDialogIsOpen = false;
	HWND dialog = OwnerDraw::Custom_Message_Box(text_buffer, StringTable::LoadString("TXT_CANCEL", NULL, RA2_SOURCE, 1415), &ModemDialogIsOpen);

	if (dialog) {
		OwnerDraw::Display_Dialog(dialog);

		/*
		**	Start waiting for connection response
		*/
		DebugString("Setting modem dial type\n");
		SerialPort->Set_Modem_Dial_Type((WinCommDialMethodType) method);

		/*
		**	Clear out any old modem results that might be hanging around
		*/
		DebugString("Clearing results buffer\n");
		SerialPort->Get_Modem_Result(TIMER_SECOND, buffer, 81, -1);

		/*
		**	Dial that sucker
		*/
		DebugString("Calling dial function\n");
		SerialPort->Dial_Modem(string);

		/*
		**	Sets up the ability to abort modem commands when any input is in the
		**	Keyboard buffer.  This also calls the game CallBack().
		*/
		SerialPort->Set_Abort_Function((int(*)(void))Abort_Modem);
		ModemDialogIsOpen = false;

		/*------------------------------------------------------------------------
		Main Processing Loop
		------------------------------------------------------------------------*/
		delay = ModemWaitCarrier;
		DebugString("Waiting for dial result\n");
		while (process == true) {

			if (OwnerDraw::Dialog_Message_Handler() != 1 && !ModemDialogIsOpen) {
				Title_Screen_Restore();
				memset(buffer, 0, sizeof(buffer));
				delay = SerialPort->Get_Modem_Result(delay, buffer, 81, TIMER_SECOND / 4);

				if (delay == -1000) {
					dialstatus = DIAL_CANCELED;
					if (SerialPort != NULL) {
						char escape[3] = "\r";
						SerialPort->Write_To_Serial_Port((unsigned char*)escape, sizeof(escape)-1);
					}
					DebugString("Dialling cancelled\n");
					process = false;
					break;
				}

				strupr(buffer);
				if (strlen(buffer)) {
					DebugString("From Modem: %s\n", buffer);
				}

				if ( strstr( buffer, "CON" ) != 0 ) {
					memset (ModemRXString, 0, 80);
					strncpy (ModemRXString, buffer, 79);
					dialstatus = DIAL_CONNECTED;
					DebugString("Dial result is %s\n", buffer);
					process = false;
				} else if ( strncmp( buffer, "BUSY", 4 ) == 0 ) {
					dialstatus = DIAL_BUSY;
					DebugString("Dial result is %s\n", buffer);
					process = false;
				} else if ( strncmp( buffer, "NO C", 4 ) == 0 ) {
					dialstatus = DIAL_NO_CARRIER;
					DebugString("Dial result is %s\n", buffer);
					process = false;
				} else if ( strncmp( buffer, "NO D", 4 ) == 0 ) {
					dialstatus = DIAL_NO_DIAL_TONE;
					DebugString("Dial result is %s\n", buffer);
					process = false;
				} else if ( strncmp( buffer, "ERRO", 4 ) == 0 ) {
					dialstatus = DIAL_ERROR;
					DebugString("Dial result is %s\n", buffer);
					process = false;
				}

				if (delay <= 0) {
					DebugString("NullModemClass::Dial_Modem has timed out\n");
					if (strlen(buffer)) {
						DebugString("Dial result is %s\n", buffer);
					}
					if (SerialPort != NULL) {
						char escape[3] = "\r";
						SerialPort->Write_To_Serial_Port((unsigned char*)escape, sizeof(escape)-1);
					}
					dialstatus = DIAL_TIMEOUT;
					process = false;
					break;
				}
			} else {
				dialstatus = DIAL_CANCELED;
				process = false;
				if (SerialPort != NULL) {
					char escape[3] = "\r";
					SerialPort->Write_To_Serial_Port((unsigned char *)escape, sizeof(escape)-1);
				}
				DebugString("Dialling cancelled\n");
				break;
			}
		}

		SerialPort->Set_Abort_Function(NULL);
		ModemDialogIsOpen = false;

		OwnerDraw::End_Dialog(dialog);
	}

	return( dialstatus );

}	/* end of Dial_Modem */


/***************************************************************************
 * NullModemClass::Answer_Modem -- waits for call and answers              *
 *                                                                         *
 * INPUT:                                                                  *
 *      reconnect   whether this is to reconnect                           *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      status      DialStatus                                             *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/02/1995 DRD : Created.                                             *
 *   8/2/96      ST : Added Win32 support                                  *
 *=========================================================================*/
DialStatusType NullModemClass::Answer_Modem( bool reconnect )
{
	/*------------------------------------------------------------------------
	Dialog variables
	------------------------------------------------------------------------*/
	bool process;							// process while true
	int delay;
	DialStatusType dialstatus;
	bool ring = false;
	wchar_t const * text_buffer;
	char comm_buffer[80*3];

	dialstatus = DIAL_ERROR;

	/*------------------------------------------------------------------------
	Determine the dimensions of the text to be used for the dialog box.
	These dimensions will control how the dialog box looks.
	------------------------------------------------------------------------*/
	if (reconnect == true) {
		text_buffer = StringTable::LoadString("TXT_MODEM_CONNERR_WAITING", NULL, RA2_SOURCE, 1580);
	} else {
		text_buffer = StringTable::LoadString("TXT_WAITING_FOR_CALL", NULL, RA2_SOURCE, 1582);
	}

	DebugString("Waiting for ring\n");

	process = true;
	ModemDialogIsOpen = false;
	HWND dialog = OwnerDraw::Custom_Message_Box(text_buffer, StringTable::LoadString("TXT_CANCEL", NULL, RA2_SOURCE, 1589), &ModemDialogIsOpen);
	if (dialog) {

		OwnerDraw::Display_Dialog(dialog);

		/*
		**	Sets up the ability to abort modem commands when any input is in the
		**	Keyboard buffer.  This also calls the game CallBack() and Input().
		*/
		Setup_Abort_Modem();

		/*------------------------------------------------------------------------
		Main Processing Loop
		------------------------------------------------------------------------*/
		delay = TIMER_MINUTE;
		while (process == true) {
			if (OwnerDraw::Dialog_Message_Handler() == true || ModemDialogIsOpen) {
				dialstatus = DIAL_CANCELED;
				DebugString("Answering cancelled\n");
				if (SerialPort != NULL) {
					char escape[3] = "\r";
					SerialPort->Write_To_Serial_Port((unsigned char*)escape, sizeof(escape)-1);
				}
				process = false;
				break;
			}

			/*.....................................................................
			Refresh display if needed
			.....................................................................*/
			Title_Screen_Restore();

			memset(comm_buffer, 0, sizeof(comm_buffer));
			delay = SerialPort->Get_Modem_Result(delay, comm_buffer, 81, ring != NULL ? TIMER_SECOND / 4 : -1);
			DebugString("Get_Modem_Result returned %d\n", delay);

			if (delay == -1000) {
				dialstatus = DIAL_CANCELED;
				DebugString("Answering cancelled\n");
				if (SerialPort != NULL) {
					char escape[3] = "\r";
					SerialPort->Write_To_Serial_Port((unsigned char*)escape, sizeof(escape)-1);
				}
				process = false;
				break;
			}

			strupr(comm_buffer);
			if (strlen(comm_buffer)) {
				DebugString("Get_Modem_Result returned string:%s\n", comm_buffer);
			}

			if (process) {
				if ( strncmp( comm_buffer, "RING", 4 ) == 0 ) {
					DebugString("RING\n");
					OwnerDraw::Set_Custom_Message_Box_Text(dialog, StringTable::LoadString("TXT_ANSWERING", NULL, RA2_SOURCE, 1647));
					DebugString("Answering with ATA\n");
					SerialPort->Write_To_Serial_Port ((unsigned char*)"ATA\r", strlen("ATA\r"));

					ring = true;
					delay = ModemWaitCarrier;
				} else if ( strstr( comm_buffer, "CONNECT" ) != 0 ) {
					memset (ModemRXString, 0, sizeof(ModemRXString));
					strncpy (ModemRXString, comm_buffer, sizeof(ModemRXString)-1);
					dialstatus = DIAL_CONNECTED;
					DebugString("Result is %s\n", comm_buffer);
					process = false;
				} else if ( strncmp( comm_buffer, "BUSY", 4 ) == 0 ) {
					dialstatus = DIAL_BUSY;
					DebugString("Result is %s\n", comm_buffer);
					process = false;
				} else if ( strncmp( comm_buffer, "NO C", 4 ) == 0 ) {
					dialstatus = DIAL_NO_CARRIER;
					DebugString("Result is %s\n", comm_buffer);
					process = false;
				} else if ( strncmp( comm_buffer, "ERRO", 4 ) == 0 ) {
					dialstatus = DIAL_ERROR;
					DebugString("Result is %s\n", comm_buffer);
					WWMessageBox().Process(StringTable::LoadString("TXT_ERROR_ERROR", NULL, RA2_SOURCE, 1671), StringTable::LoadString("TXT_OK", NULL, RA2_SOURCE, 1671), NULL, NULL);
					process = false;
				}
			}

			if (delay <= 0) {
				if (ring) {
					if (SerialPort->Get_Modem_Status() & WinModemClass::CD_SET) {
						sprintf(ModemRXString, "%s", "Connected");
						dialstatus = DIAL_CONNECTED;
						DebugString("Connected\n");
					} else {
						DebugString("NullModemClass::Answer_Modem has timed out\n");
						if (strlen(comm_buffer)) {
							DebugString("Answer result is %s\n", comm_buffer);
						}
						WWMessageBox().Process(StringTable::LoadString("TXT_ERROR_TIMEOUT", NULL, RA2_SOURCE, 1687), StringTable::LoadString("TXT_OK", NULL, RA2_SOURCE, 1687), NULL, NULL);
						DebugString("Not connected\n");
						dialstatus = DIAL_TIMEOUT;
					}
					process = false;
				} else {
					delay = TIMER_MINUTE;
				}
			}
		}

		Remove_Abort_Modem();
		OwnerDraw::End_Dialog(dialog);
	}

	return( dialstatus );

}	/* end of Answer_Modem */


/***************************************************************************
 * NullModemClass::Hangup_Modem -- hangs up the modem                      *
 *                                                                         *
 * INPUT:                                                                  *
 *      none                                                               *
 *                                                                         *
 * OUTPUT:                                                                 *
 *      status      successful or not                                      *
 *                                                                         *
 * WARNINGS:                                                               *
 *      none.                                                              *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/02/1995 DRD : Created.                                             *
 *   8/2/96         : Added Win32 support                                  *
 *=========================================================================*/
	/* end of Hangup_Modem */


/***********************************************************************************************
 * NMC::Setup_Modem_Echo -- Sets the echo callback function pointer                            *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Ptr to callback function                                                          *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 12:48PM ST : Documented and added WIn32 support                                   *
 *=============================================================================================*/
	/* end of Setup_Modem_Echo */


/***********************************************************************************************
 * NMC::Remove_Modem_Echo -- Set the echo function callback pointer to null                    *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 12:50PM ST : Documented / Win32 support added                                     *
 *=============================================================================================*/
	/* end of Remove_Modem_Echo */



/***********************************************************************************************
 * NMC::Print_EchoBuf -- Print out the contents of the echo buffer                             *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 12:51PM ST : Documented                                                           *
 *=============================================================================================*/



/***********************************************************************************************
 * NMC::Reset_EchoBuf -- Empties the echo buffer                                               *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 12:51PM ST : Documented                                                           *
 *=============================================================================================*/



/***********************************************************************************************
 * NMC::Abort_Modem -- Checks for user input so that modem operations can be aborted           *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   ASUSERABORT if abort key pressed. ASSUCESS otherwise.                             *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 12:52PM ST : Documented                                                           *
 *=============================================================================================*/
int NullModemClass::Abort_Modem( PORT * )
{
	/*
	**	Invoke game callback
	*/
	Call_Back();

	Windows_Message_Handler();

	/*
	**	Get user input
	*/
	unsigned int key = Keyboard->Check();

	if (key != KN_NONE) {
		Keyboard->Clear();
		switch ( (int)key ) {
			case (KN_ESC):
				ModemDialogIsOpen = true;
				return(-1000);
		}
	}
	return(ModemDialogIsOpen != 0 ? -1000 : 0);

}	/* end of Abort_Modem */


/***********************************************************************************************
 * NMC::Setup_Abort_Modem -- sets the modem abort function pointer                             *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 2:59PM ST : Documented / Win32 support added                                      *
 *=============================================================================================*/
	/* end of Setup_Abort_Modem */


/***********************************************************************************************
 * NMC::Remove_Abort_Modem -- Removes the modem abort function pointer                         *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 3:01PM ST : Documented / Win32 support added                                      *
 *=============================================================================================*/
	/* end of Remove_Abort_Modem */



/***********************************************************************************************
 * NMC::Change_IRQ_Priority -- Increases the priority of the serial interrupt                  *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Interrupt request number                                                          *
 *                                                                                             *
 * OUTPUT:   COMMSUCCESS if changed                                                            *
 *                                                                                             *
 * WARNINGS: The Win32 version of this function does nothing.                                  *
 *           Priorities are controlled by windoze                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 3:03PM ST : Documented / Win32 support added                                      *
 *=============================================================================================*/
	/* end of Change_IRQ_Priority */



/***********************************************************************************************
 * NMC::Get_Modem_Status -- returns status of modem control bits                               *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Modem status                                                                      *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 3:06PM ST : Documented / Win32 support added                                      *
 *=============================================================================================*/
	/* end of Get_Modem_Status */


/***********************************************************************************************
 * NMC::Send_Modem_Command -- Sends an 'AT' command to the modem and gets the response         *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    command to send to modem. e.g. 'ATZ'                                              *
 *           terminator byte for command string                                                *
 *           buffer to put modem response into                                                 *
 *           length of above buffer                                                            *
 *           delay to wait for response                                                        *
 *           number of times to retry when modem doesnt respond                                *
 *                                                                                             *
 * OUTPUT:   input delay less the time it took the modem to respond                            *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 3:09PM ST : Documented / Win32 support added                                      *
 *=============================================================================================*/
int NullModemClass::Send_Modem_Command( char const *command, char terminator, char *buffer, int buflen, int delay, int retries )
{
	return(SerialPort->Send_Command_To_Modem(command, terminator, buffer, buflen, delay, retries, -1));
}


/***********************************************************************************************
 * NMC::Verify_And_Convert_To_Int -- converts a text string of numbers to an int               *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    ptr to buffer                                                                     *
 *                                                                                             *
 * OUTPUT:   value of text number in buffer                                                    *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    8/2/96 3:13PM ST : Documented                                                            *
 *=============================================================================================*/
	/* end of Verify_And_Convert_To_Int */

/*************************** end of nullmgr.cpp ****************************/
