#pragma once
#include "recovered/recovery_b979.hpp"
#include <array>
namespace ra2::recovered::b1058 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using Api=b979::FileApi;
struct Observation{std::array<unsigned char,100>file{};std::array<char,304>candidate{};unsigned cloned=0,final_free=0,table_compares=0,index_updates=0;};
unsigned run(Memory&,const Inputs&,Heap&,Api&,Observation&);
}
