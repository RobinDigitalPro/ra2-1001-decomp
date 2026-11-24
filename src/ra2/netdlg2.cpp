// C:\RA2\netdlg2.cpp (level-2 reconstruction of GAME.EXE 1.001)
// LAN network game dialogs: the game lobby, the host and join dialogs, and the lobby/chat
// message handling. Class names come from RTTI where a vtable exists; all other class,
// method and variable names are provisional (Westwood style).
#include "GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <commctrl.h>
#include <stdlib.h>

// ---- local declarations (to be moved to headers by the integrator) ----

// Copy of VECTOR.H with Add/Delete returning bool (the out-of-line instance 0x5bd500 returns al).
template<class T> class VectorClass {
public:
    virtual ~VectorClass() { VectorClass<T>::Clear(); }
    virtual bool operator == (VectorClass<T> const & vector) const;
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr);
    virtual int ID(T const & object);
    virtual T Fetch(int index) const { return Vector[index]; }

    T & operator[](unsigned index) { return Vector[index]; }
    int Length() const { return VectorMax; }

    T * Vector;
    int VectorMax;
    bool IsInitialized;
    bool IsAllocated;
};

template<class T> bool VectorClass<T>::operator == (VectorClass<T> const & vector) const
{
    if (VectorMax == vector.VectorMax) {
        for (int index = 0; index < VectorMax; index++) {
            if (Vector[index] != vector.Vector[index]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

template<class T> bool VectorClass<T>::Resize(int newsize, T const * array)
{
    if (newsize) {
        T * newptr;
        IsInitialized = false;
        if (!array) {
            newptr = new T[newsize];
        } else {
            newptr = (T *)array;
        }
        IsInitialized = true;
        if (!newptr) {
            return false;
        }
        if (Vector != NULL) {
            int copycount = (newsize < VectorMax) ? newsize : VectorMax;
            for (int index = 0; index < copycount; index++) {
                newptr[index] = Vector[index];
            }
            if (IsAllocated) {
                delete [] Vector;
                Vector = 0;
            }
        }
        Vector = newptr;
        VectorMax = newsize;
        IsAllocated = (Vector && !array);
    } else {
        Clear();
    }
    return true;
}

template<class T> void VectorClass<T>::Clear(void)
{
    if (Vector && IsAllocated) {
        delete [] Vector;
        Vector = 0;
    }
    IsAllocated = false;
    VectorMax = 0;
}

template<class T> int VectorClass<T>::ID(T const * ptr)
{
    if (!IsInitialized) {
        return 0;
    }
    return ((unsigned long)ptr - (unsigned long)Vector) / sizeof(T);
}

template<class T> int VectorClass<T>::ID(T const & object)
{
    if (!IsInitialized) {
        return 0;
    }
    for (int index = 0; index < VectorMax; index++) {
        if (Vector[index] == object) {
            return index;
        }
    }
    return -1;
}

template<class T> class DynamicVectorClass : public VectorClass<T> {
public:
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr) { return VectorClass<T>::ID(ptr); }
    virtual int ID(T const & object);

    bool Add(T const & object);
    bool Delete(T const & object);
    bool Delete(int index);

    int ActiveCount;
    int GrowthStep;
};

template<class T> bool DynamicVectorClass<T>::Resize(int newsize, T const * array)
{
    if (VectorClass<T>::Resize(newsize, array)) {
        if (Length() < ActiveCount) {
            ActiveCount = Length();
        }
        return true;
    }
    return false;
}

template<class T> void DynamicVectorClass<T>::Clear(void)
{
    ActiveCount = 0;
    VectorClass<T>::Clear();
}

template<class T> int DynamicVectorClass<T>::ID(T const & object)
{
    for (int index = 0; index < ActiveCount; index++) {
        if ((*this)[index] == object) {
            return index;
        }
    }
    return -1;
}

template<class T> inline bool DynamicVectorClass<T>::Add(T const & object)
{
    if (ActiveCount >= Length()) {
        if ((IsAllocated || !VectorMax) && GrowthStep > 0) {
            if (!Resize(Length() + GrowthStep)) {
                return false;
            }
        } else {
            return false;
        }
    }
    (*this)[ActiveCount++] = object;
    return true;
}

template<class T> inline bool DynamicVectorClass<T>::Delete(T const & object)
{
    int index = ID(object);
    if (index != -1) {
        return Delete(index);
    }
    return false;
}

template<class T> inline bool DynamicVectorClass<T>::Delete(int index)
{
    if (index < ActiveCount) {
        ActiveCount--;
        for (int i = index; i < ActiveCount; i++) {
            (*this)[i] = (*this)[i+1];
        }
        return true;
    }
    return false;
}


wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
wchar_t * To_Wide(char const * string);         // 0x6eee20, rotating buffers (name provisional)
char * To_Narrow(wchar_t const * string);       // 0x6eedc0, rotating buffers (name provisional)
void Call_Back();                             // 0x4821e0 (provisional; see CampScor.cpp)

// Dialog stack (pairs of window and resource id at 0xb0d630; names provisional).
HWND Find_Dialog(int id);                       // 0x72a500, NULL when not open
HWND Previous_Dialog(HWND dialog);              // 0x72a570, the dialog below on the stack
HWND Current_Dialog();                          // 0x72a6d0
int Current_Dialog_ID();                        // 0x72a6e0
int Dialog_ID(HWND dialog);                     // 0x5e2de0

enum {
    DLG_LAN_LOBBY = 0xbb,                       // resource ids (provisional names)
    DLG_LAN_HOST = 0xbc,
    DLG_LAN_JOIN = 0xbd
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

// Count-down timer (as in NullDlg.CPP). The function-local statics register empty atexit
// destructors (0x5bb270..0x5bb290), so this copy has an explicit empty destructor.
template<class T>
class CDTimerClass {
public:
    CDTimerClass(long set = 0) : Started(Timer()), DelayTime(set) {}
    ~CDTimerClass() {}
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

typedef unsigned char NetNumType[4];
typedef unsigned char NetNodeType[6];

#pragma pack(push, 1)
// IPX network/node address, 10 bytes (see NetDlg.CPP).
class IPXAddressClass {
public:
    IPXAddressClass();                          // 0x522950
    void Get_Address(NetNumType net, NetNodeType node);    // 0x522a60
    int Is_Broadcast();                         // 0x522aa0, all ten bytes 0xff
private:
    NetNumType NetworkNumber;
    NetNodeType NodeAddress;
};

// Entry of the session lists (games, lobby users, players). The union layout follows the
// field accesses; names are provisional.
struct NodeNameType {
    wchar_t Name[20];                           // +0x00
    IPXAddressClass Address;                    // +0x28
    union {
        struct {
            bool IsOpen;                        // +0x32
            unsigned long LastTime;             // +0x33
        } Game;
        struct {
            unsigned long LastTime;             // +0x32
            bool LastChance;                    // +0x36
            int Value;                          // +0x37 (meaning unknown)
        } Chat;
    };
    char Unknown3B[0x71 - 0x3B];
};

// Global (session) packet, 0x1c7 bytes. Only the fields used here.
struct GlobalPacketType {
    int Command;                                // +0x00
    char Name[0x14];                            // +0x04 narrow player or game name
    char Name2[0x17];                           // +0x18 (meaning provisional)
    union {
        int ID;                                 // +0x2f
        wchar_t Text[1];                        // +0x2f
        struct {
            unsigned IsOpen:1;                  // +0x2f
        } GameInfo;
        struct {
            unsigned char Recipients;           // +0x2f
            wchar_t Text[0x70];                 // +0x30
            int ID;                             // +0x110
            unsigned long NameCRC;              // +0x114
        } Message;
        struct {
            int Value1;                         // +0x2f
            int Value2;                         // +0x33
            unsigned long NameCRC;              // +0x37
            char Unknown3B[0x53 - 0x3B];
            int Value3;                         // +0x53
        } PlayerInfo;
    };
    unsigned char Unknown[0x1C7 - 0x118];
};
#pragma pack(pop)

enum NetCommandType {                           // provisional names
    NET_QUERY_GAME = 0,
    NET_ANSWER_GAME = 1,
    NET_QUERY_PLAYER = 2,
    NET_ANSWER_PLAYER = 3,
    NET_CHAT_QUERY = 4,
    NET_SIGN_OFF = 10,
    NET_MESSAGE = 12,
    NET_READY_TO_GO = 19,
    NET_PING = 5,
    NET_REJECT_JOIN = 8,
    NET_CHAT_ANNOUNCE = 22
};

// RTTI .?AVIPXManagerClass@@ (vtable 0x78f6d4); only the non-virtual methods used here.
class IPXManagerClass {
public:
    int Init();                                 // 0x523fb0
    void Set_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout, bool flag);   // 0x524160 (names provisional)
    void Set_Timing_524210(unsigned long a, unsigned long b, unsigned long c);   // 0x524210 (meaning unknown)
    int Service();                              // 0x524890
    int Global_Num_Send();                      // 0x524ce0
    unsigned long Global_Response_Time();       // 0x524ed0 (name provisional)
    int Send_Global_Message(void * buf, int buflen, int ack_req, IPXAddressClass * address);   // 0x524560
    void Set_Bridge(NetNumType bridge);         // 0x5259d0
};
extern IPXManagerClass Ipx;                     // 0xa285c8

// RTTI .?AVWinsockInterfaceClass@@ (vtable 0x79a8b4); slot 0 is the deleting destructor.
class WinsockInterfaceClass {
public:
    virtual ~WinsockInterfaceClass();
};
extern WinsockInterfaceClass * PacketTransport; // 0x821f90

// Multiplayer player list entry (see LdPrgMgr.cpp); only the fields used here.
#pragma pack(push, 1)
class MPPlayerNode {
public:
    int Side() const;                           // 0x664e80: SideIndex unless SidePref is -2
    int Color() const;                          // 0x664e90: ColorIndex unless ColorPref is -2
    void Set_Side(int side);                    // 0x664ec0
    void Set_Color(int color);                  // 0x664ef0

    wchar_t Name[20];                           // +0x00
    IPXAddressClass Address;                    // +0x28
    char Unknown32[0x49 - 0x32];
    int SideIndex;                              // +0x49
    int SidePref;                               // +0x4d
    int ColorIndex;                             // +0x51
    int ColorPref;                              // +0x55
    char Unknown59[0x65 - 0x59];
    int AcceptState;                            // +0x65 (meaning provisional)
};
#pragma pack(pop)

enum { GAME_INTERNET = 4 };

// Session object at 0xa255c8 (class name provisional); only the members used here, at their
// binary offsets (names from ModemHst.cpp where known).
class SessionClass {
public:
    bool Func_6683F0();                         // 0x6683f0 (meaning unknown)
    int Func_668C60();                          // 0x668c60 (meaning unknown)
    int Func_668C80();                          // 0x668c80 (meaning unknown)

    int Type;                                   // +0x0000 (0xa255c8)
    char Unknown0004[0x0018 - 0x0004];
    int Field018;                               // +0x0018 (0xa255e0, meaning unknown)
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
    char Unknown0034[0x0038 - 0x0034];
    int UnitCount;                              // +0x0038 (0xa25600)
    int AIPlayers;                              // +0x003c (0xa25604)
    char Unknown0040[0x0044 - 0x0040];
    int SlotA[8];                               // +0x0044 (0xa2560c, meaning unknown)
    int SlotB[8];                               // +0x0064 (0xa2562c, meaning unknown)
    int SlotC[8];                               // +0x0084 (0xa2564c, meaning unknown)
    char Unknown00A4[0x00A8 - 0x00A4];
    bool MCVRedeploy;                           // +0x00a8 (0xa25670)
    char Unknown00A9[0x00AA - 0x00A9];
    wchar_t ScenarioName[0x2D];                 // +0x00aa (0xa25672)
    int Field104;                               // +0x0104 (0xa256cc, meaning unknown)
    char Handle[0x14];                          // +0x0108 (0xa256d0)
    int UniqueID;                               // +0x011c (0xa256e4, see NullDlg.CPP)
    int Field120;                               // +0x0120 (0xa256e8, meaning unknown)
    char Unknown0124[0x012C - 0x0124];
    int Color;                                  // +0x012c (0xa256f4)
    int ColorPref;                              // +0x0130 (0xa256f8, -2 = random)
    char Unknown0134[0x01B8 - 0x0134];
    char Field1B8[0x0658 - 0x01B8];             // +0x01b8 (0xa25780, passed by address; meaning unknown)
    char ScenarioFile[0x104];                   // +0x0658 (0xa25c20)
    char Unknown075C[0x085A - 0x075C];
    char Field85A[0x22];                        // +0x085a (0xa25e22, meaning unknown)
    int Field87C;                               // +0x087c (0xa25e44, meaning unknown)
    bool Flag880;                               // +0x0880 (0xa25e48, meaning unknown)
    char Unknown0881[0x0884 - 0x0881];
    int Field884;                               // +0x0884 (0xa25e4c, meaning unknown)
    char Unknown0888[0x0894 - 0x0888];
    IPXAddressClass HostAddress;                // +0x0894 (0xa25e5c, see the other claims)
    char Unknown089E[0x2364 - 0x089E];
    int IsBridge;                               // +0x2364 (0xa2792c)
    IPXAddressClass BridgeNet;                  // +0x2368 (0xa27930)
    bool Flag2372;                              // +0x2372 (0xa2793a, meaning unknown)
    char Unknown2373[0x2374 - 0x2373];
    bool Flag2374;                              // +0x2374 (0xa2793c, game open; meaning provisional)
    char Unknown2375[0x2376 - 0x2375];
    wchar_t GameName[0x14];                     // +0x2376 (0xa2793e, see Conquer.CPP SessionName2376)
    GlobalPacketType GPacket;                   // +0x239e (0xa27966)
    char Unknown2565[0x27B0 - 0x2565];
    DynamicVectorClass<NodeNameType *> Chat;    // +0x27b0 (0xa27d78)
    DynamicVectorClass<NodeNameType *> Games;   // +0x27c8 (0xa27d90)
    DynamicVectorClass<MPPlayerNode *> Players; // +0x27e0 (0xa27da8, MPPlayers in other files)
    int Field27F8;                              // +0x27f8 (0xa27dc0, meaning unknown)
    MPPlayerNode * Slots[8];                    // +0x27fc (0xa27dc4, meaning provisional)
};
extern SessionClass Session;                    // 0xa255c8

struct GameOptionsType {
    int GameSpeed;                              // +0x00
};
extern GameOptionsType Options;                 // 0xa28758 (OptionsClass, only GameSpeed here)
extern int Seed;                                // 0xa2897c (name provisional)

extern char OptionsString[0x200];               // 0xa59764 (this file's .bss, name provisional)

// Simple owned strings (library code near 0x759260 / 0x75b300; see WDTGameOptions.cpp).
class CharStringClass {
public:
    CharStringClass(char const * string);           // 0x759260
    CharStringClass(CharStringClass const & string); // 0x7592c0
    ~CharStringClass();                              // 0x759320
    operator char * ();                              // 0x75a030
    char * Buffer;
};
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);         // 0x75b300
    ~WideStringClass();                              // 0x75b390
    WideStringClass & operator = (wchar_t const * string);   // 0x75b4b0
    wchar_t * Buffer;
};
CharStringClass To_CharString(WideStringClass const & string);   // 0x75cf10 (name provisional)
extern char NullString[];                       // 0x8248a4

// RTTI .?AVMultiplayerGameMode@@ (vtable 0x792188, 44 slots); only up to slot 20 here.
class MultiplayerGameMode {
public:
    virtual ~MultiplayerGameMode();
    virtual void Slot_01(); virtual void Slot_02(); virtual void Slot_03(); virtual void Slot_04();
    virtual void Slot_05(); virtual void Slot_06(); virtual void Slot_07(); virtual void Slot_08();
    virtual void Slot_09(); virtual void Slot_10(); virtual void Slot_11();
    virtual bool Slot_12();                     // slot 12 (see NetDlg.CPP Announce_Last_Player)
    virtual void Slot_13(); virtual void Slot_14(); virtual void Slot_15(); virtual void Slot_16();
    virtual void Slot_17(); virtual void Slot_18(); virtual void Slot_19();
    virtual void Slot_20();                     // slot 20 (meaning unknown)
};
extern MultiplayerGameMode * SessionGameMode;   // 0xa255cc  (Session + 0x4)

extern bool Flag_A28944;                        // 0xa28944 (meaning unknown, see Restate.cpp)
unsigned long Compute_Name_CRC(wchar_t * name); // 0x5b6c30 (NetDlg.CPP)
void Delete_All(DynamicVectorClass<MPPlayerNode *> & vector);   // 0x5a4070 (MPLayer.CPP; other files use NodeNameType)
void Delete_All(DynamicVectorClass<NodeNameType *> & vector);   // 0x5a4070 (same function)

// Message box with an inline constructor that stores the caption (see NullDlg.CPP).
class WWMessageBox {
public:
    WWMessageBox(wchar_t const * caption = L" ") : Caption(caption) {}
    int Process(wchar_t const * msg, wchar_t const * b1, wchar_t const * b2 = NULL,
        wchar_t const * b3 = NULL, bool flag = false);     // 0x5b1290
    wchar_t const * Caption;
};

class ScenarioClass {
public:
    char Unknown0[0x83C];
    char FileName[0x104];                       // +0x83c (size assumed)
};
extern ScenarioClass * Scen;                    // 0xa255c0

bool Is_Scenario_Available(char const * filename, int crc, char const * name, bool random, int unknown);  // 0x663180 (provisional)
bool Get_File_From_Host(char * filename, int flag, int unknown);           // 0x661e50 (name from a debug string)
void Options_Func_5BE090(HWND dialog, int value);   // 0x5be090 (meaning unknown)

extern wchar_t NullWString[];                   // 0x82208c (.bss), shared empty wide string (name provisional)
// Dialog helpers used by the join dialog (see Skirmish.cpp, GDlgSupp.cpp, CampScor.cpp).
int Player_Side_ID(int slot);                           // 0x4d0d70
int Player_Side_Slot(int id);                           // 0x4d0dd0
wchar_t const * Side_Name(int side);                    // 0x4d0e40
void Fill_All_Side_Lists(HWND dialog);                  // 0x4d1030
void Select_Player_Side(HWND dialog, int slot);         // 0x4d10b0
int Get_Side_Data(HWND dialog, int id, int index);      // 0x4d14f0
int Player_Color_ID(int slot);                          // 0x4d1530
int Player_Color_Slot(int id);                          // 0x4d1590
wchar_t const * Color_Name(int color);                  // 0x4d1600
void Init_Player_Colors();                              // 0x4d1700
void Fill_All_Color_Lists(HWND dialog);                 // 0x4d1a80
void Select_Player_Color(HWND dialog, int slot);        // 0x4d1b00
int Get_Color_Data(HWND dialog, int id, int index);     // 0x4d1fd0
void Func_5F6060(LPARAM lparam);                        // 0x5f6060 (provisional, WM_DRAWITEM)
void Func_5F6B50(HWND dialog);                          // 0x5f6b50 (provisional, WM_PAINT)
void Func_5DE390(HWND dialog);                          // 0x5de390 (provisional, WM_PAINT)
void Func_5E0A50(HWND dialog);                          // 0x5e0a50 (provisional, message 0x4ec)
char const * Control_Help_Label(HWND dialog, HWND control);  // 0x5da760 (provisional)
bool Is_Scenario_Valid(int index);                      // 0x5c1bd0

// Tool tip text request sent to a dialog with message 0x4e9 (lparam); see Skirmish.cpp.
struct ControlTipType {
    HWND Window;                                // +0x0 control under the mouse
    int Index;                                  // +0x4 list item, -1 = none
    WideStringClass Text;                       // +0x8 tip text to fill in
};

// Map preview image (0xa5a860); see ModemGst.cpp.
class PreviewClass {
public:
    ~PreviewClass();                            // 0x615020
    void Draw(HWND dialog);                     // 0x615040
    void * Data;
};
extern PreviewClass * Preview;                  // 0xa5a860

// Two ints passed by value (meaning provisional); see SendFile.CPP.
struct Point2DStruct {
    int X;
    int Y;
    Point2DStruct(int x, int y) : X(x), Y(y) {}
};

// Object at 0xa5e540 (class not bound); see SendFile.CPP.
class Object_A5E540 {
public:
    void Func_617BE0(Point2DStruct point = Point2DStruct(-1, -1));              // 0x617be0
    bool Func_617F70();                         // 0x617f70 (meaning unknown)
    void Func_617F80();                         // 0x617f80 (meaning unknown)
};
extern Object_A5E540 ObjectA5E540;              // 0xa5e540

// Join dialog helpers in netshare.cpp (names provisional).
WideStringClass Chat_Edit_Text(HWND edit);      // 0x5c5850, result unused here
void Send_Lobby_Command(char * command);        // 0x5be7a0
void Send_Player_Command(char const * name, char const * command);   // 0x5be8d0
int Join_Func_5C3120(int id);                   // 0x5c3120
wchar_t const * Join_Func_5C3190(int value);    // 0x5c3190
int Join_Func_5C32D0(HWND dialog, int id, int index);   // 0x5c32d0
void Join_Func_5C3310(HWND dialog, int side);   // 0x5c3310
void Join_Func_5C3360(HWND dialog, int color);  // 0x5c3360
void Join_Func_5C35B0(HWND dialog, int value);  // 0x5c35b0

extern int DefaultColorRGB;                     // 0x79233c (.data, 0x40ffff; name provisional)
extern int ChatRecipientsAll;                   // 0x792324 (.data, 0xf0f0; meaning provisional)
void Func_5D75D0(LPARAM lparam, bool flag);     // 0x5d75d0 (provisional, message 0x4db)

// Host dialog helpers (names from other files' claims where known; others provisional).
void Prepare_Map_Selection(HWND dialog);        // 0x5de430
int Map_Selection_Dialog(HWND parent);          // 0x5c09f0
void Update_Preview(HWND dialog);               // 0x5c15d0
void Show_Game_Mode_Name(HWND dialog, MultiplayerGameMode * mode);   // 0x5bdf90
void Show_Scenario_Name(HWND dialog);           // 0x5bdff0
bool Host_Func_5C2560();                        // 0x5c2560
void Host_Func_5C3740(HWND dialog);             // 0x5c3740
bool Host_Func_5C41A0(HWND dialog);             // 0x5c41a0
void Host_Func_5C4940(HWND dialog, int oldscenario, int scenario);   // 0x5c4940
void Host_Func_5C4D30(HWND dialog, int id, int value, int mode);     // 0x5c4d30
void Host_Func_5C5140(HWND dialog);             // 0x5c5140
void Host_Func_5C51D0(HWND dialog, void * data);    // 0x5c51d0
void Host_Func_5C5350(HWND dialog, void * data);    // 0x5c5350
void Host_Func_72BC20(HWND dialog);             // 0x72bc20
extern bool RandomMapIdle;                      // 0x7d11a0 (.data, initial true; see ModemHst.cpp)
extern HWND MainWindow;                         // 0xb0de50

class VersionClass {
public:
    void Init_Clipping();                       // 0x707d20 (name provisional)
};
extern VersionClass VerNum;                     // 0xa288c8

// level-2 1.001: Random2Class (operator() 0x62FE40, the scenario generator), not RandomClass (0x62FCC0); shown by the P9 link check.
class Random2Class {
public:
    int operator()(int minval, int maxval);     // 0x62fe40 (name provisional)
};
extern Random2Class NonCriticalRandomNumber;     // 0x821558

extern bool Flag_A5A8BE;                        // 0xa5a8be (meaning unknown)
extern int NetDialogResult;                     // 0xa59a0c (this file's .bss; name provisional)

extern bool OptionsLocked;                      // 0xa59a18 (this file's .bss; name provisional)
extern int NetState;                            // 0xa59a14 (this file's .bss; 1/2 = joined/hosting? provisional)
extern char NetPassword[];                      // 0xa5974c (this file's .bss; meaning provisional)

// Helpers in netshare.cpp and other files (names provisional).
void Build_Player_Text(wchar_t * buffer);       // 0x5c2b20
int Lobby_Func_5C4C60(HWND dialog, int value);  // 0x5c4c60
void Lobby_Add_Message(int color, wchar_t const * text, ...);   // 0x5bd810
void Net_Func_5C25A0();                         // 0x5c25a0
void Net_Func_5C28C0();                         // 0x5c28c0
void Net_Func_5C28E0();                         // 0x5c28e0
void Net_Func_5C27C0();                         // 0x5c27c0
void Net_Func_5C2860();                         // 0x5c2860
void Net_Func_5BE350(bool a, bool b);           // 0x5be350

void Join_Func_5C5930(HWND dialog, bool flag);  // 0x5c5930

extern int SelectedGame;                        // 0xa59a10 (this file's .bss, name provisional)

void Update_Player_List(bool flag);             // 0x5b6fb0, defined below
void Update_Game_List();                        // 0x5b7960, defined below
void Send_Chat_Message(HWND dialog, int color, int id);   // 0x5ba060, defined below
void Net_Service();                             // 0x5bb510, defined below
int Player_Accept_State(char const * name);     // 0x5b7e20, defined below
void Send_Join_Queries(int gamenow, int playernow, int chatnow, int init);   // 0x5bae80, defined below

// ---- end of local declarations ----

bool AllowGameSelect = true;                    // 0x7d0db0 (.data; name provisional)

// 0x5b6ef0
bool Net_Service_Callback()
{
    Call_Back();
    Net_Service();
    return false;
}

// 0x5b6f00
void Send_Chat_Announce()
{
    GlobalPacketType packet;

    memset(&packet, 0, sizeof(packet));
    packet.Command = NET_CHAT_ANNOUNCE;
    strcpy(packet.Name, Session.Handle);
    Build_Player_Text(packet.Text);

    int count = Session.Players.ActiveCount;
    for (int i = 1; i < count; i++) {
        Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Players[i]->Address);
        Call_Back();
    }
}

// 0x5b6fa0
void Refresh_Player_List()
{
    Update_Player_List(false);
}

// 0x5b6fb0 Update_Player_List(bool) is not reconstructed yet (it inlines a hash table template
// that builds the owner-draw player list; see the claims file).

// 0x5b75c0
void Send_Reject(NodeNameType * node)
{
    memset(&Session.GPacket, 0, sizeof(Session.GPacket));
    Session.GPacket.Command = NET_REJECT_JOIN;
    Session.GPacket.ID = 4;
    Ipx.Send_Global_Message(&Session.GPacket, sizeof(Session.GPacket), 1, &node->Address);
}

// 0x5b7610
int Host_Func_5B7610(int value)
{
    return Lobby_Func_5C4C60(Find_Dialog(DLG_LAN_HOST), value);
}



// 0x5b76a0
void Shutdown_Network_5B76A0()   // provisional name; Shutdown_Network is 0x5b6730 (NetDlg.CPP), called by Emergency_Exit/Prog_End
{
    Net_Func_5C27C0();
    Session.GameName[0] = 0;
    if (PacketTransport != NULL) {
        delete PacketTransport;
    }
    PacketTransport = NULL;
}

// 0x5b76d0
void Check_Timeouts()
{
    for (int i = 1; i < Session.Games.ActiveCount; i++) {
        if (wcscmp(Session.Games[i]->Name, Session.GameName) != 0) {
            if (TickCount.Value() - Session.Games[i]->Game.LastTime > 300) {
                Debug_Printf("Game '%ls' has timed out\n", Session.Games[i]->Name);
                delete Session.Games[i];
                Session.Games.Delete(Session.Games[i]);
                Update_Game_List();
                if (i <= SelectedGame) {
                    Update_Player_List(false);
                    Send_Join_Queries(0, 1, 0, 0);
                }
            }
        }
    }

    for (int j = 1; j < Session.Chat.ActiveCount; j++) {
        if (Session.Chat[j]->Chat.LastTime == 0) {
            Session.Chat[j]->Chat.LastTime = TickCount.Value();
        }
        if (TickCount.Value() - Session.Chat[j]->Chat.LastTime > 360) {
            delete Session.Chat[j];
            Session.Chat.Delete(Session.Chat[j]);
            Update_Player_List(false);
        } else if (TickCount.Value() - Session.Chat[j]->Chat.LastTime > 300 && !Session.Chat[j]->Chat.LastChance) {
            GlobalPacketType packet;
            memset(&packet, 0, sizeof(packet));
            strcpy(packet.Name, Session.Handle);
            packet.Command = NET_PING;
            Ipx.Send_Global_Message(&packet, sizeof(packet), 0, &Session.Chat[j]->Address);
            Call_Back();
            Session.Chat[j]->Chat.LastChance = true;
        }
    }
}

// 0x5b7960
void Update_Game_List()
{
    wchar_t buffer[80];

    if (Current_Dialog_ID() != DLG_LAN_LOBBY) {
        return;
    }

    HWND dialog = Current_Dialog();
    HWND list = GetDlgItem(dialog, 0x549);

    if (SelectedGame >= Session.Games.ActiveCount) {
        SelectedGame = Session.Games.ActiveCount - 1;
        Send_Join_Queries(0, 1, 0, 0);
    }
    if (SelectedGame < 0) {
        SelectedGame = 0;
    }

    int top = SendDlgItemMessageA(dialog, 0x549, LB_GETTOPINDEX, 0, 0);
    SendDlgItemMessageA(dialog, 0x549, 0x49d, 0, 1);
    SendMessageA(list, LB_RESETCONTENT, 0, 0);
#line 488 "C:\\RA2\\netdlg2.cpp"
    SendMessageA(list, 0x4cd, 0, (LPARAM)Fetch_String("TXT_LOBBY", NULL, __FILE__, __LINE__));

    for (int i = 1; i < Session.Games.ActiveCount; i++) {
        NodeNameType * game = Session.Games[i];
        if (game->Game.IsOpen) {
#line 494
            swprintf(buffer, Fetch_String("TXT_THATGUYS_GAME", NULL, __FILE__, __LINE__), game->Name);
        } else {
#line 496
            swprintf(buffer, Fetch_String("TXT_THATGUYS_GAME_BRACKET", NULL, __FILE__, __LINE__), game->Name);
        }
        SendMessageA(list, 0x4cd, 0, (LPARAM)buffer);
    }

    SendDlgItemMessageA(dialog, 0x549, LB_SETCURSEL, SelectedGame, 0);
    SendDlgItemMessageA(dialog, 0x549, LB_SETTOPINDEX, top, 0);
    SendDlgItemMessageA(dialog, 0x549, 0x49d, 0, 0);
    HWND item = GetDlgItem(dialog, 0x549);
    InvalidateRect(item, NULL, FALSE);
    UpdateWindow(item);
}

// 0x5b7b10
void Build_Options_String(char * buffer)
{
    CharStringClass name(Session.ScenarioName ? To_CharString(Session.ScenarioName) : CharStringClass(NullString));

    sprintf(buffer, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s,%d,%d,%d,%s,%s:",
        Seed, Options.GameSpeed, Session.GameSpeed, Session.Credits, Session.UnitCount,
        Session.ShortGame, Session.SuperWeapons, Session.BuildOffAlly, Session.MCVRedeploy, Session.Crates,
        Session.Field018, (char *)name, Session.Field884, Session.Flag880, Session.Field87C,
        Session.ScenarioFile, Session.Field85A);

    int count = Session.Players.ActiveCount;
    memset(OptionsString, 0, sizeof(OptionsString));
    for (int i = 0; i < count; i++) {
        MPPlayerNode * node = Session.Players[i];
        int side = node->Side();
        int color = node->Color();
        sprintf(OptionsString + strlen(OptionsString), "%s,%d,%d,", To_Narrow(Session.Players[i]->Name), side, color);
    }
    OptionsString[strlen(OptionsString) - 1] = ':';
    strcat(OptionsString, "@:");

    for (int j = 0; j < 8; j++) {
        sprintf(OptionsString + strlen(OptionsString), "%d,%d,%d,", Session.SlotA[j], Session.SlotB[j], Session.SlotC[j]);
    }

    Debug_Printf("Size of options string is %d bytes\n", strlen(OptionsString));
    strcat(buffer, OptionsString);
}

// 0x5b7d80
void Set_Player_Accept(char const * name, int state)
{
    if (name == NULL) {
        name = Session.Handle;
        if (!state) {
            HWND dialog = Find_Dialog(DLG_LAN_JOIN);
            Join_Func_5C5930(dialog, true);
        }
    }

    if (wcscmp(To_Wide(name), Session.GameName) == 0) {
        state = 1;
    }

    int index = -1;
    for (int i = 0; i < Session.Players.ActiveCount; i++) {
        if (stricmp(To_Narrow(Session.Players[i]->Name), name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        Session.Players[index]->AcceptState = state;
    }
    Update_Player_List(false);
}

// 0x5b7e20
int Player_Accept_State(char const * name)
{
    if (name == NULL) {
        name = Session.Handle;
    }

    if (wcscmp(To_Wide(name), Session.GameName) == 0) {
        return 1;
    }

    int index = -1;
    for (int i = 0; i < Session.Players.ActiveCount; i++) {
        if (stricmp(To_Narrow(Session.Players[i]->Name), name) == 0) {
            index = i;
        }
    }
    if (index != -1) {
        return Session.Players[index]->AcceptState;
    }
    return -1;
}

// 0x5b7eb0
int Set_Player_Side_Color(char const * name, int side, int color)
{
    int index = -1;
    for (int i = 0; i < 8; i++) {
        char * slotname = To_Narrow(Session.Slots[i]->Name);
        if (stricmp(slotname, name) == 0) {
            index = i;
            break;
        }
    }

    int changed = 0;
    if (index == -1) {
        return 0;
    }

    HWND dialog = Find_Dialog(DLG_LAN_HOST);
    if (!dialog) {
        dialog = Find_Dialog(DLG_LAN_JOIN);
    }

    MPPlayerNode * node = Session.Slots[index];
    if (node->Side() != side) {
        changed = 1;
        node->Set_Side(side);
    }
    if (Session.Slots[index]->Color() != color) {
        node->Set_Color(color);
    }
    Update_Player_List(false);
    return changed;
}

// 0x5b7f70
bool Get_Serial_Number(char * buffer)
{
    HKEY key;
    DWORD size;
    DWORD type;
    char serial[128];

    memset(serial, '0', 22);
    serial[22] = 0;
    strcpy(buffer, serial);
    memset(serial, 0, sizeof(serial));

    char const * keyname = "SOFTWARE\\Westwood\\Red Alert 2";
    if (keyname && strlen(keyname)) {
        char keybuf[256];
        strcpy(keybuf, keyname);
        if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, keybuf, 0, KEY_READ, &key) == ERROR_SUCCESS) {
            size = sizeof(serial);
            RegQueryValueExA(key, "Serial", NULL, &type, (LPBYTE)serial, &size);
            RegCloseKey(key);
        }
    }

    serial[22] = 0;
    strcpy(buffer, serial);

    int index = 0;
    FILE * fp = fopen("woldata.key", "r");
    if (!fp) {
        return false;
    }

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        serial[index] = (char)((((serial[index] - '0') % 10 - ch + 1000) % 10) + '0');
        index++;
        if (index == (int)strlen(serial)) {
            index = 0;
        }
    }
    fclose(fp);

    strcpy(buffer, serial);
    return true;
}

// 0x5b8150 (5606 bytes, references netdlg2.cpp; the main network dialog loop) is not
// reconstructed yet.

// 0x5b9740
bool Guest_Start_Game()
{
    Ipx.Set_Timing(Ipx.Global_Response_Time() + 2 > 30 ? Ipx.Global_Response_Time() + 2 : 30, -1, 1000, true);

    if (Is_Scenario_Available(Session.ScenarioFile, Session.Field87C, Session.Field85A, Session.Flag880, 1) == true) {
        Debug_Printf("Found local scenario, file name is %d\n", Session.ScenarioFile);
        GlobalPacketType packet;
        memset(&packet, 0, sizeof(packet));
        packet.Command = NET_READY_TO_GO;
        Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.HostAddress);
        while (Ipx.Global_Num_Send() > 0 && Ipx.Service()) {
            Call_Back();
        }
    } else {
        Debug_Printf("Failed to find local scenario, file name is %d\n", Session.ScenarioFile);
        if ((Session.Flag880 && !Session.Func_6683F0()) || !Get_File_From_Host(Session.ScenarioFile, 3, 1)) {
            Session.ScenarioIdx = -1;
#line 676
            WWMessageBox().Process(Fetch_String("TXT_UNABLE_PLAY_WAAUGH", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));

            GlobalPacketType packet;
            memset(&packet, 0, sizeof(packet));
            packet.Command = NET_SIGN_OFF;
            strcpy(packet.Name, Session.Handle);
            for (int i = 1; i < Session.Chat.ActiveCount; i++) {
                Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Chat[i]->Address);
                Call_Back();
            }
            Ipx.Send_Global_Message(&packet, sizeof(packet), 0, NULL);
            if (Session.IsBridge) {
                Ipx.Send_Global_Message(&packet, sizeof(packet), 0, &Session.BridgeNet);
            }
            while (Ipx.Global_Num_Send() > 0 && Ipx.Service()) {
                Call_Back();
            }
            return false;
        }
    }

    strcpy(Scen->FileName, Session.ScenarioFile);

    int resp = Ipx.Global_Response_Time();
    if (resp < 20) {
        Debug_Printf("IPX.Global_Response_Time() == %d. Adjusting to 20\n", resp);
        resp = 20;
    }
    Ipx.Set_Timing(resp, -1, (resp * 8 < 120) ? 120 : resp * 8, true);
    Ipx.Set_Timing_524210(60, -1, 600);
    return true;
}

// 0x5b9a30
BOOL CALLBACK Lobby_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message) {
        case WM_ERASEBKGND:
            return TRUE;

        case WM_PAINT:
            Func_5F6B50(dialog);
            Func_5DE390(dialog);
            ValidateRect(dialog, NULL);
            return FALSE;

        case WM_DRAWITEM:
            Func_5F6060(lparam);
            return TRUE;

        case WM_COMMAND:
        {
            int id = LOWORD(wparam);
            switch (id) {
                case 0x541:
                    if (IsWindowEnabled(dialog) && NetDialogResult == 0) {
                        wchar_t name[0x14];
                        name[0] = 0;
                        HWND item = GetDlgItem(dialog, 0x541);
                        SendMessageA(item, 0x4b3, 0x14, (LPARAM)name);
                        wchar_t * ptr = name;
                        while (*ptr != 0 && *ptr == L' ') {
                            ptr++;
                        }
                        if (*ptr == 0 && name[0] != 0) {
                            name[0] = 0;
                            item = GetDlgItem(dialog, 0x541);
                            SendMessageA(item, 0x4b2, 0, (LPARAM)name);
                        }
                        if (strcmp(To_Narrow(name), Session.Handle) != 0) {
                            strcpy(Session.Handle, To_Narrow(name));
                            Send_Join_Queries(0, 0, 1, 0);
                            Update_Player_List(false);
                            return FALSE;
                        }
                    }
                    break;

                case 0x540:
                    Chat_Edit_Text((HWND)lparam);
                    if (HIWORD(wparam) == 0x501) {
                        Send_Chat_Message(dialog, DefaultColorRGB, ChatRecipientsAll);
                        return FALSE;
                    }
                    break;

                case 0x549:
                    if (NetState <= 0) {
                        int oldgame = SelectedGame;
                        int sel = SendDlgItemMessageA(dialog, 0x549, LB_GETCURSEL, 0, 0);
                        if (sel >= 0 && AllowGameSelect) {
                            SelectedGame = sel;
                            wcscpy(Session.GameName, Session.Games[sel]->Name);
                        }
                        if (HIWORD(wparam) == LBN_SELCHANGE) {
                            Delete_All(Session.Players);
                            if (oldgame != SelectedGame) {
                                Send_Join_Queries(1, 1, 1, 0);
                            }
                            Update_Player_List(false);
                            return FALSE;
                        }
                        if (HIWORD(wparam) == LBN_DBLCLK) {
                            NetDialogResult = 0x6cd;
                            return FALSE;
                        }
                    }
                    break;

                case 0x5c0:
                    NetDialogResult = 0x5c0;
                    return FALSE;

                case 0x6cc:
                case 0x6cd:
                {
                    EnableWindow(dialog, FALSE);
                    HWND item = GetDlgItem(dialog, 0x541);
                    if (item != NULL) {
                        EnableWindow(item, FALSE);
                    }
                    NetDialogResult = id;
                    return FALSE;
                }
            }
            break;
        }

        case WM_MOUSEMOVE:
        {
            HWND help = GetDlgItem(dialog, 0x695);
            if (help != NULL) {
                RECT rect;
                POINT point;
                point.x = LOWORD(lparam);
                point.y = HIWORD(lparam);
                GetWindowRect(dialog, &rect);
                point.x -= rect.left;
                point.y -= rect.top;
                wchar_t const * text = NullWString;
                HWND child = ChildWindowFromPointEx(dialog, point, CWP_SKIPINVISIBLE);
                if (child != NULL) {
                    char const * label = Control_Help_Label(dialog, child);
                    if (label != NULL) {
#line 2081
                        text = Fetch_String(label, NULL, __FILE__, __LINE__);
                    }
                }
                SendMessageA(help, 0x4b2, 0, (LPARAM)text);
                return FALSE;
            }
            break;
        }

        case 0x4ec:
            Func_5E0A50(dialog);
            return FALSE;

        case 0x4db:
            Func_5D75D0(lparam, wparam != 0);
            return FALSE;

        case 0x497:
        {
            AllowGameSelect = true;
            SelectedGame = 0;
            SendDlgItemMessageA(dialog, 0x541, EM_LIMITTEXT, 0x10, 0);
            SendDlgItemMessageA(dialog, 0x541, 0x4eb, 0, (LPARAM)",");
            SendDlgItemMessageA(dialog, 0x541, 0x4d1, 1, 0);
            wchar_t * handle = To_Wide(Session.Handle);
            HWND item = GetDlgItem(dialog, 0x541);
            SendMessageA(item, 0x4b2, 0, (LPARAM)handle);
            Session.ScenarioName[0] = 0;
            Session.UniqueID = Session.Color;
            Session.Field120 = Session.ColorPref;
            Delete_All(Session.Games);
            Delete_All(Session.Players);
            Delete_All(Session.Chat);

            NodeNameType * node = new NodeNameType;
            wcscpy(node->Name, To_Wide(Session.Handle));
            node->Chat.LastTime = 0;
            node->Chat.LastChance = false;
            node->Chat.Value = Session.GPacket.PlayerInfo.Value2;
            Session.Chat.Add(node);

            NodeNameType * game = new NodeNameType;
            wcscpy(game->Name, NullWString);
            game->Game.IsOpen = false;
            game->Game.LastTime = 0;
            Session.Games.Add(game);

            Send_Join_Queries(1, 0, 1, 1);
            Update_Game_List();
            Update_Player_List(false);
            Func_5F6B50(dialog);
            SetFocus(GetDlgItem(dialog, 0x540));
            break;
        }
    }
    return FALSE;
}

// 0x5ba060
void Send_Chat_Message(HWND dialog, int color, int id)
{
    wchar_t buffer[0x70];

    HWND item = GetDlgItem(dialog, 0x540);
    SendMessageA(item, 0x4b3, 0x6f, (LPARAM)buffer);
    buffer[0x6f] = 0;
    int len = wcslen(buffer);
    item = GetDlgItem(dialog, 0x540);
    SendMessageA(item, 0x4b2, 0, (LPARAM)NullWString);
    InvalidateRect(dialog, NULL, TRUE);

    if (len > 2) {
        Lobby_Add_Message(color, L"[%s] %s", To_Wide(Session.Handle), buffer);

        GlobalPacketType packet;
        memset(&packet, 0, sizeof(packet));
        packet.Command = NET_MESSAGE;
        strcpy(packet.Name, Session.Handle);
        wcscpy(packet.Message.Text, buffer);
        packet.Message.ID = id;
        packet.Message.NameCRC = Compute_Name_CRC(Session.GameName);

        if (NetState == 2) {
            int count = Session.Players.ActiveCount;
            for (int i = 1; i < count; i++) {
                Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Players[i]->Address);
                Call_Back();
            }
        } else {
            int count = Session.Chat.ActiveCount;
            for (int i = 1; i < count; i++) {
                Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Chat[i]->Address);
                Call_Back();
            }
        }
    }
}

BOOL CALLBACK Options_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);   // 0x5baae0

// 0x5ba220
BOOL CALLBACK Host_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    if (message != 0x497) {
        Options_Dialog_Proc(dialog, message, wparam, lparam);
    }

    switch (message) {
        case WM_NCHITTEST:
        {
            HWND help = GetDlgItem(dialog, 0x695);
            if (help != NULL) {
                RECT rect;
                POINT point;
                point.x = LOWORD(lparam);
                point.y = HIWORD(lparam);
                GetWindowRect(dialog, &rect);
                point.x -= rect.left;
                point.y -= rect.top;
                wchar_t const * text = NullWString;
                HWND child = ChildWindowFromPointEx(dialog, point, CWP_SKIPINVISIBLE);
                if (child != NULL) {
                    char const * label = Control_Help_Label(dialog, child);
                    if (label != NULL) {
#line 2497
                        text = Fetch_String(label, NULL, __FILE__, __LINE__);
                    }
                }
                SendMessageA(help, 0x4b2, 0, (LPARAM)text);
                return FALSE;
            }
            break;
        }

        case WM_DRAWITEM:
            Func_5F6060(lparam);
            return TRUE;

        case WM_PAINT:
            Func_5F6B50(dialog);
            if (Preview != NULL) {
                Preview->Draw(dialog);
            }
            if (ObjectA5E540.Func_617F70()) {
                ObjectA5E540.Func_617BE0();
            }
            Func_5DE390(dialog);
            ValidateRect(dialog, NULL);
            return FALSE;

        case WM_DESTROY:
            if (ObjectA5E540.Func_617F70()) {
                ObjectA5E540.Func_617F80();
                return FALSE;
            }
            break;

        case WM_COMMAND:
        {
            int id = LOWORD(wparam);
            switch (id) {
                case 0x411: case 0x412: case 0x413: case 0x414:
                case 0x415: case 0x416: case 0x417: case 0x418:
                    if (HIWORD(wparam) == CBN_SELCHANGE && !OptionsLocked && Host_Func_5C2560()) {
                        int value = Join_Func_5C32D0(dialog, id, -1);
                        Host_Func_5C4D30(dialog, id, value, 2);
                        return FALSE;
                    }
                    break;

                case IDCANCEL:
                    if (!OptionsLocked) {
                        if (Preview != NULL) {
                            delete Preview;
                            Preview = NULL;
                        }
                        Host_Func_5C51D0(dialog, &Session.Field1B8);
                        NetDialogResult = 2;
                        return FALSE;
                    }
                    break;

                case 0x588:
                    EnableWindow(GetDlgItem(dialog, 0x588), FALSE);
                    OptionsLocked = true;
                    Host_Func_5C51D0(dialog, &Session.Field1B8);
                    NetDialogResult = 0x588;
                    return FALSE;

                case 0x540:
                    Chat_Edit_Text((HWND)lparam);
                    if (HIWORD(wparam) == 0x501) {
                        Send_Chat_Message(dialog, DefaultColorRGB, ChatRecipientsAll);
                        return FALSE;
                    }
                    break;

                case 0x5aa:
                    if (!OptionsLocked) {
                        int oldscenario = Session.ScenarioIdx;
                        bool oldmode = !SessionGameMode || SessionGameMode->Slot_12();
                        Prepare_Map_Selection(dialog);
                        ShowWindow(dialog, SW_HIDE);
                        RandomMapIdle = false;
                        if (Map_Selection_Dialog(MainWindow) == 2) {
                            Session.ScenarioIdx = oldscenario;
                            Is_Scenario_Valid(oldscenario);
                            Update_Preview(dialog);
                            RandomMapIdle = true;
                            ShowWindow(dialog, SW_SHOW);
                            Host_Func_5C5140(dialog);
                            Net_Func_5BE350(true, false);
                            InvalidateRect(dialog, NULL, FALSE);
                            return FALSE;
                        }
                        if (!Is_Scenario_Valid(Session.ScenarioIdx)) {
                            Session.ScenarioIdx = oldscenario;
                        } else {
                            Host_Func_5C4940(dialog, oldscenario, Session.ScenarioIdx);
                        }
                        RandomMapIdle = true;
                        ShowWindow(dialog, SW_SHOW);
                        Show_Scenario_Name(dialog);
                        Host_Func_5C5140(dialog);
                        bool newmode = !SessionGameMode || SessionGameMode->Slot_12();
                        if (oldmode && !newmode && Host_Func_5C41A0(dialog)) {
                            Session.AIPlayers = 0;
                            GlobalPacketType packet;
                            memset(&packet, 0, sizeof(packet));
                            packet.Command = NET_CHAT_ANNOUNCE;
                            strcpy(packet.Name, Session.Handle);
                            Build_Player_Text(packet.Text);
                            int count = Session.Players.ActiveCount;
                            for (int i = 1; i < count; i++) {
                                Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Players[i]->Address);
                                Call_Back();
                            }
                            Update_Player_List(false);
                            Net_Func_5BE350(true, false);
                            return FALSE;
                        }
                        Update_Player_List(true);
                        return FALSE;
                    }
                    break;

                case 0x510: case 0x513: case 0x514: case 0x51e: case 0x51f: case 0x520: case 0x521:
                case 0x6a1:
                    if (HIWORD(wparam) == CBN_SELCHANGE && !OptionsLocked) {
                        Join_Func_5C3310(dialog, id);
                        Net_Func_5BE350(true, false);
                        Update_Player_List(false);
                        return FALSE;
                    }
                    break;

                case 0x522: case 0x523: case 0x524: case 0x525: case 0x526: case 0x527: case 0x528:
                case 0x6a2:
                    if (HIWORD(wparam) == CBN_SELCHANGE && !OptionsLocked) {
                        Join_Func_5C3360(dialog, id);
                        Net_Func_5BE350(true, false);
                        Update_Player_List(false);
                        return FALSE;
                    }
                    break;

                default:
                    return FALSE;
            }
            break;
        }

        case 0x497:
            VerNum.Init_Clipping();
            srand(NonCriticalRandomNumber(1, 0x7fff));
            Seed = rand();
            Host_Func_72BC20(dialog);
            Fill_All_Side_Lists(dialog);
            Init_Player_Colors();
            Fill_All_Color_Lists(dialog);
            Select_Player_Side(dialog, Session.Field27F8);
            Select_Player_Color(dialog, Session.Field27F8);
            Update_Player_List(false);
            Host_Func_5C5350(dialog, &Session.Field1B8);
            Host_Func_5C4940(dialog, -1, Session.ScenarioIdx);
            Host_Func_5C3740(dialog);
            Show_Game_Mode_Name(dialog, SessionGameMode);
            Show_Scenario_Name(dialog);
            Host_Func_5C5140(dialog);
            Options_Dialog_Proc(dialog, message, wparam, lparam);
            Update_Game_List();
            return FALSE;

        case WM_HSCROLL:
        case WM_VSCROLL:
            if (!OptionsLocked) {
                Session.GameSpeed = 6 - SendDlgItemMessageA(dialog, 0x529, TBM_GETPOS, 0, 0);
                Session.Credits = SendDlgItemMessageA(dialog, 0x402, TBM_GETPOS, 0, 0);
                Session.UnitCount = SendDlgItemMessageA(dialog, 0x54f, TBM_GETPOS, 0, 0);
                return FALSE;
            }
            break;

        case 0x49b:
        {
            HWND item = GetDlgItem(dialog, wparam);
            SendMessageA(item, 0x4b3, 0x7f, lparam);
            return FALSE;
        }

        case 0x4ec:
            Func_5E0A50(dialog);
            break;

        case 0x4e9:
        {
            ControlTipType * tip = (ControlTipType *)lparam;
            tip->Text = NULL;
            if (tip->Window != NULL && tip->Index != -1) {
                int id = GetDlgCtrlID(tip->Window);
                if (Join_Func_5C3120(id) == -1) {
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
                    tip->Text = Join_Func_5C3190(Join_Func_5C32D0(dialog, id, tip->Index));
                }
            }
        }
        case WM_ERASEBKGND:
            return TRUE;

        default:
            return FALSE;
    }
    return FALSE;
}

// 0x5baae0
BOOL CALLBACK Options_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    if (!OptionsLocked) {
        switch (message) {
            case 0x497:
                Options_Func_5BE090(dialog, 1);
                return FALSE;

            case WM_HSCROLL:
                if (GetDlgItem(dialog, 0x529) == (HWND)lparam) {
                    Session.GameSpeed = 6 - SendDlgItemMessageA(dialog, 0x529, TBM_GETPOS, 0, 0);
                }
                if (GetDlgItem(dialog, 0x402) == (HWND)lparam) {
                    Session.Credits = SendDlgItemMessageA(dialog, 0x402, TBM_GETPOS, 0, 0);
                }
                if (GetDlgItem(dialog, 0x54f) == (HWND)lparam) {
                    Session.UnitCount = SendDlgItemMessageA(dialog, 0x54f, TBM_GETPOS, 0, 0);
                }
                return FALSE;

            case WM_COMMAND:
                switch (LOWORD(wparam)) {
                    case 0x54e:
                        Session.ShortGame = false;
                        if (SendDlgItemMessageA(dialog, 0x54e, BM_GETCHECK, 0, 0) == 1) {
                            Session.ShortGame = true;
                            if (!Session.Bases) {
                                Session.Bases = true;
                                SendDlgItemMessageA(dialog, 0x54b, BM_SETCHECK, 1, 0);
                            }
                        }
                        return FALSE;

                    case 0x54d:
                        Session.Crates = false;
                        if (SendDlgItemMessageA(dialog, 0x54d, BM_GETCHECK, 0, 0) == 1) {
                            Session.Crates = true;
                        }
                        return FALSE;

                    case 0x3e8:
                        Session.MCVRedeploy = false;
                        if (SendDlgItemMessageA(dialog, 0x3e8, BM_GETCHECK, 0, 0) == 1) {
                            Session.MCVRedeploy = true;
                        }
                        return FALSE;

                    case 0x624:
                        Session.BridgeDestruction = false;
                        if (SendDlgItemMessageA(dialog, 0x624, BM_GETCHECK, 0, 0) == 1) {
                            Session.BridgeDestruction = true;
                        }
                        return FALSE;

                    case 0x69d:
                        Session.BuildOffAlly = false;
                        if (SendDlgItemMessageA(dialog, 0x69d, BM_GETCHECK, 0, 0) == 1) {
                            Session.BuildOffAlly = true;
                        }
                        return FALSE;

                    case 0x69a:
                        Session.SuperWeapons = false;
                        if (SendDlgItemMessageA(dialog, 0x69a, BM_GETCHECK, 0, 0) == 1) {
                            Session.SuperWeapons = true;
                        }
                        return FALSE;
                }
                break;
        }
    }
    return FALSE;
}

// 0x5bad70
void Leave_Game(int game)
{
    GlobalPacketType packet;

    memset(&packet, 0, sizeof(packet));
    packet.Command = NET_SIGN_OFF;
    strcpy(packet.Name, Session.Handle);

    for (int i = 1; i < Session.Players.ActiveCount; i++) {
        Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Players[i]->Address);
        Call_Back();
    }

    if (NetState == 1 || NetState == 2) {
        if (!Session.Games[game]->Address.Is_Broadcast()) {
            Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Games[game]->Address);
        }
    }

    Ipx.Send_Global_Message(&packet, sizeof(packet), 0, NULL);
    Net_Func_5C28C0();
    Net_Func_5C2860();
    Delete_All(Session.Players);
    Session.GameName[0] = 0;
}

// 0x5bae80
void Send_Join_Queries(int gamenow, int playernow, int chatnow, int init)
{
    static CDTimerClass<SystemTimerClass> game_timer;
    static CDTimerClass<SystemTimerClass> player_timer;
    static CDTimerClass<SystemTimerClass> chat_timer;

    if (init) {
        game_timer = 120;
        player_timer = 35;
        chat_timer = 83;
    }

    if (game_timer == 0 || gamenow) {
        game_timer = 120;
        if (Current_Dialog_ID() != DLG_LAN_HOST || gamenow) {
            GlobalPacketType packet;
            memset(&packet, 0, sizeof(packet));
            packet.Command = NET_QUERY_GAME;
            strcpy(packet.Name, Session.Handle);
            Ipx.Send_Global_Message(&packet, sizeof(packet), 0, NULL);
            if (Session.IsBridge) {
                Ipx.Send_Global_Message(&packet, sizeof(packet), 0, &Session.BridgeNet);
            }
        }
    }

    if ((SelectedGame > 0 && SelectedGame < Session.Games.ActiveCount && player_timer == 0) || playernow) {
        player_timer = 35;
        GlobalPacketType packet;
        memset(&packet, 0, sizeof(packet));
        packet.Command = NET_QUERY_PLAYER;
        strcpy(packet.Name, To_Narrow(Session.Games[SelectedGame]->Name));
        Ipx.Send_Global_Message(&packet, sizeof(packet), 0, NULL);
        if (Session.IsBridge) {
            Ipx.Send_Global_Message(&packet, sizeof(packet), 0, &Session.BridgeNet);
        }
    }

    if ((chat_timer == 0 && NetState < 2) || chatnow) {
        chat_timer = 83;
        GlobalPacketType packet;
        memset(&packet, 0, sizeof(packet));
        packet.Command = NET_CHAT_QUERY;
        strcpy(packet.Name, Session.Handle);
        packet.PlayerInfo.Value1 = Session.Field104;
        packet.PlayerInfo.Value2 = Session.UniqueID;
        Ipx.Send_Global_Message(&packet, sizeof(packet), 0, NULL);
        if (Session.IsBridge) {
            Ipx.Send_Global_Message(&packet, sizeof(packet), 0, &Session.BridgeNet);
        }
    }
}

// 0x5bb2a0
bool Process_Global_Packet(GlobalPacketType * packet, IPXAddressClass * address)
{
    if (packet->Command == NET_QUERY_GAME && !Session.Flag2372) {
        if (wcslen(Session.GameName) > 0) {
            if (!Session.Flag2374 || stricmp(Session.Handle, To_Narrow(Session.GameName)) == 0) {
                if (stricmp(Session.Handle, To_Narrow(Session.GameName)) != 0 && !Flag_A28944) {
                    return true;
                }
                GlobalPacketType reply;
                memset(&reply, 0, sizeof(reply));
                reply.Command = NET_ANSWER_GAME;
                strcpy(reply.Name, To_Narrow(Session.GameName));
                reply.GameInfo.IsOpen = Session.Flag2374;
                Ipx.Send_Global_Message(&reply, sizeof(reply), 1, address);
            }
        }
        return true;
    }

    if (packet->Command == NET_QUERY_PLAYER) {
        if (stricmp(packet->Name, To_Narrow(Session.GameName)) == 0 && wcslen(Session.GameName) > 0
            && !Session.Flag2372 && NetState >= 2) {
            GlobalPacketType reply;
            memset(&reply, 0, sizeof(reply));
            reply.Command = NET_ANSWER_PLAYER;
            strcpy(reply.Name, Session.Handle);
            strcpy(reply.Name2, NetPassword);
            reply.PlayerInfo.Value1 = Session.Func_668C60();
            reply.PlayerInfo.Value2 = Session.Func_668C80();
            reply.PlayerInfo.NameCRC = Compute_Name_CRC(Session.GameName);
            reply.PlayerInfo.Value3 = Session.Field27F8;
            Ipx.Send_Global_Message(&reply, sizeof(reply), 1, address);
            if (stricmp(packet->Name, To_Narrow(Session.Players[0]->Name)) == 0) {
                Net_Func_5BE350(true, true);
                if (SessionGameMode) {
                    SessionGameMode->Slot_20();
                }
            }
            return true;
        }
    }
    return false;
}

// 0x5bb510 Net_Service() (6592 bytes, the global packet loop) is not reconstructed yet.

// 0x5bced0
BOOL CALLBACK Join_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message) {
        case WM_DESTROY:
            if (ObjectA5E540.Func_617F70()) {
                ObjectA5E540.Func_617F80();
            }
            if (Preview != NULL) {
                delete Preview;
                Preview = NULL;
                return FALSE;
            }
            break;

        case WM_DRAWITEM:
            Func_5F6060(lparam);
        case WM_ERASEBKGND:
            return TRUE;

        case WM_PAINT:
            Func_5F6B50(dialog);
            if (Preview != NULL) {
                Preview->Draw(dialog);
            }
            if (ObjectA5E540.Func_617F70()) {
                ObjectA5E540.Func_617BE0();
            }
            Func_5DE390(dialog);
            ValidateRect(dialog, NULL);
            return FALSE;

        case WM_NCHITTEST:
        {
            HWND help = GetDlgItem(dialog, 0x695);
            if (help != NULL) {
                RECT rect;
                POINT point;
                point.x = LOWORD(lparam);
                point.y = HIWORD(lparam);
                GetWindowRect(dialog, &rect);
                point.x -= rect.left;
                point.y -= rect.top;
                wchar_t const * text = NullWString;
                HWND child = ChildWindowFromPointEx(dialog, point, CWP_SKIPINVISIBLE);
                if (child != NULL) {
                    char const * label = Control_Help_Label(dialog, child);
                    if (label != NULL) {
#line 2904
                        text = Fetch_String(label, NULL, __FILE__, __LINE__);
                    }
                }
                SendMessageA(help, 0x4b2, 0, (LPARAM)text);
                return FALSE;
            }
            break;
        }

        case 0x497:
            Fill_All_Side_Lists(dialog);
            Init_Player_Colors();
            Fill_All_Color_Lists(dialog);
            Join_Func_5C35B0(dialog, Session.Field27F8);
            Select_Player_Side(dialog, Session.Field27F8);
            Select_Player_Color(dialog, Session.Field27F8);
            EnableWindow(GetDlgItem(dialog, 0x59f), FALSE);
            Flag_A5A8BE = false;
            Set_Player_Accept(NULL, 0);
            Update_Player_List(false);
            Update_Game_List();
            Options_Func_5BE090(dialog, 1);
            Is_Scenario_Valid(-1);
            Session.Field884 = 8;
            return FALSE;

        case WM_COMMAND:
        {
            int id = LOWORD(wparam);
            switch (id) {
                case IDCANCEL:
                    if (!OptionsLocked) {
                        NetDialogResult = 2;
                        return FALSE;
                    }
                    break;

                case 0x540:
                    Chat_Edit_Text((HWND)lparam);
                    if (HIWORD(wparam) == 0x501) {
                        Send_Chat_Message(dialog, DefaultColorRGB, ChatRecipientsAll);
                        return FALSE;
                    }
                    break;

                case 0x59f:
                {
                    char buffer[0x40];
                    Session.Players[0]->AcceptState = 1;
                    sprintf(buffer, "A1");
                    Send_Lobby_Command(buffer);
                    HWND item;
                    Join_Func_5C5930(dialog, false);
                    item = GetDlgItem(dialog, 0x59f);
                    EnableWindow(item, FALSE);
                    InvalidateRect(item, NULL, FALSE);
                    SendMessageA(item, 0x4dc, 0, 0);
                    Update_Player_List(false);
                    return FALSE;
                }

                case 0x510:
                case 0x513:
                case 0x514:
                case 0x51e: case 0x51f: case 0x520: case 0x521: case 0x522: case 0x523:
                case 0x524: case 0x525: case 0x526: case 0x527: case 0x528:
                case 0x6a1:
                case 0x6a2:
                    if (HIWORD(wparam) == CBN_SELCHANGE) {
                        char buffer[0x40];
                        int sideslot = Player_Side_Slot(id);
                        int colorslot = Player_Color_Slot(id);
                        int slot = (sideslot > colorslot) ? sideslot : colorslot;
                        int side = Player_Side_ID(slot);
                        int color = Player_Color_ID(slot);
                        if (slot == sideslot) {
                            Join_Func_5C3310(dialog, side);
                        } else {
                            Join_Func_5C3360(dialog, color);
                        }
                        int sidedata = Get_Side_Data(dialog, side, -1);
                        int colordata = Get_Color_Data(dialog, color, -1);
                        sprintf(buffer, "R%d,%d", sidedata, colordata);
                        Send_Player_Command(To_Narrow(Session.GameName), buffer);
                        return FALSE;
                    }
                    break;
            }
            break;
        }

        case 0x4e9:
        {
            ControlTipType * tip = (ControlTipType *)lparam;
            tip->Text = NULL;
            if (tip->Window != NULL && tip->Index != -1) {
                int id = GetDlgCtrlID(tip->Window);
                if (Join_Func_5C3120(id) == -1) {
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
                    tip->Text = Join_Func_5C3190(Join_Func_5C32D0(dialog, id, tip->Index));
                }
            }
            return TRUE;
        }

        case 0x4ec:
            Func_5E0A50(dialog);
            break;
    }
    return FALSE;
}

// 0x5bd470
void Host_Update_Start_Button()
{
    HWND dialog = Current_Dialog();
    HWND item = GetDlgItem(dialog, 0x59f);
    if (Player_Accept_State(NULL) != 1) {
        SendMessageA(item, 0x4dc, 0, 1);
#line 4655
        Lobby_Add_Message(-1, Fetch_String("GUI:HostGameStartJoiner", NULL, __FILE__, __LINE__));
    }
}

// 0x5bd4d0
void Host_Clear_Start_Button()
{
    HWND dialog = Current_Dialog();
    HWND item = GetDlgItem(dialog, 0x59f);
    SendMessageA(item, 0x4dc, 0, 0);
}
