#pragma once
#include "recovered/recovery_b979.hpp"
namespace ra2::recovered::b1220{using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;unsigned run(unsigned,Memory&,const Inputs&,Heap&);unsigned cleanup(Memory&,unsigned,Heap&);}
