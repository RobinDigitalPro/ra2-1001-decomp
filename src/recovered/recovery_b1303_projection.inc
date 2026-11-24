using U = std::uint32_t;
using I = std::int32_t;
constexpr U kMap = 0x702c0u;
constexpr U kHeight = 0x75960u;
constexpr U kConvert = 0x297fb0u;
constexpr U kOuterReturn = 0x13579bdfu;
constexpr U kPrivateStackBase = 0x7e000000u;
constexpr U kHeightStack = kPrivateStackBase + 0x1000u;
constexpr U kConvertStack = kPrivateStackBase + 0x8100u;
constexpr U kOutput = kPrivateStackBase + 0x0200u;

const ra2::recovered::direct_b33::Entry& height_entry() {
    for (const auto& e : ra2::recovered::direct_b33::entries_a())
        if (e.rva == kHeight) return e;
    throw std::runtime_error("missing accepted 0x75960 translation");
}
struct MapContext { Memory* memory{}; ra2::platform::x87::State* fp{}; };
void invoke_map(Memory& m, ra2::recovered::direct_b33::State& s,
                const ra2::recovered::direct_b33::Call& call, void* raw) {
    auto& ctx = *static_cast<MapContext*>(raw);
    if (call.target != kMap || call.argument_words != 1u || call.cleanup != 4u)
        throw std::runtime_error("0x75960 reached an unreviewed call boundary");
    ra2::recovered::map_b106::Inputs in{};
    in.cx = s.cx; in.arg[0] = m.r32(call.sp + 4u); in.fp = *ctx.fp;
    s.ax = ra2::recovered::map_b106::fun_004702c0(*ctx.memory, in);
    *ctx.fp = in.fp;
}
struct HeightOutput { U x{}, y{}, height{}; };
HeightOutput call_height(Memory& m, U entity, U ebp, ra2::platform::x87::State& fp) {
    std::array<std::uint8_t, 0x5000> stack_bytes{};
    Memory cm = m;
    ra2::recovered::leaf::Memory stack(stack_bytes.data(), kPrivateStackBase,
                                       std::uint32_t(stack_bytes.size()));
    cm.add(stack);
    auto s = ra2::recovered::direct_b33::State{};
    s.cx = entity; s.bp = ebp; s.bx = 0x2468ace0u;
    s.si = 0x10203040u; s.di = 0x50607080u;
    auto& e = height_entry();
    auto f = ra2::recovered::direct_b33::Frame{
        kHeightStack, kHeightStack, kOuterReturn, kOuterReturn, 4u, 1u, kMap};
    cm.w32(kHeightStack, kOuterReturn); cm.w32(kHeightStack+4u, kOutput);
    cm.w32(kHeightStack+8u, ebp);
    MapContext context{&cm, &fp};
    const ra2::recovered::direct_b33::Operations ops{invoke_map, &context};
    e.function(cm, s, f, ops);
    if (f.sp != kHeightStack+8u || s.ax != kOutput)
        throw std::runtime_error("0x75960 stack/result contract differs");
    return {cm.r32(kOutput), cm.r32(kOutput+4u), cm.r32(kOutput+8u)};
}
U call_converter(Memory& m, U ecx, ra2::platform::x87::State& fp) {
    std::array<std::uint8_t, 0x1000> stack_bytes{};
    Memory cm = m;
    ra2::recovered::leaf::Memory stack(stack_bytes.data(), kPrivateStackBase+0x8000u,
                                       std::uint32_t(stack_bytes.size()));
    cm.add(stack);
    const auto& entries = ra2::recovered::floating_callers_b40::entries_a();
    const ra2::recovered::floating_callers_b40::Entry* selected = nullptr;
    for (const auto& e : entries) if (e.rva == kConvert) selected = &e;
    if (!selected) throw std::runtime_error("missing accepted 0x297fb0 translation");
    auto s = ra2::recovered::floating_callers_b40::State{}; s.cx = ecx; s.fp = fp;
    auto f = ra2::recovered::floating_callers_b40::Frame{};
    f.entry_sp = kConvertStack; f.sp = kConvertStack; f.return_sp = kConvertStack;
    f.outer_return = kOuterReturn; cm.w32(kConvertStack, kOuterReturn);
    selected->function(cm, s, f, {});
    if (f.sp != kConvertStack+4u) throw std::runtime_error("0x297fb0 stack contract differs");
    fp = s.fp; return s.ax;
}

I arithmetic_shift(U value, unsigned bits) {
    return static_cast<I>(ra2::recovered::global_b26::sar(value, bits));
}
U sign_word(U value) { return I(value) < 0 ? 0xffffffffu : 0u; }
std::pair<I, I> project(HeightOutput h, U converted) {
    U eax = h.x * 3u; eax = eax + eax * 4u; eax <<= 2u;
    U edx = sign_word(eax); eax -= edx;
    U edi = U(arithmetic_shift(eax, 1u));
    eax = h.x * 3u; eax = eax + eax * 4u; eax <<= 1u;
    edx = sign_word(eax); eax -= edx;
    U ecx = eax;
    eax = h.y << 4u; eax -= h.y; eax = 0u - eax; eax <<= 2u;
    edx = sign_word(eax); eax -= edx; eax = U(arithmetic_shift(eax, 1u));
    edi += eax;
    eax = h.y * 3u; ecx = U(arithmetic_shift(ecx, 1u));
    eax = eax + eax * 4u; eax <<= 1u;
    edx = sign_word(eax); eax -= edx; eax = U(arithmetic_shift(eax, 1u));
    ecx += eax;
    eax = edi; edx = sign_word(eax) & 0xffu; eax += edx;
    const I screen_x = arithmetic_shift(eax, 8u);
    eax = ecx; edx = sign_word(eax) & 0xffu; eax += edx;
    const I screen_y = arithmetic_shift(eax, 8u) - I(converted);
    return {screen_x, screen_y};
}

