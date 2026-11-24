#pragma once
// Rectangle (four ints). Name and members provisional.
#include <stddef.h>
#include "POINT.H"

struct RectangleStruct {
    RectangleStruct() {}
    RectangleStruct(int x, int y, int w, int h) : X(x), Y(y), Width(w), Height(h) {}
    RectangleStruct(Point2D const & point, int w, int h);  // 0x453ab0
    TPoint2D Top_Left(void) const;                        // 0x435420
    int X;
    int Y;
    int Width;
    int Height;
};

// Intersection of two rectangles (fastcall, result through ecx). x/y are adjusted by the amount
// the second rectangle was moved. The two-argument form is an inline wrapper: GAME.EXE evaluates
// the rectangle arguments (Get_Rect calls) before it pushes the two NULL pointers, which default
// arguments do not reproduce.
RectangleStruct Intersect(RectangleStruct const & rect1, RectangleStruct const & rect2, int * x, int * y); // 0x41fdf0
inline RectangleStruct Intersect(RectangleStruct const & rect1, RectangleStruct const & rect2)
{
    return Intersect(rect1, rect2, NULL, NULL);
}
