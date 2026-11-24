#pragma once
#include "recovered/recovery_b979.hpp"
#include "platform/x87_state.hpp"
#include <array>
#include <vector>
namespace ra2::recovered::b1192{
using Memory=b979::Memory;using Inputs=b979::Inputs;using Heap=b979::Heap;using State=ra2::platform::x87::State;
using Descriptor=std::array<unsigned char,108>;
struct Sink{virtual~Sink()=default;virtual unsigned row(const Descriptor&)=0;};
struct Api{virtual~Api()=default;virtual unsigned enumerate(unsigned receiver,unsigned flags,unsigned filter,Sink&)=0;};
struct Observation{unsigned hresult=~0u,callbacks=0,capacity=0,backing=0,result=0;std::vector<Descriptor>descriptors;};
unsigned run(unsigned,Memory&,const Inputs&,Heap&,Api&,Observation&,State&);
}
