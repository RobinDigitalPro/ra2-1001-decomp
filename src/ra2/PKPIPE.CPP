// file name inferred from class name; not proven by a C:\RA2 string
// PKPIPE.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Public-key encryption pipe: the first data through the pipe is a random Blowfish key that is
// encrypted (or decrypted) with a PKey; the rest of the data goes through a Blowfish pipe.
// RTTI .?AVPKPipe@@ (bases Pipe), vtable 0x793144:
//   0 scalar deleting dtor 0x6079b0, 1 Flush (Pipe 0x6066f0), 2 End (0x46c780),
//   3 Put_To(Pipe *) 0x6076d0, 4 Put 0x607780, 5 Put_To(Pipe &) 0x6079a0.
// Code range 0x607670..0x6079ff; PKSTRAW.CPP follows at 0x607a10.
// 0x607950 is the BlowPipe scalar deleting destructor (inline, emitted here as COMDAT).
// Member names are provisional (Westwood style); offsets come from the code.
#include <string.h>

// ---- local declarations (to be moved to headers by the integrator) ----

class Pipe {
public:
    Pipe() : ChainTo(0), ChainFrom(0) {}
    virtual ~Pipe();                                // 0x606640
    virtual int Flush();                            // 0x6066f0
    virtual int End() { return Flush(); }           // 0x46c780
    virtual void Put_To(Pipe * pipe);               // 0x606680
    void Put_To(Pipe & pipe) { Put_To(&pipe); }
    virtual int Put(void const * source, int slen); // 0x6066d0

    Pipe * ChainTo;         // +0x04
    Pipe * ChainFrom;       // +0x08
};

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

// RTTI .?AVBlowPipe@@, vtable 0x793160 (BLOWPIPE.CPP).
class BlowPipe : public Pipe {
public:
    typedef enum CryptControl { ENCRYPT, DECRYPT } CryptControl;
    BlowPipe(CryptControl control) : BF(0), Counter(0), Control(control) {}
    virtual ~BlowPipe() { delete BF; BF = 0; }
    virtual int Flush();                            // 0x435550
    virtual int Put(void const * source, int slen); // 0x435590
    void Key(void const * key, int length);         // 0x4356c0

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

class PKPipe : public Pipe {
public:
    typedef enum CryptControl { ENCRYPT, DECRYPT } CryptControl;
    PKPipe(CryptControl control, RandomStraw & rnd);
    virtual void Put_To(Pipe * pipe);
    virtual void Put_To(Pipe & pipe) { Put_To(&pipe); }
    virtual int Put(void const * source, int length);
    void Key(PKey * key);

    int Encrypted_Key_Length() const;
    int Plain_Key_Length() const;

    bool IsGettingKey;      // +0x0c
    RandomStraw & Rand;     // +0x10
    BlowPipe BF;            // +0x14
    CryptControl Control;   // +0x34
    PKey * CipherKey;       // +0x38
    char Buffer[256];       // +0x3c
    int Counter;            // +0x13c
    int BytesLeft;          // +0x140
};

// ---- end of local declarations ----

// 0x607670
PKPipe::PKPipe(CryptControl control, RandomStraw & rnd) :
    IsGettingKey(true),
    Rand(rnd),
    BF((control == ENCRYPT) ? BlowPipe::ENCRYPT : BlowPipe::DECRYPT),
    Control(control),
    CipherKey(0),
    Counter(0),
    BytesLeft(0)
{
}

// 0x6076d0
void PKPipe::Put_To(Pipe * pipe)
{
    if (BF.ChainTo != pipe) {
        if (pipe != 0 && pipe->ChainFrom != 0) {
            pipe->ChainFrom->Put_To(0);
            pipe->ChainFrom = 0;
        }
        if (BF.ChainTo != 0) {
            BF.ChainTo->ChainFrom = 0;
        }
        BF.ChainTo = pipe;
        if (pipe != 0) {
            pipe->ChainFrom = &BF;
        }
        BF.ChainFrom = this;
        ChainTo = &BF;
    }
}

// 0x607720
void PKPipe::Key(PKey * key)
{
    if (key == 0) {
        Flush();
        IsGettingKey = false;
    }
    CipherKey = key;

    if (CipherKey != 0) {
        IsGettingKey = true;
        if (Control == DECRYPT) {
            Counter = BytesLeft = Encrypted_Key_Length();
        }
    }
}



// 0x6078f0
int PKPipe::Encrypted_Key_Length() const
{
    if (CipherKey == 0) return 0;
    return CipherKey->Block_Count(BLOWFISH_KEY_SIZE) * CipherKey->Crypt_Block_Size();
}

// 0x607920
int PKPipe::Plain_Key_Length() const
{
    if (CipherKey == 0) return 0;
    return CipherKey->Block_Count(BLOWFISH_KEY_SIZE) * CipherKey->Plain_Block_Size();
}
