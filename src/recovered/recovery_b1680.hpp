#pragma once
#include "recovered/recovery_b1107.hpp"
namespace ra2::recovered::b1680 {
using Memory=b979::Memory;
using Inputs=b979::Inputs;
using Heap=b979::Heap;
using Api=b1025::Api;
struct Observation {
    // Only constructor-written file spans are initialized/claimed by run.
    std::array<unsigned char,100> file;
    std::array<unsigned char,128> header;
    std::array<unsigned char,2048> pool;
    std::array<unsigned char,768> palette;
    DWORD got{};
    unsigned file_clone{},surface{},pixels{},temporary{},node{},node_key{};
    unsigned hash{},bucket{},seek_result{},temporary_free{},file_free{};
    unsigned short ratio_status{};
};
// Private finite proposal. Only AL is defined by this interface; upper24
// EAX are explicitly unclaimed. No canonical/Original execution approval.
unsigned run(Memory&,const Inputs&,Heap&,Api&,Observation&);
}
