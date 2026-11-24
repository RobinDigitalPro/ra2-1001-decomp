#include "recovered/recovery_b1466.hpp"
#include "recovered/recovery_b882.hpp"
#include "platform/listbox_wrapper1466.hpp"
namespace ra2::recovered::b1466 {
namespace {using U=std::uint32_t;namespace fp=ra2::platform::x87;
struct LocalMemory{Memory&m;Memory saved;explicit LocalMemory(Memory&v):m(v),saved(v){}~LocalMemory(){m=saved;}};
}
unsigned fun_005bd8a0(Memory&m,const Inputs&i,Heap&heap){
 auto&context=b1462::ui::context();ui::need(&context.memory()==&m&&&context.heap()==&heap&&i.arg[0]==0xffffffffu,"1466 genuine default-color wrapper context");
 ui::need(m.r16(i.arg[1])=='%'&&m.r16(i.arg[1]+2)=='s'&&m.r16(i.arg[1]+4)==0,"1466 actual nonempty percent-s format");for(U k=0;k<6;++k)ui::need(m.r16(i.arg[2]+2*k)==U(k==5?0:(k%2?'Y':'X')),"1466 exact fitting XYXYX input");
 const auto host=fp::capture_host();fp::restore_host(i.fp.image);try{
  // Original outer REP STOSD produces all 2048 buffer bytes. The helper's
  // 32-byte stream and varargs are local projections of written stack fields;
  // no unknown private word is read or seeded into a persistent result.
  std::array<std::uint8_t,2048>buffer{};std::array<std::uint8_t,32>stream{};std::array<U,14>args{};for(U k=0;k<14;++k)args[k]=i.arg[k+2];
  leaf::Memory b(buffer.data(),ui::ptr(buffer.data()),buffer.size()),s(stream.data(),ui::ptr(stream.data()),stream.size()),a(reinterpret_cast<std::uint8_t*>(args.data()),ui::ptr(args.data()),sizeof(args));LocalMemory overlay(m);m.add(b);m.add(s);m.add(a);
  const U out=b.base(),descriptor=s.base();m.w32(descriptor,out);m.w32(descriptor+4,0x7fffffff);m.w32(descriptor+8,out);m.w32(descriptor+12,0x42);
  Inputs format=i;format.arg[0]=descriptor;format.arg[1]=i.arg[1];format.arg[2]=a.base();const U units=recovery_b882::fun_00775d7e(m,format);ui::need(units==5&&m.r32(descriptor)==out+10&&format.arg[1]==i.arg[1]+6&&format.arg[2]==a.base()+4,"1466 genuine formatter result/stream/cursor");
  // Actual76F398 decrements count and writes two terminator bytes separately.
  for(U k=0;k<2;++k){const U count=m.r32(descriptor+4)-1;m.w32(descriptor+4,count);ui::need(int(count)>=0,"1466 positive stream capacity");const U at=m.r32(descriptor);m.w32(descriptor,at+1);m.w8(at,0);}
  const U first=m.r32(0xb0d84c);ui::need(first&&first==ui::ptr(context.parent()),"1466 authentic parent-HWND field projection");const U parent=m.r32(0xb0d84c);auto child=ui::getitem(reinterpret_cast<HWND>(std::uintptr_t(parent)),0x5b5);
  Inputs call=i;call.cx=i.arg[0];call.dx=out;call.arg[0]=ui::ptr(child);call.fp.image=fp::capture_host();const U result=b1462::fun_005bd930(m,call,heap);i.fp.image=call.fp.image;fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
