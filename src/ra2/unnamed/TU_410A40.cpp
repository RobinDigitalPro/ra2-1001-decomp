// unidentified translation unit starting at 0x410a40 (uses BSurface; Surface inline methods emitted here)
// level-2 reconstruction of GAME.EXE 1.001
// Probably the alpha buffer (provisional class ABufferClass, file ABuffer.cpp; no RTTI, not polymorphic):
// a circular buffer of 16-bit values stored in a BSurface, scrolled with the view (Shift) and
// cleared to 0x7f. Global instance pointer at 0x8198f4 (new 0x30 bytes at 0x498ba1).
//
// Open (see W/analysis/level2/agents/TU_410A40.claims.json):
// - Fill/Fill_Rect call vtable+0x14 and only match when SURFACE.H declares Fill_Rect(area, color)
//   before Fill_Rect(area, cliprect, color) (VC6 reverses overload order in the vtable).
// - The constructor additionally needs XSurface(width, height, bpp) to set BytesPerPixel.
// - Every Lock call site (ctor, Blit_To, Clear_Rect) loads both arguments into registers before
//   the vtable load in the original (ctor: xor edx/xor eax instead of the zero in ebx). Not yet reproduced.
// - Shift: original does not keep a zero register and does not tail-merge the Fill_Rect calls.
#include <stdlib.h>
#include "../SURFACE.H"

// ---- local declarations (to be moved to headers by the integrator) ----
class ABufferClass {
public:
    ABufferClass(RectangleStruct rect);
    ~ABufferClass();

    void Blit_To(Surface & surface, int x, int y, int width, int height);
    void Fill_Words(unsigned short * buffer, int count, unsigned short value);
    void Shift(int dx, int dy, unsigned short value);
    void Fill(unsigned short value);
    void Fill_Rect(unsigned short value, RectangleStruct rect);
    void Clear_Rect(RectangleStruct rect);
    unsigned char * Get_Buffer_Ptr(Point2D point);

    RectangleStruct Rect;          // +0x00
    int BufferOffset;              // +0x10 byte offset of the logical origin
    BSurface * BufferSurface;            // +0x14
    unsigned char * BufferStart;   // +0x18
    unsigned char * BufferEnd;     // +0x1c
    int BufferSize;                // +0x20 bytes
    int MaxValue;                  // +0x24
    int Width;                     // +0x28
    int Height;                    // +0x2c
};
// ---- end of local declarations ----

ABufferClass::ABufferClass(RectangleStruct rect)
{
    Width = rect.Width;
    Height = rect.Height;
    Rect = rect;
    BufferSize = Width * Height * 2;
    BufferSurface = new BSurface(Width, Height, 2);

    rect.X = 0;
    rect.Y = 0;
    rect.Width = Width;
    rect.Height = Height;
    BufferSurface->Fill_Rect(rect, 0x7f);

    BufferStart = (unsigned char *)BufferSurface->Lock();
    BufferOffset = 0;
    MaxValue = 0x8000;
    BufferEnd = BufferStart + Width * Height * 2;
    BufferSurface->Unlock();
}

void ABufferClass::Blit_To(Surface & surface, int x, int y, int width, int height)
{
    unsigned short * dst = (unsigned short *)surface.Lock(Point2D(x, y));
    unsigned short * src = (unsigned short *)(BufferStart + BufferOffset);
    int skip = surface.Get_Pitch() / 2 - width;

    if (dst != NULL) {
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                *dst++ = *src++;
                if ((unsigned char *)src >= BufferEnd) {
                    src = (unsigned short *)((unsigned char *)src - BufferSize);
                }
            }
            dst += skip;
        }
    }
    surface.Unlock();
}

ABufferClass::~ABufferClass()
{
    if (BufferSurface != NULL) {
        delete BufferSurface;
    }
    BufferSurface = NULL;
}

void ABufferClass::Fill_Words(unsigned short * buffer, int count, unsigned short value)
{
    if (((int)buffer & 2) && count) {
        *buffer++ = value;
        count--;
    }
    int dwords = count >> 1;
    unsigned short * end = NULL;
    if (dwords) {
        unsigned long pattern = ((unsigned long)value << 16) + value;
        unsigned long * ptr = (unsigned long *)buffer;
        for (int i = dwords; i; i--) {
            *ptr++ = pattern;
        }
        end = (unsigned short *)ptr;
    }
    if ((count & 1) && end) {
        *end = value;
    }
}

void ABufferClass::Shift(int dx, int dy, unsigned short value)
{
    int col = (BufferOffset / 2) % Width;

    if (abs(dx) <= Width && abs(dy) <= Height) {
        int newcol = col + dx;
        RectangleStruct rect;

        if (dx != 0) {
            BufferOffset += dx * 2;
            unsigned char * ptr = BufferStart + BufferOffset;
            if (ptr < BufferStart) ptr += BufferSize;
            if (ptr >= BufferEnd) ptr -= BufferSize;
            BufferOffset = ptr - BufferStart;

            if (dx < 0) {
                if (newcol < 0) {
                    rect.X = 0;
                    rect.Y = 0;
                    rect.Width = col;
                    rect.Height = Height;
                    BufferSurface->Fill_Rect(rect, value);
                    newcol += Width;
                    rect.X = newcol;
                    rect.Y = 0;
                    rect.Width = Width - newcol;
                    rect.Height = Height;
                    BufferSurface->Fill_Rect(rect, value);
                } else {
                    rect.X = newcol;
                    rect.Y = 0;
                    rect.Width = -dx;
                    rect.Height = Height;
                    BufferSurface->Fill_Rect(rect, value);
                }
            } else {
                if (newcol >= Width) {
                    rect.X = col;
                    rect.Y = 0;
                    rect.Width = Width - col;
                    rect.Height = Height;
                    BufferSurface->Fill_Rect(rect, value);
                    rect.X = 0;
                    rect.Y = 0;
                    rect.Width = newcol - Width;
                    rect.Height = Height;
                    BufferSurface->Fill_Rect(rect, value);
                } else {
                    rect.X = col;
                    rect.Y = 0;
                    rect.Width = dx;
                    rect.Height = Height;
                    BufferSurface->Fill_Rect(rect, value);
                }
            }
        }

        if (dy != 0) {
            int oldoffset = BufferOffset;
            int row = (BufferOffset / 2) / Width;
            MaxValue -= dy;
            BufferOffset += Width * dy * 2;
            int newrow = row + dy;
            unsigned char * ptr = BufferStart + BufferOffset;
            if (ptr < BufferStart) ptr += BufferSize;
            if (ptr >= BufferEnd) ptr -= BufferSize;
            BufferOffset = ptr - BufferStart;

            if (dy < 0) {
                if (newrow < 0) {
                    Fill_Words((unsigned short *)BufferStart, oldoffset / 2, value);
                    Fill_Words((unsigned short *)(BufferStart + BufferOffset), (Height * Width * 2 - BufferOffset) / 2, value);
                } else {
                    Fill_Words((unsigned short *)(BufferStart + BufferOffset), (oldoffset - BufferOffset) / 2, value);
                }
            } else {
                if (newrow >= Height) {
                    Fill_Words((unsigned short *)(BufferStart + oldoffset), (Height * Width * 2 - oldoffset) / 2, value);
                    Fill_Words((unsigned short *)BufferStart, BufferOffset / 2, value);
                } else {
                    Fill_Words((unsigned short *)(BufferStart + oldoffset), (BufferOffset - oldoffset) / 2, value);
                }
            }
        }
    } else {
        RectangleStruct rect;
        rect.X = 0;
        rect.Y = 0;
        rect.Width = Width;
        rect.Height = Height;
        BufferSurface->Fill_Rect(rect, value);
        MaxValue = 0x8000;
    }
}

void ABufferClass::Fill(unsigned short value)
{
    RectangleStruct rect;
    rect.X = 0;
    rect.Y = 0;
    rect.Width = Width;
    rect.Height = Height;
    BufferSurface->Fill_Rect(rect, value);
}

void ABufferClass::Fill_Rect(unsigned short value, RectangleStruct rect)
{
    BufferSurface->Fill_Rect(rect, value);
}

void ABufferClass::Clear_Rect(RectangleStruct rect)
{
    unsigned char * ptr = Get_Buffer_Ptr(Point2D(rect.X, rect.Y));

    for (int row = 0; row < rect.Height; row++) {
        if (ptr + rect.Width * 2 >= BufferEnd) {
            int count = (unsigned)(BufferEnd - ptr) / 2;
            Fill_Words((unsigned short *)ptr, count, 0x7f);
            Fill_Words((unsigned short *)BufferStart, rect.Width - count, 0x7f);
        } else {
            Fill_Words((unsigned short *)ptr, rect.Width, 0x7f);
        }
        ptr += Width * 2;
        if (ptr >= BufferEnd) ptr -= BufferSize;
    }
}

unsigned char * ABufferClass::Get_Buffer_Ptr(Point2D point)
{
    void * ptr = BufferSurface->Lock(point);
    BufferSurface->Unlock();
    unsigned char * result = BufferOffset + (unsigned char *)ptr;
    if (result >= BufferEnd) result -= BufferSize;
    return result;
}
