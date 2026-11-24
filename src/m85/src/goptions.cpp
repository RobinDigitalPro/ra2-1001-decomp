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

/* $Header: /counterstrike/GOPTIONS.CPP 6     3/15/97 7:18p Steve_tall $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : OPTIONS.CPP                                                  *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : June 8, 1994                                                 *
 *                                                                                             *
 *                  Last Update : July 27, 1995 [JLB]                                          *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   OptionsClass::Process -- Handles all the options graphic interface.                       *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "goptions.h"

#include "_keyboar.h"
#include "_map.h"
#include "data.h"
#include "dbgprint.h"
#include "gamedlg.h"
#include "language\language.h"
#include "loaddlg.h"
#include "ownrdraw.h"
#include "queue.h"
#include "restate.h"
#include "scenario.h"
#include "wonline.h"

#include "special.hh"

#include "house.h" // RA2: the live human count
#include "stringtable.h" // RA2: button captions


#define RA2_SOURCE "C:\\RA2\\GOptions.CPP" // RA2: the source name LoadString records

/*
**	RA2's game options dialog controls (resource IDs; names chosen here).
*/
#define IDC_GOPTIONS_LEAVE		1737	// RA2: Leave / Observe
#define IDC_GOPTIONS_RESTART	1810	// RA2: Restart / Observe
#define IDC_GOPTIONS_RESUME		1670	// RA2: Resume

static int LeaveResult; // RA2: what the Leave button returns (0xA40E1C)
static int RestartResult; // RA2: what the Restart button returns (0xA40E20)


BOOL CALLBACK Abort_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: defined after the dialog
BOOL CALLBACK Game_Options_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // level-2 1.001: 0x4DCF50, defined after the dialog
void Init_Game_Options_Controls(HWND window); // level-2 1.001: 0x4DD4A0, defined after the dialog procedure

#define IDD_GAME_OPTIONS			181		// level-2 1.001: the options menu of a single player or skirmish game
#define IDD_GAME_OPTIONS_INTERNET	255		// level-2 1.001: the options menu of an internet game
#define IDD_GAME_OPTIONS_NETWORK	3002	// level-2 1.001: the options menu of the other multiplayer games
#define IDC_GOPTIONS_BRIEFING		1004	// level-2 1.001: the dialog result that restates the mission briefing
#define IDC_GOPTIONS_CONNECTION	1007	// level-2 1.001: the connection quality slider (internet games)
#define IDC_GOPTIONS_LOAD		1310	// level-2 1.001: Load
#define IDC_GOPTIONS_DELETE		1312	// level-2 1.001: Delete
#define IDC_GOPTIONS_SPEED		1321	// level-2 1.001: the game speed slider (internet games)
#define IDC_GOPTIONS_SAVE		1311	// level-2 1.001: Save
#define IDC_GOPTIONS_CONTROLS	1313	// level-2 1.001: game controls (SDLG_SETTINGS)
#define IDC_GOPTIONS_ABORT		1314	// level-2 1.001: abort (or surrender) the mission
#define IDC_GOPTIONS_RESUME2	1653	// level-2 1.001: the second resume button
#define IDC_GOPTIONS_SPEED_LABEL		1649	// level-2 1.001: the game speed text next to its slider
#define IDC_GOPTIONS_CONNECTION_LABEL	1650	// level-2 1.001: the connection quality text next to its slider

extern char const * GameSpeedNames[]; // level-2 1.001: 0x7C34B0 (GameDlg.CPP), the text IDs of the seven game speeds
static char const * ConnectionNames[] = { // level-2 1.001: 0x7C4C54, the text IDs of the four connection qualities
	"TXT_WORST_CONNECTION",
	"TXT_POOR_CONNECTION",
	"TXT_GOOD_CONNECTION",
	"TXT_BEST_CONNECTION"
};


/// <summary>
/// Displays the in game options menu.
/// Which dialog appears depends on the kind of game in progress. When the player asked for
/// the mission briefing it is restated on the way out, and the whole screen is redrawn.
/// </summary>
void Game_Options_Dialog(void) // level-2 1.001: 0x4DCEA0 (1.006 0x004DD7D0)
{
	int result = 0;
	HWND dialog;
	if (Session.Type == GAME_NORMAL || Session.Type == GAME_SKIRMISH) {
		dialog = OwnerDraw::Begin_Dialog(IDD_GAME_OPTIONS, Game_Options_Dialog_Proc, 0);
	} else if (Session.Type == GAME_INTERNET) {
		dialog = OwnerDraw::Begin_Dialog(IDD_GAME_OPTIONS_INTERNET, Game_Options_Dialog_Proc, 0);
	} else {
		dialog = OwnerDraw::Begin_Dialog(IDD_GAME_OPTIONS_NETWORK, Game_Options_Dialog_Proc, 0);
	}
	if (dialog) {
		SetWindowLong(dialog, DWL_USER, (LONG)&result);
		OwnerDraw::Display_Dialog(dialog);
		while (result == 0) {
			if (OwnerDraw::Dialog_Message_Handler() == true) {
				result = 1;
			}
		}
		OwnerDraw::End_Dialog(dialog);
	}
	if (result == IDC_GOPTIONS_BRIEFING) {
		Restate_Mission(Scen);
	}
	Map.Flag_To_Redraw(GS_REDRAW_ALL);
}



/// <summary>
/// The WM_COMMAND handler of the in game options menu (level-2 1.001: inlined into
/// Game_Options_Dialog_Proc; a separate function as in gibbo101 YR goptions.cpp).
/// </summary>
static BOOL Game_Options_On_COMMAND(HWND window, WPARAM wparam)
{
		int code = HIWORD(wparam);
		int * retval = (int *)GetWindowLong(window, DWL_USER);

		static CDTimerClass<SystemTimerClass> SpeedTimer;
		static CDTimerClass<SystemTimerClass> LatencyTimer;

		switch (LOWORD(wparam)) {

			case IDC_GOPTIONS_LOAD:
				if (!code) {
					ShowWindow(window, SW_HIDE);
					if (LoadOptionsClass().Load()) {
						*retval = IDC_GOPTIONS_LOAD;
					} else {
						ShowWindow(window, SW_SHOW);
						UpdateWindow(window);
					}
				}
				break;

			case IDC_GOPTIONS_BRIEFING:
				if (!code) {
					*retval = IDC_GOPTIONS_BRIEFING;
				}
				break;

			case IDC_GOPTIONS_DELETE:
				if (!code) {
					ShowWindow(window, SW_HIDE);
					LoadOptionsClass().Delete();
					Init_Game_Options_Controls(window);
					ShowWindow(window, SW_SHOW);
					UpdateWindow(window);
				}
				break;

			case IDC_GOPTIONS_SAVE:
				if (!code) {
					if (Session.Type == GAME_NORMAL || Session.Type == GAME_SKIRMISH) {
						ShowWindow(window, SW_HIDE);
						wchar_t description[512];
						swprintf(description, L"%s", Scen->Description);
						LoadOptionsClass().Save(description);
						Init_Game_Options_Controls(window);
						ShowWindow(window, SW_SHOW);
						UpdateWindow(window);
					} else {
						OutList.Add(EventClass(PlayerPtr->HeapID, EventClass::SAVEGAME));
						*retval = IDC_GOPTIONS_SAVE;
					}
				}
				break;

			case IDC_GOPTIONS_CONTROLS:
				if (!code) {
					SpecialDialog = SDLG_SETTINGS;
					*retval = IDOK;
				}
				break;

			case IDC_GOPTIONS_RESUME2:
			case IDC_GOPTIONS_RESUME:
				if (!code) {
					if (Session.Type == GAME_INTERNET) {
						HWND handle = GetDlgItem(window, IDC_GOPTIONS_CONNECTION);
						if (handle) {
							int fudge = 3 - SendMessage(handle, TBM_GETPOS, 0, 0);
							if (fudge != Session.LatencyFudge) {
								if (!LatencyTimer) {
									CDTimerClass<SystemTimerClass> fresh(900);
									LatencyTimer = fresh;
									OutList.Add(EventClass(PlayerPtr->HeapID, EventClass::LATENCYFUDGE, fudge));
									DebugString("LATENCYFUDGE event created - %d\n", fudge);
								} else {
									DebugString("Ignoring latency change to avoid cheating\n");
								}
							}
						}
						handle = GetDlgItem(window, IDC_GOPTIONS_SPEED);
						if (handle) {
							int speed = 6 - SendMessage(handle, TBM_GETPOS, 0, 0);
							if (Options.GameSpeed != speed) {
								if (!SpeedTimer) {
									CDTimerClass<SystemTimerClass> fresh(900);
									SpeedTimer = fresh;
									OutList.Add(EventClass(PlayerPtr->HeapID, EventClass::GAMESPEED, speed));
								} else {
									DebugString("Ignoring speed change to avoid cheating\n");
								}
							}
						}
					}
					*retval = IDOK;
				}
				break;

			case IDC_GOPTIONS_ABORT:
				if (!code) {
					if (Session.Type == GAME_INTERNET) {
						SpecialDialog = SDLG_SURRENDER;
						if (!WestwoodOnline_Tournament) {
							SpecialDialog = SDLG_ABORT;
						}
					} else {
						SpecialDialog = SDLG_ABORT;
					}
					*retval = IDCANCEL;
				}
				break;

			default:
				break;
		}
	return(FALSE);
}


/// <summary>
/// The dialog procedure of the in game options menu (level-2 1.001: 0x4DCF50; structure as in
/// gibbo101 YR goptions.cpp, whose command handler is a separate function there).
/// </summary>
BOOL CALLBACK Game_Options_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	BOOL rc = OwnerDraw::Default_Dialog_Proc(window, message, wparam, lparam);
	if (rc) {
		return(rc);
	}

	switch (message) {

		case 0x497:
			Init_Game_Options_Controls(window);
			break;

		case WM_COMMAND:
			return(Game_Options_On_COMMAND(window, wparam));

		case WM_HSCROLL:
			if (LOWORD(wparam) == SB_THUMBTRACK) {
				int pos = HIWORD(wparam);
				char const * textid;
				HWND handle;

				if ((HWND)lparam == GetDlgItem(window, IDC_GOPTIONS_SPEED)) {
					textid = GameSpeedNames[pos];
					handle = GetDlgItem(window, IDC_GOPTIONS_SPEED_LABEL);
				} else if ((HWND)lparam == GetDlgItem(window, IDC_GOPTIONS_CONNECTION)) {
					textid = ConnectionNames[pos];
					handle = GetDlgItem(window, IDC_GOPTIONS_CONNECTION_LABEL);
				} else {
					break;
				}

				if (handle) {
					SendMessage(handle, OD_SETTEXTW, 0, (LPARAM)StringTable::LoadString(textid, NULL, RA2_SOURCE, 192)); // level-2 1.001: line 192
				}
			}
			break;

		default:
			break;
	}

	return(FALSE);
}



/// <summary>
/// Prepares the game type dependent controls of the in game options menu.
/// In a single player or skirmish game the load and delete buttons are only enabled when
/// saved games exist; in an internet game the connection quality and game speed sliders are
/// set from the current settings.
/// </summary>
void Init_Game_Options_Controls(HWND window) // level-2 1.001: 0x4DD4A0 (name provisional)
{
	if (Session.Type == GAME_NORMAL || Session.Type == GAME_SKIRMISH) {
		bool files = LoadOptionsClass().Files_Present();
		HWND button = GetDlgItem(window, IDC_GOPTIONS_LOAD);
		if (button) {
			EnableWindow(button, files);
		}
		button = GetDlgItem(window, IDC_GOPTIONS_DELETE);
		if (button) {
			EnableWindow(button, files);
		}
	} else if (Session.Type == GAME_INTERNET) {
		HWND slider = GetDlgItem(window, IDC_GOPTIONS_CONNECTION);
		if (slider) {
			int quality = 3 - Session.LatencyFudge;
			SendMessage(slider, TBM_SETRANGE, TRUE, MAKELONG(0, 3));
			SendMessage(slider, TBM_SETPOS, TRUE, quality);
		}
		slider = GetDlgItem(window, IDC_GOPTIONS_SPEED);
		if (slider) {
			SendMessage(slider, TBM_SETRANGE, TRUE, MAKELONG(0, 6));
			SendMessage(slider, TBM_SETPOS, TRUE, 6 - Options.GameSpeed);
		}
	}
}


/// <summary>
/// Displays the in game options dialog.
/// This routine is used by the special dialog handler when the player calls up the options
/// screen. Which dialog appears depends on the kind of game in progress. Game input stays
/// locked out for as long as the dialog is up, and if the player asked for the mission
/// briefing it is restated on the way out.
/// </summary>
int Abort_Dialog(void) // RA2: at 0x4DDF20, returns the choice
{
	int result = 0; // RA2: Abort_Dialog at 0x4DDF20 matches only so
	HWND dialog = OwnerDraw::Begin_Dialog(IDD_MISSION_ABORT, Abort_Dialog_Proc, 0); // RA2: as above
	if (dialog) {
		SetWindowLong(dialog, DWL_USER, (LONG)&result); // RA2: as above
		OwnerDraw::Display_Dialog(dialog);
		while (result == 0) { // RA2: as above
			if (OwnerDraw::Dialog_Message_Handler() == true) {
				result = 1; // RA2: as above
			}
		}
		OwnerDraw::End_Dialog(dialog);
	}
	return(result); // RA2: as above
} // RA2: Abort_Dialog at 0x4DDF20 has no IgnoreInput, Scen, IsInputLocked and 2 more


/// <summary>
/// Handles messages for the in game options dialog.
/// This routine offers every message to the owner draw system first. What is left it uses
/// to service the option buttons -- save, load, delete, briefing, resume, abort and
/// settings -- either acting on them directly or noting the player's choice for
/// Abort_Dialog to deal with once the dialog comes down. Dragging the game speed or
/// connection quality slider updates the label beside it.
/// </summary>
/// <returns>Returns with TRUE if the owner draw system consumed the message.</returns>
BOOL CALLBACK Abort_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: at 0x4DDF90
{
	int result = OwnerDraw::Default_Dialog_Proc(window, message, wparam, lparam); // RA2: as above
	if (result) { // RA2: as above
		return(result); // RA2: as above
	}

	switch (message) {
		case WM_COMMAND: { // RA2: as above
			int * retval = (int *)GetWindowLong(window, DWL_USER); // RA2: as above
			if (HIWORD(wparam) == 0) { // RA2: as above
				switch (LOWORD(wparam)) { // RA2: as above
					case IDC_GOPTIONS_LEAVE: // RA2: as above
						*retval = LeaveResult;
						return(FALSE); // RA2: as above

					case IDOK: // RA2: as above
					case IDC_GOPTIONS_RESUME: // RA2: as above
						*retval = 1;
						return(FALSE); // RA2: as above

					case IDC_GOPTIONS_RESTART: // RA2: as above
						*retval = RestartResult;
						break;
				} // RA2: no HIWORD, GetWindowLong, LOWORD and 30 more (TibSun's use does not compile against RA2's declaration)
			}
			break;
		}

		case OD_SUBCLASSED: { // RA2: as above
			HWND leave = GetDlgItem(window, IDC_GOPTIONS_LEAVE); // RA2: as above
			SendMessage(leave, OD_SETTEXTW, 0, (LPARAM)StringTable::LoadString("GUI:Leave", NULL, RA2_SOURCE, 539)); // level-2 1.001: line 539 (1.006: 543)
			LeaveResult = 2; // RA2: as above

			HWND restart = GetDlgItem(window, IDC_GOPTIONS_RESTART); // RA2: as above
			RestartResult = 0; // RA2: as above
			if (Session.Type == GAME_NORMAL) { // RA2: as above
				SendMessage(restart, OD_SETTEXTW, 0, (LPARAM)StringTable::LoadString("GUI:Restart", NULL, RA2_SOURCE, 550)); // level-2 1.001: line 550 (1.006: 554)
				RestartResult = 5; // RA2: as above
			} else if (Session.Type == GAME_SKIRMISH) { // RA2: as above
				ShowWindow(restart, SW_HIDE); // RA2: as above
			} else if (Session.Type == GAME_IPX || Session.Type == GAME_INTERNET) { // RA2: as above
				int humans = 0; // RA2: as above
				for (int index = 0; index < Houses.Count(); index++) { // RA2: as above
					if (Houses[index]->IsHuman && !Houses[index]->IsDefeated) { // RA2: as above
						humans++; // RA2: as above
					}
				}
				if (humans >= 2 && !PlayerPtr->IsDefeated) { // RA2: as above
					LeaveResult = 3; // RA2: as above
					SendMessage(restart, OD_SETTEXTW, 0, (LPARAM)StringTable::LoadString("GUI:Observe", NULL, RA2_SOURCE, 578)); // level-2 1.001: line 578 (1.006: 582)
					RestartResult = 4; // RA2: as above
				} else {
					ShowWindow(restart, SW_HIDE); // RA2: as above
				}
			}
			OwnerDraw::Set_Control_Result(leave, LeaveResult); // RA2: as above
			OwnerDraw::Set_Control_Result(restart, RestartResult); // RA2: as above
			return(FALSE); // RA2: as above
		}
	}

	return(FALSE);
}
