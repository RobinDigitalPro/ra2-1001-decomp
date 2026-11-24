#pragma once
#include "recovered/global_b26_memory.hpp"
#include <string>
namespace ra2::recovered::recovery_b944 {using global_b26::Memory;using global_b26::Inputs;using U=std::uint32_t;
struct Compare {virtual ~Compare()=default;virtual U ansi(U,U,const std::string&,const std::string&)=0;};
U compare(Memory&,const Inputs&,Compare&);U environment(Memory&,const Inputs&,Compare&);
}
