#include "recovery_b416.hpp"
#include "recovered/recovery_b407.hpp"
#include "platform/observed_locale153.hpp"
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b416 {
namespace {
using U=std::uint32_t;
void need(bool b,const char*m){if(!b)throw std::domain_error(m);}
U descriptor(Memory&m,U stream){const U fd=m.r32(stream+0x10u);need(fd<m.r32(0xb10e00u),"B416 valid stream descriptor");const U row=m.r32(0xb10d00u+4u*(fd>>5))+36u*(fd&31u);need((m.r8(row+4u)&1u)!=0,"B416 initialized open descriptor");return fd;}
U write_locked(Memory&m,FileOps&o,U fd,U address,U size){const U row=m.r32(0xb10d00u+4u*(fd>>5))+36u*(fd&31u);need((m.r8(row+4u)&1u)!=0,"B416 open descriptor");o.enter(row+12u);U done=0;const bool okay=o.write(m.r32(row),address,size,done);o.leave(row+12u);need(okay,"B416 actual descriptor write succeeds");return done;}
}

// Positive narrow buffered-stream route. A pending byte forces the reached
// _flsbuf path to flush through the original low-level writer before the new
// character becomes the first byte in the buffer.
U fun_00776b88(Memory&m,const Inputs&i,FileOps&o){
 const U stream=i.arg[1],flags=m.r32(stream+0x0cu),fd=descriptor(m,stream);
 const U ch=i.arg[0]&0xffffu,buffer=m.r32(stream+8u),capacity=m.r32(stream+0x18u),pending=m.r32(stream)-buffer;
 need(stream&&buffer&&capacity>=2u&&(flags&0x40u)==0&&(flags&0x82u)==0x82u&&(flags&0x100u)==0x100u,
      "B416 narrow writable buffered-stream flags");
 need(pending>=1u&&pending<capacity&&m.r32(stream+4u)==0u,"B416 pending-buffer flush boundary");
 need(ch<=0xffu&&m.r32(0xb10530u)==0u,"B416 narrow C-locale fast route");
 // Reached 37b7bd performs one actual Interlocked pair; 37b816 returns the
 // original byte in mode zero. The CRT helper writes the pending bytes, then
 // installs this character at the new buffer head.
 ra2::platform::locale153::Counter::enter();
 ra2::platform::locale153::Counter::leave();
 i.arg[1]=(i.arg[1]&0xffffff00u)|ch;
 const U result=write_locked(m,o,fd,buffer,pending);
 need(result==pending,"B416 buffered flush completes");
 m.w32(stream+4u,capacity-1u);m.w32(stream,buffer+1u);m.w8(buffer,static_cast<std::uint8_t>(ch));
 return ch;
}

// Positive binary bulk-write route. A one-byte stream chunk threshold makes
// any nonempty request enter the original direct descriptor-write loop.
U fun_0076e142(Memory&m,const Inputs&i,FileOps&o){
 const U source=i.arg[0],unit=i.arg[1],count=i.arg[2],stream=i.arg[3];
 need(source&&unit==1u&&count>=1u&&count<=37u,"B416 bounded positive byte-count request");
 const U flags=m.r32(stream+0x0cu),fd=descriptor(m,stream),threshold=m.r32(stream+0x18u),total=unit*count;
 // Nonbuffered FILE state (flag 0x4) selects the descriptor-write loop;
 // threshold one makes the complete positive request a single real write.
 need((flags&0x10cu)==4u&&(flags&0x108u)==0u&&threshold==1u,"B416 nonbuffered binary write path");
 const U result=write_locked(m,o,fd,source,total);
 need(result==total,"B416 successful complete binary write");
 i.arg[0]=source+total;i.arg[3]=threshold;
 return count;
}
}
