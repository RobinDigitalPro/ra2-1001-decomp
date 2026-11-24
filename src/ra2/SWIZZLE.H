#pragma once
// Pointer swizzle manager used while loading saved games (GAME.EXE object 0xaa5370, method 0x6951f0).
// Layout not yet reconstructed; the method is __stdcall (COM-style implementation class).
#include <windows.h>
class SwizzleManagerClass {
public:
    HRESULT __stdcall Here_I_Am(LONG id, void * pointer);
};
extern SwizzleManagerClass SwizzleManager;
