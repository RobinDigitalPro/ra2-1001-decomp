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

// RA2: the first part of wonline.cpp (0x0073C040-0x00741EA0): the lobby helpers, the chat text senders, the channel list requests, the idle callback, the reset of the globals, the lobby, game and user lists, the user list, the start of the chat services and the leave of a user; Shutdown_Chat, Get_WDT_State_Silent, Init_Wonline (0x00742080-0x007424C0) follow as functions placed by their addresses
#include "always.h"

#include "_keyboar.h"
#include "_map.h"
#include "_rules.h"
#include "arraylist.h"
#include "dict.h" // RA2: the lobby dictionaries
#include "conquer.h"
#include "data.h"
#include "dbgprint.h"
#include "globals.h"
#include "goptions.h"
#include "ini.h" // RA2: the includes this file needs
#include "rcptr.h" // RA2: the profile pointer
#include "rules.h" // RA2: the CRCs of the rules
#include "init.h" // RA2: Title_Screen_Restore
#include "msgloop.h" // RA2: Peek_Windows_Message, MessageLoopCount
#include "ipxmgr.h"
#include "language\language.h"
#include "netshare.h"
#include "ownrdraw.h"
#include "playerprofile.h" // RA2: the profile of the player (wolpersonainformation.cpp)
#include "scenario.h"
#include "srfcache.h" // RA2: the images of the game list
#include "session.h"
#include "theme.h"
#include "widewstring.h" // RA2: the lobby text is wide
#include "windlg.h"
#include "winstub.h"
#include "wolapi.h" // RA2: the includes this file needs
#include "wonline.h"
#include "wstring.h"

#include <atlbase.h> // RA2: the chat services are COM objects
extern CComModule _Module; // RA2: required between atlbase.h and atlcom.h, defined with the rest of the file
#include <atlcom.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <shellapi.h>
#include <windows.h>
#undef LoadString // RA2: windows.h maps it to LoadStringA
#include "stringtable.h" // RA2: the texts are loaded from the string table by label

// RA2: the per user lobby record. It is 0x94 bytes (as TibSun's), the player's accepted state is at +0x20 (0x0073D150 stores it)
struct ChannelUserInfo
{
	char name[20];
	int color;
	int house;
	int Unknown_1C; // RA2: as above
	int accepted;
	char pad[0x70];
};

// RA2: globals and functions of the rest of wonline.cpp and of other files, as the executable's callers use them
extern ChannelUserInfo g_UserInfo[]; // RA2: 0x00B29CF0, one record per user of the channel
extern int g_RuleCRC; // RA2: the three CRCs 0x0073CFD0 xors (0x00B2AC18 to 0x00B2AC20)
extern int g_ArtCRC; // RA2: as above
extern int g_AICRC; // RA2: as above
extern ArrayList<unsigned int> g_ChanListQueue; // RA2: 0x00B29390, the channel list requests that wait for an answer
extern HANDLE g_WaitEventHandles[18]; // RA2: 0x00B264F8, EV_COUNT events
extern unsigned int g_ActiveWaitFlags; // RA2: 0x00B2ABE0, the events the wait dialog (0xC4) waits for
extern wchar_t g_LastErrorMessage[]; // RA2: 0x00B2A8EC, wide
extern int g_IsChannelCreator; // RA2: 0x00B2AC58, 1 for the host of the channel
extern bool g_GameStartRequested; // RA2: 0x00B2AC04
extern int g_MatchState; // RA2: 0x00B26898, set with the next three by Set_Match_State
extern int g_MatchTimeout; // RA2: 0x00B2AB88
extern int g_MatchResult; // RA2: 0x00B2AC2C
extern long g_MatchStartTime; // RA2: 0x00B2A8A4
extern ArrayList<User> g_UserList; // RA2: 0x00B2A728
extern Channel g_CurrentChannel; // RA2: 0x00B299C0
extern int g_AllowPage; // RA2: the lobby settings, 0x00B290A0
extern int g_AllowFind; // RA2: 0x00B2A818
extern int g_LangFilter; // RA2: 0x00B2A7E4
extern int g_LobbyMusic; // RA2: 0x00B297C8
extern int g_ShowAllChannels; // RA2: 0x00B2A634
extern int g_DisplayAsian; // RA2: 0x00B2A804, the two settings TibSun does not have
extern int g_DisplayLatin; // RA2: 0x00B2A7E8
extern int g_LanguageCode; // RA2: 0x00B2AC5C
extern int Online_Session_State; // RA2: as in ownrdraw.cpp
extern ArrayList<Wstring> g_WDTTeamLookupQueue; // RA2: 0x00B2A648, the names whose team is asked for (0x0073E100 sends them in batches)
extern ArrayList<Wstring> g_UserLocaleLookupQueue; // RA2: 0x00B29468, the names whose locale is asked for
extern unsigned g_LastWDTUserTeamRequestTime; // RA2: 0x00B28FF8
extern unsigned g_LastChannelLocaleRequestTime; // RA2: 0x00B28FF4
extern int g_NextWDTStatePollTime; // RA2: 0x00B292DC
extern int WolOptionsLocked; // RA2: 0x00B2AC40, as in netshare.cpp (2 once the host started the game)
extern bool g_StartGameReceived; // RA2: 0x00B2AC45, the start of the game was announced, Start_Game_Now runs it
extern bool g_StartGameRunning; // RA2: 0x00B2AC44, Start_Game_Now is running (it sets it first and clears it at its end)
void Start_Game_Now(void); // RA2: 0x0074F300, the executable's own debug text names it so
extern rc_ptr<PlayerProfile> g_PlayerProfile; // RA2: 0x00B28CC0, set by Reset_WOL_Globals
extern ArrayList<Channel> g_UserChannels; // RA2: 0x00B26C88
extern ArrayList<Channel> g_GameChannelList; // RA2: 0x00B29990
extern Dictionary<Wstring, int> g_WDTTeams; // RA2: 0x00B294B8
extern Dictionary<Wstring, int> g_UserLocales; // RA2: 0x00B293A0
extern Dictionary<Wstring, Ladder> g_BattleClansLadderDict; // RA2: 0x00B296F8
extern Dictionary<Wstring, Ladder> g_WDTLadderDict; // RA2: 0x00B26970
extern Dictionary<Wstring, Ladder> g_GeneralLadderDict; // RA2: 0x00B2AB98
extern Dictionary<Wstring, Channel> g_BuddyChannels; // RA2: 0x00B29478, the channel a buddy is in, by name
extern ArrayList<Wstring> g_BuddyList; // RA2: 0x00B26920, the names of the buddies
extern ArrayList<Wstring> g_BuddyRequests; // RA2: 0x00B29838, the buddies whose status waits to be asked for
extern Dictionary<Wstring, unsigned int> g_BuddyStatus; // RA2: 0x00B29848, the status of a buddy by name
extern Dictionary<Wstring, Ladder> * g_ActiveLadder; // RA2: 0x00B2AC24
extern int g_InstalledLadderSKU; // RA2: 0x00B2A7F0
extern int g_SelectedLadderSKU; // RA2: 0x00B26564
extern int g_GameSKU; // RA2: 0x007FD370, 0x2100
extern Channel g_PendingChannel; // RA2: 0x00B26A60, cleared with the current channel
extern Server g_GameServer; // RA2: 0x00B28CD0
extern Server g_WDTServer; // RA2: 0x00B29880
extern int g_CurrentServerIndex; // RA2: 0x00B292D8
extern int g_TargetServerIndex; // RA2: 0x00B2A7F4
extern bool g_IgnoreNetStatus; // RA2: 0x00B2ABD8
extern bool g_ShowMOTD; // RA2: 0x007FD2FC, true at first
extern Wstring g_Motd; // RA2: 0x00B26954, the message of the day
extern bool g_PlayingNetGame; // RA2: 0x00B2ABD9, as windlg.cpp
extern bool g_ConnectionLost; // RA2: 0x00B2ABDA
extern int g_ServerType; // RA2: 0x007FD300, -1 at first
extern int g_LastChatListTime; // RA2: 0x00B2ABD0
extern int g_LastGameListTime; // RA2: 0x00B2ABD4
extern unsigned short const * g_Lobbies[6]; // RA2: 0x00B26C94, the lobby names, wide // level-2 1.001: six lobbies (0x00B0E5D4)
extern int WDT_TERRITORY_LOBBY_INDEXES[6]; // RA2: 0x00B26540, one index per lobby // level-2 1.001: six (0x00B0DFB8)
extern DWORD g_dwChatAdvise; // RA2: 0x00B2AC60
extern DWORD g_dwNetUtilAdvise; // RA2: 0x00B2AC64
extern DWORD g_dwDownloadAdvise; // RA2: 0x00B2AC68
extern int g_SquadInfoRequests; // RA2: 0x00B2ABF4
extern int g_RequestingOwnSquadInfo; // RA2: 0x00B2ABF8
extern int g_OwnSquadID; // RA2: 0x00B2ABFC
extern char g_OwnSquadName[41]; // RA2: 0x00B2A8B0
extern int g_ChannelCount; // RA2: 0x00B2ABE8
extern int g_LadderPos; // RA2: 0x00B29CE8
extern int g_JoinLobbyNow; // RA2: 0x00B2ABF0
extern int g_UserAge; // RA2: 0x00B2AC6C
extern int g_UserConsent; // RA2: 0x00B2AC70
extern int ManglerIndex; // RA2: 0x00B2AC38, the mangler server picked for the port probes (FirewallHelperClass::Get_Next_Mangled_Source_Port reads it)
extern int g_Col_ChanName; // RA2: 0x00B29CCC, the column of the channel names in the lobby lists
extern int g_Col_GameName; // RA2: 0x00B2A8A8, the columns of the game list (TibSun's g_Col_GameName, g_Col_GameIcon, g_Col_GamePrivate, g_Col_GamePingTime and the observer column RA2 adds)
extern int g_Col_GameIcon; // RA2: 0x00B2A6F8
extern int g_Col_GamePrivate; // RA2: 0x00B2A6F4
extern int g_Col_GameObserver; // RA2: 0x00B299A0
extern int g_Col_GamePingTime; // RA2: 0x00B292A8
extern bool g_GameListRefreshing; // RA2: 0x00B2AC80, set while Refresh_Game_List fills the list
extern int ObserverMode; // RA2: 0x00A72C68, as in init.cpp
void __fastcall Clear_Listbox(HWND list); // RA2: 0x00600DB0, removes every row of an owner drawn list box
void __fastcall Get_Window_Item_Text(HWND list, int row, Wstring & text); // RA2: 0x00600EB0, the text of a row
#define OD_INSERTSTRING (WM_USER + 199) // RA2: 0x4C7, inserts the string at the row of wParam and returns the new row (name guessed from its use)
#define OD_ADDSTRING_LIST (WM_USER + 200) // RA2: 0x4C8, appends the string of lParam to an owner drawn list box and returns its row (name guessed from its use) // level-2 1.001: moved up for Refresh_Lobby_List
#define OD_FINDSTRING (WM_USER + 197) // RA2: 0x4C5, the row whose text is lParam, -1 if none (name guessed from its use)
WideWstring WideWstring_FromInt(int value); // RA2: 0x007710C0, the number as wide text ("%d")
WideWstring operator+(wchar_t const * first, WideWstring const & second); // RA2: 0x00771380

int Count_AI_Slots(void); // RA2: 0x005C9400, the slots holding an easy, medium or hard computer player
bool Is_Observer_Slot_Occupied(void); // RA2: 0x005C94B0, the observer slot holds a seated entry whose team is -1
bool Is_Observer_Slot_Full(void); // RA2: 0x005C9490, defined in netdlg2.cpp
bool Is_Real_Player_Entry(NodeNameType * entry); // RA2: 0x005C9320, the entry is a player (not open, closed, waiting or a computer player)
Wstring Lobby_Entry_Name(NodeNameType * entry); // RA2: 0x005CD0E0, the lobby's name for an open, closed, waiting or computer player entry
void Load_Observer_Mode(void); // RA2: 0x005CD380, reads MultiPlayer ObserverMode from RA2.INI (the counterpart of Save_Observer_Mode)
void Save_Observer_Mode(void); // RA2: 0x005CD3A0, defined in netdlg2.cpp
void Update_Observer_Buttons(HWND dialog); // RA2: 0x005CD540, defined in netdlg2.cpp
void Enable_Player_Combos(HWND dialog, bool value); // RA2: 0x005CD030, defined in netdlg2.cpp
int Player_Side_Combo_ID(int player); // RA2: 0x004D1350, defined in netdlg2.cpp (as the next eight)
int Player_Color_Combo_ID(int player); // RA2: 0x004D1CB0
int Side_Combo_Data(HWND dialog, int id, int index); // RA2: 0x004D1C70
void Fill_Observer_Combo(HWND dialog, int id); // RA2: 0x004D1640
void Fill_Random_Color_Combo(HWND dialog, int id); // RA2: 0x004D2250
void Select_Color_Combo(HWND dialog, int id, int color); // RA2: 0x004D2480
void Fill_Side_Combo(HWND dialog, int id); // RA2: 0x004D1560
void Fill_Color_Combo(HWND dialog, int id); // RA2: 0x004D2080
int Get_Slot_Control_Id(int slot); // RA2: 0x005C97A0
char * Wide_To_Narrow(wchar_t const * text); // RA2: 0x006FA120, static buffer
Wstring Wstring_FromWide(WideWstring const & text); // RA2: 0x007715D0, keeps the 7 bit characters
Wstring Wstring_Narrow(WideWstring const & text); // RA2: 0x00771280, narrows each character of a wide string (the counterpart of Wstring_ToWide)
void Draw_Player_List(int keep_selection, bool force); // RA2: 0x0073FEE0, one more argument than TibSun's
#define OD_INSERTSTRINGW (WM_USER + 204) // RA2: 0x4CC, inserts the wide string of lParam at the row of wParam (-1 appends) and returns the new row (name guessed from its use)
#define OD_SETTEXT (WM_USER + 180) // RA2: 0x4B4, sets the (narrow) text of a control of the dialog (name guessed from its use)
#define APP_REG_KEY "SOFTWARE\\Westwood\\Red Alert 2" // RA2: the registry key of the game (the literal at 0x007E6AD8)
void __fastcall Refresh_Slot_Settings(HWND dialog, bool force); // RA2: 0x005CA000, redraws the slot list of the game lobby
void __fastcall Fill_Buddy_List(HWND dialog); // RA2: 0x00755180, fills the buddy dialog (0x116)
void Char_To_Wide(wchar_t * wide, char const * narrow, int length); // RA2: 0x006FA0C0
wchar_t * Narrow_To_Wide(char const * narrow); // RA2: 0x006FA180
extern int g_Col_Username; // RA2: 0x00B2A81C, the name column of the user list (lobby and game channels)
extern int g_Col_Rank; // RA2: 0x00B292A4
extern int g_Col_Chanop; // RA2: 0x00B2657C
extern int g_Col_Gameinfo; // RA2: 0x00B2AB80
extern int g_Col_House; // RA2: 0x00B292E0
extern int g_Col_Accept; // RA2: 0x00B297B8
extern int g_Col_GamePing; // RA2: 0x00B26958
void Show_Wait_Window(unsigned int event, WideWstring const & text, bool block); // RA2: 0x0074D4D0, the wait dialog with a wide text
void Reset_Wait_Events(void); // RA2: 0x00752930, resets every wait event
BOOL CALLBACK WOL_Find_Page_Dialog_Proc(HWND win, UINT uMsg, WPARAM wParam, LPARAM lParam); // RA2: 0x007485D0
bool Wait_Callback_Thunk(void); // RA2: 0x0073C120, defined below
bool Is_Channel_Flag_8(Channel const * channel); // RA2: 0x0073C3C0, defined below

// level-2 1.001: the global objects of wonline.cpp, defined in the order of their dynamic initializers
// (0x0072F4A0-0x0072FB60, after the header constants). The order follows the executable's initializer
// table; it is the order gibbo101's YR wonline.cpp has, without YR's highscore dictionary, its
// welcome-choice functions, its timer and its wide string. Names without binary evidence are provisional.
class OLEInitializer // level-2 1.001: 0x0072F4A0/0x0072F4C0, OLE is brought up for the whole run (gibbo101 YR name)
{
	public:
		OLEInitializer(void) { OleInitialize(NULL); }
		~OLEInitializer(void) { OleUninitialize(); }
};

OLEInitializer g_OLEInitializer; // level-2 1.001: initializer 0x0072F4A0, destructor 0x0072F4C0
Wstring g_Motd; // level-2 1.001: 0x00B0E3B8, the message of the day
ArrayList<Server> g_Servers; // level-2 1.001: 0x00B0FBD8
ArrayList<Channel> g_UserChannels; // level-2 1.001: 0x00B0E5C8
ArrayList<Channel> g_GameChannelList; // level-2 1.001: 0x00B0EE70
ArrayList<User> g_UserList; // level-2 1.001: 0x00B0FC00
ArrayList<unsigned int> g_ChanListQueue; // level-2 1.001: 0x00B0E880
Dictionary<Wstring, Ladder> g_BattleClansLadderDict(Wstring_Hash); // level-2 1.001: 0x00B0EBE0 (name and order as gibbo101 YR)
Dictionary<Wstring, Ladder> g_WDTLadderDict(Wstring_Hash); // level-2 1.001: 0x00B0E3D0
Dictionary<Wstring, Ladder> g_GeneralLadderDict(Wstring_Hash); // level-2 1.001: 0x00B10060
Dictionary<Wstring, int> g_WDTTeams(Wstring_Hash); // level-2 1.001: 0x00B0E9A0 (no YR highscore dictionary before it)
ArrayList<Wstring> g_WDTTeamLookupQueue; // level-2 1.001: 0x00B0FB20
Dictionary<Wstring, int> g_UserLocales(Wstring_Hash); // level-2 1.001: 0x00B0E890
ArrayList<Wstring> g_UserLocaleLookupQueue; // level-2 1.001: 0x00B0E958
ArrayList<Wstring> g_WDT_NodWinEmphasisSounds; // level-2 1.001: 0x00B0E490, eight WDT sound lists (gibbo101 YR: Nod/GDI win emphasis, territory win and lose sounds); provisional names
ArrayList<Wstring> g_WDT_GDIWinEmphasisSounds; // level-2 1.001: 0x00B0DFE0
ArrayList<Wstring> g_WDT_NodLoseEmphasisSounds; // level-2 1.001: 0x00B0EE90
ArrayList<Wstring> g_WDT_GDILoseEmphasisSounds; // level-2 1.001: 0x00B0E870
ArrayList<Wstring> g_WDT_NodTerritoryWinSounds; // level-2 1.001: 0x00B0E3C0
ArrayList<Wstring> g_WDT_GDITerritoryWinSounds; // level-2 1.001: 0x00B0FBA0
ArrayList<Wstring> g_WDT_NodTerritoryLoseSounds; // level-2 1.001: 0x00B0DFF0
ArrayList<Wstring> g_WDT_GDITerritoryLoseSounds; // level-2 1.001: 0x00B0E720
ArrayList<Wstring> g_BuddyList; // level-2 1.001: 0x00B0E390, the names of the buddies
ArrayList<Wstring> g_BuddyRequests; // level-2 1.001: 0x00B0ED18, the buddies whose status waits to be asked for
ArrayList<Wstring> g_BuddyLadderRequests; // level-2 1.001: 0x00B0FCB0, the buddies whose ladder entry waits to be asked for
Wstring g_BuddyFindName; // level-2 1.001: 0x00B0E3B4, the buddy whose channel was asked for last
Wstring g_SelectedBuddy; // level-2 1.001: 0x00B0F1B4, the name selected in the buddy dialog
Dictionary<Wstring, unsigned int> g_BuddyStatus(Wstring_Hash); // level-2 1.001: 0x00B0ED28, the status of a buddy by name
Dictionary<Wstring, Channel> g_BuddyChannels(Wstring_Hash); // level-2 1.001: 0x00B0E968, the channel a buddy is in, by name
extern int g_SliderMin_7E6B70; // level-2 1.001: 0x007E6B70 (4), provisional name: the two ends of a range a dialog control (message 0x4A6) gets
extern int g_SliderMax_7E6B74; // level-2 1.001: 0x007E6B74 (0xD2)
extern int g_SliderMin_7E6B80; // level-2 1.001: 0x007E6B80 (0x101), as above for a second range
extern int g_SliderMax_7E6B84; // level-2 1.001: 0x007E6B84 (0x1A0)
int g_SliderSpan_B0E950 = g_SliderMax_7E6B74 - g_SliderMin_7E6B70 - 4; // level-2 1.001: 0x00B0E950, provisional name
int g_SliderSpan_B0E5EC = g_SliderMax_7E6B84 - g_SliderMin_7E6B80 - 4; // level-2 1.001: 0x00B0E5EC, provisional name
ArrayList<Wstring> g_PingRequests; // level-2 1.001: 0x00B0EE60, the addresses that wait to be pinged (gibbo101 YR: the match ping request list); provisional name
ArrayList<Wstring> g_PingServers; // level-2 1.001: 0x00B0ED08, the pings that wait for an answer: Wstring elements (its destructor destroys 4-byte Wstrings), not Server
Wstring g_MatchOpponentName; // level-2 1.001: 0x00B0EE58, provisional name (used by the match code near Set_Match_State)
Wstring g_GameString_B0F1BC; // level-2 1.001: 0x00B0F1BC, provisional name; the next eight are read by the game channel join code
Wstring g_GameString_B0E408; // level-2 1.001: 0x00B0E408, provisional name
Wstring g_GameString_B0E7BC; // level-2 1.001: 0x00B0E7BC, provisional name
Wstring g_GameString_B0ECA4; // level-2 1.001: 0x00B0ECA4, provisional name
Wstring g_GameString_B0FB18; // level-2 1.001: 0x00B0FB18, provisional name
Wstring g_GameString_B0FBF0; // level-2 1.001: 0x00B0FBF0, provisional name
Wstring g_GameString_B0FBF8; // level-2 1.001: 0x00B0FBF8, provisional name
Wstring g_GameString_B0E94C; // level-2 1.001: 0x00B0E94C, provisional name
Wstring g_UnusedString_B0EC9C; // level-2 1.001: 0x00B0EC9C, provisional name; only its initializer and destructor refer to it
rc_ptr<PlayerProfile> g_PlayerProfile; // level-2 1.001: 0x00B0E5F8, set by Reset_WOL_Globals

void Spaces_To_Underscores(char * text) // RA2: 0x0073C040, turns every space of the text into an underscore, nothing calls it
{
	for (char * space = strchr(text, ' '); space != NULL; space = strchr(space, ' ')) { // RA2: as above
		*space = '_';
	}
}

bool Is_User_Message_Shown(User const * user) // RA2: 0x0073C070, a message from this user shows when the user is an operator, a lobby dialog is open or Latin text is allowed
{
	if (!user) return(false); // RA2: as above
	if (user->flags & 1) return(true); // RA2: as above
	if (WS_Find_Dialog(0xC2)) return(true); // RA2: as above
	if (WS_Find_Dialog(0xC9)) return(true); // RA2: as above
	return g_DisplayLatin != 0; // RA2: as above
}

bool Is_Text_Shown(unsigned char const * flags, WideWstring const & text) // RA2: 0x0073C0B0, as Is_User_Message_Shown but with the first byte of a user record, and the Asian setting for text above 0xFF
{
	if (flags == NULL) { // RA2: as above
		return(false);
	}
	if (*flags & 1) { // RA2: as above
		return(true);
	}
	if (WS_Find_Dialog(0xC2) != NULL) { // RA2: as above
		return(true);
	}
	if (WS_Find_Dialog(0xC9) != NULL) { // RA2: as above
		return(true);
	}
	if (text.Is_Narrow()) { // RA2: as above
		return(g_DisplayLatin != 0); // RA2: as above
	}
	return(g_DisplayAsian != 0); // RA2: as above
}

bool Wait_Callback_Thunk(void) // RA2: 0x0073C120, a jump to WOL_Wait_Callback (the message box callback)
{
	return(WOL_Wait_Callback()); // RA2: as above
}

//	SKU, reported to WOLAPI for the purpose of finding patches.
IPXAddressClass User_To_IPX_Address(User const * user) // RA2: 0x0073C130, the address of a user from its IP: net 0, the IP in the first four node bytes
{
	NetNumType net; // RA2: as above
	NetNodeType node; // RA2: as above
	memset(net, 0, sizeof(net)); // RA2: as above
	memset(node, 0, sizeof(node)); // RA2: as above
	unsigned long ip = ntohl(user->ipaddr); // RA2: as above
	node[3] = (unsigned char)ip; // RA2: as above
	node[2] = (unsigned char)(ip >> 8); // RA2: as above
	node[1] = (unsigned char)(ip >> 16); // RA2: as above
	node[0] = (unsigned char)(ip >> 24); // RA2: as above
	IPXAddressClass address(net, node); // RA2: as above // level-2 1.001: the two-argument constructor 0x522980 (no port)
	return(address); // RA2: as above
}

void Set_Lobby_Music(bool online) // RA2: 0x0073C1B0, restarts the lobby score (theme -2) or queues theme -3
{
	if (online) { // RA2: as above
		if (!Theme.Still_Playing()) { // RA2: as above
			Theme.Stop();
			Theme.Queue_Song((ThemeType)-2); // RA2: as above
			return;
		}
		if (Theme.What_Is_Playing() == Theme.From_Name("INTRO")) { // RA2: as above
			Theme.Stop();
			Theme.Queue_Song((ThemeType)-2); // RA2: as above
		}
	} else {
		Theme.Queue_Song((ThemeType)-3); // RA2: as above
	}
}

// RA2: the four values of the match state are set together (0x0073D150 and the quick match start 0x00759E20 inline this)
void Set_Match_State(int state, int timeout, int result); // level-2 1.001: an ordinary function, defined at its own place near the end of the file (0x00747ED0)

/// <summary>
/// Opens the Find Page dialog, waits for it to close, then restores the input-ignore flag
/// and forces the tactical map to fully redraw.
/// </summary>
void DoFindPage(void) // RA2: 0x0073C230, dialog 0xCF is opened by OwnerDraw::Begin_Dialog and the lobby is redrawn after it
{
	HWND dlg = OwnerDraw::Begin_Dialog(0xCF, (DLGPROC)WOL_Find_Page_Dialog_Proc, 0); // RA2: as above
	IgnoreInput = true;
	Keyboard->Clear();
	ShowWindow(dlg, SW_NORMAL);
	WS_Wait_Dialog(dlg, OwnerDraw::Dialog_Message_Handler, false, true, true); // RA2: as above
	Keyboard->Clear();
	IgnoreInput = Scen->IsInputLocked;
	Map.Flag_To_Redraw(GS_REDRAW_ALL);
}

/// <summary>
/// Searches the global user list for an entry whose name matches the given name
/// case-insensitively.
/// </summary>
/// <param name="name">Name to search for.</param>
/// <returns>Index of the matching user in g_UserList, or -1 if no user was found.</returns>
void Open_Tournament_Page(void) // RA2: 0x0073C2A0, a jump to ViewHTML with the tournament page
{
	ViewHTML("http://www.westwood.com/westwoodonline/tournaments/redalert2/", 0); // RA2: as above
}

void Open_Registration_Page(void) // RA2: 0x0073C2B0, the registration page for the language code
{
	char url[256];
	sprintf(url, "http://games2.westwood.com/cgi-bin/cgiclient?register&request=reg_menu&LANGCODE=%d", g_LanguageCode); // RA2: as above
	ViewHTML(url, 0);
}

int Player_Name_To_Index(Wstring const & name) // RA2: 0x0073C2E0, the name is a Wstring
{
	int i;
	User * user = 0;
	for (i = 0; i < g_UserList.length(); i++) {
		g_UserList.getPointer(&user, i);
		if (stricmp(name.text(), (char *)user->name) == 0) { // RA2: as above
			return(i);
		}
	}
	return(-1);
}

bool Is_Channel_Tournament(Channel const * channel) // RA2: 0x0073C340, only in an Internet game: the tournament flag or channel flag 8
{
	if (Session.Type != GAME_INTERNET) return(false); // RA2: as above
	return(channel->tournament || Is_Channel_Flag_8(channel)); // RA2: as above
}

bool Is_Current_Channel_Tournament(void) // RA2: 0x0073C370, the same test of the current channel
{
	return(Is_Channel_Tournament(&g_CurrentChannel)); // RA2: as above
}

bool Is_Current_Channel_Flag_8(void) // RA2: 0x0073C3A0, channel flag 8 of the current channel
{
	return(Is_Channel_Flag_8(&g_CurrentChannel)); // RA2: as above
}

bool Is_Channel_Flag_8(Channel const * channel) // RA2: 0x0073C3C0, only in an Internet game: bit 8 of the channel's reserved word
{
	if (Session.Type != GAME_INTERNET) return(false); // RA2: as above
	return((channel->reserved >> 8) & 1); // RA2: as above
}

bool Is_Channel_Flag_11(Channel const * channel) // RA2: 0x0073C3E0, as above for bit 11
{
	if (Session.Type != GAME_INTERNET) return(false); // RA2: as above
	return((channel->reserved >> 11) & 1); // RA2: as above
}

bool Is_Channel_Flag_12(Channel const * channel) // RA2: 0x0073C400, as above for bit 12
{
	if (Session.Type != GAME_INTERNET) return(false); // RA2: as above
	return((channel->reserved >> 12) & 1); // RA2: as above
}

Wstring g_NickName; // RA2: a Wstring, the persona of the login (0x0073C420 constructs it)
Wstring g_LoginPassword; // RA2: a Wstring, the password of the login (0x0073C450 constructs it)

void Send_Player_List(void) // RA2: 0x0073C480, sends the names of the eight slots (the lobby entry names for open and AI slots) as game option L
{
	char text[256];
	strcpy(text, "L"); // RA2: as above
	for (int i = 0; i < 8; ++i) { // RA2: as above
		NodeNameType * entry = Session.Slots[i]; // RA2: as above
		Wstring name;
		if (Is_Real_Player_Entry(entry)) { // RA2: as above
			name = Wstring_Narrow(entry->Name); // RA2: as above
		} else {
			name = Lobby_Entry_Name(entry); // RA2: as above
		}
		strncat(text, name.get(), 256); // RA2: as above
		strncat(text, ",", 256); // RA2: as above
	}
	g_pChat->RequestPublicGameOptions(text); // RA2: as above
}

/// <summary>
/// Displays a web page in the player's own browser.
/// This routine hands the page to whatever program the system has registered for HTML and
/// then waits on it, pumping the wait callback throughout so the Westwood Online connection
/// does not lapse while the player reads. The game window is brought back to the front once
/// the browser is finished with. If no browser is installed the player is told so.
/// </summary>
/// <param name="name">URL or page name passed to the browser as the "[open]" argument.</param>
/// <param name="no_ask">Should the browser be launched without asking the player first?</param>
void ViewHTML(const char * name, int no_ask) // RA2: 0x0073C580, the launch and the missing browser texts come from the string table
{
	/*
	 * Create a throwaway HTML file so FindExecutable can tell us which browser handles it.
	 */
	char filename[160];
	tmpnam(filename);
	strcat(filename, ".html");

	FILE * file = fopen(filename, "w");
	fprintf(file, "<title>Hi there.</title>");
	fclose(file);

	char exeName[MAX_PATH + 1];
	int result = (int)FindExecutable(filename, NULL, exeName);

	_unlink(filename);

	/// Ask the user for confirmation (unless no_ask forces an immediate launch), then spawn the browser.
	if (result > 32) { // RA2: as above
		if (!no_ask && ODMessageBox(StringTable::LoadString("TXT_LAUNCHBROWSER", NULL, "C:\\RA2\\wonline.cpp", 1004), MB_YESNO, Wait_Callback_Thunk, false) != IDYES) { // RA2: as above // level-2 1.001: line literal
			return;
		}

		char commandLine[MAX_PATH + 10];
		sprintf(commandLine, "[open] %s", name);
		
		STARTUPINFO startupInfo;
		memset(&startupInfo, 0, sizeof(startupInfo));
		startupInfo.cb = sizeof(startupInfo);

		PROCESS_INFORMATION processInfo;

		BOOL createSuccess = CreateProcess(exeName, commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo); // RA2: as above

		if (createSuccess) {
			HANDLE process = processInfo.hProcess;
			if (process) {
				int done_waiting = FALSE;

				WOL_Wait_Callback();

				WaitForInputIdle(process, 5000);

				/// Wait for the browser to exit, or for the game window to regain focus.
				do {
					WOL_Wait_Callback();
					Sleep(500);

					DWORD exitCode;
					GetExitCodeProcess(process, &exitCode);
					if (exitCode != STILL_ACTIVE) {
						done_waiting = TRUE;
					}

					if (GameInFocus || GetTopWindow(NULL) == MainWindow || GetForegroundWindow() == MainWindow) {
						done_waiting = TRUE;
					}
					WOL_Wait_Callback();
				} while (!done_waiting); // RA2: as above

				/*
				 * Bring the game window back to the foreground now that the browser is done.
				 */
				WOL_Wait_Callback();
	
				if (GetTopWindow(NULL) != MainWindow) {
					WOL_Wait_Callback();
					SetForegroundWindow(MainWindow);
					ShowWindow(MainWindow, SW_RESTORE);
					WOL_Wait_Callback();
				}

				int waits = 10;
				while (waits) {
					Sleep(100);
					WOL_Wait_Callback();
					waits--;
				}
			}
		}
	} else {
		/*
		 * No handler found for this file type -- tell the user there's no browser installed.
		 */
		ODMessageBox(StringTable::LoadString("TXT_NOBROWSER", NULL, "C:\\RA2\\wonline.cpp", 1072), MB_OK, Wait_Callback_Thunk, false); // RA2: as above // level-2 1.001: line literal
	}
}

/// <summary>
/// Determines the sort order of two channel users.
/// Channel owners come first, then users with voice, then everyone else; equals are listed
/// alphabetically. This is the order the user list box is kept in.
/// </summary>
/// <returns>Returns with a negative value if the u1 user sorts first, a positive value if
/// the u2 one does, and zero if the two cannot be told apart.</returns>
void Read_WOL_Settings(void) // RA2: 0x0073C7C0, two more settings than TibSun (DisplayAsian, DisplayLatin) and the observer mode
{
	g_AllowPage = ConfigINI.Get_Int("WOnline", "AllowPage", TRUE);
	g_AllowFind = ConfigINI.Get_Int("WOnline", "AllowFind", TRUE);
	g_LangFilter = ConfigINI.Get_Int("WOnline", "LangFilter", TRUE);
	g_LobbyMusic = ConfigINI.Get_Int("WOnline", "LobMusic", TRUE);
	g_ShowAllChannels = ConfigINI.Get_Int("WOnline", "ShowAll", TRUE);
	// level-2 1.001: no DisplayAsian/DisplayLatin settings and no observer mode (1.006 additions)
}

/// <summary>
/// Writes the current WOL lobby settings (paging, finding, language filter, lobby music,
/// show-all) to the config INI and saves it to disk.
/// </summary>
void Write_WOL_Settings(void) // RA2: 0x0073C890, the file is RA2.INI, as above
{
	RawFileClass file("RA2.INI"); // RA2: as above
	ConfigINI.Put_Int("WOnline", "AllowPage", g_AllowPage);
	ConfigINI.Put_Int("WOnline", "AllowFind", g_AllowFind);
	ConfigINI.Put_Int("WOnline", "LangFilter", g_LangFilter);
	ConfigINI.Put_Int("WOnline", "LobMusic", g_LobbyMusic);
	ConfigINI.Put_Int("WOnline", "ShowAll", g_ShowAllChannels);
	// level-2 1.001: no DisplayAsian/DisplayLatin settings (1.006 additions)
	ConfigINI.Save(file, false);
	// level-2 1.001: no observer mode (1.006 addition)
}

/// <summary>
/// Applies the current WOL settings to the active chat session: pushes the language filter
/// and find/page flags to the chat client, and starts, continues, or fades out the lobby
/// music depending on the LobMusic setting.
/// </summary>
void Apply_WOL_Settings(void) // RA2: 0x0073C990, the observer buttons are updated and the lobby music is queued as in Set_Lobby_Music
{
	if (g_pChat) {
		g_pChat->SetLangFilter(g_LangFilter);
		g_pChat->SetFindPage(g_AllowFind, g_AllowPage);
	}
	// level-2 1.001: no observer buttons (1.006 addition)

		/// Manage the lobby music according to the LobMusic setting.
	bool music = g_LobbyMusic != 0; // RA2: as above
	if (music && !Theme.Still_Playing()) { // RA2: as above
		Theme.Stop();
		Theme.Queue_Song((ThemeType)-2); // RA2: as above
	} else if (music) { // RA2: as above
		if (Theme.What_Is_Playing() == Theme.From_Name("INTRO")) { // RA2: as above
			Theme.Stop();
			Theme.Queue_Song((ThemeType)-2); // RA2: as above
		}
	} else if (!music) { // RA2: as above
		Theme.Queue_Song((ThemeType)-3); // RA2: as above
	}
}

/// <summary>
/// Sends a chat message on the player's behalf.
/// The message goes privately to whoever is selected in the user list box, or out to the
/// whole channel when nothing is selected.
/// </summary>
/// <param name="msg">Text of the message to send.</param>
/// <returns>Returns with 0 if the message went to the whole channel, or 1 if it went
/// privately to the selected users.</returns>
int Send_Chat_Message(WideWstring const & msg) // RA2: 0x0073CA50, the text is wide and goes through the wide IChat calls
{
	static int sel_user_indexes[128];
	HWND users = GetDlgItem(WS_Top_Window(), IDC_USERS);
	int count = ListBox_GetSelItems(users, (WPARAM)32, (LPARAM)sel_user_indexes);

	if (count == 0) {
		/*
		 * No users selected -- broadcast to the whole channel.
		 */
		g_pChat->RequestPublicMessageWide((unsigned short const *)msg.text()); // RA2: as above
		return(0);
	} else {
		/*
		 * Build a linked list of the selected users and send them a private message.
		 */
		User * last = NULL;
		User * head = NULL;
		User * item = NULL;
		User source;
		memset(&source, 0, sizeof(source));
		for (int i = 0; i < count; i++) {
			g_UserList.get(source, sel_user_indexes[i]);
			item = new User;
			*item = source;
			item->next = NULL;
			if (i == 0) head = item;
			if (last) last->next = item;
			last = item;
		}

		if (head) g_pChat->RequestPrivateMessageWide(head, (unsigned short const *)msg.text()); // RA2: as above

		/// Free the temporary user list.
		while (head) {
			item = head;
			head = head->next;
			delete (item);
		}
		return(1);
	}
}

/// <summary>
/// Sends a chat action on the player's behalf.
/// The action goes privately to whoever is selected in the user list box, or out to the
/// whole channel when nothing is selected.
/// </summary>
/// <param name="msg">Text of the action to send.</param>
/// <returns>Returns with 0 if the action went to the whole channel, or 1 if it went
/// privately to the selected users.</returns>
int Send_Chat_Action(WideWstring const & msg) // RA2: 0x0073CB80, as above
{
	static int sel_user_indexes[128];
	HWND users = GetDlgItem(WS_Top_Window(), IDC_USERS);
	int count = ListBox_GetSelItems(users, (WPARAM)32, (LPARAM)sel_user_indexes);

	if (count == 0) {
		/*
		 * No users selected -- broadcast to the whole channel.
		 */
		g_pChat->RequestPublicActionWide((unsigned short const *)msg.text()); // RA2: as above
		return(0);
	} else {
		/*
		 * Build a linked list of the selected users and send them a private action.
		 */
		User * last = NULL;
		User * head = NULL;
		User * item = NULL;
		User source;
		memset(&source, 0, sizeof(source));
		for (int i = 0; i < count; i++) {
			g_UserList.get(source, sel_user_indexes[i]);
			item = new User;
			*item = source;
			item->next = NULL;
			if (i == 0) head = item;
			if (last) last->next = item;
			last = item;
		}

		if (head) g_pChat->RequestPrivateActionWide(head, (unsigned short const *)msg.text()); // RA2: as above

		/// Free the temporary user list.
		while (head) {
			item = head;
			head = head->next;
			delete (item);
		}
		return(1);
	}
}

static inline bool Same_Player_Name(wchar_t const * first, wchar_t const * second) // RA2: the inline compare of two lobby names (case insensitive, as narrow text)
{
	char * name = Wide_To_Narrow(first); // RA2: as above
	return(stricmp(name, Wide_To_Narrow(second)) == 0); // RA2: as above
}

/// <summary>
/// Encodes the current game options and scenario info, followed by each user's name,
/// house, and color, into a single comma-separated string for transmission over WOL.
/// </summary>
/// <param name="out">Buffer that receives the encoded options string.</param>
void Encode_Game_Options(char * out) // RA2: 0x0073CCB0, RA2's option text: seed, speed, credits, units, switches, mode, map name, scenario, then the players and the computer players
{
	static char useroptions[512];

	Wstring name = Session.Options.ScenarioDescription ? Wstring_FromWide(Session.Options.ScenarioDescription) : ""; // RA2: only the 7 bit characters of the map name are sent
	int value = Session.ScenarioMaxPlayers; // level-2 1.001: read into a local first, as in netdlg2.cpp Net2EncodeGameopt

	/// Encode the game options and scenario info.
	sprintf(out, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s,%d,%d,%d,%s,%s:", // RA2: as above
			Seed, Options.GameSpeed, Session.Options.GameSpeed, Session.Options.Credits, Session.Options.UnitCount, // RA2: as above
			Session.Options.ShortGame, Session.Options.SWAllowed, Session.Options.BuildOffAlly, Session.Options.MCVRedeploy, // RA2: as above
			Session.Options.Goodies, Session.Options.MPModeIndex, name.get(), value, Session.ScenarioIsOfficial, // RA2: as above
			Session.ScenarioFileLength, Session.ScenarioFileName, Session.ScenarioDigest); // RA2: as above

	/*
	 * Append each user's name, house, and color.
	 * Append each user's name, country, color, address, port and ping.
	 */
	memset(useroptions, 0, sizeof(useroptions));
	for (int i = 0, count = Session.Players.Count(); i < count; i++) { // RA2: as above
		NodeNameType * entry = Session.Players[i]; // RA2: as above
		int country = entry->Get_Country(); // RA2: as above
		int color = entry->Get_Color(); // RA2: as above
		Wstring text(Wstring_Narrow(Session.Players[i]->Name)); // RA2: as above
		sprintf(useroptions + strlen(useroptions), "%s,%d,%d,", text.get(), country, color); // level-2 1.001: only the name, country and color (no address, port or ping)
	}
	useroptions[strlen(useroptions) - 1] = ':'; // RA2: as above
	strcat(useroptions, "@:"); // RA2: as above

	/// Append the computer players.
	for (int k = 0; k < 8; k++) { // RA2: as above
		sprintf(useroptions + strlen(useroptions), "%d,%d,%d,", Session.Options.AISlots.Difficulties[k], Session.Options.AISlots.Countries[k], Session.Options.AISlots.Colors[k]); // RA2: as above
	}

	strcat(out, useroptions);
}

/// <summary>
/// Combines the rules, AI, and art CRCs into a single hash used to verify that all players
/// are running matching game data.
/// </summary>
/// <returns>Combined CRC hash.</returns>
int GetINIHash(void) // RA2: 0x0073CFD0
{
	return(g_RuleCRC ^ g_AICRC ^ g_ArtCRC);
}

/// <summary>
/// Encodes extended game/session info -- build number, data hash, options, and a flag
/// describing which house(s) still have room -- into a comma-separated string for
/// transmission over WOL.
/// </summary>
/// <param name="out">Buffer that receives the encoded info string.</param>
void Encode_Channel_ExInfo(char * out) // RA2: 0x0073CFF0, RA2's info text: build, hash, computer players, observer slot state, scenario file
{
	int i = 0;
	int house1_count = 0;
	int house0_count = 0;

	/// Count how many users are currently on each house.
	for (int j = 0; j < (int)g_CurrentChannel.currentUsers; j++) {
		int house = g_UserInfo[j].house;
		if (house == 0) {
			house0_count++;
		} else if (house == 1) { // RA2: as above
			house1_count++;
		}
	}

	/// Flag which house(s) still have free slots.
	if (house1_count < (int)g_CurrentChannel.maxUsers / 2) {
		i = 2;
	}

	if (house0_count < (int)g_CurrentChannel.maxUsers / 2) {
		i++;
	}

	sprintf(out, "%d,%d,%d", Build_Number(), GetINIHash(), Count_AI_Slots()); // RA2: as above // level-2 1.001: no observer fields and no scenario file name
}

/// <summary>
/// Records whether the given user (or the local player if who is NULL) has accepted an
/// invitation/request, then refreshes the user list display.
/// </summary>
/// <param name="who">Name of the user to update, or NULL for the local player.</param>
void Parse_Channel_ExInfo(char * text, int * build, int * hash, int * ai_count) // RA2: 0x0073D070, the counterpart of Encode_Channel_ExInfo // level-2 1.001: 0x332010, three fields only
{
	char * token = strtok(text, ","); // RA2: as above
	*build = token != NULL ? atol(token) : 0;
	token = strtok(NULL, ",");
	*hash = token != NULL ? atol(token) : 0;
	token = strtok(NULL, ",");
	*ai_count = token != NULL ? atol(token) : 0;
	// level-2 1.001: no observer, not-full and scenario fields (1.006 additions)
}



/// <summary>
/// Records whether the given user (or the local player if who is empty) has accepted the game
/// options, then refreshes the user list display. When the host is waiting for the only other
/// player of a two player game and that player has accepted, the game is started.
/// </summary>
/// <param name="who">Name of the user to update, empty for the local player.</param>
/// <param name="status">New accepted status to store.</param>
void SetPlayerAccepted(Wstring const & who, int status) // RA2: 0x0073D150, the name is a Wstring and the host starts a two player game when the guest accepts
{
	Wstring const nick(who.length() > 0 ? who : g_NickName); // RA2: as above
	if (nick == g_NickName && status == 0) { // RA2: as above
		HWND dialog = WS_Find_Dialog(201); // RA2: as above
		Enable_Player_Combos(dialog, true); // RA2: as above
	}

	User * user = 0;
	for (int index = 0; index < g_UserList.length(); ++index) { // RA2: as above
		g_UserList.getPointer(&user, index); // RA2: as above
		if (stricmp(nick.text(), (char *)user->name) == 0) { // RA2: as above
			if (index != -1) {
				g_UserInfo[index].accepted = status; // RA2: as above
				Draw_Player_List(0, false); // RA2: as above
			}
			break;
		}
	}

	bool local = g_IsChannelCreator == 1; // RA2: as above
	Wstring const lower = nick.toLower(); // RA2: as above
	int player_index; // RA2: as above
	for (player_index = 0; player_index < Session.Players.Count(); ++player_index) { // RA2: as above
		Wstring const player = Wstring_Narrow(Session.Players[player_index]->Name); // RA2: as above
		if (player.toLower() == lower) break; // RA2: as above
	}
	if (player_index >= Session.Players.Count()) return; // RA2: as above
	Session.Players[player_index]->Slot.Unknown77 = status; // RA2: as above

	if (local && (Online_Session_State == 2 || Online_Session_State == 1) && !g_GameStartRequested && player_index == 1 && g_UserList.length() == 2) { // RA2: as above
		User * node; // RA2: as above
		User * head = 0; // RA2: as above
		User copy; // RA2: as above
		memset(&copy, 0, sizeof(copy)); // RA2: as above
		for (int user_index = 0; user_index < g_UserList.length(); ++user_index) { // RA2: as above
			g_UserList.get(copy, user_index); // RA2: as above
			node = new User; // RA2: as above
			*node = copy;
			node->next = head; // RA2: as above
			head = node; // RA2: as above
		}
		Set_Match_State(9, 90, 0); // RA2: as above
		g_pChat->RequestGameStart(head);
		g_GameStartRequested = true;
		node = head; // RA2: as above
		while (node) { // RA2: as above
			head = node->next; // RA2: as above
			delete node; // RA2: as above
			node = head; // RA2: as above
		}
	}
	Draw_Player_List(0, false); // RA2: as above
}

/// <summary>
/// Looks up whether the given user (or the local player if who is NULL) has accepted an
/// invitation/request.
/// </summary>
/// <param name="who">Name of the user to query, or NULL for the local player.</param>
/// <returns>The user's accepted status, or -1 if the user could not be found.</returns>
int GetPlayerAccepted(Wstring const & who) // RA2: 0x0073D3F0, the name is a Wstring and the answer is the player slot's status
{
	Wstring const nick(who.length() > 0 ? who : g_NickName); // RA2: as above
	Wstring const lower = nick.toLower(); // RA2: as above
	if (Wstring_ToWide(lower) == static_cast<WideWstring const &>(WideWstring(Session.GameName)).toLower()) { // RA2: as above
		return(1);
	}
	int found = -1; // RA2: as above
	for (int index = 0; index < Session.Players.Count(); index++) { // RA2: as above
		Wstring const player = Wstring_Narrow(Session.Players[index]->Name); // RA2: as above
		if (player.toLower() == lower) found = index; // RA2: as above
	}
	if (found != -1) { // RA2: as above
		return(Session.Players[found]->Slot.Unknown77); // RA2: as above
	}
	return(-1);
}

/// <summary>
/// Leaves the current channel (waiting for the leave to complete) and joins the lobby channel
/// selected by Pick_Lobby.
/// </summary>
/// <returns>The index of the joined lobby channel, or -1 if the leave timed out, the join
/// failed, or no lobby was available.</returns>
/// <param name="who">Name of the player whose country/color changed.</param>
/// <param name="house">New country selection.</param>
/// <param name="color">New color selection.</param>
/// <returns>1 if the player's country actually changed, 0 otherwise.</returns>
int Assign_House_And_Color(Wstring const & who, int house, int color) // RA2: 0x0073D550, works on the lobby slots and fills the side and color boxes for the observer
{
	int found = -1; // RA2: as above
	Wstring const lower = who.toLower(); // RA2: as above
	for (int index = 0; index < 8; ++index) { // RA2: as above
		Wstring const player_name = Wstring_Narrow(Session.Slots[index]->Name); // RA2: as above
		if (lower == player_name.toLower()) { // RA2: as above
			found = index; // RA2: as above
			break;
		}
	}
	int changed = 0; // RA2: as above
	if (found == -1) return(changed); // RA2: as above

	HWND window = WS_Find_Dialog(0xC2); // RA2: as above
	if (!window) window = WS_Find_Dialog(0xC9); // RA2: as above
	NodeNameType * player = Session.Slots[found]; // RA2: as above
	if (player->Get_Country() != house) { // RA2: as above
		changed = 1; // RA2: as above
		player->Set_Country(house); // RA2: as above // level-2 1.001: no observer handling, the dialog boxes are not touched
	}
	if (Session.Slots[found]->Get_Color() != color) player->Set_Color(color); // RA2: as above // level-2 1.001: no preferred color update
	Draw_Player_List(0, false); // RA2: as above
	return(changed); // RA2: as above
}

/// <summary>
/// Fills a login dialog in from a remembered login.
/// This routine is used to spare the player from retyping credentials. If the nickname is
/// one Westwood Online has kept, its password and locale are recalled into the dialog's
/// controls along with it; if it is not, the dialog is left as it was.
/// </summary>
/// <param name="name">Nickname to search for among the stored logins, or NULL to skip
/// the lookup.</param>
/// Most names are exposed by debug prints in RA2, rest guessed
enum {
	EV_ABORT,
	EV_GOT_SERVERS,
	EV_CONNECTED,
	EV_CHAN_LIST,
	EV_CHAN_JOINED,
	EV_ERROR,
	EV_EXIT,
	EV_STARTGAME,
	EV_QUITGAME,
	EV_NETIGNORE,
	EV_CHAN_JOIN_FAIL,
	EV_11, // continue waiting?
	EV_12,
	EV_13,
	EV_LOCALE,
	EV_SKIRMISH,
	EV_16, // RA2: as above
	EV_17, // RA2: as above
	EV_COUNT,
};

/// <summary>
/// Saves a login's nickname, password, and locale into one of the 32 stored login slots.
/// Reuses whichever slot already stores this nickname if one exists, otherwise the first
/// empty slot, otherwise cycles to the slot after the session's last-used nickname slot.
/// </summary>
/// <param name="loginName">Nickname to store.</param>
/// <param name="password">Password to store alongside the nickname.</param>
/// <param name="passwordPlaintext">Whether the password is stored/sent as plaintext.</param>
/// <param name="locale">Locale value to associate with this login.</param>
/// <returns>The result of setting the nick's locale (from SetNickLocale), or the computed
/// slot number if no slot ended up being written to.</returns>
/// <param name="channel_type">0 for the chat channels, 0x21 for the game channels.</param>
/// <param name="autoping">Should the server ping the channels?</param>
/// <returns>True if the request was sent.</returns>
bool Request_Channel_List(int channel_type, unsigned char autoping) // RA2: 0x0073D760, not in TibSun: the request and its queue entry in one place
{
	unsigned int type = channel_type; // level-2 1.001: the queue entry is taken first (Get_Channel_List stores it before the request)
	if (g_pChat->RequestChannelList(-99999, autoping) != S_OK) { // level-2 1.001: no debug text (its string is absent); the request always passes the fixed type -99999 (push 0xFFFE7961)
		return(false);
	}
	g_ChanListQueue.addTail(type);
	return(true);
}

// level-2 1.001: the request, its queue entry and the wait are one function (the executable's own debug text names it Get_Channel_List); 1.006 split it into Wait_Channel_List, Queue_Channel_List_Request and the two callers below
bool Get_Channel_List(int channel_type, unsigned char autoping) // level-2 1.001: 0x332730
{
	{
		WideWstring title(StringTable::LoadString("TXT_REQ_CHANLIST", NULL, "C:\\RA2\\wonline.cpp", 1794)); // RA2: as above // level-2 1.001: line literal
		Show_Wait_Window(1, title, false); // RA2: as above
	}
	Reset_Wait_Events(); // level-2 1.001: every wait event is cleared before the request
	if (!Request_Channel_List(channel_type, autoping)) { // level-2 1.001: expanded here (its ArrayList::add stays out of line)
		SetEvent(g_WaitEventHandles[EV_ABORT]);
		Close_Wait_Window(1); // RA2: as above
		return(false);
	}
	int elapsed = 0; // RA2: as above
	for (;;) { // RA2: as above
		DWORD event = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100); // RA2: as above
		while (event == WAIT_TIMEOUT) { // RA2: as above
			elapsed += 100; // RA2: as above
			if (elapsed > 30000) { // RA2: as above
				swprintf(g_LastErrorMessage, StringTable::LoadString("TXT_CANT_CONNECT", NULL, "C:\\RA2\\wonline.cpp", 1811)); // RA2: as above // level-2 1.001: line literal
				SetEvent(g_WaitEventHandles[EV_ABORT]);
				return(false);
			}
			WOL_Wait_Callback();
			event = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100); // RA2: as above
		}
		if (event == WAIT_FAILED) { // RA2: as above
			Close_Wait_Window(1); // RA2: as above
			DebugString("WaitForMultipleObjects() failed in Get_Channel_List\n"); // RA2: as above
			return(false);
		}
		ResetEvent(g_WaitEventHandles[event]); // RA2: as above
		if (event == EV_ERROR) { // RA2: as above
			Close_Wait_Window(1); // RA2: as above
			return(false);
		}
		if (event == EV_ABORT) { // RA2: as above
			Close_Wait_Window(1); // RA2: as above
			break;
		}
		if (event == EV_CHAN_LIST) { // RA2: as above
			Close_Wait_Window(1); // RA2: as above
			return(true);
		}
	}
	return(false);
}

bool Request_Chat_Channel_List(void) // level-2 1.001: 0x332A20, no wait argument: a jump to Get_Channel_List
{
	return(Get_Channel_List(0, 0));
}

bool Request_Game_Channel_List(unsigned char autoping) // level-2 1.001: 0x332A30, as above for the game channels (0x21)
{
	return(Get_Channel_List(0x21, autoping));
}

bool Is_Tournament_Session(void) // RA2: 0x0073BDB0 // level-2 1.001: 0x00730970, the function netshare.cpp calls (0x005BF3AE, 0x005BFC96); expanded at its uses in this file
{
	return(Online_Session_State == 2 || Online_Session_State == 1);
}

bool WOL_Wait_Callback(void) // RA2: 0x0073E100, no channel list requests (TibSun's are gone), the match timeout and the start of the game are RA2's
{
	Title_Screen_Restore(false); // RA2: as above

	static int prev_exinfo = 0;
	static int prev_ping = 0;

	MSG msg;
	int counter = 0;
	MessageLoopCount++; // RA2: as above
	while (Peek_Windows_Message(&msg, NULL, 0, 0, 1)) { // RA2: as above
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		counter++;
		if (counter == 100) break;
	}

	// RA2: a tournament match that waited longer than its timeout is cancelled (states 2 to 5) or given 30 seconds more
	if (Is_Tournament_Session() && g_MatchTimeout != -1 && g_MatchState != 1 && g_MatchState != 0 && g_MatchState != 11 && (unsigned)(time(NULL) - g_MatchStartTime) > (unsigned)g_MatchTimeout) {
		if (g_MatchState >= 2 && g_MatchState <= 5) {
			Set_Match_State(0, -1, 2);
		} else {
			Lobby_Chat_Printf(0x20C0FF, StringTable::LoadString("WOL:MatchTimeout", NULL, "C:\\RA2\\wonline.cpp", 1895)); // level-2 1.001: line literal
			Set_Match_State(2, 30, 0);
		}
		SetEvent(g_WaitEventHandles[EV_ERROR]);
	}

	WS_Top_Window_ID(); // RA2: the result is not used

	if (g_WDTTeamLookupQueue.length() > 200) {
		g_WDTTeamLookupQueue.clear();
	}

	if (g_LastWDTUserTeamRequestTime < (unsigned)time(0) - 2 && g_WDTTeamLookupQueue.length() > 65 ||
		g_LastWDTUserTeamRequestTime < (unsigned)time(0) - 3 && g_WDTTeamLookupQueue.length() > 10 ||
		g_LastWDTUserTeamRequestTime < (unsigned)time(0) - 15 && g_WDTTeamLookupQueue.length() > 0) {

		User * list = NULL;
		User * last_user = NULL;
		for (int i = 0; i < 10; i++) {
			if (g_WDTTeamLookupQueue.length() > 0) {
				User * new_user = new User;
				memset(new_user, 0, sizeof(User));
				Wstring name;
				g_WDTTeamLookupQueue.removeTail(name);
				char * rawName = name.get();
				if (strlen(rawName) > 9) {
					rawName[9] = '\0';
				}
				strcpy((char *)new_user->name, rawName);
				if (last_user == NULL) {
					list = new_user;
				} else {
					last_user->next = new_user;
				}
				last_user = new_user;
			} else {
				break;
			}
		}

		if (g_pChat != NULL) {
			g_pChat->RequestUserTeam(list);
		}

		User * d = list;
		while (d != NULL) {
			User * next = d->next;
			delete d;
			d = next;
		}

		g_LastWDTUserTeamRequestTime = time(0);
	}

	if (g_UserLocaleLookupQueue.length() > 200) {
		g_UserLocaleLookupQueue.clear();
	}

	if (g_LastChannelLocaleRequestTime < (unsigned)time(0) - 2 && g_UserLocaleLookupQueue.length() > 65 ||
		g_LastChannelLocaleRequestTime < (unsigned)time(0) - 3 && g_UserLocaleLookupQueue.length() > 10 ||
		g_LastChannelLocaleRequestTime < (unsigned)time(0) - 15 && g_UserLocaleLookupQueue.length() > 0) {

		User * list = NULL;
		User * last_user = NULL;
		for (int i = 0; i < 10; i++) {
			if (g_UserLocaleLookupQueue.length() > 0) {
				User * new_user = new User;
				memset(new_user, 0, sizeof(User));
				Wstring name;
				g_UserLocaleLookupQueue.removeTail(name);
				char * rawName = name.get();
				if (strlen(rawName) > 9) {
					rawName[9] = '\0';
				}
				strcpy((char *)new_user->name, rawName);
				if (last_user == NULL) {
					list = new_user;
				} else {
					last_user->next = new_user;
				}
				last_user = new_user;
			} else {
				break;
			}
		}

		if (g_pChat != NULL) {
			g_pChat->RequestUserLocale(list);
		}

		User * d = list;
		while (d != NULL) {
			User * next = d->next;
			delete d;
			d = next;
		}

		g_LastChannelLocaleRequestTime = time(0);
	}

	if (Session.Type == GAME_INTERNET && Online_Session_State == 2 && time(0) > g_NextWDTStatePollTime) { // RA2: an Internet tournament session, not TibSun's Session.IsWDT
		g_NextWDTStatePollTime = time(0) + 30;
		Get_WDT_State_Silent();
	}

	if ((g_pChat) && (g_SuspendChatPump == 0)) g_pChat->PumpMessages();
	if (g_pNetUtil) g_pNetUtil->PumpMessages();
	if (g_pDownload) g_pDownload->PumpMessages();

	Call_Back();

	if ((g_CurrentChannel.name[0]) && (g_CurrentChannel.type == 0x21) && (g_IsChannelCreator)) Send_Lobby_Options(false, false); // RA2: for PumpGameopts(false)

	if ((g_pChat != NULL) && (g_CurrentChannel.type != 0) && (g_IsChannelCreator)) {
		if ((time(NULL) - prev_exinfo) > 10) {
			char exinfo_out[80];
			memset(exinfo_out, 0, 80);
			Encode_Channel_ExInfo(exinfo_out);
			exinfo_out[40] = 0;
			g_pChat->SetChannelExInfo(exinfo_out);
			prev_exinfo = time(NULL);
		}
	}

	{ // level-2 1.001: the pings are also asked for once the game is locked in
		if ((g_pChat != NULL) && (g_CurrentChannel.type != 0) && ((time(NULL) - prev_ping) > 10)) {
			User user;
			Wstring nick = ((Wstring const &)g_NickName).toLower(); // RA2: the names are compared as Wstrings, not with stricmp; the const member returns the lower case copy
			int handle;
			int i;
			in_addr addr;

			if (!Is_Tournament_Session()) { // RA2: as above
				for (i = 0; i < g_UserList.length(); i++) {
					g_UserList.get(user, i);
					Wstring const user_name((char *)user.name); // RA2: as above
					if (nick == user_name.toLower()) continue; // RA2: as above
					addr.s_addr = user.ipaddr;
					if (user.ipaddr != 0) g_pNetUtil->RequestPing(inet_ntoa(addr), 1000, &handle);
				}
			}
			prev_ping = time(NULL);
		}
	}

	// level-2 1.001: the game is not started from here
	Handle_Preview_Download();
	return(false);
}

void Reset_WOL_Globals(void) // RA2: 0x0073E8D0, loads the default profile, clears the buddy lists and sets the SKU of the tournament ladder
{
	g_PlayerProfile = PlayerProfile::Load_Default(); // RA2: as above

	g_UserChannels.clear();
	g_GameChannelList.clear();
	g_UserList.clear();

	g_WDTTeamLookupQueue.clear();
	g_WDTTeams.clear();

	g_UserLocaleLookupQueue.clear();
	g_UserLocales.clear();

	g_NextWDTStatePollTime = time(0) + 86400;
	g_LastChannelLocaleRequestTime = 0;
	g_LastWDTUserTeamRequestTime = 0;

	g_BattleClansLadderDict.clear();
	g_WDTLadderDict.clear();
	g_BuddyChannels.clear(); // RA2: as above
	g_BuddyList.clear(); // RA2: as above
	g_BuddyRequests.clear(); // RA2: as above
	g_BuddyStatus.clear(); // RA2: as above

	if (Session.Type == GAME_INTERNET && Online_Session_State == 2) { // RA2: an Internet tournament session, not TibSun's Addon_Enabled(ADDON_FIRESTORM) && Session.IsWDT
		int sku = 0x2300; // RA2: the SKU of the tournament ladder
		g_InstalledLadderSKU = sku;
		g_SelectedLadderSKU = sku;
		g_ActiveLadder = &g_WDTLadderDict;
	} else {
		int sku = g_GameSKU;
		g_InstalledLadderSKU = sku;
		g_SelectedLadderSKU = sku;
		g_ActiveLadder = &g_GeneralLadderDict;
	}

	memset(&g_CurrentChannel, 0, sizeof(g_CurrentChannel));
	memset(&g_PendingChannel, 0, sizeof(g_PendingChannel)); // RA2: as above
	memset(&g_GameServer, 0, sizeof(g_GameServer));
	memset(&g_WDTServer, 0, sizeof(g_WDTServer));

	g_LastErrorMessage[0] = 0;

	g_MatchResult = 0;
	g_MatchState = 1;
	g_MatchTimeout = -1;
	g_MatchStartTime = time(0);

	g_CurrentServerIndex = 0;
	g_TargetServerIndex = 0;

	g_IsChannelCreator = 0;
	g_ActiveWaitFlags = 0;

	g_GameStartRequested = false;

	g_IgnoreNetStatus = false;
	g_ShowMOTD = true;
	g_Motd.clear(); // RA2: as above

	memset(&g_WaitEventHandles, 0, sizeof(g_WaitEventHandles));

	g_PlayingNetGame = false;
	g_ConnectionLost = false;

	g_ServerType = -1;

	g_SuspendChatPump = 0;

	g_LastChatListTime = 0xFFFFFFFF;
	g_LastGameListTime = 0xFFFFFFFF;

	g_Lobbies[0] = StringTable::LoadString("TXT_LOB_1", NULL, "C:\\RA2\\wonline.cpp", 2205); // RA2: as above // level-2 1.001: six lobbies, line literal
	g_Lobbies[1] = StringTable::LoadString("TXT_LOB_2", NULL, "C:\\RA2\\wonline.cpp", 2206); // RA2: as above // level-2 1.001: six lobbies, line literal
	g_Lobbies[2] = StringTable::LoadString("TXT_LOB_3", NULL, "C:\\RA2\\wonline.cpp", 2207); // RA2: as above // level-2 1.001: six lobbies, line literal
	g_Lobbies[3] = StringTable::LoadString("TXT_LOB_4", NULL, "C:\\RA2\\wonline.cpp", 2208); // RA2: as above // level-2 1.001: six lobbies, line literal
	g_Lobbies[4] = StringTable::LoadString("TXT_LOB_5", NULL, "C:\\RA2\\wonline.cpp", 2209); // RA2: as above // level-2 1.001: six lobbies, line literal
	g_Lobbies[5] = StringTable::LoadString("TXT_LOB_6", NULL, "C:\\RA2\\wonline.cpp", 2210); // RA2: as above // level-2 1.001: six lobbies, line literal

	memset(WDT_TERRITORY_LOBBY_INDEXES, 0xFFFFFFFF, sizeof(WDT_TERRITORY_LOBBY_INDEXES));

	g_pChat = NULL;
	g_pNetUtil = NULL;
	g_pDownload = NULL;

	g_dwChatAdvise = 0;
	g_dwNetUtilAdvise = 0;
	g_dwDownloadAdvise = 0;

	g_SquadInfoRequests = 0;
	g_RequestingOwnSquadInfo = 0;
	memset(g_OwnSquadName, 0, 41); // RA2: as above // level-2 1.001: before the squad id
	g_OwnSquadID = 0;

	g_ChannelCount = 0;

	g_LadderPos = 1;

	g_JoinLobbyNow = 0;

	g_ChanListQueue.clear(); // level-2 1.001: called out of line (0x007524D0)

	WolOptionsLocked = 0; // RA2: TibSun's g_GameStarted

	g_UserAge = 0;
	g_UserConsent = 0;

	g_RuleCRC = RulesClass::Get_Rule_Unique_ID();
	RulesClass::Load_Art_INI();
	g_ArtCRC = RulesClass::Get_Art_Unique_ID();
	g_AICRC = RulesClass::Get_AI_Unique_ID();
	// level-2 1.001: ManglerIndex is not reset here
}

void Refresh_Lobby_List(void) // RA2: 0x0073EE80, fills the lobby list of dialog 0x113 with the "Lob_33_" channels in number order, the current one selected
{
	HWND dialog = WS_Find_Dialog(0x113);
	if (!dialog) return; // RA2: as above
	HWND list = GetDlgItem(dialog, 0x53D);
	if (!list) return; // RA2: as above

	Wstring selected; // RA2: the text of the first visible row
	int top_row = SendMessageA(list, LB_GETTOPINDEX, 0, 0); // RA2: the first visible row is kept, not the selected one
	if (top_row != -1) Get_Window_Item_Text(list, top_row, selected);
	SendMessageA(list, OD_DISABLEPAINT, 0, 1);
	Clear_Listbox(list);

	int count = g_UserChannels.length();
	for (int i = 0; i < count; ++i) {
		Channel channel;
		g_UserChannels.get(channel, i);
		if (strncmp((char *)channel.name, "Lob_33_", strlen("Lob_33_")) != 0) continue;
		int number = atol((char *)channel.name + strlen("Lob_33_"));
		bool current = strcmp((char *)channel.name, (char *)g_CurrentChannel.name) == 0;
		wchar_t title[80];
		int page = number / 6; // level-2 1.001: six lobby names
		int name_index = number % 6;
		if (page == 0) {
			swprintf(title, L"%s  (%d)", (wchar_t const *)g_Lobbies[name_index], channel.currentUsers);
		} else {
			swprintf(title, L"%s_%d  (%d)", (wchar_t const *)g_Lobbies[name_index], page + 1, channel.currentUsers);
		}
		int row = SendMessageA(list, OD_ADDSTRING_LIST, 0, (LPARAM)channel.name); // level-2 1.001: appended, not inserted in number order
		SendMessageA(list, LB_SETITEMDATA, row, i);
		OwnerDraw::CellData cell;
		cell.type = OwnerDraw::CellData::TEXT;
		cell.string.set((unsigned short *)title);
		cell.hint.set((unsigned short *)L"");
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_Col_ChanName, row), (LPARAM)&cell);
		if (current) SendMessageA(list, LB_SETCURSEL, row, 0);
	}

	int restored = SendMessageA(list, OD_FINDSTRING, 0, (LPARAM)selected.text());
	if (restored != -1) SendMessageA(list, LB_SETTOPINDEX, restored, 0);
	SendMessageA(list, OD_DISABLEPAINT, 0, 0);
	InvalidateRect(list, NULL, false);
}

WideWstring Get_Locale_Name(int locale) // RA2: 0x0073F1C0, the localized name of a locale number, from the string "WOL:Locale" and the number in two digits
{
	Wstring label = "WOL:Locale" + Wstring_FromInt(locale, 2); // RA2: as above
	WideWstring text(StringTable::LoadString(label.get(), NULL, "C:\\RA2\\wonline.cpp", 2345)); // RA2: as above // level-2 1.001: line literal
	if (locale < 37) { // RA2: both ways return the same text, the test is kept
		return(text);
	} else {
		return(text);
	}
}

WideWstring User_Tooltip(User const & user) // RA2: 0x0073F250, the text of the tooltip of a lobby user: name, rank in the active ladder, squad and locale
{
	Wstring name((char *)user.name); // RA2: as above
	WideWstring text = Wstring_ToWide(name) + L" : "; // RA2: as above
	name.toLower();
	Ladder ladder;
	memset(&ladder, 0, sizeof(ladder));
	if (g_ActiveLadder && g_ActiveLadder->getValue(name, ladder)) { // RA2: as above
		text += WideWstring(StringTable::LoadString("TXT_RANK", NULL, "C:\\RA2\\wonline.cpp", 2373)) + WideWstring(L" ") + WideWstring_FromInt(ladder.rung); // RA2: as above // level-2 1.001: line literal
	} else {
		text += StringTable::LoadString("TXT_UNRANKED", NULL, "C:\\RA2\\wonline.cpp", 2375); // RA2: as above // level-2 1.001: line literal
	}
	Wstring squad((char *)user.squadname); // RA2: as above
	if (squad.length() == 0) squad = (char *)user.squadabbrev; // RA2: the abbreviation stands for a squad without a name
	if (squad.length() > 0) {
		text += L": " + Wstring_ToWide(squad); // RA2: as above
	}
	if (g_UserLocales.contains(name)) { // RA2: as above
		int * locale = 0;
		if (g_pChat && g_UserLocales.getPointer(name, &locale) && locale && *locale) { // RA2: as above
			text += L" : " + Get_Locale_Name(*locale); // RA2: as above
		}
	}
	return(text);
}

WideWstring Get_Mission_Description(Wstring const & filename) // RA2: 0x0073F550, the description of the scenario of a file name, a fixed text for the random map and none for an unknown file
{
	if (stricmp(filename.text(), "RandMap.Sed") == 0) { // RA2: as above
		return(WideWstring(StringTable::LoadString("TXT_RANDOM_MAP_DESCRIPTION", NULL, "C:\\RA2\\wonline.cpp", 2705))); // RA2: as above
	}
	for (int index = 0; index < Session.Scenarios.Count(); index++) { // RA2: as above
		MultiMission * mission = Session.Scenarios[index]; // RA2: as above
		if (stricmp(filename.text(), mission->Get_Filename()) == 0) { // RA2: as above
			return(WideWstring(mission->Description())); // RA2: as above
		}
	}
	return(WideWstring(L"")); // RA2: as above
}

WideWstring Game_List_Tooltip(HWND list, int row) // RA2: 0x0073F5F0, the tooltip of a row of the game list: the host as User_Tooltip makes it, the ping and the description of the scenario
{
	if (row == -1) { // RA2: as above
		return(WideWstring(StringTable::LoadString("STT:LobbyListGames", NULL, "C:\\RA2\\wonline.cpp", 2406))); // RA2: as above // level-2 1.001: line literal
	}
	Channel channel;
	memset(&channel, 0, sizeof(channel));
	int index = SendMessageA(list, LB_GETITEMDATA, row, 0);
	if (index >= 0 && index < g_GameChannelList.length()) { // RA2: as above
		g_GameChannelList.get(channel, index);
		Wstring host((char *)channel.name);
		host.truncate('\''); // RA2: the host name ends before the first quote
		User user;
		memset(&user, 0, sizeof(user));
		strncpy((char *)user.name, host.get(), 10);
		WideWstring tooltip = User_Tooltip(user);
		tooltip += WideWstring(L", ") + StringTable::LoadString("TXT_TOURNEY_COLON", NULL, "C:\\RA2\\wonline.cpp", 2427); // level-2 1.001: the tournament line replaces the scenario description
		if (Is_Channel_Flag_8(&channel)) { // level-2 1.001: as above
			tooltip += StringTable::LoadString("TXT_BATTLE_CLAN", NULL, "C:\\RA2\\wonline.cpp", 2429); // level-2 1.001: as above
		} else if (Is_Channel_Tournament(&channel)) { // level-2 1.001: as above
			tooltip += StringTable::LoadString("TXT_YES", NULL, "C:\\RA2\\wonline.cpp", 2431); // level-2 1.001: as above
		} else {
			tooltip += StringTable::LoadString("TXT_NO", NULL, "C:\\RA2\\wonline.cpp", 2433); // level-2 1.001: as above
		}
		tooltip += WideWstring(L", "); // level-2 1.001: as above
		wchar_t ping_text[64];
		if (channel.latency > 0) { // level-2 1.001: a positive latency
			swprintf(ping_text, StringTable::LoadString("MSG:PingInfo", NULL, "C:\\RA2\\wonline.cpp", 2438), channel.latency); // level-2 1.001: line literal
			tooltip += ping_text;
		} else {
			tooltip += StringTable::LoadString("TXT_UNKNOWN_PING", NULL, "C:\\RA2\\wonline.cpp", 2441); // level-2 1.001: line literal
		}
		return(tooltip);
	}
	return(WideWstring(StringTable::LoadString("STT:LobbyListGames", NULL, "C:\\RA2\\wonline.cpp", 2413))); // RA2: as above // level-2 1.001: line literal
}

WideWstring User_List_Tooltip(HWND list, int row) // RA2: 0x0073F850, the tooltip of a row of the user list: User_Tooltip of the user
{
	if (row == -1) { // RA2: as above
		return(WideWstring(StringTable::LoadString("STT:LobbyListUsers", NULL, "C:\\RA2\\wonline.cpp", 2449))); // RA2: as above // level-2 1.001: line literal
	}
	int index = SendMessageA(list, LB_GETITEMDATA, row, 0);
	if (index >= 0 && index < g_UserList.length()) { // RA2: as above
		User user;
		memset(&user, 0, sizeof(user));
		g_UserList.get(user, index);
		return(User_Tooltip(user));
	}
	return(WideWstring(StringTable::LoadString("STT:LobbyListUsers", NULL, "C:\\RA2\\wonline.cpp", 2454))); // RA2: as above // level-2 1.001: line literal
}

void Refresh_Game_List(void) // RA2: 0x0073F8F0, fills the game list of dialog 0x113 from the game channels: name with the players, kind, password, observer and ping cells, the selection and the first visible row kept
{
	HWND dialog = WS_Find_Dialog(0x113);
	if (!dialog) return; // RA2: as above
	HWND list = GetDlgItem(dialog, 0x6EE);
	if (!list) return; // RA2: as above

	Wstring selected;
	int selected_row = SendMessageA(list, LB_GETCURSEL, 0, 0);
	if (selected_row != -1) Get_Window_Item_Text(list, selected_row, selected);
	Wstring top;
	int top_row = SendMessageA(list, LB_GETTOPINDEX, 0, 0);
	if (top_row != -1) Get_Window_Item_Text(list, top_row, top);
	SendMessageA(list, OD_DISABLEPAINT, 0, 1);
	// level-2 1.001: no g_GameListRefreshing flag (1.006 addition)
	SendMessageA(list, LB_RESETCONTENT, 0, 0);

	int count = g_GameChannelList.length();
	for (int i = 0; i < count; ++i) {
		Channel channel;
		memset(&channel, 0, sizeof(channel));
		g_GameChannelList.get(channel, i);
		if (Is_Channel_Flag_11(&channel) || Is_Channel_Flag_12(&channel)) continue; // RA2: as above
		char options[132];
		strncpy(options, (char *)channel.exInfo, 128);
		int build = 0;
		int hash = 0;
		int ai_count = 0;
		Parse_Channel_ExInfo(options, &build, &hash, &ai_count); // level-2 1.001: three fields
		wchar_t title[80];
		swprintf(title, L"%hs %d/%d", channel.name, channel.currentUsers + ai_count, channel.maxUsers); // RA2: as above // level-2 1.001: no observer slot
		int row = SendMessageA(list, OD_INSERTSTRING, -1, (LPARAM)channel.name);
		SendMessageA(list, LB_SETITEMDATA, row, i);

		OwnerDraw::CellData cell;
		cell.type = OwnerDraw::CellData::TEXT;
		cell.string.set((unsigned short *)title);
		cell.hint.set((unsigned short *)L"");
		cell.color = ColorSystem;
		if (channel.currentUsers == channel.maxUsers) { // level-2 1.001: a full channel, no observer mode
			cell.color = ColorNoJoin;
		}
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_Col_GameName, row), (LPARAM)&cell);

		cell.type = OwnerDraw::CellData::INVALID;
		cell.hint.set((unsigned short *)L"");
		cell.type = OwnerDraw::CellData::SURFACE;
		cell.hint.set((unsigned short *)L"");
		if (Is_Channel_Flag_8(&channel)) { // RA2: a battle clan game
			cell.surf = SurfaceCache.GetSurface("wolclan.pcx", false);
			cell.hint.set(StringTable::LoadString("TXT_BATTLECLAN_GAME", NULL, "C:\\RA2\\wonline.cpp", 2552)); // level-2 1.001: line literal
		} else if (Is_Channel_Tournament(&channel)) {
			cell.surf = SurfaceCache.GetSurface("woltrny.pcx", false);
			cell.hint.set(StringTable::LoadString("TXT_TOURNAMENT_GAME", NULL, "C:\\RA2\\wonline.cpp", 2557)); // level-2 1.001: line literal
		} else {
			cell.surf = SurfaceCache.GetSurface("gt18.bmp", false); // level-2 1.001: the bitmap
			cell.hint.set((unsigned short *)L"");
		}
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_Col_GameIcon, row), (LPARAM)&cell);

		cell.type = OwnerDraw::CellData::SURFACE;
		cell.hint.set((unsigned short *)L"");
		if (channel.flags & 0x100) {
			cell.surf = SurfaceCache.GetSurface("wolpriv.pcx", false);
			cell.hint.set(StringTable::LoadString("TXT_GAME_PASSWORD", NULL, "C:\\RA2\\wonline.cpp", 2571)); // level-2 1.001: line literal
		} else {
			cell.type = OwnerDraw::CellData::INVALID;
			cell.hint.set((unsigned short *)L"");
		}
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_Col_GamePrivate, row), (LPARAM)&cell);

		cell.type = OwnerDraw::CellData::INVALID;
		cell.string.set((unsigned short *)L"");
		cell.hint.set((unsigned short *)L"");
		if (channel.reserved & 0x600) { // level-2 1.001: no observer icons
			cell.type = OwnerDraw::CellData::SURFACE;
			cell.surf = SurfaceCache.GetSurface("wolreslk.pcx", false);
		}
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_Col_GameObserver, row), (LPARAM)&cell);

		if (channel.latency < 0) { // level-2 1.001: any negative latency
			cell.type = OwnerDraw::CellData::TEXT;
			cell.string.set((unsigned short *)L"???");
		} else {
			cell.pingtime = channel.latency;
			cell.type = OwnerDraw::CellData::PING;
		}
		swprintf(title, StringTable::LoadString("WOL:GamePing", NULL, "C:\\RA2\\wonline.cpp", 2601), channel.latency); // level-2 1.001: line literal
		cell.hint.set((unsigned short *)title);
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_Col_GamePingTime, row), (LPARAM)&cell);
	}

	int restored = SendMessageA(list, OD_FINDSTRING, 0, (LPARAM)selected.text());
	SendMessageA(list, LB_SETCURSEL, restored, 0);
	int restored_top = SendMessageA(list, OD_FINDSTRING, 0, (LPARAM)top.text());
	if (restored_top != -1) SendMessageA(list, LB_SETTOPINDEX, restored_top, 0);
	SendMessageA(list, OD_DISABLEPAINT, 0, 0);
	SetFocus(GetDlgItem(dialog, 0x540)); // level-2 1.001: no repaint and the focus always moves to the list
}

void Draw_Player_List(int keep_selection, bool force) // RA2: 0x0073FEE0, fills the user list of the lobby (0x113), of the buddy dialog (0x116) or of the game lobby's slot list (Refresh_Slot_Settings)
{
	HWND win = GameoptWindow(); // RA2: the game lobby shows its players in its own slot list, redrawn by 0x005CA000
	HWND userwin; // RA2: as above
	int i;
	if (win) { // RA2: as above
		Refresh_Slot_Settings(win, force); // RA2: as above
		return;
	}
	if (WS_Find_Dialog(0x6B)) return; // RA2: as above
	win = WS_Find_Dialog(0x116); // RA2: the buddy dialog (0x116) is filled first, TibSun has no such dialog
	if (win) { // RA2: as above
		Fill_Buddy_List(win); // RA2: as above
	} else {
		win = WS_Find_Dialog(0x113); // RA2: the lobby dialog is 0x113
	}
	userwin = GetDlgItem(win, 0x53E); // RA2: as above
	if (!win || !userwin) return; // RA2: as above

	Dictionary<WideWstring, bool> lbdict(Wstring_Hash); // RA2: as above
	LBSaveSelections(userwin, lbdict);
	int topindex = SendDlgItemMessageA(win, 0x53E, LB_GETTOPINDEX, 0, 0); // RA2: as above
	SendDlgItemMessageA(win, 0x53E, OD_DISABLEPAINT, 0, 1); // RA2: as above
	SendDlgItemMessageA(win, 0x53E, LB_RESETCONTENT, 0, 0); // RA2: as above

	Wstring ladder_name;
	Ladder ladder;
	memset(&ladder, 0, sizeof(ladder));
	OwnerDraw::CellData thecell;
	Wstring const & nick = g_NickName; // RA2: the const toLower (0x0076EE70) is called on the nickname
	Wstring local_name = nick.toLower(); // RA2: as above
	wchar_t info[80]; // RA2: as above
	wchar_t rank_string[80]; // RA2: as above
	char count_text[20]; // RA2: as above
	User user;
	static wchar_t localestring[64]; // RA2: 0x00B29738

	for (i = 0; i < g_UserList.length(); i++) {
		g_UserList.get(user, i);
		Wstring const user_name((char *)user.name); // RA2: the names are compared as lower case Wstrings
		if (local_name == user_name.toLower()) { // RA2: as above
			HWND hwnd = GetDlgItem(win, 0x555); // RA2: as above
			if (hwnd) {
				LONG style = GetWindowLongA(hwnd, GWL_STYLE); // RA2: as above
				if (user.flags & 1) { // RA2: as above
					style &= ~WS_DISABLED;
				} else {
					style |= WS_DISABLED;
				}
				SetWindowLongA(hwnd, GWL_STYLE, style); // RA2: as above
				InvalidateRect(hwnd, NULL, 0);
			}
			hwnd = GetDlgItem(win, 0x587); // RA2: as above
			if (hwnd) {
				LONG style = GetWindowLongA(hwnd, GWL_STYLE); // RA2: as above
				if (user.flags & 1) { // RA2: as above
					style &= ~WS_DISABLED;
				} else {
					style |= WS_DISABLED;
				}
				SetWindowLongA(hwnd, GWL_STYLE, style); // RA2: as above
				InvalidateRect(hwnd, NULL, 0);
			}
		}

		if (g_CurrentChannel.type == 0) { // RA2: a chat channel
			swprintf(info, L"%hs", user.name); // RA2: the row text is wide
			int row = SendDlgItemMessageA(win, 0x53E, OD_INSERTSTRINGW, (WPARAM)-1, (LPARAM)info); // RA2: message 0x4CC inserts the wide text and returns the row
			thecell.type = OwnerDraw::CellData::TEXT;
			thecell.hint.set(StringTable::LoadString("TXT_UNRANKED", NULL, "C:\\RA2\\wonline.cpp", 2730)); // RA2: as above // level-2 1.001: line literal
			Char_To_Wide(info, (char *)user.name, -1); // RA2: the cell text is wide
			thecell.string.set(info);
			if (Session.Type == GAME_INTERNET && Online_Session_State == 2) { // RA2: as above
				if (!(user.flags & 1)) { // RA2: as above
					Wstring team_name = Wstring_Narrow(thecell.string.get()); // RA2: the team is looked up by the narrowed name
					if (g_WDTTeams.contains(team_name)) { // RA2: as above
						int color;
						int * value = 0; // RA2: as above
						if (g_WDTTeams.getPointer(team_name, &value) && value) color = *value; // RA2: as above
						WideWstring converted_team(Narrow_To_Wide(team_name.get())); // RA2: as above
						thecell.string = converted_team; // RA2: as above
						thecell.color = PlayerColorTable[color];
					} else {
						thecell.color = ColorSystem;
					}
				} else {
					thecell.color = ColorSystem;
				}
			} else {
				thecell.color = ColorSystem;
			}

			ladder_name.set((char *)user.name);
			ladder_name.toLower();
			memset(localestring, 0, sizeof(localestring));
			int locale = 0;
			if (g_UserLocales.contains(ladder_name) && g_pChat) { // RA2: as above
				int * value = 0; // RA2: as above
				if (g_UserLocales.getPointer(ladder_name, &value) && value) locale = *value; // RA2: as above
				if (locale) {
					WideWstring locale_name = Get_Locale_Name(locale); // RA2: as above
					swprintf(localestring, L"(%hs)", locale_name.get()); // RA2: as above
				}
			}
			if (g_ActiveLadder->getValue(ladder_name, ladder)) {
				swprintf(rank_string, L"%s %d", StringTable::LoadString("TXT_RANK", NULL, "C:\\RA2\\wonline.cpp", 2796), ladder.rung); // RA2: as above // level-2 1.001: line literal
				thecell.hint.set(rank_string);
			}
			if (g_UserLocales.contains(ladder_name)) {
				if (locale) thecell.hint.insert(L" ", 0); // RA2: as above
				thecell.hint.insert(localestring, 0);
			}
			SendMessageA(GetDlgItem(win, 0x53E), LB_SETITEMDATA, row, i); // RA2: the row remembers its index in the user list
			SendDlgItemMessageA(win, 0x53E, OD_SETCELL, MAKEWPARAM(g_Col_Username, i), (LPARAM)&thecell); // RA2: as above

			thecell.type = OwnerDraw::CellData::TEXT;
			ladder_name.set((char *)user.name);
			ladder_name.toLower();
			rank_string[0] = 0;
			if (strlen((char *)user.squadabbrev)) {
				swprintf(rank_string, L"[%hs]", user.squadabbrev); // RA2: as above
				wchar_t squad_name[200]; // RA2: as above
				Char_To_Wide(squad_name, (char *)user.squadname, -1); // RA2: as above
				thecell.hint.set(squad_name); // RA2: as above
			} else if (g_ActiveLadder->getValue(ladder_name, ladder)) {
				swprintf(rank_string, L"(%s %d)", StringTable::LoadString("TXT_RANK", NULL, "C:\\RA2\\wonline.cpp", 2838), ladder.rung); // RA2: as above // level-2 1.001: line literal
				thecell.hint.set(L""); // RA2: as above
			}
			thecell.string.set(rank_string);
			SendDlgItemMessageA(win, 0x53E, OD_SETCELL, MAKEWPARAM(g_Col_Rank, i), (LPARAM)&thecell); // RA2: as above

			thecell.type = OwnerDraw::CellData::TEXT;
			if (user.flags & 1) { // RA2: as above
				thecell.type = OwnerDraw::CellData::SURFACE;
				thecell.surf = SurfaceCache.GetSurface("woloper.pcx", false); // RA2: as above
				thecell.hint.set(StringTable::LoadString("TXT_OPER", NULL, "C:\\RA2\\wonline.cpp", 2850)); // RA2: as above // level-2 1.001: line literal
			} else if (user.flags & 2) { // RA2: as above
				thecell.type = OwnerDraw::CellData::SURFACE;
				thecell.surf = SurfaceCache.GetSurface("wolvoice.pcx", false); // RA2: as above
				thecell.hint.set(StringTable::LoadString("TXT_VOICE", NULL, "C:\\RA2\\wonline.cpp", 2856)); // RA2: as above // level-2 1.001: line literal
			} else {
				thecell.string.set(L""); // RA2: as above
				thecell.hint.set(L""); // RA2: as above
			}
			SendDlgItemMessageA(win, 0x53E, OD_SETCELL, MAKEWPARAM(g_Col_Chanop, i), (LPARAM)&thecell); // RA2: as above
		} else {
			if (HouseTypes.Count() <= 1) return;
			int slot_index;
			{
				Wstring lookup_name((char *)user.name); // RA2: as above
				slot_index = Player_Name_To_Index(lookup_name); // RA2: as above
			}
			int house = 0; // RA2: as above
			int star = 0; // RA2: as above
			if (slot_index != -1) {
				house = g_UserInfo[slot_index].house;
				if (g_UserInfo[slot_index].accepted) star = 1;
				if (slot_index == 0) {
					g_UserInfo[slot_index].accepted = 1;
					star = 2;
				}
			}
			house = house > 0 ? house : 0; // RA2: nine countries (usai.pcx .. rusi.pcx) instead of GDI and Nod

			ladder_name.set((char *)user.name);
			ladder_name.toLower();
			swprintf(info, L"%hs", user.name); // RA2: the row text is wide
			for (int j = 0; j < (int)wcslen(info); j++) { // RA2: as above
				info[j] = (wchar_t)tolower(info[j]); // RA2: as above
			}
			SendDlgItemMessageA(win, 0x53E, OD_INSERTSTRINGW, (WPARAM)-1, (LPARAM)info); // RA2: as above

			thecell.type = OwnerDraw::CellData::PRIMARY;
			thecell.color = PlayerColorTable[g_UserInfo[slot_index].color];
			thecell.hint.set(StringTable::LoadString("TXT_UNRANKED", NULL, "C:\\RA2\\wonline.cpp", 2931)); // RA2: as above // level-2 1.001: line literal
			if (g_ActiveLadder->getValue(ladder_name, ladder)) {
				swprintf(rank_string, L"%s %d", StringTable::LoadString("TXT_RANK", NULL, "C:\\RA2\\wonline.cpp", 2934), ladder.rung); // RA2: as above // level-2 1.001: line literal
				thecell.hint.set(rank_string);
			}
			SendDlgItemMessageA(win, 0x53E, OD_SETCELL, MAKEWPARAM(g_Col_Username, i), (LPARAM)&thecell); // RA2: as above

			thecell.type = OwnerDraw::CellData::TEXT;
			if (strlen((char *)user.squadabbrev)) {
				Char_To_Wide(info, (char *)user.squadname, -1); // RA2: as above
				thecell.hint.set(info);
				Char_To_Wide(info, (char *)user.squadabbrev, -1); // RA2: as above
			} else {
				if (g_ActiveLadder->getValue(ladder_name, ladder)) {
					swprintf(info, L"(%s %d)", StringTable::LoadString("TXT_RANK", NULL, "C:\\RA2\\wonline.cpp", 2953), ladder.rung); // RA2: as above // level-2 1.001: line literal
					thecell.hint.set(L""); // RA2: as above
				} else {
					swprintf(info, L""); // RA2: as above
					thecell.hint.set(L""); // RA2: as above
				}
			}
			thecell.string.set(info);
			SendDlgItemMessageA(win, 0x53E, OD_SETCELL, MAKEWPARAM(g_Col_Gameinfo, i), (LPARAM)&thecell); // RA2: as above

			thecell.type = OwnerDraw::CellData::SURFACE;
			switch (house) { // RA2: the country icon and its side name (TXT_GDI for the first five, TXT_NOD for the rest)
			case 0:
				thecell.surf = SurfaceCache.GetSurface("usai.pcx", false); // RA2: as above
				{
					const wchar_t *sideName = StringTable::LoadString("TXT_GDI", NULL, "C:\\RA2\\wonline.cpp", 2989);
					swprintf(info, L"%s", sideName);
				} // RA2: as above // level-2 1.001: line literal
				break;
			case 1:
				thecell.surf = SurfaceCache.GetSurface("japi.pcx", false); // RA2: as above
				{
					const wchar_t *sideName = StringTable::LoadString("TXT_GDI", NULL, "C:\\RA2\\wonline.cpp", 2993);
					swprintf(info, L"%s", sideName);
				} // RA2: as above // level-2 1.001: line literal
				break;
			case 2:
				thecell.surf = SurfaceCache.GetSurface("frai.pcx", false); // RA2: as above
				{
					const wchar_t *sideName = StringTable::LoadString("TXT_GDI", NULL, "C:\\RA2\\wonline.cpp", 2997);
					swprintf(info, L"%s", sideName);
				} // RA2: as above // level-2 1.001: line literal
				break;
			case 3:
				thecell.surf = SurfaceCache.GetSurface("geri.pcx", false); // RA2: as above
				swprintf(info, L"%s", StringTable::LoadString("TXT_GDI", NULL, "C:\\RA2\\wonline.cpp", 3001)); // RA2: as above // level-2 1.001: line literal
				break;
			case 4:
				thecell.surf = SurfaceCache.GetSurface("gbri.pcx", false); // RA2: as above
				swprintf(info, L"%s", StringTable::LoadString("TXT_GDI", NULL, "C:\\RA2\\wonline.cpp", 3005)); // RA2: as above // level-2 1.001: line literal
				break;
			case 5:
				thecell.surf = SurfaceCache.GetSurface("djbi.pcx", false); // RA2: as above
				swprintf(info, L"%s", StringTable::LoadString("TXT_NOD", NULL, "C:\\RA2\\wonline.cpp", 3009)); // RA2: as above // level-2 1.001: line literal
				break;
			case 6: // RA2: as above
				thecell.surf = SurfaceCache.GetSurface("arbi.pcx", false); // RA2: as above
				swprintf(info, L"%s", StringTable::LoadString("TXT_NOD", NULL, "C:\\RA2\\wonline.cpp", 3013)); // RA2: as above // level-2 1.001: line literal
				break;
			case 7: // RA2: as above
				thecell.surf = SurfaceCache.GetSurface("lati.pcx", false); // RA2: as above
				swprintf(info, L"%s", StringTable::LoadString("TXT_NOD", NULL, "C:\\RA2\\wonline.cpp", 3017)); // RA2: as above // level-2 1.001: line literal
				break;
			case 8: // RA2: as above
				thecell.surf = SurfaceCache.GetSurface("rusi.pcx", false); // RA2: as above
				swprintf(info, L"%s", StringTable::LoadString("TXT_NOD", NULL, "C:\\RA2\\wonline.cpp", 3021)); // RA2: as above // level-2 1.001: line literal
				break;
			}
			thecell.hint.set(info);
			SendDlgItemMessageA(win, 0x53E, OD_SETCELL, MAKEWPARAM(g_Col_House, i), (LPARAM)&thecell); // RA2: as above

			thecell.type = OwnerDraw::CellData::SURFACE;
			if (star) {
				if (star == 2) {
					thecell.surf = SurfaceCache.GetSurface("wolhost.pcx", false); // RA2: as above
				} else {
					thecell.surf = SurfaceCache.GetSurface("wolacpt.pcx", false); // RA2: as above
				}
				thecell.hint.set(StringTable::LoadString("TXT_ACCEPTED", NULL, "C:\\RA2\\wonline.cpp", 3035)); // RA2: as above // level-2 1.001: line literal
			} else {
				thecell.type = OwnerDraw::CellData::INVALID;
				thecell.hint.set(L""); // RA2: as above
			}
			SendDlgItemMessageA(win, 0x53E, OD_SETCELL, MAKEWPARAM(g_Col_Accept, i), (LPARAM)&thecell); // RA2: as above

			int average_ping = 0; // RA2: as above
			g_pNetUtil->GetAvgPing(user.ipaddr, &average_ping);
			if (average_ping < 0) average_ping = 0;
			thecell.type = OwnerDraw::CellData::PING;
			thecell.pingtime = average_ping;
			wchar_t ping_text[200]; // RA2: as above
			swprintf(ping_text, StringTable::LoadString("MSG:PingInfo", NULL, "C:\\RA2\\wonline.cpp", 3051), average_ping); // RA2: as above // level-2 1.001: line literal
			if (average_ping == 0) {
				swprintf(ping_text, StringTable::LoadString("TXT_UNKNOWN_PING", NULL, "C:\\RA2\\wonline.cpp", 3053)); // RA2: as above // level-2 1.001: line literal
			}
			thecell.hint.set(ping_text); // RA2: as above
			Wstring const ping_name((char *)user.name); // RA2: as above
			if (local_name == ping_name.toLower()) { // RA2: as above
				thecell.type = OwnerDraw::CellData::INVALID;
			}
			SendDlgItemMessageA(win, 0x53E, OD_SETCELL, MAKEWPARAM(g_Col_GamePing, i), (LPARAM)&thecell); // RA2: as above
		}
	}

	if (keep_selection == 0) LBRestoreSelections(userwin, lbdict);
	int sel_count = SendDlgItemMessageA(win, 0x53E, LB_GETSELCOUNT, 0, 0); // RA2: as above
	int user_count = g_UserList.length();
	if (sel_count > 0) {
		sprintf(count_text, "%d  (%d)", user_count, sel_count); // RA2: as above
	} else {
		sprintf(count_text, "%d", user_count); // RA2: as above
	}
	SendDlgItemMessageA(win, 0x60B, OD_SETTEXT, 0, (LPARAM)count_text); // RA2: message 0x4B4 sets the text of the count label
	SendDlgItemMessageA(win, 0x53E, LB_SETTOPINDEX, (WPARAM)topindex, 0); // RA2: as above
	SendDlgItemMessageA(win, 0x53E, OD_DISABLEPAINT, 0, 0); // RA2: as above
	InvalidateRect(GetDlgItem(win, 0x53E), NULL, 0); // RA2: as above
}


// RA2: the event sinks of the chat, net utility and download services. Their handlers are defined with the rest of the file (they are not part of this part); the classes are declared here as the executable creates them in Startup_Chat (0x00741300): each is 32 bytes, the vtable pointer, the reference count and the critical section of CComObjectRoot
class CChatEventSink : public CComObjectRoot, public IChatEvent // RA2: the sink the executable creates in Startup_Chat
{
	public:
		CChatEventSink(void); // level-2 1.001: out of line (0x34B760)
		BEGIN_COM_MAP(CChatEventSink)
		COM_INTERFACE_ENTRY(IChatEvent)
		END_COM_MAP()
		STDMETHOD(OnServerList)(HRESULT res, Server *servers); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnUpdateList)(HRESULT res, Update *updates); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnServerError)(HRESULT res, LPCSTR ircmsg); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnConnection)(HRESULT res, LPCSTR motd); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnMessageOfTheDay)(HRESULT res, LPCSTR motd); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnChannelList)(HRESULT res, Channel *channels); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnChannelCreate)(HRESULT res, Channel *channel); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnChannelJoin)(HRESULT res, Channel *channel, User *user); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnChannelLeave)(HRESULT res, Channel *channel, User *user); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnChannelTopic)(HRESULT res, Channel *channel, LPCSTR topic); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnPrivateAction)(HRESULT res, User *user, LPCSTR action); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnPublicAction)(HRESULT res, Channel *channel, User *user, LPCSTR action); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnUserList)(HRESULT res, Channel *channel, User *users); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnPublicMessage)(HRESULT res, Channel *channel, User *user, LPCSTR message); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnPrivateMessage)(HRESULT res, User *user, LPCSTR message); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnSystemMessage)(HRESULT res, LPCSTR message); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnNetStatus)(HRESULT res); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnLogout)(HRESULT status, User *user); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnPrivateGameOptions)(HRESULT res, User *user, LPCSTR options); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnPublicGameOptions)(HRESULT res, Channel *channel, User *user, LPCSTR options); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnGameStart)(HRESULT res, Channel *channel, User *users, int gameid); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnUserKick)(HRESULT res, Channel *channel, User *kicked, User *kicker); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnUserIP)(HRESULT res, User *user); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnFind)(HRESULT res, Channel *chan); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnPageSend)(HRESULT res); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnPaged)(HRESULT res, User *user, LPCSTR message); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnServerBannedYou)(HRESULT res, time_t bannedTill); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnUserFlags)(HRESULT res, LPCSTR name, unsigned int flags, unsigned int mask); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnChannelBan)(HRESULT res, LPCSTR name, int banned); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnSquadInfo)(HRESULT res, unsigned long id, Squad *squad); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnUserLocale)(HRESULT res, User *users); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnUserTeam)(HRESULT res, User *users); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnSetLocale)(HRESULT res, Locale newlocale); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnSetTeam)(HRESULT res, int newteam); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnBuddyList)(HRESULT res, User *buddyList); // level-2 1.001: slots 35..42 of IChatEvent
		STDMETHOD(OnBuddyAdd)(HRESULT res, User *buddy); // level-2 1.001: as above
		STDMETHOD(OnBuddyDelete)(HRESULT res, User *buddy); // level-2 1.001: as above
		STDMETHOD(OnPublicUnicodeMessage)(HRESULT res, Channel *channel, User *user, const unsigned short *message); // level-2 1.001: as above
		STDMETHOD(OnPrivateUnicodeMessage)(HRESULT res, User *user, const unsigned short *message); // level-2 1.001: as above
		STDMETHOD(OnPrivateUnicodeAction)(HRESULT res, User *user, const unsigned short *action); // level-2 1.001: as above
		STDMETHOD(OnPublicUnicodeAction)(HRESULT res, Channel *channel, User *user, const unsigned short *action); // level-2 1.001: as above
		STDMETHOD(OnPagedUnicode)(HRESULT res, User *user, const unsigned short *message); // level-2 1.001: as above
};

class CNetUtilEventSink : public CComObjectRoot, public INetUtilEvent // RA2: the sink the executable creates in Startup_Chat
{
	public:
		CNetUtilEventSink(void); // level-2 1.001: out of line (0x34A9C0)
		BEGIN_COM_MAP(CNetUtilEventSink)
		COM_INTERFACE_ENTRY(INetUtilEvent)
		END_COM_MAP()
		STDMETHOD(OnPing)(HRESULT res, int time, unsigned long ip, int handle); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnLadderList)(HRESULT res, Ladder *list, int totalCount, long timeStamp, int keyRung); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnGameresSent)(HRESULT res); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnNewNick)(HRESULT res, LPCSTR message, LPCSTR nick, LPCSTR pass); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnAgeCheck)(HRESULT res, int years, int consent); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnWDTState)(HRESULT res, unsigned char *state, int length); // RA2: a handler of the interface, defined with the rest of the file
};

class CDownloadEventSink : public CComObjectRoot, public IDownloadEvent // RA2: the sink the executable creates in Startup_Chat
{
	public:
		CDownloadEventSink(void) {}
		BEGIN_COM_MAP(CDownloadEventSink)
		COM_INTERFACE_ENTRY(IDownloadEvent)
		END_COM_MAP()
		STDMETHOD(OnEnd)(void); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnError)(int error); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnProgressUpdate)(int bytesread, int totalsize, int timetaken, int timeleft); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnQueryResume)(void); // RA2: a handler of the interface, defined with the rest of the file
		STDMETHOD(OnStatusUpdate)(int status); // RA2: a handler of the interface, defined with the rest of the file
};

extern CComObject<CChatEventSink> * g_pChatSink; // RA2: 0x00B2A720
extern CComObject<CNetUtilEventSink> * g_pNetUtilSink; // RA2: 0x00B26560
extern CComObject<CDownloadEventSink> * g_pDownloadSink; // RA2: 0x00B28DE0

void Redraw_Player_List(void) // RA2: 0x007412F0, Draw_Player_List with the default arguments (a jump to it)
{
	Draw_Player_List(0, false); // RA2: as above
}

extern CLSID const CLSID_Chat; // RA2: 0x007AF640, the class ids of the three services
extern CLSID const CLSID_NetUtil; // RA2: 0x007AF660
extern CLSID const CLSID_Download; // RA2: 0x007AF650
extern IID const IID_IChat; // RA2: 0x007AF5A0, the interface ids
extern IID const IID_IChatEvent; // RA2: 0x007AF5B0
extern IID const IID_INetUtil; // RA2: 0x007AF5E0
extern IID const IID_INetUtilEvent; // RA2: 0x007AF5F0
extern IID const IID_IDownload; // RA2: 0x007AF5C0
extern IID const IID_IDownloadEvent; // RA2: 0x007AF5D0

int Startup_Chat(HINSTANCE hInstance) // RA2: 0x00741300, creates the chat, net utility and download services with their event sinks, checks the version of the chat API and tells it the registry key and the SKU; 1 when all is well, -2 when a service is missing or too old
{
	HRESULT hresult = NULL;
	assert(hInstance != NULL); // level-2: assert inferred from VC6 inline budget
	assert(g_pChatSink == NULL); // level-2: assert inferred from VC6 inline budget (the services are started once, see Init_Wonline)
	assert(g_pNetUtilSink == NULL); // level-2: assert inferred from VC6 inline budget
	assert(g_pDownloadSink == NULL); // level-2: assert inferred from VC6 inline budget
	_Module.Init(NULL, hInstance);

	g_pChat = NULL;
	g_pNetUtil = NULL;
	g_pDownload = NULL;
	g_dwChatAdvise = 0;
	g_dwNetUtilAdvise = 0;
	g_dwDownloadAdvise = 0;

	CoCreateInstance(CLSID_Chat, NULL, CLSCTX_INPROC_SERVER, IID_IChat, (void **)&g_pChat);
	if (g_pChat) {
		CComObject<CChatEventSink>::CreateInstance(&g_pChatSink);
		hresult = AtlAdvise(g_pChat, g_pChatSink->GetUnknown(), IID_IChatEvent, &g_dwChatAdvise);
	}
	if ((g_pChat == NULL) || (hresult != S_OK)) {
		ODMessageBox(StringTable::LoadString("TXT_APIMISSING", NULL, "C:\\RA2\\wonline.cpp", 6722), 0, NULL, false); // RA2: as above // level-2 1.001: line literal
		return(-2); // RA2: as above
	}

	CoCreateInstance(CLSID_NetUtil, NULL, CLSCTX_INPROC_SERVER, IID_INetUtil, (void **)&g_pNetUtil);
	if (g_pNetUtil) {
		CComObject<CNetUtilEventSink>::CreateInstance(&g_pNetUtilSink);
		hresult = AtlAdvise(g_pNetUtil, g_pNetUtilSink->GetUnknown(), IID_INetUtilEvent, &g_dwNetUtilAdvise);
	}
	if ((g_pNetUtil == NULL) || (hresult != S_OK)) {
		ODMessageBox(StringTable::LoadString("TXT_APIMISSING", NULL, "C:\\RA2\\wonline.cpp", 6738), 0, NULL, false); // RA2: as above // level-2 1.001: line literal
		return(-2); // RA2: as above
	}

	CoCreateInstance(CLSID_Download, NULL, CLSCTX_INPROC_SERVER, IID_IDownload, (void **)&g_pDownload);
	if (g_pDownload) {
		CComObject<CDownloadEventSink>::CreateInstance(&g_pDownloadSink);
		hresult = AtlAdvise(g_pDownload, g_pDownloadSink->GetUnknown(), IID_IDownloadEvent, &g_dwDownloadAdvise);
	}
	if ((g_pDownload == NULL) || (hresult != S_OK)) {
		ODMessageBox(StringTable::LoadString("TXT_APIMISSING", NULL, "C:\\RA2\\wonline.cpp", 6754), 0, NULL, false); // RA2: as above // level-2 1.001: line literal
		return(-2); // RA2: as above
	}

	unsigned long version;
	g_pChat->GetVersion(&version);
	if (version < 0x1000E) { // RA2: the API of RA2 is newer than TibSun's
		ODMessageBox(StringTable::LoadString("TXT_APIWRONGVERSION", NULL, "C:\\RA2\\wonline.cpp", 6766), 0, NULL, false); // RA2: as above // level-2 1.001: line literal
		return(-2); // RA2: as above
	}

	g_pChat->SetAttributeValue("RegPath", APP_REG_KEY);

	HKEY rKey;
	char buf[256];
	if (APP_REG_KEY != NULL && strlen(APP_REG_KEY)) {
		strcpy(buf, APP_REG_KEY);
		if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, buf, 0, KEY_READ, &rKey) == ERROR_SUCCESS) {
			DWORD type;
			DWORD value;
			DWORD valuesize = sizeof(value);
			if (RegQueryValueEx(rKey, "SKU", NULL, &type, (LPBYTE)&value, &valuesize) == ERROR_SUCCESS) {
				g_pChat->SetProductSKU(value);
			}
			RegCloseKey(rKey);
		}
	}

	return(1); // RA2: as above
}

/// <summary>
/// Determines the sort order of two channel users.
/// Channel owners come first, then users with voice, then everyone else; equals are listed
/// alphabetically. This is the order the user list box is kept in.
/// </summary>
/// <returns>Returns with a negative value if the u1 user sorts first, a positive value if
/// the u2 one does, and zero if the two cannot be told apart.</returns>
inline int Compare_Users(User * u1, User * u2) // RA2: 0x007416D0, the same as TibSun's // level-2 1.001: inline: OnChannelJoin 0x0074CB20 expands it, and GAME.EXE has no out-of-line copy (no caller, no byte match)
{
	User * users[2];
	int value[2];
	users[0] = u1;
	users[1] = u2;
	value[0] = 0;
	value[1] = 0;

	for (int i = 0; i < 2; i++) {
		if (users[i]->flags & 1) value[i] += 4; // RA2: as above
		if (users[i]->flags & 2) value[i] += 2; // RA2: as above
	}
	if (value[0] < value[1]) {
		return(1);
	} else if (value[0] > value[1]) {
		return(-1);
	}
	return(stricmp((char *)u1->name, (char *)u2->name));
}

#include "multiplayer.h" // RA2: the game mode of the session, the handlers of the end of the game

namespace OwnerDraw { BOOL __stdcall Set_Paint_Disabled(HWND window, LPARAM lparam); } // RA2: 0x005ECF40, defined in ownrdraw.cpp
void __fastcall Set_Player_Ping(HWND dialog, int player, int ping); // RA2: 0x004D1060, defined in gdlgsupp.cpp
void __fastcall Enable_Start_Button(void); // RA2: 0x005C9700, defined in netshare.cpp
void __fastcall Release_Slot_By_Name(char const * name); // RA2: 0x005C9270, defined in netshare.cpp
void __fastcall Release_Slot_By_Address(IPXAddressClass & address); // level-2 1.001: 0x005C2D20, frees the slot of the player of this address, defined in netshare.cpp
int Join_Selected_Lobby(bool join); // RA2: 0x00744930, defined later in the file
int Pick_Lobby(bool require_room); // RA2: 0x00744090, the index of the lobby channel to join, -1 when none
void __fastcall Store_User_Ping(char const * name, int ping); // RA2: 0x0075B110, a user's ping (WOL), defined later in the file
extern int g_PlayerPings[8]; // RA2: 0x00B292AC, the ping of each slot of the game lobby

/// <summary>
/// Handles a user leaving the current channel. If the departing user is ourselves, resets all
/// local channel/session state and returns to the lobby (closing any open guest or game-options
/// dialogs); otherwise removes the given user from our local user list and updates the
/// game-options acceptance state before refreshing the user list display.
/// </summary>
/// <param name="user">The user who left the channel.</param>
static inline void Focus_Chat_Line(void) // level-2 1.001: INFERRED helper (F29): the focus goes back to the chat line (0x540) of the top dialog, the tail that Close_Wait_Window 0x0074D780 also has. Handle_User_Leave needs GetDlgItem referenced only inside an inline here: with the flat statements the loop below hoists GetDlgItem before EnableWindow, 1.001 hoists EnableWindow first
{
	HWND top = WS_Top_Window(); // RA2: as above
	HWND control = GetDlgItem(top, 0x540); // RA2: as above
	if (control) { // RA2: as above
		SetFocus(control); // RA2: as above
	}
}

void Handle_User_Leave(User & user) // RA2: 0x00741750
{
	stricmp(g_NickName.get(), (char *)user.name); // RA2: the result is not used

	if (g_CurrentChannel.type != 0) VocClass::PlayGlobal(Rule->PlayerLeft, 1.0f, 0x2000, 0); // RA2: as above

	if (user.flags & 0x8000) { // RA2: as above
		DebugString("Local user leaving channel\n"); // RA2: as above
		if (WolOptionsLocked != 0) DebugString("Local user leaving channel after game start\n"); // RA2: as above
		wchar_t name[64]; // RA2: as above
		Char_To_Wide(name, (char *)g_CurrentChannel.name, -1); // RA2: the name is wide
		if (strncmp((char *)g_CurrentChannel.name, "Lob_33_", 7) == 0) { // RA2: as above
			int num = atol(((char *)g_CurrentChannel.name) + strlen("Lob_33_")); // RA2: as above
			int num2 = num / 6; // RA2: as above // level-2 1.001: six lobby names
			int num1 = num % 6; // RA2: as above
			if (num2 == 0) {
				swprintf(name, L"%s", g_Lobbies[num1]); // RA2: as above
			} else {
				swprintf(name, L"%s %d", g_Lobbies[num1], num2 + 1); // RA2: as above
			}
		}
		if (Online_Session_State != 2 && Online_Session_State != 1) { // RA2: no message in a LAN or WDT game
			Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_YOULEFT", NULL, "C:\\RA2\\wonline.cpp", 6834), name); // RA2: as above // level-2 1.001: line literal
		}
		g_ChannelCount = 0;
		DebugString("Channel Leave \n"); // RA2: as above
		memset(&g_CurrentChannel, 0, sizeof(Channel));
		memset(g_UserInfo, 0, sizeof(ChannelUserInfo) * 16); // RA2: sixteen users
		g_UserList.clear();
		g_IsChannelCreator = 0;
		HWND wait_dlg = WS_Find_Dialog(0xC4); // RA2: Close_Wait_Window inline, for the channel leave event
		if (wait_dlg) { // RA2: as above
			g_ActiveWaitFlags &= ~0x40; // RA2: as above
			if (g_ActiveWaitFlags == 0) {
				WS_Destroy_Dialog(wait_dlg, 0); // RA2: as above
			}
		}
		Focus_Chat_Line(); // level-2 1.001: the inline helper above (flat statements give the other hoist order of the two import pointers at +0x4D2)

		++Session.Suspended; // RA2: a count that is raised while the dialogs are closed, +0x2824 of the session
		Session.Options.ScenarioDescription[0] = 0;
		Session.ScenarioFileLength = 0;
		Session.ScenarioDigest[0] = 0;
		HWND mainwin = WS_Find_Dialog(0x113); // RA2: as above
		if (mainwin && g_PlayingNetGame) { // RA2: as above
			ShowWindow(mainwin, SW_HIDE); // RA2: as above
			OwnerDraw::Set_Paint_Disabled(mainwin, 1); // RA2: as above
		}
		HWND guest_dlg = WS_Find_Dialog(0xC9); // RA2: as above
		if (guest_dlg) {
			WS_Destroy_Dialog(guest_dlg, 2); // RA2: as above
			ShowWindow(guest_dlg, SW_HIDE); // RA2: as above
			OwnerDraw::Set_Paint_Disabled(guest_dlg, 1); // RA2: as above
			if (Online_Session_State == 3) { // RA2: as above
				if (g_PlayingNetGame) {
					if (mainwin) {
						ShowWindow(mainwin, SW_HIDE); // RA2: as above
						OwnerDraw::Set_Paint_Disabled(mainwin, 1); // RA2: as above
					}
				} else {
					Join_Selected_Lobby(false); // RA2: as above // level-2 1.001: no message to the lobby dialog
				}
			} else if (Online_Session_State == 4) { // RA2: as above
				DebugString("Setting g_JoinLobbyNow, Guest\n"); // RA2: as above
				g_JoinLobbyNow = 1;
			}
		}
		HWND gamewin = WS_Find_Dialog(0xC2); // RA2: as above
		if (gamewin) {
			WS_Destroy_Dialog(gamewin, 2); // RA2: as above
			ShowWindow(gamewin, SW_HIDE); // RA2: as above
			OwnerDraw::Set_Paint_Disabled(gamewin, 1); // RA2: as above
			if (Online_Session_State == 3) { // RA2: as above
				if (g_PlayingNetGame) {
					if (mainwin) {
						ShowWindow(mainwin, SW_HIDE); // RA2: as above
						OwnerDraw::Set_Paint_Disabled(mainwin, 1); // RA2: as above
					}
				} else {
					Join_Selected_Lobby(false); // RA2: as above // level-2 1.001: no message to the lobby dialog
				}
			} else if (Online_Session_State == 4) { // RA2: as above
				DebugString("Setting g_JoinLobbyNow, Host\n"); // RA2: as above
			}
		}
		if (mainwin) {
			if (!g_PlayingNetGame) { // RA2: as above
				ShowWindow(mainwin, SW_SHOW);
				OwnerDraw::Set_Paint_Disabled(mainwin, 0); // RA2: as above
			}
			Refresh_Game_List(); // RA2: the game list is redrawn, there is no channel list
		}
		--Session.Suspended; // RA2: as above
		return;
	}

	if (WolOptionsLocked == 2) { // RA2: the game was started, nothing else to do for another player
		DebugString("other player leaving channel after Game Started\n"); // RA2: as above
		return;
	}

	// level-2 1.001: the slot of the leaving player keeps its ping (no slot search here)
	User temp;
	for (int i = 0; i < g_UserList.length(); i++) {
		g_UserList.get(temp, i);
		if (stricmp((char *)temp.name, (char *)user.name) == 0) { // RA2: as above
			g_UserList.remove(i);
			if (g_CurrentChannel.type != 0) { // RA2: as above
				memmove(g_UserInfo + i, g_UserInfo + i + 1, sizeof(ChannelUserInfo) * (15 - i)); // RA2: sixteen users
				if (WolOptionsLocked != 2) { // RA2: as above
					for (int user_index = 1; user_index < 16; user_index++) { // RA2: every user but the host loses the accept status // level-2 1.001: an int index
						g_UserInfo[user_index].accepted = 0;
						EnableWindow(GetDlgItem(GameoptWindow(), 0x59F), 1); // RA2: as above
					}
					if (!g_IsChannelCreator) { // RA2: as above
						HWND guest = WS_Find_Dialog(0xC9); // RA2: as above
						Enable_Player_Combos(guest, true); // RA2: a guest gets the combos back
					}
					Enable_Start_Button(); // RA2: as above
				}
			}
			if (i == 0 && g_CurrentChannel.type != 0 && g_IsChannelCreator == 0) { // RA2: as above
				g_pChat->RequestChannelLeave();
			}
			break;
		}
	}

	if (g_CurrentChannel.type != 0) { // RA2: as above
		IPXAddressClass address = User_To_IPX_Address(&user); // level-2 1.001: the player is found by its address, not by its name
		Release_Slot_By_Address(address); // level-2 1.001: frees the slot of the player (0x005C2D20)
		for (int player = 0; player < Session.Players.Count(); player++) { // RA2: as above
			if (Session.Players[player]->Address == address) { // level-2 1.001: every entry of the address is dropped (no break, no port list)
				NodeNameType * entry = Session.Players[player]; // RA2: as above
				Session.Players.Delete_Index(player); // RA2: as above
				delete entry; // RA2: as above
			}
		}
		// level-2 1.001: no ping update of the slots here
		if (g_IsChannelCreator) { // RA2: as above
			Enable_Start_Button(); // RA2: as above
			Send_Player_List(); // RA2: as above
			Send_Lobby_Options(true, true); // RA2: PumpGameopts(true, true)
			if (WS_Top_Window_ID() == 0x6B) { // RA2: in the game list dialog the game mode of the selected row is told
				HWND window = WS_Top_Window(); // RA2: as above
				int index = SendDlgItemMessageA(window, 0x6EB, LB_GETCURSEL, 0, 0); // RA2: as above
				if (index != -1) {
					MultiplayerGameMode * mode = (MultiplayerGameMode *)SendDlgItemMessageA(window, 0x6EB, LB_GETITEMDATA, index, 0); // RA2: as above
					if (mode) { // RA2: as above
						mode->vt_entry_78(); // RA2: as above
						Draw_Player_List(0, false); // RA2: as above
						return;
					}
				}
			} else if (Session.MPGameMode) { // RA2: as above
				Session.MPGameMode->vt_entry_78(); // RA2: as above
			}
		}
	}
	Draw_Player_List(0, false); // RA2: as above
}

extern bool g_WOLInitialized; // RA2: 0x00B2AC81, set once the chat services are up, tested by Shutdown_Chat
void __fastcall Free_Lobby_Entries(void); // RA2: 0x005C8950, defined in netshare.cpp

static inline void Reset_Wait_Event_At(int index) { ResetEvent(g_WaitEventHandles[index]); }
static inline void Reset_All_Wait_Events(void) { for (int i = 0; i < EV_COUNT; i++) { Reset_Wait_Event_At(i); } }
/// <summary>
/// Logs the local player out of the WOL chat session. Sends a logout request to the Chat
/// interface and waits (with timeout retries) for it to complete or be aborted, then, for
/// World Domination Tour sessions, also closes the event handles and fully shuts down chat.
/// </summary>
void Logout_WOnline(void) // RA2: 0x00741EA0
{
	int i;
	DWORD wait_result;

	g_IgnoreNetStatus = TRUE;

	if (Session.Type == GAME_INTERNET && Online_Session_State == 2) { // RA2: the team lookups of the WDT are dropped
		g_WDTTeams.clear();
	}

	if (g_pChat != NULL) {
		Reset_All_Wait_Events();
		WOL_Wait_Callback();
		if (g_pChat->RequestLogout() == S_OK) {
			{
				WideWstring title(StringTable::LoadString("TXT_WOL_LOGGING_OUT", NULL, "C:\\RA2\\wonline.cpp", 7040)); // level-2 1.001: line 7040 // RA2: the wait dialog takes a wide text
				Show_Wait_Window(0x20, title, false);
			}
			for (i = 0; i < 5; i++) {
				while ((wait_result = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100)) == WAIT_TIMEOUT) {
					WOL_Wait_Callback();
				}
				ResetEvent(g_WaitEventHandles[wait_result]);
				if (wait_result == EV_ABORT) {
					break;
				}
				if (wait_result == EV_NETIGNORE) {
					break;
				}
			}
		}

		HWND profile = WS_Find_Dialog(0x11E); // RA2: the profile dialog is closed first
		if (profile) WS_Destroy_Dialog(profile, 0);
		Close_Wait_Window(0x20); // RA2: expanded here
	}
}

/// <summary>
/// Tears down the WOL COM interfaces: unadvises each event sink, releases the Chat, NetUtil,
/// and Download interfaces, clears the global pointers, and terminates the ATL module.
/// </summary>
void Shutdown_Chat(void) // RA2: 0x00742080
{
	if (MultiplayerMapPreview) { // RA2: the preview of the map is dropped
		delete MultiplayerMapPreview;
		MultiplayerMapPreview = NULL;
	}
	HWND profile = WS_Find_Dialog(0x11E); // RA2: the profile dialog is closed first
	if (profile) WS_Destroy_Dialog(profile, 0); // RA2: as above
	if (g_WOLInitialized) { // RA2: only after Startup_Chat
		Free_Lobby_Entries(); // RA2: the fixed lobby entries are dropped
		if (g_pChat) {
			AtlUnadvise(g_pChat, IID_IChatEvent, g_dwChatAdvise);
			g_pChat->Release();
		}
		if (g_pNetUtil) {
			AtlUnadvise(g_pNetUtil, IID_INetUtilEvent, g_dwNetUtilAdvise);
			g_pNetUtil->Release();
		}
		if (g_pDownload) {
			AtlUnadvise(g_pDownload, IID_IDownloadEvent, g_dwDownloadAdvise);
			g_pDownload->Release();
		}
		g_pChat = NULL;
		g_pNetUtil = NULL;
		g_pDownload = NULL;
		for (int i = 0; i < EV_COUNT; i++) {
			CloseHandle(g_WaitEventHandles[i]);
		}
		_Module.Term();
		g_WOLInitialized = false; // RA2: as above
	}
}

extern char g_WDTHost[]; // RA2: 0x00B269AC, the host of the WDT server (Request_WDT_Server_List sets it)
extern int g_WDTPort; // RA2: 0x00B299BC

/// <summary>
/// Requests the World Domination Tour state.
/// This routine puts up no wait window of its own, which is what lets the wait callback
/// poll the tour state in the background while the player is doing something else. The
/// language code is refreshed from the installed product's SKU on the way through.
/// </summary>
/// <returns>Returns with true if a request was issued, or false if there is no NetUtil connection
/// to issue it on.</returns>
bool Get_WDT_State_Silent(void) // RA2: 0x00742270, returns a bool
{
	DWORD value = 0;

	HKEY rKey;
	char buf[256];
	if (APP_REG_KEY != NULL && strlen(APP_REG_KEY)) {
		strcpy(buf, APP_REG_KEY);
		if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, buf, 0, KEY_READ, &rKey) == ERROR_SUCCESS) {
			DWORD type;
			DWORD valuesize = sizeof(value);
			RegQueryValueEx(rKey, "SKU", NULL, &type, (LPBYTE)&value, &valuesize);
			RegCloseKey(rKey);
		}
	}

	g_LanguageCode = value & 0xFF;
	if (g_pChat != NULL) {
		g_pChat->SetProductSKU(value);
	}

	if (g_pNetUtil != NULL) {
		DebugString("Get_WDT_State_Silent: WDTHost is %s, port is %d\n", g_WDTHost, g_WDTPort);
		g_pNetUtil->RequestWDTState(g_WDTHost, g_WDTPort, 3 /* RA2: everything, as WDT_REQ_STATE_EVERYTHING of wdtnet.h */); // RA2: 3 asks for everything (WDT_REQ_STATE_EVERYTHING of wdtnet.h, which this file does not include)
		return(true); // RA2: as above
	}
	return(false); // RA2: as above
}

void __fastcall Init_Lobby_Entries(void); // RA2: 0x005C86E0, defined in netshare.cpp
void __fastcall Clear_Slot_Lists(void); // RA2: 0x005C8A70, as above
void __fastcall Reset_Slots(void); // RA2: 0x005C8A90, as above

int Init_Wonline(void) // RA2: 0x00742390, not in TibSun: brings the chat services up once (the work Login_WOL did itself in TibSun), 1 when they already are, else the result of Startup_Chat
{
	if (g_WOLInitialized) return(1); // RA2: as above
	g_WOLInitialized = true; // RA2: set before the services come up
	Init_Lobby_Entries(); // RA2: the fixed lobby entries (open, closed, computers)
	Clear_Slot_Lists(); // RA2: as above
	Reset_Slots(); // RA2: as above

	DWORD value = 0;
	HKEY rKey;
	char regkey[256];
	if (APP_REG_KEY != NULL && strlen(APP_REG_KEY)) {
		strcpy(regkey, APP_REG_KEY);
		if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, regkey, 0, KEY_READ, &rKey) == ERROR_SUCCESS) {
			DWORD type;
			DWORD valuesize = sizeof(value);
			RegQueryValueEx(rKey, "SKU", NULL, &type, (LPBYTE)&value, &valuesize);
			RegCloseKey(rKey);
		}
	}

	value &= 0xFF; // RA2: as above
	g_LanguageCode = value; // RA2: as above
	g_GameSKU = value + 0x2100; // RA2: the SKU of Red Alert 2 plus the language

	Reset_WOL_Globals();
	g_IgnoreNetStatus = true;
	for (int i = 0; i < EV_COUNT; i++) {
		g_WaitEventHandles[i] = CreateEvent(NULL, FALSE, FALSE, NULL);
	}
	return(Startup_Chat(ProgramInstance)); // RA2: 1 on success, -2 when a service is missing
}

#include "wolopt.h" // RA2: the options of Westwood Online

extern char g_LadderAddress[]; // RA2: 0x00B29018, the address of the ladder server (empty when there is none)
extern int g_LadderPort; // RA2: 0x00B2A8AC, the port of the ladder server
extern bool g_PlaintextPassword; // RA2: 0x007FD374, TibSun's name; RequestConnection takes its low byte
namespace OwnerDraw {
class DialogControl { // RA2: the base of the controls dialogs report to (vtable 0x007A7B28); the same class as in ownrdraw.cpp, whose header does not exist yet
public:
	DialogControl(void); // RA2: 0x00601030
	virtual ~DialogControl(void); // RA2: as above
	virtual void Set_Window(unsigned int key, HWND window) = 0; // RA2: as above
	virtual bool Is_Done(void) = 0; // RA2: as above
	virtual HWND Get_Window(void) = 0; // RA2: as above
	virtual bool Is_Cancelled(void) = 0; // RA2: as above
};
class SimpleDialogControl : public DialogControl { // RA2: vtable 0x007A7B40
public:
	SimpleDialogControl(void); // RA2: 0x006010C0, defined in another file
	virtual ~SimpleDialogControl(void); // RA2: 0x006010E0, as above
	virtual void Set_Window(unsigned int key, HWND window); // RA2: 0x006010F0
	virtual bool Is_Done(void); // RA2: 0x00601170, reads the byte at +8
	virtual HWND Get_Window(void); // RA2: 0x00601180, returns the dword at +4 (the dialogs store their answer there)
	virtual bool Is_Cancelled(void); // RA2: 0x00601190
	HWND window; // RA2: +0x04
	bool IsDone; // RA2: +0x08
};
int __fastcall Controlled_Dialog(int resource, DLGPROC procedure, DialogControl * control); // RA2: 0x006011A0, runs the dialog until its control reports; defined in ownrdraw.cpp
}
class SimpleWonlineDialogControl : public OwnerDraw::SimpleDialogControl { // RA2: vtable 0x007AF6F4
public:
	SimpleWonlineDialogControl(void); // RA2: 0x0073C000 (the base constructor and the vtable) // level-2 1.001: 0x00730B80, defined out of line next to the destructor (the executable keeps a copy that nobody calls)
	virtual ~SimpleWonlineDialogControl(void); // RA2: 0x0073C020, called out of line by Connect_To_Server (stores the vtable, jumps to the base destructor); declared only, its copy lies before the module. Login_Wonline expands it (0x00742FD0 shows the vtable store and the base destructor call): the executable decides differently there, see the note at Login_Wonline
	virtual bool Is_Cancelled(void) {return(WOL_Wait_Callback());} // level-2 1.001: 0x00730BB0 (vtable 0x0079A584 slot 4 is this jump to WOL_Wait_Callback 0x00732A40, emitted after the destructor 0x00730BA0); also the inline call sites of Login_Wonline's login loop
};
BOOL CALLBACK Locale_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 0x00751190, the country dialog (0xFE)

Wstring Server_Name_Without_Prefix(Server const * server); // RA2: 0x00745450, defined below

// RA2: the executable calls Dictionary<Wstring, int>::add 0x00766070, ::remove(key, value) 0x007675E0 and ::getPointer 0x00767570 out of line from Connect_To_Server (meastes keeps them as non-inline members of the name set, defined in other files); these explicit specializations carry the template's own statements and are never expanded (auto_inline off), so the executable's copies are emitted here and match; replaces the Update_Locale layers and the Get_Locale_Pointer wrapper



int Ask_Locale(void) // level-2 1.001: 0x0073F880, also out of line (that copy has no caller) // RA2: the dialog (0xFE, Locale_Dialog_Proc 0x00751190) that asks for the country of the persona; the control is destroyed on each way out (debt: its real name and form are not known, two returns give the executable's two copies of the destructor call)
{
	SimpleWonlineDialogControl control; // RA2: vtable 0x007AF6F4, constructed by 0x006010C0, destroyed by 0x0073C020
	int answer = OwnerDraw::Controlled_Dialog(0xFE, Locale_Dialog_Proc, &control); // RA2: as above
	if (answer < 0) { // RA2: cancelled
		return(0);
	}
	return(answer);
}


static inline char Get_Locale_Pointer(Wstring const & name, int ** value) { return g_UserLocales.getPointer(name, value); } // RA2: a wrapper layer (debt: its real name is not known); the executable calls Dictionary::getPointer 0x00767570 out of line here; an explicit specialization of getPointer (auto_inline off) does that too but also changes User_Tooltip 0x0073F250 and Draw_Player_List 0x0073FEE0, which expand it

int __fastcall Wait_For_Wait_Event(int seconds, int count);

bool Connect_To_Server(Server * server) // RA2: 0x007424C0, not in TibSun (its Login_WOL did this): logs in to the chat server with the persona and password, waits for the answer (30 seconds, 20 rounds), reads the profile of the persona, tells the ladder server about it and settles the locale of the persona; matches (2192 bytes) with the out-of-line derived destructor and the out-of-line Dictionary calls above
{
	strcpy((char *)server->login, g_NickName.get()); // RA2: the persona and the password go into the server entry
	strcpy((char *)server->password, g_LoginPassword.get()); // RA2: as above
	Reset_All_Wait_Events(); // level-2 1.001: clear every wait event
	{
		WideWstring connecting(StringTable::LoadString("TXT_CONNECTING_SERVER", NULL, "C:\\RA2\\wonline.cpp", 7215)); // RA2: the wait dialog takes a wide text // level-2 1.001: line literal
		Show_Wait_Window(0x10, connecting, false); // RA2: as above
	}
	g_pChat->RequestConnection(server, 20, ((int &)g_PlaintextPassword) & 0xFF); // RA2: virtual 0x14

	int attempts = 20; // RA2: rounds of the wait
	for (;;) { // RA2: as above
		int event = Wait_For_Wait_Event(30, EV_COUNT); // level-2 1.001: thirty seconds per wait
		if (event == EV_ABORT) { // RA2: as above
			Close_Wait_Window(0xFFFFFFFF); // RA2: as above
			return(false);
		}
		if (event == EV_ERROR) { // RA2: as above
			ODMessageBox(StringTable::LoadString("TXT_CANT_CONNECT", NULL, "C:\\RA2\\wonline.cpp", 7228), 0, Wait_Callback_Thunk); // RA2: as above // level-2 1.001: line literal
			Close_Wait_Window(0xFFFFFFFF); // RA2: as above
			return(false);
		}
		if (event == EV_COUNT) { // RA2: as above
			Close_Wait_Window(0xFFFFFFFF); // RA2: as above
			return(false);
		}
		if (attempts-- < 0) { // RA2: as above
			ODMessageBox(StringTable::LoadString("TXT_CANT_CONNECT", NULL, "C:\\RA2\\wonline.cpp", 7235), 0, Wait_Callback_Thunk); // RA2: as above // level-2 1.001: line literal
			Close_Wait_Window(0xFFFFFFFF); // RA2: as above
			return(false);
		}
		if (event == EV_CONNECTED) { // RA2: as above
			break;
		}
	}
	Close_Wait_Window(0xFFFFFFFF); // RA2: as above
	g_pChat->SetClientVersion(0x1000E); // RA2: virtual 0xD4
	g_IgnoreNetStatus = false; // RA2: as above
	Session.Read_MultiPlayer_Settings(); // RA2: as above

	WOLOptionsClass options; // RA2: the constructor of wolopt.h clears both members
	options.Load(); // RA2: then Load is called, as 0x004FF200 shows
	rc_ptr<PlayerProfile> profile; // RA2: as above
	if (options.Is_Bit1_Clear()) { // RA2: as above
		profile = PlayerProfile::Load(g_NickName); // RA2: the persona's own profile
	} else {
		profile = g_PlayerProfile.Get(); // RA2: the profile of Reset_WOL_Globals
	}
	if (Online_Session_State == 3 || Online_Session_State == 4) { // RA2: as above
		{
			Wstring name(Server_Name_Without_Prefix(server)); // RA2: as above
			profile->SetName(&name); // RA2: the server's name is kept in the profile
		}
		if (options.Is_Bit1_Clear()) { // RA2: as above
			profile->Save(&g_NickName); // RA2: as above
		}
	}
	strcpy(Session.Handle, g_NickName.get()); // RA2: as above
	Session.Set_Side(profile->Country, false); // RA2: as above
	Session.Set_Color(profile->Color, false); // RA2: as above
	Session.Write_MultiPlayer_Settings(); // RA2: as above
	WOL_Set_Last_Valid_Persona(g_NickName); // RA2: as above
	if (g_pNetUtil && strlen(g_LadderAddress)) { // RA2: as above
		g_pNetUtil->RequestLadderList(g_LadderAddress, g_LadderPort, g_NickName.get(), g_GameSKU & 0xFFFF00, -1, 0, 0); // RA2: virtual 0x14
	}
	Reset_All_Wait_Events(); // level-2 1.001: clear every wait event
	User user;
	memset(&user, 0, sizeof(user)); // RA2: as above
	strcpy((char *)user.name, g_NickName.get()); // RA2: as above
	g_pChat->RequestUserLocale(&user); // RA2: virtual 0xBC
	for (;;) { // RA2: the second wait, for the locale
		int event = Wait_For_Wait_Event(30, EV_COUNT); // level-2 1.001: thirty seconds per wait
		if (event == EV_ABORT) { // RA2: as above
			Close_Wait_Window(0xFFFFFFFF); // RA2: as above
			break;
		}
		if (event == EV_ERROR) { // RA2: as above
			ODMessageBox(StringTable::LoadString("TXT_WDT_NET_ERR", NULL, "C:\\RA2\\wonline.cpp", 7319), 0, Wait_Callback_Thunk); // RA2: as above // level-2 1.001: line literal
			Close_Wait_Window(0xFFFFFFFF); // RA2: as above
			break;
		}
		if (event == EV_COUNT) { // RA2: as above
			Close_Wait_Window(0xFFFFFFFF); // RA2: as above
			break;
		}
		if (event == EV_LOCALE) { // RA2: as above
			break;
		}
	}

	Wstring const & nick_source = g_NickName; // RA2: the const overload of toLower
	Wstring nick = nick_source.toLower(); // RA2: the locales are kept by lower case name
	if (g_UserLocales.contains(nick)) { // RA2: the server answered for the persona
		int locale = 0; // RA2: as above
		{
			int * value = NULL; // RA2: as above
			if (Get_Locale_Pointer(nick, &value) && value != NULL) { // RA2: as above
				locale = *value; // RA2: as above
			}
		}
		if (locale != 0) { // RA2: the server already knows a locale: make the profile agree with it and tell the server the profile's
			if (profile.Get() != NULL && profile->Locale != locale) { // RA2: as above
				if (profile->Locale == 0) { // RA2: the profile had none yet
					profile->SetLocale(locale, 2); // RA2: as above
					profile->Save(&g_NickName); // RA2: as above
				}
				int current = profile->Locale; // RA2: read once into a register (the executable uses esi)
				g_pChat->RequestSetLocale((Locale)current); // RA2: virtual 0xB8
				g_pChat->RequestUserLocale(&user); // RA2: virtual 0xBC
				locale = current; // RA2: the executable keeps the new locale in esi and stores it only here, for the update
				g_UserLocales.updateValue(nick, locale); // RA2: Dictionary::remove then ::add (calls 0x007675E0 and 0x00766070)
			}
			return(true);
		}
	}
	int chosen = 0; // RA2: the locale of the second path
	if (profile.Get() == NULL || (chosen = profile->Locale) == 0) { // RA2: no locale known anywhere: ask the player
		chosen = Ask_Locale(); // RA2: as above
		if (profile.Get() != NULL) { // RA2: as above
			profile->SetLocale(chosen, 3); // RA2: as above
			profile->Save(&g_NickName); // RA2: as above
		}
	}
	if (chosen != 0) { // RA2: as above
		g_pChat->RequestSetLocale((Locale)chosen); // RA2: as above
		g_pChat->RequestUserLocale(&user); // RA2: as above
		int stored = chosen; // RA2: Dictionary::updateValue takes a reference: the value goes through a variable of its own
		g_UserLocales.updateValue(nick, stored); // RA2: as above
	}
	return(true);
}

// level-2 1.001: g_Servers is defined with the other globals at the top of the file (an extern after the definition makes VC6 emit its initializer a second time)
extern HRESULT g_OnConnectionResult; // RA2: 0x00B2AC10, the result of the last connection (the chat event sink stores it)

bool Connect_To_Selected_Server(void) // RA2: 0x00742D50, not in TibSun: connects to the server of the list the player picked, false when the index is not in the list
{
	if (g_CurrentServerIndex >= 1 && g_CurrentServerIndex < g_Servers.length()) { // RA2: as above
		Server * server = NULL; // RA2: as above
		g_Servers.getPointer(&server, g_CurrentServerIndex); // RA2: as above
		return(Connect_To_Server(server)); // RA2: a jump to Connect_To_Server
	}
	return(false); // RA2: as above
}

bool Recall_Stored_Login(Wstring const & name) // RA2: 0x00742D80, not in TibSun: looks the persona up among the 32 logins the chat API remembers; keeps its nickname and password when it is there, else clears the nickname
{
	g_LoginPassword.clear(); // RA2: as above
	for (int index = 1; index <= 32; index++) { // RA2: as above
		char const * nickname; // RA2: not cleared, the chat API sets both when it succeeds
		char const * password; // RA2: as above
		if (g_pChat->GetNick(index, &nickname, &password) == 0 && nickname && strlen(nickname) && !stricmp(name.text(), nickname)) { // RA2: as above
			g_NickName = nickname; // RA2: as above
			g_LoginPassword = password; // RA2: as above
			g_PlaintextPassword = false; // RA2: as above
			return(true); // RA2: as above
		}
	}
	g_NickName.clear(); // RA2: as above
	return(false); // RA2: as above
}

int Find_Server_Suffix(Wstring const & name) // RA2: 0x00742E30, not in TibSun: the index of the server whose name is "<prefix>:" followed by this name, -1 when there is none
{
	if (name.length() != 0) { // RA2: as above
		for (int i = 1; i < g_Servers.length(); i++) { // RA2: as above
			Server * server = NULL; // RA2: as above
			g_Servers.getPointer(&server, i); // RA2: as above
			char * separator = strchr((char *)server->name, ':'); // RA2: as above
			if (separator && *separator && name == (separator + 1)) { // RA2: as above
				return(i);
			}
		}
	}
	return(-1); // RA2: as above
}

static const HRESULT CHAT_E_BANNED = (HRESULT)0x80040072; // RA2: the answers of the chat server that have a support page; the page names say which is which (banned_, disabled_, serialbanned_, serialdup_, serialunknown_, skuserialmismatch_)
static const HRESULT CHAT_E_DISABLED = (HRESULT)0x80040074; // RA2: as above
static const HRESULT CHAT_E_SERIALBANNED = (HRESULT)0x80040075; // RA2: as above
static const HRESULT CHAT_E_SERIALDUP = (HRESULT)0x80040076; // RA2: as above
static const HRESULT CHAT_E_SERIALUNKNOWN = (HRESULT)0x80040077; // RA2: as above
static const HRESULT CHAT_E_SKUSERIALMISMATCH = (HRESULT)0x80040078; // RA2: as above

bool Handle_Connection_Error(void) // RA2: 0x00742EB0, not in TibSun: shows the error text of the failed connection; for the answers that have a support page it asks whether to open it and does so (4 is the yes/no kind). True when the answer was one of those
{
	bool handled = false; // RA2: as above
	char url[260]; // RA2: as above
	if (g_OnConnectionResult == CHAT_E_SERIALUNKNOWN || g_OnConnectionResult == CHAT_E_SKUSERIALMISMATCH || g_OnConnectionResult == CHAT_E_BANNED || g_OnConnectionResult == CHAT_E_DISABLED || g_OnConnectionResult == CHAT_E_SERIALBANNED || g_OnConnectionResult == CHAT_E_SERIALDUP) { // RA2: as above
		handled = true; // RA2: as above
		if (ODMessageBox(g_LastErrorMessage, 4, Wait_Callback_Thunk, false) == 6) { // RA2: IDYES
			int language = g_LanguageCode; // RA2: the support pages exist per language
			switch (g_OnConnectionResult) { // RA2: as above
			case CHAT_E_SERIALUNKNOWN: sprintf(url, "http://apiregister.westwood.com/support/serialunknown_%d.html", language); break; // RA2: as above
			case CHAT_E_SKUSERIALMISMATCH: sprintf(url, "http://apiregister.westwood.com/support/skuserialmismatch_%d.html", language); break; // RA2: as above
			case CHAT_E_BANNED: sprintf(url, "http://apiregister.westwood.com/support/banned_%d.html", language); break; // RA2: as above
			case CHAT_E_DISABLED: sprintf(url, "http://apiregister.westwood.com/support/disabled_%d.html", language); break; // RA2: as above
			case CHAT_E_SERIALBANNED: sprintf(url, "http://apiregister.westwood.com/support/serialbanned_%d.html", language); break; // RA2: as above
			case CHAT_E_SERIALDUP: sprintf(url, "http://apiregister.westwood.com/support/serialdup_%d.html", language); break; // RA2: as above
			}
			ViewHTML(url, 1); // RA2: as above
		}
	} else {
		ODMessageBox(g_LastErrorMessage, 0, Wait_Callback_Thunk, false); // RA2: as above
	}
	return(handled); // RA2: as above
}

int __fastcall Request_And_Wait_Server_List(unsigned int flags); // RA2: 0x00751C30, asks for the list of chat servers and waits for it (0 done, 1 failed, 2 quit), not yet defined
LRESULT CALLBACK Wonline_Account_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 0x007540A0, the dialog proc of the login dialog (0x10F, 0x11D)
LRESULT CALLBACK Wonline_Autologin_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 0x00755070, the dialog proc of the dialog (0x112) after a login
extern bool g_RememberLogin; // RA2: 0x00B2AC74, the login is to be kept in the chat service's list of logins (set by the login dialog)
int Save_Nickname(char const * name, char const * password, bool mangle, int locale); // RA2: 0x00745320, defined below
void Darken_Surface(Surface * surface, bool update); // RA2: 0x005159B0, defined in init.cpp

static inline void Set_Login_Focus(HWND window) // RA2: the login dialog puts the focus on the password box (0x72C) when a nickname is known, else on the name box (0x628); the executable has both SetFocus calls with a merged tail
{
	if (g_NickName.length() > 0 && g_LoginPassword.length() == 0) { // RA2: as above
		SetFocus(GetDlgItem(window, 0x72C)); // RA2: as above
	} else {
		SetFocus(GetDlgItem(window, 0x628)); // RA2: as above
	}
}

int Fetch_Server_List(void) // level-2 1.001: 0x00740310, also out of line (that copy has no caller) // RA2: shows "fetching the server list" and requests the list for the product (0x2300 in a tournament session, else 0x2100)
{
	{
		WideWstring fetching(StringTable::LoadString("TXT_FETCHING_SERVLIST", NULL, "C:\\RA2\\wonline.cpp", 15732)); // RA2: as above // level-2 1.001: line literal
		Show_Wait_Window(16, fetching, false); // RA2: as above
	}
	int sku = 0x2300; // RA2: as above
	if (Online_Session_State != 2) { // RA2: as above
		sku = 0x2100; // RA2: as above
	}
	return(Request_And_Wait_Server_List(sku)); // RA2: as above
}

SimpleWonlineDialogControl::SimpleWonlineDialogControl(void) {} // level-2 1.001: 0x00730B80, expanded at every use

SimpleWonlineDialogControl::~SimpleWonlineDialogControl(void) {} // RA2: 0x0073C020 // level-2 1.001: expandable: Join_Game_Channel 0x339BD0 and Login_Wonline 0x337590 expand it (Login_Wonline's expansions keep ArrayList<Server>::getPointer 0x352310 out of line); 1.001 Connect_To_Server 0x336A80 calls it out of line twice and matches only with auto_inline(off) here (open: an inline-budget difference)

int __fastcall Login_Wonline(void) // RA2: 0x00742FD0, not in TibSun: logs in to Westwood Online: starts the chat services, fetches the server list, tries the stored login of the auto login persona, else opens the login dialog (the executable's debug text says "Creating login dlg") and connects to the server the persona's profile names; 1 when connected, 0 when not, negative when the server list could not be fetched; level-2 1.001 (b14): byte-identical (1728 bytes, 0x337590) with the binary's tournament branch (no profile lookup) and both WOL_Wait_Callback calls written as the control's Is_Cancelled override (two inline sites: they keep ArrayList<Server>::getPointer 0x00752310 out of line in the first two expansions); the two return(1) of the connected path (the second after the auto-login question) give 1.001's register split (zero in ebp outside the dialog, the control vtable in ebx inside it)
{
	bool failed = false; // RA2: as above
	g_OnConnectionResult = 0; // RA2: as above
	int result = Init_Wonline(); // RA2: as above
	if (result != 1) { // RA2: as above
		return(result); // RA2: as above
	}
	{ // RA2: the lists of the last session are cleared before the login
	memset(&g_CurrentChannel, 0, sizeof(g_CurrentChannel)); // RA2: as above
	memset(&g_PendingChannel, 0, sizeof(g_PendingChannel)); // RA2: as above
	g_UserChannels.clear(); // RA2: as above
	g_GameChannelList.clear(); // RA2: as above
	g_UserList.clear(); // RA2: as above
	g_ChannelCount = 0; // RA2: as above
	result = 0; // RA2: as above
	int error = Fetch_Server_List(); // RA2: as above
	switch (error) { // RA2: as above
	case 0: // RA2: as above
		break; // RA2: as above
	case 2: // RA2: as above
		failed = true; // RA2: as above
		result = -1; // RA2: as above
		break; // RA2: as above
	default: // RA2: as above
		failed = true; // RA2: as above
		result = -2; // RA2: as above
		break; // RA2: as above
	}
	WOLOptionsClass options; // RA2: as above
	options.Load(); // RA2: as above
	if (!failed) { // RA2: as above
		if (options.Is_Bit0_Clear()) { // RA2: the auto login is on
			Wstring persona = WOL_Auto_Login_Persona(); // RA2: as above
			if (persona.length() > 0) { // RA2: as above
				if (Recall_Stored_Login(persona)) { // RA2: expanded here
					int index = -1; // RA2: as above
					if (Is_Tournament_Session()) { // RA2: an Internet game
						index = g_CurrentServerIndex; // level-2 1.001 (b9/b14): no profile lookup in a tournament session (0x1A2-0x1B9 jumps straight to the index test)
					} else {
						rc_ptr<PlayerProfile> profile = PlayerProfile::Load(persona); // RA2: as above
						if (profile.Get()) { // RA2: as above
							if (profile->Name.length() == 0) { // RA2: as above
								index = g_CurrentServerIndex; // RA2: as above
							} else {
								index = Find_Server_Suffix(profile->Name); // RA2: expanded here
							}
						}
					}
					if (index != -1) { // RA2: as above
						g_CurrentServerIndex = index; // RA2: as above
						if (Connect_To_Selected_Server()) { // RA2: expanded here
							return(1); // RA2: as above
						}
						failed = Handle_Connection_Error(); // RA2: as above
					}
				}
			}
		}
		if (g_NickName.length() == 0 && options.Is_Bit1_Clear()) { // RA2: as above
			g_NickName = WOL_Last_Valid_Persona(); // RA2: as above
		}
		{
			Wstring empty(""); // RA2: as above
			WOL_Set_Auto_Login_Persona(empty); // RA2: the auto login is used once
		}
		if (failed) { // RA2: as above
			return(0); // RA2: as above
		}
		DebugString("Creating login dlg\n"); // RA2: as above
		SimpleWonlineDialogControl control; // RA2: as above
		int dialog_id = options.Is_Bit1_Clear() ? 0x10F : 0x11D; // RA2: as above
		Darken_Surface(NULL, true); // RA2: as above
		HWND window = OwnerDraw::Begin_Dialog(dialog_id, (DLGPROC)Wonline_Account_Dialog_Proc, (LPARAM)&control); // RA2: as above
		OwnerDraw::Display_Dialog(window); // RA2: as above
		Set_Login_Focus(window); // RA2: as above
		while (!control.Is_Done() && !control.Is_Cancelled() && !OwnerDraw::Dialog_Message_Handler()) { // RA2: as above // level-2 1.001 (b9): the control's own override (same call); one inline site of the dead-probe gauge
			Title_Screen_Restore(false); // RA2: as above
		}
		OwnerDraw::End_Dialog(window); // RA2: as above
		if ((int)control.Get_Window() == 2) { // RA2: the dialog was cancelled
			failed = true; // RA2: as above
		} else {
			control.Is_Cancelled(); // RA2: as above // level-2 1.001 (b14): the control's override, the same WOL_Wait_Callback call; the second inline site of the gauge
			g_IgnoreNetStatus = false; // RA2: as above
			WOLOptionsClass saved; // RA2: as above
			saved.Load(); // RA2: as above
			rc_ptr<PlayerProfile> profile; // RA2: as above
			if (saved.Is_Bit1_Clear()) { // RA2: as above
				profile = PlayerProfile::Load(g_NickName); // RA2: as above
			} else {
				profile = g_PlayerProfile.Get(); // RA2: as above
			}
			int found = Find_Server_Suffix(profile->Name); // RA2: expanded here
			if (found != -1) { // RA2: as above
				g_CurrentServerIndex = found; // RA2: as above
			}
			if (g_CurrentServerIndex >= g_Servers.length()) { // RA2: as above
				g_CurrentServerIndex = -1; // RA2: as above
			}
			if (g_CurrentServerIndex == -1 && g_Servers.length() > 1) { // RA2: as above
				g_CurrentServerIndex = 1; // RA2: as above
			}
			if (Connect_To_Selected_Server()) { // RA2: expanded here
				if (g_RememberLogin && saved.Is_Bit1_Clear()) { // RA2: the login is kept for the next time
					int locale = profile->Locale; // RA2: read before the nickname is saved (0x00742FD0)
					Save_Nickname(g_NickName.get(), g_LoginPassword.get(), g_PlaintextPassword, locale); // RA2: as above
					Session.Write_MultiPlayer_Settings(); // RA2: as above
				}
				if (!saved.Is_Bit0_Clear() || !WOL_Get_Auto_Login()) { // RA2: no auto-login question unless the profile allows it and auto-login is on
					return(1); // RA2: as above
				}
				Darken_Surface(NULL, true); // RA2: as above
				SimpleWonlineDialogControl next; // RA2: as above
				OwnerDraw::Controlled_Dialog(0x112, (DLGPROC)Wonline_Autologin_Dialog_Proc, &next); // RA2: as above
				return(1); // RA2: as above
			}
		}
	}
	Close_Wait_Window(0xFFFFFFFF); // RA2: expanded here
	if (!failed) { // RA2: as above
		Handle_Connection_Error(); // RA2: as above
	}
	g_IgnoreNetStatus = true; // RA2: as above
	} // RA2: as above
	return(result); // RA2: as above
}

void Reset_Wait_Events(void) // RA2: 0x00752930, not in TibSun: resets every wait event
{
	for (int i = 0; i < EV_COUNT; i++) { // RA2: as above
		ResetEvent(g_WaitEventHandles[i]); // RA2: as above
	}
}

// RA2: declarations for the functions below (placed after Draw_Player_List: declarations above it change its code)
#include "ccfile.h" // RA2: WDTMAP.INI is read through the game's file system by Pick_Lobby
#include "mixfile.h" // RA2: and WDT.MIX is opened
#include "_pk.h" // RA2: FastKey
#include "wdtnet.h" // RA2: the state of the tour
extern int g_LobbyNumber; // RA2: 0x00B2ABEC, the number of the lobby channel ("Lob_33_<number>") joined last
extern wchar_t * g_TerritoryName; // RA2: 0x00B28CC8, the name of the WDT territory of this player ("A territory" when the map INI has none), a copy made by _wcsdup
rc_ptr<WDTState> const & __fastcall Current_WDT_State(void); // RA2: 0x00769510, defined in worlddom.cpp

bool Leave_Current_Channel(unsigned int event, bool block) // RA2: 0x00744610, not in TibSun: leaves the channel the chat is in, waits up to 15 seconds for the server to confirm; true when no channel is left
{
	if (g_ChannelCount) { // RA2: as above
		DebugString("Leave_Channel, channel %s type %d\n", g_CurrentChannel.name, g_CurrentChannel.type); // RA2: as above
		g_pChat->RequestChannelLeave(); // RA2: virtual 0x24
		{
			WideWstring title(StringTable::LoadString("WOL:LeavingChannel", NULL, "C:\\RA2\\wonline.cpp", 8207)); // RA2: the wait dialog takes a wide text // level-2 1.001: line literal
			Show_Wait_Window(event, title, block); // RA2: as above
		}
		for (int i = 0; g_ChannelCount && i < 150; i++) { // RA2: 150 steps of 100 ms
			Sleep(100); // RA2: as above
			WOL_Wait_Callback(); // RA2: as above
		}
		Close_Wait_Window(0x40); // RA2: expanded here
	}
	return(g_ChannelCount == 0); // RA2: as above
}

int Request_Channel_Join(Channel * channel, Wstring const & password, WideWstring title) // RA2: 0x00744700, not in TibSun: joins a channel (leaves the current one first); title is the text of the wait dialog; the chat's answer, 1 when the old channel could not be left
{
	char const * name = (char const *)channel->name; // RA2: as above
	if (strcmp(name, (char const *)g_CurrentChannel.name) && strcmp(name, (char const *)g_PendingChannel.name)) { // RA2: not the channel the chat is in nor the one it was asked to join
		if (g_ChannelCount) { // RA2: as Leave_Current_Channel
			DebugString("Leave_Channel, channel %s type %d\n", g_CurrentChannel.name, g_CurrentChannel.type); // RA2: as above
			g_pChat->RequestChannelLeave(); // RA2: as above
			{
				WideWstring leaving(StringTable::LoadString("WOL:LeavingChannel", NULL, "C:\\RA2\\wonline.cpp", 8207)); // RA2: as above // level-2 1.001: line literal
				Show_Wait_Window(0x40, leaving, true); // RA2: as above
			}
			for (int i = 0; g_ChannelCount && i < 150; i++) { // RA2: as above
				Sleep(100); // RA2: as above
				WOL_Wait_Callback(); // RA2: as above
			}
			Close_Wait_Window(0x40); // RA2: expanded here
			if (g_ChannelCount) { // RA2: the channel was not left
				return(1); // RA2: as above
			}
		}
		strcpy((char *)channel->key, password.text()); // RA2: as above
		g_PendingChannel = *channel; // RA2: as above
		{
			WideWstring message(title.text()); // RA2: as above
			Show_Wait_Window(2, message, false); // RA2: as above
		}
		DebugString("Requesting channel join %s\n", name); // RA2: as above
		return g_pChat->RequestChannelJoin(channel); // RA2: virtual 0x20
	}
	return(0); // RA2: as above
}

// level-2 1.001: STEERING place the lobby selector beside its caller to preserve the two reloads after the first channel copy.
int Pick_Lobby(bool require_room) // RA2: 0x00744090, not in TibSun: chooses the lobby channel to join. In a World Domination Tour game it is the one that carries the player's territory; else the lobby that was joined last, else the lobby with the fewest players that still has room; the index in the channel list, -1 when there is none
{
	int count = g_UserChannels.length(); // RA2: as above
	Channel channel; // RA2: as above
	memset(&channel, 0, sizeof(channel)); // RA2: as above
	char section[32]; // RA2: the INI sections of the territory
	char entry[32]; // RA2: as above
	char fallback[32]; // RA2: as above
	char name[32]; // RA2: as above
	wchar_t territory[32]; // RA2: the name of the territory, wide
	if (Session.Type == GAME_INTERNET && Online_Session_State == 2) { // RA2: a World Domination Tour game
		memset(section, 0, sizeof(section)); // RA2: as above
		memset(territory, 0, 32); // RA2: only the first 32 bytes
		memset(entry, 0, sizeof(entry)); // RA2: as above
		memset(fallback, 0, sizeof(fallback)); // RA2: as above
		MixFileClass * archive = new MixFileClass("WDT.MIX", &FastKey); // RA2: the tour's archive is open while the INI is read
		{
			INIClass ini; // RA2: as above
			CCFileClass file("WDTMAP.INI"); // RA2: as above
			ini.Load(file, false); // RA2: as above
			sprintf(entry, "Territory%02d", Session.TournamentTerritory); // RA2: as above
			strcpy(fallback, entry); // RA2: as above
			if (Current_WDT_State()->MapID == 0) { // RA2: the map decides which of the two sections names the territory
				ini.Get_String("NorthAmerica", entry, fallback, section, sizeof(section)); // RA2: as above
			} else {
				ini.Get_String("Europe", entry, fallback, section, sizeof(section)); // RA2: as above
			}
			ini.Get_String(section, "Name", "A territory", name, sizeof(name)); // RA2: as above
			Char_To_Wide(territory, name, -1); // RA2: as above
			g_TerritoryName = _wcsdup(territory); // RA2: as above
			delete archive; // RA2: as above
		}
	}
	Wstring lobby_name = Wstring("Lob_33_") + Wstring_FromInt(g_LobbyNumber); // RA2: the lobby that was joined last // level-2 1.001: plain "%d" form
	int i; // RA2: as above
	for (i = 0; i < count; i++) { // RA2: the territory's lobby or the one joined last
		g_UserChannels.get(channel, i); // RA2: as above
		if (Session.Type == GAME_INTERNET && Online_Session_State == 2) { // RA2: as above
			if (wcscmp((wchar_t const *)g_Lobbies[i], territory) != 0) { // RA2: as above
				continue; // RA2: as above
			}
			if (!require_room || (int)channel.currentUsers <= 25) { // RA2: 25 players per lobby
				return(i); // RA2: as above
			}
		}
		Wstring channel_name((char const *)channel.name); // RA2: as above
		if (channel_name == lobby_name) { // RA2: as above
			if (!require_room || (int)channel.currentUsers <= 25) { // RA2: as above
				return(i); // RA2: as above
			}
		}
	}
	int best = -1; // RA2: the lobby with the fewest players
	unsigned int smallest = 10000; // RA2: as above
	for (i = 0; i < count; i++) { // RA2: as above
		g_UserChannels.get(channel, i); // RA2: as above
		if (Session.Type == GAME_INTERNET && Online_Session_State == 2) { // RA2: as above
			if (wcsncmp((wchar_t const *)g_Lobbies[i], territory, wcslen(territory)) != 0) { // RA2: as above
				continue; // RA2: as above
			}
			if (!require_room || (int)channel.currentUsers <= 25) { // RA2: as above
				g_LobbyNumber = atol((char const *)channel.name + strlen("Lob_33_")); // RA2: the number is remembered
				return(i); // RA2: as above
			}
			if (channel.currentUsers < smallest) { // RA2: as above
				best = i; // RA2: as above
				smallest = channel.currentUsers; // RA2: as above
			}
		}
		if (strncmp((char const *)channel.name, "Lob_33_", strlen("Lob_33_")) == 0) { // RA2: as above
			if (!require_room || (int)channel.currentUsers <= 25) { // RA2: as above
				g_LobbyNumber = atol((char const *)channel.name + strlen("Lob_33_")); // RA2: as above
				return(i); // RA2: as above
			}
			if (channel.currentUsers < smallest) { // RA2: as above
				best = i; // RA2: as above
				smallest = channel.currentUsers; // RA2: as above
			}
		}
	}
	if (best != -1) { // RA2: as above
		g_UserChannels.get(channel, best); // RA2: as above
		g_LobbyNumber = atol((char const *)channel.name + strlen("Lob_33_")); // RA2: as above
	}
	return(best); // RA2: as above
}

int Join_Selected_Lobby(bool join) // RA2: 0x00744930, not in TibSun: joins the lobby channel Pick_Lobby chose (the argument is its "needs room" flag); the lobby's index, -1 when none was picked or the join was refused
{
	int choice = Pick_Lobby(join); // RA2: as above
	if (choice != -1) { // RA2: as above
		Channel channel; // RA2: as above
		g_UserChannels.get(channel, choice); // RA2: as above
		int result; // RA2: as above
		{
			Wstring password("zotclot9"); // RA2: the password of the lobby channels
			result = Request_Channel_Join(&channel, password, WideWstring(StringTable::LoadString("TXT_JOINLOB", NULL, "C:\\RA2\\wonline.cpp", 8256))); // RA2: the wait text is passed by value // level-2 1.001: line literal
		}
		if (!result) { // RA2: as above
			HWND dialog = WS_Find_Dialog(0x113); // RA2: the game list dialog gets the focus
			if (dialog) { // RA2: as above
				SetFocus(GetDlgItem(dialog, 1344)); // RA2: as above
			}
			Refresh_Game_List(); // RA2: as above
			return(choice); // RA2: as above
		}
	}
	Refresh_Game_List(); // RA2: as above
	return(-1); // RA2: as above
}

int Save_Nickname(char const * name, char const * password, bool mangle, int locale) // RA2: 0x00745320, not in TibSun: stores the persona in the chat API's list of 32 logins (the slot it already has, else an empty one, else the next of a round robin) and its locale; the slot
{
	int slot = 0; // RA2: as above
	char const * nick; // RA2: as above
	char const * stored; // RA2: as above
	for (int i = 1; i <= 32; i++) { // RA2: the slot that already holds the persona
		nick = NULL; // RA2: as above
		stored = NULL; // RA2: as above
		if (g_pChat->GetNick(i, &nick, &stored) == 0 && nick && !strcmp(nick, name)) { // RA2: as above
			slot = i; // RA2: as above
			break; // RA2: as above
		}
	}
	if (slot == 0) { // RA2: else the first empty one
		for (int i = 1; i <= 32; i++) { // RA2: as above
			nick = NULL; // RA2: as above
			stored = NULL; // RA2: as above
			if (g_pChat->GetNick(i, &nick, &stored) == 0 && (!nick || strlen(nick) == 0)) { // level-2 1.001: a failed GetNick skips the slot
				slot = i; // RA2: as above
				break; // RA2: as above
			}
		}
	}
	if (slot == 0) { // RA2: else the next slot in turn
		int next = Session.LastNicknameSlot; // RA2: as above
		if (next == -1) { // RA2: as above
			next = 1; // RA2: as above
		}
		slot = next++; // RA2: as above
		Session.LastNicknameSlot = next; // RA2: as above
		if (next > 32) { // RA2: as above
			Session.LastNicknameSlot = 1; // RA2: as above
		}
	}
	if (slot) { // RA2: as above
		g_pChat->SetNick(slot, name, password, mangle); // RA2: virtual 0x94
		g_pChat->SetNickLocale(slot, (Locale)locale); // RA2: virtual 0xC8
	}
	return(slot); // RA2: as above
}

Wstring Server_Name_Without_Prefix(Server const * server) // RA2: 0x00745450, not in TibSun: the name of the server after the first colon (the part before it names the kind of server)
{
	Wstring name((char const *)server->name); // RA2: the server's name is copied into a Wstring
	Wstring token; // RA2: as above
	int position = name.getToken(0, ":", token); // RA2: the first token ends at the first colon
	if (position >= 0) { // RA2: as above
		name.remove(0, position + 1); // RA2: as above
	}
	return(name); // RA2: as above
}

#define OD_ADDSTRING_COMBO (WM_USER + 188) // RA2: 0x4BC, appends the string of lParam to an owner drawn combo box and returns its row (name guessed from its use)
int __fastcall Clear_ComboBox(HWND list); // RA2: 0x006007F0, removes every row of an owner drawn combo box, defined in ownrdraw.cpp

bool Populate_Server_Choices(HWND list, bool combo) // RA2: 0x007454C0, not in TibSun: fills a list box (or combo box) with the names of the chat servers and selects the one of the persona's profile; false when the server list is empty
{
	if (combo) { // RA2: as above
		Clear_ComboBox(list); // RA2: as above
	} else {
		Clear_Listbox(list); // RA2: as above
	}
	if (g_Servers.length() == 1) { // RA2: only the entry 0 of the list: no server to choose from
		if (combo) { // RA2: as above
			SendMessage(list, OD_ADDSTRING_COMBO, 0, (LPARAM)"GUI:NoServersAvailable"); // RA2: as above
		} else {
			SendMessage(list, OD_ADDSTRING_LIST, 0, (LPARAM)"GUI:NoServersAvailable"); // RA2: as above
		}
		EnableWindow(list, FALSE); // RA2: as above
		return(false); // RA2: as above
	}
	Wstring preferred; // RA2: the server of the persona's profile
	WOLOptionsClass options; // RA2: as in Connect_To_Server
	options.Load(); // RA2: as above
	rc_ptr<PlayerProfile> profile; // RA2: as above
	if (options.Is_Bit1_Clear()) { // RA2: as above
		profile = PlayerProfile::Load(g_NickName); // RA2: as above
	} else {
		profile = g_PlayerProfile.Get(); // RA2: as above
	}
	if (profile.Get()) { // RA2: as above
		preferred = profile->Name; // RA2: as above
	}
	EnableWindow(list, TRUE); // RA2: as above
	int selected = -1; // RA2: as above
	for (int i = 1; i < g_Servers.length(); i++) { // RA2: as above
		Server * server = NULL; // RA2: as above
		g_Servers.getPointer(&server, i); // RA2: as above
		DebugString("Server found %s\n", (char *)server->name); // RA2: as above
		Wstring display = Server_Name_Without_Prefix(server); // RA2: expanded here
		int row; // RA2: as above
		if (combo) { // RA2: as above
			row = SendMessage(list, OD_ADDSTRING_COMBO, 0, (LPARAM)display.text()); // RA2: as above
			SendMessage(list, CB_SETITEMDATA, row, i); // RA2: as above
		} else {
			row = SendMessage(list, OD_ADDSTRING_LIST, 0, (LPARAM)display.text()); // RA2: as above
			SendMessage(list, LB_SETITEMDATA, row, i); // RA2: as above
		}
		if (preferred.length() > 0) { // RA2: as above
			bool match = ((Wstring const &)preferred).toLower() == ((Wstring const &)display).toLower(); // RA2: the const toLower returns a copy
			if (match) { // RA2: as above
				selected = row; // RA2: as above
				g_CurrentServerIndex = i; // RA2: the server of the profile becomes the one to connect to
				g_TargetServerIndex = i; // RA2: as above
			}
		}
	}
	if (selected == -1) { // RA2: as above
		selected = 0; // RA2: as above
	}
	if (combo) { // RA2: as above
		SendMessage(list, CB_SETCURSEL, selected, 0); // RA2: as above
	} else {
		SendMessage(list, LB_SETCURSEL, selected, 0); // RA2: as above
		SendMessage(list, LB_SETTOPINDEX, selected, 0); // RA2: as above
	}
	return(true); // RA2: as above
}

bool __fastcall Can_Join_Channel(Channel const * channel, bool check); // level-2 1.001: 0x343F10, no observer argument // RA2: 0x00755CD0, whether the player may join the game channel (the version, the full game, the observer slot ...); not yet defined
bool Test_Display_Mode_Dialog(int width, int height); // RA2: 0x00543A70, defined in mainopt.cpp
LRESULT CALLBACK Wonline_Password_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 0x007492D0, the dialog proc of the password dialog (0xE1)
void Darken_Surface(Surface * surface, bool update); // RA2: 0x005159B0, defined in init.cpp
class WonlineStringDialogControl : public SimpleWonlineDialogControl { // RA2: vtable 0x007AF934, the control of the dialogs that ask for a text
public: // RA2: as above
	WonlineStringDialogControl(void) {} // RA2: expanded where it is used
	virtual ~WonlineStringDialogControl(void) {} // RA2: expanded where it is used
	Wstring Text; // RA2: +0x0C, the text the player typed
};
#include "misc.h" // RA2: VideoModeWidth

bool __fastcall Join_Game_Channel(Channel const * channel) // level-2 1.001: 0x339BD0, no observer argument // RA2: 0x00745780, not in TibSun: joins a game channel: tests that the player may (Can_Join_Channel), that the screen is not wider than the game's resolution limit (offering to switch to 800x600 or 640x480), asks for the password of a private game; true when the join was requested
{
	if (!Can_Join_Channel(channel, true)) { // RA2: as above // level-2 1.001: as above
		return(false); // RA2: as above
	}
	unsigned int mode = channel->reserved; // RA2: the flags of the game: the resolution limit
	int maximum = (mode & 0x400) ? 800 : ((mode & 0x200) ? 640 : 1024); // RA2: as above
	if (VideoModeWidth > maximum) { // RA2: the screen is wider than the game allows
		{
			WideWstring warning((mode & 0x400) ? StringTable::LoadString("WOL:ResolutionLimited800", NULL, "C:\\RA2\\wonline.cpp", 8964) : StringTable::LoadString("WOL:ResolutionLimited640", NULL, "C:\\RA2\\wonline.cpp", 8965)); // RA2: as above // level-2 1.001: line literal
			if (ODMessageBox(warning.get(), 4, Wait_Callback_Thunk, true) == 6) { // RA2: IDYES: the screen is switched
				int width = (maximum == 800) ? 800 : 640; // RA2: as above
				int height = (width == 800) ? 600 : 480; // RA2: as above
				if (Test_Display_Mode_Dialog(width, height)) { // RA2: as above
					Options.ScreenWidth = width; // RA2: as above
					Options.ScreenHeight = height; // RA2: as above
					Options.Save_Settings(); // RA2: as above
				}
			}
		}
		if (VideoModeWidth > maximum) { // RA2: as above
			return(false); // RA2: as above
		}
	}
	Wstring password; // RA2: as above
	if (channel->flags & 0x100) { // RA2: a private game: the player types the password
		Darken_Surface(NULL, true); // RA2: as above
		WonlineStringDialogControl control; // RA2: as above
		if (OwnerDraw::Controlled_Dialog(0xE1, (DLGPROC)Wonline_Password_Dialog_Proc, &control) == 2) { // RA2: cancelled
			return(false); // RA2: as above
		}
		password = control.Text; // RA2: as above
		password.replace(" ", "_"); // RA2: spaces are not allowed in the key
	}
	return(Request_Channel_Join((Channel *)channel, password, WideWstring(StringTable::LoadString("TXT_JOINLOB", NULL, "C:\\RA2\\wonline.cpp", 9020))) == 0); // RA2: as above // level-2 1.001: line literal
}

bool __fastcall Is_AI_Entry(NodeNameType * entry); // RA2: 0x005C9370, defined in netshare.cpp
int __fastcall Get_Scenario_Slot_Limit(int index); // RA2: 0x005C65A0, defined in netshare.cpp
extern NodeNameType * LobbyEntries[]; // RA2: 0x00A72D2C, the fixed entries of the lobby (open, closed, ...), as in netshare.cpp

void Update_Channel_Player_Limit(void) // RA2: 0x00749F20, not in TibSun: tells the chat service how many players the game channel takes (the slots that are open or hold players, plus the host) by a "mode #<channel> +l <number>" command, sends the channel info and the number of players with the computer players
{
	int limit = Get_Scenario_Slot_Limit(Session.Options.ScenarioIndex); // RA2: as above // level-2 1.001: no observer slot
	int open_slots = 0; // RA2: as above
	int player_slots = 0; // RA2: the slots held by computer players
	int fixed_slots = 0; // RA2: the slots held by players
	for (int i = 1; i < limit; ++i) { // RA2: the slots the scenario has // level-2 1.001: only these, and only the open entry counts as open
		NodeNameType * entry = Session.Slots[i]; // RA2: as above
		if (entry == LobbyEntries[0]) { // RA2: as above
			++open_slots; // RA2: as above
		} else if (Is_Real_Player_Entry(entry)) { // RA2: as above
			++fixed_slots; // RA2: as above
		} else if (Is_AI_Entry(entry)) { // RA2: as above
			++player_slots; // RA2: as above
		}
	}
	if (g_pChat) { // RA2: as above
		int capacity = open_slots + fixed_slots + 1; // RA2: as above
		player_slots += capacity; // level-2 1.001: the total with the computer players is made at once (it stays in a register)
		Wstring command = Wstring("mode #") + Wstring((char const *)g_CurrentChannel.name) + Wstring(" +l ") + Wstring_FromInt(capacity) + Wstring("\r\n"); // RA2: as above
		g_pChat->RequestRawMessage(command.get()); // RA2: virtual 0x9C
		char info[80]; // RA2: as above
		memset(info, 0, sizeof(info)); // RA2: as above
		Encode_Channel_ExInfo(info); // RA2: as above
		info[40] = 0; // RA2: as above
		g_pChat->SetChannelExInfo(info); // RA2: virtual 0xA8
		g_pChat->Unknown_Virtual_FC(1, player_slots); // RA2: virtual 0xFC
	}
}

extern wchar_t g_PingTooltip[]; // RA2: 0x00B28DE4, the text Player_Ping_Tooltip returns
int __fastcall Find_Slot_By_Name(wchar_t const * name); // RA2: 0x005C8C30, defined in netshare.cpp

wchar_t * __fastcall Player_Ping_Tooltip(wchar_t const * name) // RA2: 0x0074A4E0, not in TibSun: the tooltip of the ping icon of the player of this slot name: "unknown" when no ping is known, else good (below 300), fair (below 500) or poor with the number
{
	int ping = g_PlayerPings[Find_Slot_By_Name(name)]; // RA2: as above
	if (ping < 0) { // RA2: no ping known
		swprintf(g_PingTooltip, StringTable::LoadString("TXT_LATENCY_ICON_TOOLTIP_NOPING", NULL, "C:\\RA2\\wonline.cpp", 14063), name, StringTable::LoadString("TXT_UNKNOWN", NULL, "C:\\RA2\\wonline.cpp", 14063), StringTable::LoadString("TXT_UNKNOWN_PING", NULL, "C:\\RA2\\wonline.cpp", 14063)); // RA2: as above
	} else if (ping < 300) { // RA2: as above
		swprintf(g_PingTooltip, StringTable::LoadString("TXT_LATENCY_ICON_TOOLTIP_PING", NULL, "C:\\RA2\\wonline.cpp", 14065), name, StringTable::LoadString("TXT_GOOD", NULL, "C:\\RA2\\wonline.cpp", 14065), ping); // RA2: as above
	} else if (ping < 500) { // RA2: as above
		swprintf(g_PingTooltip, StringTable::LoadString("TXT_LATENCY_ICON_TOOLTIP_PING", NULL, "C:\\RA2\\wonline.cpp", 14067), name, StringTable::LoadString("TXT_FAIR", NULL, "C:\\RA2\\wonline.cpp", 14067), ping); // RA2: as above
	} else {
		swprintf(g_PingTooltip, StringTable::LoadString("TXT_LATENCY_ICON_TOOLTIP_PING", NULL, "C:\\RA2\\wonline.cpp", 14069), name, StringTable::LoadString("TXT_POOR", NULL, "C:\\RA2\\wonline.cpp", 14069), ping); // RA2: as above
	}
	return(g_PingTooltip); // RA2: as above
}

int __fastcall Slot_From_Control_Id(int id) // RA2: 0x0074A5D0, not in TibSun: the player slot (0 to 7) of the control ids 0x754 to 0x75B of the game lobby, -1 for any other; no caller (expanded where it is used)
{
	if (id == 0x754) { // RA2: as above
		return(0); // RA2: as above
	}
	if (id == 0x755) { // RA2: as above
		return(1); // RA2: as above
	}
	if (id == 0x756) { // RA2: as above
		return(2); // RA2: as above
	}
	if (id == 0x757) { // RA2: as above
		return(3); // RA2: as above
	}
	if (id == 0x758) { // RA2: as above
		return(4); // RA2: as above
	}
	if (id == 0x759) { // RA2: as above
		return(5); // RA2: as above
	}
	if (id == 0x75A) { // RA2: as above
		return(6); // RA2: as above
	}
	return(id == 0x75B ? 7 : -1); // RA2: as above
}

void __fastcall Enforce_Tournament_Options(HWND dialog) // RA2: 0x0074A640, not in TibSun: in a tournament channel the game options dialog fixes the settings: no computer players or alliances, bases and a short game on, and the controls of them disabled
{
	if (Is_Channel_Tournament(&g_CurrentChannel)) { // RA2: expanded here
		EnableWindow(GetDlgItem(dialog, 0x552), FALSE); // RA2: as above
		EnableWindow(GetDlgItem(dialog, 0x553), FALSE); // RA2: as above
		EnableWindow(GetDlgItem(dialog, 0x597), FALSE); // RA2: as above
		Session.Options.AIPlayers = 0; // RA2: as above
		Session.Options.AlliesAllowed = false; // RA2: as above
		HWND first = GetDlgItem(dialog, 0x54E); // RA2: as above
		SendMessage(first, BM_SETCHECK, 1, 0); // RA2: as above
		EnableWindow(first, FALSE); // RA2: as above
		HWND second = GetDlgItem(dialog, 0x54B); // RA2: as above
		SendMessage(second, BM_SETCHECK, 1, 0); // RA2: as above
		EnableWindow(second, FALSE); // RA2: as above
		Session.Options.ShortGame = true; // RA2: as above
		Session.Options.Bases = true; // RA2: as above
	}
}

void __fastcall Leave_Channel_With_Message(HWND dialog) // RA2: 0x0074C5F0, not in TibSun: the joiner has no slot in the game any more: tells the player (the channel is full, or the observer slot is) and leaves the channel; the dialog is closed when leaving fails
{
	if (dialog) { // RA2: as above
		if (ObserverMode == 0) { // RA2: as above
			ODMessageBox(StringTable::LoadString("TXT_CHANNEL_FULL", NULL, "C:\\RA2\\wonline.cpp", 15375), 0, Wait_Callback_Thunk, false); // RA2: as above
		} else {
			ODMessageBox(StringTable::LoadString("TXT_OBSERVER_FULL", NULL, "C:\\RA2\\wonline.cpp", 15377), 0, Wait_Callback_Thunk, false); // RA2: as above
		}
		if (g_pChat->RequestChannelLeave() < 0) { // RA2: virtual 0x24
			WS_Destroy_Dialog(dialog, 2); // RA2: as above
		}
	}
}

void __fastcall Show_Dialog(HWND dialog, int id); // RA2: 0x005FF7E0, defined in ownrdraw.cpp
LRESULT CALLBACK Wonline_Wait_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 0x0074D5E0, the dialog proc of the wait dialog (0xC4)
#define OD_SETLABEL (WM_USER + 178) // RA2: 0x4B2, sets the wide text of the control (name guessed from its use)

void Show_Wait_Window(unsigned int event, WideWstring const & text, bool block) // RA2: 0x0074D4D0, not in TibSun: opens the wait dialog (0xC4) with the text, or when it is open adds the events it waits for and changes its text; block waits until it closes
{
	HWND dialog = WS_Find_Dialog(0xC4); // RA2: as above
	if (dialog) { // RA2: the dialog is open
		g_ActiveWaitFlags |= event; // RA2: as above
		if (text.length() > 0) { // RA2: as above
			HWND label = GetDlgItem(dialog, 0x5B2); // RA2: as above
			SendMessage(label, OD_SETLABEL, 0, (LPARAM)text.text()); // RA2: as above
		}
	} else if (event) { // RA2: as above
		HWND focus = WS_Top_Window(); // RA2: the control that has the focus goes back to it
		focus = GetDlgItem(focus, 0x540); // RA2: as above
		dialog = WS_Create_Dialog(ProgramInstance, 0xC4, MainWindow, (DLGPROC)Wonline_Wait_Dialog_Proc, 0); // RA2: as above
		Show_Dialog(dialog, 0xC4); // RA2: as above
		HWND label = GetDlgItem(dialog, 0x5B2); // RA2: as above
		SendMessage(label, OD_SETLABEL, 0, (LPARAM)text.text()); // RA2: as above
		g_ActiveWaitFlags = event; // RA2: as above
		if (focus) { // RA2: as above
			SetFocus(focus); // RA2: as above
		}
	}
	if (block && g_ActiveWaitFlags) { // RA2: as above
		WS_Wait_Dialog(dialog, Wait_Callback_Thunk, false, true, false); // RA2: as above
	}
}

void __fastcall Dialog_On_WM_PAINT(HWND dialog); // RA2: 0x005FEE70, before a dialog paints, defined in ownrdraw.cpp
void __fastcall Dialog_On_WM_DRAWITEM(long item); // RA2: 0x005FE380
namespace OwnerDraw { void __fastcall Set_Dialog_Waiting(HWND control); } // RA2: 0x005E6390, defined in ownrdraw.cpp
extern int g_WaitDialogDelay; // RA2: 0x007FD384, 7000 milliseconds: how long the wait dialog stays hidden

LRESULT CALLBACK Wonline_Wait_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x0074D5E0, not in TibSun: the dialog proc of the wait dialog (0xC4): the abort button sets the first wait event, the other opens the network status page; the dialog shows itself after a delay
{
	switch (message) { // RA2: as above
	case WM_DESTROY: // RA2: as above
		KillTimer(window, 0x45); // RA2: as above
		break; // RA2: as above
	case WM_DRAWITEM: // RA2: as above
		Dialog_On_WM_DRAWITEM(lparam); // RA2: as above
		return(1); // RA2: as above
	case WM_PAINT: // RA2: as above
		Dialog_On_WM_PAINT(window); // RA2: as above
		Slide_Pending_Dialog(window); // RA2: as above
		ValidateRect(window, NULL); // RA2: as above
		break; // RA2: as above
	case WM_ERASEBKGND: // RA2: as above
		return(1); // RA2: as above
	case WM_INITDIALOG: // RA2: as above
		return(0); // RA2: as above
	case WM_COMMAND: // RA2: as above
		if ((unsigned short)wparam == 0x58D) { // the abort button // level-2 1.001: no network status button (its page string is absent)
			SetEvent(g_WaitEventHandles[0]); // RA2: as above
			WS_Destroy_Dialog(window, 1); // RA2: as above
		}
		break; // RA2: as above
	case WM_TIMER: // RA2: as above
		if (wparam == 0x45) { // RA2: the delay is over: the dialog shows
			ShowWindow(window, SW_SHOW); // RA2: as above
			KillTimer(window, 0x45); // RA2: as above
		}
		break; // RA2: as above
	case 0x497: // RA2: the dialog was made
		SendMessage(window, 0x4A9, 0, 1); // RA2: as above
		SetTimer(window, 0x45, g_WaitDialogDelay, NULL); // RA2: as above
		OwnerDraw::Set_Dialog_Waiting(window); // RA2: as above
		break; // RA2: as above
	}
	return(0); // RA2: as above
}

void Set_Wait_Window_Text(LPARAM text) // RA2: 0x0074D750, not in TibSun: changes the wide text of the wait dialog when it is open; no caller (expanded where it is used)
{
	HWND dialog = WS_Find_Dialog(0xC4); // RA2: as above
	if (dialog != NULL) { // RA2: as above
		SendDlgItemMessage(dialog, 0x5B2, OD_SETLABEL, 0, text); // RA2: as above
	}
}

void Close_Wait_Window(unsigned int event) // RA2: 0x0074D780, not in TibSun: takes the events out of what the wait dialog (0xC4) waits for, closes it when none is left, and gives the focus back to the chat line of the top dialog
{
	HWND win = WS_Find_Dialog(196); // RA2: as above
	if (win) { // RA2: as above
		g_ActiveWaitFlags &= ~event; // RA2: as above
		if (g_ActiveWaitFlags == 0) { // RA2: as above
			WS_Destroy_Dialog(win, 0); // RA2: as above
		}
	}
	HWND top = WS_Top_Window(); // RA2: as above
	HWND control = GetDlgItem(top, 1344); // RA2: as above
	if (control) { // RA2: as above
		SetFocus(control); // RA2: as above
	}
}

extern int PlayerPings[8]; // RA2: 0x00B2A734, as in mpcoop.cpp
NodeNameType * __fastcall Find_Lobby_Name(wchar_t const * name); // RA2: 0x005C8B20, defined in netshare.cpp
#include "wsproto.h" // RA2: PacketTransport

void __fastcall User_List_To_Session_Players(User * user) // RA2: 0x0074D7D0, not in TibSun (the executable's debug text names it): copies what the chat knows about the users into the session: the squad of each player, the address of the channel owner (the host), the pings, and the broadcast addresses of the players; the argument is not used
{
	Session.NumPlayers = 1; // RA2: the local player is slot 0
	User entry; // RA2: a copy of each user of the channel
	for (int i = 0; i < g_UserList.length(); i++) { // RA2: as above
		g_UserList.get(entry, i); // RA2: as above
		NodeNameType * player = Find_Lobby_Name(Narrow_To_Wide((char const *)entry.name)); // RA2: as above
		if (player && Is_Real_Player_Entry(player)) { // RA2: as above
			player->Player.SquadID = entry.squadID; // RA2: as above
		}
		if (stricmp((char const *)entry.name, g_NickName.get())) { // RA2: the others
			if (entry.flags & 1) { // RA2: the owner of the channel hosts the game
				Session.HostAddress = Find_Lobby_Name(Narrow_To_Wide((char const *)entry.name))->Address; // level-2 1.001: the whole address is copied (10 bytes)
			}
			int ping = 0; // RA2: as above
			g_pNetUtil->GetAvgPing(entry.ipaddr, &ping); // RA2: virtual 0x20
			if (ping < 0) { // RA2: as above
				ping = 0; // RA2: as above
			}
			PlayerPings[Session.NumPlayers++] = ping; // RA2: as above
		}
	}
	PacketTransport->Clear_Broadcast_Addresses(); // RA2: as above
	NetNumType network; // level-2 1.001: the address is still split, but not used
	NetNodeType node; // level-2 1.001: as above
	char address[32] = "xxx.xxx.xxx.xxx"; // level-2 1.001: one fixed text is passed for every player, and there are no debug texts
	for (int n = 1; n < Session.Players.Count(); n++) { // RA2: as above
		Session.Players[n]->Address.Get_Address(network, node); // level-2 1.001: as above
		PacketTransport->Set_Broadcast_Address(address); // level-2 1.001: as above
	}
}

extern User g_OwnerUser; // RA2: 0x00B2A658, the copy of the channel owner's user record Find_Owner_User returns
extern int g_PlayerCheckBoxIDs[8]; // RA2: 0x007FD334, the ids of the check boxes of the players in the readiness dialog (0x12C)
extern bool g_PlayerChecked[8]; // RA2: 0x00B28DCC, which of them were ticked
bool User_Is_Channel_Owner(Wstring const & name); // RA2: 0x0074D9E0, defined below
User * Find_Owner_User(void); // RA2: 0x0074DA60, defined below

bool __fastcall Local_User_Is_Channel_Owner(void) // RA2: 0x0074D960, not in TibSun: the local user is the owner of the channel (WOL)
{
	return(User_Is_Channel_Owner(g_NickName)); // RA2: expanded here
}

bool User_Is_Channel_Owner(Wstring const & name) // RA2: 0x0074D9E0, not in TibSun: the channel owner (the user with flag 1) has this name; no caller (expanded where it is used)
{
	User * owner = Find_Owner_User(); // RA2: expanded here
	if (owner == NULL) { // RA2: as above
		return(false); // RA2: as above
	}
	if (stricmp((char *)owner->name, name.text()) == 0) { // RA2: as above
		return(true); // level-2 1.001: the if form (no sete) lets OnPublicGameOptions keep its early-return layout
	}
	return(false); // RA2: as above
}

User * Find_Owner_User(void) // RA2: 0x0074DA60, not in TibSun: the user of the channel with the owner flag (1), a copy kept in a global; NULL when there is none
{
	for (int i = 0; i < g_UserList.length(); i++) { // RA2: as above
		g_UserList.get(g_OwnerUser, i); // RA2: as above
		if (g_OwnerUser.flags & 1) { // RA2: as above
			return(&g_OwnerUser); // RA2: as above
		}
	}
	return(NULL); // RA2: as above
}

void __fastcall Mark_Player_Checked(int index) // RA2: 0x0074DAB0, not in TibSun: ticks the check box of a player in the readiness dialog (0x12C) and has the dialog redrawn
{
	if (index >= 0 && index < Session.Players.Count()) { // RA2: as above
		HWND dialog = WS_Find_Dialog(0x12C); // RA2: as above
		if (dialog) { // RA2: as above
			HWND box = GetDlgItem(dialog, g_PlayerCheckBoxIDs[index]); // RA2: as above
			g_PlayerChecked[index] = true; // RA2: as above
			SendMessage(box, BM_SETCHECK, 1, 0); // RA2: 0xF1
			PostMessage(dialog, WM_PAINT, 0, 0); // RA2: 0xF
		}
	}
}

LRESULT CALLBACK Player_Readiness_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 0x0074DB40, the dialog proc of the readiness dialog (0x12C)

void Open_Readiness_Dialog(void) // RA2: 0x0074DB10, not in TibSun: opens the dialog (0x12C) that shows which players are ready; no caller (expanded where it is used)
{
	HWND dialog = WS_Create_Dialog(ProgramInstance, 300, MainWindow, (DLGPROC)Player_Readiness_Dialog_Proc, 0); // RA2: as above
	if (dialog != NULL) { // RA2: as above
		Show_Dialog(dialog, 300); // RA2: as above
	}
}

extern bool g_PlayerReady[8]; // RA2: 0x00B28DC4, the check boxes the program has ticked (read by the readiness dialog proc)

LRESULT CALLBACK Player_Readiness_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x0074DB40, not in TibSun: the dialog proc of the readiness dialog (0x12C): a check box for each player of the game, set by Mark_Player_Checked; the player cannot change them
{
	switch (message) { // RA2: as above
	case WM_PAINT: // RA2: as above
		Dialog_On_WM_PAINT(window); // RA2: as above
		ValidateRect(window, NULL); // RA2: as above
		return(0); // RA2: as above
	case WM_ERASEBKGND: // RA2: as above
		return(1); // RA2: as above
	case WM_DRAWITEM: // RA2: as above
		Dialog_On_WM_DRAWITEM(lparam); // RA2: as above
		return(1); // RA2: as above
	case WM_COMMAND: // RA2: as above
		wparam &= 0xFFFF; // RA2: as above
		switch (wparam) { // RA2: as above
		case 0x761: case 0x762: case 0x764: case 0x765: // RA2: as above
		case 0x766: case 0x767: case 0x768: case 0x769: // RA2: the check boxes of the players
			if (g_PlayerReady[wparam - 0x761]) { // RA2: ticked by the program: it stays ticked
				if (SendDlgItemMessage(window, wparam, BM_GETCHECK, 0, 0) == 0) { // RA2: as above
					SendDlgItemMessage(window, wparam, BM_SETCHECK, 1, 0); // RA2: as above
				}
			} else {
				if (SendDlgItemMessage(window, wparam, BM_GETCHECK, 0, 0) == 1) { // RA2: as above
					SendDlgItemMessage(window, wparam, BM_SETCHECK, 0, 0); // RA2: as above
					return(0); // RA2: as above
				}
			}
		}
		break; // RA2: as above
	case WM_CTLCOLORMSGBOX: case WM_CTLCOLOREDIT: case WM_CTLCOLORLISTBOX: case WM_CTLCOLORBTN: // RA2: as above
	case WM_CTLCOLORDLG: case WM_CTLCOLORSCROLLBAR: case WM_CTLCOLORSTATIC: // RA2: as above
		return((long)GetStockObject(BLACK_BRUSH)); // RA2: the controls are painted on black
	case 0x497: // RA2: the dialog was made
		for (int i = 0; i < 8; ++i) { // RA2: as above
			HWND control = GetDlgItem(window, g_PlayerCheckBoxIDs[i]); // RA2: as above
			memset(g_PlayerChecked, 0, 8); // RA2: as above
			if (i > Session.Players.Count() - 1) { // RA2: no player: the check box goes
				DestroyWindow(control); // RA2: as above
			}
		}
		for (int player = 0; player < Session.Players.Count(); ++player) { // RA2: as above
			HWND control = GetDlgItem(window, g_PlayerCheckBoxIDs[player]); // RA2: as above
			SendMessage(control, 0x4B2, 0, (LPARAM)Session.Players[player]->Name); // RA2: the name of the player
			SendMessage(control, BM_SETCHECK, 0, 0); // RA2: as above
		}
		SendMessage(window, 0x4A9, 0, 1); // RA2: as above
		OwnerDraw::Set_Dialog_Waiting(window); // RA2: as above
		ShowWindow(window, SW_SHOW); // RA2: as above
		break; // RA2: as above
	}
	return(0); // RA2: as above
}

extern int g_ConnectionStatus[8]; // RA2: 0x00B26A2C, how the connection of each player of the game ended (0 reported, 1 local, 2 pserver port, 3 host aborted)
extern int g_ConnectionStatusRank[4]; // RA2: 0x007FD324, 1, 2, 0, 1: the statuses a connection state may replace

void __fastcall Set_Connection_Status(int index, int status) // RA2: 0x0074DD20, not in TibSun: records how the connection of a player ended, unless the status it has is already worse; no caller (expanded where it is used)
{
	if (index < Session.Players.Count() && g_ConnectionStatus[index] < g_ConnectionStatusRank[index]) { // RA2: as above
		g_ConnectionStatus[index] = status; // RA2: as above
	}
}

void Report_Connection_Errors(void) // RA2: 0x0074DD50, not in TibSun: prints into the lobby chat what went wrong with the connections of the players: the status each player's connection ended with, the channel owner being the host; a general text when none is known
{
	wchar_t message[256]; // RA2: as above
	User * owner = Find_Owner_User(); // RA2: expanded here
	if (owner) { // RA2: as above
		int owner_index = -1; // RA2: as above
		int i; // RA2: as above
		for (i = 0; i < Session.Players.Count(); i++) { // RA2: as above
			if (!stricmp(Wide_To_Narrow(Session.Players[i]->Name), (char const *)owner->name)) { // RA2: as above
				owner_index = i; // RA2: as above
				break; // RA2: as above
			}
		}
		bool reported = false; // RA2: as above
		for (i = 0; i < Session.Players.Count(); i++) { // RA2: as above
			switch (g_ConnectionStatus[i]) { // RA2: as above
			case 0: // RA2: as above
				reported = true; // RA2: as above
				DebugString("Player %s was unable to establish a connection\n", Wide_To_Narrow(Session.Players[i]->Name)); // RA2: as above
				swprintf(message, StringTable::LoadString("TXT_TALK_REPORTED_PROBLEM", NULL, "C:\\RA2\\wonline.cpp", 16894), Session.Players[i]->Name); // RA2: as above
				Lobby_Chat_Printf(ColorSystem, message); // RA2: as above
				break; // RA2: as above
			case 1: // RA2: as above
				reported = true; // RA2: as above
				DebugString("Unable to connect to player %s\n", Wide_To_Narrow(Session.Players[i]->Name)); // RA2: as above
				swprintf(message, StringTable::LoadString("TXT_TALK_LOCAL_PROBLEM", NULL, "C:\\RA2\\wonline.cpp", 16904), Session.Players[i]->Name); // RA2: as above
				Lobby_Chat_Printf(ColorSystem, message); // RA2: as above
				break; // RA2: as above
			case 2: // RA2: as above
				reported = true; // RA2: as above
				if (i == owner_index) { // RA2: the host could not be reached
					DebugString("Unable to talk to the pserver port\n"); // RA2: as above
					Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_TALK_FORWARDER_PROBLEM_GUES", NULL, "C:\\RA2\\wonline.cpp", 16915)); // RA2: as above
				} else {
					DebugString("Player %s was unable to connect to the pserver port\n", Wide_To_Narrow(Session.Players[i]->Name)); // RA2: as above
					swprintf(message, StringTable::LoadString("TXT_TALK_FORWARDER_PROBLEM_HOST", NULL, "C:\\RA2\\wonline.cpp", 16918), Session.Players[i]->Name); // RA2: as above
					Lobby_Chat_Printf(ColorSystem, message); // RA2: as above
				}
				break; // RA2: as above
			case 3: // RA2: as above
				reported = true; // RA2: as above
				DebugString("The game host reported a connection problem between players\n"); // RA2: as above
				Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_TALK_HOST_ABORTED", NULL, "C:\\RA2\\wonline.cpp", 16929)); // RA2: as above
				break; // RA2: as above
			}
		}
		if (!reported) { // RA2: as above
			Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_FAILED_TO_TALK", NULL, "C:\\RA2\\wonline.cpp", 16942)); // RA2: as above
		}
	}
}

unsigned short __fastcall Get_Port_Blitz_Port_Number(int send_port, int mangled_port, int unused, int port_spread) // RA2: 0x0074DFD0, not in TibSun (the executable's debug text names it so): the port to send to for a peer whose router allocates ports by this spread (1 consecutive, 2 every second, a larger one in pairs, a negative one downwards), never below 1024; no caller (expanded where it is used)
{
	int port = send_port + mangled_port; // RA2: as above
	if (port_spread != 1) { // RA2: as above
		if (port_spread == 2) { // RA2: as above
			port = mangled_port + send_port * 2; // RA2: as above
		} else if (port_spread > 1) { // RA2: as above
			port = send_port % 2 + mangled_port + (send_port / 2) * port_spread; // RA2: as above
		} else if (port_spread < 0) { // RA2: as above
			if (port_spread == -100) { // RA2: as above
				port = mangled_port + send_port * 100; // RA2: as above
			} else {
				port = send_port % 2 - (send_port / 2) * port_spread + mangled_port; // RA2: as above
			}
		}
	}
	DebugString("Get_Port_Blitz_Port_Number - send port = %d, mangled_port = %d, port_spread = %d, port = %d\n", send_port, mangled_port, port_spread, port); // RA2: as above
	if ((unsigned short)port < 1024) { // RA2: as above
		port = 1024; // RA2: as above
	}
	return((unsigned short)port); // RA2: as above
}

#include "firewall.h" // RA2: FirewallHelper.Rank_A
extern FirewallHelperClass FirewallHelper; // RA2: 0x00A71B18, as in init.cpp

int __fastcall Build_Connection_Pairs(int (* pairs)[2]) // RA2: 0x0074E070, not in TibSun: orders the players of the game by how awkward their connections are (FirewallHelper.Rank_A of their state) and writes every pair of them into the table; the number of pairs
{
	int order[8]; // RA2: the slots of the players
	memset(order, 0, sizeof(order)); // RA2: as above
	int i = 0; // RA2: as above
	int * out = order; // RA2: as above
	for (; i < 8; i++) { // RA2: the slots that hold real players
		if (Is_Real_Player_Entry(Session.Slots[i])) { // RA2: as above
			*out++ = i;
		}
	}
	for (int a = 0; a < Session.Players.Count(); a++) { // RA2: sorted, the most awkward first
		for (int b = 0; b < Session.Players.Count() - 1; b++) { // RA2: as above
			int current = Session.WolPlayerState[order[b]]; // RA2: as above
			int next = Session.WolPlayerState[order[b + 1]]; // RA2: as above
			if (FirewallHelper.Rank_A(current) < FirewallHelper.Rank_A(next)) { // RA2: as above
				int temp = order[b]; // RA2: as above
				order[b] = order[b + 1]; // RA2: as above
				order[b + 1] = temp; // RA2: as above
			}
		}
	}
	DebugString("Connection order = %d, %d, %d, %d, %d, %d\n", order[0], order[1], order[2], order[3], order[4], order[5]); // RA2: as above
	int n = 0; // RA2: as above
	DebugString("Connection pairs....\n"); // RA2: as above
	for (int x = 0; x < Session.Players.Count(); x++) { // RA2: as above
		for (int y = x + 1; y < Session.Players.Count(); y++) { // RA2: as above
			pairs[n][0] = order[x]; // RA2: as above
			pairs[n][1] = order[y]; // RA2: as above
			DebugString("\t%d & %d\n", order[x], order[y]); // RA2: as above
			n++; // RA2: as above
		}
	}
	return(n); // RA2: as above
}

void __fastcall Register_Connection_State(char const * sender, char const * receiver, int state) // RA2: 0x0074E1F0, not in TibSun: a player reported the state of its connection to another (both by name): stored for the pair of slots in either direction
{
	int sender_slot = -1; // RA2: as above
	int receiver_slot = -1; // RA2: as above
	DebugString("Registering connection state from %s to %s. conn_state = %d\n", sender, receiver, state); // RA2: as above
	int i = 0; // RA2: as above
	for (NodeNameType ** slot = Session.Slots; (long)slot < (long)(Session.Slots + 8); ++slot, ++i) { // RA2: the slots of the game
		if (stricmp(Wide_To_Narrow((*slot)->Name), sender) == 0) { // RA2: as above
			sender_slot = i; // RA2: as above
		}
		if (stricmp(Wide_To_Narrow((*slot)->Name), receiver) == 0) { // RA2: as above
			receiver_slot = i; // RA2: as above
		}
	}
	for (i = 0; i < Session.ConnectionResultCount; ++i) { // RA2: the pair is looked up
		if (Session.PeerProbeData[i][0] == sender_slot && Session.PeerProbeData[i][1] == receiver_slot) { // RA2: as above
			Session.ConnectionResults[i][0] = state; // RA2: as above
			return; // RA2: as above
		}
		if (Session.PeerProbeData[i][0] == receiver_slot && Session.PeerProbeData[i][1] == sender_slot) { // RA2: as above
			Session.ConnectionResults[i][1] = state; // RA2: as above
			return; // RA2: as above
		}
	}
}

void __fastcall Store_Player_Port(char const * name, unsigned short port) // RA2: 0x0074E2D0, not in TibSun: a player says which port to send to: kept for its slot
{
	DebugString("Player %s is telling us we should send to port %d\n", name, port); // RA2: as above
	for (int i = 0; i < 8; ++i) { // RA2: as above
		if (!stricmp(Wide_To_Narrow(Session.Slots[i]->Name), name)) { // RA2: as above
			Session.PeerPorts[i] = port; // RA2: as above
			return; // RA2: as above
		}
	}
}

void __fastcall Send_User_Port(char const * name, unsigned short port) // RA2: 0x0074E330, not in TibSun: tells the user of this name by private game options string ("Z4" and the port) which port to send to
{
	User * user = NULL; // RA2: as above
	char text[256]; // RA2: as above
	for (int i = 0; i < g_UserList.length(); ++i) { // RA2: as above
		g_UserList.getPointer(&user, i); // RA2: as above
		if (stricmp(name, (char const *)user->name) == 0) { // RA2: as above
			text[0] = 'Z'; // RA2: as above
			text[1] = '4'; // RA2: as above
			sprintf(text + 2, "%d", port); // RA2: as above
			DebugString("Sending string %s to user %s\n", text, name); // RA2: as above
			g_pChat->RequestPrivateGameOptions(user, text); // RA2: virtual 0x38
		}
	}
}

void __fastcall Send_Public_Options(char kind, char const * text) // RA2: 0x0074E3F0, not in TibSun: sends a public game options string "Z1", the kind and the text to the channel
{
	char options[256]; // RA2: as above
	options[0] = 'Z'; // RA2: as above
	options[1] = '1'; // RA2: as above
	options[2] = kind + '0'; // RA2: as above
	if (text) { // RA2: as above
		strcpy(options + 3, text); // RA2: as above
	} else {
		options[3] = 0; // RA2: as above
	}
	DebugString("Sending public options string %s\n", options); // RA2: as above
	g_pChat->RequestPublicGameOptions(options); // RA2: virtual 0x3C
}

static CDTimerClass<SystemTimerClass> KeepAliveTimer[MAX_PLAYERS]; // level-2 1.001: not a SessionClass member (1.006: Session.KeepAliveTimer, +0x2F34); the countdown of each keepalive (1200 ticks)

void Resend_Pending_Requests(void) // RA2: 0x0074E470, not in TibSun: sends a keepalive (NET_PING) to each peer whose countdown ran out and restarts it
{
	for (int index = 0; index < Session.KeepAliveCount; ++index) { // RA2: as above
		if (KeepAliveTimer[index] == 0) { // RA2: as above
			GlobalPacketType packet; // RA2: as above
			memset(&packet, 0, sizeof(packet)); // RA2: as above
			packet.Command = NET_PING; // RA2: as above
			strcpy(packet.Name, g_NickName.get()); // RA2: as above
			char const * name = Wide_To_Narrow(Session.Slots[Session.KeepAliveSlot[index]]->Name); // RA2: as above
			DebugString("Sending keepalive NET_PING packet to %s\n", name); // RA2: as above
			Ipx.Send_Global_Message_To_Name(&packet, 0x2F, 0, Session.Slots[Session.KeepAliveSlot[index]]->Name); // RA2: as above
			KeepAliveTimer[index] = 1200; // RA2: 20 seconds
		}
	}
}

void __fastcall Queue_Peer_Timeout(int peer) // RA2: 0x0074E590, not in TibSun: queues a keepalive for this slot
{
	Session.KeepAliveSlot[Session.KeepAliveCount] = peer; // RA2: as above
	KeepAliveTimer[Session.KeepAliveCount] = 1200; // RA2: as above
	++Session.KeepAliveCount; // RA2: as above
}

bool __fastcall Start_Talking_To(int player, int pair_slot, int retries); // RA2: 0x0074E5E0, the executable's debug text "Start_Talking_To player %d, retries = %d" names it: makes the connection to one peer by port probes, tries again up to the number of retries; true when it is made
struct SessionPortAllocator : public SessionClass { // RA2: the file-local subclass of session.cpp that holds Allocate_Player_Ports (0x00673090); no data
	void Allocate_Player_Ports(void); // RA2: as above
};

bool Connect_Player_Pairs(void) // RA2: 0x0074EF80, not in TibSun: makes the connections of the pairs of players Build_Connection_Pairs arranged: talks to the peer of each pair the local player is in (Start_Talking_To), waits for the others to connect among themselves; false when one of them fails
{
	CDTimerClass<SystemTimerClass> timer; // RA2: as above
	Session.KeepAliveCount = 0; // RA2: as above
	memset(&Session.PeerAttemptBlock[3], 0, 0x20); // RA2: the eight values at +0x2EF4 are cleared
	int pair_slot = -1; // RA2: as above
	g_SuspendChatPump = 0; // RA2: the chat is pumped again
	if (Session.ConnectionResultCount == 0) { // RA2: no pair to make
		return(false); // RA2: as above
	}
	((SessionPortAllocator &)Session).Allocate_Player_Ports(); // RA2: as above
	if (Session.Players.Count() > 0) { // RA2: the first check box of the readiness dialog (the local player) is ticked
		HWND window = WS_Find_Dialog(300); // RA2: as above
		if (window) { // RA2: as above
			HWND control = GetDlgItem(window, g_PlayerCheckBoxIDs[0]); // RA2: as above
			g_PlayerChecked[0] = true; // RA2: as above
			SendMessage(control, BM_SETCHECK, 1, 0); // RA2: as above
			PostMessage(window, WM_PAINT, 0, 0); // RA2: as above
		}
	}
	for (int pair = 0; pair < Session.ConnectionResultCount; ++pair) { // RA2: as above
		int first = Session.PeerProbeData[pair][0]; // RA2: the slots of the pair
		int second = Session.PeerProbeData[pair][1]; // RA2: as above
		int peer = -1; // RA2: as above
		NodeNameType * first_player = Session.Slots[first]; // RA2: as above
		NodeNameType * second_player = Session.Slots[second]; // RA2: as above
		char const * first_name = Wide_To_Narrow(first_player->Name); // RA2: as above
		char const * second_name = Wide_To_Narrow(second_player->Name); // RA2: as above
		DebugString("Connecting pair %d, %s and %s\n", pair, first_name, second_name); // RA2: as above
		char const * name = Wide_To_Narrow(Session.Slots[first]->Name); // RA2: as above
		if (stricmp(name, g_NickName.get()) == 0) { // RA2: the local player is the first of the pair
			peer = second; // RA2: as above
			pair_slot = pair * 2 + 1; // RA2: as above
			Session.ConnectionResults[pair][0] = 11; // RA2: as above
		}
		name = Wide_To_Narrow(Session.Slots[second]->Name); // RA2: as above
		if (stricmp(name, g_NickName.get()) == 0) { // RA2: or the second
			peer = first; // RA2: as above
			pair_slot = pair * 2; // RA2: as above
			Session.ConnectionResults[pair][1] = 11; // RA2: as above
		}
		if (peer != -1) { // RA2: the local player is in the pair
			int step; // RA2: the harder of the two connections decides how many retries
			if (FirewallHelper.Rank_B(Session.WolPlayerState[first]) > FirewallHelper.Rank_B(Session.WolPlayerState[second])) { // RA2: as above
				step = FirewallHelper.Rank_B(Session.WolPlayerState[first]); // RA2: as above
			} else {
				step = FirewallHelper.Rank_B(Session.WolPlayerState[second]); // RA2: as above
			}
			if (!Start_Talking_To(peer, pair_slot, step)) { // RA2: as above
				return(false); // RA2: as above
			}
		} else { // RA2: the others connect among themselves: wait for both results
			DebugString("Waiting for other guys to connect\n"); // RA2: as above
			timer = CDTimerClass<SystemTimerClass>(960); // RA2: 16 seconds
			int progress = 0; // RA2: as above
			do { // RA2: as above
				Sleep(5); // RA2: as above
				WOL_Wait_Callback(); // RA2: as above
				Resend_Pending_Requests(); // RA2: as above
				int first_status = Session.ConnectionResults[pair][0]; // RA2: as above
				int second_status = Session.ConnectionResults[pair][1]; // RA2: as above
				if ((first_status == 11 || first_status == 0) && (second_status == 11 || second_status == 0)) { // RA2: as above
					DebugString("Got both results - woohoo!\n"); // RA2: as above
					break; // RA2: as above
				}
				if (first_status >= 1 && first_status < 11 && first_status - 1 > progress) { // RA2: the first one tries again
					DebugString("Connecting player 1 is trying again - try_now = %d\n", first_status - 1); // RA2: as above
					progress = first_status - 1; // RA2: as above
					timer = CDTimerClass<SystemTimerClass>(840); // RA2: 14 seconds more
				}
				if (second_status >= 1 && second_status < 11 && second_status - 1 > progress) { // RA2: the second one
					DebugString("Connecting player 2 is trying again - try_now = %d\n", second_status - 1); // RA2: as above
					progress = second_status - 1; // RA2: as above
					timer = CDTimerClass<SystemTimerClass>(840); // RA2: as above
				}
			} while (timer.Value() != 0); // RA2: as above
		}
		if (Session.ConnectionResults[pair][0] != 11) { // RA2: as above
			return(false); // RA2: as above
		}
		if (Session.ConnectionResults[pair][1] != 11) { // RA2: as above
			return(false); // RA2: as above
		}
		DebugString("Connection good, next pair\n"); // RA2: as above
	}
	return(true); // RA2: as above
}

extern bool g_ReceivingHostPreview; // RA2: 0x00B2AC46, set while Receive_Host_Map_Preview takes the map preview from the host
namespace OwnerDraw { void __fastcall WideToCharString(char * dest, wchar_t const * src, int count); } // RA2: 0x006FA0F0, as in conquer.cpp

bool Receive_Host_Map_Preview(void) // RA2: 0x00750D10 (1.001 0x0073F5A0), not in TibSun: a guest of a game channel takes the map preview from the host when the host's NET_PREVIEW_MODE packet is waiting in the global channel; true when the preview was received
{
	IPXAddressClass address; // RA2: as above
	if (g_CurrentChannel.type && g_UserList.length() >= 2) { // RA2: in a channel with at least one other user
		User * owner = Find_Owner_User(); // RA2: expanded here
		if (owner && !stricmp((char const *)owner->name, g_NickName.text())) { // RA2: the host does not receive its own preview
			return(false); // RA2: as above
		}
		if (WolOptionsLocked == 0) { // level-2 1.001: no peek at the global channel and no preview control of the lobby
			User user; // RA2: as above
			g_UserList.get(user, 0); // RA2: as above
			user.next = NULL; // RA2: as above
			User_List_To_Session_Players(&user); // RA2: the session addresses first
			Call_Back(); // RA2: as above
			GlobalPacketType packet; // RA2: as above
			int length = sizeof(packet); // RA2: as above
			unsigned short product; // RA2: as above
			if (Ipx.Get_Global_Message(&packet, &length, &address, &product) && packet.Command == NET_PREVIEW_MODE && address == Session.HostAddress && product == 0xAA03) { // level-2 1.001: the address is compared whole, the sender name is not checked
				DebugString("Received NET_PREVIEW_MODE packet from host\n"); // RA2: as above
				Ipx.Set_Timing(50, (unsigned long)-1, 5000, true); // RA2: slow resends while the preview comes
				g_ReceivingHostPreview = true; // RA2: as above
				Receive_Random_Map_Preview(); // RA2: as above
				g_ReceivingHostPreview = false; // RA2: as above
				Ipx.Set_Timing(30, (unsigned long)-1, 600, true); // RA2: the usual timing again
				return(true); // RA2: as above
			}
		}
	}
	return(false); // RA2: as above
}

void Poke_The_Host(void) // level-2 1.001: 0x0073F720 (YR 0x00796960), the executable's debug text names it: a guest of a game channel sends a NET_PING to the host's address once the session knows it
{
	IPXAddressClass address; // level-2 1.001: constructed and not used
	if (g_UserList.length() >= 2) {
		User * owner = Find_Owner_User();
		if (owner && !stricmp((char const *)owner->name, g_NickName.text())) { // level-2 1.001: not the host
			return;
		}
		if (WolOptionsLocked == 0 && g_CurrentChannel.type) {
			User user;
			g_UserList.get(user, 0);
			user.next = NULL;
			User_List_To_Session_Players(&user);
			Call_Back();
			Ipx.Set_Timing(50, (unsigned long)-1, 5000, true);
			DebugString("Poke_The_Host - Host address is %s\n", Session.HostAddress.As_String());
			GlobalPacketType packet;
			memset(&packet, 0, sizeof(packet));
			packet.Command = NET_PING;
			Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.HostAddress);
			Call_Back();
		}
	}
}

void Add_Test_Player_Ol_Cruddy(void) // RA2: 0x007513E0, not in TibSun: a test player "Ol Cruddy" at 10.2.81.82 is added to the session (house 0, color 3), as a stand-in for a real opponent; no caller
{
	NodeNameType * player = new NodeNameType; // RA2: as above
	Char_To_Wide(player->Name, "Ol Cruddy", -1); // RA2: as above
	player->Player.SquadID = -1; // RA2: as above
	player->Player.House = 0; // RA2: as above
	player->Player.Color = 3; // RA2: as above
	NetNumType network; // RA2: as above
	NetNodeType node; // RA2: as above
	memset(network, 0, sizeof(network)); // RA2: as above
	node[5] = 0; // RA2: the address 10.2.81.82
	node[4] = 0; // RA2: as above
	node[3] = 82; // RA2: as above
	node[2] = 81; // RA2: as above
	node[1] = 2; // RA2: as above
	node[0] = 10; // RA2: as above
	player->Address.Set_Address(network, node); // level-2 1.001: no port
	Session.Players.Add(player); // RA2: as above
	PlayerPings[Session.NumPlayers] = 100; // RA2: as above
	++Session.NumPlayers; // RA2: as above
}

void Add_Test_Player_Potato(void) // RA2: 0x007514D0, not in TibSun: a test player "Potato" at 10.2.20.97 is added to the session (house 0, color 0); no caller
{
	NodeNameType * player = new NodeNameType; // RA2: as above
	Char_To_Wide(player->Name, "Potato", -1); // RA2: as above
	player->Player.SquadID = -1; // RA2: as above
	player->Player.House = 0; // RA2: as above
	player->Player.Color = 0; // RA2: as above
	NetNumType network; // RA2: as above
	NetNodeType node; // RA2: as above
	memset(network, 0, sizeof(network)); // RA2: as above
	node[5] = 0; // RA2: the address 10.2.20.97
	node[4] = 0; // RA2: as above
	node[3] = 97; // RA2: as above
	node[2] = 20; // RA2: as above
	node[1] = 2; // RA2: as above
	node[0] = 10; // RA2: as above
	player->Address.Set_Address(network, node); // level-2 1.001: no port
	Session.Players.Add(player); // RA2: as above
	PlayerPings[Session.NumPlayers] = 100; // RA2: as above
	++Session.NumPlayers; // RA2: as above
}

void Add_Test_Player_Potato_Too(void) // RA2: 0x007515B0, not in TibSun: a test player "PotatoToo" at 10.2.80.250 is added to the session as the host (house 1, color 2); no caller
{
	NodeNameType * player = new NodeNameType; // RA2: as above
	Char_To_Wide(player->Name, "PotatoToo", -1); // RA2: as above
	player->Player.SquadID = -1; // RA2: as above
	player->Player.House = 1; // RA2: as above
	player->Player.Color = 2; // RA2: as above
	NetNumType network; // RA2: as above
	NetNodeType node; // RA2: as above
	memset(network, 0, sizeof(network)); // RA2: as above
	node[5] = 0; // RA2: the address 10.2.80.250
	node[4] = 0; // RA2: as above
	node[3] = 250; // RA2: as above
	node[2] = 80; // RA2: as above
	node[1] = 2; // RA2: as above
	node[0] = 10; // RA2: as above
	player->Address.Set_Address(network, node); // level-2 1.001: no port
	Session.Players.Add(player); // RA2: as above
	PlayerPings[Session.NumPlayers] = 100; // RA2: as above
	++Session.NumPlayers; // RA2: as above
	Session.HostAddress = player->Address; // RA2: the host
}

#pragma auto_inline(off) // RA2: as above

// level-2 1.001: the event sink handlers (0x34A9C0..0x351E90), merged from the wol_c proposal (W/analysis/level2/agents/wol_c_wonline.claims.json)
extern int WestwoodOnline_Tournament;
void __fastcall Send_Statistics_Packet(bool alt_server);
void __fastcall Set_Current_State(rc_ptr<WDTState> const & state);
void __fastcall Set_Current_State2(rc_ptr<WDTState> const & state);
extern HRESULT g_AgeCheckResult;
extern int g_UserConsent;
extern bool g_PingSessionActive;
extern int g_PingsSent;
extern int g_PingsReceived;
extern int g_ServerPingsReceived;
void Server_Pings_Done(void);

CNetUtilEventSink::CNetUtilEventSink(void)
{
}

STDMETHODIMP CNetUtilEventSink::OnWDTState(HRESULT res, unsigned char *state, int length)
{
	if (res < 0 || length <= 0) {
		SetEvent(g_WaitEventHandles[EV_ERROR]);
		return(S_OK);
	}
	rc_ptr<WDTState> wdt = WDTState::Create(state);
	if (wdt.Get() && wdt->Has_Owner_History()) {
		if (wdt->Is_Previous_Cycle()) {
			DebugString("OnWDTState: Previous cycle data received\n");
			Set_Current_State2(wdt);
			SetEvent(g_WaitEventHandles[11]);
		} else {
			DebugString("OnWDTState: Current cycle data received\n");
			g_NextWDTStatePollTime = time(NULL) + wdt->TickTime;
			Set_Current_State(wdt);
			SetEvent(g_WaitEventHandles[11]);
		}
	} else {
		DebugString("OnWDTState: NACK received from server\n");
		SetEvent(g_WaitEventHandles[11]);
	}
	return(S_OK);
}

STDMETHODIMP CNetUtilEventSink::OnGameresSent(HRESULT res)
{
	if (Session.Type == GAME_INTERNET && Online_Session_State == 2 && WestwoodOnline_Tournament) {
		WestwoodOnline_Tournament = 1;
		Send_Statistics_Packet(true);
	}
	return(S_OK);
}

STDMETHODIMP CNetUtilEventSink::OnAgeCheck(HRESULT res, int years, int consent)
{
	DebugString("OnAgeCheck\n");
	g_AgeCheckResult = res;
	if (res == 0) {
		g_UserAge = years;
		g_UserConsent = consent;
	}
	HWND dialog = WS_Find_Dialog(0xC4);
	if (dialog) {
		g_ActiveWaitFlags &= ~0x100;
		if (g_ActiveWaitFlags == 0) {
			WS_Destroy_Dialog(dialog, 0);
		}
	}
	HWND top = WS_Top_Window();
	HWND input = GetDlgItem(top, 0x540);
	if (input) {
		SetFocus(input);
	}
	return(S_OK);
}

STDMETHODIMP CNetUtilEventSink::OnPing(HRESULT res, int time, unsigned long ip, int handle)
{
	if (g_PlayingNetGame && g_PingsSent) {
		if (res == 0 && time >= 0 && time < 1000) {
			g_PingsReceived++;
		}
		return(S_OK);
	}
	if (Is_Tournament_Session()) {
		DebugString("Received Ping\n");
		g_ServerPingsReceived++;
		if (g_ServerPingsReceived >= g_PingServers.length()) {
			Server_Pings_Done();
			return(S_OK);
		}
	} else if (g_CurrentChannel.type) {
		Draw_Player_List(0, false);
	}
	return(S_OK);
}

CChatEventSink::CChatEventSink(void)
{
}

STDMETHODIMP CChatEventSink::OnLogout(HRESULT status, User *user)
{
	if (status >= 0) {
		Handle_User_Leave(*user);
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnServerError(HRESULT res, LPCSTR ircmsg)
{
	wchar_t text[512];
	if (!g_PlayingNetGame) {
		swprintf(text, L"%s : %hs", StringTable::LoadString("TXT_SERVER_ERROR", NULL, "C:\\RA2\\wonline.cpp", 4008), ircmsg);
		Lobby_Chat_Printf(-1, text);
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnChannelLeave(HRESULT res, Channel *channel, User *user)
{
	if (res < 0) {
		DebugString("OnChannelLeave with error!\n");
		return(S_OK);
	}
	Handle_User_Leave(*user);
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnChannelTopic(HRESULT res, Channel *channel, LPCSTR topic)
{
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnUserIP(HRESULT res, User *user)
{
	return(S_OK);
}

extern int g_SystemMessageColor;
STDMETHODIMP CChatEventSink::OnSystemMessage(HRESULT res, LPCSTR message)
{
	if (!g_PlayingNetGame && res >= 0) {
		Lobby_Chat_Printf(g_SystemMessageColor, L">>> %hs", message);
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnBuddyAdd(HRESULT res, User *user)
{
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnBuddyDelete(HRESULT res, User *user)
{
	return(S_OK);
}

static inline WideWstring Widen_Text(char const * text)
{
	Wstring narrow(text);
	return(Wstring_ToWide(narrow));
}

STDMETHODIMP CChatEventSink::OnMessageOfTheDay(HRESULT res, LPCSTR motd)
{
	wchar_t wide[1024];
	if (res < 0) {
		return(S_OK);
	}
	char * buffer = strdup(motd);
	char * line = strtok(buffer, "\n");
	while (line) {
		Char_To_Wide(wide, line, -1);
		Lobby_Chat_Printf(ColorSystem, wide);
		line = strtok(NULL, "\n");
	}
	free(buffer);
	Lobby_Chat_Printf(ColorSystem, L"\n");
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnPrivateAction(HRESULT res, User *user, LPCSTR action)
{
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	if (res < 0) {
		return(S_OK);
	}
	WideWstring wide = Widen_Text(action);
	if (stricmp(Session.Handle, (char *)user->name)) {
		Lobby_Chat_Printf(ColorPrivAction, L"%hs %s", user->name, wide.get());
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnPrivateUnicodeAction(HRESULT res, User *user, const unsigned short *action)
{
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	if (res < 0) {
		return(S_OK);
	}
	if (stricmp(Session.Handle, (char *)user->name)) {
		Lobby_Chat_Printf(ColorPrivAction, L"%hs %s", user->name, action);
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnPublicAction(HRESULT res, Channel *channel, User *user, LPCSTR action)
{
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	if (res < 0) {
		return(S_OK);
	}
	WideWstring wide = Widen_Text(action);
	if (stricmp(Session.Handle, (char *)user->name)) {
		Lobby_Chat_Printf(ColorAction, L"%hs %s", user->name, wide.get());
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnPublicUnicodeAction(HRESULT res, Channel *channel, User *user, const unsigned short *action)
{
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	if (res < 0) {
		return(S_OK);
	}
	if (stricmp(Session.Handle, (char *)user->name)) {
		Lobby_Chat_Printf(ColorAction, L"%hs %s", user->name, action);
	}
	return(S_OK);
}

void __fastcall Process_Match_Message(char const * message, bool is_private); // level-2 1.001: 0x7494B0, provisional name (gibbo FUN_007A16B0)

STDMETHODIMP CChatEventSink::OnPublicMessage(HRESULT res, Channel *channel, User *user, LPCSTR message)
{
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	if (res < 0) {
		return(S_OK);
	}
	if (Is_Tournament_Session()) {
		if (user->flags & 1) {
			Process_Match_Message(message, false);
		}
		return(S_OK);
	}
	WideWstring wide = Widen_Text(message);
	COLORREF color = ColorUser;
	if (user->flags & 1) {
		color = ColorOp;
	}
	if (stricmp(Session.Handle, (char *)user->name)) {
		Lobby_Chat_Printf(color, L"[%hs] : %s", user->name, wide.get());
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnPublicUnicodeMessage(HRESULT res, Channel *channel, User *user, const unsigned short *message)
{
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	if (res < 0) {
		return(S_OK);
	}
	WideWstring wide(message);
	COLORREF color = ColorUser;
	if (user->flags & 1) {
		color = ColorOp;
	}
	if (stricmp(Session.Handle, (char *)user->name)) {
		Lobby_Chat_Printf(color, L"[%hs] : %s", user->name, wide.get());
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnPrivateMessage(HRESULT res, User *user, LPCSTR message)
{
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	if (res < 0) {
		return(S_OK);
	}
	if (Is_Tournament_Session()) {
		if (user->flags & 1) {
			Process_Match_Message(message, true);
			return(S_OK);
		}
		DebugString("Received message from non-channel owner %s: %s\n", user->name, message);
		return(S_OK);
	}
	WideWstring wide = Widen_Text(message);
	COLORREF color = ColorPriv;
	if (user->flags & 1) {
		color = ColorOp;
	}
	if (stricmp(Session.Handle, (char *)user->name)) {
		Lobby_Chat_Printf(color, L"%hs : %s", user->name, wide.get());
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnPrivateUnicodeMessage(HRESULT res, User *user, const unsigned short *message)
{
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	if (res < 0) {
		return(S_OK);
	}
	WideWstring wide(message);
	COLORREF color = ColorPriv;
	if (user->flags & 1) {
		color = ColorOp;
	}
	if (stricmp(Session.Handle, (char *)user->name)) {
		Lobby_Chat_Printf(color, L"%hs : %s", user->name, wide.get());
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnPageSend(HRESULT res)
{
	if (res == 0) {
		SMessagePrintf(ColorSystem, StringTable::LoadString("TXT_PAGESENT", NULL, "C:\\RA2\\wonline.cpp", 5957));
		return(S_OK);
	}
	if (res == 0x40134) {
		SMessagePrintf(ColorSystem, StringTable::LoadString("TXT_PAGEDISABLED", NULL, "C:\\RA2\\wonline.cpp", 5959));
		return(S_OK);
	}
	if (res == 0x40133) {
		SMessagePrintf(ColorSystem, StringTable::LoadString("TXT_PAGEUSERGONE", NULL, "C:\\RA2\\wonline.cpp", 5961));
		return(S_OK);
	}
	SMessagePrintf(ColorSystem, StringTable::LoadString("TXT_PAGEFAILED", NULL, "C:\\RA2\\wonline.cpp", 5963));
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnServerBannedYou(HRESULT res, time_t bannedTill)
{
	wchar_t text[200];
	if (!g_PlayingNetGame && res == 0) {
		swprintf(text, StringTable::LoadString("TXT_BANNEDTILL", NULL, "C:\\RA2\\wonline.cpp", 6386), ctime(&bannedTill));
		ODMessageBox(text, 0, Wait_Callback_Thunk, false);
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnChannelBan(HRESULT res, LPCSTR name, int banned)
{
	if (!g_PlayingNetGame) {
		if (banned) {
			Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_CHAN_BAN", NULL, "C:\\RA2\\wonline.cpp", 6399), Narrow_To_Wide(name));
		} else {
			Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_CHAN_UNBAN", NULL, "C:\\RA2\\wonline.cpp", 6402), Narrow_To_Wide(name));
		}
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnUserFlags(HRESULT res, LPCSTR name, unsigned int flags, unsigned int mask)
{
	if (res == 0) {
		for (int i = 0; i < g_UserList.length(); i++) {
			User user;
			if (g_UserList.get(user, i) && !stricmp((char *)user.name, name)) {
				user.flags = (user.flags & mask) | flags;
				g_UserList.replace(user, i);
			}
		}
		Draw_Player_List(0, false);
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnSquadInfo(HRESULT res, unsigned long id, Squad *squad)
{
	g_SquadInfoRequests--;
	if (g_RequestingOwnSquadInfo) {
		g_RequestingOwnSquadInfo = 0;
		g_OwnSquadID = id;
		if (res != 0) {
			return(S_OK);
		}
		strcpy(g_OwnSquadName, (char *)squad->abbreviation);
	} else if (res != 0) {
		return(S_OK);
	}
	for (int i = 0; i < g_UserList.length(); i++) {
		User * user = NULL;
		g_UserList.getPointer(&user, i);
		if (user->squadID == id) {
			strcpy((char *)user->squadabbrev, (char *)squad->abbreviation);
			strcpy((char *)user->squadname, (char *)squad->name);
		}
	}
	if (g_SquadInfoRequests == 0) {
		Draw_Player_List(0, false);
	}
	return(S_OK);
}

extern char _kickmessage[64]; // level-2 1.001: 0xB10840
bool __fastcall Too_Many_Players(void); // level-2 1.001: 0x5C2EF0 (netshare.cpp)
bool __fastcall Is_Game_Full(void); // level-2 1.001: 0x5C2EB0 (netshare.cpp)
void __fastcall _DrawMessage(int color, wchar_t const * message, HWND window); // level-2 1.001: 0x5BD930 (netshare.cpp)

STDMETHODIMP CChatEventSink::OnUserKick(HRESULT res, Channel *channel, User *kicked, User *kicker)
{
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	if (res < 0) {
		return(S_OK);
	}
	memset(_kickmessage, 0, sizeof(_kickmessage));
	if (strnicmp((char *)channel->name, "Lob_33_", strlen("Lob_33_")) == 0) {
		int lobby = atol((char *)channel->name + strlen("Lob_33_"));
		int copy = lobby / 6;
		int slot = lobby % 6;
		if (copy == 0) {
			sprintf(_kickmessage, "%s", g_Lobbies[slot]);
		} else {
			sprintf(_kickmessage, "%s %d", g_Lobbies[slot], copy + 1);
		}
	} else {
		sprintf(_kickmessage, "%s", channel->name);
	}
	if (kicked->flags & 0x8000) {
		WideWstring wide;
		if (g_CurrentChannel.type && Too_Many_Players()) {
			wide = StringTable::LoadString("TXT_CHANNEL_FULL", NULL, "C:\\RA2\\wonline.cpp", 6466);
		} else {
			wchar_t message[1024];
			memset(message, 0, sizeof(message));
			swprintf(message, StringTable::LoadString("TXT_YOURE_KICKED", NULL, "C:\\RA2\\wonline.cpp", 6470), Narrow_To_Wide((char *)channel->name), Narrow_To_Wide((char *)kicker->name));
			wide = message;
		}
		if (!g_CurrentChannel.type) {
			ODMessageBox(wide.get(), 0, Wait_Callback_Thunk, false);
			g_LobbyNumber++;
		} else {
			HWND dialog = WS_Find_Dialog(0x113);
			if (dialog) {
				_DrawMessage(ColorSystem, wide.get(), GetDlgItem(dialog, 0x53F));
			}
		}
	} else if (!Is_Game_Full()) {
		Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_USER_KICKED", NULL, "C:\\RA2\\wonline.cpp", 6494), Narrow_To_Wide((char *)kicked->name), Narrow_To_Wide((char *)channel->name), Narrow_To_Wide((char *)kicker->name));
	}
	Handle_User_Leave(*kicked);
	Draw_Player_List(0, false);
	Refresh_Game_List();
	return(S_OK);
}

#include "voc.h"
#include "gadget.h"
void __fastcall Darken_Surface(Surface * surface, bool update); // level-2 1.001: 0x514F50 (init.cpp)
BOOL CALLBACK WOL_Page_Reply_Dialog_Proc(HWND win, UINT uMsg, WPARAM wParam, LPARAM lParam); // level-2 1.001: 0x745F70, provisional name (dialog 0x11E)
Wstring Buddy_Name_From_List(HWND list); // level-2 1.001: 0x745EB0, defined below

static inline void Set_Item_Wstring(HWND item, Wstring const & text)
{
	SendMessageA(item, OD_SETTEXT, 0, (LPARAM)text.text());
}

STDMETHODIMP CChatEventSink::OnPaged(HRESULT res, User *user, LPCSTR message)
{
	wchar_t text[256];
	if (res < 0) {
		return(S_OK);
	}
	WideWstring wide = Widen_Text(message);
	if (g_PlayingNetGame) {
		swprintf(text, L"(%hs) %s", user->name, wide.get());
		int scheme = GadgetClass::Get_Color_Scheme();
		Session.Messages.Add_Message(NULL, 0, text, scheme, TextPrintType(0x16), int(Rule->MessageDelay * TICKS_PER_MINUTE), false);
		Map.Flag_To_Redraw(GS_REDRAW_DIRTY);
		SMessagePrintf(ColorPaged, L"(%hs) %s", user->name, wide.get());
	} else {
		HWND top = WS_Top_Window();
		while (top) {
			if (GetDlgItem(top, 0x53F)) {
				Lobby_Chat_Printf(ColorPaged, L"(%hs) %s", user->name, wide.get());
				break;
			}
			if (GetDlgItem(top, 0x5B5)) {
				SMessagePrintf(ColorPaged, L"(%hs) %s", user->name, wide.get());
			}
			top = WS_Next_Lower_Dialog(top);
		}
		if (!top) {
			ReleaseCapture();
			Darken_Surface(NULL, true);
			top = OwnerDraw::Begin_Dialog(0x11E, (DLGPROC)WOL_Page_Reply_Dialog_Proc, 0);
			if (top) {
				SetFocus(top);
				Lobby_Chat_Printf(ColorPaged, L"(%hs) %s", user->name, wide.get());
				ShowWindow(top, SW_SHOWNORMAL);
			}
		}
		Set_Item_Wstring(GetDlgItem(top, 0x718), Buddy_Name_From_List(GetDlgItem(top, 0x53F)));
	}
	VocClass::PlayGlobal(Rule->IncomingMessage, 1.0f, 0x2000);
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnPagedUnicode(HRESULT res, User *user, const unsigned short *message)
{
	wchar_t text[256];
	if (res < 0) {
		return(S_OK);
	}
	if (g_PlayingNetGame) {
		swprintf(text, L"(%hs) %s", user->name, message);
		int scheme = GadgetClass::Get_Color_Scheme();
		Session.Messages.Add_Message(NULL, 0, text, scheme, TextPrintType(0x16), int(Rule->MessageDelay * TICKS_PER_MINUTE), false);
		Map.Flag_To_Redraw(GS_REDRAW_DIRTY);
		SMessagePrintf(ColorPaged, L"(%hs) %s", user->name, message);
	} else {
		HWND top = WS_Top_Window();
		while (top) {
			if (GetDlgItem(top, 0x53F)) {
				Lobby_Chat_Printf(ColorPaged, L"(%hs) %s", user->name, message);
				break;
			}
			if (GetDlgItem(top, 0x5B5)) {
				SMessagePrintf(ColorPaged, L"(%hs) %s", user->name, message);
			}
			top = WS_Next_Lower_Dialog(top);
		}
		if (!top) {
			ReleaseCapture();
			Darken_Surface(NULL, true);
			top = OwnerDraw::Begin_Dialog(0x11E, (DLGPROC)WOL_Page_Reply_Dialog_Proc, 0);
			SetFocus(top);
			Lobby_Chat_Printf(ColorPaged, L"(%hs) %s", user->name, message);
			ShowWindow(top, SW_SHOWNORMAL);
		}
		Set_Item_Wstring(GetDlgItem(top, 0x718), Buddy_Name_From_List(GetDlgItem(top, 0x53F)));
	}
	VocClass::PlayGlobal(Rule->IncomingMessage, 1.0f, 0x2000);
	return(S_OK);
}

extern HRESULT g_LastIgnoredNetStatus; // level-2 1.001: 0xB100C8, provisional name

STDMETHODIMP CChatEventSink::OnNetStatus(HRESULT res)
{
	wchar_t message[256];
	if (g_IgnoreNetStatus) {
		SetEvent(g_WaitEventHandles[EV_NETIGNORE]);
		g_LastIgnoredNetStatus = res;
		return(S_OK);
	}
	if (res == 0x4012F) {
		if (g_PlayingNetGame) {
			if (!g_ConnectionLost) {
				message[0] = 0;
				swprintf(message, StringTable::LoadString("TXT_WOL_CONNLOST", NULL, "C:\\RA2\\wonline.cpp", 6111));
				int scheme = GadgetClass::Get_Color_Scheme();
				Session.Messages.Add_Message(NULL, 0, message, scheme, TextPrintType(0x16), int(Rule->MessageDelay * TICKS_PER_MINUTE), false);
				Map.Flag_To_Redraw(GS_REDRAW_DIRTY);
				g_ConnectionLost = true;
				g_ChannelCount = 0;
				memset(&g_CurrentChannel, 0, sizeof(g_CurrentChannel));
				memset(&g_PendingChannel, 0, sizeof(g_PendingChannel));
				DebugString("NetStatus disconnect ingame\n");
			}
		} else {
			if (WS_Find_Dialog(0x113)) {
				ODMessageBox(StringTable::LoadString("TXT_YOURE_DISCON", NULL, "C:\\RA2\\wonline.cpp", 6129), 0, Wait_Callback_Thunk, false);
			}
			g_IgnoreNetStatus = true;
			g_ConnectionLost = true;
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			g_ChannelCount = 0;
			memset(&g_CurrentChannel, 0, sizeof(g_CurrentChannel));
			memset(&g_PendingChannel, 0, sizeof(g_PendingChannel));
			DebugString("NetStatus disconnect not in game \n");
		}
	}
	return(S_OK);
}

extern HRESULT g_OnNewNickResult; // level-2 1.001: 0xB100D0, provisional name

static inline rc_ptr<PlayerProfile> Profile_For_Nick(char const * nick)
{
	Wstring name(nick);
	return(PlayerProfile::Load(name));
}

STDMETHODIMP CNetUtilEventSink::OnNewNick(HRESULT res, LPCSTR message, LPCSTR nick, LPCSTR pass)
{
	DebugString("OnNewNick\n");
	g_OnNewNickResult = res;
	if (res == 0) {
		rc_ptr<PlayerProfile> profile = Profile_For_Nick(nick);
		int nicknum = 0;
		WOLOptionsClass options;
		options.Load();
		if (options.Is_Bit1_Clear()) {
			int locale = profile->Locale;
			nicknum = Save_Nickname(nick, pass, true, locale);
			Session.Write_MultiPlayer_Settings();
		}
		bool login_mode = true;
		bool combo_mode = false;
		HWND dialog = WS_Find_Dialog(0x10F);
		if (dialog == NULL) {
			dialog = WS_Find_Dialog(0x11D);
			combo_mode = (dialog != NULL);
			if (dialog == NULL) {
				login_mode = false;
				dialog = WS_Find_Dialog(0x114);
			}
		}
		if (dialog != NULL) {
			HWND item = GetDlgItem(dialog, 0x628);
			if (combo_mode) {
				SendMessageA(item, OD_SETTEXT, 0, (LPARAM)nick);
			} else {
				int index = SendMessageA(item, 0x4BC, 0, (LPARAM)nick);
				SendMessageA(item, CB_SETITEMDATA, index, nicknum);
				SendMessageA(item, CB_SETCURSEL, index, 0);
			}
			if (login_mode) {
				g_NickName = nick;
				g_LoginPassword = pass;
				HWND password = GetDlgItem(dialog, 0x72C);
				SendMessageA(password, OD_SETTEXT, 0, (LPARAM)g_LoginPassword.text());
				g_PlaintextPassword = true;
				EnableWindow(GetDlgItem(dialog, 0x539), TRUE);
				if (!combo_mode) {
					EnableWindow(GetDlgItem(dialog, 0x72D), FALSE);
					SendMessageA(GetDlgItem(dialog, 0x72D), BM_SETCHECK, 1, 0);
				}
			} else {
				SendMessageA(GetDlgItem(dialog, 0x6FF), BM_SETCHECK, 0, 0);
				EnableWindow(GetDlgItem(dialog, 0x6FF), TRUE);
			}
			if (!combo_mode) {
				EnableWindow(GetDlgItem(dialog, 0x6EB), TRUE);
				Wstring name(nick);
				profile->PopulateDialog(dialog, &name, true);
			}
		}
	}
	if (message) {
		wchar_t text[0x1400];
		Char_To_Wide(text, message, -1);
		ODMessageBox(text, 0, Wait_Callback_Thunk, false);
	} else {
		ODMessageBox(L"Unknown Status", 0, Wait_Callback_Thunk, false);
	}
	HWND chat = WS_Find_Dialog(0xC4);
	if (chat) {
		g_ActiveWaitFlags &= ~0x100;
		if (g_ActiveWaitFlags == 0) {
			WS_Destroy_Dialog(chat, 0);
		}
	}
	HWND top = WS_Top_Window();
	HWND input = GetDlgItem(top, 0x540);
	if (input) {
		SetFocus(input);
	}
	return(S_OK);
}

extern int g_GameIconsLoaded; // level-2 1.001: 0xB1015C, provisional name
extern int g_ListIconHeight; // level-2 1.001: 0x7E6B6C, provisional name

STDMETHODIMP CChatEventSink::OnConnection(HRESULT res, LPCSTR motd)
{
	g_OnConnectionResult = res;
	if (res < 0) {
		g_IgnoreNetStatus = true;
	}
	switch (res) {
		case (HRESULT)0x80040064:
			wcscpy(g_LastErrorMessage, StringTable::LoadString("TXT_LOGIN_USED", NULL, "C:\\RA2\\wonline.cpp", 4082));
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			break;
		case (HRESULT)0x80040065:
			wcscpy(g_LastErrorMessage, StringTable::LoadString("TXT_BADPASS", NULL, "C:\\RA2\\wonline.cpp", 4087));
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			break;
		case CHAT_E_BANNED:
			wcscpy(g_LastErrorMessage, StringTable::LoadString("TXT_BANNED", NULL, "C:\\RA2\\wonline.cpp", 4092));
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			break;
		case CHAT_E_DISABLED:
			wcscpy(g_LastErrorMessage, StringTable::LoadString("TXT_DISABLED", NULL, "C:\\RA2\\wonline.cpp", 4098));
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			break;
		case CHAT_E_SERIALBANNED:
			wcscpy(g_LastErrorMessage, StringTable::LoadString("TXT_BANNED", NULL, "C:\\RA2\\wonline.cpp", 4103));
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			break;
		case CHAT_E_SERIALDUP:
			wcscpy(g_LastErrorMessage, StringTable::LoadString("TXT_SERIALDUP", NULL, "C:\\RA2\\wonline.cpp", 4108));
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			break;
		case CHAT_E_SERIALUNKNOWN:
			wcscpy(g_LastErrorMessage, StringTable::LoadString("TXT_SERIALUNKNOWN", NULL, "C:\\RA2\\wonline.cpp", 4113));
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			break;
		case CHAT_E_SKUSERIALMISMATCH:
			wcscpy(g_LastErrorMessage, StringTable::LoadString("TXT_SKUSERIALMISMATCH", NULL, "C:\\RA2\\wonline.cpp", 4118));
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			break;
		default:
			wcscpy(g_LastErrorMessage, StringTable::LoadString("TXT_CANT_CONNECT", NULL, "C:\\RA2\\wonline.cpp", 4124));
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			break;
		case 0:
			if (g_GameIconsLoaded == 0) {
				char const * gametypes;
				g_pChat->GetGametypeList(&gametypes);
				char * buffer = new char[strlen(gametypes) + 32];
				strcpy(buffer, gametypes);
				strcat(buffer, ",-1,0,18");
				char * token = strtok(buffer, ",");
				while (token) {
					int type = atol(token);
					unsigned char * bitmap;
					int bytes;
					char const * name;
					char const * url;
					g_pChat->GetGametypeInfo(type, g_ListIconHeight, &bitmap, &bytes, &name, &url);
					char bitmap_name[64];
					sprintf(bitmap_name, "gt%d.bmp", type);
					SurfaceCache.CacheBMP(bitmap_name, bitmap, bytes, 2);
					token = strtok(NULL, ",");
				}
				delete [] buffer;
				g_GameIconsLoaded = 1;
			}
			if (g_ShowMOTD) {
				g_Motd = motd;
			} else {
				g_Motd.clear();
			}
			g_ConnectionLost = false;
			g_ChannelCount = 0;
			memset(&g_CurrentChannel, 0, sizeof(g_CurrentChannel));
			memset(&g_PendingChannel, 0, sizeof(g_PendingChannel));
			SetEvent(g_WaitEventHandles[EV_CONNECTED]);
			break;
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnChannelCreate(HRESULT res, Channel *channel)
{
	if (res < 0) {
		Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_CHANCREATE_FAILED", NULL, "C:\\RA2\\wonline.cpp", 4170));
		g_IsChannelCreator = 0;
		g_CurrentChannel.name[0] = 0;
		Close_Wait_Window(4);
		return(S_OK);
	}
	if (channel->type == 0) {
		Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_CREATED_CHAN", NULL, "C:\\RA2\\wonline.cpp", 4180), Narrow_To_Wide((char *)channel->name));
	} else {
		memset(g_UserInfo, 0, sizeof(ChannelUserInfo) * 16);
		strcpy(g_UserInfo[0].name, g_NickName.get());
		g_UserInfo[0].house = Session.House;
		g_UserInfo[0].Unknown_1C = 0;
		g_UserInfo[0].color = Session.PrefColor;
		g_UserInfo[0].accepted = 1;
	}
	memcpy(&g_CurrentChannel, channel, sizeof(Channel));
	g_IsChannelCreator = 1;
	g_ChannelCount++;
	DebugString("Created channel\n");
	if (g_pChat && channel->type != 0) {
		char info[80];
		memset(info, 0, sizeof(info));
		Encode_Channel_ExInfo(info);
		info[40] = 0;
		g_pChat->SetChannelExInfo(info);
	}
	Close_Wait_Window(4);
	return(S_OK);
}

BOOL CALLBACK WOL_Download_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // level-2 1.001: 0x73BD10, provisional name (dialog 0xD3)

STDMETHODIMP CChatEventSink::OnUpdateList(HRESULT res, Update *updates)
{
	int count = 0;
	char working_dir[257];
	char fullpath[257];
	char localfile[257];
	wchar_t status[200];
	if (res < 0 || updates == NULL) {
		SetEvent(g_WaitEventHandles[EV_ABORT]);
		return(S_OK);
	}
	g_SuspendChatPump = 1;
	Update * tmp = updates;
	while (tmp != NULL) {
		tmp = tmp->next;
		count++;
	}
	Close_Wait_Window(0x10);
	if (ODMessageBox(StringTable::LoadString("TXT_UPGRADEREQUIRED", NULL, "C:\\RA2\\wonline.cpp", 3875), MB_YESNO, Wait_Callback_Thunk, false) == IDNO) {
		SetEvent(g_WaitEventHandles[EV_ABORT]);
		return(S_OK);
	}
	GetCurrentDirectoryA(0x100, working_dir);
	int i = 0;
	while (updates != NULL) {
		sprintf(fullpath, "%s/%s", updates->patchpath, updates->patchfile);
		sprintf(localfile, "%s\\%s", updates->localpath, updates->patchfile);
		CreateDirectoryA((char *)updates->localpath, NULL);
		g_pDownload->DownloadFile((char *)updates->server, (char *)updates->login, (char *)updates->password, fullpath, localfile, "SOFTWARE\\Westwood\\Red Alert 2");
		i++;
		swprintf(status, StringTable::LoadString("TXT_DOWNLOADING_X_OF_Y", NULL, "C:\\RA2\\wonline.cpp", 3897), i, count);
		WideWstring text(status);
		SimpleWonlineDialogControl control;
		HWND dialog = OwnerDraw::Begin_Dialog(0xD3, (DLGPROC)WOL_Download_Dialog_Proc, 0);
		HWND title = GetDlgItem(dialog, 0x5C7);
		SendMessageA(title, 0x4B2, 0, (LPARAM)text.text());
		if (WS_Wait_Dialog(dialog, Wait_Callback_Thunk, false, true, true) == IDCANCEL) {
			SetEvent(g_WaitEventHandles[EV_ABORT]);
			SetCurrentDirectoryA(working_dir);
			return(S_OK);
		}
		updates = updates->next;
	}
	ODMessageBox(StringTable::LoadString("TXT_GAME_RESTART", NULL, "C:\\RA2\\wonline.cpp", 3929), 0, Wait_Callback_Thunk, false);
	SetEvent(g_WaitEventHandles[EV_QUITGAME]);
	SetCurrentDirectoryA(working_dir);
	return(S_OK);
}


#pragma auto_inline(on) // RA2: as above



// level-2 1.001 (wol_b, 2026-11-22): PROPOSED tail of wonline.cpp, to be appended at the end of P/src/m85/src/wonline.cpp by its owner.
// Structure adapted from gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later; FUN_007983E0..FUN_007A27D0), checked against RA2 1.001 bytes.
// Also required: make Set_Match_State a non-inline function (prototype at its old place, see wol_b_set_match_state.diff).


// level-2 1.001 (wol_b): the tail of wonline.cpp after Reset_Wait_Events (0x741080-0x74A1F0); proposed source, verified in a scratch copy
void Wol_Send_Start_Reminder(void) // RA2: 0x0075C960 (1.001 0x0074A150), sends the game option "G" through the chat service
{
	if (g_pChat) {
		g_pChat->RequestPublicGameOptions("G");
	}
}

void Wol_Handle_Start_Reminder(void) // RA2: 0x0075C980 (1.001 0x0074A170), the joiner is told to accept
{
	HWND dialog = WS_Top_Window();
	HWND item = GetDlgItem(dialog, 0x59F);
	bool joiner;
	{
		Wstring host((char const *)NULL);
		joiner = GetPlayerAccepted(host) != 1;
	}
	if (joiner) {
		SendMessage(item, 0x4DC, 0, 1);
		Lobby_Chat_Printf(-1, StringTable::LoadString("GUI:HostGameStartJoiner", NULL, "C:\\RA2\\wonline.cpp", 19955)); // level-2 1.001: line literal
	}
}

void Wol_Reset_Ready(void) // RA2: 0x0075CA00 (1.001 0x0074A1F0), sends message 0x4DC to the ready button
{
	HWND dialog = WS_Top_Window();
	HWND item = GetDlgItem(dialog, 0x59F);
	SendMessage(item, 0x4DC, 0, 0);
}

void Reset_Channel_State(void) // RA2: 0x00753F10 (1.001 0x007422A0), clears the channel lists and the current channel
{
	g_UserChannels.setEmpty();
	memset(&g_CurrentChannel, 0, sizeof(g_CurrentChannel));
	memset(&g_PendingChannel, 0, sizeof(g_PendingChannel));
	g_GameChannelList.setEmpty();
	g_UserList.setEmpty();
	g_ChannelCount = 0;
}

void Close_All_Dialogs(void) // RA2: 0x00753F50 (1.001 0x007422E0), destroys the dialogs that are still open
{
	HWND window = WS_Top_Window();
	while (window) {
		WS_Destroy_Dialog(window, 0);
		window = WS_Top_Window();
	}
}

BOOL CALLBACK Wonline_Lobby_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 1.001 0x00741700, the lobby dialog (0x114)

int Run_Wonline_Lobby(void) // RA2: 0x00753F70 (1.001 0x00742300), the lobby; -2 or -1 to leave
{
	int result = Init_Wonline();
	if (result != 1) {
		return(result);
	}
	if (Fetch_Server_List()) {
		return(0);
	}
	SimpleWonlineDialogControl control;
	OwnerDraw::Controlled_Dialog(0x114, Wonline_Lobby_Dialog_Proc, &control);
	return(Online_Session_State != 0);
}


BOOL CALLBACK Wonline_Select_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 1.001 0x00741270, the game selection dialog (0x10E)
BOOL CALLBACK Wonline_Select_Limited_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 1.001 0x00741080, the game selection dialog (0x11C) when options bit 1 is set

int Run_Wonline_Selection_Dialog(void) // RA2: 0x00753110 (1.001 0x00741500), the game selection dialog of the Internet menu; 1 once a game is ready
{
	WOLOptionsClass options;
	options.Load();
	Darken_Surface(NULL, true);
	if (options.Is_Bit1_Clear()) {
		SimpleWonlineDialogControl control;
		OwnerDraw::Controlled_Dialog(0x10E, Wonline_Select_Dialog_Proc, &control);
		return(Online_Session_State != 0);
	}
	SimpleWonlineDialogControl control;
	OwnerDraw::Controlled_Dialog(0x11C, Wonline_Select_Limited_Dialog_Proc, &control);
	return(Online_Session_State != 0);
}

void Fill_Locale_Combo(HWND combo) // RA2: 1.001 0x007415D0, fills a combo box with the locale names (the first two inserted at the top) and selects the persona's locale
{
	Clear_ComboBox(combo);
	int count = 0;
	g_pChat->GetLocaleCount(&count);
	WOLOptionsClass options;
	options.Load();
	rc_ptr<PlayerProfile> profile;
	if (options.Is_Bit1_Clear()) {
		profile = PlayerProfile::Load(g_NickName);
	} else {
		profile = g_PlayerProfile.Get();
	}
	if (count > 0) {
		for (int i = count - 1; i >= 0; i--) {
			WideWstring name = Get_Locale_Name(i);
			int item;
			if (i < 2) {
				item = SendMessage(combo, 0x4C1, 0, (LPARAM)name.get());
			} else {
				item = SendMessage(combo, 0x4C2, 0, (LPARAM)name.get());
			}
			SendMessage(combo, CB_SETITEMDATA, item, i);
			if (profile.Get() && i == profile->Locale) {
				SendMessage(combo, CB_SETCURSEL, item, 0);
			}
		}
	}
}

bool __fastcall Find_Channel(Wstring const & name, ArrayList<Channel> & list, Channel & result); // RA2: 1.001 0x00747440, defined below

bool Can_Join_Buddy_Game(void) // RA2: 1.001 0x007440D0, the selected buddy is in a game the player may join
{
	if (g_SelectedBuddy.length() == 0) {
		return(false);
	}
	unsigned int state = 0;
	g_BuddyStatus.getValue(g_SelectedBuddy, state);
	if (state == 4) {
		return(true);
	}
	if (state != 5) {
		return(false);
	}
	Channel channel;
	if (!g_BuddyChannels.getValue(g_SelectedBuddy, channel)) {
		return(false);
	}
	Wstring game_name((char *)channel.name);
	Channel game;
	if (!Find_Channel(game_name, g_GameChannelList, game)) {
		return(false);
	}
	return(Can_Join_Channel(&game, false));
}

void Open_Buddy_Page_Dialog(void) // RA2: 1.001 0x007442B0, opens the dialog (0x11E) and waits for it
{
	HWND dialog = WS_Create_Dialog(ProgramInstance, 0x11E, MainWindow, WOL_Page_Reply_Dialog_Proc, 0);
	Show_Dialog(dialog, 0x11E);
	SendMessage(dialog, 0x4A9, 0, 1);
	ShowWindow(dialog, SW_SHOWNORMAL);
	WS_Wait_Dialog(dialog, WOL_Wait_Callback);
}

bool Is_Selected_Buddy_Known(void) // RA2: 1.001 0x00744310, the status of the selected buddy is above 2
{
	if (g_SelectedBuddy.length() == 0) {
		return(false);
	}
	unsigned int state = 0;
	g_BuddyStatus.getValue(g_SelectedBuddy, state);
	if ((int)state >= 0 && (int)state <= 2) {
		return(false);
	}
	return(true);
}

void Update_Buddy_Buttons(HWND dialog) // RA2: 1.001 0x00744390, enables the buttons of the buddy dialog
{
	EnableWindow(GetDlgItem(dialog, 0x703), g_SelectedBuddy.length() > 0);
	EnableWindow(GetDlgItem(dialog, 0x62D), Can_Join_Buddy_Game());
	EnableWindow(GetDlgItem(dialog, 0x5C2), Is_Selected_Buddy_Known());
}

bool __fastcall Find_Channel(Wstring const & name, ArrayList<Channel> & list, Channel & result) // RA2: 1.001 0x00747440, the channel of the list with this name
{
	memset(&result, 0, sizeof(Channel));
	for (int i = 0; i < list.length(); i++) {
		list.get(result, i);
		if (stricmp((char *)result.name, name.text()) == 0) {
			return(true);
		}
	}
	memset(&result, 0, sizeof(Channel));
	return(false);
}

void Set_Match_State(int state, int timeout, int result) // RA2: 1.001 0x00747ED0, the four values of the match state are set together (some callers expand it)
{
	g_MatchResult = result;
	g_MatchState = state;
	g_MatchTimeout = timeout;
	g_MatchStartTime = time(0);
}

// level-2 1.001: INFERRED macro. The dialog procs store the WM_INITDIALOG parameter record (DWL_USER) through the
// do/while(0) expansion of a macro (gibbo101 YR Select_WDT_Location_Proc form); the statement shape decides VC6 numbering.
#define Set_Dialog_Init_Param(window, lparam) do SetWindowLong(window, DWL_USER, ((int *)lparam)[1]); while (0)

int __fastcall Standard_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 1.001 0x005F77C0, the common part of the owner drawn dialog procs (ownrdraw.cpp)

LRESULT CALLBACK Wonline_Autologin_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x00755070 (1.001 0x00743390), the dialog (0x112) after a login: OK keeps the nickname as the auto login persona, Cancel sets the auto login from the check box 0x6F9
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	OwnerDraw::SimpleDialogControl * control = (OwnerDraw::SimpleDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_ERASEBKGND:
		return(1);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(1);
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case IDOK:
			WOL_Set_Auto_Login_Persona(g_NickName);
			control->Set_Window((unsigned int)window, (HWND)1);
			break;
		case IDCANCEL:
			{
				bool checked = IsDlgButtonChecked(window, 0x6F9) == BST_CHECKED;
				WOL_Set_Auto_Login(!checked);
				control->Set_Window((unsigned int)window, (HWND)2);
			}
			break;
		}
		break;
	}
	return(0);
}

extern int Online_Session_Return; // RA2: 1.001 0x00A255D8, the state the online menu (4) returns to (as in wolstart.cpp)

BOOL CALLBACK Wonline_Select_Limited_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x00741080, the game selection dialog (0x11C): each button sets the next state of the online session
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	OwnerDraw::SimpleDialogControl * control = (OwnerDraw::SimpleDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_ERASEBKGND:
		return(1);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(1);
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x6E0:
			Online_Session_State = 1;
			control->Set_Window((unsigned int)window, (HWND)0x6E0);
			break;
		case 0x6E1:
			Online_Session_State = 3;
			control->Set_Window((unsigned int)window, (HWND)0x6E1);
			break;
		case 0x6E2:
			Online_Session_State = 4;
			Online_Session_Return = 0;
			control->Set_Window((unsigned int)window, (HWND)0x6E2);
			break;
		case 0x6E3:
			Online_Session_State = 2;
			control->Set_Window((unsigned int)window, (HWND)0x6E3);
			break;
		case 0x686:
			Online_Session_State = 0;
			control->Set_Window((unsigned int)window, (HWND)0x686);
			break;
		}
		break;
	}
	return(0);
}

BOOL CALLBACK Wonline_Select_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x00741270, the game selection dialog (0x10E): as above with the lobby button (0x6E4) and the profile of the persona (0x497)
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	OwnerDraw::SimpleDialogControl * control = (OwnerDraw::SimpleDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_ERASEBKGND:
		return(1);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(1);
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case 0x497:
		if (g_NickName.length() > 0) {
			rc_ptr<PlayerProfile> profile = PlayerProfile::Load(g_NickName);
			if (profile.Get()) {
				profile->PopulateDialog(window, &g_NickName, true);
			}
		}
		break;
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x6E0:
			Online_Session_State = 1;
			control->Set_Window((unsigned int)window, (HWND)0x6E0);
			break;
		case 0x6E1:
			Online_Session_State = 3;
			control->Set_Window((unsigned int)window, (HWND)0x6E1);
			break;
		case 0x6E2:
			Online_Session_State = 4;
			Online_Session_Return = 0;
			control->Set_Window((unsigned int)window, (HWND)0x6E2);
			break;
		case 0x6E3:
			Online_Session_State = 2;
			control->Set_Window((unsigned int)window, (HWND)0x6E3);
			break;
		case 0x6E4:
			Online_Session_State = 5;
			control->Set_Window((unsigned int)window, (HWND)0x6E4);
			break;
		case 0x686:
			Online_Session_State = 0;
			control->Set_Window((unsigned int)window, (HWND)0x686);
			break;
		}
		break;
	}
	return(0);
}

bool __fastcall Can_Join_Channel(Channel const * channel, bool check) // RA2: 0x00755CD0 (1.001 0x00743F10, no observer argument), whether the player may join the game channel: the session kind, the clan, the version and the room; prints why not when check is set
{
	bool restricted;
	if (Is_Channel_Flag_11(channel)) {
		restricted = true;
	} else if (!Is_Channel_Flag_12(channel)) {
		restricted = false;
	} else {
		restricted = true;
	}
	if (restricted != Is_Tournament_Session()) {
		return(false);
	}
	if (Is_Channel_Flag_8(channel) && g_OwnSquadID < 1) {
		if (check) {
			Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_NO_CLAN", NULL, "C:\\RA2\\wonline.cpp", 17843)); // level-2 1.001: line literal
		}
		return(false);
	}
	char text[132];
	strcpy(text, (char *)channel->exInfo);
	int build;
	int hash;
	int ai_count;
	Parse_Channel_ExInfo(text, &build, &hash, &ai_count);
	if (Build_Number() == build && GetINIHash() == hash) {
		if (channel->currentUsers + ai_count >= channel->maxUsers) {
			if (check) {
				Lobby_Chat_Printf(-1, StringTable::LoadString("WOL:GameFull", NULL, "C:\\RA2\\wonline.cpp", 17878)); // level-2 1.001: line literal
			}
		} else {
			return(true);
		}
	} else if (check) {
		Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_MISMATCH", NULL, "C:\\RA2\\wonline.cpp", 17872)); // level-2 1.001: line literal
	}
	return(false);
}

extern long g_BuddyFindTime; // RA2: 1.001 0x00B0FCCC, when it was asked for

void Request_Next_Buddy_Find(void) // RA2: 1.001 0x007447E0, asks the chat service for the channel of the next buddy of the request list (one every 5 seconds)
{
	if (g_BuddyFindName.length() > 0) {
		if ((unsigned)(time(NULL) - g_BuddyFindTime) < 5) {
			return;
		}
		g_BuddyFindName.clear();
	}
	if (g_BuddyRequests.length() == 0) {
		return;
	}
	g_BuddyRequests.removeHead(g_BuddyFindName);
	g_BuddyFindTime = time(NULL);
	User user;
	memset(&user, 0, sizeof(user));
	strcpy((char *)user.name, g_BuddyFindName.get());
	g_pChat->RequestFind(&user);
}

bool Is_Valid_New_Buddy(Wstring const & name) // RA2: 1.001 0x00744960, the name may be added as a buddy: not empty, not the player, no separators and not yet in the list
{
	Wstring lower(name);
	lower.toLower();
	if (name.length() == 0) {
		return(false);
	}
	if (((Wstring const &)lower).toLower() == ((Wstring const &)g_NickName).toLower()) {
		return(false);
	}
	if (name.containsAny(" ,;")) {
		return(false);
	}
	for (int i = 0; i < g_BuddyList.length(); i++) {
		Wstring entry;
		g_BuddyList.get(entry, i);
		entry.toLower();
		if (entry == lower) {
			return(false);
		}
	}
	return(true);
}


void Add_Buddy_Name(Wstring const & name) // RA2: 1.001 0x00744A90, adds a valid new name to the buddy lists and asks for its channel
{
	if (!Is_Valid_New_Buddy(name)) {
		return;
	}
	Wstring entry(name);
	g_BuddyList.addTail(entry);
	g_BuddyRequests.addTail(entry);
	g_BuddyLadderRequests.addTail(entry);
	Request_Next_Buddy_Find();
}

void Request_Buddy_Ladders(void); // RA2: 1.001 0x00745580, defined below

void Add_Buddy(Wstring const & name) // RA2: 1.001 0x00744D10, asks the chat service to add the buddy, then adds it to the lists
{
	if (!Is_Valid_New_Buddy(name)) {
		return;
	}
	User user;
	memset(&user, 0, sizeof(user));
	strncpy((char *)user.name, name.text(), 9);
	g_pChat->Unknown_Virtual_E0(&user); // RA2: the buddy add request (YR: RequestBuddyAdd)
	Add_Buddy_Name(name);
	Request_Buddy_Ladders();
}

static inline char Forget_Buddy_Channel(Wstring const & key, Channel & channel) { return(g_BuddyChannels.remove(key, channel)); } // RA2: a wrapper layer (as in the YR decompilation); the executable calls Dictionary::remove out of line here

void Remove_Buddy(Wstring const & name) // RA2: 1.001 0x00744FE0, removes the buddy from the list, forgets its channel and status and asks the chat service to delete it
{
	Channel channel;
	User user;
	for (int i = 0; i < g_BuddyList.length(); i++) {
		Wstring entry;
		g_BuddyList.get(entry, i);
		if (entry == name) {
			g_BuddyList.remove(i);
			Wstring key(name);
			Forget_Buddy_Channel(key, channel);
			g_BuddyStatus.remove(key);
			memset(&user, 0, sizeof(user));
			strncpy((char *)user.name, name.text(), 9);
			g_pChat->Unknown_Virtual_E4(&user); // RA2: the buddy delete request (YR: RequestBuddyDelete)
			return;
		}
	}
}

extern long g_BuddyRefreshTime; // RA2: 1.001 0x00B0FBC8, when the buddy channels were asked for last

void Refresh_Buddy_Channels(void) // RA2: 1.001 0x007452B0, requests the game channel list, then asks again for the channel of every buddy
{
	g_BuddyRefreshTime = time(NULL);
	if (!Get_Channel_List(0x21, true)) {
		SetEvent(g_WaitEventHandles[5]);
		return;
	}
	g_BuddyRequests.clear();
	for (int i = 0; i < g_BuddyList.length(); i++) {
		Wstring node;
		g_BuddyList.get(node, i);
		g_BuddyRequests.addTail(node);
	}
	Request_Next_Buddy_Find();
}

void Request_Buddy_Ladders(void) // RA2: 1.001 0x00745580, asks the ladder server for the entries of up to 10 buddies of the request list
{
	int count = g_BuddyLadderRequests.length();
	if (count > 10) {
		count = 10;
	} else if (count == 0) {
		return;
	}
	Wstring keys;
	for (int i = 0; i < count; i++) {
		Wstring name;
		g_BuddyLadderRequests.removeHead(name);
		if (keys.length() > 0) {
			keys += ":";
		}
		keys += name;
	}
	g_pNetUtil->RequestLadderList(g_LadderAddress, g_LadderPort, keys.get(), g_GameSKU & 0xFFFF00, -1, 0, 0); // RA2: no highscore request (YR asks for both)
}

void Request_All_Buddy_Ladders(void) // RA2: 1.001 0x00745730, puts every buddy into the ladder request list and asks for the first ten
{
	g_BuddyLadderRequests.clear();
	for (int i = 0; i < g_BuddyList.length(); i++) {
		Wstring node;
		g_BuddyList.get(node, i);
		g_BuddyLadderRequests.addTail(node);
	}
	Request_Buddy_Ladders();
}

void Reset_Buddy_Lists(void) // RA2: 1.001 0x00745920, clears the buddy lists, asks for the buddy list and refreshes their channels and ladder entries
{
	g_BuddyList.clear();
	g_BuddyRequests.clear();
	g_BuddyStatus.clear();
	g_BuddyChannels.clear();
	g_pChat->Unknown_Virtual_DC(); // RA2: the buddy list request (YR: RequestBuddyList)
	Refresh_Buddy_Channels();
	Request_All_Buddy_Ladders();
}

long __fastcall Get_List_Item_Wide_Text(HWND list, unsigned int index, WideWstring & text); // RA2: 1.001 0x005F8BB0, the wide text of a row of an owner drawn list (ownrdraw.cpp)

Wstring Buddy_Name_From_List(HWND list) // RA2: 1.001 0x00745EB0, the name in parentheses of the first row from the selection on, else the selected buddy
{
	int index = SendMessage(list, LB_GETCURSEL, 0, 0);
	if (index == -1) {
		index = 0;
	}
	while (index < SendMessage(list, LB_GETCOUNT, 0, 0)) {
		WideWstring text;
		Get_List_Item_Wide_Text(list, index, text);
		if (text.getChar(0) == L'(' && text.truncate(L')')) {
			text.removeChar(L'(');
			return(Wstring_Narrow(text));
		}
		index++;
	}
	return(g_SelectedBuddy);
}


// level-2 1.001 (wol_j, 2026-11-22): structure adapted from gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later; FUN_0079D720..FUN_0079DFE0), checked against RA2 1.001 bytes.
long __fastcall Get_Control_Wide_Text(HWND control, WideWstring & text); // RA2: 1.001 0x005F8AF0, the wide text of an owner drawn control (ownrdraw.cpp)
extern wchar_t EmptyUIName[]; // RA2: 1.001 0x0082208C, the shared empty wide string

BOOL CALLBACK WOL_Page_Buddy_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x00745B40, a page dialog to the selected buddy (no caller in 1.001)
{
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	switch (message) {
	case WM_DESTROY:
		return(FALSE);

	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x540:
			switch (HIWORD(wparam)) {
			case EN_CHANGE:
				{
					WideWstring text;
					Get_Control_Wide_Text((HWND)lparam, text);
					EnableWindow(GetDlgItem(window, 0x5C2), text.length() > 0);
				}
				return(FALSE);

			case EN_UPDATE:
				{
					WideWstring text;
					Get_Control_Wide_Text((HWND)lparam, text);
					text.trimTrailing(L"\n\r");
				}
				return(FALSE);

			case EN_MAXTEXT:
				SendMessage(GetDlgItem(window, 0x5C2), BM_CLICK, 0, 0);
				return(FALSE);
			}
			return(FALSE);

		case 0x5C2:
			{
				WideWstring text;
				HWND edit = GetDlgItem(window, 0x540);
				Get_Control_Wide_Text(edit, text);
				SendMessage(edit, OD_SETLABEL, 0, (LPARAM)EmptyUIName);
				if (text.length() > 0) {
					text.trimTrailing(L"\n\r");
					User user;
					memset(&user, 0, sizeof(user));
					strcpy((char *)user.name, g_SelectedBuddy.get());
					g_pChat->Unknown_Virtual_F8(&user, text.get()); // RA2: the wide page request (YR: RequestUnicodePage)
				}
				InvalidateRect(edit, NULL, FALSE);
				WS_Destroy_Dialog(window, 0x5C2);
			}
			return(FALSE);

		case 0x686:
			WS_Destroy_Dialog(window, 0x686);
			return(FALSE);
		}
		return(FALSE);

	case 0x497:
		{
			HWND edit = GetDlgItem(window, 0x540);
			SendMessage(edit, EM_LIMITTEXT, 0x78, 0);
			SendMessage(edit, OD_SETLABEL, 0, (LPARAM)EmptyUIName);
			EnableWindow(GetDlgItem(window, 0x5C2), FALSE);
			HWND label = GetDlgItem(window, 0x712);
			SendMessage(label, OD_SETTEXT, 0, (LPARAM)g_SelectedBuddy.text());
		}
		return(FALSE);

	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);

	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(TRUE);

	case WM_ERASEBKGND:
		return(TRUE);
	}
	return(FALSE);
}

static inline void Show_Page_Name(HWND window, Wstring const & name)
{
	HWND label = GetDlgItem(window, 0x718);
	SendMessage(label, OD_SETTEXT, 0, (LPARAM)name.text());
}

BOOL CALLBACK WOL_Page_Reply_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x00745F70, the page dialog (0x11E): the name of the selected row of the list 0x53F is the recipient
{
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	switch (message) {
	case WM_DESTROY:
		return(FALSE);

	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x53F:
			switch (HIWORD(wparam)) {
			case LBN_SELCHANGE:
				{
					Wstring name = Buddy_Name_From_List((HWND)lparam);
					HWND label = GetDlgItem(window, 0x718);
					SendMessage(label, OD_SETTEXT, 0, (LPARAM)name.text());
				}
				return(FALSE);
			}
			return(FALSE);

		case 0x540:
			switch (HIWORD(wparam)) {
			case EN_CHANGE:
				{
					WideWstring text;
					Get_Control_Wide_Text((HWND)lparam, text);
					EnableWindow(GetDlgItem(window, 0x5C2), text.length() > 0);
				}
				return(FALSE);

			case EN_UPDATE:
				{
					WideWstring text;
					Get_Control_Wide_Text((HWND)lparam, text);
					text.trimTrailing(L"\n\r");
				}
				return(FALSE);

			case EN_MAXTEXT:
				{
					WideWstring text;
					Get_Control_Wide_Text((HWND)lparam, text);
					text.trimTrailing(L"\n\r");
					if (text.length() > 0) {
						SendMessage(GetDlgItem(window, 0x5C2), BM_CLICK, 0, 0);
					}
				}
				return(FALSE);
			}
			return(FALSE);

		case 0x5C2:
			{
				WideWstring text;
				HWND edit = GetDlgItem(window, 0x540);
				Get_Control_Wide_Text(edit, text);
				SendMessage(edit, OD_SETLABEL, 0, (LPARAM)EmptyUIName);
				Wstring name = Buddy_Name_From_List(GetDlgItem(window, 0x53F));
				if (name.length() > 0 && text.length() > 0) {
					text.trimTrailing(L"\n\r");
					User user;
					memset(&user, 0, sizeof(user));
					strcpy((char *)user.name, name.get());
					g_pChat->Unknown_Virtual_F8(&user, text.get()); // RA2: the wide page request (YR: RequestUnicodePage)
					Lobby_Chat_Printf(ColorUser, L"[%hs] %s", g_NickName, text.get());
				}
				EnableWindow((HWND)lparam, FALSE);
				InvalidateRect(edit, NULL, FALSE);
			}
			return(FALSE);

		case 0x686:
			WS_Destroy_Dialog(window, 0x5C2);
			return(FALSE);
		}
		return(FALSE);

	case 0x497:
		{
			HWND edit = GetDlgItem(window, 0x540);
			SendMessage(edit, EM_LIMITTEXT, 0x78, 0);
			SendMessage(edit, OD_SETLABEL, 0, (LPARAM)EmptyUIName);
			EnableWindow(GetDlgItem(window, 0x5C2), FALSE);
			Show_Page_Name(window, Buddy_Name_From_List(GetDlgItem(window, 0x53F)));
			if (MouseCursor) {
				MouseCursor->Release_Mouse();
			}
		}
		return(FALSE);

	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);

	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(TRUE);

	case WM_ERASEBKGND:
		return(TRUE);
	}
	return(FALSE);
}

long __fastcall Get_Control_Text(HWND control, Wstring & text); // RA2: 1.001 0x005F8A90, the narrow text of an owner drawn control (ownrdraw.cpp)
extern char NullString[]; // RA2: 1.001 0x008248A4, the shared empty narrow string

BOOL CALLBACK WOL_Add_Buddy_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x00746400, the dialog that adds a buddy by name: 0x540 is the name, 0x702 adds it
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	OwnerDraw::SimpleDialogControl * control = (OwnerDraw::SimpleDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x540:
			if (HIWORD(wparam) != 0) {
				Wstring name;
				Get_Control_Text((HWND)lparam, name);
				EnableWindow(GetDlgItem(window, 0x702), Is_Valid_New_Buddy(name));
			}
			return(FALSE);

		case 0x686:
			control->Set_Window((unsigned int)window, (HWND)0x686);
			return(FALSE);

		case 0x702:
			{
				Wstring name;
				HWND edit = GetDlgItem(window, 0x540);
				Get_Control_Text(edit, name);
				SendMessage(edit, OD_SETTEXT, 0, (LPARAM)NullString);
				if (Is_Valid_New_Buddy(name)) {
					Add_Buddy(name);
				}
				InvalidateRect(edit, NULL, FALSE);
				control->Set_Window((unsigned int)window, (HWND)0x702);
			}
			return(FALSE);
		}
		return(FALSE);

	case 0x497:
		{
			HWND edit = GetDlgItem(window, 0x540);
			SendMessage(edit, EM_LIMITTEXT, 9, 0);
			SendMessage(edit, 0x4D1, 1, 0);
			SendMessage(edit, OD_SETTEXT, 0, (LPARAM)NullString);
			EnableWindow(GetDlgItem(window, 0x702), FALSE);
		}
		return(FALSE);

	case 0x4DA:
		PostMessage(GetDlgItem(window, 0x702), BM_CLICK, 0, 0);
		return(FALSE);

	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);

	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		// RA2: falls through
	case WM_ERASEBKGND:
		return(TRUE);
	}
	return(FALSE);
}


void Queue_User_Pings(void) // RA2: 1.001 0x007486B0, puts every user of the channel except operators and the player into the ping request list
{
	User user;
	memset(&user, 0, sizeof(user));
	DebugString("User list is %d long, adding to ping request queue\n", g_UserList.length());
	for (int i = 0; i < g_UserList.length(); i++) {
		g_UserList.get(user, i);
		if (user.flags & 1) {
			DebugString("%s is channel operator, no ping request\n", user.name);
		} else if (stricmp((char *)user.name, g_NickName.get()) == 0) {
			DebugString("%s is local user, no ping request\n", user.name);
		} else {
			Wstring name((char *)user.name);
			DebugString("Adding %s to ping request queue\n", name.get());
			g_PingRequests.addTail(name);
		}
	}
}

bool __fastcall Any_Players_From(HWND dialog, int first); // RA2: 1.001 0x005C4C60 (netshare.cpp)

bool WOL_Func_74A220(int first) // RA2: 1.001 0x0074A220, Any_Players_From on the lobby dialog (0xC2) (meaning unknown, name from netshare)
{
	return(Any_Players_From(WS_Find_Dialog(0xC2), first));
}

void WOL_Kick_User(Wstring const & name) // RA2: 1.001 0x0074A240, has the chat service kick the channel user of this name (no caller in 1.001)
{
	User user;
	user.flags = 0;
	for (int i = 0; i < g_UserList.length(); i++) {
		g_UserList.get(user, i);
		if (stricmp(name.text(), (char *)user.name) == 0) {
			g_pChat->RequestUserKick(&user);
			return;
		}
	}
}

class MPPlayerNode; // RA2: the name src/ra2 uses for NodeNameType; its wide name comes first

void WOL_Kick_Player(MPPlayerNode * node) // RA2: 1.001 0x0074A2C0 (1.006 Kick_Channel_User 0x0075CAE0), kicks the channel user of this lobby entry
{
	if (node) {
		Wstring name = Wstring_Narrow((wchar_t const *)node);
		WOL_Kick_User(name);
	}
}

bool Get_Add_Match_Buddies(void); // RA2: 1.001 0x0072DA70, the option to offer the opponent of a quick match as a buddy (WOLPersonaInformation.cpp)
void __fastcall Set_Add_Match_Buddies(bool value); // RA2: 1.001 0x0072DB60 (WOLPersonaInformation.cpp)

BOOL CALLBACK WOL_Add_Opponent_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0074A3F0, the dialog (0x122) that offers the opponent of the quick match as a buddy; the check box 0x6F9 stops asking
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	OwnerDraw::SimpleDialogControl * control = (OwnerDraw::SimpleDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_ERASEBKGND:
		return(TRUE);

	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(TRUE);

	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);

	case 0x497:
		{
			wchar_t text[128];
			swprintf(text, L"Add %hs to your buddy list?", g_MatchOpponentName.get());
			HWND label = GetDlgItem(window, 0x71B);
			SendMessage(label, OD_SETLABEL, 0, (LPARAM)text);
		}
		return(FALSE);

	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case IDOK:
			{
				bool checked = IsDlgButtonChecked(window, 0x6F9) == BST_CHECKED;
				Set_Add_Match_Buddies(!checked);
			}
			Add_Buddy(g_MatchOpponentName);
			control->Set_Window((unsigned int)window, (HWND)1);
			break;

		case IDCANCEL:
			{
				bool checked = IsDlgButtonChecked(window, 0x6F9) == BST_CHECKED;
				Set_Add_Match_Buddies(!checked);
			}
			control->Set_Window((unsigned int)window, (HWND)2);
			return(FALSE);
		}
		break;
	}
	return(FALSE);
}

void Open_Buddy_Dialog(void) // RA2: 1.001 0x0074A380, after a quick match: offers the opponent as a buddy (dialog 0x122)
{
	g_PlayingNetGame = false;
	if (!g_ConnectionLost && Get_Add_Match_Buddies() && Is_Valid_New_Buddy(g_MatchOpponentName)) {
		SimpleWonlineDialogControl control;
		OwnerDraw::Controlled_Dialog(0x122, WOL_Add_Opponent_Dialog_Proc, &control);
	}
}

void Add_Chat_Dot(void); // RA2: 1.001 0x005BDB80, adds a dot to the waiting text (netshare.cpp)

BOOL CALLBACK WOL_Match_Wait_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x00749CB0, the dialog (0x117) while the quick match is searched; 0x708/0x709 are test buttons
{
	switch (message) {
	case WM_DESTROY:
		KillTimer(window, 0);
		return(FALSE);

	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(TRUE);

	case WM_ERASEBKGND:
		return(TRUE);

	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);

	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x5C0:
			if (g_MatchState == 11) {
				WS_Destroy_Dialog(window, 0);
				return(FALSE);
			}
			SetEvent(g_WaitEventHandles[0]);
			break;

		case 0x708:
			g_pChat->RequestPublicMessage("start 4439,0,0,10000,10,1,1,1,3,Match,1,0,MP18S3.MAP,Match:mshag,4,1,xyzkerble,7,4");
			return(FALSE);

		case 0x709:
			g_pChat->RequestPublicMessage("start 4439,0,0,10000,10,1,1,1,3,Match,1,0,MP18S3.MAP,Match:xyzkerble,7,4,mshag,4,1,");
			return(FALSE);
		}
		break;

	case WM_TIMER:
		if (wparam == 0) {
			Add_Chat_Dot();
			return(FALSE);
		}
		break;

	case 0x497:
		SetTimer(window, 0, 2000, NULL);
		return(FALSE);
	}
	return(FALSE);
}

#include "mapgen.h"
#include "preview.h"
#include "progress.h"

BOOL CALLBACK WOL_Match_Found_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0074A020, the dialog (0x11F) of the found quick match with the map preview
{
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	switch (message) {
	case WM_COMMAND:
		if (LOWORD(wparam) == 0x5C0) {
			SetEvent(g_WaitEventHandles[0]);
			WS_Destroy_Dialog(window, 0x5C0);
		}
		break;

	case WM_DESTROY:
		if (MultiplayerMapPreview) {
			delete MultiplayerMapPreview;
			MultiplayerMapPreview = NULL;
		}
		return(FALSE);

	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		if (MultiplayerMapPreview) {
			MultiplayerMapPreview->Blit_Preview(window);
		} else if (Session.Options.ScenarioIndex == -1 && RandomMapGen.MapPreview) {
			RandomMapGen.MapPreview->Blit_Preview(window);
		}
		if (Progress.Has_Dialog()) {
			Progress.Display_Progress();
		}
		ValidateRect(window, NULL);
		return(TRUE);

	case WM_ERASEBKGND:
		return(TRUE);

	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);

	case 0x5C0:
		return(FALSE);
	}
	return(FALSE);
}

extern char g_MatchStartOptions[]; // RA2: 1.001 0x00B0DFFC, the options of the "Start " message of the matching server (provisional name)

static inline bool Match_Failed(char const * message)
{
	if (strnicmp(message, "Fail", 4) == 0) {
		Lobby_Chat_Printf(0x40FFFF, StringTable::LoadString("WOL:MatchFail", NULL, "C:\\RA2\\wonline.cpp", 19530));
		SetEvent(g_WaitEventHandles[EV_17]);
		return(true);
	}
	if (strnicmp(message, "PingFail", 8) == 0) {
		Lobby_Chat_Printf(0x40FFFF, StringTable::LoadString("WOL:MatchFailPing", NULL, "C:\\RA2\\wonline.cpp", 19536));
		SetEvent(g_WaitEventHandles[EV_17]);
		return(true);
	}
	if (strnicmp(message, "RankFail", 8) == 0) {
		Lobby_Chat_Printf(0x40FFFF, StringTable::LoadString("WOL:MatchFailRank", NULL, "C:\\RA2\\wonline.cpp", 19542));
		SetEvent(g_WaitEventHandles[EV_17]);
		return(true);
	}
	if (strnicmp(message, "WDTSideFail", 11) == 0) {
		Lobby_Chat_Printf(0x40FFFF, StringTable::LoadString("WOL:MatchFailWDTSide", NULL, "C:\\RA2\\wonline.cpp", 19548));
		SetEvent(g_WaitEventHandles[EV_17]);
		return(true);
	}
	return(false);
}

void __fastcall Process_Match_Message(char const * message, bool is_private) // RA2: 1.001 0x007494B0, a message of the matching server (the private ones may fail or start the match)
{
	if (is_private && Match_Failed(message)) {
		return;
	}
	if (strnicmp(message, "Exit", 4) == 0) {
		Lobby_Chat_Printf(0x40FFFF, StringTable::LoadString("WOL:MatchFailExit", NULL, "C:\\RA2\\wonline.cpp", 19554));
		g_pChat->RequestChannelLeave();
		ODMessageBox(StringTable::LoadString("WOL:MatchFailExit", NULL, "C:\\RA2\\wonline.cpp", 19557), 0, Wait_Callback_Thunk, false);
		SetEvent(g_WaitEventHandles[EV_ABORT]);
		return;
	}
	if (strnicmp(message, "Working", 7) == 0) {
		if (g_MatchState == 4) {
			Set_Match_State(5, 180, 0);
		}
		Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("GUI:MatchingProgress2", NULL, "C:\\RA2\\wonline.cpp", 19569));
		return;
	}
	if (strnicmp(message, "Info ", 5) == 0) {
		Lobby_Chat_Printf(0xFF8080, Narrow_To_Wide(message + 5));
		return;
	}
	if (strnicmp(message, "Pool ", 5) == 0) {
		message += 5;
		Lobby_Chat_Printf(0xFF8080, StringTable::LoadString("WOL:MatchingPlayerPool", NULL, "C:\\RA2\\wonline.cpp", 19579), message);
		return;
	}
	if (is_private && strnicmp(message, "Start ", 6) == 0) {
		message += 6;
		strncpy(g_MatchStartOptions, message, 0xFF);
		DebugString("%s\n", g_MatchStartOptions);
		SetEvent(g_WaitEventHandles[EV_16]);
		return;
	}
	if (stricmp(message, "ack") == 0 || stricmp(message, "nack") == 0) {
		return;
	}
	if (strnicmp(message, "need ", 5) == 0) {
		DebugString("%s\n", message);
		return;
	}
	if (is_private) {
		Lobby_Chat_Printf(0x40FFFF, StringTable::LoadString("WOL:MatchUnknownServerCommand", NULL, "C:\\RA2\\wonline.cpp", 19612));
	}
}


// ---- level-2 1.001 (wol_g): the dialog procs 0x0073B6E0 .. 0x0073CE34 ----

LRESULT __fastcall Get_Control_Wide_Text(HWND window, WideWstring & text); // RA2: 1.001 0x005F8AF0, the wide text of an owner drawn control, defined in ownrdraw.cpp
WideWstring __fastcall Limit_Name_Text(HWND control); // RA2: 1.001 0x005C5850, defined in netshare.cpp
extern wchar_t NullWString[]; // RA2: 1.001 0x0082208C, an empty wide string
extern int WDTUnknownB100A4; // RA2: 1.001 0x00B100A4, the most players of a new game channel (the new game dialog sets 4), as named in WorldDom.cpp
class CreateGameDialogControl : public WonlineStringDialogControl { // RA2: RTTI CreateGameDialogControl, vtable 0x0079A7C4, the control of the new game dialog (0xD2); the inherited Text (+0x0C) is the password of the game
public:
	CreateGameDialogControl(bool low_resolution) : Tournament(false), ClanGame(false), LowResolution(low_resolution) {} // RA2: expanded where it is used; the base constructor is called out of line there
	bool Tournament; // RA2: +0x10, box 0x629
	bool ClanGame; // RA2: +0x11, box 0x66C (only for a player of a squad)
	bool LowResolution; // RA2: +0x12, box 0x71E (only while the screen is narrower than 1024)
};
LRESULT __fastcall Get_Control_Text(HWND window, Wstring & text); // RA2: 1.001 0x005F8A90, the text of an owner drawn control, defined in ownrdraw.cpp
extern char NullString[]; // RA2: 1.001 0x008248A4, an empty narrow string
extern Wstring g_BirthName; // RA2: 1.001 0x00B0F1BC, the text of control 0x626 of the birth date dialog
extern Wstring g_BirthMonthText; // RA2: 1.001 0x00B0E408, the text of the month combo box (0x62E)
extern int g_BirthMonth; // RA2: 1.001 0x00B0E304, its number (0 when the dialog has no month box)
extern Wstring g_BirthDayText; // RA2: 1.001 0x00B0E7BC, the text of the day box (0x62F)
extern int g_BirthDay; // RA2: 1.001 0x00B0E3A0
extern Wstring g_BirthYearText; // RA2: 1.001 0x00B0ECA4, the text of the year box (0x630)
extern int g_BirthYear; // RA2: 1.001 0x00B0FBAC
extern int g_BirthCheck; // RA2: 1.001 0x00B0E7B8, the check box 0x631
int __fastcall Dialog_ID_Of_Window(HWND window); // RA2: 1.001 0x005E2DE0, the resource id of the dialog of this window, defined in ownrdraw.cpp
bool __fastcall Focus_Next_Tab_Item(HWND window, bool previous); // RA2: 1.001 0x005D75D0, defined in ownrdraw.cpp (level-2 1.001: the flag is a bool; ownrdraw.cpp declares it unsigned int and masks it, see the claims)
extern Wstring g_NewNickName; // RA2: 1.001 0x00B0FB18, the nickname typed in the new nickname dialogs (0x628)
extern Wstring g_NewNickPassword; // RA2: 1.001 0x00B0FBF0, the password typed there (0x72C)
extern Wstring g_NewNickPasswordVerify; // RA2: 1.001 0x00B0FBF8, the password typed again (0x627)
extern Wstring g_NewNickEmail; // RA2: 1.001 0x00B0E94C, the e-mail address of the account dialog 0xF3 (0x5E5)
extern int g_NewNickCheck; // RA2: 1.001 0x00B0EFB0, the check box (0x66B) of the account dialog 0xF4
extern int g_NewNickTabCount; // RA2: 1.001 0x00B1012C, counts the tab presses in the new nickname dialogs
#include "sounddlg.h" // RA2: the sound controls dialog of the options
namespace OwnerDraw { void __fastcall Slide_Dialog(HWND dialog, bool reverse); } // RA2: 1.001 0x005DD5E0, defined in ownrdraw.cpp
extern void * g_OptionsData; // RA2: 1.001 0x00B10134, freed when the options dialog closes (no allocation of it remains in 1.001)
extern int g_NewAllowPage; // RA2: 1.001 0x00B0E7E4, the check boxes of the options dialog; the lobby copies them into g_AllowPage ... when it returns IDOK
extern int g_NewAllowFind; // RA2: 1.001 0x00B0E9D8
extern int g_NewLangFilter; // RA2: 1.001 0x00B0ECF0
extern int g_NewLobbyMusic; // RA2: 1.001 0x00B0ECAC
extern int g_NewShowAllChannels; // RA2: 1.001 0x00B0FB1C

BOOL CALLBACK WOL_Find_Page_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0073B6E0, the find and page dialog (0xCF): finds a player (0x5C3), pages him (0x5C2) or the own squad (0x607); the page button is enabled while a name and a message are typed
{
	User user;
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	switch (message) {
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x5C1: // RA2: the name box
			{
				Wstring name;
				Get_Control_Text((HWND)lparam, name);
				WideWstring text;
				Get_Control_Wide_Text(GetDlgItem(window, 0x540), text);
				EnableWindow(GetDlgItem(window, 0x5C2), name.length() > 0 && text.length() > 0);
			}
			return(0);
		case IDCANCEL:
			WS_Destroy_Dialog(window, 2);
			return(0);
		case 0x5C2: // RA2: the page button
			{
				HWND input = GetDlgItem(window, 0x540);
				WideWstring text = Limit_Name_Text(input);
				SendMessage(input, 0x4B2, 0, (LPARAM)NullWString);
				EnableWindow(GetDlgItem(window, 0x5C2), FALSE);
				SetFocus(input);
				if (!g_pChat) {
					return(0);
				}
				Wstring name;
				Get_Control_Text(GetDlgItem(window, 0x5C1), name);
				name.truncate((unsigned int)9);
				User target;
				strcpy((char *)target.name, name.get());
				if (text.length() > 0 && strlen((char *)target.name) != 0) {
					g_pChat->Unknown_Virtual_F8(&target, text.get());
					SMessagePrintf(ColorMe, L"[%hs] %s", g_NickName, text.get());
				} else if (strlen((char *)target.name) == 0) {
					SMessagePrintf(-1, StringTable::LoadString("TXT_NAME_ERROR", NULL, "C:\\RA2\\wonline.cpp", 10854));
				} else {
					SMessagePrintf(-1, StringTable::LoadString("TXT_ENTER_MESSAGE", NULL, "C:\\RA2\\wonline.cpp", 10856));
				}
			}
			return(0);
		case 0x607: // RA2: the squad page button
			if (g_pChat) {
				if (g_OwnSquadID == 0) {
					SMessagePrintf(-1, StringTable::LoadString("TXT_NOSQUAD", NULL, "C:\\RA2\\wonline.cpp", 10868));
					return(0);
				}
				WideWstring text;
				HWND input = GetDlgItem(window, 0x540);
				Get_Control_Wide_Text(input, text);
				SendMessage(input, 0x4B2, 0, (LPARAM)NullWString);
				SetFocus(input);
				strcpy((char *)user.name, "0"); // RA2: the name "0" pages the own squad
				if (text.length() > 0) {
					g_pChat->Unknown_Virtual_F8(&user, text.get());
				} else {
					SMessagePrintf(-1, StringTable::LoadString("TXT_ENTER_MESSAGE", NULL, "C:\\RA2\\wonline.cpp", 10887));
				}
				return(0);
			}
			break;
		case 0x5C3: // RA2: the find button
			if (g_pChat) {
				char name[64];
				memset(name, 0, sizeof(name));
				SendDlgItemMessage(window, 0x5C1, 0x4B5, 60, (LPARAM)name);
				name[9] = 0;
				strcpy((char *)user.name, name);
				if (strlen((char *)user.name) != 0) {
					g_pChat->RequestFind(&user);
				} else {
					SMessagePrintf(-1, StringTable::LoadString("TXT_NAME_ERROR", NULL, "C:\\RA2\\wonline.cpp", 10811));
				}
				return(0);
			}
			break;
		}
		break;
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(0);
	case 0x497: // RA2: the dialog is shown
		{
			SendDlgItemMessage(window, 0x5C1, EM_LIMITTEXT, 9, 0);
			HWND item = GetDlgItem(window, 0x5C1);
			SendMessage(item, 0x4D1, 1, 0);
			item = GetDlgItem(window, 0x5C1);
			SendMessage(item, 0x4B4, 0, (LPARAM)NullString);
		}
		return(0);
	case 0x4DB: // RA2: tab in an edit control
		Focus_Next_Tab_Item((HWND)lparam, wparam != 0);
		return(0);
	case 0x4DA: // RA2: enter presses the page button
		PostMessage(GetDlgItem(window, 0x5C2), BM_CLICK, 0, 0);
		break;
	case 0x540: // RA2: the message box changed
		{
			WideWstring text = Limit_Name_Text((HWND)lparam);
			Wstring name;
			Get_Control_Text(GetDlgItem(window, 0x5C1), name);
			EnableWindow(GetDlgItem(window, 0x5C2), text.length() > 0 && name.length() > 0);
		}
		return(0);
	}
	return(0);
}

BOOL CALLBACK WOL_Download_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0073BD10, the download dialog (0xD3): the download sink posts 0x5F4 when the file is complete and 0x5F5 when it failed; cancel aborts the download
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	switch (message) {
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case IDCANCEL:
			g_pDownload->Abort();
			WS_Destroy_Dialog(window, 2);
			break;
		default:
			return(0);
		}
		break;
	case WM_INITDIALOG:
		break;
	case 0x5F4: // RA2: the download is complete
		WS_Destroy_Dialog(window, 1);
		break;
	case 0x5F5: // RA2: the download failed
		ODMessageBox(StringTable::LoadString("TXT_DOWNLOAD_FAILED", NULL, "C:\\RA2\\wonline.cpp", 11355), 0, Wait_Callback_Thunk, false);
		g_pDownload->Abort();
		WS_Destroy_Dialog(window, 2);
		break;
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case WM_ERASEBKGND:
		break;
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(0);
	default:
		return(0);
	}
	return(1);
}

BOOL CALLBACK WOL_New_Game_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0073BE50, the new game dialog (0xD2): the password and the kind of the game (tournament or clan game, the 640 limit); OK stores them in the control
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	CreateGameDialogControl * control = (CreateGameDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_ERASEBKGND:
		return(1);
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(0);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case IDCANCEL:
			control->Set_Window((unsigned int)window, (HWND)IDCANCEL);
			return(0);
		case IDOK:
			{
				WDTUnknownB100A4 = 4;
				Wstring text;
				Get_Control_Text(GetDlgItem(window, 0x72C), text);
				control->Text = text;
				control->Set_Window((unsigned int)window, (HWND)IDOK);
			}
			return(0);
		case 0x629:
			if (SendDlgItemMessage(window, 0x629, BM_GETCHECK, 0, 0) == 1) {
				SendDlgItemMessage(window, 0x66C, BM_SETCHECK, 0, 0);
				control->ClanGame = false;
				control->Tournament = true;
			} else {
				control->Tournament = false;
			}
			return(0);
		case 0x66C:
			if (SendDlgItemMessage(window, 0x66C, BM_GETCHECK, 0, 0) == 1) {
				SendDlgItemMessage(window, 0x629, BM_SETCHECK, 0, 0);
				control->ClanGame = true;
				control->Tournament = false;
			} else {
				control->ClanGame = false;
			}
			return(0);
		case 0x6DF:
			if (IsDlgButtonChecked(window, 0x6E0)) {
				CheckDlgButton(window, 0x6E0, 0);
			} else {
				CheckDlgButton(window, 0x6DF, 1);
			}
			return(0);
		case 0x72C:
			if (lparam) {
				Wstring text;
				Get_Control_Text((HWND)lparam, text);
				EnableWindow(GetDlgItem(window, IDOK), !text.containsAny(" ,;"));
			}
			return(0);
		case 0x6E0:
			if (IsDlgButtonChecked(window, 0x6DF)) {
				CheckDlgButton(window, 0x6DF, 0);
			} else {
				CheckDlgButton(window, 0x6E0, 1);
			}
			return(0);
		case 0x71E:
			control->LowResolution = SendMessage((HWND)lparam, BM_GETCHECK, 0, 0) == 1;
			return(0);
		}
		break;
	case 0x497: // RA2: the dialog is shown
		{
			HWND edit = GetDlgItem(window, 0x72C);
			SendMessage(edit, 0x4D1, 1, 0);
			edit = GetDlgItem(window, 0x72C);
			SendMessage(edit, 0x4B4, 0, (LPARAM)NullString);
			SendDlgItemMessage(window, 0x72C, EM_LIMITTEXT, 8, 0);
			SetFocus(GetDlgItem(window, 0x72C));
			CheckDlgButton(window, 0x629, control->Tournament != 0);
			CheckDlgButton(window, 0x66C, control->ClanGame != 0);
			if (!(Session.Type == GAME_INTERNET && Online_Session_State == 2) && g_OwnSquadID < 1) {
				EnableWindow(GetDlgItem(window, 0x66C), FALSE);
			}
			HWND box = GetDlgItem(window, 0x71E);
			bool big = VideoModeWidth >= 1024;
			EnableWindow(box, !big);
			SendMessage(box, BM_SETCHECK, (control->LowResolution && !big) ? 1 : 0, 0);
		}
		break;
	case 0x4DA: // RA2: enter in the edit control presses OK
		PostMessage(GetDlgItem(window, IDOK), BM_CLICK, 0, 0);
		break;
	}
	return(0);
}

LRESULT CALLBACK Wonline_Password_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0073C260, the password dialog (0xE1): OK stores the typed text in the control; OK is enabled only while the text has no space, comma or semicolon
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	WonlineStringDialogControl * control = (WonlineStringDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(0);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x72C: // RA2: the edit control of the password
			if (lparam) {
				Wstring text;
				Get_Control_Text((HWND)lparam, text);
				EnableWindow(GetDlgItem(window, IDOK), !text.containsAny(" ,;"));
			}
			return(0);
		case IDCANCEL:
			control->Set_Window((unsigned int)window, (HWND)IDCANCEL);
			return(0);
		case IDOK:
			{
				Wstring text;
				Get_Control_Text(GetDlgItem(window, 0x72C), text);
				control->Text = text;
				control->Set_Window((unsigned int)window, (HWND)IDOK);
			}
			return(0);
		}
		break;
	case 0x497: // RA2: the dialog is shown: the edit control takes the focus
		{
			HWND edit = GetDlgItem(window, 0x72C);
			SendMessage(edit, 0x4D1, 1, 0);
			edit = GetDlgItem(window, 0x72C);
			SendMessage(edit, 0x4B4, 0, (LPARAM)NullString);
		}
		SendDlgItemMessage(window, 0x72C, EM_LIMITTEXT, 8, 0);
		SetFocus(GetDlgItem(window, 0x72C));
		break;
	case 0x4DA: // RA2: enter in the edit control presses OK
		PostMessage(GetDlgItem(window, IDOK), BM_CLICK, 0, 0);
		break;
	}
	return(0);
}

BOOL CALLBACK WOL_Begin_Nick_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0073C460, the first dialog of a new nickname: the birth date of the player (the month box lists the month names) and a check box; the privacy button opens the privacy policy
{
	switch (message) {
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(0);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case IDOK:
			{
				g_BirthName.clear();
				HWND item = GetDlgItem(window, 0x626);
				if (item) {
					Get_Control_Text(item, g_BirthName);
				}
				g_BirthMonthText.clear();
				item = GetDlgItem(window, 0x62E);
				if (item) {
					Get_Control_Text(item, g_BirthMonthText);
					g_BirthMonth = atol(g_BirthMonthText.get());
				} else {
					g_BirthMonth = 0;
				}
				g_BirthDayText.clear();
				item = GetDlgItem(window, 0x62F);
				if (item) {
					Get_Control_Text(item, g_BirthDayText);
					g_BirthDay = atol(g_BirthDayText.get());
				}
				g_BirthYearText.clear();
				item = GetDlgItem(window, 0x630);
				if (item) {
					Get_Control_Text(item, g_BirthYearText);
					g_BirthYear = atol(g_BirthYearText.get());
				}
				g_BirthCheck = 0;
				item = GetDlgItem(window, 0x631);
				if (item) {
					g_BirthCheck = SendMessage(item, BM_GETCHECK, 0, 0);
				}
				WS_Destroy_Dialog(window, 1);
			}
			return(0);
		case IDCANCEL:
			WS_Destroy_Dialog(window, 2);
			return(0);
		case 0x576: // RA2: the privacy policy button
			ViewHTML("http://privacypolicy.westwood.com", 0);
			return(0);
		}
		return(0);
	case 0x497: // RA2: the dialog is shown
		{
			HWND item = GetDlgItem(window, 0x626);
			SendMessage(item, 0x4D1, 1, 0);
			SendMessage(GetDlgItem(window, 0x62F), EM_LIMITTEXT, 2, 0);
			SendMessage(GetDlgItem(window, 0x630), EM_LIMITTEXT, 4, 0);
			SetFocus(GetDlgItem(window, 0x62F));
			HWND combo = GetDlgItem(window, 0x62E);
			Clear_ComboBox(combo);
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_JANUARY", NULL, "C:\\RA2\\wonline.cpp", 11801));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_FEBRUARY", NULL, "C:\\RA2\\wonline.cpp", 11802));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_MARCH", NULL, "C:\\RA2\\wonline.cpp", 11803));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_APRIL", NULL, "C:\\RA2\\wonline.cpp", 11804));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_MAY", NULL, "C:\\RA2\\wonline.cpp", 11805));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_JUNE", NULL, "C:\\RA2\\wonline.cpp", 11806));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_JULY", NULL, "C:\\RA2\\wonline.cpp", 11807));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_AUGUST", NULL, "C:\\RA2\\wonline.cpp", 11808));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_SEPTEMBER", NULL, "C:\\RA2\\wonline.cpp", 11809));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_OCTOBER", NULL, "C:\\RA2\\wonline.cpp", 11810));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_NOVEMBER", NULL, "C:\\RA2\\wonline.cpp", 11811));
			SendMessage(combo, 0x4C2, 0, (LPARAM)StringTable::LoadString("TXT_DECEMBER", NULL, "C:\\RA2\\wonline.cpp", 11812));
			SendDlgItemMessage(window, 0x62E, CB_SETCURSEL, 0, 0);
			SendMessage(window, 0x4A9, 0, 1);
		}
		return(0);
	case 0x4DB: // RA2: tab in an edit control
		Focus_Next_Tab_Item((HWND)lparam, wparam != 0);
		return(0);
	}
	return(0);
}

BOOL CALLBACK WOL_New_Nick_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0073C870, the dialogs (0xF3, 0xF4, ...) that ask for a new nickname, its password twice and the account details; OK stores the texts in the new nickname globals
{
	switch (message) {
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(0);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case IDOK:
			{
				int id = Dialog_ID_Of_Window(window);
				g_NewNickName.clear();
				HWND item = GetDlgItem(window, 0x628);
				if (item) {
					Get_Control_Text(item, g_NewNickName);
				}
				g_NewNickPassword.clear();
				item = GetDlgItem(window, 0x72C);
				if (item) {
					Get_Control_Text(item, g_NewNickPassword);
				}
				g_NewNickPasswordVerify.clear();
				item = GetDlgItem(window, 0x627);
				if (item) {
					Get_Control_Text(item, g_NewNickPasswordVerify);
				}
				if (id == 0xF3) {
					g_NewNickEmail.clear();
					item = GetDlgItem(window, 0x5E5);
					if (item) {
						Get_Control_Text(item, g_NewNickEmail);
						WS_Destroy_Dialog(window, 1);
						return(0);
					}
				} else if (id == 0xF4) {
					g_NewNickCheck = 0;
					item = GetDlgItem(window, 0x66B);
					if (item) {
						g_NewNickCheck = SendMessage(item, BM_GETCHECK, 0, 0);
					}
				}
				WS_Destroy_Dialog(window, 1);
			}
			return(0);
		case IDCANCEL:
			WS_Destroy_Dialog(window, 2);
			return(0);
		}
		break;
	case 0x497: // RA2: the dialog is shown
		{
			HWND item = GetDlgItem(window, 0x628);
			SendMessage(item, 0x4D1, 1, 0);
			item = GetDlgItem(window, 0x72C);
			SendMessage(item, 0x4D1, 1, 0);
			item = GetDlgItem(window, 0x627);
			SendMessage(item, 0x4D1, 1, 0);
			item = GetDlgItem(window, 0x5E5);
			SendMessage(item, 0x4D1, 1, 0);
			SendMessage(GetDlgItem(window, 0x628), EM_LIMITTEXT, 9, 0);
			SendMessage(GetDlgItem(window, 0x72C), EM_LIMITTEXT, 8, 0);
			SendMessage(GetDlgItem(window, 0x627), EM_LIMITTEXT, 8, 0);
			SetFocus(GetDlgItem(window, 0x628));
		}
		break;
	case 0x4DB: // RA2: tab in an edit control
		g_NewNickTabCount++;
		Focus_Next_Tab_Item((HWND)lparam, wparam != 0);
		return(0);
	}
	return(0);
}

BOOL CALLBACK WOL_Options_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0073CAE0, the options dialog of the lobby (0x2BC): five check boxes (page, find, language filter, lobby music, all channels); the music box switches the lobby score at once; the sound button opens the sound controls
{
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	switch (message) {
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(0);
	case WM_DESTROY:
		GameActive = true;
		return(0);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case IDCANCEL:
			delete g_OptionsData;
			g_OptionsData = NULL;
			WS_Destroy_Dialog(window, 2);
			return(0);
		case IDOK:
			{
				g_NewAllowPage = 0;
				HWND item = GetDlgItem(window, 0x5F5);
				if (item) {
					g_NewAllowPage = SendMessage(item, BM_GETCHECK, 0, 0);
				}
				g_NewAllowFind = 0;
				item = GetDlgItem(window, 0x5F7);
				if (item) {
					g_NewAllowFind = SendMessage(item, BM_GETCHECK, 0, 0);
				}
				g_NewLangFilter = 0;
				item = GetDlgItem(window, 0x5F6);
				if (item) {
					g_NewLangFilter = SendMessage(item, BM_GETCHECK, 0, 0);
				}
				g_NewLobbyMusic = 0;
				item = GetDlgItem(window, 0x5F8);
				if (item) {
					g_NewLobbyMusic = SendMessage(item, BM_GETCHECK, 0, 0);
				}
				item = GetDlgItem(window, 0x5F9);
				if (item) {
					g_NewShowAllChannels = SendMessage(item, BM_GETCHECK, 0, 0);
				}
				delete g_OptionsData;
				g_OptionsData = NULL;
				WS_Destroy_Dialog(window, 1);
			}
			return(0);
		case 0x5F8: // RA2: the lobby music box
			if (HIWORD(wparam) == 1 || HIWORD(wparam) == 0) {
				bool play = false;
				if (result == 0) {
					play = SendMessage((HWND)lparam, BM_GETCHECK, 0, 0) == 1;
				}
				if (play) {
					if (!Theme.Still_Playing()) {
						Theme.Stop();
						Theme.Queue_Song((ThemeType)-2);
						return(0);
					}
					if (Theme.What_Is_Playing() == Theme.From_Name("INTRO")) {
						Theme.Stop();
						Theme.Queue_Song((ThemeType)-2);
						return(0);
					}
				} else {
					Theme.Queue_Song((ThemeType)-3);
					return(0);
				}
			}
			return(0);
		case 0x63A: // RA2: the sound controls
			{
				OwnerDraw::Slide_Dialog(window, false);
				Darken_Surface(NULL, true);
				GameActive = false;
				SoundControlsClass controls;
				controls.Dialog();
				ShowWindow(window, SW_SHOW);
				OwnerDraw::Set_Paint_Disabled(window, 0);
			}
			return(0);
		}
		break;
	case 0x4ED:
		ShowWindow(window, SW_HIDE);
		OwnerDraw::Set_Paint_Disabled(window, 1);
		return(0);
	case 0x497: // RA2: the dialog is shown: the boxes take the lobby settings
		if (g_AllowPage) {
			SendDlgItemMessage(window, 0x5F5, BM_SETCHECK, 1, 0);
		}
		if (g_AllowFind) {
			SendDlgItemMessage(window, 0x5F7, BM_SETCHECK, 1, 0);
		}
		if (g_LangFilter) {
			SendDlgItemMessage(window, 0x5F6, BM_SETCHECK, 1, 0);
		}
		if (g_LobbyMusic) {
			SendDlgItemMessage(window, 0x5F8, BM_SETCHECK, 1, 0);
		}
		if (g_ShowAllChannels) {
			SendDlgItemMessage(window, 0x5F9, BM_SETCHECK, 1, 0);
		}
		break;
	}
	return(0);
}


// level-2 1.001 (wol_i, 2026-11-22): the lobby dialog (0x114) of 1.001, adapted from gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later; FUN_00799080), checked against RA2 1.001 bytes
extern char EmptyString[]; // RA2: 1.001 0x008248A4, the empty text
void __fastcall NewLogin(HWND dialog); // RA2: 1.001 0x00738E50, the dialogs that create a new nickname (YR NewLogin 0x00788B00)
LRESULT __fastcall Get_Control_Text(HWND window, Wstring &text); // RA2: 1.001 0x005F8A90, defined in ownrdraw.cpp
LRESULT __fastcall Get_Combo_Item_Wide_Text(HWND window, WPARAM index, WideWstring &text); // RA2: 1.001 0x005F8C70, defined in ownrdraw.cpp
void __fastcall Fill_Side_List(HWND dialog, int id); // RA2: 1.001 0x004D0F60, defined in gdlgsupp.cpp
void __fastcall Init_Player_Colors(void); // RA2: 1.001 0x004D1700, defined in gdlgsupp.cpp
void __fastcall Fill_Color_List(HWND dialog, int id); // RA2: 1.001 0x004D18C0, defined in gdlgsupp.cpp

BOOL CALLBACK Wonline_Lobby_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x00741700, the lobby dialog (0x114): the nickname, its profile and the auto login
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	OwnerDraw::SimpleDialogControl * control = (OwnerDraw::SimpleDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(TRUE);
	case WM_ERASEBKGND:
		return(TRUE);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x687:
			Online_Session_State = 4;
			Online_Session_Return = 5;
			control->Set_Window((unsigned int)window, (HWND)0x687);
			return(FALSE);
		case 0x688:
			Open_Tournament_Page();
			return(FALSE);
		case 0x686:
			Online_Session_State = 0;
			control->Set_Window((unsigned int)window, (HWND)0x686);
			return(FALSE);
		case 0x628:
			switch (HIWORD(wparam)) {
			case CBN_SELCHANGE: {
				HWND check = GetDlgItem(window, 0x6FF);
				SendMessage(check, 0x49D, 0, 1);
				ShowWindow(check, SW_HIDE);
				int item = SendMessage((HWND)lparam, CB_GETCURSEL, 0, 0);
				int index = -1;
				if (item != -1) {
					index = SendMessage((HWND)lparam, CB_GETITEMDATA, item, 0);
				}
				g_NickName.clear();
				if (index != -1) {
					char const * nick = NULL;
					char const * pass = NULL;
					if (g_pChat->GetNick(index, &nick, &pass) == 0) {
						g_NickName = nick;
					}
				}
				rc_ptr<PlayerProfile> profile = PlayerProfile::Load(g_NickName);
				Wstring autologin = WOL_Auto_Login_Persona();
				EnableWindow(check, index != -1);
				SendMessage(check, BM_SETCHECK, (autologin == g_NickName) ? BST_CHECKED : BST_UNCHECKED, 0);
				SendMessage(check, 0x49D, 0, 0);
				ShowWindow(check, SW_SHOW);
				InvalidateRect(check, NULL, FALSE);
				if (profile.Get()) {
					profile->PopulateDialog(window, &g_NickName, false);
				}
				EnableWindow(GetDlgItem(window, 0x6EB), index != -1 && g_NickName.length() > 0);
				EnableWindow(GetDlgItem(window, 0x687), index != -1 && g_NickName.length() > 0);
				return(FALSE);
			}
			}
			break;
		case 0x629:
			switch (HIWORD(wparam)) {
			case CBN_SELCHANGE: {
				Wstring text;
				Get_Control_Text((HWND)lparam, text);
				rc_ptr<PlayerProfile> profile = PlayerProfile::Load(g_NickName);
				if (profile.Get()) {
					profile->SetName(&text);
					profile->Save(&g_NickName);
				}
				return(FALSE);
			}
			}
			break;
		case 0x62A:
			switch (HIWORD(wparam)) {
			case CBN_SELCHANGE: {
				int locale = 0;
				int item = SendMessage((HWND)lparam, CB_GETCURSEL, 0, 0);
				if (item != -1) {
					locale = SendMessage((HWND)lparam, CB_GETITEMDATA, item, 0);
				}
				rc_ptr<PlayerProfile> profile = PlayerProfile::Load(g_NickName);
				if (profile.Get()) {
					profile->SetLocale(locale, 3);
					profile->Save(&g_NickName);
				}
				return(FALSE);
			}
			}
			break;
		case 0x6A1:
			switch (HIWORD(wparam)) {
			case CBN_SELCHANGE: {
				int country = -2;
				int item = SendMessage((HWND)lparam, CB_GETCURSEL, 0, 0);
				if (item != -1) {
					country = SendMessage((HWND)lparam, CB_GETITEMDATA, item, 0);
				}
				rc_ptr<PlayerProfile> profile = PlayerProfile::Load(g_NickName);
				if (profile.Get()) {
					profile->SetCountry(country);
					profile->Save(&g_NickName);
				}
				return(FALSE);
			}
			}
			break;
		case 0x6A2:
			switch (HIWORD(wparam)) {
			case CBN_SELCHANGE: {
				int color = -2;
				int item = SendMessage((HWND)lparam, CB_GETCURSEL, 0, 0);
				if (item != -1) {
					color = SendMessage((HWND)lparam, CB_GETITEMDATA, item, 0);
				}
				rc_ptr<PlayerProfile> profile = PlayerProfile::Load(g_NickName);
				if (profile.Get()) {
					profile->SetColor(color);
					profile->Save(&g_NickName);
				}
				return(FALSE);
			}
			}
			break;
		case 0x6FF:
			if (SendMessage((HWND)lparam, BM_GETCHECK, 0, 0) == BST_CHECKED) {
				WOL_Set_Auto_Login_Persona(g_NickName);
				return(FALSE);
			} else {
				Wstring const autologin = WOL_Auto_Login_Persona();
				if (autologin.toLower() == ((Wstring const &)g_NickName).toLower()) {
					WOL_Set_Auto_Login_Persona(EmptyString);
				}
				return(FALSE);
			}
		case 0x6EA:
			NewLogin(window);
			return(FALSE);
		case 0x6EB:
			{
				HWND combo = GetDlgItem(window, 0x628);
				int item = SendMessage(combo, CB_GETCURSEL, 0, 0);
				if (item != -1) {
					WideWstring wide;
					Get_Combo_Item_Wide_Text(combo, item, wide);
					Wstring name = Wstring_Narrow(wide);
					name.toLower();
					Wstring const autologin = WOL_Auto_Login_Persona();
					if (name == autologin.toLower()) {
						WOL_Set_Auto_Login_Persona(EmptyString);
					}
					Wstring const lastvalid = WOL_Last_Valid_Persona();
					if (name == lastvalid.toLower()) {
						WOL_Set_Last_Valid_Persona(EmptyString);
					}
					int slot = SendMessage(combo, CB_GETITEMDATA, item, 0);
					if (slot != -1) {
						g_pChat->SetNick(slot, EmptyString, EmptyString, 1);
						SendMessage(combo, CB_DELETESTRING, item, 0);
					}
					SendMessage(combo, CB_SETCURSEL, -1, 0);
				}
				WOL_Unknown_Stats_Text(window, true);
				InvalidateRect(combo, NULL, FALSE);
				EnableWindow(GetDlgItem(window, 0x6EB), FALSE);
				SendMessage(combo, CB_SETCURSEL, 0, 0);
				rc_ptr<PlayerProfile> profile = PlayerProfile::Load_Default();
				if (profile.Get()) {
					profile->PopulateDialog(window, &(Wstring const &)EmptyString, false);
					HWND check = GetDlgItem(window, 0x6FF);
					SendMessage(check, 0x49D, 0, 1);
					EnableWindow(check, FALSE);
					SendMessage(check, BM_SETCHECK, 0, 0);
					SendMessage(check, 0x49D, 0, 0);
					InvalidateRect(check, NULL, FALSE);
				}
			}
			return(FALSE);
		case 0x6EC:
			Open_Registration_Page();
			return(FALSE);
		}
		break;
	case 0x497:
		{
			HWND combo = GetDlgItem(window, 0x628);
			Clear_ComboBox(combo);
			SendMessage(combo, CB_LIMITTEXT, 9, 0);
			WideWstring text(StringTable::LoadString("GUI:Default", NULL, "C:\\RA2\\wonline.cpp", 16427)); // level-2 1.001: line literal
			int item = SendMessage(combo, 0x4C2, 0, (LPARAM)text.text());
			SendMessage(combo, CB_SETITEMDATA, item, -1);
			SendMessage(combo, CB_SETCURSEL, item, 0);
			char const * nick;
			char const * pass;
			for (int i = 1; i <= 0x20; i++) {
				nick = NULL;
				pass = NULL;
				if (g_pChat->GetNick(i, &nick, &pass) == 0) {
					if (nick != NULL) {
						if (strlen(nick) != 0) {
							WideWstring wide = Wstring_ToWide(nick);
							int added = SendMessage(combo, 0x4C2, 0, (LPARAM)wide.text());
							SendMessage(combo, CB_SETITEMDATA, added, i);
						}
					}
				}
			}
			Fill_Locale_Combo(GetDlgItem(window, 0x62A));
			Fill_Side_List(window, 0x6A1);
			Init_Player_Colors();
			Fill_Color_List(window, 0x6A2);
			Populate_Server_Choices(GetDlgItem(window, 0x629), true);
			rc_ptr<PlayerProfile> profile = PlayerProfile::Load(g_NickName);
			if (profile.Get()) {
				profile->PopulateDialog(window, &g_NickName, true);
			}
			int index = -1;
			int sel = SendMessage(combo, CB_GETCURSEL, 0, 0);
			if (sel != -1) {
				index = SendMessage(combo, CB_GETITEMDATA, sel, 0);
			}
			BOOL valid = index != -1;
			EnableWindow(GetDlgItem(window, 0x6EB), valid);
			EnableWindow(GetDlgItem(window, 0x687), valid);
			HWND check = GetDlgItem(window, 0x6FF);
			EnableWindow(check, valid);
			Wstring autologin = WOL_Auto_Login_Persona();
			SendMessage(GetDlgItem(window, 0x6FF), BM_SETCHECK, (autologin == g_NickName) ? BST_CHECKED : BST_UNCHECKED, 0);
		}
		break;
	case 0x4ED:
		ShowWindow(window, SW_HIDE);
		OwnerDraw::Set_Paint_Disabled(window, 1);
		return(FALSE);
	}
	return(FALSE);
}

// level-2 1.001 (wol_i, 2026-11-22): the login dialog of 1.001, adapted from gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later; FUN_00799EA0), checked against RA2 1.001 bytes
extern bool g_LoginControlsUpdating; // RA2: 1.001 0x00B1013C, set while the login dialog writes its own controls (their change notifications are ignored then)
LRESULT __fastcall Get_Combo_Item_Text(HWND window, WPARAM index, Wstring &text); // RA2: 1.001 0x005F8C10, defined in ownrdraw.cpp
bool __fastcall Focus_Next_Tab_Item(long lparam, bool flag); // RA2: 1.001 0x005D75D0, message 0x4DB (as in mainopt.cpp and netdlg2.cpp)

LRESULT CALLBACK Wonline_Account_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x007540A0 (1.001 0x007423C0), the login dialog (0x10F, 0x11D): the nickname, its stored password and the profile of a new persona
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	OwnerDraw::SimpleDialogControl * control = (OwnerDraw::SimpleDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_ERASEBKGND:
		return(TRUE);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(TRUE);
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x629:
			if (WS_Find_Dialog(0x11D) && g_PlayerProfile.Get()) {
				Wstring text;
				Get_Control_Text(GetDlgItem(window, 0x629), text);
				g_PlayerProfile.Get()->SetName(&text);
				return(FALSE);
			}
			break;
		case 0x628:
			{
				bool open = WS_Find_Dialog(0x11D) != NULL;
				switch (HIWORD(wparam)) {
				case CBN_EDITCHANGE:
				case EN_CHANGE:
					if (HIWORD(wparam) == EN_CHANGE && !open) {
						break;
					}
					if (HIWORD(wparam) == CBN_EDITCHANGE && open) {
						break;
					}
					if (g_LoginControlsUpdating) {
						break;
					}
					{
						Wstring text;
						Get_Control_Text((HWND)lparam, text);
						bool found = Recall_Stored_Login(text);
						bool enable = found || g_RememberLogin;
						if (!found) {
							g_NickName = text;
						}
						g_LoginControlsUpdating = true;
						HWND edit = GetDlgItem(window, 0x72C);
						SendMessage(edit, 0x4B4, 0, (LPARAM)g_LoginPassword.text());
						InvalidateRect(edit, NULL, FALSE);
						g_LoginControlsUpdating = false;
						bool ready = g_NickName.length() > 0 && g_LoginPassword.length() == 8;
						HWND check = GetDlgItem(window, 0x72D);
						ShowWindow(check, SW_HIDE);
						SendMessage(check, 0x49D, 0, 1);
						SendMessage(check, BM_SETCHECK, enable, 0);
						EnableWindow(check, FALSE);
						SendMessage(check, 0x49D, 0, 0);
						ShowWindow(check, SW_SHOW);
						InvalidateRect(check, NULL, FALSE);
						EnableWindow(GetDlgItem(window, 0x6EB), g_NickName.length() > 0);
						EnableWindow(GetDlgItem(window, 0x539), ready);
					}
					return(FALSE);
				case CBN_SELCHANGE:
					if (open) {
						break;
					}
					{
						g_LoginControlsUpdating = true;
						g_NickName.clear();
						g_LoginPassword.clear();
						g_PlaintextPassword = true;
						HWND edit = GetDlgItem(window, 0x72C);
						SendMessage(edit, 0x4B4, 0, (LPARAM)g_LoginPassword.text());
						bool enable = g_RememberLogin;
						int item = SendMessage((HWND)lparam, CB_GETCURSEL, 0, 0);
						if (item != -1) {
							int slot = SendMessage((HWND)lparam, CB_GETITEMDATA, item, 0);
							if (slot > 0 && slot <= 0x20) {
								Get_Combo_Item_Text((HWND)lparam, item, g_NickName);
								char const * nick;
								char const * pass;
								g_pChat->GetNick(slot, &nick, &pass);
								g_LoginPassword = pass;
								edit = GetDlgItem(window, 0x72C);
								SendMessage(edit, 0x4B4, 0, (LPARAM)g_LoginPassword.text());
								g_PlaintextPassword = false;
								enable = true;
							}
						}
						bool ready = g_NickName.length() > 0 && g_LoginPassword.length() == 8;
						HWND check = GetDlgItem(window, 0x72D);
						SendMessage(check, BM_SETCHECK, enable, 0);
						EnableWindow(check, FALSE);
						InvalidateRect(check, NULL, FALSE);
						EnableWindow(GetDlgItem(window, 0x6EB), g_NickName.length() > 0);
						EnableWindow(GetDlgItem(window, 0x539), ready);
						g_LoginControlsUpdating = false;
					}
					return(FALSE);
				}
			}
			break;
		case 0x539:
			control->Set_Window((unsigned int)window, (HWND)0x539);
			return(FALSE);
		case 0x62A:
			if (WS_Find_Dialog(0x11D) && g_PlayerProfile.Get()) {
				HWND combo = GetDlgItem(window, 0x62A);
				int item = SendMessage(combo, CB_GETCURSEL, 0, 0);
				int locale = 0;
				if (item != -1) {
					locale = SendMessage(combo, CB_GETITEMDATA, item, 0);
				}
				g_PlayerProfile.Get()->SetLocale(locale, 3);
				return(FALSE);
			}
			break;
		case 0x6A1:
			if (WS_Find_Dialog(0x11D) && g_PlayerProfile.Get()) {
				int country = -2;
				HWND combo = GetDlgItem(window, 0x6A1);
				int item = SendMessage(combo, CB_GETCURSEL, 0, 0);
				if (item != -1) {
					country = SendMessage(combo, CB_GETITEMDATA, item, 0);
				}
				g_PlayerProfile.Get()->SetCountry(country);
				return(FALSE);
			}
			break;
		case 0x686:
			control->Set_Window((unsigned int)window, (HWND)2);
			return(FALSE);
		case 0x6A2:
			if (WS_Find_Dialog(0x11D) && g_PlayerProfile.Get()) {
				int color = -2;
				HWND combo = GetDlgItem(window, 0x6A2);
				int item = SendMessage(combo, CB_GETCURSEL, 0, 0);
				if (item != -1) {
					color = SendMessage(combo, CB_GETITEMDATA, item, 0);
				}
				g_PlayerProfile.Get()->SetColor(color);
				return(FALSE);
			}
			break;
		case 0x72C:
			if (HIWORD(wparam) == EN_CHANGE && !g_LoginControlsUpdating) {
				g_PlaintextPassword = true;
				Get_Control_Text((HWND)lparam, g_LoginPassword);
				Wstring text;
				Get_Control_Text(GetDlgItem(window, 0x628), text);
				bool ready = text.length() > 0 && g_LoginPassword.length() == 8;
				HWND check = GetDlgItem(window, 0x72D);
				SendMessage(check, 0x49D, 0, 1);
				EnableWindow(check, ready);
				InvalidateRect(check, NULL, FALSE);
				SendMessage(check, 0x49D, 0, 0);
				EnableWindow(GetDlgItem(window, 0x6EB), FALSE);
				EnableWindow(GetDlgItem(window, 0x539), ready);
				return(FALSE);
			}
			break;
		case 0x72D:
			g_RememberLogin = SendMessage((HWND)lparam, BM_GETCHECK, 0, 0) == BST_CHECKED;
			return(FALSE);
		case 0x6EB:
			{
				g_LoginControlsUpdating = true;
				HWND combo = GetDlgItem(window, 0x628);
				int item = SendMessage(combo, 0x4B9, -1, (LPARAM)g_NickName.text());
				if (item != -1) {
					Wstring name;
					Get_Combo_Item_Text(combo, item, name);
					name.toLower();
					Wstring const autologin = WOL_Auto_Login_Persona();
					if (name == autologin.toLower()) {
						WOL_Set_Auto_Login_Persona(EmptyString);
					}
					Wstring const lastvalid = WOL_Last_Valid_Persona();
					if (name == lastvalid.toLower()) {
						WOL_Set_Last_Valid_Persona(EmptyString);
					}
					int slot = SendMessage(combo, CB_GETITEMDATA, item, 0);
					SendMessage(combo, CB_DELETESTRING, item, 0);
					g_pChat->SetNick(slot, EmptyString, EmptyString, 1);
				}
				SendMessage(combo, 0x4B4, 0, (LPARAM)EmptyString);
				InvalidateRect(combo, NULL, FALSE);
				HWND edit = GetDlgItem(window, 0x72C);
				SendMessage(edit, 0x4B4, 0, (LPARAM)EmptyString);
				g_NickName.clear();
				g_LoginPassword.clear();
				g_PlaintextPassword = true;
				HWND check = GetDlgItem(window, 0x72D);
				EnableWindow(check, FALSE);
				InvalidateRect(check, NULL, FALSE);
				EnableWindow(GetDlgItem(window, 0x6EB), FALSE);
				EnableWindow(GetDlgItem(window, 0x539), FALSE);
				g_LoginControlsUpdating = false;
			}
			return(FALSE);
		case 0x6EA:
			NewLogin(window);
			return(FALSE);
		case 0x6EC:
			Open_Registration_Page();
			return(FALSE);
		}
		break;
	case 0x497:
		{
			g_LoginControlsUpdating = true;
			HWND combo = GetDlgItem(window, 0x628);
			HWND edit = GetDlgItem(window, 0x72C);
			SendMessage(combo, 0x4D1, 1, 0);
			SendMessage(edit, 0x4D1, 1, 0);
			SendMessage(combo, EM_LIMITTEXT, 9, 0);
			SendMessage(edit, EM_LIMITTEXT, 8, 0);
			Clear_ComboBox(combo);
			SendMessage(combo, CB_LIMITTEXT, 9, 0);
			for (int i = 1; i < 0x20; i++) {
				char const * nick;
				char const * pass;
				if (g_pChat->GetNick(i, &nick, &pass) == 0 && nick != NULL && strlen(nick) != 0) {
					int added = SendMessage(combo, 0x4BC, 0, (LPARAM)nick);
					SendMessage(combo, CB_SETITEMDATA, added, i);
				}
			}
			Wstring saved(g_NickName);
			bool found = Recall_Stored_Login(g_NickName);
			if (!found) {
				g_NickName = saved;
			}
			SendMessage(combo, 0x4B4, 0, (LPARAM)g_NickName.text());
			if (g_NickName.length() > 0) {
				SendMessage(edit, 0x4B4, 0, (LPARAM)g_LoginPassword.text());
				g_PlaintextPassword = false;
			}
			bool ready = g_NickName.length() > 0 && g_LoginPassword.length() == 8;
			HWND check = GetDlgItem(window, 0x72D);
			SendMessage(check, 0x49D, 0, 1);
			SendMessage(check, BM_SETCHECK, found, 0);
			EnableWindow(check, FALSE);
			InvalidateRect(check, NULL, FALSE);
			SendMessage(check, 0x49D, 0, 0);
			EnableWindow(GetDlgItem(window, 0x6EB), g_NickName.length() > 0);
			EnableWindow(GetDlgItem(window, 0x539), ready);
			WOLOptionsClass options;
			options.Load();
			if (!options.Is_Bit1_Clear()) {
				Fill_Locale_Combo(GetDlgItem(window, 0x62A));
				Fill_Side_List(window, 0x6A1);
				HWND country = GetDlgItem(window, 0x6A1);
				int count = SendMessage(country, CB_GETCOUNT, 0, 0);
				for (int j = 0; j < count; j++) {
					int data = SendMessage(country, CB_GETITEMDATA, j, 0);
					if (data == g_PlayerProfile.Get()->Country) {
						SendMessage(country, CB_SETCURSEL, j, 0);
						break;
					}
				}
				Init_Player_Colors();
				Fill_Color_List(window, 0x6A2);
				HWND color = GetDlgItem(window, 0x6A2);
				int colors = SendMessage(color, CB_GETCOUNT, 0, 0);
				for (int k = 0; k < colors; k++) {
					int data = SendMessage(color, CB_GETITEMDATA, k, 0);
					if (data == g_PlayerProfile.Get()->Color) {
						SendMessage(color, CB_SETCURSEL, k, 0);
						break;
					}
				}
				Populate_Server_Choices(GetDlgItem(window, 0x629), true);
			}
			g_LoginControlsUpdating = false;
		}
		return(FALSE);
	case 0x4ED:
		ShowWindow(window, SW_HIDE);
		OwnerDraw::Set_Paint_Disabled(window, 1);
		return(FALSE);
	case 0x4DB:
		{
			bool previous = wparam != 0;
			HWND child = (HWND)lparam;
			HWND parent = GetParent(child);
			while (parent && child && parent != window) {
				child = parent;
				parent = GetParent(child);
			}
			if (child) {
				Focus_Next_Tab_Item((long)child, previous);
				return(FALSE);
			}
		}
		break;
	case 0x4DA:
		{
			Get_Control_Text(GetDlgItem(window, 0x72C), g_LoginPassword);
			Wstring text;
			Get_Control_Text(GetDlgItem(window, 0x628), text);
			if (text.length() > 0 && g_LoginPassword.length() == 8) {
				PostMessage(GetDlgItem(window, 0x539), BM_CLICK, 0, 0);
			}
		}
		break;
	}
	return(FALSE);
}

// level-2 1.001 (wol_i, 2026-11-22): adapted from gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later; FUN_0079C040), checked against RA2 1.001 bytes
extern wchar_t NullWString[]; // RA2: 1.001 0x0082208C, the shared empty wide text

static inline void Set_Label_Text(HWND window, wchar_t const * text) // RA2: a helper of the profile labels (as in the YR decompilation)
{
	SendMessage(window, 0x4B2, 0, (LPARAM)text);
}

void Update_Buddy_Profile_Labels(HWND dialog) // RA2: 1.001 0x00744480, the labels of the buddy dialog: the name of the selected buddy and its ladder entry (or the unknown text)
{
	HWND name_label = GetDlgItem(dialog, 0x6EF);
	HWND rung_label = GetDlgItem(dialog, 0x6F4);
	HWND points_label = GetDlgItem(dialog, 0x6F5);
	HWND wins_label = GetDlgItem(dialog, 0x6F0);
	HWND losses_label = GetDlgItem(dialog, 0x6F1);
	HWND disconnects_label = GetDlgItem(dialog, 0x701);
	if (g_SelectedBuddy.length() == 0) {
		SendMessage(name_label, 0x4B2, 0, (LPARAM)NullWString);
		SendMessage(rung_label, 0x4B2, 0, (LPARAM)NullWString);
		SendMessage(points_label, 0x4B2, 0, (LPARAM)NullWString);
		SendMessage(wins_label, 0x4B2, 0, (LPARAM)NullWString);
		SendMessage(losses_label, 0x4B2, 0, (LPARAM)NullWString);
		SendMessage(disconnects_label, 0x4B2, 0, (LPARAM)NullWString);
		return;
	}
	WideWstring format(StringTable::LoadString("GUI:UserProfileLabel", NULL, "C:\\RA2\\wonline.cpp", 17970)); // level-2 1.001: line literal
	wchar_t * text = new wchar_t[format.length() + g_SelectedBuddy.length() + 1];
	swprintf(text, format.get(), g_SelectedBuddy.get());
	HWND name_item = GetDlgItem(dialog, 0x6EF);
	SendMessage(name_item, 0x4B2, 0, (LPARAM)text);
	delete text;
	Ladder ladder;
	memset(&ladder, 0, sizeof(ladder));
	Wstring key = ((Wstring const &)g_SelectedBuddy).toLower();
	if (g_GeneralLadderDict.getValue(key, ladder)) {
		Set_Label_Text(rung_label, WideWstring_FromInt(ladder.rung).text());
		Set_Label_Text(points_label, WideWstring_FromInt(ladder.points).text());
		Set_Label_Text(wins_label, WideWstring_FromInt(ladder.wins).text());
		Set_Label_Text(losses_label, WideWstring_FromInt(ladder.losses).text());
		Set_Label_Text(disconnects_label, WideWstring_FromInt(ladder.disconnects).text());
	} else {
		WideWstring unknown(StringTable::LoadString("GUI:UnknownStats", NULL, "C:\\RA2\\wonline.cpp", 17987)); // level-2 1.001: line literal
		Set_Label_Text(rung_label, unknown.text());
		Set_Label_Text(points_label, unknown.text());
		Set_Label_Text(wins_label, unknown.text());
		Set_Label_Text(losses_label, unknown.text());
		Set_Label_Text(disconnects_label, unknown.text());
	}
}


// ---- wol_h (level-2 1.001): functions of 0x0073F1C0 .. 0x00741060 ----

#include "sendfile.h" // level-2 1.001: the scenario transfer of a game channel

static inline bool Is_Owner_Name(Wstring const & name) // level-2 1.001: the owner of the game channel has this name
{
	User * owner = Find_Owner_User();
	return(owner && !stricmp((char const *)owner->name, name.text()));
}

static inline bool Is_Local_Host(void) // level-2 1.001: the local user owns the game channel
{
	return(Is_Owner_Name(g_NickName));
}

void Negotiate_Scenario_Transfer(void) // level-2 1.001: 0x0073F1C0 (YR 0x00795CD0, provisional name), before the game starts: the host sends NET_GO, collects who wants the scenario (NET_REQ_SCENARIO) or is ready (NET_READY_TO_GO) and sends the scenario; a guest looks for the scenario locally, says it is ready, else fetches it from the host
{
	GlobalPacketType packet;
	int responses[MAX_PLAYERS];

	Ipx.Set_Timing(50, (unsigned long)-1, 5000, true);

	if (Is_Local_Host()) {
		memset(&packet, 0, sizeof(packet));
		packet.Command = NET_GO;
		for (int i = 1; i < Session.Players.Count(); i++) {
			do {
				Call_Back();
			} while (!Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Players[i]->Address));
		}

		memset(responses, 0, sizeof(responses));
		int num_responses = 0;
		bool send_scenario = false;
		DebugString("About to wait for 'GO' response.\n");

		CDTimerClass<SystemTimerClass> timer;
		timer = CDTimerClass<SystemTimerClass>(1800);

		do {
			Call_Back();
			if (Ipx.Get_Global_Message(&Session.GPacket, &Session.GPacketlen, &Session.GAddress, &Session.GProductID) && Session.GProductID == 0xAA03) {
				DebugString("Packet is C&C2 packet\n");
				for (int i = 1; i < Session.Players.Count(); i++) {
					if (Session.Players[i]->Address == Session.GAddress && !responses[i]) {
						if (Session.GPacket.Command == NET_REQ_SCENARIO) {
							DebugString("Packet type is NET_REQ_SCENARIO\n");
							responses[i] = Session.GPacket.Command;
							send_scenario = true;
							num_responses++;
						}
						if (Session.GPacket.Command == NET_READY_TO_GO) {
							DebugString("Packet type is NET_READY_TO_GO\n");
							responses[i] = Session.GPacket.Command;
							num_responses++;
						}
					}
				}
			}
		} while (num_responses < Session.Players.Count() - 1 && timer);

		if (send_scenario) {
			memset(Session.ScenarioRequests, 0, sizeof(Session.ScenarioRequests));
			Session.RequestCount = 0;
			for (int i = 1; i < Session.Players.Count(); i++) {
				if (responses[i] == NET_REQ_SCENARIO) {
					Session.ScenarioRequests[Session.RequestCount++] = (char)i;
				}
			}
			Send_Remote_File(Scen->ScenarioName, GAME_IPX, false, true); // level-2 1.001: the transfer runs as in an IPX game (3), as netdlg2.cpp does
		}
	} else {
		if (Find_Local_Scenario(Session.ScenarioFileName, Session.ScenarioFileLength, Session.ScenarioDigest, Session.ScenarioIsOfficial, true)) {
			memset(&packet, 0, sizeof(packet));
			packet.Command = NET_READY_TO_GO;
			Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.HostAddress);
			DebugString("Sent NET_READY_TO_GO\n");

			CDTimerClass<SystemTimerClass> timer;
			timer = CDTimerClass<SystemTimerClass>(1800);
			while (Ipx.Global_Num_Send() > 0 && timer) {
				Call_Back();
			}
		} else {
			if (Session.ScenarioIsOfficial && !Session.Is_Random_Map()) { // level-2 1.001: the test is made and has no effect, the scenario is fetched in any case
			}
			Get_File_From_Host(Session.ScenarioFileName, GAME_IPX, true); // level-2 1.001: as above
		}
		strcpy(Scen->ScenarioName, Session.ScenarioFileName);
	}

	Ipx.Set_Timing(Ipx.Global_Response_Time() + 2, (unsigned long)-1, MAX(2 * TIMER_SECOND, Ipx.Global_Response_Time() * 8), true);
}

BOOL CALLBACK Locale_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x00751190 (1.001 0x0073F8E0, YR Select_WDT_Location_Proc 0x00796B90), the country dialog (0xFE): a list of the locales of the chat service, OK answers the one picked (0 for none), Cancel answers 0
{
	if (message == WM_INITDIALOG && lparam) {
		Set_Dialog_Init_Param(window, lparam); // level-2 1.001: the do/while(0) form of gibbo101's YR Select_WDT_Location_Proc (probably a macro of the original): with it the count of case 0x497 lies in the slot of the window argument, as in the executable
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	int count;
	SimpleWonlineDialogControl * control = (SimpleWonlineDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);
	case WM_ERASEBKGND:
		return(TRUE);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(FALSE);
	case WM_NCDESTROY:
		On_WM_NCDESTROY(window);
		return(FALSE);
	case 0x497:
		{
			SendDlgItemMessage(window, 0x3F0, LB_RESETCONTENT, 0, 0);
			count = 0;
			g_pChat->GetLocaleCount(&count);
			if (count > 0) {
				HWND list = GetDlgItem(window, 0x3F0);
				for (int i = count - 1; i >= 0; i--) {
					WideWstring name(Get_Locale_Name(i));
					DebugString("Adding country: %hs\n", name.get());
					int item;
					if (i < 2) {
						item = SendMessage(list, 0x4CC, 0, (LPARAM)name.get());
					} else {
						item = SendMessage(list, 0x4CD, 0, (LPARAM)name.get());
					}
					SendMessage(list, LB_SETITEMDATA, item, i);
				}
				SendMessage(list, LB_SETCURSEL, -1, 0);
			}
		}
		return(FALSE);
	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case IDOK:
			{
				HWND list = GetDlgItem(window, 0x3F0);
				int locale = 0;
				int index = SendMessage(list, LB_GETCURSEL, 0, 0);
				if (index != -1) {
					locale = SendMessage(list, LB_GETITEMDATA, index, 0);
				}
				control->Set_Window((unsigned int)window, (HWND)locale);
			}
			return(FALSE);
		case IDCANCEL:
			control->Set_Window((unsigned int)window, (HWND)0);
			return(FALSE);
		case 0x3F0:
			if (HIWORD(wparam) == LBN_SELCHANGE) {
				EnableWindow(GetDlgItem(window, LOWORD(wparam) - 0x3EF), SendMessage((HWND)lparam, LB_GETCURSEL, 0, 0) != -1);
			}
			return(FALSE);
		}
		break;
	}
	return(FALSE);
}

void Wonline_Stub_73F870(void) // level-2 1.001: 0x0073F870 (YR 0x00796B20), an empty function between Poke_The_Host and Ask_Locale; no caller, real name unknown
{
}

#include "wspudp.h" // level-2 1.001: the ports of the test game
void Clear_Vector(DynamicVectorClass <NodeNameType *> *vector); // level-2 1.001: 0x005A4070, as in mplayer.h

void Start_Test_Game(void) // level-2 1.001: 0x0073FE10 (YR 0x007970D0), a developer's test: sets up an Internet game with the three test players (their order depends on the computer name, "STEVE-T3" also precalculates the frame rate) and the fixed options, then starts it; no caller
{
	char computer[0x3F8];
	unsigned long size;
	bool precalc;

	WestwoodOnline_GameID = 0;
	WestwoodOnline_GameSKU_TS = g_GameSKU;
	WestwoodOnline_Tournament = 0;
	strcpy(WestwoodOnline_LoginName, g_NickName.get());
	Clear_Vector(&Session.Players);
	size = 0x3F7;
	GetComputerName(computer, &size);
	precalc = false;
	if (!stricmp(computer, "STEVE-T3")) {
		Add_Test_Player_Potato_Too();
		Add_Test_Player_Ol_Cruddy();
		Add_Test_Player_Potato();
		precalc = true;
	} else if (!stricmp(computer, "STEVE-T2")) {
		Add_Test_Player_Potato();
		Add_Test_Player_Ol_Cruddy();
		Add_Test_Player_Potato_Too();
	} else {
		Add_Test_Player_Ol_Cruddy();
		Add_Test_Player_Potato();
		Add_Test_Player_Potato_Too();
	}
	PacketTransport->Clear_Broadcast_Addresses();
	char address[32] = {"xxx.xxx.xxx.xxx"};
	NetNumType network;
	NetNodeType node;
	for (int p = 1; p < Session.Players.Count(); p++) {
		Session.Players[p]->Address.Get_Address(network, node);
		PacketTransport->Set_Broadcast_Address(address);
	}
	WolOptionsLocked = 2;
	DebugString("Starting a %d player game.\n", Session.NumPlayers);
	Char_To_Wide(Session.MasterPlayerName, "PotatoToo", -1);
	Session.MasterPlayerID = -1;
	Session.House = 0;
	Seed = 1;
	BuildLevel = 10;
	Session.Options.UnitCount = 10;
	Session.Options.Credits = 10000;
	Session.Options.FogOfWar = false;
	Session.Options.BridgeDestruction = true;
	Session.Options.Goodies = true;
	Session.Options.MCVRedeploy = true;
	Session.Options.AlliesAllowed = true;
	Session.Options.HarvTruce = false;
	Session.Options.Bases = true;
	Session.Options.CTF = false;
	Session.Options.AIPlayers = 0;
	Session.Options.AIDifficulty = (DiffType)0;
	Session.Options.ShortGame = true;
	Session.Options.SWAllowed = true;
	Session.Options.BuildOffAlly = false;
	Session.Options.CrapEngineers = true;
	Session.Options.ScenarioIndex = 1;
	Session.Options.GameSpeed = 0;
	Set_Scenario_Info_From_Index(Session.Options.ScenarioIndex);
	Session.Options.GameSpeed = 2;
	Options.GameSpeed = 2;
	Scen->Scenario = Session.Options.ScenarioIndex;
	Session.FrameSendRate = 5;
	switch (Session.Options.GameSpeed) {
	case 0:
		Session.MaxAhead = 40;
		Session.PrecalcDesiredFrameRate = 60;
		Session.FrameSendRate = 10;
		break;
	case 1:
		Session.MaxAhead = 40;
		Session.PrecalcDesiredFrameRate = 45;
		Session.FrameSendRate = 10;
		break;
	case 2:
		Session.MaxAhead = 30;
		Session.PrecalcDesiredFrameRate = 30;
		break;
	case 3:
		Session.MaxAhead = 20;
		Session.PrecalcDesiredFrameRate = 20;
		break;
	case 4:
		Session.MaxAhead = 20;
		Session.PrecalcDesiredFrameRate = 15;
		break;
	case 5:
		Session.MaxAhead = 20;
		Session.PrecalcDesiredFrameRate = 12;
		break;
	default:
		Session.MaxAhead = 10;
		Session.PrecalcDesiredFrameRate = 10;
		break;
	}
	Session.PrecalcMaxAhead = 0;
	if (!precalc) {
		Session.PrecalcDesiredFrameRate = 0;
	}
	int worst = 0;
	for (int q = 0; q < Session.Players.Count(); q++) {
		if (PlayerPings[q] > worst) {
			worst = PlayerPings[q];
		}
	}
	Session.LatencyFudge = 1;
	if (worst != 0 && worst != 1000) {
		DebugString("Max ping is %d ms\n", worst);
		if (worst > 1000) {
			Session.LatencyFudge = 2;
		} else if (worst < 600) {
			Session.LatencyFudge = 1;
		}
		int ticks = 60 * worst / 1000;
		ticks += 120 * ticks / 100;
		Ipx.Set_Timing(ticks, (unsigned long)-1, ticks * 8, true);
		if (precalc) {
			Ipx.Set_Lobby_Timing(5, (unsigned long)-1, 120);
			unsigned ahead;
			switch (Session.LatencyFudge) {
			case 0:
			case 1:
				ahead = Session.MaxAhead;
				break;
			case 2:
				ahead = (Session.MaxAhead / 2) + Session.MaxAhead;
				break;
			case 3:
				ahead = Session.MaxAhead * 2;
				break;
			default:
				ahead = Session.PrecalcMaxAhead;
				break;
			}
			ahead = 10 * (ahead / 10);
			Session.PrecalcMaxAhead = ahead;
		}
	} else {
		Session.PrecalcDesiredFrameRate = 0;
		DebugString("Ping times not available\n");
	}
	DebugString("PrecalcMaxAhead is %d\n", Session.PrecalcMaxAhead);
	DebugString("PrecalcDesiredFrameRate is %d\n", Session.PrecalcDesiredFrameRate);
	DebugString("LatencyFudge is %d\n", Session.LatencyFudge);
	DebugString("FrameSendRate is %d\n", Session.FrameSendRate);
	Session.MaxMaxAhead = Session.MaxAhead;
	memset(Session.ConnectionStats, 0, sizeof(Session.ConnectionStats));
	UDPInterfaceClass::UDPListenPort = 1234;
	Options.GameSpeed = Session.Options.GameSpeed;
	AlternateSendPort = 1235;
	AlternateListenPort = 1236;
	LoopbackPort = 1237;
	Frame = 0;
	WestwoodOnline_Clan1_Players[0] = 0;
	WestwoodOnline_Clan2_Players[0] = 0;
	PregameSetup();
}

int __fastcall Request_And_Wait_Server_List(unsigned int flags) // RA2: 0x00751C30 (1.001 0x00740370), asks for the list of chat servers and waits for it (0 done, 1 failed, 2 quit)
{
	bool saved = g_IgnoreNetStatus;
	int version = g_LanguageCode | flags;
	g_IgnoreNetStatus = true;
	g_Servers.setEmpty();
	g_CurrentServerIndex = 0;
	g_TargetServerIndex = 0;
	g_pChat->RequestServerList(version, 0x10001, "TibSun", "TibPass99", 0x23);
	g_pChat->SetProductSKU(g_GameSKU);
	bool done = false;
	bool servers = false;
	int result;
	int elapsed = 0;
	for (;;) {
		DWORD index;
		while ((index = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 50)) == WAIT_TIMEOUT) {
			elapsed += 50;
			if (elapsed > 30000) {
				ODMessageBox(StringTable::LoadString("TXT_CANT_CONNECT", NULL, "C:\\RA2\\wonline.cpp", 15783), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
				SetEvent(g_WaitEventHandles[EV_ABORT]);
				index = EV_ABORT;
				break;
			}
			WOL_Wait_Callback();
		}
		ResetEvent(g_WaitEventHandles[index]);
		if (index == EV_ABORT) {
			result = 1;
			break;
		}
		if (index == EV_QUITGAME) {
			result = 2;
			break;
		}
		if (index == EV_GOT_SERVERS) {
			done = true;
			if (servers) {
				result = 0;
				break;
			}
		} else if (index == EV_NETIGNORE && g_LastIgnoredNetStatus == 0x4012F) {
			servers = true;
			if (done) {
				result = 0;
				break;
			}
		}
	}
	HWND dialog = WS_Find_Dialog(0xC4);
	if (dialog) {
		g_ActiveWaitFlags = 0;
		WS_Destroy_Dialog(dialog, 0);
	}
	HWND top = WS_Top_Window();
	HWND control = GetDlgItem(top, 0x540);
	if (control) {
		SetFocus(control);
	}
	g_IgnoreNetStatus = saved;
	return(result);
}

static inline void Close_WDT_Wait_Window(void) // level-2 1.001: closes the wait dialog (0xC4) whatever it waits for and gives the focus back to the chat line of the top dialog
{
	HWND dialog = WS_Find_Dialog(0xC4);
	if (dialog) {
		g_ActiveWaitFlags = 0;
		WS_Destroy_Dialog(dialog, 0);
	}
	HWND top = WS_Top_Window();
	HWND control = GetDlgItem(top, 0x540);
	if (control) {
		SetFocus(control);
	}
}

bool Func_740520(void) // level-2 1.001: 0x00740520 (YR Request_WDT_Cycle 0x00797800), asks the WDT server for the current and the previous cycle of the tour and waits for both; false on any error
{
	if (!g_WDTServer.conndata) {
		ODMessageBox(StringTable::LoadString("TXT_WDT_NET_ERR", NULL, "C:\\RA2\\wonline.cpp", 15846), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
		return(false);
	}
	for (int i = 0; i < EV_COUNT; i++) {
		ResetEvent(g_WaitEventHandles[i]);
	}
	HRESULT result = g_pNetUtil->RequestWDTState(g_WDTHost, g_WDTPort, 3);
	DebugString("WDTHost is %s, port is %d\n", g_WDTHost, g_WDTPort);
	DebugString("Requesting current WDT cycle\n");
	if (result) {
		ODMessageBox(StringTable::LoadString("TXT_WDT_NET_ERR", NULL, "C:\\RA2\\wonline.cpp", 15862), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
		return(false);
	}
	{
		WideWstring text(StringTable::LoadString("TXT_FETCHING_WDT", NULL, "C:\\RA2\\wonline.cpp", 15866)); // level-2 1.001: line literal
		Show_Wait_Window(16, text, false);
	}
	DWORD index;
	for (;;) {
		int timeout = 30000;
		index = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100);
		while (index == WAIT_TIMEOUT) {
			timeout -= 100;
			if (timeout <= 0) {
				goto failed;
			}
			WOL_Wait_Callback();
			index = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100);
		}
		ResetEvent(g_WaitEventHandles[index]);
		if (index == EV_ABORT) {
			Close_WDT_Wait_Window();
			return(false);
		}
		if (index == EV_ERROR) {
			ODMessageBox(StringTable::LoadString("TXT_WDT_NET_ERR", NULL, "C:\\RA2\\wonline.cpp", 15885), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
			Close_WDT_Wait_Window();
			return(false);
		}
		if (index == EV_COUNT) {
failed:
			ODMessageBox(StringTable::LoadString("TXT_WDT_NET_ERR", NULL, "C:\\RA2\\wonline.cpp", 15891), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
			Close_WDT_Wait_Window();
			return(false);
		}
		if (index == EV_11) {
			break;
		}
	}
	result = g_pNetUtil->RequestWDTState(g_WDTHost, g_WDTPort, 5);
	DebugString("Requesting Previous Cycle\n");
	if (result) {
		Close_WDT_Wait_Window();
		return(false);
	}
	for (;;) {
		index = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100);
		while (index == WAIT_TIMEOUT) {
			WOL_Wait_Callback();
			index = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100);
		}
		ResetEvent(g_WaitEventHandles[index]);
		if (index == EV_ABORT) {
			Close_WDT_Wait_Window();
			return(false);
		}
		if (index == EV_ERROR) {
			ODMessageBox(StringTable::LoadString("TXT_WDT_NET_ERR", NULL, "C:\\RA2\\wonline.cpp", 15918), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
			Close_WDT_Wait_Window();
			return(false);
		}
		if (index == EV_11) {
			break;
		}
	}
	Close_WDT_Wait_Window();
	return(true);
}

// level-2 1.001: the sounds of the World Domination Tour (TibSun's lists, Nod and GDI, kept in RA2)
extern char g_WDTSoundsInited; // level-2 1.001: 0x00B100F0

void Init_WDT_Sounds(void) // level-2 1.001: 0x00740940 (YR 0x00797C20), fills the lists of the tour's voice files once
{
	if (g_WDTSoundsInited) {
		return;
	}
	static Wstring _sound_names[16];

	_sound_names[0].set("01-W024.V01");
	_sound_names[1].set("01-W026.V01");
	_sound_names[2].set("01-W028.V01");
	_sound_names[3].set("01-W018.V01");
	_sound_names[4].set("01-W020.V01");
	_sound_names[5].set("01-W022.V01");
	_sound_names[6].set("00-W022.V00");
	_sound_names[7].set("00-W024.V00");
	_sound_names[8].set("00-W026.V00");
	_sound_names[9].set("00-W017.V00");
	_sound_names[10].set("00-W018.V00");
	_sound_names[11].set("00-W020.V00");
	_sound_names[12].set("01-W032.V01");
	_sound_names[13].set("01-W030.V01");
	_sound_names[14].set("00-W031.V00");
	_sound_names[15].set("00-W029.V00");

	g_WDT_NodWinEmphasisSounds.clear();
	g_WDT_GDIWinEmphasisSounds.clear();
	g_WDT_NodLoseEmphasisSounds.clear();
	g_WDT_GDILoseEmphasisSounds.clear();
	g_WDT_NodTerritoryWinSounds.clear();
	g_WDT_GDITerritoryWinSounds.clear();
	g_WDT_NodTerritoryLoseSounds.clear();
	g_WDT_GDITerritoryLoseSounds.clear();

	g_WDT_NodWinEmphasisSounds.addHead(_sound_names[0]);
	g_WDT_NodWinEmphasisSounds.addHead(_sound_names[1]);
	g_WDT_NodWinEmphasisSounds.addHead(_sound_names[2]);
	g_WDT_NodLoseEmphasisSounds.addHead(_sound_names[3]);
	g_WDT_NodLoseEmphasisSounds.addHead(_sound_names[4]);
	g_WDT_NodLoseEmphasisSounds.addHead(_sound_names[5]);
	g_WDT_GDIWinEmphasisSounds.addHead(_sound_names[6]);
	g_WDT_GDIWinEmphasisSounds.addHead(_sound_names[7]);
	g_WDT_GDIWinEmphasisSounds.addHead(_sound_names[8]);
	g_WDT_GDILoseEmphasisSounds.addHead(_sound_names[9]);
	g_WDT_GDILoseEmphasisSounds.addHead(_sound_names[10]);
	g_WDT_GDILoseEmphasisSounds.addHead(_sound_names[11]);
	g_WDT_NodTerritoryWinSounds.addHead(_sound_names[12]);
	g_WDT_NodTerritoryLoseSounds.addHead(_sound_names[13]);
	g_WDT_GDITerritoryWinSounds.addHead(_sound_names[14]);
	g_WDT_GDITerritoryLoseSounds.addHead(_sound_names[15]);

	g_WDTSoundsInited = 1;
}

void Deinit_WDT_Sounds(void) // level-2 1.001: 0x00740E60 (YR 0x00798140), empties the lists again
{
	g_WDT_NodWinEmphasisSounds.clear();
	g_WDT_GDIWinEmphasisSounds.clear();
	g_WDT_NodLoseEmphasisSounds.clear();
	g_WDT_GDILoseEmphasisSounds.clear();
	g_WDT_NodTerritoryWinSounds.clear();
	g_WDT_GDITerritoryWinSounds.clear();
	g_WDT_NodTerritoryLoseSounds.clear();
	g_WDT_GDITerritoryLoseSounds.clear();
	g_WDTSoundsInited = 0;
}

void Play_WDT_Sound(ArrayList<Wstring> list) // level-2 1.001: 0x00740FC0 (YR 0x007982A0), plays nothing in the release
{
}

int __fastcall Wait_For_Wait_Event(int seconds, int count) // level-2 1.001: 0x00740FF0 (YR 0x007982D0), waits for one of the first count events, EV_COUNT after the seconds
{
	int remaining = seconds * 1000;
	DWORD index;
	while ((index = WaitForMultipleObjects(count, g_WaitEventHandles, FALSE, 100)) == WAIT_TIMEOUT) {
		remaining -= 100;
		if (remaining <= 0) {
			return(EV_COUNT);
		}
		WOL_Wait_Callback();
	}
	ResetEvent(g_WaitEventHandles[index]);
	return(index);
}


// level-2 1.001: INFERRED helper shared by the three server-switch waits.
static inline DWORD Wait_For_Server_Switch_Event(void)
{
	DWORD event;
	while ((event = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100)) == WAIT_TIMEOUT) {
		WOL_Wait_Callback();
	}
	ResetEvent(g_WaitEventHandles[event]);
	return event;
}

// level-2 1.001: INFERRED helper for the two requests made when switching servers.
static inline bool Request_Switch_Channel_List(unsigned int type, unsigned char autoping)
{
	if (g_pChat->RequestChannelList(type, autoping) != S_OK) {
		return false;
	}
	g_ChanListQueue.addTail(type);
	return true;
}

/// <summary>
/// Moves the login to another server of the server list: logs out, waits for the logout,
/// logs in to the first server (type 0, the chat server) or to the server the player picked
/// (type 0x21, a game server), prints the message of the day into the chat and requests the
/// channel lists of the new server. Nothing in the executable calls it.
/// </summary>
/// <returns>True when the server was changed (or the list has no other server), false when
/// one of the waits was aborted (the error text is shown).</returns>
bool Switch_Server(int type) // level-2 1.001: 0x00731290, provisional name for the server-switch routine
{
	Server * server = NULL;
	g_LastErrorMessage[0] = 0;
	int server_count = g_Servers.length();
	if (server_count > 1) {
		HWND dialog = WS_Find_Dialog(0x113);
		if (type == 0) {
			if (dialog) EnableWindow(GetDlgItem(dialog, 0x55B), FALSE);
		} else {
			if (dialog) EnableWindow(GetDlgItem(dialog, 0x55B), TRUE);
		}

		g_IgnoreNetStatus = true;
		g_LastIgnoredNetStatus = 0;
		g_pChat->RequestLogout();
		{
			WideWstring connecting(StringTable::LoadString("TXT_CONNECTING_SERVER", NULL, "C:\\RA2\\wonline.cpp", 1123)); // level-2 1.001: line literal
			Show_Wait_Window(0x10, connecting, false);
		}
		for (int i = 0; i < EV_COUNT; i++) {
			ResetEvent(g_WaitEventHandles[i]);
		}

		DWORD event;
		for (;;) {
			event = Wait_For_Server_Switch_Event();
			if (event == EV_NETIGNORE) {
				if (g_LastIgnoredNetStatus == 0x4012F) break;
			} else if (event == EV_ABORT) {
				break;
			}
		}
		if (event != EV_ABORT) {
			g_IgnoreNetStatus = false;

			if (type == 0) {
				g_Servers.getPointer(&server, 0);
			} else if (type == 0x21) {
				g_Servers.getPointer(&server, g_TargetServerIndex);
			}
			char const * nickname = g_NickName.get();
			strcpy((char *)server->login, nickname);
			char const * password = g_LoginPassword.get();
			strcpy((char *)server->password, password);
			g_pChat->RequestConnection(server, 20, ((int &)g_PlaintextPassword) & 0xFF);

			event = Wait_For_Server_Switch_Event();
			if (event != EV_ABORT) {
				g_CurrentServerIndex = g_TargetServerIndex;

				if (g_Motd.length() > 0) {
					char * buffer = new char[g_Motd.length() + 1];
					if (buffer) {
						strcpy(buffer, g_Motd.get());
						char * line = strtok(buffer, "\n");
						while (line) {
							WideWstring wide = Wstring_ToWide(line);
							Lobby_Chat_Printf(ColorSystem, wide.get());
							line = strtok(NULL, "\n");
						}
						Lobby_Chat_Printf(ColorSystem, L"\n");
						g_Motd.clear();
						delete[] buffer;
					}
				}
				g_ShowMOTD = true;

				Set_Wait_Window_Text((LPARAM)StringTable::LoadString("TXT_REQ_CHANLIST", NULL, "C:\\RA2\\wonline.cpp", 1206)); // level-2 1.001: line literal
				if (Request_Switch_Channel_List(0, 0)) {
					g_LastChatListTime = time(0);
				}
				event = Wait_For_Server_Switch_Event();
			}
		}
		if (event == EV_ABORT) {
			Close_Wait_Window(0xFFFFFFFF);
			ODMessageBox(g_LastErrorMessage, MB_OK, Wait_Callback_Thunk, false);
			return(false);
		}

		if (Request_Switch_Channel_List(0x21, 1)) {
			g_LastGameListTime = time(0);
		}
		Close_Wait_Window(0xFFFFFFFF);
		g_ServerType = type;
	}
	return(true);
}


// ---- level-2 1.001 (wol_k): the new nickname flow 0x00738E50 ----
// level-2 1.001 (wol_k, 2026-11-22): adapted from gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later; NewLogin 0x00788B00), checked against RA2 1.001 bytes

static inline void Set_Item_Text(HWND dialog, int id, char const * text) // RA2: the text of a control of the dialog
{
	HWND item = GetDlgItem(dialog, id);
	SendMessage(item, OD_SETTEXT, 0, (LPARAM)text);
}

static inline void Set_Item_String(HWND dialog, int id, char const * text) // RA2: as above, an empty text for an empty string
{
	if (text && strlen(text)) {
		Set_Item_Text(dialog, id, text);
	} else {
		Set_Item_Text(dialog, id, EmptyString);
	}
}

void __fastcall NewLogin(HWND dialog) // RA2: 1.001 0x00738E50, not in TibSun: asks the server for the account rules, then the birth date dialog (0xE7), the age check, and the new nickname dialog (0xE6 under 13, 0xF3, 0xF4 from 18); the nickname is requested with its password, which must be typed twice and have 8 characters
{
	char nick[32];
	char pass[32];
	char verify[32];
	char email[128];
	char parent_email[128];
	int newsletter;
	int shareinfo;
	int month;
	int day;
	int year;
	int dialog_id;
	HWND dlg;
	int wait;

	OwnerDraw::Slide_Dialog(dialog, false);
	Darken_Surface(NULL, true);
	newsletter = 1;
	month = 1;
	day = 0;
	year = 0;
	for (int i = 0; i < EV_COUNT; i++) {
		ResetEvent(g_WaitEventHandles[i]);
	}
	memset(nick, 0, sizeof(nick));
	memset(pass, 0, sizeof(pass));
	memset(verify, 0, sizeof(verify));
	memset(email, 0, sizeof(email));
	memset(parent_email, 0, sizeof(parent_email));
	{
		WideWstring title(StringTable::LoadString("WOL:NewAccountFetch", NULL, "C:\\RA2\\wonline.cpp", 8329)); // RA2: the wait dialog takes a wide text
		Show_Wait_Window(0x80, title, false);
	}
	DebugString("Newnick update check\n");
	g_pChat->RequestServerList(g_GameSKU, 0x10001, "TibSun", "TibPass99", 35);
	do {
		wait = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100);
		while (wait == WAIT_TIMEOUT) {
			WOL_Wait_Callback();
			wait = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100);
		}
		ResetEvent(g_WaitEventHandles[wait]);
	} while (wait != EV_ABORT && wait != EV_GOT_SERVERS);
	Close_Wait_Window(0xFFFFFFFF);
	if (wait == EV_ABORT) {
		ShowWindow(dialog, SW_SHOW);
		OwnerDraw::Set_Paint_Disabled(dialog, 0);
		return;
	}
	if (wait == EV_QUITGAME) {
		SetEvent(g_WaitEventHandles[EV_QUITGAME]);
		ShowWindow(dialog, SW_SHOW);
		OwnerDraw::Set_Paint_Disabled(dialog, 0);
		return;
	}

first_nick_retry:
	Darken_Surface(NULL, true);
	dlg = WS_Create_Dialog(ProgramInstance, 0xE7, MainWindow, WOL_Begin_Nick_Dialog_Proc, 0);
	Show_Dialog(dlg, 0xE7);
	SendDlgItemMessage(dlg, 0x62E, CB_SETCURSEL, month - 1, 0);
	if (day > 0) {
		Wstring text = Wstring_FromInt(day);
		Set_Item_Text(dlg, 0x62F, text.get());
	} else {
		Set_Item_Text(dlg, 0x62F, EmptyString);
	}
	if (year > 0) {
		Wstring text = Wstring_FromInt(year);
		Set_Item_Text(dlg, 0x630, text.get());
	} else {
		Set_Item_Text(dlg, 0x630, EmptyString);
	}
	SendDlgItemMessage(dlg, 0x626, OD_SETTEXT, 0, (LPARAM)email);
	SendDlgItemMessage(dlg, 0x631, BM_SETCHECK, newsletter, 0);
	ShowWindow(dialog, SW_HIDE);
	ShowWindow(dlg, SW_SHOWNORMAL);
	if (WS_Wait_Dialog(dlg, Wait_Callback_Thunk, false, true, true) == 1) {
	email[0] = 0;
	strcpy(email, g_BirthName.get());
	month = g_BirthMonth + 1;
	day = g_BirthDay;
	year = g_BirthYear;
	newsletter = g_BirthCheck;
	if (month <= 0 || day <= 0 || year <= 0 || strlen(email) < 6) {
		ODMessageBox(StringTable::LoadString("TXT_REQUIRED_FIELD", NULL, "C:\\RA2\\wonline.cpp", 8423), 0, Wait_Callback_Thunk, false); // level-2 1.001: one message for every missing field
		goto first_nick_retry;
	}
	g_UserConsent = 0;
	g_UserAge = -1;
	if (g_pNetUtil->RequestAgeCheck(month, day, year, email)) {
		ODMessageBox(StringTable::LoadString("TXT_CANT_CONNECT", NULL, "C:\\RA2\\wonline.cpp", 8431), 0, Wait_Callback_Thunk, false);
		goto pick_dialog;
	}
	{
		WideWstring title(StringTable::LoadString("WOL:RequestingNickname", NULL, "C:\\RA2\\wonline.cpp", 8434));
		Show_Wait_Window(0x100, title, true);
	}
	if (g_UserAge < 0) {
		if (g_AgeCheckResult == 0x80040100) {
			ODMessageBox(StringTable::LoadString("TXT_REQUIRED_FIELD", NULL, "C:\\RA2\\wonline.cpp", 8438), 0, Wait_Callback_Thunk, false);
		} else {
			ODMessageBox(StringTable::LoadString("TXT_CANT_CONNECT", NULL, "C:\\RA2\\wonline.cpp", 8440), 0, Wait_Callback_Thunk, false);
		}
		goto first_nick_retry;
	}
	if (g_UserAge < 13 && g_UserConsent == 0) {
		if (ODMessageBox(StringTable::LoadString("TXT_CONSENT_REQUIRED", NULL, "C:\\RA2\\wonline.cpp", 8449), 4, Wait_Callback_Thunk, false) == IDYES) {
			char url[256];
			sprintf(url, "http://apiregister.westwood.com/consent_form/index_%d.html", g_LanguageCode);
			ViewHTML(url, 1);
		}
		goto first_nick_retry;
	}
pick_dialog:
	if (g_UserAge < 13) {
		dialog_id = 0xE6;
	} else {
		dialog_id = (g_UserAge >= 18) + 0xF3;
	}
	dlg = WS_Create_Dialog(ProgramInstance, dialog_id, MainWindow, WOL_New_Nick_Dialog_Proc, 0);
	Show_Dialog(dlg, dialog_id);
	Set_Item_String(dlg, 0x628, nick);
	Set_Item_String(dlg, 0x5E5, parent_email);
	Set_Item_String(dlg, 0x72C, pass);
	Set_Item_String(dlg, 0x627, verify);
	ShowWindow(dlg, SW_SHOWNORMAL);
	SendMessage(dlg, 0x4A9, 0, 1);
	if (WS_Wait_Dialog(dlg, Wait_Callback_Thunk, false, true, true) != 1) {
		goto first_nick_retry;
	}
	nick[0] = 0;
	strcpy(nick, g_NewNickName.get());
	pass[0] = 0;
	strcpy(pass, g_NewNickPassword.get());
	verify[0] = 0;
	strcpy(verify, g_NewNickPasswordVerify.get());
	parent_email[0] = 0;
	if (dialog_id == 0xF3) {
		strcpy(parent_email, g_NewNickEmail.get());
	}
	shareinfo = 0;
	if (dialog_id == 0xF4) {
		shareinfo = g_NewNickCheck;
	}
	if (strcmp(pass, verify) != 0) {
		ODMessageBox(StringTable::LoadString("TXT_PASSWORD_VERIFY", NULL, "C:\\RA2\\wonline.cpp", 8555), 0, Wait_Callback_Thunk, false);
		goto pick_dialog;
	}
	if (strlen(pass) != 8) {
		ODMessageBox(StringTable::LoadString("TXT_PASSWORD_TOO_SHORT", NULL, "C:\\RA2\\wonline.cpp", 8560), 0, Wait_Callback_Thunk, false);
		goto pick_dialog;
	}
	if (g_pNetUtil->RequestNewNick(nick, pass, email, parent_email, newsletter, shareinfo) != 0) {
		goto cant_connect;
	}
	{
		WideWstring title(StringTable::LoadString("TXT_REQ_NICK", NULL, "C:\\RA2\\wonline.cpp", 8567));
		Show_Wait_Window(0x100, title, true);
	}
	if (g_OnNewNickResult >= 0) {
		goto done;
	}
	goto pick_dialog;

cant_connect:
	ODMessageBox(StringTable::LoadString("TXT_CANT_CONNECT", NULL, "C:\\RA2\\wonline.cpp", 8565), 0, Wait_Callback_Thunk, false);
done:
	ShowWindow(dialog, SW_SHOW);
	OwnerDraw::Set_Paint_Disabled(dialog, 0);
	} else {
		ShowWindow(dialog, SW_SHOWNORMAL);
		ShowWindow(dialog, SW_SHOW);
		OwnerDraw::Set_Paint_Disabled(dialog, 0);
	}
}

// ---- level-2 1.001 (wol_k): the creation of a game channel 0x00739DF0 ----
MultiplayerGameMode * Default_Game_Mode(void); // RA2: 1.001 0x005B39D0, the first game mode, as declared in src/ra2/netshare.cpp
void Delete_All(DynamicVectorClass<NodeNameType *> & vector); // RA2: 1.001 0x005A4070, deletes the nodes of the list, defined in src/ra2/MPLayer.CPP
void Seat_First_Player(int slot); // RA2: 1.001 0x005C2B00, defined in netshare.cpp
BOOL CALLBACK WOL_Game_Setup_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // RA2: 1.001 0x0073D030, the game setup dialog (0xC2) of a game channel (provisional name)

bool Create_Game_Channel(void) // RA2: 1.001 0x00739DF0, not in TibSun: the new game dialog (0xD2) asks for the password and the kind of the game (not in a tournament or clan match), then the game channel "<nick>'s_game" is created with the player as its first slot and the game setup dialog (0xC2) is opened; true when the channel was created
{
	Wstring password;
	if (VideoModeWidth >= 1024) {
		Session.WOLLimitResolution = false;
	}
	CreateGameDialogControl control(Session.WOLLimitResolution);
	g_GameStartRequested = false;
	if (Is_Tournament_Session()) { // RA2: a tournament or a clan match: no dialog
		WDTUnknownB100A4 = 2;
	} else {
		Darken_Surface(NULL, true);
		if (OwnerDraw::Controlled_Dialog(0xC3, (DLGPROC)WOL_New_Game_Dialog_Proc, &control) == 2) {
			return(false);
		}
		password = control.Text;
		password.replace(" ", "_");
	}
	g_pChat->RequestChannelLeave(); // RA2: virtual 0x24
	Channel channel;
	memset(&channel, 0, sizeof(channel));
	sprintf((char *)channel.name, "%s's_game", g_NickName);
	channel.type = 33;
	channel.minUsers = 1;
	if (WDTUnknownB100A4 < 2) {
		WDTUnknownB100A4 = 4;
	}
	strcpy((char *)channel.key, password.get());
	channel.maxUsers = WDTUnknownB100A4;
	char info[80];
	memset(info, 0, sizeof(info));
	Encode_Channel_ExInfo(info);
	info[40] = 0;
	strcpy((char *)channel.exInfo, info);
	if (Session.Type == GAME_INTERNET && Online_Session_State == 2) {
		channel.tournament = 1;
		channel.reserved |= 0x1000;
	} else if (Is_Tournament_Session()) {
		channel.tournament = 1;
		channel.reserved |= 0x800;
	} else {
		channel.tournament = control.Tournament;
		if (control.ClanGame) {
			channel.reserved |= 0x100;
		}
		Session.WOLLimitResolution = control.LowResolution;
		if (control.LowResolution) {
			channel.reserved |= (VideoModeWidth == 800) ? 0x400 : 0x200;
		}
	}
	channel.reserved += g_LobbyNumber;
	Leave_Current_Channel(0xC0, false);
	Session.MPGameMode = Default_Game_Mode();
	Session.Options.MPModeIndex = Session.MPGameMode->MPModeIndex;
	Session.MPGameMode->vt_entry_20();
	Set_Scenario_Info_From_Index(0);
	Delete_All(Session.Players);
	Clear_Slot_Lists();
	Reset_Slots();
	NodeNameType * player = new NodeNameType;
	memset(player, 0, sizeof(NodeNameType));
	WideWstring name = Wstring_ToWide(g_NickName);
	wcscpy(player->Name, name.get());
	WOLOptionsClass options;
	options.Load();
	rc_ptr<PlayerProfile> profile;
	if (options.Is_Bit1_Clear()) {
		profile = PlayerProfile::Load(g_NickName);
	} else {
		profile = g_PlayerProfile.Get();
	}
	if (profile.Get()) {
		Session.Set_Side(profile->Country, false);
		Session.Set_Color(profile->Color, false);
	}
	player->Set_Country(Session.Chosen_House());
	player->Set_Color(Session.Chosen_Color());
	player->Slot.Unknown77 = 1; // RA2: the player has accepted (as in the game options handling)
	Session.Players.Add(player);
	Seat_First_Player(0);
	wcscpy(Session.GameName, name.get());
	HRESULT result = g_pChat->RequestChannelCreate(&channel); // RA2: virtual 0x1C
	if (result == 0x800401F8) {
		ODMessageBox(StringTable::LoadString("TXT_BAD_CHANKEY", NULL, "C:\\RA2\\wonline.cpp", 9227), 0, Wait_Callback_Thunk, false);
		Close_Wait_Window(0x80);
		return(false);
	}
	if (result) {
		ODMessageBox(StringTable::LoadString("TXT_CANTCREATE_CHAN", NULL, "C:\\RA2\\wonline.cpp", 9233), 0, Wait_Callback_Thunk, false);
		Close_Wait_Window(0x80);
		return(false);
	}
	WideWstring creating(StringTable::LoadString("GUI:CreatingChannel", NULL, "C:\\RA2\\wonline.cpp", 9241));
	Show_Wait_Window(4, creating, false);
	Close_Wait_Window(0x80);
	Show_Wait_Window(4, creating, true);
	int index = Player_Name_To_Index(g_NickName);
	if (index < 0) {
		return(false);
	}
	User * user = NULL;
	g_UserList.getPointer(&user, index);
	player->Address = User_To_IPX_Address(user);
	if (!Is_Tournament_Session()) {
		HWND top = WS_Top_Window();
		if (top) {
			OwnerDraw::Slide_Dialog(top, false);
			Darken_Surface(NULL, true);
		}
		Darken_Surface(NULL, true);
		HWND dialog = OwnerDraw::Begin_Dialog(0xC2, (DLGPROC)WOL_Game_Setup_Dialog_Proc, 0);
		Session.MPGameMode->vt_entry_84();
		Session.MPGameMode->vt_entry_20();
		Session.MPGameMode->AssignTeamsAtStart();
		Session.MPGameMode->UnfixAlliances();
		ShowWindow(dialog, SW_SHOWNORMAL);
		if (top) {
			ShowWindow(top, SW_HIDE);
		}
	}
	return(true);
}


// level-2 1.001 (wol_l): NOT MATCHING (near miss, not claimed): faithful to the disassembly; with 4..7 dead inline calls after the tour voice block the bytes are equal apart from two `xor ebx,ebx` placements, so 1.001 has about 4 more inline call sites after that block (natural source not found); ArrayList<Wstring>::get 0x752730 is then called out of line in the three by-value copies for Play_WDT_Sound
// level-2 1.001 (wol_l): the lobby session of Wonline_Main (state 3), after Login_Wonline in the module
struct MPScoreRecord { // level-2 1.001: the score line of a player (MPScore.cpp, 0x70 bytes); only the name is read here
	wchar_t Name[20]; // +0x00
	int Data[18]; // +0x28, the scheme and the counts (see MPScore.cpp)
};
struct MPScoreData { // level-2 1.001: as declared in MPScore.cpp
	MPScoreRecord Records[8]; // 0x00A27534
	int GameNumber; // 0x00A278B4
	int PlayerCount; // 0x00A278B8
	int WinnerIndex; // 0x00A278BC
};
extern MPScoreData ScoreData; // level-2 1.001: 0x00A27534, defined in MPScore.cpp
BOOL CALLBACK Wonline_Chat_Lobby_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam); // level-2 1.001: 0x0073A680, the chat lobby dialog (0x113), provisional name, not yet defined

int __fastcall Run_Lobby_Session(int dialog_arg) // level-2 1.001: 0x00737C50 (1.006 0x00743720), the chat lobby: plays the voice of the last World Domination Tour game, logs in again after a lost connection, opens the lobby dialog (0x113) with the message of the day, requests the channel list, joins a lobby and waits until the player leaves (0), quits (2) or a game starts (1); the argument is the HWND of a lobby dialog that is already open (Wonline_Main passes 0)
{
	int result = 0;
	HWND & dialog = (HWND &)dialog_arg; // level-2 1.001: the argument itself holds the dialog (ebp), it is replaced by the new dialog

	if (g_PlayingNetGame && Session.Type == GAME_INTERNET && Online_Session_State == 2 && ScoreData.WinnerIndex != -1 && ScoreData.WinnerIndex < 8) { // level-2 1.001: the voice of the tour after a game
		Wstring winner = Wstring_Narrow(ScoreData.Records[ScoreData.WinnerIndex].Name);
		if (strnicmp(winner.get(), Session.Handle, 20) == 0) { // level-2 1.001: the player won
			if (Session.House == 0) {
				Play_WDT_Sound(g_WDT_GDIWinEmphasisSounds);
			} else if (Session.House == 1) {
				Play_WDT_Sound(g_WDT_NodWinEmphasisSounds);
			}
		} else if (Session.House == 0) {
			Play_WDT_Sound(g_WDT_GDILoseEmphasisSounds);
		}
	}
	g_PlayingNetGame = false;
	WolOptionsLocked = 0;
	if (Session.Type == GAME_INTERNET && Online_Session_State == 2) {
		g_pChat->RequestSetTeam(Session.House);
		if (!g_WDTSoundsInited) {
			Init_WDT_Sounds();
		}
	}

	if (g_ConnectionLost) {
		int login = Login_Wonline();
		if (login != 1) {
			return(login);
		}
	}
	Reset_All_Wait_Events(); // level-2 1.001 (a12): the file's helper, not a flat loop (inline call sites: VC6 then calls ArrayList<Wstring>::get 0x00752730 out of line in the three Play_WDT_Sound copies)

	if (dialog == NULL) {
		Darken_Surface(NULL, true);
		dialog = OwnerDraw::Begin_Dialog(0x113, (DLGPROC)Wonline_Chat_Lobby_Dialog_Proc, 0);
		if (g_Motd.length() > 0) { // level-2 1.001: the message of the day, line by line
			char * motd = new char[g_Motd.length() + 1];
			if (motd) {
				strcpy(motd, g_Motd.get());
				char * line = strtok(motd, "\n");
				while (line) {
					WideWstring text = Widen_Text(line); // level-2 1.001 (a12): the file's helper, as in the chat handlers
					Lobby_Chat_Printf(ColorSystem, text.get());
					line = strtok(NULL, "\n");
				}
				Lobby_Chat_Printf(ColorSystem, L"\n");
				g_Motd.clear();
				delete [] motd;
			}
		}
		Show_Wait_Window(0x10, StringTable::LoadString("GUI:LoginComplete", NULL, "C:\\RA2\\wonline.cpp", 7879), false);
	}

	g_SquadInfoRequests++;
	g_RequestingOwnSquadInfo = 1;
	g_pChat->RequestSquadInfo(0);
	g_ServerType = 0x21;
	Set_Wait_Window_Text((LPARAM)StringTable::LoadString("TXT_REQ_CHANLIST", NULL, "C:\\RA2\\wonline.cpp", 7896));
	if (!Get_Channel_List(0, false)) goto done;
	Set_Wait_Window_Text((LPARAM)StringTable::LoadString("TXT_JOINLOB", NULL, "C:\\RA2\\wonline.cpp", 7946));
	if (Join_Selected_Lobby(true) == -1) goto done;
	{
		DWORD event;
		while ((event = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100)) == WAIT_TIMEOUT) {
			WOL_Wait_Callback();
		}
		Reset_Wait_Event_At(event); // level-2 1.001 (a12): as above
		if (event == EV_ABORT || event == EV_ERROR) goto leave;
	}
	g_JoinLobbyNow = 0;
	Close_Wait_Window(0xFFFFFFFF);
	SetFocus(MainWindow);
	ShowWindow(dialog, SW_SHOWNORMAL);
	SetFocus(dialog);
	SetFocus(GetDlgItem(dialog, 0x540));
	g_LastGameListTime = 0;
	g_LastChatListTime = time(0);
	for (;;) {
		DWORD event;
		while ((event = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 20)) == WAIT_TIMEOUT) {
			WOL_Wait_Callback();
			if (g_JoinLobbyNow) { // level-2 1.001: the lobby is changed: its controls are off while the join runs
				EnableWindow(GetDlgItem(dialog, 0x53D), FALSE);
				EnableWindow(GetDlgItem(dialog, 0x6EE), FALSE);
				EnableWindow(GetDlgItem(dialog, 0x62D), FALSE);
				EnableWindow(GetDlgItem(dialog, 0x62B), FALSE);
				EnableWindow(GetDlgItem(dialog, 0x689), FALSE);
				EnableWindow(GetDlgItem(dialog, 0x558), FALSE);
				EnableWindow(GetDlgItem(dialog, 0x61F), FALSE);
				EnableWindow(GetDlgItem(dialog, 0x686), FALSE);
				if (Join_Selected_Lobby(false) == -1) {
					EnableWindow(GetDlgItem(dialog, 0x686), TRUE);
					SetEvent(g_WaitEventHandles[EV_ERROR]);
				}
				g_JoinLobbyNow = 0;
			}
		}
		Reset_Wait_Event_At(event); // level-2 1.001 (a12): as above
		if (event == EV_ABORT) {
			goto done;
		}
		if (event != EV_EXIT) { // level-2 1.001 (b5): the event tests in the 1.006 form (break in the else, the start of the game at the end); with the flat tests VC6 starts the zero web (ebx) after the first EV_ABORT test and the leave block's g_pChat test
			if (event == EV_SKIRMISH) {
				result = 2;
				break;
			}
			if (event == EV_ERROR) {
				goto done;
			}
			if (event == EV_STARTGAME) {
				goto started;
			}
		} else {
			break;
		}
	}
	g_LastErrorMessage[0] = 0;
leave:
	WS_Destroy_Dialog(dialog, 0);
	WOL_Wait_Callback();
	dialog = NULL;
	if (g_pChat) {
		g_pChat->RequestChannelLeave();
	}
done:
	Close_Wait_Window(0xFFFFFFFF);
	ODMessageBox(g_LastErrorMessage, 0, Wait_Callback_Thunk, false);
	if (dialog) WS_Destroy_Dialog(dialog, 0);
	while (WS_Destroy_Dialog(NULL, 0)) {
	}
	if (result == 1) {
		g_PlayingNetGame = true;
	}
	if (Session.Type == GAME_INTERNET && Online_Session_State == 2) {
		g_WDTTeams.clear();
	}
	return(result);
started:
	result = 1;
	g_pChat->RequestChannelLeave();
	g_GameStartRequested = false;
	g_LastErrorMessage[0] = 0;
	goto done;
}


// ---- wol_m (2026-11-22): the buddy dialog (0x116) ----

extern int g_BuddyColumn_7E6B78; // level-2 1.001: 0x007E6B78 (0xE3), provisional name; with g_SliderMin_7E6B70 (4), g_SliderMax_7E6B74 (0xD2), g_BuddyColumn_7E6B7C, g_SliderMin_7E6B80 (0x101) and g_SliderMax_7E6B84 (0x1A0) the six column positions of the buddy list (0x689)
extern int g_BuddyColumn_7E6B7C; // level-2 1.001: 0x007E6B7C (0xF0), provisional name

void __fastcall Fill_Buddy_List(HWND dialog) // RA2: 0x00755180 (1.001 0x007434A0), fills the buddy list of the dialog (0x116): a row per buddy with its status, the game it is in and that game's icons and ping // level-2 1.001: adapted from gibbo101/ra2-decomp src/wonline.cpp FUN_0079AF10 (YR 1.001, GPL-3.0-or-later)
{
	HWND list = GetDlgItem(dialog, 0x689);
	SendMessageA(list, OD_DISABLEPAINT, 0, 1);

	for (int i = 0; i < g_BuddyList.length(); ++i) {
		Wstring buddy;
		g_BuddyList.get(buddy, i);
		WideWstring display = Wstring_ToWide(buddy);
		unsigned int state = 0;
		g_BuddyStatus.getValue(buddy, state);

		int row = SendMessageA(list, OD_FINDSTRING, 0, (LPARAM)buddy.text());
		if (row == -1) {
			row = SendMessageA(list, OD_ADDSTRING_LIST, 0, (LPARAM)buddy.text());
		}

		OwnerDraw::CellData name;
		name.type = OwnerDraw::CellData::TEXT;
		name.string.set(display.get());
		name.hint.set(EmptyUIName);

		OwnerDraw::CellData status;
		status.type = OwnerDraw::CellData::TEXT;
		status.hint.set(EmptyUIName);

		OwnerDraw::CellData mode;
		mode.type = OwnerDraw::CellData::INVALID;
		mode.string.set(EmptyUIName);
		mode.hint.set(EmptyUIName);

		OwnerDraw::CellData password;
		password.type = OwnerDraw::CellData::INVALID;
		password.string.set(EmptyUIName);
		password.hint.set(EmptyUIName);

		OwnerDraw::CellData gametype;
		gametype.type = OwnerDraw::CellData::INVALID;
		gametype.string.set(EmptyUIName);
		gametype.hint.set(EmptyUIName);

		OwnerDraw::CellData ping;
		ping.type = OwnerDraw::CellData::INVALID;
		ping.string.set(EmptyUIName);
		ping.hint.set(EmptyUIName);

		switch (state) {
		case 1:
			status.string.set(StringTable::LoadString("WOL:BuddyDisabledFind", NULL, "C:\\RA2\\wonline.cpp", 17702));
			name.color = status.color = 0x808080;
			break;

		case 2:
			status.string.set(StringTable::LoadString("WOL:BuddyOffline", NULL, "C:\\RA2\\wonline.cpp", 17708));
			name.color = status.color = 0x808080;
			break;

		case 3:
			status.string.set(StringTable::LoadString("WOL:BuddyOnline", NULL, "C:\\RA2\\wonline.cpp", 17714));
			name.color = status.color = 0xF0F0;
			break;

		case 7:
		case 8:
			status.string.set(StringTable::LoadString("WOL:BuddyQuickMatching", NULL, "C:\\RA2\\wonline.cpp", 17721));
			name.color = status.color = 0x80FF00;
			break;

		case 4:
			{
				Channel channel;
				memset(&channel, 0, sizeof(channel));
				if (!g_BuddyChannels.getValue(buddy, channel)) {
					status.string.set(StringTable::LoadString("WOL:BuddyOnline", NULL, "C:\\RA2\\wonline.cpp", 17746));
					name.color = status.color = 0xF0F0;
				} else {
					if (channel.type == 0 && strncmp((char *)channel.name, "Lob_33_", strlen("Lob_33_")) == 0) { // level-2 1.001: the RA2 lobby prefix
						int lobby = atol((char *)channel.name + strlen("Lob_33_"));
						int page = lobby / 6; // level-2 1.001: six lobbies
						WideWstring location(g_Lobbies[lobby % 6]);
						if (page) {
							location += L" ";
							location += WideWstring_FromInt(page); // level-2 1.001: the page itself (YR: page + 1)
						}
						status.string.set(location.get());
					} else {
						status.string.set(Narrow_To_Wide((char *)channel.name));
					}
					name.color = status.color = 0xFF4000;
				}
			}
			break;

		case 5:
			{
				Channel game;
				memset(&game, 0, sizeof(game));
				char found = g_BuddyChannels.getValue(buddy, game);
				if (found) {
					Wstring game_name((char *)game.name);
					found = Find_Channel(game_name, g_GameChannelList, game);
				}
				if (found) {
					wchar_t details[80];
					swprintf(details, L"%hs %d/%d", game.name, game.currentUsers, game.maxUsers); // level-2 1.001: no info text fields
					status.string.set(details);
					name.color = status.color = 0xFFFF00;

					mode.type = OwnerDraw::CellData::SURFACE;
					if (game.tournament) {
						mode.surf = SurfaceCache.GetSurface("woltrny.pcx", false);
						mode.hint.set(StringTable::LoadString("TXT_TOURNAMENT_GAME", NULL, "C:\\RA2\\wonline.cpp", 17765));
					} else if (game.reserved & 0x100) {
						mode.surf = SurfaceCache.GetSurface("wolclan.pcx", false);
						mode.hint.set(StringTable::LoadString("TXT_BATTLECLAN_GAME", NULL, "C:\\RA2\\wonline.cpp", 17768));
					} else {
						mode.surf = SurfaceCache.GetSurface("gt18.bmp", false);
						mode.hint.set(EmptyUIName);
					}

					if (game.reserved & 0x400) { // level-2 1.001: the resource lock icon, in the password column
						password.type = OwnerDraw::CellData::SURFACE;
						password.surf = SurfaceCache.GetSurface("wolreslk.pcx", false);
					}

					if (game.flags & 0x100) {
						password.type = OwnerDraw::CellData::SURFACE;
						password.surf = SurfaceCache.GetSurface("wolpriv.pcx", false);
						password.hint.set(StringTable::LoadString("TXT_GAME_PASSWORD", NULL, "C:\\RA2\\wonline.cpp", 17782));
					}

					ping.type = OwnerDraw::CellData::PING;
					ping.pingtime = game.latency;
					swprintf(details, StringTable::LoadString("WOL:GamePing", NULL, "C:\\RA2\\wonline.cpp", 17787), game.latency);
					ping.hint.set(details);
				} else {
					status.string.set(StringTable::LoadString("WOL:BuddyOnline", NULL, "C:\\RA2\\wonline.cpp", 17790));
					name.color = status.color = 0xF0F0;
				}
			}
			break;

		case 6:
			status.string.set(StringTable::LoadString("WOL:BuddyPlayingGame", NULL, "C:\\RA2\\wonline.cpp", 17797));
			name.color = status.color = 0x3050FF;
			break;

		default:
			status.string.set(StringTable::LoadString("WOL:BuddyUnknownStatus", NULL, "C:\\RA2\\wonline.cpp", 17803));
			name.color = status.color = 0x808080;
			break;
		}

		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_SliderMin_7E6B70, row), (LPARAM)&name);
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_SliderMax_7E6B74, row), (LPARAM)&mode);
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_BuddyColumn_7E6B78, row), (LPARAM)&password);
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_BuddyColumn_7E6B7C, row), (LPARAM)&gametype);
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_SliderMin_7E6B80, row), (LPARAM)&status);
		SendMessageA(list, OD_SETCELL, MAKEWPARAM(g_SliderMax_7E6B84, row), (LPARAM)&ping);
	}

	int wanted = -1;
	if (g_SelectedBuddy.length() > 0) {
		wanted = SendMessageA(list, OD_FINDSTRING, 0, (LPARAM)g_SelectedBuddy.text());
	}
	if (wanted != SendMessageA(list, LB_GETCURSEL, 0, 0)) {
		SendMessageA(list, LB_SETCURSEL, wanted, 0);
	}
	SendMessageA(list, OD_DISABLEPAINT, 0, 0);
	InvalidateRect(list, NULL, FALSE);
	Update_Buddy_Buttons(dialog);
	Update_Buddy_Profile_Labels(dialog);
}

// level-2 1.001 (wol_n, 2026-11-22): the quick match of 1.001, adapted from gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later; FUN_0079FC40, FUN_007A0690, FUN_007A1060, FUN_007A1330), checked against RA2 1.001 bytes
bool Send_Match_Request(void); // RA2: 1.001 0x00748910, defined below
void Request_Match_Pings(void); // RA2: 1.001 0x00748EB0, defined below
bool Match_Start_Game(void); // RA2: 1.001 0x007497E0, defined below

int Start_Quick_Match(void) // RA2: 1.001 0x00747F00, the quick match: joins the lobby of the matching server, sends the match request and waits until the game starts; 1 when it does
{
	g_PlayingNetGame = false;
	Set_Match_State(1, -1, 0);
	if (VideoModeWidth > 640) {
		WideWstring text(Session.Type == GAME_INTERNET && Online_Session_State == 2 ? StringTable::LoadString("WOL:WDTResolutionQuery", NULL, "C:\\RA2\\wonline.cpp", 19046)
			: StringTable::LoadString("WOL:QuickMatchResolutionQuery", NULL, "C:\\RA2\\wonline.cpp", 19047));
		if (ODMessageBox(text.get(), MB_YESNO, Wait_Callback_Thunk, true) != IDYES) {
			return(0);
		}
		if (!Test_Display_Mode_Dialog(640, 480)) {
			return(0);
		}
		Options.ScreenWidth = 640;
		Options.ScreenHeight = 480;
		Options.Save_Settings();
	}

	WolOptionsLocked = 0;
	Set_Match_State(2, 30, 0);
	g_UserChannels.setEmpty();
	g_MatchOpponentName.clear();
	if (!Get_Channel_List(0, 0)) {
		return(0);
	}
	if (g_UserChannels.length() == 0) {
		ODMessageBox(StringTable::LoadString("WOL:NoMatchingAgentFound", NULL, "C:\\RA2\\wonline.cpp", 19080), 0, Wait_Callback_Thunk, false);
		return(0);
	}

	Channel chan;
	memset(&chan, 0, sizeof(chan));
	char const * prefix = Session.Type == GAME_INTERNET && Online_Session_State == 2 ? "Lob_35_" : "Lob_38_";
	int i;
	for (i = 0; i < g_UserChannels.length(); i++) {
		g_UserChannels.get(chan, i);
		if (strnicmp((char *)chan.name, prefix, strlen(prefix)) == 0) {
			break;
		}
	}
	if (i >= g_UserChannels.length()) {
		ODMessageBox(StringTable::LoadString("WOL:MatchingServerUnavailable", NULL, "C:\\RA2\\wonline.cpp", 19099), 0, Wait_Callback_Thunk, false);
		return(0);
	}

	HWND dialog = WS_Create_Dialog(ProgramInstance, 0x117, MainWindow, WOL_Match_Wait_Dialog_Proc, 0);
	Show_Dialog(dialog, 0x117);
	SendMessage(dialog, 0x4A9, 0, 1);
	ShowWindow(dialog, SW_SHOWNORMAL);
	Reset_Wait_Events();
	int result = 0;
	Reset_Buddy_Lists();

	while (true) {
		if (g_MatchState == 2) {
			long joined;
			{
				Wstring key("zotclot9");
				joined = Request_Channel_Join(&chan, key, WideWstring(StringTable::LoadString("TXT_JOINLOB", NULL, "C:\\RA2\\wonline.cpp", 19122)));
			}
			if (joined != 0) {
				Set_Match_State(0, -1, 1);
				ODMessageBox(StringTable::LoadString("WOL:ChannelJoinFailure", NULL, "C:\\RA2\\wonline.cpp", 19125), 0, Wait_Callback_Thunk, false);
				goto done;
			}
			Set_Match_State(3, 20, 0);
		}
		if (g_MatchState == 3) {
			if (strcmp((char *)chan.name, (char *)g_CurrentChannel.name) == 0) {
				Send_Match_Request();
			}
		}
		DWORD index;
		while ((index = WaitForMultipleObjects(18, g_WaitEventHandles, FALSE, 20)) == WAIT_TIMEOUT) {
			WOL_Wait_Callback();
		}
		Reset_Wait_Event_At(index); // level-2 1.001: the helper of the file (one more inline call site than ResetEvent itself)
		if (index == 0 || index == 6) {
			goto done;
		}
		if (index == 0x11) {
			Queue_User_Pings();
			Request_Match_Pings();
			continue;
		}
		if (index == 5) {
			if (g_MatchState == 0) {
				switch (g_MatchResult) {
					case 1:
						ODMessageBox(StringTable::LoadString("WOL:NoMatchingAgentFound", NULL, "C:\\RA2\\wonline.cpp", 19184), 0, Wait_Callback_Thunk, false);
						break;
					case 2:
						ODMessageBox(StringTable::LoadString("WOL:MatchTimeout", NULL, "C:\\RA2\\wonline.cpp", 19188), 0, Wait_Callback_Thunk, false);
						break;
					default:
						ODMessageBox(StringTable::LoadString("WOL:MatchFailExit", NULL, "C:\\RA2\\wonline.cpp", 19192), 0, Wait_Callback_Thunk, false);
						break;
				}
				goto done;
			}
			continue;
		}
		if (index == 0x10) {
			if (Match_Start_Game() && Online_Session_State == 2) {
				HWND match = OwnerDraw::Begin_Dialog(0x11F, WOL_Match_Found_Dialog_Proc, 0);
				Set_Match_State(10, 180, 0);
				SendMessage(match, 0x4A9, 0, 1);
				ShowWindow(match, SW_SHOWNORMAL);
			}
			continue;
		}
		if (index == 7) {
			break;
		}
	}

	Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("WOL:MatchGameStarting", NULL, "C:\\RA2\\wonline.cpp", 19217));
	g_GameStartRequested = false;
	result = 1;

done:
	WS_Destroy_Dialog(dialog, 0);
	HWND match = WS_Find_Dialog(0x11F);
	if (match) {
		WS_Destroy_Dialog(match, 0);
	}
	if (g_MatchState != 11) {
		Set_Match_State(1, -1, 0);
	}
	Leave_Current_Channel(0x40, true); // level-2 1.001: expanded here
	if (MultiplayerMapPreview) {
		delete MultiplayerMapPreview;
		MultiplayerMapPreview = NULL;
	}
	return(result);
}


void Request_Match_Pings(void); // RA2: 1.001 0x00748EB0, defined below
int Get_Performance_Profile(void); // RA2: 1.001 0x00519DF0, the rating of this machine (init.cpp)
rc_ptr<WorldDominationTour::Campaign> & Current_Campaign(void); // RA2: 1.001 0x00755810, the campaign of the tour (WorldDom.cpp)
extern int WDTScenarioID; // RA2: 1.001 0x00A255D0, the territory of the tour that is played

bool Send_Match_Request(void) // RA2: 1.001 0x00748910, asks the matching server (the channel host) for a quick match: "Match " or "MatchWDT " with the country, color, locale, rating and screen width; then the pings of the channel users are asked for
{
	g_MatchOpponentName.clear();
	HWND dialog = WS_Find_Dialog(0x11F);
	if (dialog) {
		WS_Destroy_Dialog(dialog, 0);
	}
	WolOptionsLocked = 0;
	if (g_UserList.length() < 2) {
		Set_Match_State(0, -1, 1);
		return(false);
	}
	g_PingRequests.clear();
	g_PingServers.clear();
	g_ServerPingsReceived = 0;
	Queue_User_Pings();

	User user;
	memset(&user, 0, sizeof(user));
	int host_index = -1;
	DebugString("User list is %d long, adding to ping request queue\n", g_UserList.length());
	for (int i = 0; i < g_UserList.length(); i++) {
		g_UserList.get(user, i);
		if (user.flags & 1) {
			host_index = i;
		}
	}
	if (host_index == -1) {
		Set_Match_State(0, -1, 1);
		return(false);
	}

	User host;
	memset(&host, 0, sizeof(host));
	g_UserList.get(host, host_index);
	host.next = NULL;

	WOLOptionsClass options;
	options.Load();
	rc_ptr<PlayerProfile> profile;
	if (options.Is_Bit1_Clear()) {
		profile = PlayerProfile::Load(g_NickName);
	} else {
		profile = g_PlayerProfile.Get();
	}
	int country = profile->Country;
	Wstring game("Match ");
	Wstring wdt;

	if (Online_Session_State == 2) {
		game = "MatchWDT ";
		rc_ptr<WorldDominationTour::Campaign> campaign = Current_Campaign();
		if (campaign.Get() == NULL) {
			wdt = ", WDS=0";
		} else {
			switch (campaign->PlayerFaction) {
				case 2:
					wdt = ", WDS=0";
					if (country > 4) {
						country = -1;
					}
					break;

				case 3:
					wdt = ", WDS=1";
					if (country >= 0 && country <= 4) {
						country = -1;
					}
					break;

				default:
					Set_Match_State(0, -1, 0);
					return(false);
			}
		}
		wdt += ", WDT=";
		wdt += Wstring_FromInt(WDTScenarioID);
	}

	Lobby_Chat_Printf(ColorPriv, StringTable::LoadString("WOL:RequestingMatch", NULL, "C:\\RA2\\wonline.cpp", 19398));

	Wstring request(game);
	request += "COU=";
	request += Wstring_FromInt(country);
	request += ", COL=";
	request += Wstring_FromInt(profile->Color);

	Wstring nick(g_NickName);
	nick.toLower();
	if (g_UserLocales.contains(nick)) {
		int locale = 0;
		g_UserLocales.getValue(nick, locale);
		request += ", LOC=";
		request += Wstring_FromInt(locale);
	}
	request += ", RAT=";
	request += Wstring_FromInt(Get_Performance_Profile());
	request += ", RES=";
	request += Wstring_FromInt(VideoModeWidth);
	request += wdt;

	g_pChat->RequestPrivateMessage(&host, request.get());
	Set_Match_State(4, 180, 0);
	Request_Match_Pings();
	return(true);
}


void Request_Match_Pings(void) // RA2: 1.001 0x00748EB0, asks the net utility for the pings of up to 10 users of the request list; the asked ones go to the pending list
{
	User user;
	memset(&user, 0, sizeof(user));
	DebugString("Requesting match pings, request list is %d long, pending list is %d long\n", g_PingRequests.length(), g_PingServers.length());
	while (g_PingRequests.length() != 0 && g_PingServers.length() < 10) {
		Wstring name;
		g_PingRequests.removeHead(name);
		DebugString("Removing %s from request list\n", name.get());
		int index;
		{
			Wstring key(name.get());
			index = Player_Name_To_Index(key);
		}
		if (index != -1) {
			g_UserList.get(user, index);
			if (user.ipaddr) {
				g_PingServers.addTail(name);
				DebugString("Pinging %s\n", name.get());
				int handle;
				in_addr addr;
				addr.s_addr = user.ipaddr;
				g_pNetUtil->RequestPing(inet_ntoa(addr), 1000, &handle);
			} else {
				DebugString("%s ipaddr is zero\n", name.get());
			}
		} else {
			DebugString("%s not found in info\n", name.get());
		}
	}
}

void Server_Pings_Done(void) // RA2: 1.001 0x007491B0, all pending match pings are answered: their averages go to the channel host as "Pings name,ping;...", then the next pings are asked for
{
	int count = 0;
	User user;
	memset(&user, 0, sizeof(user));
	Wstring pings("Pings ");
	DebugString("Sending ping list, pending list is %d long\n", g_PingServers.length());
	if (g_PingServers.length() != 0) {
		unsigned long ip = user.ipaddr;
		do {
			Wstring name;
			g_PingServers.removeTail(name);
			DebugString("Removed %s from ping pending list\n", name.get());
			int index;
			{
				Wstring key(name.get());
				index = Player_Name_To_Index(key); // level-2 1.001: expanded here
			}
			if (index == -1) {
				DebugString("%s not found in info\n", name.get());
			} else {
				g_UserList.get(user, index);
				ip = user.ipaddr;
				if (ip == 0) {
					DebugString("%s ipaddr is zero\n", name.get());
				} else {
					int ping = -1;
					g_pNetUtil->GetAvgPing(ip, &ping);
					if (ping != -1) {
						DebugString("%s avg ping is %d\n", name.get(), ping);
						pings += name + Wstring(",") + Wstring_FromInt(ping) + Wstring(";");
						count++;
					} else {
						DebugString("Error measuring %s/'s ping\n", name.get());
					}
				}
			}
		} while (g_PingServers.length() != 0);
	}
	if (count > 0) {
		User * host = Find_Owner_User(); // level-2 1.001: expanded here
		if (host) {
			g_pChat->RequestPrivateMessage(host, pings.get());
			DebugString("Sending ping list : %s\n", pings.get());
		}
	}
	Request_Match_Pings();
}

bool Create_Game_Channel(void); // RA2: 1.001 0x00739DF0, creates the game channel of the player (as the lobby's new game button does); true when the channel was created

bool Match_Start_Game(void) // RA2: 1.001 0x007497E0 (level-2 1.001: nested ifs with one final return, as in gibbo101's YR 0x007A1BB0; the timeout falls into the common end, so VC6 keeps the channel list failure's return tail), the "Start " message of the matching server names the two players: the first creates the game channel, the second looks for it ("<first>'s_game") and joins it
{
	char options[256];
	WolOptionsLocked = 0;
	strncpy(options, g_MatchStartOptions, sizeof(options));
	strtok(options, ":");
	char * first = strtok(NULL, ",");
	strtok(NULL, ",");
	strtok(NULL, ",");
	char * second = strtok(NULL, ",");
	if (first && second) {
		if (stricmp(first, g_NickName.get()) == 0 || stricmp(second, g_NickName.get()) == 0) {
			if (stricmp(first, g_NickName.get()) == 0) {
				g_MatchOpponentName = second;
				Lobby_Chat_Printf(0xC0FFFF, StringTable::LoadString("WOL:MatchFoundWith", NULL, "C:\\RA2\\wonline.cpp", 19668), second);
				Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("WOL:MatchCreatingGame", NULL, "C:\\RA2\\wonline.cpp", 19669));
				g_GameStartRequested = false;
				Set_Match_State(6, 30, 0);
				if (Create_Game_Channel()) {
					Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("WOL:MatchWaitingForJoin", NULL, "C:\\RA2\\wonline.cpp", 19673), second);
					return(true);
				}
				Lobby_Chat_Printf(0x20C0FF, StringTable::LoadString("WOL:MatchErrorCreatingGame", NULL, "C:\\RA2\\wonline.cpp", 19680));
				Set_Match_State(2, 30, 0);
			} else {
				g_MatchOpponentName = first;
				Lobby_Chat_Printf(0xC0FFFF, StringTable::LoadString("WOL:MatchFoundWith", NULL, "C:\\RA2\\wonline.cpp", 19685), first);
				Wstring game_name = Wstring(first) + Wstring("'s_game");
				Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("WOL:MatchAttemptingToFindGame", NULL, "C:\\RA2\\wonline.cpp", 19688), first);
				Set_Match_State(7, 30, 0);
				int attempt = 0;
				while (attempt++ < 30) {
					if (!Get_Channel_List(0x21, 0)) {
						Lobby_Chat_Printf(0x20C0FF, StringTable::LoadString("WOL:MatchGameChannelNotFound", NULL, "C:\\RA2\\wonline.cpp", 19692), first);
						Set_Match_State(3, 20, 0);
						return(false);
					}
					Channel channel;
					memset(&channel, 0, sizeof(channel));
					for (int i = 0; i < g_GameChannelList.length(); i++) {
						g_GameChannelList.get(channel, i);
						if (stricmp((char *)channel.name, game_name.get()) == 0) {
							if (Join_Game_Channel(&channel)) {
								Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("WOL:MatchJoinedGame", NULL, "C:\\RA2\\wonline.cpp", 19702), first);
								Set_Match_State(9, 90, 0);
								return(true);
							}
							Lobby_Chat_Printf(0x20C0FF, StringTable::LoadString("WOL:MatchErrorJoiningGame", NULL, "C:\\RA2\\wonline.cpp", 19710));
							return(false);
						}
					}
					WOL_Wait_Callback();
					Sleep(100);
				}
				Lobby_Chat_Printf(0x20C0FF, StringTable::LoadString("WOL:MatchGameChannelNotFound", NULL, "C:\\RA2\\wonline.cpp", 19718), first);
				Set_Match_State(2, 30, 0);
			}
		} else {
			Lobby_Chat_Printf(0x20C0FF, StringTable::LoadString("WOL:MatchBadParameters", NULL, "C:\\RA2\\wonline.cpp", 19658));
			Set_Match_State(3, 20, 0);
		}
	} else {
		Lobby_Chat_Printf(0x20C0FF, StringTable::LoadString("WOL:MatchBadParameters", NULL, "C:\\RA2\\wonline.cpp", 19648));
		Set_Match_State(3, 20, 0);
	}
	return(false);
}

void __fastcall Setup_Match_Map(char const * options) // RA2: 1.001 0x00749DD0, the two players of the "Start " message of the matching server (name, side, color each) and the random map of the match
{
	char buffer[256];
	strcpy(buffer, options);
	char * name = strtok(buffer, ":,");
	int house = atol(strtok(NULL, ","));
	int color = atol(strtok(NULL, ","));
	{
		Wstring player(name);
		Assign_House_And_Color(player, house, color);
	}
	name = strtok(NULL, ",");
	house = atol(strtok(NULL, ","));
	color = atol(strtok(NULL, ","));
	{
		Wstring player(name);
		Assign_House_And_Color(player, house, color);
	}

	strcpy(Session.ScenarioFileName, "RandMap.Sed");
	RandomMapGen.SeedData.NumPlayers = 4;
	Session.Options.ScenarioIndex = -1;
	HWND dialog = WS_Find_Dialog(0x11F);
	Do_Random_Map(dialog, Wait_Callback_Thunk);
	RandomMapGen.SeedData.Save("RandMap.Sed");

	int index;
	bool found = false;
	for (index = 0; index < Session.Scenarios.Count(); index++) {
		if (Session.Scenarios[index]->Is_Random_Map()) {
			found = true;
			break;
		}
	}
	char * digest = CalcRandomMapDigest();
	if (!found) {
		MultiMission * scenario = new MultiMission("RandMap.Sed", RandomMapGen.SeedData.MapDescription, digest, true);
		Session.Scenarios.Add(scenario);
	} else {
		Session.Scenarios[index]->Set_Digest(digest);
		Session.Scenarios[index]->Set_Description(RandomMapGen.SeedData.MapDescription);
	}
	delete digest;
	if (Set_Scenario_Info_From_Index(index) == true) {
		Session.Options.ScenarioIndex = index;
	}
}

// level-2 1.001 (wol_n, 2026-11-22): adapted from gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later; CNetUtilEventSink::OnLadderList 0x007A3100), checked against RA2 1.001 bytes
extern int g_Col_Rung; // RA2: 1.001 0x00B0FCD8, the columns of the ladder list (0x57F) of the ladder dialog (0xC1) (provisional names, as in the YR decompilation)
extern int g_Col_Name; // RA2: 1.001 0x00B0E5C0
extern int g_Col_Points; // RA2: 1.001 0x00B0ECA0
extern int g_Col_Wins; // RA2: 1.001 0x00B0FFC4
extern int g_Col_Losses; // RA2: 1.001 0x00B0E39C
extern int g_Col_Disconnects; // RA2: 1.001 0x00B0EE7C
void Update_Buddy_Profile_Labels(HWND dialog); // RA2: 1.001 0x00744480, defined above

static inline char Remove_Ladder(Dictionary<Wstring, Ladder> & dict, Wstring & key, Ladder & value) // RA2: a wrapper layer (as in the YR decompilation); the executable calls Dictionary::remove out of line here
{
	return dict.remove(key, value);
}

STDMETHODIMP CNetUtilEventSink::OnLadderList(HRESULT res, Ladder *list, int totalCount, long timeStamp, int keyRung) // RA2: 1.001 0x0074AB00, the ladder entries from the ladder server: they fill the ladder list when the ladder dialog asked, go into the ladder dictionary of their SKU and update the player's own profile
{
	Ladder * temp = NULL;
	if (res != 0) {
		list = NULL;
	}
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	HWND rung_list = GetDlgItem(WS_Find_Dialog(0xC1), 0x57F);
	if (rung_list && keyRung == -1 && res == 0) {
		rung_list = NULL;
	}
	if (rung_list) {
		SendMessage(rung_list, LB_RESETCONTENT, 0, 0);
		if (list == NULL) {
			SendMessage(rung_list, 0x4CC, (WPARAM)-1, (LPARAM)StringTable::LoadString("TXT_NOT_IN_LADDER", NULL, "C:\\RA2\\wonline.cpp", 3272));
			InvalidateRect(rung_list, NULL, FALSE);
			return(S_OK);
		}
	} else if (list == NULL) {
		return(S_OK);
	}

	temp = list;
	wchar_t list_string[128];
	int top_rung = list->rung;
	OwnerDraw::CellData thecell;

	if (list->sku == 0x802100) {
		if (g_BattleClansLadderDict.getEntries() > 2000) {
			g_BattleClansLadderDict.clear();
		}
	} else if (list->sku == 0x2300) {
		if (g_WDTLadderDict.getEntries() > 2000) {
			g_WDTLadderDict.clear();
		}
	} else {
		if (g_GeneralLadderDict.getEntries() > 2000) {
			g_GeneralLadderDict.clear();
		}
	}

	if (list && rung_list) {
		g_LadderPos = list->rung;
	}

	Wstring my_name = ((Wstring const &)g_NickName).toLower();
	int row = 0;
	while (temp) {
		if (temp->points == -1) {
			temp = temp->next;
			continue;
		}

		if (rung_list) {
			thecell.type = OwnerDraw::CellData::PRIMARY;
			swprintf(list_string, L"%d", temp->rung);
			SendMessage(rung_list, 0x4CC, (WPARAM)-1, (LPARAM)list_string);
			SendMessage(rung_list, OD_SETCELL, MAKEWPARAM(g_Col_Rung, row), (LPARAM)&thecell);

			thecell.type = OwnerDraw::CellData::TEXT;
			wchar_t wide_name[0x1400];
			Char_To_Wide(wide_name, (char *)temp->login_name, -1);
			thecell.string.set(wide_name);
			SendMessage(rung_list, OD_SETCELL, MAKEWPARAM(g_Col_Name, row), (LPARAM)&thecell);

			swprintf(list_string, L"%d", temp->points);
			thecell.string.set(list_string);
			SendMessage(rung_list, OD_SETCELL, MAKEWPARAM(g_Col_Points, row), (LPARAM)&thecell);

			swprintf(list_string, L"%d", temp->wins);
			thecell.string.set(list_string);
			SendMessage(rung_list, OD_SETCELL, MAKEWPARAM(g_Col_Wins, row), (LPARAM)&thecell);

			swprintf(list_string, L"%d", temp->losses);
			thecell.string.set(list_string);
			SendMessage(rung_list, OD_SETCELL, MAKEWPARAM(g_Col_Losses, row), (LPARAM)&thecell);

			swprintf(list_string, L"%d", temp->disconnects);
			thecell.string.set(list_string);
			SendMessage(rung_list, OD_SETCELL, MAKEWPARAM(g_Col_Disconnects, row), (LPARAM)&thecell);

			row++;
		}

		Wstring ladder_name((char *)temp->login_name);
		ladder_name.toLower();

		if (list->sku == 0x802100) {
			Ladder old;
			Remove_Ladder(g_BattleClansLadderDict, ladder_name, old);
			g_BattleClansLadderDict.add(ladder_name, *temp);
		} else if (list->sku == 0x2300) {
			Ladder old;
			Remove_Ladder(g_WDTLadderDict, ladder_name, old);
			g_WDTLadderDict.add(ladder_name, *temp);
		} else {
			Ladder old;
			Remove_Ladder(g_GeneralLadderDict, ladder_name, old);
			g_GeneralLadderDict.add(ladder_name, *temp);
		}

		if (my_name == ladder_name) {
			rc_ptr<PlayerProfile> profile = PlayerProfile::Load(g_NickName);
			if (profile.Get()) {
				profile->UpdateStats(temp);
				profile->Save(&ladder_name);
			}
		}

		temp = temp->next;
	}

	if (rung_list) {
		SendMessage(rung_list, LB_SETCURSEL, (WPARAM)keyRung - top_rung, 0);
		InvalidateRect(rung_list, NULL, FALSE);
	} else {
		Draw_Player_List(0, false);
	}
	Request_Buddy_Ladders();
	HWND dialog = WS_Find_Dialog(0x116);
	if (dialog) {
		Update_Buddy_Profile_Labels(dialog);
	}
	return(S_OK);
}


// ---- level-2 1.001 (wol_o): declarations of the game channel dialogs (setup 0x0073D030, guest 0x0073E420) ----
int __fastcall Player_Side_Slot(int id); // RA2: 1.001 0x004D0DD0, the player a side combo box belongs to, or -1 (GDlgSupp.cpp)
int __fastcall Player_Color_Slot(int id); // RA2: 1.001 0x004D1590, the player a color combo box belongs to, or -1 (GDlgSupp.cpp)
int __fastcall Player_Side_ID(int slot); // RA2: 1.001 0x004D0D70, the side combo box of a player (GDlgSupp.cpp)
int __fastcall Player_Color_ID(int slot); // RA2: 1.001 0x004D1530, the color combo box of a player (GDlgSupp.cpp)
int __fastcall Get_Side_Data(HWND dialog, int id, int index); // RA2: 1.001 0x004D14F0 (GDlgSupp.cpp)
int __fastcall Get_Color_Data(HWND dialog, int id, int index); // RA2: 1.001 0x004D1FD0 (GDlgSupp.cpp)
wchar_t const * __fastcall Side_Name(int side); // RA2: 1.001 0x004D0E40 (GDlgSupp.cpp)
wchar_t const * __fastcall Color_Name(int color); // RA2: 1.001 0x004D1600 (GDlgSupp.cpp)
void __fastcall Fill_All_Side_Lists(HWND dialog); // RA2: 1.001 0x004D1030 (GDlgSupp.cpp)
void __fastcall Fill_All_Color_Lists(HWND dialog); // RA2: 1.001 0x004D1A80 (GDlgSupp.cpp)
void __fastcall Slot_Side_Changed(HWND dialog, int id); // RA2: 1.001 0x005C3310 (netshare.cpp)
void __fastcall Slot_Color_Changed(HWND dialog, int id); // RA2: 1.001 0x005C3360 (netshare.cpp)
int __fastcall Control_Slot(int id); // RA2: 1.001 0x005C3120 (netshare.cpp)
int __fastcall Get_Combo_Data(HWND dialog, int id, int index); // RA2: 1.001 0x005C32D0 (netshare.cpp)
wchar_t const * __fastcall Slot_Node_Name(MPPlayerNode * node); // RA2: 1.001 0x005C3190 (netshare.cpp)
void __fastcall Send_Public_Game_Options(char const * options); // RA2: 1.001 0x005BE7A0 (netshare.cpp)
void __fastcall Send_Private_Game_Options(char const * name, char const * options); // RA2: 1.001 0x005BE8D0 (netshare.cpp)
void __fastcall Enable_Host_Controls(HWND dialog, bool enable); // RA2: 1.001 0x005C5930 (netshare.cpp)
void __fastcall Set_Item_Text(HWND dialog, MultiplayerGameMode * mode); // RA2: 1.001 0x005BDF90, the name of the game mode (netshare.cpp)
void __fastcall Set_Skirmish_Dialog_Text(HWND dialog); // RA2: 1.001 0x005BDFF0 (netshare.cpp)
void __fastcall Update_Preview(HWND dialog); // RA2: 1.001 0x005C15D0 (netshare.cpp)
namespace OwnerDraw { char const * __fastcall Control_Tooltip_Label(unsigned int key, HWND window); } // RA2: 1.001 0x005DA760, defined in ownrdraw.cpp
extern bool Flag_A5A8BE; // RA2: 1.001 0x00A5A8BE, netdlg2.cpp's LobbyDialogFlag, cleared when the dialog of a joined player is set up
struct WOLToolTipTextRequest { // level-2 1.001: what a combo box asks for with message 0x4E9 (netdlg2.cpp's ToolTipTextRequest)
	HWND Window; // RA2: the control
	int Item; // RA2: the list item under the cursor, -1 for none
	WideWstring Text; // RA2: the answer
};


// ---- level-2 1.001 (wol_o): the game setup dialog of a game channel 0x0073D030 ----
struct SkirmishSettingsType; // RA2: the type src/ra2/netshare.cpp gives Session.WOL in Save_Skirmish_Settings
void __fastcall Save_Skirmish_Settings(HWND dialog, SkirmishSettingsType * settings); // RA2: 1.001 0x005C51D0, stores the options of the dialog (netshare.cpp)
void __fastcall Host_Func_5C5350(HWND dialog, void * settings); // RA2: 1.001 0x005C5350, sets the options of the dialog from the stored settings (netshare.cpp)
void __fastcall Clear_Accept_States(void); // RA2: 1.001 0x005C3020 (netshare.cpp)
bool __fastcall Is_Host(void); // RA2: 1.001 0x005C2560 (netshare.cpp)
void __fastcall Set_Slot_Node(HWND dialog, int id, MPPlayerNode * node, int kind); // RA2: 1.001 0x005C4D30 (netshare.cpp)
void __fastcall Leave_Lobby(void); // RA2: 1.001 0x005BE6B0 (netshare.cpp)
bool __fastcall Clear_AI_Slots(HWND dialog); // RA2: 1.001 0x005C41A0 (netshare.cpp)
void __fastcall Scenario_Changed(HWND dialog, int old_index, int new_index); // RA2: 1.001 0x005C4940 (netshare.cpp)
void __fastcall Update_Slot_Icons(HWND dialog); // RA2: 1.001 0x005C3740 (netshare.cpp)
void __fastcall Load_Random_Map_Preview(HWND dialog); // RA2: 1.001 0x005C5140 (netshare.cpp)
void __fastcall Select_Player_Side(HWND dialog, int slot); // RA2: 1.001 0x004D10B0 (GDlgSupp.cpp)
void __fastcall Select_Player_Color(HWND dialog, int slot); // RA2: 1.001 0x004D1B00 (GDlgSupp.cpp)
#include "version.h" // RA2: VerNum

// level-2 1.001 (wol_o): NOT MATCHING (near miss, not claimed): 57 bytes differ, only in the block layout of the side/color combo cases: 1.001 emits the color case with the shared tail (Send_Lobby_Options, Refresh_Slot_Settings, return) and the side case jumps back into it; every source form tried (separate returns, break, early exit, a shared label in either case or order) puts the tail after the side case or does not merge it
BOOL CALLBACK WOL_Game_Setup_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0073D030 (YR WOL_Game_Options_Proc), the game setup dialog (0xC2) of the host of a game channel: the options, the slots, the scenario and the start button
{
	int i;
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	if (!WolOptionsLocked) {
		switch (message) {
		case 0x497:
			if (Session.Type == GAME_INTERNET && (g_CurrentChannel.tournament || Is_Current_Channel_Flag_8())) { // RA2: a tournament or a clan game: no computer players and no alliances
				EnableWindow(GetDlgItem(window, 0x552), FALSE);
				EnableWindow(GetDlgItem(window, 0x553), FALSE);
				EnableWindow(GetDlgItem(window, 0x597), FALSE);
				Session.Options.AIPlayers = 0;
				Session.Options.AlliesAllowed = false;
				HWND item = GetDlgItem(window, 0x54E);
				SendMessage(item, BM_SETCHECK, 1, 0);
				EnableWindow(item, FALSE);
				item = GetDlgItem(window, 0x54B);
				SendMessage(item, BM_SETCHECK, 1, 0);
				EnableWindow(item, FALSE);
				Session.Options.ShortGame = true;
				Session.Options.Bases = true;
			}
			Fill_Options_Dialog(window, 1);
			break;
		case WM_HSCROLL:
			if ((short)wparam == 8) {
				if (GetDlgItem(window, 0x54F)) {
					Session.Options.UnitCount = SendDlgItemMessage(window, 0x54F, 0x400, 0, 0);
				}
				if (GetDlgItem(window, 0x402)) {
					Session.Options.Credits = SendDlgItemMessage(window, 0x402, 0x400, 0, 0);
				}
				if (GetDlgItem(window, 0x529)) {
					Session.Options.GameSpeed = 6 - SendDlgItemMessage(window, 0x529, 0x400, 0, 0);
				}
				for (i = 1; i < 4; i++) {
					g_UserInfo[i].accepted = 0;
				}
				Clear_Accept_States();
				Draw_Player_List(0, false);
			}
			break;
		case WM_COMMAND:
			{
				bool changed = false;
				switch (LOWORD(wparam)) {
				case 0x3E8:
					Session.Options.MCVRedeploy = false;
					if (SendDlgItemMessage(window, 0x3E8, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.MCVRedeploy = true;
					}
					changed = true;
					break;
				case 0x54D:
					Session.Options.Goodies = false;
					if (SendDlgItemMessage(window, 0x54D, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.Goodies = true;
					}
					changed = true;
					break;
				case 0x551:
					Session.Options.CrapEngineers = false;
					if (SendDlgItemMessage(window, 0x551, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.CrapEngineers = true;
					}
					changed = true;
					break;
				case 0x596:
					Session.Options.HarvTruce = false;
					if (SendDlgItemMessage(window, 0x596, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.HarvTruce = true;
					}
					changed = true;
					break;
				case 0x597:
					Session.Options.AlliesAllowed = false;
					if (SendDlgItemMessage(window, 0x597, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.AlliesAllowed = true;
					}
					changed = true;
					break;
				case 0x599:
					Session.Options.FogOfWar = false;
					if (SendDlgItemMessage(window, 0x599, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.FogOfWar = true;
					}
					changed = true;
					break;
				case 0x624:
					Session.Options.BridgeDestruction = false;
					if (SendDlgItemMessage(window, 0x624, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.BridgeDestruction = true;
					}
					changed = true;
					break;
				case 0x69A:
					Session.Options.SWAllowed = false;
					if (SendDlgItemMessage(window, 0x69A, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.SWAllowed = true;
					}
					break;
				case 0x54B:
					Session.Options.Bases = false;
					if (SendDlgItemMessage(window, 0x54B, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.Bases = true;
					} else if (!Session.Options.Bases) {
						Session.Options.ShortGame = false;
						SendDlgItemMessage(window, 0x54E, BM_SETCHECK, 0, 0);
					}
					changed = true;
					break;
				case 0x54E:
					Session.Options.ShortGame = false;
					if (SendDlgItemMessage(window, 0x54E, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.ShortGame = true;
						if (!Session.Options.Bases) {
							Session.Options.Bases = true;
							SendDlgItemMessage(window, 0x54B, BM_SETCHECK, 1, 0);
						}
					}
					changed = true;
					break;
				case 0x69D:
					Session.Options.BuildOffAlly = false;
					if (SendDlgItemMessage(window, 0x69D, BM_GETCHECK, 0, 0) == 1) {
						Session.Options.BuildOffAlly = true;
					}
					break;
				}
				if (changed) {
					for (i = 1; i < 4; i++) {
						g_UserInfo[i].accepted = 0;
					}
					Clear_Accept_States();
					Draw_Player_List(0, false);
				}
			}
			break;
		}
	}
	switch (message) {
	case WM_NCHITTEST: // RA2: the tool tip of the control under the cursor
		{
			HWND tip = GetDlgItem(window, 0x695);
			if (!tip) {
				goto unhandled;
			}
			POINT point;
			point.x = lparam & 0xFFFF;
			point.y = (unsigned long)lparam >> 16;
			RECT rect;
			GetWindowRect(window, &rect);
			point.x -= rect.left;
			point.y -= rect.top;
			wchar_t const * text = NullWString;
			HWND control = ChildWindowFromPointEx(window, point, 1);
			if (control) {
				char const * label = OwnerDraw::Control_Tooltip_Label((unsigned int)window, control);
				if (label) {
					text = StringTable::LoadString(label, NULL, "C:\\RA2\\wonline.cpp", 12376);
				}
			}
			SendMessage(tip, 0x4B2, 0, (LPARAM)text);
		}
		return(0);

	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);

	case WM_DESTROY:
		if (MultiplayerMapPreview) {
			delete MultiplayerMapPreview;
			MultiplayerMapPreview = NULL;
		}
		if (!Progress.Has_Dialog()) {
			goto unhandled;
		}
		Progress.Clear_Dialog();
		return(0);

	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		if (MultiplayerMapPreview) {
			MultiplayerMapPreview->Blit_Preview(window);
		} else if (Session.Options.ScenarioIndex == -1 && RandomMapGen.MapPreview) {
			RandomMapGen.MapPreview->Blit_Preview(window);
		}
		if (Progress.Has_Dialog()) {
			Progress.Display_Progress(Point2D(-1, -1));
		}
		ValidateRect(window, NULL);
		return(0);

	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case IDCANCEL: // RA2: leave the game channel
			if (WolOptionsLocked) {
				goto unhandled;
			}
			Save_Skirmish_Settings(window, (SkirmishSettingsType *)&Session.WOL);
			Session.Write_MultiPlayer_Settings();
			if (MultiplayerMapPreview) {
				delete MultiplayerMapPreview;
				MultiplayerMapPreview = NULL;
			}
			WS_Destroy_Dialog(window, 2);
			ShowWindow(window, SW_HIDE);
			OwnerDraw::Set_Paint_Disabled(window, 1);
			g_pChat->RequestChannelLeave();
			g_JoinLobbyNow = 1;
			return(0);

		case 0x3ED: // RA2: the action button
			{
				HWND edit = GetDlgItem(window, 0x540);
				WideWstring text = Limit_Name_Text(edit);
				SendMessage(edit, 0x4B2, 0, (LPARAM)NullWString);
				SetFocus(edit);
				InvalidateRect(edit, NULL, FALSE);
				COLORREF color = ColorAction;
				if (strlen((char *)g_CurrentChannel.name) == 0) {
					Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_NOT_IN_CHAN", NULL, "C:\\RA2\\wonline.cpp", 13025));
				} else if (text.length() > 0) {
					if (Send_Chat_Action(text)) {
						color = ColorPrivAction;
					}
					Lobby_Chat_Printf(color, L"%hs %s", g_NickName, text.get());
				} else {
					Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_ENTER_MESSAGE", NULL, "C:\\RA2\\wonline.cpp", 13032));
				}
			}
			return(0);

		case 0x540: // RA2: the chat line
			{
				WideWstring text = Limit_Name_Text((HWND)lparam);
				if (HIWORD(wparam) == 0x501) {
					SendMessage((HWND)lparam, 0x4B2, 0, (LPARAM)NullWString);
					if (text.length() > 0) {
						COLORREF color = ColorMe;
						if (Send_Chat_Message(text) == 1) {
							color = ColorPriv;
						}
						Lobby_Chat_Printf(color, L"[%hs] %s", g_NickName, text.get());
					}
				}
			}
			return(0);

		case 0x588: // RA2: the start button
			{
				SetFocus(GetDlgItem(window, 0x540));
				if (g_GameStartRequested == true) {
					goto unhandled;
				}
				Save_Skirmish_Settings(window, (SkirmishSettingsType *)&Session.WOL);
				Session.Write_MultiPlayer_Settings();
				Refresh_Slot_Settings(window, true);
				if (g_UserList.length() < 2) {
					Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_ONLY_ONE", NULL, "C:\\RA2\\wonline.cpp", 12799));
					return(0);
				}
				bool nomap = false;
				for (i = 1; i < Session.Players.Count(); i++) {
					if (!Session.Players[i]->Slot.Unknown7F) { // RA2: the player does not have the scenario
						Lobby_Chat_Printf(-1, StringTable::LoadString("GUI:HostNoMap", NULL, "C:\\RA2\\wonline.cpp", 12817), Session.Players[i]->Name, Session.Options.ScenarioDescription);
						nomap = true;
					}
				}
				if (nomap) {
					return(0);
				}
				for (i = 0; i < g_UserList.length(); i++) {
					if (!g_UserInfo[i].accepted) {
						Leave_Lobby();
						Lobby_Chat_Printf(-1, StringTable::LoadString("GUI:HostGameStartHost", NULL, "C:\\RA2\\wonline.cpp", 12836));
						return(0);
					}
				}
				if (Session.Type == GAME_INTERNET && Online_Session_State == 2) { // RA2: a ladder game needs full and equal teams
					if (g_UserList.length() < (int)g_CurrentChannel.maxUsers) {
						Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_NEED_MORE_PLAYERS", NULL, "C:\\RA2\\wonline.cpp", 12846), g_CurrentChannel.maxUsers);
						return(0);
					}
					int team1 = 0;
					int team2 = 0;
					for (i = 0; i < g_UserList.length(); i++) {
						if (g_UserInfo[i].house == 0) {
							team2++;
						} else {
							team1++;
						}
					}
					if (team1 != team2) {
						Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_NEED_EQUAL_TEAMS", NULL, "C:\\RA2\\wonline.cpp", 12861));
						return(0);
					}
				}
				int limit = Get_Scenario_Slot_Limit(Session.Options.ScenarioIndex);
				int requested = SendDlgItemMessage(window, 0x552, 0x400, 0, 0); // RA2: the computer players
				if (limit < g_UserList.length() + requested) {
					Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_SCENARIO_TOO_SMALL", NULL, "C:\\RA2\\wonline.cpp", 12872), limit);
					return(0);
				}
				MultiplayerGameMode * mode = Session.MPGameMode;
				WideWstring error;
				if (!mode->CheckStartConditions(&error)) {
					Lobby_Chat_Printf(-1, error.get());
					EnableWindow(GetDlgItem(WS_Top_Window(), 0x588), TRUE);
					return(0);
				}
				if (Is_Current_Channel_Flag_8()) { // RA2: a clan game: two squads of equal size
					User * user = NULL;
					unsigned long squad1 = 0;
					unsigned long squad2 = 0;
					int count1 = 0;
					int count2 = 0;
					for (i = 0; i < g_UserList.length(); i++) {
						g_UserList.getPointer(&user, i);
						unsigned long squad = user->squadID;
						if (squad < 1) {
							Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_CLAN_NOSTART", NULL, "C:\\RA2\\wonline.cpp", 12900));
							return(0);
						}
						if (!squad1 || squad1 == squad) {
							squad1 = squad;
							count1++;
						} else {
							if (squad2 && squad2 != squad) {
								Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_CLAN_NOSTART", NULL, "C:\\RA2\\wonline.cpp", 12915));
								return(0);
							}
							squad2 = squad;
							count2++;
						}
					}
					if (count1 != count2) {
						Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_CLAN_NOSTART", NULL, "C:\\RA2\\wonline.cpp", 12921));
						return(0);
					}
				}
				mode->vt_entry_58();
				Session.Assign_Random_Choices();
				Send_Player_List();
				Send_Lobby_Options(true, true);
				mode->vt_entry_54();
				mode->vt_entry_24();
				User * node;
				User * head = NULL;
				User copy;
				memset(&copy, 0, sizeof(copy));
				for (i = 0; i < g_UserList.length(); i++) {
					g_UserList.get(copy, i);
					node = new User;
					*node = copy;
					node->next = head;
					head = node;
				}
				g_pChat->RequestGameStart(head);
				WolOptionsLocked = 1;
				g_GameStartRequested = true;
				node = head;
				while (node) {
					head = node->next;
					delete node;
					node = head;
				}
			}
			return(0);

		case 0x5AA: // RA2: the scenario button
			{
				if (WolOptionsLocked) {
					goto unhandled;
				}
				int old = Session.Options.ScenarioIndex;
				bool skirmish = !Session.MPGameMode || Session.MPGameMode->IsSkirmishAllowed();
				char filename[132]; // level-2 1.001: 132/130 as in gibbo101's YR WOL_Game_Options_Proc; puts description at [esp+0xb8]
				wchar_t description[130];
				strcpy(filename, Session.ScenarioFileName);
				wcscpy(description, Session.Options.ScenarioDescription);
				IsRandomMap = false;
				OwnerDraw::Slide_Dialog(window, false);
				Darken_Surface(NULL, true);
				bool cancelled = Scenario_Dialog(MainWindow) == 2;
				ShowWindow(window, SW_SHOW);
				OwnerDraw::Set_Paint_Disabled(window, 0);
				SetFocus(GetDlgItem(window, 0x540));
				if (cancelled) {
					Session.Options.ScenarioIndex = old;
					Set_Scenario_Info_From_Index(old);
					Update_Preview(window);
					IsRandomMap = true;
					ShowWindow(window, SW_SHOW);
					OwnerDraw::Set_Paint_Disabled(window, 0);
					Load_Random_Map_Preview(window);
					Send_Lobby_Options(true, false);
					InvalidateRect(window, NULL, FALSE);
					return(0);
				}
				if (!Set_Scenario_Info_From_Index(Session.Options.ScenarioIndex)) {
					Session.Options.ScenarioIndex = old;
				} else {
					bool new_skirmish = !Session.MPGameMode || Session.MPGameMode->IsSkirmishAllowed();
					if (skirmish && !new_skirmish) {
						if (Clear_AI_Slots(window)) {
							Session.Options.AIPlayers = 0;
							Send_Player_List();
							Draw_Player_List(0, false);
							Send_Lobby_Options(true, false);
						} else {
							Draw_Player_List(0, true);
						}
					}
					Scenario_Changed(window, old, Session.Options.ScenarioIndex);
					Update_Channel_Player_Limit();
				}
				IsRandomMap = true;
				ShowWindow(window, SW_SHOW);
				OwnerDraw::Set_Paint_Disabled(window, 0);
				Set_Skirmish_Dialog_Text(window);
				if (strcmp(filename, Session.ScenarioFileName) || wcscmp(description, Session.Options.ScenarioDescription)) {
					for (i = 1; i < 4; i++) {
						g_UserInfo[i].accepted = 0;
					}
				}
				Clear_Accept_States();
				Load_Random_Map_Preview(window);
				Refresh_Slot_Settings(window, true);
				Send_Lobby_Options(true, false);
				InvalidateRect(window, NULL, FALSE);
			}
			return(0);

		case 0x411:
		case 0x412:
		case 0x413:
		case 0x414:
		case 0x415:
		case 0x416:
		case 0x417:
		case 0x418: // RA2: the player combo boxes of the slots
			if (HIWORD(wparam) == CBN_SELCHANGE && !WolOptionsLocked && Is_Host()) {
				MPPlayerNode * node = (MPPlayerNode *)Get_Combo_Data(window, LOWORD(wparam), -1);
				Set_Slot_Node(window, LOWORD(wparam), node, 2);
				return(0);
			}
			goto unhandled;

		case 0x522:
		case 0x523:
		case 0x524:
		case 0x525:
		case 0x526:
		case 0x527:
		case 0x528:
		case 0x6A2: // RA2: the color combo boxes
			if (HIWORD(wparam) == CBN_SELCHANGE && !WolOptionsLocked) {
				Slot_Color_Changed(window, LOWORD(wparam));
				Send_Lobby_Options(true, false);
				Refresh_Slot_Settings(window, true);
				break;
			}
			goto unhandled;
		case 0x510:
		case 0x513:
		case 0x514:
		case 0x51E:
		case 0x51F:
		case 0x520:
		case 0x521:
		case 0x6A1: // RA2: the side combo boxes
			if (HIWORD(wparam) == CBN_SELCHANGE && !WolOptionsLocked) {
				Slot_Side_Changed(window, LOWORD(wparam));
				Send_Lobby_Options(true, false);
				Refresh_Slot_Settings(window, true);
				break;
			}
			goto unhandled;
		default:
			return(0);
		}
		goto unhandled;

	case 0x497: // RA2: the dialog is shown
		SendDlgItemMessage(window, 0x3ED, 0x49C, 0, (LPARAM)SurfaceCache.GetSurface("wouact.pcx", NULL));
		SendDlgItemMessage(window, 0x3ED, 0x4AA, 0, (LPARAM)SurfaceCache.GetSurface("wodact.pcx", NULL));
		{
			MultiplayerGameMode * mode = Default_Game_Mode();
			Session.Options.MPModeIndex = mode->MPModeIndex;
			Session.MPGameMode = mode;
			mode->vt_entry_20();
			Set_Item_Text(window, mode);
			Session.Options.ScenarioIndex = mode->FirstValidMapIndex();
			Set_Scenario_Info_From_Index(Session.Options.ScenarioIndex);
		}
		Fill_All_Side_Lists(window);
		Init_Player_Colors();
		Fill_All_Color_Lists(window);
		Select_Player_Side(window, Session.LocalSlot);
		Select_Player_Color(window, Session.LocalSlot);
		Host_Func_5C5350(window, &Session.WOL);
		Scenario_Changed(window, -1, Session.Options.ScenarioIndex);
		Update_Channel_Player_Limit();
		Update_Slot_Icons(window);
		Set_Item_Text(window, Session.MPGameMode);
		Set_Skirmish_Dialog_Text(window);
		Load_Random_Map_Preview(window);
		Update_Preview(window);
		Session.PlayingAgainstVersion = VerNum.Version_Number();
		Refresh_Slot_Settings(window, true);
		SetFocus(GetDlgItem(window, 0x540));
		return(0);

	case WM_HSCROLL:
	case WM_VSCROLL:
		if (WolOptionsLocked) {
			goto unhandled;
		}
		Session.Options.UnitCount = SendDlgItemMessage(window, 0x54F, 0x400, 0, 0);
		Session.Options.Credits = SendDlgItemMessage(window, 0x402, 0x400, 0, 0);
		Session.Options.GameSpeed = 6 - SendDlgItemMessage(window, 0x529, 0x400, 0, 0);
		return(0);

	case 0x49B: // RA2: passes the message on to the control
		{
			HWND control = GetDlgItem(window, wparam);
			SendMessage(control, 0x4B3, 0x7F, lparam);
		}
		return(0);

	case 0x4E9: // RA2: the tool tip text of a combo box item
		{
			WOLToolTipTextRequest * request = (WOLToolTipTextRequest *)lparam;
			WideWstring & text = request->Text;
			text = NULL;
			if (request->Window && request->Item != -1) {
				int id = GetDlgCtrlID(request->Window);
				if (Control_Slot(id) == -1) {
					if (Player_Side_Slot(id) == -1) {
						if (Player_Color_Slot(id) != -1) {
							text = Color_Name(Get_Color_Data(window, id, request->Item));
						}
					} else {
						int side = Get_Side_Data(window, id, request->Item);
						if (side != -1) {
							text = Side_Name(side);
						}
					}
				} else {
					text = Slot_Node_Name((MPPlayerNode *)Get_Combo_Data(window, id, request->Item));
				}
			}
		}
		return(1);

	case 0x4ED: // RA2: hide the dialog
		ShowWindow(window, SW_HIDE);
		OwnerDraw::Set_Paint_Disabled(window, 1);
	unhandled:
		return(0);

	case WM_MOVE:
	case WM_SHOWWINDOW:
		goto unhandled;

	case WM_ERASEBKGND:
		return(1);
	}
	return(0);
}
BOOL CALLBACK WOL_Guest_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x0073E420 (YR WOL_Guest_Dialog_Proc), the dialog (0xC9) of a player that joined a game channel: the chat line, the side and color of the own slot and the accept button
{
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	switch (message) {
	case WM_NCHITTEST: // RA2: the tool tip of the control under the cursor
		{
			HWND tip = GetDlgItem(window, 0x695);
			if (tip) {
				POINT point;
				point.x = lparam & 0xFFFF;
				point.y = (unsigned long)lparam >> 16;
				RECT rect;
				GetWindowRect(window, &rect);
				point.x -= rect.left;
				point.y -= rect.top;
				wchar_t const * text = NullWString;
				HWND control = ChildWindowFromPointEx(window, point, 1);
				if (control) {
					char const * label = OwnerDraw::Control_Tooltip_Label((unsigned int)window, control);
					if (label) {
						text = StringTable::LoadString(label, NULL, "C:\\RA2\\wonline.cpp", 13329);
					}
				}
				SendMessage(tip, 0x4B2, 0, (LPARAM)text);
				return(0);
			}
		}
		break;

	case WM_DESTROY:
		if (Progress.Has_Dialog()) {
			Progress.Clear_Dialog();
		}
		if (MultiplayerMapPreview) {
			delete MultiplayerMapPreview;
			MultiplayerMapPreview = NULL;
			return(0);
		}
		break;

	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		if (MultiplayerMapPreview) {
			MultiplayerMapPreview->Blit_Preview(window);
		}
		if (Progress.Has_Dialog()) {
			Progress.Display_Progress(Point2D(-1, -1));
		}
		ValidateRect(window, NULL);
		return(0);

	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);

	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x3ED: // RA2: the action button
			{
				HWND edit = GetDlgItem(window, 0x540);
				WideWstring text = Limit_Name_Text(edit);
				SendMessage(edit, 0x4B2, 0, (LPARAM)NullWString);
				SetFocus(edit);
				InvalidateRect(edit, NULL, FALSE);
				COLORREF color = ColorAction;
				if (strlen((char *)g_CurrentChannel.name) == 0) {
					Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_NOT_IN_CHAN", NULL, "C:\\RA2\\wonline.cpp", 13523));
				} else if (text.length() > 0) {
					if (Send_Chat_Action(text)) {
						color = ColorPrivAction;
					}
					Lobby_Chat_Printf(color, L"%hs %s", g_NickName, text.get());
				} else {
					Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_ENTER_MESSAGE", NULL, "C:\\RA2\\wonline.cpp", 13531));
				}
			}
			return(0);

		case 0x540: // RA2: the chat line
			{
				HWND edit = (HWND)lparam;
				WideWstring text = Limit_Name_Text(edit);
				if (HIWORD(wparam) == 0x501) {
					SendMessage(edit, 0x4B2, 0, (LPARAM)NullWString);
					if (text.length() > 0) {
						COLORREF color = ColorMe;
						if (Send_Chat_Message(text) == 1) {
							color = ColorPriv;
						}
						Lobby_Chat_Printf(color, L"[%hs] %s", g_NickName, text.get());
					}
				}
			}
			return(0);

		case IDCANCEL:
			if (!WolOptionsLocked && g_pChat->RequestChannelLeave() < 0) {
				WS_Destroy_Dialog(window, 2);
			}
			return(0);

		case 0x59F: // RA2: the accept button
			{
				Session.Players[0]->Slot.Unknown77 = 1;
				char text[64];
				sprintf(text, "A1");
				Send_Public_Game_Options(text);
				Enable_Host_Controls(window, false);
				HWND button = GetDlgItem(window, 0x59F);
				EnableWindow(button, FALSE);
				InvalidateRect(button, NULL, FALSE);
				SendMessage(button, 0x4DC, 0, 0);
				Draw_Player_List(0, false);
				SetFocus(GetDlgItem(window, 0x540));
			}
			return(0);

		case 0x510:
		case 0x513:
		case 0x514:
		case 0x51E:
		case 0x51F:
		case 0x520:
		case 0x521:
		case 0x522:
		case 0x523:
		case 0x524:
		case 0x525:
		case 0x526:
		case 0x527:
		case 0x528:
		case 0x6A1:
		case 0x6A2:
			if (HIWORD(wparam) == CBN_SELCHANGE) {
				int id = LOWORD(wparam);
				int side_player = Player_Side_Slot(id);
				int color_player = Player_Color_Slot(id);
				int player = side_player > color_player ? side_player : color_player;
				int side_id = Player_Side_ID(player);
				int color_id = Player_Color_ID(player);
				if (player == side_player) {
					Slot_Side_Changed(window, side_id);
				} else {
					Slot_Color_Changed(window, color_id);
				}
				char text[64];
				int side = Get_Side_Data(window, side_id, -1);
				int color = Get_Color_Data(window, color_id, -1);
				sprintf(text, "R%d,%d", side, color);
				Wstring host = Wstring_Narrow(Session.GameName);
				Send_Private_Game_Options(host.get(), text);
			}
			return(0);
		}
		break;

	case 0x4ED: // RA2: hide the dialog
		ShowWindow(window, SW_HIDE);
		OwnerDraw::Set_Paint_Disabled(window, 1);
		return(0);

	case 0x4E9: // RA2: the tool tip text of a combo box item
		{
			WOLToolTipTextRequest * request = (WOLToolTipTextRequest *)lparam;
			request->Text = NULL;
			if (request->Window && request->Item != -1) {
				int id = GetDlgCtrlID(request->Window);
				if (Control_Slot(id) == -1) {
					if (Player_Side_Slot(id) == -1) {
						if (Player_Color_Slot(id) != -1) {
							request->Text = Color_Name(Get_Color_Data(window, id, request->Item));
							return(1);
						}
					} else {
						int side = Get_Side_Data(window, id, request->Item);
						if (side != -1) {
							request->Text = Side_Name(side);
							return(1);
						}
					}
				} else {
					request->Text = Slot_Node_Name((MPPlayerNode *)Get_Combo_Data(window, id, request->Item));
				}
			}
		}
		return(1);

	case 0x497: // RA2: the dialog is shown
		SetFocus(GetDlgItem(window, 0x540));
		SendDlgItemMessage(window, 0x3ED, 0x49C, 0, (LPARAM)SurfaceCache.GetSurface("wouact.pcx", NULL));
		SendDlgItemMessage(window, 0x3ED, 0x4AA, 0, (LPARAM)SurfaceCache.GetSurface("wodact.pcx", NULL));
		{
			MultiplayerGameMode * mode = Default_Game_Mode();
			Session.Options.MPModeIndex = mode->MPModeIndex;
			Set_Item_Text(window, mode);
			Session.Options.ScenarioIndex = mode->FirstValidMapIndex();
			Set_Scenario_Info_From_Index(Session.Options.ScenarioIndex);
		}
		Fill_All_Side_Lists(window);
		Init_Player_Colors();
		Fill_All_Color_Lists(window);
		Set_Scenario_Info_From_Index(-1);
		Flag_A5A8BE = false;
		Session.ScenarioMaxPlayers = 8;
		Set_Skirmish_Dialog_Text(window);
		Update_Preview(window);
		Fill_Options_Dialog(window, 1);
		Draw_Player_List(0, false);
		break;
	}
	return(0);
}


// level-2 1.001 (wol_p, 2026-11-22): CChatEventSink handlers OnChannelList (slot 5), the locale/team handlers (slots 30..33) and OnBuddyList (slot 35).
// The locale/team bodies follow gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later; FUN_007AB8E0..FUN_007ABFA0, FUN_007AA870, FUN_007AC220) and the wol_c proposal, checked against RA2 1.001 bytes.
// Requires the edits in edits.py: the explicit Dictionary<Wstring, int>::add/remove specializations (auto_inline off) are removed, so the template members are expandable here as in 1.001.


STDMETHODIMP CChatEventSink::OnUserLocale(HRESULT res, User *users) // level-2 1.001: 0x007512A0, the locales of users from the server go into the locale dictionary; the persona's own locale is also stored in its profile and ends the locale wait
{
	bool found = false;
	if (res < 0) {
		DebugString("OnUserLocale callback failed!\n");
		return(S_OK);
	}
	User * user = users;
	while (user != NULL) {
		Wstring name;
		name.set((char *)user->name);
		name.toLower();
		g_UserLocales.remove(name); // level-2 1.001: the one-argument remove (its inner remove(key, value) 0x00753680 stays out of line, add is expanded)
		int locale = user->locale;
		g_UserLocales.add(name, locale);
		if (stricmp((char *)users->name, g_NickName.get()) == 0) {
			WOLOptionsClass options;
			options.Load();
			rc_ptr<PlayerProfile> profile;
			if (options.Is_Bit1_Clear()) {
				profile = PlayerProfile::Load(g_NickName);
			} else {
				profile = g_PlayerProfile.Get();
			}
			profile->SetLocale(users->locale, 2);
			if (options.Is_Bit1_Clear()) {
				profile->Save(&g_NickName);
			}
			DebugString("OnUserLocale callback - Locale is %d\n", users->locale);
			found = true;
		}
		user = user->next;
	}
	if (found) {
		SetEvent(g_WaitEventHandles[EV_LOCALE]);
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnSetLocale(HRESULT res, Locale newlocale) // level-2 1.001: 0x007514B0, the server confirmed the persona's new locale: it replaces the entry in the locale dictionary (contains, remove and add all expanded)
{
	Wstring name;
	char handle[64];
	strcpy(handle, Session.Handle);
	name.set(handle);
	name.toLower();
	if (g_UserLocales.contains(name)) {
		g_UserLocales.remove(name);
	}
	int locale = newlocale;
	g_UserLocales.add(name, locale);
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnUserTeam(HRESULT res, User *users) // level-2 1.001: 0x00751700, the tournament teams of users go into the team dictionary, then the player list is redrawn
{
	if (res >= 0) {
		User * user = users;
		Wstring name;
		while (user != NULL) {
			name.set((char *)user->name);
			if (g_WDTTeams.contains(name)) {
				g_WDTTeams.remove(name);
			}
			int team = user->team;
			g_WDTTeams.add(name, team);
			user = user->next;
		}
		Draw_Player_List(0, false);
		return(S_OK);
	}
	DebugString("OnUserTeam FAILED!\n");
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnSetTeam(HRESULT res, int newteam) // level-2 1.001: 0x00751960, the server confirmed the persona's new team: the session house and the team dictionary entry are replaced
{
	if (res == 0) {
		Session.House = newteam;
		Wstring name;
		char handle[64];
		strcpy(handle, Session.Handle);
		name.set(handle);
		name.toLower();
		if (g_WDTTeams.contains(name)) {
			g_WDTTeams.remove(name);
		}
		g_WDTTeams.add(name, newteam);
		return(S_OK);
	}
	DebugString("OnSetTeam FAILED: %d\n", newteam);
	return(S_OK);
}
STDMETHODIMP CChatEventSink::OnBuddyList(HRESULT res, User *buddyList) // level-2 1.001: 0x00751BE0, slot 35 of IChatEvent: the buddies of the persona from the server go into the buddy lists, then the ladders of the buddies are asked for and the buddy dialog (0x116) is refilled
{
	if (res >= 0) {
		for (User * user = buddyList; user != NULL; user = user->next) {
			Wstring name((char *)user->name);
			Add_Buddy_Name(name);
		}
		Request_Buddy_Ladders();
		Close_Wait_Window(0x200);
		HWND list = WS_Find_Dialog(0x116);
		if (list != NULL) {
			Fill_Buddy_List(list);
			SendMessageA(list, 0x4A9, 0, 1);
			KillTimer(list, 0x704);
			EnableWindow(GetDlgItem(list, 0x704), TRUE);
		}
	}
	return(S_OK);
}

STDMETHODIMP CChatEventSink::OnChannelList(HRESULT res, Channel *channels) // level-2 1.001: 0x00750830, the chat (type 0) and game channels from the server: the lists are rebuilt, the owners of the game channels are queued for their team and locale and asked for at the ladder server in batches of 20, then the lobby or the game list is refreshed
{
	Wstring name;
	int counter = 0;
	char keys[512 + 1];
	memset(keys, 0, sizeof(keys));
	if (g_PlayingNetGame) {
		return(S_OK);
	}
	unsigned int type = 0;
	if (res == 0x4013B) { // level-2 1.001: the answer to a ping refresh of the game list
		type = 0x21;
	} else {
		g_ChanListQueue.removeHead(type);
		if (res < 0) {
			return(S_OK);
		}
	}
	g_UserChannels.clear(); // level-2 1.001: both lists are cleared for every answer
	g_GameChannelList.clear();
	while (channels != NULL) {
		if (channels->type == 0) {
			g_UserChannels.addTail(*channels);
		} else {
			g_GameChannelList.addTail(*channels);
			name.set((char *)channels->name);
			name.truncate('\'');
			name.toLower();
			if (Session.Type == GAME_INTERNET && Online_Session_State == 2) {
				Wstring temp;
				bool found = false;
				for (int i = 0; i < g_WDTTeamLookupQueue.length(); i++) {
					g_WDTTeamLookupQueue.get(temp, i);
					if (temp == name) {
						found = true;
						break;
					}
				}
				if (!found) {
					g_WDTTeamLookupQueue.addHead(name);
				}
			}
			if (!g_UserLocales.contains(name)) {
				Wstring temp;
				bool found = false;
				for (int i = 0; i < g_UserLocaleLookupQueue.length(); i++) {
					g_UserLocaleLookupQueue.get(temp, i);
					if (temp == name) {
						found = true;
						break;
					}
				}
				if (!found) {
					g_UserLocaleLookupQueue.addHead(name);
				}
			}
			if (!g_ActiveLadder->contains(name)) {
				strcat(keys, name.get());
				strcat(keys, ":");
				counter++;
			}
		}
		if (counter > 20) {
			g_pNetUtil->RequestLadderList(g_LadderAddress, g_LadderPort, keys, g_GameSKU & 0xFFFF00, -1, 0, 0);
			counter = 0;
			memset(keys, 0, sizeof(keys) - 1);
		}
		channels = channels->next;
	}
	if (counter != 0) {
		g_pNetUtil->RequestLadderList(g_LadderAddress, g_LadderPort, keys, g_GameSKU & 0xFFFF00, -1, 0, 0);
		memset(keys, 0, sizeof(keys) - 1);
	}
	SetEvent(g_WaitEventHandles[EV_CHAN_LIST]);
	if (Is_Tournament_Session()) {
		DebugString("Received channel list, user list is %d long\n", g_UserList.length());
	} else if (type == 0) {
		Refresh_Lobby_List();
		HWND lobby = WS_Find_Dialog(0x113);
		if (lobby != NULL) {
			KillTimer(lobby, 0x55D);
			EnableWindow(GetDlgItem(lobby, 0x55D), TRUE);
		}
	} else {
		Refresh_Game_List();
	}
	return(S_OK);
}


// ---- level-2 1.001 (wol_r): the chat lobby dialog 0x0073A680 ----
extern int g_LastJoinRow_7E6BA8; // level-2 1.001: 0x007E6BA8 (-1), provisional name: the game list entry the join button tested last; Can_Join_Channel prints its reason only for a different entry
extern int g_LastGameRow_7E6BAC; // level-2 1.001: 0x007E6BAC (-1), provisional name: the game list entry selected last, used the same way

BOOL CALLBACK Wonline_Chat_Lobby_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // level-2 1.001: 0x0073A680, the chat lobby dialog (0x113): the chat line and its action button, the lobby list, the game list with its new game and join buttons, the options, the squad message, the buddy and ladder buttons and the refresh of the channel list (provisional name)
{
	User user;
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	switch (message) {
	case WM_DESTROY:
		KillTimer(window, 0);
		KillTimer(window, 0x55D);
		return(0);

	case WM_SETFOCUS: // RA2: the focus goes to the chat line
		SetFocus(GetDlgItem(window, 0x540));
		break;

	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(0);

	case WM_ERASEBKGND:
		return(1);

	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(1);

	case WM_SHOWWINDOW: // level-2 1.001: an empty case; the executable's jump table runs up to it (2..0x18), which also decides the compare tree
		return(0);

	case WM_TIMER:
		switch (wparam) {
		case 0x55D: // RA2: the refresh button is enabled again
			KillTimer(window, wparam);
			EnableWindow(GetDlgItem(window, wparam), TRUE);
			return(0);
		case 0: // RA2: the channel list is refreshed every 30 seconds while the lobby is on top
			if (WS_Top_Window() == window) {
				Get_Channel_List(0x21, true);
				return(0);
			}
			break;
		}
		break;

	case WM_COMMAND:
		switch (LOWORD(wparam)) {
		case 0x53D: // RA2: the lobby list: a newly selected lobby is joined
			{
				HWND list = (HWND)lparam;
				int row = SendMessage(list, LB_GETCURSEL, 0, 0);
				if (row != -1) {
					int lobby = SendMessage(list, LB_GETITEMDATA, row, 0);
					if (HIWORD(wparam) == LBN_SELCHANGE && lobby != -1) {
						Channel channel;
						if (g_UserChannels.get(channel, lobby) && strcmp((char *)channel.name, (char *)g_CurrentChannel.name) != 0 && strcmp((char *)channel.name, (char *)g_PendingChannel.name) != 0) {
							g_JoinLobbyNow = 1;
							g_LobbyNumber = lobby;
							SetEvent(g_WaitEventHandles[EV_NETIGNORE]);
							return(0);
						}
					}
				}
			}
			break;

		case 0x53E: // RA2: the user list (level-2 1.001: an empty case; its compare survives as a dead `dec eax` and it decides the compare tree)
			return(0);

		case 0x3ED: // RA2: the action button
			{
				HWND edit = GetDlgItem(window, 0x540);
				WideWstring text = Limit_Name_Text(edit);
				SendMessage(edit, 0x4B2, 0, (LPARAM)NullWString);
				SetFocus(edit);
				InvalidateRect(edit, NULL, FALSE);
				COLORREF color = ColorAction;
				if (strlen((char *)g_CurrentChannel.name) == 0) {
					Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_NOT_IN_CHAN", NULL, "C:\\RA2\\wonline.cpp", 9708));
				} else if (text.length() > 0) {
					if (Send_Chat_Action(text)) {
						color = ColorPrivAction;
					}
					Lobby_Chat_Printf(color, L"%hs %s", g_NickName, text.get());
				} else {
					Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_ENTER_MESSAGE", NULL, "C:\\RA2\\wonline.cpp", 9716));
				}
			}
			return(0);

		case 0x540: // RA2: the chat line
			{
				HWND edit = GetDlgItem(window, 0x540);
				WideWstring text = Limit_Name_Text(edit);
				if (HIWORD(wparam) == 0x501) {
					SendMessage(edit, 0x4B2, 0, (LPARAM)NullWString);
					if (text.length() > 0) {
						if (strlen((char *)g_CurrentChannel.name) == 0) {
							Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_NOT_IN_CHAN", NULL, "C:\\RA2\\wonline.cpp", 9683));
							return(0);
						}
						COLORREF color = ColorMe;
						if (Send_Chat_Message(text) == 1) {
							color = ColorPriv;
						}
						Lobby_Chat_Printf(color, L"[%hs] %s", g_NickName, text.get());
					}
				}
			}
			return(0);

		case 0x55D: // RA2: the refresh button: off for three seconds
			EnableWindow((HWND)lparam, FALSE);
			SetTimer(window, 0x55D, 3000, NULL);
			Get_Channel_List(0x21, true);
			return(0);

		case 0x547:
		case 0x5C0:
		case 0x686:
			OwnerDraw::Set_Dialog_Waiting(window);
			SetEvent(g_WaitEventHandles[EV_EXIT]);
			return(0);

		case 0x689:
			Online_Session_State = 4;
			Online_Session_Return = 3;
			OwnerDraw::Set_Dialog_Waiting(window);
			SetEvent(g_WaitEventHandles[EV_EXIT]);
			return(0);

		case 0x61F: // RA2: the options dialog (0x2BC)
			{
				OwnerDraw::Slide_Dialog(window, false);
				Darken_Surface(NULL, true);
				HWND dialog = OwnerDraw::Begin_Dialog(0x2BC, (DLGPROC)WOL_Options_Dialog_Proc, 0);
				ShowWindow(dialog, SW_SHOWNORMAL);
				int answer = WS_Wait_Dialog(dialog, Wait_Callback_Thunk, false, true, true);
				InvalidateRect(window, NULL, FALSE);
				ShowWindow(window, SW_SHOW);
				OwnerDraw::Set_Paint_Disabled(window, 0);
				if (answer == 2) { // level-2 1.001: the settings are applied as in Apply_WOL_Settings, written out here (the executable has both copies inline)
					if (g_pChat) {
						g_pChat->SetLangFilter(g_LangFilter);
						g_pChat->SetFindPage(g_AllowFind, g_AllowPage);
					}
					bool music = g_LobbyMusic != 0;
					if (music && !Theme.Still_Playing()) {
						Theme.Stop();
						Theme.Queue_Song((ThemeType)-2);
					} else if (music) {
						if (Theme.What_Is_Playing() == Theme.From_Name("INTRO")) {
							Theme.Stop();
							Theme.Queue_Song((ThemeType)-2);
						}
					} else if (!music) {
						Theme.Queue_Song((ThemeType)-3);
					}
				} else {
					g_AllowPage = g_NewAllowPage;
					g_AllowFind = g_NewAllowFind;
					g_LangFilter = g_NewLangFilter;
					g_LobbyMusic = g_NewLobbyMusic;
					g_ShowAllChannels = g_NewShowAllChannels;
					Write_WOL_Settings();
					if (g_pChat) {
						g_pChat->SetLangFilter(g_LangFilter);
						g_pChat->SetFindPage(g_AllowFind, g_AllowPage);
					}
					bool music = g_LobbyMusic != 0;
					if (music && !Theme.Still_Playing()) {
						Theme.Stop();
						Theme.Queue_Song((ThemeType)-2);
					} else if (music) {
						if (Theme.What_Is_Playing() == Theme.From_Name("INTRO")) {
							Theme.Stop();
							Theme.Queue_Song((ThemeType)-2);
						}
					} else if (!music) {
						Theme.Queue_Song((ThemeType)-3);
					}
				}
			}
			SetFocus(GetDlgItem(window, 0x540));
			break;

		case 0x558: // RA2: the tournaments page (level-2 1.001: after the options case in the source, so that its focus tail is the one the other cases jump into)
			ViewHTML("http://www.westwood.com/westwoodonline/tournaments/redalert2/", 0);
			SetFocus(GetDlgItem(window, 0x540));
			break;

		case 0x62D: // RA2: the join button
			{
				HWND list = GetDlgItem(window, 0x6EE);
				int row = SendMessage(list, LB_GETCURSEL, 0, 0);
				bool ok = false;
				int index = -1;
				if (row != -1) {
					index = SendMessage(list, LB_GETITEMDATA, row, 0);
					if (index >= 0 && index < g_GameChannelList.length()) {
						Channel channel;
						memset(&channel, 0, sizeof(channel));
						g_GameChannelList.get(channel, index);
						ok = Can_Join_Channel(&channel, index != g_LastJoinRow_7E6BA8);
						if (ok) {
							EnableWindow(GetDlgItem(window, 0x62B), FALSE);
							EnableWindow(GetDlgItem(window, 0x62D), FALSE);
							SendMessage(GetDlgItem(window, 0x6EE), LB_SETCURSEL, -1, 0);
							EnableWindow(GetDlgItem(window, 0x689), FALSE);
							EnableWindow(GetDlgItem(window, 0x558), FALSE);
							EnableWindow(GetDlgItem(window, 0x61F), FALSE);
							EnableWindow(GetDlgItem(window, 0x686), FALSE);
							bool joined = Join_Game_Channel(&channel);
							EnableWindow(GetDlgItem(window, 0x62B), TRUE);
							EnableWindow(GetDlgItem(window, 0x689), TRUE);
							EnableWindow(GetDlgItem(window, 0x558), TRUE);
							EnableWindow(GetDlgItem(window, 0x61F), TRUE);
							EnableWindow(GetDlgItem(window, 0x686), TRUE);
							if (joined) {
								OwnerDraw::Slide_Dialog(window, false);
								Darken_Surface(NULL, true);
								ShowWindow(window, SW_HIDE);
								OwnerDraw::Set_Paint_Disabled(window, 1);
							}
						}
					}
				}
				g_LastJoinRow_7E6BA8 = index;
				EnableWindow((HWND)lparam, ok);
			}
			SetFocus(GetDlgItem(window, 0x540));
			return(0);

		case 0x62B: // RA2: the new game button
			{
				EnableWindow((HWND)lparam, FALSE);
				EnableWindow(GetDlgItem(window, 0x62D), FALSE);
				SendMessage(GetDlgItem(window, 0x6EE), LB_SETCURSEL, -1, 0);
				EnableWindow(GetDlgItem(window, 0x689), FALSE);
				EnableWindow(GetDlgItem(window, 0x558), FALSE);
				EnableWindow(GetDlgItem(window, 0x61F), FALSE);
				EnableWindow(GetDlgItem(window, 0x686), FALSE);
				bool created = Create_Game_Channel();
				EnableWindow((HWND)lparam, TRUE);
				EnableWindow(GetDlgItem(window, 0x689), TRUE);
				EnableWindow(GetDlgItem(window, 0x558), TRUE);
				EnableWindow(GetDlgItem(window, 0x61F), TRUE);
				EnableWindow(GetDlgItem(window, 0x686), TRUE);
				if (!created) {
					SetFocus(GetDlgItem(window, 0x540));
					return(0);
				}
			}
			break;

		case 0x6EE: // RA2: the game list: a double click joins the game
			{
				bool join = false;
				switch (HIWORD(wparam)) {
				case LBN_SELCHANGE:
					break;
				case LBN_DBLCLK:
					join = true;
					break;
				default:
					return(0);
				}
				int row = SendMessage((HWND)lparam, LB_GETCURSEL, 0, 0);
				int index = -1;
				bool ok = false;
				if (row != -1) {
					index = SendMessage((HWND)lparam, LB_GETITEMDATA, row, 0);
					if (index >= 0 && index < g_GameChannelList.length()) {
						Channel channel;
						memset(&channel, 0, sizeof(channel));
						g_GameChannelList.get(channel, index);
						ok = Can_Join_Channel(&channel, join || g_LastGameRow_7E6BAC != index);
						if (ok && join) {
							EnableWindow(GetDlgItem(window, 0x62B), FALSE);
							EnableWindow(GetDlgItem(window, 0x62D), FALSE);
							SendMessage(GetDlgItem(window, 0x6EE), LB_SETCURSEL, -1, 0);
							EnableWindow(GetDlgItem(window, 0x689), FALSE);
							EnableWindow(GetDlgItem(window, 0x558), FALSE);
							EnableWindow(GetDlgItem(window, 0x61F), FALSE);
							EnableWindow(GetDlgItem(window, 0x686), FALSE);
							if (Join_Game_Channel(&channel)) {
								OwnerDraw::Slide_Dialog(window, false);
								Darken_Surface(NULL, true);
								ShowWindow(window, SW_HIDE);
								OwnerDraw::Set_Paint_Disabled(window, 1);
							}
							EnableWindow(GetDlgItem(window, 0x62B), TRUE);
							EnableWindow(GetDlgItem(window, 0x689), TRUE);
							EnableWindow(GetDlgItem(window, 0x558), TRUE);
							EnableWindow(GetDlgItem(window, 0x61F), TRUE);
							EnableWindow(GetDlgItem(window, 0x686), TRUE);
						}
					}
				}
				g_LastGameRow_7E6BAC = index;
				HWND button = GetDlgItem(window, 0x62D);
				EnableWindow(button, ok);
			}
			return(0);

		case 0x608: // RA2: the squad message: the name "0" pages the own squad
			{
				WideWstring text;
				HWND edit = GetDlgItem(window, 0x540);
				Get_Control_Wide_Text(edit, text);
				SendMessage(edit, 0x4B2, 0, (LPARAM)NullWString);
				SetFocus(edit);
				if (g_OwnSquadID) {
					memset(&user, 0, sizeof(user));
					strcpy((char *)user.name, "0");
					g_pChat->RequestPrivateMessageWide(&user, text.get());
				} else {
					Lobby_Chat_Printf(-1, StringTable::LoadString("TXT_NOSQUAD", NULL, "C:\\RA2\\wonline.cpp", 9742));
				}
			}
			return(0);
		}
		break;

	case 0x497: // RA2: the dialog is shown: the button images, the list columns and the lists
		SendDlgItemMessage(window, 0x3ED, 0x49C, 0, (LPARAM)SurfaceCache.GetSurface("wouact.pcx", NULL));
		SendDlgItemMessage(window, 0x3ED, 0x4AA, 0, (LPARAM)SurfaceCache.GetSurface("wodact.pcx", NULL));
		SendDlgItemMessage(window, 0x55D, 0x49C, 0, (LPARAM)SurfaceCache.GetSurface("wouref.pcx", NULL));
		SendDlgItemMessage(window, 0x55D, 0x4AA, 0, (LPARAM)SurfaceCache.GetSurface("wodref.pcx", NULL));
		g_Col_GameIcon = 2;
		g_Col_GamePrivate = 0x13;
		g_Col_GameObserver = 0x24;
		g_Col_GameName = 0x35;
		g_Col_GamePingTime = 0xC8;
		SendDlgItemMessage(window, 0x6EE, 0x4A6, 0x93, g_Col_GameName);
		SendDlgItemMessage(window, 0x6EE, 0x4A6, 0, g_Col_GameIcon);
		SendDlgItemMessage(window, 0x6EE, 0x4A6, 0, g_Col_GamePrivate);
		SendDlgItemMessage(window, 0x6EE, 0x4A6, 0, g_Col_GamePingTime);
		SendDlgItemMessage(window, 0x6EE, 0x4A6, 0, g_Col_GameObserver);
		g_Col_ChanName = 2;
		SendDlgItemMessage(window, 0x53D, 0x4A6, 0, g_Col_ChanName);
		g_Col_Chanop = 2;
		g_Col_Username = 0x12;
		g_Col_Rank = 0x85;
		SendDlgItemMessage(window, 0x53E, 0x4A6, 0x73, g_Col_Username);
		SendDlgItemMessage(window, 0x53E, 0x4A6, 0, g_Col_Chanop);
		SendDlgItemMessage(window, 0x53E, 0x4A6, 0, g_Col_Rank);
		Refresh_Lobby_List();
		Refresh_Game_List();
		Draw_Player_List(0, false);
		SetFocus(GetDlgItem(window, 0x540));
		SetTimer(window, 0, 30000, NULL);
		return(0);

	case 0x4ED: // RA2: hide the dialog
		ShowWindow(window, SW_HIDE);
		OwnerDraw::Set_Paint_Disabled(window, 1);
		return(0);

	case 0x4E9: // RA2: the tool tip text of a list row
		{
			WOLToolTipTextRequest * request = (WOLToolTipTextRequest *)lparam;
			if (request) {
				switch (GetDlgCtrlID(request->Window)) {
				case 0x6EE:
					request->Text = Game_List_Tooltip(request->Window, request->Item);
					return(0);
				case 0x53E:
					request->Text = User_List_Tooltip(request->Window, request->Item);
					break;
				}
			}
		}
		break;
	}
	return(0);
}



STDMETHODIMP CChatEventSink::OnPublicGameOptions(HRESULT res, Channel *channel, User *user, LPCSTR options) // level-2 1.001: 0x0074F1A0, the public options of a game channel: they are decoded into the session; a guest of a tournament game accepts at once, a guest of a normal game asks the host for the map preview of a changed or missing random map (structure after gibbo101's YR 0x007A7EA0: nested ifs and the isnew-driven request at the end, which gives 1.001's shared exit after Poke_The_Host)
{
	static BasicTimerClass<SystemTimerClass> timer; // level-2 1.001: how long the preview is awaited (guard 0x00B10880, object 0x00B10888; its destructor is the empty atexit entry 0x00751E90)
	if (g_PlayingNetGame || WolOptionsLocked || res < 0) {
		return(S_OK);
	}
	char * buffer = strdup(options);
	bool scenario_changed = Net2DecodeGameopt(buffer, (char *)user->name);
	free(buffer);
	bool isnew = false;
	if (Local_User_Is_Channel_Owner()) { // level-2 1.001: the host ignores its own options
		return(S_OK);
	}
	if (Is_Tournament_Session()) {
		WideWstring nickname = Wstring_ToWide(g_NickName);
		NodeNameType * local = Find_Lobby_Name(nickname.get());
		if (local == NULL) {
			return(S_OK);
		}
		if (local->Get_Country() < 0 || local->Get_Color() < 0) {
			return(S_OK);
		}
		if (options[0] < '0' || options[0] > '9') {
			return(S_OK);
		}
		if (g_UserList.length() == 2) {
			g_pChat->RequestPublicGameOptions("A1");
		}
		return(S_OK);
	}
	HWND dialog = WS_Top_Window();
	HWND item = GetDlgItem(dialog, 0x71F);
	if (item != NULL) {
		ShowWindow(item, SW_HIDE);
	}
	ShowWindow(GetDlgItem(dialog, 0x468), SW_SHOWNORMAL);
	if (MultiplayerMapPreview == NULL) {
		if (Session.Is_Random_Map()) {
			if (scenario_changed) {
				isnew = true;
				timer = 0;
			}
			if (timer > 900 && (MultiplayerMapPreview == NULL || !MultiplayerMapPreview->Get_Preview_Surface()) && !g_ReceivingHostPreview) {
				isnew = true;
			}
		} else {
			bool exists = false;
			if (Find_Local_Scenario(Session.ScenarioFileName, Session.ScenarioFileLength, Session.ScenarioDigest, Session.ScenarioIsOfficial, false)) {
				{
					RawFileClass file(Session.ScenarioFileName);
					if (file.Is_Available()) {
						exists = true;
					}
				}
				if (!exists) {
					goto update_dialog;
				}
			}
			if (Is_Current_Channel_Tournament() && Session.Players[0]->Slot.Unknown77) {
				Session.Players[0]->Slot.Unknown77 = 0;
				Send_Public_Game_Options("A0");
				EnableWindow(GetDlgItem(dialog, 0x59F), FALSE);
			}
update_dialog:
			if (WS_Top_Window_ID() == 0xC9) {
				InvalidateRect(WS_Top_Window(), NULL, FALSE);
			}
		}
	}
	if (isnew) {
		char text[64];
		sprintf(text, "P%s", Session.ScenarioFileName);
		User host;
		g_UserList.getHead(host);
		g_pChat->RequestPrivateGameOptions(&host, text);
		DebugString("Sent private game option packet requesting a preview download\n");
		Poke_The_Host();
		return(S_OK);
	}
	return(S_OK);
}

static inline Wstring User_Name(User const * user) // level-2 1.001: the name of a user as a Wstring; returned by value, so the callers address the temporary through its frame slot (lea) as 0x0074F4E0 does
{
	return(Wstring((char *)user->name));
}

STDMETHODIMP CChatEventSink::OnPrivateGameOptions(HRESULT res, User *user, LPCSTR options) // level-2 1.001: 0x0074F4E0, the host of a game channel takes a guest's private options: "R" carries the guest's new side and color, "P" asks for the map preview of a random map
{
	if (g_PlayingNetGame || WolOptionsLocked || g_IsChannelCreator != 1 || Online_Session_State == 2 || Online_Session_State == 1) {
		return(S_OK);
	}
	if (Player_Name_To_Index(User_Name(user)) == -1) { // level-2 1.001: only users of the channel are heard
		return(S_OK);
	}
	switch (options[0]) {
		case 'R':
		{
			char * buffer = strdup(options + 1);
			int found = -1;
			for (int index = 0; index < 8; ++index) {
				Wstring name = Wstring_Narrow(Session.Slots[index]->Name); // level-2 1.001: a named local (its destructor is on both paths of the test)
				if (!stricmp(name.get(), (char *)user->name)) {
					found = index;
					break;
				}
			}
			if (found != -1) {
				char * token = strtok(buffer, ",");
				int side = 0;
				if (token) side = atol(token);
				token = strtok(NULL, ",");
				int color = 0;
				if (token) color = atol(token);
				HWND window = WS_Find_Dialog(0xC2); // level-2 1.001: the dialog is looked up but not used (no observer handling, as in Assign_House_And_Color)
				if (!window) window = WS_Find_Dialog(0xC9);
				int country = Session.Slots[found]->Get_Country();
				bool side_changed = country != side;
				if (Session.MPGameMode && !Session.MPGameMode->IsCountryAllowed(side)) {
					side = Session.MPGameMode->IsCountryAllowed(country) ? country : -2;
					side_changed = true;
				}
				if (side_changed) Session.Slots[found]->Set_Country(side);
				bool color_changed = Session.Slots[found]->Get_Color() != color;
				if (color_changed) {
					if (Session.Is_Color_Used(color)) color = -2;
					Session.Slots[found]->Set_Color(color);
				}
				if (side_changed || color_changed) {
					Send_Lobby_Options(true, false);
					Draw_Player_List(0, false);
				}
			}
			free(buffer);
			break;
		}

		case 'P':
			DebugString("Received private preview request from channel guest\n");
			if (g_UserList.length() < 2 || !Local_User_Is_Channel_Owner() // level-2 1.001: only the host of a random map with a preview answers
				 || WolOptionsLocked || !g_CurrentChannel.type || !MultiplayerMapPreview || !MultiplayerMapPreview->Get_Preview_Surface() || !IsRandomMap) {
				break;
			}
			int index = Player_Name_To_Index(User_Name(user));
			if (index == -1) {
				break;
			}
			User guest;
			g_UserList.get(guest, index);
			guest.next = NULL;
			User_List_To_Session_Players(&guest);
			int suspend = g_SuspendChatPump; // level-2 1.001: the chat is not pumped while the preview is sent
			g_SuspendChatPump = 1;
			Send_Map_Preview(MultiplayerMapPreview);
			g_SuspendChatPump = suspend;
			break;
	}
	return(S_OK);
}

// level-2 1.001 (wol_u, 2026-11-22): CChatEventSink::OnServerList (vtable 0x79A618 slot 0) and OnChannelJoin (slot 7).
// Bodies adapted from gibbo101/ra2-decomp src/wonline.cpp (YR 1.001, GPL-3.0-or-later, commit f8916323fcb0cbb0df1821530bd65afa7b0df804:
// FUN_007A41C0 and CChatEventSink::OnChannelJoin), checked against the RA2 1.001 bytes. Requires the Compare_Users edit in edits.py.

// level-2 1.001 (F11, 2026-11-22): the handlers of the download sink (IDownloadEvent, vtable slots 3..7 of CDownloadEventSink), in the
// order of the executable (0x752A20..0x752BF0, after the chat and net utility handlers). Structure after gibbo101/ra2-decomp
// src/wonline.cpp (YR 1.001, GPL-3.0-or-later, commit 94adbad041; CDownloadEventSink::OnEnd .. OnQueryResume), with the 1.001 line literals.

extern time_t prev_stat; // level-2 1.001: 0x00B10160, the time of the last progress text (name from gibbo101 YR)

STDMETHODIMP CDownloadEventSink::OnEnd(void) // level-2 1.001: 0x00752A20, tells the download dialog (0xD3) that the file is complete
{
	SendMessage(WS_Top_Window(), 0x5F4, 0, 0);
	return(S_OK);
}

STDMETHODIMP CDownloadEventSink::OnError(int error) // level-2 1.001: 0x00752A40, tells the download dialog that the download failed
{
	SendMessage(WS_Top_Window(), 0x5F5, 0, error);
	return(S_OK);
}

STDMETHODIMP CDownloadEventSink::OnProgressUpdate(int bytesread, int totalsize, int timetaken, int timeleft) // level-2 1.001: 0x00752A60, moves the progress bar (0x5C6) and prints the byte counts, at most once a second
{
	wchar_t buffer[200];

	buffer[0] = 0;
	SendDlgItemMessage(WS_Top_Window(), 0x5C6, PBM_SETPOS, bytesread * 100 / (unsigned)totalsize, 0);
	if (timeleft > 0) {
		swprintf(buffer, StringTable::LoadString("TXT_BYTES_W_TIME", NULL, "C:\\RA2\\wonline.cpp", 3596), bytesread, totalsize, timeleft);
	} else {
		swprintf(buffer, StringTable::LoadString("TXT_BYTES_WO_TIME", NULL, "C:\\RA2\\wonline.cpp", 3601), bytesread, totalsize);
	}
	if (time(NULL) - prev_stat != 0) {
		HWND item = GetDlgItem(WS_Top_Window(), 0x5C8);
		SendMessage(item, 0x4B2, 0, (LPARAM)buffer);
		prev_stat = time(NULL);
	}
	return(S_OK);
}

STDMETHODIMP CDownloadEventSink::OnStatusUpdate(int status) // level-2 1.001: 0x00752B60, prints the state of the download
{
	wchar_t buffer[200];

	buffer[0] = 0;
	switch (status) {
	case 2:
		swprintf(buffer, StringTable::LoadString("TXT_CONNECTING", NULL, "C:\\RA2\\wonline.cpp", 3620));
		break;
	case 4:
		swprintf(buffer, StringTable::LoadString("TXT_FINDING_PATCH", NULL, "C:\\RA2\\wonline.cpp", 3624));
		break;
	}
	HWND item = GetDlgItem(WS_Top_Window(), 0x5C8);
	SendMessage(item, 0x4B2, 0, (LPARAM)buffer);
	return(S_OK);
}

STDMETHODIMP CDownloadEventSink::OnQueryResume(void) // level-2 1.001: 0x00752BF0
{
	return(S_OK);
}

extern char g_GameServerHost[]; // level-2 1.001: 0x00B0FC2C, the host of the first game (GAM) server
extern int g_GameServerPort; // level-2 1.001: 0x00B0E71C, its port (provisional name)
extern char g_GameServerHost2[]; // level-2 1.001: 0x00B0FFC8, the host of the second game (GAM) server (provisional name)
extern int g_GameServerPort2; // level-2 1.001: 0x00B0E704, its port (provisional name)

STDMETHODIMP CChatEventSink::OnServerList(HRESULT res, Server *servers) // level-2 1.001: 0x0074B780, the server list from the server server: the chat (IRC) servers go into g_Servers and one of those for this SKU is picked at random, the ladder (LAD), game (GAM, two) and WDT servers are remembered, then every chat server gets the persona and the password (body after gibbo101 YR FUN_007A41C0, without YR's mangler servers and firewall detection)
{
	Server * tmp = servers;
	Server * server = NULL;
	int chat_server_index = 0;
	int skumatchcount = 0;
	int game_srv_found = 0;
	char namebuf[128];
	char conndata[128];
	char conndata3[128];
	char token[128];
	char conndata2[128];

	srand(time(0));

	if (res < 0) {
		SetEvent(g_WaitEventHandles[EV_ABORT]);
		swprintf(g_LastErrorMessage, StringTable::LoadString("TXT_NO_SERV_LIST", NULL, "C:\\RA2\\wonline.cpp", 3704)); // level-2 1.001: line literal
		return(S_OK);
	}

	while (tmp != NULL) {
		if (strcmp((char *)tmp->connlabel, "IRC") == 0) {
			if (chat_server_index == 0) {
				g_Servers.addTail(*tmp);
				g_CurrentServerIndex = 0;
				chat_server_index = 1;
			} else {
				g_Servers.addTail(*tmp);
				char * nameToken;
				strcpy(namebuf, (char *)tmp->name);
				int sku = -1;
				nameToken = strtok(namebuf, ",");
				while (nameToken != NULL) {
					sku = atol(nameToken);
					if (sku == (unsigned char)g_GameSKU) {
						break;
					}
					if (strchr(nameToken, ':') != NULL) {
						break;
					}
					nameToken = strtok(NULL, ",");
				}
				if (sku == (unsigned char)g_GameSKU) {
					skumatchcount++;
					if (rand() * (1.0 / 32767.0) <= 1.0 / skumatchcount) {
						g_CurrentServerIndex = chat_server_index;
					}
				}
				g_TargetServerIndex = g_CurrentServerIndex;
				chat_server_index++;
			}
		} else if (strcmp((char *)tmp->connlabel, "LAD") == 0) {
			char * host;
			char * port;
			strcpy(token, (char *)tmp->conndata);
			strtok(token, ";");
			host = strtok(NULL, ";");
			if (host != NULL) {
				strcpy(g_LadderAddress, host);
			}
			port = strtok(NULL, ";");
			if (port != NULL) {
				g_LadderPort = atol(port);
			}
		} else if (strcmp((char *)tmp->connlabel, "GAM") == 0 && game_srv_found == 0) {
			char * host;
			char * port;
			memcpy(&g_GameServer, tmp, sizeof(g_GameServer));
			strcpy(conndata, (char *)g_GameServer.conndata);
			strtok(conndata, ";");
			host = strtok(NULL, ";");
			if (host != NULL) {
				strcpy(g_GameServerHost, host);
			}
			port = strtok(NULL, ";");
			if (port != NULL) {
				g_GameServerPort = atol(port);
			}
			g_GameServerHost2[0] = 0;
			g_GameServerPort2 = 0;
			game_srv_found = 1;
		} else if (strcmp((char *)tmp->connlabel, "GAM") == 0 && game_srv_found == 1) {
			char * host;
			char * port;
			memcpy(&g_GameServer, tmp, sizeof(g_GameServer));
			strcpy(conndata3, (char *)g_GameServer.conndata);
			strtok(conndata3, ";");
			host = strtok(NULL, ";");
			if (host != NULL) {
				strcpy(g_GameServerHost2, host);
			}
			port = strtok(NULL, ";");
			if (port != NULL) {
				g_GameServerPort2 = atol(port);
			}
			game_srv_found = 2;
		} else if (strcmp((char *)tmp->connlabel, "WDT") == 0) {
			char * host;
			char * port;
			memcpy(&g_WDTServer, tmp, sizeof(g_WDTServer));
			strcpy(conndata2, (char *)g_WDTServer.conndata);
			strtok(conndata2, ";");
			host = strtok(NULL, ";");
			if (host != NULL) {
				strcpy(g_WDTHost, host);
			}
			port = strtok(NULL, ";");
			if (port != NULL) {
				g_WDTPort = atol(port);
			}
		}
		tmp = tmp->next;
	}

	server = NULL;
	for (int i = 0; i < g_Servers.length(); i++) {
		g_Servers.getPointer(&server, i);
		strcpy((char *)server->login, g_NickName.get());
		strcpy((char *)server->password, g_LoginPassword.get());
	}

	SetEvent(g_WaitEventHandles[EV_GOT_SERVERS]);
	return(S_OK);
}

int __fastcall Add_To_Open_Slot(MPPlayerNode * node); // level-2 1.001: 0x005C2CF0 (src/ra2/netshare.cpp), puts the new player into the first open slot
void __fastcall Handle_Mode_Selection(void); // level-2 1.001: 0x005BE030 (src/m85/src/netshare.cpp)

STDMETHODIMP CChatEventSink::OnChannelJoin(HRESULT res, Channel *channel, User *user) // level-2 1.001: 0x0074CB20, a user (or the persona itself) joined a channel: a failed join is reported and the pending channel forgotten; the persona's own join of a lobby enables the lobby dialog, of a game channel sets up the session and opens the guest dialog (0xC9); another user is queued for its team, locale and ladder, added to the sorted user list and to the slots (by the host); body after gibbo101 YR CChatEventSink::OnChannelJoin, without YR's observers, highscores and mangler code
{
	if (res == 0x8004006C) {
		return(S_OK);
	}
	int i;
	int players;
	wchar_t joinname[64];
	joinname[0] = 0;
	if (channel) {
		Char_To_Wide(joinname, (char *)channel->name, -1);
		if (strncmp((char *)channel->name, "Lob_33_", 7) == 0) {
			int lobby = atol((char *)channel->name + strlen("Lob_33_"));
			int d = lobby / 6; // level-2 1.001: six lobby names
			int m = lobby % 6;
			if (d == 0) {
				swprintf(joinname, L"%s", g_Lobbies[m]);
			} else {
				swprintf(joinname, L"%s %d", g_Lobbies[m], d + 1);
			}
		}
	}
	if (res < 0) {
		if (res == 0x80040070) {
			Channel *chan = NULL;
			for (int channelIndex = 0; channelIndex < g_UserChannels.length(); channelIndex++) {
				g_UserChannels.getPointer(&chan, channelIndex);
				if (strcmp((char *)g_PendingChannel.name, (char *)chan->name) == 0) {
					g_UserChannels.remove(channelIndex);
					break;
				}
			}
			for (int gameIndex = 0; gameIndex < g_GameChannelList.length(); gameIndex++) {
				g_GameChannelList.getPointer(&chan, gameIndex);
				if (strcmp((char *)g_PendingChannel.name, (char *)chan->name) == 0) {
					g_GameChannelList.remove(gameIndex);
					break;
				}
			}
			if (Is_Tournament_Session()) {
				Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_GAME_CLOSED", NULL, "C:\\RA2\\wonline.cpp", 4290)); // level-2 1.001: line literal
				SetEvent(g_WaitEventHandles[EV_ERROR]);
			} else {
				ODMessageBox(StringTable::LoadString("TXT_GAME_CLOSED", NULL, "C:\\RA2\\wonline.cpp", 4293), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
			}
		} else if (res == 0x80040071) {
			if (Is_Tournament_Session()) {
				Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_BADPASS", NULL, "C:\\RA2\\wonline.cpp", 4300)); // level-2 1.001: line literal
				SetEvent(g_WaitEventHandles[EV_ERROR]);
			} else {
				ODMessageBox(StringTable::LoadString("TXT_BADPASS", NULL, "C:\\RA2\\wonline.cpp", 4303), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
			}
		} else if (res == 0x8004006E) {
			if (Is_Tournament_Session()) {
				Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_CHANNEL_FULL", NULL, "C:\\RA2\\wonline.cpp", 4310)); // level-2 1.001: line literal
				SetEvent(g_WaitEventHandles[EV_ERROR]);
			} else {
				ODMessageBox(StringTable::LoadString("TXT_CHANNEL_FULL", NULL, "C:\\RA2\\wonline.cpp", 4313), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
				if (g_PendingChannel.type == 0) {
					SetEvent(g_WaitEventHandles[EV_ERROR]);
				}
			}
		} else if (res == 0x80040072) {
			ODMessageBox(StringTable::LoadString("TXT_JOINBAN", NULL, "C:\\RA2\\wonline.cpp", 4322), 0, Wait_Callback_Thunk, false); // level-2 1.001: line literal
			SetEvent(g_WaitEventHandles[EV_ERROR]);
			g_LobbyNumber++;
		} else {
			Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_CANT_JOINCHAN", NULL, "C:\\RA2\\wonline.cpp", 4329), res); // level-2 1.001: line literal
			SetEvent(g_WaitEventHandles[EV_ERROR]);
		}
		g_IsChannelCreator = 0;
		g_CurrentChannel.name[0] = 0;
		memset(&g_PendingChannel, 0, sizeof(Channel));
		Close_Wait_Window(2);
		g_PendingChannel.name[0] = 0;
		Refresh_Game_List();
		Draw_Player_List(0, false);
		SetEvent(g_WaitEventHandles[EV_CHAN_JOIN_FAIL]);
		g_JoinLobbyNow = (g_PendingChannel.type != 0);
		HWND main = WS_Find_Dialog(0x113);
		if (main) {
			ShowWindow(main, SW_SHOW);
			OwnerDraw::Set_Paint_Disabled(main, 0);
		}
		return(S_OK);
	}

	g_PendingChannel.name[0] = 0;
	if (user->flags & 0x8000) {
		memcpy(&g_CurrentChannel, channel, sizeof(Channel));
		memset(&g_PendingChannel, 0, sizeof(Channel));
		Close_Wait_Window(2);
		g_ChannelCount++;
		DebugString("Joined Channel\n");
		g_LobbyNumber = atol((char *)channel->name + strlen("Lob_33_"));
		if (!Is_Tournament_Session()) {
			Lobby_Chat_Printf(ColorSystem, StringTable::LoadString("TXT_JOINED_S", NULL, "C:\\RA2\\wonline.cpp", 4377), joinname); // level-2 1.001: line literal
		}
		if (channel->type == 0) {
			HWND main = WS_Find_Dialog(0x113);
			if (main) {
				EnableWindow(GetDlgItem(main, 0x53D), TRUE);
				bool join = false;
				HWND list = GetDlgItem(main, 0x6EE);
				int index = SendMessage(list, LB_GETCURSEL, 0, 0);
				if (index != LB_ERR) {
					index = SendMessage(list, LB_GETITEMDATA, index, 0);
					if (index >= 0 && index < g_GameChannelList.length()) {
						Channel choice;
						memset(&choice, 0, sizeof(choice));
						g_GameChannelList.get(choice, index);
						join = Can_Join_Channel(&choice, false);
					}
				}
				EnableWindow(GetDlgItem(main, 0x6EE), TRUE);
				EnableWindow(GetDlgItem(main, 0x62D), join);
				EnableWindow(GetDlgItem(main, 0x62B), TRUE);
				EnableWindow(GetDlgItem(main, 0x689), TRUE);
				EnableWindow(GetDlgItem(main, 0x558), TRUE);
				EnableWindow(GetDlgItem(main, 0x61F), TRUE);
				EnableWindow(GetDlgItem(main, 0x686), TRUE);
				SetFocus(GetDlgItem(main, 0x540));
			}
			Request_Channel_List(0x21, 1); // level-2 1.001: the game channel list is asked for without a wait (the request and its queue entry are expanded)
			Refresh_Lobby_List();
		}
		if (channel->type == 0x21) {
			Session.MPGameMode = Default_Game_Mode();
			Session.ScenarioMaxPlayers = 8;
			if (Session.MPGameMode) {
				Session.MPGameMode->vt_entry_24();
			}
			Delete_All(Session.Players);
			Clear_Slot_Lists();
			Reset_Slots();
			NodeNameType *node = new NodeNameType;
			memset(node, 0, sizeof(NodeNameType));
			wcscpy(node->Name, Narrow_To_Wide((char *)user->name));
			node->Address = User_To_IPX_Address(user);
			node->Set_Country(-2);
			node->Set_Color(-2);
			Session.Players.Add(node);
			Session.GameName[0] = 0;
			if (!Is_Tournament_Session()) {
				Darken_Surface(NULL, true);
				HWND dlg = WS_Create_Dialog(ProgramInstance, 0xC9, MainWindow, WOL_Guest_Dialog_Proc, 0);
				Show_Dialog(dlg, 0xC9);
				HWND main = WS_Find_Dialog(0x113);
				if (main) {
					ShowWindow(main, SW_HIDE);
					OwnerDraw::Set_Paint_Disabled(main, 0);
				}
				SendMessage(dlg, 0x4A9, 0, 1);
				ShowWindow(dlg, SW_SHOWNORMAL);
			}
		}
	} else {
		if (g_CurrentChannel.type == 0x21) {
			VocClass::PlayGlobal(Rule->PlayerJoined, 1.0f, 0x2000, 0);
		}
		if (user->squadID != 0 && strlen((char *)user->squadabbrev) == 0) {
			g_SquadInfoRequests++;
			g_pChat->RequestSquadInfo(user->squadID);
		}
		{
			Wstring ladder_name;
			ladder_name.set((char *)user->name);
			ladder_name.toLower();
			if (Session.Type == GAME_INTERNET && Online_Session_State == 2) {
				Wstring name;
				bool found = false;
				for (int teamIndex = 0; teamIndex < g_WDTTeamLookupQueue.length(); teamIndex++) {
					g_WDTTeamLookupQueue.get(name, teamIndex);
					if (name == ladder_name) {
						found = true;
						break;
					}
				}
				if (!found) {
					g_WDTTeamLookupQueue.addHead(ladder_name);
				}
			}
			if (!g_UserLocales.contains(ladder_name)) {
				Wstring name;
				bool found = false;
				for (int localeIndex = 0; localeIndex < g_UserLocaleLookupQueue.length(); localeIndex++) {
					g_UserLocaleLookupQueue.get(name, localeIndex);
					if (name == ladder_name) {
						found = true;
						break;
					}
				}
				if (!found) {
					g_UserLocaleLookupQueue.addHead(ladder_name);
				}
			}
			if (!g_ActiveLadder->contains(ladder_name)) {
				g_pNetUtil->RequestLadderList(g_LadderAddress, g_LadderPort, ladder_name.get(), g_GameSKU & 0xFFFF00, -1, 0, 0);
			}
		}
		if (channel->type != 0) {
			for (i = 1; i < 16; i++) {
				g_UserInfo[i].accepted = 0;
				EnableWindow(GetDlgItem(GameoptWindow(), 0x59F), TRUE);
			}
			if (!g_IsChannelCreator) {
				HWND dialog = WS_Find_Dialog(0xC9);
				Enable_Player_Combos(dialog, true);
			}
			Enable_Start_Button();
		}
	}

	int index = g_UserList.length();
	User temp_user;
	for (i = 0; i < g_UserList.length(); i++) {
		g_UserList.get(temp_user, i);
		if (Compare_Users(user, &temp_user) < 0) {
			index = i;
			break;
		}
	}
	User newuser = *user; // level-2 1.001: copied after the sorted position is found (no lobby special case as in YR)
	newuser.next = NULL;
	g_UserList.add(newuser, index);
	if (!(user->flags & 0x8000) && channel->type == 0 && (Online_Session_State == 2 || Online_Session_State == 1) && g_MatchState == 4) { // level-2 1.001: the tournament test is written out here and below (not Is_Tournament_Session): with the helper the ping addTail is called out of line
		Wstring name((char *)user->name);
		g_PingRequests.addTail(name);
		if (g_PingServers.length() == 0) {
			Request_Match_Pings();
		}
	}
	players = g_UserList.length();
	if (channel->type != 0) {
		char * name = (char *)user->name;
		int userinfoindex = Player_Name_To_Index(User_Name(user)); // level-2 1.001: through User_Name (by value), as in OnPrivateGameOptions; a plain Wstring temporary gives a frame 4 bytes larger
		memmove(&g_UserInfo[userinfoindex + 1], &g_UserInfo[userinfoindex], sizeof(ChannelUserInfo) * (15 - userinfoindex));
		memset(&g_UserInfo[userinfoindex], 0, sizeof(ChannelUserInfo));
		strcpy(g_UserInfo[userinfoindex].name, name);
		if (g_IsChannelCreator == 1) {
			if (Is_Game_Full()) {
				WOL_Kick_User(User_Name(user)); // level-2 1.001: a full game: the new user is kicked (WOL_Kick_User 0x0074A240 expanded)
			} else {
				int color = 0;
				int taken = 0;
				while (true) {
					g_UserInfo[userinfoindex].color = color;
					taken = 0;
					for (i = 0; i < players; i++) {
						if (i != userinfoindex && g_UserInfo[i].color == color) {
							color++;
							taken = 1;
						}
					}
					if (taken == 0) {
						break;
					}
				}
				NodeNameType *node = new NodeNameType;
				memset(node, 0, sizeof(NodeNameType));
				wcscpy(node->Name, Narrow_To_Wide(name));
				node->Address = User_To_IPX_Address(user);
				if (Session.MPGameMode) {
					node->Set_Country(Session.MPGameMode->DefaultCountry());
				} else {
					node->Set_Country(-2);
				}
				node->Set_Color(-2);
				Session.Players.Add(node);
				Add_To_Open_Slot((MPPlayerNode *)node);
				if ((Online_Session_State == 2 || Online_Session_State == 1) && channel->type != 0) {
					if (Online_Session_State != 2) {
						Net2DecodeGameopt(g_MatchStartOptions, NULL);
					} else {
						Setup_Match_Map(strchr(g_MatchStartOptions, ':'));
					}
					for (i = 0; i < Session.Scenarios.Count(); i++) {
						char const *filename = Session.Scenarios[i]->Get_Filename(); // level-2 1.001: a named local (as gibbo101 YR); the direct call gives other registers here and in the last branch
						if (stricmp(Session.ScenarioFileName, filename) == 0) {
							Set_Scenario_Info_From_Index(i);
							break;
						}
					}
					if (i >= Session.Scenarios.Count()) {
						Set_Scenario_Info_From_Index(0);
					}
				}
				Enable_Start_Button();
				Handle_Mode_Selection();
				Send_Player_List();
				Send_Lobby_Options(true, false);
			}
		} else if (!(user->flags & 0x8000)) {
			NodeNameType *node = new NodeNameType;
			memset(node, 0, sizeof(NodeNameType));
			wcscpy(node->Name, Narrow_To_Wide(name));
			node->Address = User_To_IPX_Address(user);
			node->Set_Country(-2);
			node->Set_Color(-2);
			Session.Players.Add(node);
			HWND dialog = WS_Find_Dialog(0xC9);
			Enable_Player_Combos(dialog, true);
			Enable_Start_Button();
		}
	}
	SetEvent(g_WaitEventHandles[EV_CHAN_JOINED]);
	Draw_Player_List(0, false);
	return(S_OK);
}

static inline char Lookup_Buddy_Channel(Wstring const & name, Channel & value) // level-2 1.001: INFERRED wrapper around the buddy dictionary lookup
{
	return g_BuddyChannels.getValue(name, value);
}

static inline char Lookup_Buddy_Status(Wstring const & name, unsigned int & value) // level-2 1.001: INFERRED wrapper around the buddy dictionary lookup
{
	return g_BuddyStatus.getValue(name, value);
}

BOOL CALLBACK WOL_Buddy_List_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam);

// level-2 1.001: ported from meastes/redalert2-decomp src/recovered/wonline.cpp @613e28e4e0 (GPL-3.0-or-later).
static inline bool Request_Buddy_Game_List() // level-2 1.001: INFERRED buddy game list refresh
{
	if (Get_Channel_List(0x21, false)) return true;
	DebugString("Buddy List Guest Get Channel List failed\n");
	return false;
}

int __fastcall Run_Online_Menu(bool first_time) // level-2 1.001: 0x007474E0, the buddy list and its host and guest game sessions.
{
	g_PlayingNetGame = false;
	WolOptionsLocked = 0;
	if (!Get_Channel_List(0, false)) {
		Online_Session_Return = 0;
		return 0;
	}
	// level-2 1.001: STEERING expand the leave operation here to retain the original inline depth.
	if (g_ChannelCount) {
		DebugString("Leave_Channel, channel %s type %d\n", g_CurrentChannel.name, g_CurrentChannel.type);
		g_pChat->RequestChannelLeave();
		{
			WideWstring title(StringTable::LoadString("WOL:LeavingChannel", NULL, "C:\\RA2\\wonline.cpp", 8207));
			Show_Wait_Window(0x40, title, true);
		}
		for (int i = 0; g_ChannelCount && i < 150; i++) {
			Sleep(100);
			WOL_Wait_Callback();
		}
		Close_Wait_Window(0x40);
	}
	g_BuddyChannels.clear();
	for (;;) {
		SimpleWonlineDialogControl control;
		Reset_All_Wait_Events();
		HWND dialog = OwnerDraw::Begin_Dialog(0x116, WOL_Buddy_List_Dialog_Proc, (LPARAM)&control);
		OwnerDraw::Display_Dialog(dialog);
		while (!control.Is_Done()) {
			DWORD event;
			while ((event = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 100)) == WAIT_TIMEOUT && !control.Is_Done()) {
				WOL_Wait_Callback();
			}
			Reset_Wait_Event_At(event);
			if (event == EV_ABORT) {
				Close_Wait_Window(0xFFFFFFFF);
				OwnerDraw::End_Dialog(dialog);
				Online_Session_Return = 0;
				ODMessageBox(StringTable::LoadString("TXT_YOURE_DISCON", NULL, "C:\\RA2\\wonline.cpp", 0x498D), 0, Wait_Callback_Thunk, false);
				return 0;
			}
			if (event == EV_ERROR) {
				Close_Wait_Window(0xFFFFFFFF);
				OwnerDraw::End_Dialog(dialog);
				Online_Session_Return = 0;
				ODMessageBox(StringTable::LoadString("TXT_YOURE_DISCON", NULL, "C:\\RA2\\wonline.cpp", 0x4995), 0, Wait_Callback_Thunk, false);
				return 0;
			}
			Title_Screen_Restore(false);
		}
		OwnerDraw::End_Dialog(dialog);
		switch ((int)control.Get_Window()) {
		case 0x5C0:
		case 0x686:
			return 0;
		case 0x62B:
			Reset_All_Wait_Events();
			if (!Create_Game_Channel()) {
				DebugString("Buddy List Host Create Game failed\n");
			} else {
				g_JoinLobbyNow = 0;
				do {
					DWORD event;
					do {
						event = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 20);
						if (event == WAIT_TIMEOUT) WOL_Wait_Callback();
					} while (event == WAIT_TIMEOUT && !g_JoinLobbyNow);
					Reset_Wait_Event_At(event);
					if (event == EV_ABORT) {
						DebugString("EV_ABORT from Buddy List Host\n");
						g_JoinLobbyNow = 1;
					} else if (event == EV_EXIT) {
						DebugString("EV_EXIT from Buddy List Host\n");
						g_JoinLobbyNow = 1;
					} else if (event == EV_SKIRMISH) {
						DebugString("Skirmish from Buddy List\n");
						g_GameStartRequested = false;
						g_LastErrorMessage[0] = 0;
						g_PlayingNetGame = false;
						return 2;
					} else if (event == EV_STARTGAME) {
						DebugString("Start Game from Buddy List Host\n");
						g_GameStartRequested = false;
						g_pChat->RequestChannelLeave();
						g_LastErrorMessage[0] = 0;
						g_PlayingNetGame = true;
						g_JoinLobbyNow = 0;
						return 1;
					}
				} while (!g_JoinLobbyNow);
				DebugString("Stop Buddy Host\n");
				g_JoinLobbyNow = 0;
			}
			Close_Wait_Window(0xFFFFFFFF);
			Reset_All_Wait_Events();
			if (g_LastErrorMessage[0]) ODMessageBox(g_LastErrorMessage, 0, Wait_Callback_Thunk, false);
			while (WS_Destroy_Dialog(NULL, 0)) {
			}
			g_PlayingNetGame = false;
			break;
		case 0x62D: {
			Channel buddy;
			memset(&buddy, 0, sizeof(buddy));
			if (g_SelectedBuddy.length() <= 0 || !Lookup_Buddy_Channel(g_SelectedBuddy, buddy)) break;
			unsigned int status = 0;
			if (!Lookup_Buddy_Status(g_SelectedBuddy, status)) break;
			Channel game;
			switch (status) {
			case 4: {
				memset(&game, 0, sizeof(game));
				Online_Session_Return = 3;
				for (int i = 0; i < g_UserChannels.length(); ++i) {
					g_UserChannels.get(game, i);
					if (!stricmp((char *)game.name, (char *)buddy.name)) {
						g_LobbyNumber = i;
						break;
					}
				}
				return 0;
			}
			case 5: {
				// level-2 1.001: STEERING keep the name temporary alive through guest cleanup.
				Wstring const &name = Wstring((char *)buddy.name);
				if (!Find_Channel(name, g_GameChannelList, game)) {
					// level-2 1.001: STEERING name the refresh result to preserve later TU code generation.
					bool refreshed = Request_Buddy_Game_List();
					// level-2 1.001: STEERING bind the retry result for the original boolean materialization.
					bool const & found = refreshed ? Find_Channel(name, g_GameChannelList, game) : false;
					if (!found) {
						DebugString("Buddy List Guest Find Channel by name failed\n");
						goto guest_done;
					}
				}
				if (!Join_Game_Channel(&game)) {
					DebugString("Buddy List Guest Join_Game failed\n");
				} else {
					int remaining = 500;
					g_JoinLobbyNow = 0;
					do {
						DWORD event;
						while ((event = WaitForMultipleObjects(EV_COUNT, g_WaitEventHandles, FALSE, 20)) == WAIT_TIMEOUT && !g_JoinLobbyNow) {
							WOL_Wait_Callback();
						}
						Reset_Wait_Event_At(event);
						// level-2 1.001: STEERING keep each event test and its original flag store independent.
						if (event == EV_ABORT) {
							DebugString("EV_ABORT from Buddy List Guest\n");
							g_JoinLobbyNow = 1;
						}
						if (event == EV_EXIT) {
							DebugString("EV_EXIT from Buddy List Guest\n");
							g_JoinLobbyNow = 1;
						}
						if (event == EV_ERROR) {
							DebugString("EV_ERROR from Buddy List Guest\n");
							g_JoinLobbyNow = 1;
						}
						if (event == EV_CHAN_JOIN_FAIL) {
							DebugString("EV_CHAN_JOIN_FAIL from Buddy List Guest\n");
							g_JoinLobbyNow = 1;
						}
						if (event == EV_STARTGAME) {
							DebugString("EV_STARTGAME from Buddy List Guest\n");
							g_GameStartRequested = false;
							g_pChat->RequestChannelLeave();
							g_LastErrorMessage[0] = 0;
							g_PlayingNetGame = true;
							g_JoinLobbyNow = 0;
							return 1;
						}
						if (remaining-- < 0) {
							DebugString("Timeout from Buddy List Guest\n");
							break;
						}
					} while (!g_JoinLobbyNow);
					g_JoinLobbyNow = 0;
					DebugString("Exit from BuddyList Guest\n");
				}
			guest_done: // level-2 1.001: STEERING share the name destructor with the failed retry.
				break;
			}
			}
			break;
		}
		}
	}
}


// RA2: 1.001 0x005F8B50, implemented in ownrdraw.cpp
LRESULT __fastcall Get_List_Item_Text(HWND list, WPARAM index, Wstring & text);



class WolUserArray : public ArrayList<User> {
public:
    bool Insert(const User &user, int index);
};

// level-2 1.001: ported from meastes/redalert2-decomp src/recovered/wonline/WolUserArray_Insert.cpp @613e28e4e0 (GPL-3.0-or-later).
bool WolUserArray::Insert(const User &user, int index)
{
    // ArrayList takes a mutable reference but copies the supplied user.
    return add(const_cast<User &>(user), index) != FALSE;
}

// level-2 1.001: STEERING
static inline void Set_Buddy_Refresh_Enabled(HWND button, BOOL enabled)
{
	EnableWindow(button, enabled);
}

// level-2 1.001: INFERRED timer-only helper, keeping the queue rebuild at the original inline depth.
static inline void Queue_Timer_Buddy_Requests(void)
{
	for (int i = 0; i < g_BuddyList.length(); i++) {
		Wstring node;
		g_BuddyList.get(node, i);
		g_BuddyRequests.addTail(node);
	}
	Request_Next_Buddy_Find();
}

BOOL CALLBACK WOL_Buddy_List_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 1.001 0x00746940, buddy list dialog (0x116)
{
	if (message == WM_INITDIALOG && lparam) {
		SetWindowLong(window, 8, ((int *)lparam)[1]);
	}
	int result = Standard_Dialog_Proc(window, message, wparam, lparam);
	if (result) {
		return(result);
	}
	OwnerDraw::SimpleDialogControl * control = (OwnerDraw::SimpleDialogControl *)GetWindowLong(window, 8);
	switch (message) {
	case 0x497:
		{
			HWND list = GetDlgItem(window, 0x689);
			SendMessage(list, 0x4A6, g_SliderSpan_B0E950, g_SliderMin_7E6B70);
			SendMessage(list, 0x4A6, 0, g_SliderMax_7E6B74);
			SendMessage(list, 0x4A6, 0, g_BuddyColumn_7E6B78);
			SendMessage(list, 0x4A6, g_SliderSpan_B0E5EC, g_SliderMin_7E6B80);
			SendMessage(list, 0x4A6, 0, g_SliderMax_7E6B84);
			HWND refresh = GetDlgItem(window, 0x704);
			SendMessage(refresh, 0x49C, 0, (LPARAM)SurfaceCache.GetSurface("wouref.pcx", NULL));
			SendMessage(refresh, 0x4AA, 0, (LPARAM)SurfaceCache.GetSurface("wodref.pcx", NULL));
			Reset_Buddy_Lists();
			SetTimer(window, 0, 1000, NULL);
		}
		return(FALSE);
	case WM_TIMER:
		if (wparam) {
			if (wparam == 0x704) {
				KillTimer(window, 0x704);
				EnableWindow(GetDlgItem(window, 0x704), TRUE);
			}
		} else if ((unsigned)(time(NULL) - g_BuddyRefreshTime) > 30) {
			g_BuddyRefreshTime = time(NULL);
			if (!Get_Channel_List(0x21, true)) {
				SetEvent(g_WaitEventHandles[5]);
				return(FALSE);
			}
			g_BuddyRequests.clear();
			Queue_Timer_Buddy_Requests();
		}
		return(FALSE);
	case WM_COMMAND:
		if (control->Is_Done()) {
			return(FALSE);
		}
		switch (LOWORD(wparam)) {
		case 0x62B:
			control->Set_Window((unsigned int)window, (HWND)0x62B);
			break;
		case 0x62D:
			control->Set_Window((unsigned int)window, (HWND)0x62D);
			break;
		case 0x5C2:
			Open_Buddy_Page_Dialog();
			break;
		case 0x540:
			if (HIWORD(wparam) == EN_CHANGE) {
				Wstring name;
				Get_Control_Text((HWND)lparam, name);
				EnableWindow(GetDlgItem(window, 0x702), name.length() != 0);
			}
			break;
		case 0x686:
			control->Set_Window((unsigned int)window, (HWND)0x686);
			break;
		case 0x702:
			{
				SimpleWonlineDialogControl add;
				OwnerDraw::Controlled_Dialog(0x115, WOL_Add_Buddy_Dialog_Proc, &add);
				Fill_Buddy_List(window);
			}
			break;
		case 0x703:
			{
				HWND list = GetDlgItem(window, 0x689);
				int index = SendMessage(list, LB_GETCURSEL, 0, 0);
				if (index != LB_ERR) {
					Wstring name;
					Get_List_Item_Text(list, index, name);
					Remove_Buddy(name);
					SendMessage(list, LB_DELETESTRING, index, 0);
					g_SelectedBuddy.clear();
					Fill_Buddy_List(window);
				}
			}
			break;
		case 0x704:
			Set_Buddy_Refresh_Enabled((HWND)lparam, FALSE);
			Refresh_Buddy_Channels();
			SetTimer(window, 0x704, 3000, NULL);
			break;
		case 0x689:
			switch (HIWORD(wparam)) {
			case LBN_DBLCLK:
				if (Can_Join_Buddy_Game()) {
					SendMessage(GetDlgItem(window, 0x62D), BM_CLICK, 0, 0);
				} else if (Is_Selected_Buddy_Known()) {
					SendMessage(GetDlgItem(window, 0x5C2), BM_CLICK, 0, 0);
				}
				return(FALSE);
			case LBN_SELCHANGE:
				{
					HWND list = (HWND)lparam;
					int index = SendMessage(list, LB_GETCURSEL, 0, 0);
					if (index == LB_ERR) {
						g_SelectedBuddy.clear();
					} else {
						Get_List_Item_Text(list, index, g_SelectedBuddy);
					}
					Update_Buddy_Buttons(window);
					Update_Buddy_Profile_Labels(window);
				}
				return(FALSE);
			}
			break;
		}
		return(FALSE);
	case WM_DESTROY:
		KillTimer(window, 0);
		KillTimer(window, 0x704);
		return(FALSE);
	case WM_DRAWITEM:
		Dialog_On_WM_DRAWITEM(lparam);
		return(TRUE);
	case WM_PAINT:
		Dialog_On_WM_PAINT(window);
		Slide_Pending_Dialog(window);
		ValidateRect(window, NULL);
		return(TRUE);
	case WM_ERASEBKGND:
		return(TRUE);
	}
	return(FALSE);
}

// level-2 1.001: retain the existing Wstring ArrayList removal body used by the buddy queue.
template <>
char ArrayList<Wstring>::remove(Wstring &node, int pos)
{
	char retval;
	retval = get(node, pos);
	if (retval == FALSE) return(FALSE);
	return(remove(pos));
}

// level-2 1.001: 0x00754200, the Channel dictionary doubles its bucket count. Body from the refreshed dict.h.
template <>
void Dictionary<Wstring,Channel>::expand(void)
{
	int i;
	int oldsize;
	unsigned int offset;
	DNode<Wstring,Channel> **oldtable,*temp,*first,*next;

	if (keepSize==TRUE)
		return;

	oldtable=table;
	oldsize=size;
	size*=2;
	tableBits++;

	table=(DNode<Wstring,Channel> **)new DNode<Wstring,Channel>* [size];
	assert(table!=NULL);
	memset((void *)table,0,size*sizeof(void *));

	for (i=0; i<oldsize; i++)
	{
		temp=oldtable[i];
		while (temp!=NULL)
		{
			offset=keyHash(temp->key);
			first=table[offset];
			table[offset]=temp;
			next=temp->hashNext;
			temp->hashNext=first;
			temp=next;
		}
	}
	delete[](oldtable);
}

// Adapted from meastes/redalert2-decomp 7c68e23b61, recovered/wonline.cpp,
// CChatEventSink::OnUserList (1.006 VA 0x00760C00), GPL-3.0-or-later.
// The 1.001 callback builds a country/color reply and queues individual squad lookups.
STDMETHODIMP CChatEventSink::OnUserList(HRESULT result, Channel *channel, User *users)
{
	if (g_PlayingNetGame) return S_OK;
	static char ladder_names[512]; // level-2 1.001: writable buffer at VA 0x00B108A0
	memset(ladder_names, 0, sizeof(ladder_names));
	Wstring key;
	if (FAILED(result)) return S_OK;

	SendDlgItemMessage(WS_Top_Window(), 0x53E, LB_RESETCONTENT, 0, 0);
	g_UserList.setEmpty();
	int batch_count = 0;
	int user_count = 0;
	bool saw_owner = false;
	for (; users; users = users->next) {
		++user_count;
		if (users->squadID && strlen((const char *)users->squadabbrev) == 0) {
			++g_SquadInfoRequests;
			g_pChat->RequestSquadInfo(users->squadID);
		}
		unsigned long is_owner = users->flags & 1;
		const char *nickname = (const char *)users->name;
		const char *session_name = nickname; // level-2 1.001: STEERING alias the live callback name to preserve sibling code generation
		User entry = *users;
		entry.next = NULL;
		g_UserList.addTail(entry);

		if (is_owner) saw_owner = true;
		key.set(nickname);
		key.toLower();
		if (Session.Type == GAME_INTERNET && Online_Session_State == 2 && !g_WDTTeams.contains(key)) {
			g_WDTTeamLookupQueue.addHead(key);
		}
		if (!g_UserLocales.contains(key)) g_UserLocaleLookupQueue.addHead(key);
		if (!g_ActiveLadder->contains(key) && user_count < 100) {
			key.set(nickname); // level-2 1.001: STEERING rebuild the key before appending, as in the callback
			key.toLower();
			strcat(ladder_names, key.get());
			strcat(ladder_names, ":");
			++batch_count;
		}
		if (batch_count > 20) {
			g_pNetUtil->RequestLadderList(g_LadderAddress, g_LadderPort, ladder_names, g_GameSKU & 0xFFFF00, -1, 0, 0);
			batch_count = 0;
			memset(ladder_names, 0, sizeof(ladder_names));
		}
		if (g_CurrentChannel.type && !g_IsChannelCreator) {
			Wstring slot_name = User_Name(users);
			int index = Player_Name_To_Index(slot_name);
			if ((unsigned int)index >= 16U) continue;
			ChannelUserInfo &slot = g_UserInfo[index];
			memset(&slot, 0, sizeof(slot));
			strcpy(slot.name, nickname);
			if (stricmp(nickname, g_NickName.get()) != 0) {
				if (Session.Players.Count() == 1) wcscpy(Session.GameName, Narrow_To_Wide(session_name));
				NodeNameType *node = new NodeNameType;
				if (node) {
					memset(node, 0, sizeof(NodeNameType));
					WideWstring wide_name = Wstring_ToWide(nickname);
					wcscpy(node->Name, wide_name.get());
					node->Address = User_To_IPX_Address(users);
					node->Set_Country(-2);
					node->Set_Color(-2);
					Session.Players.Add(node);
				}
			}
		}
	}
	if (strlen(ladder_names)) {
		g_pNetUtil->RequestLadderList(g_LadderAddress, g_LadderPort, ladder_names, g_GameSKU & 0xFFFF00, -1, 0, 0);
	}
	if (g_CurrentChannel.type && !saw_owner) {
		for (int i = 0; i < g_UserList.length(); ++i) {
			User entry;
			if (g_UserList.get(entry, i) && !stricmp((const char *)entry.name, g_NickName.get())) {
				Handle_User_Leave(entry);
				break;
			}
		}
	}
	if (g_CurrentChannel.type && !g_IsChannelCreator && g_UserList.length() == 1) {
		User sole_user;
		if (g_UserList.getHead(sole_user) && !stricmp((const char *)sole_user.name, g_NickName.get())) {
			Handle_User_Leave(sole_user);
		}
	}
	if (g_CurrentChannel.type) {
		IsColorChangePending = 1;
		if (!g_IsChannelCreator) Enable_Host_Controls(WS_Find_Dialog(0xC9), true);
		Clear_Accept_States();
		WOLOptionsClass options;
		options.Load();
		rc_ptr<PlayerProfile> profile;
		if (options.Is_Bit1_Clear()) profile = PlayerProfile::Load(g_NickName);
		else profile = g_PlayerProfile.Get();
		PlayerProfile *active_profile = profile.Get();
		if (active_profile) {
			Session.Set_Side(profile->Country, false);
			Session.Set_Color(active_profile->Color, false);
			char reply[64];
			sprintf(reply, "R%d,%d", profile->Country, profile->Color);
			User host;
			if (g_UserList.getHead(host)) {
				g_pChat->RequestPrivateGameOptions(&host, reply);
			}
		}
	}
	if ((Online_Session_State == 2 || Online_Session_State == 1) && !g_CurrentChannel.type && !Send_Match_Request()) {
		SetEvent(g_WaitEventHandles[EV_ERROR]);
	}
	Draw_Player_List(0, false);
	return S_OK;
}

// level-2 1.001: IChatEvent slot 23, 0x00750070.
STDMETHODIMP CChatEventSink::OnFind(HRESULT res, Channel *chan)
{
	if (g_PlayingNetGame) {
		return S_OK;
	}
	unsigned int status = 0;
	if (g_BuddyFindName.length()) {
		Lookup_Buddy_Status(g_BuddyFindName, status);
	}
	char location[64];
	location[0] = 0;
	User user;
	if (chan) {
		if (!chan->type) {
			if (!strnicmp((char *)chan->name, "Lob_38_", strlen("Lob_38_"))) {
				status = 7;
			} else if (!strnicmp((char *)chan->name, "Lob_35_", strlen("Lob_35_"))) {
				status = 8;
			} else {
				status = 4;
			}
		} else {
			status = 5;
			Wstring lookup_name((char *)chan->name);
			Channel game;
			if (Find_Channel(lookup_name, g_GameChannelList, game)) {
				if (Is_Channel_Flag_12(&game)) {
					status = 8;
				} else if (Is_Channel_Flag_11(&game)) {
					status = 7;
				}
			}
		}
		if (g_BuddyFindName.length() > 0) {
			g_BuddyChannels.add(g_BuddyFindName, *chan);
		}
		strcpy(location, (char *)chan->name);
		if (!strncmp(location, "Lob_33_", 7)) {
			int lobby = atol(location + strlen("Lob_33_"));
			int page = lobby / 6;
			int index = lobby % 6;
			if (!page) {
				sprintf(location, "%s", g_Lobbies[index]);
			} else {
				sprintf(location, "%s %d", g_Lobbies[index], page + 1);
			}
		}
		SMessagePrintf(ColorSystem, StringTable::LoadString("TXT_FINDOK", NULL, "C:\\RA2\\wonline.cpp", 6020), location);
	} else {
		if (g_BuddyFindName.length() > 0) {
			g_BuddyChannels.remove(g_BuddyFindName);
		}
		if (res == 0x40131) {
			status = 3;
			SMessagePrintf(ColorSystem, StringTable::LoadString("TXT_FINDNONE", NULL, "C:\\RA2\\wonline.cpp", 6029));
		} else if (res == 0x40130) {
			status = 2;
			SMessagePrintf(ColorSystem, StringTable::LoadString("TXT_FINDGONE", NULL, "C:\\RA2\\wonline.cpp", 6033));
		} else if (res == 0x40132) {
			status = 1;
			SMessagePrintf(ColorSystem, StringTable::LoadString("TXT_FINDDISABLED", NULL, "C:\\RA2\\wonline.cpp", 6037));
		} else {
			SMessagePrintf(ColorSystem, StringTable::LoadString("TXT_FINDFAILED", NULL, "C:\\RA2\\wonline.cpp", 6040));
		}
	}
	if (g_BuddyFindName.length() > 0) {
		g_BuddyStatus.add(g_BuddyFindName, status);
		g_BuddyFindName.clear();
		HWND dialog = WS_Find_Dialog(0x116);
		if (dialog) {
			Fill_Buddy_List(dialog);
		}
	}
	if (g_BuddyFindName.length() > 0) {
		if ((unsigned)(time(NULL) - g_BuddyFindTime) < 5) {
			goto find_complete;
		}
		g_BuddyFindName.clear();
	}
	if (g_BuddyRequests.length() != 0) {
		if (g_BuddyRequests.getHead(g_BuddyFindName)) {
			// Select the indexed overload; 1.001 calls this erase out of line.
			char (ArrayList<Wstring>::*erase)(int) = &ArrayList<Wstring>::remove;
			(g_BuddyRequests.*erase)(0);
		}
		g_BuddyFindTime = time(NULL);
		memset(&user, 0, sizeof(user));
		strcpy((char *)user.name, g_BuddyFindName.get());
		g_pChat->RequestFind(&user);
	}
find_complete:
	return S_OK;
}

#include "ownertalk.h" // level-2 1.001: the router shutdown wait of the game start
extern char WestwoodOnline_UserName[]; // level-2 1.001: 0x00B0FCDC, the name of the first user of the channel (wonline.h)
extern long GameStartTime; // level-2 1.001: 0x00B0FB10, time(0) when the game started (stats.cpp)
extern int g_WDTGameSKU; // level-2 1.001: 0x00B0E0FC, 0x2300, the product of the tournament ladder (stats.cpp)

STDMETHODIMP CChatEventSink::OnGameStart(HRESULT res, Channel *channel, User *users, int gameid) // level-2 1.001: 0x0074E810, the host started the game: when the started users are the users of the channel, the session is set up from the channel (players, timing from the pings, squads) and the game begins
{
	bool all_found = true;
	int count = g_UserList.length();
	int listed = 0;
	User * user = users;
	while (user != NULL) {
		listed++;
		Wstring name((char *)user->name);
		name.toLower();
		int i;
		for (i = 0; i < count; i++) {
			User entry;
			g_UserList.get(entry, i);
			Wstring other((char *)entry.name);
			other.toLower();
			if (name == other) {
				break;
			}
		}
		if (i >= count) {
			all_found = false;
			break;
		}
		user = user->next;
	}
	bool ok = (listed == count && all_found);
	if (!ok) {
		g_GameStartRequested = false;
		WolOptionsLocked = 0;
		return(S_OK);
	}

	if (Is_Tournament_Session()) {
		HWND dialog = WS_Find_Dialog(0x117);
		WS_Destroy_Dialog(dialog, 0);
	}
	WestwoodOnline_GameID = gameid;
	WestwoodOnline_GameSKU_TS = g_GameSKU;
	WestwoodOnline_Tournament = g_CurrentChannel.tournament;
	g_WDTGameSKU = 0x2300;
	if (Is_Current_Channel_Flag_8()) {
		WestwoodOnline_Tournament = 2;
	}
	strcpy(WestwoodOnline_LoginName, g_NickName.get());
	User * first = NULL;
	g_UserList.getPointer(&first, 0);
	if (first) {
		strcpy(WestwoodOnline_UserName, (char *)first->name);
	}
	GameStartTime = time(NULL);
	DebugString("OnGameStart\n");
	if (channel) {
		g_LobbyNumber = channel->reserved & 0xFF;
	}
	User_List_To_Session_Players(users);
	WolOptionsLocked = 2;
	DebugString("Starting a %d player game.\n", Session.NumPlayers);
	Char_To_Wide(Session.MasterPlayerName, (char *)Find_Owner_User()->name, -1);
	Session.MasterPlayerID = -1;
	Negotiate_Scenario_Transfer();
	if (Session.Type != GAME_INTERNET || Online_Session_State != 2) {
		Session.House = 0;
	}
	Session.FrameSendRate = 5;
	switch (Session.Options.GameSpeed) {
	case 0:
		Session.MaxAhead = 40;
		Session.PrecalcDesiredFrameRate = 60;
		Session.FrameSendRate = 10;
		break;
	case 1:
		Session.MaxAhead = 40;
		Session.PrecalcDesiredFrameRate = 45;
		Session.FrameSendRate = 10;
		break;
	case 2:
		Session.MaxAhead = 30;
		Session.PrecalcDesiredFrameRate = 30;
		break;
	case 3:
		Session.MaxAhead = 20;
		Session.PrecalcDesiredFrameRate = 20;
		break;
	case 4:
		Session.MaxAhead = 20;
		Session.PrecalcDesiredFrameRate = 15;
		break;
	case 5:
		Session.MaxAhead = 20;
		Session.PrecalcDesiredFrameRate = 12;
		break;
	default:
		Session.MaxAhead = 10;
		Session.PrecalcDesiredFrameRate = 10;
		break;
	}
	if (Session.UseRouter) {
		Session.MaxAhead += 20;
	}
	Session.PrecalcMaxAhead = 0;
	if (!Local_User_Is_Channel_Owner()) {
		Session.PrecalcDesiredFrameRate = 0;
	}
	int worst = 0;
	for (int q = 0; q < 8; q++) {
		if (g_PlayerPings[q] > worst) {
			worst = g_PlayerPings[q];
		}
	}
	if (Session.UseRouter) {
		worst *= 2;
	}
	Session.LatencyFudge = 1;
	if (worst != 0 && worst != 1000) {
		DebugString("Max ping is %d ms\n", worst);
		if (worst > 1000) {
			Session.LatencyFudge = 2;
		} else if (worst < 600) {
			Session.LatencyFudge = 1;
		}
		int ticks = 60 * worst / 1000;
		ticks += 120 * ticks / 100;
		Ipx.Set_Timing(ticks, (unsigned long)-1, ticks * 8, true);
		if (Local_User_Is_Channel_Owner()) {
			unsigned ahead;
			switch (Session.LatencyFudge) {
			case 0:
			case 1:
				ahead = Session.MaxAhead;
				break;
			case 2:
				ahead = (Session.MaxAhead / 2) + Session.MaxAhead;
				break;
			case 3:
				ahead = Session.MaxAhead * 2;
				break;
			default:
				ahead = Session.PrecalcMaxAhead;
				break;
			}
			ahead = 10 * (ahead / 10);
			Session.PrecalcMaxAhead = ahead;
		}
	} else {
		DebugString("Ping times not available - Using defaults\n");
		Session.PrecalcMaxAhead = 10 * (Session.MaxAhead / 10);
		if (Session.PrecalcMaxAhead <= 10u) {
			Session.PrecalcMaxAhead = 10;
		}
	}
	DebugString("PrecalcMaxAhead is %d\n", Session.PrecalcMaxAhead);
	DebugString("PrecalcDesiredFrameRate is %d\n", Session.PrecalcDesiredFrameRate);
	DebugString("LatencyFudge is %d\n", Session.LatencyFudge);
	DebugString("FrameSendRate is %d\n", Session.FrameSendRate);
	Session.MaxMaxAhead = Session.MaxAhead;
	memset(Session.ConnectionStats, 0, sizeof(Session.ConnectionStats));
	UDPInterfaceClass::UDPListenPort = 1234;
	Options.GameSpeed = Session.Options.GameSpeed;
	AlternateSendPort = 1235;
	AlternateListenPort = 1236;
	LoopbackPort = 1237;
	Frame = 0;
	if (Session.UseRouter) {
		OwnerTalk.Wait_For_Router_Shutdown(2000);
	}
	WestwoodOnline_Clan1_Players[0] = 0;
	WestwoodOnline_Clan2_Players[0] = 0;
	if (Session.Type == GAME_INTERNET && Is_Current_Channel_Flag_8()) {
		unsigned long squad2 = 0;
		User * member = NULL;
		unsigned long squad1 = 0;
		for (int s = 0; s < g_UserList.length(); s++) {
			g_UserList.getPointer(&member, s);
			if (squad1 != 0 && squad1 != member->squadID) {
				if (squad2 == 0 || squad2 == member->squadID) {
					strcat(WestwoodOnline_Clan2_Players, (char *)member->name);
					strcat(WestwoodOnline_Clan2_Players, ",");
					squad2 = member->squadID;
				}
			} else {
				strcat(WestwoodOnline_Clan1_Players, (char *)member->name);
				strcat(WestwoodOnline_Clan1_Players, ",");
				squad1 = member->squadID;
			}
		}
	}
	if (Session.Type == GAME_INTERNET && Online_Session_State == 2) {
		User * member = NULL;
		for (int t = 0; t < g_UserList.length(); t++) {
			g_UserList.getPointer(&member, t);
			if (g_UserInfo[t].house == 0) {
				strcat(WestwoodOnline_Clan1_Players, (char *)member->name);
				strcat(WestwoodOnline_Clan1_Players, ",");
			} else {
				strcat(WestwoodOnline_Clan2_Players, (char *)member->name);
				strcat(WestwoodOnline_Clan2_Players, ",");
			}
		}
	}
	DebugString("setting EV_STARTGAME\n");
	SetEvent(g_WaitEventHandles[EV_STARTGAME]);
	if (Is_Tournament_Session()) {
		Set_Match_State(11, -1, 0);
	}
	g_PlayingNetGame = true;
	DebugString("Request channel leave in game start\n");
	g_pChat->RequestChannelLeave();
	PregameSetup();
	return(S_OK);
}

