// C:\RA2\Conquer.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Main game helpers: the game loop driver, special dialogs, the network call-backs, the
// global packet dispatcher, name/enum conversions, free disk space and the mpstats.txt dump.
// Class names come from RTTI; all other names are provisional.
#include "GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)

enum SourceType { SOURCE_NONE = -1, SOURCE_FIRST = 0, SOURCE_COUNT = 5 };
enum TheaterType { THEATER_NONE = -1, THEATER_FIRST = 0, THEATER_COUNT = 3 };
enum FacingType { FACING_NONE = -1, FACING_N, FACING_NE, FACING_E, FACING_SE, FACING_S,
    FACING_SW, FACING_W, FACING_NW };
enum CrateType { CRATE_MONEY = 0, CRATE_COUNT = 19 };
enum HousesType { HOUSE_NONE = -1 };
enum LandType { LAND_NONE = -1, LAND_FIRST = 0, LAND_COUNT = 12 };
enum SpeedType { SPEED_NONE = -1, SPEED_FIRST = 0, SPEED_COUNT = 8 };
enum LayerType { LAYER_NONE = -1, LAYER_FIRST = 0, LAYER_COUNT = 5 };

// Key number modifier bits (masked off by KN_To_Facing).
enum {
    KN_SHIFT_BIT = 0x100, KN_CTRL_BIT = 0x200, KN_ALT_BIT = 0x400,
    KN_PGUP = 0x21, KN_PGDN = 0x22, KN_END = 0x23, KN_HOME = 0x24,
    KN_LEFT = 0x25, KN_UP = 0x26, KN_RIGHT = 0x27, KN_DOWN = 0x28
};

// Theater description, 0x68 bytes (table at 0x785b68, three entries). Only the name is used here.
struct TheaterDataType {
    char Name[16];                              // +0x00 "TEMPERATE", "SNOW", "URBAN"
    char Unknown10[0x68 - 0x10];
};

extern char const * SourceName[SOURCE_COUNT];   // 0x785b50 North/East/South/West/Air
extern TheaterDataType const Theaters[THEATER_COUNT];  // 0x785b68
extern char const * CrateNames[CRATE_COUNT];    // 0x788e54 Money..Pod
extern char const * LandNames[LAND_COUNT];      // 0x7be9ac Clear..Weeds
extern char const * SpeedNames[SPEED_COUNT];    // 0x7be9dc Foot..FloatBeach
extern char const * LayerNames[LAYER_COUNT];    // 0x7be9fc Underground..Top
extern DynamicVectorClass<char *> NameList_A58C68;  // 0xa58c68, list of names (meaning unknown)

class HouseTypeClass {
public:
    static HousesType From_Name(char const * name);    // 0x4f89d0
};

// RTTI ids used by Fetch_Techno_Type (values from the switch; names provisional).
enum RTTIType {
    RTTI_UNIT = 1, RTTI_AIRCRAFT = 2, RTTI_AIRCRAFTTYPE = 3, RTTI_BUILDING = 6,
    RTTI_BUILDINGTYPE = 7, RTTI_INFANTRY = 15, RTTI_INFANTRYTYPE = 16, RTTI_UNITTYPE = 40
};
class TechnoTypeClass {
};
class UnitTypeClass : public TechnoTypeClass {
};
class AircraftTypeClass : public TechnoTypeClass {
};
class BuildingTypeClass : public TechnoTypeClass {
};
class InfantryTypeClass : public TechnoTypeClass {
};
extern DynamicVectorClass<UnitTypeClass *> UnitTypes;          // 0xa1e078
extern DynamicVectorClass<AircraftTypeClass *> AircraftTypes;  // 0xa255a8
extern DynamicVectorClass<BuildingTypeClass *> BuildingTypes;  // 0xa1e008
extern DynamicVectorClass<InfantryTypeClass *> InfantryTypes;  // 0xa27fa0

// Elements of the list at 0xa288a0; virtual slot 81 (+0x144) removes the object from that list.
class ListObject_A288A0 {
public:
    virtual void Slot_00(); virtual void Slot_01(); virtual void Slot_02(); virtual void Slot_03();
    virtual void Slot_04(); virtual void Slot_05(); virtual void Slot_06(); virtual void Slot_07();
    virtual void Slot_08(); virtual void Slot_09(); virtual void Slot_10(); virtual void Slot_11();
    virtual void Slot_12(); virtual void Slot_13(); virtual void Slot_14(); virtual void Slot_15();
    virtual void Slot_16(); virtual void Slot_17(); virtual void Slot_18(); virtual void Slot_19();
    virtual void Slot_20(); virtual void Slot_21(); virtual void Slot_22(); virtual void Slot_23();
    virtual void Slot_24(); virtual void Slot_25(); virtual void Slot_26(); virtual void Slot_27();
    virtual void Slot_28(); virtual void Slot_29(); virtual void Slot_30(); virtual void Slot_31();
    virtual void Slot_32(); virtual void Slot_33(); virtual void Slot_34(); virtual void Slot_35();
    virtual void Slot_36(); virtual void Slot_37(); virtual void Slot_38(); virtual void Slot_39();
    virtual void Slot_40(); virtual void Slot_41(); virtual void Slot_42(); virtual void Slot_43();
    virtual void Slot_44(); virtual void Slot_45(); virtual void Slot_46(); virtual void Slot_47();
    virtual void Slot_48(); virtual void Slot_49(); virtual void Slot_50(); virtual void Slot_51();
    virtual void Slot_52(); virtual void Slot_53(); virtual void Slot_54(); virtual void Slot_55();
    virtual void Slot_56(); virtual void Slot_57(); virtual void Slot_58(); virtual void Slot_59();
    virtual void Slot_60(); virtual void Slot_61(); virtual void Slot_62(); virtual void Slot_63();
    virtual void Slot_64(); virtual void Slot_65(); virtual void Slot_66(); virtual void Slot_67();
    virtual void Slot_68(); virtual void Slot_69(); virtual void Slot_70(); virtual void Slot_71();
    virtual void Slot_72(); virtual void Slot_73(); virtual void Slot_74(); virtual void Slot_75();
    virtual void Slot_76(); virtual void Slot_77(); virtual void Slot_78(); virtual void Slot_79();
    virtual void Slot_80();
    virtual void Remove_This();                 // slot 81 (+0x144), meaning provisional
};
extern DynamicVectorClass<ListObject_A288A0 *> ObjectList_A288A0;  // 0xa288a0
void Func_6EB5E0(int value);                    // 0x6eb5e0 (meaning unknown)

// Object at 0x836c18 (class not bound); methods called from this TU.
class Object_836C18 {
public:
    void Func_42E340(int a, CoordStruct coord, int b);  // 0x42e340
    void Func_42E7E0();                         // 0x42e7e0
    void Func_42E940(int a, int b);             // 0x42e940
    void Func_42EB70(void * data, int a, int b, int c); // 0x42eb70
};
extern Object_836C18 Object836C18;              // 0x836c18

// RTTI .?AVWinsockInterfaceClass@@ (vtable 0x79a8b4); slots up to 19.
class WinsockInterfaceClass {
public:
    virtual ~WinsockInterfaceClass();
    virtual void Slot_01(); virtual void Slot_02(); virtual void Slot_03(); virtual void Slot_04();
    virtual void Slot_05(); virtual void Slot_06(); virtual void Slot_07(); virtual void Slot_08();
    virtual void Slot_09(); virtual void Slot_10(); virtual void Slot_11(); virtual void Slot_12();
    virtual void Slot_13(); virtual void Slot_14(); virtual void Slot_15(); virtual void Slot_16();
    virtual void Slot_17();
    virtual int Get_Num_Local_Addresses();      // slot 18 (+0x48), meaning provisional
    virtual unsigned char * Get_Local_Address(int index);  // slot 19 (+0x4c), meaning provisional
};
extern WinsockInterfaceClass * PacketTransport; // 0x821f90

typedef unsigned char NetNumType[4];
typedef unsigned char NetNodeType[6];
#pragma pack(push, 1)
class IPXAddressClass {
public:
    void Get_Address(NetNumType net, NetNodeType node);    // 0x522a60
    bool operator == (IPXAddressClass & address);          // 0x522ae0
private:
    NetNumType NetworkNumber;
    NetNodeType NodeAddress;
};
#pragma pack(pop)

// Per-player network statistics, 0x68 bytes, eight entries at Session + 0x2ec (0xa258b4).
struct NetStatsType {
    char Name[0x40];                            // +0x00 (size assumed)
    int MaxRoundTrip;                           // +0x40
    int Resends;                                // +0x44
    int Lost;                                   // +0x48
    int PercentLost;                            // +0x4c
    int MaxAvgRoundTrip;                        // +0x50
    int FrameSyncStalls;                        // +0x54
    int CommandCountStalls;                     // +0x58
    IPXAddressClass Address;                    // +0x5c
    char Unknown66[0x68 - 0x66];
};

enum GameEnum { GAME_NORMAL = 0, GAME_MODEM = 1, GAME_NULL_MODEM = 2, GAME_IPX = 3,
    GAME_INTERNET = 4, GAME_SKIRMISH = 5 };     // values from usage; names provisional
class SessionClass {
public:
    int Player_Color(int id);                   // 0x667a20 (meaning provisional)
    void Func_669010();                         // 0x669010 (meaning unknown)
    void Func_6690A0();                         // 0x6690a0 (meaning unknown)
    void Func_667120();                         // 0x667120 (meaning unknown)

    int Type;                                   // +0x0000
};
extern SessionClass Session;                    // 0xa255c8
extern int SessionMaxMaxAhead;                  // 0xa258a8  (Session + 0x2e0)
extern NetStatsType SessionNetStats[8];         // 0xa258b4  (Session + 0x2ec)
extern int SessionLatency;                      // 0xa27ed0  (Session + 0x2908)

extern int NetworkEventMode;                    // 0xa2896c, printed as the frame count

class OptionsClass {
public:
    void Process();                             // 0x5d29e0, options dialog (provisional)

    int GameSpeed;                              // +0x00
    char Unknown04[0x1C - 0x04];
    bool ToolTips;                              // +0x1c (see GameDlg.CPP)
};
extern OptionsClass Options;                    // 0xa28758

// Frame rate counters (0xa56750 total frames, 0xa56754 seconds; meaning provisional).
extern unsigned FrameRateTotal;                 // 0xa56750
extern unsigned FrameRateCount;                 // 0xa56754
inline unsigned Average_FPS()
{
    return FrameRateCount ? FrameRateTotal / FrameRateCount : 0;
}

struct SessionModemFlagsType {
    unsigned ModemService : 1;
};
extern SessionModemFlagsType SessionModemFlags; // 0xa27dec  (Session + 0x2824), see NullDlg.CPP
enum ModemGameType { MODEM_NULL_HOST, MODEM_NULL_JOIN, MODEM_DIALER, MODEM_ANSWERER };
extern ModemGameType SessionModemGameToPlay;    // 0xa27e64  (Session + 0x289c), see NullDlg.CPP

// Null-modem manager at 0xa28668 (class not bound).
class NullModemClass {
public:
    int Get_Message(void * buf, int * buflen);  // 0x5c8cc0
    int Service();                              // 0x5c8cf0
};
extern NullModemClass NullModem;                // 0xa28668

// Serial packet as received from NullModem.Get_Message (layout partly known).
#pragma pack(push, 1)
struct SerialPacketType {
    int Command;                                // +0x00
    char Unknown04[0x18 - 0x04];
    unsigned char ID;                           // +0x18
    int Value;                                  // +0x19
    char Unknown1D[0xFC - 0x1D];
};
#pragma pack(pop)
enum { SERIAL_COMMAND_6C = 0x6C };              // provisional name

// Two ints passed by value (meaning provisional).
struct Point2DStruct {
    int X;
    int Y;
    Point2DStruct(int x, int y) : X(x), Y(y) {}
};

// Object at 0xa5e540 (class not bound).
class Object_A5E540 {
public:
    void Func_617D70(int index, double value, Point2DStruct point = Point2DStruct(-1, -1));  // 0x617d70
};
extern Object_A5E540 ObjectA5E540;              // 0xa5e540

class ScenarioClass {
public:
    void Func_632630();                         // 0x632630 (dialog, meaning unknown)

    char Unknown0[0x22FC];
    bool Field22FC;                             // +0x22fc, meaning unknown
    char Unknown22FD[0x2306 - 0x22FD];
    bool Field2306;                             // +0x2306, meaning unknown
};
extern ScenarioClass * Scen;                    // 0xa255c0

// COM objects at 0xa5a874 / 0xa5a878 (Westwood Online; interfaces not bound).
struct IChatLike : public IUnknown {
    virtual HRESULT __stdcall PumpMessages() = 0;   // slot 3
};
struct IDownloadLike : public IUnknown {
    virtual HRESULT __stdcall Slot_03() = 0;
    virtual HRESULT __stdcall Slot_04() = 0;
    virtual HRESULT __stdcall Slot_05() = 0;
    virtual HRESULT __stdcall Slot_06() = 0;
    virtual HRESULT __stdcall PumpMessages() = 0;   // slot 7
};
extern IChatLike * WOLChat;                     // 0xa5a874
extern IDownloadLike * WOLDownload;             // 0xa5a878
extern bool Flag_B100A2;                        // 0xb100a2 (meaning unknown)
extern int Flag_B100AC;                         // 0xb100ac (meaning unknown)
extern time_t LastPumpTime;                     // 0x839140

// Global (session) packet, 0x1c7 bytes. Only the fields used here; the union members are
// named after the commands that read them (meanings provisional).
#pragma pack(push, 1)
struct GlobalPacketType {
    int Command;                                // +0x00
    char Name[0x2F - 0x04];                     // +0x04 narrow player name (size assumed)
    union {
        int ID;                                 // +0x2f
        struct {
            int X;                              // +0x2f
            int Y;                              // +0x33
            int Z;                              // +0x37
            char B;                             // +0x3b
            char A;                             // +0x3c
        } Location;
        struct {
            char B;                             // +0x2f
            char A;                             // +0x30
            unsigned char Data[1];              // +0x31
        } Raw;
        struct {
            unsigned char Recipients;           // +0x2f, mask tested against the host manager
            wchar_t Text[0x70];                 // +0x30
            int ID;                             // +0x110
            int NameCRC;                        // +0x114
        } Message;
        struct {
            unsigned char Recipients;           // +0x2f
            char Value;                         // +0x30
            char Unknown31[4];
            int NameCRC;                        // +0x35
        } Signal;
    };
    unsigned char Unknown[0x1C7 - 0x118];
};
#pragma pack(pop)

// Global packet commands handled here (values from the switch; names provisional except
// NET_IM_STILL_HERE, which the debug string names).
enum NetCommandType {
    NET_COMMAND_10 = 10, NET_MESSAGE = 12, NET_COMMAND_15 = 15, NET_COMMAND_16 = 16,
    NET_COMMAND_19 = 19, NET_COMMAND_28 = 28, NET_COMMAND_29 = 29, NET_COMMAND_32 = 32,
    NET_COMMAND_33 = 33, NET_COMMAND_34 = 34, NET_IM_STILL_HERE = 39
};
enum { GLOBAL_PRODUCT_ID = 0xAA03 };

// RTTI .?AVIPXManagerClass@@ (vtable 0x78f6d4); only the non-virtual methods used here.
class IPXManagerClass {
public:
    int Num_Connections();                      // 0x524450
    int Connection_ID(int index);               // 0x524460
    wchar_t * Connection_Name(int id);          // 0x524480
    IPXAddressClass * Connection_Address(int id);   // 0x5244c0
    int Get_Global_Message(void * buf, int * buflen, IPXAddressClass * address, unsigned short * product_id);  // 0x5245e0
    void Service();                             // 0x524890
};
extern IPXManagerClass Ipx;                     // 0xa285c8

struct NodeNameType {
    wchar_t Name[20];                           // +0x00 (assumed)
    IPXAddressClass Address;                    // +0x28
};

extern bool SessionFlag2373;                    // 0xa2793b  (Session + 0x2373, meaning unknown)
extern bool SessionFlag2374;                    // 0xa2793c  (Session + 0x2374, meaning unknown)
extern wchar_t SessionName2376[];               // 0xa2793e  (Session + 0x2376); same address as SessionWord2376
extern GlobalPacketType SessionGPacket;         // 0xa27966  (Session + 0x239e)
extern int SessionGPacketLength;                // 0xa27b30  (Session + 0x2568)
extern IPXAddressClass SessionGAddress;         // 0xa27b34  (Session + 0x256c)
extern unsigned short SessionGProductID;        // 0xa27b3e  (Session + 0x2576)
extern bool SessionFlag1E86;                    // 0xa2744e  (Session + 0x1e86, meaning unknown)
extern bool SessionFlag1E87;                    // 0xa2744f  (Session + 0x1e87, meaning unknown)
extern wchar_t SessionLastMessage[];            // 0xa27450  (Session + 0x1e88, meaning provisional)
extern DynamicVectorClass<NodeNameType *> SessionPlayers;  // 0xa27da8 (Session + 0x27e0)
extern bool SessionHostMigration;               // 0xa27ed4  (Session + 0x290c, meaning provisional)

class MessageListClass {
public:
    void * Add_Message(wchar_t const * name, int id, wchar_t const * text, int color,
        int style, int timeout, bool flag);     // 0x5b1980
};
extern MessageListClass SessionMessages;        // 0xa25fa0  (Session + 0x9d8)

// Object at 0xa9e820 (class not bound).
class HostManagerClass {
public:
    unsigned char Recipient_Mask(IPXAddressClass * address);  // 0x6367f0 (meaning provisional)
};
extern HostManagerClass HostManager;            // 0xa9e820

class RulesClass {
public:
    char Unknown00[0x5CC];
    int IncomingMessage;                        // +0x5cc, sound played for a message (provisional)
    char Unknown5D0[0x1128 - 0x5D0];
    double MessageDelay;                        // +0x1128, minutes
};
extern RulesClass * Rule;                       // 0x821b88

class GScreenClass {
public:
    virtual void Flag_To_Redraw(int complete);  // 0x4e0030
};
class MouseClass : public GScreenClass {
public:
    void Func_62BFA0();                         // 0x62bfa0 (dialog 0x73, meaning unknown)
};
extern MouseClass Map;                          // 0x81a820

void Windows_Message_Handler();                               // 0x5b29f0 (provisional)
bool Process_Global_Packet(GlobalPacketType * packet, IPXAddressClass * address);   // 0x5bb2a0 (provisional)
char * To_Narrow(wchar_t const * string);       // 0x6eedc0
wchar_t * To_Wide(char const * string);         // 0x6eee20, rotating buffers (name provisional)
unsigned long Compute_Name_CRC(wchar_t const * name);   // 0x5b6c30 (name provisional)
void Func_61E9D0(GlobalPacketType * packet, IPXAddressClass * address);  // 0x61e9d0
void Func_61AE90(int index);                    // 0x61ae90, stores timeGetTime per connection
void Func_5B6760(int id, int flag);             // 0x5b6760
void Func_70AB70(char value);                   // 0x70ab70
void Sound_Effect_708970(int voc, int flags, float volume, int priority);  // 0x708970 (provisional)

void Func_406EA0();                             // 0x406ea0 (meaning unknown)

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60

// Mouse (RTTI .?AVMouse@@, 18 slots; only the first eleven are needed here).
class Mouse {
public:
    virtual ~Mouse();
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Hide_Mouse() = 0;              // slot 3
    virtual void Show_Mouse() = 0;              // slot 4
    virtual void Release_Mouse() = 0;           // slot 5 (meaning provisional)
    virtual void Capture_Mouse() = 0;           // slot 6 (meaning provisional)
    virtual void Slot7() = 0;
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
    virtual int Get_Mouse_State() = 0;          // slot 10, hide count (meaning provisional)
};
extern Mouse * WWMouse;                         // 0x821fa8

// Mode for Special_Dialog (values from its switch; names provisional).
enum SpecialDialogType {
    SDLG_NONE = 0, SDLG_1 = 1, SDLG_SURRENDER = 2, SDLG_3 = 3, SDLG_OPTIONS = 4,
    SDLG_GAME_CONTROLS = 5, SDLG_6 = 6, SDLG_7 = 7, SDLG_8 = 8, SDLG_9 = 9
};
extern int ExitMode_A28988;                     // 0xa28988, the Special_Dialog mode (SpecialDialogType)

// RTTI .?AVHouseClass@@; only the fields used here.
class HouseClass {
public:
    char Unknown00[0x30];
    int ArrayIndex;                             // +0x30
    char Unknown34[0x13D - 0x34];
    bool IsDefeated;                            // +0x13d
    bool Field13E;                              // +0x13e (meaning unknown)
    bool Field13F;                              // +0x13f (meaning unknown)
    bool Field140;                              // +0x140 (meaning unknown)
};
extern HouseClass * PlayerPtr;                  // 0xa1e0e4

// Event record, 0x6f bytes. Layout not reconstructed.
#pragma pack(push, 1)
class EventClass {
public:
    EventClass(int house, int type);            // 0x4b5ce0
private:
    unsigned char Data[0x6F];
};
#pragma pack(pop)
enum { EVENT_8 = 8 };                           // event type sent on surrender/abort (name provisional)

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

class GameControlsClass {
public:
    void Process();                             // 0x4cf500 (see GameDlg.CPP)

    HWND Dialog;
};

// One-byte dialog object whose Process is 0x67e400 (name provisional).
class SoundControlsClass {
public:
    void Process();                             // 0x67e400
};

extern bool Flag_7C3980;                        // 0x7c3980 (meaning unknown; cleared after an abort event)
extern bool Flag_84E580;                        // 0x84e580 (meaning unknown)
extern HWND MainWindow;                         // 0xb0de50 (name provisional)

void Func_6530D0();                             // 0x6530d0 (meaning unknown)
void Func_6531C0();                             // 0x6531c0 (meaning unknown)
void Func_4DCEA0();                             // 0x4dcea0 (dialog, meaning unknown)
int Func_4DD5B0();                              // 0x4dd5b0 (dialog 0xb6, returns the button)
void Func_730D00();                             // 0x730d00 (dialog 0xcf)
void Func_61B240();                             // 0x61b240 (meaning unknown)
int Confirmation_Dialog(wchar_t const * text);  // 0x5a4020 (name provisional)
void Process_Global_Packets();                  // 0x482440, defined below
void Write_MPStats();                           // 0x482d80, defined below

// Recording state at 0xa27928 (Session + 0x2360).
struct SessionRecordType {
    unsigned IsRecording : 1;                   // bit 0 (meaning provisional)
    unsigned IsPlayback : 1;                    // bit 1 (meaning provisional)
};
extern SessionRecordType SessionRecord;         // 0xa27928  (Session + 0x2360)

class CCFileClass {
public:
    virtual void Close();                       // 0x468e10
};
extern CCFileClass SessionRecordFile;           // 0xa278c4  (Session + 0x22fc)

class WWKeyboardClass {
public:
    void Clear();                               // 0x530c50
};
extern WWKeyboardClass * Keyboard;              // 0x81a7a8

class ToolTipManager {
public:
    virtual ~ToolTipManager();
    void Set_Active(bool on);                   // 0x6e0740
};
extern ToolTipManager * ToolTipHandler;         // 0x821cf0 (name provisional)

class PaletteClass {
};
extern PaletteClass Palette_820150;             // 0x820150 (meaning unknown)
extern PaletteClass Palette_81F850;             // 0x81f850 (meaning unknown)
void Fade_Palette_To(PaletteClass & palette, int delay, void (* callback)());   // 0x4953b0 (name provisional)

extern HINSTANCE ProgramInstance;               // 0xb0dbf8 (name provisional)
extern void * ExceptionReturnStack;             // 0x84df44
extern void * ExceptionReturnAddress;           // 0x84df48
extern void * ExceptionReturnFrame;             // 0x84df4c

extern int Global_A283C4;                       // 0xa283c4 (meaning unknown)
extern int Global_A567EC;                       // 0xa567ec (meaning unknown)
extern int Global_A567F0;                       // 0xa567f0 (meaning unknown)
extern bool Flag_A29408;                        // 0xa29408 (meaning unknown)
extern int Global_AA5038;                       // 0xaa5038 (meaning unknown)
extern bool Flag_AA5008;                        // 0xaa5008 (meaning unknown)
extern bool Flag_A28984;                        // 0xa28984 (see Restate.cpp)
extern bool Flag_A28944;                        // 0xa28944 (see Restate.cpp)
extern bool Flag_A27FD0;                        // 0xa27fd0 (meaning unknown)
extern bool Flag_7B8F98;                        // 0x7b8f98 (initially true, meaning unknown)

int Init_Game();                                // 0x510af0 (name provisional): <0 failed, >0 quit
bool Select_Game(bool fade);                    // 0x512e00 (name provisional)
bool Main_Loop();                             // 0x53dc10 (meaning unknown)
bool Func_53D940();                               // 0x53d940 (name provisional), true when the game ends
void Func_68F7D0();                             // 0x68f7d0 (meaning unknown)
void Func_6E81A0();                             // 0x6e81a0 (meaning unknown)
void Func_5C7120();                             // 0x5c7120 (modem game end, meaning provisional)
void Func_5B6730();                             // 0x5b6730 (IPX game end, meaning provisional)
void Call_Back_5168E0(bool flag);               // 0x5168e0 (see GameDlg.CPP)

// ---- end of local declarations ----

// 0x481a80: unreferenced empty function.
void Conquer_Stub_481A80()
{
}

void Special_Dialog()
{
    if (ExitMode_A28988 == SDLG_NONE) {
        return;
    }

    if (Session.Type != GAME_NORMAL) {
        if (PlayerPtr->Field140 || PlayerPtr->Field13F || PlayerPtr->Field13E
            || (!Flag_7C3980 && !PlayerPtr->IsDefeated)) {
            ExitMode_A28988 = SDLG_NONE;
            return;
        }
        if (!Flag_7C3980) {
            Flag_7C3980 = true;
        }
    }

    Func_6530D0();
    WWMouse->Release_Mouse();
    while (WWMouse->Get_Mouse_State()) {
        WWMouse->Show_Mouse();
    }

    while (ExitMode_A28988 != SDLG_NONE) {
        switch (ExitMode_A28988) {
            case SDLG_9:
                Scen->Func_632630();
                if (ExitMode_A28988 == SDLG_9) {
                    ExitMode_A28988 = SDLG_NONE;
                }
                break;

            case SDLG_8:
                Map.Func_62BFA0();
                if (ExitMode_A28988 == SDLG_8) {
                    ExitMode_A28988 = SDLG_NONE;
                }
                break;

            case SDLG_1:
                Func_4DCEA0();
                if (ExitMode_A28988 == SDLG_1) {
                    ExitMode_A28988 = SDLG_NONE;
                }
                break;

            case SDLG_GAME_CONTROLS: {
                GameControlsClass().Process();
                if (ExitMode_A28988 == SDLG_GAME_CONTROLS) {
                    ExitMode_A28988 = SDLG_1;
                }
                break;
            }

            case SDLG_6: {
                SoundControlsClass().Process();
                ExitMode_A28988 = SDLG_GAME_CONTROLS;
                break;
            }

            case SDLG_OPTIONS:
                Options.Process();
                ExitMode_A28988 = SDLG_GAME_CONTROLS;
                break;

            case SDLG_3:
                switch (Func_4DD5B0()) {
                    case 3:
                        OutList.Add(EventClass(PlayerPtr->ArrayIndex, EVENT_8));
                        Flag_7C3980 = false;
                        // fall through

                    case 2:
                        Func_61B240();
                        break;

                    case 4:
                        OutList.Add(EventClass(PlayerPtr->ArrayIndex, EVENT_8));
                        Flag_7C3980 = false;
                        break;

                    case 5:
                        Flag_84E580 = true;
                        break;
                }
                ExitMode_A28988 = SDLG_NONE;
                break;

            case SDLG_SURRENDER:
                if (!PlayerPtr->IsDefeated && !PlayerPtr->Field13F && !PlayerPtr->Field140 && !PlayerPtr->Field13E) {
#line 470 "C:\\RA2\\Conquer.CPP"
                    if (Confirmation_Dialog(Fetch_String("TXT_SURRENDER", NULL, __FILE__, __LINE__))) {
                        OutList.Add(EventClass(PlayerPtr->ArrayIndex, EVENT_8));
                        Flag_7C3980 = false;
                    }
                }
                ExitMode_A28988 = SDLG_NONE;
                break;

            case SDLG_7:
                Func_730D00();
                ExitMode_A28988 = SDLG_NONE;
                break;
        }
    }

    UpdateWindow(MainWindow);
    if (Scen->Field2306) {
        WWMouse->Hide_Mouse();
    }
    WWMouse->Capture_Mouse();
    Session.Func_669010();
    Func_6531C0();
}

void Main_Game()
{
    static bool fade = true;

    int init = Init_Game();
    if (init != 0) {
        if (init < 0) {
            char text[0x1400];
            char title[0x800];
#line 545 "C:\\RA2\\Conquer.CPP"
            WideCharToMultiByte(CP_ACP, 0, Fetch_String("TXT_INITGAME_FAILED", NULL, __FILE__, __LINE__), -1, text, sizeof(text), NULL, NULL);
            WideCharToMultiByte(CP_ACP, 0, Fetch_String("TXT_SHORT_TITLE", NULL, __FILE__, __LINE__), -1, title, sizeof(title), NULL, NULL);

            MSGBOXPARAMSA params;
            params.cbSize = sizeof(params);
            params.hwndOwner = MainWindow;
            params.hInstance = ProgramInstance;
            params.lpszText = text;
            params.lpszCaption = title;
            params.dwStyle = MB_ICONHAND | MB_SETFOREGROUND | MB_TOPMOST;
            params.lpszIcon = NULL;
            params.dwContextHelpId = 0;
            params.lpfnMsgBoxCallback = NULL;
            params.dwLanguageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT);
            MessageBoxIndirectA(&params);
        }
        return;
    }

    // Remember where to continue after an exception.
    __asm {
        mov ExceptionReturnStack, esp
        mov ExceptionReturnFrame, ebp
        lea eax, ExceptionReturn
        mov ExceptionReturnAddress, eax
    }
ExceptionReturn:
    Debug_Printf("ExceptionReturnStack = %08X\n", ExceptionReturnStack);
    Debug_Printf("ExceptionReturnAddress = %08X\n", ExceptionReturnAddress);

    while (Select_Game(fade)) {
        Global_A283C4 = 0;
        fade = true;
        Fade_Palette_To(Palette_820150, 15, NULL);
        Keyboard->Clear();

        if (SessionRecord.IsPlayback) {
            WWMouse->Hide_Mouse();
            Global_A567EC = 0;
            Global_A567F0 = 0;
        }

        if (Session.Type == GAME_INTERNET) {
            Func_68F7D0();
            Flag_A29408 = false;
            Global_AA5038 = 0;
            Flag_AA5008 = false;
        }

        if (ToolTipHandler != NULL) {
            ToolTipHandler->Set_Active(Options.ToolTips);
        }

        Flag_A28984 = Scen->Field2306;
        ExitMode_A28988 = SDLG_NONE;
        Flag_7C3980 = true;
        Session.Func_669010();

        for (;;) {
            if (Main_Loop() && Func_53D940()) {
                break;
            }
            Special_Dialog();
            if (Func_53D940()) {
                break;
            }
        }

        Func_6E81A0();
        Session.Func_6690A0();
        Flag_A28944 = false;
        Flag_A27FD0 = false;
        Debug_Printf("Game loop finished. Average FPS = %d\n", Average_FPS());
        Write_MPStats();

        if (!Flag_7B8F98) {
            Fade_Palette_To(Palette_81F850, 30, NULL);
        }
        Call_Back_5168E0(true);

        if (SessionRecord.IsRecording || SessionRecord.IsPlayback) {
            SessionRecordFile.Close();
        }

        if (Session.Type == GAME_NULL_MODEM || Session.Type == GAME_MODEM) {
            if (!SessionRecord.IsPlayback) {
                Func_5C7120();
            }
        } else if (Session.Type == GAME_IPX) {
            if (!SessionRecord.IsPlayback) {
                Func_5B6730();
            }
        }

        if (Session.Type == GAME_IPX || Session.Type == GAME_INTERNET || Session.Type == GAME_NULL_MODEM
            || Session.Type == GAME_MODEM) {
            if (!SessionRecord.IsPlayback) {
                Session.Func_667120();
            }
        }

        if (SessionRecord.IsPlayback) {
            SessionRecord.IsPlayback = false;
            Session.Type = GAME_NORMAL;
            WWMouse->Show_Mouse();
        }
    }

    if (WWMouse != NULL) {
        WWMouse->Release_Mouse();
    }
}

void Modem_Call_Back()
{
    SerialPacketType packet;
    int packetlen;

    if (Session.Type == GAME_NULL_MODEM || SessionModemFlags.ModemService) {
        NullModem.Service();
        if (Scen->Field22FC) {
            while (NullModem.Get_Message(&packet, &packetlen) > 0) {
                if (packet.Command == SERIAL_COMMAND_6C && packet.ID != SessionModemGameToPlay) {
                    ObjectA5E540.Func_617D70(1, packet.Value);
                }
            }
        }
    }
}

void Call_Back()
{
    Func_406EA0();

    if (Session.Type == GAME_IPX || Session.Type == GAME_INTERNET) {
        Process_Global_Packets();
    }

    if (Session.Type == GAME_MODEM || Session.Type == GAME_NULL_MODEM) {
        Modem_Call_Back();
    }

    if (Session.Type == GAME_INTERNET && !Flag_B100A2) {
        if (time(NULL) != LastPumpTime) {
            if (WOLChat != NULL && !Flag_B100AC) {
                WOLChat->PumpMessages();
            }
            if (WOLDownload != NULL) {
                WOLDownload->PumpMessages();
            }
            LastPumpTime = time(NULL);
        }
    }
}

bool Func_482310()
{
    Call_Back();
    return false;
}

// True when the local player (first player entry) is among the packet's recipients; always
// true without host migration.
inline bool Is_Recipient(unsigned char const & recipients)
{
    if (SessionHostMigration) {
        return (recipients & HostManager.Recipient_Mask(&SessionPlayers[0]->Address)) != 0;
    }
    return true;
}

void Process_Global_Packets()
{
    Windows_Message_Handler();
    Ipx.Service();

    if (SessionFlag2374) {
        return;
    }

    while (Ipx.Get_Global_Message(&SessionGPacket, &SessionGPacketLength, &SessionGAddress, &SessionGProductID)) {
        if (SessionGProductID == GLOBAL_PRODUCT_ID) {
            switch (SessionGPacket.Command) {
                case NET_COMMAND_28:
                    Func_61E9D0(&SessionGPacket, &SessionGAddress);
                    break;

                case NET_IM_STILL_HERE: {
                    for (int index = 0; index < Ipx.Num_Connections(); index++) {
                        if (Ipx.Connection_ID(index) == SessionGPacket.ID) {
                            Debug_Printf("Got NET_IM_STILL_HERE packet from %s\n",
                                To_Narrow(Ipx.Connection_Name(SessionGPacket.ID)));
                            Func_61AE90(index);
                            break;
                        }
                    }
                    break;
                }

                case NET_COMMAND_32:
                    Object836C18.Func_42E340(SessionGPacket.Location.A,
                        CoordStruct(SessionGPacket.Location.X, SessionGPacket.Location.Y, SessionGPacket.Location.Z),
                        SessionGPacket.Location.B);
                    break;

                case NET_COMMAND_33:
                    Object836C18.Func_42E940(SessionGPacket.Location.A, SessionGPacket.Location.B);
                    break;

                case NET_COMMAND_34:
                    Object836C18.Func_42EB70(SessionGPacket.Raw.Data, SessionGPacket.Raw.A,
                        SessionGPacket.Raw.B, 0);
                    break;

                case NET_COMMAND_10: {
                    for (int index = 0; index < Ipx.Num_Connections(); index++) {
                        int id = Ipx.Connection_ID(index);
                        if (SessionGAddress == *Ipx.Connection_Address(id)) {
                            Func_5B6760(id, 0);
                        }
                    }
                    break;
                }

                case NET_MESSAGE:
                    if (SessionFlag2373 && SessionGPacket.Message.NameCRC != Compute_Name_CRC(SessionName2376)) {
                        break;
                    }
                    if (!Is_Recipient(SessionGPacket.Message.Recipients)) {
                        break;
                    }
                    SessionMessages.Add_Message(To_Wide(SessionGPacket.Name), SessionGPacket.Message.ID,
                        SessionGPacket.Message.Text, Session.Player_Color(SessionGPacket.Message.ID), 0x4046,
                        Rule->MessageDelay * 900.0, false);
                    Sound_Effect_708970(Rule->IncomingMessage, 0x2000, 1.0f, 0);
                    Map.Flag_To_Redraw(2);
                    wcscpy(SessionLastMessage, SessionGPacket.Message.Text);
                    break;

                case NET_COMMAND_29:
                    if (SessionFlag2373 && SessionGPacket.Signal.NameCRC != Compute_Name_CRC(SessionName2376)) {
                        break;
                    }
                    if (!Is_Recipient(SessionGPacket.Signal.Recipients)) {
                        break;
                    }
                    if ((SessionFlag1E86 && Session.Type == GAME_IPX) || (SessionFlag1E87 && Session.Type == GAME_INTERNET)) {
                        Func_70AB70(SessionGPacket.Signal.Value);
                    }
                    break;

                case NET_COMMAND_15: {
                    for (int index = 0; index < SessionPlayers.ActiveCount; index++) {
                        if (SessionPlayers[index]->Address == SessionGAddress) {
                            ObjectA5E540.Func_617D70(index, SessionGPacket.ID);
                            break;
                        }
                    }
                    break;
                }

                case NET_COMMAND_16:
                case NET_COMMAND_19:
                    break;

                default:
                    Process_Global_Packet(&SessionGPacket, &SessionGAddress);
                    break;
            }
        }
        Windows_Message_Handler();
        Ipx.Service();
    }
}

SourceType Source_From_Name(char const * name)
{
    if (name != NULL) {
        for (SourceType source = SOURCE_FIRST; source < SOURCE_COUNT; source = SourceType(source + 1)) {
            if (stricmp(SourceName[source], name) == 0) {
                return source;
            }
        }
    }
    return SOURCE_NONE;
}

char const * Name_From_Source(SourceType source)
{
    if ((unsigned)source < SOURCE_COUNT) {
        return SourceName[source];
    }
    return "None";
}

TheaterType Theater_From_Name(char const * name)
{
    for (TheaterType theater = THEATER_FIRST; theater < THEATER_COUNT; theater = TheaterType(theater + 1)) {
        if (stricmp(name, Theaters[theater].Name) == 0) {
            return theater;
        }
    }
    return THEATER_NONE;
}

FacingType KN_To_Facing(int input)
{
    input &= ~(KN_ALT_BIT | KN_SHIFT_BIT | KN_CTRL_BIT);
    switch (input) {
        case KN_LEFT:
            return FACING_W;

        case KN_RIGHT:
            return FACING_E;

        case KN_UP:
            return FACING_N;

        case KN_DOWN:
            return FACING_S;

        case KN_HOME:
            return FACING_NW;

        case KN_PGUP:
            return FACING_NE;

        case KN_END:
            return FACING_SW;

        case KN_PGDN:
            return FACING_SE;
    }
    return FACING_NONE;
}

void Clear_Object_List_482960()
{
    while (ObjectList_A288A0.ActiveCount) {
        ObjectList_A288A0[0]->Remove_This();
    }
    Func_6EB5E0(0);
    Object836C18.Func_42E7E0();
}

TechnoTypeClass * Fetch_Techno_Type(RTTIType type, int id)
{
    switch (type) {
        case RTTI_UNIT:
        case RTTI_UNITTYPE:
            return UnitTypes[id];

        case RTTI_BUILDING:
        case RTTI_BUILDINGTYPE:
            return BuildingTypes[id];

        case RTTI_INFANTRY:
        case RTTI_INFANTRYTYPE:
            return InfantryTypes[id];

        case RTTI_AIRCRAFT:
        case RTTI_AIRCRAFTTYPE:
            return AircraftTypes[id];
    }
    return NULL;
}

typedef bool (__stdcall * GetDiskFreeSpaceExType)(char const * dir, ULARGE_INTEGER * avail,
    ULARGE_INTEGER * total, ULARGE_INTEGER * free);

unsigned Disk_Space_Available()
{
    Debug_Printf("Checking available disk space\n");

    HMODULE kernel = GetModuleHandleA("KERNEL32.DLL");
    if (kernel != NULL) {
        GetDiskFreeSpaceExType get_free = (GetDiskFreeSpaceExType)GetProcAddress(kernel, "GetDiskFreeSpaceExA");
        if (get_free != NULL) {
            Debug_Printf("Using GetDiskFreeSpaceEx\n");
            ULARGE_INTEGER avail;
            ULARGE_INTEGER total;
            ULARGE_INTEGER free;
            if (!get_free(NULL, &avail, &total, &free)) {
                Debug_Printf("GetDiskFreeSpaceEx failed with error code %d - %s\n", GetLastError(), NULL);
            } else {
                unsigned kbytes = (unsigned)(((int)avail.HighPart * 4294967296.0 + (int)avail.LowPart) / 1024.0);
                Debug_Printf("Free disk space is %d Mb\n", kbytes >> 10);
                return kbytes;
            }
        } else {
            Debug_Printf("GetProcAddress failed with error code %d - %s\n", GetLastError(), NULL);
        }
    } else {
        Debug_Printf("Failed to get module handle for KERNEL32.DLL\n");
    }

    DWORD sectors_per_cluster;
    DWORD bytes_per_sector;
    DWORD free_clusters;
    DWORD total_clusters;
    if (GetDiskFreeSpaceA(NULL, &sectors_per_cluster, &bytes_per_sector, &free_clusters, &total_clusters)) {
        unsigned kbytes = ((sectors_per_cluster * bytes_per_sector) >> 10) * free_clusters;
        Debug_Printf("Free disk space is %d Mb\n", kbytes >> 10);
        return kbytes;
    }
    return 0;
}

CrateType Crate_From_Name(char const * name)
{
    if (name != NULL) {
        for (CrateType crate = CRATE_MONEY; crate < CRATE_COUNT; crate = CrateType(crate + 1)) {
            if (stricmp(name, CrateNames[crate]) == 0) {
                return crate;
            }
        }
    }
    return CRATE_MONEY;
}

int Owner_From_Name(char const * text)
{
    int ownable = 0;
    HousesType house = HouseTypeClass::From_Name(text);
    if (house != HOUSE_NONE) {
        ownable |= (1 << house);
    }
    return ownable;
}

// 0x482ba0: empty in this build (called with a shake count).
void Shake_The_Screen(int shakes)
{
}

void List_Copy(CellStruct const * source, int len, CellStruct * dest)
{
    if (source == NULL || dest == NULL) {
        return;
    }
    while (len > 0) {
        *dest = *source;
        if (dest->X == 0x7FFF && dest->Y == 0x7FFF) {
            return;
        }
        dest++;
        source++;
        len--;
    }
    *(dest - 1) = CellStruct(0x7FFF, 0x7FFF);
}

int Name_Index_482C00(char const * name)
{
    if (name != NULL && stricmp("<none>", name) != 0) {
        for (int index = 0; index < NameList_A58C68.ActiveCount; index++) {
            if (stricmp(name, NameList_A58C68[index]) == 0) {
                return index;
            }
        }
    }
    return -1;
}

LandType Land_From_Name(char const * name)
{
    if (stricmp("<none>", name) != 0 && name != NULL) {
        for (LandType land = LAND_FIRST; land < LAND_COUNT; land = LandType(land + 1)) {
            if (stricmp(LandNames[land], name) == 0) {
                return land;
            }
        }
    }
    return LAND_NONE;
}

char const * Name_From_Land(LandType land)
{
    if ((unsigned)land < LAND_COUNT) {
        return LandNames[land];
    }
    return "<none>";
}

SpeedType Speed_From_Name(char const * name)
{
    if (name != NULL) {
        for (SpeedType speed = SPEED_FIRST; speed < SPEED_COUNT; speed = SpeedType(speed + 1)) {
            if (stricmp(SpeedNames[speed], name) == 0) {
                return speed;
            }
        }
    }
    return SPEED_NONE;
}

char const * Name_From_Speed(SpeedType speed)
{
    if ((unsigned)speed < SPEED_COUNT) {
        return SpeedNames[speed];
    }
    return "<none>";
}

LayerType Layer_From_Name(char const * name)
{
    if (name != NULL) {
        for (LayerType layer = LAYER_FIRST; layer < LAYER_COUNT; layer = LayerType(layer + 1)) {
            if (stricmp(LayerNames[layer], name) == 0) {
                return layer;
            }
        }
    }
    return LAYER_NONE;
}

char const * Name_From_Layer(LayerType layer)
{
    if ((unsigned)layer < LAYER_COUNT) {
        return LayerNames[layer];
    }
    return "<none>";
}

void Write_MPStats()
{
    if (Session.Type == GAME_INTERNET) {
        FILE * fp = fopen("mpstats.txt", "wt");
        if (fp != NULL) {
            fprintf(fp, "Frames: %d\n", NetworkEventMode);
            fprintf(fp, "Average FPS: %d\n", Average_FPS());
            fprintf(fp, "Max MaxAhead: %d\n", SessionMaxMaxAhead);
            fprintf(fp, "Latency setting: %d\n", SessionLatency);
            fprintf(fp, "Game speed setting: %d\n", Options.GameSpeed);

            if (PacketTransport != NULL) {
                for (int index = 0; index < PacketTransport->Get_Num_Local_Addresses(); index++) {
                    unsigned char * address = PacketTransport->Get_Local_Address(index);
                    if (address != NULL) {
                        unsigned long ip = *(unsigned long *)address;
                        fprintf(fp, "Local address: %d.%d.%d.%d\n", ip & 0xFF, (ip >> 8) & 0xFF,
                            (ip >> 16) & 0xFF, ip >> 24);
                    }
                }
            }

            for (int player = 0; player < 8; player++) {
                NetStatsType & stats = SessionNetStats[player];
                if (stats.Name[0] != '\0') {
                    NetNumType net;
                    NetNodeType node;
                    stats.Address.Get_Address(net, node);
                    fprintf(fp, "\nName: %s\n", stats.Name);
                    fprintf(fp, "Address: %d.%d.%d.%d\n", node[0], node[1], node[2], node[3]);
                    fprintf(fp, "Max avg round trip: %d\n", stats.MaxAvgRoundTrip);
                    fprintf(fp, "Max round trip: %d\n", stats.MaxRoundTrip);
                    fprintf(fp, "Resends: %d\n", stats.Resends);
                    fprintf(fp, "Frame sync stalls: %d\n", stats.FrameSyncStalls);
                    fprintf(fp, "Command cound stalls: %d\n", stats.CommandCountStalls);
                    fprintf(fp, "Lost: %d\n", stats.Lost);
                    fprintf(fp, "Percent lost: %d\n", stats.PercentLost);
                }
            }
            fclose(fp);
        }
    }
}
