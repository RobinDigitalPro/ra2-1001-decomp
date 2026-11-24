// C:\RA2\WDTTerr.cpp (level-2 reconstruction of GAME.EXE 1.001)
// WorldDominationTour::Territory: one selectable territory of the World Domination Tour map, with its
// INI-defined target/origin points, its overlay shape and its two map animations.
// Class names come from RTTI (.?AVTerritory@WorldDominationTour@@, rc_ptr, VectorCursor, MSOverlayAnim,
// MSEngine, CCFileClass); all other names are provisional.
#include "GAMECONST.H"

// ---- local declarations (to be moved to headers by the integrator) ----
#include <stddef.h>
#include "VECTOR.H"

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);   // 0x2eeb60 (also in ABSTYPE.H)

// Simple owned narrow string, one pointer (library code near 0x359250; name provisional).
class CharStringClass {
public:
    CharStringClass();                                          // 0x359250
    CharStringClass(char const * string);                       // 0x359260
    CharStringClass(CharStringClass const & string);            // 0x3592c0
    ~CharStringClass();                                         // 0x359320
    CharStringClass & operator = (CharStringClass const & string);   // 0x359570
    CharStringClass operator + (char const * string) const;    // 0x3599d0
    char const * Peek_Buffer() const;                           // 0x35a030 (Buffer or NullString)
    char * Buffer;
};
CharStringClass operator + (char const * string1, CharStringClass const & string2);            // 0x35aff0
CharStringClass operator + (CharStringClass const & string1, CharStringClass const & string2); // 0x35b110
CharStringClass Int_To_String(int value);                                                      // 0x35aec0 ("%d")
CharStringClass Int_To_String(int value, int width);                                           // 0x35af50 ("%0<width>d")

// Simple owned wide string, one pointer (library code near 0x35b2f0; name provisional).
class WideStringClass {
public:
    WideStringClass();                                          // 0x35b2f0
    ~WideStringClass();                                         // 0x35b390
    WideStringClass & operator = (wchar_t const * string);      // 0x35b4b0
    wchar_t * Buffer;
};

// Screen width in pixels (0x83a710; name provisional).
extern int ScreenWidth;

struct Point2D {
    Point2D() {}
    Point2D(int x, int y) : X(x), Y(y) {}
    int X;
    int Y;
};

// RTTI .?AV?$TRect@H@@ appears in VectorCursor<TRect<int>,...>; member names provisional.
template<class T>
class TRect {
public:
    TRect() {}
    bool Is_Valid() const { return Width > 0 && Height > 0; }
    T X;
    T Y;
    T Width;
    T Height;
};

template<class T>
TRect<T> const Union(TRect<T> const & rect1, TRect<T> const & rect2)
{
    TRect<T> result = rect1;
    if (result.Is_Valid()) {
        if (rect2.Is_Valid()) {
            if (result.X > rect2.X) {
                result.Width += result.X - rect2.X;
                result.X = rect2.X;
            }
            if (result.Y > rect2.Y) {
                result.Height += result.Y - rect2.Y;
                result.Y = rect2.Y;
            }
            if (result.X + result.Width < rect2.X + rect2.Width) {
                result.Width = ((rect2.X + rect2.Width) - result.X) + 1;
            }
            if (result.Y + result.Height < rect2.Y + rect2.Height) {
                result.Height = ((rect2.Y + rect2.Height) - result.Y) + 1;
            }
        }
    } else {
        result = rect2;
    }
    return result;
}

// INI database; 0x50ec50 reads "x,y" with a default (class and name provisional).
class INIClass {
public:
    Point2D Get_Point(CharStringClass const & section, CharStringClass const & entry, Point2D const & defvalue) const;   // 0x50ec50
};

// File class hierarchy, as in Restate.cpp (signatures provisional).
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
    char RawFileData[0x1C];
};

class BufferIOFileClass : public RawFileClass {
public:
    virtual ~BufferIOFileClass();       // 0x42f250
private:
    char BufferIOData[0x34];
};

class CDFileClass : public BufferIOFileClass {
public:
    virtual ~CDFileClass() {}
    virtual char const * Set_Name(char const * filename);   // 0x46fd50
};

class Buffer {
public:
    Buffer(void * buffer = NULL, long size = 0);   // 0x438140
    ~Buffer();                                     // 0x438290
private:
    void * BufferPtr;
    long Size;
    bool IsAllocated;
};

class CCFileClass : public CDFileClass {
public:
    CCFileClass(CharStringClass const & filename);          // 0x468bb0
    virtual ~CCFileClass() { Position = 0; }
    virtual bool Is_Available(int forced = false);          // 0x468dc0
    virtual void Close();                                   // 0x468e10
private:
    Buffer Data;                        // +0x54
    long Position;                      // +0x60
};

// RTTI .?AVMSAnim@@, vtable 0x791d10 (9 slots).
class MSAnim {
public:
    virtual ~MSAnim();
    virtual void Set_Visible(bool visible);          // slot 1: 0x5ac7e0 writes +0x0c
    virtual void Virtual_02();
    virtual void Virtual_03();
    virtual void Virtual_04() = 0;
    virtual void Virtual_05() = 0;
    virtual TRect<int> Get_Rect() const = 0;         // slot 6
    virtual void Virtual_07();
    virtual void Virtual_08();
};

// RTTI .?AVMSOverlayAnim@@ : MSFadeAnim : MSShapeAnim : MSAnim, vtable 0x791d88, size 0x4c.
class MSOverlayAnim : public MSAnim {
public:
    MSOverlayAnim(CharStringClass const & filename, int x, int y, void * palette, int unknown5,
        DynamicVectorClass<MSAnim *> * list, bool unknown7, int unknown8, bool unknown9);   // 0x5a9f50
    void Reset();                    // 0x5aa3f0 clears +0x40
    int Set_Frame(int frame);        // 0x5aa400
    virtual void Virtual_04();       // 0x5aa030
    virtual void Virtual_05();       // 0x5aa290
    virtual TRect<int> Get_Rect() const;   // 0x5a98e0 (MSShapeAnim)
    virtual void Virtual_07();       // 0x5aa4a0
    virtual void Virtual_08();       // 0x5aa420
private:
    char OverlayData[0x48];          // +0x04, layout not reconstructed
};

// RTTI .?AVMSEngine@@, vtable 0x791ffc (3 slots).
class MSEngine {
public:
    virtual ~MSEngine();
    virtual void Virtual_01();
    virtual void Virtual_02();
    void Add_Anim(MSAnim * anim);                    // 0x5af940
    void Remove_Anim_Later(MSAnim * anim, int delay);   // 0x5afb10
    void Update();                                   // 0x5afb70
    void Redraw(bool force);                         // 0x5b0130
    void Invalidate(TRect<int> const & rect);        // 0x5b03e0
    int Unknown04[5];
    DynamicVectorClass<MSAnim *> Anims;              // +0x18
};

// RTTI .?AVReferenceCounted@@, vtable 0x793cd4.
class ReferenceCounted {
public:
    ReferenceCounted() : ReferenceCount(0) {}
    virtual ~ReferenceCounted();                 // 0x230cb0 (deleting 0x230cf0)
    virtual bool Is_Kind(int kind) const;        // 0x230ce0
    virtual void Release();                      // 0x230cc0
    void Add_Ref() { ++ReferenceCount; }
    int ReferenceCount;
};

// RTTI .?AVrc_ptr_base@@, vtable 0x793ccc.
class rc_ptr_base {
public:
    rc_ptr_base();                               // 0x230a80
    rc_ptr_base(ReferenceCounted * pointer);     // 0x230a90
    rc_ptr_base(rc_ptr_base const & other);      // 0x230b00
    virtual ~rc_ptr_base();                      // 0x230ab0 (deleting 0x230b20)
    void Set(ReferenceCounted * pointer);        // 0x230ad0
protected:
    ReferenceCounted * Pointer;
};

template<class T>
class rc_ptr : public rc_ptr_base {
public:
    rc_ptr() {}
    rc_ptr(T * pointer) { Set(pointer); }
    rc_ptr(rc_ptr<T> const & other) { Set(other.Pointer); }
    virtual ~rc_ptr() {}
    T * Get() const { return (T *)Pointer; }
    T * operator -> () const { return (T *)Pointer; }
    bool operator == (rc_ptr<T> const & other) const { return Pointer == other.Pointer; }
    bool operator != (rc_ptr<T> const & other) const { return Pointer != other.Pointer; }
};

// RTTI .?AV?$VectorCursor@...@@ (4 slots: destructor, Is_Valid, operator++, operator--).
template<class T, class V>
class VectorCursor {
public:
    VectorCursor(V & vector) : Vector(&vector), Index(0) {}
    virtual ~VectorCursor() {}
    virtual bool Is_Valid() const { return Index < Vector->ActiveCount; }
    virtual VectorCursor<T, V> & operator ++ () { ++Index; return *this; }
    virtual VectorCursor<T, V> & operator -- () { --Index; return *this; }
    T & operator * () const { return (*Vector)[Index]; }
    V * Vector;
    int Index;
};

namespace WorldDominationTour {

// RTTI .?AVTerritory@WorldDominationTour@@, vtable 0x79a27c, size 0x30.
class Territory : public ReferenceCounted {
public:
    Territory(int id, INIClass & ini, CharStringClass const & section,
        CharStringClass const & shape_prefix, CharStringClass const & name_prefix);
    virtual ~Territory();

    static rc_ptr<Territory> Create(int id, INIClass & ini, CharStringClass const & section,
        CharStringClass const & shape_prefix, CharStringClass const & name_prefix);
    static rc_ptr<Territory> Find(DynamicVectorClass<rc_ptr<Territory> > & list, int id);

    void Create_Overlay(MSEngine & engine, void * palette, Point2D const & offset);
    void Create_Highlight(MSEngine & engine, void * palette, Point2D const & offset);
    void Set_State(int state, MSEngine & engine, int unused);
    void Show_Highlight(bool show, MSEngine & engine);
    void Set_Pending(int value);
    int Take_Pending();

    int ID;                          // +08
    WideStringClass Name;            // +0C
    Point2D Target;                  // +10
    Point2D Origin;                  // +18
    CharStringClass ShapeName;       // +20
    MSOverlayAnim * OverlayAnim;     // +24
    MSOverlayAnim * HighlightAnim;   // +28
    int Pending;                     // +2C
};

}
// ---- end of local declarations ----

using namespace WorldDominationTour;

// 0x325740
rc_ptr<Territory> Territory::Create(int id, INIClass & ini, CharStringClass const & section,
    CharStringClass const & shape_prefix, CharStringClass const & name_prefix)
{
    return rc_ptr<Territory>(new Territory(id, ini, section, shape_prefix, name_prefix));
}

// 0x3257a0; the original __LINE__ of the Fetch_String call is 39.
#line 28 "C:\\RA2\\WDTTerr.cpp"
Territory::Territory(int id, INIClass & ini, CharStringClass const & section,
    CharStringClass const & shape_prefix, CharStringClass const & name_prefix) :
    ID(id),
    Target(0, 0),
    Origin(0, 0),
    OverlayAnim(NULL),
    HighlightAnim(NULL),
    Pending(0)
{
    ShapeName = shape_prefix + Int_To_String(id, 2) + ".shp";
    CharStringClass label = name_prefix + Int_To_String(id, 2);
    Name = Fetch_String(label.Peek_Buffer(), NULL, __FILE__, __LINE__);

    CharStringClass width = Int_To_String(ScreenWidth);
    Target = ini.Get_Point(section, "Target_" + width, Target);
    Origin = ini.Get_Point(section, "Origin_" + width, Origin);
    if (ScreenWidth > 800) {
        if (Target.X == 0 && Target.Y == 0) {
            Target = ini.Get_Point(section, "Target_800", Target);
        }
        if (Origin.X == 0 && Origin.Y == 0) {
            Origin = ini.Get_Point(section, "Origin_800", Origin);
        }
    }
}

// 0x3259c0
void Territory::Create_Overlay(MSEngine & engine, void * palette, Point2D const & offset)
{
    int x = Origin.X + offset.X;
    int y = Origin.Y + offset.Y;
    CCFileClass file(ShapeName);
    if (file.Is_Available()) {
        OverlayAnim = new MSOverlayAnim(ShapeName, x, y, palette, 0, &engine.Anims, true, -1, false);
        OverlayAnim->Set_Visible(false);
        engine.Add_Anim(OverlayAnim);
    }
}

// 0x325a80
void Territory::Create_Highlight(MSEngine & engine, void * palette, Point2D const & offset)
{
    int x = Origin.X + offset.X;
    int y = Origin.Y + offset.Y;
    CCFileClass file(ShapeName);
    if (file.Is_Available()) {
        HighlightAnim = new MSOverlayAnim(ShapeName, x, y, palette, 0, &engine.Anims, true, 0, false);
        HighlightAnim->Set_Visible(false);
        engine.Add_Anim(HighlightAnim);
    }
}

// 0x325b40 (scalar deleting destructor 0x325e50)
Territory::~Territory()
{
}

// 0x325b70
void Territory::Set_State(int state, MSEngine & engine, int)
{
    if (OverlayAnim != NULL) {
        int frame = -1;
        switch (state) {
            case 1:
                frame = 3;
                break;
            case 2:
                frame = 2;
                break;
            case 3:
                frame = 1;
                break;
        }
        TRect<int> oldrect = OverlayAnim->Get_Rect();
        if (frame >= 0) {
            OverlayAnim->Set_Frame(frame);
            OverlayAnim->Set_Visible(true);
            OverlayAnim->Reset();
        } else {
            OverlayAnim->Set_Visible(false);
        }
        engine.Invalidate(Union(OverlayAnim->Get_Rect(), oldrect));
        engine.Update();
        engine.Redraw(true);
    }
}

// 0x325ce0
void Territory::Show_Highlight(bool show, MSEngine & engine)
{
    if (HighlightAnim != NULL) {
        HighlightAnim->Set_Visible(show);
        TRect<int> rect = HighlightAnim->Get_Rect();
        engine.Invalidate(rect);
        engine.Update();
        engine.Remove_Anim_Later(HighlightAnim, 300000);
    }
}

// 0x325d50
void Territory::Set_Pending(int value)
{
    Pending = value;
}

// 0x325d60
int Territory::Take_Pending()
{
    int value = Pending;
    Pending = 0;
    return value;
}

// Finds the entry with the given ID from the current cursor position on.
template<class T, class V>
inline rc_ptr<T> Find_ID(VectorCursor<rc_ptr<T>, V> & cursor, int id)
{
    for (; cursor.Is_Valid(); ++cursor) {
        if ((*cursor)->ID == id) {
            break;
        }
    }
    return cursor.Is_Valid() ? *cursor : rc_ptr<T>();
}

// 0x325d70
rc_ptr<Territory> Territory::Find(DynamicVectorClass<rc_ptr<Territory> > & list, int id)
{
    VectorCursor<rc_ptr<Territory>, DynamicVectorClass<rc_ptr<Territory> > > cursor(list);
    return Find_ID(cursor, id);
}
