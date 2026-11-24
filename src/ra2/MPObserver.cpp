// C:\RA2\MPObserver.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Contents: the Megawealth game mode and the observer team of multiplayer games.
// Class names come from RTTI (.?AVMegawealth@@, .?AVMultiplayerObserverTeam@@); all other names
// (methods, members, the string classes and Map's method) are provisional.
#include <stddef.h>
#include "GAMECONST.H"

// ---- local declarations (to be moved to headers by the integrator) ----

// Identical prototype already in ABSTYPE.H (0x6eeb60, __fastcall); declared here to avoid pulling in
// the AbstractClass headers. Belongs in a string-table header.
wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);

// One-pointer wide string (provisional name). 0x75b300 ctor(const wchar_t *),
// 0x75b350 copy ctor, 0x75b390 dtor.
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);
    WideStringClass(WideStringClass const & string);
    ~WideStringClass();
private:
    wchar_t * Buffer;
};

// One-pointer narrow string (provisional name). 0x7592c0 copy ctor.
class CharStringClass {
public:
    CharStringClass(CharStringClass const & string);
    ~CharStringClass();
private:
    char * Buffer;
};

// Global map object at 0x81a820 (its exact class is not yet bound).
class MapClass {
public:
    void Reveal_The_Map();      // 0x556fe0: marks PlayerPtr+0x188 and reveals every cell to it
};
extern MapClass Map;

// RTTI .?AVMultiplayerTeam@@, vtable 0x7922e4 (3 slots), size 0xc.
class MultiplayerTeam {
public:
    MultiplayerTeam(WideStringClass const & name, int id);   // 0x5b63b0
    virtual ~MultiplayerTeam();                              // 0x5b63e0 (slot 0: 0x1b64b0)
    virtual bool Is_Valid_Index(int index);                  // slot 1: 0x5b63f0, 0 <= index < [0xa27db8]
    virtual bool Can_Join(int index);                        // slot 2: 0x5b6410

    WideStringClass Name;   // +0x04
    int ID;                 // +0x08
};

// RTTI .?AVMultiplayerGameMode@@, vtable 0x792188 (44 slots).
class MultiplayerGameMode {
public:
    MultiplayerGameMode(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_name, CharStringClass const & ini_file, bool flag, int value);  // 0x5b37e0
    virtual ~MultiplayerGameMode();      // 0x5b3930
    virtual void Virtual_01();
    virtual void Virtual_02();
    virtual void Virtual_03();
    virtual void Virtual_04();
    virtual void Virtual_05();
    virtual void Virtual_06();
    virtual void Virtual_07();
    virtual void Virtual_08();
    virtual void Virtual_09();
    virtual void Virtual_10();
    virtual void Virtual_11();
    virtual void Virtual_12();
    virtual void Virtual_13();
    virtual void Virtual_14();
    virtual void Virtual_15();
    virtual void Virtual_16();
    virtual void Virtual_17();
    virtual void Virtual_18();
    virtual void Virtual_19();
    virtual void Virtual_20();
    virtual void Virtual_21();
    virtual void Virtual_22();
    virtual void Virtual_23();
    virtual void Virtual_24();
    virtual void Virtual_25();
    virtual void Virtual_26();
    virtual void Virtual_27();
    virtual void Virtual_28();
    virtual bool Reveal_Map();           // slot 29: base 0x5b4d00 returns true
    virtual void Virtual_30();
    virtual void Virtual_31();
    virtual void Virtual_32();
    virtual void Virtual_33();
    virtual void Virtual_34();
    virtual void Virtual_35();
    virtual void Virtual_36();
    virtual void Virtual_37();
    virtual void Virtual_38();
    virtual void Virtual_39();
    virtual void Virtual_40();
    virtual void Virtual_41();
    virtual void Virtual_42();
    virtual void Virtual_43();
};

// RTTI .?AVMegawealth@@ : MultiplayerGameMode, vtable 0x791a7c.
class Megawealth : public MultiplayerGameMode {
public:
    Megawealth(WideStringClass const & name, WideStringClass const & description,
        CharStringClass const & ini_name, CharStringClass const & ini_file, bool flag, int value);
    virtual ~Megawealth();
    virtual bool Reveal_Map();
};

// RTTI .?AVMultiplayerObserverTeam@@ : MultiplayerTeam, vtable 0x791b30.
class MultiplayerObserverTeam : public MultiplayerTeam {
public:
    MultiplayerObserverTeam();
    virtual bool Is_Valid_Index(int index);
};

// ---- end of local declarations ----

Megawealth::Megawealth(WideStringClass const & name, WideStringClass const & description,
    CharStringClass const & ini_name, CharStringClass const & ini_file, bool flag, int value) :
    MultiplayerGameMode(name, description, ini_name, ini_file, flag, value)
{
}

Megawealth::~Megawealth()
{
}

bool Megawealth::Reveal_Map()
{
    Map.Reveal_The_Map();
    return true;
}

#line 3 "C:\\RA2\\MPObserver.cpp"
MultiplayerObserverTeam::MultiplayerObserverTeam() :
    // Original __LINE__ is 5.
    MultiplayerTeam(Fetch_String("MP:ObserverTeam", NULL, __FILE__, __LINE__), -1)
{
}

bool MultiplayerObserverTeam::Is_Valid_Index(int index)
{
    return MultiplayerTeam::Is_Valid_Index(index);
}
