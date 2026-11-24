// C:\RA2\WDTGameOptions.cpp (level-2 reconstruction of GAME.EXE 1.001)
// WorldDominationTour game options: the conditions a World Domination Tour territory places on a
// battle (map size, player count, flags) and their textual description. Class names GameOption,
// FlagGameOption and MapSizeGameOption come from RTTI; all other names are provisional.
// ThresholdGameOption and PlayerCountGameOption have no vtable in the binary (never constructed);
// their out-of-line methods 0x31d250..0x31d370 and 0x31d530/0x31d540 are unreferenced.
#include "GAMECONST.H"

// ---- local declarations (to be moved to headers by the integrator) ----
#include <stddef.h>

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x2eeb60 (also in ABSTYPE.H)

// Simple owned narrow string, one pointer (library code near 0x359260; name provisional).
class CharStringClass {
public:
    CharStringClass(char const * string);           // 0x359260
    CharStringClass(CharStringClass const & string); // 0x3592c0
    ~CharStringClass();                              // 0x359320
    operator char * ();                              // 0x35a030 (identical code to the const version)
    operator char const * () const;                  // 0x35a070
    unsigned Get_Length() const;                     // 0x35a0e0
    char * Buffer;
};
CharStringClass operator + (CharStringClass const & left, CharStringClass const & right);   // 0x35b110
CharStringClass Int_To_String(int value);            // 0x35aec0 (sprintf "%d")

// Simple owned wide string, one pointer (library code near 0x35b300; name provisional).
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);           // 0x35b300
    WideStringClass(WideStringClass const & string);   // 0x35b350
    ~WideStringClass();                                 // 0x35b390
    unsigned Get_Length() const;                        // 0x35bde0
    WideStringClass operator + (wchar_t const * string) const;   // 0x35b810
    wchar_t * Buffer;
};
WideStringClass operator + (WideStringClass const & left, WideStringClass const & right);   // 0x35cda0

// RTTI .?AVReferenceCounted@@, vtable 0x793cd4.
class ReferenceCounted {
public:
    ReferenceCounted() : ReferenceCount(0) {}
    virtual ~ReferenceCounted();                 // 0x230cb0 (deleting 0x230cf0)
    virtual bool Is_Kind(int kind) const;        // 0x230ce0 (returns false; name provisional)
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
    T * Get() const { return (T *)Pointer; }
    T * operator -> () const { return (T *)Pointer; }
};

// RTTI .?AVWDTTerritory@@, vtable 0x79a168. Only the fields read by the game options are named.
class WDTTerritory : public ReferenceCounted {
public:
    char Unknown08[6];               // +08
    unsigned char Value0E;           // +0E (read by the ValueGameOption getter 0x31c730)
    unsigned char Value0F;           // +0F (read by the ValueGameOption getter 0x31c740)
    char Unknown10[2];               // +10
    unsigned char MapSize;           // +12 (0..3, index into the map size labels)
    unsigned char AlternateMapSize;  // +13 (0..3)
    unsigned char PlayerCount;       // +14 (4 or other)
    char Unknown15[0x38 - 0x15];     // +15
    int Flags;                       // +38 (tested against FlagGameOption::Mask)
};

namespace WorldDominationTour {

// RTTI .?AVGameOption@WorldDominationTour@@, vtable 0x799fa8 (slots 3 and 4 pure), size 0xc.
class GameOption : public ReferenceCounted {
public:
    GameOption(int mask) : Mask(mask) {}
    virtual ~GameOption();                                                    // 0x31d230 (deleting 0x31c9b0)
    virtual int Get_Status(rc_ptr<WDTTerritory> const & territory) const = 0;
    virtual WideStringClass Describe(rc_ptr<WDTTerritory> const & territory, WideStringClass const & text) const = 0;

    bool Is_Fixed(rc_ptr<WDTTerritory> const & territory) const;              // 0x31d240

    int Mask;      // +08
};

// No vtable in the binary (never constructed); name and layout from 0x31d250/0x31d330/0x31d370 only.
class ThresholdGameOption : public GameOption {
public:
    virtual int Get_Status(rc_ptr<WDTTerritory> const & territory) const;    // 0x31d370
    virtual WideStringClass Describe(rc_ptr<WDTTerritory> const & territory, WideStringClass const & text) const;  // 0x31d250
    virtual int Classify(rc_ptr<WDTTerritory> const & territory) const = 0;  // slot 5

    int Classify_Value(unsigned value) const;                                 // 0x31d330

    int Unknown0C;           // +0C
    CharStringClass Prefix;  // +10
    unsigned Limit1;         // +14
    unsigned Limit2;         // +18
    unsigned Limit3;         // +1C
    unsigned Limit4;         // +20
};

// RTTI .?AVFlagGameOption@WorldDominationTour@@, vtable 0x799fe4, size 0x1c.
class FlagGameOption : public GameOption {
public:
    FlagGameOption(int mask, CharStringClass clear_label, int clear_status, CharStringClass set_label, int set_status) :
        GameOption(mask),
        ClearStatus(clear_status),
        SetStatus(set_status),
        SetLabel(set_label),
        ClearLabel(clear_label)
    {
    }                                                                         // 0x31d750
    // implicit virtual destructor; deleting destructor 0x31d7b0
    virtual int Get_Status(rc_ptr<WDTTerritory> const & territory) const;    // 0x31d410
    virtual WideStringClass Describe(rc_ptr<WDTTerritory> const & territory, WideStringClass const & text) const;  // 0x31d430

    static rc_ptr<FlagGameOption> Create(int mask, CharStringClass clear_label, int clear_status, CharStringClass set_label, int set_status);  // 0x31d390

    int ClearStatus;             // +0C
    int SetStatus;               // +10
    CharStringClass SetLabel;    // +14
    CharStringClass ClearLabel;  // +18
};

// No vtable in the binary (never constructed); methods 0x31d530/0x31d540 only.
class PlayerCountGameOption : public GameOption {
public:
    virtual int Get_Status(rc_ptr<WDTTerritory> const & territory) const;    // 0x31d530
    virtual WideStringClass Describe(rc_ptr<WDTTerritory> const & territory, WideStringClass const & text) const;  // 0x31d540
};

// RTTI .?AVMapSizeGameOption@WorldDominationTour@@, vtable 0x799ffc, size 0xc.
class MapSizeGameOption : public GameOption {
public:
    MapSizeGameOption(int mask) : GameOption(mask) {}
    virtual ~MapSizeGameOption() {}                                           // deleting 0x31d7f0
    virtual int Get_Status(rc_ptr<WDTTerritory> const & territory) const;    // 0x31d730
    virtual WideStringClass Describe(rc_ptr<WDTTerritory> const & territory, WideStringClass const & text) const;  // 0x31d670

    static rc_ptr<MapSizeGameOption> Create(int mask);                        // 0x31d620
};

}
// ---- end of local declarations ----

using namespace WorldDominationTour;

// 0x799fd0 (.rdata)
static char const * const MapSizeLabels[4] = {
    "WDT:SmallMap",
    "WDT:MediumMap",
    "WDT:LargeMap",
    "WDT:VeryLargeMap"
};

// 0x7e53e0 (.data): status of the map size option, indexed by [MapSize][AlternateMapSize].
static int MapSizeStatus[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 2, 0},
    {0, 2, 1, 0},
    {0, 0, 0, 0}
};

// 0x31d230
GameOption::~GameOption()
{
}

// 0x31d240
bool GameOption::Is_Fixed(rc_ptr<WDTTerritory> const &) const
{
    return false;
}

// 0x31d250; the original __LINE__ values of the two Fetch_String calls are 22 and 25.
#line 16 "C:\\RA2\\WDTGameOptions.cpp"
WideStringClass ThresholdGameOption::Describe(rc_ptr<WDTTerritory> const & territory, WideStringClass const & text) const
{
    int value = Classify(territory);
    CharStringClass label = Prefix + Int_To_String(value);
    if (text.Get_Length() != 0) {
        WideStringClass separator(L", ");
        return text + separator + Fetch_String(label, NULL, __FILE__, __LINE__);
    }

    return WideStringClass(Fetch_String(label, NULL, __FILE__, __LINE__));
}

// 0x31d330
int ThresholdGameOption::Classify_Value(unsigned value) const
{
    if (value <= Limit1) return 0;
    if (value <= Limit2) return 1;
    if (value >= Limit4) return 3;
    if (value >= Limit3) return 2;
    return 4;
}

// 0x31d370
int ThresholdGameOption::Get_Status(rc_ptr<WDTTerritory> const & territory) const
{
    return (Classify(territory) == 4) ? 2 : 0;
}

// 0x31d390
rc_ptr<FlagGameOption> FlagGameOption::Create(int mask, CharStringClass clear_label, int clear_status, CharStringClass set_label, int set_status)
{
    return rc_ptr<FlagGameOption>(new FlagGameOption(mask, clear_label, clear_status, set_label, set_status));
}

// 0x31d410
int FlagGameOption::Get_Status(rc_ptr<WDTTerritory> const & territory) const
{
    if (territory->Flags & Mask) {
        return SetStatus;
    }
    return ClearStatus;
}

// 0x31d430; the original __LINE__ values of the two Fetch_String calls are 78 and 81.
#line 69
WideStringClass FlagGameOption::Describe(rc_ptr<WDTTerritory> const & territory, WideStringClass const & text) const
{
    CharStringClass label((territory->Flags & Mask) ? SetLabel : ClearLabel);
    if (label.Get_Length() == 0) {
        return text;
    }

    if (text.Get_Length() > 0) {
        WideStringClass separator(L", ");
        return text + separator + Fetch_String(label, NULL, __FILE__, __LINE__);
    }

    return WideStringClass(Fetch_String(label, NULL, __FILE__, __LINE__));
}

// 0x31d530
int PlayerCountGameOption::Get_Status(rc_ptr<WDTTerritory> const &) const
{
    return 0;
}

// 0x31d540; the original __LINE__ values of the two Fetch_String calls are 104 and 107.
#line 99
WideStringClass PlayerCountGameOption::Describe(rc_ptr<WDTTerritory> const & territory, WideStringClass const & text) const
{
    CharStringClass label((territory->PlayerCount == 4) ? "WDT:FourPlayerOnly" : "WDT:TwoPlayerOnly");
    if (text.Get_Length() > 0) {
        WideStringClass separator(L", ");
        return text + separator + Fetch_String(label, NULL, __FILE__, __LINE__);
    }

    return WideStringClass(Fetch_String(label, NULL, __FILE__, __LINE__));
}

// 0x31d620
rc_ptr<MapSizeGameOption> MapSizeGameOption::Create(int mask)
{
    return rc_ptr<MapSizeGameOption>(new MapSizeGameOption(mask));
}

// 0x31d670; the original __LINE__ values of the two Fetch_String calls are 129 and 131.
#line 125
WideStringClass MapSizeGameOption::Describe(rc_ptr<WDTTerritory> const & territory, WideStringClass const & text) const
{
    if (text.Get_Length() > 0) {
        WideStringClass separator(L", ");
        return text + separator + Fetch_String(MapSizeLabels[territory->MapSize], NULL, __FILE__, __LINE__);
    }
    return WideStringClass(Fetch_String(MapSizeLabels[territory->AlternateMapSize], NULL, __FILE__, __LINE__));
}

// 0x31d730
int MapSizeGameOption::Get_Status(rc_ptr<WDTTerritory> const & territory) const
{
    return MapSizeStatus[territory->MapSize][territory->AlternateMapSize];
}

// Dynamic initializer 0x31d820: 16 bytes at 0xb0d1e8, written nowhere else in this TU.
struct WDTGameOptionsUnknownStruct {
    WDTGameOptionsUnknownStruct() : A(0), B(0), C(0), D(0) {}
    int A;
    int B;
    int C;
    int D;
};
static WDTGameOptionsUnknownStruct WDTGameOptionsUnknown;
