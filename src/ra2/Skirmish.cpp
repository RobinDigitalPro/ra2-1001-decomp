// C:\RA2\Skirmish.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Skirmish set-up dialog: player slots with AI difficulty combo boxes, their side and colour
// combo boxes (see GDlgSupp.cpp), the map selection and the start of a skirmish game.
// All function, class and variable names are provisional.
#include "GAMECONST.H"
#include <windows.h>
#include <commctrl.h>
#include <string.h>
#include <stdio.h>
#include "ABSTYPE.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60

// GDlgSupp.cpp
int Player_Flag_ID(int slot);                           // 0x4d0a80
int Player_Side_ID(int slot);                           // 0x4d0d70
void Select_Side(HWND dialog, int id, int side);        // 0x4d1310
int Player_Color_ID(int slot);                          // 0x4d1530
void Select_Color(HWND dialog, int id, int color);      // 0x4d1bb0
int Player_Side_Slot(int id);                           // 0x4d0dd0
void Fill_All_Side_Lists(HWND dialog);                  // 0x4d1030
void Select_Player_Side(HWND dialog, int slot);         // 0x4d10b0
int Get_Side_Data(HWND dialog, int id, int index);      // 0x4d14f0
wchar_t const * Side_Name(int side);                    // 0x4d0e40
int Player_Color_Slot(int id);                          // 0x4d1590
wchar_t const * Color_Name(int color);                  // 0x4d1600
void Init_Player_Colors();                              // 0x4d1700
void Fill_All_Color_Lists(HWND dialog);                 // 0x4d1a80
void Select_Player_Color(HWND dialog, int slot);        // 0x4d1b00
int Get_Color_Data(HWND dialog, int id, int index);     // 0x4d1fd0

// Dialog support (see GameDlg.CPP).
HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);            // 0x5f72d0
void Show_Dialog(HWND dialog);          // 0x5f7480
void End_Dialog(HWND dialog);           // 0x5f73a0
bool Dialog_Abort_Check();              // 0x5f7d70, pumps messages, true when the dialog must close
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
void Call_Back_5168E0(bool flag);       // 0x5168e0, called while the dialog runs outside a game (meaning unknown)
void Func_514F50(int a, bool b);        // 0x514f50 (provisional, see CampScor.cpp)

// Owner-draw control registry (see GDlgSupp.cpp, Set_Control_Image 0x5da440): true when the
// control window has a registered owner-draw entry (hash table at 0xa5b1a0). Provisional.
bool Is_Control_Registered(HWND window);    // 0x5dcb50

// One-pointer wide string (see PhoneEd.cpp, WorldDom.cpp; provisional name).
class WideStringClass {
public:
    WideStringClass();                                          // 0x75b2f0
    ~WideStringClass();                                         // 0x75b390
    WideStringClass & operator = (wchar_t const * string);      // 0x75b4b0
    operator wchar_t const * () const;                          // 0x75bd30
    wchar_t * Buffer;
};

// Tool tip text request sent to a dialog with message 0x4e9 (lparam). Provisional.
struct ControlTipType {
    HWND Window;                                // +0x0 control under the mouse
    int Index;                                  // +0x4 list item, -1 = none
    WideStringClass Text;                       // +0x8 tip text to fill in
};

// RTTI .?AVHouseTypeClass@@ (primary vtable 0x78e048, 27 slots); only what is used here.
class HouseTypeClass : public AbstractTypeClass {
public:
};
extern DynamicVectorClass<HouseTypeClass *> HouseTypes;    // 0xa1e038

extern CCINIClass * RuleINI;                    // 0x821a10 (name provisional)

class RulesClass {
public:
    void Read_Sides(CCINIClass & ini);          // 0x642b70 (name provisional)
    void Read_Countries(CCINIClass & ini);      // 0x642cc0 (name provisional)

    char Unknown0000[0x10E8];
    int MinCredits;                             // +0x10e8 (names provisional)
    int Unknown10EC;
    int MaxCredits;                             // +0x10f0
    int CreditStep;                             // +0x10f4
    int MinUnitCount;                           // +0x10f8
    int Unknown10FC;
    int MaxUnitCount;                           // +0x1100
};
extern RulesClass * Rule;                       // 0x821b88

// Preview picture of the selected map, one image pointer (constructor 0x615010, destructor
// 0x615020 deletes the image through its vtable). Names provisional.
class MapPreviewClass {
public:
    MapPreviewClass();                          // 0x615010
    ~MapPreviewClass();                         // 0x615020
    void Draw(HWND dialog);                     // 0x615040
    void Load(char const * name);               // 0x615d50
    void * Image;                               // +0x0
};
extern MapPreviewClass * MapPreview;            // 0xa5a860

wchar_t * To_Wide(char const * string);         // 0x6eee20 (see Conquer.CPP)

// Multiplayer scenario description (Session scenario list entries). Provisional.
class MultiMission {
public:
    bool Is_Random_Map() const;                 // 0x668370 (name provisional)
};

int Scenario_Max_Players(int scenario);         // 0x5c0690 (name provisional)
bool Is_Scenario_Valid(int scenario);           // 0x5c1bd0 (name provisional)

// RTTI .?AVMultiplayerGameMode@@ (vtable 0x792188, 44 slots); only up to slot 13 here.
class MultiplayerGameMode {
public:
    virtual ~MultiplayerGameMode();
    virtual void Virtual_01();
    virtual void Virtual_02();
    virtual void Virtual_03();
    virtual void Virtual_04();
    virtual bool Can_Start(WideStringClass & reason);  // slot 5 (meaning provisional)
    virtual void Virtual_06();
    virtual void Virtual_07();
    virtual void Activate();                    // slot 8 (meaning provisional)
    virtual void Virtual_09();
    virtual void Virtual_10();
    virtual void Virtual_11();
    virtual bool Announce_Last_Player();        // slot 12 (meaning provisional)
    virtual int Default_Scenario();             // slot 13 (meaning provisional)

    bool Is_Scenario_Allowed(MultiMission * scenario);  // 0x5b3f30 (name provisional)

    char Unknown04[0x28 - 0x04];
    int ID;                                     // +0x28
};

int Game_Mode_Count();                          // 0x5b3a90 (name provisional)
MultiplayerGameMode * Default_Game_Mode();      // 0x5b39d0 (name provisional)
MultiplayerGameMode * Game_Mode_From_ID(int id);    // 0x5b3af0 (name provisional)
MultiplayerGameMode * Current_Game_Mode();      // 0x5be010, mode of Session.Options.GameMode or the default
void Show_Game_Mode_Name(HWND dialog, MultiplayerGameMode * mode);  // 0x5bdf90 (name provisional)
void Show_Scenario_Name(HWND dialog);           // 0x5bdff0 (name provisional)
void Update_Map_Preview(HWND dialog);           // 0x5c15d0 (name provisional)

extern HWND MainWindow;                         // 0xb0de50

void Wide_To_Narrow(char * dest, wchar_t const * src, int length);    // 0x6eed90 (see NullDlg.CPP)

void Prepare_Map_Selection(HWND dialog);        // 0x5de430 (name provisional)
int Map_Selection_Dialog(HWND parent);          // 0x5c09f0, 2 = cancelled (name provisional)

// Message box with an inline constructor that stores the caption (L" " at 0x7c1624); see NullDlg.CPP.
class WWMessageBox {
public:
    WWMessageBox(wchar_t const * caption = L" ") : Caption(caption) {}
    int Process(wchar_t const * msg, wchar_t const * b1, wchar_t const * b2 = NULL,
        wchar_t const * b3 = NULL, bool flag = false);     // 0x5b1290
    wchar_t const * Caption;
};

// Game options object (see GameDlg.CPP); only the game speed.
class OptionsClass {
public:
    int GameSpeed;                              // +0x00
};
extern OptionsClass Options;                    // 0xa28758

void Update_Player_Flag(HWND dialog, int slot);     // 0x4d0c50 (GDlgSupp.cpp)
void Color_Changed(HWND dialog, int id);            // 0x4d1e00 (GDlgSupp.cpp)

// Entry of the session player list (0x71 bytes; see ModemGst.cpp).
#pragma pack(push, 1)
class IPXAddressClass {
public:
    IPXAddressClass();                          // 0x522950
private:
    unsigned char Address[10];
};

struct NodeNameType {
    wchar_t Name[20];                           // +0x00
    IPXAddressClass Address;                    // +0x28
    char Unknown32[0x49 - 0x32];
    int House;                                  // +0x49
    char Unknown4D[0x51 - 0x4D];
    int Color;                                  // +0x51
    char Unknown55[0x61 - 0x55];
    int Unknown61;                              // +0x61
    char Unknown65[0x71 - 0x65];
};
#pragma pack(pop)
void Delete_All(DynamicVectorClass<NodeNameType *> & list);    // 0x5a4070 (see MPLayer.CPP)

// Game options of the session being set up (Session + 0x18). Field names provisional.
struct GameOptionsType {
    void Clear_AI_Players();                    // 0x668a80, clears AIPlayers and two 8-entry tables

    int GameMode;                               // +0x00 0xa255e0
    int Scenario;                               // +0x04 0xa255e4
    bool Bases;                                 // +0x08 0xa255e8, check box 0x66a
    int Credits;                                // +0x0c 0xa255ec
    bool Option10;                              // +0x10 0xa255f0, check box 0x624
    bool Option11;                              // +0x11 0xa255f1, check box 0x696
    bool Option12;                              // +0x12 0xa255f2, check box 0x54e
    bool Option13;                              // +0x13 0xa255f3, check box 0x69a
    bool Option14;                              // +0x14 0xa255f4, check box 0x69d
    int GameSpeed;                              // +0x18 0xa255f8
    bool Option1C;                              // +0x1c 0xa255fc
    int UnitCount;                              // +0x20 0xa25600
    int AIPlayers;                              // +0x24 0xa25604
    int Unknown28;                              // +0x28
    int AIDifficulty[8];                        // +0x2c, per player slot
    int Side[8];                                // +0x4c, per player slot
    int Color[8];                               // +0x6c, per player slot
    bool Option8C;                              // +0x8c
    bool Option8D;                              // +0x8d 0xa2566d
    bool Option8E;                              // +0x8e
    bool Option8F;                              // +0x8f 0xa2566f
    bool Option90;                              // +0x90 0xa25670, check box 0x693
    bool Unknown91;
    wchar_t ScenarioName[(0xF0 - 0x92) / 2];    // +0x92 0xa25672 (see CampScor.cpp; size provisional)
};

// Skirmish settings kept between dialogs (Session + 0x13c). Field names provisional.
struct SkirmishAIType {
    int Type;                                   // 1 = none, 4 = hard, 5 = medium, 6 = easy
    int Side;
    int Color;
};
struct SkirmishSettingsType {
    int GameMode;                               // +0x00 0xa25704
    int Scenario;                               // +0x04 0xa25708
    int GameSpeed;                              // +0x08 0xa2570c
    int Credits;                                // +0x0c 0xa25710
    int UnitCount;                              // +0x10 0xa25714
    bool Option12;                              // +0x14 0xa25718
    bool Option13;                              // +0x15
    bool Option14;                              // +0x16
    bool Option90;                              // +0x17
    bool Option11;                              // +0x18
    int Unknown1C[(0x28 - 0x1C) / 4];
    SkirmishAIType AI[7];                       // +0x28 0xa2572c
};

// Session object at 0xa255c8 (class name provisional). Other level-2 files keep its members
// as separate globals; here the code addresses them through the object (the load order of
// Session.Scenarios[Session.Options.Scenario] requires it). Offsets are binary evidence,
// field names provisional.
class SessionClass {
public:
    void Write_MultiPlayer_Settings();          // 0x666d70 (name provisional)
    void Set_Side_Choice(int side, bool flag);  // 0x668ca0 (name provisional)
    void Set_Color_Choice(int color, bool flag);    // 0x668d50 (name provisional)
    void Apply_Player_Choices();                // 0x668e20 (name provisional)

    int Type;                                   // +0x000
    MultiplayerGameMode * GameMode;             // +0x004 0xa255cc (SessionGameMode in NetDlg.CPP)
    char Unknown008[0x18 - 0x08];
    GameOptionsType Options;                    // +0x018 0xa255e0
    char Handle[20];                            // +0x108 0xa256d0, player name
    int UniqueID;                               // +0x11c 0xa256e4 (see NullDlg.CPP)
    int Unknown120;
    int House;                                  // +0x124 0xa256ec
    char Unknown128[0x13C - 0x128];
    SkirmishSettingsType Skirmish;              // +0x13c 0xa25704
    char Unknown1B8[0x640 - 0x1B8];
    DynamicVectorClass<MultiMission *> Scenarios;   // +0x640 0xa25c08
    char ScenarioFile[0x27E0 - 0x658];          // +0x658 0xa25c20 (size provisional)
    DynamicVectorClass<NodeNameType *> Players; // +0x27e0 0xa27da8
};
extern SessionClass Session;                    // 0xa255c8

// ---- end of local declarations ----

#define MAX_SLOTS       8
#define MAX_AI          7
#define SIDE_RANDOM     -2
#define COLOR_RANDOM    -2

// AI difficulty stored as item data of the AI combo boxes.
#define AI_NONE         -1
#define AI_HARD         0
#define AI_MEDIUM       1
#define AI_EASY         2

#define IDD_SKIRMISH            0x102
#define IDC_START_GAME          0x617
#define IDC_BACK                0x5C0
#define IDC_MAP_PREVIEW         0x468
#define WM_SKIRMISH_INIT        (WM_USER + 0x97)
#define WM_CONTROL_TIP          (WM_USER + 0xE9)
#define WM_SET_TEXT_WIDE        (WM_USER + 0xB2)
#define WM_EDIT_STYLE           (WM_USER + 0xD1)
#define WM_CB_ADD_WIDE_STRING   (WM_USER + 0xC2)
#define WM_SLIDER_STEP          (WM_USER + 0xAB)
#define IDC_PLAYER_NAME         0x6A0
#define IDC_GAME_SPEED          0x529
#define IDC_CREDITS             0x511
#define IDC_UNIT_COUNT          0x50C
#define IDC_OPTION_54E          0x54E
#define IDC_OPTION_69A          0x69A
#define IDC_OPTION_69D          0x69D
#define IDC_OPTION_693          0x693
#define IDC_OPTION_696          0x696
#define IDC_CHOOSE_MAP          0x5AA
#define IDC_PLAYER_SIDE         0x6A1
#define IDC_PLAYER_COLOR        0x6A2
#define WM_GET_TEXT_WIDE        (WM_USER + 0xB3)

static HWND SkirmishDialog;                             // 0xaa4904

// Combo box of the AI player in slot index + 1.
int AI_Combo_ID(int index)
{
    if (index == 0) return 0x50B;
    if (index == 1) return 0x50E;
    if (index == 2) return 0x516;
    if (index == 3) return 0x51A;
    if (index == 4) return 0x51B;
    if (index == 5) return 0x51C;
    if (index == 6) return 0x51D;
    return -1;
}

int AI_Combo_Index(int id)
{
    if (id == 0x50B) return 0;
    if (id == 0x50E) return 1;
    if (id == 0x516) return 2;
    if (id == 0x51A) return 3;
    if (id == 0x51B) return 4;
    if (id == 0x51C) return 5;
    if (id == 0x51D) return 6;
    return -1;
}

wchar_t const * AI_Difficulty_Name(int difficulty)
{
    if (difficulty == AI_NONE) {
#line 133 "C:\\RA2\\Skirmish.cpp"
        return Fetch_String("STT:PlayerNone", NULL, __FILE__, __LINE__);
    } else if (difficulty == AI_EASY) {
        return Fetch_String("STT:PlayerDumbAI", NULL, __FILE__, __LINE__);
    } else if (difficulty == AI_MEDIUM) {
        return Fetch_String("STT:PlayerSmartAI", NULL, __FILE__, __LINE__);
    } else if (difficulty == AI_HARD) {
        return Fetch_String("STT:PlayerGeniusAI", NULL, __FILE__, __LINE__);
    }
    return 0;
}

BOOL Is_AI_Selected(HWND dialog, int id);

// True when one of the AI slots from slot on has a computer player.
bool Any_AI_From(int slot)
{
    HWND dialog = SkirmishDialog;
    for (int i = slot; i < MAX_SLOTS; i++) {
        int id = AI_Combo_ID(i - 1);
        if (Is_AI_Selected(dialog, id)) {
            return true;
        }
    }
    return false;
}

// Reads a check box into an option flag when the control exists.
inline void Read_Check_Box(HWND dialog, int id, bool & option)
{
    HWND check = GetDlgItem(dialog, id);
    if (check != NULL) {
        option = (SendMessageA(check, BM_GETCHECK, 0, 0) == BST_CHECKED);
    }
}

// Difficulty (item data) of the current selection of an AI combo box.
inline int AI_Difficulty(HWND dialog, int id)
{
    int index = SendDlgItemMessageA(dialog, id, CB_GETCURSEL, 0, 0);
    return SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, index, 0);
}

// Enables the side and colour combo boxes of an AI slot only while it has a computer player.
inline void Update_AI_Slot(HWND dialog, int id)
{
    int slot = AI_Combo_Index(id) + 1;
    int color = Player_Color_ID(slot);
    int side = Player_Side_ID(slot);
    unsigned char enable = Is_AI_Selected(dialog, id);
    if (!enable) {
        Select_Color(dialog, color, COLOR_RANDOM);
        Select_Side(dialog, side, SIDE_RANDOM);
    }
    HWND color_list = GetDlgItem(dialog, color);
    HWND side_list = GetDlgItem(dialog, side);
    EnableWindow(color_list, enable);
    EnableWindow(side_list, enable);
}

BOOL Skirmish_Init(HWND dialog, WPARAM wparam, LPARAM lparam);

void Show_Player_Slots(HWND dialog, int first, int count);
void Hide_Player_Slots(HWND dialog, int first);

// Shows or hides player slots when the maximum player count changes with the scenario.
inline void Update_Player_Slots(HWND dialog, int old_scenario, int new_scenario)
{
    int old_max = (old_scenario == -1) ? MAX_SLOTS : Scenario_Max_Players(old_scenario);
    int new_max = Scenario_Max_Players(new_scenario);
    int change = new_max - old_max;
    if (old_scenario == new_scenario) {
        Hide_Player_Slots(dialog, 1);
        Show_Player_Slots(dialog, 1, new_max - 1);
    }
    if (change > 0) {
        Show_Player_Slots(dialog, old_max, change);
    } else if (change < 0) {
        Hide_Player_Slots(dialog, new_max);
    }
}

// Conversions between the combo box difficulty and the AI type kept in Session.Skirmish.
inline int Difficulty_AI_Type(int difficulty)
{
    if (difficulty == AI_NONE) return 1;
    if (difficulty == AI_HARD) return 4;
    if (difficulty == AI_MEDIUM) return 5;
    if (difficulty == AI_EASY) return 6;
    return 0;
}

inline int AI_Type_Difficulty(int type)
{
    if (type == 1) return AI_NONE;
    if (type == 4) return AI_HARD;
    if (type == 5) return AI_MEDIUM;
    if (type == 6) return AI_EASY;
    return AI_NONE;
}

static BOOL CALLBACK Skirmish_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);

// WM_COMMAND handler of the skirmish dialog.
void Skirmish_Command(HWND dialog, int id, HWND control, UINT code)
{
    int * result = (int *)GetWindowLongA(dialog, DWL_USER);
    int button = id;

    switch (id) {
        case 0x50B:
        case 0x50E:
        case 0x516:
        case 0x51A:
        case 0x51B:
        case 0x51C:
        case 0x51D:
            Update_AI_Slot(dialog, id);
            break;

        case IDC_CHOOSE_MAP:
        {
            int old_mode = Session.Options.GameMode;
            int old_scenario = Session.Options.Scenario;
            {
                char old_file[512];
                strcpy(old_file, Session.ScenarioFile);
            }
            {
                wchar_t old_name[256];
                wcscpy(old_name, Session.Options.ScenarioName);
            }
            Prepare_Map_Selection(dialog);
            ShowWindow(dialog, SW_HIDE);
            if (Map_Selection_Dialog(MainWindow) == 2) {
                Session.Options.GameMode = old_mode;
                Session.Options.Scenario = old_scenario;
                Is_Scenario_Valid(old_scenario);
                Update_Map_Preview(dialog);
                ShowWindow(dialog, SW_SHOW);
                if (Session.Scenarios[Session.Options.Scenario]->Is_Random_Map()) {
                    delete MapPreview;
                    MapPreview = new MapPreviewClass;
                    MapPreview->Load("RandMap.img");
                    if (MapPreview->Image == NULL) {
                        Update_Map_Preview(dialog);
                    }
                    InvalidateRect(dialog, NULL, FALSE);
                } else {
                    Update_Map_Preview(dialog);
                }
                InvalidateRect(dialog, NULL, FALSE);
                return;
            }

            Update_Player_Slots(dialog, old_scenario, Session.Options.Scenario);
            ShowWindow(dialog, SW_SHOW);
            if (Is_Scenario_Valid(Session.Options.Scenario)) {
                Show_Game_Mode_Name(dialog, Game_Mode_From_ID(Session.Options.GameMode));
                Show_Scenario_Name(dialog);
                if (Session.Scenarios[Session.Options.Scenario]->Is_Random_Map()) {
                    if (MapPreview != NULL) {
                        delete MapPreview;
                        MapPreview = new MapPreviewClass;
                        MapPreview->Load("RandMap.img");
                    }
                    if (MapPreview->Image == NULL) {
                        Update_Map_Preview(dialog);
                    }
                    InvalidateRect(dialog, NULL, FALSE);
                } else {
                    Update_Map_Preview(dialog);
                }
            } else {
                Session.Options.Scenario = old_scenario;
                Session.Options.GameMode = old_mode;
            }
            break;
        }

        case IDC_BACK:
        case IDC_START_GAME:
        {
            if (code != BN_CLICKED) break;
            if (id == IDC_START_GAME) {
                EnableWindow(GetDlgItem(dialog, IDC_START_GAME), FALSE);
            }

            int max_players = Scenario_Max_Players(Session.Options.Scenario);
            int ai_players = 0;
            for (int index = 0; index < MAX_AI; index++) {
                if (Is_AI_Selected(dialog, AI_Combo_ID(index))) {
                    ai_players++;
                }
            }
            int players = ai_players + 1;
            Session.Options.AIPlayers = ai_players;

            if (button == IDC_START_GAME) {
                if (max_players < players) {
                    wchar_t buffer[256];
#line 820 "C:\\RA2\\Skirmish.cpp"
                    swprintf(buffer, Fetch_String("TXT_SCENARIO_TOO_SMALL", NULL, __FILE__, __LINE__), max_players);
                    WWMessageBox().Process(buffer, Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    EnableWindow(GetDlgItem(dialog, IDC_START_GAME), TRUE);
                    return;
                }
                if (players <= 1) {
                    wchar_t buffer[256];
#line 828 "C:\\RA2\\Skirmish.cpp"
                    swprintf(buffer, Fetch_String("TXT_NEED_AT_LEAST_TWO_PLAYERS", NULL, __FILE__, __LINE__), max_players);
                    WWMessageBox().Process(buffer, Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    EnableWindow(GetDlgItem(dialog, IDC_START_GAME), TRUE);
                    return;
                }
            }

            MultiplayerGameMode * mode = Session.GameMode;
            WideStringClass reason;
            if (!mode->Can_Start(reason)) {
                if (button == IDC_START_GAME) {
#line 843 "C:\\RA2\\Skirmish.cpp"
                    WWMessageBox().Process(reason, Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    EnableWindow(GetDlgItem(dialog, IDC_START_GAME), TRUE);
                    return;
                }
                Default_Game_Mode();
            }

            Session.Skirmish.GameMode = Session.Options.GameMode;
            Session.Skirmish.Scenario = Session.Options.Scenario;
            if (Session.Skirmish.Scenario >= Session.Scenarios.ActiveCount) {
                Session.Skirmish.Scenario = 0;
            }

            wchar_t name[20];
            HWND edit = GetDlgItem(dialog, IDC_PLAYER_NAME);
            SendMessageA(edit, WM_GET_TEXT_WIDE, 20, (LPARAM)name);
            Wide_To_Narrow(Session.Handle, name, -1);
            int house = Get_Side_Data(dialog, IDC_PLAYER_SIDE, -1);
            Session.Set_Side_Choice(house, true);

            int slot;
            for (index = 0; index < MAX_AI; index++) {
                slot = index + 1;
                int ai = AI_Combo_ID(index);
                int side = Player_Side_ID(slot);
                int color = Player_Color_ID(slot);
                if (Is_AI_Selected(dialog, ai)) {
                    Session.Options.AIDifficulty[slot] = AI_Difficulty(dialog, ai);
                    Session.Options.Side[slot] = Get_Side_Data(dialog, side, -1);
                    Session.Options.Color[slot] = Get_Color_Data(dialog, color, -1);
                }
            }

            for (slot = 1; slot < MAX_SLOTS; slot++) {
                int ai = AI_Combo_ID(slot - 1);
                int side = Player_Side_ID(slot);
                int color = Player_Color_ID(slot);
                int difficulty = AI_Difficulty(dialog, ai);
                int ai_house = Get_Side_Data(dialog, side, -1);
                int ai_color = Get_Color_Data(dialog, color, -1);
                Session.Skirmish.AI[slot - 1].Type = Difficulty_AI_Type(difficulty);
                Session.Skirmish.AI[slot - 1].Side = ai_house;
                Session.Skirmish.AI[slot - 1].Color = ai_color;
            }

            int scheme = Get_Color_Data(dialog, IDC_PLAYER_COLOR, -1);
            Session.Set_Color_Choice(scheme, true);

            NodeNameType * node = new NodeNameType;
            if (node != NULL) {
                wcscpy(node->Name, To_Wide(Session.Handle));
                node->House = Session.House;
                node->Color = Session.UniqueID;
                node->Unknown61 = -1;
                Session.Players.Add(node);
            }
            Session.Apply_Player_Choices();

            HWND slider = GetDlgItem(dialog, IDC_GAME_SPEED);
            if (slider != NULL) {
                Session.Options.GameSpeed = 6 - SendMessageA(slider, TBM_GETPOS, 0, 0);
                Options.GameSpeed = Session.Options.GameSpeed;
            }
            slider = GetDlgItem(dialog, IDC_CREDITS);
            if (slider != NULL) {
                Session.Options.Credits = SendMessageA(slider, TBM_GETPOS, 0, 0);
            }
            slider = GetDlgItem(dialog, IDC_UNIT_COUNT);
            if (slider != NULL) {
                Session.Options.UnitCount = SendMessageA(slider, TBM_GETPOS, 0, 0);
            }
            Session.Skirmish.GameSpeed = Session.Options.GameSpeed;
            Session.Skirmish.Credits = Session.Options.Credits;
            Session.Skirmish.UnitCount = Session.Options.UnitCount;

            Read_Check_Box(dialog, IDC_OPTION_54E, Session.Options.Option12);
            Read_Check_Box(dialog, IDC_OPTION_69A, Session.Options.Option13);
            Read_Check_Box(dialog, IDC_OPTION_69D, Session.Options.Option14);
            Read_Check_Box(dialog, IDC_OPTION_693, Session.Options.Option90);
            Read_Check_Box(dialog, IDC_OPTION_696, Session.Options.Option11);

            Session.Skirmish.Option12 = Session.Options.Option12;
            Session.Skirmish.Option13 = Session.Options.Option13;
            Session.Skirmish.Option14 = Session.Options.Option14;
            Session.Skirmish.Option90 = Session.Options.Option90;
            Session.Skirmish.Option11 = Session.Options.Option11;

            Session.Options.Option8F = false;
            Session.Options.Option10 = true;
            Session.Options.Option8D = false;
            Session.Options.Option1C = false;

            if (MapPreview != NULL) {
                delete MapPreview;
                MapPreview = NULL;
            }
            *result = button;
            break;
        }

        case 0x522:
        case 0x523:
        case 0x524:
        case 0x525:
        case 0x526:
        case 0x527:
        case 0x528:
        case IDC_PLAYER_COLOR:
            if (code == CBN_SELCHANGE) {
                Color_Changed(dialog, id);
            }
            break;

        case IDC_PLAYER_SIDE:
        case 0x510:
        case 0x513:
        case 0x51E:
        case 0x514:
        case 0x51F:
        case 0x520:
        case 0x521:
            Update_Player_Flag(dialog, Player_Side_Slot(id));
            break;
    }
}

BOOL Is_AI_Selected(HWND dialog, int id)
{
    int index = SendDlgItemMessageA(dialog, id, CB_GETCURSEL, 0, 0);
    int difficulty = SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, index, 0);
    return difficulty == AI_HARD || difficulty == AI_MEDIUM || difficulty == AI_EASY;
}

void Show_Player_Slots(HWND dialog, int first, int count)
{
    int last = first + count;
    for (int slot = first; slot < last; slot++) {
        int id = AI_Combo_ID(slot - 1);
        int flag = Player_Flag_ID(slot);
        int color = Player_Color_ID(slot);
        int side = Player_Side_ID(slot);
        HWND ai_list = GetDlgItem(dialog, id);
        HWND flag_image = GetDlgItem(dialog, flag);
        HWND color_list = GetDlgItem(dialog, color);
        HWND side_list = GetDlgItem(dialog, side);
        ShowWindow(ai_list, SW_SHOW);
        ShowWindow(flag_image, SW_SHOW);
        ShowWindow(color_list, SW_SHOW);
        ShowWindow(side_list, SW_SHOW);
        Update_AI_Slot(dialog, id);
    }
}

void Hide_Player_Slots(HWND dialog, int first)
{
    int slot;
    for (slot = first; slot < MAX_SLOTS; slot++) {
        int id = AI_Combo_ID(slot - 1);
        int count = SendDlgItemMessageA(dialog, id, CB_GETCOUNT, 0, 0);
        for (int index = 0; index < count; index++) {
            if (SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, index, 0) == AI_NONE) {
                SendDlgItemMessageA(dialog, id, CB_SETCURSEL, index, 0);
                break;
            }
        }
        Update_AI_Slot(dialog, id);
    }
    for (slot = first; slot < MAX_SLOTS; slot++) {
        int id = AI_Combo_ID(slot - 1);
        int flag = Player_Flag_ID(slot);
        int side = Player_Side_ID(slot);
        int color = Player_Color_ID(slot);
        HWND ai_list = GetDlgItem(dialog, id);
        HWND flag_image = GetDlgItem(dialog, flag);
        HWND side_list = GetDlgItem(dialog, side);
        HWND color_list = GetDlgItem(dialog, color);
        ShowWindow(ai_list, SW_HIDE);
        ShowWindow(flag_image, SW_HIDE);
        ShowWindow(side_list, SW_HIDE);
        ShowWindow(color_list, SW_HIDE);
    }
}

bool Skirmish_Dialog()
{
    int result = -1;

    Rule->Read_Sides(*RuleINI);
    Rule->Read_Countries(*RuleINI);
    for (int index = 0; index < HouseTypes.ActiveCount; index++) {
        HouseTypes[index]->Read_INI(*RuleINI);
    }

    HWND dialog = Create_Dialog(IDD_SKIRMISH, Skirmish_Dialog_Proc, 0);
    if (dialog != NULL) {
        SkirmishDialog = dialog;
        SetWindowLongA(dialog, DWL_USER, (LONG)&result);
        Show_Dialog(dialog);
        while (result != IDC_START_GAME && result != IDC_BACK) {
            if (Dialog_Abort_Check() == true) {
                break;
            }
            Call_Back_5168E0(false);
        }
        End_Dialog(dialog);
        SkirmishDialog = NULL;
    }

    if (MapPreview != NULL) {
        delete MapPreview;
        MapPreview = NULL;
    }
    Session.Write_MultiPlayer_Settings();
    if (result == IDC_BACK) {
        Func_514F50(0, true);
    }
    if (result == IDC_START_GAME) {
        return true;
    }
    return false;
}

static BOOL CALLBACK Skirmish_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) return result;

    switch (message) {
        case WM_PAINT:
            if (MapPreview != NULL && !Is_Control_Registered(GetDlgItem(dialog, IDC_MAP_PREVIEW))) {
                MapPreview->Draw(dialog);
            }
            ValidateRect(dialog, NULL);
            return FALSE;

        case WM_COMMAND:
            Skirmish_Command(dialog, LOWORD(wparam), (HWND)lparam, HIWORD(wparam));
            return TRUE;

        case WM_SKIRMISH_INIT:
            return Skirmish_Init(dialog, wparam, lparam);

        case WM_CONTROL_TIP:
        {
            ControlTipType * tip = (ControlTipType *)lparam;
            tip->Text = NULL;
            if (tip->Window != NULL && tip->Index != -1) {
                int id = GetDlgCtrlID(tip->Window);
                if (AI_Combo_Index(id) == -1) {
                    if (Player_Side_Slot(id) == -1) {
                        if (Player_Color_Slot(id) != -1) {
                            tip->Text = Color_Name(Get_Color_Data(dialog, id, tip->Index));
                        }
                    } else {
                        int side = Get_Side_Data(dialog, id, tip->Index);
                        if (side != -1) {
                            tip->Text = Side_Name(side);
                        }
                    }
                } else {
                    int index = tip->Index;
                    if (index == -1) {
                        index = SendDlgItemMessageA(dialog, id, CB_GETCURSEL, 0, 0);
                    }
                    tip->Text = AI_Difficulty_Name(SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, index, 0));
                }
            }
            return TRUE;
        }
    }
    return FALSE;
}

BOOL Skirmish_Init(HWND dialog, WPARAM, LPARAM)
{
    Session.Options.Clear_AI_Players();

    HWND name = GetDlgItem(dialog, IDC_PLAYER_NAME);
    if (name != NULL) {
        SendMessageA(name, EM_LIMITTEXT, 19, 0);
        SendMessageA(name, WM_SET_TEXT_WIDE, 0, (LPARAM)To_Wide(Session.Handle));
        SendMessageA(name, WM_EDIT_STYLE, 1, 0);
    }

    for (int index = 0; index < MAX_AI; index++) {
        HWND list = GetDlgItem(dialog, AI_Combo_ID(index));
        SendMessageA(list, CB_RESETCONTENT, 0, 0);
#line 156 "C:\\RA2\\Skirmish.cpp"
        int item = SendMessageA(list, WM_CB_ADD_WIDE_STRING, 0, (LPARAM)Fetch_String("GUI:None", NULL, __FILE__, __LINE__));
        SendMessageA(list, CB_SETITEMDATA, item, AI_NONE);

        item = SendMessageA(list, WM_CB_ADD_WIDE_STRING, 0, (LPARAM)Fetch_String("GUI:AIEasy", NULL, __FILE__, __LINE__));
        SendMessageA(list, CB_SETITEMDATA, item, AI_EASY);

        item = SendMessageA(list, WM_CB_ADD_WIDE_STRING, 0, (LPARAM)Fetch_String("GUI:AINormal", NULL, __FILE__, __LINE__));
        SendMessageA(list, CB_SETITEMDATA, item, AI_MEDIUM);

        item = SendMessageA(list, WM_CB_ADD_WIDE_STRING, 0, (LPARAM)Fetch_String("GUI:AIHard", NULL, __FILE__, __LINE__));
        SendMessageA(list, CB_SETITEMDATA, item, AI_HARD);

        SendMessageA(list, CB_SETCURSEL, 0, 0);
    }

    Fill_All_Side_Lists(dialog);
    Init_Player_Colors();
    Fill_All_Color_Lists(dialog);
    Select_Player_Side(dialog, 0);
    Select_Player_Color(dialog, 0);

    for (int slot = 1; slot < MAX_SLOTS; slot++) {
        int id = AI_Combo_ID(slot - 1);
        int difficulty = AI_Type_Difficulty(Session.Skirmish.AI[slot - 1].Type);
        int count = SendDlgItemMessageA(dialog, id, CB_GETCOUNT, 0, 0);
        for (int entry = 0; entry < count; entry++) {
            if (SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, entry, 0) == difficulty) {
                SendDlgItemMessageA(dialog, id, CB_SETCURSEL, entry, 0);
                break;
            }
        }
        int side = Player_Side_ID(slot);
        int color = Player_Color_ID(slot);
        if (difficulty == AI_NONE) {
            Select_Side(dialog, side, SIDE_RANDOM);
            Select_Color(dialog, color, COLOR_RANDOM);
            HWND side_list = GetDlgItem(dialog, side);
            HWND color_list = GetDlgItem(dialog, color);
            EnableWindow(side_list, FALSE);
            EnableWindow(color_list, FALSE);
        } else {
            Select_Side(dialog, side, Session.Skirmish.AI[slot - 1].Side);
            Select_Color(dialog, color, Session.Skirmish.AI[slot - 1].Color);
        }
    }

    if (Session.Skirmish.GameMode < 0 || Session.Skirmish.GameMode >= Game_Mode_Count()) {
        Session.Skirmish.GameMode = Default_Game_Mode()->ID;
    }
    Session.Options.GameMode = Session.Skirmish.GameMode;
    MultiplayerGameMode * mode = Current_Game_Mode();
    Session.Skirmish.GameMode = mode->ID;
    Session.Options.GameMode = mode->ID;

    if (Session.Skirmish.Scenario < 0 || Session.Skirmish.Scenario >= Session.Scenarios.ActiveCount) {
        Session.Skirmish.Scenario = 0;
    }
    Session.Options.Scenario = Is_Scenario_Valid(Session.Skirmish.Scenario) ? Session.Skirmish.Scenario : 0;
    MultiMission * scenario = Session.Scenarios[Session.Options.Scenario];
    if (!mode->Is_Scenario_Allowed(scenario)) {
        int index = mode->Default_Scenario();
        if (index == -1) {
            mode = Default_Game_Mode();
            Session.Skirmish.GameMode = mode->ID;
            Session.Options.GameMode = mode->ID;
            index = mode->Default_Scenario();
        }
        scenario = Session.Scenarios[index];
        Session.Skirmish.Scenario = index;
        Session.Options.Scenario = index;
    }
    Update_Player_Slots(dialog, -1, Session.Options.Scenario);

    Session.GameMode = mode;
    mode->Activate();
    Show_Game_Mode_Name(dialog, mode);
    Show_Scenario_Name(dialog);
    Delete_All(Session.Players);

    Session.Options.GameSpeed = Session.Skirmish.GameSpeed;
    Session.Options.Credits = Session.Skirmish.Credits;
    Session.Options.UnitCount = Session.Skirmish.UnitCount;

    HWND speed = GetDlgItem(dialog, IDC_GAME_SPEED);
    if (speed != NULL) {
        int position = 6 - Session.Options.GameSpeed;
        SendMessageA(speed, TBM_SETRANGE, TRUE, MAKELONG(0, 6));
        SendMessageA(speed, TBM_SETPOS, TRUE, position);
    }
    HWND slider = GetDlgItem(dialog, IDC_CREDITS);
    if (slider != NULL) {
        SendMessageA(slider, TBM_SETRANGE, TRUE, MAKELONG(Rule->MinCredits, Rule->MaxCredits));
        SendMessageA(slider, TBM_SETPOS, TRUE, Session.Options.Credits);
        SendMessageA(slider, WM_SLIDER_STEP, 0, Rule->CreditStep);
    }
    slider = GetDlgItem(dialog, IDC_UNIT_COUNT);
    if (slider != NULL) {
        SendMessageA(slider, TBM_SETRANGE, TRUE, MAKELONG(Rule->MinUnitCount, Rule->MaxUnitCount));
        SendMessageA(slider, TBM_SETPOS, TRUE, Session.Options.UnitCount);
    }

    Session.Options.Option12 = Session.Skirmish.Option12;
    Session.Options.Option13 = Session.Skirmish.Option13;
    Session.Options.Option14 = Session.Skirmish.Option14;
    Session.Options.Option90 = Session.Skirmish.Option90;
    Session.Options.Option11 = Session.Skirmish.Option11;

    HWND check = GetDlgItem(dialog, IDC_OPTION_54E);
    if (check != NULL) SendMessageA(check, BM_SETCHECK, Session.Options.Option12 != false, 0);
    check = GetDlgItem(dialog, IDC_OPTION_69A);
    if (check != NULL) SendMessageA(check, BM_SETCHECK, Session.Options.Option13 != false, 0);
    check = GetDlgItem(dialog, IDC_OPTION_69D);
    if (check != NULL) SendMessageA(check, BM_SETCHECK, Session.Options.Option14 != false, 0);
    check = GetDlgItem(dialog, IDC_OPTION_693);
    if (check != NULL) SendMessageA(check, BM_SETCHECK, Session.Options.Option90 != false, 0);
    check = GetDlgItem(dialog, IDC_OPTION_696);
    if (check != NULL) SendMessageA(check, BM_SETCHECK, Session.Options.Option11 != false, 0);

    if (scenario->Is_Random_Map()) {
        delete MapPreview;
        MapPreview = new MapPreviewClass;
        MapPreview->Load("RandMap.img");
        if (MapPreview->Image != NULL) {
            return FALSE;
        }
    }
    Update_Map_Preview(dialog);
    return FALSE;
}
