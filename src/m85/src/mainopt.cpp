/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "always.h"

#include "mainopt.h"

#include "_map.h"
#include "_mixfile.h"
#include "_rect.h"
#include "_surface.h"
#include "convert.h"
#include "data.h"
#include "dbgprint.h"
#include "dsaudio.h"
#include "dsurface.h"
#include "gamedlg.h"
#include "globals.h"
#include "init.h"
#include "language\language.h"
#include "misc.h"
#include "mixfile.h"
#include "msgbox.h"
#include "newmenu.h"
#include "ownrdraw.h"
#include "sidebar.h"
#include "sounddlg.h"
#include "stimer.h"
#include "surface.h"
#include "wspipx.h"
#include "wwmouse.h"
#include "_rules.h" // RA2: ConfigINI
#include "firewall.h" // RA2: FirewallHelperClass
#include "options.h" // RA2: OptionsClass
#include "session.h" // RA2: Session.SendDelay and PortNumberOverride
#include "stringtable.h" // RA2: StringTable::LoadString
#include "techno.h" // RA2: TechnoClass::Set_Action_Lines
#include "theme.h" // RA2: Theme
#include "windlg.h" // RA2: WS_Top_Window and WS_Next_Lower_Dialog

#include "color.hh"



/*
**	RA2: the original path of this file, passed with each string table lookup (see stringtable.h).
*/
#define RA2_SOURCE "C:\\RA2\\MainOpt.cpp" // RA2: the path the executable passes with each lookup

enum {
	IDC_TRY_MODE_OK = 1473, // RA2: 0x5C1, the button of the trial and confirmation dialogs that accepts
	IDC_TRY_MODE_CANCEL = 1738, // RA2: 0x6CA, the button that declines
	IDC_SHOW_HIDDEN = 1540, // RA2: 0x604, the show hidden check box
	IDC_OPTMAIN_OK = 1670, // RA2: 0x686, the button that closes the main options dialog
	IDC_OPTMAIN_RESOLUTION = 1773, // RA2: 0x6ED, the resolution combo box
	IDC_IPX_PORT = 1495, // RA2: 0x5D7, the source port edit box
	IDC_IPX_FIREWALL = 1890, // RA2: 0x762, the firewall check box
	IDC_DISPLAY_OK = 1739 // level-2 1.001: 0x6CB, the second accepting button of the display options dialog (IDC_DISPLAY_RESLIST 0x5D9 and IDC_STRETCH_MOVIES 0x674 come from language.h)
};

/*
**	RA2: owner draw dialog messages the executable sends (names guessed from their use).
*/
#define OD_SETTEXT (WM_USER + 180) // RA2: 0x4B4, sets the text of a control
#define OD_GETTEXT (WM_USER + 181) // RA2: 0x4B5, reads the text of a control
#define OD_FINDSTRING (WM_USER + 184) // RA2: 0x4B8, finds a string in a combo box
#define OD_ADDSTRING (WM_USER + 188) // RA2: 0x4BC, adds a string to a combo box
#define OD_ADDITEM (WM_USER + 194) // RA2: 0x4C2, adds an item to a combo box
#define OD_REFRESH_IPX (WM_USER + 100) // RA2: 0x464, sent to the network dialog after the card is chosen
#define OD_TABFOCUS (WM_USER + 219) // RA2: 0x4DB, moves the focus to the next tab stop
#define OD_LB_ADDSTRING (WM_USER + 200) // level-2 1.001: 0x4C8, adds a string to an owner-draw list box

struct ModeSize { // RA2: one entry of the list EnumDisplayModes returns (width, height; a zero width ends it)
	int Width; // RA2: as above
	int Height; // RA2: as above
};

extern FirewallHelperClass FirewallHelper; // RA2: 0x00A71B18 (firewall.cpp)
extern int __fastcall AudioDeviceAvailable(void); // RA2: 0x00406F30, whether the audio library opened a device
extern int SidebarWidth; // RA2: 0x007ADD80
void Relayout_Interface_Art(int width, int height); // RA2: 0x006F33B0 (txtlabel2.cpp)
void Darken_Surface(Surface * surface, bool update); // RA2: 0x005159B0 (init.cpp)
void Resize_Dialog_To_Screen(HWND dialog, Point2D * old_size); // RA2: 0x005E9F00 (ownrdraw.cpp)
extern Rect __fastcall Get_Title_Screen_Area(void); // RA2: 0x006F1F30
extern bool __fastcall Focus_Next_Tab_Item(long lparam, bool flag); // RA2: 0x005DEF80

BOOL CALLBACK Mode_Prompt_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: as above
bool Mode_Prompt_Dialog(void); // RA2: as above
void Apply_Game_Settings(HWND window); // RA2: as above
BOOL CALLBACK Main_Options_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam);
BOOL CALLBACK IPX_Options_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam);
BOOL CALLBACK Test_Display_Mode_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam);
bool Change_Display_Mode(int width, int height);
bool Test_Display_Mode_Dialog(int width, int height);

OptionsClass TempOptions; // RA2: the copy of Options taken before the options dialog opens (0x00A6EC38), a plain OptionsClass; its initializer is the jump at 0x00542150


/*
**	RA2: the labels the options sliders show (0x007DFD80, 0x007DFD8C, 0x007DFD98) and the list positions the dialogs remember.
*/
static char const * DetailLabels[3] = {"TXT_LOW", "TXT_MEDIUM", "TXT_HIGH"}; // RA2: 0x007DFD80, the detail slider labels
static char const * DifficultyLabels[3] = {"TXT_EASY", "TXT_NORMAL", "TXT_HARD"}; // RA2: 0x007DFD8C, the difficulty slider labels
static char const * ScrollLabels[7] = {"TXT_SLOWEST", "TXT_SLOWER", "TXT_SLOW", "TXT_MEDIUM", "TXT_FAST", "TXT_FASTER", "TXT_FASTEST"}; // RA2: 0x007DFD98, the scroll rate slider labels
static int InitialResolution = -1; // RA2: 0x007DFDB4, the resolution combo selection when the dialog opened
static bool OptionsReady; // RA2: 0x00A6ED0C, the controls are filled, the sliders ignore scrolling until then
static ModeSize * ResolutionModes; // RA2: 0x00A6ED10, the mode list of the resolution combo box
static int CurrentNetCard = -1; // RA2: 0x007DFDB8, the network card combo selection


/// <summary>
/// Handles the dialog that announces a display mode trial.
/// This routine shows the warning text and reports the button the player pressed.
/// </summary>
BOOL CALLBACK Mode_Prompt_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x00542160, the dialog that announces a mode trial, not in TibSun
{
	int rc = OwnerDraw::Default_Dialog_Proc(window, message, wparam, lparam);
	if (rc == 0) {
		int * result = (int *)GetWindowLong(window, DWL_USER);
		switch (message) {
			case OD_SUBCLASSED: { // RA2: as above
				wchar_t const * text = StringTable::LoadString("TXT_ABOUT_TO_TRY_MODE", NULL, RA2_SOURCE, 159); // level-2 1.001: line 159
				HWND item = GetDlgItem(window, IDC_CONFIRM_MODE_TEXT); // RA2: as above
				SendMessage(item, OD_SETTEXTW, 0, (LPARAM)text); // RA2: as above
				break;
			}

			case WM_COMMAND:
				switch (LOWORD(wparam)) {
					case IDC_TRY_MODE_OK: // RA2: as above
						*result = 1;
						break;

					case IDC_TRY_MODE_CANCEL: // RA2: as above
						*result = 2;
						break;
				}
				break;
		}
		return(0);
	}
	return(rc);
}


/// <summary>
/// Warns the player that a display mode is about to be tried.
/// </summary>
/// <returns>bool; Did the player accept?</returns>
bool Mode_Prompt_Dialog(void) // RA2: 0x00542210, not in TibSun; the executable has no caller of its own copy because Main_Options_Dialog_Proc expands it
{
	int rc = -1;

	HWND dialog = OwnerDraw::Begin_Dialog(IDD_OPT_CONFIRM_MODE, Mode_Prompt_Dialog_Proc); // RA2: as above
	if (dialog) {
		SetWindowLong(dialog, DWL_USER, (LONG)&rc);
		OwnerDraw::Display_Dialog(dialog);
		while (rc < 0 && !OwnerDraw::Dialog_Message_Handler()) Title_Screen_Restore(); // RA2: as above
		OwnerDraw::End_Dialog(dialog);
	}
	return(rc == 1); // RA2: as above
}


/// <summary>
/// Takes the settings of the main options dialog over into the game options.
/// </summary>
void Apply_Game_Settings(HWND window) // RA2: 0x00542280, not in TibSun
{
	HWND control = GetDlgItem(window, IDC_DETAIL_LEVEL_SLIDER); // RA2: as above
	if (control) { // RA2: as above
		int detail = SendMessage(control, TBM_GETPOS, 0, 0) ? 2 : 0; // RA2: as above
		if (Options.DetailLevel != detail) { // RA2: as above
			Options.DetailLevel = detail; // RA2: as above
			Map.Reinit_Cell_Drawers(); // RA2: as above
		}
	}

	control = GetDlgItem(window, IDC_DIFFICULTY_SLIDER); // RA2: as above
	if (control) { // RA2: as above
		Options.Difficulty = SendMessage(control, TBM_GETPOS, 0, 0); // RA2: as above
	}

	control = GetDlgItem(window, IDC_TARGET_LINES); // RA2: as above
	if (control) { // RA2: as above
		Options.ActionLines = SendMessage(control, BM_GETCHECK, 0, 0) == 1; // RA2: as above
		TechnoClass::Set_Action_Lines(Options.ActionLines); // RA2: as above
	}

	control = GetDlgItem(window, IDC_SHOW_HIDDEN); // RA2: as above
	if (control) { // RA2: as above
		Options.IsShowHidden = SendMessage(control, BM_GETCHECK, 0, 0) == 1; // RA2: as above
	}

	control = GetDlgItem(window, IDC_TOOLTIPS); // RA2: as above
	if (control) { // RA2: as above
		Options.ToolTips = SendMessage(control, BM_GETCHECK, 0, 0) == 1; // RA2: as above
	}

	control = GetDlgItem(window, IDC_SCROLL_SPEED_SLIDER); // RA2: as above
	if (control) { // RA2: as above
		Options.ScrollRate = 6 - SendMessage(control, TBM_GETPOS, 0, 0); // RA2: as above
	}

	control = GetDlgItem(window, IDC_MUSIC_VOLUME); // RA2: as above
	if (control) { // RA2: as above
		Options.Set_Score_Volume((float)(SendMessage(control, TBM_GETPOS, 0, 0) * 0.1), false); // RA2: as above; level-2 1.001: no theme stop at volume zero
	}

	control = GetDlgItem(window, IDC_SOUND_VOLUME); // RA2: as above
	if (control) { // RA2: as above
		Options.Set_Sound_Volume((float)(SendMessage(control, TBM_GETPOS, 0, 0) * 0.1), false); // RA2: as above
	}

	control = GetDlgItem(window, IDC_VOICE_VOLUME); // RA2: as above
	if (control) { // RA2: as above
		Options.Set_Voice_Volume((float)(SendMessage(control, TBM_GETPOS, 0, 0) * 0.1), false); // RA2: as above
	}
}


/// <summary>
/// Brings up the main options dialog.
/// This routine drives the options menu, dispatching to the sound, display, network,
/// keyboard and game settings dialogs until the player backs out. A resolution change is
/// offered as a trial first, and the settings are written out when the player leaves.
/// </summary>
/// <remarks>Game logic is suspended for the duration of this routine.</remarks>
void Main_Options_Dialog(void) // RA2: 0x00542460, the executable has the main dialog, the network settings and the keyboard dialog only; the sound, display and game settings dialogs are pages of the main dialog
{
	bool old_game_active = GameActive;
	GameActive = false;

	HWND main_handle;
	LONG main_rc;

	HWND in_handle;
	LONG in_rc;

	while (true) {
		do {
			TempOptions = Options;
			main_rc = -1;
			main_handle = OwnerDraw::Begin_Dialog(IDD_OPT_MAIN, Main_Options_Dialog_Proc);
		} while (main_handle == 0);
		SetWindowLong(main_handle, DWL_USER, (LONG)&main_rc);
		OwnerDraw::Display_Dialog(main_handle);

		while (main_rc < 0) {
			if (OwnerDraw::Dialog_Message_Handler() == true) {
				break;
			}
			Title_Screen_Restore();
		}

		Apply_Game_Settings(main_handle); // RA2: as above
		OwnerDraw::End_Dialog(main_handle);

		switch (main_rc) {
			case IDC_OPTMAIN_NETWORK: {
				in_rc = -1; // level-2 1.001: no Read_MultiPlayer_Settings call here
				in_handle = OwnerDraw::Begin_Dialog(IDD_OPT_IPX, IPX_Options_Proc);
				if (in_handle) {
					SetWindowLong(in_handle, DWL_USER, (LONG)&in_rc);
					OwnerDraw::Display_Dialog(in_handle);

					while (in_rc < 0) {
						if (OwnerDraw::Dialog_Message_Handler() == true) {
							break;
						}
						Title_Screen_Restore();
					}

					OwnerDraw::End_Dialog(in_handle);
				}
			}
			break;

			case IDC_OPTMAIN_KEYBOARD:
				Options.Hotkey_Dialog();
				break;

			default:
				Options.Save_Settings();
				GameActive = old_game_active;
				return;
		}
	}
}


/// <summary>
/// Handles the main options dialog.
/// This routine reports the button the player pressed back to the options dialog driver so
/// that it can bring up the appropriate sub dialog. The sound button is disabled when there
/// is no audio hardware to talk to.
/// </summary>
BOOL CALLBACK Main_Options_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x00542590; level-2 1.001: 0x0053FC70, 1996 instruction bytes; the detail slider index selection differs in nine bytes
{
	int rc = OwnerDraw::Default_Dialog_Proc(window, message, wparam, lparam);
	if (rc != 0) { // RA2: as above
		return(rc);
	}

	int * result = (int *)GetWindowLong(window, DWL_USER);
	HWND control = (HWND)lparam; // RA2: as above
	switch (message) {
		case WM_COMMAND:
			switch (LOWORD(wparam)) {
				case IDC_OPTMAIN_NETWORK: // RA2: as above
				case IDC_OPTMAIN_KEYBOARD:
					delete [] ResolutionModes; // RA2: as above
					ResolutionModes = NULL; // RA2: as above
					*result = LOWORD(wparam);
					break;

				case IDC_OPTMAIN_OK: // RA2: as above
					if (HIWORD(wparam) == 0) { // RA2: as above
						delete [] ResolutionModes; // RA2: as above
						ResolutionModes = NULL; // RA2: as above
						*(int *)GetWindowLong(window, DWL_USER) = IDC_OPTMAIN_MAINMENU;
					}
					break;

				case IDC_OPTMAIN_RESOLUTION: // RA2: as above
					if (HIWORD(wparam) == CBN_SELCHANGE) { // RA2: as above
						Center_Window_Within_Window(window, MainWindow);
						HWND combo = GetDlgItem(window, IDC_OPTMAIN_RESOLUTION); // RA2: as above
						if (combo == NULL) { // RA2: as above
							return(0);
						}
						int item = ComboBox_GetCurSel(combo); // RA2: as above
						int mode = ComboBox_GetItemData(combo, item); // RA2: as above
						TempOptions.ScreenWidth = ResolutionModes[mode].Width; // RA2: as above
						TempOptions.ScreenHeight = ResolutionModes[mode].Height; // RA2: as above
						if (TempOptions.ScreenWidth == Options.ScreenWidth && TempOptions.ScreenHeight == Options.ScreenHeight) {
							return(0);
						}
						if (Mode_Prompt_Dialog()) { // RA2: as above
							if (Debug_IngameModeChange) {
								Options.ScreenWidth = TempOptions.ScreenWidth;
								Options.ScreenHeight = TempOptions.ScreenHeight;
								return(0);
							}
							if (Test_Display_Mode_Dialog(TempOptions.ScreenWidth, TempOptions.ScreenHeight)) { // RA2: as above
								Options.ScreenWidth = TempOptions.ScreenWidth;
								Options.ScreenHeight = TempOptions.ScreenHeight;
								Relayout_Interface_Art(TempOptions.ScreenWidth, TempOptions.ScreenHeight); // RA2: as above
								Darken_Surface(NULL, true); // RA2: as above
								return(0);
							}
							ComboBox_SetCurSel(combo, InitialResolution); // RA2: as above
							return(0);
						}
						ComboBox_SetCurSel(combo, InitialResolution); // RA2: as above
						return(0);
					}
					break;
			}
			return(0);

		case WM_DESTROY: // RA2: as above
			if (ResolutionModes) { // RA2: as above
				delete [] ResolutionModes; // RA2: as above
				ResolutionModes = NULL; // RA2: as above
			}
			return(0);

		case WM_HSCROLL: { // RA2: as above
			if (LOWORD(wparam) != TB_THUMBTRACK) { // RA2: as above
				return(0);
			}
			int position = HIWORD(wparam); // RA2: as above
			char const * name; // RA2: as above; level-2 1.001: one label tail after the slider chain, as in gibbo101 src/mainopt.cpp FUN_0055FDB0 (YR 1.001, @719fcc7)
			HWND text = NULL; // RA2: as above
			if (control == GetDlgItem(window, IDC_DETAIL_LEVEL_SLIDER)) { // RA2: as above
				int index = 2;
				if (!position) {
					index = 0;
				}
				name = DetailLabels[index]; // RA2: as above
				text = GetDlgItem(window, IDC_DETAIL_LEVEL_LABEL); // RA2: as above
			} else if (control == GetDlgItem(window, IDC_DIFFICULTY_SLIDER)) { // RA2: as above
				name = DifficultyLabels[position]; // RA2: as above
				text = GetDlgItem(window, IDC_DIFFICULTY_LABEL); // RA2: as above
			} else if (control == GetDlgItem(window, IDC_SCROLL_SPEED_SLIDER)) { // RA2: as above
				name = ScrollLabels[position]; // RA2: as above
				text = GetDlgItem(window, IDC_SCROLL_SPEED_LABEL); // RA2: as above
			} else if (control == GetDlgItem(window, IDC_MUSIC_VOLUME)) { // RA2: as above
				if (OptionsReady) { // level-2 1.001: as above
					Options.Set_Score_Volume((float)(SendMessage(control, TBM_GETPOS, 0, 0) * 0.1), true); // RA2: as above
				}
			} else if (control == GetDlgItem(window, IDC_SOUND_VOLUME)) { // RA2: as above
				if (OptionsReady) { // level-2 1.001: as above
					Options.Set_Sound_Volume((float)(SendMessage(control, TBM_GETPOS, 0, 0) * 0.1), true); // RA2: as above
				}
			} else if (control == GetDlgItem(window, IDC_VOICE_VOLUME)) { // RA2: as above
				if (OptionsReady) { // level-2 1.001: as above
					Options.Set_Voice_Volume((float)(SendMessage(control, TBM_GETPOS, 0, 0) * 0.1), true); // RA2: as above
				}
			}
			if (text) { // RA2: as above
				SendMessage(text, OD_SETTEXTW, 0, (LPARAM)StringTable::LoadString(name, NULL, RA2_SOURCE, 540)); // level-2 1.001: line 540
			}
			return(0);
		}

		case OD_SUBCLASSED: { // RA2: as above
			OptionsReady = false; // RA2: as above
			HWND slider = GetDlgItem(window, IDC_DETAIL_LEVEL_SLIDER); // RA2: as above
			if (slider) { // RA2: as above
				SendMessage(slider, OD_TRACKNUMBERS, 0, 0); // RA2: as above
				SendMessage(slider, TBM_SETRANGE, TRUE, MAKELONG(0, 1)); // RA2: as above
				SendMessage(slider, TBM_SETPOS, TRUE, Options.DetailLevel != 0); // RA2: as above
			}

			HWND combo = GetDlgItem(window, IDC_OPTMAIN_RESOLUTION); // RA2: as above
			if (Options.AllowHiResModes) {
				ResolutionModes = (ModeSize *)EnumDisplayModes(640, 480, 4096, 4096, 16); // RA2: as above
			} else {
				ResolutionModes = (ModeSize *)EnumDisplayModes(640, 480, 1024, 768, 16); // RA2: as above
			}
			int * modes = (int *)ResolutionModes; // RA2: as above
			int selected = -1; // RA2: as above
			int count = 0; // RA2: as above
			int item_index = 0; // level-2 1.001: initialised after the others (count stores an immediate zero)
			if (modes != NULL) {
				while (*modes != 0) {
					int width = *modes++;
					int height = *modes++;
					if (Options.AllowHiResModes || width == 640 || width == 800 || width == 1024) { // RA2: as above
						if (width == TempOptions.ScreenWidth && height == TempOptions.ScreenHeight) {
							selected = count; // RA2: as above
						}
						char buffer[64];
						sprintf(buffer, "%d x %d x 16", width, height);
						int item = SendMessage(combo, OD_ADDSTRING, 0, (LPARAM)buffer); // level-2 1.001: the owner-draw add (0x4BC), not CB_ADDSTRING
						ComboBox_SetItemData(combo, item, item_index); // RA2: as above
						count++; // RA2: as above
						item_index++;
					} else { // level-2 1.001: the skipped mode counts in its own branch (gibbo101 src/mainopt.cpp FUN_0055FDB0, @719fcc7)
						item_index++;
					}
				}
			}
			ComboBox_SetCurSel(combo, selected); // RA2: as above
			InitialResolution = selected; // RA2: as above

			slider = GetDlgItem(window, IDC_DIFFICULTY_SLIDER); // RA2: as above
			if (slider) { // RA2: as above
				SendMessage(slider, OD_TRACKNUMBERS, 0, 0); // RA2: as above
				SendMessage(slider, TBM_SETRANGE, TRUE, MAKELONG(0, 2)); // RA2: as above
				SendMessage(slider, TBM_SETPOS, TRUE, Options.Difficulty); // RA2: as above
			}

			HWND box = GetDlgItem(window, IDC_TARGET_LINES); // RA2: as above
			if (box) { // RA2: as above
				SendMessage(box, BM_SETCHECK, Options.ActionLines != 0, 0); // RA2: as above
			}
			box = GetDlgItem(window, IDC_SHOW_HIDDEN); // RA2: as above
			if (box) { // RA2: as above
				SendMessage(box, BM_SETCHECK, Options.IsShowHidden != 0, 0); // RA2: as above
			}
			box = GetDlgItem(window, IDC_TOOLTIPS); // RA2: as above
			if (box) { // RA2: as above
				SendMessage(box, BM_SETCHECK, Options.ToolTips != 0, 0); // RA2: as above
			}

			slider = GetDlgItem(window, IDC_SCROLL_SPEED_SLIDER); // RA2: as above
			if (slider) { // RA2: as above
				SendMessage(slider, OD_TRACKNUMBERS, 0, 0); // RA2: as above
				SendMessage(slider, TBM_SETRANGE, TRUE, MAKELONG(0, 6)); // RA2: as above
				SendMessage(slider, TBM_SETPOS, TRUE, 6 - Options.ScrollRate); // RA2: as above
			}

			int sound = AudioDeviceAvailable(); // RA2: as above
			slider = GetDlgItem(window, IDC_MUSIC_VOLUME); // RA2: as above
			if (slider) { // RA2: as above
				SendMessage(slider, OD_TRACKSILENT, 0, 0); // RA2: as above
				SendMessage(slider, TBM_SETRANGE, TRUE, MAKELONG(0, 10)); // RA2: as above
				SendMessage(slider, TBM_SETPOS, TRUE, (int)(Options.ScoreVolume * 10.0 + 0.5)); // RA2: as above
				EnableWindow(slider, sound); // RA2: as above
			}
			slider = GetDlgItem(window, IDC_SOUND_VOLUME); // RA2: as above
			if (slider) { // RA2: as above
				SendMessage(slider, OD_TRACKSILENT, 0, 0); // RA2: as above
				SendMessage(slider, TBM_SETRANGE, TRUE, MAKELONG(0, 10)); // RA2: as above
				SendMessage(slider, TBM_SETPOS, TRUE, (int)(Options.SoundVolume * 10.0 + 0.5)); // RA2: as above
				EnableWindow(slider, sound); // RA2: as above
			}
			slider = GetDlgItem(window, IDC_VOICE_VOLUME); // RA2: as above
			if (slider) { // RA2: as above
				SendMessage(slider, OD_TRACKSILENT, 0, 0); // RA2: as above
				SendMessage(slider, TBM_SETRANGE, TRUE, MAKELONG(0, 10)); // RA2: as above
				SendMessage(slider, TBM_SETPOS, TRUE, (int)(Options.VoiceVolume * 10.0 + 0.5)); // RA2: as above
				EnableWindow(slider, sound); // RA2: as above
			}
			OptionsReady = true; // RA2: as above
			return(0);
		}
	}
	return(0);
}


/// <summary>
/// Handles the network options dialog.
/// This routine lists the IPX addresses of the network cards bound to the machine and lets
/// the player choose one, along with the socket number and destination network to use. The
/// socket and destination network are validated before the options are accepted.
/// </summary>
BOOL CALLBACK IPX_Options_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x00542D60, TibSun's IPX_Options_Proc; level-2 1.001: 0x00540440, TibSun's form (opents_TibSun code/mainopt.cpp) without the firewall check box and the source port of later versions
{
	HWND handle; // level-2 1.001: TibSun's function locals
	int i;
	bool inited;
	int * result;
	char socket_string[16];
	char addr_string[32];
	char addr_str[64];

	int rc = OwnerDraw::Default_Dialog_Proc(window, message, wparam, lparam);

	if (rc == 0) {
		result = (int *)GetWindowLong(window, DWL_USER);

		switch (message) {
			case OD_SUBCLASSED: { // RA2: as above
				HWND combobox = GetDlgItem(window, IDC_IPX_NETCARD); // RA2: as above

				inited = false;
				if (PacketTransport == NULL) {
					PacketTransport = new IPXInterfaceClass;
					PacketTransport->Init();
					inited = true;
				}

				if (PacketTransport != NULL) {
					DebugString("Creating IPX Interface\n");
					IPXInterfaceClass * ipxi = (IPXInterfaceClass *)PacketTransport;
					for (i = 0; ipxi->Get_Network_Card_Address_As_String(i, addr_str, sizeof(addr_str)); ++i) { // level-2 1.001: the list ends at the first card without an address
						DebugString("Got address for network card %d\n", i);
						DebugString("Address is %s\n", addr_str);
						if (SendMessage(combobox, OD_FINDSTRING, 0, (LPARAM)addr_str) != -1) { // level-2 1.001: a card already listed ends the list
							break;
						}
						SendMessage(combobox, OD_ADDSTRING, 0, (LPARAM)addr_str); // RA2: as above
					}
				}

				if (inited) {
					delete PacketTransport;
					PacketTransport = NULL;
				}

				if (SendMessage(combobox, CB_GETCOUNT, 0, 0) == 0) { // RA2: as above
					SendMessage(combobox, OD_ADDITEM, 0, (LPARAM)StringTable::LoadString("TXT_NO_BOUND_NET_CARD", NULL, RA2_SOURCE, 870)); // level-2 1.001: line 870
				}
				int netcard = Options.NetCard;
				if (netcard < 0 || netcard >= SendMessage(combobox, CB_GETCOUNT, 0, 0)) {
					netcard = 0;
				}
				SendMessage(combobox, CB_SETCURSEL, netcard, 0); // RA2: as above
				SendMessage(window, OD_REFRESH_IPX, 0, 0); // RA2: as above

				CurrentNetCard = -1; // RA2: as above
				handle = GetDlgItem(window, IDC_IPX_SOCKET);
				if (Options.Socket != 0xFFFF) {
					sprintf(socket_string, "%d", Options.Socket);
					SendMessage(handle, OD_SETTEXT, 0, (LPARAM)socket_string); // RA2: as above
				}
				SendMessage(handle, EM_LIMITTEXT, 5, 0); // RA2: as above
				handle = GetDlgItem(window, IDC_IPX_DESTNET);
				if (strlen(Options.DestNet)) {
					SendMessage(handle, OD_SETTEXT, 0, (LPARAM)Options.DestNet); // RA2: as above
				}
				SendMessage(handle, EM_LIMITTEXT, 11, 0); // RA2: as above
				return(0); // level-2 1.001: no firewall check box or port edit box
			}

			case OD_TABFOCUS: // RA2: as above
				Focus_Next_Tab_Item(lparam, wparam != 0); // RA2: as above
				return(0);

			case WM_COMMAND: {
				switch (LOWORD(wparam)) {
					case IDOK:
						handle = GetDlgItem(window, IDC_IPX_SOCKET);
						SendMessage(handle, OD_GETTEXT, sizeof(socket_string), (LPARAM)socket_string); // RA2: as above
						unsigned short socket;
						if (strlen(socket_string)) {
							socket = atoi(socket_string);
							if (strlen(socket_string) > 5 || socket > 16383) {
								WWMessageBox(L" ").Process(StringTable::LoadString("TXT_INVALID_SOCKET", NULL, RA2_SOURCE, 938), StringTable::LoadString("TXT_OK", NULL, RA2_SOURCE, 938), NULL, NULL, false); // level-2 1.001: line 938
								return(0);
							}
						} else {
							socket = -1;
						}
						handle = GetDlgItem(window, IDC_IPX_DESTNET);
						SendMessage(handle, OD_GETTEXT, sizeof(addr_string), (LPARAM)addr_string); // RA2: as above
						strncpy(addr_str, addr_string, sizeof(addr_string));

						if (strlen(addr_string)) {
							char * octet = strtok(addr_string, ".");
							int net[4] = {-1, -1, -1, -1}; // RA2: as above
							if (octet) {
								int * part = net; // RA2: as above
								do {
									sscanf(octet, "%x", part);
									part++;
									octet = strtok(NULL, ".");
								} while (octet);
							}
							if ((net[0] & 255) != net[0] || (net[1] & 255) != net[1] || (net[2] & 255) != net[2] || (net[3] & 255) != net[3]) {
								WWMessageBox(L" ").Process(StringTable::LoadString("TXT_DESTNET_ADDR_ERROR", NULL, RA2_SOURCE, 972), StringTable::LoadString("TXT_OK", NULL, RA2_SOURCE, 972), NULL, NULL, false); // level-2 1.001: line 972
								return(0);
							}
						}

						handle = GetDlgItem(window, IDC_IPX_NETCARD);
						Options.NetCard = SendMessage(handle, CB_GETCURSEL, 0, 0); // RA2: as above
						Options.Socket = socket;
						strcpy(Options.DestNet, addr_str);
						break;

					case IDCANCEL:
						break;

					case IDC_IPX_NETCARD:
						handle = GetDlgItem(window, IDC_IPX_NETCARD);
						CurrentNetCard = SendMessage(handle, CB_GETCURSEL, 0, 0); // RA2: as above
						return(0);

					default:
						return(0);
				}
				*result = 2;
			}
		}
		rc = 0;
	}

	return(rc);
}


/// <summary>
/// Switches the game over to a new screen resolution.
/// This routine tears down every drawing surface and the mouse handler, sets the new video
/// mode, then builds all of them back up and hands the tactical map its new dimensions. The
/// hicolor remap tables are rebuilt as well, since the new mode may pack its pixels
/// differently.
/// </summary>
/// <param name="width">The width of the display mode to change to.</param>
/// <param name="height">The height of the display mode to change to.</param>
/// <returns>bool; Was the mode changed? If not, the previous mode has been restored.</returns>
bool Change_Display_Mode(int width, int height) // RA2: 0x005434E0
{
	DebugString("About to set video mode\n");

	Point2D old_size(VideoModeWidth, VideoModeHeight); // RA2: as above

	int redleft = DSurface::Get_Red_Left();
	int redright = DSurface::Get_Red_Right();
	int greenleft = DSurface::Get_Green_Left();
	int greenright = DSurface::Get_Green_Right();
	int blueleft = DSurface::Get_Blue_Left();
	int blueright = DSurface::Get_Blue_Right();

	Hide_Mouse();

	Wait_Blit();

	if (WindowedMode == true) {
		VisibleRect = Rect(0, 0, width, height);
		VideoModeWidth = width;
		VideoModeHeight = height;
		DebugString("VisibleRect: %dx%d\n", width, height);
	} else {
		if (MouseCursor != NULL) {
			DebugString("Removing mouse handler\n");
			delete MouseCursor;
			MouseCursor = NULL;
		}

		if (VisibleSurface != NULL) {
			DebugString("Deleting primary surface\n");
			delete VisibleSurface;
			VisibleSurface = NULL;
		}

		if (!Set_Video_Mode(MainWindow, width, height, 16)) {
			DebugString("Set_Video_Mode failed.\n");

			DebugString("Restoring primary surface\n");
			VisibleSurface = DSurface::Create_Primary();

			DebugString("Restoring mouse handler\n");
			MouseCursor = new WWMouseClass(VisibleSurface, MainWindow);

			void const * mouseshp = MFCD::Retrieve("MOUSE.SHP");
			if (mouseshp != NULL) {
				Point2D hotspot = Point2D(0, 0);
				Set_Mouse_Cursor(hotspot, (ShapeSet const *)mouseshp, 0);
			}

			Map.Set_Default_Mouse(MOUSE_NORMAL);
			Map.Override_Mouse_Shape(MOUSE_NORMAL);

			Show_Mouse();

			return(false);
		}

		DebugString("Mode apparently set OK\n");
		VisibleRect = Rect(0, 0, width, height);
		DebugString("VisibleRect: %dx%d\n", width, height);
	}

	if (AlternateSurface != NULL) {
		DebugString("Deleting AlternateSurface\n");
		delete AlternateSurface;
		AlternateSurface = NULL;
	}

	if (HiddenSurface != NULL) {
		DebugString("Deleting HiddenSurface\n");
		delete HiddenSurface;
		HiddenSurface = NULL;
	}

	if (TileSurface != NULL) {
		DebugString("Deleting TileSurface\n");
		delete TileSurface;
		TileSurface = NULL;
	}

	if (SidebarSurface != NULL) {
		DebugString("Deleting SidebarSurface\n");
		delete SidebarSurface;
		SidebarSurface = NULL;
	}

	if (CompositeSurface != NULL) {
		DebugString("Deleting CompositeSurface\n");
		delete CompositeSurface;
		CompositeSurface = NULL;
	}

	if (WindowedMode == false) {
		DebugString("Setting new window size to %dx%d\n", width, height);
		SetWindowPos(MainWindow, HWND_TOP, 0, 0, width, height, SWP_NOMOVE);
		DebugString("Creating primary surface\n");
		VisibleSurface = DSurface::Create_Primary();
	} else {
		DebugString("Setting new window size to %dx%d\n", width, height);
		RECT windowrect;
		SetRect(&windowrect, 0, 0, width, height);
		AdjustWindowRectEx(&windowrect, GetWindowLong(MainWindow, GWL_STYLE), GetMenu(MainWindow) != 0, GetWindowLong(MainWindow, GWL_EXSTYLE));
		MoveWindow(MainWindow, 0, 0, windowrect.right - windowrect.left, windowrect.bottom - windowrect.top, TRUE);
	}

	Rect temp = Get_Title_Screen_Area(); // RA2: as above

	{
		Rect sidebar(0, 0, SidebarWidth, VisibleRect.Height); // RA2: as above
		Rect tile(0, 0, temp.Width, VisibleRect.Height); // RA2: as above
		Rect composite(0, 0, temp.Width, VisibleRect.Height); // RA2: as above
		Allocate_Surfaces(VisibleRect, composite, tile, sidebar, false); // RA2: as above
	}
	LogicalSurface = HiddenSurface;

	DebugString("Recalc color remap tables\n");
	ConvertClass::Reinitialize_Hicolor_Tables(redleft, redright, greenleft, greenright, blueleft, blueright);

	if (MouseCursor == NULL) {
		MouseCursor = new WWMouseClass(VisibleSurface, MainWindow);

		void const * mouseshp = MFCD::Retrieve("MOUSE.SHP");
		if (mouseshp != NULL) {
			Point2D hotspot = Point2D(0, 0);
			Set_Mouse_Cursor(hotspot, (ShapeSet const *)mouseshp, 0);
		}

		Map.Set_Default_Mouse(MOUSE_NORMAL);
		Map.Override_Mouse_Shape(MOUSE_NORMAL);

		Show_Mouse();

	} else {
		((WWMouseClass*)MouseCursor)->Calc_Confining_Rect();
	}

	Map.Set_View_Dimensions(temp);
	Relayout_Interface_Art(VideoModeWidth, VideoModeHeight); // RA2: as above

	Map.Init_IO();
	Map.Activate(1); // RA2: as above
	Map.Reposition_Sidebar();
	Map.Flag_To_Redraw(GS_REDRAW_ALL);

	for (HWND dialog = WS_Top_Window(); dialog != NULL; dialog = WS_Next_Lower_Dialog(dialog)) { // RA2: as above
		On_WM_NCDESTROY(dialog); // RA2: as above
		Resize_Dialog_To_Screen(dialog, &old_size); // RA2: as above
	}

	Show_Mouse();

	DebugString("Mode change complete.\n");

	return(true);
}


/// <summary>
/// Tries a display mode out and asks the player to confirm it.
/// This routine switches to the requested mode and puts up a confirmation dialog. If the
/// player does not accept the mode -- or says nothing at all, because a bad mode may well
/// leave the screen unreadable -- the previous resolution is restored.
/// </summary>
/// <param name="width">The width of the display mode to try.</param>
/// <param name="height">The height of the display mode to try.</param>
/// <returns>bool; Was the new display mode accepted and left in place?</returns>
bool Test_Display_Mode_Dialog(int width, int height) // RA2: 0x00543A70
{
	int rc = -1;

	DebugString("Testing display mode @ %dx%d\n", width, height);
	Hide_Mouse();
	HiddenSurface->Fill(TBLACK);
	Update_Visible_Surface();

	if (!Change_Display_Mode(width, height)) {
		return(false);
	}

	HiddenSurface->Fill(TBLACK);
	Update_Visible_Surface();
	Show_Mouse();
	Darken_Surface(NULL, true); // RA2: as above

	HWND dialog = OwnerDraw::Begin_Dialog(IDD_OPT_CONFIRM_MODE, Test_Display_Mode_Dialog_Proc);
	if (dialog) {
		SetWindowLong(dialog, DWL_USER, (LONG)&rc);
		OwnerDraw::Display_Dialog(dialog);

		CDTimerClass<SystemTimerClass> timer = 10 * TIMER_SECOND;
		while (rc < 0) {
			if (OwnerDraw::Dialog_Message_Handler() == true) {
				break;
			}
			Title_Screen_Restore();
			if (timer <= 0) {
				PostMessage(dialog, WM_COMMAND, IDC_TRY_MODE_CANCEL, 0); // RA2: as above
				timer = 5 * TIMER_SECOND;
			}
		}

		OwnerDraw::End_Dialog(dialog);
		if (rc != 1) { // RA2: as above
			DebugString("Resetting display mode @ %dx%d\n", Options.ScreenWidth, Options.ScreenHeight);
			Change_Display_Mode(Options.ScreenWidth, Options.ScreenHeight);
			LogicalSurface = HiddenSurface;
			return(false);
		}
	}

	DebugString("Keeping display mode @ %dx%d\n", width, height);
	LogicalSurface = HiddenSurface;
	return(true);
}


/// <summary>
/// Handles the mode confirmation dialog.
/// This routine records the button the player pressed so that the mode test can tell
/// whether the new resolution was accepted or rejected.
/// </summary>
BOOL CALLBACK Test_Display_Mode_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x00543C40, TibSun's Test_Display_Mode_Dialog_Proc
{
	int rc = OwnerDraw::Default_Dialog_Proc(window, message, wparam, lparam);
	if (rc == 0) {
		int * result = (int *)GetWindowLong(window, DWL_USER);
		switch (message) {
			case OD_SUBCLASSED: { // RA2: as above
				wchar_t const * text = StringTable::LoadString("GUI:ConfirmModeChange", NULL, RA2_SOURCE, 1401); // level-2 1.001: line 1401
				HWND item = GetDlgItem(window, IDC_CONFIRM_MODE_TEXT); // RA2: as above
				SendMessage(item, OD_SETTEXTW, 0, (LPARAM)text); // RA2: as above
				break;
			}

			case WM_COMMAND:
				switch (LOWORD(wparam)) {
					case IDC_TRY_MODE_OK: // RA2: as above
						*result = 1;
						break;

					case IDC_TRY_MODE_CANCEL: // RA2: as above
						*result = 2;
						break;
				}
				break;
		}
		return(0);
	}
	return(rc);
}


/// <summary>
/// Handles the display options dialog messages.
/// This routine fills the resolution list with the display modes the hardware reports,
/// remembers which one the player picked, and tracks the movie stretching preference. The
/// chosen resolution is staged in the temporary options so that it can be tested before
/// being made permanent.
/// </summary>
/// level-2 1.001: adopted from gibbo101 src/mainopt.cpp Display_Options_Dialog_Body (YR 1.001, @719fcc7, GPL-3.0-or-later), itself TibSun's
/// (opents_TibSun code/mainopt.cpp); RA2 1.001 keeps this TibSun dialog at 0x00541180 although nothing calls it.
static __forceinline BOOL Display_Options_Dialog_Body(HWND window, UINT message, WPARAM wparam)
{
	enum {
		MIN_WIDTH = 640,
		MIN_HEIGHT = 480,
		MAX_WIDTH = 1024,
		MAX_HEIGHT = 768,
		MAX_HI_WIDTH = 4096,
		MAX_HI_HEIGHT = 4096
	};

	static int * _modes = NULL; // level-2 1.001: 0x00A56934
	static int _current_mode = -1; // level-2 1.001: 0x007CA90C
	static int _previous_mode = -1; // level-2 1.001: 0x007CA910
	static bool _initialized = true; // level-2 1.001: 0x007CA914

	int * result = (int *)GetWindowLong(window, DWL_USER);
	switch (message) {
		case WM_COMMAND:
			switch (LOWORD(wparam)) {
				default:
					return(0);

				case IDC_DISPLAY_RESLIST: {
					HWND list = GetDlgItem(window, IDC_DISPLAY_RESLIST);
					_current_mode = ListBox_GetCurSel(list);
				}
				return(0);

				case IDOK:
				case IDC_DISPLAY_OK: {
					if (_previous_mode != _current_mode) {
						Center_Window_Within_Window(window, MainWindow);
						HWND list = GetDlgItem(window, IDC_DISPLAY_RESLIST);
						if (list) {
							int index = ListBox_GetItemData(list, _current_mode);
							int * modes = &_modes[2 * index];
							TempOptions.ScreenWidth = modes[0];
							TempOptions.ScreenHeight = modes[1];
						}
					}
					HWND button = GetDlgItem(window, IDC_STRETCH_MOVIES);
					if (button) {
						Options.StretchMovies = Button_GetCheck(button) == BST_CHECKED;
					}
				}
				break;

				case IDC_OPTMAIN_OK:
					delete [] _modes;
					_modes = NULL;
					*result = 2;
					return(0);
			}
			delete [] _modes;
			_modes = NULL;
			*result = 1;
			break;

		case OD_SUBCLASSED: {
			HWND list = GetDlgItem(window, IDC_DISPLAY_RESLIST);
			if (Options.AllowHiResModes) {
				_modes = EnumDisplayModes(MIN_WIDTH, MIN_HEIGHT, MAX_HI_WIDTH, MAX_HI_HEIGHT, 16);
			} else {
				_modes = EnumDisplayModes(MIN_WIDTH, MIN_HEIGHT, MAX_WIDTH, MAX_HEIGHT, 16);
			}
			int * modes = _modes;
			int item_index = 0;
			int initial_mode = -1;
			int mode_index = 0;
			if (modes != NULL) {
				while (*modes != 0) {
					int width = *modes++;
					int height = *modes++;
					if (Options.AllowHiResModes || width == MIN_WIDTH || width == 800 || width == MAX_WIDTH) {
						if (width == TempOptions.ScreenWidth && height == TempOptions.ScreenHeight) {
							initial_mode = mode_index;
						}
						char buffer[64];
						sprintf(buffer, "%d x %d x 16", width, height);
						int index = (int)SendMessage(list, OD_LB_ADDSTRING, 0, (LPARAM)buffer);
						ListBox_SetItemData(list, index, item_index);
						mode_index++;
						item_index++;
					} else {
						item_index++;
					}
				}
			}
			ListBox_SetCurSel(list, initial_mode);
			_initialized = true;
			_current_mode = initial_mode;
			_previous_mode = initial_mode;

			HWND button = GetDlgItem(window, IDC_STRETCH_MOVIES);
			if (button) {
				bool stretch = Options.StretchMovies == true && DSurface::AllowStretchBlits == true;
				Button_SetCheck(button, stretch != false);
				EnableWindow(button, (BOOL)DSurface::AllowStretchBlits);
			}
		}
		break;

	}
	return(0);
}


/// <summary>
/// Handles the display options dialog.
/// This routine gives the owner draw dialog system first refusal on the message and only
/// deals with what it leaves behind.
/// </summary>
BOOL CALLBACK Display_Options_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // level-2 1.001: 0x00541180, TibSun's dialog (via gibbo101 src/mainopt.cpp @719fcc7); not in 1.006
{
	int rc = OwnerDraw::Default_Dialog_Proc(window, message, wparam, lparam);
	if (rc == 0) {
		return(Display_Options_Dialog_Body(window, message, wparam));
	}
	return(rc);
}
