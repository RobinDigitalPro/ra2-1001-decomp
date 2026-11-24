#include "recovered/recovery_b407.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b407 {
namespace {
void need(bool b){if(!b)throw std::domain_error("B407 requires a valid initialized binary descriptor and successful synchronous file operations");}
unsigned descriptor(Memory&m,unsigned fd){need(fd<m.r32(0xb10e00));const auto p=m.r32(0xb10d00+4*(fd>>5))+36*(fd&31);need((m.r8(p+4)&1)!=0);return p;}
unsigned seek(Memory&m,FileOps&o,unsigned p,unsigned offset,unsigned origin){auto r=o.seek(m.r32(p),offset,origin);need(r!=0xffffffffu);m.w8(p+4,m.r8(p+4)&0xfd);return r;}
}
// Binary positive-count branch: no text conversion or pipe lookahead.
unsigned fun_00774404(Memory&m,const Inputs&i,FileOps&o){const auto p=descriptor(m,i.arg[0]);need(i.arg[2]>0&&(m.r8(p+4)&0xca)==0);unsigned done=0;need(o.read(m.r32(p),i.arg[1],i.arg[2],done));return done;}
unsigned fun_0077497a(Memory&m,const Inputs&i,FileOps&o){const auto p=descriptor(m,i.arg[0]);need(i.arg[2]>0&&(m.r8(p+4)&0xe0)==0);unsigned done=0;need(o.write(m.r32(p),i.arg[1],i.arg[2],done)&&done>0);i.arg[0]=0;return done;}
// Valid descriptor, initialized lock, successful seeks; preserve the cursor.
unsigned fun_00782ac8(Memory&m,const Inputs&i,FileOps&o){const auto p=descriptor(m,i.arg[0]);need(m.r32(p+8)!=0);o.enter(p+12);const auto saved=seek(m,o,p,0,1),length=seek(m,o,p,0,2);if(saved!=length)seek(m,o,p,saved,0);o.leave(p+12);return length;}
// Positive shrink path. Original private 4096-byte growth buffer is unused.
unsigned fun_0077f302(Memory&m,const Inputs&i,FileOps&o){const auto p=descriptor(m,i.arg[0]);const auto saved=seek(m,o,p,0,1),length=seek(m,o,p,0,2);need(i.arg[1]>0&&i.arg[1]<length);seek(m,o,p,i.arg[1],0);need(o.truncate(m.r32(p)));seek(m,o,p,saved,0);return 0;}
}
