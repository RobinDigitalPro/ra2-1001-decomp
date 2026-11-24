#pragma once
#include "recovered/recovery_b1025.hpp"
namespace ra2::recovered::b1039 {
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using Api=b1025::Api;
struct Observation{std::array<unsigned char,100>file{};std::array<char,256>name{},extension{},candidate{};unsigned cloned=0,final_free=0,nodes=0;DWORD bytes_read=0;};
unsigned run(Memory&,const Inputs&,Heap&,Api&,Observation&);
}
