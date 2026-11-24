// file name inferred from class name; not proven by a C:\RA2 string
// GADGET.CPP (level-2 reconstruction of GAME.EXE 1.001)
//
// Gadget base class: a rectangular input/draw element in a linked gadget list, with the list
// input dispatcher and the sticky/focus/mouse-over bookkeeping (RTTI .?AVGadgetClass@@, vtable
// 0x78c82c, 33 slots; chain GadgetClass : LinkClass). All method, member and variable names
// except the class names are provisional.
//
// TU span 0x4ceb80..0x4cf30b: 0x4ceb80 is the 16-byte zeroing header initializer (.bss
// 0x84e310..0x84e31f; not reproduced, not claimed). The TU's own statics follow directly in .bss
// (StuckOn 0x84e320, LastList 0x84e324, Focused 0x84e328, MouseOver 0x84e32c). Then the methods
// 0x4ceba0..0x4cf26e and the scalar deleting destructors of GadgetClass (0x4cf280) and
// LinkClass (0x4cf2f0, COMDAT chosen from this object). The zeroing initializer 0x4cf310 (.bss
// 0x84e338) starts the next TU.
#include "RECT.H"


// ---- local declarations (to be moved to headers by the integrator) ----

enum KeyNumType {
    KN_NONE = 0,
    KN_LMOUSE = 0x01,                           // VK_LBUTTON
    KN_RMOUSE = 0x02,                           // VK_RBUTTON
    KN_RLSE_BIT = 0x0800,                       // key release flag
    KN_RIGHT_BUTTON = 0x4000,                   // added to a control ID on a right release (name provisional)
    KN_BUTTON = 0x8000                          // marks a control ID
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

// RTTI .?AVLinkClass@@ (vtable 0x78c8b4, 10 slots); see LINK.CPP.
class LinkClass {
public:
    LinkClass() : Next(0), Prev(0) {}
    LinkClass(LinkClass & link);                // 0x537140
    virtual ~LinkClass();                       // 0x537180
    LinkClass & operator = (LinkClass & link);  // 0x5371e0

    virtual LinkClass * Get_Next() const;       // slot 1
    virtual LinkClass * Get_Prev() const;       // slot 2
    virtual LinkClass & Add(LinkClass & object);        // slot 3
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

// RTTI .?AVGadgetClass@@ (vtable 0x78c82c, 33 slots); see GADGET.CPP. Slots 14, 17, 19 and 24
// are header inlines: their single copies lie in the first objects in link order that emit a
// vtable referencing them (0x47d2f0, 0x49ea00, 0x483340, 0x47d300).
class GadgetClass : public LinkClass {
public:
    GadgetClass(int x, int y, int w, int h, unsigned flags, bool sticky = false);  // 0x4cebc0
    GadgetClass(GadgetClass const & gadget);    // 0x4cec10
    virtual ~GadgetClass();                     // 0x4cec60
    virtual LinkClass * Get_Next() const;       // slot 1 (0x4ced70)
    virtual LinkClass * Get_Prev() const;       // slot 2 (0x4ced80)
    virtual LinkClass * Remove();               // slot 9 (0x4ced50)
    virtual KeyNumType Input();                 // slot 10 (0x4cef10)
    virtual void Draw_All(bool forced = true);  // slot 11 (0x4cee40)
    virtual void Delete_List();                 // slot 12 (0x4ced90)
    virtual ControlClass * Extract_Gadget(unsigned id);  // slot 13 (0x4cf140)
    virtual void Flag_List_To_Redraw() { LastList = 0; }    // slot 14 (copy used: 0x47d2f0)
    virtual void Disable();                     // slot 15 (0x4ced30)
    virtual void Enable();                      // slot 16 (0x4ced20)
    virtual unsigned Get_ID() const { return 0; }           // slot 17 (copy used: 0x49ea00)
    virtual void Flag_To_Redraw();              // slot 18 (+0x48, 0x4cf180)
    virtual void Peer_To_Peer(unsigned flags, KeyNumType & key, ControlClass & whom) {}    // slot 19 (+0x4c, copy used: 0x483340)
    virtual void Set_Focus();                   // slot 20 (0x4cf1c0)
    virtual void Clear_Focus();                 // slot 21 (+0x54, 0x4cf1f0)
    virtual bool Has_Focus();                   // slot 22 (0x4cf210)
    virtual int Is_List_To_Redraw();            // slot 23 (0x4cf220)
    virtual bool Is_To_Redraw() { return IsToRepaint; }     // slot 24 (copy used: 0x47d300)
    virtual void Set_Position(int x, int y);    // slot 25 (0x4cf240)
    virtual void Set_Size(int w, int h);        // slot 26 (0x4cf260)
    virtual int Draw_Me(int forced = false);    // slot 27 (+0x6c, 0x4cee20)
    virtual void Mouse_Enter();                 // slot 28 (+0x70, 0x4cede0; name provisional)
    virtual void Mouse_Leave();                 // slot 29 (+0x74, 0x4cedf0; name provisional)
    virtual void Sticky_Process(unsigned flags);        // slot 30 (+0x78, 0x4cf190)
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31 (+0x7c, 0x4cee00)
    virtual int Clicked_On(KeyNumType & key, unsigned flags, int x, int y);  // slot 32 (+0x80, 0x4cecc0)

    static int Get_Color_Scheme();              // 0x4ceba0 (index into ColorSchemes; name provisional)
    int Is_Enabled() const;                     // 0x4ced40 (name provisional)
    GadgetClass * Find_Gadget(int x, int y);    // 0x4cee70 (name provisional)

    int X;                                      // +0x0c
    int Y;                                      // +0x10
    int Width;                                  // +0x14
    int Height;                                 // +0x18
    bool IsToRepaint;                           // +0x1c
    bool IsSticky;                              // +0x1d
    bool IsDisabled;                            // +0x1e
    unsigned Flags;                             // +0x20

    static GadgetClass * StuckOn;               // 0x84e320
    static GadgetClass * LastList;              // 0x84e324
    static GadgetClass * Focused;               // 0x84e328
    static GadgetClass * MouseOver;             // 0x84e32c (name provisional)
};

// RTTI .?AVControlClass@@ (vtable 0x788ea4, 34 slots); see CONTROL.CPP. No explicit destructor.
class ControlClass : public GadgetClass {
public:
    ControlClass(unsigned id, int x, int y, int w, int h, unsigned flags = 0, bool sticky = false);  // 0x483210
    ControlClass(ControlClass const & control); // 0x483260
    virtual unsigned Get_ID() const;            // slot 17 (+0x44, 0x483300)
    virtual int Draw_Me(int forced = false);    // slot 27 (0x483310)
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31 (0x483290)
    virtual void Make_Peer(GadgetClass & gadget);       // slot 33 (+0x84, 0x4832f0)

    unsigned ID;                                // +0x24
    GadgetClass * Peer;                         // +0x28
};

// RTTI .?AVToggleClass@@ (vtable 0x78b730, 34 slots, 0x34 bytes); see TOGGLE.CPP. No explicit destructor.
class ToggleClass : public ControlClass {
public:
    ToggleClass(unsigned id, int x, int y, int w, int h);   // 0x6e03e0
    virtual int Action(unsigned flags, KeyNumType & key);  // slot 31 (0x6e0440)

    void Turn_On();                             // 0x6e0420
    void Turn_Off();                            // 0x6e0430

    bool IsPressed;                             // +0x2c
    bool IsOn;                                  // +0x2d
    int ToggleType;                             // +0x30: 1 toggles on release, 2 latches on (names provisional)
};

// RTTI-less colour scheme (vector element type "ColorScheme"); only what is used here.
class ColorScheme {
public:
    static ColorScheme * Find(char const * name, int shades);  // 0x65ace0 (see Egos.CPP)
    int ID;                                     // +0x00, index in ColorSchemes (name provisional)
};
extern char const * MessageColorName;           // 0x7c34a4 (provisional; see Egos.CPP)

class WWKeyboardClass {
public:
    unsigned short Check();                     // 0x530530
    unsigned short Get();                       // 0x530580
    bool Down(int key);                         // 0x530af0
    int MouseQX;                                // +0x00, mouse x of the last queued mouse key
    int MouseQY;                                // +0x04, mouse y of the last queued mouse key
};
extern WWKeyboardClass * Keyboard;              // 0x81a7a8

extern int const LoadScreenWidths[3];           // 0x798bfc {640, 800, 1024} (see LdPrgMgr.cpp)
extern int const LoadScreenHeights[3];          // 0x798c08 {480, 600, 768}

// ---- end of local declarations ----


GadgetClass * GadgetClass::StuckOn;             // 0x84e320, gadget that holds the mouse
GadgetClass * GadgetClass::LastList;            // 0x84e324, list processed by the last Input
GadgetClass * GadgetClass::Focused;             // 0x84e328, gadget with the keyboard focus
GadgetClass * GadgetClass::MouseOver;           // 0x84e32c, gadget under the mouse


// 0x4ceba0
int GadgetClass::Get_Color_Scheme()
{
    ColorScheme * scheme = ColorScheme::Find(MessageColorName, 1);
    if (scheme) {
        return scheme->ID;
    }
    return 0;
}


// 0x4cebc0
GadgetClass::GadgetClass(int x, int y, int w, int h, unsigned flags, bool sticky) :
    X(x),
    Y(y),
    Width(w),
    Height(h),
    IsToRepaint(false),
    IsSticky(sticky),
    IsDisabled(false),
    Flags(flags)
{
    if (IsSticky) {
        Flags |= LEFTPRESS | LEFTRELEASE;
    }
}


// 0x4cec10
GadgetClass::GadgetClass(GadgetClass const & gadget) :
    X(gadget.X),
    Y(gadget.Y),
    Width(gadget.Width),
    Height(gadget.Height),
    IsToRepaint(gadget.IsToRepaint),
    IsSticky(gadget.IsSticky),
    IsDisabled(gadget.IsDisabled),
    Flags(gadget.Flags)
{
}


// 0x4cec60
GadgetClass::~GadgetClass()
{
    if (Has_Focus()) {
        Clear_Focus();
    }
    if (this == StuckOn) {
        StuckOn = 0;
    }
    if (this == LastList) {
        LastList = 0;
    }
    if (this == Focused) {
        Focused = 0;
    }
}


// 0x4cecc0
int GadgetClass::Clicked_On(KeyNumType & key, unsigned flags, int mousex, int mousey)
{
    flags &= Flags;
    if (this == StuckOn || (flags & KEYBOARD) ||
        (flags && (unsigned)(mousex - X) < (unsigned)Width && (unsigned)(mousey - Y) < (unsigned)Height)) {
        return Action(flags, key);
    }
    return false;
}


// 0x4ced20
void GadgetClass::Enable()
{
    IsDisabled = false;
    IsToRepaint = true;
    Clear_Focus();
}


// 0x4ced30
void GadgetClass::Disable()
{
    IsDisabled = true;
    IsToRepaint = true;
    Clear_Focus();
}


// 0x4ced40
int GadgetClass::Is_Enabled() const
{
    return !IsDisabled;
}


// 0x4ced50
LinkClass * GadgetClass::Remove()
{
    Clear_Focus();
    return LinkClass::Remove();
}


// 0x4ced70
LinkClass * GadgetClass::Get_Next() const
{
    return LinkClass::Get_Next();
}


// 0x4ced80
LinkClass * GadgetClass::Get_Prev() const
{
    return LinkClass::Get_Prev();
}


// 0x4ced90
void GadgetClass::Delete_List()
{
    GadgetClass * gadget = this;
    while (gadget->Get_Prev()) {
        gadget = (GadgetClass *)gadget->Get_Prev();
    }
    while (gadget) {
        gadget->Clear_Focus();
        GadgetClass * temp = gadget;
        gadget = (GadgetClass *)gadget->Get_Next();
        delete temp;
    }
}


// 0x4cede0
void GadgetClass::Mouse_Enter()
{
}


// 0x4cedf0
void GadgetClass::Mouse_Leave()
{
}


// 0x4cee00
int GadgetClass::Action(unsigned flags, KeyNumType &)
{
    if (flags) {
        IsToRepaint = true;
        Sticky_Process(flags);
        return true;
    }
    return false;
}


// 0x4cee20
int GadgetClass::Draw_Me(int forced)
{
    if (forced || IsToRepaint) {
        IsToRepaint = false;
        return true;
    }
    return false;
}


// 0x4cee40
void GadgetClass::Draw_All(bool forced)
{
    GadgetClass * gadget = this;
    while (gadget) {
        gadget->Draw_Me(forced);
        gadget = (GadgetClass *)gadget->Get_Next();
    }
}


// 0x4cee70
GadgetClass * GadgetClass::Find_Gadget(int x, int y)
{
    RectangleStruct best(0, 0, LoadScreenWidths[2], LoadScreenHeights[2]);
    GadgetClass * found = 0;

    for (GadgetClass * gadget = this; gadget; gadget = (GadgetClass *)gadget->Get_Next()) {
        RectangleStruct rect(gadget->X, gadget->Y, gadget->Width, gadget->Height);
        if (!gadget->IsDisabled && x >= rect.X && x < rect.X + rect.Width && y >= rect.Y && y < rect.Y + rect.Height
            && rect.Width * rect.Height <= best.Width * best.Height) {
            best = rect;
            found = gadget;
        }
    }
    return found;
}


// 0x4cef10
KeyNumType GadgetClass::Input()
{
    int mousex;
    int mousey;
    KeyNumType key;
    unsigned flags;
    GadgetClass * next_button;
    int forced = false;

    if (LastList != this) {
        LastList = this;
        forced = true;
        StuckOn = 0;
        Focused = 0;
    }

    key = (KeyNumType)Keyboard->Check();
    if (key) {
        key = (KeyNumType)Keyboard->Get();
    }

    int ascii = key & 0xFF;
    if (ascii == KN_LMOUSE || ascii == KN_RMOUSE) {
        mousex = Keyboard->MouseQX;
        mousey = Keyboard->MouseQY;
    } else {
        mousex = WWMouse->Get_Mouse_X();
        mousey = WWMouse->Get_Mouse_Y();
    }

    GadgetClass * over = Find_Gadget(mousex, mousey);
    if (over != MouseOver) {
        if (MouseOver) {
            MouseOver->Mouse_Leave();
        }
        MouseOver = over;
        if (over) {
            over->Mouse_Enter();
        }
    }

    if (key != KN_NONE) {
        if (key == KN_LMOUSE) {
            flags = LEFTPRESS;
        } else if (key == KN_RMOUSE) {
            flags = RIGHTPRESS;
        } else if (key == (KN_LMOUSE | KN_RLSE_BIT)) {
            flags = LEFTRELEASE;
        } else {
            flags = (key == (KN_RMOUSE | KN_RLSE_BIT)) ? RIGHTRELEASE : KEYBOARD;
        }
    } else {
        flags = Keyboard->Down(KN_LMOUSE) ? LEFTHELD : LEFTUP;
        if (Keyboard->Down(KN_RMOUSE)) {
            flags |= RIGHTHELD;
        } else {
            flags |= RIGHTUP;
        }
    }

    if (StuckOn) {
        StuckOn->Draw_Me();
        next_button = StuckOn;
        StuckOn->Clicked_On(key, flags, mousex, mousey);
        if (StuckOn) {
            StuckOn->Draw_Me();
        } else {
            next_button->Draw_Me();
        }
    } else if (Focused && (flags & KEYBOARD)) {
        Focused->Draw_Me();
        Focused->Clicked_On(key, flags, mousex, mousey);
        if (Focused) {
            Focused->Draw_Me();
        }
    } else {
        next_button = this;
        while (next_button) {
            next_button->Draw_Me(forced);
            if (!next_button->IsDisabled) {
                if (next_button->Clicked_On(key, flags, mousex, mousey)) {
                    next_button->Draw_Me();
                    break;
                }
            }
            next_button = (GadgetClass *)next_button->Get_Next();
        }
    }
    return key;
}


// 0x4cf140
ControlClass * GadgetClass::Extract_Gadget(unsigned id)
{
    GadgetClass * gadget = this;
    if (id) {
        while (gadget) {
            if (gadget->Get_ID() == id) {
                return (ControlClass *)gadget;
            }
            gadget = (GadgetClass *)gadget->Get_Next();
        }
    }
    return 0;
}


// 0x4cf180
void GadgetClass::Flag_To_Redraw()
{
    IsToRepaint = true;
}


// 0x4cf190
void GadgetClass::Sticky_Process(unsigned flags)
{
    if (IsSticky && (flags & (LEFTPRESS | RIGHTPRESS))) {
        StuckOn = this;
    }
    if (StuckOn == this && (flags & (LEFTRELEASE | RIGHTRELEASE))) {
        StuckOn = 0;
    }
}


// 0x4cf1c0
void GadgetClass::Set_Focus()
{
    if (Focused) {
        Focused->Flag_To_Redraw();
        Focused->Clear_Focus();
    }
    Flags |= KEYBOARD;
    Focused = this;
}


// 0x4cf1f0
void GadgetClass::Clear_Focus()
{
    if (Focused == this) {
        Flags &= ~KEYBOARD;
        Focused = 0;
    }
}


// 0x4cf210
bool GadgetClass::Has_Focus()
{
    return this == Focused;
}


// 0x4cf220
int GadgetClass::Is_List_To_Redraw()
{
    GadgetClass * gadget = this;
    while (gadget) {
        if (gadget->IsToRepaint) {
            return true;
        }
        gadget = (GadgetClass *)gadget->Get_Next();
    }
    return false;
}


// 0x4cf240
void GadgetClass::Set_Position(int x, int y)
{
    X = x;
    Y = y;
}


// 0x4cf260
void GadgetClass::Set_Size(int w, int h)
{
    Width = w;
    Height = h;
}
