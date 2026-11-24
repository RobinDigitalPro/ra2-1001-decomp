// unidentified translation unit (GAMECONST.H initializers at 0x2166b0) (level-2 reconstruction of GAME.EXE 1.001)
// Loading-screen progress display: ProgressScreenClass (RTTI name, one virtual slot inherited from
// INoticeSource) and its global instance. All other names are provisional.
#include "../RECT.H"
static RectangleStruct const ZeroRectA(0, 0, 0, 0);
#include "../GAMECONST.H"
#include "../VECTOR.H"
#include "../SURFACE.H"
#include <string.h>

// ---- local declarations (to be moved to headers by the integrator) ----

class ColorScheme {
public:
    static ColorScheme * Find(char const * name, int shades);  // 0x65ace0
};
extern DynamicVectorClass<ColorScheme *> ColorSchemes;   // 0xa9ea00

extern Surface * HiddenSurface;                         // 0x821c94
void * Load_File_Data(char const * name, bool & allocated);   // 0x495050
void * Side_Flag_Image(int side);                        // 0x4d0b50 (returns a Surface)
void Set_Load_Palette(void * palette, bool redraw);      // 0x515020 (fastcall; name provisional)

struct MPPlayerNode {
    int Color() const;                                   // 0x664e90
};

class SessionClass {
public:
    int Player_Color(int color);                         // 0x667a20
    char Pad[0x27e0];
    DynamicVectorClass<MPPlayerNode *> Players;          // +0x27e0 (0xa27da8)
};
extern SessionClass Session;                             // 0xa255c8

// Shape file header: frame count at +6, 24-byte frame records from +8.
struct ShapeFrameStruct {
    short X;
    short Y;
    short Width;
    short Height;
    char Pad[16];
};

struct ShapeFileStruct {
    short Unknown0;
    short Width;
    short Height;
    short Frames;
    ShapeFrameStruct * Get_Frame_Data(int frame)          // 0x217fa0
    {
        if ((unsigned)frame < (unsigned)Frames) {
            return &((ShapeFrameStruct *)(this + 1))[frame];
        }
        return 0;
    }
};

// INoticeSource's single slot here is a thiscall with one argument (0x217f90), unlike the
// __stdcall no-argument declaration in COM.H.
class ProgressScreenClass {
public:
    ProgressScreenClass();
    ~ProgressScreenClass();
    virtual void Set_Notice(int value);

    void Init(int x48, int x4c, int count, void * x64);
    void Deactivate(void);
    void Free_Shape(void);
    void Set_Side(int side);
    int Get_Side(void) const;
    ColorScheme * Text_Scheme(void) const;
    ColorScheme * Bar_Scheme(void) const;
    ColorScheme * Player_Scheme(int index);
    void Set_Shape(char const * name, void * palette, int x74);
    void Set_X78(int value);
    void Shape_Size(int & width, int & height);
    void Flag_Size(int & width, int & height);
    bool Has_X64(void) const;
    void Clear_X64(void);

    int Notice;                     // +0x04
    struct BarStruct {
        int A;
        int B;
    } Bars[8];                      // +0x08
    int X48;                        // +0x48
    int X4C;                        // +0x4c
    int X50;                        // +0x50
    ShapeFileStruct * Shape;        // +0x54
    bool IsShapeAllocated;          // +0x58
    void * Palette;                 // +0x5c
    bool IsActive;                  // +0x60
    char Count;                     // +0x61
    char X62;                       // +0x62
    void * X64;                     // +0x64
    int X68;                        // +0x68
    int X6C;                        // +0x6c
    bool X70;                       // +0x70
    bool X71;                       // +0x71
    int X74;                        // +0x74
    int X78;                        // +0x78
    int X7C;                        // +0x7c
    int Side;                       // +0x80
};

// ---- end of local declarations ----

ProgressScreenClass ProgressScreen;     // 0xa5e540



ProgressScreenClass::~ProgressScreenClass()
{
    Free_Shape();
}

void ProgressScreenClass::Init(int x48, int x4c, int count, void * x64)
{
    X48 = x48;
    X4C = x4c;
    Count = (char)(count > 1 ? count : 1);
    for (int index = 0; index < Count; index++) {
        BarStruct & bar = Bars[index];
        bar.A = 0;
        bar.B = 0;
    }
    IsActive = true;
    if (x64 != 0) {
        X64 = x64;
    } else {
        HiddenSurface->Fill(0);
    }
    X50 = 0;
    X7C = -1;
}

void ProgressScreenClass::Deactivate(void)
{
    IsActive = false;
}

void ProgressScreenClass::Free_Shape(void)
{
    if (IsShapeAllocated) {
        delete Shape;
        IsShapeAllocated = false;
    }
    Shape = 0;
}

void ProgressScreenClass::Set_Side(int side)
{
    Side = side;
}

int ProgressScreenClass::Get_Side(void) const
{
    return Side;
}

ColorScheme * ProgressScreenClass::Text_Scheme(void) const
{
    if (Side == 0) {
        return ColorScheme::Find("AlliedLoad", 1);
    }
    return ColorScheme::Find("SovietLoad", 1);
}

ColorScheme * ProgressScreenClass::Bar_Scheme(void) const
{
    if (Side == 0) {
        return ColorScheme::Find("AlliedLoad", 1);
    }
    return ColorScheme::Find("SovietLoad", 1);
}

ColorScheme * ProgressScreenClass::Player_Scheme(int index)
{
    ColorScheme * scheme = 0;
    if (index >= 0 && index < 8) {
        scheme = ColorSchemes[Session.Player_Color(Session.Players[index]->Color())];
    }
    return scheme;
}

void ProgressScreenClass::Set_Shape(char const * name, void * palette, int x74)
{
    if (name != 0) {
        if (Shape != 0) {
            Free_Shape();
        }
        Shape = (ShapeFileStruct *)Load_File_Data(name, IsShapeAllocated);
        if (Shape != 0) {
            if (palette != 0) {
                Palette = palette;
                Set_Load_Palette(palette, false);
            }
            X74 = x74;
        }
    }
}

void ProgressScreenClass::Set_X78(int value)
{
    X78 = value;
}

void ProgressScreenClass::Shape_Size(int & width, int & height)
{
    RectangleStruct rect;
    ShapeFrameStruct * frame = Shape->Get_Frame_Data(0);
    if (frame != 0) {
        rect = RectangleStruct(frame->X, frame->Y, frame->Width, frame->Height);
    } else {
        rect = ZeroRectA;
    }
    width = rect.Width + 6;
    height = rect.Height + 6;
}

void ProgressScreenClass::Flag_Size(int & width, int & height)
{
    Surface * flag = (Surface *)Side_Flag_Image(0);
    if (flag == 0) {
        width = 0;
        height = 0;
        return;
    }
    width = flag->Get_Width();
    height = flag->Get_Height();
}

bool ProgressScreenClass::Has_X64(void) const
{
    return X64 != 0;
}

void ProgressScreenClass::Clear_X64(void)
{
    X64 = 0;
}

void ProgressScreenClass::Set_Notice(int value)
{
    Notice = value;
}
