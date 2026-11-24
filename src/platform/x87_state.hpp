#pragma once
// Platform x87 state adapter used by the Block39 recovered routines.
// Raw values and x87 state are explicit; this backend requires x86 GNU assembly.
// Masked exceptions only; single-threaded nonreentrant boundary. Pointer/opcode
// bookkeeping is not reconstructed. No original function bytes are invoked.
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#if !defined(__i386__) && !defined(__x86_64__)
#error This backend requires an x87-capable x86 target.
#endif
namespace ra2::platform::x87 {
struct alignas(16) Image {
    std::array<std::uint8_t,108> bytes{};
    std::uint16_t word(unsigned offset) const {
        std::uint16_t value{};std::memcpy(&value,bytes.data()+offset,2);return value;
    }
    void word(unsigned offset,std::uint16_t value){std::memcpy(bytes.data()+offset,&value,2);}
    static Image empty(std::uint16_t control=0x037f){Image value;value.word(0,control);value.word(8,0xffff);return value;}
};
static_assert(sizeof(Image::bytes)==108);
// FIP/FDP/opcode and reserved environment bytes are deliberately separate
// from this prospective numeric-state comparison. Their use by an original
// body must be excluded or modeled before any recovery acceptance.
inline bool same_numeric(const Image& a,const Image& b){
    return a.word(0)==b.word(0)&&a.word(4)==b.word(4)&&a.word(8)==b.word(8)&&
        std::memcmp(a.bytes.data()+28,b.bytes.data()+28,80)==0;
}
#define B39FP_CLOBBERS "memory","st","st(1)","st(2)","st(3)","st(4)","st(5)","st(6)","st(7)"
inline Image capture_host(){
    Image value;
    asm volatile("fnsave %0\n\tfrstor %0" : "=m"(value.bytes) : : B39FP_CLOBBERS);
    return value;
}
inline void restore_host(const Image& value){asm volatile("frstor %0" : : "m"(value.bytes) : B39FP_CLOBBERS);}
struct Raw80 {std::array<std::uint8_t,10> bytes{};};
static_assert(sizeof(Raw80)==10);
struct State {
    Image image=Image::empty();
    void require_masked()const{
        if((image.word(0)&0x3f)!=0x3f)throw std::invalid_argument("prototype requires all x87 exception masks");
    }
#define B39FP_INPUT(NAME,TYPE,OP) \
    void NAME(TYPE operand){require_masked();Image host; \
        asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t" OP " %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]" \
            : [host]"=m"(host.bytes),[guest]"+m"(image.bytes) : [operand]"m"(operand) : B39FP_CLOBBERS);}
    B39FP_INPUT(load32,std::uint32_t,"flds")
    B39FP_INPUT(load64,std::uint64_t,"fldl")
    B39FP_INPUT(add32,std::uint32_t,"fadds")
    B39FP_INPUT(add64,std::uint64_t,"faddl")
    B39FP_INPUT(multiply32,std::uint32_t,"fmuls")
    B39FP_INPUT(multiply64,std::uint64_t,"fmull")
    B39FP_INPUT(load80,Raw80,"fldt")
    B39FP_INPUT(load_integer32,std::uint32_t,"fildl")
    B39FP_INPUT(divide_integer32,std::uint32_t,"fidivl")
    B39FP_INPUT(subtract32,std::uint32_t,"fsubs")
    B39FP_INPUT(subtract64,std::uint64_t,"fsubl")
    B39FP_INPUT(reverse_subtract64,std::uint64_t,"fsubrl")
    B39FP_INPUT(divide64,std::uint64_t,"fdivl")
    B39FP_INPUT(compare32,std::uint32_t,"fcoms")
    B39FP_INPUT(compare_pop32,std::uint32_t,"fcomps")
    B39FP_INPUT(compare_pop64,std::uint64_t,"fcompl")
    B39FP_INPUT(load_control_masked,std::uint16_t,"fldcw")
#undef B39FP_INPUT
#define B39FP_OUTPUT(NAME,TYPE,OP) \
    TYPE NAME(){require_masked();Image host;TYPE operand{}; \
        asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t" OP " %[operand]\n\tfnsave %[guest]\n\tfrstor %[host]" \
            : [host]"=m"(host.bytes),[guest]"+m"(image.bytes),[operand]"=m"(operand) : : B39FP_CLOBBERS);return operand;}
    B39FP_OUTPUT(store32,std::uint32_t,"fsts")
    B39FP_OUTPUT(store64,std::uint64_t,"fstl")
    B39FP_OUTPUT(pop32,std::uint32_t,"fstps")
    B39FP_OUTPUT(pop64,std::uint64_t,"fstpl")
    B39FP_OUTPUT(pop_integer32,std::uint32_t,"fistpl")
    B39FP_OUTPUT(pop_integer64,std::uint64_t,"fistpll")
    B39FP_OUTPUT(control,std::uint16_t,"fnstcw")
    B39FP_OUTPUT(waiting_control,std::uint16_t,"fstcw")
    B39FP_OUTPUT(status,std::uint16_t,"fnstsw")
    B39FP_OUTPUT(waiting_status,std::uint16_t,"fstsw")
#undef B39FP_OUTPUT
#define B39FP_REGISTER(NAME,OP) \
    void NAME(){require_masked();Image host; \
        asm volatile("fnsave %[host]\n\tfrstor %[guest]\n\t" OP "\n\tfnsave %[guest]\n\tfrstor %[host]" \
            : [host]"=m"(host.bytes),[guest]"+m"(image.bytes) : : B39FP_CLOBBERS);}
    B39FP_REGISTER(compare_pop_st1,".byte 0xd8,0xd9")
    B39FP_REGISTER(pop_st0,".byte 0xdd,0xd8")
    B39FP_REGISTER(add_pop,".byte 0xde,0xc1")
    B39FP_REGISTER(load_st0,".byte 0xd9,0xc0")
    B39FP_REGISTER(load_st2,".byte 0xd9,0xc2")
    B39FP_REGISTER(exchange_st1,".byte 0xd9,0xc9")
    B39FP_REGISTER(subtract_pop,".byte 0xde,0xe9")
    B39FP_REGISTER(subtract_st0_st1,".byte 0xd8,0xe1")
    B39FP_REGISTER(change_sign,".byte 0xd9,0xe0")
    B39FP_REGISTER(divide_pop,".byte 0xde,0xf9")
    B39FP_REGISTER(load_st1,".byte 0xd9,0xc1")
    B39FP_REGISTER(compare_pop_twice,".byte 0xde,0xd9")
    B39FP_REGISTER(round_integer,".byte 0xd9,0xfc")
    B39FP_REGISTER(reverse_subtract_st1_st0,".byte 0xdc,0xe1")
    B39FP_REGISTER(two_to_x_minus_one,".byte 0xd9,0xf0")
    B39FP_REGISTER(load_one,".byte 0xd9,0xe8")
    B39FP_REGISTER(scale,".byte 0xd9,0xfd")
    B39FP_REGISTER(pop_st1,".byte 0xdd,0xd9")
    B39FP_REGISTER(clear_exceptions,".byte 0xdb,0xe2")
    B39FP_REGISTER(load_zero,".byte 0xd9,0xee")
    B39FP_REGISTER(reverse_divide_pop,".byte 0xde,0xf1")
    B39FP_REGISTER(load_pi,".byte 0xd9,0xeb")
    B39FP_REGISTER(wait,".byte 0x9b")
#undef B39FP_REGISTER
    void load_control(std::uint16_t value){
        if((value&0x3fu)!=0x3fu)throw std::invalid_argument("B39 current test domain excludes unmasked x87 exceptions");
        load_control_masked(value);
    }
};
#undef B39FP_CLOBBERS
}
