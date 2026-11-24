// C:\RA2\WOLPersonaInformation.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Westwood Online persona information: the per-persona profile (server, locale, country, colour and
// ladder statistics) kept in WOLINFO.INI, the AutoLogin/AddMatchBuddies/DefaultPersona/LastValid
// settings of that file, and the persona fields of the WOL login dialog.
// Class names come from RTTI (PlayerProfile, ReferenceCounted, rc_ptr<PlayerProfile>, INIClass,
// GenericList, GenericNode, List<INIClass::INISection *>, CDFileClass); all other names are provisional.

// Dynamic initializer 0x32d010: 16 bytes at 0xb0de80, inside this TU's .bss (between the GAMECONST
// static 0xb0de78 and DefaultPersonaName 0xb0de90) and directly before the GAMECONST block, so it
// belongs to this TU (as in WorldDom.cpp). Meaning unknown.
struct WOLPersonaUnknownStruct {
    WOLPersonaUnknownStruct() : A(0), B(0), C(0), D(0) {}
    int A;
    int B;
    int C;
    int D;
};
static WOLPersonaUnknownStruct WOLPersonaUnknown;

#include "GAMECONST.H"

// ---- local declarations (to be moved to headers by the integrator) ----
#include <windows.h>
#include <stdio.h>
#include <stddef.h>

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x6eeb60 (also in ABSTYPE.H)

extern char NullString[];               // 0x8248a4 (.bss), shared empty string (name provisional)
extern wchar_t NullWString[];           // 0x82208c (.bss), shared empty wide string (name provisional)

// Simple owned narrow string, one pointer (library code near 0x759250; name provisional).
class CharStringClass {
public:
    CharStringClass();                                          // 0x759250
    CharStringClass(char const * string);                       // 0x759260
    CharStringClass(CharStringClass const & string);            // 0x7592c0
    ~CharStringClass();                                         // 0x759320
    bool operator == (CharStringClass const & string) const;    // 0x7593b0
    CharStringClass & operator = (CharStringClass const & string);   // 0x759570
    operator char * ();                                         // 0x75a030 (identical code to the const version)
    operator char const * () const;                             // 0x75a070
    unsigned Get_Length() const;                                // 0x75a0e0
    void To_Lower();                                            // 0x75a760
    char * Buffer;
};

// Simple owned wide string, one pointer (library code near 0x75b2f0; name provisional).
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);                    // 0x75b300
    ~WideStringClass();                                         // 0x75b390
    WideStringClass & operator = (wchar_t const * string);      // 0x75b4b0
    operator wchar_t const * () const;                          // 0x75bd30
    operator wchar_t * ();                                      // 0x75bd70 (identical code to the const version)
    unsigned Get_Length() const;                                // 0x75bde0
    wchar_t * Buffer;
};
WideStringClass Int_To_WideString(int value);                   // 0x75ca00 (swprintf "%d"; fastcall)
WideStringClass To_WideString(CharStringClass const & string);  // 0x75cb00 (narrow to wide; fastcall)

// File class hierarchy (RTTI FileClass, RawFileClass, BufferIOFileClass, CDFileClass); slot order from
// the CDFileClass vtable 0x785658 (overloaded Open slots are reversed by VC6). Signatures provisional.
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
    virtual char const * File_Name() const;
    virtual char const * Set_Name(char const * filename);
    virtual int Create();                                       // 0x6307a0
    virtual int Delete();                                       // 0x6307e0
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
    virtual ~BufferIOFileClass();                               // 0x42f250
    virtual bool Is_Available(int forced = false);              // 0x42f5e0
    virtual void Close();                                       // 0x42fca0
private:
    char BufferIOData[0x34];            // +0x20, layout not reconstructed
};

class CDFileClass : public BufferIOFileClass {
public:
    CDFileClass(char const * filename);                         // 0x46f930
    virtual ~CDFileClass() {}
    virtual char const * Set_Name(char const * filename);       // 0x46fd50
    virtual int Open(char const * filename, int rights = 1);    // 0x46fe50
    virtual int Open(int rights = 1);                           // 0x46fa10
};

// Doubly linked list (RTTI: GenericNode, GenericList, List<T>). The constructors are inline; their
// out-of-line copies are 0x40e160 and 0x490c60.
class GenericNode {
public:
    GenericNode() : NextNode(0), PrevNode(0) {}
    virtual ~GenericNode();
    void Link(GenericNode * node);                              // 0x40e180
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

template<class T, class U>
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

// INI database. The CharStringClass overloads are out-of-line wrappers of the char const * versions.
class INIClass {
public:
    struct INISection;

    INIClass() : Unknown34(0) {}
    virtual ~INIClass();                                                        // 0x50ad20

    int Load(FileClass & file, bool withdigest);                                // 0x50b030
    int Save(FileClass & file);                                                 // 0x50ba30
    INISection * Find_Section(char const * section);                            // 0x50be00
    bool Is_Present(CharStringClass const & section) { return Find_Section(section) != NULL; }
    bool Put_Int(CharStringClass const & section, CharStringClass const & entry, int number, int format = 0);   // 0x50cbb0
    int Get_Int(CharStringClass const & section, CharStringClass const & entry, int defvalue = 0);              // 0x50ce20
    int Put_String(CharStringClass const & section, CharStringClass const & entry, CharStringClass const & string);   // 0x50ddc0
    int Get_String(CharStringClass const & section, CharStringClass const & entry, CharStringClass const & defvalue, CharStringClass & buffer);   // 0x50df90
    bool Put_Bool(char const * section, char const * entry, bool value);        // 0x50e7d0
    bool Put_Bool(CharStringClass const & section, CharStringClass const & entry, bool value);   // 0x50e810
    bool Get_Bool(char const * section, char const * entry, bool defvalue = false);   // 0x50e860
private:
    List<INISection *> SectionList;                 // +0x04
    IndexClass<int, INISection *> SectionIndex;     // +0x20
    int Unknown34;                                  // +0x34
};

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
    virtual ~rc_ptr_base();                      // 0x630ab0 (deleting 0x630b20)
    void Set(ReferenceCounted * pointer);        // 0x630ad0
protected:
    ReferenceCounted * Pointer;
};

template<class T>
class rc_ptr : public rc_ptr_base {
public:
    rc_ptr() {}
    rc_ptr(T * pointer) { Set(pointer); }
    virtual ~rc_ptr() {}
    T * Get() const { return (T *)Pointer; }
    T * operator -> () const { return (T *)Pointer; }
};

// WOLAPI registry options (HKLM\SOFTWARE\Westwood\WOLAPI\, value "Options"); 0x4fe700 reads them.
class WOLAPIOptions {
public:
    WOLAPIOptions() : Flags(0), IsLoaded(false) { Load(); }
    bool Load();                                 // 0x4fe700
    bool Is_Option_2_Clear() const;              // 0x4fe7c0, true when bit 1 is clear (meaning unknown)
private:
    unsigned long Flags;
    bool IsLoaded;
};

namespace WOL {
// Ladder entry as delivered by WOLAPI; only the fields read here are named.
struct Ladder {
    unsigned int SKU;
    unsigned int TeamNo;
    unsigned int Wins;          // +08
    unsigned int Losses;        // +0C
    unsigned int Points;        // +10
    unsigned int Kills;
    unsigned int Rank;
    unsigned int Rung;          // +1C
    unsigned int Disconnects;   // +20
};
}

// RTTI .?AVPlayerProfile@@ : ReferenceCounted, vtable 0x79a3e4, size 0x38.
class PlayerProfile : public ReferenceCounted {
public:
    PlayerProfile(CharStringClass const & server, int locale, bool locale_verified, int locale_source,
        int country, int color, int rank, int points, int wins, int losses, int disconnects);
    virtual ~PlayerProfile();

    static rc_ptr<PlayerProfile> Load_Default();
    static rc_ptr<PlayerProfile> Load(CharStringClass const & name);
    static void Clear_Dialog(HWND dialog, bool clear_name);

    void Save(CharStringClass const & name);
    void Set_Server(CharStringClass const & server);
    void Set_Locale(int locale, int source);
    void Set_Country(int country);
    void Set_Color(int color);
    void Set_Ladder(WOL::Ladder const & ladder);
    void Update_Dialog(HWND dialog, CharStringClass const & name, bool full) const;

    bool IsChanged;             // +08
    CharStringClass Server;     // +0C
    int Locale;                 // +10
    bool LocaleVerified;        // +14
    int LocaleSource;           // +18
    int Country;                // +1C
    int Color;                  // +20
    int Rank;                   // +24
    int Points;                 // +28
    int Wins;                   // +2C
    int Losses;                 // +30
    int Disconnects;            // +34
};

bool Get_Auto_Login();
void Set_Auto_Login(bool value);
bool Get_Add_Match_Buddies();
void Set_Add_Match_Buddies(bool value);
CharStringClass Get_Default_Persona();
void Set_Default_Persona(CharStringClass const & name);
CharStringClass Get_Last_Valid_Persona();
void Set_Last_Valid_Persona(CharStringClass const & name);

// Dialog control IDs and messages of the WOL persona dialog (names provisional).
#define IDC_PERSONA_NAME        0x628
#define IDC_PERSONA_SERVER      0x629
#define IDC_PERSONA_LOCALE      0x62A
#define IDC_PERSONA_COUNTRY     0x6A1
#define IDC_PERSONA_COLOR       0x6A2
#define IDC_PERSONA_LABEL       0x6EF
#define IDC_PERSONA_WINS        0x6F0
#define IDC_PERSONA_LOSSES      0x6F1
#define IDC_PERSONA_RANK        0x6F4
#define IDC_PERSONA_POINTS      0x6F5
#define IDC_PERSONA_DISCONNECTS 0x701
#define WM_SET_TEXT_WIDE        (WM_USER + 0xB2)
#define WM_SET_TEXT_NARROW      (WM_USER + 0xB4)
#define WM_FIND_STRING_NARROW   (WM_USER + 0xB9)
#define WM_FIND_STRING_WIDE     (WM_USER + 0xBF)
#define WM_GET_ITEM_COUNT       (WM_USER + 0xCE)
// ---- end of local declarations ----

// 0x32d200 (atexit destructor 0x32d220): section name of the default persona.
CharStringClass DefaultPersonaName("_Default_");

// 0x32d230
rc_ptr<PlayerProfile> PlayerProfile::Load_Default()
{
    CharStringClass server;
    int locale = 0;
    int country = -2;
    int color = -2;

    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        file.Create();
        file.Close();
        file.Open("wolinfo.ini", 1);
    }
    if (file.Is_Available()) {
        INIClass ini;
        ini.Load(file, false);
        file.Close();
        if (ini.Is_Present(DefaultPersonaName)) {
            ini.Get_String(DefaultPersonaName, "Server", server, server);
            locale = ini.Get_Int(DefaultPersonaName, "Locale", 0);
            country = ini.Get_Int(DefaultPersonaName, "Country", -2);
            color = ini.Get_Int(DefaultPersonaName, "Color", -2);
        }
    }
    return rc_ptr<PlayerProfile>(new PlayerProfile(server, locale, false, 0, country, color, -1, -1, -1, -1, -1));
}

// 0x32d440
rc_ptr<PlayerProfile> PlayerProfile::Load(CharStringClass const & name)
{
    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        file.Create();
        file.Close();
        file.Open("wolinfo.ini", 1);
    }
    if (!file.Is_Available()) {
        return Load_Default();
    }

    INIClass ini;
    ini.Load(file, false);
    file.Close();

    CharStringClass section = name;
    section.To_Lower();
    if (!ini.Is_Present(section)) {
        return Load_Default();
    }

    CharStringClass server;
    ini.Get_String(section, "Server", server, server);
    int locale = ini.Get_Int(section, "Locale", 0);
    bool verified = ini.Get_Bool(section, "LocaleVerified", false);
    int country = ini.Get_Int(section, "Country", -2);
    int color = ini.Get_Int(section, "Color", -2);
    int rank = ini.Get_Int(section, "Rank", -1);
    int points = ini.Get_Int(section, "Points", -1);
    int wins = ini.Get_Int(section, "Wins", -1);
    int losses = ini.Get_Int(section, "Losses", -1);
    int disconnects = ini.Get_Int(section, "Disconnects", -1);
    return rc_ptr<PlayerProfile>(new PlayerProfile(server, locale, verified, verified ? 1 : 3, country, color,
        rank, points, wins, losses, disconnects));
}

// 0x32d800
PlayerProfile::PlayerProfile(CharStringClass const & server, int locale, bool locale_verified, int locale_source,
    int country, int color, int rank, int points, int wins, int losses, int disconnects) :
    IsChanged(false),
    Server(server),
    Locale(locale),
    LocaleVerified(locale_verified),
    LocaleSource(locale_source),
    Country(country),
    Color(color),
    Rank(rank),
    Points(points),
    Wins(wins),
    Losses(losses),
    Disconnects(disconnects)
{
}

// 0x32d870
bool Get_Auto_Login()
{
    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        return false;
    }
    INIClass ini;
    ini.Load(file, false);
    file.Close();
    return ini.Get_Bool("Ask", "AutoLogin", true);
}

// 0x32d960
void Set_Auto_Login(bool value)
{
    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        file.Create();
        file.Close();
        file.Open("wolinfo.ini", 1);
    }
    INIClass ini;
    if (file.Is_Available()) {
        ini.Load(file, false);
        ini.Put_Bool("Ask", "AutoLogin", value);
        ini.Save(file);
    }
}

// 0x32da70
bool Get_Add_Match_Buddies()
{
    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        return false;
    }
    INIClass ini;
    ini.Load(file, false);
    file.Close();
    return ini.Get_Bool("Ask", "AddMatchBuddies", true);
}

// 0x32db60
void Set_Add_Match_Buddies(bool value)
{
    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        file.Create();
        file.Close();
        file.Open("wolinfo.ini", 1);
    }
    INIClass ini;
    if (file.Is_Available()) {
        ini.Load(file, false);
        ini.Put_Bool("Ask", "AddMatchBuddies", value);
        ini.Save(file);
    }
}

// 0x32dc70
CharStringClass Get_Default_Persona()
{
    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        return NULL;
    }
    INIClass ini;
    ini.Load(file, false);
    file.Close();
    CharStringClass name;
    ini.Get_String("DefaultPersona", "AutoLogin", name, name);
    return name;
}

// 0x32ddb0
void Set_Default_Persona(CharStringClass const & name)
{
    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        file.Create();
        file.Close();
        file.Open("wolinfo.ini", 1);
    }
    INIClass ini;
    if (file.Is_Available()) {
        ini.Load(file, false);
        ini.Put_String("DefaultPersona", "AutoLogin", name);
        ini.Save(file);
    }
}

// 0x32def0
CharStringClass Get_Last_Valid_Persona()
{
    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        return NULL;
    }
    INIClass ini;
    ini.Load(file, false);
    file.Close();
    CharStringClass name;
    ini.Get_String("DefaultPersona", "LastValid", name, name);
    return name;
}

// 0x32e030
void Set_Last_Valid_Persona(CharStringClass const & name)
{
    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        file.Create();
        file.Close();
        file.Open("wolinfo.ini", 1);
    }
    INIClass ini;
    if (file.Is_Available()) {
        ini.Load(file, false);
        ini.Put_String("DefaultPersona", "LastValid", name);
        ini.Save(file);
    }
}

// 0x32e170 (scalar deleting destructor 0x32ec50)
PlayerProfile::~PlayerProfile()
{
}

// 0x32e190
void PlayerProfile::Save(CharStringClass const & name)
{
    WOLAPIOptions options;
    if (!IsChanged) {
        return;
    }

    CharStringClass section = name;
    if (name.Get_Length() == 0) {
        section = DefaultPersonaName;
    } else {
        section.To_Lower();
        if (!options.Is_Option_2_Clear()) {
            return;
        }
    }

    CDFileClass file("wolinfo.ini");
    if (!file.Is_Available()) {
        file.Create();
        file.Close();
        file.Open("wolinfo.ini", 1);
    }
    if (file.Is_Available()) {
        INIClass ini;
        ini.Load(file, false);
        ini.Put_String(section, "Server", Server);
        ini.Put_Int(section, "Locale", Locale);
        // The cast only resolves the overload ambiguity; the conversion temporary is built as for the
        // implicit conversions of the other calls.
        ini.Put_Bool(section, (CharStringClass const &)"LocaleVerified", LocaleVerified);
        ini.Put_Int(section, "Country", Country);
        ini.Put_Int(section, "Color", Color);
        ini.Put_Int(section, "Rank", Rank);
        ini.Put_Int(section, "Points", Points);
        ini.Put_Int(section, "Wins", Wins);
        ini.Put_Int(section, "Losses", Losses);
        ini.Put_Int(section, "Disconnects", Disconnects);
        ini.Save(file);
        file.Close();
        IsChanged = false;
    }
}

// 0x32e4e0
void PlayerProfile::Set_Server(CharStringClass const & server)
{
    if (!(server == Server)) {
        Server = server;
        IsChanged = true;
    }
}

// 0x32e510
void PlayerProfile::Set_Locale(int locale, int source)
{
    if (locale == Locale) {
        if (source == 2 && !LocaleVerified) {
            LocaleVerified = true;
            IsChanged = true;
        }
        return;
    }
    bool better = source >= LocaleSource;
    if (Locale == 0) {
        better = true;
    } else if (!better) {
        return;
    }
    if (locale != 0 && better) {
        if (source == 3) {
            LocaleVerified = false;
        }
        Locale = locale;
        LocaleSource = source;
        IsChanged = true;
    }
}

// 0x32e570
void PlayerProfile::Set_Country(int country)
{
    if (country != Country) {
        Country = country;
        IsChanged = true;
    }
}

// 0x32e590
void PlayerProfile::Set_Color(int color)
{
    if (color != Color) {
        Color = color;
        IsChanged = true;
    }
}

// 0x32e5b0
void PlayerProfile::Set_Ladder(WOL::Ladder const & ladder)
{
    if (ladder.Rung != Rank) {
        Rank = ladder.Rung;
        IsChanged = true;
    }
    if (ladder.Points != Points) {
        Points = ladder.Points;
        IsChanged = true;
    }
    if (ladder.Wins != Wins) {
        Wins = ladder.Wins;
        IsChanged = true;
    }
    if (ladder.Losses != Losses) {
        Losses = ladder.Losses;
        IsChanged = true;
    }
    if (ladder.Disconnects != Disconnects) {
        Disconnects = ladder.Disconnects;
        IsChanged = true;
    }
}

// Sets the wide text of a dialog control.
static inline void Set_Item_Text(HWND item, wchar_t const * text)
{
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)text);
}

static inline void Set_Item_Text(HWND item, WideStringClass & text)
{
    SendMessageA(item, WM_SET_TEXT_WIDE, 0, (LPARAM)(wchar_t *)text);
}

// 0x32e610
void PlayerProfile::Clear_Dialog(HWND dialog, bool clear_name)
{
    if (clear_name) {
        HWND combo = GetDlgItem(dialog, IDC_PERSONA_NAME);
        SendMessageA(combo, WM_SET_TEXT_NARROW, 0, (LPARAM)NullString);
        InvalidateRect(combo, NULL, FALSE);
    }
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_LABEL), NullWString);
#line 639 "C:\\RA2\\WOLPersonaInformation.cpp"
    WideStringClass unknown(Fetch_String("GUI:UnknownStats", NULL, __FILE__, __LINE__));
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_WINS), unknown);
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_LOSSES), unknown);
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_DISCONNECTS), unknown);
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_RANK), unknown);
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_POINTS), unknown);
}

// Selects the combo box entry whose item data equals the value.
static inline void Select_Item_Data(HWND combo, int const & value)
{
    if (combo != NULL) {
        int count = SendMessageA(combo, CB_GETCOUNT, 0, 0);
        for (int index = 0; index < count; index++) {
            if (SendMessageA(combo, CB_GETITEMDATA, index, 0) == value) {
                SendMessageA(combo, CB_SETCURSEL, index, 0);
                break;
            }
        }
    }
}

// 0x32e730. Not yet byte-identical: control flow, calls and temporaries match, but from the second
// statistics line on VC6 keeps GetDlgItem in ebp and spills the text pointer (one extra stack slot),
// where the original keeps the text pointer and later the persona name in ebp.
void PlayerProfile::Update_Dialog(HWND dialog, CharStringClass const & name, bool full) const
{
    if (full) {
        HWND combo = GetDlgItem(dialog, IDC_PERSONA_NAME);
        bool has_items = SendMessageA(combo, WM_GET_ITEM_COUNT, 0, 0) != 0;
        if (name.Get_Length() != 0 && !has_items) {
            int index = SendMessageA(combo, WM_FIND_STRING_NARROW, -1, (LPARAM)(char const *)name);
            SendMessageA(combo, CB_SETCURSEL, index, 0);
            if (index == -1) {
                SendMessageA(combo, WM_SET_TEXT_NARROW, 0, (LPARAM)(char const *)name);
            }
        } else {
            WideStringClass wide = To_WideString(name);
            int index;
            if (name.Get_Length() <= 0 || (index = SendMessageA(combo, WM_FIND_STRING_WIDE, -1, (LPARAM)(wchar_t *)wide)) == -1) {
#line 668 "C:\\RA2\\WOLPersonaInformation.cpp"
                wide = Fetch_String("GUI:Default", NULL, __FILE__, __LINE__);
                index = SendMessageA(combo, WM_FIND_STRING_WIDE, -1, (LPARAM)(wchar_t *)wide);
            }
            SendMessageA(combo, CB_SETCURSEL, index, 0);
            if (index == -1) {
                SendMessageA(combo, WM_SET_TEXT_WIDE, 0, (LPARAM)(wchar_t *)wide);
            }
        }
    }

    HWND server = GetDlgItem(dialog, IDC_PERSONA_SERVER);
    int index = SendMessageA(server, WM_FIND_STRING_NARROW, -1, (LPARAM)(char const *)Server);
    SendMessageA(server, CB_SETCURSEL, index, 0);

    Select_Item_Data(GetDlgItem(dialog, IDC_PERSONA_LOCALE), Locale);
    Select_Item_Data(GetDlgItem(dialog, IDC_PERSONA_COUNTRY), Country);
    Select_Item_Data(GetDlgItem(dialog, IDC_PERSONA_COLOR), Color);

#line 729 "C:\\RA2\\WOLPersonaInformation.cpp"
    WideStringClass unknown(Fetch_String("GUI:UnknownStats", NULL, __FILE__, __LINE__));
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_RANK), Rank == -1 ? unknown : Int_To_WideString(Rank));
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_POINTS), Points == -1 ? unknown : Int_To_WideString(Points));
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_WINS), Wins == -1 ? unknown : Int_To_WideString(Wins));
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_LOSSES), Losses == -1 ? unknown : Int_To_WideString(Losses));
    Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_DISCONNECTS), Disconnects == -1 ? unknown : Int_To_WideString(Disconnects));

    if (name.Get_Length() > 0) {
#line 737 "C:\\RA2\\WOLPersonaInformation.cpp"
        WideStringClass const label(Fetch_String("GUI:UserProfileLabel", NULL, __FILE__, __LINE__));
        wchar_t * text = new wchar_t[label.Get_Length() + name.Get_Length() + 1];
        swprintf(text, label, (char const *)name);
        Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_LABEL), text);
        delete [] text;
    } else {
        Set_Item_Text(GetDlgItem(dialog, IDC_PERSONA_LABEL), NullWString);
    }
}
