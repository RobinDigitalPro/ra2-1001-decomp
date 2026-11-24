// C:\RA2\Ion.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Lightning (ion) storm weather: clouds appear over a target cell, lightning bolts strike from
// them, and the scene ambient/tint is changed while the storm (or a nuke flash, FlashStatus 1/2)
// is active. The file name is proven by __FILE__ ("C:\RA2\Ion.cpp") in 0x11ee70, 0x11f740 and
// 0x120130; the strings name the effect "LightningStorm". There is no RTTI for the storm class;
// the class name LightningStormClass and all member, function and global names are provisional.
//
// TU boundary: 0x11e450 .. 0x1204d7. 0x11e450..0x11e611 is this TU's own GAMECONST.H block, then
// the 16-byte zero initializer 0x11e620 (.bss 0xa394d8), Coords 0x11e640 (.bss 0xa394b8), the
// three static vectors 0x11e650/0x11e6f0/0x11e790 (.bss 0xa39548/0xa394c0/0xa39508, guarded
// atexit destructors of static data members), the functions 0x11e830..0x120177 in source order
// and the DynamicVectorClass<AnimClass const *> instances 0x120180..0x1204d7 (claimed by
// templates/VECTOR_INSTANCES.cpp). All .bss it writes (0xa394a8..0xa39587) lies between its own
// GAMECONST constants, and the anchor functions read the same EmptyCell/EmptyCoord/I7/I10 copies.
// The next TU (IonBlast, DynamicVectorClass<IonBlastClass *>) starts with the GAMECONST block
// 0x1204e0. src/ra2/unnamed/TU_51E450.cpp reconstructs the same GAMECONST block and is therefore
// a duplicate of this file's initializers (left untouched here; for the integrator).
#include "GAMECONST.H"
#include "ABSTRACT.H"
#include "RECT.H"
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60
int Play_Sound(int voc, float volume, int pan, int flags);   // 0x708970 (names provisional)
void Speak(char const * name, int arg2 = -1, int arg3 = -1);  // 0x70a700 (see Super.CPP)
void Sound_Effect(int voc, CoordStruct const & coord, int arg = 0);  // 0x708a20 (name provisional)
int Pixel_To_Lepton(int pixel);                 // 0x697ff0 (name provisional)
extern int Frame;                               // 0xa2896c, game frame counter

inline bool operator == (CellStruct const & left, CellStruct const & right)
{
    return left.X == right.X && left.Y == right.Y;
}
inline bool operator == (CoordStruct const & left, CoordStruct const & right)
{
    return left.X == right.X && left.Y == right.Y && left.Z == right.Z;
}

// Frame-based count-down timer (as in Super.CPP).
class FrameTimerClass {
public:
    long operator()() const { return Frame; }
};
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
    HRESULT __stdcall Swizzle(void ** pointer);             // 0x695170
};
extern SwizzleManagerClass SwizzleManager;

// Random number generator inside the scenario (as in MPCoop.cpp).
// level-2 1.001: Random2Class (operator() 0x62FE40, the scenario generator), not RandomClass (0x62FCC0); shown by the P9 link check.
class Random2Class {
public:
    unsigned operator()();                      // 0x62fde0
    int operator()(int minval, int maxval);     // 0x62fe40
};

class ScenarioClass {
public:
    char Unknown0[0x218];
    Random2Class RandomNumber;                   // +0x218
    char Unknown219[0x828 - 0x219];
    CDTimerClass<FrameTimerClass> AmbientTimer; // +0x828 (name provisional)
    char Unknown834[0x22A8 - 0x834];
    int NormalAmbient;                          // +0x22a8
    char Unknown22AC[0x22B0 - 0x22AC];
    int CurrentAmbient;                         // +0x22b0
    char Unknown22B4[0x22C8 - 0x22B4];
    int IonAmbient;                             // +0x22c8
    int IonRed;                                 // +0x22cc
    int IonGreen;                               // +0x22d0
    int IonBlue;                                // +0x22d4
    char Unknown22D8[0x22E0 - 0x22D8];
    int NukeAmbient;                            // +0x22e0
    int NukeRed;                                // +0x22e4
    int NukeGreen;                              // +0x22e8
    int NukeBlue;                               // +0x22ec
};
extern ScenarioClass * Scen;                    // 0xa255c0
inline int Random_Pick(int a, int b) { return Scen->RandomNumber(a, b); }
inline unsigned Random_Number() { return Scen->RandomNumber(); }

// Session object at 0xa255c8; only the member used here.
class SessionClass {
public:
    char Unknown0[0x2B0];
    int Field2B0;                               // +0x2b0 (0xa25878), meaning unknown
};
extern SessionClass Session;                    // 0xa255c8

class MessageListClass {
public:
    void * Add_Message(wchar_t const * name, int id, wchar_t const * text, int color,
        int style, int timeout, bool flag);     // 0x5b1980
};
extern MessageListClass SessionMessages;        // 0xa25fa0 (Session + 0x9d8)

struct ShapeFileStruct {
    short Type;                                 // +0
    short Width;                                // +2
    short Height;                               // +4
    short Count;                                // +6, number of frames
};

class CCINIClass;
class ObjectTypeClass : public AbstractClass {
public:
    virtual void Load_Theater_Art(int theater);
    virtual bool Read_INI(CCINIClass & ini);
    virtual bool Write_INI(CCINIClass & ini) const;
    virtual void Slot_027(); virtual void Slot_028(); virtual void Slot_029(); virtual void Slot_030();
    virtual void Slot_031(); virtual void Slot_032(); virtual void Slot_033(); virtual void Slot_034();
    virtual void Slot_035(); virtual void Slot_036(); virtual void Slot_037(); virtual void Slot_038();
    virtual ShapeFileStruct const * Get_Image_Data() const;  // slot 39 (+0x9c)
};
class AnimTypeClass : public ObjectTypeClass {
};
class WarheadTypeClass;

enum { RTTI_INFANTRY = 15 };

class ObjectClass : public AbstractClass {
public:
    virtual void Slot_024(); virtual void Slot_025(); virtual void Slot_026(); virtual void Slot_027();
    virtual void Slot_028(); virtual void Slot_029(); virtual void Slot_030(); virtual void Slot_031();
    virtual void Slot_032();
    virtual ObjectTypeClass * Class_Of() const;             // slot 33 (+0x84)
};
class BuildingClass;

// RTTI .?AVAnimClass@@, 0x1a8 bytes. Only what is used here.
class AnimClass : public ObjectClass {
public:
    AnimClass(AnimTypeClass * type, CoordStruct const & coord, int timedelay = 0, int loop = 1,
        int flags = 0x600, int arg6 = 0);       // 0x420110
    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    char Unknown24[0x98 - 0x24];
    int Stage;                                  // +0x98, current frame (name provisional)
    char Unknown9C[0x1A8 - 0x9C];
};

class HouseClass {
public:
    bool Is_Ally(HouseClass const * house) const;   // 0x4e4be0
    void Func_4F4D40(int duration);             // 0x4f4d40 (storm warning, meaning provisional)
    char Unknown0[0x13D];
    bool IsDefeated;                            // +0x13d (name provisional)
    char Unknown13E[0x5669 - 0x13E];
    bool Field5669;                             // +0x5669 (set while a storm is active)
    char Unknown566A[0x15F40 - 0x566A];
    int ColorScheme;                            // +0x15f40
};
extern DynamicVectorClass<HouseClass *> Houses; // 0xa1a5c8
extern HouseClass * PlayerPtr;                  // 0xa1e0e4

class CellClass {
public:
    BuildingClass * Cell_Building() const;      // 0x4713b0
    ObjectClass * Cell_Object(Point2D const & spot = Point2D(0, 0), bool alt = false, int arg = 0) const;  // 0x471260 (provisional)
    CoordStruct Cell_Coord() const;             // 0x475960
    char Unknown0[0x24];
    CellStruct MapCoords;                       // +0x24
    char Unknown28[0xEC - 0x28];
    int LandType;                               // +0xec
    char UnknownF0[0x11B - 0xF0];
    signed char Level;                          // +0x11b
    char Unknown11C[0x140 - 0x11C];
    int Flags;                                  // +0x140 (bit 8 tested; meaning unknown)

    int Height() const { return ((Flags & 0x100) ? I10 : 0) + Level * I7; }
};

inline CellStruct Coord_Cell(CoordStruct const & coord)
{
    return CellStruct((short)(coord.X / 256), (short)(coord.Y / 256));
}

class GScreenClass {
public:
    virtual void Flag_To_Redraw(int complete);  // 0x4e0030
};
class MapClass : public GScreenClass {
public:
    CellClass & operator [] (CoordStruct const & coord);    // 0x545490
    CellClass & operator [] (CellStruct const & cell);      // 0x545500
    bool In_Radar(CellStruct const & cell) const;           // 0x547f40
    void Func_49E310();                                     // 0x49e310 (meaning unknown)
    char Unknown4[0x128 - 0x4];
    int MapCellWidth;                           // +0x128 (name provisional)
    int MapCellHeight;                          // +0x12c (name provisional)
};
class MouseClass : public MapClass {
};
extern MouseClass Map;                          // 0x81a820

class RulesClass {
public:
    char Unknown0[0x134];
    DynamicVectorClass<AnimTypeClass *> DebrisAnims;    // +0x134 (name provisional)
    char Unknown14C[0x250 - 0x14C];
    DynamicVectorClass<AnimTypeClass *> CloudAnims;     // +0x250
    char Unknown268[0x26C - 0x268];
    DynamicVectorClass<AnimTypeClass *> BoltAnims;      // +0x26c
    char Unknown284[0x650 - 0x284];
    int StormSound;                                     // +0x650
    DynamicVectorClass<int> BoltSounds;                 // +0x654
    char Unknown66C[0x13EC - 0x66C];
    int BoltDamage;                                     // +0x13ec
    int Unknown13F0;
    int CloudDelay;                                     // +0x13f4
    int ScatterDelay;                                   // +0x13f8
    int ScatterRange;                                   // +0x13fc
    int CloudSeparation;                                // +0x1400
    bool StormMessages;                                 // +0x1404
    WarheadTypeClass * BoltWarhead;                     // +0x1408
};
extern RulesClass * Rule;                       // 0x821b88

AnimTypeClass * Combat_Anim(int damage, WarheadTypeClass * warhead, int landtype, CoordStruct const & coord);  // 0x47f0f0
int Func_47F8E0(CoordStruct coord);             // 0x47f8e0 (meaning unknown)
void Func_47F220(int damage, WarheadTypeClass * warhead, CoordStruct coord, int arg4, int arg5);    // 0x47f220 (meaning unknown)
void Damage_Area(CoordStruct const & coord, int damage, ObjectClass * source, WarheadTypeClass * warhead, bool flag);    // 0x47dec0

// Colour remaps that follow the ambient tint.
class ConvertClass {
public:
    virtual ~ConvertClass();
    virtual void Adjust_Tint(int red, int green, int blue, bool flag);  // slot 1 (name provisional)
};
extern DynamicVectorClass<ConvertClass *> Converts; // 0x81a6d8 (name provisional)

class ColorScheme {
public:
    char Unknown0[0x30C];
    ConvertClass * Convert;                     // +0x30c
    int Field310;                               // +0x310
};
extern DynamicVectorClass<ColorScheme *> ColorSchemes;   // 0xa9ea00

// Iterator over extra colour scheme sets (0x5fb220 Next; set size from 0x5fb7f0). Provisional.
class SchemeSetIterator {
public:
    SchemeSetIterator() : Bucket(0), Index(0), Done(false) {}
    DynamicVectorClass<ColorScheme *> * Next();  // 0x5fb220
    int Bucket;
    int Index;
    bool Done;
};
int Scheme_Set_Count();                         // 0x5fb7f0

void Adjust_Scheme_Set_Tints(int red, int green, int blue, bool flag);   // 0x51ffc0
void Adjust_Tints(int red, int green, int blue, bool flag);              // 0x520040

class LightningStormClass {
public:
    static void Init_Clear();                   // 0x51e830
    static HRESULT Save(IStream * pStm);        // 0x51e930
    static HRESULT Load(IStream * pStm);        // 0x51eb20
    static void Set_Active(bool active);        // 0x51ee60
    static void Start(int duration, int deferment, CellStruct cell, HouseClass * owner);   // 0x51ee70
    static void Request_Stop();                 // 0x51f0f0
    static void Stop();                         // 0x51f110
    static int Active_Or_Deferred();           // 0x51f170
    static bool Is_Active();                    // 0x51f190
    static bool Is_Flash_Rising();              // 0x51f1a0
    static bool Is_Flash_Fading();              // 0x51f1b0
    static bool Func_51F1C0();                  // 0x51f1c0
    static void Manifest_Cloud(CellStruct cell);// 0x51f1d0
    static void Strike(CoordStruct coord);      // 0x51f390
    static void AI();                           // 0x51f740
    static void Update_Ambient();               // 0x51fcb0
    static void Flash_Start();                  // 0x51fde0
    static void Flash_Fade();                   // 0x51fec0
    static void Print_Message();                // 0x520130

    static CellStruct Coords;                   // 0xa394b8
    static DynamicVectorClass<AnimClass const *> CloudsManifesting;   // 0xa39548
    static DynamicVectorClass<AnimClass const *> CloudsPresent;       // 0xa394c0
    static DynamicVectorClass<AnimClass const *> BoltsPresent;        // 0xa39508
    static int StartFrame;                      // 0x7c8bd0
    static int Duration;                        // 0x7c8bd4
    static int FlashStart;                      // 0x7c8bd8
    static int FlashDuration;                   // 0x7c8bdc
    static bool IsActive;                       // 0xa39574
    static int Deferment;                       // 0xa39578
    static int FlashStatus;                     // 0xa3957c (1 rising, 2 fading)
    static HouseClass * Owner;                  // 0xa39580
    static bool TimeToEnd;                      // 0xa39584
};

// ---- end of local declarations ----

static RectangleStruct const ZeroRect(0, 0, 0, 0);

CellStruct LightningStormClass::Coords = EmptyCell;
DynamicVectorClass<AnimClass const *> LightningStormClass::CloudsManifesting;
DynamicVectorClass<AnimClass const *> LightningStormClass::CloudsPresent;
DynamicVectorClass<AnimClass const *> LightningStormClass::BoltsPresent;
int LightningStormClass::StartFrame = -1;
int LightningStormClass::Duration = -1;
int LightningStormClass::FlashStart = -1;
int LightningStormClass::FlashDuration = -1;
bool LightningStormClass::IsActive;
int LightningStormClass::Deferment;
int LightningStormClass::FlashStatus;
HouseClass * LightningStormClass::Owner;
bool LightningStormClass::TimeToEnd;

// 0x11e830
void LightningStormClass::Init_Clear()
{
    Coords = EmptyCell;
    IsActive = false;
    FlashStatus = 0;
    StartFrame = -1;
    Duration = -1;
    FlashStart = -1;
    FlashDuration = -1;
    Deferment = 0;
    Owner = NULL;
    CloudsManifesting.Clear();
    CloudsPresent.Clear();
    BoltsPresent.Clear();
    Scen->CurrentAmbient = Scen->NormalAmbient;
    Adjust_Tints(-1, -1, -1, false);
}

// 0x11e930
HRESULT LightningStormClass::Save(IStream * pStm)
{
    HRESULT hr;
    hr = pStm->Write(&IsActive, sizeof(IsActive), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(&StartFrame, sizeof(StartFrame), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(&Duration, sizeof(Duration), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(&Deferment, sizeof(Deferment), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(&TimeToEnd, sizeof(TimeToEnd), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(&FlashStart, sizeof(FlashStart), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(&FlashDuration, sizeof(FlashDuration), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(&FlashStatus, sizeof(FlashStatus), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(&Coords, sizeof(Coords), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Write(&Owner, sizeof(Owner), NULL);
    if (FAILED(hr)) return hr;

    int count;
    int index;
    AnimClass const * anim;

    count = CloudsManifesting.Count();
    hr = pStm->Write(&count, sizeof(count), NULL);
    if (FAILED(hr)) return hr;
    for (index = 0; index < count; index++) {
        anim = CloudsManifesting[index];
        hr = pStm->Write(&anim, sizeof(anim), NULL);
        if (FAILED(hr)) return hr;
    }

    count = CloudsPresent.Count();
    hr = pStm->Write(&count, sizeof(count), NULL);
    if (FAILED(hr)) return hr;
    for (index = 0; index < count; index++) {
        anim = CloudsPresent[index];
        hr = pStm->Write(&anim, sizeof(anim), NULL);
        if (FAILED(hr)) return hr;
    }

    count = BoltsPresent.Count();
    hr = pStm->Write(&count, sizeof(count), NULL);
    if (FAILED(hr)) return hr;
    for (index = 0; index < count; index++) {
        anim = BoltsPresent[index];
        hr = pStm->Write(&anim, sizeof(anim), NULL);
        if (FAILED(hr)) return hr;
    }
    return hr;
}

// 0x11eb20
HRESULT LightningStormClass::Load(IStream * pStm)
{
    HRESULT hr;
    hr = pStm->Read(&IsActive, sizeof(IsActive), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Read(&StartFrame, sizeof(StartFrame), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Read(&Duration, sizeof(Duration), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Read(&Deferment, sizeof(Deferment), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Read(&TimeToEnd, sizeof(TimeToEnd), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Read(&FlashStart, sizeof(FlashStart), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Read(&FlashDuration, sizeof(FlashDuration), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Read(&FlashStatus, sizeof(FlashStatus), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Read(&Coords, sizeof(Coords), NULL);
    if (FAILED(hr)) return hr;
    hr = pStm->Read(&Owner, sizeof(Owner), NULL);
    if (FAILED(hr)) return hr;
    SwizzleManager.Swizzle((void **)&Owner);

    int count;
    int index;
    AnimClass const * anim;

    hr = pStm->Read(&count, sizeof(count), NULL);
    if (FAILED(hr)) return hr;
    for (index = 0; index < count; index++) {
        hr = pStm->Read(&anim, sizeof(anim), NULL);
        if (FAILED(hr)) return hr;
        CloudsManifesting.Add(anim);
    }
    for (index = 0; index < count; index++) {
        SwizzleManager.Swizzle((void **)&CloudsManifesting[index]);
    }

    hr = pStm->Read(&count, sizeof(count), NULL);
    if (FAILED(hr)) return hr;
    for (index = 0; index < count; index++) {
        hr = pStm->Read(&anim, sizeof(anim), NULL);
        if (FAILED(hr)) return hr;
        CloudsPresent.Add(anim);
    }
    for (index = 0; index < count; index++) {
        SwizzleManager.Swizzle((void **)&CloudsPresent[index]);
    }

    hr = pStm->Read(&count, sizeof(count), NULL);
    if (FAILED(hr)) return hr;
    for (index = 0; index < count; index++) {
        hr = pStm->Read(&anim, sizeof(anim), NULL);
        if (FAILED(hr)) return hr;
        BoltsPresent.Add(anim);
    }
    for (index = 0; index < count; index++) {
        SwizzleManager.Swizzle((void **)&BoltsPresent[index]);
    }
    return hr;
}

// 0x11ee60
void LightningStormClass::Set_Active(bool active)
{
    IsActive = active;
}

// 0x11ee70
void LightningStormClass::Start(int duration, int deferment, CellStruct cell, HouseClass * owner)
{
    if (cell == EmptyCell) {
        while (!Map.In_Radar(cell)) {
            cell = CellStruct(Random_Pick(0, Map.MapCellWidth), Random_Pick(0, Map.MapCellHeight));
        }
    }
    Coords = cell;
    Owner = owner;
    if (IsActive) {
        return;
    }
    if (deferment) {
        if (Deferment == 0 || Deferment >= deferment) {
            Deferment = deferment;
        }
        Duration = duration;
        return;
    }
    Duration = duration;
    StartFrame = Frame;
    IsActive = true;
    for (int index = 0; index < Houses.Count(); index++) {
        if (Owner == NULL || !Owner->Is_Ally(Houses[index])) {
            if (!Houses[index]->IsDefeated && !Session.Field2B0) {
                Houses[index]->Func_4F4D40(duration);
            }
        }
    }
    if (PlayerPtr) {
        PlayerPtr->Field5669 = true;
    }
    if (FlashStatus != 1) {
        Scen->CurrentAmbient = Scen->IonAmbient;
        Adjust_Tints(Scen->IonRed * 1000 / 100, Scen->IonGreen * 1000 / 100, Scen->IonBlue * 1000 / 100, true);
    }
    if (Rule->StormMessages) {
        int color = 3;
        if (PlayerPtr) {
            color = PlayerPtr->ColorScheme;
        }
        Play_Sound(Rule->StormSound, 1.0f, 0x2000, 0);
#line 462 "C:\\RA2\\Ion.cpp"
        SessionMessages.Add_Message(NULL, 0, Fetch_String("TXT_LIGHTNING_STORM", NULL, __FILE__, __LINE__), color, 0x4046, 0x96, false);
    }
    Map.Flag_To_Redraw(1);
}

// 0x11f0f0
void LightningStormClass::Request_Stop()
{
    if (IsActive) {
        TimeToEnd = true;
    }
}

// 0x11f110
void LightningStormClass::Stop()
{
    if (IsActive) {
        IsActive = false;
        Coords = EmptyCell;
        Owner = NULL;
        if (FlashStatus != 1) {
            Scen->CurrentAmbient = Scen->NormalAmbient;
            Adjust_Tints(-1, -1, -1, false);
            Map.Flag_To_Redraw(1);
        }
    }
}

// 0x11f170
int LightningStormClass::Active_Or_Deferred()
{
    if (IsActive || Deferment > 0) {
        return true;
    }
    return false;
}

// 0x11f190
bool LightningStormClass::Is_Active()
{
    return IsActive;
}

// 0x11f1a0
bool LightningStormClass::Is_Flash_Rising()
{
    return FlashStatus == 1;
}

// 0x11f1b0
bool LightningStormClass::Is_Flash_Fading()
{
    return FlashStatus == 2;
}

// 0x11f1c0
bool LightningStormClass::Func_51F1C0()
{
    return false;
}

// 0x11f1d0
void LightningStormClass::Manifest_Cloud(CellStruct cell)
{
    CellClass & cellptr = Map[cell];
    int height = Rule->BoltAnims[0]->Get_Image_Data()->Height / 2;
    int z = Pixel_To_Lepton(height);
    z += (cellptr.Flags & 0x100) ? I10 : 0;
    z += cellptr.Level * I7;
    CoordStruct coord(cell.X * 256 + 128, cell.Y * 256 + 128, z);
    if (coord == EmptyCoord) {
        return;
    }
    AnimTypeClass * type = Rule->CloudAnims[Random_Number() % Rule->CloudAnims.Count()];
    AnimClass * anim = new AnimClass(type, coord);
    CloudsManifesting.Add(anim);
    CloudsPresent.Add(anim);
}

// 0x11f390
void LightningStormClass::Strike(CoordStruct coord)
{
    CellClass & cellptr = Map[coord];
    CoordStruct center = cellptr.Cell_Coord();
    AnimTypeClass * type = Rule->BoltAnims[Random_Number() % Rule->BoltAnims.Count()];
    AnimClass * bolt = new AnimClass(type, center);
    BoltsPresent.Add(bolt);

    CellStruct cell = cellptr.MapCoords;
    int level = cellptr.Level;
    CoordStruct target(cell.X * 256 + 128, cell.Y * 256 + 128,
        ((cellptr.Flags & 0x100) ? I10 : 0) + level * I7);
    if (target == EmptyCoord) {
        return;
    }
    if (Rule->BoltSounds.Count() > 0) {
        Sound_Effect(Rule->BoltSounds[Random_Number() % Rule->BoltSounds.Count()], target);
    }
    int damage = Rule->BoltDamage;
    AnimTypeClass * explosion = Combat_Anim(damage, Rule->BoltWarhead, cellptr.LandType, target);
    new AnimClass(explosion, target, 0, 1, 0x2600, Func_47F8E0(target));

    bool debris = false;
    BuildingClass * building = cellptr.Cell_Building();
    ObjectClass * object = cellptr.Cell_Object();
    bool infantry = (object && object->Kind_Of() == RTTI_INFANTRY);
    if (!building && !object) {
        switch (cellptr.LandType) {
            case 1:
            case 3:
            case 4:
            case 11:
                debris = true;
                break;
        }
    }
    Func_47F220(damage, Rule->BoltWarhead, target, 0, 0);
    Damage_Area(target, damage, NULL, Rule->BoltWarhead, true);
    bool changed = (building != cellptr.Cell_Building() || object != cellptr.Cell_Object()
        || cellptr.Level != level) ? true : debris;
    if (!infantry && changed) {
        int count = Random_Pick(2, 4);
        for (int index = 0; index < count; index++) {
            new AnimClass(Rule->DebrisAnims[Random_Pick(0, Rule->DebrisAnims.Count() - 1)], target);
        }
    }
}

// 0x11f740
void LightningStormClass::AI()
{
    if (FlashStatus == 1) {
        if (FlashDuration != -1 && FlashStart + FlashDuration < Frame) {
            FlashStart = Frame;
            FlashStatus = 2;
            FlashDuration = 15;
            if (IsActive) {
                Scen->CurrentAmbient = Scen->IonAmbient;
                Adjust_Tints(Scen->IonRed * 1000 / 100, Scen->IonGreen * 1000 / 100, Scen->IonBlue * 1000 / 100, true);
            } else {
                Scen->CurrentAmbient = Scen->NormalAmbient;
                Adjust_Tints(-1, -1, -1, false);
            }
            Map.Flag_To_Redraw(1);
        }
    } else if (FlashStatus == 2) {
        if (FlashDuration != -1 && FlashStart + FlashDuration < Frame) {
            FlashStatus = 0;
        }
    }

    int index;
    if (BoltsPresent.Count() > 0) {
        for (index = BoltsPresent.Count() - 1; index >= 0; index--) {
            AnimClass const * bolt = BoltsPresent[index];
            int stage = bolt->Stage;
            if (stage >= bolt->Class_Of()->Get_Image_Data()->Count / 2) {
                BoltsPresent.Delete(index);
            }
        }
    }

    for (index = CloudsManifesting.Count() - 1; index >= 0; index--) {
        AnimClass const * cloud = CloudsManifesting[index];
        int stage = cloud->Stage;
        if (stage > cloud->Class_Of()->Get_Image_Data()->Count / 2) {
            Strike(cloud->Center_Coord());
            CloudsManifesting.Delete(index);
        }
    }

    if (CloudsPresent.Count() > 0) {
        for (index = CloudsPresent.Count() - 1; index >= 0; index--) {
            AnimClass const * cloud = CloudsPresent[index];
            int stage = cloud->Stage;
            if (stage >= cloud->Class_Of()->Get_Image_Data()->Count - 1) {
                CloudsPresent.Delete(index);
            }
        }
    } else if (TimeToEnd) {
        Stop();
        TimeToEnd = false;
    }

    if (IsActive && !TimeToEnd) {
        if (Duration != -1 && StartFrame + Duration < Frame) {
            TimeToEnd = true;
            return;
        }
        if (Frame % Rule->CloudDelay == 0) {
            Manifest_Cloud(Coords);
        }
        if (Frame % Rule->ScatterDelay == 0) {
            int range = Rule->ScatterRange >> 1;
            int tries;
            CellStruct cell = Coords;
            for (tries = 3; tries > 0; tries--) {
                cell = Coords;
                cell.X += Random_Pick(-range, range);
                cell.Y += Random_Pick(-range, range);
                bool tooclose = false;
                for (index = 0; index < CloudsPresent.Count(); index++) {
                    CellStruct other = Coord_Cell(CloudsPresent[index]->Center_Coord());
                    int dx = cell.X - other.X;
                    if (dx < 0) dx = -dx;
                    int dy = cell.Y - other.Y;
                    if (dy < 0) dy = -dy;
                    if (dx + dy < Rule->CloudSeparation) {
                        tooclose = true;
                        break;
                    }
                }
                if (Map.In_Radar(cell) && !tooclose) {
                    break;
                }
            }
            if (tries > 0) {
                Manifest_Cloud(cell);
            }
        }
    } else if (Deferment > 0) {
        Deferment--;
        if (Deferment == 0) {
            Start(Duration, 0, Coords, Owner);
        } else if (Deferment % 225 == 0) {
            if (Rule->StormMessages) {
                int color = 3;
                if (PlayerPtr) {
                    color = PlayerPtr->ColorScheme;
                }
                Speak("EVA_LightningStormCreated");
#line 901 "C:\\RA2\\Ion.cpp"
                SessionMessages.Add_Message(NULL, 0, Fetch_String("TXT_LIGHTNING_STORM_APPROACHING", NULL, __FILE__, __LINE__), color, 0x46, 0x96, false);
            }
        }
    }
}

// 0x11fcb0
void LightningStormClass::Update_Ambient()
{
    if (FlashStatus == 1) {
        Scen->CurrentAmbient = Scen->NukeAmbient;
        Adjust_Tints(Scen->NukeRed * 1000 / 100, Scen->NukeGreen * 1000 / 100, Scen->NukeBlue * 1000 / 100, true);
    } else if (IsActive) {
        PlayerPtr->Field5669 = true;
        Scen->CurrentAmbient = Scen->IonAmbient;
        Adjust_Tints(Scen->IonRed * 1000 / 100, Scen->IonGreen * 1000 / 100, Scen->IonBlue * 1000 / 100, true);
    }
}

// 0x11fde0
void LightningStormClass::Flash_Start()
{
    FlashStatus = 1;
    FlashDuration = 30;
    FlashStart = Frame;
    Scen->AmbientTimer = 1;
    Scen->CurrentAmbient = Scen->NukeAmbient;
    Adjust_Tints(Scen->NukeRed * 1000 / 100, Scen->NukeGreen * 1000 / 100, Scen->NukeBlue * 1000 / 100, true);
    Map.Flag_To_Redraw(1);
}

// 0x11fec0
void LightningStormClass::Flash_Fade()
{
    FlashStatus = 2;
    FlashStart = Frame;
    FlashDuration = 15;
    if (IsActive) {
        Scen->CurrentAmbient = Scen->IonAmbient;
        Adjust_Tints(Scen->IonRed * 1000 / 100, Scen->IonGreen * 1000 / 100, Scen->IonBlue * 1000 / 100, true);
    } else {
        Scen->CurrentAmbient = Scen->NormalAmbient;
        Adjust_Tints(-1, -1, -1, false);
    }
    Map.Flag_To_Redraw(1);
}

// 0x11ffc0
void Adjust_Scheme_Set_Tints(int red, int green, int blue, bool flag)
{
    SchemeSetIterator iter;
    DynamicVectorClass<ColorScheme *> * schemes = iter.Next();
    while (schemes) {
        int count = Scheme_Set_Count();
        for (int index = 0; index < count; index++) {
            (*schemes)[index]->Convert->Adjust_Tint(red, green, blue, flag);
        }
        schemes = iter.Next();
    }
}

// 0x120040
void Adjust_Tints(int red, int green, int blue, bool flag)
{
    int index;
    for (index = 0; index < Converts.Count(); index++) {
        Converts[index]->Adjust_Tint(red, green, blue, flag);
    }
    for (index = 0; index < ColorSchemes.Count(); index++) {
        if (ColorSchemes[index]->Field310 > 1) {
            ColorSchemes[index]->Convert->Adjust_Tint(red, green, blue, flag);
        }
    }
    Adjust_Scheme_Set_Tints(red, green, blue, flag);
    Map.Func_49E310();
}

// 0x120130
void LightningStormClass::Print_Message()
{
#line 1063 "C:\\RA2\\Ion.cpp"
    wchar_t const * text = Fetch_String("Msg:LightningStormActive", NULL, __FILE__, __LINE__);
    int color = 3;
    if (PlayerPtr) {
        color = PlayerPtr->ColorScheme;
    }
    SessionMessages.Add_Message(NULL, 0, text, color, 0x4046, 0x96, false);
}
