#include "recovery_b1122.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1122 {
namespace{
namespace fp=ra2::platform::x87;
using Inputs=numeric_b71::Inputs;
namespace floating_b61=ra2::recovered::floating_b61;
struct MutableFrame{const Inputs&original;Inputs value;explicit MutableFrame(const Inputs&i):original(i),value(i){}~MutableFrame(){original.arg=value.arg;original.fp=value.fp;}};
inline void raw_register(fp::State&state,unsigned first,unsigned second){state.require_masked();fp::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t.byte %c[first],%c[second]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(state.image.bytes):[first]"i"(first),[second]"i"(second):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
inline void fimul32(fp::State&state,std::uint32_t value){state.require_masked();fp::Image host;asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\tfimull %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]" :[host]"=m"(host.bytes),[guest]"+m"(state.image.bytes):[operand]"m"(value):"memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)");}
inline std::uint32_t convert_helper(Memory& m,Inputs& i) {
    const auto current=i.fp.control();
    if (current != static_cast<std::uint16_t>(m.r32(0x007c3a04u)))
        i.fp.load_control(static_cast<std::uint16_t>(m.r32(0x007c3a04u)));
    const auto result=i.fp.pop_integer64();
    i.dx=static_cast<std::uint32_t>(std::uint64_t(result)>>32u);
    i.ax=static_cast<std::uint32_t>(result);
    return i.ax;
}
void clamp_byte_float(Memory& m,Inputs& i) {
    const auto hi=m.r32(0x007860a8u),lo=m.r32(0x00785738u);
    i.fp.load32(hi);i.fp.compare_pop_st1();auto status=i.fp.status();i.ax=floating_b61::with_ax(i.ax,status);
    if(((status>>8u)&1u)==0u){
        i.fp.load32(lo);i.fp.compare_pop_st1();status=i.fp.status();i.ax=floating_b61::with_ax(i.ax,status);
        if(((status>>8u)&0x41u)==0u){i.fp.pop_st0();i.fp.load32(lo);return;}
    }
    i.fp.load32(hi);i.fp.compare_pop_st1();status=i.fp.status();i.ax=floating_b61::with_ax(i.ax,status);
    if(((status>>8u)&1u)!=0u){i.fp.pop_st0();i.fp.load32(hi);}
}
std::uint32_t color_blend(Memory& m, const Inputs& input) {
    MutableFrame frame(input);
    auto& i = frame.value;
    const auto dst = i.cx;
    const auto src_a = i.arg[0];
    const auto src_b = i.arg[1];
    i.fp.load32(m.r32(0x007867f8u));
    i.fp.subtract32(i.arg[2]);
    // Channel 0: B*weight + A*(one-weight), in the original FILD/FILD/FMUL ST2 order.
    i.fp.load_integer32(m.r8(src_b));
    i.fp.multiply32(i.arg[2]);
    i.fp.load_integer32(m.r8(src_a));
    raw_register(i.fp, 0xd8, 0xca);
    i.fp.add_pop();
    clamp_byte_float(m, i);
    m.w8(dst, convert_helper(m, i) & 0xffu);

    // Channel 1: A*(one-weight) + B*weight, preserving the original FMUL ST1,
    // then memory FMUL and FADDP sequence.
    i.fp.load_integer32(m.r8(src_a + 1u));
    raw_register(i.fp, 0xd8, 0xc9);
    i.fp.load_integer32(m.r8(src_b + 1u));
    i.fp.multiply32(i.arg[2]);
    i.fp.add_pop();
    clamp_byte_float(m, i);
    m.w8(dst + 1u, convert_helper(m, i) & 0xffu);

    // Channel 2: integer multiply of the surviving stack value by A, then B*weight.
    fimul32(i.fp, m.r8(src_a + 2u));
    i.fp.load_integer32(m.r8(src_b + 2u));
    i.fp.multiply32(i.arg[2]);
    i.fp.add_pop();
    clamp_byte_float(m, i);
    m.w8(dst + 2u, convert_helper(m, i) & 0xffu);

    i.arg[1] = m.r8(src_b + 2u);
    return dst;
}
std::uint32_t color_scale(Memory& m, const Inputs& input) {
    MutableFrame frame(input);
    auto& i = frame.value;
    const auto dst = i.cx;
    const auto src = i.arg[0];
    const auto scale = i.arg[1];
    for (unsigned k = 0; k != 3; ++k) {
        const auto value = m.r8(src + k);
        i.fp.load_integer32(value);
        i.fp.multiply32(scale);
        clamp_byte_float(m, i);
        m.w8(dst + k, convert_helper(m, i) & 0xffu);
        i.arg[0] = value;
    }
    return dst;
}

}
static void need(bool ok){if(!ok)throw std::domain_error("private12C630 positive genuine numeric owner");}
unsigned rebuild(Memory&m,unsigned owner,Heap&heap,ra2::platform::x87::State&fp){
 const unsigned v=owner+0x274u,blob=m.r32(owner+0xa4u);
 need(m.r32(v)==0x79022cu&&m.r8(v+12u)==1u&&m.r32(v+20u)==10u);
 need(m.r32(v+16u)>=1u&&m.r32(v+16u)<=4u&&m.r32(v+8u)>=m.r32(v+16u)&&m.r32(v+4u)&&m.r8(v+13u)==1u);
 const auto rows=heap.r32(blob),cols=heap.r32(blob+4u),total=rows*cols;
 need(rows>=1u&&rows<=2u&&cols>=1u&&cols<=2u&&total<=4u);
 //52C63A..52C66D frees each prior owned52B color payload.
 for(unsigned n=0;n<m.r32(v+16u);++n){const auto p=heap.r32(m.r32(v+4u)+4u*n);if(p)need(heap.release(p)!=0u);}
 //Genuine79022C slot+C ->52C930; owned backing is released and cleared.
 m.w32(v+16u,0u);const auto old=m.r32(v+4u);
 if(old&&m.r8(v+13u)){need(heap.release(old)!=0u);m.w32(v+4u,0u);}
 m.w8(v+13u,0u);m.w32(v+8u,0u);
 std::array<unsigned char,64>scratch{};leaf::Memory sm{scratch.data(),0x30000000u,unsigned(scratch.size())};Memory view=m;view.add(sm);
 numeric_b71::Inputs ni{};ni.fp=fp;
 const auto grow=[&](){
  need(m.r32(v+8u)==0u&&m.r32(v+4u)==0u);
  //52CB70 exactpositive first-growth path. No former cells exist afterclear.
  m.w8(v+12u,0u);const auto p=heap.allocate(40u);m.w8(v+12u,1u);need(p);
  m.w32(v+4u,p);m.w32(v+8u,10u);m.w8(v+13u,1u);
 };
 const auto append=[&](unsigned p){if(m.r32(v+16u)>=m.r32(v+8u))grow();const auto n=m.r32(v+16u);m.w32(v+16u,n+1u);heap.w32(m.r32(v+4u)+4u*n,p);};
 const auto pack=[&](unsigned p){unsigned result=0u;constexpr unsigned shifts[]{0x83b2e8u,0x83b2f8u,0x83b2f0u};for(unsigned k=0;k<3u;++k){const auto a=shifts[k];result|=((view.r8(p+k)>>(m.r8(a+4u)&31u))<<(m.r32(a)&31u));}return result;};
 for(unsigned n=0;n<total;++n){
  const auto cell=heap.r32(blob+16u+4u*n);if(!cell){append(0u);continue;}
  const auto output=heap.allocate(52u);need(output);append(output);
  for(unsigned k=0;k<6u;++k)view.w8(0x30000000u+k,heap.r8(cell+0x2bu+k));
  ni.cx=0x30000010u;ni.arg[0]=0x30000000u;ni.arg[1]=m.r32(0x790114u);color_scale(view,ni);
  ni.cx=0x30000014u;ni.arg[0]=0x30000003u;ni.arg[1]=m.r32(0x790114u);color_scale(view,ni);
  for(unsigned k=0;k<=12u;++k){
   ni.fp.load_integer32(k);ni.fp.multiply64(std::uint64_t(m.r32(0x790268u))|(std::uint64_t(m.r32(0x79026cu))<<32));const auto weight=ni.fp.pop32();
   ni.cx=0x30000018u;ni.arg[0]=0x30000000u;ni.arg[1]=0x30000010u;ni.arg[2]=weight;color_blend(view,ni);const auto first=pack(ni.cx);
   ni.cx=0x3000001cu;ni.arg[0]=0x30000003u;ni.arg[1]=0x30000014u;ni.arg[2]=weight;color_blend(view,ni);const auto second=pack(ni.cx);
   heap.w8(output+4u*k,first&255u);heap.w8(output+4u*k+1u,(first>>8)&255u);heap.w8(output+4u*k+2u,second&255u);heap.w8(output+4u*k+3u,(second>>8)&255u);
  }
 }
 fp=ni.fp;return total;
}
//1297C0 completepositive physicalfile route: filename clone, actual size/read,
//newblobrelocation, positive palette rebuild, complete localfilename release.
unsigned run(unsigned root,Memory&m,const global_b26::Inputs&i,Heap&h,b1025::Api&api,ra2::platform::x87::State&fp,Observation&o){
 if(root==0x12c630u)return rebuild(m,i.cx,h,fp);
 need(root==0x1297c0u&&m.r32(i.cx+0xa4u)==0u&&m.r32(0xa588e0u)==0u&&m.r32(0x838be0u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0xb10adcu)==0u&&m.r32(0x817554u)==0u&&m.r32(0xb10e14u)==0u);
 constexpr char expected[]="whole.bin";for(unsigned k=0;k<10u;++k)need(m.r8(i.cx+0x2c5u+k)==unsigned(expected[k]));
 o.filename=h.allocate(10u);need(o.filename);for(unsigned k=0;k<10u;++k)h.w8(o.filename+k,unsigned(expected[k]));
 const auto put=[&](unsigned a,unsigned x){for(unsigned k=0;k<4u;++k)o.file.at(a+k)=static_cast<unsigned char>(x>>(8u*k));};
 put(0u,0x7856a0u);put(4u,1u);put(0xcu,0xffffffffu);put(0x10u,0xffffffffu);put(0x14u,o.filename);o.file[0x1cu]=1u;put(0x3cu,0xffffffffu);put(0x40u,0xffffffffu);
 const auto path=reinterpret_cast<const char*>(std::uintptr_t(o.filename));
 const auto close=[&](HANDLE file){need(api.close_handle(file)!=FALSE);put(0x10u,0xffffffffu);};
 const auto probe=[&](){auto p=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);need(p!=INVALID_HANDLE_VALUE);put(0x10u,unsigned(reinterpret_cast<std::uintptr_t>(p)));close(p);};
 const auto open=[&](){probe();auto p=api.create_file_a(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr);need(p!=INVALID_HANDLE_VALUE);put(0x10u,unsigned(reinterpret_cast<std::uintptr_t>(p)));return p;};
 probe();HANDLE file=open();o.length=api.size(file,nullptr);need(o.length>=72u&&o.length<=240u);put(0xcu,o.length);close(file);
 if(const auto old=m.r32(i.cx+0xa4u))need(h.release(old)!=0u);
 o.payload=h.allocate(o.length);need(o.payload);m.w32(i.cx+0xa4u,o.payload);
 file=open();need(api.seek(file,0,nullptr,FILE_BEGIN)==0u&&api.seek(file,0,nullptr,FILE_CURRENT)==0u);need(api.read_file(file,reinterpret_cast<void*>(std::uintptr_t(o.payload)),o.length,&o.bytes_read,nullptr)!=FALSE&&o.bytes_read==o.length);m.w8(0xa9e184u,0u);close(file);
 m.w8(i.cx+0xa8u,1u);m.w32(i.cx+0x2b4u,h.r8(o.payload));m.w32(i.cx+0x2b8u,h.r8(o.payload+4u));const auto count=m.r32(i.cx+0x2b4u)*m.r32(i.cx+0x2b8u);need(count>=1u&&count<=4u);
 for(unsigned k=0;k<count;++k){const auto field=o.payload+16u+4u*k,x=h.r32(field);if(x&&x<o.payload)h.w32(field,x+o.payload);}
 rebuild(m,i.cx,h,fp);
 put(0u,0x7856a0u);put(0x60u,0u); //438290 null cachedfile buffer.
 put(0u,0x793c3cu);o.final_free=h.release(o.filename);need(o.final_free);put(0x14u,0u);o.file[0x1cu]=0u;
 return o.length;
}

}
