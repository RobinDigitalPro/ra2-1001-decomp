// C:\RA2\Egos.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Credits screen: reads CREDITS.TXT, turns every text run into one scrolling EgoClass line and
// scrolls them up the screen over a fading top and bottom band. Class names come from RTTI where available (DSurface,
// Mouse, CCFileClass, DynamicVectorClass<EgoClass *>); all other names are provisional.
#include <string.h>
#include <wchar.h>
#include <stddef.h>
#include "SURFACE.H"

// TU boundary: this file starts at 0xb3290 (its first dynamic initializer) and ends before
// 0xb43a0. It has no GAMECONST.H block of its own. 0xb2c60..0xb3290 (GAMECONST block, two
// zero-rect initializers, Build_Fading_Table, Build_Translucent_Table) belongs to one or two
// earlier TUs; their byte-matching code is kept in the #if 0 block at the end of this file.

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x6eeb60
void Call_Back();                         // 0x4821e0 (provisional; see CampScor.cpp)
void Show_Surface(bool flag, Surface * surface, int value);     // 0x4e0320 (see MPScore.cpp)

// Copy of VECTOR.H plus the constructors and Count() that VECTOR.H does not have yet (same as
// ToolTip.cpp). The constructors are inlined into the dynamic initializer 0xb32b0.
template<class T> class VectorClass {
public:
    VectorClass(unsigned size = 0, T const * array = 0) :
        Vector(0), VectorMax(size), IsInitialized(true), IsAllocated(false)
    {
        if (size) {
            if (array) {
                Vector = (T *)array;
            } else {
                Vector = new T[size];
                IsAllocated = true;
            }
        }
    }
    virtual ~VectorClass() { VectorClass<T>::Clear(); }
    virtual bool operator == (VectorClass<T> const & vector) const;
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr);
    virtual int ID(T const & object);
    virtual T Fetch(int index) const { return Vector[index]; }

    T & operator[](unsigned index) { return Vector[index]; }
    int Length() const { return VectorMax; }

    T * Vector;
    int VectorMax;
    bool IsInitialized;
    bool IsAllocated;
};

template<class T> bool VectorClass<T>::operator == (VectorClass<T> const & vector) const
{
    if (VectorMax == vector.VectorMax) {
        for (int index = 0; index < VectorMax; index++) {
            if (Vector[index] != vector.Vector[index]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

template<class T> bool VectorClass<T>::Resize(int newsize, T const * array)
{
    if (newsize) {
        T * newptr;
        IsInitialized = false;
        if (!array) {
            newptr = new T[newsize];
        } else {
            newptr = (T *)array;
        }
        IsInitialized = true;
        if (!newptr) {
            return false;
        }
        if (Vector != NULL) {
            int copycount = (newsize < VectorMax) ? newsize : VectorMax;
            for (int index = 0; index < copycount; index++) {
                newptr[index] = Vector[index];
            }
            if (IsAllocated) {
                delete [] Vector;
                Vector = 0;
            }
        }
        Vector = newptr;
        VectorMax = newsize;
        IsAllocated = (Vector && !array);
    } else {
        Clear();
    }
    return true;
}

template<class T> void VectorClass<T>::Clear(void)
{
    if (Vector && IsAllocated) {
        delete [] Vector;
        Vector = 0;
    }
    IsAllocated = false;
    VectorMax = 0;
}

template<class T> int VectorClass<T>::ID(T const * ptr)
{
    if (!IsInitialized) {
        return 0;
    }
    return ((unsigned long)ptr - (unsigned long)Vector) / sizeof(T);
}

template<class T> int VectorClass<T>::ID(T const & object)
{
    if (!IsInitialized) {
        return 0;
    }
    for (int index = 0; index < VectorMax; index++) {
        if (Vector[index] == object) {
            return index;
        }
    }
    return -1;
}

template<class T> class DynamicVectorClass : public VectorClass<T> {
public:
    DynamicVectorClass(unsigned size = 0, T const * array = 0) : VectorClass<T>(size, array)
    {
        GrowthStep = 10;
        ActiveCount = 0;
    }
    virtual bool Resize(int newsize, T const * array = 0);
    virtual void Clear(void);
    virtual int ID(T const * ptr) { return VectorClass<T>::ID(ptr); }
    virtual int ID(T const & object);

    int Count() const { return ActiveCount; }
    int Add(T const & object);
    int Delete(T const & object);
    int Delete(int index);

    int ActiveCount;
    int GrowthStep;
};

template<class T> bool DynamicVectorClass<T>::Resize(int newsize, T const * array)
{
    if (VectorClass<T>::Resize(newsize, array)) {
        if (Length() < ActiveCount) {
            ActiveCount = Length();
        }
        return true;
    }
    return false;
}

template<class T> void DynamicVectorClass<T>::Clear(void)
{
    ActiveCount = 0;
    VectorClass<T>::Clear();
}

template<class T> int DynamicVectorClass<T>::ID(T const & object)
{
    for (int index = 0; index < ActiveCount; index++) {
        if ((*this)[index] == object) {
            return index;
        }
    }
    return -1;
}

template<class T> inline int DynamicVectorClass<T>::Add(T const & object)
{
    if (ActiveCount >= Length()) {
        if ((IsAllocated || !VectorMax) && GrowthStep > 0) {
            if (!Resize(Length() + GrowthStep)) {
                return false;
            }
        } else {
            return false;
        }
    }
    (*this)[ActiveCount++] = object;
    return true;
}

template<class T> inline int DynamicVectorClass<T>::Delete(T const & object)
{
    int index = ID(object);
    if (index != -1) {
        return Delete(index);
    }
    return false;
}

template<class T> inline int DynamicVectorClass<T>::Delete(int index)
{
    if (index < ActiveCount) {
        ActiveCount--;
        for (int i = index; i < ActiveCount; i++) {
            (*this)[i] = (*this)[i+1];
        }
        return true;
    }
    return false;
}

// Colour schemes (RTTI vector element type "ColorScheme").
class ColorScheme {
public:
    static ColorScheme * Find(char const * name, int shades);  // 0x65ace0
};

// Variadic text printer (cdecl, 0x497920; vsprintf of text and the extra arguments).
Point2D __cdecl Fancy_Text_Print(char const * text, Surface * surface, RectangleStruct const & rect,
    Point2D const & xy, ColorScheme * fore, unsigned back, int flags, ...);

// Draws a wide string into a surface rectangle (0x5f5e90). Parameter names provisional.
int Print_Wide_Text(unsigned color, int unknown1, RectangleStruct & rect, wchar_t const * text, int length,
    int justify, int unknown2, Surface * surface, int unknown3);

// DirectDraw surface (RTTI .?AVDSurface@@ 38 slots, 0x24 bytes).
class DSurface : public XSurface {
public:
    DSurface(int width, int height, bool system_memory);    // 0x4aa1b0
    virtual int Get_Bytes_Per_Pixel(void) const;            // slot 28, 0x4aa970
    virtual int Get_Pitch(void) const;                      // slot 29, 0x4aa980
private:
    char DSurfaceData[0x10];                                // +0x14, layout not reconstructed
};

extern Surface * VisibleSurface;             // 0x821c90 (provisional)
extern Surface * HiddenSurface;            // 0x821c94
extern Surface * AlternateSurface;          // 0x821c98
extern Surface * LogicalSurface;               // 0x821c9c (provisional)
extern int ScreenWidth;                     // 0x83a710
extern int ScreenHeight;                    // 0x83a714
extern int DSurfaceWidth;                   // 0x821988 (provisional)
extern int DSurfaceHeight;                  // 0x82198c (provisional)
extern bool AllSurfacesLost;                // 0x83a70c (provisional)
extern bool Flag_839FE0;                    // 0x839fe0 (meaning unknown)
extern bool GameInFocus;                    // 0xa28968 (provisional)
extern char const * MessageColorName;       // 0x7c34a4 (provisional; colour scheme name)
extern int FrameDelay;                      // 0x7c1560 (provisional; ticks per credits frame, 2)

// 16-bit pixel channel masks and the fade factors that the inline pixel fade writes.
extern unsigned short RedMask;              // 0xa5df30 (provisional)
extern unsigned short GreenMask;            // 0xa5df32 (provisional)
extern unsigned short BlueMask;             // 0xa5df34 (provisional)
extern unsigned FadeLevel;                  // 0xb10ab4 (provisional)
extern unsigned FadeInverse;                // 0xb10ab8 (provisional)

inline unsigned short Fade_Pixel(unsigned short pixel, unsigned char level)
{
    FadeLevel = level;
    FadeInverse = 255 - level;
    return (unsigned short)(((((pixel & GreenMask) * FadeInverse) >> 8) & GreenMask)
        | ((((pixel & RedMask) * FadeInverse) >> 8) & RedMask)
        | (((pixel & BlueMask) * FadeInverse) >> 8));
}

// Mouse (RTTI .?AVMouse@@, 18 slots; only the first five are needed here).
class Mouse {
public:
    virtual ~Mouse();
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Hide_Mouse() = 0;
    virtual void Show_Mouse() = 0;
};
extern Mouse * WWMouse;                     // 0x821fa8

class WWKeyboardClass {
public:
    unsigned short Check();                 // 0x530530
    unsigned short Get();                   // 0x530580
    void Clear();                           // 0x530c50
};
extern WWKeyboardClass * Keyboard;          // 0x81a7a8

class ThemeClass {
public:
    void Queue_Song(int theme);             // 0x6dd0e0
    void Stop(bool fade = false);           // 0x6dd460
    int From_Name(char const * name);       // 0x6dd7d0
};
extern ThemeClass Theme;                    // 0xa1e0a8

class OptionsClass {
public:
    void Set_Score_Volume(float volume, bool feedback);     // 0x5d1010

    char Unknown0[0x34];
    float ScoreVolume;                      // +0x34
};
extern OptionsClass Options;                // 0xa28758

class SystemTimerClass {
public:
    long operator()() const;                // 0x68fad0
};

template<class T>
class TTimerClass {
public:
    long Value() const
    {
        long value = Accumulated;
        if (Started != -1) {
            value += Timer() - Started;
        }
        return value;
    }
    long Started;
    T Timer;
    long Accumulated;
};
extern TTimerClass<SystemTimerClass> TickCount;     // 0x821cc0 (name provisional)

// File class hierarchy (see Restate.cpp).
class FileClass {
public:
    virtual ~FileClass();
    virtual char const * File_Name() const = 0;
    virtual char const * Set_Name(char const * filename) = 0;
    virtual int Create() = 0;
    virtual int Delete() = 0;
    virtual bool Is_Available(int forced = false) = 0;
    virtual bool Is_Open() const = 0;
    virtual int Open(char const * filename, int rights = 1) = 0;
    virtual int Open(int rights = 1) = 0;
    virtual long Read(void * buffer, long size) = 0;
    virtual long Seek(long pos, int dir = 1) = 0;
    virtual long Size() = 0;
    virtual long Write(void const * buffer, long size) = 0;
    virtual void Close() = 0;
    virtual unsigned long Get_Date_Time() = 0;
    virtual bool Set_Date_Time(unsigned long datetime) = 0;
    virtual void Error(int error, int canretry = false, char const * filename = NULL) = 0;
};

class RawFileClass : public FileClass {
public:
    virtual char const * File_Name() const;
    virtual char const * Set_Name(char const * filename);
    virtual int Create();
    virtual int Delete();
    virtual bool Is_Available(int forced = false);
    virtual bool Is_Open() const;
    virtual int Open(char const * filename, int rights = 1);
    virtual int Open(int rights = 1);
    virtual long Read(void * buffer, long size);
    virtual long Seek(long pos, int dir = 1);
    virtual long Size();
    virtual long Write(void const * buffer, long size);
    virtual void Close();
    virtual unsigned long Get_Date_Time();
    virtual bool Set_Date_Time(unsigned long datetime);
    virtual void Error(int error, int canretry = false, char const * filename = NULL);
private:
    char RawFileData[0x1C];             // +0x04, layout not reconstructed
};

class BufferIOFileClass : public RawFileClass {
public:
    virtual ~BufferIOFileClass();       // 0x42f250
private:
    char BufferIOData[0x34];            // +0x20, layout not reconstructed
};

class CDFileClass : public BufferIOFileClass {
public:
    virtual ~CDFileClass() {}
    virtual char const * Set_Name(char const * filename);   // 0x46fd50
};

class CCFileClass : public CDFileClass {
public:
    CCFileClass(char const * filename);                     // 0x468b70
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual long Read(void * buffer, long size);            // 0x468c80
    virtual long Size();                                    // 0x468d70
    virtual void Close();                                   // 0x468e10
private:
    Buffer Data;                   // +0x54
    long Position;                      // +0x60
};

// One line of the credits text, 0x10 bytes (no RTTI of its own; the vector RTTI names it EgoClass).
class EgoClass {
public:
    EgoClass(int x, int y, wchar_t const * text, int flags);
    ~EgoClass();
    bool Scroll(int distance);
    void Render(bool forced);

    wchar_t * Text;                     // +0x00
    int X;                              // +0x04, always 0 here
    int Y;                              // +0x08, screen line
    int Flags;                          // +0x0c, 0x100 / 0x200 select the justification
};

void Show_Who_Was_Responsible();

// ---- end of local declarations ----

// First initializer of Egos.CPP (0xb3290): 16 zero bytes at 0x83dc50.
static RectangleStruct const ZeroRectA(0, 0, 0, 0);

// 0x83dc60, initializer 0xb32b0 (destructor registered with atexit: 0xb32f0).
DynamicVectorClass<EgoClass *> Egos;

DSurface * CreditSurface;                   // 0x83b448
wchar_t EgoText[5120];                      // 0x83b44c (size not proven)

// 0xb3330
EgoClass::EgoClass(int x, int y, wchar_t const * text, int flags)
{
    X = x;
    Y = y;
    Flags = flags;
    Text = new wchar_t [wcslen(text) + 1];
    wcscpy(Text, text);
}

// 0xb3370
EgoClass::~EgoClass()
{
    delete [] Text;
}

// 0xb3380
bool EgoClass::Scroll(int distance)
{
    Y -= distance;
    bool gone = Y < -20;
    return gone;
}

// 0xb33a0: draws the line when it is inside the top or bottom band (or always when forced).
void EgoClass::Render(bool forced)
{
    if ((Y < LogicalSurface->Get_Height() && Y > LogicalSurface->Get_Height() - 52) || (Y >= -16 && Y <= 32) || forced) {
        RectangleStruct rect;
        rect.X = (ScreenWidth - 520) / 2;
        rect.Width = 520;
        rect.Y = Y;
        rect.Height = ScreenHeight;
        int justify = 0;
        if (Flags & 0x100) {
            justify = 1;
        } else if (Flags & 0x200) {
            justify = 4;
        }
        if (GameInFocus) {
            Print_Wide_Text(0x80ffff, 0, rect, Text, wcslen(Text), justify, 0, CreditSurface, 0);
        }
    }
}

// Copies a credits line into EgoText, replacing every {label} with its string table text.
static wchar_t const * Expand_Labels(char const * text)
{
    EgoText[0] = 0;
    wchar_t * out = EgoText;
    char const * in = text;
    if (*text) {
        while (*in) {
            if (*in == '{') {
                unsigned length = 0;
                in++;
                char const * label = in;
                while (*in && *in != '}') {
                    length++;
                    in++;
                }
                wchar_t const * string;
                if (length == 0) {
                    string = L"{Missing Label}";
                } else if (length > 31) {
                    string = L"{Bad Label}";
                } else {
                    char name[32];
                    char * np = name;
                    in = label;
                    while (*in) {
                        if (*in == '}') break;
                        if (*in != ' ' && *in != '\t') {
                            *np++ = *in;
                        }
                        in++;
                    }
                    *np = 0;
                    if (*in == '}') {
                        in++;
                    }
#line 284
                    string = Fetch_String(name, NULL, __FILE__, __LINE__);
                }
                if (string) {
                    wcscpy(out, string);
                    out += wcslen(string);
                }
            } else {
                *out++ = *in++ & 0xff;
            }
        }
    }
    *out = 0;
    return EgoText;
}

// 0xb34d0
void Show_Who_Was_Responsible()
{
    LogicalSurface = AlternateSurface;
    CCFileClass file("CREDITS.TXT");
    if (file.Is_Available()) {
        char * buffer = new char [file.Size() + 1];
        file.Read(buffer, file.Size());

        MessageColorName = "Green";
        Point2D point(0, 0);
        Fancy_Text_Print(" ", LogicalSurface, LogicalSurface->Get_Rect(), point, ColorScheme::Find("LightGold", 1), 0, 0x148);

        int remaining = file.Size();
        int row = 0;
        int column = 0;
        int ypos = HiddenSurface->Get_Height() + 2;
        int lastrow = -2;
        char * source = buffer;
        do {
            char ch = *source++;
            remaining--;
            switch (ch) {
                case '\r':
                    row++;
                    ypos += 16;
                    column = 0;
                    break;

                case '\n':
                    break;

                case ' ':
                    column++;
                    break;

                case '\t':
                    column = (column + 8) & ~7;
                    break;

                default: {
                    char * start = source - 1;
                    char * end = source + remaining;
                    char * scan = start;
                    char prev = ch;
                    char next;
                    bool stop = false;
                    do {
                        next = *scan++;
                        switch (next) {
                            case ' ':
                                if (prev == ' ') stop = true;
                                break;

                            case '\t':
                            case '\n':
                            case '\r':
                                stop = true;
                                break;
                        }
                        if (scan >= end) stop = true;
                        prev = next;
                    } while (!stop);

                    if (scan < end) {
                        if (scan[-2] == ' ') {
                            scan--;
                        }

                        int flags = 0x48;
                        if (column > 3 && column < 8) {
                            flags = 0x148;
                        } else if (column > 8) {
                            flags = 0x248;
                        }
                        if (column > 3 && column < 8 && row - lastrow > 1) {
                            flags |= 0x80;
                        } else {
                            flags |= 0x20;
                        }
                        lastrow = row;

                        char save = scan[-1];
                        scan[-1] = 0;
                        Egos.Add(new EgoClass(0, ypos, Expand_Labels(start), flags));
                        column += scan - start;
                        scan[-1] = save;
                        remaining -= (scan - start) - 1;
                        source = scan;

                        if (next == '\r') {
                            row++;
                            ypos += 16;
                            column = 0;
                        } else if (next == '\t') {
                            column = (column + 7) & ~7;
                        }
                    }
                    break;
                }
            }
        } while (remaining > 0);

        Theme.Stop();
        HiddenSurface->Fill(0);
        Show_Surface(true, HiddenSurface, 0);
        CreditSurface = new DSurface(DSurfaceWidth, DSurfaceHeight, false);
        CreditSurface->Copy_From(*HiddenSurface, false, true);
        Keyboard->Clear();
        LogicalSurface = HiddenSurface;
        float volume = Options.ScoreVolume;
        if (volume == 0.0) {
            Options.Set_Score_Volume(0.4f, false);
        }
        Theme.Queue_Song(Theme.From_Name("CREDITS"));

        long starttime = TickCount.Value();
        int counter = 0;
        int speed = 0;
        int frame = 0;
        bool redraw = false;
        WWMouse->Hide_Mouse();

        while (Egos.Count() != 0) {
            frame++;
            if (AllSurfacesLost) {
                AllSurfacesLost = false;
                redraw = true;
                if (!Flag_839FE0) {
                    VisibleSurface->Fill(0);
                    CreditSurface->Fill(0);
                }
                WWMouse->Show_Mouse();
                WWMouse->Hide_Mouse();
            }

            if (++counter > 200 && speed < 16) {
                speed++;
                counter = 0;
            }

            int index;
            for (index = Egos.Count() - 1; index >= 0; index--) {
                if (Egos[index]->Scroll(2)) {
                    delete Egos[index];
                    Egos.Delete(index);
                    break;
                }
            }

            RectangleStruct to(0, 32, ScreenWidth, ScreenHeight - 66);
            RectangleStruct from(0, 34, ScreenWidth, ScreenHeight - 66);
            RectangleStruct top(0, 0, ScreenWidth, 34);
            RectangleStruct bottom(0, ScreenHeight - 34, ScreenWidth, 34);
            CreditSurface->Fill_Rect(top, 0);
            CreditSurface->Fill_Rect(bottom, 0);

            for (index = Egos.Count() - 1; index >= 0; index--) {
                Egos[index]->Render(redraw);
            }

            unsigned short * pixels = (unsigned short *)CreditSurface->Lock();
            if (pixels) {
                int pitch = CreditSurface->Get_Pitch() / 2;
                int line = 0;
                unsigned short * upper = pixels;
                for (int fade = 256; fade > 0; fade -= 8) {
                    int level = fade;
                    if (level >= 255) level = 255;
                    unsigned short * lower = pixels + (ScreenHeight - line - 1) * pitch;
                    unsigned short * up = upper;
                    for (int x = 0; x < ScreenWidth; x++) {
                        *up = Fade_Pixel(*up, level);
                        up++;
                        *lower = Fade_Pixel(*lower, level);
                        lower++;
                    }
                    line++;
                    upper += pitch;
                }
                CreditSurface->Unlock();
            }

            if (GameInFocus) {
                if (redraw) {
                    VisibleSurface->Copy_From(*CreditSurface, false, true);
                } else {
                    VisibleSurface->Copy_From(top, *CreditSurface, top, false, true);
                    VisibleSurface->Copy_From(to, *VisibleSurface, from, false, true);
                    VisibleSurface->Copy_From(bottom, *CreditSurface, bottom, false, true);
                }
            }
            redraw = false;

            Call_Back();
            while (TickCount.Value() - starttime < FrameDelay * frame && !Keyboard->Check()) {
            }
            if (Keyboard->Check() && Keyboard->Get() == 27) break;
        }

        while (counter <= 187) {
            if (counter < 150 && counter > 47) {
                counter = 150;
            }
            frame++;
            counter++;
            Call_Back();
            while (TickCount.Value() - starttime < FrameDelay * frame && !Keyboard->Check()) {
            }
        }

        HiddenSurface->Fill(0);
        Show_Surface(true, HiddenSurface, 0);
        WWMouse->Show_Mouse();
        MessageColorName = "Blue";
        Theme.Stop();
        Options.Set_Score_Volume(volume, false);
        delete CreditSurface;
        delete [] buffer;

        while (Egos.Count() > 0) {
            delete Egos[0];
            Egos.Delete(0);
        }
        Egos.Clear();
    }
}

// (integrator 2026-11-18: the code of the TU before 0xb3290 now lives in unnamed/TU_4B2C60.cpp)
