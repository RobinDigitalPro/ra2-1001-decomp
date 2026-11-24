#include "recovery_b1170.hpp"
#include <stdexcept>
namespace ra2::recovered::b1170{
static void need(bool v){if(!v)throw std::domain_error("1170 positive genuine full-buffer CCFile continuation");}
unsigned run(Memory&m,const Inputs&i,Heap&,Api&api){
 const unsigned self=i.cx,file=self+4u,total=m.r32(self+0x528u),prefix=m.r32(self+0x52cu),buffer=m.r32(self+0x534u);const auto handle=reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(file+0x10u)));
 need(m.r8(self+0x68u)==1u&&m.r32(file)==0x7856a0u&&m.r32(file+0x54u)==0u&&m.r8(file+0x25u)==0u&&m.r32(file+0xcu)==total&&handle!=INVALID_HANDLE_VALUE&&total>prefix&&prefix>0u&&buffer&&m.r32(self+0x530u)==0u);
 const unsigned remain=total-prefix,n=i.arg[0]==0u?remain:(i.arg[0]>remain?remain:i.arg[0]);need(n>0u);
 // Real468C80->42F980->630330 enters this size-cached CURRENT query.
 // The previous positive read's630720 size query cached memberC=total.
 need(api.seek(handle,0,nullptr,FILE_CURRENT)==prefix);DWORD got=0u;need(api.read_file(handle,reinterpret_cast<void*>(std::uintptr_t(buffer+prefix)),n,&got,nullptr)!=FALSE&&got==n);m.w8(0xa9e184u,0u);
 m.w32(self+0x52cu,prefix+n);if(prefix+n<total)return 0xffffffffu;
 // Genuine7856A0+34=468E10->438140(NULL,0)->42FCA0->6302F0.
 m.w32(file+0x54u,0u);m.w32(file+0x58u,0u);m.w8(file+0x5cu,0u);m.w32(file+0x60u,0u);need(api.close_handle(handle)!=FALSE);m.w32(file+0x10u,0xffffffffu);m.w8(self+0x68u,0u);return 0xfffffffeu;
}
unsigned cleanup(Memory&m,unsigned self,Heap&h,Api&api){const unsigned file=self+4u;need(h.release(m.r32(self+0x534u))!=0u);need(m.r32(file)==0x7856a0u&&m.r32(file+0x54u)==0u&&m.r8(file+0x5cu)==0u);
 // Buffer is fixture-owned; release is outside the candidate boundary and
 // deliberately leaves its raw former pointer in the caller-owned projection.
 m.w32(file,0x7856a0u);m.w32(file+0x60u,0u);m.w32(file+0x54u,0u);m.w32(file+0x58u,0u);m.w8(file+0x5cu,0u);m.w32(file,0x785658u);m.w32(file,0x78773cu);m.w32(file+0x2cu,0u);m.w32(file+0x30u,0u);for(unsigned k:{0x21u,0x23u,0x24u,0x25u})m.w8(file+k,0u);m.w32(file,0x793c84u);
 if(m.r32(file+0x10u)!=0xffffffffu){need(api.close_handle(reinterpret_cast<HANDLE>(std::uintptr_t(m.r32(file+0x10u))))!=FALSE);m.w32(file+0x10u,0xffffffffu);}need(m.r8(file+0x1cu)==1u&&m.r32(file+0x14u));need(h.release(m.r32(file+0x14u))!=0u);m.w32(file+0x14u,0u);m.w8(file+0x1cu,0u);m.w32(file,0x793c3cu);return file;}
}
