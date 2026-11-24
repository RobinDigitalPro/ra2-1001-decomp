#pragma once
// Fixed-capacity string (N characters + terminator). Inline code reconstructed from GAME.EXE
// (AbstractTypeClass constructor 0x410580 and Read_INI 0x4107e0). Name provisional.
#include <string.h>
#include "NOINIT.H"

template<int N> class FixedString {
public:
    FixedString() { Buffer[0] = '\0'; }
    FixedString(NoInitClass const &) {}
    FixedString(char const * s) {
        if (s == NULL) {
            Buffer[0] = '\0';
        } else {
            strncpy(Buffer, s, N);
            Buffer[N] = '\0';
        }
    }
    FixedString & operator = (FixedString const & that) {
        if (&that != this) {
            memcpy(Buffer, that.Buffer, sizeof(Buffer));
        }
        return *this;
    }
    operator char const * () const { return Buffer; }

    char Buffer[N + 1];
};
