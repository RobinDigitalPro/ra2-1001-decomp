// unidentified translation unit (GAMECONST.H initializers at 0x314ab0) (level-2 reconstruction of GAME.EXE 1.001)
// Contents: WarheadTypeClass (RTTI .?AVWarheadTypeClass@@, primary vtable 0x799a98, base
// AbstractTypeClass, Size_Of 0x178, Kind_Of 0x32). INI keys from Read_INI name the members;
// everything else is provisional.
#include "../GAMECONST.H"
#include "../ABSTYPE.H"
#include "../VECTOR.H"
#include <new.h>
#include <string.h>
#include <stdlib.h>

// ---- local declarations (to be moved to headers by the integrator) ----

// CRC.H plus the double overload 0x493d50 used here.
class CRCEngine {
public:
    void operator() (char datum);           // 0x493bd0
    void operator() (bool datum);           // 0x493c60
    void operator() (int datum);            // 0x493d10
    void operator() (double datum);         // 0x493d50
    void operator() (char const * string);
};

class SwizzleManagerClass {
public:
    HRESULT __stdcall Swizzle(void ** pointer);             // 0x695170
    HRESULT __stdcall Here_I_Am(LONG id, void * pointer);   // 0x6951f0
};
extern SwizzleManagerClass SwizzleManager;                  // 0xaa5370

void Detach_This_From_All(AbstractClass * object, bool all);    // 0x6e1e50 (name provisional)

class AnimTypeClass;
class ParticleTypeClass;

// TypeList<T> (RTTI .?AV?$TypeList@PBVAnimTypeClass@@@@, vtable 0x78eb3c): a DynamicVectorClass of
// type pointers with one extra dword (+0x18). Load/Save are inline here.
template<class T> class TypeList : public DynamicVectorClass<T> {
public:
    TypeList() {}

    void Init() { new (this) TypeList<T>; }
    void Load(IStream * pStm)
    {
        Init();
        int count;
        pStm->Read(&count, sizeof(count), NULL);
        for (int index = 0; index < count; index++) {
            T ptr;
            pStm->Read(&ptr, sizeof(ptr), NULL);
            Add(ptr);
        }
    }
    void Save(IStream * pStm)
    {
        int count = Count();
        pStm->Write(&count, sizeof(count), NULL);
        for (int index = 0; index < count; index++) {
            pStm->Write(&Vector[index], sizeof(Vector[index]), NULL);
        }
    }

    int Unknown18;
};

// {A8C54DA4-0F7B-11D2-8172-006008055BB5} (GAME.EXE 0x78cdb0)
class __declspec(uuid("A8C54DA4-0F7B-11D2-8172-006008055BB5")) WarheadTypeClass : public AbstractTypeClass {
public:
    WarheadTypeClass(char const * ini_name);
    WarheadTypeClass(NoInitClass const & x);
    virtual ~WarheadTypeClass();

    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);

    virtual void Pointer_Expired(AbstractClass * object, bool removed);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    virtual void Compute_CRC(CRCEngine & crc) const;
    virtual bool Read_INI(CCINIClass & ini);

    static WarheadTypeClass * Find_Or_Make(char const * name);
    static WarheadTypeClass * From_Name(char const * name);

    double Deform;                          // +0x98
    double Verses[11];                      // +0xa0
    double ProneDamage;                     // +0xf8
    int DeformThreshhold;                   // +0x100
    TypeList<AnimTypeClass const *> AnimList;   // +0x104
    int InfDeath;                           // +0x120
    float CellSpread;                       // +0x124
    float CellInset;                        // +0x128
    float PercentAtMax;                     // +0x12c
    bool CausesDelayKill;                   // +0x130
    int DelayKillFrames;                    // +0x134
    float DelayKillAtMax;                   // +0x138
    float CombatLightSize;                  // +0x13c
    ParticleTypeClass * Particle;           // +0x140
    bool Wall;                              // +0x144
    bool WallAbsoluteDestroyer;             // +0x145
    bool Wood;                              // +0x146
    bool Tiberium;                          // +0x147
    bool IsOrganic;                         // +0x148 (Verses[4] and Verses[6] both zero; name provisional)
    bool Sparky;                            // +0x149
    bool Sonic;                             // +0x14a
    bool Fire;                              // +0x14b
    bool Conventional;                      // +0x14c
    bool Rocker;                            // +0x14d
    bool Bright;                            // +0x14e
    bool CLDisableRed;                      // +0x14f
    bool CLDisableGreen;                    // +0x150
    bool CLDisableBlue;                     // +0x151
    bool EMEffect;                          // +0x152
    bool MindControl;                       // +0x153
    bool IvanBomb;                          // +0x154
    bool ElectricAssault;                   // +0x155
    bool Parasite;                          // +0x156
    bool Temporal;                          // +0x157
    bool BombDisarm;                        // +0x158
    int Paralyzes;                          // +0x15c
    bool Culling;                           // +0x160
    bool MakesDisguise;                     // +0x161
    bool NukeMaker;                         // +0x162
    bool Radiation;                         // +0x163
    bool PsychicDamage;                     // +0x164
    bool Bullets;                           // +0x165
    bool Veinhole;                          // +0x166
    int ShakeXlo;                           // +0x168
    int ShakeXhi;                           // +0x16c
    int ShakeYlo;                           // +0x170
    int ShakeYhi;                           // +0x174
};

extern DynamicVectorClass<WarheadTypeClass *> WarheadTypes;         // 0x821e40
extern DynamicVectorClass<AbstractClass *> AbstractList87B8;        // 0xaa87b8, meaning unknown

// ---- end of local declarations ----

// 0x314c80: "75%" style percentage or plain number (name provisional).
double Percent_Value(char const * string)
{
    if (strchr(string, '%')) {
        return atoi(string) * 0.01;
    }
    return atof(string);
}

WarheadTypeClass::WarheadTypeClass(char const * ini_name) :
    AbstractTypeClass(ini_name),
    Deform(0.0),
    ProneDamage(1.0),
    DeformThreshhold(0),
    InfDeath(0),
    CellSpread(0.0f),
    CellInset(0.0f),
    PercentAtMax(1.0f),
    CausesDelayKill(false),
    DelayKillFrames(5),
    DelayKillAtMax(1.0f),
    CombatLightSize(0.0f),
    Particle(NULL),
    Wall(false),
    WallAbsoluteDestroyer(false),
    Wood(false),
    Tiberium(false),
    IsOrganic(false),
    Sparky(false),
    Sonic(false),
    Fire(false),
    Conventional(false),
    Rocker(false),
    Bright(false),
    CLDisableRed(false),
    CLDisableGreen(false),
    CLDisableBlue(false),
    EMEffect(false),
    MindControl(false),
    IvanBomb(false),
    ElectricAssault(false),
    Parasite(false),
    Temporal(false),
    BombDisarm(false),
    Paralyzes(0),
    Culling(false),
    MakesDisguise(false),
    NukeMaker(false),
    Radiation(false),
    PsychicDamage(false),
    Bullets(false),
    Veinhole(false),
    ShakeXlo(0),
    ShakeXhi(0),
    ShakeYlo(0),
    ShakeYhi(0)
{
    AbstractClass::Create_ID();
    WarheadTypes.Add(this);
    AbstractList87B8.Add(this);
    for (int index = 0; index < 11; index++) {
        Verses[index] = 1.0;
    }
}

WarheadTypeClass::WarheadTypeClass(NoInitClass const & x) : AbstractTypeClass(x)
{
}

WarheadTypeClass::~WarheadTypeClass()
{
    Detach_This_From_All(this, true);
    WarheadTypes.Delete(this);
    AbstractList87B8.Delete(this);
}

void WarheadTypeClass::Compute_CRC(CRCEngine & crc) const
{
    AbstractTypeClass::Compute_CRC(crc);
    crc(Wall);
    crc(Wood);
    crc(Tiberium);
    crc(IsOrganic);
    crc(Sparky);
    crc(Sonic);
    crc(Fire);
    crc(Conventional);
    crc(Rocker);
    crc(Bright);
    crc(CLDisableRed);
    crc(CLDisableGreen);
    crc(CLDisableBlue);
    crc(Deform);
    crc(DeformThreshhold);
    crc(ProneDamage);
    crc(Veinhole);
    crc(ShakeXlo);
    crc(ShakeXhi);
    crc(ShakeYlo);
    crc(ShakeYhi);
    for (int index = 0; index < 11; index++) {
        crc(Verses[index]);
    }
    crc(AnimList.Count());
    crc(InfDeath);
}

HRESULT __stdcall WarheadTypeClass::GetClassID(CLSID * pClassID)
{
    if (pClassID == NULL) {
        return E_POINTER;
    }
    *pClassID = __uuidof(WarheadTypeClass);
    return S_OK;
}

HRESULT __stdcall WarheadTypeClass::Load(IStream * pStm)
{
    HRESULT hr = AbstractTypeClass::Load(pStm);
    if (FAILED(hr)) {
        return hr;
    }
    new (this) WarheadTypeClass(NoInitClass());
    AnimList.Load(pStm);
    for (int index = 0; index < AnimList.Count(); index++) {
        SwizzleManager.Swizzle((void **)&AnimList[index]);
    }
    SwizzleManager.Swizzle((void **)&Particle);
    return S_OK;
}

HRESULT __stdcall WarheadTypeClass::Save(IStream * pStm, BOOL fClearDirty)
{
    HRESULT hr = AbstractTypeClass::Save(pStm, fClearDirty);
    if (FAILED(hr)) {
        return hr;
    }
    AnimList.Save(pStm);
    return S_OK;
}

WarheadTypeClass * WarheadTypeClass::Find_Or_Make(char const * name)
{
    if (!stricmp("<none>", name) || !stricmp("none", name)) {
        return NULL;
    }
    for (int index = 0; index < WarheadTypes.Count(); index++) {
        if (!stricmp(WarheadTypes[index]->ID, name)) {
            return WarheadTypes[index];
        }
    }
    return new WarheadTypeClass(name);
}

void WarheadTypeClass::Pointer_Expired(AbstractClass * object, bool removed)
{
    if (object == (AbstractClass *)Particle) {
        Particle = NULL;
    }
    AnimList.Delete((AnimTypeClass const *)object);
}

WarheadTypeClass * WarheadTypeClass::From_Name(char const * name)
{
    for (int index = 0; index < WarheadTypes.Count(); index++) {
        if (!stricmp(WarheadTypes[index]->ID, name)) {
            return WarheadTypes[index];
        }
    }
    return NULL;
}

int WarheadTypeClass::Size_Of() const
{
    return sizeof(WarheadTypeClass);
}

int WarheadTypeClass::Kind_Of() const
{
    return 0x32;
}
