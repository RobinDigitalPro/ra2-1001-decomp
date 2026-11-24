// file name inferred from class name; not proven by a C:\RA2 string
// CONTROL.CPP (level-2 reconstruction of GAME.EXE 1.001)
//
// Control gadget: a gadget with an ID that it returns as a button key, and an optional peer
// (RTTI .?AVControlClass@@, vtable 0x788ea4, 34 slots; chain ControlClass : GadgetClass :
// LinkClass). All method, member and variable names except the class names are provisional.
//
// TU span 0x4831f0..0x48336f: the GAMECONST block 0x482f80..0x4831d0 and the 16-byte zeroing
// header initializer 0x4831f0 (.bss 0x839460..0x83946f) open this TU (not reproduced, not
// claimed). Then ctor 0x483210, copy ctor 0x483260, Action 0x483290, Make_Peer 0x4832f0, Get_ID
// 0x483300, Draw_Me 0x483310, the header inline GadgetClass::Peer_To_Peer 0x483340 (COMDAT; this
// is the copy all gadget vtables use) and the scalar deleting destructor 0x483350. The zeroing
// initializer 0x483370 (.bss 0x839470..) starts the next TU.
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

// ---- end of local declarations ----


// 0x483210
ControlClass::ControlClass(unsigned id, int x, int y, int w, int h, unsigned flags, bool sticky) :
    GadgetClass(x, y, w, h, flags, sticky),
    ID(id),
    Peer(0)
{
}


// 0x483260
ControlClass::ControlClass(ControlClass const & control) :
    GadgetClass(control),
    ID(control.ID),
    Peer(control.Peer)
{
}


// 0x483290
int ControlClass::Action(unsigned flags, KeyNumType & key)
{
    if (flags) {
        if (ID) {
            key = (KeyNumType)(ID | KN_BUTTON);
            if ((flags & RIGHTRELEASE) && (Flags & RIGHTPRESS)) {
                key = (KeyNumType)(key | KN_RIGHT_BUTTON);
            }
        } else {
            key = KN_NONE;
        }
    }

    if (Peer) {
        Peer->Peer_To_Peer(flags, key, *this);
    }
    return GadgetClass::Action(flags, key);
}


// 0x4832f0
void ControlClass::Make_Peer(GadgetClass & gadget)
{
    Peer = &gadget;
}


// 0x483300
unsigned ControlClass::Get_ID() const
{
    return ID;
}


// 0x483310
int ControlClass::Draw_Me(int forced)
{
    if (Peer) {
        Peer->Draw_Me();
    }
    return GadgetClass::Draw_Me(forced);
}
