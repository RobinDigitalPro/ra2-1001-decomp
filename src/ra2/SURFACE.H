// Surface hierarchy (RTTI .?AVSurface@@ 34 slots, .?AVXSurface@@ / .?AVBSurface@@ 36 slots).
// Inline methods are emitted in the first translation unit that uses them; method names provisional.
#pragma once
#include <stddef.h>
#include "RECT.H"
#include "BUFFER.H"
#include "POINT.H"

class Surface {
public:
    Surface(int width, int height) : Width(width), Height(height) {}
    virtual ~Surface() {}

    // overloaded virtuals: VC6 places them in reverse declaration order
    virtual bool Copy_From(RectangleStruct & toclip, RectangleStruct & toarea, Surface & from, RectangleStruct & fromclip, RectangleStruct & fromarea, bool trans, bool unknown) = 0;
    virtual bool Copy_From(RectangleStruct & toarea, Surface & from, RectangleStruct & fromarea, bool trans, bool unknown) = 0;
    virtual bool Copy_From(Surface & from, bool trans, bool unknown) = 0;
    virtual bool Fill_Rect(RectangleStruct & area, unsigned color) = 0;
    virtual bool Fill_Rect(RectangleStruct & cliprect, RectangleStruct & area, unsigned color) = 0;
    virtual bool Fill(unsigned color) = 0;
    virtual bool Fill_Rect_Trans(RectangleStruct & area, unsigned color, unsigned opacity) = 0;
    virtual void Draw_Ellipse(int x, int y, int rx, int ry, RectangleStruct clip, unsigned color) = 0;
    virtual bool Put_Pixel(Point2D & point, unsigned color) = 0;
    virtual unsigned Get_Pixel(Point2D & point) = 0;
    virtual bool Draw_Line(Point2D & start, Point2D & end, unsigned color) = 0;
    virtual bool Draw_Line(RectangleStruct & cliprect, Point2D & start, Point2D & end, unsigned color) = 0;
    virtual bool Slot13(int, int, int, int, int, int, int) = 0;
    virtual bool Slot14(int, int, int, int, int, int, int) = 0;
    virtual bool Slot15(int, int, int, int, int, int, int, int, int, int, int) = 0;
    virtual bool Slot16(int, int, int, int, int, int, int) = 0;
    virtual bool Plot_Line(RectangleStruct & cliprect, Point2D & start, Point2D & end, void (* plot)(Point2D & point)) = 0;
    virtual int Draw_Dashed_Line(Point2D & start, Point2D & end, unsigned color, bool * pattern, int offset) = 0;
    virtual int Slot19(int, int, int, int, int, int) = 0;
    virtual bool Slot20(int, int, int, int) = 0;
    virtual bool Draw_Rect(RectangleStruct & rect, unsigned color) = 0;
    virtual bool Draw_Rect(RectangleStruct & cliprect, RectangleStruct & rect, unsigned color) = 0;
    virtual void * Lock(Point2D point = Point2D(0, 0)) = 0;
    virtual bool Unlock(void) = 0;
    virtual bool Can_Lock(int x = 0, int y = 0) { return true; }
    virtual bool Can_Blit(int x = 0, int y = 0) { return true; }
    virtual bool Is_Locked(void) const = 0;
    virtual int Get_Bytes_Per_Pixel(void) const = 0;
    virtual int Get_Pitch(void) const = 0;
    virtual RectangleStruct Get_Rect(void) const {
        RectangleStruct rect;
        rect.X = 0;
        rect.Y = 0;
        rect.Width = Width;
        rect.Height = Height;
        return rect;
    }
    virtual int Get_Width(void) const { return Width; }
    virtual int Get_Height(void) const { return Height; }
    virtual bool Is_Direct_Draw(void) const { return false; }

    int Width;     // +0x04
    int Height;    // +0x08
};

class XSurface : public Surface {
public:
    XSurface(int width, int height, int bpp = 0) : Surface(width, height), LockLevel(0) { BytesPerPixel = bpp; }
    virtual ~XSurface() {}

    // overloaded virtuals: VC6 places them in reverse declaration order
    virtual bool Copy_From(RectangleStruct & toclip, RectangleStruct & toarea, Surface & from, RectangleStruct & fromclip, RectangleStruct & fromarea, bool trans, bool unknown);
    virtual bool Copy_From(RectangleStruct & toarea, Surface & from, RectangleStruct & fromarea, bool trans, bool unknown);
    virtual bool Copy_From(Surface & from, bool trans, bool unknown);
    virtual bool Fill_Rect(RectangleStruct & area, unsigned color);
    virtual bool Fill_Rect(RectangleStruct & cliprect, RectangleStruct & area, unsigned color);
    virtual bool Fill(unsigned color);
    virtual bool Fill_Rect_Trans(RectangleStruct & area, unsigned color, unsigned opacity);
    virtual void Draw_Ellipse(int x, int y, int rx, int ry, RectangleStruct clip, unsigned color);
    virtual bool Put_Pixel(Point2D & point, unsigned color);
    virtual unsigned Get_Pixel(Point2D & point);
    virtual bool Draw_Line(Point2D & start, Point2D & end, unsigned color);
    virtual bool Draw_Line(RectangleStruct & cliprect, Point2D & start, Point2D & end, unsigned color);
    virtual bool Slot13(int, int, int, int, int, int, int);
    virtual bool Slot14(int, int, int, int, int, int, int);
    virtual bool Slot15(int, int, int, int, int, int, int, int, int, int, int);
    virtual bool Slot16(int, int, int, int, int, int, int);
    virtual bool Plot_Line(RectangleStruct & cliprect, Point2D & start, Point2D & end, void (* plot)(Point2D & point));
    virtual int Draw_Dashed_Line(Point2D & start, Point2D & end, unsigned color, bool * pattern, int offset);
    virtual int Slot19(int, int, int, int, int, int);
    virtual bool Slot20(int, int, int, int);
    virtual bool Draw_Rect(RectangleStruct & rect, unsigned color);
    virtual bool Draw_Rect(RectangleStruct & cliprect, RectangleStruct & rect, unsigned color);
    virtual void * Lock(Point2D point = Point2D(0, 0)) { LockLevel++; return NULL; }
    virtual bool Unlock(void) { LockLevel--; return true; }
    virtual bool Is_Locked(void) const { return LockLevel != 0; }
    virtual bool Is_Direct_Draw(void) const { return false; }
    // slots 34/35 (XSurface only)
    virtual bool Put_Pixel_Clip(Point2D & point, unsigned color, RectangleStruct & cliprect);
    virtual unsigned Get_Pixel_Clip(Point2D & point, RectangleStruct & cliprect);

    void Fill_Circle(int x, int y, int radius, RectangleStruct clip, unsigned color);

    int LockLevel;       // +0x0c
    int BytesPerPixel;   // +0x10
};

class BSurface : public XSurface {
public:
    BSurface(int width, int height, int bpp, void * buffer = NULL) :
        XSurface(width, height, bpp),
        Buffer(buffer, width * height * bpp)
    {
    }


    virtual void * Lock(Point2D point = Point2D(0, 0)) {
        XSurface::Lock();
        return (char *)Buffer.Get_Buffer() + point.Y * Get_Pitch() + point.X * Get_Bytes_Per_Pixel();
    }
    virtual int Get_Bytes_Per_Pixel(void) const { return BytesPerPixel; }
    virtual int Get_Pitch(void) const { return Get_Width() * BytesPerPixel; }

    Buffer Buffer;  // +0x14
};
