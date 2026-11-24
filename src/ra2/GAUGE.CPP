// GAUGE.CPP (level-2 reconstruction of GAME.EXE 1.001)
// File name inferred from class name; not proven by a C:\RA2 string.
//
// Gauge gadget (RTTI .?AVGaugeClass@@, vtable 0x78c8f4, 42 slots) and the three-colour gauge
// (RTTI .?AVTriColorGaugeClass@@, vtable 0x78c9a0, 44 slots). Chain: TriColorGaugeClass :
// GaugeClass : ControlClass : GadgetClass : LinkClass. SliderClass (SLIDER.CPP) derives from
// GaugeClass. All method, member and variable names except the class names are provisional.
//
// TU span 0x4cfc70..0x4d088f: 0xcfc70 is the 16-byte zeroing initializer _$E2 of ZeroRect (.bss
// 0x84e3a8..0x84e3b7, see below). Then the GaugeClass methods 0xcfc90..0xd01cb,
// the TriColorGaugeClass methods 0xd01d0..0xd081d, the inline accessors 0xd0820..0xd0845 and the
// two scalar deleting destructors 0xd0850 / 0xd0870. The zeroing initializer at 0xd0890 (.bss
// 0x84e3c0..) starts the next TU (GDlgSupp.cpp). The TU before (0xcfbd0..) is a timer TU.
#include "RECT.H"

// Zero rectangle with its own dynamic initializer (0x4cfc70, .bss 0x84e3a8), the same form as
// Event.CPP's ZeroRect. Name provisional.
static RectangleStruct const ZeroRect(0, 0, 0, 0);

#include "SURFACE.H"
#include "VECTOR.H"


// ---- local declarations (to be moved to headers by the integrator) ----

enum KeyNumType {
    KN_NONE = 0
};

// Gadget input flags.
enum {
    LEFTPRESS = 0x0001,
    LEFTHELD = 0x0002,
    LEFTRELEASE = 0x0004,
    LEFTUP = 0x0008,
    RIGHTPRESS = 0x0010,
    RIGHTHELD = 0x0020,
    RIGHTRELEASE = 0x0040,
    RIGHTUP = 0x0080,
    KEYBOARD = 0x0100
};

void Draw_Box(RectangleStruct const & rect, int style, bool filled);  // 0x4971b0 (name provisional)

enum {
    BOXSTYLE_DOWN = 0,                          // style values from the calls here (names provisional)
    BOXSTYLE_RAISED = 1
};

extern Surface * LogicalSurface;                   // 0x821c9c (provisional; see Egos.CPP)

// Shape palette converter (layout not reconstructed; only the fields used here).
class ConvertClass {
public:
    void * VTable;                              // +0x00 (assumed)
    int BytesPerPixel;                          // +0x04
    char Unknown8[0x174 - 0x08];
    void * ColorTable;                          // +0x174, palette index -> pixel value

    unsigned Get_Color(int index) const {
        if (BytesPerPixel == 1) {
            return ((unsigned char const *)ColorTable)[index];
        }
        return ((unsigned short const *)ColorTable)[index];
    }
};
extern ConvertClass * NormalDrawer;             // 0x81a704 (name provisional)

// RTTI .?AVColorScheme@@; only the field used here.
class ColorScheme {
public:
    char Unknown0[0x330];
    int GaugeColor;                             // +0x330, palette index (name provisional)
};
extern DynamicVectorClass<ColorScheme *> ColorSchemes;   // 0xa9ea00

// Palette indices of the tri-colour gauge (names provisional).
enum {
    TRICOLOR_GREEN = 3,
    TRICOLOR_YELLOW = 5,
    TRICOLOR_RED = 6
};

// Mouse (RTTI .?AVMouse@@, 18 slots; only the first thirteen are needed here).
class Mouse {
public:
    virtual ~Mouse();
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Hide_Mouse() = 0;              // slot 3
    virtual void Show_Mouse() = 0;              // slot 4
    virtual void Release_Mouse() = 0;           // slot 5 (meaning provisional)
    virtual void Capture_Mouse() = 0;           // slot 6 (meaning provisional)
    virtual void Slot7() = 0;
    virtual void Conditional_Hide_Mouse(RectangleStruct rect) = 0;  // slot 8 (+0x20)
    virtual void Conditional_Show_Mouse() = 0;  // slot 9 (+0x24)
    virtual int Get_Mouse_State() = 0;          // slot 10
    virtual int Get_Mouse_X() = 0;              // slot 11 (+0x2c)
    virtual int Get_Mouse_Y() = 0;              // slot 12 (+0x30)
};
extern Mouse * WWMouse;                         // 0x821fa8

// RTTI .?AVLinkClass@@ (vtable 0x78c8b4, 10 slots).
class LinkClass {
public:
    virtual ~LinkClass();                       // slot 0
    virtual LinkClass * Get_Next() const;       // slot 1
    virtual LinkClass * Get_Prev() const;       // slot 2
    virtual LinkClass & Add(LinkClass & object);        // slot 3 (0x537280)
    virtual LinkClass & Add_Tail(LinkClass & object);   // slot 4
    virtual LinkClass & Add_Head(LinkClass & object);   // slot 5
    virtual LinkClass & Head_Of_List();         // slot 6
    virtual LinkClass & Tail_Of_List();         // slot 7
    virtual void Zap();                         // slot 8
    virtual LinkClass * Remove();               // slot 9
    LinkClass * Next;                           // +0x04
    LinkClass * Prev;                           // +0x08
};

class ControlClass;

// RTTI .?AVGadgetClass@@ (vtable 0x78c82c, 33 slots).
class GadgetClass : public LinkClass {
public:
    GadgetClass(int x, int y, int w, int h, unsigned flags, int sticky = false);
    virtual ~GadgetClass();                     // 0x4cec60
    virtual LinkClass * Get_Next() const;       // slot 1
    virtual LinkClass * Get_Prev() const;       // slot 2
    virtual LinkClass * Remove();               // slot 9
    virtual KeyNumType Input();                 // slot 10
    virtual void Draw_All(bool forced = true);  // slot 11
    virtual void Delete_List();                 // slot 12
    virtual ControlClass * Extract_Gadget(unsigned id);  // slot 13
    virtual void Clear_Sticky();                // slot 14 (provisional)
    virtual void Disable();                     // slot 15
    virtual void Enable();                      // slot 16
    virtual unsigned Get_ID() const;            // slot 17
    virtual void Flag_To_Redraw();              // slot 18 (+0x48)
    virtual void Peer_To_Peer(unsigned flags, KeyNumType & key, ControlClass & whom);  // slot 19
    virtual void Set_Focus();                   // slot 20
    virtual void Clear_Focus();                 // slot 21
    virtual bool Has_Focus();                   // slot 22
    virtual int Is_List_To_Redraw();            // slot 23
    virtual bool Is_To_Redraw();                // slot 24
    virtual void Set_Position(int x, int y);    // slot 25
    virtual void Set_Size(int w, int h);        // slot 26
    virtual int Draw_Me(int forced = false);    // slot 27
    virtual void Slot28();                      // slot 28 (empty in GadgetClass)
    virtual void Slot29();                      // slot 29 (empty in GadgetClass)
    virtual void Sticky_Process(unsigned flags);        // slot 30 (+0x78)
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31
    virtual int Clicked_On(KeyNumType & key, unsigned flags, int x, int y);  // slot 32

    static int Get_Color_Scheme();              // 0x4ceba0 (index into ColorSchemes; name provisional)

    int X;                                      // +0x0c
    int Y;                                      // +0x10
    int Width;                                  // +0x14
    int Height;                                 // +0x18
    bool IsToRepaint;                           // +0x1c
    bool IsSticky;                              // +0x1d
    bool IsDisabled;                            // +0x1e
    unsigned Flags;                             // +0x20

    static GadgetClass * StuckOn;               // 0x84e320
};

// RTTI .?AVControlClass@@ (vtable 0x788ea4, 34 slots).
class ControlClass : public GadgetClass {
public:
    ControlClass(unsigned id, int x, int y, int w, int h, unsigned flags = 0, int sticky = false);  // 0x483210
    virtual unsigned Get_ID() const;            // slot 17
    virtual void Peer_To_Peer(unsigned flags, KeyNumType & key, ControlClass & whom);  // slot 19
    virtual int Draw_Me(int forced = false);    // slot 27 (0x483310)
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31 (0x483290)
    virtual void Make_Peer(GadgetClass & gadget);       // slot 33 (+0x84)

    unsigned ID;                                // +0x24
    GadgetClass * Peer;                         // +0x28
};

// RTTI .?AVGaugeClass@@ (vtable 0x78c8f4, 42 slots).
class GaugeClass : public ControlClass {
public:
    GaugeClass(unsigned id, int x, int y, int w, int h);    // 0x4cfc90
    virtual int Draw_Me(int forced = false);    // slot 27 (0x4cfe20)
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31 (0x4cffc0)
    virtual int Set_Maximum(int value);         // slot 34 (0x4cfd10)
    virtual int Set_Value(int value);           // slot 35 (+0x8c, 0x4cfd30)
    virtual int Get_Value() const { return CurValue; }      // slot 36 (0x4d0820)
    virtual void Use_Thumb(int value) { HasThumb = value ? true : false; }  // slot 37 (0x4d0830)
    virtual int Thumb_Pixels() { return 4; }    // slot 38 (+0x98, 0x4d0840)
    virtual void Draw_Thumb();                  // slot 39 (+0x9c, 0x4d0120)
    virtual int Pixel_To_Value(int pixel);      // slot 40 (+0xa0, 0x4cfd60)
    virtual int Value_To_Pixel(int value);      // slot 41 (+0xa4, 0x4cfde0)

    bool IsColorized;                           // +0x2c
    bool HasThumb;                              // +0x2d
    bool IsHorizontal;                          // +0x2e
    int MaxValue;                               // +0x30
    int CurValue;                               // +0x34
    int ClickDiff;                              // +0x38
};

// RTTI .?AVTriColorGaugeClass@@ (vtable 0x78c9a0, 44 slots).
class TriColorGaugeClass : public GaugeClass {
public:
    TriColorGaugeClass(unsigned id, int x, int y, int w, int h);    // 0x4d01d0
    virtual int Draw_Me(int forced = false);    // slot 27 (0x4d02d0)
    virtual int Set_Red_Limit(int value);       // slot 42 (0x4d0270)
    virtual int Set_Yellow_Limit(int value);    // slot 43 (0x4d02a0)

    int RedLimit;                               // +0x3c
    int YellowLimit;                            // +0x40
};

template<class T> inline T Bound(T original, T minval, T maxval)
{
    if (original < minval) return minval;
    if (original > maxval) return maxval;
    return original;
}

// ---- end of local declarations ----


// 0x4cfc90
GaugeClass::GaugeClass(unsigned id, int x, int y, int w, int h) :
    ControlClass(id, x, y, w, h, LEFTPRESS | LEFTHELD | LEFTRELEASE, true)
{
    Set_Maximum(255);
    Set_Value(0);

    HasThumb = true;
    IsHorizontal = (w > h);
    IsColorized = true;
    ClickDiff = 0;
}


// 0x4cfd10
int GaugeClass::Set_Maximum(int value)
{
    if (value != MaxValue) {
        MaxValue = value;
        Flag_To_Redraw();
        return true;
    }
    return false;
}


// 0x4cfd30
int GaugeClass::Set_Value(int value)
{
    value = Bound(value, 0, MaxValue);
    if (value != CurValue) {
        CurValue = value;
        Flag_To_Redraw();
        return true;
    }
    return false;
}


// 0x4cfd60
int GaugeClass::Pixel_To_Value(int pixel)
{
    int maxpix;
    if (IsHorizontal) {
        pixel -= X + 1;
        maxpix = Width;
    } else {
        pixel -= Y + 1;
        maxpix = Height;
    }
    maxpix -= 2;
    if (pixel < 0) {
        pixel = 0;
    } else if (pixel > maxpix) {
        pixel = maxpix;
    }
    return (int)((double)pixel / maxpix * MaxValue);
}


// 0x4cfde0
int GaugeClass::Value_To_Pixel(int value)
{
    int start;
    int maxpix;
    if (IsHorizontal) {
        maxpix = Width;
        start = X;
    } else {
        maxpix = Height;
        start = Y;
    }
    maxpix -= 2;
    return (int)((double)value / MaxValue * maxpix + start);
}


// 0x4cfe20
int GaugeClass::Draw_Me(int forced)
{
    if (ControlClass::Draw_Me(forced)) {
        WWMouse->Conditional_Hide_Mouse(RectangleStruct(X, Y, Width, Height));
        Draw_Box(RectangleStruct(X, Y, Width, Height), BOXSTYLE_DOWN, true);

        if (IsColorized) {
            int middle = Value_To_Pixel(CurValue);
            int color = ColorSchemes[Get_Color_Scheme()]->GaugeColor;
            if (IsHorizontal) {
                if (middle >= X + 1) {
                    LogicalSurface->Fill_Rect(RectangleStruct(X + 1, Y + 1, middle - X - 1, Height - 2), NormalDrawer->Get_Color(color));
                }
            } else {
                if (middle >= Y + 1) {
                    LogicalSurface->Fill_Rect(RectangleStruct(X + 1, Y + 1, Width - 2, middle - Y - 1), NormalDrawer->Get_Color(color));
                }
            }
        }

        if (HasThumb) {
            Draw_Thumb();
        }
        WWMouse->Conditional_Show_Mouse();
        return true;
    }
    return false;
}


// 0x4cffc0
int GaugeClass::Action(unsigned flags, KeyNumType & key)
{
    if (!HasThumb) {
        return false;
    }

    Sticky_Process(flags);

    if ((flags & LEFTPRESS) || ((flags & LEFTHELD) && StuckOn == this)) {
        if (flags & LEFTPRESS) {
            int curpix = Value_To_Pixel(CurValue);
            int clickpix = IsHorizontal ? WWMouse->Get_Mouse_X() : WWMouse->Get_Mouse_Y();
            if (clickpix > curpix && clickpix - curpix < Thumb_Pixels()) {
                ClickDiff = clickpix - curpix;
            } else {
                ClickDiff = 0;
            }
            int testval = Pixel_To_Value(IsHorizontal ? WWMouse->Get_Mouse_X() - ClickDiff : WWMouse->Get_Mouse_Y() - ClickDiff);
            while (testval < CurValue && ClickDiff > 0) {
                ClickDiff--;
                testval = Pixel_To_Value(IsHorizontal ? WWMouse->Get_Mouse_X() - ClickDiff : WWMouse->Get_Mouse_Y() - ClickDiff);
            }
        }

        if (!Set_Value(Pixel_To_Value((IsHorizontal ? WWMouse->Get_Mouse_X() : WWMouse->Get_Mouse_Y()) - ClickDiff))) {
            ControlClass::Action(0, key);
            key = KN_NONE;
            return true;
        }
    } else {
        flags &= ~LEFTHELD;
    }
    return ControlClass::Action(flags, key);
}


// 0x4d0120
void GaugeClass::Draw_Thumb()
{
    int x = Value_To_Pixel(CurValue);
    if (x + 4 > Value_To_Pixel(MaxValue)) {
        x = Value_To_Pixel(MaxValue) - 2;
    }
    if (x < X) {
        x = X;
    }
    if (IsHorizontal) {
        Draw_Box(RectangleStruct(x, Y, 4, Height), BOXSTYLE_RAISED, true);
    } else {
        Draw_Box(RectangleStruct(X, x, Width, 4), BOXSTYLE_RAISED, true);
    }
}


// 0x4d01d0
TriColorGaugeClass::TriColorGaugeClass(unsigned id, int x, int y, int w, int h) :
    GaugeClass(id, x, y, w, h),
    RedLimit(0),
    YellowLimit(0)
{
}


// 0x4d0270
int TriColorGaugeClass::Set_Red_Limit(int value)
{
    if (value >= 0 && value < MaxValue) {
        RedLimit = value;
        Flag_To_Redraw();
        return true;
    }
    return false;
}


// 0x4d02a0
int TriColorGaugeClass::Set_Yellow_Limit(int value)
{
    if (value >= 0 && value < MaxValue) {
        YellowLimit = value;
        Flag_To_Redraw();
        return true;
    }
    return false;
}


// 0x4d02d0
// The rectangle extents below reproduce the original arithmetic exactly, including the
// inconsistent edges of the yellow segments.
int TriColorGaugeClass::Draw_Me(int forced)
{
    if (GaugeClass::Draw_Me(forced)) {
        WWMouse->Conditional_Hide_Mouse(RectangleStruct(X, Y, Width, Height));
        Draw_Box(RectangleStruct(X, Y, Width, Height), IsDisabled ? BOXSTYLE_RAISED : BOXSTYLE_DOWN, true);

        int red = Value_To_Pixel(RedLimit);
        int yellow = Value_To_Pixel(YellowLimit);
        int middle = Value_To_Pixel(CurValue);

        if (CurValue <= RedLimit) {
            if (IsHorizontal) {
                LogicalSurface->Fill_Rect(RectangleStruct(X + 1, Y + 1, middle - X + 1, Height - 2), NormalDrawer->Get_Color(TRICOLOR_RED));
            } else {
                LogicalSurface->Fill_Rect(RectangleStruct(X + 1, Y + 1, Width - 2, middle - Y + 1), NormalDrawer->Get_Color(TRICOLOR_RED));
            }
        } else if (CurValue > RedLimit && CurValue <= YellowLimit) {
            if (IsHorizontal) {
                LogicalSurface->Fill_Rect(RectangleStruct(X + 1, Y + 1, red - X + 1, Height - 2), NormalDrawer->Get_Color(TRICOLOR_RED));
                LogicalSurface->Fill_Rect(RectangleStruct(red - X + 1, Y + 1, middle - X - 1, Height - 2), NormalDrawer->Get_Color(TRICOLOR_YELLOW));
            } else {
                LogicalSurface->Fill_Rect(RectangleStruct(X + 1, Y + 1, Width - 2, red - Y + 1), NormalDrawer->Get_Color(TRICOLOR_RED));
                LogicalSurface->Fill_Rect(RectangleStruct(X + 1, red - Y + 1, X + Width - 2, middle - Y + 1), NormalDrawer->Get_Color(TRICOLOR_YELLOW));
            }
        } else if (CurValue > YellowLimit && CurValue <= MaxValue) {
            if (IsHorizontal) {
                LogicalSurface->Fill_Rect(RectangleStruct(X + 1, Y + 1, red - X + 1, Height - 2), NormalDrawer->Get_Color(TRICOLOR_RED));
                LogicalSurface->Fill_Rect(RectangleStruct(red, Y + 1, yellow - X + 1, Height - 2), NormalDrawer->Get_Color(TRICOLOR_YELLOW));
                LogicalSurface->Fill_Rect(RectangleStruct(yellow, Y + 1, middle - X + 1, Height - 2), NormalDrawer->Get_Color(TRICOLOR_GREEN));
            } else {
                LogicalSurface->Fill_Rect(RectangleStruct(X + 1, Y + 1, Width - 2, red - Y + 1), NormalDrawer->Get_Color(TRICOLOR_RED));
                LogicalSurface->Fill_Rect(RectangleStruct(X + 1, red, Width - 2, yellow - Y + 1), NormalDrawer->Get_Color(TRICOLOR_YELLOW));
                LogicalSurface->Fill_Rect(RectangleStruct(X + 1, yellow, Width - 2, middle - Y + 1), NormalDrawer->Get_Color(TRICOLOR_GREEN));
            }
        }

        if (HasThumb) {
            Draw_Thumb();
        }
        WWMouse->Conditional_Show_Mouse();
        return true;
    }
    return false;
}
