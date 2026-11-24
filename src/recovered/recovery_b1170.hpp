#pragma once
#include "recovered/recovery_b1025.hpp"
namespace ra2::recovered::b1170{using Memory=b1025::Memory;using Inputs=b1025::Inputs;using Heap=b1025::Heap;using Api=b1025::Api;unsigned run(Memory&,const Inputs&,Heap&,Api&);unsigned cleanup(Memory&,unsigned receiver,Heap&,Api&);}
