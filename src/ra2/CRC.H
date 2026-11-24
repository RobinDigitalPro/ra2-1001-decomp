#pragma once
// CRC accumulator (GAME.EXE functions 0x493c60 / 0x493d10); layout not yet reconstructed.
class CRCEngine {
public:
    void operator() (char datum);                // 0x493bd0
    void operator() (bool datum);                // 0x493c60 (normalises with setne)
    void operator() (int datum);
    void operator() (char const * string);
};
