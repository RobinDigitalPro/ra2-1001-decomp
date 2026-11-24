#pragma once
// Operating-system version information (GetVersionExA; constructor GAME.EXE 0x72ba70 in another TU).
// Layout partial; name provisional.
class OSVersionClass {
public:
    OSVersionClass();
    ~OSVersionClass() {}

    unsigned long Major;      // +0x00
    unsigned long Minor;      // +0x04
    unsigned long Build;      // +0x08
    char Text[0x80];          // +0x0c
    bool IsWin9x;             // +0x8c
    bool IsWinNT;             // +0x8d
};
