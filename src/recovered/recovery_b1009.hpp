#pragma once
#define NOMINMAX
#include <windows.h>
#include "recovered/recovery_b979.hpp"
#include <array>
namespace ra2::recovered::b1009 {
using Memory=ra2::recovered::b979::Memory;using Inputs=ra2::recovered::b979::Inputs;using Heap=ra2::recovered::b979::Heap;using FileApi=ra2::recovered::b979::FileApi;
struct Api:FileApi{using RectProc=BOOL(WINAPI*)(LPRECT,int,int,int,int);RectProc set_rect=nullptr;};
struct Observation{std::array<unsigned char,28>header{};unsigned font=0,scratch=0,filename_free_bool=0,file_free_bool=0;};
void prepare(Memory&,Inputs&,unsigned base,unsigned root);
unsigned run(Memory&,const Inputs&,Heap&,Api&,unsigned root,Observation&);
void cleanup(Memory&,const Inputs&,Heap&,unsigned root,unsigned font);
unsigned fun_00431010(Memory&,const Inputs&,Heap&,Api&,Observation&);
unsigned fun_00430f00(Memory&,const Inputs&,Heap&,Api&,Observation&);
}
