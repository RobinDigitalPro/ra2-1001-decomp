#include "recovered/text_b104_extra.hpp"

#include "recovered/crt_b83.hpp"
#include "recovered/crt_classify.hpp"
#include "recovered/decimal_text.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"
#include "recovered/text_b86.hpp"
#include "recovered/text_b96.hpp"
#include "recovered/text_bytes.hpp"
#include "recovered/text_trim.hpp"
#include "recovered/strings_b37_memory.hpp"
#include "recovered/leaf_memory.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::text_b104_extra {
using U = std::uint32_t;
using namespace global_b26;
namespace {

std::uint32_t bounded_length(Memory& m, U address, U max) {
    for (U n=0; n<=max; ++n) if (m.r8(address+n)==0) return n;
    throw std::domain_error("Block104 extra text exceeds its bounded route");
}

CrtClassification file_crt(Memory& m, std::array<std::uint16_t,257>& table) {
    if (m.r32(0x00b10530u)!=0u || m.r32(0x0081776cu)!=1u ||
        m.r32(0x00817560u)!=0x0081756au)
        throw std::domain_error("Block104 extra requires original initialized single-byte CRT state");
    const U first=m.r32(0x00817560u)-2u;
    for (U n=0;n<table.size();++n) table[n]=static_cast<std::uint16_t>(m.r16(first+2u*n));
    return CrtClassification{1,table.data(),nullptr,nullptr};
}

struct ClassifyContext { CrtClassification* crt; };
std::int32_t classify_decimal(std::uint8_t c, std::uint32_t mask, void* opaque) {
    auto& context=*static_cast<ClassifyContext*>(opaque);
    return static_cast<std::int32_t>(fun_0076e4cc(static_cast<std::int32_t>(c),*context.crt)&mask);
}
std::int32_t uppercase_ascii(std::int32_t c, void* opaque) {
    auto& m=*static_cast<Memory*>(opaque);
    Inputs in{};in.arg[0]=static_cast<U>(c);
    return static_cast<std::int32_t>(crt_b83::fun_0076e382(m,in));
}
void reverse_3829a0(std::array<std::uint8_t,16>& bytes) {
    constexpr U base=0x31000000u,buffer=base+0x100u,sp=base+0x2000u,ret=0xdecafbadU;
    std::array<std::uint8_t,0x3000> storage{};
    ra2::recovered::leaf::Memory span(storage.data(),base,static_cast<U>(storage.size()));
    ra2::recovered::strings_b37::Memory memory;memory.add(span);
    for(U n=0;n<bytes.size();++n)memory.w8(buffer+n,bytes[n]);memory.w8(buffer+16u,0);
    memory.w32(sp,ret);memory.w32(sp+4u,buffer);
    auto& entries=ra2::recovered::strings_b37::entries_b();
    const auto it=std::find_if(entries.begin(),entries.end(),[](const auto& e){return e.rva==0x3829a0u;});
    if(it==entries.end()||!it->function)throw std::logic_error("accepted original 0x3829a0 reverse helper unavailable");
    ra2::recovered::strings_b37::State state{};ra2::recovered::strings_b37::Frame frame{};
    frame.entry_sp=sp;frame.sp=sp;frame.outer_return=ret;frame.argument_words=1u;
    it->function(memory,state,frame,ra2::recovered::strings_b37::Operations{});
    for(U n=0;n<bytes.size();++n)bytes[n]=static_cast<std::uint8_t>(memory.r8(buffer+n));
}
void uppercase_local(std::array<std::uint8_t,128>& bytes) {
    // The recovered CRT helper only observes the mode global and its buffer.
    // Run it in an isolated guest-address view so the source caller's span stays
    // read-only, matching the candidate's stack-local scratch buffer.
    constexpr U buffer=0x32000000u,mode_page=0x00b10000u;
    std::array<std::uint8_t,128> scratch{};
    std::array<std::uint8_t,0x1000> globals{};
    leaf::Memory scratch_span(scratch.data(),buffer,static_cast<U>(scratch.size()));
    leaf::Memory global_span(globals.data(),mode_page,static_cast<U>(globals.size()));
    Memory local;local.add(scratch_span);local.add(global_span);
    local.w32(0x00b10530u,0u);
    for(U n=0;n<bytes.size();++n)local.w8(buffer+n,bytes[n]);
    Inputs input{};input.arg[0]=buffer;
    (void)crt_b83::fun_00781b14(local,input);
    for(U n=0;n<bytes.size();++n)bytes[n]=static_cast<std::uint8_t>(local.r8(buffer+n));
}
void sort_unreachable(IniIndexEntry*,std::int32_t,IniIndexKind,void*) {
    throw std::domain_error("Block104 extra sorted INI fixture unexpectedly requested sorting");
}

// The compact host view projects the actual one-entry x86 INI structures read
// from guest memory. The accepted portable INI routines perform both searches
// and linked-list selection against these views; source/value bytes remain the
// original fixture bytes.
struct IniProjection {
    IniIndexEntry section_entry{};
    IniIndexEntry key_entry{};
    IniIndex sections{};
    IniIndex keys{};
    IniSection section{};
    IniValue value{};
    IniKeyNode node{},sentinel{};
    std::array<std::uint8_t,14> section_name{};
    std::array<std::uint8_t,2> key_name{};
    std::array<std::uint8_t,16> value_copy{};
    std::uint8_t empty[1]={0};
    IniOperations operations{};
    U original_root_cache{};
    U original_key_cache{};
};

IniIndexEntry* map_cache(U raw,U table,IniIndexEntry* entry) {
    if(!raw)return nullptr;
    if(raw==table)return entry;
    throw std::domain_error("Block104 extra INI cache is outside prepared sorted table");
}
void flush_cache(Memory& m,U address,IniIndexEntry* cached,U table,IniIndexEntry* entry) {
    const U raw=cached==entry?table:0u;
    if(cached&&raw==0u)throw std::domain_error("Block104 extra INI cache escaped prepared entry");
    if(m.r32(address)!=raw)m.w32(address,raw);
}

std::uint32_t raw_hash(Memory& m,U name) {
    const U length=bounded_length(m,name,64u);
    std::array<std::uint8_t,65> bytes{};
    for(U n=0;n<length;++n)bytes[n]=static_cast<std::uint8_t>(m.r8(name+n));
    return ini_name_hash(bytes.data(),length,nullptr);
}
void project_ini(Memory& m,U object,IniProjection& p) {
    const U sec_table=m.r32(object+0x20u);
    const U sec_count=m.r32(object+0x24u);
    const U sec_sorted=m.r8(object+0x2cu);
    if(sec_count!=1u||sec_sorted==0u||!sec_table)
        throw std::domain_error("Block104 extra requires one existing sorted INI section");
    const U sec_hash=m.r32(sec_table);
    const U sec_addr=m.r32(sec_table+4u);
    if(!sec_addr||sec_hash!=raw_hash(m,0x007db9f4u))
        throw std::domain_error("Block104 extra section table does not match VariableNames");
    const U key_table=m.r32(sec_addr+0x2cu);
    const U key_count=m.r32(sec_addr+0x30u);
    const U key_sorted=m.r8(sec_addr+0x38u);
    if(key_count!=1u||key_sorted==0u||!key_table)
        throw std::domain_error("Block104 extra requires one existing sorted INI key");
    const U key_hash=m.r32(key_table);
    const U val_addr=m.r32(key_table+4u);
    const U first_node=m.r32(sec_addr+0x18u);
    if(!first_node||!m.r32(first_node+4u)||!m.r32(first_node+8u))
        throw std::domain_error("Block104 extra INI linked-list sentinels are not initialized");
    const U key_name=m.r32(first_node+0x0cu);
    if(key_hash!=raw_hash(m,key_name)) throw std::domain_error("Block104 extra linked INI key hash mismatch");
    if(bounded_length(m,key_name,8u)!=1u||m.r8(key_name)!='1')
        throw std::domain_error("Block104 extra key is not the real decimal key 1");
    if(!val_addr)throw std::domain_error("Block104 extra INI value object is null");
    const U text=m.r32(val_addr+0x10u);
    if(!text||bounded_length(m,text,16u)!=9u)throw std::domain_error("Block104 extra value is not the bounded padded alpha text");
    for(U n=0;n<=9u;++n)p.value_copy[n]=static_cast<std::uint8_t>(m.r8(text+n));
    p.value.text=p.value_copy.data();
    for(U n=0;n<14u;++n)p.section_name[n]=static_cast<std::uint8_t>(m.r8(0x007db9f4u+n));
    p.key_name[0]=static_cast<std::uint8_t>(m.r8(key_name));p.key_name[1]=0;
    p.section_entry={static_cast<std::int32_t>(sec_hash),&p.section};
    p.key_entry={static_cast<std::int32_t>(key_hash),&p.value};
    p.original_root_cache=m.r32(object+0x30u);
    p.original_key_cache=m.r32(sec_addr+0x3cu);
    p.keys={&p.key_entry,1,1,map_cache(p.original_key_cache,key_table,&p.key_entry),0};
    p.section.keys=p.keys;
    p.node={&p.sentinel,&p.sentinel,p.key_name.data()};
    p.sentinel={&p.sentinel,&p.sentinel,p.empty};
    p.section.first=&p.node;
    p.sections={&p.section_entry,1,1,map_cache(p.original_root_cache,sec_table,&p.section_entry),0};
    p.operations={ini_name_hash,sort_unreachable,uppercase_ascii,&m,nullptr,nullptr};
}

} // namespace

std::uint32_t fun_005d0a20(Memory& m,const Inputs& i) {
    if(!i.cx)return 0u;
    const U length=bounded_length(m,i.cx,16u);
    if(length!=16u)throw std::domain_error("Block104 hash contract requires exactly sixteen ASCII bytes");
    for(U n=0;n<length;++n){const U c=m.r8(i.cx+n);if(c<0x21u||c>0x7eu)throw std::domain_error("Block104 hash contract excludes nonprintable ASCII");}
    std::array<std::uint8_t,128> local{};
    for(U n=0;n<128u;++n)local[n]=0xa5u;
    std::array<std::uint8_t,128> input{};
    for(U n=0;n<128u;++n)input[n]=static_cast<std::uint8_t>(m.r8(i.cx+n));
    (void)fun_0076dd10(local.data(),input.data(),128u);
    local[127]=0;
    uppercase_local(local);
    std::array<std::uint16_t,257> class_table{};
    auto crt=file_crt(m,class_table);
    for(U n=0;n<length;++n){
        const auto c=static_cast<std::int8_t>(local[n]);
        if(fun_0076e5cd(c,crt)==0u)local[n]=static_cast<std::uint8_t>('A'+(n%26u));
    }
    // The selected sixteen-byte route skips the length extension and partial
    // CRC helper. Each call uses the recovered zero-state CRC helper.
    NameHashState state{};
    (void)fun_00493da0(state,local.data(),16);
    std::array<std::uint8_t,16> reverse_buffer{};
    std::copy_n(local.begin(),16u,reverse_buffer.begin());
    reverse_3829a0(reverse_buffer);std::copy(reverse_buffer.begin(),reverse_buffer.end(),local.begin());
    state={};
    U rolling=fun_00493da0(state,local.data(),16);
    std::copy_n(local.begin(),16u,reverse_buffer.begin());
    reverse_3829a0(reverse_buffer);std::copy(reverse_buffer.begin(),reverse_buffer.end(),local.begin());
    U last_mixed=0;
    // The loop uses 16-bit destination registers for MOVSX AX/SI/BP/CX;
    // preserve their upper halves between groups exactly as the instructions do.
    for(U n=0;n<16u;++n){const U mixed=rolling^local[n];last_mixed=mixed;local[n]=static_cast<std::uint8_t>(rolling);rolling=((mixed&0xffu)<<24)|global_b26::sar(mixed,8u);}
    for(U n=0;n<16u;++n){const U a=m.r8(0x007d23a4u+(n&7u)),b=m.r8(0x007d239cu+(n&7u));local[n]=static_cast<std::uint8_t>((a|local[n])&~b);}
    U eax=rolling,ecx=global_b26::sar(last_mixed,8u),esi=0,edi=0,ebp=0,ebx=16;
    auto movsx_low16=[](U previous,std::uint8_t value){const auto signed16=static_cast<std::int16_t>(static_cast<std::int8_t>(value));return (previous&0xffff0000u)|static_cast<std::uint16_t>(signed16);};
    for(U group=0;group<4u;++group){
        const U g=group*4u;
        esi=movsx_low16(esi,local[g]);eax=movsx_low16(eax,local[g+1]);ebp=movsx_low16(ebp,local[g+2]);
        U edx=esi;eax=eax+eax;edx=edx*esi;ecx=movsx_low16(ecx,local[g+3]);
        const U saved_2x2=eax;eax=ebp+ebp;eax^=edx;
        eax=eax*esi;ecx=ecx*ecx;esi=eax;eax=ecx;eax^=saved_2x2;ebx=esi;eax+=esi;
        edi+=4u;eax*=ebp;edx^=eax;ebx+=eax;
        const U low_2x3=ebp+ebp;
        local[g]=static_cast<std::uint8_t>(edx);
        local[g+1]=static_cast<std::uint8_t>(low_2x3^eax);
        const auto out2=static_cast<std::uint8_t>(saved_2x2^ebx);
        local[g+2]=out2;
        const auto out3=static_cast<std::uint8_t>(ecx^ebx);
        local[g+3]=out3;
        eax=(eax&0xffffff00u)|out2;
        ecx=(ecx&0xffffff00u)|out3;
        ebx=16u; // MOV EBX,[ESP+0x24] restores the length after each group.
    }
    state={};
    return fun_00493da0(state,local.data(),16);
}

std::uint32_t fun_00658480(Memory& m,const Inputs& i) {
    const U receiver=i.cx,ini=i.arg[0];
    if(!receiver||!ini)throw std::domain_error("Block104 INI name query needs mapped receiver and object");
    IniProjection projection{};project_ini(m,ini,projection);
    const auto* section=projection.section_name.data();
    const auto first_count=fun_0050bf50(&projection.sections,section,projection.operations);
    const auto count=first_count<50?fun_0050bf50(&projection.sections,section,projection.operations):50;
    if(count<1||count>=50)throw std::domain_error("Block104 VariableNames section count outside positive route");
    const auto* key=fun_0050c250(&projection.sections,section,0,projection.operations);
    if(!key)throw std::domain_error("Block104 key enumeration did not return the real first key");
    flush_cache(m,ini+0x30u,projection.sections.cached,m.r32(ini+0x20u),&projection.section_entry);

    std::array<std::uint16_t,257> class_table{};auto crt=file_crt(m,class_table);ClassifyContext context{&crt};
    DecimalOperations decimal{classify_decimal,&context};
    const U decimal_value=fun_0076e73d(key,decimal);
    if(decimal_value!=1u)throw std::domain_error("Block104 decimal key did not parse as one");
    std::array<std::uint8_t,40> output{};
    const std::uint8_t fallback[]={0};
    const auto copied=fun_0050ddf0(&projection.sections,
        section,key,fallback,output.data(),40,projection.operations);
    // The accepted INI copy helper may sort and install both index caches.
    // Reflect those cache-pointer writes back into the real guest objects.
    const U section_table=m.r32(ini+0x20u);
    const U section_addr=m.r32(section_table+4u);
    const U key_table=m.r32(section_addr+0x2cu);
    flush_cache(m,ini+0x30u,projection.sections.cached,section_table,&projection.section_entry);
    flush_cache(m,section_addr+0x3cu,projection.section.keys.cached,key_table,&projection.key_entry);
    if(copied!=5)throw std::domain_error("Block104 real INI copy/trim did not produce alpha length five");
    const U destination=receiver+0x1210u+decimal_value*0x29u;
    for(U n=0;n<40u;++n)m.w8(destination+n,output[n]);
    // The final copy helper returns trimmed length 5 with upper EAX bits clear;
    // MOV AL,1 then leaves the full 32-bit result equal to 1.
    return 1u;
}

std::uint32_t fun_006da720(Memory& m,const Inputs& i) {
    const U selector=i.cx;
    const U initialized=m.r8(0x00a28953u);
    if(initialized==0u&&selector==m.r32(0x007c397cu))
        throw std::domain_error("Block104 archive route excludes the original no-op selector branch");
    const U count=m.r32(0x00a27f80u),rows=m.r32(0x00a27f74u);
    if(count!=1u||!rows)throw std::domain_error("Block104 archive path requires one active path row");
    const U row=m.r32(rows);
    if(!row||m.r8(row+0x1fcu)==0u||m.r8(row+0xa8u)!=0u||m.r32(row+0xa4u)!=0u)
        throw std::domain_error("Block104 archive path row outside finite positive route");
    const U scratch=0x33000000u,path=scratch+0x10u,slot=scratch+0x100u,filename=scratch+0x200u;
    const U suffix=0x00785bacu+selector*104u;
    if((suffix&~0xfffu)!=0x00785000u||suffix>0x00785f80u)
        throw std::domain_error("Block104 archive suffix selector outside mapped literal page");
    std::array<std::uint8_t,4096> suffix_page{},archive_globals{},locale_globals{};
    for(U n=0;n<4096u;++n){
        suffix_page[n]=static_cast<std::uint8_t>(m.r8(0x00785000u+n));
        archive_globals[n]=static_cast<std::uint8_t>(m.r8(0x00a58000u+n));
        locale_globals[n]=static_cast<std::uint8_t>(m.r8(0x00b10000u+n));
    }
    std::uint32_t filename_length=0;
    for(;filename_length<64u;++filename_length){const auto c=m.r8(row+0x24u+filename_length);if(!c)break;}
    if(filename_length==64u)throw std::domain_error("Block104 inline archive filename exceeds bounded local copy");
    const U archive_address=m.r32(0x00a588e0u);
    if(!archive_address)throw std::domain_error("Block104 positive archive route has null archive record");
    const U entry_count=m.r32(archive_address+0x14u),table_address=m.r32(archive_address+0x20u);
    if(entry_count==0u||entry_count>32u||!table_address)
        throw std::domain_error("Block104 archive index outside positive count 1..32");
    std::array<std::uint8_t,0x28> archive_record{};
    std::array<std::uint8_t,32u*12u> archive_table{};
    for(U n=0;n<archive_record.size();++n)archive_record[n]=static_cast<std::uint8_t>(m.r8(archive_address+n));
    for(U n=0;n<entry_count*12u;++n)archive_table[n]=static_cast<std::uint8_t>(m.r8(table_address+n));
    std::array<std::uint8_t,0x400> private_bytes{};
    leaf::Memory suffix_span(suffix_page.data(),0x00785000u,4096u);
    leaf::Memory archive_globals_span(archive_globals.data(),0x00a58000u,4096u);
    leaf::Memory locale_globals_span(locale_globals.data(),0x00b10000u,4096u);
    leaf::Memory archive_span(archive_record.data(),archive_address,static_cast<U>(archive_record.size()));
    leaf::Memory table_span(archive_table.data(),table_address,entry_count*12u);
    leaf::Memory scratch_span(private_bytes.data(),scratch,static_cast<U>(private_bytes.size()));
    Memory private_memory;private_memory.add(suffix_span);private_memory.add(archive_globals_span);
    private_memory.add(locale_globals_span);private_memory.add(archive_span);private_memory.add(table_span);
    private_memory.add(scratch_span);
    for(U n=0;n<filename_length;++n)private_memory.w8(filename+n,m.r8(row+0x24u+n));
    private_memory.w8(filename+filename_length,0);
    Inputs path_in{};path_in.arg[0]=path;path_in.arg[1]=0;path_in.arg[2]=0;path_in.arg[3]=filename;path_in.arg[4]=suffix;
    (void)text_b86::fun_0076eb30(private_memory,path_in);
    if(bounded_length(private_memory,path,64u)>63u)throw std::domain_error("Block104 generated archive path exceeds candidate buffer");
    private_memory.w32(slot,0u);
    Inputs archive{};archive.cx=path;archive.dx=slot;
    (void)text_b96::fun_005928a0(private_memory,archive);
    const U result=private_memory.r32(slot);
    if(!result)throw std::domain_error("Block104 positive archive hash lookup did not resolve a mapped entry");
    m.w32(row+0xa4u,result);
    return count;
}

} // namespace ra2::recovered::text_b104_extra
