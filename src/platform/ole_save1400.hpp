#pragma once
#include "platform/ole_stream951.hpp"
namespace ra2::platform::ole_save1400 {
using Save=HRESULT(WINAPI*)(IPersistStream*,IStream*);
inline Save actual_export(){
    const auto module=GetModuleHandleW(L"ole32.dll");
    ole_stream951::need(module!=nullptr,"1400 actual ole32 module from genuine COM link");
    const auto p=GetProcAddress(module,"OleSaveToStream");
    ole_stream951::need(p!=nullptr,"1400 actual OleSaveToStream export");
    return reinterpret_cast<Save>(p);
}
inline std::uint32_t address(){return std::uint32_t(reinterpret_cast<std::uintptr_t>(actual_export()));}
}
