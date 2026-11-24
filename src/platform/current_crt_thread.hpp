#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <cstdint>
#include <stdexcept>
namespace ra2::platform {
// Original374fcb nonnull TLS branch: preserve the caller's actual OS error,
// fetch the real current-thread slot, then restore the error before returning.
inline std::uint32_t current_crt_thread(std::uint32_t slot){
 const DWORD saved=GetLastError();const auto p=TlsGetValue(slot);SetLastError(saved);
 if(!p)throw std::domain_error("uninitialized CRT TLS slot outside finite contract");
 return std::uint32_t(reinterpret_cast<std::uintptr_t>(p));
}
}
