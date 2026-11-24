#include "recovery_b367.hpp"

#include <stdexcept>
#include <utility>

namespace ra2::recovery_b367 {
namespace {
constexpr std::uint32_t kCache0 = 0x00a5ab48u;
constexpr std::uint32_t kCache1 = 0x00a5ab4cu;
constexpr std::uint32_t kCache2 = 0x00a5ab50u;
constexpr std::uint32_t kCache3 = 0x00a5ab54u;
constexpr std::uint32_t kFlags = 0x00a5ab58u;
constexpr std::uint32_t kFilename = 0x007d2238u;
constexpr std::uint32_t kInvalidHandle = 0xffffffffu;

std::string guest_string(const recovered::global_b26::Memory& m,
                         std::uint32_t address) {
    std::string out;
    for (unsigned n = 0; n != 64; ++n) {
        const auto ch = static_cast<char>(m.r8(address + n));
        if (!ch) return out;
        out.push_back(ch);
    }
    throw std::runtime_error("bounded guest filename is not terminated");
}

class Reader {
public:
    Reader(recovered::global_b26::Memory& memory, FileApi& files,
           std::string filename)
        : memory_(memory), files_(files), filename_(std::move(filename)) {}

    bool is_open() const { return handle_ != kInvalidHandle; }

    bool open_read() {
        if (is_open()) close();
        handle_ = files_.create_existing_read(filename_, 0x80000000u, 3u,
                                               3u, 0x8000080u);
        // 0x63021b tests the size cached at receiver+0xc. After Size(),
        // reopening takes slot+0x28 Seek(0, FILE_BEGIN), even with base offset 0.
        if (cached_size_ != 0xffffffffu &&
            files_.set_file_pointer(handle_, 0u, 0u, 0u) == 0xffffffffu)
            throw std::runtime_error("B367 selected reopen seek failed");
        return handle_ != kInvalidHandle;
    }

    bool exists() {
        const auto handle = files_.create_existing_read(filename_, 0x80000000u,
                                                         1u, 3u, 0x80u);
        if (handle == kInvalidHandle) return false;
        const auto closed = files_.close_handle(handle);
        if (!closed) {
            (void)files_.get_last_error();
            return false;
        }
        return true;
    }

    std::uint32_t size() {
        if (!is_open() && !open_read()) return 0xffffffffu;
        const auto n = files_.get_file_size(handle_);
        if (n == 0xffffffffu) (void)files_.get_last_error();
        close();
        cached_size_ = n; // 0x630790, after closing the temporary size handle.
        return n;
    }

    std::uint32_t read_all(std::uint32_t destination,
                           std::uint32_t requested) {
        if (!is_open() && !open_read()) return 0;
        if (files_.set_file_pointer(handle_, 0u, 0u, 1u) == 0xffffffffu) {
            (void)files_.get_last_error();
            close();
            return 0;
        }
        std::uint32_t total = 0;
        while (total < requested) {
            std::uint32_t transferred = 0;
            if (!files_.read_file(handle_, destination + total,
                                  requested - total, transferred)) {
                (void)files_.get_last_error();
                break;
            }
            if (!transferred) break;
            total += transferred;
        }
        // Original 0x630330 clears this global immediately before its final
        // slot+0x34 close when any bytes were transferred.
        if (total != 0u) memory_.w8(0x00a9e184u, 0u);
        close();
        return total;
    }

    void close() {
        if (!is_open()) return;
        (void)files_.close_handle(handle_);
        handle_ = kInvalidHandle;
    }

private:
    recovered::global_b26::Memory& memory_;
    FileApi& files_;
    std::string filename_;
    std::uint32_t handle_ = kInvalidHandle;
    std::uint32_t cached_size_ = 0xffffffffu;
};

std::uint32_t load_one(recovered::global_b26::Memory& m,
                      platform::ordinary_heap::Heap& heap, FileApi& files,
                      std::uint32_t name_address) {
    Reader reader(m, files, guest_string(m, name_address));
    if (!reader.exists()) return 0;
    const auto length = reader.size();
    if (length == 0xffffffffu || length == 0u || length > 0x100000u)
        return 0;
    const auto buffer = heap.allocate(length);
    if (!buffer) return 0;
    if (reader.read_all(buffer, length) != length)
        throw std::runtime_error("B367 selected complete-read route returned a short buffer");
    return buffer;
}
} // namespace

std::uint32_t fun_005ce490(recovered::global_b26::Memory& m,
                           const recovered::global_b26::Inputs& in,
                           platform::ordinary_heap::Heap& heap,
                           FileApi& files) {
    (void)in; // Original root has no stack arguments and does not read input registers.
    if (m.r32(kCache0) != 0u)
        throw std::runtime_error("B367 route requires the reviewed first-cache miss");
    const auto p = load_one(m, heap, files, kFilename);
    if (!p) throw std::runtime_error("B367 selected positive file-load route failed");
    m.w32(kCache0, p);
    m.w8(kFlags, 1u);
    if (m.r32(kCache1) == 0u || m.r32(kCache2) == 0u || m.r32(kCache3) == 0u)
        throw std::runtime_error("B367 fixture must supply the remaining cache pointers");
    return m.r32(kCache3);
}

} // namespace ra2::recovery_b367
