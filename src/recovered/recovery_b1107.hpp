#pragma once
#include "recovered/recovery_b1025.hpp"
namespace ra2::recovered::b1107{using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using Api=b1025::Api;
struct DecodeObservation{std::array<unsigned char,128>header{};std::array<unsigned char,2048>pool{};DWORD got{};unsigned surface{},pixels{};};
struct FileObservation{std::array<unsigned char,100>file{};unsigned name{};DecodeObservation decode;};
struct Observation{DecodeObservation single;std::array<FileObservation,3>images;};
unsigned run(Memory&,const Inputs&,Heap&,Api&,Observation&,unsigned root);}
