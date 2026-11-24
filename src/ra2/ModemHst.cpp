// C:\RA2\ModemHst.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Modem / null modem game host dialog: dialog set-up and read-back of the game options, chat,
// the option and timing packets sent to the guest, the incoming packet handler, sign-off, the
// "GO" handshake that starts the game and the map preview upload.
// The dialog object has no vtable; the class name ModemHostDialogClass (see NullDlg.CPP) and all
// method, member and variable names are provisional (Westwood style).
//
// TU boundary: the 12 GAMECONST initializers 0x195a40..0x195c01, then the code 0x195c10..0x19998d
// (member functions in source order, ending with the compiler generated scalar deleting destructor
// of the preview object at 0x199970). The following code 0x199990..0x19a37c is the Windows modem
// registry class (ModemRegistryEntryClass, see SerialEd.cpp) of another TU, and the 16-byte zeroing
// initializer at 0x19a380 precedes the next GAMECONST block (0x19a3a0); neither is claimed here.
// Several small members (the check box, slider and combo box handlers, Send_Chat, Display_Message)
// are auto-inlined into Dialog_Proc / Init_Dialog / Send_Message and also emitted out of line.
// Matching notes: Session members must be accessed through the Session object (indexed loads of
// Session.Scenarios otherwise come out in the wrong order); HouseTypeClass::Full_Name() and the
// acknowledged flag in Send_Preview are needed for the original register allocation / block order.
// Open: Dialog_Proc inlines one slider handler too many (Tech_Level_Changed; the original only
// inlines Unit_Count_Changed), Init_Dialog has one register choice left, and Select_Multi_Map,
// Select_Random_Map, Get_Message and Send_Game_Options differ only in register allocation /
// scheduling.
#include "GAMECONST.H"
#include <windows.h>
#include <commctrl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
void Wide_To_Narrow(char * dest, wchar_t const * src, int length);      // 0x6eed90 (see NullDlg.CPP)
void Narrow_To_Wide(wchar_t * dest, char const * src, int length);      // 0x6eed60 (name provisional)
char * To_Narrow(wchar_t const * string);       // 0x6eedc0, rotating buffers
wchar_t * To_Wide(char const * string);         // 0x6eee20, rotating buffers
void Wcstrim(wchar_t * buffer);                 // 0x6e4240
void Call_Back();                             // 0x4821e0 (provisional)
void Windows_Message_Handler();                               // 0x5b29f0 (provisional)
int Play_Sound(int voc, float volume, int pan, int flags);   // 0x708970 (see Options.CPP)

// Dialog support (see also NullDlg.CPP / SerialEd.cpp).
HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);            // 0x5f72d0
void Show_Dialog(HWND dialog);          // 0x5f7480
void End_Dialog(HWND dialog);           // 0x5f73a0
bool Dialog_Abort_Check();              // 0x5f7d70
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
void Call_Back_5168E0(bool flag);       // 0x5168e0
HWND Create_Cancel_Dialog(wchar_t const * text, wchar_t const * button, bool * cancelled);  // 0x5f7e80
void Set_Cancel_Dialog_Text(HWND dialog, wchar_t const * text);    // 0x5f7f60 (name provisional)
int Find_Item_Data(HWND combo, int start, int data);    // 0x72b9d0

// Multiplayer dialog helpers of other files (names provisional).
int Scenario_Max_Players(int index);    // 0x5c0690
int Select_Map_Dialog(HWND parent);     // 0x5c09f0, 2 = cancelled (provisional)
bool Set_Scenario(int index);           // 0x5c1bd0
void Update_Preview(HWND dialog);       // 0x5c15d0
char * Random_Map_Digest();             // 0x5c22e0, allocated with new
void Add_Chat_Text(int color, wchar_t const * text, HWND list);     // 0x5bd930
typedef bool (*DialogCallbackType)();
int Random_Map_Dialog(DialogCallbackType callback);     // 0x574280, 1 = accepted
void Shutdown_Modem();                  // 0x5c70f0 (NullDlg.CPP)
void Send_Remote_File(char const * filename, int flag, int a, int b);  // 0x662830 (provisional)
int Func_649690();                      // 0x649690 (version or CRC values compared with the guest)
void Func_6497D0();                     // 0x6497d0
int Func_6497B0();                      // 0x6497b0
int Func_6497C0();                      // 0x6497c0
int Func_72C6B0();                      // 0x72c6b0

// Message box with an inline constructor that stores the caption (L" " at 0x7c1624).
class WWMessageBox {
public:
    WWMessageBox(wchar_t const * caption = L" ") : Caption(caption) {}
    int Process(wchar_t const * msg, wchar_t const * b1, wchar_t const * b2 = NULL,
        wchar_t const * b3 = NULL, bool flag = false);     // 0x5b1290
    wchar_t const * Caption;
};

class SystemTimerClass {
public:
    long operator()() const;                    // 0x68fad0
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
    operator long() const { return Value(); }

    long Started;
    T Timer;
    long Accumulated;
};
extern TTimerClass<SystemTimerClass> TickCount;     // 0x821cc0

// Count-down timer (see NullDlg.CPP).
template<class T>
class CDTimerClass {
public:
    CDTimerClass(long set = 0) : Started(Timer()), DelayTime(set) {}
    long Value() const
    {
        long remain = DelayTime;
        if (Started != -1) {
            long value = Timer() - Started;
            if (value < remain) {
                return remain - value;
            }
            return 0;
        }
        return remain;
    }
    operator long() const { return Value(); }

    long Started;
    T Timer;
    long DelayTime;
};

class RandomClass {
public:
    int operator()(int minval, int maxval);     // 0x62fe40
};
extern RandomClass NonCriticalRandomNumber;     // 0x821558 (name provisional)

// File classes (see Options.CPP); only what is used here.
class FileClass {
public:
    virtual ~FileClass() {}
    virtual char const * File_Name() const = 0;
    virtual char const * Set_Name(char const * filename) = 0;
    virtual int Create() = 0;
    virtual int Delete() = 0;
    virtual bool Is_Available(int forced = false) = 0;
    virtual bool Is_Open() const = 0;
    virtual int Open(char const * filename, int rights = 1) = 0;
    virtual int Open(int rights = 1) = 0;
    virtual long Read(void * buffer, long size) = 0;
    virtual long Seek(long pos, int dir = 1) = 0;
    virtual long Size() = 0;
    virtual long Write(void const * buffer, long size) = 0;
    virtual void Close() = 0;
    virtual unsigned long Get_Date_Time() = 0;
    virtual bool Set_Date_Time(unsigned long datetime) = 0;
    virtual void Error(int error, int canretry = false, char const * filename = NULL) = 0;
};

class RawFileClass : public FileClass {
public:
    RawFileClass(char const * filename);    // 0x6300e0
    virtual ~RawFileClass();                // 0x630060
    virtual char const * File_Name() const;
    virtual char const * Set_Name(char const * filename);
    virtual int Create();
    virtual int Delete();
    virtual bool Is_Available(int forced = false);
    virtual bool Is_Open() const;
    virtual int Open(char const * filename, int rights = 1);
    virtual int Open(int rights = 1);
    virtual long Read(void * buffer, long size);
    virtual long Seek(long pos, int dir = 1);
    virtual long Size();
    virtual long Write(void const * buffer, long size);
    virtual void Close();
    virtual unsigned long Get_Date_Time();
    virtual bool Set_Date_Time(unsigned long datetime);
    virtual void Error(int error, int canretry = false, char const * filename = NULL);
private:
    char RawFileData[0x1C];             // +0x04, layout not reconstructed
};

class BufferIOFileClass : public RawFileClass {
public:
    virtual ~BufferIOFileClass();       // 0x42f250
private:
    char BufferIOData[0x34];            // +0x20, layout not reconstructed
};

class CDFileClass : public BufferIOFileClass {
public:
    virtual ~CDFileClass() {}
    virtual char const * Set_Name(char const * filename);   // 0x46fd50
};

class Buffer {
public:
    Buffer(void * buffer = NULL, long size = 0);
    ~Buffer();                          // 0x438290
private:
    void * BufferPtr;
    long Size;
    bool IsAllocated;
};

class CCFileClass : public CDFileClass {
public:
    CCFileClass(char const * filename); // 0x468b70
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual long Size();                // 0x468d70
    virtual void Close();               // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

// Pipes (see PIPE.CPP / PKPIPE.CPP); RTTI .?AVPipe@@ vtable 0x789a20.
class Pipe {
public:
    Pipe() : ChainTo(0), ChainFrom(0) {}
    virtual ~Pipe();                                // 0x606640
    virtual int Flush();                            // 0x6066f0
    virtual int End() { return Flush(); }           // 0x46c780
    virtual void Put_To(Pipe * pipe);               // 0x606680
    void Put_To(Pipe & pipe) { Put_To(&pipe); }
    virtual int Put(void const * source, int slen); // 0x6066d0

    Pipe * ChainTo;         // +0x04
    Pipe * ChainFrom;       // +0x08
};

// RTTI .?AVBufferPipe@@, vtable 0x789a08.
class BufferPipe : public Pipe {
public:
    BufferPipe(void * buffer, long length) : BufferPtr(buffer, length), Index(0) {}
    virtual int Put(void const * source, int slen);

private:
    Buffer BufferPtr;       // +0x0c
    int Index;              // +0x18
};

// RTTI .?AVLZOPipe@@, vtable 0x790894.
class LZOPipe : public Pipe {
public:
    enum CompControl { COMPRESS, DECOMPRESS };
    LZOPipe(CompControl control, int blocksize);    // 0x53cd20
    virtual ~LZOPipe();                             // 0x53cd80
    virtual int Flush();                            // 0x53d050
    virtual int Put(void const * source, int slen); // 0x53cdc0

private:
    char Data[0x28 - 0x0C];
};

enum FileAccessType { READ = 1, WRITE = 2 };

// RTTI .?AVNullModemClass@@ (vtable 0x7923d4); only the members used here.
class NullModemClass {
public:
    virtual ~NullModemClass();
    void Func_5C8A50();                         // 0x5c8a50 (meaning unknown)
    int Send_Message(void * buf, int buflen, int ack_req);  // 0x5c8c80
    int Get_Message(void * buf, int * buflen);  // 0x5c8cc0
    int Service();                              // 0x5c8cf0
    int Num_Send();                             // 0x5c8f30
    unsigned long Response_Time();              // 0x5c8f70
    void Func_5C8F90(int value);                // 0x5c8f90 (meaning unknown)
};
extern NullModemClass NullModem;                // 0xa28668

// Version information object at 0xa288c8 (names provisional).
class VersionClass {
public:
    int Version_Number(int version);            // 0x707cf0
    void Init();                                // 0x707d20
    int Verify(int minversion, int maxversion); // 0x707d30, 0 / -1 = incompatible
    int Min_Version();                          // 0x707d70
    int Max_Version();                          // 0x707d80
};
extern VersionClass VerNum;                     // 0xa288c8

// Special game flags (RA name), 0xa28570.
class SpecialClass {
public:
    void Apply_To_Game();                       // 0x680b10 (m85 name)
    void Initialize();                          // 0x680b20 (m85 name; Init is 0x680a20)

    unsigned Bit0 : 1;
    unsigned Bit1 : 1;
    unsigned Bit2 : 1;
    unsigned Bit3 : 1;
    unsigned Bit4 : 1;                          // from Rule + 0x111a
    unsigned Bit5 : 1;
    unsigned Bit6 : 1;
    unsigned Bit7 : 1;
    unsigned Bit8 : 1;
    unsigned Bit9 : 1;
    unsigned Bit10 : 1;
    unsigned IsHarvesterTruce : 1;              // bit 11
    unsigned Bit12 : 1;
    unsigned Bit13 : 1;
    unsigned Bit14 : 1;
    unsigned IsBridgeDestruction : 1;           // bit 15
};
extern SpecialClass Special;                    // 0xa28570
extern int Seed;                                // 0xa2897c
extern int NetworkEventMode;                    // 0xa2896c (see NetDlg.CPP)

class OptionsClass {
public:
    int GameSpeed;                              // +0x00
};
extern OptionsClass Options;                    // 0xa28758

class RulesClass {
public:
    char Unknown00[0x5CC];
    int ChatSound;                              // +0x5cc (provisional)
    char Unknown5D0[0x5D4 - 0x5D0];
    int GuestJoinSound;                         // +0x5d4 (provisional)
    char Unknown5D8[0x10E8 - 0x5D8];
    int MinCredits;                             // +0x10e8
    int Credits;                                // +0x10ec
    int MaxCredits;                             // +0x10f0
    char Unknown10F4[0x10F8 - 0x10F4];
    int MinUnitCount;                           // +0x10f8
    int UnitCount;                              // +0x10fc
    int MaxUnitCount;                           // +0x1100
    char Unknown1104[0x1114 - 0x1104];
    bool BridgeDestruction;                     // +0x1114
    char Unknown1115[0x1117 - 0x1115];
    bool Bases;                                 // +0x1117
    char Unknown1118[0x1119 - 0x1118];
    bool Crates;                                // +0x1119
    bool Field111A;                             // +0x111a (Special bit 4)
    char Unknown111B[0x1121 - 0x111B];
    bool SuperWeapons;                          // +0x1121
    bool BuildOffAlly;                          // +0x1122
};
extern RulesClass * Rule;                       // 0x821b88

class ScenarioClass {
public:
    unsigned Bit0_9 : 10;
    unsigned Bit10 : 1;                         // cleared when a modem game starts
    unsigned Rest : 21;
    char Unknown04[0x60C - 0x04];
    int Field60C;                               // +0x60c
    int Field610;                               // +0x610
    char Unknown614[0x834 - 0x614];
    int ScenarioIndex;                          // +0x834
    char Unknown838[0x83C - 0x838];
    char ScenarioName[0x100];                   // +0x83c
};
extern ScenarioClass * Scen;                    // 0xa255c0

// RTTI .?AVHouseTypeClass@@; only the fields used here.
class HouseTypeClass {
public:
    wchar_t const * Full_Name() const { return UIName; }

    char Unknown00[0x60];
    wchar_t const * UIName;                     // +0x60
    char Unknown64[0x1A5 - 0x64];
    bool IsMultiplay;                           // +0x1a5
};
extern DynamicVectorClass<HouseTypeClass *> HouseTypes;    // 0xa1e038

// Multiplayer scenario list entry (class name provisional).
class MultiMission {
public:
    MultiMission(char const * filename, char const * description, char const * digest, bool official);   // 0x668020
    void Set_Description(char const * description); // 0x668250
    void Set_Digest(char const * digest);           // 0x668300

    wchar_t Description[0x2C];                  // +0x00
    char FileName[0x104];                       // +0x58
    char Digest[0x20];                          // +0x15c
    bool IsOfficial;                            // +0x17c
};

// Map preview picture of the dialog (class name provisional), 4 bytes, no vtable.
class PreviewClass {
public:
    PreviewClass();                             // 0x615010
    ~PreviewClass();                            // 0x615020
    void Draw(HWND dialog);                     // 0x615040
    void Load_Image(char const * filename);     // 0x615d50
    void Load_Scenario(char const * filename);  // 0x615e80
    void * Get_Data(int bpp, int * size);       // 0x616070

    void * Data;
};
extern PreviewClass * Preview;                  // 0xa5a860

class RandomMapClass {
public:
    void Func_575CC0(char const * filename);    // 0x575cc0
};
extern RandomMapClass RandomMap;                // 0xa57980 (see WorldDom.cpp)
extern char RandomMapName[];                    // 0xa579f8

#pragma pack(push, 1)
class IPXAddressClass {
public:
    IPXAddressClass();                          // 0x522950
private:
    unsigned char NetworkNumber[4];
    unsigned char NodeAddress[6];
};

// Entry of the session player list (0x71 bytes).
struct NodeNameType {
    wchar_t Name[20];                           // +0x00
    IPXAddressClass Address;                    // +0x28
    char Unknown32[0x49 - 0x32];
    int House;                                  // +0x49
    char Unknown4D[0x51 - 0x4D];
    int Color;                                  // +0x51
    char Unknown55[0x61 - 0x55];
    int ProcessTime;                            // +0x61
    char Unknown65[0x71 - 0x65];
};

// Serial game packet, 0xfa bytes.
struct SerialOptionsType {
    int House;                                  // +0x19
    char Color;                                 // +0x1d
    int MinVersion;                             // +0x1e
    int MaxVersion;                             // +0x22
    wchar_t Description[0x2C];                  // +0x26
    int Credits;                                // +0x7e
    unsigned Bases : 1;                         // +0x82
    unsigned BridgeDestruction : 1;
    unsigned Crates : 1;
    unsigned Unused3 : 1;
    unsigned IsOfficial : 1;
    int Version54;                              // +0x86
    unsigned char TechLevel;                    // +0x8a
    unsigned char UnitCount;                    // +0x8b
    unsigned char AIPlayers;                    // +0x8c
    unsigned char AIDifficulty;                 // +0x8d
    unsigned Unused0 : 1;                       // +0x8e
    unsigned HarvesterTruce : 1;
    unsigned MCVRedeploy : 1;
    unsigned FogOfWar : 1;
    unsigned ShortGame : 1;
    unsigned SuperWeapons : 1;
    unsigned BuildOffAlly : 1;
    unsigned CrapEngineers : 1;
    int Seed;                                   // +0x92
    SpecialClass Special;                       // +0x96
};

struct SerialPacketType {
    int Command;                                // +0x00
    char Name[20];                              // +0x04
    unsigned char ID;                           // +0x18
    union {
        wchar_t Message[0x40];                  // +0x19
        SerialOptionsType Options;              // +0x19
    };
    unsigned long ResponseTime;                 // +0x9a
    int FileLength;                             // +0x9e
    unsigned char GameSpeed;                    // +0xa2
    char ScenarioFile[0x0D];                    // +0xa3
    char Digest[0x20];                          // +0xb0
    int Version5C;                              // +0xd0
    int Version58;                              // +0xd4
    int ValueD8;                                // +0xd8
    char UnknownDC[0xFA - 0xDC];
};
#pragma pack(pop)

enum SerialCommandType {
    SERIAL_CONNECT = 0x64,
    SERIAL_GAME_OPTIONS = 0x65,
    SERIAL_SIGNOFF = 0x66,
    SERIAL_GO = 0x67,
    SERIAL_MESSAGE = 0x68,
    SERIAL_TIMING = 0x69,
    SERIAL_SCORE_SCREEN = 0x6A,
    SERIAL_LAST = 0x6D,
    SERIAL_REQ_SCENARIO = 0x6E,
    SERIAL_READY_TO_GO = 0x72,
    SERIAL_NO_SCENARIO = 0x73,
    SERIAL_ACCEPT_OPTIONS = 0x74,
    SERIAL_PREVIEW = 0x75,
    SERIAL_PREVIEW_ACK = 0x76,
    SERIAL_PREVIEW_REQUEST = 0x77
};

void Delete_All(DynamicVectorClass<NodeNameType *> & vector);  // 0x5a4070 (MPLayer.CPP)

// Session object at 0xa255c8 (class name provisional); only the members used here, at their
// binary offsets. Accesses go through the object (this affects the load order of indexed members).
class SessionClass {
public:
    void Write_MultiPlayer_Settings();          // 0x666d70

    int Type;                                   // +0x0000 (0xa255c8)
    char Unknown0004[0x0014 - 0x0004];
    int Version;                                // +0x0014 (0xa255dc)
    char Unknown0018[0x001C - 0x0018];
    int ScenarioIdx;                            // +0x001c (0xa255e4)
    bool Bases;                                 // +0x0020 (0xa255e8)
    char Unknown0021[0x0024 - 0x0021];
    int Credits;                                // +0x0024 (0xa255ec)
    bool BridgeDestruction;                     // +0x0028 (0xa255f0)
    bool Crates;                                // +0x0029 (0xa255f1)
    bool ShortGame;                             // +0x002a (0xa255f2)
    bool SuperWeapons;                          // +0x002b (0xa255f3)
    bool BuildOffAlly;                          // +0x002c (0xa255f4)
    char Unknown002D[0x0030 - 0x002D];
    int GameSpeed;                              // +0x0030 (0xa255f8)
    bool CrapEngineers;                         // +0x0034 (0xa255fc)
    char Unknown0035[0x0038 - 0x0035];
    int UnitCount;                              // +0x0038 (0xa25600)
    int AIPlayers;                              // +0x003c (0xa25604)
    int AIDifficulty;                           // +0x0040 (0xa25608)
    char Unknown0044[0x00A4 - 0x0044];
    bool Flag0A4;                               // +0x00a4 (0xa2566c)
    bool HarvesterTruce;                        // +0x00a5 (0xa2566d)
    char Unknown00A6[0x00A7 - 0x00A6];
    bool FogOfWar;                              // +0x00a7 (0xa2566f)
    bool MCVRedeploy;                           // +0x00a8 (0xa25670)
    char Unknown00A9[0x00AA - 0x00A9];
    wchar_t ScenarioName[0x2F];                 // +0x00aa (0xa25672)
    char Handle[0x14];                          // +0x0108 (0xa256d0)
    int ColorIdx;                               // +0x011c (0xa256e4)
    char Unknown0120[0x0124 - 0x0120];
    int House;                                  // +0x0124 (0xa256ec)
    char Unknown0128[0x012C - 0x0128];
    int Color;                                  // +0x012c (0xa256f4)
    char Unknown0130[0x02C4 - 0x0130];
    int NumPlayers;                             // +0x02c4 (0xa2588c)
    int MaxAhead;                               // +0x02c8 (0xa25890)
    int FrameSendRate;                          // +0x02cc (0xa25894)
    char Unknown02D0[0x02E4 - 0x02D0];
    int Field2E4;                               // +0x02e4 (0xa258ac)
    int Field2E8;                               // +0x02e8 (0xa258b0)
    char Unknown02EC[0x0640 - 0x02EC];
    DynamicVectorClass<MultiMission *> Scenarios;// +0x0640 (0xa25c08)
    char ScenarioFile[0x104];                   // +0x0658 (0xa25c20)
    char Unknown075C[0x2374 - 0x075C];
    bool Flag2374;                              // +0x2374 (0xa2793c)
    char Unknown2375[0x27E0 - 0x2375];
    DynamicVectorClass<NodeNameType *> Players; // +0x27e0 (0xa27da8)
    char Unknown27F8[0x289C - 0x27F8];
    int ModemGameToPlay;                        // +0x289c (0xa27e64)
    char Unknown28A0[0x2908 - 0x28A0];
    int Latency;                                // +0x2908 (0xa27ed0)
};
extern SessionClass Session;                    // 0xa255c8

extern char LastChatMessage[];                  // 0xa5a978, 0x50 bytes (name provisional)
extern int TechLevel;                           // 0x7c3978 (.data, initial 10; name provisional)
extern bool RandomMapIdle;                      // 0x7d11a0 (.data, initial true; name provisional)
extern int PlayerColorRGB[8];                   // 0x7d1178 (GDlgSupp.cpp declares it static)
extern int DefaultChatColor;                    // 0x79233c (.rdata, 0x40ffff; name provisional)
extern wchar_t NullWString[];                   // 0x82208c
extern HWND MainWindow;                         // 0xb0de50

#define IDD_MODEM_HOST          0xF1
#define IDC_CREDITS             0x402
#define IDC_COLOR               0x405
#define IDC_GAME_SPEED          0x529
#define IDC_CHAT_LIST           0x53F
#define IDC_CHAT_EDIT           0x540
#define IDC_CRATES              0x54C
#define IDC_FOG_OF_WAR          0x54D
#define IDC_SHORT_GAME          0x54E
#define IDC_TECH_LEVEL          0x550
#define IDC_CRAP_ENGINEERS      0x551
#define IDC_AI_PLAYERS          0x552
#define IDC_AI_DIFFICULTY       0x553
#define IDC_HARVESTER_TRUCE     0x596
#define IDC_SCENARIO_NAME       0x5A8
#define IDC_SELECT_MAP          0x5AA
#define IDC_NAME                0x5C1
#define IDC_BRIDGE_DESTRUCTION  0x624
#define IDC_SIDE                0x667
#define IDC_GUEST               0x668
#define IDC_UNIT_COUNT          0x669
#define IDC_BASES               0x66A
#define IDC_MCV_REDEPLOY        0x66B
#define IDC_SUPER_WEAPONS       0x69A
#define IDC_BUILD_OFF_ALLY      0x69D

// Custom messages of the game's owner-drawn controls (meanings provisional).
#define WM_SET_TEXT_WIDE        (WM_USER + 0xB2)
#define WM_GET_TEXT_WIDE        (WM_USER + 0xB3)
#define WM_SET_TEXT_COLOR       (WM_USER + 0x98)
#define WM_SET_PAGE_SIZE        (WM_USER + 0xAB)
#define CB_ADDSTRING_COLOR      (WM_USER + 0xC1)
#define CB_ADDSTRING_WIDE       (WM_USER + 0xC2)
#define EN_ENTER                0x501

enum { RESULT_NONE = -1, RESULT_START = 1, RESULT_CANCEL = 2 };

class ModemHostDialogClass {
public:
    bool Process();

private:
    static BOOL CALLBACK Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);
    void Init_Dialog();
    bool Read_Dialog();
    void Send_Chat();
    void Side_Changed();
    void Color_Changed();
    void Name_Changed(bool editing);
    void Set_Guest(wchar_t const * name, int color, int house);
    void Unit_Count_Changed();
    void Tech_Level_Changed();
    void Credits_Changed();
    void AI_Players_Changed();
    void Game_Speed_Changed();
    void AI_Difficulty_Changed();
    void MCV_Redeploy_Clicked();
    void Bases_Clicked();
    void Crates_Clicked();
    void Fog_Of_War_Clicked();
    void Bridge_Destruction_Clicked();
    void Harvester_Truce_Clicked();
    void Short_Game_Clicked();
    void Super_Weapons_Clicked();
    void Build_Off_Ally_Clicked();
    void Crap_Engineers_Clicked();
    void Select_Multi_Map();
    void Select_Random_Map();
    void Send_Timing(bool force);
    bool Get_Message(bool quiet);
    void Send_Game_Options();
    void Send_Message(wchar_t const * message);
    void Display_Message(wchar_t const * name, int color, wchar_t const * message);
    void Sign_Off();
    bool Start_Game(bool loadgame);
    static bool Message_Callback();
    void Send_Preview();

    HWND Dialog;                                // +0x00
    int Result;                                 // +0x04
    bool SettingsChanged;                       // +0x08
    bool OptionsChanged;                        // +0x09
    unsigned long OptionsTime;                  // +0x0c
    unsigned long ResponseTime;                 // +0x10
    unsigned long LastMessageTime;              // +0x14
    unsigned long MessageTimeout;               // +0x18
    unsigned long TimingTime;                   // +0x1c
    bool GuestKnown;                            // +0x20
    wchar_t GuestName[21];                      // +0x22
    int GuestColor;                             // +0x4c
    int GuestHouse;                             // +0x50
    int Version54;                              // +0x54
    int Version58;                              // +0x58
    int Version5C;                              // +0x5c, object size 0x60
};

// ---- end of local declarations ----

static bool FirstTime = true;                   // 0x7ccee8
static ModemHostDialogClass * HostDialog;       // 0xa589fc

static inline int Chat_Color(int color)
{
    int rgb;
    if (color >= 0 && color < 8) {
        rgb = PlayerColorRGB[color];
    } else {
        rgb = DefaultChatColor;
    }
    return rgb;
}

bool ModemHostDialogClass::Process()
{
    bool retval = false;

    Debug_Printf("ModemHost.Dialog(enter)\n");
    Result = RESULT_NONE;
    Dialog = Create_Dialog(IDD_MODEM_HOST, Dialog_Proc, 0);
    if (Dialog) {
        SetWindowLongA(Dialog, DWL_USER, (LONG)this);
        Init_Dialog();
        Show_Dialog(Dialog);

        SettingsChanged = false;
        OptionsChanged = true;
        OptionsTime = TickCount;
        ResponseTime = 10000;
        LastMessageTime = TickCount;
        MessageTimeout = 1200;
        TimingTime = 0;
        GuestKnown = false;
        GuestName[0] = 0;
        GuestColor = -1;
        GuestHouse = -1;
        HostDialog = this;
        Version54 = Func_649690();
        Func_6497D0();
        Version58 = Func_6497B0();
        Version5C = Func_6497C0();

        while (true) {
            Result = RESULT_NONE;
            while (Result < 0) {
                if (Dialog_Abort_Check() == true) {
                    break;
                }
                Send_Timing(false);
                if (Get_Message(false) == true) {
                    break;
                }
                Call_Back_5168E0(false);
            }
            if (Result != RESULT_START) {
                break;
            }
            ShowWindow(Dialog, SW_HIDE);
            if (Start_Game(false) == true) {
                retval = true;
                break;
            }
            ShowWindow(Dialog, SW_SHOW);
        }

        End_Dialog(Dialog);
        HostDialog = NULL;
        if (SettingsChanged == true) {
            Session.Write_MultiPlayer_Settings();
        }
    }

    if (Result == RESULT_CANCEL) {
        Sign_Off();
    }
    Debug_Printf("ModemHost.Dialog(exit %s)\n", (retval == true) ? "true" : "false");
    return retval;
}

BOOL CALLBACK ModemHostDialogClass::Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) {
        return result;
    }

    ModemHostDialogClass * self = (ModemHostDialogClass *)GetWindowLongA(dialog, DWL_USER);

    switch (message) {
        case WM_COMMAND:
            switch (LOWORD(wparam)) {
                case IDCANCEL:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        self->Read_Dialog();
                        self->Result = RESULT_CANCEL;
                    }
                    break;

                case IDOK:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        if (self->Read_Dialog() == true) {
                            self->Send_Game_Options();
                            self->Result = RESULT_START;
                        }
                    }
                    break;

                case IDC_COLOR:
                    if (HIWORD(wparam) == CBN_SELCHANGE) {
                        self->Color_Changed();
                    }
                    break;

                case IDC_CHAT_EDIT:
                    if (HIWORD(wparam) == EN_ENTER) {
                        self->Send_Chat();
                    }
                    break;

                case IDC_CRATES:
                    self->Crates_Clicked();
                    break;

                case IDC_FOG_OF_WAR:
                    self->Fog_Of_War_Clicked();
                    break;

                case IDC_SHORT_GAME:
                    self->Short_Game_Clicked();
                    break;

                case IDC_CRAP_ENGINEERS:
                    self->Crap_Engineers_Clicked();
                    break;

                case IDC_HARVESTER_TRUCE:
                    self->Harvester_Truce_Clicked();
                    break;

                case IDC_SELECT_MAP:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        self->Select_Multi_Map();
                    }
                    break;

                case IDC_NAME:
                    if (HIWORD(wparam) == EN_ENTER || HIWORD(wparam) == EN_CHANGE) {
                        self->Name_Changed(HIWORD(wparam) == EN_CHANGE);
                    }
                    break;

                case IDC_BRIDGE_DESTRUCTION:
                    self->Bridge_Destruction_Clicked();
                    break;

                case IDC_SIDE:
                    if (HIWORD(wparam) == CBN_SELCHANGE) {
                        self->Side_Changed();
                    }
                    break;

                case IDC_BASES:
                    self->Bases_Clicked();
                    break;

                case IDC_MCV_REDEPLOY:
                    self->MCV_Redeploy_Clicked();
                    break;

                case IDC_SUPER_WEAPONS:
                    self->Super_Weapons_Clicked();
                    break;

                case IDC_BUILD_OFF_ALLY:
                    self->Build_Off_Ally_Clicked();
                    break;
            }
            break;

        case WM_HSCROLL:
        case WM_VSCROLL:
            if ((HWND)lparam == GetDlgItem(dialog, IDC_UNIT_COUNT)) {
                self->Unit_Count_Changed();
            } else if ((HWND)lparam == GetDlgItem(dialog, IDC_TECH_LEVEL)) {
                self->Tech_Level_Changed();
            } else if ((HWND)lparam == GetDlgItem(dialog, IDC_CREDITS)) {
                self->Credits_Changed();
            } else if ((HWND)lparam == GetDlgItem(dialog, IDC_AI_PLAYERS)) {
                self->AI_Players_Changed();
            } else if ((HWND)lparam == GetDlgItem(dialog, IDC_AI_DIFFICULTY)) {
                self->AI_Difficulty_Changed();
            } else if ((HWND)lparam == GetDlgItem(dialog, IDC_GAME_SPEED)) {
                self->Game_Speed_Changed();
            }
            break;

        case WM_PAINT:
            if (Preview) {
                Preview->Draw(dialog);
            }
            ValidateRect(dialog, NULL);
            return FALSE;

        case WM_DESTROY:
            if (Preview) {
                delete Preview;
                Preview = NULL;
            }
            return FALSE;

    }
    return FALSE;
}

void ModemHostDialogClass::Init_Dialog()
{
    wchar_t message[0x400];

    Debug_Printf("ModemHost.InitDialog(enter)\n");

    if (FirstTime == true) {
        FirstTime = false;
        Special.Initialize();
        Session.Credits = Rule->Credits;
        Session.Bases = Rule->Bases;
        Session.BridgeDestruction = Rule->BridgeDestruction;
        Session.Crates = Rule->Crates;
        Session.AIPlayers = 0;
        Session.UnitCount = Rule->UnitCount;
        Session.ShortGame = false;
        Session.SuperWeapons = Rule->SuperWeapons;
        Session.BuildOffAlly = Rule->BuildOffAlly;
        Session.GameSpeed = Options.GameSpeed;
        Session.CrapEngineers = false;
    }

    HWND item = GetDlgItem(Dialog, IDC_NAME);
    if (item) {
        SendMessageA(item, EM_LIMITTEXT, 0x13, 0);
        SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)To_Wide(Session.Handle));
    }
    Debug_Printf("Name: %ls\n", Session.Handle);

    item = GetDlgItem(Dialog, IDC_COLOR);
    if (item) {
        SendMessageA(item, CB_RESETCONTENT, 0, 0);
#line 407 "C:\\RA2\\ModemHst.cpp"
        SendMessageA(item, CB_ADDSTRING_COLOR, -1, (LPARAM)Fetch_String("TXT_GOLD", NULL, __FILE__, __LINE__));
        SendMessageA(item, CB_ADDSTRING_COLOR, -1, (LPARAM)Fetch_String("TXT_RED", NULL, __FILE__, __LINE__));
        SendMessageA(item, CB_ADDSTRING_COLOR, -1, (LPARAM)Fetch_String("TXT_BLUE", NULL, __FILE__, __LINE__));
        SendMessageA(item, CB_ADDSTRING_COLOR, -1, (LPARAM)Fetch_String("TXT_GREEN", NULL, __FILE__, __LINE__));
        SendMessageA(item, CB_ADDSTRING_COLOR, -1, (LPARAM)Fetch_String("TXT_ORANGE", NULL, __FILE__, __LINE__));
        SendMessageA(item, CB_ADDSTRING_COLOR, -1, (LPARAM)Fetch_String("TXT_SKY_BLUE", NULL, __FILE__, __LINE__));
        SendMessageA(item, CB_ADDSTRING_COLOR, -1, (LPARAM)Fetch_String("TXT_PURPLE", NULL, __FILE__, __LINE__));
        SendMessageA(item, CB_ADDSTRING_COLOR, -1, (LPARAM)Fetch_String("TXT_PINK", NULL, __FILE__, __LINE__));
        for (int i = 0; i < 8; i++) {
            SendMessageA(item, WM_SET_TEXT_COLOR, i, PlayerColorRGB[i]);
        }
        Session.ColorIdx = Session.Color;
        SendMessageA(item, CB_SETCURSEL, Session.Color, 0);
    }
    Debug_Printf("Color: %d\n", Session.ColorIdx);

    item = GetDlgItem(Dialog, IDC_SIDE);
    if (item) {
        SendMessageA(item, CB_RESETCONTENT, 0, 0);
        for (int house = 0; house < HouseTypes.ActiveCount; house++) {
            HouseTypeClass * type = HouseTypes[house];
            if (type->IsMultiplay) {
                int index = SendMessageA(item, CB_ADDSTRING_WIDE, 0, (LPARAM)type->Full_Name());
                SendMessageA(item, CB_SETITEMDATA, index, house);
            }
        }
        int index = Find_Item_Data(item, -1, Session.House);
        SendMessageA(item, CB_SETCURSEL, index, 0);
    }

    int value;
    item = GetDlgItem(Dialog, IDC_UNIT_COUNT);
    if (item) {
        value = Session.UnitCount;
        SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(Rule->MinUnitCount, Rule->MaxUnitCount));
        SendMessageA(item, TBM_SETPOS, TRUE, value);
    }
    Debug_Printf("UnitCount: %d\n", Session.UnitCount);

    item = GetDlgItem(Dialog, IDC_TECH_LEVEL);
    if (item) {
        value = TechLevel;
        SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(1, 10));
        SendMessageA(item, TBM_SETPOS, TRUE, value);
    }
    Debug_Printf("TechLevel: %d\n", TechLevel);

    item = GetDlgItem(Dialog, IDC_CREDITS);
    if (item) {
        value = Session.Credits;
        SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(Rule->MinCredits, Rule->MaxCredits));
        SendMessageA(item, TBM_SETPOS, TRUE, value);
        SendMessageA(item, WM_SET_PAGE_SIZE, 0, 250);
    }
    Debug_Printf("Credits: %d\n", Session.Credits);

    item = GetDlgItem(Dialog, IDC_AI_PLAYERS);
    if (item) {
        value = Session.AIPlayers;
        SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(0, 6));
        SendMessageA(item, TBM_SETPOS, TRUE, value);
    }
    Debug_Printf("AIPlayers: %d\n", Session.AIPlayers);

    item = GetDlgItem(Dialog, IDC_GAME_SPEED);
    if (item) {
        SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(0, 6));
        SendMessageA(item, TBM_SETPOS, TRUE, 6 - Options.GameSpeed);
    }
    Debug_Printf("Game Speed: %d\n", Session.GameSpeed);

    item = GetDlgItem(Dialog, IDC_AI_DIFFICULTY);
    if (item) {
        value = Session.AIDifficulty;
        SendMessageA(item, TBM_SETRANGE, TRUE, MAKELONG(0, 2));
        SendMessageA(item, TBM_SETPOS, TRUE, value);
    }
    Debug_Printf("AIDifficulty: %d\n", Session.AIDifficulty);

    item = GetDlgItem(Dialog, IDC_MCV_REDEPLOY);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.MCVRedeploy == true, 0);
    }
    Debug_Printf("MCV Redeploy: %s\n", (Session.MCVRedeploy == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_BASES);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.Bases == true, 0);
    }
    Debug_Printf("Bases: %s\n", (Session.Bases == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_CRATES);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.Crates == true, 0);
    }
    Debug_Printf("Crates: %s\n", (Session.Crates == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_FOG_OF_WAR);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.FogOfWar == true, 0);
    }
    Debug_Printf("FogOfWar: %s\n", (Session.FogOfWar == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_BRIDGE_DESTRUCTION);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.BridgeDestruction == true, 0);
    }
    Debug_Printf("BridgeDestroy: %s\n", (Session.BridgeDestruction == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_HARVESTER_TRUCE);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.HarvesterTruce == true, 0);
    }
    Debug_Printf("Harvester Truce: %s\n", (Session.HarvesterTruce == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_SHORT_GAME);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.ShortGame == true, 0);
    }
    Debug_Printf("Short Game: %s\n", (Session.ShortGame == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_SUPER_WEAPONS);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.SuperWeapons == true, 0);
    }
    Debug_Printf("SuperWeapons: %s\n", (Session.SuperWeapons == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_BUILD_OFF_ALLY);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.BuildOffAlly == true, 0);
    }
    Debug_Printf("BuildOffAlly: %s\n", (Session.BuildOffAlly == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_CRAP_ENGINEERS);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.CrapEngineers == true, 0);
    }
    Debug_Printf("Crap Engineers: %s\n", (Session.CrapEngineers == true) ? "ON" : "OFF");

    VerNum.Init();
    srand(NonCriticalRandomNumber(1, 0x7FFF));
    Seed = rand();
    Special.Bit4 = Rule->Field111A;

    if (Preview) {
        delete Preview;
        Preview = NULL;
    }

    Delete_All(Session.Players);
    Set_Scenario(0);
    Session.ScenarioIdx = 0;
    HWND name = GetDlgItem(Dialog, IDC_SCENARIO_NAME);
    SendMessageA(name, WM_SET_TEXT_WIDE, 0, (LPARAM)Session.ScenarioName);
    Session.Flag2374 = true;
    if (CCFileClass(Session.ScenarioFile).Is_Available()) {
        Preview = new PreviewClass;
        Preview->Load_Scenario(Session.ScenarioFile);
        PostMessageA(Dialog, WM_PAINT, 0, 0);
    }

    if (strlen(LastChatMessage) > 0x4E) {
        LastChatMessage[0x4F] = 0;
    }
    if (strlen(LastChatMessage)) {
        Narrow_To_Wide(message, LastChatMessage, -1);
        Display_Message(message, -1, NullWString);
    }
    LastChatMessage[0] = 0;

    item = GetDlgItem(Dialog, IDOK);
    if (item) {
        EnableWindow(item, FALSE);
    }
    NullModem.Func_5C8F90(1);
    Debug_Printf("ModemHost.InitDialog(exit)\n");
}

bool ModemHostDialogClass::Read_Dialog()
{
    wchar_t name[20];
    wchar_t buffer[0x100];

    Debug_Printf("ModemHost.ReadDialog(enter)\n");

    int maxplayers = Scenario_Max_Players(Session.ScenarioIdx);
    int players = 2;
    HWND item = GetDlgItem(Dialog, IDC_AI_PLAYERS);
    if (item) {
        players = SendMessageA(item, TBM_GETPOS, 0, 0) + 2;
    }
    if (maxplayers < players) {
#line 759
        swprintf(buffer, Fetch_String("TXT_SCENARIO_TOO_SMALL", NULL, __FILE__, __LINE__), maxplayers);
        WWMessageBox().Process(buffer, Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
        return false;
    }

    item = GetDlgItem(Dialog, IDC_NAME);
    if (item) {
        SendMessageA(item, WM_GET_TEXT_WIDE, 20, (LPARAM)name);
        Wide_To_Narrow(Session.Handle, name, -1);
    }
    Debug_Printf("Name: %ls\n", Session.Handle);

    item = GetDlgItem(Dialog, IDC_COLOR);
    if (item) {
        Session.ColorIdx = SendMessageA(item, CB_GETCURSEL, 0, 0);
    }
    Debug_Printf("Color: %d\n", Session.ColorIdx);

    item = GetDlgItem(Dialog, IDC_SIDE);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        Session.House = SendMessageA(item, CB_GETITEMDATA, index, 0);
    }

    item = GetDlgItem(Dialog, IDC_UNIT_COUNT);
    if (item) {
        Session.UnitCount = SendMessageA(item, TBM_GETPOS, 0, 0);
    }
    Debug_Printf("UnitCount: %d\n", Session.UnitCount);

    item = GetDlgItem(Dialog, IDC_TECH_LEVEL);
    if (item) {
        TechLevel = SendMessageA(item, TBM_GETPOS, 0, 0);
    }
    Debug_Printf("TechLevel: %d\n", TechLevel);

    item = GetDlgItem(Dialog, IDC_CREDITS);
    if (item) {
        Session.Credits = SendMessageA(item, TBM_GETPOS, 0, 0);
    }
    Debug_Printf("Credits: %d\n", Session.Credits);

    item = GetDlgItem(Dialog, IDC_AI_PLAYERS);
    if (item) {
        Session.AIPlayers = SendMessageA(item, TBM_GETPOS, 0, 0);
    }
    Debug_Printf("AIPlayers: %d\n", Session.AIPlayers);

    item = GetDlgItem(Dialog, IDC_GAME_SPEED);
    if (item) {
        Session.GameSpeed = 6 - SendMessageA(item, TBM_GETPOS, 0, 0);
    }
    Debug_Printf("Game Speed: %d\n", Session.GameSpeed);

    item = GetDlgItem(Dialog, IDC_AI_DIFFICULTY);
    if (item) {
        Session.AIDifficulty = SendMessageA(item, TBM_GETPOS, 0, 0);
    }
    Debug_Printf("AIDifficulty: %d\n", Session.AIDifficulty);

    item = GetDlgItem(Dialog, IDC_MCV_REDEPLOY);
    if (item) {
        Session.MCVRedeploy = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("MCVRedeploy: %s\n", (Session.MCVRedeploy == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_BASES);
    if (item) {
        Session.Bases = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("Bases: %s\n", (Session.Bases == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_CRATES);
    if (item) {
        Session.Crates = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("Crates: %s\n", (Session.Crates == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_FOG_OF_WAR);
    if (item) {
        Session.FogOfWar = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("FogOfWar: %s\n", (Session.FogOfWar == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_BRIDGE_DESTRUCTION);
    if (item) {
        Session.BridgeDestruction = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("BridgeDestroy: %s\n", (Session.BridgeDestruction == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_HARVESTER_TRUCE);
    if (item) {
        Session.HarvesterTruce = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("Harvester Truce: %s\n", (Session.HarvesterTruce == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_SHORT_GAME);
    if (item) {
        Session.ShortGame = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("Short Game: %s\n", (Session.ShortGame == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_SUPER_WEAPONS);
    if (item) {
        Session.SuperWeapons = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("Short Game: %s\n", (Session.ShortGame == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_BUILD_OFF_ALLY);
    if (item) {
        Session.BuildOffAlly = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("Short Game: %s\n", (Session.ShortGame == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_CRAP_ENGINEERS);
    if (item) {
        Session.CrapEngineers = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
    }
    Debug_Printf("Crap Engineers: %s\n", (Session.CrapEngineers == true) ? "ON" : "OFF");

    Debug_Printf("ModemHost.ReadDialog(exit)\n");
    return true;
}

void ModemHostDialogClass::Send_Chat()
{
    wchar_t message[0x100];

    memset(message, 0, sizeof(message));
    HWND item = GetDlgItem(Dialog, IDC_CHAT_EDIT);
    if (item) {
        SendMessageA(item, WM_GET_TEXT_WIDE, 0x100, (LPARAM)message);
        SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)NullWString);
        if (wcslen(message) && message[0] != L'\r') {
            Wcstrim(message);
            Send_Message(message);
        }
    }
}

void ModemHostDialogClass::Side_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_SIDE);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        if (index != CB_ERR) {
            int house = SendMessageA(item, CB_GETITEMDATA, index, 0);
            if (house != CB_ERR) {
                Session.House = house;
                OptionsChanged = true;
                SettingsChanged = true;
            }
        }
    }
}

void ModemHostDialogClass::Color_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_COLOR);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        if (index != CB_ERR) {
            Session.ColorIdx = index;
            OptionsChanged = true;
            SettingsChanged = true;
            SendMessageA(item, WM_SET_TEXT_COLOR, 0, Chat_Color(index));
        }
    }
}

void ModemHostDialogClass::Name_Changed(bool editing)
{
    wchar_t name[20];

    HWND item = GetDlgItem(Dialog, IDC_NAME);
    if (item) {
        SendMessageA(item, WM_GET_TEXT_WIDE, 20, (LPARAM)name);
        Wcstrim(name);
        if (editing == false) {
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)name);
        }
        strcpy(Session.Handle, To_Narrow(name));
        OptionsChanged = true;
        SettingsChanged = true;
    }
}

void ModemHostDialogClass::Set_Guest(wchar_t const * name, int color, int house)
{
    wchar_t buffer[0x50];

    if (_wcsicmp(GuestName, name) || GuestColor != color || GuestHouse != house) {
        wcscpy(GuestName, name);
        GuestColor = color;
        GuestHouse = house;
        HWND item = GetDlgItem(Dialog, IDC_GUEST);
        if (item) {
            swprintf(buffer, L"%s [%s]", name, HouseTypes[house]->UIName);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
            SendMessageA(item, WM_SET_TEXT_COLOR, 0, Chat_Color(color));
        }
        Play_Sound(Rule->GuestJoinSound, 1.0f, 0x2000, 0);
    }
    OptionsChanged = true;
}

void ModemHostDialogClass::Unit_Count_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_UNIT_COUNT);
    if (item) {
        Session.UnitCount = SendMessageA(item, TBM_GETPOS, 0, 0);
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Tech_Level_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_TECH_LEVEL);
    if (item) {
        TechLevel = SendMessageA(item, TBM_GETPOS, 0, 0);
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Credits_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_CREDITS);
    if (item) {
        Session.Credits = SendMessageA(item, TBM_GETPOS, 0, 0);
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::AI_Players_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_AI_PLAYERS);
    if (item) {
        Session.AIPlayers = SendMessageA(item, TBM_GETPOS, 0, 0);
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Game_Speed_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_GAME_SPEED);
    if (item) {
        Session.GameSpeed = 6 - SendMessageA(item, TBM_GETPOS, 0, 0);
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::AI_Difficulty_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_AI_DIFFICULTY);
    if (item) {
        Session.AIDifficulty = SendMessageA(item, TBM_GETPOS, 0, 0);
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::MCV_Redeploy_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_MCV_REDEPLOY);
    if (item) {
        Session.MCVRedeploy = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Bases_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_BASES);
    if (item) {
        Session.Bases = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        if (Session.Bases == false && GetDlgItem(Dialog, IDC_SHORT_GAME) != NULL) {
            Session.ShortGame = false;
            SendDlgItemMessageA(Dialog, IDC_SHORT_GAME, BM_SETCHECK, BST_UNCHECKED, 0);
        }
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Crates_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_CRATES);
    if (item) {
        Session.Crates = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Fog_Of_War_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_FOG_OF_WAR);
    if (item) {
        Session.FogOfWar = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Bridge_Destruction_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_BRIDGE_DESTRUCTION);
    if (item) {
        Session.BridgeDestruction = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Harvester_Truce_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_HARVESTER_TRUCE);
    if (item) {
        Session.HarvesterTruce = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Short_Game_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_SHORT_GAME);
    if (item) {
        Session.ShortGame = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        OptionsChanged = true;
        if (Session.ShortGame && GetDlgItem(Dialog, IDC_BASES) != NULL) {
            Session.Bases = true;
            SendDlgItemMessageA(Dialog, IDC_BASES, BM_SETCHECK, BST_CHECKED, 0);
        }
    }
}

void ModemHostDialogClass::Super_Weapons_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_SUPER_WEAPONS);
    if (item) {
        Session.SuperWeapons = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Build_Off_Ally_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_BUILD_OFF_ALLY);
    if (item) {
        Session.ShortGame = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Crap_Engineers_Clicked()
{
    HWND item = GetDlgItem(Dialog, IDC_CRAP_ENGINEERS);
    if (item) {
        Session.CrapEngineers = (SendMessageA(item, BM_GETCHECK, 0, 0) == BST_CHECKED) ? true : false;
        OptionsChanged = true;
    }
}

void ModemHostDialogClass::Select_Multi_Map()
{
    char oldfile[0x84];
    wchar_t oldname[0x80];

    Debug_Printf("ModemHost.SelectMultiMap(enter)\n");

    int oldindex = Session.ScenarioIdx;
    strcpy(oldfile, Session.ScenarioFile);
    wcscpy(oldname, Session.ScenarioName);
    ShowWindow(Dialog, SW_HIDE);

    if (Select_Map_Dialog(MainWindow) == 2) {
        Session.ScenarioIdx = oldindex;
        Set_Scenario(oldindex);
        Update_Preview(Dialog);
        ShowWindow(Dialog, SW_SHOW);
        if (!stricmp(Session.Scenarios[Session.ScenarioIdx]->FileName, "RandMap.Sed")) {
            delete Preview;
            Preview = new PreviewClass;
            Preview->Load_Image("RandMap.img");
            if (!Preview->Data) {
                Update_Preview(Dialog);
            }
            InvalidateRect(Dialog, NULL, FALSE);
        } else {
            Update_Preview(Dialog);
        }
        InvalidateRect(Dialog, NULL, FALSE);
    } else {
        ShowWindow(Dialog, SW_SHOW);
        if (Set_Scenario(Session.ScenarioIdx) == true) {
            HWND item = GetDlgItem(Dialog, IDC_SCENARIO_NAME);
            SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)Session.ScenarioName);
            if (!stricmp(Session.Scenarios[Session.ScenarioIdx]->FileName, "RandMap.Sed")) {
                if (Preview) {
                    delete Preview;
                    Preview = new PreviewClass;
                    Preview->Load_Image("RandMap.img");
                }
                if (!Preview->Data) {
                    Update_Preview(Dialog);
                }
                InvalidateRect(Dialog, NULL, FALSE);
            } else {
                Update_Preview(Dialog);
            }
        } else {
            Session.ScenarioIdx = oldindex;
        }
    }

    OptionsChanged = true;
    Debug_Printf("ModemHost.SelectMultiMap(exit)\n");
}

void ModemHostDialogClass::Select_Random_Map()
{
    Debug_Printf("ModemHost.SelectRandomMap(enter)\n");

    RandomMapIdle = false;
    if (Random_Map_Dialog(Message_Callback) == 1) {
        RandomMapIdle = true;
        RandomMap.Func_575CC0("RandMap.Sed");
        if (Preview) {
            delete Preview;
            Preview = NULL;
        }
        HWND item = GetDlgItem(Dialog, IDC_SCENARIO_NAME);
        SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)RandomMapName);

        bool found = false;
        int index;
        for (index = 0; index < Session.Scenarios.ActiveCount; index++) {
            if (!stricmp(Session.Scenarios[index]->FileName, "RandMap.Sed")) {
                found = true;
                break;
            }
        }

        char * digest = Random_Map_Digest();
        if (!found) {
            Session.Scenarios.Add(new MultiMission("RandMap.Sed", RandomMapName, digest, true));
        } else {
            Session.Scenarios[index]->Set_Digest(digest);
            Session.Scenarios[index]->Set_Description(RandomMapName);
        }
        delete digest;

        if (Set_Scenario(index) == true) {
            Session.ScenarioIdx = index;
            strcpy(Session.ScenarioFile, "RandMap.Sed");
            strcpy(Scen->ScenarioName, Session.ScenarioFile);
            if (CCFileClass(Session.ScenarioFile).Is_Available()) {
                Preview = new PreviewClass;
                Preview->Load_Image("RandMap.img");
                PostMessageA(Dialog, WM_PAINT, 0, 0);
            }
        }
        OptionsChanged = true;
    }

    RandomMapIdle = true;
    Debug_Printf("ModemHost.SelectMultiMap(exit)\n");
}

void ModemHostDialogClass::Send_Timing(bool force)
{
    SerialPacketType packet;

    NullModem.Service();

    if ((OptionsChanged == true && (unsigned long)TickCount - OptionsTime > 30) || force == true) {
        Send_Game_Options();
        OptionsTime = TickCount;
        OptionsChanged = false;
    }

    if ((unsigned long)TickCount - TimingTime > 40) {
        memset(&packet, 0, sizeof(packet));
        packet.Command = SERIAL_TIMING;
        packet.ResponseTime = NullModem.Response_Time();
        packet.ID = Session.ModemGameToPlay;
        NullModem.Send_Message(&packet, sizeof(packet), 0);
        TimingTime = TickCount;
    }
}

bool ModemHostDialogClass::Get_Message(bool quiet)
{
    bool same;
    int packetlen;
    SerialPacketType packet;

    if (NullModem.Get_Message(&packet, &packetlen) > 0) {
        LastMessageTime = TickCount;
        MessageTimeout = 1200;

        if (packet.Command >= SERIAL_CONNECT && packet.Command < SERIAL_LAST && packet.Command != SERIAL_MESSAGE
            && packet.ID == Session.ModemGameToPlay) {
            Debug_Printf("Received our own packet back\n");
            if (!quiet) {
#line 2018
                WWMessageBox().Process(Fetch_String("TXT_SYSTEM_NOT_RESPONDING", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            }
            return true;
        }

        switch (packet.Command) {
            case SERIAL_SIGNOFF:
            {
                Debug_Printf("Received SignOff!\n");
                unsigned long starttime = TickCount;
                while ((unsigned long)TickCount - starttime < 60) {
                    Call_Back();
                    NullModem.Service();
                }
                if (!quiet) {
#line 2038
                    WWMessageBox().Process(Fetch_String("TXT_USER_SIGNED_OFF", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                }
                LastMessageTime = TickCount;
                Shutdown_Modem();
                return true;
            }

            case SERIAL_GAME_OPTIONS:
            {
                Debug_Printf("Received game options\n");
                int version = VerNum.Verify(packet.Options.MinVersion, packet.Options.MaxVersion);
                if (version == 0) {
                    if (!quiet) {
#line 2059
                        WWMessageBox().Process(Fetch_String("TXT_DESTGAME_OUTDATED", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    }
                    LastMessageTime = TickCount;
                    return true;
                }
                if (version == -1) {
                    if (!quiet) {
#line 2068
                        WWMessageBox().Process(Fetch_String("TXT_YOURGAME_OUTDATED", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    }
                    LastMessageTime = TickCount;
                    return true;
                }
                same = true; // level-2 1.001: flag form (mov cl,1; je; xor cl,cl)
                if (packet.Options.Version54 != Version54) {
                    same = false;
                }
                if (packet.Version5C != Version5C) {
                    same = false;
                }
                if (packet.Version58 != Version58) {
                    same = false;
                }
                if (!same) {
                    if (!quiet) {
#line 2129
                        WWMessageBox().Process(Fetch_String("TXT_MISMATCH", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    }
                    LastMessageTime = TickCount;
                    return true;
                }
                Session.Version = VerNum.Version_Number(version);
                Set_Guest(To_Wide(packet.Name), packet.Options.Color, packet.Options.House);
                GuestKnown = true;
                break;
            }

            case SERIAL_ACCEPT_OPTIONS:
                Debug_Printf("Received Accept Options\n");
                EnableWindow(GetDlgItem(Dialog, IDOK), TRUE);
                break;

            case SERIAL_MESSAGE:
                Debug_Printf("Received serial message\n");
                Display_Message(To_Wide(packet.Name), packet.ID, packet.Message);
                if (!quiet) {
                    Play_Sound(Rule->ChatSound, 1.0f, 0x2000, 0);
                }
                break;

            case SERIAL_TIMING:
                Debug_Printf("Received timing packet\n");
                ResponseTime = packet.ResponseTime;
                if (!GuestKnown) {
                    OptionsChanged = true;
                }
                break;

            case SERIAL_SCORE_SCREEN:
                Debug_Printf("Received score screen packet\n");
                break;

            case SERIAL_PREVIEW_REQUEST:
                Send_Preview();
                LastMessageTime = TickCount;
                break;

            default:
                Debug_Printf("Received packet\n");
                break;
        }
    }

    unsigned long elapsed = (unsigned long)TickCount - LastMessageTime;
    if (elapsed > MessageTimeout) {
        Debug_Printf("Timeout! %d ticks since last incoming message\n", elapsed);
        if (!quiet) {
#line 2197
            WWMessageBox().Process(Fetch_String("TXT_SYSTEM_NOT_RESPONDING", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
        }
        return true;
    }
    return false;
}

void ModemHostDialogClass::Send_Game_Options()
{
    SerialPacketType packet;

    Debug_Printf("Sending game options packet\n");
    EnableWindow(GetDlgItem(Dialog, IDOK), FALSE);

    memset(&packet, 0, sizeof(packet));
    packet.Command = SERIAL_GAME_OPTIONS;
    packet.Options.Version54 = Version54;
    packet.Version58 = Version58;
    packet.Version5C = Version5C;
    packet.ValueD8 = Func_72C6B0();
    packet.Options.MinVersion = VerNum.Min_Version();
    packet.Options.MaxVersion = VerNum.Max_Version();
    packet.Options.Seed = Seed;
    packet.Options.Special = Special;
    packet.GameSpeed = Session.GameSpeed;
    packet.Options.ShortGame = Session.ShortGame;
    packet.Options.SuperWeapons = Session.SuperWeapons;
    packet.Options.BuildOffAlly = Session.BuildOffAlly;
    packet.Options.CrapEngineers = Session.CrapEngineers;
    packet.ID = Session.ModemGameToPlay;
    strcpy(packet.Name, Session.Handle);
    packet.Options.House = Session.House;
    packet.Options.Color = Session.ColorIdx;
    packet.Options.Credits = Session.Credits;
    packet.Options.Bases = Session.Bases;
    packet.Options.MCVRedeploy = Session.MCVRedeploy;
    packet.Options.BridgeDestruction = Session.BridgeDestruction;
    packet.Options.Crates = Session.Crates;
    packet.Options.AIPlayers = Session.AIPlayers;
    packet.Options.HarvesterTruce = Session.HarvesterTruce;
    packet.Options.FogOfWar = Session.FogOfWar;
    packet.Options.AIDifficulty = Session.AIDifficulty;
    packet.Options.TechLevel = TechLevel;
    packet.Options.UnitCount = Session.UnitCount;
    wcscpy(packet.Options.Description, Session.Scenarios[Session.ScenarioIdx]->Description);
    CCFileClass file(Session.Scenarios[Session.ScenarioIdx]->FileName);
    packet.FileLength = file.Size();
    strncpy(packet.ScenarioFile, Session.Scenarios[Session.ScenarioIdx]->FileName, sizeof(packet.ScenarioFile));
    strncpy(packet.Digest, Session.Scenarios[Session.ScenarioIdx]->Digest, sizeof(packet.Digest));
    packet.Options.IsOfficial = Session.Scenarios[Session.ScenarioIdx]->IsOfficial;
    NullModem.Send_Message(&packet, sizeof(packet), 1);
}

void ModemHostDialogClass::Send_Message(wchar_t const * message)
{
    SerialPacketType packet;

    if (message) {
        memset(&packet, 0, sizeof(packet));
        packet.Command = SERIAL_MESSAGE;
        strcpy(packet.Name, Session.Handle);
        packet.ID = Session.ColorIdx;
        wcscpy(packet.Message, message);
        NullModem.Send_Message(&packet, sizeof(packet), 1);
        NullModem.Service();
        Display_Message(To_Wide(Session.Handle), Session.ColorIdx, message);
    }
}

void ModemHostDialogClass::Display_Message(wchar_t const * name, int color, wchar_t const * message)
{
    wchar_t buffer[0x100];

    if (message) {
        HWND item = GetDlgItem(Dialog, IDC_CHAT_LIST);
        if (item) {
            int rgb = Chat_Color(color);
            swprintf(buffer, L"[%s] %s", name, message);
            Add_Chat_Text(rgb, buffer, item);
        }
    }
}

void ModemHostDialogClass::Sign_Off()
{
    int packetlen;
    SerialPacketType packet;
    SerialPacketType receivepacket;

    memset(&packet, 0, sizeof(packet));
    packet.Command = SERIAL_SIGNOFF;
    packet.Options.Color = Session.ColorIdx;
    packet.ID = Session.ModemGameToPlay;
    NullModem.Send_Message(&packet, sizeof(packet), 1);

#line 2398
    HWND dialog = Create_Cancel_Dialog(Fetch_String("TXT_SIGNING_OFF", NULL, __FILE__, __LINE__), NULL, NULL);
    if (dialog) {
        Show_Dialog(dialog);
    }

    unsigned long starttime = TickCount;
    while (NullModem.Num_Send()) {
        if ((unsigned long)TickCount - starttime >= 300) {
            break;
        }
        if (NullModem.Get_Message(&receivepacket, &packetlen) > 0 && receivepacket.Command == SERIAL_SIGNOFF
            && receivepacket.ID == Session.ModemGameToPlay) {
            break;
        }
        Call_Back();
        Windows_Message_Handler();
        NullModem.Service();
    }

    Shutdown_Modem();
    if (dialog) {
        End_Dialog(dialog);
    }
}

bool ModemHostDialogClass::Start_Game(bool loadgame)
{
    int packetlen;
    SerialPacketType packet;
    SerialPacketType receivepacket;

    Debug_Printf("ModemHost.StartGame(enter)\n");
    Debug_Printf("LoadGame = %s\n", (loadgame == true) ? "true" : "false");
    if (loadgame == true) {
        return false;
    }

    Scen->ScenarioIndex = Session.ScenarioIdx;
    strcpy(Scen->ScenarioName, Session.Scenarios[Session.ScenarioIdx]->FileName);
    Scen->Field610 = 1;
    Scen->Field60C = 1;
    Session.NumPlayers = 0;

    NodeNameType * who = new NodeNameType;
    if (who) {
        wcscpy(who->Name, To_Wide(Session.Handle));
        who->House = Session.House;
        who->Color = Session.ColorIdx;
        who->ProcessTime = -1;
        Session.Players.Add(who);
    }

    who = new NodeNameType;
    if (who) {
        wcscpy(who->Name, GuestName);
        who->House = GuestHouse;
        who->Color = GuestColor;
        who->ProcessTime = -1;
        Session.Players.Add(who);
    }

    if (Session.Players.ActiveCount != 2) {
        return false;
    }

    memset(&packet, 0, sizeof(packet));
    packet.Command = SERIAL_GO;
    packet.ResponseTime = NullModem.Response_Time();
    if (ResponseTime != 10000 && packet.ResponseTime < ResponseTime) {
        packet.ResponseTime = ResponseTime;
    }

    Options.GameSpeed = Session.GameSpeed;
    Session.FrameSendRate = 5;
    Session.Latency = 0;
    Session.Field2E4 = 0;
    Session.Field2E8 = 0;
    if (Session.Version == 2) {
        unsigned long maxahead = ((packet.ResponseTime / 8 + 4) / 5) * 5;
        if (maxahead > 10) {
            Session.MaxAhead = maxahead;
        } else {
            Session.MaxAhead = 10;
        }
    } else {
        Session.MaxAhead = packet.ResponseTime / 8;
        if (Session.MaxAhead <= Session.FrameSendRate) {
            Session.MaxAhead = Session.FrameSendRate;
        }
    }

    packet.ID = Session.ModemGameToPlay;
    NullModem.Send_Message(&packet, sizeof(packet), 1);

#line 2540
    HWND dialog = Create_Cancel_Dialog(Fetch_String("TXT_SENDING_GO", NULL, __FILE__, __LINE__), NULL, NULL);
    if (dialog) {
        Show_Dialog(dialog);
    }

    unsigned long starttime = TickCount;
    while ((NullModem.Num_Send() && (unsigned long)TickCount - starttime < 1800) || (unsigned long)TickCount - starttime < 60) {
        Call_Back();
        Windows_Message_Handler();
        NullModem.Service();
    }

    if (dialog) {
#line 2557
        Set_Cancel_Dialog_Text(dialog, Fetch_String("TXT_WAITING_GO", NULL, __FILE__, __LINE__));
    }

    Debug_Printf("Waiting for 'GO' response.\n");
    starttime = TickCount;
    do {
        Call_Back();
        Windows_Message_Handler();
        NullModem.Service();
        if (NullModem.Get_Message(&receivepacket, &packetlen) > 0) {
            Debug_Printf("Received message\n");
            if (receivepacket.Command == SERIAL_READY_TO_GO) {
                Debug_Printf("Received GO message\n");
                break;
            }
            if (receivepacket.Command == SERIAL_NO_SCENARIO) {
#line 2582
                WWMessageBox().Process(Fetch_String("TXT_NO_EXPANSION_SCENARIO", NULL, __FILE__, __LINE__), Fetch_String("TXT_CANCEL", NULL, __FILE__, __LINE__));
                LastMessageTime = TickCount;
                Debug_Printf("***Guest doesn't have scenario!\n");
                return false;
            }
            if (receivepacket.Command == SERIAL_REQ_SCENARIO) {
                Debug_Printf("About to call 'Send_Remote_File'.\n");
                Send_Remote_File(Scen->ScenarioName, 1, 0, 0);
                break;
            }
        }
    } while ((unsigned long)TickCount - starttime < 1200);

    if (dialog) {
        End_Dialog(dialog);
    }
    NullModem.Func_5C8A50();
    Session.Flag2374 = false;
    Scen->ScenarioIndex = Session.ScenarioIdx;
    Session.NumPlayers = Session.Players.ActiveCount;
    NetworkEventMode = 0;
    Session.Version = 2;
    Special.Bit6 = true;
    Special.Bit7 = true;
    Special.IsHarvesterTruce = Session.HarvesterTruce;
    Special.IsBridgeDestruction = Session.BridgeDestruction;
    Scen->Bit10 = false;
    Session.Flag0A4 = true;
    Special.Apply_To_Game();
    Debug_Printf("ModemHost.StartGame(exit)\n");
    return true;
}

bool ModemHostDialogClass::Message_Callback()
{
    if (HostDialog) {
        HostDialog->Send_Timing(false);
        HostDialog->Get_Message(true);
    }
    Call_Back();
    return false;
}

void ModemHostDialogClass::Send_Preview()
{
    int size;
    int packetlen;
    CDTimerClass<SystemTimerClass> timer;
    SerialPacketType packet;
    SerialPacketType receivepacket;

    if (stricmp(Session.ScenarioFile, "RandMap.Sed")) {
        return;
    }

    Debug_Printf("Starting map preview upload\n");
    memset(&packet, 0, sizeof(packet));
    packet.Command = SERIAL_PREVIEW;
    NullModem.Send_Message(&packet, sizeof(packet), 1);

    timer = 600;
    while (NullModem.Num_Send() > 0 && timer) {
        Call_Back();
    }

    bool acknowledged = false;
    timer = 1800;
    do {
        Call_Back();
        if (NullModem.Get_Message(&receivepacket, &packetlen) > 0 && receivepacket.Command == SERIAL_PREVIEW_ACK) {
            acknowledged = true;
        }
    } while (!acknowledged && timer);
    if (!acknowledged) {
        Debug_Printf("Failed to get SERIAL_PREVIEW_ACK\n");
        return;
    }

    size = 0;
    void * image = Preview->Get_Data(0x40, &size);
    Debug_Printf("Preview size is %d bytes\n", size);
    char * buffer = new char [size * 4];
    BufferPipe bpipe(buffer, size * 4);
    LZOPipe lpipe(LZOPipe::COMPRESS, 0x2000);
    lpipe.Put_To(&bpipe);
    int compressed = lpipe.Put(image, size);
    compressed += lpipe.End();
    Debug_Printf("Compressed preview image is %d bytes\n", compressed);

    RawFileClass file("Preview.bin");
    if (file.Is_Available()) {
        file.Delete();
    }
    file.Open(WRITE);
    file.Write(&size, sizeof(size));
    file.Write(buffer, compressed);
    file.Close();
    delete [] buffer;

    Debug_Printf("Calling Send_Remote_File to send the preview\n");
    Send_Remote_File("Preview.bin", 1, 0, 0);
}
