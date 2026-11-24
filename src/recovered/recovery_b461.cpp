#include "recovered/recovery_b461.hpp"
#include "recovered/numeric_b105.hpp"
#include "recovered/floating_callers_b40_memory.hpp"
#include "recovered/leaf_memory.hpp"
#include <array>
#include <algorithm>
#include <stdexcept>
namespace ra2::recovered::recovery_b461 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*m){if(!b)throw std::domain_error(m);}
U signed_div(U n,U d){need(s32(d)>0,"B461 positive divisor");return U(s32(n)/s32(d));}
U distance(Memory& original,ra2::platform::x87::State& fp,U x,U y,U z){
 // Compose the accepted, exact 0x1b780 C++ entry and its own reviewed closed
 // sqrt/conversion callees on a private local vector and x86 guest stack.
 std::array<std::uint8_t,1024> bytes{};constexpr U base=0x5f200000u,vec=base+0x40u,sp=base+0x1f0u,ret=0x42e771u;
 ra2::recovered::leaf::Memory scratch(bytes.data(),base,U(bytes.size()));Memory local=original;local.add(scratch);
 local.w32(vec,x);local.w32(vec+4,y);local.w32(vec+8,z);local.w32(sp,ret);
 floating_callers_b40::State s{};s.cx=vec;s.fp=fp;floating_callers_b40::Frame f{};f.entry_sp=f.return_sp=f.sp=sp;f.outer_return=ret;
 const auto& entries=floating_callers_b40::entries_a();auto it=std::find_if(entries.begin(),entries.end(),[](const auto&e){return e.rva==0x1b780u;});
 need(it!=entries.end(),"B461 accepted 0x1b780 model missing");it->function(local,s,f,floating_callers_b40::Operations{});fp=s.fp;return s.ax;
}
}
std::uint32_t fun_0049e0e0(Memory&m,const Inputs&i){
 const U count=m.r32(0xa288b0u),items=m.r32(0xa288a4u);
 need(count==3&&items,"B461 bounded positive selection list count 3");
 std::array<U,3> sum{};
 for(U k=0;k<count;++k){const U p=m.r32(items+4*k);need(p,"B461 non-null selected coordinate record");for(U c=0;c<3;++c)sum[c]+=m.r32(p+0x88+4*c);}
 std::array<U,3> centroid{};for(U c=0;c<3;++c)centroid[c]=signed_div(sum[c],count);
 U max_distance=0;std::array<U,3> furthest{};
 for(U k=0;k<count;++k){const U p=m.r32(items+4*k);std::array<U,3>d{};for(U c=0;c<3;++c)d[c]=centroid[c]-m.r32(p+0x88+4*c);const U d2=distance(m,i.fp,d[0],d[1],d[2]);if(s32(d2)>s32(max_distance)){max_distance=d2;for(U c=0;c<3;++c)furthest[c]=m.r32(p+0x88+4*c);}}
 std::array<U,3> target{};for(U c=0;c<3;++c)target[c]=signed_div(sum[c]-furthest[c],count-1);
 std::array<std::uint8_t,64> local_bytes{};constexpr U local_base=0x5f210000u;ra2::recovered::leaf::Memory local_span(local_bytes.data(),local_base,U(local_bytes.size()));Memory work=m;work.add(local_span);const U scratch=local_base+16;for(U c=0;c<3;++c)work.w32(scratch+4*c,target[c]);
 Inputs ci{};ci.cx=m.r32(0x821cacu);ci.arg[0]=scratch;ci.fp=i.fp;const U eax=numeric_b105::fun_0069bcf0(work,ci);i.fp=ci.fp;return eax;
}
}
