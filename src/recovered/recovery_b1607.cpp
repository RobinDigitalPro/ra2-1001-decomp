#include "recovered/recovery_b1607.hpp"
#include <stdexcept>
namespace ra2::recovered::b1607 {
namespace {void need(bool b){if(!b)throw std::domain_error("B1607 hash initialization before viewport");}}
U run(U root,Memory&m,const Inputs&i,Heap&heap){
 need(root==0x2293c0||root==0x229550);const U self=i.cx;
 need(self!=0x81a820&&m.r32(self+0x1254)==0&&m.r32(self+0x14a0)==0&&m.r32(self+0x14a4)==0&&m.r32(self+0x14ac)!=3&&m.r32(0xa28870)==0);
 need(i.fp.image.word(0)==0xe7f&&i.fp.image.word(4)==0&&i.fp.image.word(8)==0xffff);
 if(root==0x229550)for(U off:{0x1218u,0x121cu,0x1238u,0x1254u,0x1270u})m.w32(self+off,0);
 namespace fp=ra2::platform::x87;const auto host=fp::capture_host();fp::restore_host(i.fp.image);
 U header=0,bucket=0;auto state=i.fp;
 try{
  header=heap.allocate(16);need(header);heap.w32(header+4,0x6292e0);heap.w32(header+8,256);heap.w32(header+12,10);
  bucket=heap.allocate(0x1804);need(bucket);heap.w32(bucket,256);
  for(U k=0;k<256;++k){const U p=bucket+4+24*k;
   // Selected zero-size62C6B0 path and caller's growth assignment.
   heap.w32(p,0x7937c4);heap.w32(p+4,0);heap.w32(p+8,0);heap.w8(p+12,1);heap.w8(p+13,0);heap.w32(p+16,0);heap.w32(p+20,10);
  }
  heap.w32(header,bucket+4);state.image=fp::capture_host();fp::restore_host(host);
 }catch(...){fp::restore_host(host);throw;}
 m.w32(self+0x1254,header);
 b1129::Inputs q{};q.ax=i.ax;q.cx=0x81a820;q.dx=i.dx;q.arg=i.arg;q.arg[0]=0x81a918;q.stack_minus8=i.stack_minus8;q.arithmetic_flags=i.arithmetic_flags;
 b1129::run(0x227ec0,m,q,heap,state);i.fp=state;
 // Real628080 sees the separate Scene width0 and returns before any display
 // receiver or oldsurface is used. Empty entity loop leaves fullEAX0.
 need(m.r32(self+0x14a0)==0);return 0;
}
}
