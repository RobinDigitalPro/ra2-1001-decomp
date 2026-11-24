// unidentified translation unit (GAMECONST.H initializers at 0xd2270) (level-2 reconstruction of GAME.EXE 1.001)
// This is the GLOBALS translation unit: after the shared header initializers it defines the game's global
// object lists and objects (0xd2460..0xd4040: one dynamic initializer and one atexit destructor per object).
// The definition order follows the 1.001 disassembly; it mirrors gibbo101/ra2-decomp src/globals.cpp
// (Yuri's Revenge 1.001, GPL-3.0-or-later), without its YR-only lists (the Buildings list at 0x8B41E0 in YR,
// the RGBClass colour globals) that 1.001 does not have here.
#include <windows.h>
#include <unknwn.h>
#include "../GAMECONST.H"
#include "../RECT.H"
#include "../VECTOR.H"
static RectangleStruct const ZeroRectB(0, 0, 0, 0);

// ---- local declarations (to be moved to headers by the integrator) ----

class AITriggerTypeClass;
class TriggerTypeClass;
class TriggerClass;
class BuildingLightClass;
class ParticleSystemClass;
class TubeClass;
class WaveClass;
class BulletClass;
class OverlayClass;
class ParticleClass;
class SmudgeClass;
class TerrainClass;
class InfantryClass;
class BuildingClass;
class AircraftClass;
class UnitClass;
class HouseClass;
class AnimClass;
class TeamClass;
class FactoryClass;
class CampaignClass;
class SideClass;
class HouseTypeClass;
class TaskForceClass;
class TeamTypeClass;
class ScriptTypeClass;
class OverlayTypeClass;
class SmudgeTypeClass;
class TerrainTypeClass;
class BuildingTypeClass;
class AircraftTypeClass;
class UnitTypeClass;
class AnimTypeClass;
class InfantryTypeClass;
class BulletTypeClass;
class VoxelAnimTypeClass;
class IsometricTileTypeClass;
class ParticleTypeClass;
class ParticleSystemTypeClass;
class SuperWeaponTypeClass;
class SuperClass;
class TechnoClass;
class TechnoTypeClass;
class ObjectClass;
class AbstractTypeClass;
class TagClass;
struct ThemeControl;
class VoxelLibrary;
class MotionLibrary;

// COM class factory of the game (vtable 0x78daa4). AddRef 0xd4020, Release 0xd4030, LockServer 0xd4040;
// QueryInterface 0x426b10 and CreateInstance 0x426b70 live in app.cpp.
class TiberianSunClassFactory : public IClassFactory
{
    public:
        virtual LONG STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID * ppvObject);
        virtual ULONG STDMETHODCALLTYPE AddRef(void) {return(1);}
        virtual ULONG STDMETHODCALLTYPE Release(void) {return(1);}

        virtual HRESULT STDMETHODCALLTYPE CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, LPVOID * ppvObject);
        virtual HRESULT STDMETHODCALLTYPE LockServer(BOOL fLock) {return(S_OK);}
};

// 0x20 bytes per mission; constructor 0x591bd0 (mission.cpp).
class MissionControlClass
{
    public:
        MissionControlClass(void);

        int Data[8];
};

enum { MISSION_COUNT = 30 };

// constructor 0x6346c0, destructor 0x634710 (rndstraw.cpp).
class RandomStraw
{
    public:
        RandomStraw(void);
        virtual ~RandomStraw(void);
};

// constructor 0x7076e0 (version.cpp); one virtual slot (??_G 0xd4050).
class VersionClass
{
    public:
        VersionClass(void);
        virtual ~VersionClass(void) {};
};

// destructor 0x5cd0f0 (object.cpp).
struct VoxelDataStruct
{
    VoxelDataStruct(void)
    {
        VoxLib = NULL;
        MotLib = NULL;
    }
    ~VoxelDataStruct(void);

    VoxelLibrary * VoxLib;
    MotionLibrary * MotLib;
};

// constructor 0x5d0ed0 (Options.CPP).
class OptionsClass
{
    public:
        OptionsClass(void);
};

// constructor 0x6dcf20 (theme.cpp); the theme list is at +0x14.
class ThemeClass
{
    public:
        ThemeClass(void);

        int Data[5];
        DynamicVectorClass<ThemeControl *> Themes;
};

// constructor 0x4942f0 (credits.cpp).
class CreditClass
{
    public:
        CreditClass(void);
};

// 0x6f bytes; only the event type at +0 is set by the constructor.
#pragma pack(push, 1)
class EventClass
{
    public:
        EventClass(void) {Type = 0;};

        unsigned char Type;
        unsigned char Data[0x6e];
};
#pragma pack(pop)

enum { MAX_EVENTS = 128 };

template<class T, int size>
class QueueClass
{
    public:
        const int Count;

        QueueClass(void);
        void Init(void);

        int Head;
        int Tail;

        T Array[size];
        unsigned long Timings[size];
};

template<class T, int size>
inline QueueClass<T,size>::QueueClass(void) : Count(0)
{
    Init();
}

template<class T, int size>
inline void QueueClass<T,size>::Init(void)
{
    ((int &)Count) = 0;
    Head = 0;
    Tail = 0;
}

// constructor 0x664f70, destructor 0x665630 (session.cpp).
class SessionClass
{
    public:
        SessionClass(void);
        ~SessionClass(void);
};

// constructor 0x5c8650, destructor 0x5c86e0.
class NullModemClass
{
    public:
        NullModemClass(int numsend, int numreceive, int maxlen, unsigned short magicnum);
        virtual ~NullModemClass(void);
};

// constructor 0x523e20, destructor 0x523f20.
class IPXManagerClass
{
    public:
        IPXManagerClass(int glb_maxlen, int pvt_maxlen, int glb_num_packets, int pvt_num_packets, unsigned short socket, unsigned short product_id);
        virtual ~IPXManagerClass(void);
};

// constructor 0x4d2010, destructor 0x4d20e0 (playcd.cpp).
class GetCDClass
{
    public:
        GetCDClass(void);
        ~GetCDClass(void);
};

// ---- end of local declarations ----

DynamicVectorClass<AITriggerTypeClass *> AITriggerTypes;              // 0xa25590
DynamicVectorClass<TriggerTypeClass *> TriggerTypes;                  // 0x84e538
DynamicVectorClass<TriggerClass *> Triggers;                          // 0xa286e0
DynamicVectorClass<BuildingLightClass *> BuildingLights;              // 0x84e550
DynamicVectorClass<ParticleSystemClass *> ParticleSystems;            // 0xa1a5b0
DynamicVectorClass<TubeClass *> Tubes;                                // 0x84e4f8
DynamicVectorClass<WaveClass *> Waves;                                // 0xa28828
DynamicVectorClass<BulletClass *> Bullets;                            // 0xa28928
DynamicVectorClass<OverlayClass *> Overlays;                          // 0xa28840
DynamicVectorClass<ParticleClass *> Particles;                        // 0xa1e158
DynamicVectorClass<SmudgeClass *> Smudges;                            // 0xa25570
DynamicVectorClass<TerrainClass *> Terrains;                          // 0xa28590
DynamicVectorClass<InfantryClass *> Infantry;                         // 0xa1e178
DynamicVectorClass<BuildingClass *> Buildings;                        // 0xa28738
DynamicVectorClass<AircraftClass *> Aircraft;                         // 0xa27fe8
DynamicVectorClass<UnitClass *> Units;                                // 0x84e4c8
DynamicVectorClass<HouseClass *> Houses;                              // 0xa1a5c8
DynamicVectorClass<AnimClass *> Anims;                                // 0xa285b0
DynamicVectorClass<TeamClass *> Teams;                                // 0x84e4a8
DynamicVectorClass<FactoryClass *> Factories;                         // 0xa1e1c0
DynamicVectorClass<CampaignClass *> Campaigns;                        // 0xa1e090
DynamicVectorClass<SideClass *> Sides;                                // 0x84e4e0
DynamicVectorClass<HouseTypeClass *> HouseTypes;                      // 0xa1e038
DynamicVectorClass<TaskForceClass *> TaskForces;                      // 0xa284e0
DynamicVectorClass<TeamTypeClass *> TeamTypes;                        // 0xa28888
DynamicVectorClass<ScriptTypeClass *> ScriptTypes;                    // 0x84e588
DynamicVectorClass<OverlayTypeClass *> OverlayTypes;                  // 0xa1e118
DynamicVectorClass<SmudgeTypeClass *> SmudgeTypes;                    // 0xa28808
DynamicVectorClass<TerrainTypeClass *> TerrainTypes;                  // 0xa27f70
DynamicVectorClass<BuildingTypeClass *> BuildingTypes;                // 0xa1e008
DynamicVectorClass<AircraftTypeClass *> AircraftTypes;                // 0xa255a8
DynamicVectorClass<UnitTypeClass *> UnitTypes;                        // 0xa1e078
DynamicVectorClass<AnimTypeClass *> AnimTypes;                        // 0x84e510
DynamicVectorClass<InfantryTypeClass *> InfantryTypes;                // 0xa27fa0
DynamicVectorClass<BulletTypeClass *> BulletTypes;                    // 0xa1e020
DynamicVectorClass<VoxelAnimTypeClass *> VoxelAnimTypes;              // 0xa28720
DynamicVectorClass<IsometricTileTypeClass *> IsometricTileTypes;      // 0xa28910
DynamicVectorClass<ParticleTypeClass *> ParticleTypes;                // 0xa1e130
DynamicVectorClass<ParticleSystemTypeClass *> ParticleSystemTypes;    // 0xa1e100
DynamicVectorClass<SuperWeaponTypeClass *> SuperWeaponTypes;          // 0xa27f88
DynamicVectorClass<SuperClass *> Supers;                              // 0xa1e058
DynamicVectorClass<SuperClass *> ShowTimers;                          // 0xa1e0e8
DynamicVectorClass<TechnoClass *> Technos;                            // 0xa28860
DynamicVectorClass<TechnoTypeClass *> TechnoTypes;                    // 0xa286f8
DynamicVectorClass<ObjectClass *> Objects;                            // 0xa27fb8
DynamicVectorClass<AbstractTypeClass *> AbstractTypes;                // 0xa28578
DynamicVectorClass<AnimClass *> MoveFlashes;                          // 0xa1e190

TiberianSunClassFactory TibSunFactory;                                // 0xa284dc
MissionControlClass MissionControl[MISSION_COUNT];                    // 0xa28000
RandomStraw CryptRandom;                                              // 0xa283c8
DynamicVectorClass<ObjectClass *> CurrentObject;                      // 0xa288a0
VersionClass VerNum;                                                  // 0xa288c8
VoxelDataStruct DropPodVoxel;                                         // 0xa288c0
OptionsClass Options;                                                 // 0xa28758
ThemeClass Theme;                                                     // 0xa1e0a8
CreditClass CreditDisplay;                                            // 0xa1e1a8
QueueClass<EventClass, MAX_EVENTS> OutList;                           // 0xa1a668
QueueClass<EventClass, (MAX_EVENTS * 128)> DoList;                    // 0x84e5a0
QueueClass<EventClass, (MAX_EVENTS * 2)> MirrorList;                  // 0xa1e260
DynamicVectorClass<TagClass *> MapTags;                               // 0x84e568
DynamicVectorClass<TagClass *> LogicTags;                             // 0x84e490
SessionClass Session;                                                 // 0xa255c8
NullModemClass NullModem(16, 16, 0xE6, 0x1234);                       // 0xa28668
IPXManagerClass Ipx(0x1C7, 0x234, 0xA0, 0x20, 0x8813, 0xAA03);       // 0xa285c8
GetCDClass CDList;                                                    // 0xa284f8
