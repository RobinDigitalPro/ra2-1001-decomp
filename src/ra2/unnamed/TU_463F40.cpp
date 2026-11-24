// BulletTypeClass (RTTI .?AVBulletTypeClass@@, vtable 0x7885c0) (level-2 reconstruction of GAME.EXE 1.001)
// Probable original file C:\RA2\BTYPE.CPP or BulletType.cpp (no __FILE__ string in this range).
// Code range 0x464110..0x464ea5. Member names follow the INI keys; other names are provisional.
#include "../RECT.H"
static RectangleStruct const ZeroRectA(0, 0, 0, 0);
#include "../GAMECONST.H"
#include <stdlib.h>
#include <string.h>
#include <new.h>
#include "../ABSTYPE.H"

// ---- local declarations (to be moved to headers by the integrator) ----

class HouseClass;
class ObjectClass;

// INI database; only the methods used here (see CCINI.H).
class CCINIClass {
public:
    int Get_String(char const * section, char const * entry, char const * defvalue, char * buffer, int size);   // 0x50ddf0
    bool Get_Bool(char const * section, char const * entry, bool defvalue) const;      // 0x50e860
    int Get_Int(char const * section, char const * entry, int defvalue) const;         // 0x50cc40
    double Get_Float(char const * section, char const * entry, double defvalue) const; // 0x50d7f0
    int Get_Color_Index(char const * section, char const * entry, int defvalue) const; // 0x469b70 (name provisional)
};
extern CCINIClass ArtINI;                       // 0x821b30
extern char NullString[];                       // 0x8248a4 (.bss), shared empty string (name provisional)

// CRC accumulator (see CRC.H); adds the double overload 0x493d50.
class CRCEngine {
public:
    void operator() (char datum);               // 0x493bd0
    void operator() (bool datum);               // 0x493c60
    void operator() (int datum);                // 0x493d10
    void operator() (double datum);             // 0x493d50
};

// Pointer swizzling while loading (object 0xaa5370), see Super.CPP.
class SwizzleManagerClass {
public:
    HRESULT __stdcall Swizzle(void ** pointer);             // 0x695170
};
extern SwizzleManagerClass SwizzleManager;      // 0xaa5370

class MapClass {
public:
    int Get_Cell_Height(CoordStruct const & coord) const;   // 0x557070 (name provisional)
};
class MouseClass : public MapClass {
};
extern MouseClass Map;                          // 0x81a820

void Detach_This_From_All(AbstractClass * object, bool all);    // 0x6e1e50 (name provisional)
extern DynamicVectorClass<AbstractClass *> AbstractList87B8;     // 0xaa87b8 (meaning unknown, see Super.CPP)

class AnimTypeClass {
public:
    static AnimTypeClass * Find_Or_Make(char const * name);     // 0x4264a0
};
class WeaponTypeClass {
public:
    static WeaponTypeClass * Find_Or_Make(char const * name);   // 0x728a60
};

// ObjectTypeClass; only the slots and fields used here are named (as in TU_6D9E50.cpp).
class ObjectTypeClass : public AbstractTypeClass {
public:
    ObjectTypeClass(char const * ini_name);     // 0x5cde80
    ObjectTypeClass(NoInitClass const & x);     // 0x5ce110
    virtual ~ObjectTypeClass();                 // 0x5ce1f0

    virtual HRESULT __stdcall Load(IStream * pStm);                    // 0x5d02c0
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);  // 0x5d04f0
    virtual bool Read_INI(CCINIClass & ini);    // 0x5cfea0

    virtual CoordStruct Fixup_Coord(CoordStruct const & coord) const;   // slot 27 (+0x6c)
    virtual void Slot_028();
    virtual void Slot_029();
    virtual void Slot_030();
    virtual void Slot_031();
    virtual bool Create_And_Place(CellStruct const & cell, HouseClass * house) const;  // slot 32 (+0x80)
    virtual int Cost_Of(HouseClass * house) const;                     // slot 33 (+0x84)
    virtual void Slot_034();
    virtual ObjectClass * Create_One_Of(HouseClass * house) const;     // slot 35 (+0x8c)
    virtual CellStruct const * Occupy_List(bool placement = false) const;  // slot 36 (+0x90)
    virtual void Slot_037();
    virtual void Slot_038();
    virtual void Slot_039();

    void Load_Fixup_5CEDC0();                   // 0x5cedc0 (meaning unknown)
    void Load_Fixup_5CFCC0();                   // 0x5cfcc0 (meaning unknown)

    char Unknown98[0x1C8 - 0x98];             // AbstractTypeClass ends at 0x98 (Name is 0x31 bytes)
    char GraphicName[0x1FC - 0x1C8];            // +0x1c8
    bool IsTheater;                             // +0x1fc
    char Unknown1FD[0x1FF - 0x1FD];
    bool IsFlag1FF;                             // +0x1ff
    bool IsFlag200;                             // +0x200
    bool IsFlag201;                             // +0x201
    bool IsFlag202;                             // +0x202
    bool IsFlag203;                             // +0x203
    bool IsFlag204;                             // +0x204
    bool IsFlag205;                             // +0x205
    bool IsFlag206;                             // +0x206
    char Unknown207[0x264 - 0x207];
};

// {5AF2CE77-0634-11D2-ACA4-006008055BB5} (GAME.EXE 0x78cb40)
class __declspec(uuid("5AF2CE77-0634-11D2-ACA4-006008055BB5")) BulletTypeClass : public ObjectTypeClass {
public:
    BulletTypeClass(char const * ini_name);
    BulletTypeClass(NoInitClass const & x);
    virtual ~BulletTypeClass();

    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);

    virtual void Pointer_Expired(AbstractClass * object, bool removed);
    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    virtual void Compute_CRC(CRCEngine & crc) const;
    virtual bool Read_INI(CCINIClass & ini);
    virtual CoordStruct Fixup_Coord(CoordStruct const & coord) const;
    virtual bool Create_And_Place(CellStruct const & cell, HouseClass * house) const;
    virtual ObjectClass * Create_One_Of(HouseClass * house) const;

    void Set_Field_2B8(int value);              // 0x464d80 (meaning unknown)

    static int Find_Or_Make_Index(char const * name);
    static char const * Name_From(int index);
    static BulletTypeClass * Find_Or_Make(char const * name);

    bool IsAirburst;                            // +0x264
    bool IsFloater;                             // +0x265
    bool IsSubjectToCliffs;                     // +0x266
    bool IsSubjectToElevation;                  // +0x267
    bool IsSubjectToWalls;                      // +0x268
    bool IsVeryHigh;                            // +0x269
    bool IsShadow;                              // +0x26a
    bool IsArcing;                              // +0x26b
    bool IsDropping;                            // +0x26c
    bool IsLevel;                               // +0x26d
    bool IsInviso;                              // +0x26e
    bool IsProximity;                           // +0x26f
    bool IsRanged;                              // +0x270
    bool IsRotates;                             // +0x271 (art key Rotates)
    bool IsInaccurate;                          // +0x272
    bool IsFlakScatter;                         // +0x273
    bool IsAntiAir;                             // +0x274
    bool IsAntiGround;                          // +0x275
    bool IsDegenerates;                         // +0x276
    bool IsBouncy;                              // +0x277
    bool IsAnimPalette;                         // +0x278
    bool IsFirersPalette;                       // +0x279
    int Cluster;                                // +0x27c
    WeaponTypeClass * AirburstWeapon;           // +0x280
    WeaponTypeClass * ShrapnelWeapon;           // +0x284
    int ShrapnelCount;                          // +0x288
    int DetonationAltitude;                     // +0x28c
    bool IsVertical;                            // +0x290
    double Elasticity;                          // +0x298
    int Acceleration;                           // +0x2a0
    int Color;                                  // +0x2a4
    AnimTypeClass * Trailer;                    // +0x2a8
    int ROT;                                    // +0x2ac
    int CourseLockDuration;                     // +0x2b0
    int SpawnDelay;                             // +0x2b4
    int Field2B8;                               // +0x2b8 (meaning unknown)
    bool IsScalable;                            // +0x2bc
    int Arm;                                    // +0x2c0
    unsigned char AnimLow;                      // +0x2c4
    unsigned char AnimHigh;                     // +0x2c5
    unsigned char AnimRate;                     // +0x2c6
    bool IsFlat;                                // +0x2c7
};

extern DynamicVectorClass<BulletTypeClass *> BulletTypes;   // 0xa1e020

// ---- end of local declarations ----

BulletTypeClass::BulletTypeClass(char const * ini_name) :
    ObjectTypeClass(ini_name),
    IsAirburst(false),
    IsFloater(false),
    IsSubjectToCliffs(false),
    IsSubjectToElevation(false),
    IsSubjectToWalls(false),
    IsVeryHigh(false),
    IsShadow(true),
    IsArcing(false),
    IsDropping(false),
    IsLevel(false),
    IsInviso(false),
    IsProximity(false),
    IsRanged(false),
    IsRotates(true),
    IsInaccurate(false),
    IsFlakScatter(false),
    IsAntiAir(false),
    IsAntiGround(true),
    IsDegenerates(false),
    IsBouncy(false),
    IsAnimPalette(false),
    IsFirersPalette(false),
    Cluster(1),
    AirburstWeapon(NULL),
    ShrapnelWeapon(NULL),
    ShrapnelCount(0),
    DetonationAltitude(0),
    IsVertical(false),
    Elasticity(0.75),
    Acceleration(3),
    Color(0),
    Trailer(NULL),
    ROT(0),
    CourseLockDuration(0),
    SpawnDelay(3),
    Field2B8(0),
    IsScalable(false),
    Arm(0),
    AnimLow(0),
    AnimHigh(0),
    AnimRate(0),
    IsFlat(false)
{
    Create_ID();
    IsFlag204 = true;
    IsFlag1FF = true;
    IsFlag200 = false;
    IsFlag201 = false;
    IsFlag202 = true;
    IsFlag203 = true;
    IsFlag205 = false;
    BulletTypes.Add(this);
    AbstractList87B8.Add(this);
}

BulletTypeClass::BulletTypeClass(NoInitClass const & x) : ObjectTypeClass(x)
{
}

BulletTypeClass::~BulletTypeClass()
{
    Detach_This_From_All(this, true);
    AbstractList87B8.Delete(this);
    BulletTypes.Delete(this);
}

bool BulletTypeClass::Read_INI(CCINIClass & ini)
{
    if (ObjectTypeClass::Read_INI(ini)) {
        Arm = ini.Get_Int(ID, "Arm", Arm);
        ROT = ini.Get_Int(ID, "ROT", ROT);
        CourseLockDuration = ini.Get_Int(ID, "CourseLockDuration", CourseLockDuration);
        Elasticity = ini.Get_Float(ID, "Elasticity", Elasticity);
        Acceleration = ini.Get_Int(ID, "Acceleration", Acceleration);
        Color = ini.Get_Color_Index(ID, "Color", Color);
        IsArcing = ini.Get_Bool(ID, "Arcing", IsArcing);
        IsFloater = ini.Get_Bool(ID, "Floater", IsFloater);
        IsSubjectToCliffs = ini.Get_Bool(ID, "SubjectToCliffs", IsSubjectToCliffs);
        IsSubjectToElevation = ini.Get_Bool(ID, "SubjectToElevation", IsSubjectToElevation);
        IsSubjectToWalls = ini.Get_Bool(ID, "SubjectToWalls", IsSubjectToWalls);
        IsVeryHigh = ini.Get_Bool(ID, "VeryHigh", IsVeryHigh);
        IsShadow = ini.Get_Bool(ID, "Shadow", IsShadow);
        IsDropping = ini.Get_Bool(ID, "Dropping", IsDropping);
        IsLevel = ini.Get_Bool(ID, "Level", IsLevel);
        IsInviso = ini.Get_Bool(ID, "Inviso", IsInviso);
        IsProximity = ini.Get_Bool(ID, "Proximity", IsProximity);
        IsRanged = ini.Get_Bool(ID, "Ranged", IsRanged);
        IsInaccurate = ini.Get_Bool(ID, "Inaccurate", IsInaccurate);
        IsFlakScatter = ini.Get_Bool(ID, "FlakScatter", IsFlakScatter);
        IsAntiAir = ini.Get_Bool(ID, "AA", IsAntiAir);
        IsAntiGround = ini.Get_Bool(ID, "AG", IsAntiGround);
        IsDegenerates = ini.Get_Bool(ID, "Degenerates", IsDegenerates);
        IsBouncy = ini.Get_Bool(ID, "Bouncy", IsBouncy);
        IsAirburst = ini.Get_Bool(ID, "Airburst", IsAirburst);
        Cluster = ini.Get_Int(ID, "Cluster", Cluster);
        IsScalable = ini.Get_Bool(ID, "Scalable", IsScalable);

        char buffer[128];
        if (ini.Get_String(ID, "Image", NullString, GraphicName, 0x19) > 0) {
            AnimTypeClass * trailer = Trailer;
            if (ArtINI.Get_String(GraphicName, "Trailer", NullString, buffer, sizeof(buffer))) {
                trailer = AnimTypeClass::Find_Or_Make(buffer);
            }
            Trailer = trailer;
            SpawnDelay = ArtINI.Get_Int(GraphicName, "SpawnDelay", SpawnDelay);
            IsRotates = !ArtINI.Get_Bool(GraphicName, "Rotates", !IsRotates);
            IsFlat = ArtINI.Get_Bool(GraphicName, "Flat", IsFlat);
        }

        WeaponTypeClass * weapon = AirburstWeapon;
        if (ini.Get_String(ID, "AirburstWeapon", NullString, buffer, sizeof(buffer))) {
            weapon = WeaponTypeClass::Find_Or_Make(buffer);
        }
        AirburstWeapon = weapon;
        weapon = ShrapnelWeapon;
        if (ini.Get_String(ID, "ShrapnelWeapon", NullString, buffer, sizeof(buffer))) {
            weapon = WeaponTypeClass::Find_Or_Make(buffer);
        }
        ShrapnelWeapon = weapon;
        ShrapnelCount = ini.Get_Int(ID, "ShrapnelCount", ShrapnelCount);
        DetonationAltitude = ini.Get_Int(ID, "DetonationAltitude", DetonationAltitude);
        IsVertical = ini.Get_Bool(ID, "Vertical", IsVertical);
        IsFirersPalette = ini.Get_Bool(ID, "FirersPalette", IsFirersPalette);
        AnimLow = ArtINI.Get_Int(GraphicName, "AnimLow", AnimLow);
        AnimHigh = ArtINI.Get_Int(GraphicName, "AnimHigh", AnimHigh);
        AnimRate = ArtINI.Get_Int(GraphicName, "AnimRate", AnimRate);
        IsAnimPalette = ArtINI.Get_Bool(GraphicName, "AnimPalette", IsAnimPalette);

        if (!IsInviso) {
            Load_Fixup_5CFCC0();
        }
        if (IsFlag206) {
            Load_Fixup_5CEDC0();
        }
        return true;
    }
    return false;
}

int BulletTypeClass::Find_Or_Make_Index(char const * name)
{
    if (stricmp(name, "<none>") == 0) {
        return -1;
    }
    for (int index = 0; index < BulletTypes.Count(); index++) {
        if (stricmp(name, BulletTypes[index]->ID) == 0) {
            return index;
        }
    }
    return BulletTypes.ID(new BulletTypeClass(name));
}

char const * BulletTypeClass::Name_From(int index)
{
    if ((unsigned)index < (unsigned)BulletTypes.Count()) {
        return BulletTypes[index]->ID;
    }
    return NULL;
}

CoordStruct BulletTypeClass::Fixup_Coord(CoordStruct const & coord) const
{
    CoordStruct result = coord;
    if (result.Z <= Map.Get_Cell_Height(result)) {
        result.Z = Map.Get_Cell_Height(result) + 1;
    }
    return result;
}

void BulletTypeClass::Compute_CRC(CRCEngine & crc) const
{
    ObjectTypeClass::Compute_CRC(crc);
    crc(IsAirburst);
    crc(IsShadow);
    crc(IsArcing);
    crc(IsDropping);
    crc(IsLevel);
    crc(IsInviso);
    crc(IsProximity);
    crc(IsRanged);
    crc(IsRotates);
    crc(IsInaccurate);
    crc(IsFlakScatter);
    crc(IsAntiAir);
    crc(IsAntiGround);
    crc(IsDegenerates);
    crc(IsBouncy);
    crc(Elasticity);
    crc(Acceleration);
    crc(ROT);
    crc(Arm);
    crc(IsFlat);
}

HRESULT __stdcall BulletTypeClass::Load(IStream * pStm)
{
    HRESULT hr = ObjectTypeClass::Load(pStm);
    if (SUCCEEDED(hr)) {
        new (this) BulletTypeClass(NoInitClass());
        Load_Fixup_5CEDC0();
        Load_Fixup_5CFCC0();
        SwizzleManager.Swizzle((void **)&Trailer);
        SwizzleManager.Swizzle((void **)&AirburstWeapon);
        SwizzleManager.Swizzle((void **)&ShrapnelWeapon);
        hr = S_OK;
    }
    return hr;
}

HRESULT __stdcall BulletTypeClass::Save(IStream * pStm, BOOL fClearDirty)
{
    HRESULT hr = ObjectTypeClass::Save(pStm, fClearDirty);
    if (SUCCEEDED(hr)) {
        hr = S_OK;
    }
    return hr;
}

HRESULT __stdcall BulletTypeClass::GetClassID(CLSID * pClassID)
{
    if (pClassID == NULL) {
        return E_POINTER;
    }
    *pClassID = __uuidof(BulletTypeClass);
    return S_OK;
}

BulletTypeClass * BulletTypeClass::Find_Or_Make(char const * name)
{
    if (!stricmp("<none>", name) || !stricmp("none", name)) {
        return NULL;
    }
    for (int index = 0; index < BulletTypes.Count(); index++) {
        if (!stricmp(BulletTypes[index]->ID, name)) {
            return BulletTypes[index];
        }
    }
    return new BulletTypeClass(name);
}

void BulletTypeClass::Pointer_Expired(AbstractClass * object, bool)
{
    if (object == (AbstractClass *)Trailer) {
        Trailer = NULL;
    }
}

void BulletTypeClass::Set_Field_2B8(int value)
{
    Field2B8 = value;
}

int BulletTypeClass::Kind_Of() const
{
    return 9;
}

int BulletTypeClass::Size_Of() const
{
    return sizeof(*this);
}

bool BulletTypeClass::Create_And_Place(CellStruct const &, HouseClass *) const
{
    return false;
}

ObjectClass * BulletTypeClass::Create_One_Of(HouseClass *) const
{
    return NULL;
}
