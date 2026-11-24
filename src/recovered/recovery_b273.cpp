#include "recovery_b273.hpp"

#include "recovered/crt_b83.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_text.hpp"
#include "recovered/name_hash.hpp"

#include <array>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::recovery_b273 {
namespace {
using namespace ra2::recovered;
static_assert(sizeof(void*)==4,"Block273 guest-local pointer span requires the documented x86 test target");
constexpr std::uint32_t kRootIndexOffset = 0x20;
constexpr std::uint32_t kSectionKeyIndexOffset = 0x2c;
constexpr std::uint32_t kIndexCachedOffset = 0x10;
constexpr std::uint32_t kNodeBytes = 8;
constexpr std::uint32_t kValueTextOffset = 0x10;
constexpr std::uint32_t kRowKeyOffset = 0x24;
constexpr std::uint32_t kQueryBytes = 0x80;
constexpr std::uint32_t kMode = 0x00b10530;
constexpr std::uint32_t kFixedReject0 = 0x007b8e5c;
constexpr std::uint32_t kFixedReject1 = 0x007b907c;
constexpr std::array<std::uint8_t,7> kFallback{{'<','n','o','n','e','>',0}};

struct RawIndex32 {
    std::uint32_t table;
    std::int32_t count;
    std::uint32_t capacity;
    std::uint8_t sorted;
    std::uint8_t padding[3];
    std::uint32_t cached;
};
static_assert(sizeof(RawIndex32)==20 && offsetof(RawIndex32,cached)==0x10,
              "raw INI index offsets follow the accepted INI fixture contract");

std::int32_t signed32(std::uint32_t v) {
    return v<=0x7fffffffu ? static_cast<std::int32_t>(v)
        : -1-static_cast<std::int32_t>(0xffffffffu-v);
}
std::uint32_t checked_add(std::uint32_t a,std::uint32_t b) {
    if(a>std::numeric_limits<std::uint32_t>::max()-b)
        throw std::domain_error("B273 guest address wrap excluded");
    return a+b;
}
RawIndex32 read_index(Memory& m,std::uint32_t address) {
    RawIndex32 result{};
    result.table=m.r32(address);
    result.count=signed32(m.r32(checked_add(address,4)));
    result.capacity=m.r32(checked_add(address,8));
    result.sorted=static_cast<std::uint8_t>(m.r8(checked_add(address,12)));
    for(unsigned i=0;i<3;++i) result.padding[i]=static_cast<std::uint8_t>(m.r8(checked_add(address,13+i)));
    result.cached=m.r32(checked_add(address,kIndexCachedOffset));
    return result;
}
std::vector<std::uint8_t> read_string(Memory& m,std::uint32_t address,
                                      std::size_t max_bytes,const char* what) {
    if(!address) throw std::domain_error(what);
    std::vector<std::uint8_t> bytes;
    bytes.reserve(max_bytes);
    for(std::size_t i=0;i<max_bytes;++i) {
        const auto c=static_cast<std::uint8_t>(m.r8(checked_add(address,static_cast<std::uint32_t>(i))));
        bytes.push_back(c);
        if(!c) return bytes;
    }
    throw std::domain_error(what);
}
struct AdaptedIni {
    IniValue value{};
    IniIndexEntry key_entry{};
    IniSection section{};
    IniIndexEntry section_entry{};
    IniIndex root{};
    std::vector<std::uint8_t> stored_text;
    std::uint32_t root_index_address{};
    std::uint32_t root_entry_address{};
    std::uint32_t section_address{};
    std::uint32_t key_index_address{};
    std::uint32_t key_entry_address{};
};

AdaptedIni adapt_single_sorted_hit(Memory& m,std::uint32_t receiver,
                                   const std::vector<std::uint8_t>& section_name,
                                   const std::vector<std::uint8_t>& key_name) {
    AdaptedIni a{};
    a.root_index_address=checked_add(receiver,kRootIndexOffset);
    const auto raw_root=read_index(m,a.root_index_address);
    if(raw_root.count!=1 || raw_root.sorted==0 || raw_root.cached!=0 || !raw_root.table)
        throw std::domain_error("B273 domain requires one sorted, uncached raw section-index entry");
    a.root_entry_address=raw_root.table;
    const auto root_hash=signed32(ini_name_hash(section_name.data(),section_name.size()-1,nullptr));
    if(signed32(m.r32(a.root_entry_address))!=root_hash)
        throw std::domain_error("B273 raw section index hash does not match the real query");
    a.section_address=m.r32(checked_add(a.root_entry_address,4));
    if(!a.section_address) throw std::domain_error("B273 positive INI hit requires a real section object");

    a.key_index_address=checked_add(a.section_address,kSectionKeyIndexOffset);
    const auto raw_keys=read_index(m,a.key_index_address);
    if(raw_keys.count!=1 || raw_keys.sorted==0 || raw_keys.cached!=0 || !raw_keys.table)
        throw std::domain_error("B273 domain requires one sorted, uncached raw key-index entry");
    a.key_entry_address=raw_keys.table;
    const auto key_hash=signed32(ini_name_hash(key_name.data(),key_name.size()-1,nullptr));
    if(signed32(m.r32(a.key_entry_address))!=key_hash)
        throw std::domain_error("B273 raw key index hash does not match the real query");
    const auto raw_value=m.r32(checked_add(a.key_entry_address,4));
    if(!raw_value) throw std::domain_error("B273 positive INI hit requires a real value object");
    const auto text_address=m.r32(checked_add(raw_value,kValueTextOffset));
    a.stored_text=read_string(m,text_address,256,"B273 INI text must terminate within the bounded source span");
    a.value.text=a.stored_text.data();
    a.key_entry={key_hash,&a.value};
    a.section.keys={&a.key_entry,1,1,nullptr};
    a.section_entry={root_hash,&a.section};
    a.root={&a.section_entry,1,1,nullptr};
    return a;
}

struct Table { std::uint32_t array_va,count_va; };
constexpr std::array<Table,4> kTables{{
    {0x00a27fa4,0x00a27fb0}, // original scanner 0x5094c0
    {0x00a1e07c,0x00a1e088}, // original scanner 0x6ff450
    {0x00a255ac,0x00a255b8}, // original scanner 0x41be60
    {0x00a1e00c,0x00a1e018}, // original scanner 0x458050
}};
std::uint32_t compare(Memory& m,std::uint32_t first,std::uint32_t second) {
    Inputs args{};
    args.arg[0]=first;
    args.arg[1]=second;
    return crt_b83::fun_0076d860(m,args);
}
std::int32_t scan(Memory& m,std::uint32_t query,const Table& table,
                  bool first_scanner) {
    if(first_scanner &&
       (compare(m,query,kFixedReject0)==0 || compare(m,query,kFixedReject1)==0))
        return -1;
    const auto count=signed32(m.r32(table.count_va));
    if(count<=0) return -1;
    if(count>4) throw std::domain_error("B273 fixture table count is bounded to four rows");
    const auto array=m.r32(table.array_va);
    if(!array) throw std::domain_error("B273 positive table count requires readable pointer array");
    for(std::int32_t i=0;i<count;++i) {
        const auto slot=checked_add(array,static_cast<std::uint32_t>(i)*4u);
        const auto row=m.r32(slot);
        if(!row) throw std::domain_error("B273 counted rows require non-null row pointers");
        const auto key=checked_add(row,kRowKeyOffset);
        const auto row_text=read_string(m,key,8,"B273 row key must terminate within eight ASCII bytes");
        for(const auto c:row_text)
            if(c>0x7f) throw std::domain_error("B273 row key must be ASCII");
        if(compare(m,key,query)==0) return i;
    }
    return -1;
}
}

std::uint32_t fun_0046bef0(Memory& m,const Inputs& input) {
    if(m.r32(kMode)!=0)
        throw std::domain_error("B273 finite contract requires accepted comparator mode zero");
    const auto receiver=input.cx;
    if(!receiver || !input.arg[0] || !input.arg[1])
        throw std::domain_error("B273 finite contract requires receiver and both INI names");
    const auto section_name=read_string(m,input.arg[0],32,"B273 section name must terminate within 32 bytes");
    const auto key_name=read_string(m,input.arg[1],32,"B273 key name must terminate within 32 bytes");
    auto adapted=adapt_single_sorted_hit(m,receiver,section_name,key_name);
    adapted.value.text=adapted.stored_text.data(); // Rebind after the adapted object is returned by value.
    adapted.key_entry.value=&adapted.value;
    adapted.section.keys={&adapted.key_entry,1,1,nullptr};
    adapted.section_entry.value=&adapted.section;
    adapted.root={&adapted.section_entry,1,1,nullptr};

    std::array<std::uint8_t,kQueryBytes> query{};
    const auto length=fun_0050ddf0(&adapted.root,section_name.data(),key_name.data(),
                                   kFallback.data(),query.data(),kQueryBytes,
                                   IniOperations{ini_name_hash,nullptr,nullptr,nullptr,nullptr,nullptr});
    if(adapted.root.cached!=&adapted.section_entry ||
       adapted.section.keys.cached!=&adapted.key_entry)
        throw std::domain_error("B273 finite INI route must hit both sorted logical indexes");
    // The original helper caches exact raw table-node addresses. Propagate the
    // accepted logical index result back to the observed raw +0x10 cache fields.
    m.w32(checked_add(adapted.root_index_address,kIndexCachedOffset),adapted.root_entry_address);
    m.w32(checked_add(adapted.key_index_address,kIndexCachedOffset),adapted.key_entry_address);
    if(length<=0 || length>7 || query[7]!=0)
        throw std::domain_error("B273 query must be a nonempty bounded value with NUL in first eight bytes");
    for(std::int32_t i=0;i<length;++i)
        if(query[static_cast<std::size_t>(i)]>0x7f)
            throw std::domain_error("B273 comparator domain is ASCII only");

    // The original output is a stack-local 0x80-byte buffer. Give the accepted
    // comparator a checked guest-address span over this local storage so it can
    // exercise its real Memory/Inputs implementation without a made-up callback.
    const auto query_address=static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(query.data()));
    if(!query_address)
        throw std::domain_error("B273 guest x86 build required for the local query span");
    leaf::Memory local_query(query.data(),query_address,kQueryBytes);
    // Copy only the span registry, not its backing bytes. This keeps the
    // temporary query mapping scoped to this invocation when one Memory object
    // is reused by the case driver.
    Memory query_memory=m;
    query_memory.add(local_query);

    for(std::size_t n=0;n<kTables.size();++n) {
        const auto index=scan(query_memory,query_address,kTables[n],n==0);
        if(index>=0) {
            const auto array=query_memory.r32(kTables[n].array_va);
            return query_memory.r32(checked_add(array,static_cast<std::uint32_t>(index)*4u));
        }
    }
    return 0;
}
}
