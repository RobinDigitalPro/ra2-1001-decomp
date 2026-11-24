#pragma once
#define NOMINMAX
#include <windows.h>
#include <vector>
#include <utility>
#include <cstdint>
namespace ra2::platform::desktop_metrics859 {using Trace=std::vector<std::pair<int,int>>;int raw(int);int get(int);void reset();const Trace&trace();std::uint32_t forwarder_address();}
