// Probably C:\RA2\XSurface.cpp (level-2 reconstruction of GAME.EXE 1.001)
// XSurface (RTTI .?AVXSurface@@, vtable 0x785f8c): Westwood's software surface. All drawing goes
// through the virtual Lock/Unlock/Get_Pitch/Get_Bytes_Per_Pixel of the derived class (BSurface,
// DSurface), so the pixel code here works on any 8 or 16 bit surface.
//
// TU boundary: the file starts at 0x35f270 with its only dynamic initializer (16-byte zero
// rectangle at 0xb10408, already matched) and ends before 0x3612c0, where the BlitPlain/BlitTrans
// template instances it instantiates begin (claimed by templates/BLIT_INSTANCES.cpp). The next
// initializer is 0x3614a0. Function, parameter and global names are provisional except XSurface.
// Surface/XSurface, Point2D/TPoint2D and RectangleStruct come from SURFACE.H, POINT.H and RECT.H
// (corrected from this file's former local copies; see W/analysis/level2/agents/XSURFACE.claims.json).
//
// Open (byte mismatches; logic believed complete): Draw_Line(cliprect,...) 0x35f2c0,
// Draw_Dashed_Line 0x35f570, Plot_Line 0x35f840 (register allocation), Fill_Rect(cliprect, area)
// 0x35fd00 (stack slots/register choice in case 2), Draw_Ellipse 0x360000, Fill_Circle 0x3605d0
// (induction variables), Lock_Surfaces 0x360cf0 (overlap test registers), Clip_Line 0x360f60 (x87).
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "../SURFACE.H"
#include "../BLIT.H"

// ---- local declarations (to be moved to headers by the integrator) ----

// Blits sourcerect of source to destrect of dest through blitter (0x4349a0, defined elsewhere).
bool Blit_Surface(Surface & dest, RectangleStruct const & destrect, Surface & source, RectangleStruct const & sourcerect,
                  Blitter const & blitter, int zmin = 0, int level = 3, int alpha = 1000, int warp = 0);

bool Clip_Rects(RectangleStruct & torect, RectangleStruct const & tobounds, RectangleStruct & fromrect, RectangleStruct const & frombounds);
bool Lock_Surfaces(Surface & dest, RectangleStruct const & destbounds, RectangleStruct & destrect,
                   Surface & source, RectangleStruct const & sourcebounds, RectangleStruct & sourcerect,
                   bool & overlap, void * & destptr, void * & sourceptr);
bool Lock_Surfaces(Surface & dest, RectangleStruct & destrect, Surface & source, RectangleStruct & sourcerect,
                   bool & overlap, void * & destptr, void * & sourceptr);
bool Blit_Plain(Surface & dest, RectangleStruct const & destrect, Surface & source, RectangleStruct const & sourcerect);
bool Blit_Trans(Surface & dest, RectangleStruct const & destrect, Surface & source, RectangleStruct const & sourcerect);
bool Clip_Line(Point2D & start, Point2D & end, RectangleStruct const & rect);
int Line_Clip_Code(RectangleStruct const & rect, double x, double y);
// Stores count copies of value at dest and returns the end pointer in eax (inline assembly; the
// x86 code of the dword fills in Fill_Rect, which also forces its EBP frame).
#pragma warning(disable : 4035)
inline void * Fill_Dwords(void * dest, unsigned long value, int count)
{
    __asm {
        push edi
        mov ecx, count
        mov edi, dest
        cmp ecx, 0
        jle done
        mov eax, value
        rep stosd
done:
        mov eax, edi
        pop edi
    }
}
#pragma warning(default : 4035)
// ---- end of local declarations ----

static RectangleStruct ZeroRect(0, 0, 0, 0);   // 0xb10408 (initializer 0x35f270, already matched)

bool XSurface::Draw_Line(Point2D & start, Point2D & end, unsigned color)
{
    return XSurface::Draw_Line(Get_Rect(), start, end, color);
}

bool XSurface::Draw_Line(RectangleStruct & cliprect, Point2D & start, Point2D & end, unsigned color)
{
    RectangleStruct rect = Intersect(cliprect, Get_Rect());
    Point2D pt1(start.X + rect.X, start.Y + rect.Y);
    Point2D pt2(end.X + rect.X, end.Y + rect.Y);

    if (Clip_Line(pt1, pt2, rect)) {
        if (pt1.X > pt2.X) {
            Point2D temp = pt1;
            pt1 = pt2;
            pt2 = temp;
        }

        int bpp = Get_Bytes_Per_Pixel();
        void * ptr = Lock(pt1);
        if (ptr != NULL) {
            if (pt1.Y == pt2.Y) {
                if (bpp == 1) {
                    memset(ptr, color, pt2.X - pt1.X + 1);
                    Unlock();
                    return true;
                }
                unsigned short * wptr = (unsigned short *)ptr;
                for (int x = 0; x <= pt2.X - pt1.X; x++) {
                    *wptr++ = color;
                }
                Unlock();
                return true;
            }

            if (pt1.X == pt2.X) {
                int pitch;
                if (pt1.Y > pt2.Y) {
                    pitch = -Get_Pitch();
                } else {
                    pitch = Get_Pitch();
                }
                int length = abs(pt2.Y - pt1.Y);
                for (int y = 0; y <= length; y++) {
                    if (bpp == 1) {
                        *(unsigned char *)ptr = color;
                    } else {
                        *(unsigned short *)ptr = color;
                    }
                    ptr = (char *)ptr + pitch;
                }
                Unlock();
                return true;
            }

            int dy = pt2.Y - pt1.Y;
            int dx = pt2.X - pt1.X;
            int pitch = Get_Pitch();
            if (dy < 0) {
                pitch = -pitch;
            }
            int ady = abs(dy);
            int dx2 = dx * 2;
            int ady2 = ady * 2;

            if (dx > ady) {
                int error = ady2 - dx;
                for (int x = 0; x < dx; x++) {
                    if (bpp == 1) {
                        ((unsigned char *)ptr)[x] = color;
                    } else {
                        ((unsigned short *)ptr)[x] = color;
                    }
                    if (error > 0) {
                        ptr = (char *)ptr + pitch;
                        error -= dx2;
                    }
                    error += ady2;
                }
            } else {
                int error = dx2 - ady;
                int x = 0;
                for (int count = ady; count > 0; count--) {
                    if (bpp == 1) {
                        ((unsigned char *)ptr)[x] = color;
                    } else {
                        ((unsigned short *)ptr)[x] = color;
                    }
                    if (error > 0) {
                        x++;
                        error -= ady2;
                    }
                    error += dx2;
                    ptr = (char *)ptr + pitch;
                }
            }
            Unlock();
            return true;
        }
    }
    return false;
}

int XSurface::Draw_Dashed_Line(Point2D & start, Point2D & end, unsigned color, bool * pattern, int offset)
{
    int x1 = start.X;
    int y1 = start.Y;
    int x2 = end.X;
    int y2 = end.Y;
    int step = 1;
    int pos;

    if (x1 > x2) {
        x1 = end.X;
        y1 = end.Y;
        x2 = start.X;
        y2 = start.Y;
        int length = abs(x1 - x2);
        int ylength = abs(y1 - y2) + 1;
        if (length < ylength) {
            length = ylength;
        }
        pos = (length + offset) % 16;
        step = -1;
    } else {
        pos = offset;
    }

    int bpp = Get_Bytes_Per_Pixel();
    void * ptr = Lock(Point2D(x1, y1));
    if (ptr != NULL) {
        if (y1 == y2) {
            unsigned short * wptr = (unsigned short *)ptr;
            for (int x = 0; x <= x2 - x1; x++) {
                if (pos < 0) pos += 16;
                if (pos >= 16) pos -= 16;
                if (pattern[pos]) {
                    *wptr = color;
                }
                wptr++;
                pos += step;
            }
        } else if (x1 == x2) {
            int pitch;
            if (y1 > y2) {
                pitch = -Get_Pitch();
            } else {
                pitch = Get_Pitch();
            }
            for (int y = 0; y <= abs(y2 - y1); y++) {
                if (pos < 0) pos += 16;
                if (pos >= 16) pos -= 16;
                if (pattern[pos]) {
                    if (bpp == 1) {
                        *(unsigned char *)ptr = color;
                    } else {
                        *(unsigned short *)ptr = color;
                    }
                }
                ptr = (char *)ptr + pitch;
                pos += step;
            }
        } else {
            int dy = y2 - y1;
            int dx = x2 - x1;
            int pitch = Get_Pitch();
            if (dy < 0) {
                pitch = -pitch;
            }
            int ady = abs(dy);
            int dx2 = dx * 2;
            int ady2 = ady * 2;

            if (dx > ady) {
                int error = ady2 - dx;
                for (int x = 0; x < dx; x++) {
                    if (pos < 0) pos += 16;
                    if (pos >= 16) pos -= 16;
                    if (pattern[pos]) {
                        if (bpp == 1) {
                            ((unsigned char *)ptr)[x] = color;
                        } else {
                            ((unsigned short *)ptr)[x] = color;
                        }
                    }
                    if (error > 0) {
                        ptr = (char *)ptr + pitch;
                        error -= dx2;
                    }
                    error += ady2;
                    pos += step;
                }
            } else {
                int error = dx2 - ady;
                int x = 0;
                for (int count = ady; count > 0; count--) {
                    if (pos < 0) pos += 16;
                    if (pos >= 16) pos -= 16;
                    if (pattern[pos]) {
                        if (bpp == 1) {
                            ((unsigned char *)ptr)[x] = color;
                        } else {
                            ((unsigned short *)ptr)[x] = color;
                        }
                    }
                    if (error > 0) {
                        x++;
                        error -= ady2;
                    }
                    error += dx2;
                    ptr = (char *)ptr + pitch;
                    pos += step;
                }
            }
        }
        Unlock();
    }
    return pos;
}

int XSurface::Slot19(int, int, int, int, int, int)
{
    return 0;
}

bool XSurface::Slot20(int, int, int, int)
{
    return false;
}

bool XSurface::Slot13(int, int, int, int, int, int, int)
{
    return false;
}

bool XSurface::Slot14(int, int, int, int, int, int, int)
{
    return false;
}

bool XSurface::Slot15(int, int, int, int, int, int, int, int, int, int, int)
{
    return false;
}

bool XSurface::Slot16(int, int, int, int, int, int, int)
{
    return false;
}

// level-2 1.001: INFERRED TU-local adaptation of the reference Bias_To helper.
static inline Point2D const Plot_Bias_To(Point2D const & point, RectangleStruct const & rect)
{
    return Point2D(point.X + rect.X, point.Y + rect.Y);
}

bool XSurface::Plot_Line(RectangleStruct & cliprect, Point2D & start, Point2D & end, void (* plot)(Point2D & point))
{
    RectangleStruct rect = Intersect(cliprect, Get_Rect());
    Point2D pt1 = Plot_Bias_To(start, rect);
    Point2D pt2 = Plot_Bias_To(end, rect);

    if (!Clip_Line(pt1, pt2, rect)) {
        return false;
    }

    if (pt1.X > pt2.X) {
        Point2D temp = pt1;
        pt1 = pt2;
        pt2 = temp;
    }

    if (pt1.Y == pt2.Y) {
        int length = pt2.X - pt1.X;
        for (int x = 0; x <= length; x++) {
            Point2D point(pt1.X + x, pt2.Y);
            plot(point);
        }
    } else if (pt1.X == pt2.X) {
        int length = abs(pt1.Y - pt2.Y);
        int y = pt2.Y;
        if (pt1.Y <= pt2.Y) {
            y = pt1.Y;
        }
        for (int i = 0; i <= length; i++) {
            Point2D point(pt1.X, y + i);
            plot(point);
        }
    } else {
        int end_x = pt2.X;
        int dx = end_x - pt1.X;
        int dy = pt2.Y - pt1.Y;
        int ystep = 1;
        if (dy < 0) {
            ystep = -1;
        }
        int ady = abs(dy);
        int dx2 = dx * 2;
        int ady2 = ady * 2;
        if (dx > ady) {
            int error = ady2 - dx;
            int y = pt1.Y;
            for (int x = pt1.X; x <= end_x; x++) {
                Point2D point(x, y);
                plot(point);
                if (error > 0) {
                    y += ystep;
                    error -= dx2;
                }
                error += ady2;
            }
        } else {
            int error = dx2 - ady;
            int x = pt1.X;
            int y = pt1.Y;
            for (int i = 0; i <= ady; i++) {
                Point2D point(x, y);
                plot(point);
                if (error > 0) {
                    x++;
                    error -= ady2;
                }
                error += dx2;
                y += ystep;
            }
        }
    }
    Unlock();
    return true;
}

bool XSurface::Draw_Rect(RectangleStruct & rect, unsigned color)
{
    return XSurface::Draw_Rect(Get_Rect(), rect, color);
}

bool XSurface::Draw_Rect(RectangleStruct & cliprect, RectangleStruct & rect, unsigned color)
{
    Point2D topleft(rect.X, rect.Y);
    Point2D topright(rect.X + rect.Width - 1, rect.Y);
    Point2D bottomleft(rect.X, rect.Y + rect.Height - 1);
    Point2D bottomright(rect.X + rect.Width - 1, rect.Y + rect.Height - 1);

    Draw_Line(cliprect, topleft, topright, color);
    Draw_Line(cliprect, topleft, bottomleft, color);
    Draw_Line(cliprect, topright, bottomright, color);
    Draw_Line(cliprect, bottomleft, bottomright, color);
    return true;
}

unsigned XSurface::Get_Pixel(Point2D & point)
{
    unsigned color = 0;
    void * ptr = Lock(point);
    if (ptr != NULL) {
        if (Get_Bytes_Per_Pixel() == 2) {
            color = *(unsigned short *)ptr;
        } else {
            color = *(unsigned char *)ptr;
        }
        Unlock();
    }
    return color;
}

bool XSurface::Put_Pixel(Point2D & point, unsigned color)
{
    void * ptr = Lock(point);
    if (ptr != NULL) {
        if (Get_Bytes_Per_Pixel() == 2) {
            *(unsigned short *)ptr = color;
        } else {
            *(unsigned char *)ptr = color;
        }
        Unlock();
        return true;
    }
    return false;
}

unsigned XSurface::Get_Pixel_Clip(Point2D & point, RectangleStruct & cliprect)
{
    unsigned color = 0;
    if (point.X >= cliprect.X && point.X < cliprect.X + cliprect.Width &&
        point.Y >= cliprect.Y && point.Y < cliprect.Y + cliprect.Height) {
        void * ptr = Lock(point);
        if (ptr != NULL) {
            if (Get_Bytes_Per_Pixel() == 2) {
                color = *(unsigned short *)ptr;
            } else {
                color = *(unsigned char *)ptr;
            }
            Unlock();
        }
    }
    return color;
}

bool XSurface::Put_Pixel_Clip(Point2D & point, unsigned color, RectangleStruct & cliprect)
{
    if (point.X >= cliprect.X && point.X < cliprect.X + cliprect.Width &&
        point.Y >= cliprect.Y && point.Y < cliprect.Y + cliprect.Height) {
        void * ptr = Lock(point);
        if (ptr != NULL) {
            if (Get_Bytes_Per_Pixel() == 2) {
                *(unsigned short *)ptr = color;
            } else {
                *(unsigned char *)ptr = color;
            }
            Unlock();
            return true;
        }
    }
    return false;
}

bool XSurface::Fill_Rect(RectangleStruct & area, unsigned color)
{
    return XSurface::Fill_Rect(area, Get_Rect(), color);
}

bool XSurface::Fill_Rect(RectangleStruct & cliprect, RectangleStruct & area, unsigned color)
{
    if (area.Width <= 0 || area.Height <= 0) {
        return false;
    }

    RectangleStruct crect = Intersect(cliprect, Get_Rect());
    Point2D origin(cliprect.X + area.X, cliprect.Y + area.Y);
    RectangleStruct arect = RectangleStruct(origin, area.Width, area.Height);
    RectangleStruct rect = Intersect(crect, arect);
    if (rect.Width <= 0 || rect.Height <= 0) {
        return false;
    }

    int width = rect.Width;
    int height = rect.Height;
    int pitch = Get_Pitch();
    void * ptr = Lock(rect.Top_Left());
    if (ptr == NULL) {
        return false;
    }

    if (Get_Bytes_Per_Pixel() == 1) {
        for (int y = 0; y < rect.Height; y++) {
            memset(ptr, color, rect.Width);
            ptr = (char *)ptr + pitch;
        }
    } else switch ((int)ptr & 3) {
        case 0:
        {
            int dwords = width >> 1;
            int odd = width & 1;
            unsigned long pattern = (color << 16) | color;
            for (int y = height; y > 0; y--) {
                unsigned short * end = (unsigned short *)Fill_Dwords(ptr, pattern, dwords);
                if (odd) {
                    *end = color;
                }
                ptr = (char *)ptr + pitch;
            }
            break;
        }

        case 2:
            if (width <= 1) {
                if (width == 1) {
                    for (int y = height; y > 0; y--) {
                        *(unsigned short *)ptr = color;
                        ptr = (char *)ptr + pitch;
                    }
                }
            } else {
                width--;
                int dwords = width >> 1;
                int odd = width & 1;
                unsigned long pattern = (color << 16) | color;
                for (int y = height; y > 0; y--) {
                    *(unsigned short *)ptr = color;
                    unsigned short * end = (unsigned short *)Fill_Dwords((unsigned short *)ptr + 1, pattern, dwords);
                    if (odd) {
                        *end = color;
                    }
                    ptr = (char *)ptr + pitch;
                }
            }
            break;

        default:
            for (int y = height; y > 0; y--) {
                unsigned short * wptr = (unsigned short *)ptr;
                for (int i = 0; i < width; i++) {
                    *wptr++ = color;
                }
                ptr = (char *)ptr + pitch;
            }
            break;
    }
    Unlock();
    return true;
}

bool XSurface::Fill_Rect_Trans(RectangleStruct &, unsigned, unsigned)
{
    return false;
}

void XSurface::Draw_Ellipse(int x, int y, int rx, int ry, RectangleStruct clip, unsigned color)
{
    int pitch = Get_Pitch() >> 1;

    int bottom = y + ry;
    if (x >= clip.X && x < clip.X + clip.Width && bottom >= clip.Y && bottom < clip.Y + clip.Height) {
        Put_Pixel(Point2D(x, bottom), color);
    }
    int top = y - ry;
    if (x >= clip.X && x < clip.X + clip.Width && top >= clip.Y && top < clip.Y + clip.Height) {
        Put_Pixel(Point2D(x, top), color);
    }

    int b2 = ry * ry;
    int a2 = rx * rx;
    int yy = ry;
    int px = 0;
    int py = 2 * a2 * ry;
    int d = a2 / 4 - a2 * ry;
    unsigned short * buffer = (unsigned short *)Lock();
    int xl = x;
    int xr = x;
    unsigned short * p1 = buffer + bottom * pitch + x;
    unsigned short * p2 = buffer + top * pitch + x;
    unsigned short * p3 = buffer + top * pitch + x;
    unsigned short * p4 = buffer + bottom * pitch + x;
    for (;;) {
        d += b2 + px;
        if (d >= 0) {
            py -= 2 * a2;
            d -= py;
            yy--;
            p1 -= pitch;
            p2 += pitch;
            p3 += pitch;
            p4 -= pitch;
        }
        px += 2 * b2;
        xr++;
        xl--;
        p1++;
        p2--;
        p3++;
        p4--;
        if (px >= py) break;

        if (xr >= clip.X && xr < clip.X + clip.Width && y + yy >= clip.Y && y + yy < clip.Y + clip.Height) *p1 = color;
        if (xl >= clip.X && xl < clip.X + clip.Width && y - yy >= clip.Y && y - yy < clip.Y + clip.Height) *p2 = color;
        if (xr >= clip.X && xr < clip.X + clip.Width && y - yy >= clip.Y && y - yy < clip.Y + clip.Height) *p3 = color;
        if (xl >= clip.X && xl < clip.X + clip.Width && y + yy >= clip.Y && y + yy < clip.Y + clip.Height) *p4 = color;
    }

    xr = x + rx;
    if (xr >= clip.X && xr < clip.X + clip.Width && y >= clip.Y && y < clip.Y + clip.Height) {
        Put_Pixel(Point2D(xr, y), color);
    }
    xl = x - rx;
    if (xl >= clip.X && xl < clip.X + clip.Width && y >= clip.Y && y < clip.Y + clip.Height) {
        Put_Pixel(Point2D(xl, y), color);
    }

    yy = 0;
    py = 0;
    px = 2 * b2 * rx;
    d = b2 / 4 - b2 * rx;
    int centerRow = pitch * y;
    p1 = &buffer[centerRow + xr];
    p2 = &buffer[x + (centerRow - rx)];
    p3 = &buffer[centerRow + x + rx];
    p4 = &buffer[centerRow + xl];
    for (;;) {
        d += a2 + py;
        if (d >= 0) {
            px -= 2 * b2;
            d -= px;
            xr--;
            xl++;
            p1--;
            p2++;
            p3--;
            p4++;
        }
        py += 2 * a2;
        yy++;
        p1 += pitch;
        p2 -= pitch;
        p3 -= pitch;
        p4 += pitch;
        if (py > px) break;

        if (xr >= clip.X && xr < clip.X + clip.Width && y + yy >= clip.Y && y + yy < clip.Y + clip.Height) *p1 = color;
        if (xl >= clip.X && xl < clip.X + clip.Width && y - yy >= clip.Y && y - yy < clip.Y + clip.Height) *p2 = color;
        if (xr >= clip.X && xr < clip.X + clip.Width && y - yy >= clip.Y && y - yy < clip.Y + clip.Height) *p3 = color;
        if (xl >= clip.X && xl < clip.X + clip.Width && y + yy >= clip.Y && y + yy < clip.Y + clip.Height) *p4 = color;
    }
    Unlock();
}

void XSurface::Fill_Circle(int x, int y, int radius, RectangleStruct clip, unsigned color)
{
    int d = 3 - 2 * radius;
    int yy = radius;
    int xx = 0;
    do {
        Draw_Line(clip, Point2D(x - yy, y + xx), Point2D(x + yy, y + xx), color);
        Draw_Line(clip, Point2D(x - xx, y + yy), Point2D(x + xx, y + yy), color);
        Draw_Line(clip, Point2D(x - yy, y - xx), Point2D(x + yy, y - xx), color);
        Draw_Line(clip, Point2D(x - xx, y - yy), Point2D(x + xx, y - yy), color);
        if (d < 0) {
            d += 4 * xx + 6;
        } else {
            d += 4 * (xx - yy) + 10;
            yy--;
        }
        xx++;
    } while (xx <= yy);
}

bool XSurface::Fill(unsigned color)
{
    return Fill_Rect(Get_Rect(), Get_Rect(), color);
}

bool XSurface::Copy_From(Surface & from, bool trans, bool unknown)
{
    RectangleStruct torect = Get_Rect();
    torect.X = 0;
    torect.Y = 0;
    RectangleStruct fromrect = from.Get_Rect();
    fromrect.X = 0;
    fromrect.Y = 0;
    return Copy_From(torect, from, fromrect, trans, unknown);
}

bool XSurface::Copy_From(RectangleStruct & toarea, Surface & from, RectangleStruct & fromarea, bool trans, bool unknown)
{
    return XSurface::Copy_From(Get_Rect(), toarea, from, from.Get_Rect(), fromarea, trans, unknown);
}

bool XSurface::Copy_From(RectangleStruct & toclip, RectangleStruct & toarea, Surface & from, RectangleStruct & fromclip, RectangleStruct & fromarea, bool trans, bool)
{
    RectangleStruct torect = toarea;
    RectangleStruct fromrect = fromarea;
    if (Clip_Rects(torect, toclip, fromrect, fromclip)) {
        if (trans) {
            return Blit_Trans(*this, torect, from, fromrect);
        }
        return Blit_Plain(*this, torect, from, fromrect);
    }
    return false;
}

bool Clip_Rects(RectangleStruct & torect, RectangleStruct const & tobounds, RectangleStruct & fromrect, RectangleStruct const & frombounds)
{
    if (torect.Width == fromrect.Width && torect.Height == fromrect.Height) {
        if (torect.X < 0) {
            fromrect.X -= torect.X;
            fromrect.Width += torect.X;
            torect.Width += torect.X;
            torect.X = 0;
        }
        if (torect.Y < 0) {
            fromrect.Y -= torect.Y;
            fromrect.Height += torect.Y;
            torect.Height += torect.Y;
            torect.Y = 0;
        }
        int over = torect.X - tobounds.Width + torect.Width;
        if (over > 0) {
            fromrect.Width -= over;
            torect.Width -= over;
        }
        over = torect.Height - tobounds.Height + torect.Y;
        if (over > 0) {
            fromrect.Height -= over;
            torect.Height -= over;
        }
        if (fromrect.X < 0) {
            torect.X -= fromrect.X;
            fromrect.Width += fromrect.X;
            torect.Width += fromrect.X;
            fromrect.X = 0;
        }
        if (fromrect.Y < 0) {
            torect.Y -= fromrect.Y;
            fromrect.Height += fromrect.Y;
            torect.Height += fromrect.Y;
            fromrect.Y = 0;
        }
        over = fromrect.Width - frombounds.Width + fromrect.X;
        if (over > 0) {
            fromrect.Width -= over;
            torect.Width -= over;
        }
        over = fromrect.Y - frombounds.Height + fromrect.Height;
        if (over > 0) {
            fromrect.Height -= over;
            torect.Height -= over;
        }
    } else {
        torect = Intersect(torect, tobounds);
        fromrect = Intersect(fromrect, frombounds);
    }
    return torect.Width > 0 && torect.Height > 0 && fromrect.Width > 0 && fromrect.Height > 0;
}

bool Lock_Surfaces(Surface & dest, RectangleStruct & destrect, Surface & source, RectangleStruct & sourcerect,
                   bool & overlap, void * & destptr, void * & sourceptr)
{
    return Lock_Surfaces(dest, dest.Get_Rect(), destrect, source, source.Get_Rect(), sourcerect, overlap, destptr, sourceptr);
}

bool Lock_Surfaces(Surface & dest, RectangleStruct const & destbounds, RectangleStruct & destrect,
                   Surface & source, RectangleStruct const & sourcebounds, RectangleStruct & sourcerect,
                   bool & overlap, void * & destptr, void * & sourceptr)
{
    overlap = false;
    destptr = NULL;
    sourceptr = NULL;

    if (destrect.Width <= 0 || destrect.Height <= 0 ||
        destbounds.Width <= 0 || destbounds.Height <= 0 ||
        sourcerect.Width <= 0 || sourcerect.Height <= 0 ||
        sourcebounds.Width <= 0 || sourcebounds.Height <= 0) {
        return false;
    }

    if (!Clip_Rects(destrect, destbounds, sourcerect, sourcebounds)) {
        return false;
    }

    overlap = false;
    if (&source == &dest) {
        if (sourcerect.X < destrect.X + destrect.Width &&
            sourcerect.Y < destrect.Y + destrect.Height &&
            sourcerect.X + sourcerect.Width > destrect.X &&
            sourcerect.Y + sourcerect.Height > destrect.Y) {
            if (sourcerect.Y < destrect.Y || (sourcerect.Y == destrect.Y && sourcerect.X < destrect.X)) {
                overlap = true;
            }
        }
    }

    destptr = dest.Lock(destbounds.Top_Left() + destrect.Top_Left());
    if (destptr == NULL) {
        return false;
    }
    sourceptr = source.Lock(sourcebounds.Top_Left() + sourcerect.Top_Left());
    if (sourceptr == NULL) {
        dest.Unlock();
        return false;
    }
    return true;
}

bool Blit_Plain(Surface & dest, RectangleStruct const & destrect, Surface & source, RectangleStruct const & sourcerect)
{
    if (dest.Get_Bytes_Per_Pixel() == 1) {
        return Blit_Surface(dest, destrect, source, sourcerect, BlitPlain<unsigned char>());
    }
    return Blit_Surface(dest, destrect, source, sourcerect, BlitPlain<unsigned short>());
}

bool Blit_Trans(Surface & dest, RectangleStruct const & destrect, Surface & source, RectangleStruct const & sourcerect)
{
    if (dest.Get_Bytes_Per_Pixel() == 1) {
        return Blit_Surface(dest, destrect, source, sourcerect, BlitTrans<unsigned char>());
    }
    return Blit_Surface(dest, destrect, source, sourcerect, BlitTrans<unsigned short>());
}

bool Clip_Line(Point2D & start, Point2D & end, RectangleStruct const & rect)
{
    double x1 = start.X;
    double y1 = start.Y;
    double x2 = end.X;
    double y2 = end.Y;
    double dxdy = (x2 - x1) / (y2 - y1);
    double dydx = (y2 - y1) / (x2 - x1);

    int code1 = Line_Clip_Code(rect, x1, y1);
    int code2 = Line_Clip_Code(rect, x2, y2);

    for (;;) {
        if (code1 == 0 && code2 == 0) {
            start.X = x1;
            start.Y = y1;
            end.X = x2;
            end.Y = y2;
            return true;
        }
        if (code1 & code2) {
            return false;
        }
        int code = code1 ? code1 : code2;
        double x;
        double y;
        if (code & 8) {
            x = x1 + (rect.Y - y1) * dxdy;
            y = rect.Y;
        } else if (code & 4) {
            y = rect.Y + rect.Height - 1;
            x = x1 + (y - y1) * dxdy;
        } else if (code & 2) {
            x = rect.X + rect.Width - 1;
            y = y1 + (x - x1) * dydx;
        } else if (code & 1) {
            x = rect.X;
            y = y1 + (rect.X - x1) * dydx;
        }
        if (code == code1) {
            x1 = x;
            y1 = y;
            code1 = Line_Clip_Code(rect, x1, y1);
        } else {
            x2 = x;
            y2 = y;
            code2 = Line_Clip_Code(rect, x2, y2);
        }
    }
}

int Line_Clip_Code(RectangleStruct const & rect, double x, double y)
{
    int code = 0;
    if (x >= rect.X + rect.Width) {
        code = 2;
    } else if (x < rect.X) {
        code = 1;
    }
    if (y >= rect.Y + rect.Height) {
        code |= 4;
    } else if (y < rect.Y) {
        code |= 8;
    }
    return code;
}
