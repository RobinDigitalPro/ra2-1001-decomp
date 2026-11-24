#pragma once
#include "recovered/recovery_b1025.hpp"
namespace ra2::recovered::b1062 {
using Memory=b1025::Memory;using Inputs=b1025::Inputs;using Heap=b1025::Heap;using Api=b1025::Api;
struct Observation{std::array<unsigned char,100>file{};std::array<unsigned char,24>header{};unsigned tag=0,length=0,count=0;DWORD bytes_read=0;unsigned filename=0,final_free=0,read_calls=0,labels=0,strings=0,extras=0;};
unsigned run(Memory&,const Inputs&,Heap&,Api&,Observation&);
void cleanup(Memory&,Heap&);
}
