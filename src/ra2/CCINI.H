#pragma once
// INI database (GAME.EXE methods 0x50be00, 0x50ddf0, 0x50da40, 0x50adf0). Layout not reconstructed; names provisional.
class CCINIClass {
public:
    int Is_Present(char const * section);
    int Get_String(char const * section, char const * entry, char const * defvalue, char * buffer, int size);
    int Put_String(char const * section, char const * entry, char const * string);
    int Clear(char const * section, char const * entry);
};
