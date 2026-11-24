// file name inferred from class name; not proven by a C:\RA2 string
// PK.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Public key (RSA style) built on the multi-precision math module (XMP_*, 0x5a4xxx..0x5a6xxx).
// The class has no vtable and no RTTI entry; "PKey" is the name used by the PKPipe/PKStraw
// classes' Westwood design and is provisional, like all member and template names here.
// Code range 0x606920..0x60766c; PKPIPE.CPP follows at 0x607670.
// 0x607380..0x60766c are out-of-line instances of the multi-precision integer template
// (64 32-bit digits) and of its remainder table, emitted here as COMDATs.
#include <stdlib.h>
#include <string.h>

// ---- local declarations (to be moved to headers by the integrator) ----

typedef unsigned long digit;

class Straw;

// Multi-precision math module (MPMATH, fastcall free functions, names provisional).
void XMP_Init(digit * r, digit value, int precision);                                   // 0x5a4890
int XMP_Count_Bits(digit const * r, int precision);                                     // 0x5a48b0
int XMP_DER_Encode(digit const * from, unsigned char * output, int precision);          // 0x5a4200
void XMP_DER_Decode(digit * result, unsigned char const * input, int precision);        // 0x5a42c0
int XMP_Exponent_Mod(digit * expmod, digit const * base, digit const * exponent, digit const * modulus, int precision); // 0x5a6450
bool XMP_Sub_Int(digit * result, digit const * left, unsigned short right, bool borrow, int precision);   // 0x5a4ab0
bool XMP_Add_Int(digit * result, digit const * left, digit right, bool carry, int precision);            // 0x5a49f0
bool XMP_Add(digit * result, digit const * left, digit const * right, bool carry, int precision);        // 0x5a4980
int XMP_Unsigned_Mult_Int(digit * prod, digit const * multiplicand, short multiplier, int precision);      // 0x5a4ce0
int XMP_Signed_Mult(digit * prod, digit const * multiplicand, digit const * multiplier, int precision);  // 0x5a4f30
void XMP_Inverse_A_Mod_B(digit * result, digit const * number, digit const * modulus, int precision);    // 0x5a5690
void XMP_Randomize(digit * result, Straw & rng, digit const * minval, digit const * maxval, int precision); // 0x5a6d90
void XMP_Shift_Left_Bits(digit * number, int bits, int precision);                       // 0x5a46f0
int XMP_Compare(digit const * r1, digit const * r2, int precision);                      // 0x5a4930
bool XMP_Is_Prime(digit const * prime, int precision);                                   // 0x5a6f70
unsigned short XMP_Unsigned_Div_Int(digit * quotient, digit const * dividend, unsigned short divisor, int precision); // 0x5a5130
unsigned short const * XMP_Fetch_Prime_Table();                                          // 0x5a4120
int XMP_Fetch_Prime_Size();                                                              // 0x5a4130

// Multi-precision integer (Westwood INT.H style; template and member names provisional).
template<int PRECISION>
class Int {
public:
    Int(digit value = 0) { XMP_Init(reg, value, PRECISION); }

    Int operator - (unsigned short value) const { Int result; Borrow = XMP_Sub_Int(result.reg, reg, value, false, PRECISION); return result; }
    Int Inverse(Int const & modulus) const { Int result; XMP_Inverse_A_Mod_B(result.reg, reg, modulus.reg, PRECISION); return result; }
    void Randomize(Straw & rng, Int const & minval, Int const & maxval) { XMP_Randomize(reg, rng, minval.reg, maxval.reg, PRECISION); reg[0] |= 1; }
    Int & operator += (Int const & value) { Carry = XMP_Add(reg, reg, value.reg, false, PRECISION); return *this; }
    Int operator + (unsigned short value) const { Int result; Carry = XMP_Add_Int(result.reg, reg, value, false, PRECISION); return result; }
    Int operator * (unsigned short value) const { Int result; Error = XMP_Unsigned_Mult_Int(result.reg, reg, value, PRECISION); return result; }
    Int operator * (Int const & value) const { Int result; Error = XMP_Signed_Mult(result.reg, reg, value.reg, PRECISION); return result; }
    Int operator << (int bits) const { Int result(*this); XMP_Shift_Left_Bits(result.reg, bits, PRECISION); return result; }
    bool operator > (Int const & value) const { return XMP_Compare(reg, value.reg, PRECISION) > 0; }
    unsigned short operator % (unsigned short value) const { return XMP_Unsigned_Div_Int(Scratch.reg, reg, value, PRECISION); }

    Int exp_b_mod_c(Int const & exponent, Int const & modulus) const { Int result; Error = XMP_Exponent_Mod(result.reg, reg, exponent.reg, modulus.reg, PRECISION); return result; }
    bool Is_Probably_Prime() const { return XMP_Is_Prime(reg, PRECISION); }
    int BitCount() const { return XMP_Count_Bits(reg, PRECISION); }
    int DER_Encode(unsigned char * output) const { return XMP_DER_Encode(reg, output, PRECISION); }
    void DER_Decode(unsigned char const * input) { XMP_DER_Decode(reg, input, PRECISION); }

    digit reg[PRECISION];

    static int Error;           // 0xa29400
    static bool Carry;          // 0xa29404
    static bool Borrow;         // 0xa29405
    static Int Scratch;         // 0xa29300 (quotient scratch for operator %)
};

typedef Int<64> BigInt;

// Remainders of a number by every small prime (Westwood INT.H style, names provisional).
template<class T>
class RemainderTable {
public:
    RemainderTable(T const & value) : HasZeroEntry(false)
    {
        int primesize = XMP_Fetch_Prime_Size();
        unsigned short const * primetable = XMP_Fetch_Prime_Table();
        for (int index = 0; index < primesize; index++) {
            table[index] = value % primetable[index];
        }
    }

    bool HasZero() const { return HasZeroEntry; }

    void Increment(unsigned short increment = 1)
    {
        int primesize = XMP_Fetch_Prime_Size();
        unsigned short const * primetable = XMP_Fetch_Prime_Table();
        HasZeroEntry = false;
        for (int index = 0; index < primesize; index++) {
            table[index] += increment;
            while (table[index] >= primetable[index]) {
                table[index] -= primetable[index];
            }
            HasZeroEntry = (HasZeroEntry || !table[index]);
        }
    }

protected:
    bool HasZeroEntry;
    unsigned short table[3511];
};

template<class T>
T Generate_Prime(Straw & rng, int pbits, T const *)
{
    T minq = (T(1) << (unsigned short)(pbits - 2));
    T maxq = ((T(1) << (unsigned short)(pbits - 1)) - (unsigned short)1);

    T q;
    T p;
    do {
        q.Randomize(rng, minq, maxq);
        p = (q * 2) + (unsigned short)1;

        RemainderTable<T> rq(q);
        RemainderTable<T> rp(p);

        while (rq.HasZero() || rp.HasZero() || !q.Is_Probably_Prime() || !p.Is_Probably_Prime()) {
            q += 2;
            p += 4;
            if (q > maxq) break;
            rq.Increment(2);
            rp.Increment(4);
        }
    } while (q > maxq);
    return p;
}

class PKey {
public:
    PKey(void const * exponent, void const * modulus);
    int Encode_Modulus(void * buffer) const;
    int Encode_Exponent(void * buffer) const;
    void Decode_Modulus(void * buffer);
    void Decode_Exponent(void * buffer);
    static void Generate(Straw & random, int bits, PKey & fastkey, PKey & slowkey);
    int Encrypt(void const * source, int slen, void * dest) const;
    int Decrypt(void const * source, int slen, void * dest) const;

    int Plain_Block_Size() const { return (BitPrecision - 1) / 8; }
    int Crypt_Block_Size() const { return Plain_Block_Size() + 1; }
    static BigInt Fast_Exponent() { return 65537L; }

    BigInt Modulus;         // +0x000
    BigInt Exponent;        // +0x100
    int BitPrecision;       // +0x200
};

// ---- end of local declarations ----

// 0x606920
PKey::PKey(void const * exponent, void const * modulus)
{
    Modulus.DER_Decode((unsigned char const *)modulus);
    Exponent.DER_Decode((unsigned char const *)exponent);
    BitPrecision = Modulus.BitCount() - 1;
}

// 0x606980
int PKey::Encode_Modulus(void * buffer) const
{
    if (buffer == 0) {
        return 0;
    }
    return Modulus.DER_Encode((unsigned char *)buffer);
}

// 0x6069a0
int PKey::Encode_Exponent(void * buffer) const
{
    if (buffer == 0) {
        return 0;
    }
    return Exponent.DER_Encode((unsigned char *)buffer);
}

// 0x6069c0
void PKey::Decode_Modulus(void * buffer)
{
    Modulus.DER_Decode((unsigned char const *)buffer);
    BitPrecision = Modulus.BitCount() - 1;
}

// 0x6069f0
void PKey::Decode_Exponent(void * buffer)
{
    Exponent.DER_Decode((unsigned char const *)buffer);
}

// 0x606a10
void PKey::Generate(Straw & random, int bits, PKey & fastkey, PKey & slowkey)
{
    for (;;) {
        BigInt p = Generate_Prime(random, bits, &p);
        BigInt q = Generate_Prime(random, bits, &q);
        BigInt e = Fast_Exponent();
        BigInt n = p * q;
        BigInt pqmin = (p - (unsigned short)1) * (q - (unsigned short)1);
        BigInt d = e.Inverse(pqmin);

        fastkey.Exponent = e;
        fastkey.Modulus = n;
        fastkey.BitPrecision = n.BitCount() - 1;

        slowkey.Exponent = d;
        slowkey.Modulus = n;
        slowkey.BitPrecision = fastkey.BitPrecision;

        char before[256];
        char after[256];
        for (int index = 0; index < fastkey.Plain_Block_Size(); index++) {
            before[index] = (char)rand();
        }
        fastkey.Encrypt(before, fastkey.Plain_Block_Size(), after);
        slowkey.Decrypt(after, slowkey.Crypt_Block_Size(), after);

        if (memcmp(before, after, fastkey.Plain_Block_Size()) == 0) break;
    }
}

// 0x607100
int PKey::Encrypt(void const * source, int slen, void * dest) const
{
    int total = 0;

    while (slen >= Plain_Block_Size()) {
        BigInt temp = 0;
        memmove(&temp, source, Plain_Block_Size());
        temp = temp.exp_b_mod_c(Exponent, Modulus);
        memmove(dest, &temp, Crypt_Block_Size());

        slen -= Plain_Block_Size();
        source = (char const *)source + Plain_Block_Size();
        dest = (char *)dest + Crypt_Block_Size();
        total += Crypt_Block_Size();
    }
    return total;
}

// 0x607230
int PKey::Decrypt(void const * source, int slen, void * dest) const
{
    int total = 0;
    BigInt temp;

    while (slen >= Crypt_Block_Size()) {
        temp = 0;
        memmove(&temp, source, Crypt_Block_Size());
        temp = temp.exp_b_mod_c(Exponent, Modulus);
        memmove(dest, &temp, Plain_Block_Size());

        slen -= Crypt_Block_Size();
        source = (char const *)source + Crypt_Block_Size();
        dest = (char *)dest + Plain_Block_Size();
        total += Plain_Block_Size();
    }
    return total;
}
