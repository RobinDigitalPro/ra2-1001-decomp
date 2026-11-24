#pragma once
#include "recovered/floating_b61_memory.hpp"
namespace ra2::recovered::b1653 {
using U=std::uint32_t;
using Memory=global_b26::Memory;
using Inputs=floating_b61::Inputs;
namespace fp=platform::x87;
// The provider attests an actually owned resource245 dialog and verifies each
// returned child belongs to that authentic control resource/class. No chosen
// API results or substituted control procedures are part of this interface.
struct Api {
 virtual ~Api()=default;
 virtual bool owned_dialog(U dialog)const=0;
 virtual U get_dialog_item(U dialog,int identifier,fp::State&)=0;
 virtual U send(U control,U message,U wparam,U lparam,fp::State&)=0;
};
// Resource245 finite domain; all16 caller words preserved. Last actual lookup
// is required null, and its full DWORD is returned unchanged (RET0 domain).
U fun_0053f9a0(Memory&,const Inputs&,Api&);
}
