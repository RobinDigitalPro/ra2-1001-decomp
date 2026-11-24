// SLIDER.CPP (level-2 reconstruction of GAME.EXE 1.001)
// File name inferred from class name; not proven by a C:\RA2 string.
//
// Slider gadget: a gauge with a draggable thumb and, unless it belongs to a list box, two
// shape buttons (BTN-PLUS.SHP / BTN-MINS.SHP) that step the value. The class name comes from
// RTTI (.?AVSliderClass@@, vtable 0x790734, 45 slots) with the chain SliderClass : GaugeClass :
// ControlClass : GadgetClass : LinkClass. All method, member and variable names are provisional.
//
// TU span 0x679df0..0x67a479: 0x279df0 is the 16-byte zeroing header initializer (.bss
// 0xaa4908..0xaa4917, written only by that initializer; it lies after Skirmish.cpp's last static
// 0xaa4904 and before 0xaa4918, which belongs to the GAMECONST block of the next TU; header not
// reproduced, not claimed). Then the SliderClass methods 0x279e10..0x27a479. The GAMECONST
// block at 0x27a480 starts the next TU. SliderClass's scalar deleting destructor (0x538d20) and
// its inline Thumb_Pixels (0x538cc0) were emitted as COMDATs by an earlier TU (the list box).
#include "RECT.H"


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

void * MFCD_Retrieve(char const * filename);    // 0x5924c0 (see Beacon.CPP; name provisional)
void Draw_Box(RectangleStruct const & rect, int style, bool filled);  // 0x4971b0 (name provisional)

enum {
    BOXSTYLE_DOWN = 0,                          // style values from the calls here (names provisional)
    BOXSTYLE_RAISED = 1
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
    virtual void Slot8() = 0;
    virtual void Slot9() = 0;
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
    virtual void Sticky_Process(unsigned flags);        // slot 30
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31
    virtual int Clicked_On(KeyNumType & key, unsigned flags, int x, int y);  // slot 32

    int X;                                      // +0x0c
    int Y;                                      // +0x10
    int Width;                                  // +0x14
    int Height;                                 // +0x18
    bool IsToRepaint;                           // +0x1c
    bool IsSticky;                              // +0x1d
    bool IsDisabled;                            // +0x1e
    unsigned Flags;                             // +0x20
};

// RTTI .?AVControlClass@@ (vtable 0x788ea4, 34 slots).
class ControlClass : public GadgetClass {
public:
    ControlClass(unsigned id, int x, int y, int w, int h, unsigned flags = 0, int sticky = false);  // 0x483210
    virtual unsigned Get_ID() const;            // slot 17
    virtual void Peer_To_Peer(unsigned flags, KeyNumType & key, ControlClass & whom);  // slot 19
    virtual int Draw_Me(int forced = false);    // slot 27 (0x483310)
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31
    virtual void Make_Peer(GadgetClass & gadget);       // slot 33 (+0x84)

    unsigned ID;                                // +0x24
    GadgetClass * Peer;                         // +0x28
};

// RTTI .?AVToggleClass@@ (vtable 0x78b730, 34 slots); layout not reconstructed.
class ToggleClass : public ControlClass {
public:
    char ToggleData[0x10];                      // +0x2c
};

// RTTI .?AVShapeButtonClass@@ (vtable 0x78b6a0, 35 slots); 0x60 bytes, layout not reconstructed.
class ShapeButtonClass : public ToggleClass {
public:
    ShapeButtonClass(unsigned id, void const * shapes, int x, int y, int a5 = 0, int a6 = 0, int a7 = 0);  // 0x66a9e0
    char ShapeButtonData[0x24];                 // +0x3c
};

// RTTI .?AVGaugeClass@@ (vtable 0x78c8f4, 42 slots).
class GaugeClass : public ControlClass {
public:
    GaugeClass(unsigned id, int x, int y, int w, int h);    // 0x4cfc90
    virtual int Draw_Me(int forced = false);    // slot 27 (0x4cfe20)
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31 (0x4cffc0)
    virtual int Set_Maximum(int value);         // slot 34 (0x4cfd10)
    virtual int Set_Value(int value);           // slot 35 (+0x8c, 0x4cfd30)
    virtual int Get_Value() const;              // slot 36
    virtual void Use_Thumb(int value);          // slot 37
    virtual int Thumb_Pixels();                 // slot 38
    virtual void Draw_Thumb();                  // slot 39
    virtual int Pixel_To_Value(int pixel);      // slot 40
    virtual int Value_To_Pixel(int value);      // slot 41

    bool IsColorized;                           // +0x2c
    bool HasThumb;                              // +0x2d
    bool IsHorizontal;                          // +0x2e
    int MaxValue;                               // +0x30
    int CurValue;                               // +0x34
    int ClickDiff;                              // +0x38
};

// RTTI .?AVSliderClass@@ (vtable 0x790734, 45 slots).
class SliderClass : public GaugeClass {
public:
    SliderClass(unsigned id, int x, int y, int w, int h, int belong_to_list = false);
    virtual ~SliderClass();
    virtual void Peer_To_Peer(unsigned flags, KeyNumType & key, ControlClass & whom);  // slot 19
    virtual int Draw_Me(int forced = false);    // slot 27
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31
    virtual int Set_Maximum(int value);         // slot 34
    virtual int Set_Value(int value);           // slot 35
    virtual int Thumb_Pixels() { return ThumbSize; }    // slot 38 (copy used: 0x538cc0)
    virtual void Draw_Thumb();                  // slot 39 (+0x9c)
    virtual void Set_Thumb_Size(int value);     // slot 42
    virtual int Bump(int up);                   // slot 43 (+0xac)
    virtual int Step(int up);                   // slot 44 (+0xb0)

    void Recalc_Thumb();

    ShapeButtonClass * PlusGadget;              // +0x3c
    ShapeButtonClass * MinusGadget;             // +0x40
    bool BelongToList;                          // +0x44, no step buttons when set
    int Thumb;                                  // +0x48, thumb size in value units
    int ThumbSize;                              // +0x4c, thumb size in pixels
    int ThumbStart;                             // +0x50, thumb offset in pixels
};

// ---- end of local declarations ----


// 0x679e10
SliderClass::SliderClass(unsigned id, int x, int y, int w, int h, int belong_to_list) :
    GaugeClass(id, x, y, w, h)
{
    BelongToList = belong_to_list ? true : false;
    PlusGadget = 0;
    MinusGadget = 0;

    if (!BelongToList) {
        PlusGadget = new ShapeButtonClass(id, MFCD_Retrieve("BTN-PLUS.SHP"), X + Width + 2, Y);
        MinusGadget = new ShapeButtonClass(id, MFCD_Retrieve("BTN-MINS.SHP"), X - 6, Y);

        if (PlusGadget) {
            PlusGadget->Make_Peer(*this);
            PlusGadget->Add(*this);
            PlusGadget->Flag_To_Redraw();
        }
        if (MinusGadget) {
            MinusGadget->Make_Peer(*this);
            MinusGadget->Add(*this);
            MinusGadget->Flag_To_Redraw();
        }
    }
    Set_Thumb_Size(1);
    Recalc_Thumb();
    IsColorized = false;
}


// 0x679ff0
SliderClass::~SliderClass()
{
    if (PlusGadget) {
        delete PlusGadget;
        PlusGadget = 0;
    }
    if (MinusGadget) {
        delete MinusGadget;
        MinusGadget = 0;
    }
}


// 0x67a030
int SliderClass::Set_Maximum(int value)
{
    if (GaugeClass::Set_Maximum(value)) {
        Recalc_Thumb();
        return true;
    }
    return false;
}


// 0x67a0b0
void SliderClass::Set_Thumb_Size(int value)
{
    Thumb = value < MaxValue ? value : MaxValue;
    Thumb = Thumb > 1 ? Thumb : 1;
    Flag_To_Redraw();
    Recalc_Thumb();
}


// 0x67a140
int SliderClass::Set_Value(int value)
{
    int limit = MaxValue - Thumb;
    value = value < limit ? value : limit;
    if (GaugeClass::Set_Value(value)) {
        Recalc_Thumb();
        return true;
    }
    return false;
}


// 0x67a1d0
void SliderClass::Recalc_Thumb()
{
    int length = IsHorizontal ? Width : Height;
    int size = (int)((double)Thumb / MaxValue * length);
    ThumbSize = size > 4 ? size : 4;
    int start = (int)((double)CurValue / MaxValue * length);
    ThumbStart = start < length - ThumbSize ? start : length - ThumbSize;
}


// 0x67a240
int SliderClass::Action(unsigned flags, KeyNumType & key)
{
    if (flags & LEFTPRESS) {
        int mouse;
        int edge;
        if (IsHorizontal) {
            mouse = WWMouse->Get_Mouse_X();
            edge = X;
        } else {
            mouse = WWMouse->Get_Mouse_Y();
            edge = Y;
        }
        edge += 1;

        if (mouse < edge + ThumbStart) {
            Bump(true);
            GaugeClass::Action(0, key);
            key = KN_NONE;
            return true;
        }
        if (mouse > edge + ThumbStart + ThumbSize) {
            Bump(false);
            GaugeClass::Action(0, key);
            key = KN_NONE;
            return true;
        }
        GaugeClass::Action(flags, key);
        key = KN_NONE;
        return true;
    }
    return GaugeClass::Action(flags, key);
}


// 0x67a2e0
int SliderClass::Bump(int up)
{
    if (up) {
        return Set_Value(CurValue - Thumb);
    }
    return Set_Value(CurValue + Thumb);
}


// 0x67a320
int SliderClass::Step(int up)
{
    if (up) {
        return Set_Value(CurValue - 1);
    }
    return Set_Value(CurValue + 1);
}


// 0x67a350
void SliderClass::Draw_Thumb()
{
    if (IsHorizontal) {
        Draw_Box(RectangleStruct(X + ThumbStart, Y, ThumbSize, Height), BOXSTYLE_RAISED, true);
    } else {
        Draw_Box(RectangleStruct(X, Y + ThumbStart, Width, ThumbSize), BOXSTYLE_RAISED, true);
    }
}


// 0x67a3d0
int SliderClass::Draw_Me(int forced)
{
    if (BelongToList && ControlClass::Draw_Me(forced)) {
        Draw_Box(RectangleStruct(X, Y, Width, Height), BOXSTYLE_DOWN, true);
        Draw_Thumb();
        return true;
    }
    return GaugeClass::Draw_Me(forced);
}


// 0x67a440
void SliderClass::Peer_To_Peer(unsigned flags, KeyNumType &, ControlClass & whom)
{
    if (flags & LEFTRELEASE) {
        if (&whom == PlusGadget) {
            Step(false);
        }
        if (&whom == MinusGadget) {
            Step(true);
        }
    }
}
