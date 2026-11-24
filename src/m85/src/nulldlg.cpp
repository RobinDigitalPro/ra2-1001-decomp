// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2026 ra2-decomp contributors
// Copyright 2025 Electronic Arts Inc.; 2026 OpenTS contributors
// Derived from Electronic Arts source code; EA's GPL Section 7 terms apply (COPYING.md).

#include "always.h"
#undef LoadString
#include "nulldlg.h"
#include "_map.h"
#include "_rules.h"
#include "_timer.h"
#include "data.h"
#include "dbgprint.h"
#include "globals.h"
#include "house.h"
#include "houstype.h"
#include "init.h"
#include "modemgst.h"
#include "modemhst.h"
#include "modemreg.h"
#include "msgbox.h"
#include "nullmgr.h"
#include "ownrdraw.h"
#include "phone.h"
#include "phoneed.h"
#include "rules.h"
#include "serialed.h"
#include "stimer.h"
#include "stringtable.h"
#include "wincomm.h"
#include <ctime>

void Select_Serial_On_INITDIALOG(HWND window);
void Modem_Echo(char c);
bool Reconnect_Null_Modem(void);
bool Dial_Modem(SerialSettingsType *settings, bool reconnect);
bool Answer_Modem(SerialSettingsType *settings, bool reconnect);
static char DialString[CWAITSTRBUF_MAX + PhoneEntryClass::PHONE_MAX_NUM - 1];
SerialSettingsType *DialSettings;

BOOL CALLBACK Select_Serial_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	int *retval;
	int rc = OwnerDraw::Default_Dialog_Proc(window, message, wparam, lparam);
	if (rc == 0) {
		switch (message) {
			case WM_COMMAND:
				retval = (int *)GetWindowLong(window, DWL_USER);
				if (wparam == 2 || wparam > IDC_DISCONNECT_MESSAGES && wparam <= IDC_SERIAL_NULLMODEM) {
					*retval = wparam;
				}
				break;

			case 0x497:
				Select_Serial_On_INITDIALOG(window);
				break;
		}
		return(0);
	}
	return(rc);
}

void Select_Serial_On_INITDIALOG(HWND window)
{
	HWND handle;

	bool enabled = true;
	if (Session.SerialDefaults.Port == 0) {
		enabled = false;
	} else if (Session.SerialDefaults.IRQ == -1) {
		enabled = false;
	} else if (Session.SerialDefaults.Baud == -1 || NullModem.Detect_Port(&Session.SerialDefaults)) {
		enabled = false;
	}

	handle = GetDlgItem(window, IDC_SERIAL_DIAL);
	if (handle) {
		EnableWindow(handle, enabled);
	}

	handle = GetDlgItem(window, IDC_SERIAL_ANSWER);
	if (handle) {
		EnableWindow(handle, enabled);
	}

	handle = GetDlgItem(window, IDC_SERIAL_NULLMODEM);
	if (handle) {
		EnableWindow(handle, enabled);
	}
}

// level-2 1.001: defined in src/ra2/NullDlg.CPP (one definition per function)
bool Init_Null_Modem( SerialSettingsType *settings );

// level-2 1.001: defined in src/ra2/NullDlg.CPP (one definition per function)
void Shutdown_Modem( void );







bool Reconnect_Null_Modem(void)
{
	bool retval = false;
	bool process = true;
	ModemDialogIsOpen = false;

	unsigned int starttime;
	unsigned int lastmsgtime;
	int packetlen;
	SerialPacketType SendPacket;
	SerialPacketType ReceivePacket;

	HWND dialog = OwnerDraw::Custom_Message_Box(StringTable::LoadString("TXT_NULL_CONNERR_CHECK_CABLES", NULL, "C:\\RA2\\NullDlg.CPP", 0x1959), StringTable::LoadString("TXT_CANCEL", NULL, "C:\\RA2\\NullDlg.CPP", 0x1959), &ModemDialogIsOpen);

	if (dialog != NULL) {
		OwnerDraw::Display_Dialog(dialog);

		starttime = lastmsgtime = TickCount;
		while (process == true) {
			if (OwnerDraw::Dialog_Message_Handler() == true || ModemDialogIsOpen != false) {
				retval = false;
				break;
			}

			NullModem.Service();

			if (TickCount - starttime > PACKET_RETRANS_TIME) {
				starttime = TickCount;
				memset(&SendPacket, 0, sizeof(SerialPacketType));
				SendPacket.Command = SERIAL_CONNECT;
				SendPacket.ID = Session.PrefColor;
				NullModem.Send_Message(&SendPacket, sizeof(SendPacket), 0);
			}

			if (NullModem.Get_Message(&ReceivePacket, &packetlen) > 0) {
				lastmsgtime = TickCount;

				if (ReceivePacket.Command == SERIAL_CONNECT) {
					if (ReceivePacket.ID == Session.PrefColor) {
						WWMessageBox().Process(StringTable::LoadString("TXT_SYSTEM_NOT_RESPONDING", NULL, "C:\\RA2\\NullDlg.CPP", 0x1982), StringTable::LoadString("TXT_OK", NULL, "C:\\RA2\\NullDlg.CPP", 0x1982), NULL, NULL);
						retval = false;
						process = false;
						break;
					}

					memset(&SendPacket, 0, sizeof(SerialPacketType));
					SendPacket.Command = SERIAL_CONNECT;
					SendPacket.ID = Session.PrefColor;
					NullModem.Send_Message(&SendPacket, sizeof(SendPacket), 1);
					starttime = TickCount;
					while (TickCount - starttime < TIMER_SECOND) {
						NullModem.Service();
					}
					retval = true;
					process = false;
				}
			}

			if (TickCount - lastmsgtime > PACKET_CANCEL_TIMEOUT) {
				retval = false;
				process = false;
			}
		}

		OwnerDraw::End_Dialog(dialog);
	}

	return(retval);
}

// level-2 1.001: defined in src/ra2/NullDlg.CPP (one definition per function)
bool Dial_Modem(SerialSettingsType *settings, bool reconnect);

// level-2 1.001: defined in src/ra2/NullDlg.CPP (one definition per function)
bool Answer_Modem(SerialSettingsType *settings, bool reconnect);

// level-2 1.001: defined in src/ra2/NullDlg.CPP (one definition per function)
void Modem_Echo(char c);

template class TTimerClass<SystemTimerClass>;
