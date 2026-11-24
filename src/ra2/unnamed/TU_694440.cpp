// unidentified translation unit (GAMECONST.H initializers at 0x294440) (level-2 reconstruction of GAME.EXE 1.001)
// Super weapon types: SuperWeaponTypeClass (RTTI name, vtable 0x797160). All other names are provisional.
// The range 0x294fa0..0x2958c0 belongs to another TU (SwizzleManagerClass, see the claims file).
#include "../RECT.H"
static RectangleStruct const ZeroRectA(0, 0, 0, 0);
#include "../GAMECONST.H"
#include "../ABSTYPE.H"
#include <string.h>

// ---- local declarations (to be moved to headers by the integrator) ----

// Fields as used here; Super.CPP declares the same class with other fields.
class SuperWeaponTypeClass : public AbstractTypeClass {
public:
    static int From_Name(char const * name);

    virtual int Kind_Of() const;
    virtual int Size_Of() const;
    virtual int Array_Index() const;
    virtual int Slot27(int arg1, int arg2) const;   // slot 27, returns +0xbc

    static char const * const Names[7];             // 0x7dfed8

    int ArrayIndex;                                 // +0x98
    char Unknown9C[0xbc - 0x9c];
    int FieldBC;                                    // +0xbc
    char UnknownC0[0xec - 0xc0];
};

// ---- end of local declarations ----

char const * const SuperWeaponTypeClass::Names[7] = {
    "MultiMissile",
    "IronCurtain",
    "LightningStorm",
    "ChronoSphere",
    "ChronoWarp",
    "ParaDrop",
    "AmerParaDrop"
};

int SuperWeaponTypeClass::From_Name(char const * name)
{
    for (int index = 0; index < 7; index++) {
        if (_stricmp(Names[index], name) == 0) {
            return index;
        }
    }
    return -1;
}

int SuperWeaponTypeClass::Kind_Of() const
{
    return 0x20;
}

int SuperWeaponTypeClass::Size_Of() const
{
    return sizeof(SuperWeaponTypeClass);
}

int SuperWeaponTypeClass::Array_Index() const
{
    return ArrayIndex;
}

int SuperWeaponTypeClass::Slot27(int, int) const
{
    return FieldBC;
}
