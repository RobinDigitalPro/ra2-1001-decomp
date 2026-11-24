// BitText translation unit 0x432130..0x432c8f (level-2 reconstruction of GAME.EXE 1.001)
// file name inferred from class name; not proven by a C:\RA2 string
//
// Contents: text output helpers on top of BitFont (word wrapping, alignment, bold, shadow and
// fade-out). The class name comes from RTTI (.?AVBitText@@ vtable 0x787790, one slot: the scalar
// deleting destructor 0x432be0); all method, member and variable names are provisional. The
// shared font object (GAME.FNT) is the file static Font (0x836d30).
//
// TU span: 0x32130 (16-byte zeroing header initializer, .bss 0x836d20) .. 0x32c8f. 0x32c30
// (RGBClass constructor) and 0x32c50 (RGB_To_Pixel) are out-of-line inline functions that GAME.EXE
// shares with many other TUs; they are emitted here because they are defined at the end.
#include <windows.h>
#include "../RECT.H"
#include "../SURFACE.H"
#include "../BLIT.H"

// ---- local declarations (to be moved to headers by the integrator) ----

// Colours (see Beacon.CPP / unnamed/BitFont.cpp).
struct RGBClass {
    RGBClass() {}
    RGBClass(unsigned char red, unsigned char green, unsigned char blue);  // 0x432c30
    void Adjust(int ratio, RGBClass const & rgb);   // 0x634310
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
};
extern RGBClass FadeColor;                  // 0xa9e369 (fade target; name provisional)
int RGB_To_Pixel(int red, int green, int blue);     // 0x432c50

// BitFont (unnamed/BitFont.cpp), only what is used here.
class BitFont {
public:
    BitFont(char const * filename);                                         // 0x430f00
    virtual ~BitFont();
    int Print_Char(wchar_t c, int x, int y, int color);                     // 0x4317a0
    int Print_Fade(wchar_t const * text, int x, int y, int maxchars, int fade);   // 0x431b80
    unsigned char const * Get_Char_Data(wchar_t c) const;                   // 0x431d40
    unsigned short Set_Color(unsigned short color);                         // 0x4312f0
    void Set_Tab_Origin(int x);                                             // 0x431790
    void Lock(Surface * surface);                                           // 0x431f70
    void Unlock(Surface * surface);                                         // 0x432010

    void * Header;              // +0x04
    unsigned char * Missing;    // +0x08
    unsigned short * Buffer;    // +0x0c
    int Pitch;                  // +0x10
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

// ---- end of local declarations ----

static RectangleStruct const ZeroRect(0, 0, 0, 0);
static BitFont * Font;          // 0x836d30

class BitText {
public:
    BitText();
    virtual ~BitText();

    int Print_Char(BitFont * font, Surface * surface, wchar_t c, int x, int y);
    int Print_Fade(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int maxchars, int fade);
    int Print_Bold(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int maxchars);
    bool Print_Wrapped(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int width, int maxheight, int flags, int fadecount, int fadelen);
    bool Print_Shadow(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int width, int maxheight, int flags, int fadecount, int fadelen);
    bool Print_Wrapped_Bold(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int width, int maxheight, int flags, int fadecount, int fadelen);
    void Load_Font();
    void Free_Font();
    void Delete_Font(BitFont * font);
};

inline RGBClass Pixel_To_RGB(unsigned short pixel)
{
    return RGBClass(
        (unsigned char)((unsigned short)(pixel >> BlitFormat.RedShiftRight) << BlitFormat.RedShiftLeft),
        (unsigned char)((unsigned short)(pixel >> BlitFormat.GreenShiftRight) << BlitFormat.GreenShiftLeft),
        (unsigned char)((unsigned short)(pixel >> BlitFormat.BlueShiftRight) << BlitFormat.BlueShiftLeft));
}

// 0x432150
BitText::BitText()
{
    Font = new BitFont("GAME.FNT");
}



// 0x4321c0
int BitText::Print_Char(BitFont * font, Surface * surface, wchar_t c, int x, int y)
{
    int result = x;
    if (font) {
        font->Lock(surface);
        font->Set_Tab_Origin(x);
        result = font->Print_Char(c, x, y, -1);
        font->Unlock(surface);
    }
    return result;
}

// 0x432210
int BitText::Print_Fade(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int maxchars, int fade)
{
    int result = x;
    if (font) {
        font->Lock(surface);
        font->Set_Tab_Origin(x);
        result = font->Print_Fade(text, x, y, maxchars, fade);
        font->Unlock(surface);
    }
    return result;
}



// Prints the characters from start up to end with the line alignment; the fade-out darkens the
// last fadelen characters before fadecount and stops at fadecount.
#define PRINT_LINE() \
    { \
        int offset = 0; \
        if (width > linewidth) { \
            if (flags & 1) { \
                offset = (width - linewidth) / 2; \
            } else if (flags & 2) { \
                offset = width - linewidth; \
            } \
        } \
        int px = x + offset; \
        while (start < text) { \
            int pixel = color; \
            printed++; \
            if (fadecount) { \
                if (printed >= fadecount) { \
                    font->Unlock(surface); \
                    return true; \
                } \
                if (fadecount - printed - 1 < fadelen) { \
                    RGBClass rgb = Pixel_To_RGB(color); \
                    rgb.Adjust((255 / fadelen) * (printed - fadecount + fadelen + 1), FadeColor); \
                    pixel = RGB_To_Pixel(rgb.Red, rgb.Green, rgb.Blue); \
                } \
            } \
            if (pixel == -1) { \
                font->Unlock(surface); \
                return true; \
            } \
            px = font->Print_Char(*start++, px, y, pixel); \
        } \
    }

// 0x432350: prints text wrapped at width (0 = no wrapping) and aligned (flags 1 = centre,
// 2 = right); stops below maxheight (0 = none).
bool BitText::Print_Wrapped(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int width, int maxheight, int flags, int fadecount, int fadelen)
{
    if (font == NULL || text == NULL) {
        return false;
    }
    font->Lock(surface);
    font->Set_Tab_Origin(x);

    unsigned short color = font->Color;
    wchar_t prev = 0;
    int linewidth = 0;
    int chars = 0;
    int height = 0;
    int spacewidth = 0;
    wchar_t const * space = NULL;
    int printed = 0;
    wchar_t const * start = text;

    wchar_t c = *text;
    while (c) {
        switch (c) {
            case '\n':
            case '\r':
                if (prev != '\r') {
                    PRINT_LINE();
                    linewidth = 0;
                    chars = 0;
                    height += font->LineHeight;
                    if (maxheight && height >= maxheight) {
                        font->Unlock(surface);
                        return true;
                    }
                    y += font->LineHeight;
                }
                start++;
                break;

            case '\t':
                linewidth += font->TabWidth;
                linewidth -= linewidth % font->TabWidth;
                break;

            case ' ':
                spacewidth = linewidth;
                space = text;
                // fall through

            default:
            {
                unsigned char const * data = font->Get_Char_Data(c);
                if (data == NULL) {
                    data = font->Get_Char_Data('?');
                    if (data == NULL) {
                        break;
                    }
                }
                chars++;
                int w = font->Spacing + *data;
                linewidth += w;
                if (width && linewidth > width) {
                    if (space) {
                        if (chars > 1) {
                            linewidth = spacewidth;
                            text = space;
                        }
                    } else if (chars > 1) {
                        linewidth -= w;
                        text--;
                    }
                    PRINT_LINE();
                    if (text == space) {
                        space = NULL;
                        start++;
                    }
                    linewidth = 0;
                    chars = 0;
                    height += font->LineHeight;
                    if (maxheight && height >= maxheight) {
                        font->Unlock(surface);
                        return true;
                    }
                    y += font->LineHeight;
                }
                break;
            }
        }
        prev = c;
        c = *++text;
    }

    PRINT_LINE();
    font->Unlock(surface);
    return true;
}

// 0x4329c0: prints the text a pixel down and right in the background colour, then normally.
bool BitText::Print_Shadow(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int width, int maxheight, int flags, int fadecount, int fadelen)
{
    if (font == NULL) {
        return false;
    }
    font->Set_Tab_Origin(x);
    unsigned short old = font->Set_Color(font->Background);
    Print_Wrapped(font, surface, text, x + 1, y + 1, width, maxheight, flags, fadecount, fadelen);
    font->Set_Color(old);
    return Print_Wrapped(font, surface, text, x, y, width, maxheight, flags, fadecount, fadelen);
}

// 0x432a70
bool BitText::Print_Wrapped_Bold(BitFont * font, Surface * surface, wchar_t const * text, int x, int y, int width, int maxheight, int flags, int fadecount, int fadelen)
{
    if (font == NULL) {
        return false;
    }
    font->Set_Tab_Origin(x);
    if (font->IsBold) {
        font->Spacing = 2;
        Print_Wrapped(font, surface, text, x, y, width, maxheight, flags, fadecount, fadelen);
        x++;
        bool result = Print_Wrapped(font, surface, text, x, y, width, maxheight, flags, fadecount, fadelen);
        font->Spacing = 1;
        return result;
    }
    return Print_Wrapped(font, surface, text, x, y, width, maxheight, flags, fadecount, fadelen);
}

// 0x432b50
void BitText::Load_Font()
{
    Font = new BitFont("GAME.FNT");
}

// 0x432b80
void BitText::Free_Font()
{
    Delete_Font(Font);
}

// 0x432bb0
void BitText::Delete_Font(BitFont * font)
{
    if (font) {
        delete font;
    }
    if (font == Font) {
        Font = NULL;
    }
}

// 0x432c30 (shared out-of-line copy)
inline RGBClass::RGBClass(unsigned char red, unsigned char green, unsigned char blue) :
    Red(red),
    Green(green),
    Blue(blue)
{
}

// 0x432c50 (shared out-of-line copy, fastcall)
inline int RGB_To_Pixel(int red, int green, int blue)
{
    return ((red >> BlitFormat.RedShiftLeft) << BlitFormat.RedShiftRight)
        | ((green >> BlitFormat.GreenShiftLeft) << BlitFormat.GreenShiftRight)
        | ((blue >> BlitFormat.BlueShiftLeft) << BlitFormat.BlueShiftRight);
}
