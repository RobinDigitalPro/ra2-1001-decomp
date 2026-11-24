// C:\RA2\Init.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Reconstructed so far: the shared header initializers and the keyboard command classes
// (CommandClass and its 56 subclasses) with the function that creates them (0x516930).
//
// The command classes are defined in Init.CPP itself: their string lookups pass "C:\RA2\Init.CPP"
// (0x7c69f0) and __LINE__ values 5689..7799. Their methods are inline (defined in the class
// bodies); the compiler emits them after Init.CPP's own functions, at 0x51a3e0..0x51d5df, together
// with the other inline/template functions that Init.CPP uses (0x51a280..0x51a3db CDFileClass,
// CCFileClass, INIClass, CCINIClass; 0x51d5e0.. vector and index templates). Execute bodies call
// the helpers of UICmnds.cpp.
//
// Generated file: edit W/analysis/level2/commands/Init.tmpl.cpp or members.cpp and run gen.py there.
// Class names come from RTTI; all other names (slots 5..7, globals, helpers) are provisional.
#include "GAMECONST.H"
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <windows.h>
#include "ABSTRACT.H"
#include "POINT.H"
#include "SURFACE.H"
#include "BUFFER.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
wchar_t const * Text_To_Wide(char const * text);    // 0x6eee20 (name provisional)

// Copy of the UICmnds.cpp vector templates (Add returns bool: 0x51d8a0 returns al).
template<class T> class VectorClass {
public:
    virtual ~VectorClass();
    virtual bool operator == (VectorClass<T> const & vector) const;
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr);
    virtual int ID(T const & object);
    virtual T Fetch(int index) const { return Vector[index]; }

    T & operator[](unsigned index) { return Vector[index]; }
    T const & operator[](unsigned index) const { return Vector[index]; }
    int Length() const { return VectorMax; }

    T * Vector;
    int VectorMax;
    bool IsInitialized;
    bool IsAllocated;
};

template<class T> class DynamicVectorClass : public VectorClass<T> {
public:
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr) { return VectorClass<T>::ID(ptr); }
    virtual int ID(T const & object);

    int Count() const { return ActiveCount; }
    bool Add(T const & object);

    int ActiveCount;
    int GrowthStep;
};

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

// Index of (key, command) pairs, as in Options.CPP (only the declarations used here).
template<class T, class U>
class IndexClass {
public:
    bool Add_Index(T const & id, U const & data);
    bool Remove_Index(T const & id);
    bool Is_Present(T const & id) const;
};

class TechnoTypeClass;
class ObjectTypeClass;

// Session object at 0xa255c8 (see Event.CPP and UICmnds.cpp).
class SessionClass {
public:
    int Type;                                   // +0x000, 0 = single player, 3/4 = network games
    char Unknown4[0x62C - 0x4];
    bool IsDebugAllowed;                        // +0x62c (name provisional)
    bool IsDebugInfo;                           // +0x62d, multiplayer debug display (name provisional)
};
extern SessionClass Session;                    // 0xa255c8

inline CoordStruct & operator -= (CoordStruct & a, CoordStruct const & b)
{
    a.X -= b.X;
    a.Y -= b.Y;
    a.Z -= b.Z;
    return a;
}

struct CellClass {
    char Unknown0[0x11B];
    signed char Level;                          // +0x11b, height level (name provisional)
};

class ScenarioClass {
public:
    char Unknown0[0x2214];
    CellStruct Views[4];                        // +0x2214, view bookmarks (name provisional)
};
extern ScenarioClass * Scen;                    // 0xa255c0

// Object hierarchy (as in UICmnds.cpp); only the slots used here are named.
class ObjectClass : public AbstractClass {
public:
    virtual void Slot_024(); virtual void Slot_025(); virtual void Slot_026(); virtual void Slot_027();
    virtual void Slot_028(); virtual void Slot_029(); virtual void Slot_030(); virtual void Slot_031();
    virtual TechnoTypeClass * Techno_Type_Class() const;    // slot 32 (+0x80)
    virtual ObjectTypeClass * Class_Of() const;             // slot 33 (+0x84)
    virtual void Slot_034(); virtual void Slot_035(); virtual void Slot_036(); virtual void Slot_037();
    virtual bool Slot_038_Query() const;                    // slot 38 (+0x98), meaning unknown
    virtual bool Slot_039_Query() const;                    // slot 39 (+0x9c), meaning unknown
    virtual void Slot_040(); virtual void Slot_041(); virtual void Slot_042(); virtual void Slot_043();
    virtual void Slot_044(); virtual void Slot_045(); virtual void Slot_046(); virtual void Slot_047();
    virtual void Slot_048(); virtual void Slot_049(); virtual void Slot_050(); virtual void Slot_051();
    virtual void Slot_052(); virtual void Slot_053(); virtual void Slot_054(); virtual void Slot_055();
    virtual void Slot_056(); virtual void Slot_057(); virtual void Slot_058(); virtual void Slot_059();
    virtual void Slot_060(); virtual void Slot_061(); virtual void Slot_062(); virtual void Slot_063();
    virtual void Slot_064(); virtual void Slot_065(); virtual void Slot_066(); virtual void Slot_067();
    virtual void Slot_068(); virtual void Slot_069(); virtual void Slot_070(); virtual void Slot_071();
    virtual void Slot_072(); virtual void Slot_073(); virtual void Slot_074(); virtual void Slot_075();
    virtual void Slot_076(); virtual void Slot_077(); virtual void Slot_078(); virtual void Slot_079();
    virtual bool Select();                                  // slot 80 (+0x140)
    virtual void Unselect();                                // slot 81 (+0x144)
    virtual void Slot_082(); virtual void Slot_083(); virtual void Slot_084(); virtual void Slot_085();
    virtual void Slot_086(); virtual void Slot_087(); virtual void Slot_088(); virtual void Slot_089();
    virtual void Slot_090(); virtual void Slot_091(); virtual void Slot_092(); virtual void Slot_093();
    virtual void Slot_094(); virtual void Slot_095(); virtual void Slot_096(); virtual void Slot_097();
    virtual void Slot_098(); virtual void Slot_099(); virtual void Slot_100(); virtual void Slot_101();
    virtual void Slot_102(); virtual void Slot_103(); virtual void Slot_104(); virtual void Slot_105();
    virtual void Slot_106();
    virtual int Slot_107(int a, int b);                    // slot 107 (+0x1ac), meaning unknown
    virtual void Slot_108(); virtual void Slot_109(); virtual void Slot_110(); virtual void Slot_111();
    virtual void Slot_112(); virtual void Slot_113(); virtual void Slot_114(); virtual void Slot_115();

    char Unknown24[0x76 - 0x24];
    bool IsInLimbo;                             // +0x76 (name provisional)
    char Unknown77[0xAC - 0x77];
};

class TechnoClass : public ObjectClass {
public:
    char UnknownAC[0x1B4 - 0xAC];
    HouseClass * House;                         // +0x1b4
};

class BuildingTypeClass {
public:
    char Unknown0[0x1353];
    bool IsBaseCenter;                          // +0x1353, construction yard (name provisional)
};

class BuildingClass : public TechnoClass {
public:
    char Unknown1B8[0x32B - 0x1B8];
    bool Field_32B;                             // +0x32b (meaning unknown)
    char Unknown32C[0x418 - 0x32C];
    BuildingTypeClass * Class;                  // +0x418
};

class UnitTypeClass;
class UnitClass : public TechnoClass {
public:
    char Unknown1B8[0x5AC - 0x1B8];
    UnitTypeClass * Class;                      // +0x5ac
};

extern DynamicVectorClass<BuildingClass *> Buildings;  // 0xa28738 (name provisional)
extern DynamicVectorClass<UnitClass *> Units;          // 0x84e4c8 (name provisional)

struct TypeListStruct {
    int Unknown0;                               // layout unknown
};
class RulesClass {
public:
    char Unknown0[0x9D0];
    TypeListStruct BaseUnit;                    // +0x9d0 (name provisional)
};
extern RulesClass * Rule;                       // 0x821b88

inline bool operator == (CoordStruct const & a, CoordStruct const & b)
{
    return a.X == b.X && a.Y == b.Y && a.Z == b.Z;
}

inline bool operator != (CoordStruct const & a, CoordStruct const & b)
{
    return a.X != b.X || a.Y != b.Y || a.Z != b.Z;
}

class MessageListClass {
public:
    void * Add_Message(wchar_t const * name, int id, wchar_t const * text, int color,
        int style, int timeout, bool flag);     // 0x5b1980
};
extern MessageListClass SessionMessages;        // 0xa25fa0  (Session + 0x9d8)

// Sidebar strip (column) of 0xe64 bytes; four of them at Map + 0x1540.
class StripClass {
public:
    bool Is_Tab_Enabled() const;                // 0x676e90 (name provisional)
    char Data[0xE64];
};

class Object_A28E20;
extern Object_A28E20 Object_A28E20_Instance;    // 0xa28e20 (meaning unknown)

class GScreenClass {
public:
    virtual void Flag_To_Redraw(int complete);  // 0x4e0030
};
class MouseClass : public GScreenClass {
public:
    void Func_49C560(int a);                    // 0x49c560 (meaning unknown; -1 toggles sell mode)
    void Func_49C600(int a, int b);             // 0x49c600 (meaning unknown)
    void Func_49C720(int a);                    // 0x49c720 (meaning unknown)
    void Func_49C7C0(int a);                    // 0x49c7c0 (meaning unknown; -1 toggles repair mode)
    void Func_49E0E0();                         // 0x49e0e0 (meaning unknown)
    ObjectClass * Next_Object(ObjectClass * object);    // 0x49a3b0 (name provisional)
    ObjectClass * Prev_Object(ObjectClass * object);    // 0x49a450 (name provisional)
    ObjectClass * Following() const;            // 0x49e970 (name provisional)
    void Follow(ObjectClass * object);          // 0x49e990 (name provisional)
    CellStruct Func_4992B0(Object_A28E20 & object);     // 0x4992b0 (meaning unknown)
    CellClass & operator [] (CoordStruct const & coord);    // 0x545490 (name provisional)
    int Get_Height(CoordStruct const & coord);  // 0x557070 (name provisional)
    void Scroll(bool up, int column);           // 0x672590, column -1 = both (name provisional)
    void Page(bool up, int column);             // 0x672650, column -1 = both (name provisional)
    void Activate_Tab(int tab);                 // 0x673150 (name provisional)

    char Unknown4[0x11A4 - 0x4];
    int Field_11A4;                             // +0x11a4 (meaning unknown)
    char Unknown11A8[0x1540 - 0x11A8];
    StripClass Column[4];                       // +0x1540
};
extern MouseClass Map;                          // 0x81a820

class TacticalClass {
public:
    void Set_Tactical_Position(CoordStruct const & coord);  // 0x69bcf0 (name provisional)
    Point2D Get_Tactical_Position() const;      // 0x69be10 (name provisional)
    CellStruct Pixel_To_Cell(Point2D const & pixel) const;  // 0x69c210 (name provisional)
};
extern TacticalClass * TacticalMap;             // 0x821cac

extern DynamicVectorClass<ObjectClass *> CurrentObjects;    // 0xa288a0 (name provisional)
extern CellStruct RadarEventCell;               // 0xa9e2e0, last radar event (name provisional)
extern bool ExtraSyncInfo;                      // 0xa9de44 (name provisional)
extern bool CursorCheat;                        // 0xa292fc (name provisional)
void Unselect_All();                            // 0x482960 (name provisional)
void Options_Dialog();                          // 0x61b0e0 (name provisional)
void Page_User_Dialog();                        // 0x61b190 (name provisional)
void Load_Hotkeys();                            // 0x5187b0, reads KEYBOARD.INI (name provisional)

// Network game data used by the Taunt command (names provisional; probably members of Session).
struct NodeNameType {
    wchar_t Name[0x24];                         // +0x00
    unsigned char Color;                        // +0x48 (name provisional)
    unsigned char Field_49;                     // +0x49, house colour index (name provisional)
};
extern DynamicVectorClass<NodeNameType *> Players;   // 0xa27da8 (Session + 0x27e0)
extern int Session_A256E4;                      // 0xa256e4 (Session + 0x11c, meaning unknown)
extern bool TauntFlags[10];                     // 0xa27446 (Session + 0x1e7e): per house, then LAN/Internet
extern wchar_t Session_A2793E[];                // 0xa2793e (Session + 0x2376, meaning unknown)
int Func_5B6C30(wchar_t const * text);          // 0x5b6c30 (meaning unknown)
char const * Wide_To_Text(wchar_t const * text);    // 0x6eedc0 (name provisional)
void Play_Taunt(unsigned char taunt);           // 0x70ab70 (name provisional)

class HouseTypeClass {
public:
    char Unknown0[0x1A5];
    bool Field_1A5;                             // +0x1a5 (meaning unknown)
};

class HouseClass : public AbstractClass {
public:
    bool Is_Player_Control() const;             // 0x4f47b0 (name provisional)
    UnitTypeClass * Func_4EEBF0(TypeListStruct & list) const;   // 0x4eebf0 (meaning unknown)

    char Unknown24[0x34 - 0x24];
    HouseTypeClass * Class;                     // +0x34
    char Unknown38[0x228 - 0x38];
    int CurUnits;                               // +0x228 (name provisional)
    char Unknown22C[0x230 - 0x22C];
    int CurBuildings;                           // +0x230 (name provisional)
    char Unknown234[0x15F16 - 0x234];
    wchar_t IniName[1];                         // +0x15f16, player name (name provisional)
};
extern DynamicVectorClass<HouseClass *> Houses; // 0xa1a5c8 (name provisional)
extern HouseClass * PlayerPtr;                  // 0xa1e0e4

// Network connection manager at 0xa285c8 (class name unknown; methods as in Westwood's IPX manager).
class ConnectionManagerClass {
public:
    int Num_Connections();                      // 0x524450
    int Connection_ID(int index);               // 0x524460
    wchar_t const * Connection_Name(int id);    // 0x524480
    void * Connection_Address(int id);          // 0x5244c0
    int Send_Private_Message(void * buf, int buflen, int ack_req, void * address);  // 0x524560
    void Service();                             // 0x524890
};
extern ConnectionManagerClass Ipx;              // 0xa285c8

// Part of the network packet built by the Taunt command (0x39 bytes are sent).
#pragma pack(push, 1)
struct TauntPacketType {
    int Command;                                // +0x00, 0x1d = taunt
    char Name[0x2C];                            // +0x04, sender name
    union {
        struct {
            unsigned char Number:4;             // +0x30, taunt 1..8
            unsigned char Color:4;
        } Bits;
        unsigned char Value;
    } Taunt;
    int Field_31;                               // +0x31
    int Field_35;                               // +0x35
    char Unknown39[0x1C8 - 0x39];
};
#pragma pack(pop)

// File classes (RTTI: CCFileClass : CDFileClass : BufferIOFileClass : RawFileClass : FileClass,
// 17 slots). Only what the screen capture uses; slot names follow the Westwood FileClass.
class BufferIOFileClass {
public:
    virtual ~BufferIOFileClass();               // 0x42f250
    virtual char const * File_Name() const;
    virtual char const * Set_Name(char const * filename);
    virtual int Create();
    virtual int Delete();
    virtual bool Is_Available(int forced = 0);  // slot 5
    char Unknown4[0x54 - 0x4];
};

class CDFileClass : public BufferIOFileClass {
public:
    virtual ~CDFileClass() {}                   // out-of-line copy 0x51a280
};

class CCFileClass : public CDFileClass {
public:
    CCFileClass(char const * filename);         // 0x468b70
    virtual ~CCFileClass() { Position = 0; }    // out-of-line copy 0x51a290

    Buffer Data;                           // +0x54
    long Position;                              // +0x60
};

class PaletteClass;
extern PaletteClass GamePalette;                // 0x820150 (name provisional)
int Write_PCX_File(CCFileClass & file, Surface & pic, PaletteClass * palette);   // 0x755a60 (name provisional)

class WWMouseClass {
public:
    virtual void Slot_0(); virtual void Slot_1(); virtual void Slot_2();
    virtual void Hide_Mouse();                  // slot 3 (name provisional)
    virtual void Show_Mouse();                  // slot 4 (name provisional)
};
extern WWMouseClass * WWMouse;                  // 0x821fa8 (name provisional)
extern Surface * HiddenSurface;                // 0x821c94 (name provisional)
extern Surface * VisibleSurface;                 // 0x821c90 (name provisional)
extern HWND MainWindow;                         // 0xb0de50 (name provisional)

// UICmnds.cpp helpers called by the Execute bodies.
void Deploy_Command();                          // 0x6ea930
void Guard_Command();                           // 0x6eab00
void Stop_Command();                            // 0x6eabb0
void All_To_Cheer_Command();                    // 0x6eac40
void Scatter_Command();                         // 0x6eacf0
void Create_Team_Command(int team);             // 0x6ead70
void Select_Team_Command(int team);             // 0x6eae60
void Center_Team_Command(int team);             // 0x6eaf40
void Add_Team_Command(int team);                // 0x6eb060
void Alliance_Command();                        // 0x6eb1f0
void Delete_Command();                          // 0x6eb300
void Place_Beacon_Command();                    // 0x6eb320
void Planning_Mode_Begin(bool flag);            // 0x6eb330
void Planning_Mode_End(bool flag);              // 0x6eb350
void Combatant_Select_Command(bool clear);      // 0x6ebb60
void Type_Select_Key_Down();                    // 0x6ec490
void Type_Select_Key_Up();                      // 0x6ec4b0
void Health_Nav_Command(bool clear);            // 0x6ec9c0
void Veterancy_Nav_Command(bool clear);         // 0x6eccf0

// ---- end of local declarations ----

// Key number modifier bits (WWKeyboardClass key numbers).
enum {
    KN_SHIFT_BIT = 0x100,
    KN_CTRL_BIT = 0x200,
    KN_ALT_BIT = 0x400,
    KN_RLSE_BIT = 0x800
};

// .bss
static char NameBuffer[0xA0];                   // 0xa290dc (size provisional)
static wchar_t UINameBuffer[0xC0];              // 0xa2917c (size provisional)

// .data
static int LastTauntTime = -1;                  // 0x7c666c

/*
**  Keyboard command (RTTI .?AVCommandClass@@, vtable 0x78f3ec, 9 slots). The pure slots point
**  to 0x4b85d0. Slot names provisional.
*/
class CommandClass {
public:
    virtual ~CommandClass() {}
    virtual char const * Get_Name() const = 0;              // slot 1, INI entry name
    virtual wchar_t const * Get_UI_Name() const { return Get_Description(); }   // slot 2
    virtual wchar_t const * Get_Category() const = 0;       // slot 3
    virtual wchar_t const * Get_Description() const = 0;    // slot 4
    virtual bool Uses_Modifiers(int key) const { return false; }                // slot 5
    virtual bool Accepts_Key(int key) const { return (key & KN_RLSE_BIT) == 0; } // slot 6
    virtual bool Virtual_07(int key) const { return false; }                    // slot 7
    virtual void Execute(int key) const = 0;                // slot 8
};

// Shared bodies of the View and SetView commands (the original repeats them per class).
inline void Jump_To_View(int index)
{
    CellStruct const & cell = Scen->Views[index];
    CoordStruct coord(cell.X * 256 + 128, cell.Y * 256 + 128, 0);
    coord.Z = Map.Get_Height(coord);
    TacticalMap->Set_Tactical_Position(coord);
    if (Map.Field_11A4) {
        Map.Func_4992B0(Object_A28E20_Instance);
    }
}

inline void Set_View(int index)
{
    Point2D pixel = TacticalMap->Get_Tactical_Position();
    Scen->Views[index] = TacticalMap->Pixel_To_Cell(pixel);
}

// RTTI .?AVCreateTeamCommandClass@@, vtable 0x78ec6c
class CreateTeamCommandClass : public CommandClass {
public:
    CreateTeamCommandClass(int number) : Number(number) {}
    virtual char const * Get_Name() const
    {
        sprintf(NameBuffer, "TeamCreate_%d", Number);
        return NameBuffer;
    }
    virtual wchar_t const * Get_UI_Name() const
    {
#line 5689 "C:\\RA2\\Init.CPP"
        swprintf(UINameBuffer, Fetch_String("TXT_CREATE_TEAM", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
#line 5691
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_TEAM", NULL, __FILE__, __LINE__); }
    virtual wchar_t const * Get_Description() const
    {
#line 5693
        swprintf(UINameBuffer, Fetch_String("TXT_CREATE_TEAM_DESC", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
    virtual void Execute(int) const { Create_Team_Command(Number); }

    int Number;                                 // +0x04, team or taunt number 1..10
};

// RTTI .?AVSetStructureTabCommandClass@@, vtable 0x78ed0c
class SetStructureTabCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "StructureTab"; }
#line 5710
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_STRUCTURE_TAB", NULL, __FILE__, __LINE__); }
#line 5712
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 5714
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_STRUCTURE_TAB_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { if (Map.Column[0].Is_Tab_Enabled()) Map.Activate_Tab(0); }
};

// RTTI .?AVSetDefenseTabCommandClass@@, vtable 0x78ece4
class SetDefenseTabCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "DefenseTab"; }
#line 5731
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_DEFENSE_TAB", NULL, __FILE__, __LINE__); }
#line 5733
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 5735
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_DEFENSE_TAB_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { if (Map.Column[1].Is_Tab_Enabled()) Map.Activate_Tab(1); }
};

// RTTI .?AVSetInfantryTabCommandClass@@, vtable 0x78ec94
class SetInfantryTabCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "InfantryTab"; }
#line 5752
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_INFANTRY_TAB", NULL, __FILE__, __LINE__); }
#line 5754
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 5756
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_INFANTRY_TAB_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { if (Map.Column[2].Is_Tab_Enabled()) Map.Activate_Tab(2); }
};

// RTTI .?AVSetUnitTabCommandClass@@, vtable 0x78ecbc
class SetUnitTabCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "UnitTab"; }
#line 5773
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_UNIT_TAB", NULL, __FILE__, __LINE__); }
#line 5775
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 5777
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_UNIT_TAB_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { if (Map.Column[3].Is_Tab_Enabled()) Map.Activate_Tab(3); }
};

// RTTI .?AVSelectTeamCommandClass@@, vtable 0x78f414
class SelectTeamCommandClass : public CommandClass {
public:
    SelectTeamCommandClass(int number) : Number(number) {}
    virtual char const * Get_Name() const
    {
        sprintf(NameBuffer, "TeamSelect_%d", Number);
        return NameBuffer;
    }
    virtual wchar_t const * Get_UI_Name() const
    {
#line 5806
        swprintf(UINameBuffer, Fetch_String("TXT_SELECT_TEAM", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
#line 5808
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_TEAM", NULL, __FILE__, __LINE__); }
    virtual wchar_t const * Get_Description() const
    {
#line 5810
        swprintf(UINameBuffer, Fetch_String("TXT_SELECT_TEAM_DESC", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
    virtual void Execute(int) const { Select_Team_Command(Number); }

    int Number;                                 // +0x04, team or taunt number 1..10
};

// RTTI .?AVAddTeamCommandClass@@, vtable 0x78f43c
class AddTeamCommandClass : public CommandClass {
public:
    AddTeamCommandClass(int number) : Number(number) {}
    virtual char const * Get_Name() const
    {
        sprintf(NameBuffer, "TeamAddSelect_%d", Number);
        return NameBuffer;
    }
    virtual wchar_t const * Get_UI_Name() const
    {
#line 5840
        swprintf(UINameBuffer, Fetch_String("TXT_ADD_SELECT_TEAM", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
#line 5842
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_TEAM", NULL, __FILE__, __LINE__); }
    virtual wchar_t const * Get_Description() const
    {
#line 5844
        swprintf(UINameBuffer, Fetch_String("TXT_ADD_SELECT_TEAM_DESC", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
    virtual void Execute(int) const { Add_Team_Command(Number); }

    int Number;                                 // +0x04, team or taunt number 1..10
};

// RTTI .?AVCenterTeamCommandClass@@, vtable 0x78f464
class CenterTeamCommandClass : public CommandClass {
public:
    CenterTeamCommandClass(int number) : Number(number) {}
    virtual char const * Get_Name() const
    {
        sprintf(NameBuffer, "TeamCenter_%d", Number);
        return NameBuffer;
    }
    virtual wchar_t const * Get_UI_Name() const
    {
#line 5875
        swprintf(UINameBuffer, Fetch_String("TXT_CENTER_TEAM", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
#line 5877
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_TEAM", NULL, __FILE__, __LINE__); }
    virtual wchar_t const * Get_Description() const
    {
#line 5879
        swprintf(UINameBuffer, Fetch_String("TXT_CENTER_TEAM_DESC", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
    virtual void Execute(int) const { Center_Team_Command(Number); }

    int Number;                                 // +0x04, team or taunt number 1..10
};

// RTTI .?AVTauntCommandClass@@, vtable 0x78f48c
class TauntCommandClass : public CommandClass {
public:
    TauntCommandClass(int number) : Number(number) {}
    virtual char const * Get_Name() const
    {
        sprintf(NameBuffer, "Taunt_%d", Number);
        return NameBuffer;
    }
    virtual wchar_t const * Get_UI_Name() const
    {
#line 5914
        swprintf(UINameBuffer, Fetch_String("TXT_TAUNT_NUMBER", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
#line 5919
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_TAUNT", NULL, __FILE__, __LINE__); }
    virtual wchar_t const * Get_Description() const
    {
#line 5923
        swprintf(UINameBuffer, Fetch_String("TXT_TAUNT_DESC", NULL, __FILE__, __LINE__), Number);
        return UINameBuffer;
    }
    virtual void Execute(int key) const;

    int Number;                                 // +0x04, team or taunt number 1..10
};

// RTTI .?AVNextObjectCommandClass@@, vtable 0x78edfc
class NextObjectCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "NextObject"; }
#line 6010
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_NEXT_OBJECT", NULL, __FILE__, __LINE__); }
#line 6012
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_SELECTION", NULL, __FILE__, __LINE__); }
#line 6014
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_NEXT_OBJECT_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const
    {
        Map.Func_49C720(0);
        Map.Func_49C600(0, 0);
        Map.Func_49C7C0(0);
        Map.Func_49C560(0);
        ObjectClass * object = Map.Next_Object(CurrentObjects.Count() ? CurrentObjects[0] : NULL);
        if (object) {
            Unselect_All();
            object->Select();
            Map.Func_49E0E0();
            Map.Flag_To_Redraw(1);
        }
    }
};

// RTTI .?AVPlanningModeCommandClass@@, vtable 0x78edd4
class PlanningModeCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "PlanningMode"; }
#line 6064
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("Cmnd:PlanningMode", NULL, __FILE__, __LINE__); }
#line 6066
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_CONTROL", NULL, __FILE__, __LINE__); }
#line 6068
    virtual wchar_t const * Get_Description() const { return Fetch_String("Cmnd:PlanningModeDesc", NULL, __FILE__, __LINE__); }
    virtual bool Uses_Modifiers(int key) const { return (key & KN_SHIFT_BIT) || (key & KN_CTRL_BIT) || (key & KN_ALT_BIT); }
    virtual bool Accepts_Key(int) const { return true; }
    virtual bool Virtual_07(int key) const { return (key & KN_RLSE_BIT) == 0; }
    virtual void Execute(int key) const
    {
        if (key & KN_RLSE_BIT) {
            Planning_Mode_End(false);
        } else {
            Planning_Mode_Begin(false);
        }
    }
};

// RTTI .?AVCombatantSelectCommandClass@@, vtable 0x78edac
class CombatantSelectCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "CombatantSelect"; }
#line 6148
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("Cmnd:CombatantSelect", NULL, __FILE__, __LINE__); }
#line 6150
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_SELECTION", NULL, __FILE__, __LINE__); }
#line 6152
    virtual wchar_t const * Get_Description() const { return Fetch_String("Cmnd:CombatantSelectDesc", NULL, __FILE__, __LINE__); }
    virtual bool Uses_Modifiers(int key) const { return (key & KN_SHIFT_BIT) != 0; }
    virtual void Execute(int key) const { Combatant_Select_Command((key & KN_SHIFT_BIT) == 0); }
};

// RTTI .?AVTypeSelectCommandClass@@, vtable 0x78ed84
class TypeSelectCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "TypeSelect"; }
#line 6174
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("Cmnd:TypeSelect", NULL, __FILE__, __LINE__); }
#line 6176
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_SELECTION", NULL, __FILE__, __LINE__); }
#line 6178
    virtual wchar_t const * Get_Description() const { return Fetch_String("Cmnd:TypeSelectDesc", NULL, __FILE__, __LINE__); }
    virtual bool Uses_Modifiers(int key) const { return (key & KN_SHIFT_BIT) != 0; }
    virtual bool Accepts_Key(int) const { return true; }
    virtual bool Virtual_07(int key) const { return (key & KN_RLSE_BIT) == 0; }
    virtual void Execute(int key) const
    {
        if (key & KN_RLSE_BIT) {
            Type_Select_Key_Up();
        } else {
            Type_Select_Key_Down();
        }
    }
};

// RTTI .?AVHealthNavCommandClass@@, vtable 0x78ed5c
class HealthNavCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "HealthNav"; }
#line 6212
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("Cmnd:HealthNavigation", NULL, __FILE__, __LINE__); }
#line 6214
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_SELECTION", NULL, __FILE__, __LINE__); }
#line 6216
    virtual wchar_t const * Get_Description() const { return Fetch_String("Cmnd:HealthNavigationDesc", NULL, __FILE__, __LINE__); }
    virtual bool Uses_Modifiers(int key) const { return (key & KN_SHIFT_BIT) != 0; }
    virtual void Execute(int key) const { Health_Nav_Command((key & KN_SHIFT_BIT) == 0); }
};

// RTTI .?AVVeterancyNavCommandClass@@, vtable 0x78ed34
class VeterancyNavCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "VeterancyNav"; }
#line 6238
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("Cmnd:VetNavigation", NULL, __FILE__, __LINE__); }
#line 6240
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_SELECTION", NULL, __FILE__, __LINE__); }
#line 6242
    virtual wchar_t const * Get_Description() const { return Fetch_String("Cmnd:VetNavigationDesc", NULL, __FILE__, __LINE__); }
    virtual bool Uses_Modifiers(int key) const { return (key & KN_SHIFT_BIT) != 0; }
    virtual void Execute(int key) const { Veterancy_Nav_Command((key & KN_SHIFT_BIT) == 0); }
};

// RTTI .?AVPrevObjectCommandClass@@, vtable 0x78ee24
class PrevObjectCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "PreviousObject"; }
#line 6301
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_PREV_OBJECT", NULL, __FILE__, __LINE__); }
#line 6303
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_SELECTION", NULL, __FILE__, __LINE__); }
#line 6305
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_PREV_OBJECT_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const
    {
        Map.Func_49C720(0);
        Map.Func_49C600(0, 0);
        Map.Func_49C7C0(0);
        Map.Func_49C560(0);
        ObjectClass * object = Map.Prev_Object(CurrentObjects.Count() ? CurrentObjects[0] : NULL);
        if (object) {
            Unselect_All();
            object->Select();
            Map.Func_49E0E0();
            Map.Flag_To_Redraw(1);
        }
    }
};

// RTTI .?AVStopCommandClass@@, vtable 0x78ee9c
class StopCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "StopObject"; }
#line 6342
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_STOP_OBJECT", NULL, __FILE__, __LINE__); }
#line 6344
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_CONTROL", NULL, __FILE__, __LINE__); }
#line 6346
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_STOP_OBJECT_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Stop_Command(); }
};

// RTTI .?AVAllToCheerCommandClass@@, vtable 0x78ee74
class AllToCheerCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "AllToCheer"; }
#line 6360
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("Cmnd:AllCheer", NULL, __FILE__, __LINE__); }
#line 6362
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_CONTROL", NULL, __FILE__, __LINE__); }
#line 6364
    virtual wchar_t const * Get_Description() const { return Fetch_String("Cmnd:AllCheerDesc", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { All_To_Cheer_Command(); }
};

// RTTI .?AVDeployCommandClass@@, vtable 0x78ee4c
class DeployCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "DeployObject"; }
#line 6387
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_DEPLOY_OBJECT", NULL, __FILE__, __LINE__); }
#line 6389
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_CONTROL", NULL, __FILE__, __LINE__); }
#line 6391
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_DEPLOY_OBJECT_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Deploy_Command(); }
};

// RTTI .?AVGuardCommandClass@@, vtable 0x78eec4
class GuardCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "GuardObject"; }
#line 6415
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_GUARD", NULL, __FILE__, __LINE__); }
#line 6417
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_CONTROL", NULL, __FILE__, __LINE__); }
#line 6419
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_GUARD_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Guard_Command(); }
};

// RTTI .?AVScatterCommandClass@@, vtable 0x78eeec
class ScatterCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "ScatterObject"; }
#line 6444
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SCATTER", NULL, __FILE__, __LINE__); }
#line 6446
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_CONTROL", NULL, __FILE__, __LINE__); }
#line 6448
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SCATTER_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Scatter_Command(); }
};

// RTTI .?AVCenterViewCommandClass@@, vtable 0x78ef14
class CenterViewCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "CenterView"; }
#line 6471
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_CENTER_VIEW", NULL, __FILE__, __LINE__); }
#line 6473
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_SELECTION", NULL, __FILE__, __LINE__); }
#line 6475
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_CENTER_VIEW_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const
    {
        if (CurrentObjects.Count() > 0) {
            Map.Func_49E0E0();
            Map.Flag_To_Redraw(1);
        }
    }
};

// RTTI .?AVCenterBaseCommandClass@@, vtable 0x78ef3c
class CenterBaseCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "CenterBase"; }
#line 6502
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_CENTER_BASE", NULL, __FILE__, __LINE__); }
#line 6504
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_SELECTION", NULL, __FILE__, __LINE__); }
#line 6506
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_CENTER_BASE_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int key) const;
};

// RTTI .?AVAllianceCommandClass@@, vtable 0x78ef64
class AllianceCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "ToggleAlliance"; }
#line 6587
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_ALLIANCE", NULL, __FILE__, __LINE__); }
#line 6589
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_CONTROL", NULL, __FILE__, __LINE__); }
#line 6591
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_ALLIANCE_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Alliance_Command(); }
};

// RTTI .?AVToggleRepairCommandClass@@, vtable 0x78ef8c
class ToggleRepairCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "ToggleRepair"; }
#line 6646
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_REPAIR_MODE", NULL, __FILE__, __LINE__); }
#line 6648
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6650
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_REPAIR_MODE_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Func_49C7C0(-1); }
};

// RTTI .?AVToggleSellCommandClass@@, vtable 0x78efb4
class ToggleSellCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "ToggleSell"; }
#line 6672
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SELL_MODE", NULL, __FILE__, __LINE__); }
#line 6674
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6676
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SELL_MODE_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Func_49C560(-1); }
};

// RTTI .?AVBeaconPlacementCommandClass@@, vtable 0x78efdc
class BeaconPlacementCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "PlaceBeacon"; }
#line 6715
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_PLACE_BEACON", NULL, __FILE__, __LINE__); }
#line 6717
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6719
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_PLACE_BEACON_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const
    {
        if (Session.Type != 0 && Session.Type != 5) {
            Place_Beacon_Command();
        }
    }
};

// RTTI .?AVCenterREventCommandClass@@, vtable 0x78f004
class CenterREventCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "CenterOnRadarEvent"; }
#line 6738
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_RADAR_EVENT", NULL, __FILE__, __LINE__); }
#line 6740
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6742
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_RADAR_EVENT_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const
    {
        CellStruct cell = RadarEventCell;
        if (cell.X || cell.Y) {
            CoordStruct coord(cell.X * 256 + 128, cell.Y * 256 + 128, 0);
            int height = (Map[coord].Level * 256) / 2;
            coord -= CoordStruct(height, height, 0);
            TacticalMap->Set_Tactical_Position(coord);
            if (Map.Field_11A4) {
                Map.Func_4992B0(Object_A28E20_Instance);
            }
        }
    }
};

// RTTI .?AVSidebarUpCommandClass@@, vtable 0x78f1e4
class SidebarUpCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "SidebarUp"; }
#line 6809
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SIDEBAR_UP", NULL, __FILE__, __LINE__); }
#line 6811
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6813
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SIDEBAR_UP_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Scroll(true, -1); }
};

// RTTI .?AVLSidebarUpCommandClass@@, vtable 0x78f1bc
class LSidebarUpCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "LeftSidebarUp"; }
#line 6835
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_LSIDEBAR_UP", NULL, __FILE__, __LINE__); }
#line 6837
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6839
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_LSIDEBAR_UP_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Scroll(true, 0); }
};

// RTTI .?AVRSidebarUpCommandClass@@, vtable 0x78f194
class RSidebarUpCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "RightSidebarUp"; }
#line 6862
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_RSIDEBAR_UP", NULL, __FILE__, __LINE__); }
#line 6864
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6866
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_RSIDEBAR_UP_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Scroll(true, 1); }
};

// RTTI .?AVSidebarPageUpCommandClass@@, vtable 0x78f0f4
class SidebarPageUpCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "SidebarPageUp"; }
#line 6888
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SIDEBAR_PGUP", NULL, __FILE__, __LINE__); }
#line 6890
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6892
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SIDEBAR_PGUP_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Page(true, -1); }
};

// RTTI .?AVLSidebarPageUpCommandClass@@, vtable 0x78f0cc
class LSidebarPageUpCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "LeftSidebarPageUp"; }
#line 6906
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_LSIDEBAR_PGUP", NULL, __FILE__, __LINE__); }
#line 6908
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6910
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_LSIDEBAR_PGUP_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Page(true, 0); }
};

// RTTI .?AVRSidebarPageUpCommandClass@@, vtable 0x78f0a4
class RSidebarPageUpCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "RightSidebarPageUp"; }
#line 6924
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_RSIDEBAR_PGUP", NULL, __FILE__, __LINE__); }
#line 6926
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6928
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_RSIDEBAR_PGUP_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Page(true, 1); }
};

// RTTI .?AVSidebarDownCommandClass@@, vtable 0x78f16c
class SidebarDownCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "SidebarDown"; }
#line 6950
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SIDEBAR_DOWN", NULL, __FILE__, __LINE__); }
#line 6952
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6954
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SIDEBAR_DOWN_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Scroll(false, -1); }
};

// RTTI .?AVLSidebarDownCommandClass@@, vtable 0x78f144
class LSidebarDownCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "LeftSidebarDown"; }
#line 6976
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_LSIDEBAR_DOWN", NULL, __FILE__, __LINE__); }
#line 6978
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6980
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_LSIDEBAR_DOWN_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Scroll(false, 0); }
};

// RTTI .?AVRSidebarDownCommandClass@@, vtable 0x78f11c
class RSidebarDownCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "RightSidebarDown"; }
#line 7003
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_RSIDEBAR_DOWN", NULL, __FILE__, __LINE__); }
#line 7005
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7007
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_RSIDEBAR_DOWN_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Scroll(false, 1); }
};

// RTTI .?AVSidebarPageDownCommandClass@@, vtable 0x78f07c
class SidebarPageDownCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "SidebarPageDown"; }
#line 7029
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SIDEBAR_PGDN", NULL, __FILE__, __LINE__); }
#line 7031
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7033
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SIDEBAR_PGDN_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Page(false, -1); }
};

// RTTI .?AVLSidebarPageDownCommandClass@@, vtable 0x78f054
class LSidebarPageDownCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "LeftSidebarPageDown"; }
#line 7047
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_LSIDEBAR_PGDN", NULL, __FILE__, __LINE__); }
#line 7049
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7051
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_LSIDEBAR_PGDN_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Page(false, 0); }
};

// RTTI .?AVRSidebarPageDownCommandClass@@, vtable 0x78f02c
class RSidebarPageDownCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "RightSidebarPageDown"; }
#line 7065
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_RSIDEBAR_PGDN", NULL, __FILE__, __LINE__); }
#line 7067
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7069
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_RSIDEBAR_PGDN_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Map.Page(false, 1); }
};

// RTTI .?AVOptionsCommandClass@@, vtable 0x78f20c
class OptionsCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "Options"; }
#line 7092
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_OPTIONS", NULL, __FILE__, __LINE__); }
#line 7094
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7096
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_OPTIONS_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Options_Dialog(); }
};

// RTTI .?AVView1CommandClass@@, vtable 0x78f34c
class View1CommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "View1"; }
#line 7269
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_VIEW_BOOKMARK1", NULL, __FILE__, __LINE__); }
#line 7271
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7273
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_VIEW_BOOKMARK1_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Jump_To_View(0); }
};

// RTTI .?AVView2CommandClass@@, vtable 0x78f324
class View2CommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "View2"; }
#line 7305
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_VIEW_BOOKMARK2", NULL, __FILE__, __LINE__); }
#line 7307
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7309
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_VIEW_BOOKMARK2_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Jump_To_View(1); }
};

// RTTI .?AVView3CommandClass@@, vtable 0x78f2fc
class View3CommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "View3"; }
#line 7341
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_VIEW_BOOKMARK3", NULL, __FILE__, __LINE__); }
#line 7343
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7345
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_VIEW_BOOKMARK3_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Jump_To_View(2); }
};

// RTTI .?AVView4CommandClass@@, vtable 0x78f2d4
class View4CommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "View4"; }
#line 7377
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_VIEW_BOOKMARK4", NULL, __FILE__, __LINE__); }
#line 7379
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7381
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_VIEW_BOOKMARK4_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Jump_To_View(3); }
};

// RTTI .?AVSetView1CommandClass@@, vtable 0x78f2ac
class SetView1CommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "SetView1"; }
#line 7413
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SET_BOOKMARK1", NULL, __FILE__, __LINE__); }
#line 7415
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7417
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SET_BOOKMARK1_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Set_View(0); }
};

// RTTI .?AVSetView2CommandClass@@, vtable 0x78f284
class SetView2CommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "SetView2"; }
#line 7440
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SET_BOOKMARK2", NULL, __FILE__, __LINE__); }
#line 7442
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7444
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SET_BOOKMARK2_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Set_View(1); }
};

// RTTI .?AVSetView3CommandClass@@, vtable 0x78f25c
class SetView3CommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "SetView3"; }
#line 7467
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SET_BOOKMARK3", NULL, __FILE__, __LINE__); }
#line 7469
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7471
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SET_BOOKMARK3_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Set_View(2); }
};

// RTTI .?AVSetView4CommandClass@@, vtable 0x78f234
class SetView4CommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "SetView4"; }
#line 7494
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SET_BOOKMARK4", NULL, __FILE__, __LINE__); }
#line 7496
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7498
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SET_BOOKMARK4_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Set_View(3); }
};

// RTTI .?AVFollowCommandClass@@, vtable 0x78f374
class FollowCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "Follow"; }
#line 7521
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_FOLLOW", NULL, __FILE__, __LINE__); }
#line 7523
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7525
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_FOLLOW_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const
    {
        if (CurrentObjects.Count() && !Map.Following()) {
            Map.Follow(CurrentObjects[0]);
        } else {
            Map.Follow(NULL);
        }
    }
};

// RTTI .?AVScreenCaptureCommandClass@@, vtable 0x78ec44
class ScreenCaptureCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "ScreenCapture"; }
#line 7633
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7634
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_SCRNCAP", NULL, __FILE__, __LINE__); }
#line 7635
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_SCRNCAP_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int key) const;
};

// RTTI .?AVMultiplayerDebugCommandClass@@, vtable 0x78f3c4
class MultiplayerDebugCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "MultiplayerDebug"; }
    virtual wchar_t const * Get_Category() const { return L"Debug"; }
    virtual wchar_t const * Get_UI_Name() const { return L"Multiplayer debug info"; }
    virtual wchar_t const * Get_Description() const { return L"Turns multiplayer debug on or off."; }
    virtual void Execute(int) const
    {
        if (Session.IsDebugAllowed) {
            Session.IsDebugInfo = !Session.IsDebugInfo;
        }
    }
};

// RTTI .?AVMultiplayerSyncCommandClass@@, vtable 0x78f39c
class MultiplayerSyncCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "ExtraSyncChecking"; }
    virtual wchar_t const * Get_Category() const { return L"Debug"; }
    virtual wchar_t const * Get_UI_Name() const { return L"Game sync logging"; }
    virtual wchar_t const * Get_Description() const { return L"Turns extra game sync logging on or off."; }
    virtual void Execute(int) const
    {
        ExtraSyncInfo = !ExtraSyncInfo;
        if (ExtraSyncInfo) {
            SessionMessages.Add_Message(NULL, 0, Text_To_Wide("Extra sync info ON"), 3, 0x4046, 150, false);
        } else {
            SessionMessages.Add_Message(NULL, 0, Text_To_Wide("Extra sync info OFF"), 3, 0x4046, 150, false);
        }
    }
};

// RTTI .?AVPageUserCommandClass@@, vtable 0x78f4b4
class PageUserCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "PageUser"; }
#line 7125
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("TXT_PAGEUSER", NULL, __FILE__, __LINE__); }
#line 7127
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 7129
    virtual wchar_t const * Get_Description() const { return Fetch_String("TXT_PAGEUSER_DESC", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const
    {
        if (Session.Type == 4) {
            Page_User_Dialog();
        }
    }
};

// RTTI .?AVCursorPositionCommandClass@@, vtable 0x78f4dc
class CursorPositionCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "CursorCheat"; }
#line 7797
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("GUI:CursorCheat", NULL, __FILE__, __LINE__); }
#line 7798
    virtual wchar_t const * Get_Category() const { return Fetch_String("GUI:Debug", NULL, __FILE__, __LINE__); }
#line 7799
    virtual wchar_t const * Get_Description() const { return Fetch_String("DESC:CursorCheat", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { CursorCheat = !CursorCheat; }
};

// RTTI .?AVDeleteCommandClass@@, vtable 0x78f504
class DeleteCommandClass : public CommandClass {
public:
    virtual char const * Get_Name() const { return "Delete"; }
#line 6043
    virtual wchar_t const * Get_UI_Name() const { return Fetch_String("Cmnd:Delete", NULL, __FILE__, __LINE__); }
#line 6045
    virtual wchar_t const * Get_Category() const { return Fetch_String("TXT_INTERFACE", NULL, __FILE__, __LINE__); }
#line 6047
    virtual wchar_t const * Get_Description() const { return Fetch_String("Cmnd:DeleteDesc", NULL, __FILE__, __LINE__); }
    virtual void Execute(int) const { Delete_Command(); }
};

// 0x51b5d0: centres the view on the construction yard, another building or the base unit.
void CenterBaseCommandClass::Execute(int) const
{
    CoordStruct center = EmptyCoord;
    CoordStruct other = EmptyCoord;
    if (PlayerPtr->CurBuildings) {
        for (int index = 0; index < Buildings.Count(); index++) {
            BuildingClass * building = Buildings[index];
            if (building && !building->IsInLimbo && building->House->Is_Player_Control()) {
                if (building->Class->IsBaseCenter) {
                    center = building->Center_Coord();
                    if (building->Field_32B) {
                        break;
                    }
                } else if (other == EmptyCoord) {
                    other = building->Center_Coord();
                }
            }
        }
    }
    if (other == EmptyCoord && center == EmptyCoord && PlayerPtr->CurUnits) {
        for (int index = 0; index < Units.Count(); index++) {
            UnitClass * unit = Units[index];
            if (unit && !unit->IsInLimbo && unit->House->Is_Player_Control() && unit->Class == PlayerPtr->Func_4EEBF0(Rule->BaseUnit)) {
                center = unit->Center_Coord();
                break;
            }
        }
    }
    if (center != EmptyCoord) {
        TacticalMap->Set_Tactical_Position(center);
    } else if (other != EmptyCoord) {
        TacticalMap->Set_Tactical_Position(other);
    }
    if (Map.Field_11A4) {
        Map.Func_4992B0(Object_A28E20_Instance);
    }
    Map.Follow(NULL);
    Map.Flag_To_Redraw(1);
}

// 0x51cab0: copies the game window to the primary surface and saves it as the next free SCRNnnnn.pcx.
void ScreenCaptureCommandClass::Execute(int) const
{
    RECT rect;
    if (GetClientRect(MainWindow, &rect)) {
        POINT topleft;
        topleft.x = rect.left;
        topleft.y = rect.top;
        if (ClientToScreen(MainWindow, &topleft)) {
            POINT bottomright;
            bottomright.x = rect.right;
            bottomright.y = rect.bottom;
            if (ClientToScreen(MainWindow, &bottomright)) {
                RectangleStruct area(topleft.x, topleft.y, rect.right + 1, rect.bottom + 1);
                if (area.Width >= HiddenSurface->Get_Width()) {
                    area.Width = HiddenSurface->Get_Width();
                }
                if (area.Height >= HiddenSurface->Get_Height()) {
                    area.Height = HiddenSurface->Get_Height();
                }
                WWMouse->Hide_Mouse();
                int width = HiddenSurface->Get_Width();
                int height = HiddenSurface->Get_Height();
                RectangleStruct full(0, 0, width, height);
                HiddenSurface->Copy_From(full, *VisibleSurface, area, false, true);
                WWMouse->Show_Mouse();

                char filename[0x80];
                int index = -1;
                do {
                    index++;
                    sprintf(filename, "SCRN%04d.pcx", index);
                } while (CCFileClass(filename).Is_Available());

                CCFileClass file(filename);
                Write_PCX_File(file, *HiddenSurface, &GamePalette);
            }
        }
    }
}

// 0x51ab00: sends the taunt to the other players of an internet or LAN game, at most every five seconds.
void TauntCommandClass::Execute(int) const
{
    if (Session.Type == 3 || Session.Type == 4) {
        int time = timeGetTime();
        if (LastTauntTime == -1 || time - LastTauntTime > 5000) {
            if ((TauntFlags[8] && Session.Type == 3) || (TauntFlags[9] && Session.Type == 4)) {
                LastTauntTime = time;
                TauntPacketType packet;
                packet.Command = 0x1d;
                strcpy(packet.Name, Wide_To_Text(Players[0]->Name));
                packet.Field_31 = Session_A256E4;
                packet.Field_35 = Func_5B6C30(Session_A2793E);
                unsigned char house = Players[0]->Field_49 << 4;
                packet.Taunt.Value = house ^ ((house ^ Number) & 0x0f);
                Play_Taunt(packet.Taunt.Value);
                int count = Houses.Count();
                for (int i = 0; i < count; i++) {
                    HouseClass * house = Houses[i];
                    if (house && house->Class->Field_1A5 && TauntFlags[i]) {
                        int connections = Ipx.Num_Connections();
                        for (int j = 0; j < connections; j++) {
                            int id = Ipx.Connection_ID(j);
                            if (wcscmp(house->IniName, Ipx.Connection_Name(id)) == 0) {
                                Ipx.Send_Private_Message(&packet, 0x39, 1, Ipx.Connection_Address(id));
                                Ipx.Service();
                            }
                        }
                    }
                }
            }
        }
    }
}

extern DynamicVectorClass<CommandClass const *> Commands;   // 0x81a698 (name provisional)
extern IndexClass<int, CommandClass const *> HotkeyIndex;  // 0x81a6c0, key number -> command (name provisional)

// 0x516930: creates the keyboard commands and binds the fixed keys (name provisional).
void Init_Commands()
{
    if (Session.IsDebugAllowed) {
        Commands.Add(new MultiplayerDebugCommandClass);
        Commands.Add(new MultiplayerSyncCommandClass);
    }
    Commands.Add(new FollowCommandClass);
    Commands.Add(new View1CommandClass);
    Commands.Add(new View2CommandClass);
    Commands.Add(new View3CommandClass);
    Commands.Add(new View4CommandClass);
    Commands.Add(new SetView1CommandClass);
    Commands.Add(new SetView2CommandClass);
    Commands.Add(new SetView3CommandClass);
    Commands.Add(new SetView4CommandClass);
    CommandClass const * options = new OptionsCommandClass;
    Commands.Add(options);
    Commands.Add(new SidebarUpCommandClass);
    Commands.Add(new LSidebarUpCommandClass);
    Commands.Add(new RSidebarUpCommandClass);
    Commands.Add(new SidebarDownCommandClass);
    Commands.Add(new LSidebarDownCommandClass);
    Commands.Add(new RSidebarDownCommandClass);
    Commands.Add(new SidebarPageUpCommandClass);
    Commands.Add(new LSidebarPageUpCommandClass);
    Commands.Add(new RSidebarPageUpCommandClass);
    Commands.Add(new SidebarPageDownCommandClass);
    Commands.Add(new LSidebarPageDownCommandClass);
    Commands.Add(new RSidebarPageDownCommandClass);
    CommandClass const * radar = new CenterREventCommandClass;
    Commands.Add(radar);
    Commands.Add(new BeaconPlacementCommandClass);
    Commands.Add(new ToggleSellCommandClass);
    Commands.Add(new ToggleRepairCommandClass);
    Commands.Add(new AllianceCommandClass);
    Commands.Add(new CenterBaseCommandClass);
    Commands.Add(new CenterViewCommandClass);
    Commands.Add(new ScatterCommandClass);
    Commands.Add(new GuardCommandClass);
    Commands.Add(new StopCommandClass);
    Commands.Add(new AllToCheerCommandClass);
    Commands.Add(new DeployCommandClass);
    Commands.Add(new PrevObjectCommandClass);
    Commands.Add(new NextObjectCommandClass);
    Commands.Add(new PlanningModeCommandClass);
    Commands.Add(new CombatantSelectCommandClass);
    Commands.Add(new TypeSelectCommandClass);
    Commands.Add(new HealthNavCommandClass);
    Commands.Add(new VeterancyNavCommandClass);
    Commands.Add(new SetStructureTabCommandClass);
    Commands.Add(new SetDefenseTabCommandClass);
    Commands.Add(new SetUnitTabCommandClass);
    Commands.Add(new SetInfantryTabCommandClass);
    Commands.Add(new CreateTeamCommandClass(1));
    Commands.Add(new CreateTeamCommandClass(2));
    Commands.Add(new CreateTeamCommandClass(3));
    Commands.Add(new CreateTeamCommandClass(4));
    Commands.Add(new CreateTeamCommandClass(5));
    Commands.Add(new CreateTeamCommandClass(6));
    Commands.Add(new CreateTeamCommandClass(7));
    Commands.Add(new CreateTeamCommandClass(8));
    Commands.Add(new CreateTeamCommandClass(9));
    Commands.Add(new CreateTeamCommandClass(10));
    Commands.Add(new SelectTeamCommandClass(1));
    Commands.Add(new SelectTeamCommandClass(2));
    Commands.Add(new SelectTeamCommandClass(3));
    Commands.Add(new SelectTeamCommandClass(4));
    Commands.Add(new SelectTeamCommandClass(5));
    Commands.Add(new SelectTeamCommandClass(6));
    Commands.Add(new SelectTeamCommandClass(7));
    Commands.Add(new SelectTeamCommandClass(8));
    Commands.Add(new SelectTeamCommandClass(9));
    Commands.Add(new SelectTeamCommandClass(10));
    Commands.Add(new AddTeamCommandClass(1));
    Commands.Add(new AddTeamCommandClass(2));
    Commands.Add(new AddTeamCommandClass(3));
    Commands.Add(new AddTeamCommandClass(4));
    Commands.Add(new AddTeamCommandClass(5));
    Commands.Add(new AddTeamCommandClass(6));
    Commands.Add(new AddTeamCommandClass(7));
    Commands.Add(new AddTeamCommandClass(8));
    Commands.Add(new AddTeamCommandClass(9));
    Commands.Add(new AddTeamCommandClass(10));
    Commands.Add(new CenterTeamCommandClass(1));
    Commands.Add(new CenterTeamCommandClass(2));
    Commands.Add(new CenterTeamCommandClass(3));
    Commands.Add(new CenterTeamCommandClass(4));
    Commands.Add(new CenterTeamCommandClass(5));
    Commands.Add(new CenterTeamCommandClass(6));
    Commands.Add(new CenterTeamCommandClass(7));
    Commands.Add(new CenterTeamCommandClass(8));
    Commands.Add(new CenterTeamCommandClass(9));
    Commands.Add(new CenterTeamCommandClass(10));
    Commands.Add(new TauntCommandClass(1));
    Commands.Add(new TauntCommandClass(2));
    Commands.Add(new TauntCommandClass(3));
    Commands.Add(new TauntCommandClass(4));
    Commands.Add(new TauntCommandClass(5));
    Commands.Add(new TauntCommandClass(6));
    Commands.Add(new TauntCommandClass(7));
    Commands.Add(new TauntCommandClass(8));
    Commands.Add(new ScreenCaptureCommandClass);
    Commands.Add(new PageUserCommandClass);
    Commands.Add(new CursorPositionCommandClass);
    CommandClass const * del = new DeleteCommandClass;
    Commands.Add(del);

    Load_Hotkeys();

    if (HotkeyIndex.Is_Present(VK_DELETE)) {
        HotkeyIndex.Remove_Index(VK_DELETE);
    }
    HotkeyIndex.Add_Index(VK_DELETE, del);
    if (HotkeyIndex.Is_Present(VK_ESCAPE)) {
        HotkeyIndex.Remove_Index(VK_ESCAPE);
    }
    HotkeyIndex.Add_Index(VK_ESCAPE, options);
    if (HotkeyIndex.Is_Present(VK_SPACE)) {
        HotkeyIndex.Remove_Index(VK_SPACE);
    }
    HotkeyIndex.Add_Index(VK_SPACE, radar);
}
