// unidentified translation unit 0x42fd50.. (level-2 reconstruction of GAME.EXE 1.001)
// Contents: the Bink movie player (debug strings "Bink Error: %s", "Pause bink movie",
// "Resume bink movie"). No RTTI exists for this class; the class name BinkMovieClass and all
// method, member and variable names are provisional. The file name is unknown.
//
// TU span: 0x2fd50 (16-byte zeroing header initializer, .bss 0x836cf8) .. at least 0x30a6a. The
// bit-stream helpers 0x30a70..0x30ed8 that follow have no initializer and use no Bink call; they
// may belong to a further TU and are not reconstructed here. The next initializer 0x30ee0 starts
// the BitFont TU.
//
// Reconstructed so far: the small members. Open (0x2fe30), Set_Position (0x30180), Play (0x30330),
// Draw_Frame (0x30500), the subtitle and blit helpers 0x306e0..0x309b0 are open (see the claims).
#include <windows.h>
#include "../RECT.H"
#include "../SURFACE.H"

// ---- local declarations (to be moved to headers by the integrator) ----

// Bink SDK (binkw32.dll, stdcall imports). Only the header fields used here.
struct BINK {
    unsigned Width;             // +0x00
    unsigned Height;            // +0x04
    unsigned Frames;            // +0x08
    unsigned FrameNum;          // +0x0c
    unsigned LastFrameNum;      // +0x10
    unsigned FrameRate;         // +0x14
    unsigned FrameRateDiv;      // +0x18
};
typedef BINK * HBINK;
extern "C" __declspec(dllimport) void __stdcall BinkClose(HBINK bink);
extern "C" __declspec(dllimport) void __stdcall BinkGoto(HBINK bink, unsigned frame, int flags);
extern "C" __declspec(dllimport) int __stdcall BinkPause(HBINK bink, int pause);
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(HBINK bink, void * dest, int destpitch, unsigned destheight, unsigned destx, unsigned desty, unsigned flags);

// Movie subtitles (0x690830 creates them from the movie name; names provisional).
class MovieSubtitlesClass {
public:
    ~MovieSubtitlesClass();                         // 0x690940
    void Set_Time(int time);                        // 0x690b90
};

// ---- end of local declarations ----

static RectangleStruct const ZeroRect(0, 0, 0, 0);

class BinkMovieClass {
public:
    BinkMovieClass(char const * filename);
    BinkMovieClass(char const * filename, Surface * surface);
    ~BinkMovieClass();

    bool Open(char const * filename);                           // 0x42fe30 (not reconstructed)
    void Close();
    void Set_Position(int x, int y);                            // 0x430180 (not reconstructed)
    void Goto(int frame);
    unsigned Frame_Time() const;
    void Set_Subtitle_Time(int time);
    void Pause(bool pause);
    bool Is_Finished() const;
    void Play();                                                // 0x430330 (not reconstructed)
    bool Draw_Frame(Surface * surface, int x, int y);           // 0x430500 (not reconstructed)
    bool Draw_Frame();
    void Draw_To(::Surface * surface, int x, int y);
    void Draw_To(::Surface * surface, int x, int y, bool all);
    void Draw_Subtitles(::Surface * surface);                   // 0x4308f0 (not reconstructed)
    void Erase_Subtitles(::Surface * surface);                  // 0x4309b0 (not reconstructed)
    int Elapsed() const;

    bool CanInterrupt;                      // +0x00 (meaning provisional)
    HBINK Bink;                             // +0x04
    unsigned SurfaceType;                   // +0x08, BinkDDSurfaceType of the hidden surface
    Surface * Surface;                      // +0x0c
    RectangleStruct Rect;                   // +0x10
    MovieSubtitlesClass * Subtitles;        // +0x20
    int FrameDelay;                         // +0x24, game frames per movie frame
    HANDLE File;                            // +0x28
    bool Flag2C;                            // +0x2c (meaning unknown)
};

// 0x42fd70
BinkMovieClass::BinkMovieClass(char const * filename) :
    CanInterrupt(false),
    Bink(NULL),
    Surface(NULL),
    Subtitles(NULL),
    File(INVALID_HANDLE_VALUE),
    Flag2C(true)
{
    Open(filename);
}

// 0x42fda0
BinkMovieClass::BinkMovieClass(char const * filename, ::Surface * surface) :
    CanInterrupt(false),
    Bink(NULL),
    Surface(surface),
    Subtitles(NULL),
    File(INVALID_HANDLE_VALUE),
    Flag2C(true)
{
    Open(filename);
}

// 0x42fde0
BinkMovieClass::~BinkMovieClass()
{
    Close();
}

// 0x430130
void BinkMovieClass::Close()
{
    if (Subtitles) {
        delete Subtitles;
        Subtitles = NULL;
    }
    if (Bink) {
        BinkClose(Bink);
        Bink = NULL;
    }
    if (File != INVALID_HANDLE_VALUE) {
        CloseHandle(File);
        File = INVALID_HANDLE_VALUE;
    }
}

// 0x4302a0
void BinkMovieClass::Goto(int frame)
{
    BinkGoto(Bink, frame, 1);
}

// 0x4302c0: milliseconds per movie frame.
unsigned BinkMovieClass::Frame_Time() const
{
    return 1000 / (Bink->FrameRate / Bink->FrameRateDiv);
}

// 0x4302e0
void BinkMovieClass::Set_Subtitle_Time(int time)
{
    if (Subtitles) {
        Subtitles->Set_Time(time);
    }
}

// 0x430300
void BinkMovieClass::Pause(bool pause)
{
    BinkPause(Bink, pause);
}

// 0x430320
bool BinkMovieClass::Is_Finished() const
{
    return Bink->FrameNum >= Bink->Frames;
}

// 0x4306c0
bool BinkMovieClass::Draw_Frame()
{
    return Draw_Frame(Surface, Rect.X, Rect.Y);
}

// 0x430800: copies the current frame into a surface at x, y (whole frame).
void BinkMovieClass::Draw_To(::Surface * surface, int x, int y)
{
    Erase_Subtitles(surface);
    void * buffer = surface->Lock();
    if (buffer) {
        int pitch = surface->Get_Pitch();
        int height = surface->Get_Height();
        BinkCopyToBuffer(Bink, buffer, pitch, height, x, y, SurfaceType | 0x80000000);
        surface->Unlock();
    }
    Draw_Subtitles(surface);
}

// 0x430870
void BinkMovieClass::Draw_To(::Surface * surface, int x, int y, bool all)
{
    if (all) {
        Erase_Subtitles(surface);
    }
    void * buffer = surface->Lock();
    if (buffer) {
        int pitch = surface->Get_Pitch();
        int height = surface->Get_Height();
        unsigned flags = SurfaceType;
        if (all) {
            flags |= 0x80000000;
        }
        BinkCopyToBuffer(Bink, buffer, pitch, height, x, y, flags);
        surface->Unlock();
    }
    Draw_Subtitles(surface);
}

// 0x430a60
int BinkMovieClass::Elapsed() const
{
    return Bink->FrameNum * FrameDelay;
}
