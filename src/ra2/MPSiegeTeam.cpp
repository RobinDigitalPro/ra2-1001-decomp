// C:\RA2\MPSiegeTeam.cpp (level-2 reconstruction of GAME.EXE 1.001)
// Contents: the defender and attacker teams of the Siege multiplayer game mode, followed by the
// RDTSC processor speed measurement (see the TU note at that code).
// Class names come from RTTI (.?AVMultiplayerSiegeDefenderTeam@@, .?AVMultiplayerSiegeAttackerTeam@@);
// all other names are provisional.
#include <stddef.h>
#include <stdlib.h>
#include "GAMECONST.H"
#include <windows.h>

// ---- local declarations (to be moved to headers by the integrator) ----
#include "VECTOR.H"

// Identical prototype already in ABSTYPE.H (0x6eeb60, __fastcall). Belongs in a string-table header.
wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);

// One-pointer wide string (provisional name, as in MPObserver.cpp). 0x75b300 ctor(const wchar_t *),
// 0x75b350 copy ctor, 0x75b390 dtor.
class WideStringClass {
public:
    WideStringClass(wchar_t const * string);
    WideStringClass(WideStringClass const & string);
    ~WideStringClass();
private:
    wchar_t * Buffer;
};

// RTTI .?AVMultiplayerTeam@@, vtable 0x7922e4 (3 slots), size 0xc (as in MPObserver.cpp).
class MultiplayerTeam {
public:
    MultiplayerTeam(WideStringClass const & name, int id);   // 0x5b63b0
    virtual ~MultiplayerTeam();                              // 0x5b63e0 (slot 0: 0x1b64b0)
    virtual bool Is_Valid_Index(int index);                  // slot 1: 0x5b63f0, 0 <= index < Players.ActiveCount
    virtual bool Can_Join(int index);                        // slot 2: 0x5b6410

    WideStringClass Name;   // +0x04
    int ID;                 // +0x08
};

// Element of the multiplayer player list (provisional name and layout); only the dword at +0x59
// is used here. It is compared with 1, the ID passed by both siege team constructors.
#pragma pack(push, 1)
struct MPPlayerNode {
    char Unknown00[0x59];
    int Team;                   // +0x59 (unaligned)
};
#pragma pack(pop)

// DynamicVectorClass at 0xa27da8 (Vector 0xa27dac, ActiveCount 0xa27db8); also read by
// MultiplayerTeam::Is_Valid_Index. Its owner (a session object or a global) is not bound.
extern DynamicVectorClass<MPPlayerNode *> MPPlayers;

// RTTI .?AVMultiplayerSiegeDefenderTeam@@ : MultiplayerTeam, vtable 0x791c2c.
class MultiplayerSiegeDefenderTeam : public MultiplayerTeam {
public:
    MultiplayerSiegeDefenderTeam();
    virtual ~MultiplayerSiegeDefenderTeam();
    virtual bool Is_Valid_Index(int index);
};

// RTTI .?AVMultiplayerSiegeAttackerTeam@@ : MultiplayerTeam, vtable 0x791c3c (slots 1 and 2 inherited).
class MultiplayerSiegeAttackerTeam : public MultiplayerTeam {
public:
    MultiplayerSiegeAttackerTeam();
    virtual ~MultiplayerSiegeAttackerTeam();
};

// Processor speed measurement (provisional names).
unsigned long Get_Performance_Frequency(unsigned long * high);
void Read_Time_Stamp();
int Get_RDTSC_CPU_Speed();

// ---- end of local declarations ----

#line 3 "C:\\RA2\\MPSiegeTeam.cpp"
MultiplayerSiegeDefenderTeam::MultiplayerSiegeDefenderTeam() :
    // Original __LINE__ is 6.
    MultiplayerTeam(
        Fetch_String("MP:DefenderTeam", NULL, __FILE__, __LINE__), 1)
{
}

MultiplayerSiegeDefenderTeam::~MultiplayerSiegeDefenderTeam()
{
}

// Only one player may be on the defender team.
bool MultiplayerSiegeDefenderTeam::Is_Valid_Index(int index)
{
    int count = MPPlayers.ActiveCount;
    for (int i = 0; i < count; i++) {
        if (index != i && MPPlayers[i]->Team == 1) {
            return false;
        }
    }
    return true;
}

#line 19 "C:\\RA2\\MPSiegeTeam.cpp"
MultiplayerSiegeAttackerTeam::MultiplayerSiegeAttackerTeam() :
    // Original __LINE__ is 22.
    MultiplayerTeam(
        Fetch_String("MP:AttackerTeam", NULL, __FILE__, __LINE__), 1)
{
}

MultiplayerSiegeAttackerTeam::~MultiplayerSiegeAttackerTeam()
{
}

// 0x1a8b00
unsigned long Get_Performance_Frequency(unsigned long * high)
{
    LARGE_INTEGER frequency;
    if (QueryPerformanceFrequency(&frequency)) {
        *high = frequency.HighPart;
        return frequency.LowPart;
    }
    *high = 0;
    return 0;
}

static unsigned long TimeStampHigh;   // 0xa59394
static unsigned long TimeStampLow;    // 0xa59398

// 0x1a8b40 (no references found)
void Read_Time_Stamp()
{
    __asm {
        rdtsc
        mov TimeStampLow, eax
        mov TimeStampHigh, edx
    }
}

// 0x1a8b50: measures the processor clock in MHz against the performance counter.
int Get_RDTSC_CPU_Speed()
{
    LARGE_INTEGER count;
    LARGE_INTEGER t0;
    LARGE_INTEGER t1;
    unsigned long stamp0;
    unsigned long stamp1;
    unsigned long cycles;
    unsigned long ticks;
    unsigned long freq = 0;
    unsigned long freq2 = 0;
    int tries = 0;
    unsigned long freq3;
    unsigned long total;
    unsigned long total_cycles = 0;
    unsigned long total_ticks = 0;

    if (!QueryPerformanceFrequency(&count)) {
        return 0;
    }

    do {
        tries++;
        freq3 = freq2;
        freq2 = freq;

        QueryPerformanceCounter(&t0);
        t1.LowPart = t0.LowPart;
        t1.HighPart = t0.HighPart;
        while ((unsigned long)t1.LowPart - (unsigned long)t0.LowPart < 50) {
            QueryPerformanceCounter(&t1);
        }
        __asm {
            rdtsc
            mov stamp0, eax
        }

        t0.LowPart = t1.LowPart;
        t0.HighPart = t1.HighPart;
        while ((unsigned long)t1.LowPart - (unsigned long)t0.LowPart < 1000) {
            QueryPerformanceCounter(&t1);
        }
        __asm {
            rdtsc
            mov stamp1, eax
        }

        cycles = stamp1 - stamp0;
        ticks = (unsigned long)t1.LowPart * 100000 - (unsigned long)t0.LowPart * 100000;
        ticks = ticks / (count.LowPart / 10);
        total_ticks += ticks;
        total_cycles += cycles;
        if (ticks % count.LowPart > count.LowPart / 2) {
            ticks++;
        }
        freq = cycles / ticks;
        if (cycles % ticks > ticks / 2) {
            freq++;
        }
        total = freq + freq2 + freq3;
    } while (tries < 3 || (tries < 20 && (abs((int)(3 * freq - total)) > 3 || abs((int)(3 * freq2 - total)) > 3 || abs((int)(3 * freq3 - total)) > 3)));

    freq3 = (total_cycles * 10) / total_ticks;
    freq2 = (total_cycles * 100) / total_ticks;
    if (freq2 - freq3 * 10 >= 6) {
        freq3++;
    }
    freq = total_cycles / total_ticks;
    if (freq3 - freq * 10 >= 6) {
        freq++;
    }
    return freq;
}
