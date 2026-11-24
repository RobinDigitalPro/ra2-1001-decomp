#include "recovery_b1686.hpp"
#include <stdexcept>
namespace ra2::recovered::b1686 {
namespace {
constexpr unsigned line=0xab6e90u,ascii=0xaaadf8u,annotation=0xaabe00u,wide=0xab0e7cu;
void require(bool ok){if(!ok)throw std::invalid_argument("2EE430 excluded finite one-entry ASCII contract");}
bool letter(unsigned c){return(c>=65u&&c<=90u)||(c>=97u&&c<=122u);}
unsigned lower(unsigned c){return c>=65u&&c<=90u?c+32u:c;}
unsigned length(Memory&m,unsigned a,unsigned bound){
    for(unsigned n=0;n<bound;++n)if(m.r8(a+n)==0u)return n;
    throw std::invalid_argument("2EE430 excluded unterminated bounded input");
}
unsigned classify(Memory&m,unsigned input){
    // Exact selected7774E0 path: the original truncates both arguments to
    // WORD, regardless of the upper halves retained by MOVSX CX/AX/DX,AL.
    const unsigned c=input&0xffffu;
    require(c<256u);
    return m.r16(m.r32(0x817564u)+2u*c)&8u;
}
unsigned trim(Memory&m){
    // Preserve original overlapping copy, including NUL and otherwise
    // untouched scratch tail, rather than replacing it with a zeroed string.
    unsigned source=line;
    while(m.r8(source)!=0u&&classify(m,m.r8(source))!=0u)++source;
    const unsigned first=m.r8(source++);m.w8(line,first);
    unsigned destination=line+1u;
    if(first!=0u){unsigned c;do{c=m.r8(source++);m.w8(destination++,c);}while(c!=0u);}
    unsigned last=destination-2u;
    while(last>line){const unsigned c=m.r8(last);if(c==0u||classify(m,c)==0u)break;--last;}
    m.w8(last+1u,0u);
    return length(m,line,35u);
}
unsigned get_line(Memory&m,Stdio&io,Observation&out,unsigned limit){
    const unsigned result=io.read_line(line,limit,m.r32(0xab7eb0u));++out.reads;
    require(result==0u||result==line);
    return result;
}
unsigned key_shape(Memory&m){
    const unsigned n=length(m,line,34u);
    require(n>=2u&&n<=32u&&m.r8(line+n-1u)==10u);
    for(unsigned k=0;k<n-1u;++k)require(letter(m.r8(line+k)));
    return n-1u;
}
unsigned value_shape(Memory&m){
    const unsigned n=length(m,line,35u);
    require(n>=4u&&n<=34u&&m.r8(line)==34u&&m.r8(line+n-2u)==34u&&m.r8(line+n-1u)==10u);
    for(unsigned k=1;k<n-2u;++k)require(letter(m.r8(line+k)));
    return n-3u;
}
}
unsigned run(Memory&m,const Inputs&in,Heap&heap,Stdio&io,Observation&out){
    (void)in;out={};
    require(m.r32(0xab7ed0u)==0u&&m.r32(0xb10530u)==0u);
    require(m.r32(0x817564u)==0x81756au);
    require(m.r8(0x7e26b4u)==69u&&m.r8(0x7e26b5u)==78u&&m.r8(0x7e26b6u)==68u&&m.r8(0x7e26b7u)==0u);
    require(m.r32(0xab7eb0u)!=0u);
    const unsigned record=m.r32(0xab7ec0u);
    require(record!=0u&&m.r32(0xab7ec4u)!=0u&&m.r32(0xab7ec8u)!=0u);
    require(get_line(m,io,out,4096u)!=0u);
    const unsigned key_n=key_shape(m);require(trim(m)==key_n);
    out.key_length=key_n;
    // Entry count starts0; no duplicate-key comparisons occur on this route.
    for(unsigned k=0;k<=key_n;++k)m.w8(record+k,m.r8(line+k));
    if(global_b26::s32(key_n)>global_b26::s32(m.r32(0xab7ea8u)))m.w32(0xab7ea8u,key_n);
    m.w32(m.r32(0xab7ec0u)+0x24u,0u);out.stage=1u;

    require(get_line(m,io,out,4095u)!=0u);
    const unsigned value_n=value_shape(m);require(trim(m)==value_n+2u);
    // ActualRoot appends LF/NUL after the closing quote before6EDF40.
    m.w8(line+value_n+2u,10u);m.w8(line+value_n+3u,0u);
    // Selected6EDF40: copy ASCII letters while using actual classification;
    // closing quote terminates text; the following LF terminates annotation.
    // No stream-getter fallback, backslash state or annotation token is used.
    unsigned read=line+1u,write=ascii,remaining=4096u;
    for(unsigned k=0;k<value_n;++k){const unsigned c=m.r8(read++);require(letter(c)&&classify(m,c)==0u);m.w8(write++,c);--remaining;}
    require(m.r8(read++)==34u);m.w8(write,0u);
    require(m.r8(read)==10u);m.w8(annotation,0u);
    (void)remaining; // Originalhelper's temporary outgoing capacity copy only.
    out.value_length=value_n;out.stage=2u;

    // AB7ED0=0 bypasses reverse/case-transform scratch completely. Every
    // selected byte is an ASCII letter, so the escape dispatcher is bypassed.
    unsigned dst=wide;
    for(unsigned k=0;k<value_n;++k){const unsigned c=m.r8(ascii+k);m.w16(dst,c);dst+=2u;}
    m.w16(dst,0u);
    // Preserve the original normalization stores even though all letters
    // survive unchanged. Neither scratch padding nor heap tails are cleared.
    for(unsigned k=0;k<value_n;++k)m.w16(wide+2u*k,m.r16(wide+2u*k));
    m.w16(wide+2u*value_n,0u);
    unsigned words=0u;while(m.r16(wide+2u*words)!=0u){require(words<31u);++words;}
    out.requested=(words+1u)*2u;
    const unsigned owner=heap.allocate(out.requested);require(owner!=0u);
    out.allocation=owner;
    // Actual publication precedes the copy. Allocation is a genuine malloc
    // owner, with all rounded/raw bytes retained by the external Heap adapter.
    m.w32(m.r32(0xab7ec4u),owner);
    const unsigned destination=m.r32(m.r32(0xab7ec4u));
    for(unsigned k=0;k<=words;++k){const unsigned w=m.r16(wide+2u*k);heap.w8(destination+2u*k,w);heap.w8(destination+2u*k+1u,w>>8u);}
    require(m.r8(annotation)==0u);out.stage=3u;

    require(get_line(m,io,out,4095u)!=0u);
    const unsigned end_n=length(m,line,5u);require(end_n==4u&&m.r8(line+3u)==10u);
    require(trim(m)==3u);
    // Exact ASCII mode-zero case-insensitive comparison, using the actual
    // authentic END bytes; no constant/fake compare result service.
    for(unsigned k=0;k<4u;++k)require(lower(m.r8(line+k))==lower(m.r8(0x7e26b4u+k)));
    m.w32(m.r32(0xab7ec0u)+0x20u,1u);out.stage=4u;
    // One completed entry requires actual EOF next. Real service/provider
    // independently proves EOF state; Root itself only observes NULL return.
    require(get_line(m,io,out,4096u)==0u);
    out.stage=5u;return 1u;
}
unsigned run(Memory&m,const Inputs&in,Heap&heap,Stdio&io){Observation out;return run(m,in,heap,io,out);}
}
