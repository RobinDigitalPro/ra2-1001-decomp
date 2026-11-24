#include "recovered/recovery_b830.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"
#include "recovered/pixels_b72.hpp"
#include "recovered/leaf_b21_c.hpp"
#include "recovered/leaf_b21_b.hpp"
#include <array>
#include <stdexcept>
#include <vector>
namespace ra2::recovered::recovery_b830 {
namespace {
using U=std::uint32_t;
using Bytes=std::vector<std::uint8_t>;
[[noreturn]] void bad(const char*s){throw std::domain_error(s);}
void need(bool b,const char*s){if(!b)bad(s);}
Bytes ztext(const Memory&m,U p,U bound=0x1000){Bytes x;for(U k=0;k<bound;++k){U c=m.r8(p+k);x.push_back(static_cast<std::uint8_t>(c));if(!c)return x;}bad("B830 unterminated bounded INI text");}
U hash_z(const Bytes&s){need(!s.empty()&&s.back()==0,"B830 missing NUL");return ini_name_hash(s.data(),s.size()-1u,nullptr);}
U signed_hash(U h){return h;}
U find_section(Memory&m,U receiver,U name){U rows=m.r32(receiver+0x20),count=m.r32(receiver+0x24),key=signed_hash(hash_z(ztext(m,name,64)));need(count>0&&count<64&&rows,"B830 requires populated section index");for(U n=0;n<count;++n)if(m.r32(rows+8*n)==key){m.w32(receiver+0x30,rows+8*n);return m.r32(rows+8*n+4);}bad("B830 selected section is absent");}
U find_value(Memory&m,U section){U rows=m.r32(section+0x2c),count=m.r32(section+0x30),node=m.r32(section+0x18);need(count>0&&count<64&&rows&&node,"B830 requires populated key index and linked node");U sentinel=m.r32(node+4);need(sentinel&&m.r32(node+8)==sentinel&&m.r32(sentinel+4)==node&&m.r32(sentinel+8)==node,"B830 requires a one-node sentinel-linked key list");U keyname=m.r32(node+0x0c);need(keyname,"B830 node key name missing");U key=signed_hash(hash_z(ztext(m,keyname,64)));for(U n=0;n<count;++n)if(m.r32(rows+8*n)==key){m.w32(section+0x3c,rows+8*n);U value=m.r32(rows+8*n+4);need(value,"B830 key value missing");return m.r32(value+0x10);}bad("B830 linked key not found in sorted index");}
U decode_b64(Memory&m,U src,U length,U out,U capacity){need(length==8&&capacity>=6,"B830 Base64 route requires one full six-byte payload");Inputs decoder{};decoder.cx=src;decoder.dx=length;decoder.arg[0]=out;decoder.arg[1]=capacity;return pixels_b72::fun_0042d640(m,decoder);}
U read_one(Memory&m,const Inputs&i,U section_name,U out,U capacity){U sec=find_section(m,i.cx,section_name);U text=find_value(m,sec);Bytes original=ztext(m,text,0x80);std::array<std::uint8_t,0x100> local{};U scratch_base=0xe0000000u;ra2::recovered::leaf::Memory scratch_span(local.data(),scratch_base,static_cast<U>(local.size()));Memory work=m;work.add(scratch_span);fun_0076dd10(local.data(),original.data(),0x80);local[0x7f]=0;fun_006e41d0(local.data());U len=0;while(local[len])++len;need(len==8,"B830 expected a complete eight-character Base64 string");return decode_b64(work,scratch_base,len,out,capacity);}
}
U fun_0050c540(Memory&m,const Inputs&i){U out=i.arg[1],capacity=i.arg[2];need(i.cx&&i.arg[0]&&out&&capacity>=6,"B830 reader input outside positive contract");return read_one(m,i,i.arg[0],out,capacity);}
U fun_0050f7c0(Memory&m,const Inputs&i){need(i.cx&&i.arg[1]==0&&i.arg[0],"B830 composed route uses zero second argument and nonnull output");U out=i.arg[0];std::array<std::uint8_t,0x400> scratch{};const U sb=0xe0001000u;ra2::recovered::leaf::Memory span(scratch.data(),sb,static_cast<U>(scratch.size()));Memory work=m;work.add(span);Inputs child=i;child.arg[1]=sb+0x200;child.arg[2]=0x200;child.arg[0]=0x7c6570;U a=fun_0050c540(work,child);need(a==6,"B830 PrivateKey read length");ra2::recovered::leaf::Inputs convert{};convert.cx=sb+0x100;convert.dx=sb+0x200;convert.arg[0]=0x40;ra2::recovered::leaf::fun_005a42c0(span,convert);child.arg[0]=0x7c657c;U b=fun_0050c540(work,child);need(b==6,"B830 PublicKey read length");convert.cx=sb;convert.dx=sb+0x200;ra2::recovered::leaf::fun_005a42c0(span,convert);ra2::recovered::leaf::Inputs bits{};bits.cx=sb;bits.dx=0x40;U bit_count=ra2::recovered::leaf::fun_005a48b0(span,bits);work.w32(sb+0x200,bit_count-1u);for(U k=0;k<0x100;++k){work.w8(out+k,span.r8(sb+k));work.w8(out+0x100+k,span.r8(sb+0x100+k));}work.w32(out+0x200,bit_count-1u);return out;}
}
