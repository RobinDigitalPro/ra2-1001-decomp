// Guest graph adapter reused from accepted Block71; fixed field map independently traced at RVA244900.
#include "recovered/ini_b82.hpp"

#include "recovered/crt_classify.hpp"
#include "recovered/ini_bulk.hpp"
#include "recovered/ini_integer.hpp"
#include "recovered/name_hash.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>

namespace ra2::recovered::ini_b82 {
namespace {
using namespace ra2::recovered;


constexpr std::array<std::uint32_t,11> key_vas{0x7db68cu,0x7db67cu,0x7db670u,0x7bcd68u,0x7db664u,0x7db658u,0x7cc814u,0x7db64cu,0x7b8e48u,0x7db640u,0x7db634u};


std::vector<std::uint8_t> read_z(Memory& m,std::uint32_t p,std::uint32_t limit=256u) {
    if(!p) return {};
    std::vector<std::uint8_t> out;
    out.reserve(32);
    for(std::uint32_t k=0;k<limit;++k) {
        const auto byte=static_cast<std::uint8_t>(m.r8(p+k));
        out.push_back(byte);
        if(!byte) return out;
    }
    throw std::domain_error("Block82 INI string exceeds the bounded NUL span");
}

struct IndexView {
    std::uint32_t guest=0,table=0,count=0,initial_sorted=0;
    std::uint32_t cached_guest=0;
    IniIndex view{};
    std::vector<IniIndexEntry> nodes;
    std::vector<std::uint32_t> guest_values;

    void load_fields(Memory& m) {
        table=m.r32(guest);count=m.r32(guest+4u);initial_sorted=m.r8(guest+12u);
        if(count>16u) throw std::domain_error("Block82 INI index exceeds bounded node count");
        nodes.resize(count);guest_values.resize(count);
        for(std::uint32_t k=0;k<count;++k) {
            const auto at=table+k*8u;
            nodes[k].key=global_b26::s32(m.r32(at));
            guest_values[k]=m.r32(at+4u);
        }
        view.entries=count?nodes.data():nullptr;
        view.count=static_cast<std::int32_t>(count);
        view.sorted=static_cast<std::uint8_t>(initial_sorted);
        view.cached=nullptr;
    }
    void load_cached(Memory& m) {
        const auto raw=m.r32(guest+16u);
        cached_guest=raw;
        if(!raw) {view.cached=nullptr;return;}
        for(std::uint32_t k=0;k<count;++k) if(raw==table+k*8u) {
            view.cached=&nodes[k];return;
        }
        throw std::domain_error("Block82 INI cache pointer is outside its mapped node table");
    }
    std::uint32_t guest_value_for(const void* p,
                                  const std::vector<const void*>& local_values) const {
        for(std::uint32_t k=0;k<count;++k)
            if(local_values[k]==p) return guest_values[k];
        throw std::domain_error("Block82 INI node value is outside its bounded graph");
    }
    void flush(Memory& m,const std::vector<const void*>& local_values) {
        if(initial_sorted==0u && view.sorted!=0u) {
            for(std::uint32_t k=0;k<count;++k) {
                const auto at=table+k*8u;
                m.w32(at,static_cast<std::uint32_t>(nodes[k].key));
                m.w32(at+4u,guest_value_for(nodes[k].value,local_values));
            }
        }
        if(view.sorted!=initial_sorted) {
            m.w8(guest+12u,view.sorted);
            initial_sorted=view.sorted;
        }
        std::uint32_t cache=0;
        if(view.cached) {
            bool found=false;
            for(std::uint32_t k=0;k<count;++k) if(view.cached==&nodes[k]) {
                cache=table+k*8u;found=true;break;
            }
            if(!found) throw std::domain_error("Block82 INI cache result is outside its node table");
        }
        if(cache!=cached_guest) {
            m.w32(guest+16u,cache);
            cached_guest=cache;
        }
    }
};

struct LocalSection {
    std::uint32_t guest=0;
    IndexView keys;
    IniSection view{};
    std::vector<IniValue> values;
    std::vector<std::vector<std::uint8_t>> text_storage;
    std::vector<const void*> value_views;

    void initialize(Memory& m) {
        keys.guest=guest+0x2cu;
        keys.load_fields(m);
        values.resize(keys.count);text_storage.resize(keys.count);
        value_views.resize(keys.count);
        for(std::uint32_t k=0;k<keys.count;++k) {
            const auto value_guest=keys.guest_values[k];
            if(!value_guest) {
                keys.nodes[k].value=nullptr;
                value_views[k]=nullptr;
                continue;
            }
            const auto text_guest=m.r32(value_guest+0x10u);
            if(text_guest) {
                auto& bytes=text_storage[k];
                bytes.reserve(258);
                bytes.push_back(static_cast<std::uint8_t>(m.r8(text_guest-1u)));
                auto text=read_z(m,text_guest);
                bytes.insert(bytes.end(),text.begin(),text.end());
                values[k].text=bytes.data()+1u;
            } else values[k].text=nullptr;
            keys.nodes[k].value=&values[k];
            value_views[k]=&values[k];
        }
        keys.load_cached(m);
        view.keys=keys.view;
        view.first=nullptr; // Integer lookup never traverses the linked list.
    }
    void flush(Memory& m) {
        keys.view=view.keys;
        keys.flush(m,value_views);
    }
};

struct LocalGraph {
    IndexView root;
    std::vector<IniIndexEntry> root_nodes;
    std::vector<std::uint32_t> root_guest_values;
    std::vector<std::unique_ptr<LocalSection>> sections;
    std::vector<const void*> section_views;

    explicit LocalGraph(Memory& m,std::uint32_t root_va) {
        root.guest=root_va;root.load_fields(m);
        root_nodes.resize(root.count);root_guest_values=root.guest_values;
        sections.reserve(root.count);section_views.resize(root.count);
        for(std::uint32_t k=0;k<root.count;++k) {
            auto section=std::make_unique<LocalSection>();
            section->guest=root_guest_values[k];section->initialize(m);
            root_nodes[k].key=root.nodes[k].key;
            root_nodes[k].value=&section->view;
            section_views[k]=&section->view;
            sections.push_back(std::move(section));
        }
        root.nodes=std::move(root_nodes);
        root.view.entries=root.count?root.nodes.data():nullptr;
        root.load_cached(m);
    }
    void flush(Memory& m) {
        root.flush(m,section_views);
        for(auto& section:sections) section->flush(m);
    }
};

std::uint32_t hash_callback(const std::uint8_t* text,std::size_t length,void*) {
    return ini_name_hash(text,length,nullptr);
}
void sort_callback(IniIndexEntry* entries,std::int32_t count,IniIndexKind,void*) {
    // The supported graph uses distinct hashes, so this signed ordering is the
    // concrete comparator behavior needed by the accepted binary-search leaf.
    std::sort(entries,entries+count,[](const auto& a,const auto& b){return a.key<b.key;});
}
std::int32_t uppercase_ascii(std::int32_t value,void*) {
    return value>='A'&&value<='Z'?value+('a'-'A'):value;
}
struct ClassifierContext { const CrtClassification* ctype=nullptr; };
std::int32_t classify(std::uint8_t byte,std::uint32_t mask,void* opaque) {
    auto& c=*static_cast<ClassifierContext*>(opaque);
    if(!c.ctype) throw std::logic_error("Block82 INI classifier is not initialized");
    return static_cast<std::int32_t>(fun_0076e4cc(byte,*c.ctype)&mask);
}
}

std::uint32_t fun_00644900(Memory& m,const Inputs& input) {
    LocalGraph graph(m,input.arg[0]+0x20u);

    // The original CRT table's fixed single-byte initial state is the supported
    // environment for the already recovered integer scanner.
    std::array<std::uint16_t,257> flags{};
    const auto ctype_table=m.r32(0x00817560u)-2u;
    for(unsigned k=0;k<flags.size();++k)
        flags[k]=static_cast<std::uint16_t>(m.r16(ctype_table+k*2u));
    CrtClassification ctype{1,flags.data(),nullptr,nullptr};
    ClassifierContext classifier_context{&ctype};
    GetterHexContext hex_context{&ctype};
    IniOperations lookup{hash_callback,sort_callback,uppercase_ascii,nullptr,nullptr,nullptr};
    IntegerReadOperations operations{
        lookup,
        {classify,&classifier_context},
        uppercase_ascii,
        scan_getter_hex32_callback,&hex_context};

    const auto section=read_z(m,m.r32(0x793f40u),64u);
    const auto found=fun_0050be00(&graph.root.view,section.data(),lookup);
    graph.flush(m);
    if(!found)return 0;
    std::uint32_t eax=1u;
    for(unsigned k=0;k<key_vas.size();++k) {
        const auto key=read_z(m,key_vas[k],64u);
        eax=fun_0050cc40(&graph.root.view,section.data(),key.data(),m.r32(input.cx+0x109cu+k*4u),operations);
        graph.flush(m);
        m.w32(input.cx+0x109cu+k*4u,eax);
    }
    return (eax&0xffffff00u)|1u;
}
}
