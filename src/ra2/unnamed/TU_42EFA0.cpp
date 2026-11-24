// unidentified translation unit 0x42efa0..0x42f0f4 (level-2 reconstruction of GAME.EXE 1.001)
// Contents: a small CPU-clock benchmark accumulator (no RTTI; class name Benchmark and all member
// names are provisional). The file name is unknown; alphabetically it sits between Beacon.CPP and
// the BufferIOFileClass file (possibly a "Bench" file, not proven by a C:\RA2 string).
//
// TU span: 0x2efa0 is the 16-byte zeroing initializer of the shared header rectangle (.bss
// 0x836ce0), then six out-of-line Benchmark members 0x2efc0..0x2f0f4. None of them is called
// anywhere in GAME.EXE (they are unreferenced out-of-line copies). The BufferIOFileClass methods
// from 0x2f100 have no initializer and are placed in a separate file (BFIOFILE.CPP).
#include "../RECT.H"

// ---- local declarations (to be moved to headers by the integrator) ----

// 0x76abb4 (assembly, cdecl): rdtsc; returns the low dword and stores the high dword.
extern "C" unsigned long __cdecl Get_CPU_Clock(unsigned long & high);

// Timer source: the CPU time stamp counter divided by 16 (64-bit shift folded to 32 bits).
class CPUTimerClass {
public:
    long operator()() const
    {
        unsigned long high;
        return (Get_CPU_Clock(high) >> 4) | (high << 28);
    }
};

// Basic count-up timer (two dwords: start value and the empty timer-source object).
template<class T>
class BasicTimerClass {
public:
    BasicTimerClass(unsigned long set = 0) : Started(Timer() - set) {}
    // GAME.EXE reads the clock here through a named low dword (not through Timer()), which gives a
    // different register choice from the constructor (load-bearing).
    operator unsigned long() const
    {
        unsigned long high;
        unsigned long low = Get_CPU_Clock(high);
        return ((low >> 4) | (high << 28)) - Started;
    }

    unsigned long Started;
    T Timer;
};

// ---- end of local declarations ----

static RectangleStruct const ZeroRect(0, 0, 0, 0);

class Benchmark {
public:
    enum { MAXIMUM = 256 };

    Benchmark();
    void Reset();
    void Begin(bool reset = false);
    void End();
    void End_Unlimited();
    unsigned long Value() const;

    BasicTimerClass<CPUTimerClass> Clock;   // +0x00
    unsigned long Average;                  // +0x08 (sum of the last up to 256 samples)
    unsigned long Counter;                  // +0x0c
    unsigned long TotalCount;               // +0x10
};

// 0x42efc0
Benchmark::Benchmark() :
    Average(0),
    Counter(0),
    TotalCount(0)
{
}

// 0x42eff0
void Benchmark::Reset()
{
    Average = 0;
    Counter = 0;
    TotalCount = 0;
}

// 0x42f000
void Benchmark::Begin(bool reset)
{
    if (reset) {
        Reset();
    }
    Clock = 0;
}

// 0x42f040: adds the elapsed clock; once 256 samples are held the sum decays by 1/256.
void Benchmark::End()
{
    unsigned long value = Clock;
    if (Counter == MAXIMUM) {
        Average -= Average / MAXIMUM;
        Average += value;
    } else {
        Average += value;
        Counter++;
    }
    TotalCount++;
}

// 0x42f0a0: as End without the sample limit (name provisional).
void Benchmark::End_Unlimited()
{
    unsigned long value = Clock;
    Average += value;
    Counter++;
    TotalCount++;
}

// 0x42f0e0
unsigned long Benchmark::Value() const
{
    if (Counter) {
        return Average / Counter;
    }
    return 0;
}
