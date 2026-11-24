#pragma once
#include "recovered/recovery_b566_machine.hpp"
namespace ra2::recovered::recovery_b1702 {
using U=std::uint32_t;
using Memory=recovery_b566::Memory;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
namespace calls {
// Caller has already pushed actual outgoing arguments. Each model pushes the
// actual continuation, executes its selected callee, applies real RET cleanup,
// and returns the resulting SP to caller. No copied frame or callback target.
void fd4d0(Memory&,State&,Frame& caller,U continuation,U actual_target);
void fbd80(Memory&,State&,Frame& caller,U continuation,U actual_target);
void type_6fee90(Memory&,State&,Frame& caller,U continuation,U actual_target);
void xyz_5cd4d0(Memory&,State&,Frame& caller,U continuation,U actual_target);
void distance_4ba080(Memory&,State&,Frame& caller,U continuation,U actual_target);
void ftol_76aa50(Memory&,State&,Frame& caller,U continuation,U actual_target);
void cell_41b320(Memory&,State&,Frame& caller,U continuation,U actual_target);
}
namespace helpers {void require_selected_basis(const Memory&,const State&,const Frame&);}
// Finite positive nonzero primary destination, exact B1439 sample0 public
// basis. Actual normal Unit+1A0 cell getter gives X5 versus destination X4;
// its mismatch exits after the genuine direction DWORD1 clear. RET4.
void execute_selected(Memory&,State&,Frame&);
}
