// C:\RA2\Dropship.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Dropship loadout: the house's list of up to five unit types that are carried in by the dropship
// (HouseClass holds three DropshipLoadoutClass objects of 0x2c bytes at +0x5560), and the dropship
// loadout screen that lets the player choose them before a mission (DROPSHIP.PAL, LOADOUT.SHP).
// Class names come from RTTI where available (TechnoTypeClass, BSurface, ConvertClass,
// DynamicVectorClass<ButtonFadeEffect *>, DynamicVectorClass<CrossDissolveEffect *>); all other
// names are provisional.
//
// TU boundary: 0xa6430 (GAMECONST block) .. 0xa9fc0. 0xa6600 (zero rectangle) is this file's own
// first initializer. The template instances 0xa9800..0xa9fb7 (RGBClass constructor, vector
// instances for ButtonFadeEffect / CrossDissolveEffect / TechnoTypeClass) are emitted by the
// loadout screen 0xa68a0. 0xa9fc0 (zero rectangle at 0x83ae50, next to the following TU's
// GAMECONST data at 0x83ae60) directly precedes the next GAMECONST block 0xa9fe0 and is left to the
// next TU.
//
// Not reconstructed yet: 0xa68a0 (0x2a2d bytes, the modal loadout screen; see the claims file).
#include "GAMECONST.H"
#include <wchar.h>
#include <stdio.h>
#include "RECT.H"
#include "SURFACE.H"
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

extern int Frame;                               // 0xa2896c, game frame counter

// Timer source returning the game frame counter (see Super.CPP).
class FrameTimerClass {
public:
    long operator()() const { return Frame; }
};

// Count-down timer (start, timer source, delay); see Super.CPP.
template<class T>
class CDTimerClass {
public:
    CDTimerClass(long set = 0) : Started(Timer()), DelayTime(set) {}
    long Started;
    T Timer;
    long DelayTime;
};

// Pointer swizzling while loading (object 0xaa5370); see Super.CPP.
class SwizzleManagerClass {
public:
    long __stdcall Swizzle(void ** pointer);             // 0x695170
};
extern SwizzleManagerClass SwizzleManager;

// RTTI .?AVWeaponTypeClass@@. Only the name.
class WeaponTypeClass {
public:
    char Unknown0[0x64];
    char Name[0x30];                            // +0x64 (AbstractTypeClass::Name)
};

// Weapon slot of a techno type, 0x1c bytes (TechnoTypeClass +0x74c).
struct WeaponStruct {
    WeaponTypeClass * WeaponType;
    char Unknown04[0x1c - 4];
};

// RTTI .?AVTechnoTypeClass@@, primary vtable 0x797f28 (48 slots). Only slot 43 is used here.
class TechnoTypeClass {
public:
    virtual void Slot_00(); virtual void Slot_01(); virtual void Slot_02(); virtual void Slot_03();
    virtual void Slot_04(); virtual void Slot_05(); virtual void Slot_06(); virtual void Slot_07();
    virtual void Slot_08(); virtual void Slot_09(); virtual void Slot_10(); virtual void Slot_11();
    virtual void Slot_12(); virtual void Slot_13(); virtual void Slot_14(); virtual void Slot_15();
    virtual void Slot_16(); virtual void Slot_17(); virtual void Slot_18(); virtual void Slot_19();
    virtual void Slot_20(); virtual void Slot_21(); virtual void Slot_22(); virtual void Slot_23();
    virtual void Slot_24(); virtual void Slot_25(); virtual void Slot_26(); virtual void Slot_27();
    virtual void Slot_28(); virtual void Slot_29(); virtual void Slot_30(); virtual void Slot_31();
    virtual void Slot_32(); virtual void Slot_33(); virtual void Slot_34(); virtual void Slot_35();
    virtual void Slot_36(); virtual void Slot_37(); virtual void Slot_38(); virtual void Slot_39();
    virtual void Slot_40(); virtual void Slot_41(); virtual void Slot_42();
    virtual int Cost_Of() const;                // slot 43 (+0xac): 0x6d0250

    WeaponStruct & Get_Weapon(int index);       // 0x6d4b30

    char Unknown04[0x64 - 4];
    char Name[0x38];                            // +0x64 (AbstractTypeClass::Name)
    int Armor;                                  // +0x9c
};
extern char const * ArmorNames[];               // 0x788e28

// Only the fields used here; layout not reconstructed.
class ScenarioClass {
public:
    char Unknown0[0x2250];
    int Dropship;                               // +0x2250, 1-based dropship type (0: none)
    DynamicVectorClass<TechnoTypeClass *> DropshipTypes;   // +0x2254, types offered by the scenario
    int Unknown226C;
    DynamicVectorClass<int> DropshipLimits;     // +0x2270, -1: not offered
    int Unknown2288;
    DynamicVectorClass<int> DropshipUsed;       // +0x228c, number already chosen
};
extern ScenarioClass * Scen;                    // 0xa255c0

// RTTI .?AVConvertClass@@ (vtable 0x788f70), 0x188 bytes. Layout not reconstructed.
class ConvertClass {
public:
    int Func_485880(int value);                 // 0x485880 (meaning unknown)
};

// Draws a rectangle of one surface into another through a drawer (0x49f0c0, __fastcall,
// ret 0x28). Names and the meaning of the trailing arguments are provisional.
void Blit_Surface(Surface * dest, ConvertClass * drawer, Surface * source, RectangleStruct const & source_rect,
    Point2D const & point, RectangleStruct const & dest_rect, int arg5, int arg6, int arg7, int arg8,
    int arg9, int arg10);

// RTTI .?AVBitFont@@ (vtable 0x787788).
class BitFont {
public:
    int String_Pixel_Width(wchar_t const * text, int max_width);   // 0x431550
};
BitFont * Font_Ptr(int flags);                  // 0x497830, returns TextFont (0x836d30)

class ColorScheme {
public:
    static ColorScheme * Find(char const * name, int shades);  // 0x65ace0
};

// Variadic text printer (cdecl, 0x497920); see LdPrgMgr.cpp.
Point2D __cdecl Fancy_Text_Print(wchar_t const * text, Surface * surface, RectangleStruct const & rect,
    Point2D const & xy, ColorScheme * fore, unsigned back, int flags, ...);

extern Surface * HiddenSurface;                // 0x821c94

// ---- end of local declarations ----

// One of the three dropship loadouts of a house, 0x2c bytes.
class DropshipLoadoutClass {
public:
    enum { MAX_TYPES = 5 };

    DropshipLoadoutClass();
    ~DropshipLoadoutClass();
    bool Add(TechnoTypeClass * type);
    bool Remove(int index);
    void Clear();
    void Swizzle();
    TechnoTypeClass * Fetch(int index);
    static int Type_Index(TechnoTypeClass * type);

    CDTimerClass<FrameTimerClass> Timer;        // +0x00
    bool IsDone;                                // +0x0c (meaning provisional)
    int Count;                                  // +0x10
    TechnoTypeClass * Types[MAX_TYPES];         // +0x14
    int Cost;                                   // +0x28
};

// Smallest rectangle that contains both rectangles (inline helper; name provisional).
inline RectangleStruct Union(RectangleStruct const & rect1, RectangleStruct const & rect2)
{
    RectangleStruct rect = rect1;
    if (rect.X > rect2.X) {
        rect.Width += rect.X - rect2.X;
        rect.X = rect2.X;
    }
    if (rect.Y > rect2.Y) {
        rect.Height += rect.Y - rect2.Y;
        rect.Y = rect2.Y;
    }
    if (rect.X + rect.Width < rect2.X + rect2.Width) {
        rect.Width = rect2.X + rect2.Width - rect.X + 1;
    }
    if (rect.Y + rect.Height < rect2.Y + rect2.Height) {
        rect.Height = rect2.Y + rect2.Height - rect.Y + 1;
    }
    return rect;
}

// First own initializer (0xa6600): 16 zero bytes at 0x83adb8.
static RectangleStruct const ZeroRect(0, 0, 0, 0);

// Index of the type in the scenario's dropship list, or -1 when it is not offered.
inline int Dropship_Type_Index(TechnoTypeClass * type)
{
    if (Scen->DropshipTypes.ActiveCount == 0) {
        return -1;
    }
    for (int index = 0; index < Scen->DropshipTypes.ActiveCount; index++) {
        if (Scen->DropshipTypes[index] == type && Scen->DropshipLimits[index] != -1) {
            return index;
        }
    }
    return -1;
}

// 0xa6620
DropshipLoadoutClass::DropshipLoadoutClass() :
    Timer(0x7fffffff),
    IsDone(false),
    Count(0),
    Cost(0)
{
}

// 0xa6640
DropshipLoadoutClass::~DropshipLoadoutClass()
{
}

// 0xa6650
bool DropshipLoadoutClass::Add(TechnoTypeClass * type)
{
    if (Count < MAX_TYPES) {
        int index = Dropship_Type_Index(type);
        if (index == -1 || Scen->DropshipUsed[index] < Scen->DropshipLimits[index]) {
            Types[Count] = type;
            Count++;
            Cost += type->Cost_Of();
            if (index != -1) {
                Scen->DropshipUsed[index]++;
            }
            return true;
        }
    }
    return false;
}

// 0xa6720
bool DropshipLoadoutClass::Remove(int index)
{
    if (Count > 0 && index >= 0 && index < Count) {
        int type = Dropship_Type_Index(Types[index]);
        if (type != -1) {
            Scen->DropshipUsed[type]--;
        }
        Cost -= Types[index]->Cost_Of();
        for (int i = index; i < Count - 1; i++) {
            Types[i] = Types[i + 1];
        }
        Count--;
        Types[Count] = NULL;
        return true;
    }
    return false;
}

// 0xa67f0
void DropshipLoadoutClass::Clear()
{
    IsDone = false;
    int count = Count;
    for (int i = 0; i < count; i++) {
        Remove(0);
    }
    Count = 0;
    Cost = 0;
}

// 0xa6820
void DropshipLoadoutClass::Swizzle()
{
    for (int i = 0; i < Count; i++) {
        SwizzleManager.Swizzle((void **)&Types[i]);
    }
}

// 0xa6850
TechnoTypeClass * DropshipLoadoutClass::Fetch(int index)
{
    return Types[index];
}

// 0xa6860
int DropshipLoadoutClass::Type_Index(TechnoTypeClass * type)
{
    return Dropship_Type_Index(type);
}

static wchar_t CounterText[16];                 // 0x83ad98
static wchar_t OldCounterText[16];              // 0x83ade8

// 0xa92d0: prints "<label><value>" in yellow at the point after restoring the background of the
// area that the old and the new text cover.
void Draw_Counter(int value, int old_value, Surface * background, Point2D const & point, wchar_t const * label,
    bool centered, ConvertClass * drawer, int arg6)
{
    int flags = 0x46;
    if (centered) {
        flags = 0x146;
    }
    BitFont * font = Font_Ptr(flags);
    swprintf(CounterText, L"%s%d", label, value);
    swprintf(OldCounterText, L"%s%d", label, old_value);
    int x;
    int old_x;
    if (centered) {
        x = point.X - font->String_Pixel_Width(CounterText, 0) / 2;
        old_x = point.X - font->String_Pixel_Width(OldCounterText, 0) / 2;
    } else {
        x = point.X;
        old_x = x;
    }
    RectangleStruct rect = Union(RectangleStruct(x, point.Y, 110, 15), RectangleStruct(old_x, point.Y, 110, 15));
    RectangleStruct source = rect;
    source.X -= (HiddenSurface->Get_Width() - background->Get_Width()) / 2;
    source.Y -= (HiddenSurface->Get_Height() - background->Get_Height()) / 2;
    Blit_Surface(HiddenSurface, drawer, background, source, Point2D(0, 0), rect, 0, arg6, 0, 0, 1000, 0);
    Fancy_Text_Print(CounterText, HiddenSurface, HiddenSurface->Get_Rect(), point, ColorScheme::Find("Yellow", 1), 0, flags);
}

// 0xa94c0: information panel of a unit type (name, armament, armor, cost).
void Draw_Type_Info(Surface * background, ConvertClass * drawer, TechnoTypeClass * type, bool affordable)
{
    RectangleStruct rect = RectangleStruct(450, 300, 190, 80);
    TPoint2D offset((HiddenSurface->Get_Width() - background->Get_Width()) / 2,
        (HiddenSurface->Get_Height() - background->Get_Height()) / 2);
    TPoint2D position = TPoint2D(450, 300);
    // 0x453ab0 receives the TPoint2D sum itself (RECT.H declares it with Point2D const &).
    RectangleStruct area = RectangleStruct(*(Point2D const *)&(position + offset), 190, 80);
    Blit_Surface(HiddenSurface, drawer, background, rect, Point2D(0, 0), area, 0, drawer->Func_485880(0), 0, 0, 1000, 0);
    if (type != NULL) {
        wchar_t name[40];
        wchar_t cost[20];
        wchar_t armament[40];
        wchar_t armor[30];
        swprintf(name, L"Name: %s", type->Name);
        if (affordable) {
            swprintf(cost, L"Cost: %d", type->Cost_Of());
        } else {
            swprintf(cost, L"Cost: N/A");
        }
        if (type->Get_Weapon(0).WeaponType != NULL) {
            swprintf(armament, L"Armament: %s", type->Get_Weapon(0).WeaponType->Name);
        } else {
            swprintf(armament, L"Armament: NONE");
        }
        swprintf(armor, L"Armor: %s", ArmorNames[type->Armor]);
        ColorScheme * scheme = ColorScheme::Find(affordable ? "Green" : "Red", 1);
        Fancy_Text_Print(name, HiddenSurface, HiddenSurface->Get_Rect(), Point2D(offset.X + 450, offset.Y + 300), scheme, 0, 0x46);
        Fancy_Text_Print(armament, HiddenSurface, HiddenSurface->Get_Rect(), Point2D(offset.X + 450, offset.Y + 315), scheme, 0, 0x46);
        Fancy_Text_Print(armor, HiddenSurface, HiddenSurface->Get_Rect(), Point2D(offset.X + 450, offset.Y + 330), scheme, 0, 0x46);
        Fancy_Text_Print(cost, HiddenSurface, HiddenSurface->Get_Rect(), Point2D(offset.X + 450, offset.Y + 345), scheme, 0, 0x46);
    }
}
