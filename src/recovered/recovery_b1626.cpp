#include "recovered/recovery_b1626.hpp"

#include <stdexcept>

namespace ra2::recovered::b1626 {
namespace {
void need(bool ok, const char* why) {
    if (!ok) throw std::domain_error(why);
}

void require_ascii(Memory& m, U address, const char* expected, U length,
                   const char* why) {
    for (U n = 0; n < length; ++n)
        need(m.r8(address + n) == static_cast<unsigned char>(expected[n]), why);
    need(m.r8(address + length) == 0, why);
}

void require_bounded_ascii(Memory& m, U address, U capacity, const char* why) {
    for (U n = 0; n < capacity; ++n) {
        if (m.r8(address + n) == 0) return;
    }
    need(false, why);
}

void require_empty_utf16(Memory& m, U address) {
    need(m.r16(address) == 0, "1626 expected terminating empty UTF-16 input");
}

HANDLE open_existing(Api& api, LPCSTR path, DWORD share, DWORD flags) {
    const HANDLE h = api.create_file_a(path, GENERIC_READ, share, nullptr,
        OPEN_EXISTING, flags, nullptr);
    need(h != INVALID_HANDLE_VALUE, "1626 genuine CreateFileA success required");
    return h;
}

void close_real(Api& api, HANDLE h, const char* why) {
    need(api.close_handle(h) != FALSE, why);
}
} // namespace

U run(U root, Memory& m, const Inputs& i, Heap& heap, Api& api) {
    need(root == 0x198a80u, "1626 selected root only");
    need(i.cx != 0, "1626 receiver required");
    need(api.get_dlg_item && api.enable_window && api.create_file_a &&
         api.get_file_size && api.close_handle,
         "1626 actual API bindings required");

    // Validate the complete selected public fixture before the first UI/API or
    // heap effect. A286A4 is the actual PE-initial zero network state: the
    // following +3C query returns zero and the computed +8 call is not reached.
    need(m.r32(0xa286a4u) == 0,
         "1626 selected inactive-connection route requires PE-initial zero");
    need(m.r32(0xa255e4u) == 0,
         "1626 selected metadata index is zero");
    const U pointer_array = m.r32(0xa25c0cu);
    need(pointer_array != 0, "1626 owned metadata pointer array required");
    const U record = m.r32(pointer_array);
    need(record != 0, "1626 selected public metadata record required");
    const U name_address = record + 0x58u;
    constexpr char name_literal[] = "Map_1626.ini";
    constexpr U name_length = 12;
    require_ascii(m, name_address, name_literal, name_length,
                  "1626 exact mixed-case filename required");
    require_bounded_ascii(m, record + 0x15cu, 32u,
                          "1626 digest field must be bounded");
    (void)m.r8(record + 0x17cu); // Public byte feeds private data only on this route.
    require_empty_utf16(m, 0xa256d0u);

    const U parent_raw = m.r32(i.cx);
    need(parent_raw != 0, "1626 genuine parent HWND required");

    // Root first obtains child ID1, then disables it. EnableWindow returns
    // FALSE when the child was already enabled, matching this route's prestate.
    const HWND parent = reinterpret_cast<HWND>(static_cast<std::uintptr_t>(parent_raw));
    const HWND child = api.get_dlg_item(parent, 1);
    need(child != nullptr, "1626 owned child ID1 required");
    const BOOL was_disabled = api.enable_window(child, FALSE);
    need(was_disabled == FALSE,
         "1626 ID1 child must have been enabled before EnableWindow(FALSE)");

    // 46FD50 -> 42F550 -> 630110 clones the exact 13-byte name into one
    // Nominal CRT request of 13 bytes, rounded to 16 before actual HeapAlloc.
    // Preserve the three untouched rounded tail bytes.
    const U owned_name = heap.allocate(13u);
    need(owned_name != 0, "1626 real owned filename allocation required");
    for (U n = 0; n < name_length; ++n)
        heap.w8(owned_name + n, m.r8(name_address + n));
    heap.w8(owned_name + name_length, 0);
    const LPCSTR path = reinterpret_cast<LPCSTR>(static_cast<std::uintptr_t>(owned_name));

    // Physical availability probes: each actual open is closed immediately.
    for (unsigned n = 0; n != 2; ++n) {
        const HANDLE probe = open_existing(api, path, FILE_SHARE_READ,
                                            FILE_ATTRIBUTE_NORMAL);
        close_real(api, probe, "1626 genuine availability-probe CloseHandle success required");
    }

    // Open1 uses the read/share-3/sequential mode. The real 40-byte file is
    // queried by 630720 using GetFileSize(handle, nullptr); no ReadFile occurs.
    const HANDLE input = open_existing(api, path,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN);
    const DWORD file_size = api.get_file_size(input, nullptr);
    need(file_size == 40u, "1626 genuine 40-byte GetFileSize result required");
    close_real(api, input, "1626 actual opened-file CloseHandle success required");

    // The size enters only a root-private configuration buffer. With the
    // selected zero network state there is no public packet publication or
    // connection callback. The archive uppercase path is also not reached:
    // both availability probes succeed and the clone stays mixed case.
    return heap.release(owned_name); // actual full HeapFree BOOL is root EAX
}
} // namespace ra2::recovered::b1626

