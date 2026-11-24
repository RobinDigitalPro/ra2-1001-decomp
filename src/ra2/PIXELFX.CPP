// file name inferred from class name; not proven by a C:\RA2 string
// PIXELFX.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Pixel effect: a colour that fades between two RGB triples with a random offset and lifetime.
// RTTI .?AVPixelFXClass@@, vtable 0x79313c (one slot: scalar deleting dtor 0x606900).
// Code range 0x606700..0x60691f; PK.CPP (PKey) follows at 0x606920.
// The type table at 0x7d5958 (0x28-byte records) and all member names are provisional.
#include <stdlib.h>

// ---- local declarations (to be moved to headers by the integrator) ----

// One pixel effect type, 0x28 bytes (provisional field names).
struct PixelFXTypeStruct {
    int Red1;                   // +0x00 start colour
    int Green1;                 // +0x04
    int Blue1;                  // +0x08
    int Red2;                   // +0x0c end colour
    int Green2;                 // +0x10
    int Blue2;                  // +0x14
    int RandomBits;             // +0x18 random darkening, bits per component (0 = none)
    int LifeMask;               // +0x1c lifetime = rand() & LifeMask
    unsigned MaxRate;           // +0x20
    unsigned MinRate;           // +0x24
};
extern PixelFXTypeStruct PixelFXTypes[];        // 0x7d5958 (.data)

class PixelFXClass {
public:
    void Init(int type);
    PixelFXClass();
    PixelFXClass(int type);
    void AI(int frames);
    bool Age(int frames);
    void Set_Offset(int x, int y);
    virtual ~PixelFXClass();

    int Red;                    // +0x04 current colour
    int Green;                  // +0x08
    int Blue;                   // +0x0c
    int Phase;                  // +0x10 0..0x2000, 0x1000 = end colour
    int Rate;                   // +0x14
    int Red1;                   // +0x18
    int Green1;                 // +0x1c
    int Blue1;                  // +0x20
    int Red2;                   // +0x24
    int Green2;                 // +0x28
    int Blue2;                  // +0x2c
    int OffsetX;                // +0x30
    int OffsetY;                // +0x34
    int Life;                   // +0x38
};

// ---- end of local declarations ----

// 0x606700
void PixelFXClass::Init(int type)
{
    PixelFXTypeStruct const * fx = &PixelFXTypes[type];

    unsigned random = rand();
    OffsetX = (random & 0x3f) - 0x1f;
    OffsetY = ((random >> 5) & 0x1f) - 0xf;

    Red1 = fx->Red1;
    Green1 = fx->Green1;
    Blue1 = fx->Blue1;
    if (fx->RandomBits != 0) {
        int mask = (1 << fx->RandomBits) - 1;
        random = rand();
        Red1 -= random & mask;
        random >>= fx->RandomBits;
        Green1 -= random & mask;
        random >>= fx->RandomBits;
        Blue1 -= random & mask;
    }

    Red = Red2 = fx->Red2;
    Green = Green2 = fx->Green2;
    Blue = Blue2 = fx->Blue2;
    Phase = 0;
    unsigned range = fx->MaxRate - fx->MinRate + 1;
    Rate = rand() % range + fx->MinRate;
    Life = rand() & fx->LifeMask;
}

// 0x6067d0
PixelFXClass::PixelFXClass()
{
    Init(0);
}

// 0x6067f0
PixelFXClass::PixelFXClass(int type)
{
    Init(type);
}

// 0x606810
void PixelFXClass::AI(int frames)
{
    Phase += Rate * frames;
    if (Phase > 0x2000) {
        Phase = 0x2000;
    }

    int fraction = Phase & 0xfff;
    if (Phase & 0x1000) {
        fraction = 0x1000 - fraction;
    }

    Red = (Red2 * (0x1000 - fraction) + Red1 * fraction) >> 12;
    Green = (Green2 * (0x1000 - fraction) + Green1 * fraction) >> 12;
    Blue = (Blue2 * (0x1000 - fraction) + Blue1 * fraction) >> 12;
}

// 0x6068a0
bool PixelFXClass::Age(int frames)
{
    Life -= frames;
    if (Life <= 0) {
        Life = 0;
        return true;
    }
    return false;
}

// 0x6068d0
void PixelFXClass::Set_Offset(int x, int y)
{
    OffsetX = x;
    OffsetY = y;
}

// 0x6068f0
PixelFXClass::~PixelFXClass()
{
}
