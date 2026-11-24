// C:\RA2\netshare.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Shared network dialog code: chat list output, message boxes, game option controls, scenario
// selection and the map preview, player list helpers and the game options packets.
// All function, class and variable names are provisional (Westwood style) unless they come
// from RTTI.
#include "GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>
#include <commctrl.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60

// Simple owned strings (library code near 0x759250 / 0x75b2f0).
class CharStringClass {
public:
    CharStringClass(char const * string);                       // 0x759260
    ~CharStringClass();                                         // 0x759320
    bool operator == (char const * string) const;               // 0x759340
    operator char * ();                                         // 0x75a030
    unsigned Get_Length() const;                                // 0x75a0e0
    char * Buffer;
};

class WideStringClass {
public:
    WideStringClass();                                          // 0x75b2f0
    WideStringClass(wchar_t const * string);                    // 0x75b300
    WideStringClass(WideStringClass const & string);            // 0x75b350
    ~WideStringClass();                                         // 0x75b390
    WideStringClass & operator = (wchar_t const * string);      // 0x75b4b0
    WideStringClass & operator = (WideStringClass const & string);  // 0x75b510
    WideStringClass & operator += (wchar_t const * string);     // 0x75b710
    operator wchar_t const * () const;                          // 0x75bd30
    operator wchar_t * ();                                      // 0x75bd70
    unsigned Get_Length() const;                                // 0x75bde0
    wchar_t operator [] (unsigned index) const;                 // 0x75bdb0
    void Trim_Right(WideStringClass const & characters);        // 0x75bb70 (name provisional)
    void Truncate(unsigned length);                             // 0x75c500 (name provisional)
    bool Is_ANSI() const;                                       // 0x75c9c0, all characters below 0x100 (name provisional)
    wchar_t * Buffer;
};

WideStringClass To_WideString(CharStringClass const & string);  // 0x75cb00
CharStringClass To_CharString(WideStringClass const & string);  // 0x75cbc0 (name provisional)

// Owner-drawn control helpers (GameDlg / list box code).
void List_Get_Text(HWND list, int index, WideStringClass & text);  // 0x5f8bb0
void Window_Get_Text(HWND window, WideStringClass & text);  // 0x5f8af0

// Dialog stack (pairs of window and resource id at 0xb0d630; see netdlg2.cpp).
HWND Find_Dialog(int id);                       // 0x72a500, NULL when not open
HWND Previous_Dialog(HWND dialog);              // 0x72a570, the dialog below on the stack
HWND Current_Dialog();                          // 0x72a6d0
int Current_Dialog_ID();                        // 0x72a6e0
void Get_Child_Rect(HWND window, RECT * rect);  // 0x72a250

// GDlgSupp.cpp
int Player_Flag_ID(int slot);                           // 0x4d0a80
int Player_Side_ID(int slot);                           // 0x4d0d70
void Select_Side(HWND dialog, int id, int side);        // 0x4d1310
int Get_Side_Data(HWND dialog, int id, int index);      // 0x4d14f0
int Player_Side_Slot(int id);                           // 0x4d0dd0
int Player_Color_ID(int slot);                          // 0x4d1530
void Select_Color(HWND dialog, int id, int color);      // 0x4d1bb0
int Get_Color_Data(HWND dialog, int id, int index);     // 0x4d1fd0
int Player_Color_Slot(int id);                          // 0x4d1590
void Color_Changed(HWND dialog, int id);                // 0x4d1e00

// Image cache at 0xa5ded0 (see GDlgSupp.cpp). Provisional.
class ImageCacheClass {
public:
    void * Find(char const * name, int unknown);    // 0x682140
};
extern ImageCacheClass ImageCache;              // 0xa5ded0
void Set_Control_Image(HWND window, void * image);  // 0x5da440

// Reference counting (see WDTSel.cpp).
// RTTI .?AVReferenceCounted@@, vtable 0x793cd4.
class ReferenceCounted {
public:
    ReferenceCounted() : ReferenceCount(0) {}
    virtual ~ReferenceCounted();                 // 0x630cb0 (deleting 0x630cf0)
    virtual bool Is_Kind(int kind) const;        // 0x630ce0
    virtual void Release();                      // 0x630cc0
    int ReferenceCount;
};

// RTTI .?AVrc_ptr_base@@, vtable 0x793ccc.
class rc_ptr_base {
public:
    rc_ptr_base();                               // 0x630a80
    rc_ptr_base(ReferenceCounted * pointer);     // 0x630a90
    rc_ptr_base(rc_ptr_base const & other);      // 0x630b00
    virtual ~rc_ptr_base();                      // 0x630ab0
    void Set(ReferenceCounted * pointer);        // 0x630ad0
protected:
    ReferenceCounted * Pointer;
};

template<class T>
class rc_ptr : public rc_ptr_base {
public:
    rc_ptr() {}
    rc_ptr(T * pointer) { Set(pointer); }
    rc_ptr(rc_ptr<T> const & other) { Set(other.Pointer); }
    virtual ~rc_ptr() {}
    rc_ptr<T> & operator = (rc_ptr<T> const & other) { Set(other.Pointer); return *this; }
    T * Get() const { return (T *)Pointer; }
    T * operator -> () const { return (T *)Pointer; }
};

// RTTI .?AVWDTTerritory@@ (see WDTSel.cpp). Only the option flags are used here.
class WDTTerritory : public ReferenceCounted {
public:
    char Unknown08[0x3C - 0x08];
    unsigned long OptionFlags;                  // +0x3c, allowed game options (meaning provisional)
};
rc_ptr<WDTTerritory> Conflict_Territory(int id);   // 0x755830 (WorldDom.cpp)

class RulesClass {
public:
    char Unknown0000[0x10E8];
    int MinCredits;                             // +0x10e8
    int Credits;                                // +0x10ec
    int MaxCredits;                             // +0x10f0
    int CreditStep;                             // +0x10f4
    int MinUnitCount;                           // +0x10f8
    int UnitCount;                              // +0x10fc
    int MaxUnitCount;                           // +0x1100
};
extern RulesClass * Rule;                       // 0x821b88

class BitFont {
public:
    virtual ~BitFont();
    int Get_Text_Size(wchar_t const * text, int * width, int * height, int max_width);    // 0x431370
};
extern BitFont * TextFont;                      // 0x836d30 (provisional)

// Dialog support (names provisional; see GameDlg.CPP / WorldDom.cpp).
extern HWND MainWindow;                         // 0xb0de50
extern HINSTANCE ProgramInstance;               // 0xb0dbf8 (name provisional)
HWND Create_Modeless_Dialog(HINSTANCE instance, int resource_id, HWND parent, DLGPROC proc, LPARAM param);   // 0x72a2c0
void Close_Dialog(HWND dialog, int result);     // 0x72a3a0
int Run_Dialog(HWND dialog, bool (*callback)(), int a, int b, int c);   // 0x72a5a0 (argument meanings unknown)
void Prepare_Dialog(HWND dialog, int resource_id);  // 0x5f74a0
void Set_Default_Button(HWND button);           // 0x5e12d0 (provisional)
void Func_5F6060(LPARAM lparam);                // 0x5f6060 (provisional, WM_DRAWITEM)
void Func_5F6B50(HWND dialog);                  // 0x5f6b50 (provisional, WM_PAINT)
void Func_5DE390(HWND dialog);                  // 0x5de390 (provisional, WM_PAINT)
typedef bool (*MessageCallback)();
void Func_514F50(int a, bool b);                // 0x514f50 (provisional, see CampScor.cpp)
bool Net_Service_Callback();                    // 0x5b6ef0 (netdlg2.cpp)
bool Func_732A40();                             // 0x732a40, session type 4 (provisional)
bool Func_482310();                             // 0x482310, returns false (provisional)
bool Host_Func_5B7610(int first);               // 0x5b7610 (netdlg2.cpp, declared there with an int result)
bool WOL_Func_74A220(int first);                // 0x74a220 (meaning unknown)
bool Any_AI_From(int slot);                     // 0x678060 (Skirmish.cpp)

// Message box with an inline constructor that stores the caption (L" " at 0x7c1624); see NullDlg.CPP.
class WWMessageBox {
public:
    WWMessageBox(wchar_t const * caption = L" ") : Caption(caption) {}
    int Process(wchar_t const * msg, wchar_t const * b1, wchar_t const * b2 = NULL,
        wchar_t const * b3 = NULL, bool flag = false);     // 0x5b1290
    wchar_t const * Caption;
};
int Random_Map_Dialog(MessageCallback callback);    // 0x574280, 1 = accepted

class ModemHostDialogClass {
    friend bool Map_Dialog_Callback();
    friend int Select_Random_Map();
    static bool Message_Callback();             // 0x599670 (ModemHst.cpp)
};

// Preview picture of the selected map, one image pointer (see Skirmish.cpp).
class MapPreviewClass {
public:
    MapPreviewClass();                          // 0x615010
    ~MapPreviewClass();                         // 0x615020
    void Draw(HWND dialog);                     // 0x615040
    void Load(char const * name);               // 0x615d50
    void Set_Image(void * image);               // 0x616510
    void * Image;                               // +0x0
};
extern MapPreviewClass * MapPreview;            // 0xa5a860

class HouseClass {
public:
    bool Is_Ally(HouseClass const * house) const;   // 0x4e4be0

    char Unknown00[0x134];
    bool Field134;                              // +0x134 (meaning unknown)
    char Unknown135[0x13D - 0x135];
    bool IsDefeated;                            // +0x13d
};
extern DynamicVectorClass<HouseClass *> Houses; // 0xa1a5c8

// RTTI .?AVMultiplayerGameMode@@ (vtable 0x792188, 44 slots); only up to slot 31 here.
class MultiMission;
class MultiplayerGameMode {
public:
    virtual ~MultiplayerGameMode();
    virtual void Slot_01(); virtual void Slot_02(); virtual bool Check_Start(WideStringClass * error); virtual void Slot_04();
    virtual void Slot_05();
    virtual void Slot_06();                     // slot 6 (meaning unknown)
    virtual void Slot_07();
    virtual void Activate();                    // slot 8 (meaning provisional, see Skirmish.cpp)
    virtual void Slot_09();                     // slot 9 (meaning unknown)
    virtual int Fixed_Side();                   // slot 10 (meaning provisional), -2 = none
    virtual bool Allows_Random();
    virtual bool Announce_Last_Player();        // slot 12 (meaning provisional, see Skirmish.cpp)
    virtual void Slot_13(); virtual void Slot_14(); virtual void Fill_Map_List(HWND list, DynamicVectorClass<MultiMission const *> * maps, void * selected); virtual void Slot_16();
    virtual void Slot_17(); virtual void Slot_18(); virtual void Slot_19(); virtual void Slot_20();
    virtual void Slot_21(); virtual void Slot_22(); virtual void Slot_23(); virtual void Slot_24();
    virtual void Slot_25(); virtual void Slot_26(); virtual void Slot_27(); virtual void Slot_28();
    virtual void Slot_29(); virtual void Slot_30();
    virtual void Update_Dialog();               // slot 31 (meaning provisional)
    virtual int Max_Players();                  // slot 32 (meaning provisional)
    virtual void Deactivate();                  // slot 33 (meaning provisional)

    bool Allows_Map(MultiMission const * map); // 0x5b3f30
    char Unknown04[0x20 - 0x04];
    WideStringClass Name;                       // +0x20
    WideStringClass Tooltip; // +0x24
    int ID;                                     // +0x28
};
MultiplayerGameMode * Default_Game_Mode();      // 0x5b39d0
MultiplayerGameMode * Game_Mode_From_ID(int id);    // 0x5b3af0

typedef unsigned char NetNumType[4];
typedef unsigned char NetNodeType[6];

#pragma pack(push, 1)
// IPX network/node address, 10 bytes (see NetDlg.CPP).
class IPXAddressClass {
public:
    IPXAddressClass();                          // 0x522950
    bool operator == (IPXAddressClass & address);  // 0x522ae0
private:
    NetNumType NetworkNumber;
    NetNodeType NodeAddress;
};

// Global (session) packet, 0x1c7 bytes. Only the fields used here.
struct GlobalPacketType {
    int Command;                                // +0x00
    char Name[0x14];                            // +0x04 narrow player name
    char Name2[0x17];                           // +0x18 (meaning provisional)
    char Text[0x190];                           // +0x2f chat text
    int UniqueID;                               // +0x1bf
    unsigned long NameCRC;                      // +0x1c3
};

// Multiplayer player list entry (see netdlg2.cpp / LdPrgMgr.cpp); only the fields used here.
// No destructor (plain operator delete).
class MPPlayerNode {
public:
    int Side() const;                           // 0x664e80: SideIndex unless SidePref is -2
    int Color() const;                          // 0x664e90: ColorIndex unless ColorPref is -2
    void Set_Side(int side);                    // 0x664ec0
    void Set_Color(int color);                  // 0x664ef0

    wchar_t Name[20];                           // +0x00
    IPXAddressClass Address;                    // +0x28
    char Unknown32[0x65 - 0x32];
    int AcceptState;                            // +0x65 (meaning provisional)
    char Unknown69[0x6D - 0x69];
    int HasScenario;                            // +0x6d (meaning provisional), object size 0x71
};
#pragma pack(pop)

enum NetCommandType {                           // provisional names
    NET_GAME_OPTIONS = 0x17,
    NET_PRIVATE_GAME_OPTIONS = 0x18,
    NET_PREVIEW_ACK = 0x1A,
    NET_LOBBY_LEAVE = 0x28
};

// RTTI .?AVIPXManagerClass@@ (vtable 0x78f6d4); only the non-virtual methods used here.
class IPXManagerClass {
public:
    void Set_Timing(unsigned long retrydelta, unsigned long maxretries, unsigned long timeout, bool global);  // 0x524160 (name provisional)
    int Global_Num_Send();                      // 0x524ce0
    int Send_Global_Message(void * buf, int buflen, int ack_req, IPXAddressClass * address);   // 0x524560
};
extern IPXManagerClass Ipx;                     // 0xa285c8

void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)
wchar_t * To_Wide(char const * string);         // 0x6eee20, rotating buffers (name provisional)
char * To_Narrow(wchar_t const * string);       // 0x6eedc0, rotating buffers (name provisional)
void Call_Back();                             // 0x4821e0 (provisional; see CampScor.cpp)
unsigned long Compute_Name_CRC(wchar_t * name); // 0x5b6c30 (NetDlg.CPP)
void Host_Update_Start_Button();                // 0x5bd470 (netdlg2.cpp)
void Host_Clear_Start_Button();                 // 0x5bd4d0 (netdlg2.cpp)
void Delete_All(DynamicVectorClass<MPPlayerNode *> & vector);   // 0x5a4070 (MPLayer.CPP; other files use NodeNameType)

// COM objects of Westwood Online (interfaces not bound; see Conquer.CPP).
struct IChatLike : public IUnknown {
    virtual HRESULT __stdcall Slot_03() = 0; virtual HRESULT __stdcall Slot_04() = 0;
    virtual HRESULT __stdcall Slot_05() = 0; virtual HRESULT __stdcall Slot_06() = 0;
    virtual HRESULT __stdcall Slot_07() = 0; virtual HRESULT __stdcall Slot_08() = 0;
    virtual HRESULT __stdcall Slot_09() = 0; virtual HRESULT __stdcall Slot_10() = 0;
    virtual HRESULT __stdcall Slot_11() = 0; virtual HRESULT __stdcall Slot_12() = 0;
    virtual HRESULT __stdcall Slot_13() = 0;
    virtual HRESULT __stdcall Request_Private_Message(void * users, char const * text) = 0;    // slot 14
    virtual HRESULT __stdcall Request_Public_Message(char const * text) = 0;                   // slot 15
};
extern IChatLike * WOLChat;                     // 0xa5a874

// WOL user record passed to the chat interface (0x6c bytes; layout provisional).
struct WOLUserType {
    char Unknown00[0x24];
    char Name[0x48];                            // +0x24
};

// Westwood Online dialog helpers (names provisional).
void WOL_Func_74A150();                         // 0x74a150
void Wol_Handle_Start_Reminder();                         // 0x74a170
void WOL_Func_74A1F0();                         // 0x74a1f0
void WOL_Func_7359A0();                         // 0x7359a0 (meaning unknown)
void WOL_Func_730F50();                         // 0x730f50 (meaning unknown)
void WOL_Func_73CE40();                         // 0x73ce40 (meaning unknown)
void WOL_Kick_Player(MPPlayerNode * node);      // 0x74a2c0 (name provisional)
void Send_Reject(MPPlayerNode * node);          // 0x5b75c0 (netdlg2.cpp, declared there with NodeNameType)
void Send_Chat_Announce();                      // 0x5b6f00 (netdlg2.cpp)
void Func_5B6FA0();                             // 0x5b6fa0 (netdlg2.cpp, meaning unknown)
void Update_Game_Options(bool force, bool flag);    // 0x5be350
void Build_Options_String(char * buffer);       // 0x5b7b10 (netdlg2.cpp)
void WOL_Build_Options_String(char * buffer);   // 0x731d10 (name provisional)

bool Is_Tournament_Server();                    // 0x730e40 (meaning provisional, see Multiplayer.cpp)
bool Is_Tournament_Game();                      // 0x730e70 (meaning provisional)

// File and INI classes (as in MPCoop.cpp / WDTSel.cpp).
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
    RawFileClass(char const * filename);        // 0x6300e0
    virtual ~RawFileClass();                    // 0x630060
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
    char RawFileData[0x1C];
};

class BufferIOFileClass : public RawFileClass {
public:
    virtual ~BufferIOFileClass();       // 0x42f250
private:
    char BufferIOData[0x34];
};

class CDFileClass : public BufferIOFileClass {
public:
    virtual ~CDFileClass() {}
    virtual char const * Set_Name(char const * filename);   // 0x46fd50
};

class Buffer {
public:
    Buffer(void * buffer = NULL, long size = 0);   // 0x438140
    ~Buffer();                                     // 0x438290
private:
    void * BufferPtr;
    long Size;
    bool IsAllocated;
};

class CCFileClass : public CDFileClass {
public:
    CCFileClass(char const * filename);                     // 0x468b70
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual long Size();                                    // 0x468d70
    virtual void Close();                                   // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

// Data straws (see ModemGst.cpp).
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
    char LZOData[0x28 - 0x0C];
};

bool Get_File_From_Host(char * filename, int flag, int unknown);   // 0x661e50 (see ModemGst.cpp)

class GenericNode {
public:
    GenericNode();                      // 0x40e160
    virtual ~GenericNode();
    void Link(GenericNode * node);      // 0x40e180
private:
    GenericNode * NextNode;
    GenericNode * PrevNode;
};

class GenericList {
public:
    GenericList() { FirstNode.Link(&LastNode); }
    virtual ~GenericList();
private:
    GenericNode FirstNode;
    GenericNode LastNode;
};

template<class T>
class List : public GenericList {
};

template<class INDEX, class DATA>
class IndexClass {
public:
    IndexClass() : IndexTable(0), IndexCount(0), IndexSize(0), IsSorted(false), Archive(0) {}
    ~IndexClass();
private:
    void * IndexTable;
    int IndexCount;
    int IndexSize;
    bool IsSorted;
    void const * Archive;
};

// RTTI .?AVINIClass@@ (vtable 0x78db34).
class INIClass {
public:
    struct INISection;

    INIClass() : Unknown34(0) {}
    virtual ~INIClass();                                                        // 0x50ad20
    int Load(FileClass & file, bool withdigest);                                // 0x50b030
    int Get_Int(char const * section, char const * entry, int defvalue) const;  // 0x50cc40
private:
    List<INISection *> SectionList;                 // +0x04
    IndexClass<int, INISection *> SectionIndex;     // +0x20
    int Unknown34;                                  // +0x34
};

// Multiplayer scenario description of the session list (see ModemHst.cpp).
class MultiMission {
public:
    MultiMission(char const * filename, char const * description, char const * digest, bool official);   // 0x668020
    void Set_Description(char const * description); // 0x668250
    bool Is_Random_Map() const;                 // 0x668370 (name provisional)
    bool Func_6681B0(int value);                // 0x6681b0 (meaning unknown, checks a file; see SendFile.CPP)
    int Func_668240();                          // 0x668240, required CD

    wchar_t Description[0x2C];                  // +0x00
    char FileName[0x104];                       // +0x58
    char Digest[0x20];                          // +0x15c
    bool IsOfficial;                            // +0x17c
    char Unknown17D[0x1BC - 0x17D];
};

// CD check object (RTTI .?AVCD@@, vtable 0x788868, three slots; see SendFile.CPP).
class CD {
public:
    CD() {}
    virtual bool Force_Available(int cd);       // 0x46e0f0
    virtual bool Virtual_01();                  // 0x46e120
    virtual bool Virtual_02();                  // 0x46e350
    int Unknown04;
};
extern int RequiredCD;                          // 0x7bd078 (.data, initial -1)
int Func_46E0C0(int value);                     // 0x46e0c0 (meaning unknown)

// Special game flags (RA name), 0xa28570 (see ModemHst.cpp).
class SpecialClass {
public:
    void Func_680B10();                         // 0x680b10

    unsigned Bit0 : 1;
    unsigned Bit1 : 1;
    unsigned Bit2 : 1;
    unsigned Bit3 : 1;
    unsigned Bit4 : 1;
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
extern int NetworkEventMode;                    // 0xa2896c (see NetDlg.CPP)

class OptionsClass {
public:
    int GameSpeed;                              // +0x00
};
extern OptionsClass Options;                    // 0xa28758

class ScenarioClass {
public:
    char Unknown000[0x834];
    int ScenarioIndex;                          // +0x834
    char Unknown838[0x83C - 0x838];
    char ScenarioName[0x100];                   // +0x83c
};
extern ScenarioClass * Scen;                    // 0xa255c0

// Random map generator object at 0xa57980 (see ModemHst.cpp / WorldDom.cpp); only the
// parameter block used for the digest.
struct RandomMapParamsType {
    char Unknown00[0x40];
    char FileName[0x100];                       // +0x40 (0xa579f8, RandomMapName in other files)
};
class RandomMapClass {
public:
    void Func_575CC0(char const * filename);    // 0x575cc0
    char Unknown00[0x38];
    RandomMapParamsType Params;                 // +0x38 (0xa579b8)
};
extern RandomMapClass RandomMap;                // 0xa57980

// Game options of the session being set up (Session + 0x18; see Skirmish.cpp). Field names
// from ModemHst.cpp where known, otherwise provisional.
struct GameOptionsType {
    void Clear_AI_Players();                    // 0x668a80

    int GameMode;                               // +0x00 0xa255e0
    int Scenario;                               // +0x04 0xa255e4
    bool Bases;                                 // +0x08 0xa255e8
    int Credits;                                // +0x0c 0xa255ec
    bool BridgeDestruction;                     // +0x10 0xa255f0
    bool Crates;                                // +0x11 0xa255f1
    bool ShortGame;                             // +0x12 0xa255f2
    bool SuperWeapons;                          // +0x13 0xa255f3
    bool BuildOffAlly;                          // +0x14 0xa255f4
    int GameSpeed;                              // +0x18 0xa255f8
    bool CrapEngineers;                         // +0x1c 0xa255fc
    int UnitCount;                              // +0x20 0xa25600
    int AIPlayers;                              // +0x24 0xa25604
    int AIDifficulty;                           // +0x28 0xa25608
    int SlotAI[8];                              // +0x2c 0xa2560c, per player slot
    int Side[8];                                // +0x4c 0xa2562c, per player slot
    int Color[8];                               // +0x6c 0xa2564c, per player slot
    bool Flag8C;                                // +0x8c 0xa2566c
    bool HarvesterTruce;                        // +0x8d 0xa2566d
    bool Flag8E;                                // +0x8e
    bool FogOfWar;                              // +0x8f 0xa2566f
    bool MCVRedeploy;                           // +0x90 0xa25670
    bool Unknown91;
    wchar_t ScenarioName[0x2F];                 // +0x92 0xa25672
};

// Skirmish settings kept between dialogs (Session + 0x13c, see Skirmish.cpp). Field names
// provisional.
struct SkirmishAIType {
    int Type;                                   // slot node type (Slot_Node_Type)
    int Side;
    int Color;
};
struct SkirmishSettingsType {
    int GameMode;                               // +0x00
    int Scenario;                               // +0x04
    int GameSpeed;                              // +0x08
    int Credits;                                // +0x0c
    int UnitCount;                              // +0x10
    bool ShortGame;                             // +0x14
    bool SuperWeapons;                          // +0x15
    bool BuildOffAlly;                          // +0x16
    bool MCVRedeploy;                           // +0x17
    bool Crates;                                // +0x18
    int Unknown1C[(0x28 - 0x1C) / 4];
    SkirmishAIType AI[7];                       // +0x28, player slots 1..7
};

// Session object at 0xa255c8 (class name provisional); only the members used here, at their
// binary offsets (names from ModemHst.cpp / netdlg2.cpp where known).
class SessionClass {
public:
    int Func_668C80();                          // 0x668c80 (meaning unknown)
    void Set_Side_Choice(int side, bool flag);  // 0x668ca0 (name provisional)
    void Set_Color_Choice(int color, bool flag);    // 0x668d50 (name provisional)

    int Type;                                   // +0x0000 (0xa255c8)
    MultiplayerGameMode * GameMode;             // +0x0004 (0xa255cc)
    int TerritoryID;                            // +0x0008 (0xa255d0, World Domination territory; provisional)
    int Field00C;                               // +0x000c (0xa255d4, 2 = conflict game; provisional)
    char Unknown0010[0x0014 - 0x0010];
    int Version;                                // +0x0014 (0xa255dc)
    GameOptionsType Options;                    // +0x0018 (0xa255e0)
    char Handle[0x14];                          // +0x0108 (0xa256d0)
    int UniqueID;                               // +0x011c (0xa256e4, see NullDlg.CPP)
    char Unknown0120[0x02C0 - 0x0120];
    int MaxPlayers;                             // +0x02c0 (0xa25888, meaning provisional)
    int NumPlayers;                             // +0x02c4 (0xa2588c)
    char Unknown02C8[0x0640 - 0x02C8];
    DynamicVectorClass<MultiMission *> Scenarios;   // +0x0640 (0xa25c08)
    char ScenarioFile[0x104];                   // +0x0658 (0xa25c20)
    char Unknown075C[0x085A - 0x075C];
    char Field85A[0x22];                        // +0x085a (0xa25e22, map digest?; meaning unknown)
    int Field87C;                               // +0x087c (0xa25e44, meaning unknown)
    bool Flag880;                               // +0x0880 (0xa25e48, meaning unknown)
    char Unknown0881[0x0884 - 0x0881];
    int Field884;                               // +0x0884 (0xa25e4c, meaning unknown)
    char Unknown0888[0x0894 - 0x0888];
    IPXAddressClass HostAddress;                // +0x0894 (0xa25e5c)
    char Unknown089E[0x2376 - 0x089E];
    wchar_t GameName[0x14];                     // +0x2376 (0xa2793e)
    GlobalPacketType GPacket;                   // +0x239e (0xa27966)
    char Unknown2565[0x256C - 0x2565];
    IPXAddressClass GAddress;                   // +0x256c (0xa27b34)
    char Unknown2576[0x27E0 - 0x2576];
    DynamicVectorClass<MPPlayerNode *> Players; // +0x27e0 (0xa27da8)
    int Field27F8;                              // +0x27f8 (0xa27dc0, meaning unknown)
    MPPlayerNode * Slots[8];                    // +0x27fc (0xa27dc4, meaning provisional)
    bool Flag281C;                              // +0x281c (0xa27de4, meaning unknown)
};
extern SessionClass Session;                    // 0xa255c8

#define IDC_CHAT_LIST           0x53F
#define IDC_LOBBY_LIST          0x5B5
#define IDC_SCENARIO_NAME       0x5A8
#define IDC_GAME_MODE_NAME      0x6EC
#define IDC_GAME_MODE_LIST      0x6EB
#define DLG_MAP_SELECTION       0x6B
#define IDC_MAP_LIST            0x553

// Custom messages of the game's owner-drawn controls (meanings provisional).
#define WM_SET_TEXT_WIDE        (WM_USER + 0xB2)
#define LB_SET_REDRAW           (WM_USER + 0x9D)
#define LB_ADDSTRING_WIDE       (WM_USER + 0xCD)
#define LB_SET_ITEM_COLOR       (WM_USER + 0x98)
#define LB_SET_DC               (WM_USER + 0x9E)
#define LB_HAS_SCROLLBAR        (WM_USER + 0xA0)

// ---- end of local declarations ----

void Add_Chat_Text(int color, wchar_t const * text, HWND list);
void Add_Chat_Line(HWND list, wchar_t const * text, int length, int color);
void Lobby_Add_Message(int color, wchar_t const * format, ...);
void Send_Public_Game_Options(char const * options);
int Scenario_Max_Players(int scenario);

// 0x5bd730
unsigned long Compute_CRC(CharStringClass & string)
{
    unsigned long crc = string.Get_Length();
    for (unsigned i = 0; i < string.Get_Length(); i++) {
        crc += ((char *)string)[i] + i;
        crc = (crc << 8) ^ (crc >> 24);
    }
    return crc;
}

// 0x5bd780
unsigned long Compute_CRC(WideStringClass const & string)
{
    unsigned long crc = string.Get_Length();
    for (unsigned i = 0; i < string.Get_Length(); i++) {
        crc += ((wchar_t const *)string)[i] + i;
        crc = (crc << 8) ^ (crc >> 24);
    }
    return crc;
}

// 0x5bd7d0
HWND Find_Network_Dialog()
{
    HWND dialog;
    if ((dialog = Find_Dialog(0xC2)) != NULL) return dialog;
    if ((dialog = Find_Dialog(0xC9)) != NULL) return dialog;
    if ((dialog = Find_Dialog(0xBC)) != NULL) return dialog;
    return Find_Dialog(0xBD);
}

// 0x5bd810
void Lobby_Add_Message(int color, wchar_t const * format, ...)
{
    wchar_t buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    va_list va;
    va_start(va, format);
    vswprintf(buffer, format, va);

    if (Current_Dialog()) {
        HWND dialog = Current_Dialog();
        HWND list;
        while ((list = GetDlgItem(dialog, IDC_CHAT_LIST)) == NULL) {
            dialog = Previous_Dialog(dialog);
            if (dialog == NULL) return;
        }
        Add_Chat_Text(color, buffer, list);
    }
}

// 0x5bd8a0
void Add_Lobby_Message(int color, wchar_t const * format, ...)
{
    wchar_t buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    va_list va;
    va_start(va, format);
    vswprintf(buffer, format, va);

    if (Current_Dialog()) {
        HWND dialog = Current_Dialog();
        HWND list;
        while ((list = GetDlgItem(dialog, IDC_LOBBY_LIST)) == NULL) {
            dialog = Previous_Dialog(dialog);
            if (dialog == NULL) return;
        }
        Add_Chat_Text(color, buffer, list);
    }
}

static wchar_t ChatLine[512];                   // 0xa59a28

// 0x5bdab0
void Add_Chat_Line(HWND list, wchar_t const * text, int length, int color)
{
    memset(ChatLine, 0, sizeof(ChatLine));
    wcsncpy(ChatLine, text, length);
    wchar_t * end = wcschr(ChatLine, L'\r');
    if (end == NULL) end = wcschr(ChatLine, L'\n');
    if (end != NULL) *end = 0;

    int redraw = SendMessageA(list, LB_SET_REDRAW, 0, 1);
    int count = SendMessageA(list, LB_GETCOUNT, 0, 0);
    if (count > 500) {
        SendMessageA(list, LB_DELETESTRING, 0, 0);
        count--;
    }
    int index = SendMessageA(list, LB_ADDSTRING_WIDE, 0, (LPARAM)ChatLine);
    if (color != -1) {
        SendMessageA(list, LB_SET_ITEM_COLOR, index, color);
    }
    SendMessageA(list, LB_SETTOPINDEX, count, 0);
    SendMessageA(list, LB_SET_REDRAW, 0, redraw);
}

// Index of the last blank before length in text, -1 when none.
static inline int Find_Line_Break(wchar_t const * text, int length)
{
    for (int i = length - 1; i > 0; i--) {
        if (iswspace(text[i])) {
            return i;
        }
    }
    return -1;
}

// 0x5bd930
void Add_Chat_Text(int color, wchar_t const * text, HWND list)
{
    int length = wcslen(text);
    int margin = 18;
    RECT rect;
    Get_Child_Rect(list, &rect);
    if (SendMessageA(list, LB_HAS_SCROLLBAR, 0, 0)) {
        margin = 1;
    }
    HDC dc = GetDC(list);
    SendMessageA(list, LB_SET_DC, 0, (LPARAM)dc);

    while (length) {
        if (text != NULL) {
            wchar_t const * newline = wcschr(text, L'\n');
            if (newline != NULL) {
                int n = newline - text + 1;
                if (length >= n) {
                    length = n;
                }
            }
        }
        wchar_t * copy = _wcsdup(text);
        copy[length] = 0;
        int width;
        int height;
        TextFont->Get_Text_Size(copy, &width, &height, 0);
        free(copy);

        int avail = rect.right - rect.left - margin;
        if (width >= avail - 4) {
            int step;
            if (width / 2 > avail) {
                step = 10;
                length -= 10;
            } else {
                step = 1;
            }
            int i = Find_Line_Break(text, length);
            if (i == -1) {
                length -= step;
            } else {
                length = i;
            }
        } else {
            Add_Chat_Line(list, text, length, color);
            text += length;
            while (*text == L' ') {
                text++;
            }
            length = wcslen(text);
        }
    }
    ReleaseDC(list, dc);
}



// 0x5bdc90
int Count_Teams(HouseClass * exclude)
{
    int count = 0;
    for (int i = 0; i < Houses.ActiveCount; i++) {
        HouseClass * house = Houses[i];
        if (house != NULL && !house->IsDefeated && house->Field134 && house != exclude) {
            bool found = false;
            for (int j = 0; j < Houses.ActiveCount; j++) {
                if (j != i) {
                    HouseClass * other = Houses[j];
                    if (other != NULL && !other->IsDefeated && other->Field134 && other != exclude
                        && house->Is_Ally(other) && other->Is_Ally(house)) {
                        if (j > i && !found) {
                            count++;
                        }
                        found = true;
                    }
                }
            }
            if (!found) {
                count++;
            }
        }
    }
    return count;
}

static BOOL CALLBACK Message_Box_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);

static inline void Show_Button(HWND dialog, int id)
{
    HWND button = GetDlgItem(dialog, id);
    SetWindowLongA(button, GWL_STYLE, GetWindowLongA(button, GWL_STYLE) | WS_VISIBLE);
}

// 0x5bdd70
int Message_Box(wchar_t const * text, int buttons, MessageCallback callback, bool flag)
{
    if (text == NULL || wcslen(text) == 0) {
        return 0;
    }
    int id;
    if (flag) {
        id = 0xFB;
    } else if (buttons == 0) {
        id = 0xD0;
    } else if (buttons == 1) {
        id = 0xFC;
    } else {
        id = (buttons == 4) ? 0x126 : 0xFB;
    }
    HWND dialog = Create_Modeless_Dialog(ProgramInstance, id, MainWindow, Message_Box_Proc, 0);
    Prepare_Dialog(dialog, id);
    if (buttons == 0) {
        HWND button = GetDlgItem(dialog, 1);
        SetWindowLongA(button, GWL_STYLE, GetWindowLongA(button, GWL_STYLE) | WS_VISIBLE);
        if (flag) {
            Set_Default_Button(button);
        }
    } else if (buttons == 1) {
        Show_Button(dialog, 1);
        Show_Button(dialog, 2);
    } else if (buttons == 4) {
        Show_Button(dialog, 6);
        Show_Button(dialog, 7);
    }
    HWND item = GetDlgItem(dialog, 0x5B0);
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)text);
    ShowWindow(dialog, SW_SHOWNORMAL);
    return Run_Dialog(dialog, callback, 0, 1, 1);
}

// 0x5bdee0
static BOOL CALLBACK Message_Box_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message) {
        case WM_ERASEBKGND:
            return TRUE;

        case WM_PAINT:
            Func_5F6B50(dialog);
            Func_5DE390(dialog);
            ValidateRect(dialog, NULL);
            return TRUE;

        case WM_DRAWITEM:
            Func_5F6060(lparam);
            return TRUE;

        case WM_COMMAND:
            switch (LOWORD(wparam)) {
                case 1:
                case 2:
                case 6:
                case 7:
                    Close_Dialog(dialog, LOWORD(wparam));
                    return TRUE;
            }
            break;
    }
    return FALSE;
}

// 0x5bdf90
void Show_Game_Mode_Name(HWND dialog, MultiplayerGameMode * mode)
{
    HWND item = GetDlgItem(dialog, IDC_GAME_MODE_NAME);
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)(wchar_t *)mode->Name);
}

// 0x5bdfc0
void Show_Scenario_Description(HWND dialog, int scenario)
{
    MultiMission * mission = Session.Scenarios[scenario];
    HWND item = GetDlgItem(dialog, IDC_SCENARIO_NAME);
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)mission->Description);
}

// 0x5bdff0
void Show_Scenario_Name(HWND dialog)
{
    HWND item = GetDlgItem(dialog, IDC_SCENARIO_NAME);
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)Session.Options.ScenarioName);
}

// 0x5be010
MultiplayerGameMode * Current_Game_Mode()
{
    MultiplayerGameMode * mode = Game_Mode_From_ID(Session.Options.GameMode);
    if (mode == NULL) {
        return Default_Game_Mode();
    }
    return mode;
}

// 0x5be030
void Update_Game_Mode_Dialog()
{
    if (Current_Dialog_ID() == DLG_MAP_SELECTION) {
        HWND dialog = Current_Dialog();
        int index = SendDlgItemMessageA(dialog, IDC_GAME_MODE_LIST, LB_GETCURSEL, 0, 0);
        if (index != -1) {
            MultiplayerGameMode * mode = (MultiplayerGameMode *)SendDlgItemMessageA(dialog, IDC_GAME_MODE_LIST, LB_GETITEMDATA, index, 0);
            if (mode != NULL) {
                mode->Update_Dialog();
            }
        }
    } else if (Session.GameMode != NULL) {
        Session.GameMode->Update_Dialog();
    }
}

// 0x5be090
void Update_Option_Controls(HWND dialog, int init)
{
    int unit_count = Session.Options.UnitCount;
    int credits = Session.Options.Credits;
    int speed = Session.Options.GameSpeed;
    if (init) {
        rc_ptr<WDTTerritory> territory;
        if (Session.Type == 4 && Session.Field00C == 2) {
            territory = Conflict_Territory(Session.TerritoryID);
        }
        if (territory.Get() != NULL) {
            EnableWindow(GetDlgItem(dialog, 0x544), FALSE);
            EnableWindow(GetDlgItem(dialog, 0x6D4), FALSE);
            if (!(territory->OptionFlags & 0x20000)) {
                EnableWindow(GetDlgItem(dialog, 0x402), FALSE);
            }
            if (!(territory->OptionFlags & 0x8000)) {
                EnableWindow(GetDlgItem(dialog, 0x54F), FALSE);
            }
            if (!(territory->OptionFlags & 0x400)) {
                EnableWindow(GetDlgItem(dialog, 0x54E), FALSE);
            }
            if (!(territory->OptionFlags & 0x20)) {
                EnableWindow(GetDlgItem(dialog, 0x3E8), FALSE);
            }
            if (!(territory->OptionFlags & 0x100)) {
                EnableWindow(GetDlgItem(dialog, 0x54D), FALSE);
            }
        }
        SendDlgItemMessageA(dialog, 0x529, TBM_SETRANGE, TRUE, MAKELONG(0, 6));
        SendDlgItemMessageA(dialog, 0x402, TBM_SETRANGE, TRUE, MAKELONG(Rule->MinCredits, Rule->MaxCredits));
        SendDlgItemMessageA(dialog, 0x402, WM_USER + 0xAB, 0, Rule->CreditStep);
        SendDlgItemMessageA(dialog, 0x54F, TBM_SETRANGE, TRUE, MAKELONG(Rule->MinUnitCount, Rule->MaxUnitCount));
    }
    SendDlgItemMessageA(dialog, 0x529, TBM_SETPOS, TRUE, 6 - speed);
    SendDlgItemMessageA(dialog, 0x402, TBM_SETPOS, TRUE, credits);
    SendDlgItemMessageA(dialog, 0x54F, TBM_SETPOS, TRUE, unit_count);
    int check[2] = {BST_UNCHECKED, BST_CHECKED};
    SendDlgItemMessageA(dialog, 0x54E, BM_SETCHECK, check[Session.Options.ShortGame], 0);
    SendDlgItemMessageA(dialog, 0x69A, BM_SETCHECK, check[Session.Options.SuperWeapons], 0);
    SendDlgItemMessageA(dialog, 0x69D, BM_SETCHECK, check[Session.Options.BuildOffAlly], 0);
    SendDlgItemMessageA(dialog, 0x3E8, BM_SETCHECK, check[Session.Options.MCVRedeploy], 0);
    SendDlgItemMessageA(dialog, 0x54D, BM_SETCHECK, check[Session.Options.Crates], 0);
}

// Last game options sent (initialised to "unknown").
static int SentGameSpeed = -1;                  // 0x7d11a4
static int SentCredits = -1;                    // 0x7d11a8
static int SentUnitCount = -1;                  // 0x7d11ac
static bool SentFlag880 = true;                 // 0x7d11b0
static int SentField87C = -1;                   // 0x7d11b4
static char SentScenarioFile[14];               // 0xa5a410
static char SentField85A[0x21];                 // 0xa5a420
static wchar_t SentScenarioName[44];            // 0xa5a808
static time_t SentTime;                         // 0xa5a8b4
static bool SendPending;                        // 0xa5a8b8
static bool SentShortGame;                      // 0xa5a8b9
static bool SentSuperWeapons;                   // 0xa5a8ba
static bool SentBuildOffAlly;                   // 0xa5a8bb
static bool SentMCVRedeploy;                    // 0xa5a8bc
static bool SentCrates;                         // 0xa5a8bd

// 0x5be350
void Update_Game_Options(bool force, bool now)
{
    bool changed = false;
    if (time(NULL) - SentTime == 0) {
        if (force) {
            SendPending = true;
        }
        if (!now) {
            return;
        }
    }
    if (SendPending) {
        force = true;
    }
    SendPending = false;
    if (WOLChat != NULL) {
        if (time(NULL) - SentTime >= 5) {
            changed = true;
        }
    } else {
        if (time(NULL) - SentTime >= 2) {
            changed = true;
        }
    }
    if (force) changed = true;
    if (SentGameSpeed != Session.Options.GameSpeed) changed = true;
    if (SentCredits != Session.Options.Credits) changed = true;
    if (SentUnitCount != Session.Options.UnitCount) changed = true;
    if (SentShortGame != Session.Options.ShortGame) changed = true;
    if (SentSuperWeapons != Session.Options.SuperWeapons) changed = true;
    if (SentBuildOffAlly != Session.Options.BuildOffAlly) changed = true;
    if (SentMCVRedeploy != Session.Options.MCVRedeploy) changed = true;
    if (SentCrates != Session.Options.Crates) changed = true;
    SentScenarioName[43] = 0;
    if (_wcsicmp(SentScenarioName, Session.Options.ScenarioName) != 0) changed = true;
    SentScenarioFile[13] = 0;
    if (_stricmp(SentScenarioFile, Session.ScenarioFile) != 0) changed = true;
    SentField85A[32] = 0;
    if (_stricmp(SentField85A, Session.Field85A) != 0) changed = true;
    if (SentField87C != Session.Field87C) changed = true;
    if (SentFlag880 == Session.Flag880 && !changed) {
        return;
    }

    SentTime = time(NULL);
    SentGameSpeed = Session.Options.GameSpeed;
    SentCredits = Session.Options.Credits;
    SentUnitCount = Session.Options.UnitCount;
    SentShortGame = Session.Options.ShortGame;
    SentSuperWeapons = Session.Options.SuperWeapons;
    SentBuildOffAlly = Session.Options.BuildOffAlly;
    SentMCVRedeploy = Session.Options.MCVRedeploy;
    SentCrates = Session.Options.Crates;
    wcscpy(SentScenarioName, Session.Options.ScenarioName);
    strcpy(SentField85A, Session.Field85A);
    strcpy(SentScenarioFile, Session.ScenarioFile);
    SentField87C = Session.Field87C;
    SentFlag880 = Session.Flag880;

    char buffer[0x208];
    memset(buffer, 0, sizeof(buffer));
    if (WOLChat != NULL) {
        WOL_Build_Options_String(buffer);
        Send_Public_Game_Options(buffer);
    } else {
        Build_Options_String(buffer);
        Send_Public_Game_Options(buffer);
    }
}

// 0x5be620
void Send_Lobby_Leave()
{
    GlobalPacketType packet;
    memset(&packet, 0, sizeof(packet));
    packet.Command = NET_LOBBY_LEAVE;
    strcpy(packet.Name, Session.Handle);
    int count = Session.Players.ActiveCount;
    for (int i = 1; i < count; i++) {
        Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Players[i]->Address);
        Call_Back();
    }
}

// 0x5be6b0
void Leave_Lobby()
{
    switch (Session.Type) {
        case 3:
            Send_Lobby_Leave();
            break;
        case 4:
            WOL_Func_74A150();
            break;
    }
}

// 0x5be760
void Set_Flag281C()
{
    Session.Flag281C = true;
    if (WOLChat != NULL) {
        Wol_Handle_Start_Reminder();
    } else {
        Host_Update_Start_Button();
    }
}

// 0x5be780
void Clear_Flag281C()
{
    Session.Flag281C = false;
    if (WOLChat != NULL) {
        WOL_Func_74A1F0();
    } else {
        Host_Clear_Start_Button();
    }
}

// 0x5be7a0
void Send_Public_Game_Options(char const * options)
{
    if (WOLChat != NULL) {
        char buffer[1024];
        strncpy(buffer, options, sizeof(buffer) - 1);
        WOLChat->Request_Public_Message(buffer);
        return;
    }

    GlobalPacketType packet;
    memset(&packet, 0, sizeof(packet));
    packet.Command = NET_GAME_OPTIONS;
    strcpy(packet.Name, Session.Handle);
    strcpy(packet.Text, options);
    packet.UniqueID = Session.UniqueID;
    packet.NameCRC = Compute_Name_CRC(Session.GameName);
    for (int i = 1; i < Session.Players.ActiveCount; i++) {
        MPPlayerNode * node = Session.Players[i];
        Debug_Printf("Sending public game options to %s\n", To_Narrow(node->Name));
        Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &node->Address);
        Call_Back();
    }
}

// 0x5be8d0
void Send_Private_Game_Options(char const * name, char const * options)
{
    if (WOLChat != NULL) {
        WOLUserType user;
        memset(&user, 0, sizeof(user));
        strcpy(user.Name, name);
        WOLChat->Request_Private_Message(&user, options);
        return;
    }

    GlobalPacketType packet;
    memset(&packet, 0, sizeof(packet));
    packet.Command = NET_PRIVATE_GAME_OPTIONS;
    strcpy(packet.Name, Session.Handle);
    strcpy(packet.Text, options);
    Session.GPacket.UniqueID = Session.Func_668C80();
    Session.GPacket.NameCRC = Compute_Name_CRC(Session.GameName);
    for (int i = 1; i < Session.Players.ActiveCount; i++) {
        if (_stricmp(To_Narrow(Session.Players[i]->Name), name) == 0) {
            Debug_Printf("Sending private game options to %ls\n", Session.Players[i]->Name);
            Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.Players[i]->Address);
            Call_Back();
        }
    }
}

static inline int Find_Player(char const * name)
{
    for (int i = 0; i < Session.Players.ActiveCount; i++) {
        if (_stricmp(To_Narrow(Session.Players[i]->Name), name) == 0) {
            return i;
        }
    }
    return -1;
}

// 0x5bea40
void Set_Player_Has_Scenario(char const * name, int has_scenario)
{
    if (name == NULL) {
        name = Session.Handle;
    }
    if (wcscmp(To_Wide(name), Session.GameName) == 0) {
        has_scenario = 1;
    }
    int index = Find_Player(name);
    if (index != -1) {
        Session.Players[index]->HasScenario = has_scenario;
        if (!has_scenario) {
#line 1088 "C:\\RA2\\netshare.cpp"
            Lobby_Add_Message(-1, Fetch_String("GUI:HostNoMap", NULL, __FILE__, __LINE__), Session.Players[index]->Name, Session.Options.ScenarioName);
        }
    }
}

// 0x5c0600
int Session_Max_Players()
{
    if (Session.Type == 4) {
        if (Is_Tournament_Server() && !Is_Tournament_Game()) {
            return 2;
        }
        return 4;
    }
    return 8;
}

// 0x5c0630
int Max_Players(int scenario)
{
    if (scenario == -1) {
        return 8;
    }
    int max = Scenario_Max_Players(scenario);
    if (Session.GameMode != NULL) {
        int mode_max = Session.GameMode->Max_Players();
        if (mode_max != -1 && mode_max < max) {
            max = mode_max;
        }
    }
    if (Session.Type == 4) {
        if (Is_Tournament_Game()) {
            max &= ~1;
        } else if (Is_Tournament_Server()) {
            max = 2;
        }
    }
    return max;
}

// 0x5c0690
int Scenario_Max_Players(int scenario)
{
    if (scenario < 0 || scenario >= Session.Scenarios.ActiveCount) {
        return 0;
    }
    char filename[132];
    strcpy(filename, Session.Scenarios[scenario]->FileName);
    CCFileClass file(filename);
    INIClass ini;
    if (!ini.Load(file, false)) {
        return 0;
    }
    int count = 0;
    for (int index = 0; index < 8; index++) {
        char buffer[32];
        sprintf(buffer, "%d", index);
        if (ini.Get_Int("Waypoints", buffer, -1) != -1) {
            count++;
        }
    }
    if (count == 0) {
        count = ini.Get_Int("RandomMap", "NumPlayers", 0);
    }
    return count;
}

static HWND MapDialog;                          // 0xa5a460 (name provisional)

// 0x5c0830
int Map_Dialog_Selection()
{
    return SendDlgItemMessageA(MapDialog, IDC_MAP_LIST, LB_GETCURSEL, 0, 0);
}

static int MapDialogScenario;                   // 0xa5a450 (name provisional)
static wchar_t MapDialogDescription[0x2C];      // 0xa5a5e8 (name provisional)
static int MapDialogStartScenario;              // 0xa5a7f8 (name provisional)
void Update_Map_Preview(HWND dialog);
bool Set_Scenario(int scenario);

static inline int Scenario_Index(MultiMission * mission)
{
    for (int i = 0; i < Session.Scenarios.ActiveCount; i++) {
        if (mission == Session.Scenarios[i]) {
            return i;
        }
    }
    return -1;
}

// 0x5c0850
bool Map_Dialog_Callback()
{
    int index = SendDlgItemMessageA(MapDialog, IDC_MAP_LIST, LB_GETCURSEL, 0, 0);
    if (index != -1) {
        MultiMission * mission = (MultiMission *)SendDlgItemMessageA(MapDialog, IDC_MAP_LIST, LB_GETITEMDATA, index, 0);
        int scenario = Scenario_Index(mission);
        if (scenario != -1 && scenario != MapDialogScenario) {
            Set_Scenario(scenario);
            if (Session.Scenarios[scenario]->Is_Random_Map()) {
                delete MapPreview;
                MapPreview = new MapPreviewClass;
                MapPreview->Load("RandMap.img");
                if (MapPreview->Image == NULL) {
                    Update_Map_Preview(MapDialog);
                }
                InvalidateRect(MapDialog, NULL, FALSE);
            } else {
                Update_Map_Preview(MapDialog);
            }
            MapDialogScenario = scenario;
            Session.Options.Scenario = MapDialogStartScenario;
            Set_Scenario(Session.Options.Scenario);
        }
    }

    HWND dialog = MapDialog;
    index = SendDlgItemMessageA(dialog, IDC_MAP_LIST, LB_GETCURSEL, 0, 0);
    MultiMission * mission;
    if (index != -1 && (mission = (MultiMission *)SendDlgItemMessageA(dialog, IDC_MAP_LIST, LB_GETITEMDATA, index, 0)) != NULL) {
        wcscpy(MapDialogDescription, mission->Description);
    } else {
        MapDialogDescription[0] = 0;
    }

    if (Session.Type == 3) {
        return Net_Service_Callback();
    }
    if (Session.Type == 4) {
        return Func_732A40();
    }
    if (Session.Type == 1 || Session.Type == 2) {
        return ModemHostDialogClass::Message_Callback();
    }
    Call_Back();
    return false;
}

BOOL CALLBACK Map_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);    // 0x5c0a70 (not yet reconstructed)

// 0x5c09f0
int Map_Selection_Dialog(HWND parent)
{
    Func_514F50(0, true);
    MapDialog = Create_Modeless_Dialog(ProgramInstance, DLG_MAP_SELECTION, parent, Map_Dialog_Proc, 0);
    Prepare_Dialog(MapDialog, DLG_MAP_SELECTION);
    SendMessageA(MapDialog, WM_USER + 0xA9, 0, 1);
    ShowWindow(MapDialog, SW_SHOWNORMAL);
    return Run_Dialog(MapDialog, Map_Dialog_Callback, 0, 1, 1);
}

// 0x5c11f0
int Select_Map_By_Data(HWND dialog, int data)
{
    if (data == 0) {
        return -1;
    }
    int index = 0;
    int count = SendDlgItemMessageA(dialog, IDC_MAP_LIST, LB_GETCOUNT, 0, 0);
    for (int i = 0; i < count; i++) {
        if (SendDlgItemMessageA(dialog, IDC_MAP_LIST, LB_GETITEMDATA, i, 0) == data) {
            index = i;
        }
    }
    SendDlgItemMessageA(dialog, IDC_MAP_LIST, LB_SETCURSEL, index, 0);
    SendDlgItemMessageA(dialog, IDC_MAP_LIST, LB_SETTOPINDEX, index, 0);
    return index;
}

// 0x5c1940
void Download_Map_Preview()
{
    char filename[260];
    GlobalPacketType packet;

    Ipx.Set_Timing(50, (unsigned long)-1, 5000, true);
    Debug_Printf("Starting map preview download\n");
    memset(&packet, 0, sizeof(packet));
    packet.Command = NET_PREVIEW_ACK;
    Debug_Printf("Sending preview mode acks\n");
    while (!Ipx.Send_Global_Message(&packet, sizeof(packet), 1, &Session.HostAddress)) {
        Call_Back();
    }
    while (Ipx.Global_Num_Send()) {
        Call_Back();
    }
    Debug_Printf("Preview mode acks sent\n");
    Session.GAddress = Session.HostAddress;

    Debug_Printf("Calling Get_File_From_Host to receive the file download\n");
    if (!Get_File_From_Host(filename, 3, 0)) {
        Debug_Printf("got_file is false. Download failed\n");
        Ipx.Set_Timing(30, (unsigned long)-1, 600, true);
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
    if (MapPreview) {
        delete MapPreview;
    }
    MapPreview = new MapPreviewClass;
    MapPreview->Set_Image(image);
    InvalidateRect(Current_Dialog(), NULL, FALSE);

    Debug_Printf("Cleaning up the temporary decompression buffers\n");
    delete [] image;
    delete [] buffer;
    Ipx.Set_Timing(30, (unsigned long)-1, 600, true);
}

// 0x5c1bd0
bool Set_Scenario(int index)
{
    if (index == -1) {
        Session.Field87C = 0;
        Session.Flag880 = false;
        Session.Field884 = 0;
        Session.Options.ScenarioName[0] = 0;
        Session.ScenarioFile[0] = Session.Field85A[0] = 0;
        return false;
    }
    bool missing = !CCFileClass(Session.Scenarios[index]->FileName).Is_Available();
    if (missing) {
        if (RequiredCD != -2) {
            if (!Session.Scenarios[index]->Func_6681B0(Func_46E0C0(60))) {
                if (!CD().Force_Available(Session.Scenarios[index]->Func_668240())) {
                    return false;
                }
            }
        } else {
#line 2905 "C:\\RA2\\netshare.cpp"
            WWMessageBox().Process(Fetch_String("TXT_UNABLE_READ_SCENARIO", NULL, __FILE__, __LINE__), Fetch_String("TXT_OK", NULL, __FILE__, __LINE__));
            return false;
        }
    }
    wcscpy(Session.Options.ScenarioName, Session.Scenarios[index]->Description);
    strcpy(Session.Field85A, Session.Scenarios[index]->Digest);
    strcpy(Session.ScenarioFile, Session.Scenarios[index]->FileName);
    strcpy(Scen->ScenarioName, Session.ScenarioFile);
    Session.Flag880 = Session.Scenarios[index]->IsOfficial;
    Session.Field884 = Max_Players(index);
    Session.Field87C = CCFileClass(Session.ScenarioFile).Size();
    Session.Field87C = CCFileClass(Session.ScenarioFile).Size();
    return true;
}

// 0x5c1550
void Setup_Network_Game()
{
    Scen->ScenarioIndex = Session.Options.Scenario;
    NetworkEventMode = 0;
    Session.NumPlayers = Session.Players.ActiveCount;
    Debug_Printf("Pregame setup for %d players.\n", Session.Players.ActiveCount);
    Options.GameSpeed = Session.Options.GameSpeed;
    Session.Version = 2;
    Special.Bit6 = true;
    Special.Bit7 = true;
    Special.IsHarvesterTruce = Session.Options.HarvesterTruce;
    Special.IsBridgeDestruction = Session.Options.BridgeDestruction;
    Special.Func_680B10();
}

// Westwood checksum: rotate left by one and add the next (little endian) long.
// 0xCRC
static inline unsigned long Calculate_CRC(void const * buffer, int length)
{
    unsigned long crc = 0;
    long const * ptr = (long const *)buffer;
    while (length > 0) {
        unsigned long carry = crc >> 31;
        long value;
        if (length >= 4) {
            value = *ptr++;
            length -= 4;
        } else {
            value = 0;
            unsigned char const * bytes = (unsigned char const *)ptr;
            for (int i = length; i > 0; i--) {
                value = (value << 8) | *bytes++;
            }
            length = 0;
        }
        crc = value + (crc << 1) + carry;
    }
    return crc;
}

// Not expanded inline in Select_Random_Map in the original.
#pragma auto_inline(off)
// 0x5c22e0
char * Random_Map_Digest()
{
    char filename[0x100];
    memcpy(filename, RandomMap.Params.FileName, sizeof(filename));
    memset(RandomMap.Params.FileName, 0, sizeof(RandomMap.Params.FileName));
    unsigned long crc = Calculate_CRC(&RandomMap.Params, sizeof(RandomMap.Params));
    char * digest = new char[12];
    sprintf(digest, "%08X", crc);
    memcpy(RandomMap.Params.FileName, filename, sizeof(filename));
    return digest;
}
#pragma auto_inline(on)

// 0x5c2520
int Is_Game_Name(wchar_t const * name)
{
    return !wcscmp(name, Session.GameName);
}

// 0x5c2540
int Is_Game_Host(int index)
{
    return !wcscmp(Session.Players[index]->Name, Session.GameName);
}

// 0x5c2560
int Is_Hosting()
{
    wchar_t * name = To_Wide(Session.Handle);
    return !wcscmp(name, Session.GameName);
}

// 0x5c2580
int Is_Me(wchar_t const * name)
{
    return !wcscmp(name, To_Wide(Session.Handle));
}

// Place holder nodes of the player slots (names from the strings at 0x7d11c8).
static MPPlayerNode * OpenNode;                 // 0xa5a89c "@Open@"
static MPPlayerNode * ClosedNode;               // 0xa5a8a0 "@Closed@"
static MPPlayerNode * EasyAINode;               // 0xa5a8a4 "@EasyAI@"
static MPPlayerNode * MediumAINode;             // 0xa5a8a8 "@MediumAI@"
static MPPlayerNode * HardAINode;               // 0xa5a8ac "@HardAI@"
static MPPlayerNode * WaitingNode;              // 0xa5a8b0 "@Waiting@"

// 0x5c27c0
void Free_Slot_Nodes()
{
    if (OpenNode != NULL) {
        delete OpenNode;
        OpenNode = NULL;
    }
    if (ClosedNode != NULL) {
        delete ClosedNode;
        ClosedNode = NULL;
    }
    if (EasyAINode != NULL) {
        delete EasyAINode;
        EasyAINode = NULL;
    }
    if (MediumAINode != NULL) {
        delete MediumAINode;
        MediumAINode = NULL;
    }
    if (HardAINode != NULL) {
        delete HardAINode;
        HardAINode = NULL;
    }
    if (WaitingNode != NULL) {
        delete WaitingNode;
        WaitingNode = NULL;
    }
    Delete_All(Session.Players);
}

static inline void Init_Slot_Nodes()
{
    int max = Session_Max_Players();
    int i;
    for (i = 0; i < max; i++) {
        Session.Slots[i] = OpenNode;
    }
    for (i = max; i < 8; i++) {
        Session.Slots[i] = ClosedNode;
    }
}



static char LobbyText1[0x24];                   // 0xa5a230 (meaning unknown)
static char LobbyText2[0x24];                   // 0xa5a254 (meaning unknown)
static char LobbyText3[0x24];                   // 0xa5a278 (meaning unknown)
static char LobbyText4[0x24];                   // 0xa5a5c4 (meaning unknown)

// 0x5c28c0
void Clear_Lobby_Texts()
{
    LobbyText1[0] = 0;
    LobbyText2[0] = 0;
    LobbyText4[0] = 0;
    LobbyText3[0] = 0;
}

static wchar_t LobbyWide1[0x20];                // 0xa5a2b4 (meaning unknown)
static wchar_t LobbyWide2[0x20];                // 0xa5a464 (meaning unknown)

// 0x5c28e0
void Reset_Game_Slots()
{
    Init_Slot_Nodes();
    Session.Field27F8 = -1;
    Session.Options.Clear_AI_Players();
    LobbyWide2[0] = 0;
    LobbyWide1[0] = 0;
}

// 0x5c2970
MPPlayerNode * Find_Node(wchar_t const * name)
{
    if (!wcscmp((wchar_t *)OpenNode, name)) return OpenNode;
    if (!wcscmp((wchar_t *)ClosedNode, name)) return ClosedNode;
    if (!wcscmp((wchar_t *)EasyAINode, name)) return EasyAINode;
    if (!wcscmp((wchar_t *)MediumAINode, name)) return MediumAINode;
    if (!wcscmp((wchar_t *)HardAINode, name)) return HardAINode;
    if (!wcscmp((wchar_t *)WaitingNode, name)) return WaitingNode;
    int count = Session.Players.ActiveCount;
    for (int i = 0; i < count; i++) {
        MPPlayerNode * node = Session.Players[i];
        if (!wcscmp(node->Name, name)) {
            return node;
        }
    }
    return NULL;
}

// 0x5c2a60
int Find_Slot(wchar_t const * name)
{
    for (int i = 0; i < 8; i++) {
        MPPlayerNode * node = Session.Slots[i];
        if (!_wcsicmp(name, node->Name)) {
            return i;
        }
    }
    return -1;
}

// 0x5c2aa0
int Find_Host_Slot()
{
    if (Session.Players.ActiveCount == 0) {
        return -1;
    }
    return Find_Slot(Session.Players[0]->Name);
}

// 0x5c2af0
void Set_Slot(int slot, MPPlayerNode * node)
{
    Session.Slots[slot] = node;
}

// 0x5c2b00
void Set_Host_Slot(int slot)
{
    Session.Field27F8 = slot;
    Session.Slots[slot] = Session.Players[0];
}

// Slot tags of the player slot list text (0x7d11c8).
static char * SlotTags[6] = {
    "@Open@",
    "@Closed@",
    "@Waiting@",
    "@EasyAI@",
    "@MediumAI@",
    "@HardAI@"
};

// 0x5c2da0
int Is_Real_Player(MPPlayerNode * node)
{
    if (node == NULL || node == OpenNode || node == ClosedNode || node == WaitingNode
        || node == EasyAINode || node == MediumAINode || node == HardAINode) {
        return 0;
    }
    return 1;
}

CharStringClass Slot_Tag(MPPlayerNode * node);
MPPlayerNode * Slot_Tag_Node(WideStringClass const & tag);

// 0x5c2b20
void Build_Player_Text(wchar_t * buffer)
{
    buffer[0] = 0;
    for (int i = 0; i < 8; i++) {
        MPPlayerNode * node = Session.Slots[i];
        WideStringClass name;
        if (Is_Real_Player(node)) {
            name = node->Name;
        } else {
            CharStringClass tag = Slot_Tag(node);
            name = To_WideString(tag);
        }
        wcscat(buffer, (WideStringClass const &)name);  // level-2 1.001: the const conversion (0x75bd30) is called
        wcscat(buffer, L",");
    }
}

// 0x5c2bf0
void Parse_Player_Text(wchar_t const * text)
{
    if (text[0] == 0) {
        return;
    }
    wchar_t buffer[170];
    wcscpy(buffer, text);
    Init_Slot_Nodes();
    wchar_t * token = wcstok(buffer, L",");
    int i = 0;
    while (token != NULL) {
        MPPlayerNode * node;
        {
            WideStringClass tag(token);
            node = Slot_Tag_Node(tag);
        }
        if (node == NULL) {
            node = Find_Node(token);
            if (node == NULL) {
                node = WaitingNode;
            }
        }
        Session.Slots[i++] = node;
        token = wcstok(NULL, L",");
    }
}

// 0x5c2cf0
int Add_To_Open_Slot(MPPlayerNode * node)
{
    for (int i = 0; i < 8; i++) {
        if (Session.Slots[i] == OpenNode) {
            Session.Slots[i] = node;
            return i;
        }
    }
    return -1;
}

// 0x5c2d20
void Remove_From_Slot(IPXAddressClass & address)
{
    int max = Session_Max_Players();
    for (int i = 0; i < 8; i++) {
        MPPlayerNode * node = Session.Slots[i];
        if (node->Address == address) {
            Session.Slots[i] = (i < max) ? OpenNode : ClosedNode;
            return;
        }
    }
}

// 0x5c2de0
int Is_AI_Node(MPPlayerNode * node)
{
    if (node != NULL && (node == EasyAINode || node == MediumAINode || node == HardAINode)) {
        return 1;
    }
    return 0;
}

// The same test with a bool result (inlined into Set_Slot_Node).
static inline bool Is_AI(MPPlayerNode * node)
{
    if (node != NULL && (node == EasyAINode || node == MediumAINode || node == HardAINode)) {
        return true;
    }
    return false;
}

// 0x5c2e10
int Is_Occupied(MPPlayerNode * node)
{
    if (node == NULL || node == OpenNode || node == ClosedNode || node == WaitingNode) {
        return 0;
    }
    return 1;
}

// 0x5c2e40
int AI_Node_Difficulty(MPPlayerNode * node)
{
    int difficulty = -1;
    if (node == EasyAINode) {
        return 2;
    }
    if (node == MediumAINode) {
        return 1;
    }
    if (node == HardAINode) {
        difficulty = 0;
    }
    return difficulty;
}

// 0x5c59d0
CharStringClass Slot_Tag(MPPlayerNode * node)
{
    if (node == OpenNode) return CharStringClass(SlotTags[0]);
    if (node == ClosedNode) return CharStringClass(SlotTags[1]);
    if (node == WaitingNode) return CharStringClass(SlotTags[2]);
    if (node == EasyAINode) return CharStringClass(SlotTags[3]);
    if (node == MediumAINode) return CharStringClass(SlotTags[4]);
    if (node == HardAINode) return CharStringClass(SlotTags[5]);
    return CharStringClass(SlotTags[2]);
}

// 0x5c5a80
MPPlayerNode * Slot_Tag_Node(WideStringClass const & tag)
{
    if (tag.Is_ANSI()) {
        CharStringClass name = To_CharString(tag);
        if (name == SlotTags[0]) return OpenNode;
        if (name == SlotTags[1]) return ClosedNode;
        if (name == SlotTags[2]) return WaitingNode;
        if (name == SlotTags[3]) return EasyAINode;
        if (name == SlotTags[4]) return MediumAINode;
        if (name == SlotTags[5]) return HardAINode;
    }
    return NULL;
}

// 0x5c5ba0
int Is_Slot_Tag(CharStringClass const & name)
{
    if (name == SlotTags[0] || name == SlotTags[1] || name == SlotTags[2]
        || name == SlotTags[3] || name == SlotTags[4] || name == SlotTags[5]) {
        return 1;
    }
    return 0;
}

// 0x5c2e70
int Count_AI_Slots()
{
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (Is_AI_Node(Session.Slots[i])) {
            count++;
        }
    }
    return count;
}

// 0x5c2eb0
bool Is_Game_Full()
{
    int max = (Session.MaxPlayers < Session.Field884) ? Session.MaxPlayers : Session.Field884;
    if (Session.Players.ActiveCount < max) {
        for (int i = 0; i < max; i++) {
            if (Session.Slots[i] == OpenNode) {
                return false;
            }
        }
    }
    return true;
}

// 0x5c2ef0
bool Too_Many_Players()
{
    int max = (Session.MaxPlayers < Session.Field884) ? Session.MaxPlayers : Session.Field884;
    if (Session.Players.ActiveCount > max) {
        return true;
    }
    return false;
}

// 0x5c2f10
bool Is_Color_Used(int color)
{
    if (color != -2) {
        int i;
        for (i = 0; i < 8; i++) {
            MPPlayerNode * node = Session.Slots[i];
            if (Is_Real_Player(node) && node->Color() == color) {
                return true;
            }
        }
        for (i = 0; i < 8; i++) {
            if (Session.Options.Color[i] == color) {
                return true;
            }
        }
    }
    return false;
}

// 0x5c2f90
int Slot_Node_Type(MPPlayerNode * node)
{
    if (node == OpenNode) return 2;
    if (node == ClosedNode) return 3;
    if (node == EasyAINode) return 4;
    if (node == MediumAINode) return 5;
    return (node == HardAINode) ? 6 : 2;
}

// 0x5c2fe0
MPPlayerNode * Slot_Type_Node(int type)
{
    if (type == 2) return OpenNode;
    if (type == 3) return ClosedNode;
    if (type == 4) return EasyAINode;
    if (type == 5) return MediumAINode;
    return (type == 6) ? HardAINode : NULL;
}

// 0x5c3020
void Clear_Accept_States()
{
    if (Current_Dialog_ID() != 0xBC) {
        EnableWindow(GetDlgItem(Find_Network_Dialog(), 0x59F), TRUE);
    }
    int count = Session.Players.ActiveCount;
    for (int i = 0; i < count; i++) {
        if (wcscmp(Session.Players[i]->Name, Session.GameName) != 0) {
            MPPlayerNode * node = Session.Players[i];
            if (node->AcceptState) {
                node->AcceptState = 0;
            }
        }
    }
}

// 0x5c30c0
int Slot_Control_ID(int slot)
{
    if (slot == 0) return 0x411;
    if (slot == 1) return 0x412;
    if (slot == 2) return 0x413;
    if (slot == 3) return 0x414;
    if (slot == 4) return 0x415;
    if (slot == 5) return 0x416;
    if (slot == 6) return 0x417;
    return (slot == 7) ? 0x418 : -1;
}

// 0x5c3120
int Slot_Control_Index(int id)
{
    if (id == 0x411) return 0;
    if (id == 0x412) return 1;
    if (id == 0x413) return 2;
    if (id == 0x414) return 3;
    if (id == 0x415) return 4;
    if (id == 0x416) return 5;
    if (id == 0x417) return 6;
    return (id == 0x418) ? 7 : -1;
}

// 0x5c3190
wchar_t const * Slot_Node_Name(MPPlayerNode * node)
{
    if (node == OpenNode) {
#line 3931 "C:\\RA2\\netshare.cpp"
        return Fetch_String("STT:PlayerOpen", NULL, __FILE__, __LINE__);
    } else if (node == ClosedNode) {
        return Fetch_String("STT:PlayerClosed", NULL, __FILE__, __LINE__);
    } else if (node == EasyAINode) {
        return Fetch_String("STT:PlayerDumbAI", NULL, __FILE__, __LINE__);
    } else if (node == MediumAINode) {
        return Fetch_String("STT:PlayerSmartAI", NULL, __FILE__, __LINE__);
    } else if (node == HardAINode) {
        return Fetch_String("STT:PlayerGeniusAI", NULL, __FILE__, __LINE__);
    }
    return Fetch_String("STT:PlayerHuman", NULL, __FILE__, __LINE__);
}

// 0x5c3250
void Select_Combo_Data(HWND dialog, int id, int data)
{
    HWND combo = GetDlgItem(dialog, id);
    ShowWindow(combo, SW_HIDE);
    int count = SendDlgItemMessageA(dialog, id, CB_GETCOUNT, 0, 0);
    for (int i = 0; i < count; i++) {
        if (SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, i, 0) == data) {
            SendDlgItemMessageA(dialog, id, CB_SETCURSEL, i, 0);
            break;
        }
    }
    ShowWindow(combo, SW_SHOW);
}

// 0x5c32d0
int Get_Combo_Data(HWND dialog, int id, int index)
{
    if (index == -1) {
        index = SendDlgItemMessageA(dialog, id, CB_GETCURSEL, 0, 0);
    }
    return SendDlgItemMessageA(dialog, id, CB_GETITEMDATA, index, 0);
}

// 0x5c3310
void Slot_Side_Changed(HWND dialog, int id)
{
    int side = Get_Side_Data(dialog, id, -1);
    int slot = Player_Side_Slot(id);
    if (slot == Session.Field27F8) {
        Session.Set_Side_Choice(side, false);
        Session.Players[0]->Set_Side(side);
    } else {
        Session.Options.Side[slot] = side;
    }
}

// 0x5c3360
void Slot_Color_Changed(HWND dialog, int id)
{
    int color = Get_Color_Data(dialog, id, -1);
    int slot = Player_Color_Slot(id);
    if (slot == Session.Field27F8) {
        Color_Changed(dialog, id);
        if (Is_Color_Used(color)) {
            color = -2;
        }
        Session.Set_Color_Choice(color, false);
        Session.Players[0]->Set_Color(color);
    } else {
        Session.Options.Color[slot] = color;
    }
}

// 0x5c3430
void Enable_Slot_Controls(HWND dialog, int slot, bool enable)
{
    int side = Player_Side_ID(slot);
    int color = Player_Color_ID(slot);
    if (!enable) {
        Select_Side(dialog, side, -2);
        Select_Color(dialog, color, -2);
    }
    HWND window = GetDlgItem(dialog, side);
    EnableWindow(window, enable);
    window = GetDlgItem(dialog, color);
    EnableWindow(window, enable);
}

// 0x5c34a0
void Reset_Slot_Controls(HWND dialog, int slot)
{
    for (int i = 0; i < 8; i++) {
        HWND window = GetDlgItem(dialog, Slot_Control_ID(i));
        EnableWindow(window, TRUE);
        Enable_Slot_Controls(dialog, i, false);
    }
    Enable_Slot_Controls(dialog, slot, true);
}

// 0x5c3c50
int Is_Slot_Ready(int slot)
{
    MPPlayerNode * node = Session.Slots[slot];
    int ready = 0;
    if (Is_AI_Node(node) || node->AcceptState == 1) {
        ready = 1;
    }
    return ready;
}

// 0x5c3c90
int Slot_Side(int slot)
{
    int side = -2;
    MPPlayerNode * node = Session.Slots[slot];
    if (Session.GameMode != NULL && (Session.Type == 3 || Session.Type == 4)) {
        side = Session.GameMode->Fixed_Side();
    }
    if (Is_AI_Node(node)) {
        return Session.Options.Side[slot];
    }
    if (node != OpenNode && node != ClosedNode && node != WaitingNode) {
        side = node->Side();
    }
    return side;
}

// 0x5c3d10
int Slot_Color(int slot)
{
    MPPlayerNode * node = Session.Slots[slot];
    if (Is_AI_Node(node)) {
        return Session.Options.Color[slot];
    }
    if (node != OpenNode && node != ClosedNode && node != WaitingNode) {
        return node->Color();
    }
    return -2;
}

// 0x5c3d60
int Slot_Name_Control_ID(int slot)
{
    if (slot == 0) return 0x6D2;
    if (slot == 1) return 0x6D3;
    if (slot == 2) return 0x6D4;
    if (slot == 3) return 0x6D5;
    if (slot == 4) return 0x6D6;
    if (slot == 5) return 0x6D7;
    if (slot == 6) return 0x6D8;
    return (slot == 7) ? 0x6D9 : -1;
}

// 0x5c5140
void Update_Scenario_Preview(HWND dialog)
{
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
}

// 0x5c5850
WideStringClass Get_Name_Text(HWND window)
{
    WideStringClass text;
    Window_Get_Text(window, text);
    unsigned max = 120;
    if (!text.Is_ANSI()) {
        for (max = 0; max < text.Get_Length(); max++) {
            if (text[max] > 0x100) {
                break;
            }
        }
        max--;
        if (max <= 40) {
            max = 40;
        }
    }
    if (text.Get_Length() > max) {
        text.Truncate(max);
        SendMessageA(window, WM_SET_TEXT_WIDE, 0, (LPARAM)(wchar_t *)text);
    }
    {
        WideStringClass characters(L"\n\r");
        text.Trim_Right(characters);
    }
    return text;
}

// 0x5c5930
void Enable_Host_Controls(HWND dialog, bool enable)
{
    if (dialog != NULL) {
        int slot = Find_Host_Slot();
        HWND window = GetDlgItem(dialog, Player_Side_ID(slot));
        if (window != NULL) {
            EnableWindow(window, enable);
        }
        window = GetDlgItem(dialog, Player_Color_ID(slot));
        if (window != NULL) {
            EnableWindow(window, enable);
        }
    }
}

// 0x5c35b0
void Lock_Slot_Controls(HWND dialog, int slot)
{
    for (int i = 0; i < 8; i++) {
        HWND window = GetDlgItem(dialog, Slot_Control_ID(i));
        EnableWindow(window, FALSE);
        Enable_Slot_Controls(dialog, i, false);
    }
    HWND window = GetDlgItem(dialog, Slot_Control_ID(slot));
    EnableWindow(window, TRUE);
    Enable_Slot_Controls(dialog, slot, true);
}

static char * HostIconName = "wolhost.pcx";     // 0x7d1198 (the string lies in the preceding .data)
static char * AcceptIconName = "wolacpt.pcx";   // 0x7d119c

// 0x5c3740
void Update_Slot_Icons(HWND dialog)
{
    for (int i = 0; i < 8; i++) {
        HWND window = GetDlgItem(dialog, Slot_Name_Control_ID(i));
        void * image = NULL;
        MPPlayerNode * node = Session.Slots[i];
        if (Is_Real_Player(node) && !wcscmp(node->Name, Session.GameName)) {
            image = ImageCache.Find(HostIconName, 0);
        } else if (Is_Slot_Ready(i)) {
            image = ImageCache.Find(AcceptIconName, 0);
        }
        Set_Control_Image(window, image);
    }
}

void Set_Slot_Node(HWND dialog, int id, MPPlayerNode * node, int mode);    // 0x5c4d30

// Name and button control ids of a player slot.
static inline void Slot_IDs(int slot, int & name_id, int & control_id)
{
    if (slot == 0) {
        name_id = 0x6D2;
        control_id = 0x411;
    } else if (slot == 1) {
        name_id = 0x6D3;
        control_id = 0x412;
    } else if (slot == 2) {
        name_id = 0x6D4;
        control_id = 0x413;
    } else if (slot == 3) {
        name_id = 0x6D5;
        control_id = 0x414;
    } else if (slot == 4) {
        name_id = 0x6D6;
        control_id = 0x415;
    } else if (slot == 5) {
        name_id = 0x6D7;
        control_id = 0x416;
    } else if (slot == 6) {
        name_id = 0x6D8;
        control_id = 0x417;
    } else if (slot == 7) {
        name_id = 0x6D9;
        control_id = 0x418;
    } else {
        name_id = control_id = -1;
    }
}

// 0x5c4330
void Show_Slots(HWND dialog, int first, int count)
{
    for (int i = first; i < first + count; i++) {
        int name_id;
        int control_id;
        Slot_IDs(i, name_id, control_id);
        int flag_id = Player_Flag_ID(i);
        int color_id = Player_Color_ID(i);
        int side_id = Player_Side_ID(i);
        HWND name = GetDlgItem(dialog, name_id);
        HWND control = GetDlgItem(dialog, control_id);
        HWND flag = GetDlgItem(dialog, flag_id);
        HWND color = GetDlgItem(dialog, color_id);
        HWND side = GetDlgItem(dialog, side_id);
        ShowWindow(name, SW_SHOW);
        ShowWindow(control, SW_SHOW);
        ShowWindow(flag, SW_SHOW);
        ShowWindow(color, SW_SHOW);
        ShowWindow(side, SW_SHOW);
    }
}

// 0x5c44c0
void Hide_Slots(HWND dialog, int first)
{
    for (int i = first; i < 8; i++) {
        int name_id;
        int control_id;
        Slot_IDs(i, name_id, control_id);
        int flag_id = Player_Flag_ID(i);
        int side_id = Player_Side_ID(i);
        int color_id = Player_Color_ID(i);
        HWND name = GetDlgItem(dialog, name_id);
        HWND control = GetDlgItem(dialog, control_id);
        HWND flag = GetDlgItem(dialog, flag_id);
        HWND side = GetDlgItem(dialog, side_id);
        HWND color = GetDlgItem(dialog, color_id);
        ShowWindow(name, SW_HIDE);
        ShowWindow(control, SW_HIDE);
        ShowWindow(flag, SW_HIDE);
        ShowWindow(side, SW_HIDE);
        ShowWindow(color, SW_HIDE);
    }
}

static inline int Limit_Players(MultiplayerGameMode * mode, int count)
{
    if ((mode != NULL && !mode->Announce_Last_Player()) || Is_Tournament_Server()) {
        int max = Session_Max_Players();
        if (count > max) {
            count = max;
        }
    }
    return count;
}

// 0x5c4650
void Update_Slot_Count(HWND dialog, int old_count, int new_count, MultiplayerGameMode * new_mode)
{
    if ((Session.GameMode != NULL && !Session.GameMode->Announce_Last_Player()) || Is_Tournament_Server()) {
        int max = Session_Max_Players();
        if (old_count > max) {
            old_count = max;
        }
    }
    if ((new_mode != NULL && !new_mode->Announce_Last_Player()) || Is_Tournament_Server()) {
        int max = Session_Max_Players();
        if (new_count > max) {
            new_count = max;
        }
    }
    int change = new_count - old_count;
    if (change != 0) {
        if (change > 0) {
            Show_Slots(dialog, old_count, change);
        } else if (change < 0) {
            Hide_Slots(dialog, new_count);
        }
    }
}

// 0x5c4730
void Open_Slots(HWND dialog, int first, int count)
{
    int last = first + count;
    int max = Session_Max_Players();
    for (int i = first; i < last; i++) {
        int id = Slot_Control_ID(i);
        if (i < max) {
            Set_Slot_Node(dialog, id, OpenNode, false);
        } else {
            Set_Slot_Node(dialog, id, ClosedNode, false);
        }
    }
    Show_Slots(dialog, first, count);
    Func_5B6FA0();
    Update_Game_Options(true, false);
}

// 0x5c4840
void Close_Slots(HWND dialog, int first)
{
    int max = Session_Max_Players();
    for (int i = first; i < 8; i++) {
        int id = Slot_Control_ID(i);
        if (i < max) {
            Set_Slot_Node(dialog, id, OpenNode, true);
        } else {
            Set_Slot_Node(dialog, id, ClosedNode, true);
        }
    }
    Hide_Slots(dialog, first);
    if (WOLChat != NULL) {
        WOL_Func_7359A0();
    } else {
        Func_5B6FA0();
    }
    Update_Game_Options(true, false);
}

// 0x5c4c60
bool Any_Players_From(HWND dialog, int first)
{
    for (int i = first; i < 8; i++) {
        int id = Slot_Control_ID(i);
        MPPlayerNode * node = (MPPlayerNode *)Get_Combo_Data(dialog, id, -1);
        if (Is_Occupied(node)) {
            return true;
        }
    }
    return false;
}

// 0x5c5050
void Select_Slot_Type(HWND dialog, int id, int type)
{
    MPPlayerNode * node = Slot_Type_Node(type);
    Select_Combo_Data(dialog, id, (int)node);
    Set_Slot_Node(dialog, id, node, false);
}

// 0x5c41a0
bool Clear_AI_Slots(HWND dialog)
{
    bool changed = false;
    int max = Session_Max_Players();
    for (int i = 0; i < 8; i++) {
        int id = Slot_Control_ID(i);
        MPPlayerNode * node = (MPPlayerNode *)Get_Combo_Data(dialog, id, -1);
        if (Is_AI_Node(node)) {
            if (i < max) {
                Session.Slots[i] = OpenNode;
            } else {
                Session.Slots[i] = ClosedNode;
            }
            Enable_Slot_Controls(dialog, i, false);
            Session.Options.Color[i] = Session.Options.Side[i] = Session.Options.SlotAI[i] = -1;  // level-2 1.001: stored SlotAI, Side, Color
            changed = true;
        }
    }
    return changed;
}

// 0x5c51d0
void Save_Skirmish_Settings(HWND dialog, SkirmishSettingsType * settings)
{
    settings->GameMode = Session.Options.GameMode;
    settings->Scenario = Session.Options.Scenario;
    for (int i = 1; i < 8; i++) {
        int id = Slot_Control_ID(i);
        settings->AI[i - 1].Type = Slot_Node_Type((MPPlayerNode *)Get_Combo_Data(dialog, id, -1));
        id = Player_Side_ID(i);
        settings->AI[i - 1].Side = Get_Side_Data(dialog, id, -1);
        id = Player_Color_ID(i);
        settings->AI[i - 1].Color = Get_Color_Data(dialog, id, -1);
    }
    settings->GameSpeed = Session.Options.GameSpeed;
    settings->Credits = Session.Options.Credits;
    settings->UnitCount = Session.Options.UnitCount;
    settings->ShortGame = Session.Options.ShortGame;
    settings->SuperWeapons = Session.Options.SuperWeapons;
    settings->BuildOffAlly = Session.Options.BuildOffAlly;
    settings->MCVRedeploy = Session.Options.MCVRedeploy;
    settings->Crates = Session.Options.Crates;
}

// 0x5c4d30
void Set_Slot_Node(HWND dialog, int id, MPPlayerNode * node, int mode)
{
    int slot = Slot_Control_Index(id);
    MPPlayerNode * old = Session.Slots[slot];
    if (node == old) {
        return;
    }
    Session.Slots[slot] = node;
    if (mode == 1 || mode == 2) {
        if (!Is_Real_Player(node) && Is_Real_Player(old)) {
            if (WOLChat != NULL) {
                WOL_Kick_Player(old);
            } else {
                Send_Reject(old);
            }
        }
        if (WOLChat != NULL) {
            WOL_Func_730F50();
        } else {
            Send_Chat_Announce();
        }
    }
    bool is_ai = Is_AI(node);
    bool was_ai = Is_AI(old);
    if (is_ai) {
        Enable_Slot_Controls(dialog, slot, true);
        Session.Options.SlotAI[slot] = AI_Node_Difficulty(node);
        Session.Options.Side[slot] = -2;
        Session.Options.Color[slot] = -2;
    } else if (was_ai) {
        Enable_Slot_Controls(dialog, slot, false);
        Session.Options.SlotAI[slot] = -1;
        Session.Options.Side[slot] = -1;
        Session.Options.Color[slot] = -1;
    }
    if (WOLChat != NULL) {
        WOL_Func_73CE40();
    }
    if (is_ai || was_ai) {
        Session.Options.AIPlayers = Count_AI_Slots();
        if (mode == 2) {
            if (WOLChat != NULL) {
                WOL_Func_7359A0();
            } else {
                Func_5B6FA0();
            }
            Update_Game_Options(true, false);
        }
    }
}

static int SlotCount = 8;                       // 0x7d11c4 (name provisional)

// 0x5c4940
void Scenario_Changed(HWND dialog, int old_scenario, int new_scenario)
{
    int max = Max_Players(new_scenario);
    if ((Session.GameMode != NULL && !Session.GameMode->Announce_Last_Player()) || Is_Tournament_Server()) {
        int limit = Session_Max_Players();
        if (max > limit) {
            max = limit;
        }
    }
    if (old_scenario == -1) {
        SlotCount = 8;
    }
    int change = max - SlotCount;
    if (change > 0) {
        Open_Slots(dialog, SlotCount, change);
    } else if (change < 0) {
        Close_Slots(dialog, max);
    }
    SlotCount = max;
}

bool RandomMapIdle = true;                      // 0x7d11a0 (name as in ModemHst.cpp)

// 0x5c23a0
int Select_Random_Map()
{
    MessageCallback callback;
    if (Session.Type == 3) {
        callback = Net_Service_Callback;
    } else if (Session.Type == 4) {
        callback = Func_732A40;
    } else if (Session.Type == 1 || Session.Type == 2) {
        callback = ModemHostDialogClass::Message_Callback;
    } else {
        callback = Func_482310;
    }
    if (Random_Map_Dialog(callback) != 1) {
        return -1;
    }
    RandomMapIdle = true;
    RandomMap.Func_575CC0("RandMap.Sed");
    delete MapPreview;
    MapPreview = new MapPreviewClass;
    MapPreview->Load("RandMap.img");

    int index;
    for (index = 0; index < Session.Scenarios.ActiveCount; index++) {
        if (Session.Scenarios[index]->Is_Random_Map()) {
            Session.Scenarios[index]->Set_Description(RandomMap.Params.FileName);
            return index;
        }
    }
    char * digest = Random_Map_Digest();
    MultiMission * mission = new MultiMission("RandMap.Sed", RandomMap.Params.FileName, digest, true);
    Session.Scenarios.Add(mission);
    delete digest;
    return index;
}

// 0x5c1280
bool Map_Dialog_Accept(HWND dialog)
{
    int index = SendDlgItemMessageA(MapDialog, IDC_MAP_LIST, LB_GETCURSEL, 0, 0);
    int scenario = -1;
    if (index != -1) {
        scenario = Scenario_Index((MultiMission *)SendDlgItemMessageA(MapDialog, IDC_MAP_LIST, LB_GETITEMDATA, index, 0));
    }
    if (scenario == -1) {
        return false;
    }

    MultiplayerGameMode * old_mode = Session.GameMode;
    HWND map_dialog = MapDialog;
    MultiplayerGameMode * mode = NULL;
    index = SendDlgItemMessageA(map_dialog, IDC_GAME_MODE_LIST, LB_GETCURSEL, 0, 0);
    if (index != -1) {
        mode = (MultiplayerGameMode *)SendDlgItemMessageA(map_dialog, IDC_GAME_MODE_LIST, LB_GETITEMDATA, index, 0);
    }
    Session.GameMode = mode;
    int max = Max_Players(scenario);
    Session.GameMode = old_mode;

    bool ai = false;
    bool eject;
    switch (Session.Type) {
        case 3:
            eject = Host_Func_5B7610(max);
            break;
        case 4:
            eject = WOL_Func_74A220(max);
            break;
        case 5:
            eject = Any_AI_From(max);
            ai = true;
            break;
        default:
            goto changed;
    }
    if (eject) {
#line 2286 "C:\\RA2\\netshare.cpp"
        wchar_t const * message = Fetch_String(!ai ? "GUI:EjectPlayers" : "GUI:EjectAIPlayers", NULL, __FILE__, __LINE__);
        wchar_t const * ok = Fetch_String("GUI:Ok", NULL, __FILE__, __LINE__);
        wchar_t const * cancel = Fetch_String("GUI:Cancel", NULL, __FILE__, __LINE__);
        if (WWMessageBox().Process(message, ok, cancel) != 0) {
            return false;
        }
    }

changed:
    if (mode != Session.GameMode) {
        if (Session.GameMode != NULL) {
            Session.GameMode->Deactivate();
        }
        if (mode != NULL) {
            Session.GameMode = mode;
            Session.Options.GameMode = mode->ID;
            Session.Options.Scenario = scenario;
            mode->Activate();
        }
    }
    Session.Options.Scenario = scenario;
    if (mode != NULL) {
        mode->Slot_09();
    }
    mode->Slot_06();
    mode->Slot_26();
    Close_Dialog(dialog, 1);
    HWND net_dialog = Find_Dialog(0xC2);
    if (net_dialog == NULL) {
        net_dialog = Find_Dialog(0xC9);
        if (net_dialog == NULL) {
            net_dialog = Find_Dialog(0xBC);
            if (net_dialog == NULL) {
                net_dialog = Find_Dialog(0xBD);
            }
        }
    }
    Show_Game_Mode_Name(net_dialog, mode);
    Show_Scenario_Description(net_dialog, Session.Options.Scenario);
    mode->Slot_20();
    return true;
}

// Display names of the place holder nodes.
static wchar_t const * OpenText;                // 0xa5a884
static wchar_t const * ClosedText;              // 0xa5a888
static wchar_t const * EasyAIText;              // 0xa5a88c
static wchar_t const * MediumAIText;            // 0xa5a890
static wchar_t const * HardAIText;              // 0xa5a894
static wchar_t const * WaitingText;             // 0xa5a898

// 0x5c25a0
void Create_Slot_Nodes()
{
    if (OpenText == NULL) {
#line 3291 "C:\\RA2\\netshare.cpp"
        OpenText = Fetch_String("GUI:Open", NULL, __FILE__, __LINE__);
        ClosedText = Fetch_String("GUI:Closed", NULL, __FILE__, __LINE__);
        EasyAIText = Fetch_String("GUI:AIEasy", NULL, __FILE__, __LINE__);
        MediumAIText = Fetch_String("GUI:AINormal", NULL, __FILE__, __LINE__);
        HardAIText = Fetch_String("GUI:AIHard", NULL, __FILE__, __LINE__);
        WaitingText = Fetch_String("GUI:Waiting", NULL, __FILE__, __LINE__);
    }
    if (OpenNode == NULL) {
        OpenNode = new MPPlayerNode;
        wcscpy(OpenNode->Name, OpenText);
    }
    if (ClosedNode == NULL) {
        ClosedNode = new MPPlayerNode;
        wcscpy(ClosedNode->Name, ClosedText);
    }
    if (EasyAINode == NULL) {
        EasyAINode = new MPPlayerNode;
        wcscpy(EasyAINode->Name, EasyAIText);
    }
    if (MediumAINode == NULL) {
        MediumAINode = new MPPlayerNode;
        wcscpy(MediumAINode->Name, MediumAIText);
    }
    if (HardAINode == NULL) {
        HardAINode = new MPPlayerNode;
        wcscpy(HardAINode->Name, HardAIText);
    }
    if (WaitingNode == NULL) {
        WaitingNode = new MPPlayerNode;
        wcscpy(WaitingNode->Name, WaitingText);
    }
}

// Map-selection dialog helpers adapted from the ra2-decomp contributors (GPL-3.0-or-later).
struct MapTipRequest {
    HWND Window;
    int Item;
    WideStringClass Text;
};
static bool MapListBusy;
static bool ModeWarningShown;
void Fill_Game_Mode_List(HWND list, int mode_index); // 0x5b3cf0
void Dialog_On_OD_4EC(HWND window); // 0x5e0a50
void On_WM_NCDESTROY(HWND window); // 0x5f7040
bool Save_Dialog_Values(HWND window); // 0x5de430
bool Play_Dialog_Move_In(HWND window); // 0x5de620
static inline MultiplayerGameMode * Get_Selected_Game_Mode(HWND window)
{
	int selected = SendDlgItemMessage(window, 1771, LB_GETCURSEL, 0, 0);
	if (selected == -1) return(NULL);
	return((MultiplayerGameMode *)SendDlgItemMessage(window, 1771, LB_GETITEMDATA, selected, 0));
}

static inline void Save_Scenario_Name(void)
{
	HWND list = MapDialog;
	int sel = SendDlgItemMessage(MapDialog, IDC_MAP_LIST, LB_GETCURSEL, 0, 0);
	if (sel != -1) {
		MultiMission * title = (MultiMission *)SendDlgItemMessage(list, IDC_MAP_LIST, LB_GETITEMDATA, sel, 0);
		if (title != NULL) {
			wcscpy(MapDialogDescription, title->Description);
			return;
		}
	}
	MapDialogDescription[0] = 0;
}

static inline int Select_Scenario_By_Name(HWND window, wchar_t const * name)
{
	if (name == NULL) {
		return(-1);
	}
	int found = 0;
	int count = SendDlgItemMessage(window, IDC_MAP_LIST, LB_GETCOUNT, 0, 0);
	for (int i = 0; i < count; i++) {
		MultiMission * candidate = (MultiMission *)SendDlgItemMessage(window, IDC_MAP_LIST, LB_GETITEMDATA, i, 0);
		if (wcscmp(candidate->Description, name) == 0) {
			found = i;
		}
	}
	SendDlgItemMessage(window, IDC_MAP_LIST, LB_SETCURSEL, found, 0);
	SendDlgItemMessage(window, IDC_MAP_LIST, LB_SETTOPINDEX, found, 0);
	return(found);
}

static inline void Select_Scenario_Index(HWND window, int index)
{
	if (index < Session.Scenarios.Count()) {
		Select_Map_By_Data(window, (int)Session.Scenarios[index]);
	}
}

static inline void Enable_Random_Scenario(HWND window, MultiplayerGameMode * mode)
{
	bool allowed = mode->Allows_Random();
	HWND button = GetDlgItem(window, 0x583);
	EnableWindow(button, allowed);
}

static inline void Populate_Scenario_List(HWND window, MultiplayerGameMode * mode)
{
	DynamicVectorClass<MultiMission const *> maps;
	int count = Session.Scenarios.Count();
	for (int i = 0; i < count; i++) {
		MultiMission const * map = Session.Scenarios[i];
		if (mode->Allows_Map(map)) {
			maps.Add(map);
		}
	}
	HWND list = GetDlgItem(window, IDC_MAP_LIST);
	mode->Fill_Map_List(list, &maps, NULL);
}


static inline void Refresh_Selected_Map_Mode(HWND window, MultiplayerGameMode * mode)
{
	Populate_Scenario_List(window, mode);
	Enable_Random_Scenario(window, mode);
}

/// <summary>
/// Handles the messages for the multiplayer map selection dialog.
/// This routine fills the map list, paints the preview of the highlighted map, and services
/// the random map generator button.
/// </summary>
/// <returns>Returns with TRUE if the message was dealt with here, FALSE to leave it to the
/// dialog manager.</returns>
BOOL CALLBACK Map_Dialog_Proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam) // RA2: 0x005C69E0, ra2-decomp's twin text (Yuri's Revenge 0x005E6920) in this tree's names
{
	switch (message) {
		case WM_DRAWITEM:
			Func_5F6060(lparam);
		// Fall through: both messages have been handled.
		case WM_ERASEBKGND:
			return(TRUE);

		case WM_PAINT:
			Func_5F6B50(window); // RA2: the dialog is painted by the owner draw paint (0x005FEE70), not OwnerDraw::Draw_Dialog_Back
			if (MapPreview) MapPreview->Draw(window);
			Func_5DE390(window); // RA2: a dialog waiting to slide in does so now (0x005E5F20)
			ValidateRect(window, NULL);
			break;

		case WM_NCDESTROY:
			On_WM_NCDESTROY(window);
			break;

		case WM_COMMAND:
			switch (LOWORD(wparam)) {
				case 0x5c0:
					Close_Dialog(window, 2);
					break;
				case 0x583: {
					Save_Dialog_Values(window); // RA2: the dialog's values are saved before it is hidden (0x005E5FC0)
					ShowWindow(window, SW_HIDE);
					int scenario = Select_Random_Map();
					if (scenario != -1) {
						MultiplayerGameMode * mode = Get_Selected_Game_Mode(window);
						if (mode) {
							Populate_Scenario_List(window, mode);
				}
						Select_Scenario_Index(window, scenario);
						Set_Scenario(scenario);
						if (!MapPreview->Image) Update_Map_Preview(window);
						Session.Options.Scenario = MapDialogStartScenario;
						Set_Scenario(MapDialogStartScenario);
						bool accepted = Map_Dialog_Accept(window);
						Func_514F50(0, true);
						if (accepted) break;
			}
					Play_Dialog_Move_In(window);
					ShowWindow(window, SW_SHOW);
					break;
		}
				case 1733: // RA2: the accept button
					Map_Dialog_Accept(window);
					break;
				case 1771: // RA2: the game mode list
					if (!MapListBusy && HIWORD(wparam) == LBN_SELCHANGE) {
						MultiplayerGameMode * mode = Get_Selected_Game_Mode(window);
						if (mode) {
							WideStringClass error;
							if (mode->Check_Start(&error)) {
								mode->Slot_04();
								Refresh_Selected_Map_Mode(window, mode);
								Select_Scenario_By_Name(window, MapDialogDescription);
								Save_Scenario_Name();
								ModeWarningShown = false;
							} else {
								if (!ModeWarningShown) {
									Message_Box((wchar_t const *)static_cast<WideStringClass const &>(error), 0, NULL, false);
									ModeWarningShown = true;
						}
								SendDlgItemMessage(window, 1771, LB_SETCURSEL, 0, 0);
					}
				}
			}
					break;
		}
			break;

		case 0x4EC:
			Dialog_On_OD_4EC(window);
			break;

		case 0x4E9: { // RA2: the tool tip of a mode in the list
			MapTipRequest * request = (MapTipRequest *)lparam;
			int id = GetDlgCtrlID(request->Window);
			request->Text = (wchar_t const *)NULL;
			if (id == 1771 && request->Item != -1) {
				MultiplayerGameMode * mode = (MultiplayerGameMode *)SendDlgItemMessage(window, id, LB_GETITEMDATA, request->Item, 0);
				if (mode) request->Text = (wchar_t *)mode->Tooltip;
		}
			return(TRUE);
	}

	case 0x497: {
		MapListBusy = true;
		MultiplayerGameMode * mode = Game_Mode_From_ID(Session.Options.GameMode);
		if (!mode) mode = Default_Game_Mode();
		HWND list = GetDlgItem(window, 1771);
		Fill_Game_Mode_List(list, mode->ID);
		if (mode) {
			Populate_Scenario_List(window, mode);
		}
		Enable_Random_Scenario(window, mode);
		if (Session.Options.Scenario != -1) {
			Select_Scenario_Index(window, Session.Options.Scenario);
		}
		MapDialogStartScenario = Session.Options.Scenario;
		MapDialogScenario = -1;
		MapListBusy = false;
		break;
	}
	}
	return(FALSE);
}


