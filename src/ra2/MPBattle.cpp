

// MPBattle.cpp (level-2 reconstruction of GAME.EXE 1.001; file name provisional)
// Contents: the Battle multiplayer game mode and its team class, 0x19f0f0..0x19f3cd. The header-inline
// bodies of the MultiplayerGameMode base virtuals (0x19f150..0x19f2a0) are emitted in this file's span as
// well; they stay claimed where they are now (src/m85/src/mpfreeforall.cpp) and are only declared here.
// Class names come from RTTI (.?AVMultiplayerBattle@@ vtable 0x791690, .?AVMultiplayerBattleTeam@@ vtable
// 0x791744); the other names follow src/ra2/Multiplayer.cpp and are provisional.
// Written from the 1.001 disassembly; no m85/gibbo body exists for these functions.
#include <stddef.h>
#include "GAMECONST.H"
#include <windows.h>

// ---- local declarations (to be moved to headers by the integrator; copied from Multiplayer.cpp) ----
#include "VECTOR.H"

// Simple owned narrow string, one pointer (as in Multiplayer.cpp).
class CharStringClass {
public:
    CharStringClass(CharStringClass const & string);            // 0x7592c0
    ~CharStringClass();                                         // 0x759320
    char * Buffer;
};
class CCINIClass;
class MultiMission;
class HouseClass;

// Simple owned wide string, one pointer (as in Multiplayer.cpp). 0x75b390 destructor.
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);
    WideStringClass(WideStringClass const & string);
    ~WideStringClass();
    wchar_t * Buffer;
};
WideStringClass Int_To_WideString(int value);   // 0x75ca00 (swprintf "%d"; as in WOLPersonaInformation.cpp)

class Cell {
public:
    short X;
    short Y;
};

// RTTI .?AVMultiplayerTeam@@, vtable 0x7922e4 (3 slots), size 0xc (as in Multiplayer.cpp).
class MultiplayerTeam {
public:
    MultiplayerTeam(WideStringClass const & name, int id);   // 0x5b63b0
    virtual ~MultiplayerTeam();                              // 0x5b63e0
    virtual bool Is_Valid_Index(int index);                  // slot 1: 0x5b63f0
    virtual bool Can_Join(int index);                        // slot 2: 0x5b6410

    WideStringClass Name;   // +0x04
    int ID;                 // +0x08
};


// RTTI .?AVMultiplayerGameMode@@, vtable 0x792188 (44 slots), size 0x40. Slot names are provisional
// but derived from the base bodies in this file; slots 1-3, 8, 9, 17-19, 22, 25 and 30-39 have
// their bodies (inline in the header) in another file.
class MultiplayerGameMode {
public:
    // RTTI .?AVInitializerBase@MultiplayerGameMode@@, vtable 0x79227c.
    class InitializerBase {
    public:
        InitializerBase();
        virtual ~InitializerBase();
        virtual MultiplayerGameMode * Create(WideStringClass const & name, WideStringClass const & description,
            CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id) const = 0;
    };

    // RTTI .?AV?$Initializer@VT@@@MultiplayerGameMode@@.
    template<class T> class Initializer : public InitializerBase {
    public:
        virtual MultiplayerGameMode * Create(WideStringClass const & name, WideStringClass const & description,
            CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id) const
        {
            return new T(name, description, ini_file, key, random_maps, id);
        }
    };

    MultiplayerGameMode(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x5b37e0
    virtual ~MultiplayerGameMode();                                 // 0x5b3930
    virtual bool Virtual_01();                                      // 0x59f150 (false)
    virtual bool Virtual_02();                                      // 0x59f160 (false)
    virtual bool Virtual_03(int);                                   // 0x59f170 (true)
    virtual bool Assign_Teams();
    virtual bool Can_Start(WideStringClass & reason);
    virtual bool Virtual_06();
    virtual bool Is_Valid_House(int house);
    virtual void Activate();                                        // 0x59f180
    virtual void Request_Refresh();                                 // 0x59f190 (name from MPCoop.cpp)
    virtual int Virtual_10();
    virtual bool Allows_Random_Maps();
    virtual bool Is_Skirmish_Allowed();
    virtual int Default_Scenario();
    virtual void Fill_Combo(HWND combo, DynamicVectorClass<int> const & items, int selected);
    virtual void Fill_List_Box(HWND list, DynamicVectorClass<int> const & items, int selected);
    virtual void Fill_Team_List(HWND combo, int player);
    virtual bool Virtual_17(int, DynamicVectorClass<int>) { return false; }   // 0x59f1c0: the one base inline body that has no claim yet (mpfreeforall.cpp declares a third int argument for it); given here so that it is emitted
    virtual bool Virtual_18(int, DynamicVectorClass<int>, int, int);    // 0x59f1a0 (signature as in MPCoop.cpp)
    virtual bool Virtual_19(int, int, int);                         // 0x59f1e0 (true)
    virtual bool Virtual_20();
    virtual bool Virtual_21();
    virtual bool Virtual_22();                                      // 0x59f1f0 (true)
    virtual int Random_Country();
    virtual int Random_AI_Country();
    virtual void Virtual_25(int, int);                              // 0x59f200
    virtual bool Prepare_Scenario();
    virtual bool Assign_Start_Positions(bool flag);
    virtual bool Virtual_28();
    virtual bool Reveal_Map();
    virtual void Virtual_30();
    virtual void Virtual_31();
    virtual int Virtual_32();
    virtual void Virtual_33();
    virtual void Virtual_34(int);
    virtual void Virtual_35(int);
    virtual bool Virtual_36();
    virtual void Virtual_37();
    virtual void Virtual_38();
    virtual void Virtual_39();
    virtual void Create_Teams(DynamicVectorClass<MultiplayerTeam *> & teams);
    virtual Cell Pick_Start_Cell(int house, DynamicVectorClass<Cell> & cells, bool * used);
    virtual bool Create_Base(HouseClass * house, int & cost);
    virtual bool Create_Units(HouseClass * house, int & budget);

    static DynamicVectorClass<MultiplayerGameMode *> & Game_Modes();
    static MultiplayerGameMode * Default_Game_Mode();
    static int Game_Mode_Count();
    static MultiplayerGameMode * Game_Mode_From_ID(int id);
    static void Fill_Game_Mode_Combo(HWND combo, int selected);
    static void Fill_Game_Mode_List(HWND list, int selected);
    static void Read_Game_Modes(CharStringClass const & section, InitializerBase const & initializer);
    static void Init_Game_Modes();
    static void Free_Game_Modes();

    bool Is_Scenario_Allowed(MultiMission * scenario);
    MultiplayerTeam * Find_Team(int id);
    void Clear_Teams();
    CCINIClass * Get_INI();
    bool Create_Starting_Forces();
    int Player_Team(int id);

    bool Flag04;                                    // +0x04
    DynamicVectorClass<MultiplayerTeam *> Teams;    // +0x08
    WideStringClass Name;                           // +0x20
    WideStringClass Description;                    // +0x24
    int ID;                                         // +0x28
    CharStringClass INIFile;                        // +0x2c
    CharStringClass Key;                            // +0x30
    bool RandomMaps;                                // +0x34
    CCINIClass * INI;                               // +0x38
    int Value3C;                                    // +0x3c, "WonlineTournamentAllowed"
};


// RTTI .?AVMultiplayerBattle@@ : MultiplayerGameMode, vtable 0x791690 (slots 0 and 12 are its own).
class MultiplayerBattle : public MultiplayerGameMode {
public:
    MultiplayerBattle(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id);  // 0x59f0f0
    virtual ~MultiplayerBattle();                           // 0x59f130 (slot 0: 0x59f2c0)
    virtual bool Is_Skirmish_Allowed();                     // 0x59f140
};

// RTTI .?AVMultiplayerBattleTeam@@ : MultiplayerTeam, vtable 0x791744.
class MultiplayerBattleTeam : public MultiplayerTeam {
public:
    MultiplayerBattleTeam(WideStringClass const & name, int id);    // 0x59f2f0
    virtual bool Is_Valid_Index(int index);                 // 0x59f370
    virtual bool Can_Join(int index);                       // 0x59f390
};

MultiplayerTeam * Create_Battle_Team(int index);    // 0x59f310 (name provisional, as in Multiplayer.cpp)

// ---- end of local declarations ----

MultiplayerBattle::MultiplayerBattle(WideStringClass const & name, WideStringClass const & description,
    CharStringClass const & ini_file, CharStringClass const & key, bool random_maps, int id) :
    MultiplayerGameMode(name, description, ini_file, key, random_maps, id)
{
}

MultiplayerBattle::~MultiplayerBattle()
{
}

bool MultiplayerBattle::Is_Skirmish_Allowed()
{
    return true;
}

MultiplayerBattleTeam::MultiplayerBattleTeam(WideStringClass const & name, int id) :
    MultiplayerTeam(name, id)
{
}

// The team of one player: its name is the player index as text.
MultiplayerTeam * Create_Battle_Team(int index)
{
    return new MultiplayerBattleTeam(Int_To_WideString(index), index);
}

bool MultiplayerBattleTeam::Is_Valid_Index(int index)
{
    return MultiplayerTeam::Is_Valid_Index(index) ? true : false;
}

bool MultiplayerBattleTeam::Can_Join(int index)
{
    return MultiplayerTeam::Can_Join(index) ? true : false;
}
