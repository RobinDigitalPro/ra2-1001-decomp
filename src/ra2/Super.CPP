// C:\RA2\Super.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Contents: SuperClass, the superweapon instance owned by a house (RTTI .?AVSuperClass@@, primary
// vtable 0x7970b8, base AbstractClass). Kind_Of/What_Am_I return 0x39, Size_Of is 0x68.
// Method, member and variable names are provisional unless a debug string names them.
#include "GAMECONST.H"
#include "ABSTRACT.H"
#include "ABSTYPE.H"
#include "VECTOR.H"
#include "CRC.H"
#include <new.h>


// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60

extern int Frame;                               // 0xa2896c, game frame counter (other TUs: NetworkEventMode)

// Timer source returning the game frame counter.
class FrameTimerClass {
public:
    long operator()() const { return Frame; }
};

// Count-down timer (start, timer source, delay); Started == -1 means stopped. Same layout as
// Power.CPP. The operator long form returning from inside the branch is required by AI (0x292a30);
// Value is the out-of-line 0x453b30 used by Stop; 0x694380 is the out-of-line Start. The assignment
// from a long goes through a temporary and the implicit copy (the timer-source dword is copied too).
template<class T>
class CDTimerClass {
public:
    CDTimerClass(long set = 0) : Started(Timer()), DelayTime(set) {}
    CDTimerClass(NoInitClass const &) {}
    operator long() const
    {
        long remain = DelayTime;
        if (Started != -1) {
            long elapsed = Timer() - Started;
            if (elapsed < remain) {
                return remain - elapsed;
            }
            return 0;
        }
        return remain;
    }
    long Value() const;
    bool Is_Active() const;
    void Start();
    void Stop();

    long Started;
    T Timer;
    long DelayTime;
};

template<class T>
long CDTimerClass<T>::Value() const
{
    long remain = DelayTime;
    if (Started != -1) {
        long elapsed = Timer() - Started;
        if (elapsed < remain) {
            remain -= elapsed;
        } else {
            remain = 0;
        }
    }
    return remain;
}

template<class T>
bool CDTimerClass<T>::Is_Active() const
{
    return Started != -1;
}

template<class T>
void CDTimerClass<T>::Start()
{
    if (Started == -1) {
        Started = Timer();
    }
}

// The original repeats the Started test inside the inlined Value (see Suspend 0x292300); this form
// does not reproduce that yet.
template<class T>
void CDTimerClass<T>::Stop()
{
    if (Started != -1) {
        DelayTime = Value();
        Started = -1;
    }
}

// Pointer swizzling while loading (object 0xaa5370); SWIZZLE.H has only Here_I_Am.
class SwizzleManagerClass {
public:
    HRESULT __stdcall Swizzle(void ** pointer);             // 0x695170
    HRESULT __stdcall Here_I_Am(LONG id, void * pointer);   // 0x6951f0
};
extern SwizzleManagerClass SwizzleManager;

// Sound effect / EVA speech by name (0x70a700, __fastcall, three arguments).
void Speak(char const * name, int arg2 = -1, int arg3 = -1);
bool Func_51F170();                             // 0x51f170, meaning unknown (checked before a lightning storm)
void Func_520130();                             // 0x520130, meaning unknown (player message)

// RTTI .?AVSuperWeaponTypeClass@@ (vtable 0x797160). Only the fields used here.
enum SuperWeaponType {
    SUPER_NUKE = 0,                 // EVA_NuclearMissileReady
    SUPER_IRON_CURTAIN = 1,         // EVA_IronCurtainReady
    SUPER_LIGHTNING_STORM = 2,      // EVA_LightningStormReady
    SUPER_CHRONOSPHERE = 3,         // EVA_ChronosphereReady
    SUPER_CHRONOWARP = 4,
    SUPER_PARADROP = 5,             // EVA_ReinforcementsReady
    SUPER_AMERICAN_PARADROP = 6     // EVA_ReinforcementsReady
};
class SuperWeaponTypeClass : public AbstractTypeClass {
public:

    int ArrayIndex;
    char Unknown9C[0xb0 - 0x9c];
    int RechargeTime;                           // +0xb0
    int Type;                                   // +0xb4, SuperWeaponType
    char UnknownB8[0xdd - 0xb8];
    bool IsToggle;                              // +0xdd (cameo state 0/1/2, TXT_FIRESTORM_ON)
    bool FlagDE;                                // +0xde
    bool FlagDF;                                // +0xdf
    bool FlagE0;                                // +0xe0
    bool FlagE1;                                // +0xe1 (stays ready after discharge)
    char UnknownE2[0xe8 - 0xe2];
    bool ShowTimer;                             // +0xe8 (adds the super to ShowTimers)
    bool IsPowered;                             // +0xe9 (timer runs only while powered)
};

// RTTI .?AVHouseTypeClass@@. Only the field used here (see CampScor.cpp).
class HouseTypeClass {
public:
    char Unknown0[0x1a6];
    bool IsMultiplayPassive;                    // +0x1a6
};

// RTTI .?AVHouseClass@@. Only the fields used here.
class BuildingClass;
class WarheadTypeClass;
class InfantryTypeClass;
class HouseClass : public AbstractClass {
public:
    bool Func_4F47F0() const;                   // 0x4f47f0, meaning unknown
    char Unknown24[0x34 - 0x24];
    HouseTypeClass * Class;                     // +0x34
    BuildingClass * Find_Building(int, int);
    char Unknown38[0x130 - 0x38];
    int ActLike;
    char Unknown134[0x142 - 0x134];
    bool Flag142;                               // +0x142
    char Unknown143;
    bool IsRecalcNeeded;
    char Unknown145[0x5670 - 0x145];
    CellStruct NukeDest;                            // +0x5670
};

// RTTI .?AVAnimClass@@ (vtable 0x787084). Only what is used here.
class AnimTypeClass;
class AnimSoundClass {
public:
    void Func_405D50();                         // 0x405d50
    void Func_405FE0();                         // 0x405fe0
};
class AnimClass : public AbstractClass {
public:
    AnimClass(AnimTypeClass * type, CoordStruct const & coord, int timedelay = 0, int loop = 1,
        int flags = 0x600, int arg6 = 0);       // 0x420110
    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    char Unknown24[0x175 - 0x24];
    bool IsSuperAnim;                           // +0x175 (cleared when the super lets go of it)
    char Unknown176[0x17d - 0x176];
    bool Flag17D;                               // +0x17d
    char Unknown17E[0x180 - 0x17e];
    AnimSoundClass Sound;                       // +0x180
};

// RTTI .?AVRulesClass@@. Only the fields used here.
class RulesClass {
public:
    char Unknown0[0x16c];
    int DigSound;
    char Unknown170[0x28c - 0x170];
    AnimTypeClass * Anim28C;                    // +0x28c
    AnimTypeClass * Anim290;                    // +0x290
    AnimTypeClass * Anim294;                    // +0x294 (animation placed on the super's cell)
    char Unknown298[0x2ac - 0x298];
    AnimTypeClass *IronCurtainInvokeAnim;
    char Unknown2B0[0x680 - 0x2b0];
    double ToggleRate;                          // +0x680 (recharge scale of toggle supers)
    char Unknown688[0xac4 - 0x688];
    DynamicVectorClass<InfantryTypeClass *> AmerParaDropInf;
    char UnknownAfterAmerParaDropInf[0x1c - sizeof(DynamicVectorClass<int>)];
    DynamicVectorClass<int> AmerParaDropNum;
    char UnknownAfterAmerParaDropNum[0x1c - sizeof(DynamicVectorClass<int>)];
    DynamicVectorClass<InfantryTypeClass *> AllyParaDropInf;
    char UnknownAfterAllyParaDropInf[0x1c - sizeof(DynamicVectorClass<int>)];
    DynamicVectorClass<int> AllyParaDropNum;
    char UnknownAfterAllyParaDropNum[0x1c - sizeof(DynamicVectorClass<int>)];
    DynamicVectorClass<InfantryTypeClass *> SovParaDropInf;
    char UnknownAfterSovParaDropInf[0x1c - sizeof(DynamicVectorClass<int>)];
    DynamicVectorClass<int> SovParaDropNum;
    char UnknownB68[0xc74 - 0xb50 - sizeof(DynamicVectorClass<int>)];
    WarheadTypeClass *C4Warhead;
    char UnknownC78[0xca4 - 0xc78];
    int IronCurtainDuration;
    char UnknownCA8[0x13e8 - 0xca8];
    int LightningDeferment;
    char Unknown13EC[4];
    int LightningStormDuration;
};
extern RulesClass * Rule;                       // 0x821b88

extern int SuperTargetMode;                     // 0x81b9d4, set to 4 after a player chronosphere (warp target pending), -1 after other supers; meaning provisional

class SuperClass;
extern DynamicVectorClass<SuperClass *> Supers;             // 0xa1e058
extern DynamicVectorClass<SuperClass *> ShowTimers;         // 0xa1e0e8
extern DynamicVectorClass<AbstractClass *> SuperAnimList;   // 0xaa8700, supers that own an animation
extern DynamicVectorClass<AbstractClass *> AbstractList87B8; // 0xaa87b8, meaning unknown
extern DynamicVectorClass<AbstractClass *> AbstractList8810; // 0xaa8810, meaning unknown

// {D7F754C6-391C-11D2-9B64-00104B972FE8} (GAME.EXE 0x78caf0)
class __declspec(uuid("D7F754C6-391C-11D2-9B64-00104B972FE8")) SuperClass : public AbstractClass {
public:
    SuperClass();
    SuperClass(SuperWeaponTypeClass * type, HouseClass * house);
    SuperClass(NoInitClass const & x) : Control(x), State(x), Cell(Cell) {}
    virtual ~SuperClass();

    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);
    virtual int __stdcall What_Am_I() const;

    virtual void Pointer_Expired(AbstractClass * object, bool removed);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    virtual void Compute_CRC(CRCEngine & crc) const;

    void Remove_Animation();
    void Set_Animation(CoordStruct coord);
    void Create_Chrono_Anim(class Coord coord); // 0x6921d0
    bool Suspend(bool on);
    bool Grant(bool onetime, bool announce, bool onhold);
    bool Remove();
    void Set_Ready(bool ready);
    bool Recharge(bool arg);
    bool Discharge(bool player, CellStruct const & cell);
    bool AI(bool player);
    int Anim_Stage() const;
    void Impatient_Click();
    void Forced_Charge(bool announce);
    bool Is_FlagDE() const;
    wchar_t const * Status_Text() const;
    bool Can_Fire() const;
    void Place(CellStruct const & cell, bool player);
    void Deactivate_Firestorm(int, bool player) const;
    bool Is_Charging() const;
    void Reset();

    SuperWeaponTypeClass * Class;               // +0x24
    HouseClass * House;                         // +0x28
    CDTimerClass<FrameTimerClass> Control;      // +0x2c
    wchar_t const * UIName;                     // +0x38
    struct StateStruct {
        StateStruct() { Field40 = 0; Flag3C = false; Field44 = 0; }
        StateStruct(NoInitClass const &) {}
        bool Flag3C;                            // +0x3c
        int Field40;                            // +0x40 (cleared on load)
        int Field44;                            // +0x44 (cleared on load)
    } State;
    bool Flag48;                                // +0x48
    CellStruct Cell;                            // +0x4a
    AnimClass * Animation;                      // +0x50
    bool AnimationGotInvalid;                   // +0x54
    bool IsPresent;                             // +0x55
    bool IsOneTime;                             // +0x56
    bool IsReady;                               // +0x57
    bool IsSuspended;                           // +0x58
    int ReadinessFrame;                         // +0x5c
    int CameoState;                             // +0x60
    int Field64;                                // +0x64
};

// ---- end of local declarations ----

static CellStruct const CellOffsets[9] = {
    CellStruct(0, 0), CellStruct(1, 0), CellStruct(1, -1), CellStruct(0, -1), CellStruct(-1, -1),
    CellStruct(-1, 0), CellStruct(-1, 1), CellStruct(0, 1), CellStruct(1, 1)
};

SuperClass::SuperClass() :
    Class(NULL),
    House(NULL),
    Flag48(true),
    Cell(EmptyCell),
    Animation(NULL),
    AnimationGotInvalid(false),
    IsPresent(false),
    IsOneTime(false),
    IsReady(false),
    IsSuspended(false),
    CameoState(-1)
{
    UIName = EmptyUIName;
    Supers.Add(this);
}

SuperClass::SuperClass(SuperWeaponTypeClass * type, HouseClass * house) :
    Class(type),
    House(house),
    Flag48(true),
    Cell(EmptyCell),
    Animation(NULL),
    AnimationGotInvalid(false),
    IsPresent(false),
    IsOneTime(false),
    IsReady(false),
    IsSuspended(false),
    ReadinessFrame(-1),
    CameoState(-1)
{
    AbstractClass::Create_ID();
    Supers.Add(this);
    AbstractList87B8.Add(this);
    AbstractList8810.Add(this);
}

SuperClass::~SuperClass()
{
    Remove_Animation();
    ShowTimers.Delete(this);
    Supers.Delete(this);
    AbstractList87B8.Delete(this);
    AbstractList8810.Delete(this);
}

void SuperClass::Remove_Animation()
{
    if (Animation) {
        Animation->IsSuperAnim = false;
        Animation = NULL;
        SuperAnimList.Delete(this);
    }
    if (AnimationGotInvalid) {
        SuperAnimList.Delete(this);
        AnimationGotInvalid = false;
    }
}

// Additional native declarations used by Place. Undecoded virtual slots retain their
// original indices so indirect calls keep the 1.001 object ABI.
#include "POINT.H"
#include <comdef.h>
class TechnoTypeClass {
public:
    char Unknown0[0xa0];
    int MaxStrength;
    char UnknownA4[0xae0 - 0xa4];
    bool Teleporter;
    char UnknownAE1[0xb47 - 0xae1];
    bool Organic;
};
class InfantryTypeClass {
public:
    char Unknown0[0xb90];
    int ArrayIndex;
};
class ObjectClass : public AbstractClass {
public:
    bool Is_Foot() const {
        if (!this) return false;
        unsigned char flag = Flag3;
        return flag != 0;
    }
    char Unknown24[0x30 - 0x24];
    ObjectClass *Next;
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual TechnoTypeClass *Techno_Type_Class();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void Reserved39();
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual void Reserved53();
    virtual void Reserved54();
    virtual void Reserved55();
    virtual void Reserved56();
    virtual void Reserved57();
    virtual void Reserved58();
    virtual void Reserved59();
    virtual void Reserved60();
    virtual void Reserved61();
    virtual void Reserved62();
    virtual void Reserved63();
    virtual void Reserved64();
    virtual void Reserved65();
    virtual void Reserved66();
    virtual void Reserved67();
    virtual void Reserved68();
    virtual void Reserved69();
    virtual void Reserved70();
    virtual void Reserved71();
    virtual void Reserved72();
    virtual void Reserved73();
    virtual void Reserved74();
    virtual void Reserved75();
    virtual void Reserved76();
    virtual void Reserved77();
    virtual void Reserved78();
    virtual void Reserved79();
    virtual void Reserved80();
    virtual void Reserved81();
    virtual void IronCurtain(int);
    virtual void Reserved83();
    virtual void Reserved84();
    virtual void Reserved85();
    virtual int Take_Damage(int *, int, WarheadTypeClass *, TechnoClass *, bool, int);
    virtual void Reserved87();
    virtual void Reserved88();
    virtual void Reserved89();
    virtual void Reserved90();
    virtual void Reserved91();
    virtual void Reserved92();
    virtual void Reserved93();
    virtual void Reserved94();
    virtual void Reserved95();
    virtual void Reserved96();
    virtual void Reserved97();
    virtual void Reserved98();
    virtual void Reserved99();
    virtual void Reserved100();
    virtual void Reserved101();
    virtual void Reserved102();
    virtual void Reserved103();
    virtual void Reserved104();
    virtual void Reserved105();
    virtual void Reserved106();
    virtual void Reserved107();
    virtual void Reserved108();
    virtual void Reserved109();
    virtual void Reserved110();
    virtual bool Unknown111();
    virtual bool Unknown112();
};
struct ILocomotion : IUnknown {
    virtual HRESULT __stdcall Link_To_Object(void *) = 0;
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void __stdcall Force_Track(int, CoordStruct);
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual void __stdcall Mark_All_Occupation_Bits(int);
};
struct IPiggyback : IUnknown {
    virtual HRESULT __stdcall Begin_Piggyback(ILocomotion *) = 0;
};
extern const IID IID_ILocomotion, IID_IPiggyback;
extern const CLSID CLSID_TeleportLocomotionClass;
typedef _com_ptr_t<_com_IIID<ILocomotion, &IID_ILocomotion> > LocomotionPtr;
typedef _com_ptr_t<_com_IIID<IPiggyback, &IID_IPiggyback> > PiggybackPtr;
class FootClass : public ObjectClass {
public:
    virtual void Reserved113();
    virtual void Reserved114();
    virtual void Reserved115();
    virtual void Reserved116();
    virtual void Reserved117();
    virtual void Reserved118();
    virtual void Reserved119();
    virtual void Reserved120();
    virtual void Reserved121();
    virtual void Reserved122();
    virtual void Reserved123();
    virtual void Reserved124();
    virtual void Reserved125();
    virtual void Reserved126();
    virtual void Reserved127();
    virtual void Reserved128();
    virtual void Reserved129();
    virtual void Reserved130();
    virtual void Reserved131();
    virtual void Reserved132();
    virtual void Reserved133();
    virtual void Reserved134();
    virtual void Reserved135();
    virtual void Reserved136();
    virtual void Reserved137();
    virtual void Reserved138();
    virtual void Reserved139();
    virtual void Reserved140();
    virtual void Reserved141();
    virtual void Reserved142();
    virtual void Reserved143();
    virtual void Reserved144();
    virtual void Reserved145();
    virtual void Reserved146();
    virtual void Reserved147();
    virtual void Reserved148();
    virtual void Reserved149();
    virtual void Reserved150();
    virtual void Reserved151();
    virtual void Reserved152();
    virtual void Reserved153();
    virtual void Reserved154();
    virtual void Reserved155();
    virtual void Reserved156();
    virtual void Reserved157();
    virtual void Reserved158();
    virtual void Reserved159();
    virtual void Reserved160();
    virtual void Reserved161();
    virtual void Reserved162();
    virtual void Reserved163();
    virtual void Reserved164();
    virtual void Reserved165();
    virtual void Reserved166();
    virtual void Reserved167();
    virtual void Reserved168();
    virtual void Reserved169();
    virtual void Reserved170();
    virtual void Reserved171();
    virtual void Reserved172();
    virtual void Reserved173();
    virtual void Reserved174();
    virtual void Reserved175();
    virtual void Reserved176();
    virtual void Reserved177();
    virtual void Reserved178();
    virtual void Reserved179();
    virtual void Reserved180();
    virtual void Reserved181();
    virtual void Reserved182();
    virtual void Reserved183();
    virtual void Reserved184();
    virtual void Reserved185();
    virtual void Reserved186();
    virtual void Reserved187();
    virtual void Reserved188();
    virtual void Reserved189();
    virtual void Reserved190();
    virtual void Reserved191();
    virtual void Reserved192();
    virtual void Reserved193();
    virtual void Reserved194();
    virtual void Reserved195();
    virtual void Reserved196();
    virtual void Reserved197();
    virtual void Reserved198();
    virtual void Reserved199();
    virtual void Reserved200();
    virtual void Reserved201();
    virtual void Reserved202();
    virtual bool Unknown203();
    virtual void Reserved204();
    virtual void Reserved205();
    virtual void Reserved206();
    virtual void Reserved207();
    virtual void Reserved208();
    virtual void Reserved209();
    virtual void Reserved210();
    virtual void Reserved211();
    virtual void Reserved212();
    virtual void Reserved213();
    virtual void Reserved214();
    virtual void Reserved215();
    virtual void Reserved216();
    virtual void Reserved217();
    virtual void Reserved218();
    virtual void Reserved219();
    virtual void Reserved220();
    virtual void Reserved221();
    virtual void Reserved222();
    virtual void Reserved223();
    virtual void Reserved224();
    virtual void Reserved225();
    virtual void Reserved226();
    virtual void Reserved227();
    virtual void Reserved228();
    virtual void Reserved229();
    virtual void Reserved230();
    virtual void Reserved231();
    virtual void Reserved232();
    virtual void Reserved233();
    virtual void Reserved234();
    virtual void Reserved235();
    virtual void Reserved236();
    virtual void Reserved237();
    virtual void Reserved238();
    virtual void Reserved239();
    virtual void Reserved240();
    virtual void Reserved241();
    virtual void Reserved242();
    virtual void Reserved243();
    virtual void Reserved244();
    virtual void Reserved245();
    virtual void Reserved246();
    virtual void Reserved247();
    virtual void Reserved248();
    virtual void Reserved249();
    virtual void Reserved250();
    virtual void Reserved251();
    virtual void Reserved252();
    virtual void Reserved253();
    virtual void Reserved254();
    virtual void Reserved255();
    virtual void Reserved256();
    virtual void Reserved257();
    virtual void Reserved258();
    virtual void Reserved259();
    virtual void Assign_Destination(AbstractClass *, bool);
    char Unknown34[0x210 - 0x34];
    bool IsImmobilized;
    char Unknown211[0x21c - 0x211];
    CoordStruct ChronoDestCoords;
    char Unknown228[0x564 - 0x228];
    LocomotionPtr Locomotor;
    char Unknown568[0x5a0 - 0x568];
    bool IsOccupyingCell;
};
class BuildingClass : public ObjectClass {
public:
    virtual void Reserved113();
    virtual void Reserved114();
    virtual void Reserved115();
    virtual void QueueMission(int, bool);
    virtual bool Commence();
    char Unknown34[0x4cc - 0x34];
    int SuperWeaponFired;
};
// level-2 1.001: INFERRED velocity types matching the launch ABI.
struct Velocity2D {
    Velocity2D() {}
    Velocity2D(double x, double y) : X(x), Y(y) {}
    double X, Y;
};
struct Velocity3D : Velocity2D {
    double Z;
};
class WeaponTypeClass;
class BulletClass : public ObjectClass {
public:
    void Set_Weapon_Type(WeaponTypeClass *);
    virtual void Reserved113();
    virtual void Reserved114();
    virtual void Reserved115();
    virtual void Reserved116();
    virtual void Reserved117();
    virtual bool Launch(CoordStruct const &, Velocity3D const &);
};
class CellClass : public AbstractClass {
public:
    virtual HRESULT __stdcall GetClassID(CLSID *);
    virtual HRESULT __stdcall Load(IStream *);
    virtual HRESULT __stdcall Save(IStream *, BOOL);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    bool Is_Tile_Water() const;
    char Unknown24[0xe4 - 0x24];
    ObjectClass *OccupierPtr, *AltOccupierPtr;
    char UnknownEC[0x140 - 0xec];
    unsigned Flags;
};
class MapClass {
public:
    CellClass &operator[](CellStruct const &);
    CellClass &operator[](CoordStruct const &);
    CellStruct Nearby_Location(CellStruct const &, int, int, int, bool, Point2D, bool, bool, bool, bool, CellStruct const &, int);
    int Get_Height_GL(CoordStruct const &);
};
extern MapClass Map;
extern CellClass BlubCell;
class BulletTypeClass;
class WeaponTypeClass {
public:
    static int Index_From_Name(char const *);
    char Unknown0[0xa0];
    BulletTypeClass *Projectile;
    int Attack, MaxSpeed;
    WarheadTypeClass *Warhead;
};
class BuildingTypeClass {
public:
    char Unknown0[0x1354];
    bool NukeSilo;
    char Unknown1355[0x1374 - 0x1355];
    int SuperWeapon, SuperWeapon2;
};
class AircraftTypeClass { public: static int From_Name(char const *); };
class VoxClass { public: static int Find_Index(char const *); };
extern DynamicVectorClass<WeaponTypeClass *> Weapons;
extern DynamicVectorClass<BuildingTypeClass *> BuildingTypes;
extern int MuteSWLaunches;
void Start_Lightning_Storm(int, int, CellStruct, HouseClass *);
void Speech_Cancel(int);
int Create_Air_Reinforcement(HouseClass *, int, int, int, CellClass *, AbstractClass *, int, int);
void Notify_Psychic_Warning(HouseClass *, CellClass *, BulletClass *, char const *);
BulletClass *Create_Bullet(BulletTypeClass *, AbstractClass *, TechnoClass *, int, WarheadTypeClass *, int, bool);
class AudioEvent;
AudioEvent *Voc_Static_Add(int, CoordStruct const &, unsigned);
double __cdecl Place_Sin(double); // 0x4ba0f0
double __cdecl Place_Cos(double); // 0x4ba140
// level-2 1.001: INFERRED native coordinate arithmetic used only by Place.
inline CoordStruct operator+(CoordStruct const &a, CoordStruct const &b) { return CoordStruct(a.X+b.X,a.Y+b.Y,a.Z+b.Z); }
inline CoordStruct operator-(CoordStruct const &a, CoordStruct const &b) { return CoordStruct(a.X-b.X,a.Y-b.Y,a.Z-b.Z); }
inline CellStruct operator+(CellStruct const &a, CellStruct const &b) { return CellStruct(a.X+b.X,a.Y+b.Y); }
// level-2 1.001: INFERRED cell-centre conversion.
inline CoordStruct Cell_Coord(CellStruct const &c) { return CoordStruct(c.X*256+128,c.Y*256+128,0); }
// level-2 1.001: INFERRED native point and coordinate layout for the three
// recovered calls. The point sum returns a base point. Create_Chrono_Anim
// takes the converted coordinate by value, as in the native POINT.H conversion.
template<class T> class TPoint3D {
public:
    T X, Y, Z;
    TPoint3D() {}
    const TPoint3D operator+(const TPoint3D &other) const; // 0x694350
};
class Coord : public TPoint3D<int> {
public:
    Coord(int x, int y, int z); // 0x4346e0
    Coord(CoordStruct const &p) { X = p.X; Y = p.Y; Z = p.Z; }
    Coord(TPoint3D<int> const &p) { X = p.X; Y = p.Y; Z = p.Z; }
};

// level-2 1.001: INFERRED copy of a cell sum into the map lookup argument.
// level-2 1.001: STEERING pass the summed point by reference before copying it.
inline CellStruct Place_Lookup_Cell(CellStruct const &sum)
{
    return sum;
}

// level-2 1.001: STEERING use the converting smart-pointer constructor at this call boundary.
inline PiggybackPtr Place_Piggyback(LocomotionPtr const &source)
{
    return PiggybackPtr(source);
}

// Place control flow adapted from meastes/redalert2-decomp @613e28e4e0,
// src/recovered/super.cpp, GPL-3.0-or-later. Version-specific calls follow 1.001.
void SuperClass::Place(CellStruct const &cell, bool player)
{
    switch (Class->Type) {
    case 3:
        if (IsReady) {
            Cell = cell;
            Coord coord = Map[cell].Center_Coord();
            if (Map[cell].Flags & 0x100) {
                coord.Z += I10;
            }
            Create_Chrono_Anim(coord + Coord(0, 0, 5));
            if (player) {
                SuperTargetMode = 4;
                return;
            }
            if (Animation != 0) {
                Animation->Flag17D = true;
                Animation->Sound.Func_405D50();
                return;
            }
        }
        break;

    case 4: {

        CoordStruct dest = Map[cell].Center_Coord();
        CoordStruct from = Map[Cell].Center_Coord();
        if (Map[cell].Flags & 0x100) {
            dest.Z += I10;
        }
        if (Map[Cell].Flags & 0x100) {
            from.Z += I10;
        }
        Remove_Animation();
        {
            void *storage = ::operator new(0x1a8);
            if (storage) {
                new (storage) AnimClass(Rule->Anim290, dest + CoordStruct(0, 0, 5), 0, 1, 0x600, 0);
            }
        }
        {
            void *storage = ::operator new(0x1a8);
            if (storage) {
                new (storage) AnimClass(Rule->Anim28C, from + CoordStruct(0, 0, 5), 0, 1, 0x600, 0);
            }
        }
        // level-2 1.001: STEERING Walk the nine offsets by address to align the later switch arms.
        for (const CellStruct *p = CellOffsets; p != CellOffsets + 9; ++p) {
            CellStruct const &offset = *p;
            ObjectClass *object;
            if (Map[Place_Lookup_Cell(offset + Cell)].Flags & 0x100) {
                object = Map[Place_Lookup_Cell(Cell + offset)].AltOccupierPtr;
            } else {
                object = Map[Place_Lookup_Cell(offset + Cell)].OccupierPtr;
            }
            while (object != 0) {
                if (object->Is_Foot() && !object->Is_In_Air()) {
                    FootClass *foot = (FootClass *)object;
                    TechnoTypeClass *type = foot->Techno_Type_Class();
                    // level-2 1.001: STEERING Use the established foot receiver for the organic-unit checks and damage call.
                    if (type->Organic && !foot->Techno_Type_Class()->Teleporter && !foot->Is_In_Air()) {
                        int damage = foot->Techno_Type_Class()->MaxStrength;
                        foot->Take_Damage(&damage, 0, Rule->C4Warhead, 0, true, 0);
                    } else if (!foot->Unknown203() && !foot->IsImmobilized && !foot->Unknown111() && !foot->Unknown112()) {
                        // level-2 1.001: STEERING keep a reference to the current locomotor across the warp calls.
                        LocomotionPtr &locomotor = foot->Locomotor;
                        PiggybackPtr piggyback(locomotor);
                        LocomotionPtr teleport(CLSID_TeleportLocomotionClass, 0, 7);
                        FootClass *unit = foot->Kind_Of() == 1 ? foot : 0;
                        CoordStruct coord = Map[Place_Lookup_Cell(offset + cell)].Center_Coord();
                        if (Map[coord].Flags & 0x100) {
                            coord.Z += I10;
                        }
                        if (unit != 0) {
                            locomotor->Mark_All_Occupation_Bits(0);
                            locomotor->Force_Track(-1, CoordStruct(coord));
                            foot->IsOccupyingCell = true;
                        }
                        teleport->Link_To_Object(foot);
                        piggyback = Place_Piggyback(teleport);
                        if (piggyback.GetInterfacePtr() != 0) {
                            piggyback->Begin_Piggyback(locomotor);
                            locomotor = teleport;
                        }
                        // level-2 1.001: STEERING Subtract the map center in the same expression as the foot position.
                        CoordStruct delta = foot->Center_Coord() - Map[Cell].Center_Coord();
                        if (unit == 0) {
                            // level-2 1.001: STEERING Use the destination center as the left operand while forming the warp coordinate.
                            coord = Map[cell].Center_Coord() + delta;
                            if (Map[coord].Flags & 0x100) {
                                coord.Z += I10;
                            }
                        }
                        foot->IsImmobilized = true;
                        foot->ChronoDestCoords = coord;
                        foot->Assign_Destination(&Map[Place_Lookup_Cell(offset + cell)], true);
                    }
                }
                object = object->Next;
            }
        }
        if (!MuteSWLaunches) {
            Speak("EVA_ChronosphereActivated", -1, -1);
        }
        if (player) {
            SuperTargetMode = -1;
            Speech_Cancel(VoxClass::Find_Index("EVA_ChronosphereReady"));
            return;
        }
        break;
    }

    case 2:
        if (IsReady) {
            Start_Lightning_Storm(Rule->LightningStormDuration, Rule->LightningDeferment, cell, House);
            if (!MuteSWLaunches) {
                Speak("EVA_LightningStormCreated", -1, -1);
            }
            if (player) {
                SuperTargetMode = -1;
                Speech_Cancel(VoxClass::Find_Index("EVA_LightningStormReady"));
                return;
            }
        }
        break;

    case 1:
        if (IsReady) {
            CoordStruct coord = Map[cell].Center_Coord();
            {
                void *storage = ::operator new(0x1a8);
                if (storage) {
                    new (storage) AnimClass(Rule->IronCurtainInvokeAnim, coord + CoordStruct(0, 0, 5), 0, 1, 0x600, 0);
                }
            }
            if (!MuteSWLaunches) {
                Speak("EVA_IronCurtainActivated", -1, -1);
            }

            for (int index = 0; index < 9; index++) {
                CellStruct const *offset = &CellOffsets[index];
                for (ObjectClass *object = Map[Place_Lookup_Cell(cell + *offset)].OccupierPtr; object != 0; object = object->Next) {
                    object->IronCurtain(Rule->IronCurtainDuration);
                }
            }
            if (player) {
                SuperTargetMode = -1;
                Speech_Cancel(VoxClass::Find_Index("EVA_IronCurtainReady"));
                return;
            }
        }
        break;

    case 5:
        if (IsReady) {
            int plane = AircraftTypeClass::From_Name("PDPLANE");
            CellClass *cellptr = &Map[cell];
            if (cellptr != 0 && cellptr != &BlubCell) {
                if (cellptr->Is_Tile_Water()) {
                    CellStruct spot = Map.Nearby_Location(cell, 0, -1, 0, 0, Point2D(1, 1), false, false, false, true, CellStruct(0, 0), 0);
                    if (spot.X != EmptyCell.X || spot.Y != EmptyCell.Y) {
                        CellClass *nearptr = &Map[spot];
                        if (nearptr != 0 && nearptr != &BlubCell && !nearptr->Is_Tile_Water()) {
                            cellptr = nearptr;
                        }
                    }
                }
                if (House->ActLike == 0) {
                    if (Rule->AllyParaDropInf.Count() == Rule->AllyParaDropNum.Count()) {
                        for (int i = 0; i < Rule->AllyParaDropInf.Count(); i++) {
                            int type = Rule->AllyParaDropInf[i]->ArrayIndex;
                            if (plane != -1 && type != -1) {
                                Create_Air_Reinforcement(House, plane, 1, 0x1a, cellptr, 0, type, Rule->AllyParaDropNum[i]);
                            }
                        }
                    }
                } else {
                    for (int i = 0; i < Rule->SovParaDropInf.Count(); i++) {
                        int type = Rule->SovParaDropInf[i]->ArrayIndex;
                        if (plane != -1 && type != -1) {
                            Create_Air_Reinforcement(House, plane, 1, 0x1a, cellptr, 0, type, Rule->SovParaDropNum[i]);
                        }
                    }
                }
            }
            if (player) {
                SuperTargetMode = -1;
                Speech_Cancel(VoxClass::Find_Index("EVA_ReinforcementsReady"));
                return;
            }
        }
        break;

    case 6:
        if (IsReady) {
            int plane = AircraftTypeClass::From_Name("PDPLANE");
            CellClass *cellptr = &Map[cell];
            if (cellptr != 0 && cellptr != &BlubCell) {
                if (cellptr->Is_Tile_Water()) {
                    CellStruct spot = Map.Nearby_Location(cell, 0, -1, 0, false, Point2D(1, 1), false, false, false, true, CellStruct(0, 0), 0);
                    if (spot.X != EmptyCell.X || spot.Y != EmptyCell.Y) {
                        CellClass *nearptr = &Map[spot];
                        if (nearptr != 0 && nearptr != &BlubCell && !nearptr->Is_Tile_Water()) {
                            cellptr = nearptr;
                        }
                    }
                }
                if (Rule->AmerParaDropInf.Count() == Rule->AmerParaDropNum.Count()) {
                    for (int i = 0; i < Rule->AmerParaDropInf.Count(); i++) {
                        int type = Rule->AmerParaDropInf[i]->ArrayIndex;
                        if (plane != -1 && type != -1) {
                            Create_Air_Reinforcement(House, plane, 1, 0x1a, cellptr, 0, type, Rule->AmerParaDropNum[i]);
                        }
                    }
                }
            }
            if (player) {
                SuperTargetMode = -1;
                Speech_Cancel(VoxClass::Find_Index("EVA_ReinforcementsReady"));
            }
        }
        break;

    case 0:
        if (IsReady) {
            if (IsOneTime && IsPresent) {
                CellStruct spot = cell;
                CoordStruct coord = Cell_Coord(spot);
                coord.Z = Map.Get_Height_GL(coord);
                if (Map[spot].Flags & 0x100) {
                    coord.Z += I10;
                }
                WeaponTypeClass *payload = Weapons[WeaponTypeClass::Index_From_Name("NukePayload")];
                CellClass *target = &Map[coord];
                CoordStruct sound = coord;
                // level-2 1.001: STEERING Build the elevated launch point from its source coordinate before bullet creation.
                CoordStruct launch(coord.X, coord.Y, coord.Z + 20000);
                BulletTypeClass *btype = payload->Projectile;
                BulletClass *bullet = Create_Bullet(btype, target, 0, payload->Attack, payload->Warhead, payload->MaxSpeed, false);
                bullet->Set_Weapon_Type(payload);
                Notify_Psychic_Warning(House, target, bullet, "PSIWARN");
                if (bullet != 0) {
                    double y = Place_Sin(1.5707483884323126);
                    y *= Place_Cos(1.5707483884323126);
                    y *= -100.0;
                    Velocity2D planar(Place_Cos(1.5707483884323126) * Place_Cos(1.5707483884323126) * -100.0, y);
                    Velocity3D velocity;
                    static_cast<Velocity2D &>(velocity) = planar;
                    velocity.Z = Place_Sin(1.5707483884323126) * -100.0;
                    bullet->Launch(launch, velocity);
                    if (!MuteSWLaunches) {
                        Speak("EVA_NuclearMissileLaunched", -1, -1);
                    }
                    Voc_Static_Add(Rule->DigSound, sound, 0);
                }
                if (player) {
                    SuperTargetMode = -1;
                    Speech_Cancel(VoxClass::Find_Index("EVA_NuclearMissileReady"));
                }
                House->IsRecalcNeeded = true;
                return;
            }
            for (int index = 0; index < BuildingTypes.Count(); index++) {
                BuildingTypeClass *btype = BuildingTypes[index];
                if (btype->NukeSilo && (btype->SuperWeapon == Class->ArrayIndex || btype->SuperWeapon2 == Class->ArrayIndex)) {
                    BuildingClass *site = House->Find_Building(index, -1);
                    if (site != 0) {
                        CellStruct spot = cell;
                        CoordStruct coord = Cell_Coord(spot);
                        coord.Z = Map.Get_Height_GL(coord);
                        CoordStruct sound = coord;
                        site->QueueMission(0x16, false);
                        site->Commence();
                        House->NukeDest = cell;
                        site->SuperWeaponFired = Class->Type;
                        Voc_Static_Add(Rule->DigSound, sound, 0);
                        if (!MuteSWLaunches) {
                            Speak("EVA_NuclearMissileLaunched", -1, -1);
                        }
                    }
                    break;
                }
            }
            if (player) {
                SuperTargetMode = -1;
                Speech_Cancel(VoxClass::Find_Index("EVA_NuclearMissileReady"));
            }
            House->IsRecalcNeeded = true;
        }
        break;
    }
}


void SuperClass::Set_Animation(CoordStruct coord)
{
    Remove_Animation();
    AnimClass * anim = new AnimClass(Rule->Anim294, CoordStruct(coord.X, coord.Y, coord.Z + 5), 0, 1, 0x600, 0);
    if (anim) {
        Animation = anim;
        SuperAnimList.Add(this);
    }
}



bool SuperClass::Grant(bool onetime, bool announce, bool onhold)
{
    if (!IsPresent) {
        IsPresent = true;
        IsOneTime = onetime;
        State.Flag3C = false;
        UIName = Class->UIName;
        bool ready = false;
        Suspend(false);
        if (Class->ShowTimer && !House->Class->IsMultiplayPassive) {
            ShowTimers.Add(this);
        }
        if (Class->IsPowered) {
            ReadinessFrame = -1;
            Control = Class->RechargeTime;
            Control.Stop();
        } else {
            ready = Recharge(false);
        }
        if (onhold) {
            Suspend(true);
        }
        if (IsOneTime) {
            Forced_Charge(announce);
        }
        return ready;
    }
    return false;
}

bool SuperClass::Remove()
{
    if (IsPresent) {
        IsReady = false;
        IsPresent = false;
        ShowTimers.Delete(this);
        return true;
    }
    return false;
}

void SuperClass::Set_Ready(bool ready)
{
    IsReady = ready;
}



bool SuperClass::Discharge(bool player, CellStruct const & cell)
{
    if (Class->IsToggle) {
        if (House->Func_4F47F0()) {
            if (CameoState == 2) {
                CameoState = 1;
                Control = (int)(Class->RechargeTime - Control / Rule->ToggleRate);
                return false;
            }
            if (CameoState != 1) {
                return false;
            }
            CameoState = 2;
            Control = (int)((Class->RechargeTime - Control) * Rule->ToggleRate);
        } else if (House->Flag142) {
            return false;
        }
        Place(cell, player);
        return false;
    }

    if (!(Control.Is_Active() && IsPresent && IsReady) && !Class->FlagE1) {
        return false;
    }
    if (Class->Type == SUPER_LIGHTNING_STORM && Func_51F170()) {
        if (player) {
            Func_520130();
        }
        return false;
    }
    Place(cell, player);
    if (!Class->FlagE1) {
        IsReady = false;
    }
    if (IsOneTime) {
        IsOneTime = false;
        return Remove();
    }
    if (Class->IsPowered) {
        ReadinessFrame = -1;
        Control = Class->RechargeTime;
        Control.Stop();
        return false;
    }
    if (!Class->FlagE0 && !Class->FlagE1) {
        Recharge(false);
    }
    return false;
}

bool SuperClass::AI(bool player)
{
    if (SuperTargetMode != 4 && Animation) {
        Animation->Flag17D = true;
        Animation->Sound.Func_405FE0();
    }
    if (!IsPresent || (IsReady && !Class->IsToggle) || IsSuspended) {
        return false;
    }
    if (!Control.Is_Active()) {
        if (ReadinessFrame != -1) {
            ReadinessFrame = -1;
            return true;
        }
        return false;
    }
    if (Control == 0) {
        if (Class->IsToggle) {
            if (CameoState == 2) {
                CameoState = 0;
                Control = Class->RechargeTime;
                return true;
            }
            CameoState = 1;
            IsReady = true;
            return true;
        }
        IsReady = true;
        if (player) {
            switch (Class->Type) {
                case SUPER_NUKE:
                    Speak("EVA_NuclearMissileReady");
                    break;
                case SUPER_IRON_CURTAIN:
                    Speak("EVA_IronCurtainReady");
                    break;
                case SUPER_LIGHTNING_STORM:
                    Speak("EVA_LightningStormReady");
                    break;
                case SUPER_CHRONOSPHERE:
                    Speak("EVA_ChronosphereReady");
                    break;
                case SUPER_PARADROP:
                case SUPER_AMERICAN_PARADROP:
                    Speak("EVA_ReinforcementsReady");
                    break;
            }
        }
        return true;
    }
    if (Anim_Stage() != ReadinessFrame) {
        ReadinessFrame = Anim_Stage();
        return true;
    }
    return false;
}

int SuperClass::Anim_Stage() const
{
    if (IsPresent) {
        int stage;
        if (Class->IsToggle) {
            if (CameoState == 2) {
                long remain = Control;
                double total = Class->RechargeTime * Rule->ToggleRate;
                stage = (int)((1.0 - (total - remain) / total) * 54.0);
            } else {
                long remain = Control;
                stage = (int)((double)(Class->RechargeTime - remain) / Class->RechargeTime * 54.0);
            }
        } else {
            if (IsReady) {
                return 54;
            }
            long remain = Control;
            stage = (int)((double)(Class->RechargeTime - remain) / Class->RechargeTime * 54.0);
        }
        if (stage >= 53) {
            return 53;
        }
        return stage;
    }
    return 0;
}

void SuperClass::Impatient_Click()
{
}

void SuperClass::Forced_Charge(bool announce)
{
    if (IsPresent) {
        IsReady = true;
        Control.Start();
        Control = 0;
        if (announce) {
            switch (Class->Type) {
                case SUPER_NUKE:
                    Speak("EVA_NuclearMissileReady");
                    break;
                case SUPER_IRON_CURTAIN:
                    Speak("EVA_IronCurtainReady");
                    break;
                case SUPER_LIGHTNING_STORM:
                    Speak("EVA_LightningStormReady");
                    break;
                case SUPER_CHRONOSPHERE:
                    Speak("EVA_ChronosphereReady");
                    break;
                case SUPER_PARADROP:
                case SUPER_AMERICAN_PARADROP:
                    Speak("EVA_ReinforcementsReady");
                    break;
            }
        }
        if (Class->IsToggle) {
            CameoState = 1;
        }
    }
}

bool SuperClass::Is_FlagDE() const
{
    return Class->FlagDE;
}

wchar_t const * SuperClass::Status_Text() const
{
    if (!IsSuspended) {
        if (Class->IsToggle) {
            switch (CameoState) {
                case 0:
#line 810 "C:\\RA2\\Super.CPP"
                    return Fetch_String("TXT_CHARGING", NULL, __FILE__, __LINE__);
                case 1:
#line 813 "C:\\RA2\\Super.CPP"
                    return Fetch_String("TXT_READY", NULL, __FILE__, __LINE__);
                case 2:
#line 816 "C:\\RA2\\Super.CPP"
                    return Fetch_String("TXT_FIRESTORM_ON", NULL, __FILE__, __LINE__);
            }
            return NULL;
        }
        if (IsReady) {
#line 835 "C:\\RA2\\Super.CPP"
            return Fetch_String("TXT_READY", NULL, __FILE__, __LINE__);
        }
        return NULL;
    }
#line 841 "C:\\RA2\\Super.CPP"
    return Fetch_String("TXT_HOLD", NULL, __FILE__, __LINE__);
}

bool SuperClass::Can_Fire() const
{
    if (!IsSuspended) {
        if (Class->IsToggle) {
            return CameoState ? true : false;
        }
        return IsReady;
    }
    return false;
}

void SuperClass::Deactivate_Firestorm(int, bool player) const
{
}

bool SuperClass::Is_Charging() const
{
    if (Class->IsToggle) {
        return true;
    }
    return !IsReady;
}

HRESULT __stdcall SuperClass::GetClassID(CLSID * pClassID)
{
    if (pClassID == NULL) {
        return E_POINTER;
    }
    *pClassID = __uuidof(SuperClass);
    return S_OK;
}

HRESULT __stdcall SuperClass::Load(IStream * pStm)
{
    HRESULT hr = AbstractClass::Load(pStm);
    if (FAILED(hr)) {
        return hr;
    }
    new (this) SuperClass(NoInitClass());
    if (Animation) {
        SuperAnimList.Add(this);
    }
    SwizzleManager.Swizzle((void **)&Class);
    SwizzleManager.Swizzle((void **)&House);
    SwizzleManager.Swizzle((void **)&Animation);
    State.Field40 = 0;
    State.Field44 = 0;
    return S_OK;
}



void SuperClass::Pointer_Expired(AbstractClass * object, bool removed)
{
    if (object == House) {
        House = NULL;
    }
    if (object == Class) {
        Class = NULL;
    }
    if (object == Animation) {
        Animation = NULL;
        AnimationGotInvalid = true;
    }
}

void SuperClass::Compute_CRC(CRCEngine & crc) const
{
    AbstractClass::Compute_CRC(crc);
    crc((bool)IsPresent);
    crc((bool)IsOneTime);
    crc((bool)IsReady);
    crc(ReadinessFrame);
    crc(CameoState);
    crc((bool)Flag48);
    crc((bool)AnimationGotInvalid);
    if (Animation) {
        crc((int)Animation->IsSuperAnim);
        crc(Animation->Fetch_ID());
    }
}



int __stdcall SuperClass::What_Am_I() const
{
    return 0x39;
}

int SuperClass::Kind_Of() const
{
    return 0x39;
}

int SuperClass::Size_Of() const
{
    return sizeof(*this);
}

