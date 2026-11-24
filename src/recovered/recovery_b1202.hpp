#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
#include <array>
#include "recovered/thread1110.hpp"
namespace ra2::recovered::b1202{
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;
struct State{ra2::platform::x87::Image image;std::array<unsigned char,512>scratch{};unsigned produced=0;ra2::recovered::recovery_b1110::ThreadAPI*api=nullptr;};
unsigned run(unsigned,Memory&,const Inputs&,Heap&,State&);
unsigned cleanup(unsigned,Memory&,Heap&,unsigned);
}
