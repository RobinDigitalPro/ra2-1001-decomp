// C:\RA2\ModemGst.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Modem / null-modem game guest dialog (resource 0xf2): the joining player's view of the game
// set-up, the chat line, the option packets of the host, sign-off, the start of the game and the
// download of the map preview. Code range 0x592e10..0x595a1e; ModemHst.cpp follows at 0x595a20.
// Class names come from RTTI where a vtable exists (NullModemClass, VersionClass, Straw,
// BufferStraw, LZOStraw, RawFileClass, HouseTypeClass); all other class, method and variable
// names are provisional (Westwood style).
#include "GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
void Wide_To_Narrow(char * dest, wchar_t const * src, int length);      // 0x6eed90 (name provisional)
void Narrow_To_Wide(wchar_t * dest, char const * src, int length);      // 0x6eed60 (name provisional)
wchar_t * To_Wide(char const * string);         // 0x6eee20, rotating buffers (name provisional)
void Wcstrim(wchar_t * buffer);                 // 0x6e4240 (wide version, provisional)

// Dialog support (see also NullDlg.CPP / PhoneEd.cpp).
HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);            // 0x5f72d0
void Show_Dialog(HWND dialog);          // 0x5f7480
void End_Dialog(HWND dialog);           // 0x5f73a0
bool Dialog_Abort_Check();              // 0x5f7d70, pumps messages, true when the dialog must close
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
HWND Create_Cancel_Dialog(wchar_t const * text, wchar_t const * button, bool * cancelled);  // 0x5f7e80 (provisional)
void Call_Back_5168E0(bool flag);       // 0x5168e0, called while the dialog runs (meaning unknown)
void Windows_Message_Handler();                       // 0x5b29f0 (provisional)
void Call_Back();                     // 0x4821e0 (provisional; see CampScor.cpp)
int Find_Item_Data(HWND combo, int start, int data);    // 0x72b9d0
void Add_Chat_Text(int rgb, wchar_t const * text, HWND list);  // 0x5bd930 (name provisional)
void Update_Preview(HWND dialog);       // 0x5c15d0 (name as in ModemHst.cpp)
void Shutdown_Modem();                  // 0x5c70f0 (NullDlg.CPP)
int Play_Sound(int voc, float volume, int pan, int flags);   // 0x708970 (names provisional, as in Options.CPP)
bool Get_File_From_Host(char * filename, int flag, int unknown);           // 0x661e50 (name from a debug string)
bool Is_Scenario_Available(char const * filename, int crc, char const * name, bool random, int unknown);  // 0x663180 (provisional)
int Func_649690();                      // 0x649690 (meaning unknown)
void Func_6497D0();                     // 0x6497d0 (meaning unknown)
int Func_6497B0();                      // 0x6497b0 (meaning unknown)
int Func_6497C0();                      // 0x6497c0 (meaning unknown)
int Func_72C6B0();                      // 0x72c6b0 (meaning unknown)

extern wchar_t NullWString[];           // 0x82208c (.bss), shared empty wide string (name provisional)

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
extern TTimerClass<SystemTimerClass> TickCount;     // 0x821cc0 (name provisional)

// Count-down timer (only used as a local here; as in NullDlg.CPP).
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

// File class hierarchy (copied from Options.CPP; RTTI FileClass, RawFileClass).
class FileClass {
public:
    virtual ~FileClass();
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
    virtual long Read(void * buffer, long size);    // 0x630330
    virtual long Seek(long pos, int dir = 1);
    virtual long Size();                    // 0x630720
    virtual long Write(void const * buffer, long size);
    virtual void Close();
    virtual unsigned long Get_Date_Time();
    virtual bool Set_Date_Time(unsigned long datetime);
    virtual void Error(int error, int canretry = false, char const * filename = NULL);
private:
    char RawFileData[0x1C];             // +0x04, layout not reconstructed
};

// Owned or borrowed memory block (0x438140 constructor, 0x438290 destructor; Restate.cpp).
class Buffer {
public:
    Buffer(void * buffer = NULL, long size = 0);
    ~Buffer();
private:
    void * BufferPtr;
    long Size;
    bool IsAllocated;
};

// Data straws (RTTI .?AVStraw@@ vtable 0x7899f8, .?AVBufferStraw@@ 0x7899e8, .?AVLZOStraw@@ 0x7908ac).
class Straw {
public:
    Straw() : ChainTo(0), ChainFrom(0) {}
    virtual ~Straw();                               // 0x6906b0
    virtual void Get_From(Straw * straw);           // 0x6906f0
    virtual int Get(void * source, int slen);       // 0x690740

    Straw * ChainTo;        // +0x04
    Straw * ChainFrom;      // +0x08
};

class BufferStraw : public Straw {
public:
    BufferStraw(void const * buffer, int length) : BufferPtr((void *)buffer, length), Index(0) {}
    virtual int Get(void * source, int slen);       // 0x75f180

    Buffer BufferPtr;       // +0x0c
    int Index;              // +0x18
};

class LZOStraw : public Straw {
public:
    enum CompControl { COMPRESS, DECOMPRESS };
    LZOStraw(CompControl control, int blocksize = 0x2000);  // 0x53d190
    virtual ~LZOStraw();                            // 0x53d1f0
    virtual int Get(void * source, int slen);       // 0x53d230
private:
    char LZOData[0x28 - 0x0C];  // +0x0c, layout not reconstructed
};

// Player colours of the colour combo box (GDlgSupp.cpp defines the table).
extern int PlayerColorRGB[8];                   // 0x7d1178
extern int DefaultColorRGB;                     // 0x79233c (.data, 0x40ffff; name provisional)

inline int Color_RGB(int color)
{
    return (color >= 0 && color < 8) ? PlayerColorRGB[color] : DefaultColorRGB;
}

// RTTI .?AVHouseTypeClass@@; only the fields used here.
class HouseTypeClass {
public:
    char Unknown00[0x60];
    wchar_t const * UIName;                     // +0x60
    char Unknown64[0x1A5 - 0x64];
    bool IsMultiplay;                           // +0x1a5, country offered in multiplayer (provisional)
};
extern DynamicVectorClass<HouseTypeClass *> HouseTypes;    // 0xa1e038

// RTTI .?AVVersionClass@@ (vtable 0x78dabc, one slot); the global object is called directly.
class VersionClass {
public:
    int Version_Protocol(int version);          // 0x707cf0 (name provisional)
    void Init_Clipping();                       // 0x707d20 (name provisional)
    int Clip_Version(int minver, int maxver);   // 0x707d30, 0 = other side outdated, -1 = we are outdated
    int Min_Version();                          // 0x707d70
    int Max_Version();                          // 0x707d80
};
extern VersionClass VerNum;                     // 0xa288c8

// Special game flags (0xa28570), 32 bits; only the bits used here (names provisional).
struct SpecialClass {
    bool Is_Equal(SpecialClass const * other) const;   // 0x680af0 (name provisional)
    void Update();                              // 0x680b10 (name provisional)

    unsigned Bits0 : 6;
    unsigned IsBit6 : 1;
    unsigned IsBit7 : 1;
    unsigned Bits8 : 3;
    unsigned IsHarvesterTruce : 1;              // bit 11
    unsigned Bits12 : 3;
    unsigned IsBridgeDestruction : 1;           // bit 15
    unsigned Bits16 : 16;
};
extern SpecialClass Special;                    // 0xa28570

struct GameOptionsType {
    int GameSpeed;                              // +0x00
};
extern GameOptionsType Options;                 // 0xa28758 (OptionsClass, only GameSpeed here)
extern int BuildLevel;                          // 0x7c3978
extern int Seed;                                // 0xa2897c (name provisional)
extern int NetworkEventMode;                    // 0xa2896c (meaning unknown)

class ScenarioClass {
public:
    int Flags;                                  // +0x000 (bit 10 cleared here)
    char Unknown004[0x834 - 0x004];
    int Unknown834;                             // +0x834
    char Unknown838[0x83C - 0x838];
    char ScenarioName[1];                       // +0x83c
};
extern ScenarioClass * Scen;                    // 0xa255c0

// Map preview image (0xa5a860); 4 bytes, no vtable (names provisional).
class PreviewClass {
public:
    PreviewClass();                             // 0x615010
    ~PreviewClass();                            // 0x615020
    void Draw(HWND dialog);                     // 0x615040
    void Set_Image(void * image);               // 0x616510
    void * Data;
};
extern PreviewClass * Preview;           // 0xa5a860
extern char PendingMessage[0x50];               // 0xa5a978 (shown once when the dialog opens; provisional)

// Serial game packet, 0xfa bytes. The layout after the header depends on the command; the
// fields below are those of the guest/host game options packet (union members provisional).
#pragma pack(push, 1)
struct SerialPacketType {
    int Command;                                // +0x00
    char Name[20];                              // +0x04
    unsigned char ID;                           // +0x18, game type of the sender (colour in messages)
    union {
        wchar_t Message[0x70];                  // +0x19
        struct {
            int House;                          // +0x19
            char Color;                         // +0x1d
            int MinVersion;                     // +0x1e
            int MaxVersion;                     // +0x22
            wchar_t ScenarioName[44];           // +0x26
            int Credits;                        // +0x7e
            unsigned IsBases : 1;               // +0x82
            unsigned IsBridgeDestruction : 1;
            unsigned IsCrates : 1;
            unsigned Unused3 : 1;
            unsigned IsRandom : 1;
            unsigned Unused5 : 27;
            int Unknown86;                      // +0x86
            unsigned char BuildLevel;           // +0x8a
            unsigned char UnitCount;            // +0x8b
            unsigned char AIPlayers;            // +0x8c
            unsigned char AIDifficulty;         // +0x8d
            unsigned Unused0 : 1;               // +0x8e
            unsigned IsHarvesterTruce : 1;
            unsigned IsMCVRedeploy : 1;
            unsigned IsFogOfWar : 1;
            unsigned IsShortGame : 1;
            unsigned IsSuperWeapons : 1;
            unsigned IsBuildOffAlly : 1;
            unsigned IsCrapEngineers : 1;
            unsigned Unused8 : 24;
            int Seed;                           // +0x92
            SpecialClass Special;               // +0x96
            unsigned ResponseTime;              // +0x9a
            int ScenarioCRC;                    // +0x9e
            unsigned char GameSpeed;            // +0xa2
            char ScenarioFile[13];              // +0xa3
            char ScenarioDesc[0x20];            // +0xb0
            int UnknownD0;                      // +0xd0
            int UnknownD4;                      // +0xd4
            int UnknownD8;                      // +0xd8
            char UnknownDC[0xFA - 0xDC];
        } Info;
    };
};

// Entry of the session player list (0x71 bytes; constructor of the address only).
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

enum SerialCommandType {
    SERIAL_GAME_OPTIONS = 0x65,
    SERIAL_SIGN_OFF = 0x66,
    SERIAL_GO = 0x67,
    SERIAL_MESSAGE = 0x68,
    SERIAL_TIMING = 0x69,
    SERIAL_SCORE_SCREEN = 0x6A,
    SERIAL_LOAD_GAME = 0x6B,
    SERIAL_LAST_COMMAND = 0x6D,
    SERIAL_READY_TO_GO = 0x72,
    SERIAL_NO_SCENARIO = 0x73,
    SERIAL_ACCEPT = 0x74,
    SERIAL_PREVIEW_MODE = 0x75,
    SERIAL_PREVIEW_ACK = 0x76,
};

// RTTI .?AVNullModemClass@@; the global object is called directly.
class NullModemClass {
public:
    void Reset_Response_Time();                 // 0x5c8a50 (name provisional)
    int Send_Message(void * buf, int buflen, int ack_req);  // 0x5c8c80
    int Get_Message(void * buf, int * buflen);  // 0x5c8cc0
    int Service();                              // 0x5c8cf0
    int Num_Send();                             // 0x5c8f30 (name provisional)
    unsigned Response_Time();                   // 0x5c8f70 (name provisional)
    void Func_5C8F90(int flag);                 // 0x5c8f90 (meaning unknown)
};
extern NullModemClass NullModem;                // 0xa28668

struct ScenarioDescType {
    wchar_t Description[0x2C];                  // +0x00
    char Filename[1];                           // +0x58
};

// Session object at 0xa255c8; only the members used here, at their offsets.
class SessionClass {
public:
    void Write_MultiPlayer_Settings();          // 0x666d70 (name provisional)

    char Unknown0000[0x14];
    int CommProtocol;                           // +0x0014
    char Unknown0018[0x1C - 0x18];
    int Unknown1C;                              // +0x001c
    bool IsBases;                               // +0x0020
    char Unknown0021[0x24 - 0x21];
    int Credits;                                // +0x0024
    bool IsBridgeDestruction;                   // +0x0028
    bool IsCrates;                              // +0x0029
    bool IsShortGame;                           // +0x002a
    bool IsSuperWeapons;                        // +0x002b
    bool IsBuildOffAlly;                        // +0x002c
    char Unknown002D[0x30 - 0x2D];
    int GameSpeed;                              // +0x0030
    bool IsCrapEngineers;                       // +0x0034
    char Unknown0035[0x38 - 0x35];
    int UnitCount;                              // +0x0038
    int AIPlayers;                              // +0x003c
    int AIDifficulty;                           // +0x0040
    char Unknown0044[0xA4 - 0x44];
    bool UnknownA4;                             // +0x00a4
    bool IsHarvesterTruce;                      // +0x00a5
    char Unknown00A6[1];
    bool IsFogOfWar;                            // +0x00a7
    bool IsMCVRedeploy;                         // +0x00a8
    char Unknown00A9[1];
    wchar_t ScenarioName[0x2C];                 // +0x00aa
    char Unknown0102[0x108 - 0x102];
    char Handle[20];                            // +0x0108
    int ColorIdx;                               // +0x011c
    char Unknown0120[4];
    int House;                                  // +0x0124
    char Unknown0128[4];
    int PrefColor;                              // +0x012c
    char Unknown0130[0x2C4 - 0x130];
    int NumPlayers;                             // +0x02c4
    int MaxAhead;                               // +0x02c8
    int FrameSendRate;                          // +0x02cc
    char Unknown02D0[0x2E4 - 0x2D0];
    int Unknown2E4;                             // +0x02e4
    int Unknown2E8;                             // +0x02e8
    char Unknown02EC[0x640 - 0x2EC];
    DynamicVectorClass<ScenarioDescType *> Scenarios;   // +0x0640
    char ScenarioFile[0x85A - 0x658];           // +0x0658
    char ScenarioDesc[0x87C - 0x85A];           // +0x085a
    int ScenarioCRC;                            // +0x087c
    bool IsRandomScenario;                      // +0x0880
    char Unknown0881[0x2374 - 0x881];
    bool Flag2374;                              // +0x2374
    char Unknown2375[0x27E0 - 0x2375];
    DynamicVectorClass<NodeNameType *> Players; // +0x27e0
    char Unknown27F8[0x289C - 0x27F8];
    int ModemGameToPlay;                        // +0x289c
    char Unknown28A0[0x2908 - 0x28A0];
    int Latency;                                // +0x2908
};
extern SessionClass Session;                    // 0xa255c8

void Delete_All(DynamicVectorClass<NodeNameType *> & vector);  // 0x5a4070 (MPLayer.CPP)

class RulesClass {
public:
    char Unknown0000[0x5CC];
    int IncomingMessage;                        // +0x5cc, sound played for a message (provisional)
    char Unknown05D0[0x5D4 - 0x5D0];
    int OptionsChanged;                         // +0x5d4, sound played when the options change (provisional)
    char Unknown05D8[0x10E8 - 0x5D8];
    int MinCredits;                             // +0x10e8 (names of these limits provisional)
    char Unknown10EC[4];
    int MaxCredits;                             // +0x10f0
    char Unknown10F4[4];
    int MinUnitCount;                           // +0x10f8
    char Unknown10FC[4];
    int MaxUnitCount;                           // +0x1100
};
extern RulesClass * Rule;                       // 0x821b88

// The guest dialog, used as a local by Select_Serial_Dialog (NullDlg.CPP); 0x5c bytes.
class ModemGuestDialogClass {
public:
    bool Process();                             // 0x592e10
    static BOOL CALLBACK Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x592f70
    void Init_Dialog();                         // 0x593340
    void Read_Dialog();                         // 0x593b50
    void Chat_Input();                          // 0x593c30
    void House_Changed();                       // 0x593dc0
    void Color_Changed();                       // 0x593e10
    void Name_Changed(bool typing);             // 0x593eb0
    void Set_Host(wchar_t const * name, int color, int house);  // 0x593f30
    void Show_Options();                        // 0x594020
    void Accept();                              // 0x5942f0
    void Service(bool force);                   // 0x594350
    bool Receive();                             // 0x594480
    bool Decode_Options(SerialPacketType * packet); // 0x594c50
    void Send_Info();                           // 0x595130
    void Send_Message(wchar_t const * text);    // 0x595200
    void Display_Message(wchar_t const * name, int color, wchar_t const * text);   // 0x595310
    void Sign_Off();                            // 0x595390
    bool Start_Game(bool load);                 // 0x5954f0
    void Receive_Preview();                     // 0x5957b0

    HWND Dialog;                                // +0x00
    int Result;                                 // +0x04, 1 = start, 2 = cancel
    bool Changed;                               // +0x08, settings must be saved
    bool SendInfo;                              // +0x09, own settings must be sent
    unsigned long InfoTime;                     // +0x0c
    unsigned long InfoDelay;                    // +0x10 (set to 10000, not read here)
    unsigned long ReceiveTime;                  // +0x14
    unsigned long ReceiveTimeout;               // +0x18
    unsigned long TimingTime;                   // +0x1c
    wchar_t HostName[20];                       // +0x20
    int HostColor;                              // +0x48
    int HostHouse;                              // +0x4c
    int Unknown50;                              // +0x50
    int Unknown54;                              // +0x54
    int Unknown58;                              // +0x58
};

// ---- end of local declarations ----

#define IDD_MODEM_GUEST     0xF2
#define IDC_GUEST_COLOR     0x405
#define IDC_GUEST_CREDITS   0x402
#define IDC_GUEST_SPEED     0x529
#define IDC_GUEST_CRATES    0x54C
#define IDC_GUEST_FOG       0x54D
#define IDC_GUEST_SHORT     0x54E
#define IDC_GUEST_TECH      0x550
#define IDC_GUEST_CRAPENG   0x551
#define IDC_GUEST_AIPLAYERS 0x552
#define IDC_GUEST_AIDIFF    0x553
#define IDC_GUEST_HARVTRUCE 0x596
#define IDC_GUEST_SCENARIO  0x5A8
#define IDC_GUEST_BRIDGES   0x624
#define IDC_GUEST_MESSAGES  0x53F
#define IDC_GUEST_CHAT      0x540
#define IDC_GUEST_NAME      0x5C1
#define IDC_GUEST_HOUSE     0x667
#define IDC_GUEST_HOST      0x668
#define IDC_GUEST_UNITS     0x669
#define IDC_GUEST_BASES     0x66A
#define IDC_GUEST_MCV       0x66B
#define IDC_GUEST_SUPER     0x69A
#define IDC_GUEST_ALLY      0x69D

// Westwood control messages (names provisional).
#define WWM_SET_RANGE       (WM_USER + 0x06)
#define WWM_SET_POS         (WM_USER + 0x05)
#define WWM_SET_ITEM_COLOR  (WM_USER + 0x98)
#define WWM_SET_TEXT_WIDE   (WM_USER + 0xB2)
#define WWM_GET_TEXT_WIDE   (WM_USER + 0xB3)
#define WWM_ADD_STRING      (WM_USER + 0xC1)
#define WWM_ADD_STRING_WIDE (WM_USER + 0xC2)
#define WWN_CHANGED         0x501

#line 100 "C:\\RA2\\ModemGst.cpp"
bool ModemGuestDialogClass::Process()
{
    bool retval = false;

    Debug_Printf("ModemGuest.Dialog(enter)\n");
    Result = -1;
    Dialog = Create_Dialog(IDD_MODEM_GUEST, Dialog_Proc, 0);
    if (Dialog) {
        SetWindowLongA(Dialog, DWL_USER, (LONG)this);
        Init_Dialog();
        Show_Dialog(Dialog);

        Changed = false;
        SendInfo = true;
        InfoTime = TickCount;
        InfoDelay = 10000;
        ReceiveTime = TickCount;
        ReceiveTimeout = 1200;
        TimingTime = 0;
        HostName[0] = 0;
        HostColor = -1;
        HostHouse = -1;
        Unknown50 = Func_649690();
        Func_6497D0();
        Unknown54 = Func_6497B0();
        Unknown58 = Func_6497C0();

        while (Result < 0) {
            if (Dialog_Abort_Check() == true) {
                break;
            }
            Service(false);
            if (Receive() == true) {
                break;
            }
            Call_Back_5168E0(false);
        }
        End_Dialog(Dialog);

        if (Changed == true) {
            Session.Write_MultiPlayer_Settings();
        }
        if (Result == 1) {
            retval = true;
        } else if (Result == 2) {
            retval = false;
            Sign_Off();
        }
    }
    Debug_Printf("ModemGuest.Dialog(exit %s)\n", retval ? "true" : "false");
    return retval;
}

// The cases end with break (not return FALSE): only then does VC6 push ebp after the
// Standard_Dialog_Proc early return, as the original does.
BOOL CALLBACK ModemGuestDialogClass::Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) {
        return result;
    }

    ModemGuestDialogClass * self = (ModemGuestDialogClass *)GetWindowLongA(dialog, DWL_USER);

    switch (message) {
        case WM_DESTROY:
            if (Preview) {
                delete Preview;
                Preview = NULL;
            }
            break;

        case WM_PAINT:
            if (Preview) {
                Preview->Draw(dialog);
            }
            ValidateRect(dialog, NULL);
            break;

        case WM_COMMAND:
            switch (LOWORD(wparam)) {
                case IDOK:
                    if (HIWORD(wparam) == 0) {
                        self->Accept();
                    }
                    break;

                case IDCANCEL:
                    if (HIWORD(wparam) == 0) {
                        self->Read_Dialog();
                        self->Result = 2;
                    }
                    break;

                case IDC_GUEST_COLOR:
                    if (HIWORD(wparam) == CBN_SELCHANGE) {
                        self->Color_Changed();
                    }
                    break;

                case IDC_GUEST_CHAT:
                    if (HIWORD(wparam) == WWN_CHANGED) {
                        self->Chat_Input();
                    }
                    break;

                case IDC_GUEST_NAME:
                    if (HIWORD(wparam) == WWN_CHANGED || HIWORD(wparam) == EN_CHANGE) {
                        self->Name_Changed(HIWORD(wparam) == EN_CHANGE);
                    }
                    break;

                case IDC_GUEST_HOUSE:
                    if (HIWORD(wparam) == CBN_SELCHANGE) {
                        self->House_Changed();
                    }
                    break;
            }
            break;
    }
    return FALSE;
}



#line 270
void ModemGuestDialogClass::Init_Dialog()
{
    wchar_t buffer[1024];
    int index;

    Debug_Printf("ModemGuest.InitDialog(enter)\n");

    HWND item = GetDlgItem(Dialog, IDC_GUEST_NAME);
    if (item) {
        SendMessageA(item, EM_LIMITTEXT, 19, 0);
        SendMessageA(item, WWM_SET_TEXT_WIDE, 0, (LPARAM)To_Wide(Session.Handle));
    }
    Debug_Printf("Name: %ls\n", Session.Handle);

    item = GetDlgItem(Dialog, IDC_GUEST_COLOR);
    if (item) {
        SendMessageA(item, CB_RESETCONTENT, 0, 0);
#line 280
        SendMessageA(item, WWM_ADD_STRING, -1, (LPARAM)Fetch_String("TXT_GOLD", NULL, __FILE__, __LINE__));
        SendMessageA(item, WWM_ADD_STRING, -1, (LPARAM)Fetch_String("TXT_RED", NULL, __FILE__, __LINE__));
        SendMessageA(item, WWM_ADD_STRING, -1, (LPARAM)Fetch_String("TXT_BLUE", NULL, __FILE__, __LINE__));
        SendMessageA(item, WWM_ADD_STRING, -1, (LPARAM)Fetch_String("TXT_GREEN", NULL, __FILE__, __LINE__));
        SendMessageA(item, WWM_ADD_STRING, -1, (LPARAM)Fetch_String("TXT_ORANGE", NULL, __FILE__, __LINE__));
        SendMessageA(item, WWM_ADD_STRING, -1, (LPARAM)Fetch_String("TXT_SKY_BLUE", NULL, __FILE__, __LINE__));
        SendMessageA(item, WWM_ADD_STRING, -1, (LPARAM)Fetch_String("TXT_PURPLE", NULL, __FILE__, __LINE__));
        SendMessageA(item, WWM_ADD_STRING, -1, (LPARAM)Fetch_String("TXT_PINK", NULL, __FILE__, __LINE__));
        for (index = 0; index < 8; index++) {
            SendMessageA(item, WWM_SET_ITEM_COLOR, index, PlayerColorRGB[index]);
        }
        Session.ColorIdx = Session.PrefColor;
        SendMessageA(item, CB_SETCURSEL, Session.ColorIdx, 0);
    }
    Debug_Printf("Color: %d\n", Session.ColorIdx);

    item = GetDlgItem(Dialog, IDC_GUEST_HOUSE);
    if (item) {
        SendMessageA(item, CB_RESETCONTENT, 0, 0);
        for (index = 0; index < HouseTypes.ActiveCount; index++) {
            if (HouseTypes[index]->IsMultiplay) {
                int item_index = SendMessageA(item, WWM_ADD_STRING_WIDE, 0, (LPARAM)HouseTypes[index]->UIName);
                SendMessageA(item, CB_SETITEMDATA, item_index, index);
            }
        }
        index = Find_Item_Data(item, -1, Session.House);
        SendMessageA(item, CB_SETCURSEL, index, 0);
    }

    item = GetDlgItem(Dialog, IDC_GUEST_UNITS);
    if (item) {
        SendMessageA(item, WWM_SET_RANGE, 1, ((unsigned short)Rule->MaxUnitCount << 16) | (unsigned short)Rule->MinUnitCount);
        SendMessageA(item, WWM_SET_POS, 1, Session.UnitCount);
    }
    Debug_Printf("UnitCount: %d\n", Session.UnitCount);

    item = GetDlgItem(Dialog, IDC_GUEST_TECH);
    if (item) {
        SendMessageA(item, WWM_SET_RANGE, 1, MAKELONG(1, 10));
        SendMessageA(item, WWM_SET_POS, 1, BuildLevel);
    }
    Debug_Printf("TechLevel: %d\n", BuildLevel);

    item = GetDlgItem(Dialog, IDC_GUEST_CREDITS);
    if (item) {
        SendMessageA(item, WWM_SET_RANGE, 1, ((unsigned short)Rule->MaxCredits << 16) | (unsigned short)Rule->MinCredits);
        SendMessageA(item, WWM_SET_POS, 1, Session.Credits);
    }
    Debug_Printf("Credits: %d\n", Session.Credits);

    item = GetDlgItem(Dialog, IDC_GUEST_AIPLAYERS);
    if (item) {
        SendMessageA(item, WWM_SET_RANGE, 1, MAKELONG(0, 6));
        SendMessageA(item, WWM_SET_POS, 1, Session.AIPlayers);
    }
    Debug_Printf("AIPlayers: %d\n", Session.AIPlayers);

    item = GetDlgItem(Dialog, IDC_GUEST_SPEED);
    if (item) {
        SendMessageA(item, WWM_SET_RANGE, 1, MAKELONG(0, 6));
        SendMessageA(item, WWM_SET_POS, 1, 6 - Session.GameSpeed);
    }
    Debug_Printf("Game Speed: %d\n", Session.GameSpeed);

    item = GetDlgItem(Dialog, IDC_GUEST_AIDIFF);
    if (item) {
        SendMessageA(item, WWM_SET_RANGE, 1, MAKELONG(0, 2));
        SendMessageA(item, WWM_SET_POS, 1, Session.AIDifficulty);
    }
    Debug_Printf("AIDifficulty: %d\n", Session.AIDifficulty);

    item = GetDlgItem(Dialog, IDC_GUEST_MCV);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsMCVRedeploy == true, 0);
    }
    Debug_Printf("MCVRedeploy: %s\n", (Session.IsMCVRedeploy == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_GUEST_BASES);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsBases == true, 0);
    }
    Debug_Printf("Bases: %s\n", (Session.IsBases == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_GUEST_SHORT);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsShortGame == true, 0);
    }
    Debug_Printf("Short Game: %s\n", (Session.IsShortGame == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_GUEST_SUPER);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsSuperWeapons == true, 0);
    }
    Debug_Printf("SuperWeapons: %s\n", (Session.IsSuperWeapons == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_GUEST_ALLY);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsBuildOffAlly == true, 0);
    }
    Debug_Printf("BuildOffAlly: %s\n", (Session.IsBuildOffAlly == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_GUEST_CRAPENG);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsCrapEngineers == true, 0);
    }
    Debug_Printf("Crap Engineers: %s\n", (Session.IsCrapEngineers == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_GUEST_CRATES);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsCrates == true, 0);
    }
    Debug_Printf("Crates: %s\n", (Session.IsCrates == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_GUEST_FOG);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsFogOfWar == true, 0);
    }
    Debug_Printf("FogOfWar: %s\n", (Session.IsFogOfWar == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_GUEST_BRIDGES);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsBridgeDestruction == true, 0);
    }
    Debug_Printf("BridgeDestroy: %s\n", (Session.IsBridgeDestruction == true) ? "ON" : "OFF");

    item = GetDlgItem(Dialog, IDC_GUEST_HARVTRUCE);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsHarvesterTruce == true, 0);
    }
    Debug_Printf("Harvester Truce: %s\n", (Session.IsHarvesterTruce == true) ? "ON" : "OFF");

    VerNum.Init_Clipping();

    if (Preview) {
        delete Preview;
        Preview = NULL;
    }

    if (strlen(PendingMessage) > 0x4E) {
        PendingMessage[0x4F] = 0;
    }
    if (strlen(PendingMessage)) {
        Narrow_To_Wide(buffer, PendingMessage, -1);
        Display_Message(buffer, -1, NullWString);
    }
    PendingMessage[0] = 0;
    NullModem.Func_5C8F90(1);
    Session.Flag2374 = true;
    Delete_All(Session.Players);
    Session.ScenarioName[0] = 0;
    Debug_Printf("ModemGuest.InitDialog(exit)\n");
}

void ModemGuestDialogClass::Read_Dialog()
{
    wchar_t name[20];

    Debug_Printf("ModemGuest.ReadDialog(enter)\n");

    HWND item = GetDlgItem(Dialog, IDC_GUEST_NAME);
    if (item) {
        SendMessageA(item, WWM_GET_TEXT_WIDE, 20, (LPARAM)name);
        Wide_To_Narrow(Session.Handle, name, -1);
    }
    Debug_Printf("Name: %s\n", Session.Handle);

    item = GetDlgItem(Dialog, IDC_GUEST_COLOR);
    if (item) {
        Session.ColorIdx = SendMessageA(item, CB_GETCURSEL, 0, 0);
    }
    Debug_Printf("Color: %d\n", Session.ColorIdx);

    item = GetDlgItem(Dialog, IDC_GUEST_HOUSE);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        Session.House = SendMessageA(item, CB_GETITEMDATA, index, 0);
    }
    Debug_Printf("ModemGuest.ReadDialog(exit)\n");
}

void ModemGuestDialogClass::Chat_Input()
{
    wchar_t text[256];

    HWND item = GetDlgItem(Dialog, IDC_GUEST_CHAT);
    if (item) {
        SendMessageA(item, WWM_GET_TEXT_WIDE, 256, (LPARAM)text);
        SendMessageA(item, WWM_SET_TEXT_WIDE, 0, (LPARAM)NullWString);
        if (wcslen(text) && text[0] != VK_RETURN) {
            Wcstrim(text);
            Send_Message(text);
        }
    }
}

void ModemGuestDialogClass::House_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_GUEST_HOUSE);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        if (index != -1) {
            Session.House = SendMessageA(item, CB_GETITEMDATA, index, 0);
            SendInfo = true;
            Changed = true;
        }
    }
}

// The original never inlines this function (Dialog_Proc, Set_Host), although -Ob2 would; the
// cause is unknown. auto_inline(off) reproduces the original code (as in PhoneEd.cpp).
#pragma auto_inline(off)
void ModemGuestDialogClass::Color_Changed()
{
    HWND item = GetDlgItem(Dialog, IDC_GUEST_COLOR);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        if (index != -1) {
            if (index == HostColor) {
                index = HostColor + 1;
                if (index > 7) {
                    index = 0;
                }
                SendMessageA(item, CB_SETCURSEL, index, 0);
            }
            Session.ColorIdx = index;
            SendInfo = true;
            Changed = true;
            SendMessageA(item, WWM_SET_ITEM_COLOR, 0, Color_RGB(index));
        }
    }
}

#pragma auto_inline(on)

void ModemGuestDialogClass::Name_Changed(bool typing)
{
    wchar_t name[21];

    HWND item = GetDlgItem(Dialog, IDC_GUEST_NAME);
    if (item) {
        SendMessageA(item, WWM_GET_TEXT_WIDE, 21, (LPARAM)name);
        Wcstrim(name);
        if (!typing) {
            SendMessageA(item, WWM_SET_TEXT_WIDE, 0, (LPARAM)name);
        }
        Wide_To_Narrow(Session.Handle, name, -1);
        SendInfo = true;
        Changed = true;
    }
}

void ModemGuestDialogClass::Set_Host(wchar_t const * name, int color, int house)
{
    wchar_t buffer[80];

    wcscpy(HostName, name);
    HostColor = color;

    HWND item = GetDlgItem(Dialog, IDC_GUEST_COLOR);
    if (item) {
        int index = SendMessageA(item, CB_GETCURSEL, 0, 0);
        if (index != -1 && index == HostColor) {
            Color_Changed();
        }
    }

    HostHouse = house;
    item = GetDlgItem(Dialog, IDC_GUEST_HOST);
    if (item) {
        swprintf(buffer, L"%s [%s]", name, HouseTypes[house]->UIName);
        SendMessageA(item, WWM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
        SendMessageA(item, WWM_SET_ITEM_COLOR, 0, Color_RGB(color));
    }
}

void ModemGuestDialogClass::Show_Options()
{
    Debug_Printf("Settings change\n");

    HWND item = GetDlgItem(Dialog, IDC_GUEST_UNITS);
    if (item) {
        SendMessageA(item, WWM_SET_POS, 1, Session.UnitCount);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_TECH);
    if (item) {
        SendMessageA(item, WWM_SET_POS, 1, BuildLevel);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_CREDITS);
    if (item) {
        SendMessageA(item, WWM_SET_POS, 1, Session.Credits);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_AIPLAYERS);
    if (item) {
        SendMessageA(item, WWM_SET_POS, 1, Session.AIPlayers);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_SPEED);
    if (item) {
        SendMessageA(item, WWM_SET_POS, 1, 6 - Session.GameSpeed);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_AIDIFF);
    if (item) {
        SendMessageA(item, WWM_SET_POS, 1, Session.AIDifficulty);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_MCV);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsMCVRedeploy == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_BASES);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsBases == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_CRAPENG);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsCrapEngineers == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_SHORT);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsShortGame == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_SUPER);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsSuperWeapons == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_ALLY);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsBuildOffAlly == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_CRATES);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsCrates == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_FOG);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsFogOfWar == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_BRIDGES);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsBridgeDestruction == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_HARVTRUCE);
    if (item) {
        SendMessageA(item, BM_SETCHECK, Session.IsHarvesterTruce == true, 0);
    }
    item = GetDlgItem(Dialog, IDC_GUEST_SCENARIO);
    if (item) {
        SendMessageA(item, WWM_SET_TEXT_WIDE, 0, (LPARAM)Session.ScenarioName);
    }

    if (!Preview || !Preview->Data) {
        Update_Preview(Dialog);
    }

    item = GetDlgItem(Dialog, IDOK);
    if (item) {
        EnableWindow(item, TRUE);
    }
    Play_Sound(Rule->OptionsChanged, 1.0f, 0x2000, 0);
}

void ModemGuestDialogClass::Accept()
{
    SerialPacketType packet;

    HWND item = GetDlgItem(Dialog, IDOK);
    if (item) {
        EnableWindow(item, FALSE);
    }
    memset(&packet, 0, sizeof(packet));
    packet.Command = SERIAL_ACCEPT;
    NullModem.Send_Message(&packet, sizeof(packet), 1);
}

void ModemGuestDialogClass::Service(bool force)
{
    SerialPacketType packet;

    NullModem.Service();

    if ((SendInfo == true && (unsigned long)TickCount - InfoTime > 30) || force == true) {
        Send_Info();
        InfoTime = TickCount;
        SendInfo = false;
    }

    if ((unsigned long)TickCount - TimingTime > 40) {
        memset(&packet, 0, sizeof(packet));
        packet.Command = SERIAL_TIMING;
        packet.Info.ResponseTime = NullModem.Response_Time();
        packet.ID = Session.ModemGameToPlay;
        NullModem.Send_Message(&packet, sizeof(packet), 0);
        TimingTime = TickCount;
    }
}

#line 1150
bool ModemGuestDialogClass::Receive()
{
    SerialPacketType packet;
    SerialPacketType sendpacket;
    int packetlen;
    unsigned long starttime;

    NullModem.Service();
    if (NullModem.Get_Message(&packet, &packetlen) > 0) {
        ReceiveTime = TickCount;
        ReceiveTimeout = 1200;

        if (packet.Command >= 0x64 && packet.Command < SERIAL_LAST_COMMAND && packet.Command != SERIAL_MESSAGE
            && packet.ID == Session.ModemGameToPlay) {
            Debug_Printf("Received own packet back\n");
#line 1177
            WWMessageBox().Process(Fetch_String("TXT_SYSTEM_NOT_RESPONDING", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            return true;
        }

        switch (packet.Command) {
            case SERIAL_SIGN_OFF:
                Debug_Printf("Received SignOff\n");
                starttime = TickCount;
                while ((unsigned long)TickCount - starttime < 60) {
                    Call_Back();
                    NullModem.Service();
                }
#line 1193
                WWMessageBox().Process(Fetch_String("TXT_USER_SIGNED_OFF", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                ReceiveTime = TickCount;
                Shutdown_Modem();
                return true;

            case SERIAL_GAME_OPTIONS:
            {
                Debug_Printf("Received game options\n");
                int version = VerNum.Clip_Version(packet.Info.MinVersion, packet.Info.MaxVersion);
                if (version == 0) {
#line 1209
                    WWMessageBox().Process(Fetch_String("TXT_DESTGAME_OUTDATED", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    ReceiveTime = TickCount;
                    return true;
                }
                if (version == -1) {
#line 1215
                    WWMessageBox().Process(Fetch_String("TXT_YOURGAME_OUTDATED", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    ReceiveTime = TickCount;
                    return true;
                }

                bool match = true;
                if (packet.Info.Unknown86 != Unknown50) {
                    match = false;
                }
                if (packet.Info.UnknownD0 != Unknown58) {
                    match = false;
                }
                if (packet.Info.UnknownD4 != Unknown54) {
                    match = false;
                }
                if (!match) {
#line 1262
                    WWMessageBox().Process(Fetch_String("TXT_MISMATCH", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    ReceiveTime = TickCount;
                    return true;
                }

                Session.CommProtocol = VerNum.Version_Protocol(version);
                Set_Host(To_Wide(packet.Name), packet.Info.Color, packet.Info.House);
                if (Decode_Options(&packet) == true) {
                    Show_Options();
                }
                break;
            }

            case SERIAL_GO:
            case SERIAL_LOAD_GAME:
                Debug_Printf("Received go\n");
                if (Is_Scenario_Available(Session.ScenarioFile, Session.ScenarioCRC, Session.ScenarioDesc, Session.IsRandomScenario, 1) == true) {
                    memset(&sendpacket, 0, sizeof(sendpacket));
                    sendpacket.Command = SERIAL_READY_TO_GO;
                    NullModem.Send_Message(&sendpacket, sizeof(sendpacket), 1);
                } else if (Session.IsRandomScenario && _stricmp(Session.ScenarioFile, "RandMap.Sed")) {
                    memset(&sendpacket, 0, sizeof(sendpacket));
                    sendpacket.Command = SERIAL_NO_SCENARIO;
                    NullModem.Send_Message(&sendpacket, sizeof(sendpacket), 1);
                    Call_Back();
                    NullModem.Service();
#line 1308
                    WWMessageBox().Process(Fetch_String("TXT_UNABLE_PLAY_WAAUGH", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
                    ReceiveTime = TickCount;
                    return true;
                } else {
                    if (!Get_File_From_Host(Session.ScenarioFile, 1, 0)) {
                        return true;
                    }
                    ReceiveTime = TickCount;
                }

                strcpy(Scen->ScenarioName, Session.ScenarioFile);
                Session.FrameSendRate = 5;
                Session.Latency = 0;
                Session.Unknown2E4 = 0;
                Session.Unknown2E8 = 0;
                if (Session.CommProtocol == 2) {
                    unsigned maxahead = ((packet.Info.ResponseTime / 8) + 4) / 5 * 5;
                    Session.MaxAhead = (maxahead > 10) ? maxahead : 10;
                } else {
                    Session.MaxAhead = packet.Info.ResponseTime / 8;
                    if (Session.MaxAhead <= Session.FrameSendRate) {
                        Session.MaxAhead = Session.FrameSendRate;
                    }
                }

                if (Start_Game(packet.Command == SERIAL_LOAD_GAME) == true) {
                    Result = 1;
                } else {
                    Result = 2;
                }
                break;

            case SERIAL_MESSAGE:
                Debug_Printf("Received serial message\n");
                Display_Message(To_Wide(packet.Name), packet.ID, packet.Message);
                Play_Sound(Rule->IncomingMessage, 1.0f, 0x2000, 0);
                break;

            case SERIAL_TIMING:
                Debug_Printf("Received timing packet\n");
                break;

            case SERIAL_SCORE_SCREEN:
                Debug_Printf("Received score screen packet\n");
                SendInfo = true;
                InfoTime = TickCount;
                break;

            case SERIAL_PREVIEW_MODE:
                Debug_Printf("Received SERIAL_PREVIEW_MODE packet\n");
                Receive_Preview();
                ReceiveTime = TickCount;
                break;

            default:
                Debug_Printf("Received packet\n");
                break;
        }
    }

    unsigned long elapsed = (unsigned long)TickCount - ReceiveTime;
    if (elapsed > ReceiveTimeout) {
        Debug_Printf("Timeout! %d ticks since last incoming message\n", elapsed);
#line 1391
        WWMessageBox().Process(Fetch_String("TXT_SYSTEM_NOT_RESPONDING", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
        return true;
    }
    return false;
}

bool ModemGuestDialogClass::Decode_Options(SerialPacketType * packet)
{
    if (Session.IsBases == (bool)packet->Info.IsBases
        && Session.IsMCVRedeploy == (bool)packet->Info.IsMCVRedeploy
        && Session.IsHarvesterTruce == (bool)packet->Info.IsHarvesterTruce
        && Session.IsBridgeDestruction == (bool)packet->Info.IsBridgeDestruction
        && Session.IsCrates == (bool)packet->Info.IsCrates
        && Session.IsFogOfWar == (bool)packet->Info.IsFogOfWar
        && Session.AIPlayers == packet->Info.AIPlayers
        && Session.AIDifficulty == packet->Info.AIDifficulty
        && BuildLevel == packet->Info.BuildLevel
        && Session.Credits == packet->Info.Credits
        && Session.UnitCount == packet->Info.UnitCount
        && Seed == packet->Info.Seed
        && Special.Is_Equal(&packet->Info.Special)
        && Session.GameSpeed == packet->Info.GameSpeed
        && Session.IsShortGame == (bool)packet->Info.IsShortGame
        && Session.IsSuperWeapons == (bool)packet->Info.IsSuperWeapons
        && Session.IsBuildOffAlly == (bool)packet->Info.IsBuildOffAlly
        && Session.IsCrapEngineers == (bool)packet->Info.IsCrapEngineers
        && !_stricmp(Session.ScenarioFile, packet->Info.ScenarioFile)
        && !strcmp(Session.ScenarioDesc, packet->Info.ScenarioDesc)
        && Session.ScenarioCRC == packet->Info.ScenarioCRC) {
        return false;
    }

    Debug_Printf("Decoding game options\n");
    Session.IsBases = packet->Info.IsBases;
    Session.IsMCVRedeploy = packet->Info.IsMCVRedeploy;
    Session.IsBridgeDestruction = packet->Info.IsBridgeDestruction;
    Special.IsBridgeDestruction = packet->Info.IsBridgeDestruction;
    Session.IsCrates = packet->Info.IsCrates;
    Session.IsFogOfWar = packet->Info.IsFogOfWar;
    Session.IsHarvesterTruce = packet->Info.IsHarvesterTruce;
    Session.AIPlayers = packet->Info.AIPlayers;
    Session.AIDifficulty = packet->Info.AIDifficulty;
    BuildLevel = packet->Info.BuildLevel;
    Session.Credits = packet->Info.Credits;
    Session.UnitCount = packet->Info.UnitCount;
    Seed = packet->Info.Seed;
    Special = packet->Info.Special;
    Options.GameSpeed = Session.GameSpeed = packet->Info.GameSpeed;
    Session.IsShortGame = packet->Info.IsShortGame;
    Session.IsSuperWeapons = packet->Info.IsSuperWeapons;
    Session.IsBuildOffAlly = packet->Info.IsBuildOffAlly;
    Session.IsCrapEngineers = packet->Info.IsCrapEngineers;
    Special.IsBit6 = true;
    Special.IsBit7 = true;
    Scen->Flags &= ~0x400;
    Session.UnknownA4 = true;
    Special.Update();

    if (_stricmp(Session.ScenarioFile, packet->Info.ScenarioFile)
        || _stricmp(Session.ScenarioDesc, packet->Info.ScenarioDesc)
        || Session.IsRandomScenario != (bool)packet->Info.IsRandom
        || Session.ScenarioCRC != packet->Info.ScenarioCRC
        || Session.ScenarioName[0] == 0) {
        Debug_Printf("Scenario has changed\n");
        strcpy(Session.ScenarioFile, packet->Info.ScenarioFile);
        strcpy(Session.ScenarioDesc, packet->Info.ScenarioDesc);
        Session.IsRandomScenario = packet->Info.IsRandom;
        Session.ScenarioCRC = packet->Info.ScenarioCRC;

        bool found = false;
        if (strcmp(Session.ScenarioFile, "RandMap.Sed") || !Session.IsRandomScenario) {
            for (int index = 0; index < Session.Scenarios.ActiveCount; index++) {
                ScenarioDescType * scen = Session.Scenarios[index];
                if (!_stricmp(Session.ScenarioFile, scen->Filename)) {
                    wcscpy(Session.ScenarioName, scen->Description);
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            wcscpy(Session.ScenarioName, packet->Info.ScenarioName);
        }


        if (Preview) {
            delete Preview;
            Preview = NULL;
        }
    }
    return true;
}

void ModemGuestDialogClass::Send_Info()
{
    SerialPacketType packet;

    memset(&packet, 0, sizeof(packet));
    packet.Command = SERIAL_GAME_OPTIONS;
    packet.Info.Unknown86 = Unknown50;
    packet.Info.UnknownD4 = Unknown54;
    packet.Info.UnknownD0 = Unknown58;
    packet.Info.UnknownD8 = Func_72C6B0();
    packet.Info.MinVersion = VerNum.Min_Version();
    packet.Info.MaxVersion = VerNum.Max_Version();
    packet.ID = Session.ModemGameToPlay;
    strcpy(packet.Name, Session.Handle);
    packet.Info.House = Session.House;
    packet.Info.Color = Session.ColorIdx;
    NullModem.Send_Message(&packet, sizeof(packet), 1);
}

// Dialog_Proc inlines Chat_Input and this function but calls Display_Message (inline level three),
// while Chat_Input, Init_Dialog and Receive inline Display_Message. VC6 applies the inline depth in
// effect where the inlined function is defined; a depth of two here reproduces the original.
#pragma inline_depth(2)
void ModemGuestDialogClass::Send_Message(wchar_t const * text)
{
    SerialPacketType packet;

    if (text) {
        memset(&packet, 0, sizeof(packet));
        packet.Command = SERIAL_MESSAGE;
        strcpy(packet.Name, Session.Handle);
        packet.ID = Session.ColorIdx;
        wcscpy(packet.Message, text);
        NullModem.Send_Message(&packet, sizeof(packet), 1);
        NullModem.Service();
        Display_Message(To_Wide(Session.Handle), Session.ColorIdx, text);
    }
}

#pragma inline_depth()
void ModemGuestDialogClass::Display_Message(wchar_t const * name, int color, wchar_t const * text)
{
    wchar_t buffer[256];

    if (text) {
        HWND item = GetDlgItem(Dialog, IDC_GUEST_MESSAGES);
        if (item) {
            int rgb = Color_RGB(color);
            swprintf(buffer, L"[%s] %s", name, text);
            Add_Chat_Text(rgb, buffer, item);
        }
    }
}

#line 1680
void ModemGuestDialogClass::Sign_Off()
{
    int packetlen;
    SerialPacketType packet;
    SerialPacketType receivepacket;

    memset(&packet, 0, sizeof(packet));
    packet.Command = SERIAL_SIGN_OFF;
    packet.Info.Color = Session.ColorIdx;
    packet.ID = Session.ModemGameToPlay;
    NullModem.Send_Message(&packet, sizeof(packet), 1);

#line 1683
    HWND dialog = Create_Cancel_Dialog(Fetch_String("TXT_SIGNING_OFF", NULL, __FILE__, __LINE__), NULL, NULL);
    if (dialog) {
        Show_Dialog(dialog);
    }

    unsigned long starttime = TickCount;
    while (NullModem.Num_Send() && (unsigned long)TickCount - starttime < 300) {
        if (NullModem.Get_Message(&receivepacket, &packetlen) > 0 && receivepacket.Command == SERIAL_SIGN_OFF
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

#line 1770
bool ModemGuestDialogClass::Start_Game(bool load)
{
    if (load == true) {
        return false;
    }

    Read_Dialog();
    Session.NumPlayers = 0;

    NodeNameType * who = new NodeNameType;
    if (who) {
        Narrow_To_Wide(who->Name, Session.Handle, -1);
        who->House = Session.House;
        who->Color = Session.ColorIdx;
        who->Unknown61 = -1;
        Session.Players.Add(who);
        Session.NumPlayers++;
    }

    who = new NodeNameType;
    if (who) {
        wcscpy(who->Name, HostName);
        who->House = HostHouse;
        who->Color = HostColor;
        who->Unknown61 = -1;
        Session.Players.Add(who);
        Session.NumPlayers++;
    }

    if (Session.NumPlayers != 2) {
        return false;
    }

#line 1779
    HWND dialog = Create_Cancel_Dialog(Fetch_String("TXT_SENDING_GO_ACK", NULL, __FILE__, __LINE__), NULL, NULL);
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
        End_Dialog(dialog);
    }

    NullModem.Reset_Response_Time();
    Session.Flag2374 = false;
    Scen->Unknown834 = Session.Unknown1C;
    Session.NumPlayers = Session.Players.ActiveCount;
    Special.IsHarvesterTruce = Session.IsHarvesterTruce;
    Special.IsBridgeDestruction = Session.IsBridgeDestruction;
    NetworkEventMode = 0;
    Session.CommProtocol = 2;
    Special.IsBit6 = true;
    Special.IsBit7 = true;
    Special.Update();
    return true;
}

void ModemGuestDialogClass::Receive_Preview()
{
    CDTimerClass<SystemTimerClass> timer;
    SerialPacketType packet;
    char filename[256];

    Debug_Printf("Starting map preview download\n");
    memset(&packet, 0, sizeof(packet));
    packet.Command = SERIAL_PREVIEW_ACK;
    Debug_Printf("Sending preview mode ack\n");
    NullModem.Send_Message(&packet, sizeof(packet), 1);

    timer = 600;
    while (NullModem.Num_Send() > 0 && timer) {
        Call_Back();
    }
    Debug_Printf("Preview mode ack sent\n");

    Debug_Printf("Calling Get_File_From_Host to receive the file download\n");
    if (!Get_File_From_Host(filename, 1, 0)) {
        Debug_Printf("got_file is false. Download failed\n");
        return;
    }

    Debug_Printf("Loading the compressed preview image\n");
    RawFileClass file(filename);
    int size = file.Size();
    char * buffer = new char[size];
    file.Read(buffer, size);
    int length = *(int *)buffer;

    Debug_Printf("Decompressing the preview image\n");
    BufferStraw bstraw(buffer + 4, size);
    LZOStraw lzo(LZOStraw::DECOMPRESS, 0x2000);
    lzo.Get_From(&bstraw);
    char * image = new char[length * 2];
    lzo.Get(image, length);

    Debug_Printf("Creating the new preview surface\n");
    if (Preview) {
        delete Preview;
    }
    Preview = new PreviewClass;
    Preview->Set_Image(image);
    InvalidateRect(Dialog, NULL, FALSE);

    Debug_Printf("Cleaning up the temporary decompression buffers\n");
    delete [] image;
    delete [] buffer;
}
