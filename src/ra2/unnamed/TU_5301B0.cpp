// unidentified translation unit (GAMECONST.H initializers at 0x1301b0) (level-2 reconstruction of GAME.EXE 1.001)
// Keyboard input object: a 256-entry circular key buffer filled from the window messages.
// The class has no vtable/RTTI; WWKeyboardClass and all member names are provisional
// (Westwood library style, matching the declarations used in Restate.cpp, UICmnds.cpp, WDTSel.cpp).
#include "../RECT.H"
static RectangleStruct const ZeroRectA(0, 0, 0, 0);
#include "../GAMECONST.H"
#include <windows.h>
#include <string.h>
#include <stdlib.h>

// ---- local declarations (to be moved to headers by the integrator) ----

void Windows_Message_Handler();                               // 0x5b29f0 (provisional): pumps the window messages
void Key_Message_Hook(int key, bool release);              // 0x5228e0 (provisional)
short Get_Key_State(int vk);                    // 0x522910 (provisional; GetKeyState wrapper)
short Get_Async_Key_State(int key);      // 0x522930 (provisional)

extern bool Flag_A28984;                        // 0xa28984, set while the briefing is shown; meaning unknown
extern bool Flag_A25FB9;                        // 0xa25fb9, enables WM_CHAR text input (meaning provisional)

// Mouse object (0x821fa8); only the virtual slot used here is named.
class WWMouseClass {
public:
    virtual ~WWMouseClass();
    virtual void Virtual_01();
    virtual void Virtual_02();
    virtual void Hide_Mouse();                  // +0x0c
    virtual void Show_Mouse();                  // +0x10
    virtual void Virtual_05();
    virtual void Virtual_06();
    virtual void Virtual_07();
    virtual void Virtual_08();
    virtual void Virtual_09();
    virtual int Get_Mouse_State();              // +0x28
    virtual int Get_Mouse_X();                  // +0x2c
    virtual int Get_Mouse_Y();                  // +0x30
    virtual void Virtual_0D();
    virtual void Virtual_0E();
    virtual void Virtual_0F();
    virtual void Virtual_10();
    virtual void Convert_Coordinate(int & x, int & y);   // +0x44 (name provisional)
};
extern WWMouseClass * WWMouse;                  // 0x821fa8

enum {
    KN_LMOUSE = 0x01,
    KN_RMOUSE = 0x02,
    KN_MMOUSE = 0x04,
    KN_CHAR = 0x0a,                             // followed by the character in the buffer
    KN_SHIFT_BIT = 0x100,
    KN_CTRL_BIT = 0x200,
    KN_ALT_BIT = 0x400,
    KN_RLSE_BIT = 0x800
};

class WWKeyboardClass {
public:
    WWKeyboardClass();
    unsigned short Buff_Get();
    static bool Is_Mouse_Key(unsigned short key);
    static bool Is_Char_Key(unsigned char key);
    unsigned short Check();
    unsigned short Get();
    bool Put(unsigned short key);
    bool Put_Key_Message(unsigned short vk_key, bool release);
    bool Put_Mouse_Message(unsigned short vk_key, int x, int y, bool release);
    bool Put_Char_Message(char character);
    char To_ASCII(unsigned short key);
    char To_Char(unsigned short key);
    bool Down(unsigned short key);
    unsigned short Fetch_Element();
    unsigned short Peek_Element();
    bool Put_Element(unsigned short val);
    bool Is_Buffer_Full() const;
    bool Is_Buffer_Empty() const;
    void Fill_Buffer_From_System();
    void Clear();
    bool Message_Handler(HWND window, UINT message, UINT wParam, LONG lParam);
    int Available_Buffer_Room();

    int MouseQX;                                // +0x00
    int MouseQY;                                // +0x04
    unsigned short Char;                        // +0x08, character of the last KN_CHAR entry
    int MouseX;                                 // +0x0c
    int MouseY;                                 // +0x10
    unsigned char KeyState[256];                // +0x14
    unsigned short Buffer[256];                 // +0x114
    int Head;                                   // +0x314
    int Tail;                                   // +0x318
};

// ---- end of local declarations ----



unsigned short WWKeyboardClass::Buff_Get()
{
    while (!Check()) {}
    unsigned short temp = Fetch_Element();
    if (Is_Mouse_Key(temp)) {
        MouseQX = Fetch_Element();
        MouseQY = Fetch_Element();
        MouseX = MouseQX;
        MouseY = MouseQY;
    } else if (Is_Char_Key(temp)) {
        Char = Fetch_Element();
    }
    return temp;
}

bool WWKeyboardClass::Is_Mouse_Key(unsigned short key)
{
    key = key & 0xff;
    return key == KN_LMOUSE || key == KN_MMOUSE || key == KN_RMOUSE;
}

bool WWKeyboardClass::Is_Char_Key(unsigned char key)
{
    return key == KN_CHAR;
}

unsigned short WWKeyboardClass::Check()
{
    Fill_Buffer_From_System();
    if (Is_Buffer_Empty()) return 0;
    return Peek_Element();
}



bool WWKeyboardClass::Put(unsigned short key)
{
    return Put_Element(key);
}

#pragma auto_inline(off)
bool WWKeyboardClass::Put_Key_Message(unsigned short vk_key, bool release)
{
    if (Flag_A28984 && vk_key != VK_ESCAPE) {
        return true;
    }
    Key_Message_Hook(vk_key, release);
    if (!Is_Mouse_Key(vk_key) && (vk_key & 0xff) != KN_CHAR) {
        if (Get_Key_State(VK_SHIFT) & 0x8000) vk_key |= KN_SHIFT_BIT;
        if (Get_Key_State(VK_CONTROL) & 0x8000) vk_key |= KN_CTRL_BIT;
        if (Get_Key_State(VK_MENU) & 0x8000) {
            if (vk_key == VK_TAB) return true;
            vk_key |= KN_ALT_BIT;
        }
    }
    if (release) {
        vk_key |= KN_RLSE_BIT;
    }
    return Put(vk_key);
}

#pragma auto_inline(on)

bool WWKeyboardClass::Put_Mouse_Message(unsigned short vk_key, int x, int y, bool release)
{
    if (Flag_A28984) return true;
    if (Available_Buffer_Room() >= 3 && Is_Mouse_Key(vk_key)) {
        Put_Key_Message(vk_key, release);
        Put(x);
        Put(y);
        return true;
    }
    return false;
}

bool WWKeyboardClass::Put_Char_Message(char character)
{
    if (Flag_A28984) return true;
    if (Available_Buffer_Room() >= 2) {
        Put_Key_Message(KN_CHAR, false);
        Put(character & 0xff);
        return true;
    }
    return false;
}

char WWKeyboardClass::To_ASCII(unsigned short key)
{
    if (key & KN_RLSE_BIT) return 0;
    if ((key & 0xff) == VK_HOME) return 8;
    if ((key & 0xff) == VK_END) return '\\';

    char buffer[10];
    unsigned short shift = key & KN_SHIFT_BIT;
    if (shift) KeyState[VK_SHIFT] = 0x80;
    unsigned short ctrl = key & KN_CTRL_BIT;
    if (ctrl) KeyState[VK_CONTROL] = 0x80;
    unsigned short alt = key & KN_ALT_BIT;
    if (alt) KeyState[VK_MENU] = 0x80;

    unsigned scancode = MapVirtualKeyA(key, 0);
    int result = ToAscii(key, scancode, KeyState, (LPWORD)buffer, 0);

    if (shift) KeyState[VK_SHIFT] = 0;
    if (ctrl) KeyState[VK_CONTROL] = 0;
    if (alt) KeyState[VK_MENU] = 0;

    return (result == 1) ? buffer[0] : (char)0;
}



bool WWKeyboardClass::Down(unsigned short key)
{
    key = key & 0xff;
    if (key == KN_LMOUSE || key == KN_RMOUSE) {
        if (GetSystemMetrics(SM_SWAPBUTTON) == 1) {
            key = (key == KN_LMOUSE) ? KN_RMOUSE : KN_LMOUSE;
        }
    }
    return Get_Async_Key_State(key) != 0;
}

unsigned short WWKeyboardClass::Fetch_Element()
{
    unsigned short val = 0;
    if (Head != Tail) {
        val = Buffer[Head];
        Head = (Head + 1) % 256;
    }
    return val;
}

unsigned short WWKeyboardClass::Peek_Element()
{
    if (!Is_Buffer_Empty()) {
        return Buffer[Head];
    }
    return 0;
}

bool WWKeyboardClass::Put_Element(unsigned short val)
{
    int next = (Tail + 1) % 256;
    if (next != Head) {
        Buffer[Tail] = val;
        Tail = next;
        return true;
    }
    return false;
}

bool WWKeyboardClass::Is_Buffer_Full() const
{
    if ((Tail + 1) % 256 == Head) return true;
    return false;
}

bool WWKeyboardClass::Is_Buffer_Empty() const
{
    if (Head == Tail) return true;
    return false;
}

void WWKeyboardClass::Fill_Buffer_From_System()
{
    if (!Is_Buffer_Full()) {
        Windows_Message_Handler();
    }
}

void WWKeyboardClass::Clear()
{
    Fill_Buffer_From_System();
    Head = Tail;
    Fill_Buffer_From_System();
    Head = Tail;
}

bool WWKeyboardClass::Message_Handler(HWND window, UINT message, UINT wParam, LONG lParam)
{
    POINT point;
    point.x = LOWORD(lParam);
    point.y = HIWORD(lParam);
    ClientToScreen(window, &point);
    int x = point.x;
    int y = point.y;
    if (WWMouse) {
        WWMouse->Convert_Coordinate(x, y);
    }

    switch (message) {
        case WM_SYSKEYDOWN:
        case WM_KEYDOWN:
            if (wParam == VK_SCROLL) break;
            if (lParam & 0x40000000) break;
            Put_Key_Message(wParam, false);
            break;

        case WM_SYSKEYUP:
        case WM_KEYUP:
            Put_Key_Message(wParam, true);
            break;

        case WM_CHAR:
            if (Flag_A25FB9) {
                Put_Char_Message(wParam);
            }
            break;

        case WM_LBUTTONDOWN:
            Put_Mouse_Message(KN_LMOUSE, x, y, false);
            break;

        case WM_LBUTTONUP:
            Put_Mouse_Message(KN_LMOUSE, x, y, true);
            break;

        case WM_LBUTTONDBLCLK:
            Put_Mouse_Message(KN_LMOUSE, x, y, false);
            Put_Mouse_Message(KN_LMOUSE, x, y, true);
            break;

        case WM_MBUTTONDOWN:
            Put_Mouse_Message(KN_MMOUSE, x, y, false);
            break;

        case WM_MBUTTONUP:
            Put_Mouse_Message(KN_MMOUSE, x, y, true);
            break;

        case WM_MBUTTONDBLCLK:
            Put_Mouse_Message(KN_MMOUSE, x, y, false);
            Put_Mouse_Message(KN_MMOUSE, x, y, true);
            break;

        case WM_RBUTTONDOWN:
            Put_Mouse_Message(KN_RMOUSE, x, y, false);
            break;

        case WM_RBUTTONUP:
            Put_Mouse_Message(KN_RMOUSE, x, y, true);
            break;

        case WM_RBUTTONDBLCLK:
            Put_Mouse_Message(KN_RMOUSE, x, y, false);
            Put_Mouse_Message(KN_RMOUSE, x, y, true);
            break;

        default:
            return false;
    }
    DefWindowProcA(window, message, wParam, lParam);
    return true;
}

int WWKeyboardClass::Available_Buffer_Room()
{
    return 256 - abs(Tail - Head);
}
