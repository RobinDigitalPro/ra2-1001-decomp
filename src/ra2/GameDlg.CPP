// C:\RA2\GameDlg.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Game controls dialog: game speed, scroll rate, detail level, difficulty and three option
// check boxes. The class name GameControlsClass follows the Westwood file name; it has no
// vtable, so all class, method and variable names here are provisional.
#include "GAMECONST.H"
#include <windows.h>
#include <commctrl.h>

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)

// Dialog support (see also Restate.cpp).
HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);            // 0x5f72d0
void Show_Dialog(HWND dialog);          // 0x5f7480
void End_Dialog(HWND dialog);           // 0x5f73a0
bool Dialog_Abort_Check();              // 0x5f7d70, pumps messages, true when the dialog must close
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0

void Call_Back_5168E0(bool flag);       // 0x5168e0, called while the dialog runs outside a game (meaning unknown)
void Set_Flag_7E09A0(bool flag);        // 0x6ccf30, stores flag at 0x7e09a0 (meaning unknown)
BOOL Is_Pointer_819778_Set();           // 0x406f30, returns pointer at 0x819778 != NULL; enables button 0x52d

// Event record, 0x6f bytes (constructor 0x4b5d40). Layout not reconstructed.
#pragma pack(push, 1)
class EventClass {
public:
    EventClass(int house, int type, int id);
private:
    unsigned char Data[0x6F];
};
#pragma pack(pop)

enum { EVENT_GAMESPEED = 0xD };         // provisional name for event type 0xd

// Fixed-size ring buffer with time stamps (OutList at 0xa1a668: Count, Head, Tail, Array, Timings).
template<class T, int size> class QueueClass {
public:
    int Add(T const & q)
    {
        if (Count < size) {
            Array[Tail] = q;
            Timings[Tail] = timeGetTime();
            Tail = (Tail + 1) & (size - 1);
            Count = Count + 1;
            return 1;
        }
        return 0;
    }

    int Count;
    int Head;
    int Tail;
    T Array[size];
    int Timings[size];
};
extern QueueClass<EventClass, 128> OutList;     // 0xa1a668

class HouseClass {
public:
    char Unknown00[0x30];
    int ArrayIndex;                             // +0x30
};
extern HouseClass * PlayerPtr;                  // 0xa1e0e4

class SessionClass {
public:
    int Type;                                   // +0x00: 0 = single player, 5 = skirmish (provisional)
};
extern SessionClass Session;                    // 0xa255c8

// Game options object at 0xa28758; only the fields used here.
class OptionsClass {
public:
    void Save_Settings();                       // 0x5d1850

    int GameSpeed;                              // +0x00
    int Difficulty;                             // +0x04
    int Unknown08;
    int ScrollRate;                             // +0x0c
    int Unknown10;
    int Detail;                                 // +0x14
    char Unknown18[2];
    bool Option1A;                              // +0x1a, check box 0x601 (meaning unknown)
    bool Option1B;                              // +0x1b, check box 0x604 (meaning unknown)
    bool ToolTips;                              // +0x1c, check box 0x602
};
extern OptionsClass Options;                    // 0xa28758

// The display object at 0x81a820 (MouseClass vtable, see Restate.cpp); 0x49e2a0 is a
// non-virtual method called after the detail level changes.
class GScreenClass {
public:
    virtual void Flag_To_Redraw(int complete);  // 0x4e0030
};
class MouseClass : public GScreenClass {
public:
    void Detail_Changed();                      // 0x49e2a0 (name provisional)
};
extern MouseClass Map;                          // 0x81a820

// RTTI .?AVToolTipManager@@ (see ToolTip.cpp); check box 0x602 switches the tool tips.
class ToolTipManager {
public:
    virtual ~ToolTipManager();
    void Set_Active(bool on);                   // 0x6e0740
};
extern ToolTipManager * ToolTipHandler;         // 0x821cf0 (name provisional)

extern bool Flag_A285A8;                        // 0xa285a8, true while a game is in progress (provisional)
extern int ExitMode_A28988;                     // 0xa28988, set to 4 or 6 by buttons 0x52c/0x52d (meaning unknown)

// ---- end of local declarations ----

#define IDD_GAME_CONTROLS           0xF5
#define IDD_GAME_CONTROLS_INGAME    0xBBB
#define IDC_GAME_SPEED              0x529
#define IDC_SCROLL_RATE             0x52A
#define IDC_DETAIL                  0x52B
#define IDC_BUTTON_52C              0x52C
#define IDC_BUTTON_52D              0x52D
#define IDC_DIFFICULTY              0x50F
#define IDC_OPTION_601              0x601
#define IDC_TOOLTIPS                0x602
#define IDC_OPTION_604              0x604
#define IDC_OK                      0x686
#define IDC_DIFFICULTY_TEXT         0x670
#define IDC_GAME_SPEED_TEXT         0x671
#define IDC_SCROLL_RATE_TEXT        0x672
#define IDC_DETAIL_TEXT             0x673
#define IDC_GAME_SPEED_LABEL        0x714
#define WM_GAME_CONTROLS_INIT       (WM_USER + 0x97)
#define WM_SLIDER_STYLE             (WM_USER + 0xAC)
#define WM_SET_TEXT_WIDE            (WM_USER + 0xB2)

class GameControlsClass {
public:
    void Process();
    void Apply_Settings();

    HWND Dialog;
};

static char const * GameSpeedNames[7] = {
    "TXT_SLOWEST", "TXT_SLOWER", "TXT_SLOW", "TXT_MEDIUM", "TXT_FAST", "TXT_FASTER", "TXT_FASTEST"
};
static char const * ScrollRateNames[7] = {
    "TXT_SLOWEST", "TXT_SLOWER", "TXT_SLOW", "TXT_MEDIUM", "TXT_FAST", "TXT_FASTER", "TXT_FASTEST"
};
static char const * DetailNames[3] = {
    "TXT_LOW", "TXT_MEDIUM", "TXT_HIGH"
};
static char const * DifficultyNames[3] = {
    "TXT_EASY", "TXT_NORMAL", "TXT_HARD"
};

static BOOL CALLBACK Game_Controls_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);

void GameControlsClass::Process()
{
    int result = -1;

    Debug_Printf("GameControls: GameSpeed = %d, ScrollRate = %d, Detail = %d\n",
        Options.GameSpeed, Options.ScrollRate, Options.Detail);

    if (Flag_A285A8 == true) {
        Dialog = Create_Dialog(IDD_GAME_CONTROLS_INGAME, Game_Controls_Dialog_Proc, 0);
    } else {
        Dialog = Create_Dialog(IDD_GAME_CONTROLS, Game_Controls_Dialog_Proc, 0);
    }
    if (Dialog != NULL) {
        SetWindowLongA(Dialog, DWL_USER, (LONG)&result);
        Show_Dialog(Dialog);
        while (result == -1) {
            if (Dialog_Abort_Check() == true) {
                result = 2;
            }
            if (!Flag_A285A8) {
                Call_Back_5168E0(false);
            }
        }
        if (result == 1) {
            Apply_Settings();
            Options.Save_Settings();
        }
        End_Dialog(Dialog);
    }

    Debug_Printf("GameControls: GameSpeed = %d, ScrollRate = %d, Detail = %d\n",
        Options.GameSpeed, Options.ScrollRate, Options.Detail);
}

void GameControlsClass::Apply_Settings()
{
    if (HWND item = GetDlgItem(Dialog, IDC_GAME_SPEED)) {
        int speed = 6 - SendMessageA(item, TBM_GETPOS, 0, 0);
        if (Options.GameSpeed != speed) {
            if (Flag_A285A8 == true && Session.Type != 0 && Session.Type != 5) {
                OutList.Add(EventClass(PlayerPtr->ArrayIndex, EVENT_GAMESPEED, speed));
            } else {
                Options.GameSpeed = speed;
            }
        }
    }
    if (HWND item = GetDlgItem(Dialog, IDC_SCROLL_RATE)) {
        Options.ScrollRate = 6 - SendMessageA(item, TBM_GETPOS, 0, 0);
    }
    if (HWND item = GetDlgItem(Dialog, IDC_DETAIL)) {
        int detail = SendMessageA(item, TBM_GETPOS, 0, 0);
        if (Options.Detail != detail) {
            Options.Detail = detail;
            Map.Detail_Changed();
        }
    }
    if (HWND item = GetDlgItem(Dialog, IDC_OPTION_601)) {
        Options.Option1A = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED);
        Set_Flag_7E09A0(Options.Option1A);
    }
    if (HWND item = GetDlgItem(Dialog, IDC_OPTION_604)) {
        Options.Option1B = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED);
    }
    if (HWND item = GetDlgItem(Dialog, IDC_TOOLTIPS)) {
        Options.ToolTips = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED);
        if (ToolTipHandler != NULL && Flag_A285A8 == true) {
            ToolTipHandler->Set_Active(Options.ToolTips);
        }
    }
    if (!Flag_A285A8) {
        if (HWND item = GetDlgItem(Dialog, IDC_DIFFICULTY)) {
            Options.Difficulty = SendMessageA(item, TBM_GETPOS, 0, 0);
        }
    }
}

void Game_Controls_Command(HWND dialog, int id, HWND control, UINT code)
{
    int * result = (int *)GetWindowLongA(dialog, DWL_USER);

    switch (id) {
        case IDC_BUTTON_52C:
            if (code == BN_CLICKED && Flag_A285A8 == true) {
                ExitMode_A28988 = 4;
                *result = 1;
            }
            break;

        case IDC_BUTTON_52D:
            if (code == BN_CLICKED && Flag_A285A8 == true) {
                ExitMode_A28988 = 6;
                *result = 1;
            }
            break;

        case IDC_OK:
            *result = 1;
            break;
    }
}

static BOOL CALLBACK Game_Controls_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) return result;

    switch (message) {
        case WM_GAME_CONTROLS_INIT:
        {
            HWND item = GetDlgItem(dialog, IDC_GAME_SPEED);
            if (Session.Type == 0) {
                ShowWindow(item, SW_HIDE);
                item = GetDlgItem(dialog, IDC_GAME_SPEED_LABEL);
                ShowWindow(item, SW_HIDE);
                item = GetDlgItem(dialog, IDC_GAME_SPEED_TEXT);
                ShowWindow(item, SW_HIDE);
            } else if (item != NULL) {
                SendMessageA(item, WM_SLIDER_STYLE, 0, 0);
                SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(0, 6));
                SendMessageA(item, TBM_SETPOS, TRUE, 6 - Options.GameSpeed);
            }

            item = GetDlgItem(dialog, IDC_SCROLL_RATE);
            if (item != NULL) {
                SendMessageA(item, WM_SLIDER_STYLE, 0, 0);
                SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(0, 6));
                SendMessageA(item, TBM_SETPOS, TRUE, 6 - Options.ScrollRate);
            }

            item = GetDlgItem(dialog, IDC_DETAIL);
            if (item != NULL) {
                SendMessageA(item, WM_SLIDER_STYLE, 0, 0);
                SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(0, 2));
                SendMessageA(item, TBM_SETPOS, TRUE, Options.Detail);
            }

            item = GetDlgItem(dialog, IDC_OPTION_601);
            if (item != NULL) {
                SendMessageA(item, BM_SETCHECK, Options.Option1A != false, 0);
            }
            item = GetDlgItem(dialog, IDC_OPTION_604);
            if (item != NULL) {
                SendMessageA(item, BM_SETCHECK, Options.Option1B != false, 0);
            }
            item = GetDlgItem(dialog, IDC_TOOLTIPS);
            if (item != NULL) {
                SendMessageA(item, BM_SETCHECK, Options.ToolTips != false, 0);
            }

            if (Flag_A285A8 == true) {
                item = GetDlgItem(dialog, IDC_BUTTON_52D);
                if (item != NULL) {
                    EnableWindow(item, Is_Pointer_819778_Set());
                }
            } else {
                item = GetDlgItem(dialog, IDC_DIFFICULTY);
                if (item != NULL) {
                    SendMessageA(item, WM_SLIDER_STYLE, 0, 0);
                    SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(0, 2));
                    SendMessageA(item, TBM_SETPOS, TRUE, Options.Difficulty);
                }
            }
            return FALSE;
        }

        case WM_HSCROLL:
            if (LOWORD(wparam) == TB_THUMBTRACK) {
                int pos = HIWORD(wparam);
                char const * name;
                HWND item;
                if ((HWND)lparam == GetDlgItem(dialog, IDC_GAME_SPEED)) {
                    name = GameSpeedNames[pos];
                    item = GetDlgItem(dialog, IDC_GAME_SPEED_TEXT);
                } else if ((HWND)lparam == GetDlgItem(dialog, IDC_SCROLL_RATE)) {
                    name = ScrollRateNames[pos];
                    item = GetDlgItem(dialog, IDC_SCROLL_RATE_TEXT);
                } else if ((HWND)lparam == GetDlgItem(dialog, IDC_DETAIL)) {
                    name = DetailNames[pos];
                    item = GetDlgItem(dialog, IDC_DETAIL_TEXT);
                } else if (!Flag_A285A8 && (HWND)lparam == GetDlgItem(dialog, IDC_DIFFICULTY)) {
                    name = DifficultyNames[pos];
                    item = GetDlgItem(dialog, IDC_DIFFICULTY_TEXT);
                } else {
                    break;
                }
                if (item != NULL) {
#line 406 "C:\\RA2\\GameDlg.CPP"
                    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)Fetch_String(name, NULL, __FILE__, __LINE__));
                }
            }
            break;

        case WM_COMMAND:
            Game_Controls_Command(dialog, LOWORD(wparam), (HWND)lparam, HIWORD(wparam));
            break;
    }
    return FALSE;
}
