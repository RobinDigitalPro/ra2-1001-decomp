// file name inferred from class name; not proven by a C:\RA2 string
// TXTBUTTN.CPP (level-2 reconstruction of GAME.EXE 1.001)
//
// Text button: a toggle button that draws a box and a centred text (RTTI
// .?AVTextButtonClass@@, vtable 0x79860c, 38 slots; chain TextButtonClass : ToggleClass :
// ControlClass : GadgetClass : LinkClass). All method, member and variable names except the
// class names are provisional.
//
// TU span 0x6dc4e0..0x6dc80b: 0x6dc4e0 is the 16-byte zeroing header initializer (.bss
// 0xaa8350..0xaa835f; not reproduced, not claimed), then the TextButtonClass methods
// 0x6dc500..0x6dc7e7 and its scalar deleting destructor 0x6dc7f0. The TU before ends with the
// VectorClass/DynamicVectorClass<TEventClass *> instances (0x6dc300..0x6dc4d0); the GAMECONST
// block 0x6dc810 starts the next TU.
#include "RECT.H"
#include "SURFACE.H"
#include "VECTOR.H"


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

// Shape palette converter (layout not reconstructed; only the fields used here, see GAUGE.CPP).
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

// RTTI .?AVColorScheme@@; only the field used here.
class ColorScheme {
public:
    char Unknown0[0x30c];
    ConvertClass * Converter;                   // +0x30c (see Beacon.CPP)
};
extern DynamicVectorClass<ColorScheme *> ColorSchemes;   // 0xa9ea00

// RTTI .?AVBitFont@@ (vtable 0x787788); only what is used here.
class BitFont {
public:
    virtual ~BitFont();
    int String_Pixel_Width(wchar_t const * text, int max_width);   // 0x431550
    char Unknown4[0x1c - 0x04];
    int Height;                                 // +0x1c (name provisional)
};
BitFont * Font_Ptr(int flags);                  // 0x497830 (see Dropship.cpp)

extern Surface * LogicalSurface;                   // 0x821c9c (provisional)

void Draw_Box(RectangleStruct const & rect, int style, bool filled);  // 0x4971b0 (name provisional)

enum {
    BOXSTYLE_DOWN = 0,                          // style values from the calls here (names provisional)
    BOXSTYLE_RAISED = 1,
    BOXSTYLE_DISABLED = 3
};

// Text printer (0x497770, __fastcall, ret 0x1c; result through a hidden pointer). Name and the
// meaning of the last argument provisional.
Point2D Simple_Text_Print(wchar_t const * text, Surface * surface, RectangleStruct const & rect,
    Point2D const & xy, ColorScheme * fore, unsigned back, int flags, int unknown = 1);

// Text print flags used here (names provisional).
enum {
    TPF_CENTER = 0x0100,
    TPF_BUTTON = 0x5000,
    TPF_BUTTON_PRESSED = 0x6000
};

// RTTI .?AVTextButtonClass@@ (vtable 0x79860c, 38 slots, 0x40 bytes). No explicit destructor.
class TextButtonClass : public ToggleClass {
public:
    TextButtonClass();                          // 0x6dc590
    TextButtonClass(unsigned id, wchar_t const * text, int style, int x, int y, int w = -1, int h = -1,
        bool blackborder = false, bool nobackground = false);  // 0x6dc500
    virtual int Draw_Me(int forced = false);    // slot 27 (0x6dc5c0)
    virtual void Set_Text(wchar_t const * text, bool resize = false);  // slot 34 (0x6dc600)
    virtual void Set_Style(int style);          // slot 35 (0x6dc7e0)
    virtual void Draw_Background();             // slot 36 (+0x90, 0x6dc650)
    virtual void Draw_Text(wchar_t const * text);  // slot 37 (+0x94, 0x6dc720)

    bool IsBlackBorder;                         // +0x34
    bool HasNoBackground;                       // +0x35
    wchar_t const * Text;                       // +0x38
    int PrintFlags;                             // +0x3c
};

// ---- end of local declarations ----


// 0x6dc500
TextButtonClass::TextButtonClass(unsigned id, wchar_t const * text, int style, int x, int y, int w, int h,
        bool blackborder, bool nobackground) :
    ToggleClass(id, x, y, w, h),
    IsBlackBorder(blackborder),
    HasNoBackground(nobackground),
    Text(text),
    PrintFlags(style)
{
    if (w == -1 || h == -1) {
        BitFont * font = Font_Ptr(PrintFlags);
        if (w == -1) {
            Width = font->String_Pixel_Width(Text, 0) + 8;
        }
        if (h == -1) {
            Height = font->Height + 2;
        }
    }
}


// 0x6dc590
TextButtonClass::TextButtonClass() :
    ToggleClass(0, 0, 0, 0, 0)
{
    IsBlackBorder = false;
    Text = 0;
    PrintFlags = 2;
}


// 0x6dc5c0
int TextButtonClass::Draw_Me(int forced)
{
    if (ToggleClass::Draw_Me(forced)) {
        Draw_Background();
        Draw_Text(Text);
        return true;
    }
    return false;
}


// 0x6dc600
void TextButtonClass::Set_Text(wchar_t const * text, bool resize)
{
    Text = text;
    Flag_To_Redraw();
    if (resize && Text) {
        BitFont * font = Font_Ptr(PrintFlags);
        Width = font->String_Pixel_Width(Text, 0) + 8;
        Height = font->Height + 2;
    }
}


// 0x6dc650
void TextButtonClass::Draw_Background()
{
    if (!HasNoBackground) {
        if (IsBlackBorder) {
            LogicalSurface->Draw_Rect(RectangleStruct(X - 1, Y - 1, X + Width + 2, Y + Height + 2),
                ColorSchemes[Get_Color_Scheme()]->Converter->Get_Color(12));
        }

        int style;
        if (IsDisabled) {
            style = BOXSTYLE_DISABLED;
        } else {
            style = IsPressed ? BOXSTYLE_DOWN : BOXSTYLE_RAISED;
        }
        Draw_Box(RectangleStruct(X, Y, Width, Height), style, true);
    }
}


// 0x6dc720
void TextButtonClass::Draw_Text(wchar_t const * text)
{
    int scheme = Get_Color_Scheme();
    if (Text) {
        int flags;
        if (IsDisabled) {
            flags = 0;
        } else if (IsPressed || IsOn) {
            flags = TPF_BUTTON_PRESSED;
        } else {
            flags = TPF_BUTTON;
        }

        if (ColorSchemes.Count()) {
            if (scheme <= 0 || scheme >= ColorSchemes.Count()) {
                scheme = 0;
            }
            ColorScheme * fore = ColorSchemes[scheme];
            if (fore) {
                Simple_Text_Print(text, LogicalSurface, LogicalSurface->Get_Rect(),
                    Point2D(X + (Width >> 1) - 1, Y + 1), fore, 0, PrintFlags | flags | TPF_CENTER);
            }
        }
    }
}


// 0x6dc7e0
void TextButtonClass::Set_Style(int style)
{
    PrintFlags = style;
}
