#include "recovered/ini_mutation.hpp"

namespace ra2::recovered {
namespace {
std::int32_t signed_capacity(std::uint32_t bits) {
    return bits<=0x7fffffffu?static_cast<std::int32_t>(bits):-1-static_cast<std::int32_t>(0xffffffffu-bits);
}
void detach(IniLink& node) {
    if(node.next && node.previous) {
        node.previous->next=node.next;
        node.next->previous=node.previous;
        node.previous=nullptr; node.next=nullptr;
    }
}
}
std::uint8_t fun_00510620(IniIndex* index,std::int32_t amount,const IniMutationOperations& ops) {
    if(amount<0)return 0;
    const auto bytes=(index->spare+static_cast<std::uint32_t>(amount))*8u;
    auto* fresh=ops.allocate_entries(bytes,ops.context);
    if(!fresh)return 0;
    for(std::int32_t i=0;i<index->count;++i) {
        fresh[i].key=index->entries[i].key;
        fresh[i].value=index->entries[i].value;
    }
    ops.release_storage(index->entries,ops.context);
    index->entries=fresh; index->spare+=static_cast<std::uint32_t>(amount);
    index->cached=nullptr;
    return 1;
}
std::uint8_t fun_00510150(IniIndex& index,const std::int32_t* key,void* const* value,
                        const IniMutationOperations& ops) {
    const auto capacity=signed_capacity(index.spare);
    if(index.count+1>capacity) {
        const auto amount=capacity==0?10:capacity;
        if(!fun_00510620(&index,amount,ops))return 0;
    }
    index.entries[index.count].key=*key;
    index.entries[index.count].value=*value;
    ++index.count; index.sorted=0;
    return 1;
}
std::uint8_t fun_00510360(IniIndex& index,const std::int32_t* key,const IniOperations& ops) {
    auto* found=fun_005106d0(index,key,ops);
    if(!found)return 0;
    auto at=static_cast<std::int32_t>(found-index.entries)+1;
    for(;at<index.count;++at) {
        index.entries[at-1].key=index.entries[at].key;
        index.entries[at-1].value=index.entries[at].value;
    }
    --index.count; index.entries[index.count].key=0; index.entries[index.count].value=nullptr;
    index.cached=nullptr;
    return 1;
}
IniLink* fun_0040e160(IniLink& node) {
    node.next=nullptr; node.previous=nullptr; node.original_tag=0x785afc;
    return &node;
}
IniLink* fun_0040e180(IniLink& position,IniLink& node) {
    detach(node);
    auto* next=position.next;
    node.previous=&position; node.next=next;
    // Reread position.next after the stores: position and node may coincide.
    if(position.next)position.next->previous=&node;
    position.next=&node;
    return &node;
}
IniLinkedValue* fun_0050ffb0(IniLinkedValue& node,std::uint32_t a,std::uint32_t b,std::uint32_t c,
    std::uint32_t d,std::uint32_t e,std::uint32_t f,std::uint32_t g) {
    node.link.next=nullptr; node.link.previous=nullptr;
    node.words={a,b,c,d,f,g,e}; node.link.original_tag=0x78eb9c;
    return &node;
}
IniLinkedList* fun_00510000(IniLinkedList& list) {
    fun_0040e160(list.head); fun_0040e160(list.tail);
    list.head.next=&list.tail; list.tail.previous=&list.head;
    list.original_tag=0x78ebac;
    return &list;
}
IniLinkedList* fun_00510070(IniLinkedList& list,std::uint32_t flags,const IniMutationOperations& ops) {
    auto* result=&list;
    list.original_tag=0x785af4;
    while(list.head.next && list.head.next->next && list.head.next->previous)detach(*list.head.next);
    list.tail.original_tag=0x785afc; detach(list.tail);
    list.head.original_tag=0x785afc; detach(list.head);
    if(flags&1)ops.release_storage(result,ops.context);
    return result;
}
}
