// C:\RA2\CampScor.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Campaign score screens. Class names come from RTTI (.?AVCampaignScoreClass@@ vtable 0x788724,
// .?AVCampaignEndScoreClass@@ vtable 0x788730); all other names are provisional.
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

// Per-house build counters (four at HouseClass+0x54a0); see MPScore.cpp.
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

// RTTI .?AVHouseClass@@. Only the fields used here (same as MPScore.cpp).
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
    char Unknown541C[0x5460 - 0x541c];
    UnitTrackerClass Trackers5460[4];       // +0x5460..+0x5490, meaning unknown (summed into the score line)
    UnitTrackerClass AircraftTotals;        // +0x54a0
    UnitTrackerClass InfantryTotals;        // +0x54b0
    UnitTrackerClass UnitTotals;            // +0x54c0
    UnitTrackerClass BuildingTotals;        // +0x54d0
    char Unknown54E0[0x15f16 - 0x54e0];
    wchar_t IniName[21];                    // +0x15f16
    int ColorSchemeIndex;                   // +0x15f40
};
extern DynamicVectorClass<HouseClass *> Houses;   // 0xa1a5c8

// One score line, 0x70 bytes (same record as MPScore.cpp).
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

// Defined in MPScore.cpp (0xa27534..0xa278bc); this TU fills the same records.
struct MPScoreData {
    MPScoreRecord Records[8];               // 0xa27534
    int GameNumber;                         // 0xa278b4
    int PlayerCount;                        // 0xa278b8
    int WinnerIndex;                        // 0xa278bc
};
extern MPScoreData ScoreData;

// Colour schemes (see MPScore.cpp).
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

// Network types (see NetDlg.CPP).
#pragma pack(push, 1)
class IPXAddressClass {
private:
    unsigned char NetworkNumber[4];
    unsigned char NodeAddress[6];
};

struct NodeNameType {
    wchar_t Name[20];               // +0x00
    IPXAddressClass Address;        // +0x28
};

// Global (session) packet, 0x1c7 bytes. Only the fields used here.
struct GlobalPacketType {
    int Command;                    // +0x00
    char Name[20];                  // +0x04 (narrow player name; size assumed)
    unsigned char Data[0x1c7 - 0x18];
};
#pragma pack(pop)

// RTTI .?AVIPXManagerClass@@ (vtable 0x78f6d4); only the non-virtual methods used here.
class IPXManagerClass {
public:
    int Send_Global_Message(void * buf, int buflen, int ack_req, IPXAddressClass * address);           // 0x524560
    int Get_Global_Message(void * buf, int * buflen, IPXAddressClass * address, unsigned short * product_id);  // 0x5245e0
    void Service();                                                                                     // 0x524890
};
extern IPXManagerClass Ipx;                     // 0xa285c8

class SessionClass {
public:
    int Type;                               // +0x00: 3 = LAN?, 4 = internet game, 5 = skirmish (provisional)
};
extern SessionClass Session;                // 0xa255c8
extern wchar_t SessionScenarioName[];       // 0xa25672 (Session + 0xaa, meaning provisional)
extern GlobalPacketType SessionGPacket;     // 0xa27966 (Session + 0x239e)
extern int SessionGPacketLength;            // 0xa27b30 (Session + 0x2568)
extern IPXAddressClass SessionGAddress;     // 0xa27b34 (Session + 0x256c)
extern unsigned short SessionGProductID;    // 0xa27b3e (Session + 0x2576)
extern DynamicVectorClass<NodeNameType *> SessionPlayers;  // 0xa27da8 (Session + 0x27e0)

char * To_Narrow(wchar_t const * string);   // 0x6eedc0, rotating 8 x 1024-byte buffers
void Windows_Message_Handler();                           // 0x5b29f0 (provisional)
bool Process_Global_Packet(GlobalPacketType * packet, IPXAddressClass * address);   // 0x5bb2a0 (provisional)

HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);   // 0x5f72d0
void Show_Dialog(HWND dialog);              // 0x5f7480
void End_Dialog(HWND dialog);               // 0x5f73a0
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
void Func_5F6B50(HWND dialog);              // 0x5f6b50 (provisional, WM_PAINT)
void Func_5DE390(HWND dialog);              // 0x5de390 (provisional, WM_PAINT)
void __stdcall Func_5E5050(HWND dialog, int value);   // 0x5e5050 (provisional)

class ScenarioClass {
public:
    char Unknown0[0x2239];
    bool Field2239;                         // +0x2239, meaning unknown
};
extern ScenarioClass * Scen;                // 0xa255c0

int Do_Modal_Dialog(int resource_id, DLGPROC proc, LPARAM param);   // 0x5e2e40
void Score_Screen_Begin(int flag);          // 0x6e7a20
void Score_Screen_End();                    // 0x6e7aa0
void Score_Screen_Prepare(int flag);        // 0x6e7700 (provisional)
void Score_Screen_Finish();                 // 0x6e7740 (provisional)
void Func_514F50(int a, bool b);            // 0x514f50 (provisional)
bool Func_5B6EF0();                         // 0x5b6ef0, session type 3 (provisional)
bool Func_732A40();                         // 0x732a40, session type 4 (provisional)
void Call_Back();                         // 0x4821e0 (provisional)

class CampaignScoreClass {
public:
    CampaignScoreClass();
    virtual ~CampaignScoreClass();
    virtual void Presentation(DynamicVectorClass<MPScoreRecord *> records, int time, bool ishost, int difficulty, wchar_t const * name);

    static void Format_Time(wchar_t * buffer, int seconds);
    static void Set_Dialog_Number(HWND dialog, int id, int value);
    void Compute_Scores();
    static void Sort_Scores();
    static int __cdecl Score_Compare(void const * a, void const * b);
    static void Clear_Flags(int count);     // all flags set, then the first count cleared
    static bool All_Flags_Set();
    static BOOL CALLBACK Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);
    static void Set_Flag(int index, bool value);
    static bool Get_Flag(int index);
    static bool Func_66670();               // no caller found in this TU; meaning unknown

    int Field4;
};

class CampaignEndScoreClass {
public:
    CampaignEndScoreClass();
    virtual ~CampaignEndScoreClass();
    virtual void Presentation(DynamicVectorClass<MPScoreRecord *> records, int time, int difficulty, int campaign, wchar_t const * name);

    static void Set_Dialog_Number(HWND dialog, int id, int value);
    static void Format_Time(wchar_t * buffer, int seconds);
    static void Sort_Scores();
    static BOOL CALLBACK Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);
};

// Network campaign score screen (dialog 0xbc6): every human player confirms with OK; the host
// sends PACKET_CAMPAIGN_CONTINUE once all are ready. CampaignEndScoreClass shows the final
// campaign result (dialog 0xbc7).

// ---- end of local declarations ----

#define WM_SET_COLOR            (WM_USER + 0x98)
#define WM_SET_TEXT_WIDE        (WM_USER + 0xB2)
#define WM_CAMPAIGN_HIDE        (WM_USER + 0xED)
#define MAX_SCORE_PLAYERS       8

#define IDD_CAMPAIGN_SCORE      0xbc6
#define IDD_CAMPAIGN_END_SCORE  0xbc7
#define IDC_CAMPAIGN_CANCEL     0x5c0
#define IDC_CAMPAIGN_OK         0x6d1
#define IDC_CAMPAIGN_TIME       0x3ea
#define IDC_CAMPAIGN_SCENARIO   0x71b
#define IDC_CAMPAIGN_DIFFICULTY 0x732
#define IDC_CAMPAIGN_NAME       0x733
#define IDC_CAMPAIGN_LABEL      0x735
#define IDC_END_MOVIE           0x72b
#define IDC_END_SECOND_SCORE    0x738
#define IDC_END_SECOND_NAME     0x739
#define IDC_END_FIRST_NAME      0x73a
#define IDC_END_FIRST_SCORE     0x73b
#define WM_DIALOG_INIT          (WM_USER + 0x97)

enum {
    PACKET_CAMPAIGN_READY = 0x23,
    PACKET_CAMPAIGN_ABORT = 0x24,
    PACKET_CAMPAIGN_WAITING = 0x25,
    PACKET_CAMPAIGN_CONTINUE = 0x26
};
#define CAMPAIGN_PRODUCT_ID     0xaa03

static RectangleStruct ScoreRect(0, 0, 0, 0);       // 0x838780

MPScoreRecord * CampaignSortedScores[MAX_SCORE_PLAYERS];   // 0x838790
int CampaignTime;                                   // 0x838850, game time in frames
int CampaignDifficulty = -1;                        // 0x7bc418

// Name, kills, lost, built, score and status controls of each line (0x7bc41c).
int CampaignControls[MAX_SCORE_PLAYERS][6] = {
    {0x411, 0x419, 0x6a3, 0x6a5, 0x6a6, 0x70a},
    {0x412, 0x41a, 0x6a4, 0x6a7, 0x6a8, 0x70b},
    {0x413, 0x41b, 0x6a9, 0x6aa, 0x6ab, 0x70c},
    {0x414, 0x41c, 0x6ac, 0x6ad, 0x6ae, 0x70d},
    {0x415, 0x41d, 0x6af, 0x6b0, 0x6b1, 0x70e},
    {0x416, 0x41e, 0x6b2, 0x6b3, 0x6b4, 0x70f},
    {0x417, 0x41f, 0x6b5, 0x6b6, 0x6b7, 0x710},
    {0x418, 0x420, 0x6b8, 0x6b9, 0x6ba, 0x711},
};

bool CampaignFlags[MAX_SCORE_PLAYERS];              // 0x838810, true = player ready (or computer)
bool CampaignContinue;                              // 0x83884c, true when the campaign goes on
int CampaignRecordCount;                            // 0x838854
bool CampaignIsReady;                               // 0x838858
wchar_t CampaignName[64];                           // 0x83885c (size unknown)

MPScoreRecord * EndSortedScores[MAX_SCORE_PLAYERS]; // 0x8387f0
int EndScoreCount;                                  // 0x838830
int EndDifficulty;                                  // 0x838818
int EndTime;                                        // 0x8387e4, game time in frames
int EndCampaignNumber;                              // 0x8387d0, shown with GUI:CampaignLabel
wchar_t EndName[64];                                // 0x83889c (size unknown)

// 0x465820
CampaignScoreClass::CampaignScoreClass()
{
    Field4 = 0;
    CampaignTime = 0;
    CampaignDifficulty = -1;
}

// 0x465840
CampaignScoreClass::~CampaignScoreClass()
{
}

// 0x465850; the original __LINE__ of the Fetch_String call is 100.
void CampaignScoreClass::Format_Time(wchar_t * buffer, int seconds)
{
    if (buffer != NULL) {
        if (seconds / 3600 > 99) {
            seconds = 99 * 3600 + 59 * 60 + 59;
        }
        int hours = seconds / 3600;
        seconds -= hours * 3600;
        int minutes = seconds / 60;
        seconds -= minutes * 60;
#line 100 "C:\\RA2\\CampScor.cpp"
        swprintf(buffer, Fetch_String("TXT_TIME_FORMAT_HOURS", NULL, __FILE__, __LINE__), hours, minutes, seconds);
    }
}

// 0x4658f0
void CampaignScoreClass::Set_Dialog_Number(HWND dialog, int id, int value)
{
    wchar_t buffer[32];
    swprintf(buffer, L"%d", value);
    HWND item = GetDlgItem(dialog, id);
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
}

// 0x465940
void CampaignScoreClass::Compute_Scores()
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
        ScoreData.Records[player].Lost = house->UnitsLost + house->BuildingsLost;
        int total = house->Trackers5460[0].Total();
        total += house->Trackers5460[1].Total();
        total += house->Trackers5460[2].Total();
        total += house->Trackers5460[3].Total();
        ScoreData.Records[player].Built = house->UnitsLost + house->BuildingsLost + total;
        if (house->Points > 0) {
            ScoreData.Records[player].Score += house->Points;
        }
        Debug_Printf("%s: %s\n Scheme: %d\n Lost = %d\n Kills = %d\n Built = %d\n Score = %d\n",
            ScoreData.Records[player].Name, ScoreData.Records[player].Wins > 0 ? "Winner" : "Loser",
            ScoreData.Records[player].Scheme, ScoreData.Records[player].Lost, ScoreData.Records[player].Kills,
            ScoreData.Records[player].Built, ScoreData.Records[player].Score);
    }
}

// 0x465b10
void CampaignScoreClass::Sort_Scores()
{
    int count = ScoreData.PlayerCount;
    for (int index = 0; index < count; index++) {
        CampaignSortedScores[index] = &ScoreData.Records[index];
    }
    if (count > 1) {
        qsort(CampaignSortedScores, count, sizeof(CampaignSortedScores[0]), Score_Compare);
    }
}

// 0x465b50: highest score first.
int __cdecl CampaignScoreClass::Score_Compare(void const * a, void const * b)
{
    MPScoreRecord * record1 = *(MPScoreRecord **)a;
    MPScoreRecord * record2 = *(MPScoreRecord **)b;
    if (record1->Score == record2->Score) return 0;
    return (record1->Score > record2->Score) ? -1 : 1;
}

// 0x465b80
void CampaignScoreClass::Clear_Flags(int count)
{
    memset(CampaignFlags, 1, sizeof(CampaignFlags));
    if (count > 0) {
        memset(CampaignFlags, 0, count);
    }
}

// 0x465bb0
bool CampaignScoreClass::All_Flags_Set()
{
    int index;
    for (index = 0; index < 8; index++) {
        if (!CampaignFlags[index]) break;
    }
    return index == 8;
}

// 0x465bd0
void CampaignScoreClass::Set_Flag(int index, bool value)
{
    CampaignFlags[index] = value;
}

// 0x465be0
bool CampaignScoreClass::Get_Flag(int index)
{
    return CampaignFlags[index];
}

// Sends a campaign score packet from the local player to all other players (always inlined).
static inline void Send_Campaign_Packet(int command)
{
    GlobalPacketType packet;
    memset(&packet, 0, sizeof(packet));
    packet.Command = command;
    strcpy(packet.Name, To_Narrow(SessionPlayers[0]->Name));
    for (int index = 1; index < SessionPlayers.ActiveCount; index++) {
        Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &SessionPlayers[index]->Address);
        Ipx.Service();
    }
}

// 0x465bf0. The status texts are block-local variables and count is declared before waiting;
// a function-level text variable or the other order permutes the spill slots.
BOOL CALLBACK CampaignScoreClass::Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) return result;

    int * retval = (int *)GetWindowLongA(dialog, DWL_USER);
    HWND item;
    wchar_t const * text;
    switch (message) {
        case WM_INITDIALOG:
        {
            wchar_t buffer[32];

            item = GetDlgItem(dialog, IDC_CAMPAIGN_SCENARIO);

            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)SessionScenarioName);
#line 281 "C:\\RA2\\CampScor.cpp"
            swprintf(buffer, L"%s: ", Fetch_String("GUI:Difficulty", NULL, __FILE__, __LINE__));
            if (CampaignDifficulty == 0) {
#line 283 "C:\\RA2\\CampScor.cpp"
                swprintf(buffer, Fetch_String("GUI:DifficultyString", NULL, __FILE__, __LINE__), Fetch_String("TXT_DIFFICULTY_EASY", NULL, __FILE__, __LINE__));
            } else if (CampaignDifficulty == 1) {
#line 285 "C:\\RA2\\CampScor.cpp"
                swprintf(buffer, Fetch_String("GUI:DifficultyString", NULL, __FILE__, __LINE__), Fetch_String("TXT_DIFFICULTY_MEDIUM", NULL, __FILE__, __LINE__));
            } else if (CampaignDifficulty == 2) {
#line 287 "C:\\RA2\\CampScor.cpp"
                swprintf(buffer, Fetch_String("GUI:DifficultyString", NULL, __FILE__, __LINE__), Fetch_String("TXT_DIFFICULTY_BRUTAL", NULL, __FILE__, __LINE__));
            }
            item = GetDlgItem(dialog, IDC_CAMPAIGN_DIFFICULTY);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
            item = GetDlgItem(dialog, IDC_CAMPAIGN_NAME);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)CampaignName);
            Format_Time(buffer, CampaignTime / 60);
            item = GetDlgItem(dialog, IDC_CAMPAIGN_TIME);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);

            Clear_Flags(0);
            for (int index = 0; index < ScoreData.PlayerCount; index++) {
#line 303 "C:\\RA2\\CampScor.cpp"
                if (wcscmp(CampaignSortedScores[index]->Name, Fetch_String("TXT_COMPUTER", NULL, __FILE__, __LINE__)) != 0) {
                    Set_Flag(index, false);
                }
                ColorSchemeClass * scheme = ColorSchemes[CampaignSortedScores[index]->Scheme];
                RGBClass rgb = scheme->BaseColor.To_RGB();
                COLORREF color = RGB(rgb.Red, rgb.Green, rgb.Blue);

                int id = CampaignControls[index][0];
                wchar_t const * name = CampaignSortedScores[index]->Name;
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)name);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = CampaignControls[index][1];
                Set_Dialog_Number(dialog, id, CampaignSortedScores[index]->Kills);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = CampaignControls[index][2];
                Set_Dialog_Number(dialog, id, CampaignSortedScores[index]->Lost);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = CampaignControls[index][3];
                Set_Dialog_Number(dialog, id, CampaignSortedScores[index]->Built);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = CampaignControls[index][4];
                Set_Dialog_Number(dialog, id, CampaignSortedScores[index]->Score);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                int count = SessionPlayers.ActiveCount;
                bool waiting = false;
                for (int player = 0; player < count; player++) {
                    if (wcscmp(SessionPlayers[player]->Name, CampaignSortedScores[index]->Name) == 0) {
                        waiting = true;
                        break;
                    }
                }
                id = CampaignControls[index][5];
                if (waiting) {
#line 363 "C:\\RA2\\CampScor.cpp"
                    wchar_t const * text = Fetch_String("TXT_WAITING", NULL, __FILE__, __LINE__);
                    item = GetDlgItem(dialog, id);
                    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)text);
                } else if (!Get_Flag(index)) {
#line 366 "C:\\RA2\\CampScor.cpp"
                    wchar_t const * text = Fetch_String("TXT_ABORTED", NULL, __FILE__, __LINE__);
                    item = GetDlgItem(dialog, id);
                    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)text);
                    EnableWindow(GetDlgItem(dialog, IDC_CAMPAIGN_OK), FALSE);
                }
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);
            }
            CampaignIsReady = false;
            return FALSE;
        }

        case WM_PAINT:
            Func_5F6B50(dialog);
            Func_5DE390(dialog);
            return FALSE;

        case WM_COMMAND:
            switch (LOWORD(wparam)) {
                case IDC_CAMPAIGN_CANCEL:
                    *retval = 2;
                    CampaignContinue = false;
                    if (Session.Type == 3 || Session.Type == 4) {
                        Send_Campaign_Packet(PACKET_CAMPAIGN_ABORT);
                    }
                    return TRUE;

                case IDC_CAMPAIGN_OK:
                    if (!CampaignIsReady) {
                        if (Session.Type == 3 || Session.Type == 4) {
                            Send_Campaign_Packet(PACKET_CAMPAIGN_READY);
                        }
                        for (int index = 0; index < ScoreData.PlayerCount; index++) {
                            int id = CampaignControls[index][5];
                            if (wcscmp(SessionPlayers[0]->Name, CampaignSortedScores[index]->Name) == 0) {
#line 411 "C:\\RA2\\CampScor.cpp"
                                wchar_t const * text = Fetch_String("TXT_READY", NULL, __FILE__, __LINE__);
                                item = GetDlgItem(dialog, id);
                                SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)text);
                                break;
                            }
                        }
#line 415 "C:\\RA2\\CampScor.cpp"
                        wchar_t const * text = Fetch_String("GUI:Cancel", NULL, __FILE__, __LINE__);
                        item = GetDlgItem(dialog, IDC_CAMPAIGN_OK);
                        SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)text);
                        EnableWindow(GetDlgItem(dialog, IDC_CAMPAIGN_CANCEL), FALSE);
                        *retval = 1;
                        CampaignIsReady = true;
                        InvalidateRect(dialog, NULL, FALSE);
                        return FALSE;
                    } else {
                        if (Session.Type == 3 || Session.Type == 4) {
                            Send_Campaign_Packet(PACKET_CAMPAIGN_WAITING);
                        }
                        for (int index = 0; index < ScoreData.PlayerCount; index++) {
                            int id = CampaignControls[index][5];
                            if (wcscmp(SessionPlayers[0]->Name, CampaignSortedScores[index]->Name) == 0) {
#line 430 "C:\\RA2\\CampScor.cpp"
                                wchar_t const * text = Fetch_String("TXT_WAITING", NULL, __FILE__, __LINE__);
                                item = GetDlgItem(dialog, id);
                                SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)text);
                                break;
                            }
                        }
#line 435 "C:\\RA2\\CampScor.cpp"
                        wchar_t const * text = Fetch_String("GUI:Continue", NULL, __FILE__, __LINE__);
                        item = GetDlgItem(dialog, IDC_CAMPAIGN_OK);
                        SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)text);
                        EnableWindow(GetDlgItem(dialog, IDC_CAMPAIGN_CANCEL), TRUE);
                        *retval = 1;
                        CampaignIsReady = false;
                        InvalidateRect(dialog, NULL, FALSE);
                        return FALSE;
                    }
            }
            break;

        case WM_CAMPAIGN_HIDE:
            Func_514F50(0, true);
            Func_5E5050(dialog, 1);
            ShowWindow(dialog, SW_HIDE);
            break;
    }
    return FALSE;
}
// 0x466670
bool CampaignScoreClass::Func_66670()
{
    if (Session.Type == 3) return Func_5B6EF0();
    if (Session.Type == 4) return Func_732A40();
    Call_Back();
    return false;
}

// level-2 1.001: the Set_Text helper follows gibbo101/ra2-decomp src/campscor.cpp _Set_Text
// @94adbad041a96d176a6e5758da3916aa9b60980a (GPL-3.0-or-later, YR 1.001). Writing the three
// GetDlgItem/SendMessageA pairs through this inline (instead of flat) gives 1.001's register choice
// for the GetDlgItem/EnableWindow import pointers in the PACKET_CAMPAIGN_ABORT branch (edi/esi).
static inline void Set_Text(HWND dialog, int id, wchar_t const * text)
{
    HWND item = GetDlgItem(dialog, id);
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)text);
}

// 0x4666a0
void CampaignScoreClass::Presentation(DynamicVectorClass<MPScoreRecord *> records, int time, bool ishost, int difficulty, wchar_t const * name)
{
    CampaignRecordCount = records.ActiveCount;
    CampaignTime = time;
    CampaignDifficulty = difficulty;
    wcscpy(CampaignName, name);
    Clear_Flags(MAX_SCORE_PLAYERS);
    for (int index = 0; index < CampaignRecordCount; index++) {
        CampaignSortedScores[index] = records[index];
    }
    Compute_Scores();
    Sort_Scores();
    Score_Screen_Prepare(!Scen->Field2239);
    Func_514F50(0, true);

    HWND dialog = Create_Dialog(IDD_CAMPAIGN_SCORE, Dialog_Proc, 0);
    int result = 0;
    if (dialog != NULL) {
        SetWindowLongA(dialog, DWL_USER, (LONG)&result);
        Show_Dialog(dialog);
        while (result == 0 || result == 1) {
            Windows_Message_Handler();
            if (result == 1) {
                int index;
                for (index = 0; index < ScoreData.PlayerCount; index++) {
                    if (wcscmp(SessionPlayers[0]->Name, CampaignSortedScores[index]->Name) == 0) break;
                }
                if (CampaignIsReady) {
                    Set_Flag(index, true);
                } else {
                    Set_Flag(index, false);
                }
                if (All_Flags_Set() && ishost) {
                    CampaignContinue = true;
                    Send_Campaign_Packet(PACKET_CAMPAIGN_CONTINUE);
                    break;
                }
                if (!ishost) {
                    CampaignContinue = false;
                    break;
                }
                result = 0;
            }

            Ipx.Service();
            if (Ipx.Get_Global_Message(&SessionGPacket, &SessionGPacketLength, &SessionGAddress, &SessionGProductID)
                && SessionGProductID == CAMPAIGN_PRODUCT_ID && !Process_Global_Packet(&SessionGPacket, &SessionGAddress)) {

                if (SessionGPacket.Command == PACKET_CAMPAIGN_READY) {
                    for (int index = 0; index < ScoreData.PlayerCount; index++) {
                        if (strcmp(SessionGPacket.Name, To_Narrow(CampaignSortedScores[index]->Name)) == 0) {
                            int id = CampaignControls[index][5];
#line 574 "C:\\RA2\\CampScor.cpp"
                            Set_Text(dialog, id, Fetch_String("TXT_READY", NULL, __FILE__, __LINE__));
                            Set_Flag(index, true);
                            break;
                        }
                    }
                    if (All_Flags_Set() && ishost) {
                        CampaignContinue = true;
                        Send_Campaign_Packet(PACKET_CAMPAIGN_CONTINUE);
                        break;
                    }
                } else if (SessionGPacket.Command == PACKET_CAMPAIGN_ABORT) {
                    for (int index = 0; index < ScoreData.PlayerCount; index++) {
                        if (strcmp(SessionGPacket.Name, To_Narrow(CampaignSortedScores[index]->Name)) == 0) {
                            int id = CampaignControls[index][5];
#line 594 "C:\\RA2\\CampScor.cpp"
                            Set_Text(dialog, id, Fetch_String("TXT_ABORTED", NULL, __FILE__, __LINE__));
                            Set_Flag(index, false);
                            break;
                        }
                    }
                    for (int player = 0; player < SessionPlayers.ActiveCount; player++) {
                        if (strcmp(SessionGPacket.Name, To_Narrow(SessionPlayers[player]->Name)) == 0) {
                            delete SessionPlayers[player];
                            SessionPlayers.Delete(SessionPlayers[player]);
                            break;
                        }
                    }
                    EnableWindow(GetDlgItem(dialog, IDC_CAMPAIGN_OK), FALSE);
                    EnableWindow(GetDlgItem(dialog, IDC_CAMPAIGN_CANCEL), TRUE);
                } else if (SessionGPacket.Command == PACKET_CAMPAIGN_WAITING) {
                    for (int index = 0; index < ScoreData.PlayerCount; index++) {
                        if (strcmp(SessionGPacket.Name, To_Narrow(CampaignSortedScores[index]->Name)) == 0) {
                            int id = CampaignControls[index][5];
#line 617 "C:\\RA2\\CampScor.cpp"
                            Set_Text(dialog, id, Fetch_String("TXT_WAITING", NULL, __FILE__, __LINE__));
                            Set_Flag(index, false);
                            break;
                        }
                    }
                } else if (SessionGPacket.Command == PACKET_CAMPAIGN_CONTINUE) {
                    CampaignContinue = true;
                    break;
                } else {
                    if (All_Flags_Set() && ishost) {
                        CampaignContinue = true;
                        Send_Campaign_Packet(PACKET_CAMPAIGN_CONTINUE);
                        break;
                    }
                }
            }
        }
        Func_514F50(0, true);
        End_Dialog(dialog);
        Func_514F50(0, true);
    }
    Score_Screen_Finish();
}

// 0x466e30
CampaignEndScoreClass::CampaignEndScoreClass()
{
    EndDifficulty = -1;
    EndScoreCount = 0;
    EndTime = 0;
}

// 0x466e60
CampaignEndScoreClass::~CampaignEndScoreClass()
{
}

// 0x466e70
void CampaignEndScoreClass::Set_Dialog_Number(HWND dialog, int id, int value)
{
    wchar_t buffer[32];
    swprintf(buffer, L"%d", value);
    HWND item = GetDlgItem(dialog, id);
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
}

// 0x466ec0; the original __LINE__ of the Fetch_String call is 688.
void CampaignEndScoreClass::Format_Time(wchar_t * buffer, int seconds)
{
    if (buffer != NULL) {
        if (seconds / 3600 > 99) {
            seconds = 99 * 3600 + 59 * 60 + 59;
        }
        int hours = seconds / 3600;
        seconds -= hours * 3600;
        int minutes = seconds / 60;
        seconds -= minutes * 60;
#line 688 "C:\\RA2\\CampScor.cpp"
        swprintf(buffer, Fetch_String("TXT_TIME_FORMAT_HOURS", NULL, __FILE__, __LINE__), hours, minutes, seconds);
    }
}

// 0x466f60. The cases leave with break (single return at the end); with per-case returns VC6
// saves ebp only inside the WM_INITDIALOG branch instead of right after the early return.
BOOL CALLBACK CampaignEndScoreClass::Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) return result;

    int * retval = (int *)GetWindowLongA(dialog, DWL_USER);
    HWND item;

    switch (message) {
        case WM_INITDIALOG:
        {
            wchar_t buffer[32];
            buffer[0] = L'\0';

            item = GetDlgItem(dialog, IDC_CAMPAIGN_NAME);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)EndName);
#line 710 "C:\\RA2\\CampScor.cpp"
            swprintf(buffer, Fetch_String("GUI:CampaignLabel", NULL, __FILE__, __LINE__), EndCampaignNumber);
            item = GetDlgItem(dialog, IDC_CAMPAIGN_LABEL);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
            if (EndDifficulty == 0) {
#line 714 "C:\\RA2\\CampScor.cpp"
                swprintf(buffer, Fetch_String("GUI:DifficultyString", NULL, __FILE__, __LINE__), Fetch_String("TXT_DIFFICULTY_EASY", NULL, __FILE__, __LINE__));
            } else if (EndDifficulty == 1) {
#line 716 "C:\\RA2\\CampScor.cpp"
                swprintf(buffer, Fetch_String("GUI:DifficultyString", NULL, __FILE__, __LINE__), Fetch_String("TXT_DIFFICULTY_MEDIUM", NULL, __FILE__, __LINE__));
            } else if (EndDifficulty == 2) {
#line 718 "C:\\RA2\\CampScor.cpp"
                swprintf(buffer, Fetch_String("GUI:DifficultyString", NULL, __FILE__, __LINE__), Fetch_String("TXT_DIFFICULTY_BRUTAL", NULL, __FILE__, __LINE__));
            } else {
#line 720 "C:\\RA2\\CampScor.cpp"
                swprintf(buffer, Fetch_String("GUI:Blank", NULL, __FILE__, __LINE__));
            }
            item = GetDlgItem(dialog, IDC_CAMPAIGN_DIFFICULTY);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
            Format_Time(buffer, EndTime / 60);
            item = GetDlgItem(dialog, IDC_CAMPAIGN_TIME);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);

            for (int index = 0; index < EndScoreCount; index++) {
                ColorSchemeClass * scheme = ColorSchemes[EndSortedScores[index]->Scheme];
                RGBClass rgb = scheme->BaseColor.To_RGB();
                COLORREF color = RGB(rgb.Red, rgb.Green, rgb.Blue);

                int id = CampaignControls[index][0];
                wchar_t const * name = EndSortedScores[index]->Name;
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)name);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = CampaignControls[index][1];
                Set_Dialog_Number(dialog, id, EndSortedScores[index]->Kills);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = CampaignControls[index][2];
                Set_Dialog_Number(dialog, id, EndSortedScores[index]->Lost);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = CampaignControls[index][3];
                Set_Dialog_Number(dialog, id, EndSortedScores[index]->Built);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                id = CampaignControls[index][4];
                Set_Dialog_Number(dialog, id, EndSortedScores[index]->Score);
                item = GetDlgItem(dialog, id);
                SendMessageA(item, WM_SET_COLOR, 0, color);

                if (index == 0) {
                    name = EndSortedScores[index]->Name;
                    item = GetDlgItem(dialog, IDC_END_FIRST_NAME);
                    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)name);
                    item = GetDlgItem(dialog, IDC_END_FIRST_NAME);
                    SendMessageA(item, WM_SET_COLOR, 0, color);
                    swprintf(buffer, L"%d", EndSortedScores[index]->Score);
                    item = GetDlgItem(dialog, IDC_END_FIRST_SCORE);
                    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
                    item = GetDlgItem(dialog, IDC_END_FIRST_SCORE);
                    SendMessageA(item, WM_SET_COLOR, 0, color);
                } else if (index == 1) {
                    name = EndSortedScores[index]->Name;
                    item = GetDlgItem(dialog, IDC_END_SECOND_NAME);
                    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)name);
                    item = GetDlgItem(dialog, IDC_END_SECOND_NAME);
                    SendMessageA(item, WM_SET_COLOR, 0, color);
                    swprintf(buffer, L"%d", EndSortedScores[index]->Score);
                    item = GetDlgItem(dialog, IDC_END_SECOND_SCORE);
                    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
                    item = GetDlgItem(dialog, IDC_END_SECOND_SCORE);
                    SendMessageA(item, WM_SET_COLOR, 0, color);
                }
            }
            break;
        }

        case WM_COMMAND:
            if (LOWORD(wparam) == IDC_CAMPAIGN_OK) {
                *retval = 1;
                break;
            }
            break;

        case WM_PAINT:
            Func_5F6B50(dialog);
            Func_5DE390(dialog);
            break;

        case WM_DIALOG_INIT:
            item = GetDlgItem(dialog, IDC_END_MOVIE);
            PostMessageA(item, WM_USER + 0xD7, 0, (LPARAM)dialog);
            break;

        case WM_USER + 0xD8:
            if (wparam == 0) {
                SendDlgItemMessageA(dialog, IDC_END_MOVIE, WM_USER + 0xD5, 0, 0x1d);
            }
            break;

        case WM_USER + 0xEC:
            SendDlgItemMessageA(dialog, IDC_END_MOVIE, WM_USER + 0xD3, 0, 0);
            break;

        case WM_CAMPAIGN_HIDE:
            Func_514F50(0, true);
            ShowWindow(dialog, SW_HIDE);
            Func_5E5050(dialog, 1);
            break;
    }
    return FALSE;
}

// 0x467630
void CampaignEndScoreClass::Sort_Scores()
{
    if (EndScoreCount > 1) {
        qsort(EndSortedScores, EndScoreCount, sizeof(EndSortedScores[0]), CampaignScoreClass::Score_Compare);
    }
}

// 0x467650
void CampaignEndScoreClass::Presentation(DynamicVectorClass<MPScoreRecord *> records, int time, int difficulty, int campaign, wchar_t const * name)
{
    EndScoreCount = records.ActiveCount;
    wcscpy(EndName, name);
    for (int index = 0; index < EndScoreCount; index++) {
        EndSortedScores[index] = records[index];
    }
    Sort_Scores();
    EndCampaignNumber = campaign;
    EndDifficulty = difficulty;
    EndTime = time;
    int flag = !Scen->Field2239;
    Score_Screen_Prepare(flag);
    Score_Screen_Begin(flag);
    Func_514F50(0, true);
    Do_Modal_Dialog(0xbc7, Dialog_Proc, 0);
    Score_Screen_End();
    Score_Screen_Finish();
}
