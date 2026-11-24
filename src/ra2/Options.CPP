// C:\RA2\Options.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Game options (OptionsClass, global object Options at 0xa28758): game speed, scrolling, detail,
// sidebar and video switches, sound/voice/score volume, network settings and the unlocked campaign
// movies, loaded from and saved to RA2.INI; plus the keyboard (hot key) dialog and the movie list.
// OptionsClass has no vtable and no RTTI; all class, method and variable names are provisional.
#include "GAMECONST.H"
#include <windows.h>
#include <commctrl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

void Debug_Printf(char const * format, ...);    // 0x4068f0, empty in this build (plain ret)

// Sound stream/channel record; 0x407080 sets its volume field (+0x08) and marks it changed.
struct SoundChannelStruct;
void Set_Channel_Volume(SoundChannelStruct * channel, int volume);   // 0x407080 (name provisional)
extern SoundChannelStruct * VoiceChannel;       // 0x819790 (name provisional)
extern SoundChannelStruct * ScoreChannel;       // 0x819794 (name provisional)
extern SoundChannelStruct * SoundChannel;       // 0x819798 (name provisional)

void Set_Speech_Volume(int volume);             // 0x70aab0, clamps to 255 (name provisional)
int Play_Sound(int voc, float volume, int pan, int flags);   // 0x708970 (names provisional)

// Music.
class ThemeClass {
public:
    bool Still_Playing();                       // 0x6dd590
    void Set_Repeat(bool on) { IsRepeat = on; }
    void Set_Shuffle(bool on) { IsShuffle = on; }

    char Unknown00[0x10];
    bool IsRepeat;                              // +0x10
    bool Unknown11;
    bool IsShuffle;                             // +0x12
};
extern ThemeClass Theme;                        // 0xa1e0a8

// Rules object; only the field used here.
class RulesClass {
public:
    char Unknown000[0x630];
    int OptionsTestSound;                       // +0x630, sound played to test a volume (name provisional)
};
extern RulesClass * Rule;                       // 0x821b88

// File class hierarchy (copied from Restate.cpp; RTTI FileClass, RawFileClass, BufferIOFileClass,
// CDFileClass, CCFileClass).
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
    virtual void Close();               // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

// Doubly linked list (RTTI: GenericNode, GenericList, List<T>), see Restate.cpp.
class GenericNode {
public:
    virtual ~GenericNode();
private:
    GenericNode * NextNode;
    GenericNode * PrevNode;
};

class GenericList {
public:
    GenericList();                      // 0x490c60
    virtual ~GenericList();
private:
    GenericNode FirstNode;
    GenericNode LastNode;
};

template<class T>
class List : public GenericList {
};

// Keyboard command (RTTI .?AVCommandClass@@, vtable 0x78f3ec, 9 slots). Slot names provisional.
class CommandClass {
public:
    virtual ~CommandClass();
    virtual char const * Get_Name() const = 0;              // slot 1, INI entry name
    virtual wchar_t const * Get_UI_Name() const;            // slot 2
    virtual wchar_t const * Get_Category() const = 0;       // slot 3
    virtual wchar_t const * Get_Description() const = 0;    // slot 4
    virtual bool Virtual_05() const;
    virtual bool Virtual_06() const;
    virtual bool Virtual_07() const;
    virtual void Execute(int key) const = 0;                // slot 8
};
extern DynamicVectorClass<CommandClass const *> Commands;   // 0x81a698 (name provisional)

/*
**  Sorted index of (ID, Data) pairs. Only the inline methods used by this file are reconstructed;
**  their code is expanded in the keyboard dialog (Binary_Search is emitted here at 0x5d2c10).
*/
template<class T>
T * Binary_Search(T * A, int n, T const & target)
{
    int stride = n;
    while (stride > 0) {
        int pivot = stride / 2;
        T * ptr = &A[pivot];
        if (target < *ptr) {
            stride = pivot;
        } else if (*ptr == target) {
            return ptr;
        } else {
            A = ptr + 1;
            stride -= pivot + 1;
        }
    }
    return 0;
}

template<class T, class U>
class IndexClass {
public:
    IndexClass() : IndexTable(0), IndexCount(0), IndexSize(0), IsSorted(false), Archive(0) {}
    ~IndexClass();

    bool Add_Index(T const & id, U const & data);
    bool Remove_Index(T const & id);
    bool Is_Present(T const & id) const;
    int Count() const { return IndexCount; }
    U const & operator [] (T const & id) const;
    U const & Fetch_By_Position(int position) const;
    T Fetch_ID_By_Position(int position) const;

private:
    struct NodeElement {
        bool operator == (NodeElement const & rvalue) const { return ID == rvalue.ID; }
        bool operator < (NodeElement const & rvalue) const { return ID < rvalue.ID; }
        T ID;
        U Data;
    };

    NodeElement * IndexTable;
    int IndexCount;
    int IndexSize;
    bool IsSorted;
    NodeElement const * Archive;

    bool Increase_Table_Size(int amount);
    void Invalidate_Archive() const { ((IndexClass<T, U> *)this)->Archive = 0; }
    void Set_Archive(NodeElement const * node) const { ((IndexClass<T, U> *)this)->Archive = node; }
    bool Is_Archive_Same(T const & id) const { return Archive != 0 && Archive->ID == id; }
    NodeElement const * Search_For_Node(T const & id) const;
    static int __cdecl search_compfunc(void const * ptr, void const * ptr2);
};

template<class T, class U>
U const & IndexClass<T, U>::Fetch_By_Position(int position) const
{
    if (!IsSorted) {
        qsort(&IndexTable[0], IndexCount, sizeof(IndexTable[0]), search_compfunc);
        Invalidate_Archive();
        ((IndexClass<T, U> *)this)->IsSorted = true;
    }
    return IndexTable[position].Data;
}

template<class T, class U>
T IndexClass<T, U>::Fetch_ID_By_Position(int position) const
{
    return IndexTable[position].ID;
}

template<class T, class U>
typename IndexClass<T, U>::NodeElement const * IndexClass<T, U>::Search_For_Node(T const & id) const
{
    if (IndexCount == 0) return 0;
    if (!IsSorted) {
        qsort(&IndexTable[0], IndexCount, sizeof(IndexTable[0]), search_compfunc);
        Invalidate_Archive();
        ((IndexClass<T, U> *)this)->IsSorted = true;
    }
    NodeElement node;
    node.ID = id;
    return Binary_Search(IndexTable, IndexCount, node);
}

template<class T, class U>
bool IndexClass<T, U>::Is_Present(T const & id) const
{
    if (IndexCount == 0) return false;
    if (Is_Archive_Same(id)) return true;
    NodeElement const * nodeptr = Search_For_Node(id);
    if (nodeptr != 0) {
        Set_Archive(nodeptr);
        return true;
    }
    return false;
}

template<class T, class U>
U const & IndexClass<T, U>::operator [] (T const & id) const
{
    static U x;
    if (Is_Present(id)) {
        return Archive->Data;
    }
    return x;
}

template<class T, class U>
bool IndexClass<T, U>::Add_Index(T const & id, U const & data)
{
    if (IndexCount + 1 > IndexSize) {
        if (!Increase_Table_Size(IndexSize == 0 ? 10 : IndexSize)) {
            return false;
        }
    }
    IndexTable[IndexCount].ID = id;
    IndexTable[IndexCount].Data = data;
    IndexCount++;
    IsSorted = false;
    return true;
}

template<class T, class U>
bool IndexClass<T, U>::Remove_Index(T const & id)
{
    int found_index = -1;
    NodeElement const * nodeptr = Search_For_Node(id);
    if (nodeptr != 0) {
        found_index = nodeptr - IndexTable;
    }
    if (found_index != -1) {
        for (int index = found_index + 1; index < IndexCount; index++) {
            IndexTable[index - 1] = IndexTable[index];
        }
        IndexCount--;
        IndexTable[IndexCount].ID = T();
        IndexTable[IndexCount].Data = U();
        Invalidate_Archive();
        return true;
    }
    return false;
}

extern IndexClass<int, CommandClass const *> HotkeyIndex;  // 0x81a6c0, key number -> command (name provisional)

bool Can_Assign_Hotkey(CommandClass const * command, int key);  // 0x480dc0 (name provisional)
bool Can_Remap_Key(int key);            // 0x480de0 (name provisional)
void Load_Hotkeys();                    // 0x5187b0, reads KEYBOARD.INI (name provisional)
void Hotkey_Name(WORD hotkey, wchar_t * buffer);    // 0x5f4410, readable key name (name provisional)

// INI database (see Restate.cpp). The methods are declared on CCINIClass as in CCINI.H and
// Restate.cpp; in the Westwood design most of them belong to the INIClass base. Names provisional.
class INIClass {
public:
    struct INISection;
    struct INIEntry;

    INIClass() : Unknown34(0) {}
    virtual ~INIClass();                // 0x50ad20
private:
    List<INISection *> SectionList;                 // +0x04
    IndexClass<int, INISection *> SectionIndex;     // +0x20
    int Unknown34;                                  // +0x34
};

class CCINIClass : public INIClass {
public:
    CCINIClass() : IsDigestPresent(false) {}

    bool Clear(char const * section = NULL, char const * entry = NULL);                     // 0x50adf0
    int Get_Int(char const * section, char const * entry, int defvalue = 0);                // 0x50cc40
    bool Put_Int(char const * section, char const * entry, int number, int format = 0);     // 0x50cb30
    bool Get_Bool(char const * section, char const * entry, bool defvalue = false);         // 0x50e860
    bool Put_Bool(char const * section, char const * entry, bool value);                    // 0x50e7d0
    double Get_Float(char const * section, char const * entry, double defvalue = 0.0);      // 0x50d7f0
    bool Put_Float(char const * section, char const * entry, double number);                // 0x50d990
    int Get_String(char const * section, char const * entry, char const * defvalue, char * buffer, int size);   // 0x50ddf0
    int Put_String(char const * section, char const * entry, char const * string);          // 0x50da40
    int Get_WString(char const * section, char const * entry, wchar_t const * defvalue, wchar_t * buffer, int size);   // 0x50e240
    bool Put_WString(char const * section, char const * entry, wchar_t const * string);     // 0x50e140
    int Save(FileClass & file, bool withdigest);                                            // 0x469510
private:
    bool IsDigestPresent;               // +0x38
    unsigned char Digest[20];           // +0x39
};
extern CCINIClass SettingsINI;                  // 0x821a80, the RA2.INI settings database (name provisional)

extern char NullString[];                       // 0x8248a4 (.bss), shared empty string (name provisional)
extern wchar_t NullWString[];                   // 0x82208c (.bss), shared empty wide string (name provisional)

// IPX address (see NetDlg.CPP).
typedef unsigned char NetNumType[4];
typedef unsigned char NetNodeType[6];
#pragma pack(push, 1)
class IPXAddressClass {
public:
    IPXAddressClass(NetNumType net, NetNodeType node);     // 0x522980
private:
    NetNumType NetworkNumber;
    NetNodeType NodeAddress;
};
#pragma pack(pop)

class IPXManagerClass {
public:
    void Set_Socket(unsigned short socket);     // 0x524e40
};
extern IPXManagerClass Ipx;                     // 0xa285c8
extern int SessionIsBridge;                     // 0xa2792c  (Session + 0x2364)
extern IPXAddressClass SessionBridgeNet;        // 0xa27930  (Session + 0x2368)

// The display object at 0x81a820 (MouseClass); 0x671200 is an empty method in this build.
class MouseClass {
public:
    void Set_Cameo_Text(bool on);               // 0x671200 (name provisional)
};
extern MouseClass Map;                          // 0x81a820

void Set_Action_Lines(bool on);                 // 0x6ccf30, stores into 0x7e09a0 (name provisional)
extern bool AllowModeToggle;                    // 0xa2894b (name provisional)
extern bool MovieStretchAllowed;                // 0x83b306 (meaning provisional)

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60

// Dialog support (see Restate.cpp and GameDlg.CPP).
HWND Create_Dialog(int resource_id, DLGPROC proc, LPARAM param);            // 0x5f72d0
void Show_Dialog(HWND dialog);          // 0x5f7480
void End_Dialog(HWND dialog);           // 0x5f73a0
bool Dialog_Abort_Check();              // 0x5f7d70, pumps messages, true when the dialog must close
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
void Call_Back_5168E0(bool flag);       // 0x5168e0, called while the dialog runs outside a game (meaning unknown)
extern bool GameInProgress;             // 0xa285a8, true while a game is in progress (GameDlg.CPP: Flag_A285A8)

// ---- end of local declarations ----

static BOOL CALLBACK Keyboard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);

/*
**  Hot key modifier conversion between the game key number (WWKEY bits) and the Windows hot key
**  control format (HOTKEYF bits in the high byte).
*/
enum {
    WWKEY_SHIFT_BIT = 0x0100,
    WWKEY_CTRL_BIT = 0x0200,
    WWKEY_ALT_BIT = 0x0400,
    WWKEY_VK_BIT = 0x1000
};

int Hotkey_To_Key(int hotkey)                   // 0x5d0e60
{
    int key = hotkey & 0xFF;
    int mods = (hotkey >> 8) & 0xFF;
    if (mods & HOTKEYF_ALT) key |= WWKEY_ALT_BIT;
    if (mods & HOTKEYF_CONTROL) key |= WWKEY_CTRL_BIT;
    if (mods & HOTKEYF_SHIFT) key |= WWKEY_SHIFT_BIT;
    if (mods & HOTKEYF_EXT) key = 0;
    return key;
}

int Key_To_Hotkey(int key)                     // 0x5d0e90
{
    int mods = 0;
    if (key & WWKEY_ALT_BIT) mods = HOTKEYF_ALT;
    if (key & WWKEY_CTRL_BIT) mods |= HOTKEYF_CONTROL;
    if (key & WWKEY_SHIFT_BIT) mods |= HOTKEYF_SHIFT;
    if (key & WWKEY_VK_BIT) mods |= HOTKEYF_EXT;
    return (key & 0xFF) | (mods << 8);
}

class OptionsClass {
public:
    OptionsClass();
    void One_Time();
    void Set_Shuffle(bool on);
    void Set_Repeat(bool on);
    void Set_Score_Volume(float volume, bool feedback);
    void Set_Sound_Volume(float volume, bool feedback);
    void Set_Voice_Volume(float volume, bool feedback);
    void Load_Settings();
    void Save_Settings();
    void Apply_Network_Settings();
    void Set();
    int Normalize_Delay(int delay) const;
    int Normalize_Sound(int volume) const;
    int Get_Scroll_Method() const;
    void Movie_Seen(char const * name);
    void Fill_Movie_List(HWND list) const;
    bool Keyboard_Options();

    int GameSpeed;                              // +0x00
    int Difficulty;                             // +0x04
    int ScrollMethod;                           // +0x08
    int ScrollRate;                             // +0x0c
    bool AutoScroll;                            // +0x10
    int DetailLevel;                            // +0x14
    bool SidebarOnRight;                        // +0x18
    bool SidebarCameoText;                      // +0x19
    bool UnitActionLines;                       // +0x1a
    bool ShowHidden;                            // +0x1b
    bool ToolTips;                              // +0x1c
    int ScreenWidth;                            // +0x20
    int ScreenHeight;                           // +0x24
    bool StretchMovies;                         // +0x28
    bool AllowHiResModes;                       // +0x29
    bool AllowVRAMSidebar;                      // +0x2a
    float SoundVolume;                          // +0x2c
    float VoiceVolume;                          // +0x30
    float ScoreVolume;                          // +0x34
    bool IsScoreRepeat;                         // +0x38
    bool InGameMusic;                           // +0x39
    bool IsScoreShuffle;                        // +0x3a
    unsigned short SoundLatency;                // +0x3c
    unsigned short Socket;                      // +0x3e
    int SovietMovies;                           // +0x40, last unlocked Soviet movie (-1 = none)
    int AlliedMovies;                           // +0x44, last unlocked Allied movie (-1 = none)
    int NetCard;                                // +0x48
    char DestNet[64];                           // +0x4c
    int KeyForceMove1;                          // +0x8c
    int KeyForceMove2;                          // +0x90
    int KeyForceAttack1;                        // +0x94
    int KeyForceAttack2;                        // +0x98
    int KeySelect1;                             // +0x9c
    int KeySelect2;                             // +0xa0
    int KeyQueue1;                              // +0xa4
    int KeyQueue2;                              // +0xa8
};

OptionsClass::OptionsClass() :
    GameSpeed(3),
    Difficulty(1),
    ScrollMethod(0),
    ScrollRate(3),
    AutoScroll(true),
    DetailLevel(2),
    SidebarOnRight(true),
    SidebarCameoText(true),
    UnitActionLines(true),
    ShowHidden(false),
    ToolTips(true),
    ScreenWidth(-1),
    ScreenHeight(-1),
    StretchMovies(false),
    AllowHiResModes(false),
    AllowVRAMSidebar(false),
    SoundVolume(0.7f),
    VoiceVolume(1.0f),
    ScoreVolume(0.5f),
    IsScoreRepeat(false),
    InGameMusic(true),
    IsScoreShuffle(false),
    SoundLatency(9),
    Socket(0xFFFF),
    SovietMovies(-1),
    AlliedMovies(-1),
    NetCard(0),
    KeyForceMove1(VK_MENU),
    KeyForceMove2(VK_MENU),
    KeyForceAttack1(VK_CONTROL),
    KeyForceAttack2(VK_CONTROL),
    KeySelect1(VK_SHIFT),
    KeySelect2(VK_SHIFT),
    KeyQueue1('Q'),
    KeyQueue2('Q')
{
    DestNet[0] = '\0';
}

void OptionsClass::One_Time()
{
}

void OptionsClass::Set_Shuffle(bool on)
{
    IsScoreShuffle = on;
    Theme.Set_Shuffle(on);
    Debug_Printf("ScoreShuffle is %s\n", IsScoreShuffle == true ? "ON" : "OFF");
}

void OptionsClass::Set_Repeat(bool on)
{
    IsScoreRepeat = on;
    Theme.Set_Repeat(on);
    Debug_Printf("ScoreRepeat is %s\n", IsScoreRepeat == true ? "ON" : "OFF");
}

void OptionsClass::Set_Score_Volume(float volume, bool feedback)
{
    ScoreVolume = (volume < 1.0) ? volume : 1.0;
    Set_Channel_Volume(ScoreChannel, ScoreVolume * 16384.0f);
    if (feedback && !Theme.Still_Playing()) {
        Play_Sound(Rule->OptionsTestSound, ScoreVolume, 0x2000, 0);
    }
    Debug_Printf("ScoreVolume = %f\n", ScoreVolume);
}

void OptionsClass::Set_Sound_Volume(float volume, bool feedback)
{
    SoundVolume = (volume < 1.0) ? volume : 1.0;
    Set_Channel_Volume(SoundChannel, SoundVolume * 16384.0f);
    if (feedback) {
        Play_Sound(Rule->OptionsTestSound, 1.0f, 0x2000, 0);
    }
    Debug_Printf("SoundVolume = %f\n", SoundVolume);
}

void OptionsClass::Set_Voice_Volume(float volume, bool feedback)
{
    VoiceVolume = (volume < 1.0) ? volume : 1.0;
    Set_Speech_Volume(VoiceVolume * 255.0);
    Set_Channel_Volume(VoiceChannel, VoiceVolume * 16384.0f);
    if (feedback) {
        Play_Sound(Rule->OptionsTestSound, VoiceVolume, 0x2000, 0);
    }
    Debug_Printf("VoiceVolume = %f\n", VoiceVolume);
}

void OptionsClass::Load_Settings()
{
    Debug_Printf("--------- Loading SUN.INI settings ---------------\n");

    GameSpeed = SettingsINI.Get_Int("Options", "GameSpeed", GameSpeed);
    Debug_Printf("GameSpeed = %d\n", GameSpeed);

    Difficulty = SettingsINI.Get_Int("Options", "Difficulty", Difficulty);
    Difficulty = (Difficulty < 4) ? Difficulty : 4;
    Difficulty = (Difficulty > 0) ? Difficulty : 0;
    Debug_Printf("Difficulty = %d\n", Difficulty);

    ScrollMethod = SettingsINI.Get_Int("Options", "ScrollMethod", ScrollMethod);
    Debug_Printf("ScrollMethod = %d\n", ScrollMethod);

    ScrollRate = SettingsINI.Get_Int("Options", "ScrollRate", ScrollRate);
    Debug_Printf("ScrollRate = %d\n", ScrollRate);

    AutoScroll = SettingsINI.Get_Bool("Options", "AutoScroll", AutoScroll);
    Debug_Printf("AutoScroll is %s\n", AutoScroll == true ? "ON" : "OFF");

    DetailLevel = SettingsINI.Get_Int("Options", "DetailLevel", DetailLevel);
    DetailLevel = (DetailLevel < 2) ? DetailLevel : 2;
    DetailLevel = (DetailLevel > 0) ? DetailLevel : 0;
    Debug_Printf("DetailLevel = %d\n", DetailLevel);

    SidebarOnRight = true;
    Debug_Printf("SideBar on %s\n", SidebarOnRight ? "RIGHT" : "LEFT");

    SidebarCameoText = SettingsINI.Get_Bool("Options", "SidebarCameoText", SidebarCameoText);
    Debug_Printf("Sidebar Text is %s\n", SidebarCameoText == true ? "ON" : "OFF");

    UnitActionLines = SettingsINI.Get_Bool("Options", "UnitActionLines", UnitActionLines);
    Debug_Printf("ActionLines are %s\n", UnitActionLines == true ? "ON" : "OFF");

    ShowHidden = SettingsINI.Get_Bool("Options", "ShowHidden", ShowHidden);
    Debug_Printf("ShowHidden is %s\n", ShowHidden == true ? "ON" : "OFF");

    ToolTips = SettingsINI.Get_Bool("Options", "ToolTips", ToolTips);
    Debug_Printf("ToolTips are %s\n", ToolTips == true ? "ON" : "OFF");

    ScreenWidth = SettingsINI.Get_Int("Video", "ScreenWidth", ScreenWidth);
    ScreenHeight = SettingsINI.Get_Int("Video", "ScreenHeight", ScreenHeight);
    Debug_Printf("Resolution = %d X %d\n", ScreenWidth, ScreenHeight);

    StretchMovies = SettingsINI.Get_Bool("Video", "StretchMovies", StretchMovies);
    StretchMovies = (StretchMovies == true && MovieStretchAllowed == true);
    Debug_Printf("StretchMovies is %s\n", StretchMovies == true ? "ON" : "OFF");

    AllowHiResModes = SettingsINI.Get_Bool("Video", "AllowHiResModes", AllowHiResModes);
    Debug_Printf("AllowHiRes is %s\n", AllowHiResModes == true ? "ON" : "OFF");

    AllowModeToggle = SettingsINI.Get_Bool("Video", "AllowModeToggle", AllowModeToggle);
    AllowVRAMSidebar = SettingsINI.Get_Bool("Video", "AllowVRAMSidebar", AllowVRAMSidebar);

    Set_Sound_Volume(SettingsINI.Get_Float("Audio", "SoundVolume", SoundVolume), false);
    Set_Voice_Volume(SettingsINI.Get_Float("Audio", "VoiceVolume", VoiceVolume), false);
    Set_Score_Volume(SettingsINI.Get_Float("Audio", "ScoreVolume", ScoreVolume), false);
    Set_Repeat(SettingsINI.Get_Bool("Audio", "IsScoreRepeat", IsScoreRepeat));
    Set_Shuffle(SettingsINI.Get_Bool("Audio", "IsScoreShuffle", IsScoreShuffle));
    InGameMusic = SettingsINI.Get_Bool("Audio", "InGameMusic", InGameMusic);

    /*
    **  The unlocked campaign movies are stored, lightly disguised, as the network ID.
    */
    SovietMovies = -1;
    AlliedMovies = -1;
    wchar_t buffer[200];
    SettingsINI.Get_WString("Network", "NetID", NullWString, buffer, 200);
    if (buffer[0] != 0) {
        for (wchar_t * ptr = buffer; *ptr != 0; ptr++) {
            *ptr = ~*ptr;
            if (*ptr == 0) *ptr = 0xFFFF;
        }
        wchar_t * token = wcstok(buffer, L" ");
        if (token != NULL) {
            SovietMovies = wcstol(token, NULL, 10) - 1;
            token = wcstok(NULL, L" ");
            if (token != NULL) {
                AlliedMovies = wcstol(token, NULL, 10) - 1;
            }
        }
    }
    if (SovietMovies < -1 || SovietMovies >= 12) SovietMovies = -1;
    if (AlliedMovies < -1 || AlliedMovies >= 12) AlliedMovies = -1;

    SoundLatency = SettingsINI.Get_Int("Audio", "SoundLatency", SoundLatency);
    Debug_Printf("Emulated sound card latency default = %d\n", SoundLatency);

    Socket = SettingsINI.Get_Int("Network", "Socket", Socket);
    NetCard = SettingsINI.Get_Int("Network", "NetCard", NetCard);
    SettingsINI.Get_String("Network", "DestNet", NullString, DestNet, sizeof(DestNet));

    Debug_Printf("--------- Complete -------------------------------\n");

    Map.Set_Cameo_Text(SidebarCameoText);
    Set_Action_Lines(UnitActionLines);
    Apply_Network_Settings();
}

void OptionsClass::Save_Settings()
{
    CCFileClass file("RA2.INI");

    Debug_Printf("Saving game settings\n");

    SettingsINI.Put_Int("Options", "GameSpeed", GameSpeed);
    SettingsINI.Put_Int("Options", "Difficulty", Difficulty);
    SettingsINI.Put_Int("Options", "ScrollMethod", ScrollMethod);
    SettingsINI.Put_Int("Options", "ScrollRate", ScrollRate);
    SettingsINI.Put_Bool("Options", "AutoScroll", AutoScroll);
    SettingsINI.Put_Int("Options", "DetailLevel", DetailLevel);
    SettingsINI.Put_Bool("Options", "SidebarCameoText", SidebarCameoText);
    SettingsINI.Put_Bool("Options", "UnitActionLines", UnitActionLines);
    SettingsINI.Put_Bool("Options", "ShowHidden", ShowHidden);
    SettingsINI.Put_Bool("Options", "ToolTips", ToolTips);
    SettingsINI.Put_Int("Video", "ScreenWidth", ScreenWidth);
    SettingsINI.Put_Int("Video", "ScreenHeight", ScreenHeight);
    SettingsINI.Put_Bool("Video", "StretchMovies", StretchMovies);
    SettingsINI.Put_Float("Audio", "SoundVolume", SoundVolume);
    SettingsINI.Put_Float("Audio", "VoiceVolume", VoiceVolume);
    SettingsINI.Put_Float("Audio", "ScoreVolume", ScoreVolume);
    SettingsINI.Put_Bool("Audio", "IsScoreRepeat", IsScoreRepeat);
    SettingsINI.Put_Bool("Audio", "IsScoreShuffle", IsScoreShuffle);
    SettingsINI.Put_Int("Audio", "SoundLatency", SoundLatency);
    SettingsINI.Put_Bool("Audio", "InGameMusic", InGameMusic);
    SettingsINI.Put_Int("Network", "Socket", Socket);
    SettingsINI.Put_Int("Network", "NetCard", NetCard);
    SettingsINI.Put_String("Network", "DestNet", DestNet);

    wchar_t buffer[200];
    swprintf(buffer, L"%d %d", SovietMovies + 1, AlliedMovies + 1);
    for (wchar_t * ptr = buffer; *ptr != 0; ptr++) {
        *ptr = ~*ptr;
        if (*ptr == 0) *ptr = 0xFFFF;
    }
    SettingsINI.Put_WString("Network", "NetID", buffer);

    SettingsINI.Save(file, false);
    Apply_Network_Settings();
}

void OptionsClass::Apply_Network_Settings()
{
    if (Socket == 0xFFFF) {
        Ipx.Set_Socket(0x8813);
    } else if (Socket < 0x4000) {
        Ipx.Set_Socket(Socket + 0x4000);
    }

    int length = strlen(DestNet);
    if (length != 0) {
        NetNumType net;
        NetNodeType node;
        char * buffer = new char[length + 1];
        strcpy(buffer, DestNet);

        int i = 0;
        char * token = strtok(buffer, ".");
        while (token != NULL) {
            int value;
            sscanf(token, "%x", &value);
            if (i < 4) {
                net[i] = value;
            } else {
                node[i - 4] = value;
            }
            i++;
            token = strtok(NULL, ".");
        }

        if (i >= 4) {
            SessionIsBridge = 1;
            memset(node, 0xFF, sizeof(node));
            SessionBridgeNet = IPXAddressClass(net, node);
        }
    }
}

void OptionsClass::Set()
{
    Set_Sound_Volume(SoundVolume, false);
    Set_Voice_Volume(VoiceVolume, false);
    Set_Score_Volume(ScoreVolume, false);
    Set_Repeat(IsScoreRepeat);
    Set_Shuffle(IsScoreShuffle);
    Map.Set_Cameo_Text(SidebarCameoText);
    Set_Action_Lines(UnitActionLines);
}

int OptionsClass::Normalize_Delay(int delay) const
{
    static int _adjust[4][8] = {
        {2, 2, 1, 1, 1, 1, 1, 1},
        {3, 3, 3, 2, 2, 2, 1, 1},
        {5, 4, 4, 3, 3, 2, 2, 1},
        {7, 6, 5, 4, 4, 4, 3, 2}
    };
    if (delay) {
        if (delay < 5) {
            delay = _adjust[delay - 1][GameSpeed];
        } else {
            delay = ((delay * 8) / (GameSpeed + 1));
        }
    }
    return delay;
}

int OptionsClass::Normalize_Sound(int volume) const
{
    return volume * SoundVolume;
}

/*
**  Keyboard (hot key) dialog.
**
**  Level-2 status: same size (3008 bytes) and the same instruction structure as 0x5d1e20, but the
**  register allocation differs (the original keeps dialog in ebp, message in edi, lparam in ebx).
**  The case order below is significant: with WM_KEY_ASSIGN before WM_COMMAND and the hot key
**  sub-case after IDC_KEY_OK, VC6 inlines Binary_Search in the two Is_Present expansions and calls
**  it out of line in the two Remove_Index expansions, exactly as in GAME.EXE.
*/
#define IDC_KEY_CATEGORY            0x4C7       // combo box of command categories
#define IDC_KEY_COMMANDS            0x4C8       // list box of the commands in the category
#define IDC_KEY_DESCRIPTION         0x4CB
#define IDC_KEY_HOTKEY              0x4CD       // hot key control
#define IDC_KEY_ASSIGN              0x4CF
#define IDC_KEY_DEFAULTS            0x4D0
#define IDC_KEY_ASSIGNED_TO         0x63B       // command that currently uses the typed key
#define IDC_KEY_CURRENT             0x63C       // current key of the selected command
#define IDC_KEY_ERROR               0x63D
#define IDC_KEY_OK                  0x686

#define WM_KEY_CATEGORY_CHANGED     (WM_USER + 0x64)
#define WM_KEY_COMMAND_CHANGED      (WM_USER + 0x65)
#define WM_KEY_ASSIGN               (WM_USER + 0x66)
#define WM_KEY_FILL_CATEGORIES      (WM_USER + 0x67)
#define WM_DIALOG_INIT              (WM_USER + 0x97)

// Wide-string messages of the game's dialog controls (names provisional).
#define WM_SET_TEXT_WIDE            (WM_USER + 0xB2)
#define WM_GET_TEXT_WIDE            (WM_USER + 0xB3)
#define CB_FINDSTRINGEXACT_WIDE     (WM_USER + 0xBE)
#define CB_ADDSTRING_WIDE           (WM_USER + 0xC2)
#define LB_ADDSTRING_WIDE           (WM_USER + 0xCD)

static int LastCategory = -1;                   // 0x7d257c

static BOOL CALLBACK Keyboard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) return result;

    int * retval = (int *)GetWindowLongA(dialog, DWL_USER);
    wchar_t buffer[64];

    switch (message) {
        case WM_KEY_COMMAND_CHANGED:
        {
            HWND list = GetDlgItem(dialog, IDC_KEY_COMMANDS);
            int index = SendMessageA(list, LB_GETCURSEL, 0, 0);
            if (index == LB_ERR) break;
            CommandClass const * command = (CommandClass const *)SendMessageA(list, LB_GETITEMDATA, index, 0);
            HWND description = GetDlgItem(dialog, IDC_KEY_DESCRIPTION);
            SendMessageA(description, WM_SET_TEXT_WIDE, 0, (LPARAM)command->Get_Description());

            int key = 0;
            for (int i = 0; i < HotkeyIndex.Count(); i++) {
                if (HotkeyIndex.Fetch_By_Position(i) == command) {
                    key = HotkeyIndex.Fetch_ID_By_Position(i);
                    break;
                }
            }

            HWND current = GetDlgItem(dialog, IDC_KEY_CURRENT);
            Hotkey_Name(Key_To_Hotkey(key), buffer);
            SendMessageA(current, WM_SET_TEXT_WIDE, 0, (LPARAM)buffer);
            HWND hotkey = GetDlgItem(dialog, IDC_KEY_HOTKEY);
            SendMessageA(hotkey, HKM_SETHOTKEY, 0, 0);
            HWND assigned = GetDlgItem(dialog, IDC_KEY_ASSIGNED_TO);
            SendMessageA(assigned, WM_SET_TEXT_WIDE, 0, (LPARAM)NullWString);
            return TRUE;
        }

        case WM_KEY_CATEGORY_CHANGED:
        {
            HWND combo = GetDlgItem(dialog, IDC_KEY_CATEGORY);
            if (SendMessageA(combo, CB_GETCURSEL, 0, 0) == LastCategory) break;
            LastCategory = SendMessageA(combo, CB_GETCURSEL, 0, 0);

            SendMessageA(combo, WM_GET_TEXT_WIDE, 64, (LPARAM)buffer);

            HWND list = GetDlgItem(dialog, IDC_KEY_COMMANDS);
            SendMessageA(list, LB_RESETCONTENT, 0, 0);
            for (int i = 0; i < Commands.ActiveCount; i++) {
                CommandClass const * command = Commands[i];
                if (_wcsicmp(command->Get_Category(), buffer) == 0) {
                    int index = SendMessageA(list, LB_ADDSTRING_WIDE, 0, (LPARAM)command->Get_UI_Name());
                    if (index != LB_ERR) {
                        SendMessageA(list, LB_SETITEMDATA, index, (LPARAM)command);
                    }
                }
            }

            HWND description = GetDlgItem(dialog, IDC_KEY_DESCRIPTION);
            SendMessageA(description, WM_SET_TEXT_WIDE, 0, (LPARAM)NullWString);
            HWND current = GetDlgItem(dialog, IDC_KEY_CURRENT);
            SendMessageA(current, WM_SET_TEXT_WIDE, 0, (LPARAM)NullWString);
            HWND assigned = GetDlgItem(dialog, IDC_KEY_ASSIGNED_TO);
            SendMessageA(assigned, WM_SET_TEXT_WIDE, 0, (LPARAM)NullWString);
            SendMessageA(assigned, LB_SETCURSEL, 0, 0);
            SendMessageA(dialog, WM_KEY_COMMAND_CHANGED, 0, 0);
            return TRUE;
        }

        case WM_KEY_ASSIGN:
        {
            HWND list = GetDlgItem(dialog, IDC_KEY_COMMANDS);
            int index = SendMessageA(list, LB_GETCURSEL, 0, 0);
            if (index == LB_ERR) break;
            CommandClass const * command = (CommandClass const *)SendMessageA(list, LB_GETITEMDATA, index, 0);
            HWND hotkey = GetDlgItem(dialog, IDC_KEY_HOTKEY);
            int key = Hotkey_To_Key(SendMessageA(hotkey, HKM_GETHOTKEY, 0, 0));

            if (!Can_Assign_Hotkey(command, key)) {
                HWND error = GetDlgItem(dialog, IDC_KEY_ERROR);
#line 990 "C:\\RA2\\Options.CPP"
                SendMessageA(error, WM_SET_TEXT_WIDE, 0, (LPARAM)Fetch_String("Error:CannotMap", NULL, __FILE__, __LINE__));
                return TRUE;
            }
            if (!Can_Remap_Key(key)) {
                HWND error = GetDlgItem(dialog, IDC_KEY_ERROR);
#line 998
                SendMessageA(error, WM_SET_TEXT_WIDE, 0, (LPARAM)Fetch_String("Error:CannotRemap", NULL, __FILE__, __LINE__));
                return TRUE;
            }

            for (int i = 0; i < HotkeyIndex.Count(); i++) {
                if (HotkeyIndex.Fetch_By_Position(i) == command) {
                    HotkeyIndex.Remove_Index(HotkeyIndex.Fetch_ID_By_Position(i));
                    break;
                }
            }
            if (key == 0) break;
            HotkeyIndex.Remove_Index(key);
            if (!HotkeyIndex.Add_Index(key, command)) break;
            return TRUE;
        }

        case WM_COMMAND:
            switch (LOWORD(wparam)) {
                case IDC_KEY_COMMANDS:
                    if (HIWORD(wparam) == LBN_SELCHANGE) {
                        SendMessageA(dialog, WM_KEY_COMMAND_CHANGED, 0, 0);
                        HWND hotkey = GetDlgItem(dialog, IDC_KEY_HOTKEY);
                        if (hotkey != NULL) {
                            SetFocus(hotkey);
                            return TRUE;
                        }
                    }
                    break;

                case IDC_KEY_CATEGORY:
                    if (HIWORD(wparam) == CBN_SELCHANGE) {
                        SendMessageA(dialog, WM_KEY_CATEGORY_CHANGED, 0, 0);
                        return TRUE;
                    }
                    break;

                case IDCANCEL:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        Load_Hotkeys();
                        *retval = 2;
                        return TRUE;
                    }
                    break;

                case IDC_KEY_OK:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        CCINIClass ini;
                        ini.Clear();
                        for (int i = 0; i < HotkeyIndex.Count(); i++) {
                            CommandClass const * command = HotkeyIndex.Fetch_By_Position(i);
                            ini.Put_Int("Hotkey", command->Get_Name(), HotkeyIndex.Fetch_ID_By_Position(i));
                        }
                        RawFileClass file("Keyboard.ini");
                        ini.Save(file, false);
                        *retval = 1;
                        return TRUE;
                    }
                    break;

                case IDC_KEY_HOTKEY:
                    if (HIWORD(wparam) == EN_CHANGE) {
                        HWND error = GetDlgItem(dialog, IDC_KEY_ERROR);
                        SendMessageA(error, WM_SET_TEXT_WIDE, 0, (LPARAM)NullWString);
                        int key = Hotkey_To_Key(SendMessageA((HWND)lparam, HKM_GETHOTKEY, 0, 0));
                        wchar_t const * name = NULL;
                        if (HotkeyIndex.Is_Present(key)) {
                            name = HotkeyIndex[key]->Get_UI_Name();
                        }
                        if (name == NULL) {
                            name = NullWString;
                        }
                        HWND assigned = GetDlgItem(dialog, IDC_KEY_ASSIGNED_TO);
                        SendMessageA(assigned, WM_SET_TEXT_WIDE, 0, (LPARAM)name);
                        return TRUE;
                    }
                    break;

                case IDC_KEY_DEFAULTS:
                    if (HIWORD(wparam) == BN_CLICKED) {
                        Debug_Printf("Deleting users KEYBOARD.INI\n");
                        CCFileClass file("KEYBOARD.INI");
                        file.Delete();
                        Load_Hotkeys();
                        SendMessageA(dialog, WM_KEY_FILL_CATEGORIES, 0, 0);
                        return TRUE;
                    }
                    break;

                case IDC_KEY_ASSIGN:
                    SendMessageA(dialog, WM_KEY_ASSIGN, 0, 0);
                    SendMessageA(dialog, WM_KEY_COMMAND_CHANGED, 0, 0);
                    return TRUE;
            }
            break;

        case WM_DIALOG_INIT:
            SendMessageA(dialog, WM_KEY_FILL_CATEGORIES, 0, 0);
            return FALSE;

        case WM_KEY_FILL_CATEGORIES:
        {
            HWND combo = GetDlgItem(dialog, IDC_KEY_CATEGORY);
            SendMessageA(combo, CB_RESETCONTENT, 0, 0);
            for (int i = 0; i < Commands.ActiveCount; i++) {
                CommandClass const * command = Commands[i];
                if (SendMessageA(combo, CB_FINDSTRINGEXACT_WIDE, 0, (LPARAM)command->Get_Category()) == CB_ERR) {
                    SendMessageA(combo, CB_ADDSTRING_WIDE, 0, (LPARAM)command->Get_Category());
                }
            }
            SendMessageA(combo, CB_SETCURSEL, 0, 0);
            LastCategory = -1;
            SendMessageA(dialog, WM_KEY_CATEGORY_CHANGED, 0, 0);
            break;
        }

        default:
            return FALSE;
    }
    return TRUE;
}

#define IDD_KEYBOARD                0xA3

/*
**  Shows the keyboard (hot key) dialog and waits until it is closed.
*/
bool OptionsClass::Keyboard_Options()
{
    int result = -1;
    HWND dialog = Create_Dialog(IDD_KEYBOARD, Keyboard_Dialog_Proc, 0);
    if (dialog != NULL) {
        SetWindowLongA(dialog, DWL_USER, (LONG)&result);
        Show_Dialog(dialog);
        while (result < 0) {
            if (Dialog_Abort_Check() == true) {
                result = 2;
            }
            if (!GameInProgress) {
                Call_Back_5168E0(false);
            }
        }
        End_Dialog(dialog);
    }
    return true;
}

int OptionsClass::Get_Scroll_Method() const
{
    return ScrollMethod;
}

/*
**  Campaign movie lists. Name is the movie file, Description the string table label; Side is
**  -1 for the intro, 0 for Allied and 1 for Soviet movies (meaning of the field provisional).
*/
struct MovieInfoStruct {
    char const * Name;
    char const * Description;
    int Side;
};

MovieInfoStruct IntroMovie = {"A00_F00E", "Name:IntroMovie", -1};       // 0x7d23b0

MovieInfoStruct AlliedMovieList[] = {                                   // 0x7d23c0
    {"A01_F00e", "Name:All01", 0},
    {"A02_F00e", "Name:All02", 0},
    {"A03_F00e", "Name:All03", 0},
    {"A04_F00e", "Name:All04", 0},
    {"A05_F00e", "Name:All05", 0},
    {"A06_F00e", "Name:All06", 0},
    {"A07_F00e", "Name:All07", 0},
    {"A08_F00e", "Name:All08", 0},
    {"A09_F00e", "Name:All09", 0},
    {"A10_F00e", "Name:All10", 0},
    {"A11_F00e", "Name:All11", 0},
    {"A12_F00e", "Name:All12", 0},
    {NULL, NULL, 0}
};

MovieInfoStruct SovietMovieList[] = {                                   // 0x7d2460
    {"S01_F00e", "Name:Sov01", 1},
    {"S02_F00e", "Name:Sov02", 1},
    {"S03_F00e", "Name:Sov03", 1},
    {"S04_F00e", "Name:Sov04", 1},
    {"S05_F00e", "Name:Sov05", 1},
    {"S06_F00e", "Name:Sov06", 1},
    {"S07_F00e", "Name:Sov07", 1},
    {"S08_F00e", "Name:Sov08", 1},
    {"S09_F00e", "Name:Sov09", 1},
    {"S10_F00e", "Name:Sov10", 1},
    {"S11_F00e", "Name:Sov11", 1},
    {"S12_F00e", "Name:Sov12", 1},
    {NULL, NULL, 0}
};

static int Movie_Index(MovieInfoStruct const * list, char const * name)
{
    for (int index = 0; list->Name != NULL; index++, list++) {
        if (stricmp(name, list->Name) == 0) {
            return index;
        }
    }
    return -1;
}

/*
**  Records that a campaign movie was played, so that it becomes available in the movie list.
*/
void OptionsClass::Movie_Seen(char const * name)
{
    int index = Movie_Index(SovietMovieList, name);
    if (index > SovietMovies) {
        SovietMovies = index;
    }
    index = Movie_Index(AlliedMovieList, name);
    if (index > AlliedMovies) {
        AlliedMovies = index;
    }
}

static void Add_Movie(HWND list, MovieInfoStruct const * movie)
{
    if (movie->Name != NULL && movie->Description != NULL) {
#line 1251 "C:\\RA2\\Options.CPP"
        int index = SendMessageA(list, LB_ADDSTRING_WIDE, 0, (LPARAM)Fetch_String(movie->Description, NULL, __FILE__, __LINE__));
        if (index != LB_ERR) {
            SendMessageA(list, LB_SETITEMDATA, index, (LPARAM)movie);
        }
    }
}

/*
**  Fills a list box with the intro and all unlocked campaign movies.
*/
void OptionsClass::Fill_Movie_List(HWND list) const
{
    Add_Movie(list, &IntroMovie);

    if (SovietMovies >= 0) {
        int count = SovietMovies + 1;
        for (MovieInfoStruct const * movie = SovietMovieList; movie->Name != NULL && count > 0; movie++, count--) {
            Add_Movie(list, movie);
        }
    }

    if (AlliedMovies >= 0) {
        int count = AlliedMovies + 1;
        for (MovieInfoStruct const * movie = AlliedMovieList; movie->Name != NULL && count > 0; movie++, count--) {
            Add_Movie(list, movie);
        }
    }
}
