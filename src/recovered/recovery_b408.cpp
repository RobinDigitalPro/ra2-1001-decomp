#include "recovered/recovery_b408.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b408 {
namespace {
void need(bool b){if(!b)throw std::domain_error("B408 covers initialized positive binary file consumer routes");}
unsigned locked_transfer(Memory&m,Inputs&frame,FileOps&ops,bool writing){auto fd=frame.arg[0];need(fd<m.r32(0xb10e00));const auto p=m.r32(0xb10d00+4*(fd>>5))+36*(fd&31);need((m.r8(p+4)&1)&&m.r32(p+8));ops.enter(p+12);auto result=writing?recovery_b407::fun_0077497a(m,frame,ops):recovery_b407::fun_00774404(m,frame,ops);ops.leave(p+12);return result;}
}
unsigned fun_00763d90(Memory&m,const Inputs&i,FileOps&ops){Inputs nested{};nested.arg[0]=m.r32(i.arg[0]+0xb8);if(i.arg[1]==9){auto n=recovery_b407::fun_00782ac8(m,nested,ops);m.w32(i.arg[2],n);return 0;}need(i.arg[1]==5&&i.arg[3]>0);nested.arg[1]=i.arg[2];nested.arg[2]=i.arg[3];return locked_transfer(m,nested,ops,false)!=i.arg[3];}
unsigned fun_00771d4d(Memory&m,const Inputs&i,FileOps&ops){const auto stream=i.arg[1],flags=m.r32(stream+12),buf=m.r32(stream+8),used=m.r32(stream)-buf;need(flags==0x10a&&used>0&&used<m.r32(stream+24));m.w32(stream+4,0);i.arg[1]=0;m.w32(stream+12,(flags&~0x10u)|2);m.w32(stream,buf+1);m.w32(stream+4,m.r32(stream+24)-1);Inputs nested{};nested.arg[0]=m.r32(stream+16);nested.arg[1]=buf;nested.arg[2]=used;i.arg[1]=locked_transfer(m,nested,ops,true);m.w8(buf,i.arg[0]);need(i.arg[1]==used);return i.arg[0]&255;}
}
