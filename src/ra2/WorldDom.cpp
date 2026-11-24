// C:\RA2\WorldDom.cpp (level-2 reconstruction of GAME.EXE 1.001)
// World Domination Tour main code: the faction selection dialog, the theater choice menu and the
// main WDT state loop, plus the current campaign globals and their accessors.
// Class names come from RTTI (FactionSelectDialogControl, OwnerDraw::SimpleDialogControl, Campaign,
// Conflict, CampaignProperties, WDTState, WDTTerritory, rc_ptr, VectorCursor, GraphicMenu,
// MixFileClass, CCFileClass); all other names are provisional.

// Dynamic initializer 0x354550: 16 bytes at 0xb10180, inside this TU's .bss (between the function
// statics 0xb1017c and 0xb10190), so it belongs to this TU and comes before the GAMECONST block.
struct WorldDomUnknownStruct {
    WorldDomUnknownStruct() : A(0), B(0), C(0), D(0) {}
    int A;
    int B;
    int C;
    int D;
};
static WorldDomUnknownStruct WorldDomUnknown;

#include "GAMECONST.H"

// ---- local declarations (to be moved to headers by the integrator) ----
#include <windows.h>
#include <stdio.h>
#include <stddef.h>
#include "RECT.H"
#include "SURFACE.H"
#include "VECTOR.H"

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x2eeb60 (also in ABSTYPE.H)

// Simple owned narrow string, one pointer (library code near 0x359260; name provisional).
class CharStringClass {
public:
    CharStringClass(char const * string);           // 0x359260
    CharStringClass(CharStringClass const & string); // 0x3592c0
    ~CharStringClass();                              // 0x359320
    char * Buffer;
};

// Simple owned wide string, one pointer (library code near 0x35b300; name provisional).
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);                    // 0x35b300
    ~WideStringClass();                                         // 0x35b390
    WideStringClass & operator = (WideStringClass const & string);   // 0x35b510
    operator wchar_t const * () const;                          // 0x35bd30 (Buffer or empty string)
    wchar_t * Buffer;
};

extern int ScreenWidth;                         // 0x83a710
extern Surface * AlternateSurface;              // 0x821c98

// File class hierarchy, as in WDTTerr.cpp (signatures provisional).
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

// level-2 1.001: Buffer (ctor 0x438140, dtor 0x438290) comes from BUFFER.H through SURFACE.H.

class CCFileClass : public CDFileClass {
public:
    CCFileClass(char const * filename);                     // 0x468b70
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual void Close();                                   // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

// Encryption key used for the MIX files (0x821350; class and name provisional).
class PKey;
extern PKey FastKey;

// RTTI .?AVMixFileClass@@ (vtable 0x791458, deleting destructor 0x592a60), size 0x28.
class MixFileClass {
public:
    MixFileClass(char const * filename, PKey const * key);   // 0x5920f0
    virtual ~MixFileClass();
private:
    char MixData[0x24];
};

// Reads a PCX file into a new surface (0x604cf0; signature provisional).
Surface * Read_PCX_File(FileClass & file, void * palette = NULL, void * buffer = NULL, long size = 0);

// RTTI .?AVGraphicMenu@@. Loaded from an INI section; Run returns the chosen item.
class GraphicMenu {
public:
    virtual ~GraphicMenu();
    static GraphicMenu * Load(CharStringClass const & ini, CharStringClass const & section);   // 0x4dd8f0
    int Run();                                                                                  // 0x4de070
};

// Settings object (0xa28758); only the screen size fields are named.
class OptionsClass {
public:
    void Save_Settings();               // 0x5d1850
    char Unknown00[0x20];
    int ScreenWidth;                    // +0x20
    int ScreenHeight;                   // +0x24
};
extern OptionsClass Options;

extern int WDTPlayingSoviet;            // 0xa256ec (Session + 0x124; name provisional)
extern int WDTUnknownB100A4;            // 0xb100a4

class WDTUnknownA57980 {
public:
    void Func_5759B0();                 // 0x5759b0
};
extern WDTUnknownA57980 WDTObjectA57980;   // 0xa57980

typedef bool (*MessageCallback)();
int Message_Box(wchar_t const * text, int buttons, MessageCallback callback, bool flag);   // 0x5bdd70 (6 = yes)
bool Func_732A40();                     // 0x732a40 (see CampScor.cpp), used as a message box callback
bool Set_Resolution(int width, int height);   // 0x540f00
void Func_514F50(int a, bool b);        // 0x514f50 (provisional, see CampScor.cpp)
void Play_Movie(char const * name, int theme, bool a, bool b, bool c, bool d);   // 0x59d0c0
bool Func_740520();                     // 0x740520
int Start_Quick_Match();                // 0x747f00 (wonline.cpp)

// Create_Dialog (0x5f72d0) wraps the caller's parameter for WM_INITDIALOG.
struct DialogInitParam {
    int ResourceID;
    LPARAM Param;
};
BOOL Standard_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam);  // 0x5f77c0
void Func_5F6B50(HWND dialog);          // 0x5f6b50 (provisional, WM_PAINT)
void Func_5DE390(HWND dialog);          // 0x5de390 (provisional, WM_PAINT)
void Func_5F6060(LPARAM lparam);        // 0x5f6060 (provisional, WM_DRAWITEM)

namespace OwnerDraw {

// RTTI .?AVDialogControl@OwnerDraw@@, vtable 0x792ae8 (slots 1..4 pure).
class DialogControl {
public:
    virtual ~DialogControl() {}
    virtual void End(HWND dialog, int result) = 0;
    virtual bool Is_Done() const = 0;
    virtual bool Virtual_03() = 0;
    virtual bool Virtual_04() = 0;
};

// RTTI .?AVSimpleDialogControl@OwnerDraw@@, vtable 0x792b00, size 0xc.
class SimpleDialogControl : public DialogControl {
public:
    SimpleDialogControl();                          // 0x5f8d70
    virtual ~SimpleDialogControl();                 // 0x5f8d90
    virtual void End(HWND dialog, int result);      // 0x5f8da0
    virtual bool Is_Done() const;                   // 0x5f8e20
    virtual bool Virtual_03();                      // 0x5f8e30
    virtual bool Virtual_04();                      // 0x5f8e40
    int Result;                                     // +04
    bool Done;                                      // +08
};

int Do_Dialog(int resource_id, DLGPROC proc, SimpleDialogControl * control);   // 0x5f8e50

}

// RTTI .?AVReferenceCounted@@, vtable 0x793cd4.
class ReferenceCounted {
public:
    ReferenceCounted() : ReferenceCount(0) {}
    virtual ~ReferenceCounted();                 // 0x230cb0 (deleting 0x230cf0)
    virtual bool Is_Kind(int kind) const;        // 0x230ce0
    virtual void Release();                      // 0x230cc0
    void Add_Ref() { ++ReferenceCount; }
    int ReferenceCount;
};

// RTTI .?AVrc_ptr_base@@, vtable 0x793ccc.
class rc_ptr_base {
public:
    rc_ptr_base();                               // 0x230a80
    rc_ptr_base(ReferenceCounted * pointer);     // 0x230a90
    rc_ptr_base(rc_ptr_base const & other);      // 0x230b00
    virtual ~rc_ptr_base();                      // 0x230ab0 (deleting 0x230b20)
    void Set(ReferenceCounted * pointer);        // 0x230ad0
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
    bool operator == (rc_ptr<T> const & other) const { return Pointer == other.Pointer; }
    bool operator != (rc_ptr<T> const & other) const { return Pointer != other.Pointer; }
};

// RTTI .?AV?$VectorCursor@...@@ (4 slots: destructor, Is_Valid, operator++, operator--).
template<class T, class V>
class VectorCursor {
public:
    VectorCursor(V & vector) : Vector(&vector), Index(0) {}
    virtual ~VectorCursor() {}
    virtual bool Is_Valid() const { return Index < Vector->ActiveCount; }
    virtual VectorCursor<T, V> & operator ++ () { ++Index; return *this; }
    virtual VectorCursor<T, V> & operator -- () { --Index; return *this; }
    T & operator * () const { return (*Vector)[Index]; }
    V * Vector;
    int Index;
};

// RTTI .?AVWDTState@@, vtable 0x79a198; RTTI .?AVWDTTerritory@@, vtable 0x79a168.
class WDTState : public ReferenceCounted {
};
class WDTTerritory : public ReferenceCounted {
};

namespace WorldDominationTour {

// RTTI .?AVCampaignProperties@WorldDominationTour@@ (see WDTProps.cpp).
class CampaignProperties : public ReferenceCounted {
public:
    static rc_ptr<CampaignProperties> Create(rc_ptr<WDTState> const & state);   // 0x321d40
};

// RTTI .?AVConflict@WorldDominationTour@@, vtable 0x799f0c. Only the territory is named.
class Conflict : public ReferenceCounted {
public:
    rc_ptr<WDTTerritory> Territory;     // +08
};

typedef VectorCursor<rc_ptr<Conflict>, DynamicVectorClass<rc_ptr<Conflict> > > ConflictCursor;

// RTTI .?AVCampaign@WorldDominationTour@@, vtable 0x799e84. Only the members used here.
class Campaign : public ReferenceCounted {
public:
    static rc_ptr<Campaign> Create(CharStringClass const & name, rc_ptr<CampaignProperties> const & properties);   // 0x71aaa0
    bool Is_Finished();                 // 0x71af10
    ConflictCursor Find_Conflict(int id);   // 0x71b2f0
    void Set_Side(int side);            // 0x71b380
    // +18: DynamicVectorClass<rc_ptr<Conflict> > Conflicts (read by Find_Conflict)
};

void Func_724B40(rc_ptr<Campaign> const & campaign, int theater);   // 0x724b40
bool Func_724B80(rc_ptr<Campaign> const & campaign, int theater);   // 0x724b80

extern CharStringClass CampaignName;    // 0xb0e5f0 (name provisional)

// RTTI .?AVFactionSelectDialogControl@WorldDominationTour@@, vtable 0x79a814, size 0x20.
class FactionSelectDialogControl : public OwnerDraw::SimpleDialogControl {
public:
    FactionSelectDialogControl() :
        Side(0),
        NormalImage(NULL),
        AlliedImage(NULL),
        SovietImage(NULL)
    {
        Read_Image(NormalImage, "WDTFSBSm.pcx");
        Load_Image(AlliedImage, "WDTFSAsm.pcx");
        Load_Image(SovietImage, "WDTFSSsm.pcx");
        CurrentImage = NormalImage;
    }
    virtual ~FactionSelectDialogControl();
    // The original reads the first image unconditionally and the other two only when still unset;
    // this helper split also reproduces the inline expansion budget seen in Faction_Select (0x354e10).
    static void Read_Image(Surface *& image, char const * filename)
    {
        CCFileClass file(filename);
        image = Read_PCX_File(file);
    }
    static void Load_Image(Surface *& image, char const * filename)
    {
        if (image == NULL) {
            CCFileClass file(filename);
            image = Read_PCX_File(file);
        }
    }
    void Mouse_Over(HWND dialog, POINT const & point);
    void Draw(HWND dialog);

    int Side;                   // +0C: 0 none, 2 Allies, 3 Soviets
    Surface * NormalImage;      // +10
    Surface * AlliedImage;      // +14
    Surface * SovietImage;      // +18
    Surface * CurrentImage;     // +1C
};

CharStringClass const & Side_Code(int side);
CharStringClass const & Region_Code(int region);
int Faction_Select();
int Theater_Choice(int side);
int Main(bool resume);

extern rc_ptr<Campaign> CurrentCampaign;
extern rc_ptr<Campaign> CurrentCampaign2;
extern int CurrentSide;
extern int CurrentTheater;

}
// ---- end of local declarations ----

using namespace WorldDominationTour;

// 0x354740 (static destructors 0x354830..0x354860)
CharStringClass const & WorldDominationTour::Side_Code(int side)
{
    static CharStringClass const dis("DIS");
    static CharStringClass const all("ALL");
    static CharStringClass const sov("SOV");
    switch (side) {
        case 1:
            return dis;
        case 2:
            return all;
        case 3:
            return sov;
        default:
        {
            static CharStringClass const unknown("xx");
            return unknown;
        }
    }
}

// 0x354870 (static destructors 0x354960..0x354990)
CharStringClass const & WorldDominationTour::Region_Code(int region)
{
    static CharStringClass const na("NA");
    static CharStringClass const eu("EU");
    static CharStringClass const as("AS");
    switch (region) {
        case 1:
            return na;
        case 2:
            return eu;
        case 3:
            return as;
        default:
        {
            static CharStringClass const unknown("XX");
            return unknown;
        }
    }
}

// 0x3549a0 (scalar deleting destructor 0x3558e0)
FactionSelectDialogControl::~FactionSelectDialogControl()
{
    delete NormalImage;
    delete AlliedImage;
    delete SovietImage;
}

static inline bool In_Box(POINT const & point, int left, int top, int right, int bottom)
{
    return point.x >= left && point.x < right && point.y >= top && point.y < bottom;
}

// 0x3549e0
void FactionSelectDialogControl::Mouse_Over(HWND dialog, POINT const & point)
{
    if (Is_Done()) {
        return;
    }

    CurrentImage = NormalImage;
    int side = 0;
    if (In_Box(point, 16, 20, 364, 136) || In_Box(point, 130, 100, 300, 216) || In_Box(point, 175, 216, 245, 262)) {
        CurrentImage = AlliedImage;
        side = 2;
    } else if (In_Box(point, 252, 180, 466, 382) || In_Box(point, 212, 262, 496, 422)) {
        CurrentImage = SovietImage;
        side = 3;
    }

    if (Side != side) {
        Side = side;
        InvalidateRect(dialog, NULL, FALSE);
    }
}

// 0x354ae0
void FactionSelectDialogControl::Draw(HWND)
{
    if (AlternateSurface != NULL && CurrentImage != NULL) {
        RectangleStruct rect = CurrentImage->Get_Rect();
        AlternateSurface->Fill_Rect(rect, 0);
        AlternateSurface->Copy_From(rect, *CurrentImage, rect, false, true);
    }
}

// 0x354b60; the original __LINE__ values of the three Fetch_String calls are 176, 179 and 182.
static BOOL CALLBACK Faction_Select_Dialog_Proc(HWND dialog, UINT message, WPARAM wparam, LPARAM lparam)
{
    if (message == WM_INITDIALOG && lparam != 0) {
        SetWindowLongA(dialog, DWL_USER, ((DialogInitParam *)lparam)->Param);
    }

    BOOL result = Standard_Dialog_Proc(dialog, message, wparam, lparam);
    if (result) return result;

    FactionSelectDialogControl * control = (FactionSelectDialogControl *)GetWindowLongA(dialog, DWL_USER);

    switch (message) {
        case WM_NCHITTEST:
        {
            POINT point;
            point.x = LOWORD(lparam);
            point.y = HIWORD(lparam);
            control->Mouse_Over(dialog, point);
            return FALSE;
        }

        case WM_DRAWITEM:
            Func_5F6060(lparam);
            return TRUE;

        case WM_PAINT:
            Func_5F6B50(dialog);
            control->Draw(dialog);
            Func_5DE390(dialog);
            ValidateRect(dialog, NULL);
            return TRUE;

        case WM_ERASEBKGND:
            return TRUE;

        case WM_COMMAND:
            if (LOWORD(wparam) == 0x686) {
                control->End(dialog, -1);
                return FALSE;
            }
            break;

        case WM_LBUTTONUP:
            if (control->Side != 0) {
                control->End(dialog, 1);
            }
            break;

        case 0x497:
            return FALSE;

        case 0x4e9:
            if (*(HWND *)lparam == dialog) {
                wchar_t const * text;
                switch (control->Side) {
                    case 2:
#line 176 "C:\\RA2\\WorldDom.cpp"
                        text = Fetch_String("WDT:FactionSelectAlliesToolTip", NULL, __FILE__, __LINE__);
                        break;
                    case 3:
#line 179
                        text = Fetch_String("WDT:FactionSelectSovietToolTip", NULL, __FILE__, __LINE__);
                        break;
                    default:
#line 182
                        text = Fetch_String("WDT:FactionSelectToolTip", NULL, __FILE__, __LINE__);
                        break;
                }
                *(WideStringClass *)(lparam + 8) = text;
                return FALSE;
            }
            break;
    }
    return FALSE;
}

// 0x354e10 (no direct callers; inlined into Main)
int WorldDominationTour::Faction_Select()
{
    Func_514F50(0, true);
    FactionSelectDialogControl control;
    OwnerDraw::Do_Dialog(0x125, Faction_Select_Dialog_Proc, &control);
    return control.Side;
}

// 0x354f70
int WorldDominationTour::Theater_Choice(int side)
{
    char section[128];
    sprintf(section, "TheaterChoice%sMenu", Side_Code(side).Buffer);
    GraphicMenu * menu = GraphicMenu::Load("WDTChoice.ini", section);
    if (menu == NULL) {
        return 0;
    }

    int choice = menu->Run();
    delete menu;
    switch (choice) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
    }
    return 0;
}

// Also needed for the inline expansion budget of Main (its case 1 calls the out-of-line
// FactionSelectDialogControl constructor and destructor).
static inline bool File_Available(char const * filename)
{
    return CCFileClass(filename).Is_Available();
}

// 0x355030; the original __LINE__ of the Fetch_String call is 385.
int WorldDominationTour::Main(bool resume)
{
    if (ScreenWidth > 640) {
#line 385
        WideStringClass text(Fetch_String("WOL:WDTResolutionQuery", NULL, __FILE__, __LINE__));
        if (Message_Box(text, 4, Func_732A40, true) != 6) {
            return 0;
        }
        if (!Set_Resolution(640, 480)) {
            return 0;
        }
        Options.ScreenWidth = 640;
        Options.ScreenHeight = 480;
        Options.Save_Settings();
    }

    MixFileClass * wdtmix = NULL;
    MixFileClass * voxmix = NULL;
    MixFileClass * localmix = NULL;
    if (File_Available("WDT.MIX")) {
        wdtmix = new MixFileClass("WDT.MIX", &FastKey);
    }
    if (File_Available("WDTVOX.MIX")) {
        voxmix = new MixFileClass("WDTVOX.MIX", &FastKey);
    }
    if (File_Available("Local.MIX")) {
        localmix = new MixFileClass("Local.MIX", &FastKey);
    }
    if (wdtmix == NULL || localmix == NULL) {
        delete wdtmix;
        delete localmix;
        delete voxmix;
        return 0;
    }

    // States: 1 faction selection, 2 theater movie (not entered from here), 3 theater choice,
    // 4 campaign map, 5 battle; 0 leaves, 6 finishes the tour.
    int state = resume ? 4 : 1;
    while (state != 0 && state != 6) {
        switch (state) {
            case 1:
                CurrentSide = Faction_Select();
                state = CurrentSide ? 4 : 0;
                break;

            case 2:
            {
                char movie[128];
                sprintf(movie, "WDTTheater%02.VQA", CurrentSide);
                if (CCFileClass(movie).Is_Available()) {
                    Play_Movie(movie, -1, false, true, false, false);
                }
                state = 3;
                break;
            }

            case 3:
                CurrentTheater = Theater_Choice(CurrentSide);
                state = CurrentTheater ? 4 : 1;
                break;

            case 4:
            {
                if (!Func_740520()) {
                    state = 0;
                    break;
                }
                rc_ptr<Campaign> campaign = CurrentCampaign;
                if (campaign.Get() == NULL) {
                    return 0;
                }
                campaign->Set_Side(CurrentSide);
                if (campaign->Is_Finished()) {
                    rc_ptr<Campaign> campaign2 = CurrentCampaign2;
                    if (campaign2.Get() != NULL && !campaign2->Is_Finished()) {
                        Func_724B40(campaign2, CurrentTheater);
                    }
                }
                WDTPlayingSoviet = (CurrentSide == 3);
                if (Func_724B80(campaign, CurrentTheater)) {
                    WDTUnknownB100A4 = 0;
                    WDTObjectA57980.Func_5759B0();
                    state = 5;
                } else {
                    state = 1;
                }
                break;
            }

            case 5:
                if (Start_Quick_Match() == 1) {
                    state = 6;
                } else {
                    state = 4;
                }
                break;
        }
    }

    delete wdtmix;
    delete localmix;
    delete voxmix;
    return state == 6;
}

// Current World Domination Tour data (0xb101f8..0xb10240; names provisional).
class WDTOwnedPointer {
public:
    WDTOwnedPointer() : Pointer(NULL) {}
    ~WDTOwnedPointer() { Reset(); }
    void Reset() { if (Pointer != NULL) { delete Pointer; Pointer = NULL; } }
    char * Pointer;
};

static WDTOwnedPointer OwnedPointer1;                       // 0xb101f8 (initializer 0x355530)
static WDTOwnedPointer OwnedPointer2;                       // 0xb10208 (initializer 0x355570)
static rc_ptr<WDTState> CurrentState;                       // 0xb10200 (initializer 0x3555b0)
static rc_ptr<WDTState> CurrentState2;                      // 0xb10218 (initializer 0x3555f0)
rc_ptr<Campaign> WorldDominationTour::CurrentCampaign;      // 0xb10210 (initializer 0x355630)
rc_ptr<Campaign> WorldDominationTour::CurrentCampaign2;     // 0xb10220 (initializer 0x355670)
int WorldDominationTour::CurrentSide;                       // 0xb1023c
int WorldDominationTour::CurrentTheater;                    // 0xb10240

// 0x3556b0
rc_ptr<WDTState> & Current_State()
{
    return CurrentState;
}

// 0x3556c0
void Set_Current_State(rc_ptr<WDTState> const & state)
{
    CurrentState = state;
    CurrentCampaign = Campaign::Create(CampaignName, CampaignProperties::Create(state));
}

// 0x355730
rc_ptr<WDTState> & Current_State2()
{
    return CurrentState2;
}

// 0x355740
void Set_Current_State2(rc_ptr<WDTState> const & state)
{
    CurrentState2 = state;
    CurrentCampaign2 = Campaign::Create(CampaignName, CampaignProperties::Create(state));
}

// 0x3557b0
char * Owned_Pointer1()
{
    return OwnedPointer1.Pointer;
}

// 0x3557c0
void Set_Owned_Pointer1(char * pointer)
{
    OwnedPointer1.Reset();
    OwnedPointer1.Pointer = pointer;
}

// 0x3557e0
char * Owned_Pointer2()
{
    return OwnedPointer2.Pointer;
}

// 0x3557f0
void Set_Owned_Pointer2(char * pointer)
{
    OwnedPointer2.Reset();
    OwnedPointer2.Pointer = pointer;
}

// 0x355810
rc_ptr<Campaign> & Current_Campaign()
{
    return CurrentCampaign;
}

// 0x355820
rc_ptr<Campaign> & Current_Campaign2()
{
    return CurrentCampaign2;
}

// The territory of the conflict at the cursor, or none.
static inline rc_ptr<WDTTerritory> Cursor_Territory(ConflictCursor const & cursor)
{
    return cursor.Is_Valid() ? (*cursor)->Territory : rc_ptr<WDTTerritory>();
}

// 0x355830
rc_ptr<WDTTerritory> Conflict_Territory(int id)
{
    ConflictCursor cursor = CurrentCampaign->Find_Conflict(id);
    return Cursor_Territory(cursor);
}

// 0x3558d0 (no callers found)
bool WDT_Available()
{
    return true;
}
