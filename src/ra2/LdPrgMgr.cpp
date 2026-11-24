// C:\RA2\LdPrgMgr.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Load progress manager: builds the loading screen (campaign briefing image and texts, or the
// multiplayer side picture with country, unit and briefing texts) in its own BSurface and copies
// it to the primary surface when notified. The class name comes from RTTI (.?AVLoadProgressMgr@@ :
// INoticeSink, vtable 0x79047c); all other names are provisional.
#include "GAMECONST.H"
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include "RECT.H"
#include "SURFACE.H"
#include "VECTOR.H"
#include "BLIT.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60

// Colours (see CampScor.cpp / MPScore.cpp). The RGBClass constructor is inline; GAME.EXE keeps an
// out-of-line copy at 0x432c30 that is called where VC6 stops inlining.
struct RGBClass {
    RGBClass() {}
    RGBClass(unsigned char red, unsigned char green, unsigned char blue) : Red(red), Green(green), Blue(blue) {}
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
};
class HSVClass {
public:
    RGBClass To_RGB() const;                // 0x4fe550
    unsigned char Hue;
    unsigned char Saturation;
    unsigned char Value;
};
// RTTI .?AVColorScheme@@ (vector element type); only the field used here.
class ColorScheme {
public:
    char Unknown0[0x308];
    HSVClass BaseColor;                     // +0x308
};
extern RGBClass BlackColor;                 // 0xa9e361 (zeroed by an initializer at 0x633f50)

// 16-bit pixel <-> RGB conversion with the shifts of BLIT.H (BlitFormat, 0x83b2e8).
inline unsigned RGB_To_Pixel(int red, int green, int blue)
{
    return ((red >> BlitFormat.RedShiftLeft) << BlitFormat.RedShiftRight)
        | ((green >> BlitFormat.GreenShiftLeft) << BlitFormat.GreenShiftRight)
        | ((blue >> BlitFormat.BlueShiftLeft) << BlitFormat.BlueShiftRight);
}
inline unsigned RGB_To_Pixel(RGBClass rgb)
{
    return RGB_To_Pixel(rgb.Red, rgb.Green, rgb.Blue);
}
inline RGBClass Pixel_To_RGB(unsigned short pixel)   // out-of-line copy 0x5350b0
{
    return RGBClass((unsigned char)((pixel >> BlitFormat.RedShiftRight) << BlitFormat.RedShiftLeft),
        (unsigned char)((pixel >> BlitFormat.GreenShiftRight) << BlitFormat.GreenShiftLeft),
        (unsigned char)((pixel >> BlitFormat.BlueShiftRight) << BlitFormat.BlueShiftLeft));
}
inline int RGB_Value(RGBClass const & rgb)
{
    return (((rgb.Blue << 8) | rgb.Green) << 8) | rgb.Red;
}

// RTTI .?AVBitFont@@ (vtable 0x787788).
class BitFont {
public:
    virtual ~BitFont();
    int Get_Text_Size(wchar_t const * text, int * width, int * height, int max_width);  // 0x431370
};
extern BitFont * TextFont;                  // 0x836d30 (provisional)

// Wide text printer (0x5f5d00, __fastcall, ret 0x20). Parameter names provisional.
int Print_Text(Surface * surface, wchar_t const * text, RectangleStruct & rect, BitFont * font,
    int rgb, int justify, int unknown1, int unknown2, int unknown3, int unknown4);
// Variadic text printer (cdecl, 0x497920); see Egos.CPP (declared there with char const *).
Point2D __cdecl Fancy_Text_Print(wchar_t const * text, Surface * surface, RectangleStruct const & rect,
    Point2D const & xy, ColorScheme * fore, unsigned back, int flags, ...);
void Draw_Score_Frame(RectangleStruct & rect, Surface * surface, int a, int b);  // 0x5f6840
void Inflate_Rect(RectangleStruct & rect, int amount);                          // 0x6e6be0 (X,Y += amount, W,H -= 2*amount)
Point2D Rect_XY(RectangleStruct const & rect);                                  // 0x6e6bc0

// Shape drawing (0x49ebd0); see Power.CPP.
class ConvertClass;
void CC_Draw_Shape(Surface * surface, ConvertClass * convert, void const * shape, int frame,
    Point2D const * point, RectangleStruct const * window, int flags, int arg8, int arg9, int arg10,
    int arg11, int arg12, int arg13, Point2D offset);
void * Load_File_Data(char const * filename, bool & allocated);  // 0x495050

// Mix files (RTTI .?AVMixFileClass@@, vtable 0x791458: scalar deleting destructor).
class PKey;
extern PKey FastKey;                        // 0x821350 (provisional)
class MixFileClass {
public:
    MixFileClass(char const * filename, PKey const * key);  // 0x5920f0
    virtual ~MixFileClass();
    char Unknown04[0x28 - 4];
};

// Loading screen resources (provisional names; module at 0x6e74e0..0x6e76c0).
char const * Load_Screen_Title_Name(int width, int height, int side);   // 0x6e74e0
char const * Load_Screen_Bar_Name(int width, int height, int side);     // 0x6e7500
ConvertClass * Load_Screen_Title_Drawer();                              // 0x6e7530
ConvertClass * Load_Screen_Image_Drawer();                              // 0x6e7550
ConvertClass * Load_Screen_Bar_Drawer();                                // 0x6e7570
void Load_Screen_Campaign_Init(int flag);                               // 0x6e7580
ConvertClass * Load_Screen_MP_Drawer();                                 // 0x6e7690
void Load_Screen_MP_Init();                                             // 0x6e76a0
void Load_Screen_Campaign_Free();                                       // 0x6e75f0
void Load_Screen_MP_Free();                                             // 0x6e76c0

// Player side information (object 0xa5e540; side index at +0x80). Provisional.
class PlayerSideClass {
public:
    int Get_Side() const;                   // 0x616a30
    ColorScheme * Text_Scheme() const;      // 0x616a40
    ColorScheme * Brief_Scheme() const;     // 0x616a70
};
extern PlayerSideClass PlayerSide;          // 0xa5e540

// Multiplayer player list (see MPSiegeTeam.cpp).
class MPPlayerNode {
public:
    int Side() const;                       // 0x664e80: +0x49 unless +0x4d is -2
};
extern DynamicVectorClass<MPPlayerNode *> MPPlayers;   // 0xa27da8

class ScenarioClass {
public:
    char Unknown0[0x2239];
    bool Field2239;                         // +0x2239, meaning unknown
    char Unknown223A[0x2390 - 0x223a];
    char BriefTitle[0x1f];                  // +0x2390, string table label
    char BriefText[0x21];                   // +0x23af, string table label
    Point2D BriefPos640;                    // +0x23d0
    Point2D BriefPos800;                    // +0x23d8
    char Image640[0x40];                    // +0x23e0, loading screen image (640x480)
    char Image800[0x40];                    // +0x2420, loading screen image (800x600 and up)
};
extern ScenarioClass * Scen;                // 0xa255c0

class SessionClass {
public:
    int Type;                               // +0x00: 0 = campaign (provisional)
};
extern SessionClass Session;                // 0xa255c8

extern Surface * HiddenSurface;            // 0x821c94
extern int ScreenWidth;                     // 0x83a710
extern int ScreenHeight;                    // 0x83a714
extern int const LoadScreenWidths[3];       // 0x798bfc {640, 800, 1024} (provisional)
extern int const LoadScreenHeights[3];      // 0x798c08 {480, 600, 768} (provisional)

// RTTI .?AVINoticeSink@@ (vtable 0x785e44, one pure slot).
class INoticeSink {
public:
    virtual bool Notice(int id, void * data) = 0;
};

// ---- end of local declarations ----

class LoadProgressMgr : public INoticeSink {
public:
    LoadProgressMgr();

    virtual bool Notice(int id, void * data);

    void Calc_Rects();
    Point2D Bar_Position();
    void Init();
    void Draw_It();
    void Blit_To(::Surface & dest);
    void Free();

    MixFileClass * LoadMix;         // +0x04
    RectangleStruct TitleRect;      // +0x08
    RectangleStruct ImageRect;      // +0x18
    RectangleStruct BarRect;        // +0x28
    wchar_t const * BriefTitle;     // +0x38
    wchar_t const * BriefText;      // +0x3c
    void * TitleShape;              // +0x40
    void * ImageShape;              // +0x44
    void * BarShape;                // +0x48
    bool TitleAllocated;            // +0x4c
    bool ImageAllocated;            // +0x4d
    bool BarAllocated;              // +0x4e
    int Field50;                    // +0x50
    int Field54;                    // +0x54
    int Field58;                    // +0x58
    BSurface * Surface;             // +0x5c
};

#define NOTICE_LOAD_PROGRESS    0x11ae

LoadProgressMgr * LoadProgress;     // 0xa563f4

// Loading screen picture names (.data 0x7c9fc8..0x7c9ff0, in this definition order).
char * LoadScreenBritain = "ls%sukingdom.shp";
char * LoadScreenCuba = "ls%scuba.shp";
char * LoadScreenFrance = "ls%sfrance.shp";
char * LoadScreenGermany = "ls%sgermany.shp";
char * LoadScreenIraq = "ls%siraq.shp";
char * LoadScreenKorea = "ls%skorea.shp";
char * LoadScreenLibya = "ls%slibya.shp";
char * LoadScreenRussia = "ls%srussia.shp";
char * LoadScreenUSA = "ls%sustates.shp";
char * LoadScreenRes640 = "640";
char * LoadScreenRes800 = "800";

LoadProgressMgr * Load_Progress_Init()
{
    if (LoadProgress == NULL) {
        LoadProgress = new LoadProgressMgr;
    }
    return LoadProgress;
}

void Load_Progress_Shutdown()
{
    if (LoadProgress != NULL) {
        LoadProgress->Free();
        delete LoadProgress;
    }
    LoadProgress = NULL;
}

LoadProgressMgr::LoadProgressMgr()
{
    LoadMix = NULL;
    BriefTitle = NULL;
    BriefText = NULL;
    TitleShape = NULL;
    ImageShape = NULL;
    BarShape = NULL;
    TitleAllocated = false;
    ImageAllocated = false;
    BarAllocated = false;
    Field50 = 0;
    Field54 = 0;
    Field58 = 0;
    Surface = NULL;
}

void LoadProgressMgr::Calc_Rects()
{
    bool is640 = (ScreenWidth == 640);
    int width = is640 ? LoadScreenWidths[0] : LoadScreenWidths[1];
    if (Session.Type == 0) {
        int height = (is640 ? LoadScreenHeights[0] : LoadScreenHeights[1]) - 80;
        int x = (ScreenWidth - width) / 2;
        int y = (ScreenHeight - height - 80) / 2;
        TitleRect.X = x;
        TitleRect.Y = y;
        TitleRect.Width = width;
        TitleRect.Height = 40;
        ImageRect.X = x;
        ImageRect.Y = y + 40;
        ImageRect.Width = width;
        ImageRect.Height = height;
        BarRect.X = x;
        BarRect.Y = y + 40 + height;
        BarRect.Width = width;
        BarRect.Height = 40;
    } else {
        int height = is640 ? LoadScreenHeights[0] : LoadScreenHeights[1];
        ImageRect.X = (ScreenWidth - width) / 2;
        ImageRect.Y = (ScreenHeight - height) / 2;
        ImageRect.Width = width;
        ImageRect.Height = height;
    }
}

Point2D LoadProgressMgr::Bar_Position()
{
    Point2D xy;
    if (Session.Type == 0) {
        if (ScreenWidth == LoadScreenWidths[0]) {
            return Point2D(BarRect.X + 0x54, BarRect.Y + 7);
        }
        return Point2D(BarRect.X + 0xa4, BarRect.Y + 7);
    }
    xy = Rect_XY(ImageRect);
    if (ScreenWidth == LoadScreenWidths[0]) {
        return Point2D(xy.X + 0xc, xy.Y + 0x100);
    }
    return Point2D(xy.X + 0x10, xy.Y + 0x141);
}

int Load_Progress_Bar_Width()
{
    int width = -1;
    if (Session.Type != 0) {
        width = (ScreenWidth == LoadScreenWidths[0]) ? 0x146 : 0x196;
    }
    return width;
}

void LoadProgressMgr::Init()
{
    if (LoadMix == NULL) {
        LoadMix = new MixFileClass("LOAD.MIX", &FastKey);
        if (LoadMix == NULL) {
            return;
        }
    }
    if (Session.Type == 0) {
        Load_Screen_Campaign_Init(!Scen->Field2239);
    } else {
        Load_Screen_MP_Init();
    }
}

static wchar_t const * Country_Name(int side)
{
#line 144 "C:\\RA2\\LdPrgMgr.cpp"
    if (side == 0) {
        return Fetch_String("Name:Americans", NULL, __FILE__, __LINE__);
    } else if (side == 1) {
        return Fetch_String("Name:Alliance", NULL, __FILE__, __LINE__);
    } else if (side == 2) {
        return Fetch_String("Name:French", NULL, __FILE__, __LINE__);
    } else if (side == 3) {
        return Fetch_String("Name:Germans", NULL, __FILE__, __LINE__);
    } else if (side == 4) {
        return Fetch_String("Name:British", NULL, __FILE__, __LINE__);
    } else if (side == 5) {
        return Fetch_String("Name:Africans", NULL, __FILE__, __LINE__);
    } else if (side == 6) {
        return Fetch_String("Name:Arabs", NULL, __FILE__, __LINE__);
    } else if (side == 7) {
        return Fetch_String("Name:Confederation", NULL, __FILE__, __LINE__);
    } else if (side == 8) {
        return Fetch_String("Name:Russians", NULL, __FILE__, __LINE__);
    }
    return NULL;
}

static RectangleStruct Country_Rect()
{
    RectangleStruct rect;
    if (ScreenWidth == LoadScreenWidths[0]) {
        rect = RectangleStruct(0x181, 0x1b4, 200, 20);
    } else {
        rect = RectangleStruct(0x215, 0x221, 200, 20);
    }
    if (ScreenWidth >= LoadScreenWidths[1]) {
        rect.X += (ScreenWidth - LoadScreenWidths[1]) / 2;
        rect.Y += (ScreenHeight - LoadScreenHeights[1]) / 2;
    }
    return rect;
}

static wchar_t const * Unit_Name(int side)
{
#line 206 "C:\\RA2\\LdPrgMgr.cpp"
    if (side == 0) {
        return Fetch_String("Name:Para", NULL, __FILE__, __LINE__);
    } else if (side == 1) {
        return Fetch_String("Name:BEAGLE", NULL, __FILE__, __LINE__);
    } else if (side == 2) {
        return Fetch_String("Name:GTGCAN", NULL, __FILE__, __LINE__);
    } else if (side == 3) {
        return Fetch_String("Name:TNKD", NULL, __FILE__, __LINE__);
    } else if (side == 4) {
        return Fetch_String("Name:SNIPE", NULL, __FILE__, __LINE__);
    } else if (side == 5) {
        return Fetch_String("Name:DTRUCK", NULL, __FILE__, __LINE__);
    } else if (side == 6) {
        return Fetch_String("Name:DESO", NULL, __FILE__, __LINE__);
    } else if (side == 7) {
        return Fetch_String("Name:TERROR", NULL, __FILE__, __LINE__);
    } else if (side == 8) {
        return Fetch_String("Name:TTNK", NULL, __FILE__, __LINE__);
    }
    return NULL;
}

static RectangleStruct Unit_Rect()
{
    RectangleStruct rect;
    if (ScreenWidth == LoadScreenWidths[0]) {
        rect = RectangleStruct(0x10, 0x48, 200, 20);
    } else {
        rect = RectangleStruct(0x14, 0x5a, 200, 20);
    }
    if (ScreenWidth >= LoadScreenWidths[1]) {
        rect.X += (ScreenWidth - LoadScreenWidths[1]) / 2;
        rect.Y += (ScreenHeight - LoadScreenHeights[1]) / 2;
    }
    return rect;
}

static wchar_t const * Brief_Name(int side)
{
#line 255 "C:\\RA2\\LdPrgMgr.cpp"
    if (side == 0) {
        return Fetch_String("LoadBrief:USA", NULL, __FILE__, __LINE__);
    } else if (side == 1) {
        return Fetch_String("LoadBrief:Korea", NULL, __FILE__, __LINE__);
    } else if (side == 2) {
        return Fetch_String("LoadBrief:French", NULL, __FILE__, __LINE__);
    } else if (side == 3) {
        return Fetch_String("LoadBrief:Germans", NULL, __FILE__, __LINE__);
    } else if (side == 4) {
        return Fetch_String("LoadBrief:British", NULL, __FILE__, __LINE__);
    } else if (side == 5) {
        return Fetch_String("LoadBrief:Lybia", NULL, __FILE__, __LINE__);
    } else if (side == 6) {
        return Fetch_String("LoadBrief:Iraq", NULL, __FILE__, __LINE__);
    } else if (side == 7) {
        return Fetch_String("LoadBrief:Cuba", NULL, __FILE__, __LINE__);
    } else if (side == 8) {
        return Fetch_String("LoadBrief:Russia", NULL, __FILE__, __LINE__);
    }
    return NULL;
}

static void Upcase_Text(wchar_t * text)
{
    for (wchar_t * ptr = text; *ptr != 0; ptr++) {
        if ((*ptr >= L'a' && *ptr <= L'z') || (*ptr >= 0xe0 && *ptr <= 0xfe)) {
            *ptr -= 0x20;
        }
    }
}

RectangleStruct Brief_Rect();
RectangleStruct Loading_Rect();
void Draw_Text_Box(wchar_t const * text, Surface * surface, int x, int y, int width, int justify, bool full_width);
void Draw_Text(wchar_t const * text, Surface * surface, RectangleStruct const & rect, unsigned short pixel, int justify);

// Open (see the claims file): GAME.EXE stops inlining part-way through this function (Surface ctor
// 0x49eac0, RGBClass ctor 0x432c30, Pixel_To_RGB, Brief_Rect, Loading_Rect and the last two
// Draw_Text_Box/Draw_Text calls stay calls). This version reproduces that pattern up to the unit
// name; the briefing section is still inlined, and the frame is four bytes smaller than the original.
void LoadProgressMgr::Draw_It()
{
    bool is640 = (ScreenWidth == LoadScreenWidths[0]);
    Surface = new BSurface(ScreenWidth, ScreenHeight, 2);
    if (Surface == NULL) {
        return;
    }

    unsigned black = RGB_To_Pixel(BlackColor.Red, BlackColor.Green, BlackColor.Blue);
    RectangleStruct screen(0, 0, 0, 0);
    screen.Width = ScreenWidth;
    screen.Height = ScreenHeight;
    Surface->Fill_Rect(screen, screen, black);

    RectangleStruct rect;

    if (Session.Type == 0) {
        char const * image = is640 ? Scen->Image640 : Scen->Image800;
        if (*image != '\0') {
            BriefTitle = NULL;
            if (Scen->BriefTitle[0] != '\0') {
#line 569 "C:\\RA2\\LdPrgMgr.cpp"
                BriefTitle = Fetch_String(Scen->BriefTitle, NULL, __FILE__, __LINE__);
            }
            BriefText = NULL;
            if (Scen->BriefText[0] != '\0') {
#line 573 "C:\\RA2\\LdPrgMgr.cpp"
                BriefText = Fetch_String(Scen->BriefText, NULL, __FILE__, __LINE__);
            }

            int side = PlayerSide.Get_Side();
            char const * title = Load_Screen_Title_Name(ScreenWidth, ScreenHeight, side);
            char const * bar = Load_Screen_Bar_Name(ScreenWidth, ScreenHeight, side);
            TitleShape = Load_File_Data(title, TitleAllocated);
            BarShape = Load_File_Data(bar, BarAllocated);
            ImageShape = Load_File_Data(image, ImageAllocated);
            ConvertClass * title_drawer = Load_Screen_Title_Drawer();
            ConvertClass * image_drawer = Load_Screen_Image_Drawer();
            ConvertClass * bar_drawer = Load_Screen_Bar_Drawer();

            Point2D xy(TitleRect.X, TitleRect.Y);
            if (TitleShape != NULL) {
                CC_Draw_Shape(Surface, title_drawer, TitleShape, 0, &xy, &screen, 0x400, 0, 0, 0, 1000, 0, 0, Point2D(0, 0));
            } else {
                Surface->Fill_Rect(screen, TitleRect, black);
            }
            xy.Y = ImageRect.Y;
            CC_Draw_Shape(Surface, image_drawer, ImageShape, 0, &xy, &screen, 0x400, 0, 0, 0, 1000, 0, 0, Point2D(0, 0));
            xy.Y = BarRect.Y;
            if (BarShape != NULL) {
                CC_Draw_Shape(Surface, bar_drawer, BarShape, 0, &xy, &screen, 0x400, 0, 0, 0, 1000, 0, 0, Point2D(0, 0));
            } else {
                Surface->Fill_Rect(screen, BarRect, black);
            }

            xy.X = TitleRect.X + 10;
            xy.Y = TitleRect.Y + 10;
            ColorScheme * scheme = PlayerSide.Text_Scheme();
            if (BriefTitle != NULL) {
                Fancy_Text_Print(BriefTitle, Surface, screen, xy, scheme, 0, 0x19);
            }
            if (BriefText != NULL) {
                if (is640) {
                    xy.X = Scen->BriefPos640.X + ImageRect.X;
                    xy.Y = Scen->BriefPos640.Y + ImageRect.Y;
                } else {
                    xy.X = Scen->BriefPos800.X + ImageRect.X;
                    xy.Y = Scen->BriefPos800.Y + ImageRect.Y;
                }
                wchar_t text[2044];
                wcscpy(text, BriefText);
                RGBClass rgb = scheme->BaseColor.To_RGB();
                unsigned color = RGB_To_Pixel(rgb);
                int width = 0;
                int height = 0;
                TextFont->Get_Text_Size(text, &width, &height, 400);
                rect = RectangleStruct(xy.X, xy.Y, width, height);
                Draw_Text_Box(text, Surface, xy.X, xy.Y, 400, 0, false);
                Draw_Text(text, Surface, rect, color, 0);
            }
        }
        return;
    }

    const int side = MPPlayers[0]->Side();
    char const * res = (ScreenWidth == LoadScreenWidths[0]) ? LoadScreenRes640 : LoadScreenRes800;
    char filename[32];
    if (side == 0) {
        sprintf(filename, LoadScreenUSA, res);
    } else if (side == 1) {
        sprintf(filename, LoadScreenKorea, res);
    } else if (side == 2) {
        sprintf(filename, LoadScreenFrance, res);
    } else if (side == 3) {
        sprintf(filename, LoadScreenGermany, res);
    } else if (side == 4) {
        sprintf(filename, LoadScreenBritain, res);
    } else if (side == 5) {
        sprintf(filename, LoadScreenLibya, res);
    } else if (side == 6) {
        sprintf(filename, LoadScreenIraq, res);
    } else if (side == 7) {
        sprintf(filename, LoadScreenCuba, res);
    } else if (side == 8) {
        sprintf(filename, LoadScreenRussia, res);
    }
    ImageShape = Load_File_Data(filename, ImageAllocated);
    ConvertClass * drawer = Load_Screen_MP_Drawer();
    Point2D xy = Rect_XY(ImageRect);
    CC_Draw_Shape(Surface, drawer, ImageShape, 0, &xy, &screen, 0x400, 0, 0, 0, 1000, 0, 0, Point2D(0, 0));

    ColorScheme * brief_scheme = PlayerSide.Brief_Scheme();
    RGBClass rgb = brief_scheme->BaseColor.To_RGB();
    unsigned color = RGB_To_Pixel(rgb);

    wchar_t const * country = Country_Name(side);
    rect = Country_Rect();
    Draw_Text_Box(country, Surface, rect.X, rect.Y, rect.Width, 2, false);
    Draw_Text(country, Surface, rect, color, 2);

    wchar_t unit[128];
    wcscpy(unit, Unit_Name(side));
    Upcase_Text(unit);
    rect = Unit_Rect();
    Draw_Text(unit, Surface, rect, RGB_To_Pixel(BlackColor.Red, BlackColor.Green, BlackColor.Blue), 0);

    wchar_t const * brief = Brief_Name(side);
    rect = Brief_Rect();
    xy = Rect_XY(rect);
    Draw_Text_Box(brief, Surface, xy.X, xy.Y, rect.Width, 0, true);
    Draw_Text(brief, Surface, rect, color, 0);

#line 714 "C:\\RA2\\LdPrgMgr.cpp"
    wchar_t const * loading = Fetch_String("GUI:LoadingEx", NULL, __FILE__, __LINE__);
    rect = Loading_Rect();
    xy = Rect_XY(rect);
    Draw_Text_Box(loading, Surface, xy.X, xy.Y, rect.Width, 0, false);
    Draw_Text(loading, Surface, rect, color, 0);
}

RectangleStruct Brief_Rect()
{
    RectangleStruct rect;
    if (ScreenWidth == LoadScreenWidths[0]) {
        rect = RectangleStruct(0x10, 0x7e, 0x13e, 0x68);
    } else {
        rect = RectangleStruct(0x14, 0x9e, 0x18e, 0x82);
    }
    if (ScreenWidth >= LoadScreenWidths[1]) {
        rect.X += (ScreenWidth - LoadScreenWidths[1]) / 2;
        rect.Y += (ScreenHeight - LoadScreenHeights[1]) / 2;
    }
    return rect;
}

RectangleStruct Loading_Rect()
{
    RectangleStruct rect;
    if (ScreenWidth == LoadScreenWidths[0]) {
        rect = RectangleStruct(0x10, 0xeb, 200, 20);
    } else {
        rect = RectangleStruct(0x14, 0x12c, 200, 20);
    }
    if (ScreenWidth >= LoadScreenWidths[1]) {
        rect.X += (ScreenWidth - LoadScreenWidths[1]) / 2;
        rect.Y += (ScreenHeight - LoadScreenHeights[1]) / 2;
    }
    return rect;
}

void Draw_Text_Box(wchar_t const * text, Surface * surface, int x, int y, int width, int justify, bool full_width)
{
    RectangleStruct rect;
    int w = 0;
    int h = 0;
    TextFont->Get_Text_Size(text, &w, &h, width);
    if (full_width) {
        w = width;
    }
    rect = RectangleStruct(x, y, w, h);
    if (justify & 1) {
        rect.X = x + (width - w) / 2;
    } else if (justify & 2) {
        rect.X = x - w + width;
    }
    Inflate_Rect(rect, -4);
    Draw_Score_Frame(rect, surface, 0, 0x9f);
}

void Draw_Text(wchar_t const * text, Surface * surface, RectangleStruct const & rect, unsigned short pixel, int justify)
{
    RectangleStruct area(rect.X, rect.Y, rect.X + rect.Width, rect.Y + rect.Height);
    RGBClass rgb = Pixel_To_RGB(pixel);
    Print_Text(surface, text, area, TextFont, RGB_Value(rgb), justify, 0xc, 0, 0, 0);
}

void LoadProgressMgr::Blit_To(::Surface & dest)
{
    if (Surface != NULL) {
        dest.Copy_From(*Surface, false, true);
    }
}

void LoadProgressMgr::Free()
{
    if (TitleAllocated && TitleShape != NULL) {
        delete TitleShape;
    }
    TitleShape = NULL;
    if (ImageAllocated && ImageShape != NULL) {
        delete ImageShape;
    }
    ImageShape = NULL;
    if (BarAllocated && BarShape != NULL) {
        delete BarShape;
    }
    BarShape = NULL;
    Load_Screen_Campaign_Free();
    Load_Screen_MP_Free();
    if (LoadMix != NULL) {
        delete LoadMix;
        LoadMix = NULL;
    }
    delete Surface;
    Surface = NULL;
}

bool LoadProgressMgr::Notice(int id, void *)
{
    if (id == NOTICE_LOAD_PROGRESS) {
        Blit_To(*HiddenSurface);
        return true;
    }
    return false;
}
