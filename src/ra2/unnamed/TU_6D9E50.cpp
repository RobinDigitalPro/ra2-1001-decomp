// C:\RA2\TerrType.cpp (probable name; RTTI .?AVTerrainTypeClass@@) (level-2 reconstruction of GAME.EXE 1.001)
// Terrain object types (trees, rocks, veinholes). The class name comes from RTTI; all member,
// method and variable names are provisional (Westwood style).
#include "../RECT.H"
static RectangleStruct const ZeroRectA(0, 0, 0, 0);
#include "../GAMECONST.H"
#include <new.h>
#include <stdlib.h>
#include <string.h>
#include "../ABSTYPE.H"

// ---- local declarations (to be moved to headers by the integrator) ----

class HouseClass;
class ObjectClass;

// INI database; only the methods used here (see CCINI.H).
class CCINIClass {
public:
    bool Get_Bool(char const * section, char const * entry, bool defvalue) const;      // 0x50e860
    int Get_Int(char const * section, char const * entry, int defvalue) const;         // 0x50cc40
    double Get_Float(char const * section, char const * entry, double defvalue) const; // 0x50d7f0
    int Get_Foundation(char const * section, char const * entry, int defvalue) const;  // 0x469e80
};
extern CCINIClass ArtINI;                       // 0x821b30

// CRC accumulator (see CRC.H); adds the float overload 0x493d30.
class CRCEngine {
public:
    void operator() (char datum);               // 0x493bd0
    void operator() (bool datum);               // 0x493c60
    void operator() (int datum);                // 0x493d10
    void operator() (float datum);              // 0x493d30
};

class RulesClass {
public:
    char Unknown0000[0xE1C];
    int TreeStrength;                           // +0xe1c (name provisional)
};
extern RulesClass * Rule;                       // 0x821b88

class MapClass {
public:
    int Get_Cell_Height(CoordStruct const & coord) const;   // 0x557070 (name provisional)
};
class MouseClass : public MapClass {
};
extern MouseClass Map;                          // 0x81a820

// Theater table (0x785bac is the address of the first entry's file suffix, stride 0x68).
struct TheaterSuffixStruct {
    char Suffix[0x68];
};
extern TheaterSuffixStruct TheaterSuffixes[];   // 0x785bac (names provisional)
extern int LastTheater;                         // 0x7c397c (name provisional)
extern bool ForceTheaterReload;                 // 0xa28953 (name provisional)

class MFCD {
public:
    static void * Retrieve(char const * filename);          // 0x5924c0
};

void Detach_This_From_All(AbstractClass * object, bool all);    // 0x6e1e50 (name provisional)

struct RGBStruct {
    RGBStruct() {}
    RGBStruct(unsigned char red, unsigned char green, unsigned char blue) : Red(red), Green(green), Blue(blue) {}
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
};

// Shape file header and frame header (only the fields used here).
struct ShapeFrameStruct {
    short X;
    short Y;
    short Width;
    short Height;
    int Flags;
    unsigned char Red;                          // +0x0c
    unsigned char Green;
    unsigned char Blue;
    char Unknown0F[0x18 - 0x0F];
};
struct ShapeFileStruct {
    short Unknown0;
    short Width;
    short Height;
    unsigned short Count;                       // +0x06
    ShapeFrameStruct Frames[1];                 // +0x08
};

// ObjectTypeClass; only the slots and fields used here are named.
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
    virtual ShapeFileStruct const * Get_Image() const;                 // slot 39 (+0x9c)

    void Load_Fixup_5CEDC0();                   // 0x5cedc0 (meaning unknown)
    void Load_Fixup_5CFCC0();                   // 0x5cfcc0 (meaning unknown)

    char Unknown98[0x9C - 0x98];
    int Armor;                                  // +0x9c
    int Strength;                               // +0xa0
    void * Image;                               // +0xa4
    bool IsImageAllocated;                      // +0xa8
    char UnknownA9[0x1C8 - 0xA9];
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
    char Unknown206[0x264 - 0x206];
};

class TerrainTypeClass;

class TerrainClass {
public:
    TerrainClass(TerrainTypeClass const * classid, CellStruct const & cell);   // 0x6d8690
    char Unknown00[0xC8];
};

class __declspec(uuid("5AF2CE7B-0634-11D2-ACA4-006008055BB5")) TerrainTypeClass : public ObjectTypeClass {
public:
    TerrainTypeClass(char const * ini_name);
    TerrainTypeClass(NoInitClass const & x);
    virtual ~TerrainTypeClass();

    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);

    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    virtual void Compute_CRC(CRCEngine & crc) const;
    virtual int Array_Index() const;
    virtual bool Read_INI(CCINIClass & ini);
    virtual CoordStruct Fixup_Coord(CoordStruct const & coord) const;
    virtual bool Create_And_Place(CellStruct const & cell, HouseClass * house) const;
    virtual ObjectClass * Create_One_Of(HouseClass * house) const;
    virtual CellStruct const * Occupy_List(bool placement = false) const;

    static void Init(int theater);
    static int Find_Index(char const * name);
    static TerrainTypeClass * From_Name(char const * name);

    int ArrayIndex;                             // +0x264
    int Foundation;                             // +0x268
    RGBStruct RadarColor;                       // +0x26c
    int AnimationRate;                          // +0x270
    float AnimationProbability;                 // +0x274
    int TemperateOccupationBits;                // +0x278
    int SnowOccupationBits;                     // +0x27c
    bool WaterBound;                            // +0x280
    bool SpawnsTiberium;                        // +0x281
    bool IsFlammable;                           // +0x282
    bool IsAnimated;                            // +0x283
    bool IsVeinhole;                            // +0x284
    CellStruct const * FoundationList;          // +0x288
};

extern DynamicVectorClass<TerrainTypeClass *> TerrainTypes;     // 0xa27f70

// ---- end of local declarations ----

// The foundation table uses Cell(int, int) and Cell(), as in TerrType.cpp.
class Cell : public CellStruct {
public:
    Cell() : CellStruct() {}
    Cell(int x, int y) : CellStruct(x, y) {}
};

// Building foundation cell lists, one row per foundation type, each terminated by 0x7FFF,0x7FFF.
Cell Foundations[22][10] = {
    {Cell(0, 0), Cell(0x7FFF, 0x7FFF)},
    {Cell(0, 0), Cell(1, 0), Cell(0x7FFF, 0x7FFF)},
    {Cell(0, 0), Cell(0, 1), Cell(0x7FFF, 0x7FFF)},
    {Cell(0, 0), Cell(1, 0), Cell(0, 1), Cell(1, 1), Cell(0x7FFF, 0x7FFF)},
    {Cell(0, 0), Cell(1, 0), Cell(0, 1), Cell(1, 1), Cell(0, 2), Cell(1, 2),
     Cell(0x7FFF, 0x7FFF)},
    {Cell(0, 0), Cell(1, 0), Cell(2, 0), Cell(0, 1), Cell(1, 1), Cell(2, 1),
     Cell(0x7FFF, 0x7FFF)},
    {Cell(0, 0), Cell(1, 0), Cell(2, 0), Cell(0, 1), Cell(1, 1), Cell(2, 1),
     Cell(0, 2), Cell(1, 2), Cell(2, 2), Cell(0x7FFF, 0x7FFF)},
    {Cell(0, 0), Cell(1, 0), Cell(2, 0), Cell(3, 0), Cell(0, 1), Cell(1, 1),
     Cell(2, 1), Cell(3, 1), Cell(0x7FFF, 0x7FFF)},
};

TerrainTypeClass::TerrainTypeClass(char const * ini_name) :
    ObjectTypeClass(ini_name),
    ArrayIndex(-1),
    Foundation(0),
    RadarColor(0, 0, 0),
    AnimationRate(0),
    AnimationProbability(0),
    TemperateOccupationBits(7),
    SnowOccupationBits(7),
    WaterBound(false),
    SpawnsTiberium(false),
    IsFlammable(false),
    IsAnimated(false),
    IsVeinhole(false),
    FoundationList(NULL)
{
    Create_ID();
    IsFlag200 = false;
    IsFlag204 = true;
    IsFlag1FF = true;
    IsFlag201 = false;
    IsFlag202 = true;
    TerrainTypes.Add(this);
    ArrayIndex = TerrainTypes.ID(this);
    Strength = -1;
    Armor = 6;
}

TerrainTypeClass::TerrainTypeClass(NoInitClass const & x) : ObjectTypeClass(x)
{
}

TerrainTypeClass::~TerrainTypeClass()
{
    Detach_This_From_All(this, true);
    TerrainTypes.Delete(this);
}

void TerrainTypeClass::Init(int theater)
{
    if (!ForceTheaterReload && theater == LastTheater) {
        return;
    }
    for (int index = 0; index < TerrainTypes.Count(); index++) {
        TerrainTypeClass * terrain = TerrainTypes[index];
        if (terrain->IsTheater) {
            char fullname[512];
            _makepath(fullname, NULL, NULL, terrain->ID, TheaterSuffixes[theater].Suffix);
            if (terrain->IsImageAllocated && terrain->Image != NULL) {
                delete terrain->Image;
            }
            terrain->Image = NULL;
            terrain->IsImageAllocated = false;
            terrain->Image = MFCD::Retrieve(fullname);
        }
    }
}

int TerrainTypeClass::Find_Index(char const * name)
{
    if (name != NULL) {
        for (int index = 0; index < TerrainTypes.Count(); index++) {
            if (stricmp(name, TerrainTypes[index]->ID) == 0) {
                return index;
            }
        }
    }
    return -1;
}

bool TerrainTypeClass::Create_And_Place(CellStruct const & cell, HouseClass *) const
{
    if (new TerrainClass(this, cell)) {
        return true;
    }
    return false;
}

ObjectClass * TerrainTypeClass::Create_One_Of(HouseClass *) const
{
    return (ObjectClass *)new TerrainClass(this, EmptyCell);
}

CellStruct const * TerrainTypeClass::Occupy_List(bool) const
{
    if (FoundationList == NULL) {
        static CellStruct const _list[] = {CellStruct(0x7FFF, 0x7FFF)};
        return _list;
    }
    return FoundationList;
}

bool TerrainTypeClass::Read_INI(CCINIClass & ini)
{
    if (ObjectTypeClass::Read_INI(ini)) {
        if (Strength == -1) {
            Strength = Rule->TreeStrength;
        }
        IsVeinhole = ini.Get_Bool(ID, "IsVeinhole", IsVeinhole);
        if (IsVeinhole) {
            IsFlag204 = false;
            IsFlag201 = true;
        }
        WaterBound = ini.Get_Bool(ID, "WaterBound", WaterBound);
        SpawnsTiberium = ini.Get_Bool(ID, "SpawnsTiberium", SpawnsTiberium);
        IsFlammable = ini.Get_Bool(ID, "IsFlammable", IsFlammable);
        Foundation = ArtINI.Get_Foundation(GraphicName, "Foundation", Foundation);
        FoundationList = Foundations[Foundation];
        if (!IsTheater) {
            char fullname[512];
            _makepath(fullname, NULL, NULL, GraphicName, ".SHP");
            Image = MFCD::Retrieve(fullname);
        }
        ShapeFileStruct const * image = Get_Image();
        if (image != NULL) {
            ShapeFrameStruct const * frame = (image->Count > 0) ? &image->Frames[0] : NULL;
            RGBStruct color;
            if (frame != NULL) {
                color = RGBStruct(frame->Red, frame->Green, frame->Blue);
            } else {
                color = RGBStruct(0, 0, 0);
            }
            RadarColor = color;
        }
        IsAnimated = ini.Get_Bool(ID, "IsAnimated", IsAnimated);
        AnimationRate = ini.Get_Int(ID, "AnimationRate", AnimationRate);
        AnimationProbability = ini.Get_Float(ID, "AnimationProbability", AnimationProbability);
        TemperateOccupationBits = ini.Get_Int(ID, "TemperateOccupationBits", TemperateOccupationBits);
        SnowOccupationBits = ini.Get_Int(ID, "SnowOccupationBits", SnowOccupationBits);
        return true;
    }
    return false;
}

CoordStruct TerrainTypeClass::Fixup_Coord(CoordStruct const & coord) const
{
    CoordStruct result = coord;
    if (result.Z < Map.Get_Cell_Height(result)) {
        result.Z = Map.Get_Cell_Height(result);
    }
    return result;
}

void TerrainTypeClass::Compute_CRC(CRCEngine & crc) const
{
    ObjectTypeClass::Compute_CRC(crc);
    crc(ArrayIndex);
    crc(WaterBound);
    crc(SpawnsTiberium);
    crc(IsFlammable);
    crc(Foundation);
    crc(IsAnimated);
    crc(AnimationRate);
    crc(AnimationProbability);
}

HRESULT __stdcall TerrainTypeClass::Load(IStream * pStm)
{
    HRESULT hr = ObjectTypeClass::Load(pStm);
    if (SUCCEEDED(hr)) {
        new (this) TerrainTypeClass(NoInitClass());
        Load_Fixup_5CEDC0();
        Load_Fixup_5CFCC0();
        FoundationList = Foundations[Foundation];
        hr = S_OK;
    }
    return hr;
}

HRESULT __stdcall TerrainTypeClass::Save(IStream * pStm, BOOL fClearDirty)
{
    HRESULT hr = ObjectTypeClass::Save(pStm, fClearDirty);
    if (SUCCEEDED(hr)) {
        hr = S_OK;
    }
    return hr;
}

HRESULT __stdcall TerrainTypeClass::GetClassID(CLSID * pClassID)
{
    if (pClassID == NULL) {
        return E_POINTER;
    }
    *pClassID = __uuidof(TerrainTypeClass);
    return S_OK;
}

TerrainTypeClass * TerrainTypeClass::From_Name(char const * name)
{
    if (stricmp("<none>", name) == 0 || stricmp("none", name) == 0) {
        return NULL;
    }
    for (int index = 0; index < TerrainTypes.Count(); index++) {
        if (stricmp(TerrainTypes[index]->ID, name) == 0) {
            return TerrainTypes[index];
        }
    }
    return new TerrainTypeClass(name);
}

int TerrainTypeClass::Kind_Of() const
{
    return 0x25;
}

int TerrainTypeClass::Size_Of() const
{
    return sizeof(*this);
}

int TerrainTypeClass::Array_Index() const
{
    return ArrayIndex;
}
