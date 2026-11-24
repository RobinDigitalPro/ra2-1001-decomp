// file name inferred from class name; not proven by a C:\RA2 string
// PKSTRAW.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Public-key encryption straw: the first data drawn is a random Blowfish key that is encrypted
// (or decrypted) with a PKey; the rest of the data is drawn through a Blowfish straw.
// RTTI .?AVPKStraw@@ (bases Straw), vtable 0x793178:
//   0 scalar deleting dtor 0x607d30, 1 Get_From(Straw *) 0x607a80, 2 Get 0x607af0,
//   3 Get_From(Straw &) 0x607d20.
// Code range 0x607a10..0x607d82; PlanMgr's static initializers follow at 0x607d90.
// Member names are provisional (Westwood style); offsets come from the code.
#include <string.h>

// ---- local declarations (to be moved to headers by the integrator) ----

class Straw {
public:
    Straw() : ChainTo(0), ChainFrom(0) {}
    virtual ~Straw();                               // 0x6906b0
    virtual void Get_From(Straw * straw);           // 0x6906f0
    void Get_From(Straw & straw) { Get_From(&straw); }
    virtual int Get(void * source, int slen);       // 0x690740

    Straw * ChainTo;        // +0x04
    Straw * ChainFrom;      // +0x08
};

// Random number straw (RTTI .?AVRandomStraw@@, vtable 0x793d64); only Get is used here.
class RandomStraw : public Straw {
public:
    virtual int Get(void * source, int slen);       // 0x634c20
};

class BlowfishEngine {
public:
    ~BlowfishEngine();                              // 0x4354b0
};

enum { BLOWFISH_KEY_SIZE = 56 };

// RTTI .?AVBlowStraw@@, vtable 0x791448 (BLOWSTRAW.CPP).
class BlowStraw : public Straw {
public:
    typedef enum CryptControl { ENCRYPT, DECRYPT } CryptControl;
    BlowStraw(CryptControl control) : BF(0), Counter(0), Control(control) {}
    virtual ~BlowStraw() { delete BF; BF = 0; }
    virtual int Get(void * source, int slen);       // 0x435700
    void Key(void const * key, int length);         // 0x4357f0

    BlowfishEngine * BF;    // +0x0c
    char Buffer[8];         // +0x10
    int Counter;            // +0x18
    CryptControl Control;   // +0x1c
};

// Multi-precision integer of 64 32-bit digits (Int<64> in PK.CPP; provisional).
struct BigInt64 {
    unsigned long reg[64];
};

// Public key (PK.CPP), 0x204 bytes.
class PKey {
public:
    int Encrypt(void const * source, int slen, void * dest) const;  // 0x607100
    int Decrypt(void const * source, int slen, void * dest) const;  // 0x607230
    int Plain_Block_Size() const { return (BitPrecision - 1) / 8; }
    int Crypt_Block_Size() const { return Plain_Block_Size() + 1; }
    int Block_Count(int plaintext_length) const { return ((plaintext_length - 1) / Plain_Block_Size()) + 1; }

    BigInt64 Modulus;       // +0x000
    BigInt64 Exponent;      // +0x100
    int BitPrecision;       // +0x200
};

class PKStraw : public Straw {
public:
    typedef enum CryptControl { ENCRYPT, DECRYPT } CryptControl;
    PKStraw(CryptControl control, RandomStraw & rnd);
    virtual void Get_From(Straw * straw);
    virtual void Get_From(Straw & straw) { Get_From(&straw); }
    virtual int Get(void * source, int length);
    void Key(PKey * key);

    int Encrypted_Key_Length() const;
    int Plain_Key_Length() const;

    bool IsGettingKey;      // +0x0c
    RandomStraw & Rand;     // +0x10
    BlowStraw BF;           // +0x14
    CryptControl Control;   // +0x34
    PKey * CipherKey;       // +0x38
    char Buffer[256];       // +0x3c
    int Counter;            // +0x13c
    int BytesLeft;          // +0x140
};

// ---- end of local declarations ----

// 0x607a10
PKStraw::PKStraw(CryptControl control, RandomStraw & rnd) :
    IsGettingKey(true),
    Rand(rnd),
    BF((control == ENCRYPT) ? BlowStraw::ENCRYPT : BlowStraw::DECRYPT),
    Control(control),
    CipherKey(0),
    Counter(0),
    BytesLeft(0)
{
    Straw::Get_From(BF);
}

// 0x607a80
void PKStraw::Get_From(Straw * straw)
{
    if (BF.ChainTo != straw) {
        if (straw != 0 && straw->ChainFrom != 0) {
            straw->ChainFrom->Get_From(0);
            straw->ChainFrom = 0;
        }
        if (BF.ChainTo != 0) {
            BF.ChainTo->ChainFrom = 0;
        }
        BF.ChainTo = straw;
        BF.ChainFrom = this;
        ChainTo = &BF;
        if (straw != 0) {
            straw->ChainFrom = this;
        }
    }
}

// 0x607ad0
void PKStraw::Key(PKey * key)
{
    CipherKey = key;
    if (key != 0) {
        IsGettingKey = true;
    }
    Counter = 0;
    BytesLeft = 0;
}

// 0x607af0
int PKStraw::Get(void * source, int length)
{
    if (source == 0 || length < 1 || CipherKey == 0) {
        return Straw::Get(source, length);
    }

    int total = 0;
    if (IsGettingKey) {
        if (Control == DECRYPT) {
            char cbuffer[256];
            int got = Straw::Get(cbuffer, Encrypted_Key_Length());
            if (got != Encrypted_Key_Length()) {
                return 0;
            }
            CipherKey->Decrypt(cbuffer, got, Buffer);
            BF.Key(Buffer, BLOWFISH_KEY_SIZE);
        } else {
            char buffer[256];
            memset(buffer, 0, sizeof(buffer));
            Rand.Get(buffer, BLOWFISH_KEY_SIZE);
            Counter = BytesLeft = CipherKey->Encrypt(buffer, Plain_Key_Length(), Buffer);
            BF.Key(buffer, BLOWFISH_KEY_SIZE);
        }
        IsGettingKey = false;
    }

    if (BytesLeft > 0) {
        int tocopy = (length < BytesLeft) ? length : BytesLeft;
        memmove(source, &Buffer[Counter - BytesLeft], tocopy);
        source = ((char *)source) + tocopy;
        BytesLeft -= tocopy;
        length -= tocopy;
        total += tocopy;
    }

    return total + Straw::Get(source, length);
}

// 0x607cc0
int PKStraw::Encrypted_Key_Length() const
{
    if (CipherKey == 0) return 0;
    return CipherKey->Block_Count(BLOWFISH_KEY_SIZE) * CipherKey->Crypt_Block_Size();
}

// 0x607cf0
int PKStraw::Plain_Key_Length() const
{
    if (CipherKey == 0) return 0;
    return CipherKey->Block_Count(BLOWFISH_KEY_SIZE) * CipherKey->Plain_Block_Size();
}
