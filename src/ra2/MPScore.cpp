// C:\RA2\MPScore.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Multiplayer / skirmish score screen: collects one score record per player house, sorts the
// records by score and shows them in dialog 0x108. Class names come from RTTI where available
// (HouseClass, HouseTypeClass, VectorClass, DynamicVectorClass); all other names are provisional.
#include "GAMECONST.H"
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "RECT.H"
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x6eeb60
void Debug_Printf(char const * format, ...);        // 0x4068f0 (empty in this build)

// Dialog support (see also Restate.cpp).
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
int Do_Modal_Dialog(int resource_id, DLGPROC proc, LPARAM param);   // 0x5e2e40
void Get_Child_Rect(HWND window, RECT * rect);                       // 0x72a250
void Adjust_Rect(RectangleStruct & rect, int dx, int dy);            // 0x6e6c10: X+=dx, Y+=dy, W-=2dx, H-=2dy

// Score screen backdrop (names provisional).
class Surface;
extern Surface * HiddenSurface;            // 0x821c94
extern Surface * AlternateSurface;          // 0x821c98
extern int ScreenWidth;                     // 0x83a710
extern int ScreenHeight;                    // 0x83a714
void Score_Screen_Begin(int flag);          // 0x6e7a20
void Score_Screen_End();                    // 0x6e7aa0
void Clear_Surface_Rect(Surface * surface, RectangleStruct & rect);           // 0x6e8cc0
void Show_Surface(bool flag, Surface * surface, int value);                   // 0x4e0320
void Draw_Score_Frame(RectangleStruct & rect, Surface * surface, int a, int b);  // 0x5f6840

// Music.
class ThemeClass {
public:
    int From_Name(char const * name);       // 0x6dd7d0
    void Play_Song(int theme);              // 0x6dd170
};
extern ThemeClass Theme;                    // 0xa1e0a8

// Random number generator inside the scenario.
// level-2 1.001: Random2Class (operator() 0x62FE40, the scenario generator), not RandomClass (0x62FCC0); shown by the P9 link check.
class Random2Class {
public:
    int operator()(int minval, int maxval); // 0x62fe40
};

class SystemTimerClass {
public:
    long operator()() const;                // 0x68fad0
};

template<class T>
class TTimerClass {
public:
    long Value() const
    {
        long value = Accumulated;
        if (Started != -1) {
            value += Timer() - Started;
        }
        return value;
    }
    long Started;
    T Timer;
    long Accumulated;
};

// Only the fields used here; layout not reconstructed.
class ScenarioClass {
public:
    char Unknown0[0x218];
    Random2Class RandomNumber;                       // +0x218
    char Unknown219[0x614 - 0x219];
    TTimerClass<SystemTimerClass> ElapsedTimer;     // +0x614
    char Unknown620[0x2239 - 0x620];
    bool Field2239;                                 // +0x2239, meaning unknown
};
extern ScenarioClass * Scen;                // 0xa255c0

class SessionClass {
public:
    int Type;                               // +0x00: 4 = internet game, 5 = skirmish (provisional)
};
extern SessionClass Session;                // 0xa255c8
extern int InternetGameID;                  // 0xb0fcd0 (provisional)

// Colour schemes.
struct RGBClass {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
};
class HSVClass {
public:
    RGBClass To_RGB() const;                // 0x4fe550
    unsigned char Hue;
    unsigned char Saturation;
    unsigned char Value;
};
class ColorSchemeClass {
public:
    char Unknown0[0x308];
    HSVClass BaseColor;                     // +0x308
};
extern DynamicVectorClass<ColorSchemeClass *> ColorSchemes;   // 0xa9ea00

// Per-house build counters (four at HouseClass+0x54a0).
class UnitTrackerClass : public VectorClass<int> {
public:
    int Total() const;                      // 0x491b70
};

// RTTI .?AVHouseTypeClass@@. Only the field used here.
class HouseTypeClass {
public:
    char Unknown0[0x1a6];
    bool IsMultiplayPassive;                // +0x1a6
};

// RTTI .?AVHouseClass@@. Only the fields used here.
class HouseClass {
public:
    char Unknown0[0x34];
    HouseTypeClass * Class;                 // +0x34
    char Unknown38[0x13d - 0x38];
    bool IsDefeated;                        // +0x13d
    char Unknown13E[0x5310 - 0x13e];
    int UnitsKilled[20];                    // +0x5310
    int UnitsLost;                          // +0x5360
    int BuildingsKilled[20];                // +0x5364
    int BuildingsLost;                      // +0x53b4
    char Unknown53B8[0x5418 - 0x53b8];
    int Points;                             // +0x5418
    char Unknown541C[0x54a0 - 0x541c];
    UnitTrackerClass AircraftTotals;        // +0x54a0
    UnitTrackerClass InfantryTotals;        // +0x54b0
    UnitTrackerClass UnitTotals;            // +0x54c0
    UnitTrackerClass BuildingTotals;        // +0x54d0
    char Unknown54E0[0x15f16 - 0x54e0];
    wchar_t IniName[21];                    // +0x15f16
    int ColorSchemeIndex;                   // +0x15f40
};
extern DynamicVectorClass<HouseClass *> Houses;   // 0xa1a5c8

// One score line, 0x70 bytes.
struct MPScoreRecord {
    wchar_t Name[20];                       // +0x00
    int Scheme;                             // +0x28
    int Wins;                               // +0x2c
    int Lost;                               // +0x30
    int Unknown34[3];
    int Kills;                              // +0x40
    int Unknown44[3];
    int Built;                              // +0x50
    int Unknown54[3];
    int Score;                              // +0x60
    int Unknown64[3];
};

class MPScoreClass {
public:
    MPScoreClass();
    void Presentation();
};

void Format_Time(wchar_t * buffer, int seconds);
void Set_Dialog_Number(HWND dialog, int id, int value);
void Compute_Scores();
void Sort_Scores();
int __cdecl Score_Compare(void const * a, void const * b);
BOOL CALLBACK MPScore_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);

// ---- end of local declarations ----

#define IDD_MPSCORE             0x108
#define IDC_MPSCORE_OK          0x6d1
#define IDC_MPSCORE_TITLE       0x694
#define IDC_MPSCORE_GAME        0x6d2
#define IDC_MPSCORE_TIME        0x3ea
#define WM_DIALOG_INIT          (WM_USER + 0x97)
#define WM_SET_COLOR            (WM_USER + 0x98)
#define WM_SET_TEXT_WIDE        (WM_USER + 0xB2)
#define MAX_SCORE_PLAYERS       8

// The score data (BSS 0xa27534..0xa278bf; also read by code at 0x4659a7, 0x511b6b, 0x6549e4, 0x737cab).
// One object: Compute_Scores only keeps its Wins/WinnerIndex store order when both are in the same
// aggregate (separate globals let the compiler reorder them). Owner TU and real name not proven.
struct MPScoreData {
    MPScoreRecord Records[MAX_SCORE_PLAYERS];       // 0xa27534
    int GameNumber;                                 // 0xa278b4
    int PlayerCount;                                // 0xa278b8
    int WinnerIndex;                                // 0xa278bc
};
MPScoreData ScoreData;
MPScoreRecord * SortedScores[MAX_SCORE_PLAYERS];    // 0xa59208
int ScoreUnknownA5929C;                             // 0xa5929c, only cleared here
int ScoreUnknownA592A0;                             // 0xa592a0, only cleared here

// Name, kills, lost, built and score controls of each line (0x7cffd0).
int ScoreControls[MAX_SCORE_PLAYERS][5] = {
    {0x411, 0x419, 0x6a3, 0x6a5, 0x6a6},
    {0x412, 0x41a, 0x6a4, 0x6a7, 0x6a8},
    {0x413, 0x41b, 0x6a9, 0x6aa, 0x6ab},
    {0x414, 0x41c, 0x6ac, 0x6ad, 0x6ae},
    {0x415, 0x41d, 0x6af, 0x6b0, 0x6b1},
    {0x416, 0x41e, 0x6b2, 0x6b3, 0x6b4},
    {0x417, 0x41f, 0x6b5, 0x6b6, 0x6b7},
    {0x418, 0x420, 0x6b8, 0x6b9, 0x6ba},
};

// 0x5a7610
MPScoreClass::MPScoreClass()
{
    ScoreUnknownA5929C = 0;
    ScoreUnknownA592A0 = 0;
    memset(SortedScores, 0, sizeof(SortedScores));
}

// 0x5a7630
void MPScoreClass::Presentation()
{
    Score_Screen_Begin(!Scen->Field2239);
    RectangleStruct rect(0, 0, ScreenWidth, ScreenHeight);
    Clear_Surface_Rect(HiddenSurface, rect);
    Show_Surface(true, HiddenSurface, 0);
    Do_Modal_Dialog(IDD_MPSCORE, MPScore_Dialog_Proc, 0);
    Clear_Surface_Rect(HiddenSurface, rect);
    Show_Surface(true, HiddenSurface, 0);
    Score_Screen_End();
}

// 0x5a76d0 (also inlined into MPScore_Dialog_Proc); the original __LINE__ of the Fetch_String call is 129.
void Format_Time(wchar_t * buffer, int seconds)
{
    if (buffer != NULL) {
        if (seconds / 3600 > 99) {
            seconds = 99 * 3600 + 59 * 60 + 59;
        }
        int hours = seconds / 3600;
        seconds -= hours * 3600;
        int minutes = seconds / 60;
        seconds -= minutes * 60;
#line 129 "C:\\RA2\\MPScore.cpp"
        swprintf(buffer, Fetch_String("TXT_TIME_FORMAT_HOURS", NULL, __FILE__, __LINE__), hours, minutes, seconds);
    }
}

// 0x5a7770 (no direct callers; inlined four times into MPScore_Dialog_Proc)
void Set_Dialog_Number(HWND dialog, int id, int value)
{
    wchar_t buffer[32];
    swprintf(buffer, L"%d", value);
    HWND item = GetDlgItem(dialog, id);
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
}

// 0x5a77c0
void Compute_Scores()
{
    ScoreData.PlayerCount = 0;
    int count = Houses.ActiveCount;
    for (int index = 0; index < count; index++) {
        HouseClass * house = Houses[index];
        if (house == NULL || house->Class->IsMultiplayPassive == true) continue;

        int player = ScoreData.PlayerCount++;
        ScoreData.Records[player].Wins = 0;
        wcscpy(ScoreData.Records[player].Name, house->IniName);
        ScoreData.Records[player].Lost = 0;
        ScoreData.Records[player].Kills = 0;
        ScoreData.Records[player].Built = 0;
        ScoreData.Records[player].Score = 0;
        ScoreData.Records[player].Scheme = house->ColorSchemeIndex;
        if (!house->IsDefeated) {
            ScoreData.Records[player].Wins += 1;
            ScoreData.WinnerIndex = player;
        }

        int kills = 0;
        int i;
        for (i = 0; i < 20; i++) {
            kills += house->UnitsKilled[i];
        }
        for (i = 0; i < count; i++) {
            kills += house->BuildingsKilled[i];
        }
        ScoreData.Records[player].Kills = kills;
        ScoreData.Records[player].Lost = house->BuildingsLost + house->UnitsLost;
        int built = house->AircraftTotals.Total();
        built += house->InfantryTotals.Total();
        built += house->UnitTotals.Total();
        built += house->BuildingTotals.Total();
        ScoreData.Records[player].Built = built;
        if (house->Points > 0) {
            ScoreData.Records[player].Score += house->Points;
        }
        if (!house->IsDefeated) {
            int score = ScoreData.Records[player].Score;
            ScoreData.Records[player].Score = Scen->RandomNumber(score / 2, score) + score / 2 + score;
        }
        Debug_Printf("%s: %s\n Scheme: %d\n Lost = %d\n Kills = %d\n Built = %d\n Score = %d\n",
            ScoreData.Records[player].Name, ScoreData.Records[player].Wins > 0 ? "Winner" : "Loser",
            ScoreData.Records[player].Scheme, ScoreData.Records[player].Lost, ScoreData.Records[player].Kills,
            ScoreData.Records[player].Built, ScoreData.Records[player].Score);
    }
}

// 0x5a79b0 (also inlined into MPScore_Dialog_Proc)
void Sort_Scores()
{
    int count = ScoreData.PlayerCount;
    for (int index = 0; index < count; index++) {
        SortedScores[index] = &ScoreData.Records[index];
    }
    if (count > 1) {
        qsort(SortedScores, count, sizeof(SortedScores[0]), Score_Compare);
    }
}

// 0x5a79f0: highest score first.
int __cdecl Score_Compare(void const * a, void const * b)
{
    MPScoreRecord * record1 = *(MPScoreRecord **)a;
    MPScoreRecord * record2 = *(MPScoreRecord **)b;
    if (record1->Score == record2->Score) return 0;
    return (record1->Score > record2->Score) ? -1 : 1;
}

// 0x5a7a20; the original __LINE__ values are 280, 282, 286 and 288.
BOOL CALLBACK MPScore_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) return result;

    int * retval = (int *)GetWindowLongA(dialog, DWL_USER);

    switch (message) {
        case WM_PAINT:
        {
            RECT first;
            RECT last;
            HWND item = GetDlgItem(dialog, IDC_MPSCORE_GAME);
            Get_Child_Rect(item, &first);
            int id = ScoreControls[ScoreData.PlayerCount - 1][4];
            item = GetDlgItem(dialog, id);
            Get_Child_Rect(item, &last);
            RectangleStruct rect(first.left, first.top, last.right - first.left, last.bottom - first.top);
            Adjust_Rect(rect, -4, -8);
            Draw_Score_Frame(rect, AlternateSurface, 0, 0x9f);
            break;
        }

        case WM_COMMAND:
            if (LOWORD(wparam) == IDC_MPSCORE_OK) {
                *retval = 1;
            }
            break;

        case WM_DIALOG_INIT:
        {
            wchar_t buffer[32];

            Theme.Play_Song(Theme.From_Name("SCORE"));
            if (Session.Type == 4) {
#line 280 "C:\\RA2\\MPScore.cpp"
                swprintf(buffer, Fetch_String("TXT_GAME", NULL, __FILE__, __LINE__), InternetGameID);
            } else {
#line 282 "C:\\RA2\\MPScore.cpp"
                swprintf(buffer, Fetch_String("TXT_GAME", NULL, __FILE__, __LINE__), ScoreData.GameNumber);
            }
            wchar_t const * title;
            if (Session.Type == 5) {
#line 286 "C:\\RA2\\MPScore.cpp"
                title = Fetch_String("GUI:SkirmishScore", NULL, __FILE__, __LINE__);
            } else {
#line 288 "C:\\RA2\\MPScore.cpp"
                title = Fetch_String("GUI:MultiplayerScore", NULL, __FILE__, __LINE__);
            }
            HWND item = GetDlgItem(dialog, IDC_MPSCORE_TITLE);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)title);
            item = GetDlgItem(dialog, IDC_MPSCORE_GAME);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);

            Format_Time(buffer, Scen->ElapsedTimer.Value() / 60);
            item = GetDlgItem(dialog, IDC_MPSCORE_TIME);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);

            Compute_Scores();
            Sort_Scores();

            for (int index = 0; index < ScoreData.PlayerCount; index++) {
                ColorSchemeClass * scheme = ColorSchemes[SortedScores[index]->Scheme];
                RGBClass rgb = scheme->BaseColor.To_RGB();
                COLORREF color = RGB(rgb.Red, rgb.Green, rgb.Blue);

                int id = ScoreControls[index][0];
                wchar_t const * name = SortedScores[index]->Name;
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)name);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = ScoreControls[index][1];
                Set_Dialog_Number(dialog, id, SortedScores[index]->Kills);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = ScoreControls[index][2];
                Set_Dialog_Number(dialog, id, SortedScores[index]->Lost);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = ScoreControls[index][3];
                Set_Dialog_Number(dialog, id, SortedScores[index]->Built);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = ScoreControls[index][4];
                Set_Dialog_Number(dialog, id, SortedScores[index]->Score);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);
            }
            break;
        }
    }
    return FALSE;
}
