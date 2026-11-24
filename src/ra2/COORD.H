#pragma once
// Cell and lepton coordinates (two shorts / three ints, constructors evidenced by GAME.EXE initializers).
struct CellStruct {
    short X;
    short Y;
    CellStruct() {}
    CellStruct(short x, short y) : X(x), Y(y) {}
};

struct CoordStruct {
    int X;
    int Y;
    int Z;
    CoordStruct(int x, int y, int z) : X(x), Y(y), Z(z) {}
};
