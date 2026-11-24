#include "recovery_b1361.hpp"
#include "recovered/numeric_b88_detail.hpp"
#include <stdexcept>
namespace ra2::recovered::b1361 {
namespace {using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void initialize_759250(U&local){local=0;}
U clear_null_759f70(U&local){const U old=local;need(old==0,"1361 actual private string is null");local=0;return old;}
U destroy_null_759320(U&local){const U old=local;need(old==0,"1361 produced null destructor");local=0;return old;}
void prune(Memory&m,U self){
 const U count=m.r32(self+0x3d0u);need(count>=1&&count<=4&&m.r32(self+0x3bcu)==0,"1361 nonempty pending sequence with zero retained prefix");
 // Descending EBX is exactly the new count on every iteration. No element
 // shift/copy, destructor, allocator or substitute callback is reached.
 for(U remaining=count;remaining!=0;--remaining)m.w32(self+0x3d0u,remaining-1u);
 m.w8(self+0x3b8u,1);
}
U empty_726a20(Memory&m,U vector,U&local){
 clear_null_759f70(local);const U count=m.r32(vector+0x10u);need(count==0,"1361 actual secondary vector empty");return count&0xffffff00u;
}
}
U fun_007272c0(Memory&m,const Inputs&i){
 need(i.arg[0]==0&&m.r32(i.cx+0x38cu)==0,"1361 selected secondary vector0 is empty");
 prune(m,i.cx);U local;initialize_759250(local);clear_null_759f70(local);return destroy_null_759320(local);
}
U fun_007270d0(Memory&m,const Inputs&i){
 need(i.arg[0]==0&&i.arg[1]==0&&m.r32(i.cx+0x18u)==0,"1361 selected secondary vector8 is empty");
 prune(m,i.cx);U local;initialize_759250(local);need(empty_726a20(m,i.cx+8u,local)==0,"1361 real empty vector branch");return destroy_null_759320(local);
}
U fun_00583600(Memory&m,const Inputs&i){
 using namespace numeric_b88::detail;auto&f=i.fp;
 need(m.r32(i.cx+0x60u)==0&&f.control()==0x037fu&&f.status()==0&&f.image.word(8)==0xffffu,"1361 table setup workload0 and exact masked emptyFP entry");
 need(read64(m,0x791018u)==0x3fd47ae147ae147bull&&read64(m,0x787a88u)==0x4008000000000000ull&&m.r32(0x7c3a04u)==0x0e7fu,"1361 authoritative numeric literals");
 f.load_integer32(m.r32(i.cx+0x60u));f.add64(read64(m,0x791018u));f.multiply64(read64(m,0x787a88u));const U workload=integer(m,f);
 const U first=m.r32(0xa55c4cu);for(U k=0;k<101;++k)m.w32(0xa57cc0u+12*k,first+k);
 const U second=m.r32(0xa5593cu);for(U k=0;k<8;++k)m.w32(0xa5817cu+12*k,second+k);
 need(workload==0,"1361 positive109-write initialization before no generated work");return workload;
}
U fun_006adf00(Memory&m,const Inputs&i){
 const U context=m.r32(i.cx+0x28u);need(context!=0&&m.r32(i.cx+0x48u)==0,"1361 real pending context and empty candidates");
 m.w8(i.cx+0x7fu,0);
 // Actual65F8B0 writes context2C=-1 and AL=1. The root then reloads
 // full EAX from its candidate count, so the helper AL does not survive.
 m.w32(context+0x2cu,0xffffffffu);const U count=m.r32(i.cx+0x48u);m.w32(i.cx+0x34u,0);return count;
}
}
