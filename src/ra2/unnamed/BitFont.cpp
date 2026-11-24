// BitFont translation unit 0x430ee0..0x432128 (level-2 reconstruction of GAME.EXE 1.001)
// file name inferred from class name; not proven by a C:\RA2 string
//
// Contents: the 16-bit bitmap font renderer (GAME.FNT). The class name comes from RTTI
// (.?AVBitFont@@ vtable 0x787788, one slot: the scalar deleting destructor 0x4320c0); all method,
// member and variable names are provisional. Font files have two header formats ("fonT" with a
// full 64K character index, "FoNt" with character ranges).
//
// TU span: 0x30ee0 (16-byte zeroing header initializer, .bss 0x836d08) .. 0x32128. The next
// initializer 0x32130 starts the BitText TU (unnamed/BitText.cpp).
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "../RECT.H"
#include "../SURFACE.H"
#include "../BLIT.H"

// ---- local declarations (to be moved to headers by the integrator) ----

// File classes (see unnamed/BFIOFILE.CPP); CCFileClass is 0x64 bytes.
class FileClass {
public:
    virtual ~FileClass();
    virtual char const * File_Name() const;
    virtual char const * Set_Name(char const * filename);
    virtual int Create();
    virtual int Delete();
    virtual bool Is_Available(int forced = false);
    virtual bool Is_Open() const;
    virtual int Open(char const * filename, int rights = 1);
    virtual int Open(int rights = 1);
    virtual long Read(void * buffer, long size);
    virtual long Seek(long pos, int dir = 1);
    virtual long Size();
    virtual long Write(void const * buffer, long size);
    virtual void Close();
    virtual unsigned long Get_Date_Time();
    virtual bool Set_Date_Time(unsigned long datetime);
    virtual void Error(int error, int canretry = false, char const * filename = NULL);
};
class CCFileClass : public FileClass {
public:
    CCFileClass(char const * filename);     // 0x468b70
    char Data[0x64 - 4];
};

// Colours (see Beacon.CPP / unnamed/TU_4B2C60.cpp).
struct RGBClass {
    RGBClass() {}
    RGBClass(unsigned char red, unsigned char green, unsigned char blue) : Red(red), Green(green), Blue(blue) {}
    void Adjust(int ratio, RGBClass const & rgb);   // 0x634310
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
};
extern RGBClass FadeColor;                  // 0xa9e369 (fade target; name provisional)

// ---- end of local declarations ----

static RectangleStruct const ZeroRect(0, 0, 0, 0);

// Loaded font data (0x24 bytes; names provisional).
struct FontHeader {
    int Field00;                // +0x00
    int BytesPerRow;            // +0x04
    int Height;                 // +0x08, rows per glyph
    int LineHeight;             // +0x0c
    int GlyphCount;             // +0x10
    int GlyphSize;              // +0x14, bytes per glyph (width byte + rows)
    unsigned short * Index;     // +0x18, 0x10000 entries, glyph number + 1 (0 = none)
    unsigned char * Data;       // +0x1c
    int Used;                   // +0x20, characters with a glyph
};

// "FoNt" range record (12 bytes).
struct FontRange {
    unsigned short First;       // first glyph number
    unsigned int Start;         // first character
    unsigned int End;           // last character
};

// "fonT" file header (0x1c bytes).
struct FontFileHeader1 {
    int ID;
    int Field00;
    int BytesPerRow;
    int Height;
    int LineHeight;
    int GlyphCount;
    int GlyphSize;
};

// "FoNt" file header (0x24 bytes).
struct FontFileHeader2 {
    int ID;
    int Field00;
    int BytesPerRow;
    int Height;
    int LineHeight;
    unsigned int RangeCount;
    int GlyphSize;
    int RangeOffset;
    int DataOffset;
};

class BitFont {
public:
    BitFont(char const * filename);
    virtual ~BitFont();

    static FontHeader * Load_Font(char const * filename);
    static void Free_Font(FontHeader * font);
    bool Load(char const * filename);
    unsigned short Set_Color(unsigned short color);
    unsigned short Set_Background(unsigned short color);
    bool Set_Clipping(bool on);
    void Set_Bounds(RECT const * rect);
    bool Set_Bold(bool on);
    bool String_Pixel_Rect(wchar_t const * text, int * width, int * height, int maxwidth);
    int String_Pixel_Width(wchar_t const * text, int maxwidth);
    int String_Pixel_Width_Bold(wchar_t const * text, int maxwidth);
    int Chars_That_Fit(wchar_t const * text, int maxwidth, int maxchars, int wrap);
    bool String_Pixel_Rect_Bold(wchar_t const * text, int * width, int * height, int maxwidth);
    int Set_Tab_Width(int width);
    void Set_Tab_Origin(int x);
    int Print_Char(wchar_t c, int x, int y, int color);
    int Print_Fade(wchar_t const * text, int x, int y, int maxchars, int fade);
    unsigned char const * Get_Char_Data(wchar_t c) const;
    void Build_Missing_Glyph();
    unsigned char const * Get_Missing_Data(unsigned short * color);
    void Widen_Space();
    void Widen_Spaces();
    bool Intersect(RECT & result, RECT const & rect1, RECT const & rect2);
    void Lock(Surface * surface);
    void Unlock(Surface * surface);
    int Get_Char_Width(wchar_t c);
    void Init();

    unsigned char const * Char_Data(wchar_t c) const
    {
        unsigned char const * data = NULL;
        if (Header) {
            unsigned int index = Header->Index[c];
            if (index) {
                data = Header->Data + Header->GlyphSize * (index - 1);
            }
        }
        return data;
    }

    FontHeader * Header;        // +0x04
    unsigned char * Missing;    // +0x08, inverted glyph for missing characters
    unsigned short * Buffer;    // +0x0c, locked surface
    int Pitch;                  // +0x10, in pixels
    int Unknown14;              // +0x14
    int BytesPerRow;            // +0x18
    int LineHeight;             // +0x1c
    int TabOrigin;              // +0x20
    unsigned short Color;       // +0x24
    unsigned short Background;  // +0x26
    int TabWidth;               // +0x28
    int Spacing;                // +0x2c
    RECT Bounds;                // +0x30
    bool IsBold;                // +0x40
    bool IsClipping;            // +0x41
};

inline RGBClass Pixel_To_RGB(unsigned short pixel)
{
    return RGBClass(
        (unsigned char)((unsigned short)(pixel >> BlitFormat.RedShiftRight) << BlitFormat.RedShiftLeft),
        (unsigned char)((unsigned short)(pixel >> BlitFormat.GreenShiftRight) << BlitFormat.GreenShiftLeft),
        (unsigned char)((unsigned short)(pixel >> BlitFormat.BlueShiftRight) << BlitFormat.BlueShiftLeft));
}

inline unsigned short RGB_To_Pixel16(RGBClass const & rgb)
{
    return (unsigned short)(((unsigned short)(rgb.Green >> BlitFormat.GreenShiftLeft) << BlitFormat.GreenShiftRight)
        | ((unsigned short)(rgb.Blue >> BlitFormat.BlueShiftLeft) << BlitFormat.BlueShiftRight)
        | ((unsigned short)(rgb.Red >> BlitFormat.RedShiftLeft) << BlitFormat.RedShiftRight));
}

// 0x430f00
BitFont::BitFont(char const * filename)
{
    Init();
    Header = Load_Font(filename);
    if (Header) {
        BytesPerRow = Header->BytesPerRow;
        LineHeight = Header->LineHeight;
        Build_Missing_Glyph();
    } else {
        Init();
    }
}

// 0x430fc0
BitFont::~BitFont()
{
    if (Missing) {
        free(Missing);
    }
    if (Header) {
        Free_Font(Header);
    }
}

// 0x431010
FontHeader * BitFont::Load_Font(char const * filename)
{
    FontFileHeader1 header1;
    FontFileHeader2 header2;
    FontHeader * font = NULL;
    FontRange * ranges;
    unsigned int range;

    CCFileClass * file = new CCFileClass(filename);
    if (file) {
        if (file->Is_Available() && file->Open()) {
            font = new FontHeader;
            if (font) {
                memset(font, 0, sizeof(FontHeader));
                font->Index = (unsigned short *)new char[0x20000];
                if (font->Index) {
                    memset(font->Index, 0, 0x20000);
                    if (file->Read(&header1, sizeof(header1)) == sizeof(header1)) {
                        if (header1.ID == 0x546e6f66) {
                            font->Height = header1.Height;
                            font->LineHeight = header1.LineHeight;
                            font->BytesPerRow = header1.BytesPerRow;
                            font->Field00 = header1.Field00;
                            font->GlyphSize = header1.GlyphSize;
                            font->GlyphCount = header1.GlyphCount;
                            if (file->Read(font->Index, 0x20000) == 0x20000) {
                                goto data;
                            }
                        } else if (header1.ID == 0x744e6f46) {
                            file->Seek(0, SEEK_SET);
                            if (file->Read(&header2, sizeof(header2)) == sizeof(header2)) {
                                font->LineHeight = header2.LineHeight;
                                font->BytesPerRow = header2.BytesPerRow;
                                font->GlyphSize = header2.GlyphSize;
                                font->Height = header2.Height;
                                font->Field00 = header2.Field00;
                                ranges = (FontRange *)malloc(header2.RangeCount * sizeof(FontRange));
                                if (ranges) {
                                    file->Seek(header2.RangeOffset, SEEK_SET);
                                    if (file->Read(ranges, header2.RangeCount * sizeof(FontRange)) == (long)(header2.RangeCount * sizeof(FontRange))) {
                                        font->GlyphCount = 0;
                                        for (range = 0; range < header2.RangeCount; range++) {
                                            unsigned short glyph = ranges[range].First;
                                            for (int c = ranges[range].Start; c <= (int)ranges[range].End; c++) {
                                                font->Index[c] = ++glyph;
                                                font->GlyphCount++;
                                            }
                                        }
                                        free(ranges);
                                        file->Seek(header2.DataOffset, SEEK_SET);
data:
                                        {
                                            int size = font->GlyphCount * font->GlyphSize;
                                            font->Used = 0;
                                            for (int index = 0; index < 0x10000; index++) {
                                                if (font->Index[index]) {
                                                    font->Used++;
                                                }
                                            }
                                            font->Data = new unsigned char[size];
                                            if (font->Data && file->Read(font->Data, size) == size) {
                                                delete file;
                                                return font;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (font->Index) {
                    delete [] font->Index;
                }
                if (font->Data) {
                    delete [] font->Data;
                }
                delete font;
                font = NULL;
            }
        }
        delete file;
    }
    return font;
}

// 0x431280
void BitFont::Free_Font(FontHeader * font)
{
    if (font->Index) {
        delete [] font->Index;
    }
    if (font->Data) {
        delete [] font->Data;
    }
    delete font;
}

// 0x4312b0
bool BitFont::Load(char const * filename)
{
    Header = Load_Font(filename);
    if (Header) {
        BytesPerRow = Header->BytesPerRow;
        LineHeight = Header->LineHeight;
        Build_Missing_Glyph();
        return true;
    }
    return false;
}

// 0x4312f0
unsigned short BitFont::Set_Color(unsigned short color)
{
    unsigned short old = Color;
    Color = color;
    return old;
}

// 0x431300 (returns the foreground colour, not the old background)
unsigned short BitFont::Set_Background(unsigned short color)
{
    Background = color;
    return Color;
}

// 0x431310
bool BitFont::Set_Clipping(bool on)
{
    bool old = IsClipping;
    IsClipping = on;
    return old;
}

// 0x431320
void BitFont::Set_Bounds(RECT const * rect)
{
    if (rect) {
        Bounds.left = rect->left;
        Bounds.top = rect->top;
        Bounds.right = rect->right;
        Bounds.bottom = rect->bottom;
    } else {
        Bounds.left = Bounds.top = Bounds.right = Bounds.bottom = 0;
    }
}

// 0x431360
bool BitFont::Set_Bold(bool on)
{
    bool old = IsBold;
    IsBold = on;
    return old;
}

// 0x431370: width of the widest line and total height; maxwidth (0 = none) wraps at the last space.
bool BitFont::String_Pixel_Rect(wchar_t const * text, int * width, int * height, int maxwidth)
{
    int maxw = 0;
    int h;
    if (Header && text) {
        int lineheight = LineHeight;
        int x = 0;
        int chars = 0;
        h = lineheight;
        wchar_t const * space = NULL;
        int spacewidth;
        wchar_t prev = 0;
        wchar_t c = *text++;
        while (c) {
            switch (c) {
                case '\r':
                case '\n':
                    if (prev != '\r') {
                        h += lineheight;
                        x = 0;
                        chars = 0;
                    }
                    break;

                case '\t':
                    x += TabWidth;
                    x -= x % TabWidth;
                    break;

                case ' ':
                    space = text;
                    spacewidth = maxw;
                    // fall through

                default:
                {
                    unsigned char const * data = Char_Data(c);
                    if (data == NULL && (data = Missing) == NULL) {
                        break;
                    }
                    int w = *data;
                    chars++;
                    x += Spacing + w;
                    if (maxwidth && x > maxwidth) {
                        if (space) {
                            if (chars > 1) {
                                text = space;
                                maxw = spacewidth;
                            }
                        } else if (chars > 1) {
                            x -= Spacing + w;
                            text--;
                            if (x > maxw) {
                                maxw = x;
                            }
                        }
                        h += lineheight;
                        x = 0;
                        chars = 0;
                        space = NULL;
                    } else if (x > maxw) {
                        maxw = x;
                    }
                    break;
                }
            }
            prev = c;
            c = *text++;
        }
        if (width) {
            *width = maxw;
        }
        if (height) {
            *height = h;
        }
        return true;
    }
    if (height) {
        *height = 0;
    }
    if (width) {
        *width = 0;
    }
    return false;
}

// 0x431550
int BitFont::String_Pixel_Width(wchar_t const * text, int maxwidth)
{
    int width;
    String_Pixel_Rect(text, &width, NULL, maxwidth);
    return width;
}

// 0x431570
int BitFont::String_Pixel_Width_Bold(wchar_t const * text, int maxwidth)
{
    int width;
    if (IsBold) {
        Spacing = 2;
        String_Pixel_Rect(text, &width, NULL, maxwidth);
        Spacing = 1;
        return width;
    }
    String_Pixel_Rect(text, &width, NULL, maxwidth);
    return width;
}

// 0x4315d0: number of characters that fit into maxwidth (wrap: stop at a line end and break at a space).
int BitFont::Chars_That_Fit(wchar_t const * text, int maxwidth, int maxchars, int wrap)
{
    int width = 0;
    int count = 0;
    if (Header && text) {
        wchar_t c = *text;
        while (c) {
            switch (c) {
                case '\t':
                    width += TabWidth;
                    width -= width % TabWidth;
                    break;

                case '\n':
                case '\r':
                    break;

                default:
                {
                    unsigned char const * data = Char_Data(c);
                    if (data == NULL && (data = Missing) == NULL) {
                        break;
                    }
                    width += Spacing + *data;
                    break;
                }
            }
            count++;
            if (width > maxwidth) {
                count--;
                if (wrap && c > ' ') {
                    text--;
                    int back = count;
                    while (back) {
                        if (*text <= ' ') {
                            break;
                        }
                        back--;
                        text--;
                    }
                    if (back) {
                        count = back;
                    }
                }
                return count;
            }
            if (maxchars && count == maxchars) {
                return count;
            }
            if (wrap && (c == '\r' || c == '\n')) {
                return count;
            }
            c = *++text;
        }
        return count;
    }
    return 0;
}

// 0x431720
bool BitFont::String_Pixel_Rect_Bold(wchar_t const * text, int * width, int * height, int maxwidth)
{
    if (IsBold) {
        Spacing = 2;
        bool result = String_Pixel_Rect(text, width, height, maxwidth);
        Spacing = 1;
        return result;
    }
    return String_Pixel_Rect(text, width, height, maxwidth);
}

// 0x431780
int BitFont::Set_Tab_Width(int width)
{
    int old = TabWidth;
    TabWidth = width;
    return old;
}

// 0x431790
void BitFont::Set_Tab_Origin(int x)
{
    TabOrigin = x;
}

#define FONT_PIXEL_CLIP(bit) \
    if (px >= clip.left && px <= clip.right && (bits & bit)) { \
        *dst = pixel; \
    } \
    dst++; \
    px++;

#define FONT_PIXEL(bit) \
    if (bits & bit) { \
        *dst = pixel; \
    } \
    dst++;



// 0x431b80: prints text; with fade, the first characters are drawn in the colour faded toward
// FadeColor (stronger toward the end) and the rest is only measured.
int BitFont::Print_Fade(wchar_t const * text, int x, int y, int maxchars, int fade)
{
    unsigned short oldcolor = Color;
    int index = 0;
    wchar_t c = *text++;
    if (c) {
        int left = fade - 1;
        int ratio = (9 - fade) * 31;
        do {
            if (fade) {
                if (index >= fade) {
                    Color = oldcolor;
                    int width;
                    String_Pixel_Rect(text, &width, NULL, 0);
                    return x + width;
                }
                if (left < 8) {
                    RGBClass rgb = Pixel_To_RGB(oldcolor);
                    rgb.Adjust(ratio, FadeColor);
                    Color = RGB_To_Pixel16(rgb);
                }
                index++;
                ratio += 31;
                left--;
            }
            if (c != '\r' && c != '\n') {
                x = Print_Char(c, x, y, -1);
            }
            if (maxchars && --maxchars == 0) {
                break;
            }
            c = *text++;
        } while (c);
    }
    Color = oldcolor;
    return x;
}

// 0x431d40
unsigned char const * BitFont::Get_Char_Data(wchar_t c) const
{
    return Char_Data(c);
}

// 0x431d80: builds the inverted 'X' glyph used for characters without a glyph.
void BitFont::Build_Missing_Glyph()
{
    Missing = (unsigned char *)malloc(Header->Height * Header->BytesPerRow + 2);
    if (Header) {
        unsigned char const * data = Char_Data('X');
        if (data) {
            unsigned char const * src = data + 1;
            *Missing = *data;
            unsigned char * dst = Missing + 1;
            for (unsigned int row = 0; row < (unsigned int)Header->Height; row++) {
                for (unsigned int col = 0; col < (unsigned int)Header->BytesPerRow; col++) {
                    *dst++ = (unsigned char)~*src++;
                }
            }
        }
    }
}

// 0x431e10
unsigned char const * BitFont::Get_Missing_Data(unsigned short * color)
{
    if (color) {
        *color ^= 0x5555;
    }
    return Missing;
}

// 0x431e30
void BitFont::Widen_Space()
{
    if (Header) {
        LineHeight++;
        (*(unsigned char *)Char_Data(' '))++;
    }
}

// 0x431e60
void BitFont::Widen_Spaces()
{
    if (Header) {
        LineHeight++;
        unsigned char * space = (unsigned char *)Char_Data(' ');
        unsigned char * wide = (unsigned char *)Char_Data(0x3000);
        if (wide) {
            if (space) {
                *wide = (unsigned char)(*space << 1);
            } else {
                *wide = *(unsigned char *)Header;
            }
        }
    }
}

// 0x431ec0
bool BitFont::Intersect(RECT & result, RECT const & rect1, RECT const & rect2)
{
    if (rect1.top > rect2.bottom || rect2.top > rect1.bottom || rect1.left > rect2.right || rect2.left > rect1.right) {
        result.left = 0;
        result.top = 0;
        result.right = -1;
        result.bottom = -1;
        return false;
    }
    result = rect1;
    if (result.top < rect2.top) {
        result.top = rect2.top;
    }
    if (result.left < rect2.left) {
        result.left = rect2.left;
    }
    if (result.bottom > rect2.bottom) {
        result.bottom = rect2.bottom;
    }
    if (result.right > rect2.right) {
        result.right = rect2.right;
    }
    return true;
}



// 0x432010
void BitFont::Unlock(Surface * surface)
{
    surface->Unlock();
    Buffer = NULL;
    Pitch = 0;
}

// 0x432030
int BitFont::Get_Char_Width(wchar_t c)
{
    unsigned char const * data = Char_Data(c);
    if (data) {
        return *data;
    }
    return 0;
}

// 0x432070
void BitFont::Init()
{
    Header = NULL;
    Color = 0x7fff;
    Background = 0x3555;
    TabWidth = 64;
    IsBold = true;
    IsClipping = true;
    BytesPerRow = 1;
    LineHeight = 1;
    TabOrigin = 0;
    Buffer = NULL;
    Missing = NULL;
    SetRect(&Bounds, 0, 0, 0, 0);
    Spacing = 1;
}
