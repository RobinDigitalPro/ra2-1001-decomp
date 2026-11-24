#pragma once
// Two-dimensional points. Names provisional.

// Point returned by the out-of-line RectangleStruct::Top_Left (0x435420) and its operator+
// (0x435400). It is not Point2D itself: GAME.EXE builds a Point2D by-value argument (e.g. of
// Surface::Lock) from it in place ("sub esp,8; mov ecx,esp; copy"), which needs the inline
// converting constructor below, while Point2D references are pushed as two dwords.
struct TPoint2D {
    TPoint2D() {}
    TPoint2D(int x, int y) : X(x), Y(y) {}
    TPoint2D operator + (TPoint2D const & that) const;  // 0x435400
    int X;
    int Y;
};

// User constructors are required (non-POD): GAME.EXE passes it by value in two registers pushed
// as `xor edx,edx; xor eax,eax; push edx; push eax` (e.g. Surface::Lock) and returns it through
// a hidden pointer (e.g. Fancy_Text_Print).
struct Point2D {
    Point2D() {}
    Point2D(int x, int y) : X(x), Y(y) {}
    Point2D(TPoint2D const & point) : X(point.X), Y(point.Y) {}
    int X;
    int Y;
};
