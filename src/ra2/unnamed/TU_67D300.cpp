// C:\RA2\SmudType.cpp (probable name; RTTI .?AVSmudgeTypeClass@@) (level-2 reconstruction of GAME.EXE 1.001)
// Smudge types (craters and scorch marks). The class name comes from RTTI; all member, method and
// variable names are provisional (Westwood style).
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
};

// CRC accumulator (see CRC.H); adds the float overload 0x493d30.
class CRCEngine {
public:
    void operator() (char datum);               // 0x493bd0
    void operator() (bool datum);               // 0x493c60
    void operator() (int datum);                // 0x493d10
};

class ScenarioClass {
public:
    char Unknown000[0x838];
    int Theater;                                // +0x838
};
extern ScenarioClass * Scen;                    // 0xa255c0

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

class SmudgeTypeClass;

class SmudgeClass {
public:
    SmudgeClass(SmudgeTypeClass const * classid, CoordStruct const & coord, int house = -1);    // 0x67ccf0
    char Unknown00[0x9C];
};

inline CoordStruct Cell_Coord(CellStruct const & cell)
{
    return CoordStruct(cell.X * 256 + 128, cell.Y * 256 + 128, 0);
}

class __declspec(uuid("5AF2CE78-0634-11D2-ACA4-006008055BB5")) SmudgeTypeClass : public ObjectTypeClass {
public:
    SmudgeTypeClass(char const * ini_name);
    SmudgeTypeClass(NoInitClass const & x);
    virtual ~SmudgeTypeClass();

    virtual HRESULT __stdcall GetClassID(CLSID * pClassID);
    virtual HRESULT __stdcall Load(IStream * pStm);
    virtual HRESULT __stdcall Save(IStream * pStm, BOOL fClearDirty);

    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    virtual void Compute_CRC(CRCEngine & crc) const;
    virtual int Array_Index() const;
    virtual bool Read_INI(CCINIClass & ini);
    virtual bool Create_And_Place(CellStruct const & cell, HouseClass * house) const;
    virtual ObjectClass * Create_One_Of(HouseClass * house) const;

    static void Init(int theater);
    static int Find_Index(char const * name);
    static SmudgeTypeClass * From_Name(char const * name);

    int ArrayIndex;                             // +0x264
    int Width;                                  // +0x268
    int Height;                                 // +0x26c
    bool IsCrater;                              // +0x270
    bool IsBurn;                                // +0x271
};

extern DynamicVectorClass<SmudgeTypeClass *> SmudgeTypes;      // 0xa28808

// ---- end of local declarations ----

SmudgeTypeClass::SmudgeTypeClass(char const * ini_name) :
    ObjectTypeClass(ini_name),
    ArrayIndex(-1),
    Width(1),
    Height(1),
    IsCrater(false),
    IsBurn(false)
{
    Create_ID();
    IsFlag1FF = true;
    IsFlag200 = false;
    IsFlag201 = false;
    IsFlag202 = true;
    IsFlag203 = true;
    IsFlag205 = false;
    SmudgeTypes.Add(this);
    ArrayIndex = SmudgeTypes.ID(this);
}

SmudgeTypeClass::SmudgeTypeClass(NoInitClass const & x) : ObjectTypeClass(x)
{
}

SmudgeTypeClass::~SmudgeTypeClass()
{
    Detach_This_From_All(this, true);
    SmudgeTypes.Delete(this);
}

int SmudgeTypeClass::Find_Index(char const * name)
{
    if (name != NULL) {
        for (int index = 0; index < SmudgeTypes.Count(); index++) {
            if (stricmp(SmudgeTypes[index]->ID, name) == 0) {
                return index;
            }
        }
    }
    return -1;
}

void SmudgeTypeClass::Init(int theater)
{
    if (!ForceTheaterReload && theater == LastTheater) {
        return;
    }
    for (int index = 0; index < SmudgeTypes.Count(); index++) {
        SmudgeTypeClass * smudge = SmudgeTypes[index];
        if (smudge->IsTheater) {
            char fullname[512];
            _makepath(fullname, NULL, NULL, smudge->ID, TheaterSuffixes[theater].Suffix);
            smudge->Image = MFCD::Retrieve(fullname);
        }
    }
}

bool SmudgeTypeClass::Create_And_Place(CellStruct const & cell, HouseClass *) const
{
    if (new SmudgeClass(this, CoordStruct(cell.X * 256 + 128, cell.Y * 256 + 128, 0))) {
        return true;
    }
    return false;
}

ObjectClass * SmudgeTypeClass::Create_One_Of(HouseClass *) const
{
    return (ObjectClass *)new SmudgeClass(this, EmptyCoord);
}

bool SmudgeTypeClass::Read_INI(CCINIClass & ini)
{
    if (ObjectTypeClass::Read_INI(ini)) {
        IsCrater = ini.Get_Bool(ID, "Crater", IsCrater);
        IsBurn = ini.Get_Bool(ID, "Burn", IsBurn);
        Width = ini.Get_Int(ID, "Width", Width);
        Height = ini.Get_Int(ID, "Height", Height);
        char fullname[512];
        if (!IsTheater) {
            _makepath(fullname, NULL, NULL, GraphicName, ".SHP");
        } else {
            _makepath(fullname, NULL, NULL, GraphicName, TheaterSuffixes[Scen->Theater].Suffix);
        }
        Image = MFCD::Retrieve(fullname);
        return true;
    }
    return false;
}

void SmudgeTypeClass::Compute_CRC(CRCEngine & crc) const
{
    ObjectTypeClass::Compute_CRC(crc);
    crc(ArrayIndex);
    crc(IsCrater);
    crc(IsBurn);
    crc(Width);
    crc(Height);
}

HRESULT __stdcall SmudgeTypeClass::Load(IStream * pStm)
{
    HRESULT hr = ObjectTypeClass::Load(pStm);
    if (SUCCEEDED(hr)) {
        new (this) SmudgeTypeClass(NoInitClass());
        Load_Fixup_5CEDC0();
        Load_Fixup_5CFCC0();
        hr = S_OK;
    }
    return hr;
}

HRESULT __stdcall SmudgeTypeClass::Save(IStream * pStm, BOOL fClearDirty)
{
    HRESULT hr = ObjectTypeClass::Save(pStm, fClearDirty);
    if (SUCCEEDED(hr)) {
        hr = S_OK;
    }
    return hr;
}

HRESULT __stdcall SmudgeTypeClass::GetClassID(CLSID * pClassID)
{
    if (pClassID == NULL) {
        return E_POINTER;
    }
    *pClassID = __uuidof(SmudgeTypeClass);
    return S_OK;
}

SmudgeTypeClass * SmudgeTypeClass::From_Name(char const * name)
{
    if (stricmp("<none>", name) == 0 || stricmp("none", name) == 0) {
        return NULL;
    }
    for (int index = 0; index < SmudgeTypes.Count(); index++) {
        if (stricmp(SmudgeTypes[index]->ID, name) == 0) {
            return SmudgeTypes[index];
        }
    }
    return new SmudgeTypeClass(name);
}

int SmudgeTypeClass::Kind_Of() const
{
    return 0x1E;
}

int SmudgeTypeClass::Size_Of() const
{
    return sizeof(*this);
}

int SmudgeTypeClass::Array_Index() const
{
    return ArrayIndex;
}
