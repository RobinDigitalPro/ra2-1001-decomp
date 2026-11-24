// C:\RA2\stlscore.cpp (identified 2026-11-21 by its __FILE__ literal 0x7dfb58; placeholder name kept until the
// integrator renames it). GAMECONST.H initializers at 0x28fb10, then the score screen code 0x28fce0..0x690270 below.
#include "../RECT.H"
static RectangleStruct const ZeroRectA(0, 0, 0, 0);
#include "../GAMECONST.H"

// ---- C:\RA2\stlscore.cpp (string 0x7dfb58): the single-player par-time score screen ----
// Identified by the __FILE__ literal of its dialog procedure; the GAMECONST block above is this
// file's own. Functions 0x68fce0..0x690270 in source order: STLScoreScreen constructor,
// Present, Format_Time, Set_Number (0x68fe20, already claimed byte-identically by
// m85 campscor.cpp Campaign_Score_Set_Number) and the dialog procedure 0x68fe70.
// The class name follows gibbo101 YR stlscore.cpp (GPL-3.0-or-later, 2026 ra2-decomp
// contributors; EA's GPL section 7 terms apply); all names are provisional.
#include <windows.h>
#include <wchar.h>

// ---- local declarations (to be moved to headers by the integrator) ----
class Surface;
extern Surface * HiddenSurface;             // 0x821c94
extern int ScreenWidth;                     // 0x83a710
extern int ScreenHeight;                    // 0x83a714

class SystemTimerClass {
public:
    int operator()(void) const;
};

// level-2 1.001: INFERRED elapsed campaign timer layout used by the score dialog.
struct STLScoreElapsedTimer {
    int Started;
    SystemTimerClass Timer;
    int Accumulated;

    int Value(void) const {
        int value = Accumulated;
        if (Started != -1)
            value += Timer() - Started;
        return value;
    }
};

class ScenarioClass {
public:
    char Unknown0[0x60c];
    int Difficulty;
    int ComputerDifficulty;
    STLScoreElapsedTimer ElapsedTimer;
    char Unknown620[0x2239 - 0x620];
    bool Field2239;
    char Unknown223a[0x2308 - 0x223a];
    int ParTimeEasy, ParTimeMedium, ParTimeDifficult;
    char UnderParTitle[31], UnderParMessage[31];
    char OverParTitle[31], OverParMessage[31];
};
extern ScenarioClass * Scen;                // 0xa255c0

void __fastcall Score_Screen_Prepare(int flag);                               // 0x6e7700 (provisional)
void __fastcall Score_Screen_Finish(void);                                    // 0x6e7740 (provisional)
void __fastcall Draw_Score_Screen(Surface * surface, RectangleStruct const & rect);   // 0x6e8be0 (provisional)
void __fastcall Show_Surface(bool flag, Surface * surface, int unused);       // 0x4e0320
int __fastcall Do_Modal_Dialog(int resource_id, int (__stdcall * proc)(HWND, UINT, UINT, LONG), LONG param);   // 0x5e2e40
int __stdcall STL_Score_Dialog_Proc(HWND window, UINT message, UINT wparam, LONG lparam);   // 0x68fe70

class STLScoreScreen {
public:
    STLScoreScreen(void);
    void Present(void);
};

STLScoreScreen::STLScoreScreen(void)       // 0x68fce0
{
}

void STLScoreScreen::Present(void)          // 0x68fcf0
{
    Score_Screen_Prepare(!Scen->Field2239);
    RectangleStruct rect(0, 0, ScreenWidth, ScreenHeight);
    Draw_Score_Screen(HiddenSurface, rect);
    Show_Surface(true, HiddenSurface, false);
    Do_Modal_Dialog(0x103, STL_Score_Dialog_Proc, 0);
    Draw_Score_Screen(HiddenSurface, rect);
    Show_Surface(true, HiddenSurface, false);
    Score_Screen_Finish();
}

void __fastcall STL_Score_Format_Time(HWND dialog, int id, int seconds)   // 0x68fd90
{
    wchar_t text[32];
    int minutes = seconds / 60;
    int hours = minutes / 60;
    swprintf(text, L"%02d:%02d:%02d", hours, minutes - hours * 60, seconds - minutes * 60);
    HWND item = GetDlgItem(dialog, id);
    SendMessageA(item, 0x4b2, 0, (LPARAM)text);
}

class AudioEvent;
class VocClass;
struct AudioController {
    void Init(void);
    void Release(void);
    void Stop(void);
    void End(void);
    void __fastcall SetEvent(AudioEvent * event, VocClass * type);
};

class UnitTrackerClass {
public:
    int Get_Unit_Total(void);
private:
    int UnitTotals[512];
    int UnitCount;
    int InNetworkFormat;
};

class ThemeClass {
public:
    int From_Name(char const * name);
    void Play_Song(int index);
};
extern ThemeClass Theme;

class HouseClass {
public:
    char Unknown0[0x135];
    bool PlayerControlled;
    char Unknown136[0x2288 - 0x136];
    UnitTrackerClass DestroyedAircraft;
    UnitTrackerClass DestroyedInfantry;
    UnitTrackerClass DestroyedUnits;
    UnitTrackerClass DestroyedBuildings;
};
class RulesClass {
public:
    char Unknown0[0x1a8];
    int ScoreAnimSound;
};
extern RulesClass * Rule;
extern HouseClass ** ScoreHouseList;       // 0xa1a5cc
extern int ScoreHouseCount;                // 0xa1a5d8
extern AudioController ScoreAudio;         // 0xaa51a8
extern int ScoreAudioInitialized;          // 0xaa51dc
int __fastcall Standard_Dialog_Proc(HWND, UINT, WPARAM, LPARAM);
wchar_t const * __fastcall Fetch_String(char const *, char **, char const *, int);
class VocClass {
public:
    static void * __fastcall PlayGlobal(int sound, float volume, int pan, AudioController * controller = 0);
};

// 0x68fe20, the dialog's integer formatting helper.
void __fastcall STL_Score_Set_Number(HWND dialog, int id, int value)
{
    wchar_t text[32];
    swprintf(text, L"%d", value);
    HWND item = GetDlgItem(dialog, id);
    SendMessageA(item, 0x4b2, 0, (LPARAM)text);
}

// The single-player campaign score dialog procedure. 0x690020 is inside
// the second time conversion in the initialization message.
int __stdcall STL_Score_Dialog_Proc(HWND window, UINT message, UINT wparam, LONG lparam)
{
    int handled = Standard_Dialog_Proc(window, message, wparam, lparam);
    if (handled) return handled;

    int * done = (int *)GetWindowLongA(window, DWL_USER);
    switch (message) {
    case WM_COMMAND:
        if (LOWORD(wparam) == 0x423) {
            *done = 1;
            ScoreAudio.End();
        }
        break;
    case WM_DESTROY:
        if (ScoreAudioInitialized) {
            ScoreAudio.End();
            ScoreAudio.Release();
            ScoreAudioInitialized = 0;
        }
        break;
    case 0x497: {
        ScoreAudio.Init();
        ScoreAudioInitialized = 1;
        int par = 0;
        if (Scen->Difficulty == 0) par = Scen->ParTimeEasy;
        else if (Scen->Difficulty == 1) par = Scen->ParTimeMedium;
        else if (Scen->Difficulty == 2) par = Scen->ParTimeDifficult;
        par /= 60;
        STL_Score_Format_Time(window, 0x6f1, par);
        int elapsed = Scen->ElapsedTimer.Value() / 60;
        STL_Score_Format_Time(window, 0x6f2, elapsed);
        char const * title;
        char const * messageLabel;
        if (elapsed <= par) {
            title = Scen->UnderParTitle;
            messageLabel = Scen->UnderParMessage;
        } else {
            title = Scen->OverParTitle;
            messageLabel = Scen->OverParMessage;
        }
        wchar_t const * heading = Fetch_String(title, 0, "C:\\RA2\\stlscore.cpp", 137);
        wchar_t const * detail = Fetch_String(messageLabel, 0, "C:\\RA2\\stlscore.cpp", 138);
        HWND headingControl = GetDlgItem(window, 0x6f3);
        SendMessageA(headingControl, 0x4b2, 0, (LPARAM)heading);
        HWND detailControl = GetDlgItem(window, 0x6f4);
        SendMessageA(detailControl, 0x4b2, 0, (LPARAM)detail);
        int destroyed = 0;
        int count = ScoreHouseCount;
        for (int i = 0; i < count; ++i) {
            HouseClass * house = ScoreHouseList[i];
            if (house->PlayerControlled) {
                destroyed += house->DestroyedAircraft.Get_Unit_Total();
                destroyed += house->DestroyedInfantry.Get_Unit_Total();
                destroyed += house->DestroyedUnits.Get_Unit_Total();
                destroyed += house->DestroyedBuildings.Get_Unit_Total();
            }
        }
        HWND ownerControl = GetDlgItem(window, 0x72b);
        PostMessageA(ownerControl, 0x4d7, 0, (LPARAM)window);
        STL_Score_Set_Number(window, 0x6f6, destroyed);
        Theme.Play_Song(Theme.From_Name("SCORE"));
        break;
    }
    case 0x4ec:
        ScoreAudio.Stop();
        ScoreAudio.SetEvent((AudioEvent *)VocClass::PlayGlobal(Rule->ScoreAnimSound, 1.0f, 0x2000), 0);
        SendDlgItemMessageA(window, 0x72b, 0x4d3, 0, 0);
        break;
    case 0x4d8:
        if (wparam == 0) {
            SendDlgItemMessageA(window, 0x72b, 0x4d5, 0, 0x1d);
        }
        break;
    }
    return 0;
}
