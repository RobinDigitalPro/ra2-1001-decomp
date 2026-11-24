// Westwood COM-style interfaces used by AbstractClass.
// Layout and calling conventions are taken from GAME.EXE vtables; method names are provisional.
#pragma once
#include <windows.h>
#include <objidl.h>

// {170DAC82-12E4-11D2-8175-006008055BB5} (GAME.EXE 0x78d020)
struct __declspec(uuid("170DAC82-12E4-11D2-8175-006008055BB5")) __declspec(novtable) IRTTITypeInfo : IUnknown {
    virtual int __stdcall What_Am_I() const = 0;
    virtual int __stdcall Fetch_ID() const = 0;
    virtual void __stdcall Create_ID() = 0;
};

class INoticeSink {
public:
    virtual bool __stdcall INoticeSink_Unknown(DWORD value) = 0;
};

class INoticeSource {
public:
    virtual void __stdcall INoticeSource_Unknown() = 0;
};
