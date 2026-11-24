// C:\RA2\Power.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Contents: the sidebar power bar (PowerClass). Class names come from RTTI (.?AVPowerClass@@ vtable
// 0x7932ec and its bases RadarClass, DisplayClass, MapClass, GScreenClass, IGameMap); all method,
// member and variable names are provisional unless a debug string names them.
#include "GAMECONST.H"
#include <wchar.h>
#include "ABSTRACT.H"
#include "RECT.H"
#include "SURFACE.H"
#include "VECTOR.H"

// ---- local declarations (to be moved to headers by the integrator) ----

wchar_t const * Fetch_String(char const * label, char ** extra, char const * file, int line);  // 0x6eeb60

#include "POINT.H"

// Timer source returning timeGetTime() >> 4 (0x68fad0); see MPScore.cpp.
class SystemTimerClass {
public:
    long operator()() const;                // 0x68fad0
};

// Count-down timer (three dwords: start, timer source, delay). Started == -1 means stopped.
// The assignment from a long goes through a temporary and the implicit copy (GAME.EXE copies
// the uninitialised timer-source dword as well).
template<class T>
class CDTimerClass {
public:
    CDTimerClass(long set = 0) : Started(Timer()), DelayTime(set) {}
    operator long() const
    {
        long remain = DelayTime;
        if (Started != -1) {
            long elapsed = Timer() - Started;
            if (elapsed < remain) {
                remain -= elapsed;
            } else {
                remain = 0;
            }
        }
        return remain;
    }

    long Started;
    T Timer;
    long DelayTime;
};

// Shape drawing (0x49ebd0): __fastcall, 13 stack dwords (ret 0x34). Names and the types of the
// trailing arguments are provisional; passing the last two as a by-value Point2D reproduces the
// register-zero pushes of every call in this TU (literal int zeros give push 0).
class ConvertClass;
void CC_Draw_Shape(Surface * surface, ConvertClass * convert, void const * shape, int frame,
    Point2D const * point, RectangleStruct const * window, int flags, int arg8, int arg9, int arg10,
    int arg11, int arg12, int arg13, Point2D offset);

// Mix file / disk file loader (0x495050): returns the data and sets allocated when it was read
// from disk into a new buffer. Name provisional.
void * Load_File_Data(char const * filename, bool & allocated);

// Tool tips (RTTI .?AVToolTipManager@@, .?AVCCToolTip@@); only the two methods used here.
struct ToolTip {
    ToolTip() : Rect(0, 0, 0, 0) { Flag = false; Text = NULL; }
    int ID;                     // +0x00
    RectangleStruct Rect;       // +0x04
    wchar_t const * Text;       // +0x14 (meaning provisional)
    bool Flag;                  // +0x18 (meaning unknown)
};
class ToolTipManager {
public:
    bool Add(ToolTip const & tip);          // 0x6e0b20
    void Remove(int id);                    // 0x6e0cd0
};
extern ToolTipManager * ToolTipHandler;    // 0x821cf0

// Only the field used here; layout not reconstructed (see MPScore.cpp).
class ScenarioClass {
public:
    char Unknown0[0x2239];
    bool Field2239;                         // +0x2239, meaning unknown (shifts the sidebar by 5 pixels)
};
extern ScenarioClass * Scen;                // 0xa255c0

// RTTI .?AVBuildingTypeClass@@; only the two fields read here (meanings provisional).
class BuildingTypeClass {
public:
    char Unknown0[0xc68];
    int PowerBonus;                         // +0xc68
    int PowerDrain;                         // +0xc6c
};
class BuildingClass {
public:
    char Unknown0[0x418];
    BuildingTypeClass * Class;              // +0x418
};

// RTTI interface .?AUIHouse@@ at HouseClass+0x24 (15 slots).
struct __declspec(novtable) IHouse : IUnknown {
    virtual int __stdcall Virtual_03() = 0;
    virtual int __stdcall Virtual_04() = 0;
    virtual int __stdcall Virtual_05() = 0;
    virtual int __stdcall Virtual_06() = 0;
    virtual int __stdcall Virtual_07() = 0;
    virtual int __stdcall Power_Output() = 0;   // slot 8: HouseClass 0x4e2230 returns +0x52d0
    virtual int __stdcall Power_Drain() = 0;    // slot 9: HouseClass 0x4e2240 returns +0x52d4
};

// RTTI .?AVHouseClass@@ : AbstractClass, IHouse (+0x24), IPublicHouse (+0x28), IConnectionPointContainer (+0x2c).
class HouseClass : public AbstractClass, public IHouse {
public:
    virtual int __stdcall Power_Output();
    virtual int __stdcall Power_Drain();

    char Unknown28[0x68 - 0x28];
    DynamicVectorClass<BuildingClass *> Buildings;  // +0x68
    char Unknown80[0x52d0 - 0x80];
    int PowerOutput;                        // +0x52d0
    int PowerDrain;                         // +0x52d4
};
extern HouseClass * PlayerPtr;              // 0xa1e0e4

extern Surface * SidebarSurface;            // 0x821c88
extern ConvertClass * SidebarDrawer;        // 0x81a70c
extern RectangleStruct SidebarRect;         // 0x821960 (X and Y used here)
extern int PowerBarHeight;                  // 0xaa4878, power bar height in pixels (3 per segment)
extern bool Flag_AA488C;                    // 0xaa488c, set when the power bar was drawn; meaning unknown

// RTTI .?AUIGameMap@@ (COM interface, slot 3 implemented by MapClass 0x545430).
struct __declspec(novtable) IGameMap : IUnknown {
    virtual HRESULT __stdcall Virtual_03(int arg) = 0;
};

// RTTI .?AVGScreenClass@@, vtable 0x78dc3c (22 slots). Names follow the Westwood screen classes
// where the slot is evidenced (debug strings or use); the rest are placeholders.
class GScreenClass : public IGameMap {
public:
    virtual HRESULT __stdcall QueryInterface(REFIID riid, void ** ppv);    // 0x4dff80
    virtual ULONG __stdcall AddRef();                                       // 0x40d100
    virtual ULONG __stdcall Release();                                      // 0x40d110
    virtual ~GScreenClass();                                                // slot 4
    virtual void One_Time();                                                // slot 5
    virtual void Virtual_06(int arg);                                       // slot 6: 0x4dfff0
    virtual void Init_Clear();                                              // slot 7
    virtual void Virtual_08();                                              // slot 8
    virtual void Virtual_09(int arg1, int arg2, int arg3);                  // slot 9: 0x4e0060
    virtual void AI(int & input, Point2D const & xy);                       // slot 10
    virtual void Virtual_11(int arg);                                       // slot 11: 0x4e0130
    virtual void Virtual_12(int arg);                                       // slot 12: 0x4e0150
    virtual void Virtual_13(int arg);                                       // slot 13: 0x4e0190
    virtual void Flag_To_Redraw(int complete);                              // slot 14: 0x4e0030
    virtual void Virtual_15();                                              // slot 15: 0x4e01c0
    virtual void Draw_It(bool complete);                                    // slot 16
    virtual void Virtual_17();                                              // slot 17: 0x4e02e0
    virtual void Virtual_18() = 0;
    virtual void Virtual_19() = 0;
    virtual void Virtual_20() = 0;
    virtual void Virtual_21() = 0;
};

// RTTI .?AVMapClass@@, vtable 0x79091c (30 slots).
class MapClass : public GScreenClass {
public:
    virtual HRESULT __stdcall Virtual_03(int arg);                          // 0x545430
    virtual void Virtual_22();                                              // 0x545800
    virtual void Virtual_23();                                              // 0x545860
    virtual void Virtual_24();                                              // 0x545920
    virtual void Virtual_25(int arg1, int arg2);                            // 0x556b70
    virtual void Virtual_26();                                              // 0x49ea40
    virtual void Virtual_27();                                              // 0x54b790
    virtual void Virtual_28(int arg1, int arg2, int arg3, int arg4);
    virtual void Virtual_29(int arg);
};

// RTTI .?AVDisplayClass@@, vtable 0x78991c (50 slots).
class DisplayClass : public MapClass {
public:
    virtual void Virtual_30(int arg);
    virtual void Virtual_31(int arg);
    virtual void Virtual_32(int arg);                                       // 0x49cd70
    virtual wchar_t const * Help_Text(int gadget_id);                       // slot 33
    virtual void Set_Tool_Tips();                                           // slot 34
    virtual void Virtual_35();                                              // 0x49e920
    virtual void Virtual_36(int arg1, int arg2);
    virtual void Virtual_37(int arg1, int arg2, int arg3);
    virtual void Virtual_38(int arg1, int arg2);                            // 0x499ed0
    virtual void Virtual_39(int arg1, int arg2);                            // 0x49a150
    virtual void Virtual_40() = 0;
    virtual void Virtual_41(int arg1, int arg2, int arg3);                  // 0x499940
    virtual void Virtual_42(int arg);                                       // 0x498a60
    virtual void Virtual_43(int arg);                                       // 0x40d120
    virtual void Virtual_44(int arg);                                       // 0x49ad60
    virtual void Virtual_45(int arg);                                       // 0x49c240
    virtual void Virtual_46(int arg1, int arg2, int arg3, int arg4, int arg5);  // 0x49aed0
    virtual void Virtual_47(int arg);                                       // 0x49c2b0
    virtual void Virtual_48(int arg1, int arg2, int arg3, int arg4, int arg5);  // 0x49b900
    virtual void Virtual_49(int arg);                                       // 0x49ad70
};

// RTTI .?AVRadarClass@@, vtable 0x7936dc (54 slots). Only the overrides that PowerClass inherits or
// calls are declared. Layout before PowerClass (+0x1508) not reconstructed.
class RadarClass : public DisplayClass {
public:
    RadarClass();                                                           // 0x626470
    virtual ~RadarClass();                                                  // 0x626710
    virtual void One_Time();                                                // 0x626800 ("RadarClass::One_Time()")
    virtual void Init_Clear();                                              // 0x6268f0 ("RadarClass::Init_Clear()")
    virtual void Virtual_08();                                              // 0x626b20
    virtual void AI(int & input, Point2D const & xy);                       // 0x627350
    virtual void Draw_It(bool complete);                                    // 0x626c10
    virtual void Virtual_28(int arg1, int arg2, int arg3, int arg4);        // 0x627980
    virtual void Virtual_29(int arg);                                       // 0x627ec0
    virtual void Virtual_30(int arg);                                       // 0x62a270
    virtual void Virtual_31(int arg);                                       // 0x62a490
    virtual wchar_t const * Help_Text(int gadget_id);                       // 0x62c040
    virtual void Set_Tool_Tips();                                           // 0x627d50
    virtual void Virtual_36(int arg1, int arg2);                            // 0x627310
    virtual void Virtual_37(int arg1, int arg2, int arg3);                  // 0x627330
    virtual void Free_Shapes();                                             // slot 50: 0x6268a0
    virtual void Virtual_51(int arg1, int arg2);                            // 0x627260
    virtual void Virtual_52(int arg);                                       // 0x6279a0
    virtual void Init_For_House();                                          // slot 53: 0x6269a0 ("RadarClass::Init_For_House()")

    char RadarData[0x1508 - 4];
};

// RTTI .?AVPowerClass@@, vtable 0x7932ec. Size 0x1540.
class PowerClass : public RadarClass {
public:
    PowerClass();
    virtual void One_Time();
    virtual void Init_Clear();
    virtual void AI(int & input, Point2D const & xy);
    virtual void Draw_It(bool complete);
    virtual wchar_t const * Help_Text(int gadget_id);
    virtual void Set_Tool_Tips();
    virtual void Free_Shapes();
    virtual void Init_For_House();

    void Flash_Power();
    int Segment_Count();
    int Usable_Segments();
    int Animation_Delay();
    int Desired_Segments(int & high, int & low, int & drain);
    void Shrink_Segment();
    void Grow_Segment();

    bool IsToRedraw;                            // +0x1508
    CDTimerClass<SystemTimerClass> FlashTimer;  // +0x150c
    int FlashCount;                             // +0x1518
    CDTimerClass<SystemTimerClass> AnimTimer;   // +0x151c
    int HighSegments;                           // +0x1528, drawn with frame 1 (power above 100 surplus)
    int LowSegments;                            // +0x152c, frame 2 (surplus up to 100)
    int DrainSegments;                          // +0x1530, frame 3
    bool IsAnimating;                           // +0x1534
    int RecordedDrain;                          // +0x1538
    int RecordedOutput;                         // +0x153c

    static void const * PowerShape;             // 0xa5e474
    static bool PowerShapeAllocated;            // 0xa5e478
};

// RTTI .?AVSidebarClass@@ : PowerClass. TabClass and ScrollClass (between SidebarClass and
// MouseClass) are omitted here; only the two fields used.
class SidebarClass : public PowerClass {
public:
    char SidebarData[0x4ee1 - 0x1540];
    bool IsSidebarActive;                       // +0x4ee1
    bool IsToRedraw;                            // +0x4ee2
};

// RTTI .?AVMouseClass@@ (vtable 0x785954); overrides of the pure slots only.
class MouseClass : public SidebarClass {
public:
    virtual void Virtual_18();                  // 0x59be50
    virtual void Virtual_19();                  // 0x59c040
    virtual void Virtual_20();                  // 0x59be70
    virtual void Virtual_21();                  // 0x59be80
    virtual void Virtual_40();                  // 0x40d150
};
extern MouseClass Map;                          // 0x81a820

// ---- end of local declarations ----

#define POWER_GADGET_ID     999

void const * PowerClass::PowerShape;
bool PowerClass::PowerShapeAllocated;

static wchar_t HelpBuffer[128];                 // 0xa5e338

PowerClass::PowerClass() :
    IsToRedraw(false),
    FlashCount(0),
    HighSegments(0),
    LowSegments(0),
    DrainSegments(0),
    IsAnimating(false),
    RecordedDrain(-1),
    RecordedOutput(-1)
{
}

void PowerClass::Init_Clear()
{
    RadarClass::Init_Clear();
    RecordedDrain = -1;
    RecordedOutput = -1;
    FlashTimer = 0;
    FlashCount = 0;
    AnimTimer = 0;
    HighSegments = 0;
    LowSegments = 0;
    DrainSegments = 0;
    IsAnimating = false;
}

void PowerClass::One_Time()
{
    RadarClass::One_Time();
}

void PowerClass::Init_For_House()
{
    RadarClass::Init_For_House();
    PowerShape = Load_File_Data("POWERP.SHP", PowerShapeAllocated);
}

void PowerClass::Free_Shapes()
{
    RadarClass::Free_Shapes();
    if (PowerShapeAllocated) {
        operator delete((void *)PowerShape);
        PowerShapeAllocated = false;
    }
}

void PowerClass::Flash_Power()
{
    FlashCount = 10;
    FlashTimer = 3;
}

int PowerClass::Usable_Segments()
{
    int segments = Segment_Count();
    int drain = 0;
    int bonus = 0;
    for (int i = 0; i < PlayerPtr->Buildings.ActiveCount; i++) {
        BuildingClass * building = PlayerPtr->Buildings[i];
        drain += building->Class->PowerDrain;
        bonus += building->Class->PowerBonus;
    }
    int total = bonus + drain;
    double ratio = 400.0 / (total + 400.0);
    int unused = (int)(ratio * segments);
    unused = (unused > 0) ? unused : 0;
    unused = (unused < segments - 1) ? unused : segments - 1;
    int usable = segments - unused;
    return usable;
}

int PowerClass::Animation_Delay()
{
    int usable = Usable_Segments();
    int used = DrainSegments + LowSegments + HighSegments;
    if (used > usable) used = usable;
    return (int)((double)used / usable * 5.0);
}

int PowerClass::Segment_Count()
{
    return (PowerBarHeight + 3) / 3;
}

int PowerClass::Desired_Segments(int & high, int & low, int & drain)
{
    int segments = Segment_Count();
    int usable = Usable_Segments();

    double surplus = PlayerPtr->Power_Output() - PlayerPtr->Power_Drain();
    double highpower;
    double lowpower = 100.0;
    if (surplus < 0.0) {
        lowpower = 0.0;
        highpower = 0.0;
    } else {
        if (surplus < 100.0) {
            lowpower = surplus;
        }
        highpower = surplus - lowpower;
    }

    double drainfrac = 1.0;
    double highfrac = 0.0;
    double lowfrac = 0.0;
    double total = highpower + (lowpower + PlayerPtr->Power_Drain());
    if (total > 0.0) {
        drainfrac = PlayerPtr->Power_Drain() / total;
        highfrac = highpower / total;
        lowfrac = lowpower / total;
    }

    double drainval = usable * drainfrac;
    drain = (int)drainval;
    double lowval = usable * lowfrac;
    low = (int)lowval;
    double highval = usable * highfrac;
    high = (int)highval;
    drain = (int)((lowval - low) + (highval - high) + (drainval - drain) + drain + 0.01);
    return segments;
}



void PowerClass::Shrink_Segment()
{
    int high, low, drain;
    Desired_Segments(high, low, drain);
    if (HighSegments > high) {
        HighSegments--;
    } else if (DrainSegments > drain) {
        DrainSegments--;
    } else if (LowSegments > low) {
        LowSegments--;
    }
}

void PowerClass::Grow_Segment()
{
    int high, low, drain;
    Desired_Segments(high, low, drain);
    if (DrainSegments < drain) {
        DrainSegments++;
    } else if (HighSegments < high) {
        HighSegments++;
    } else if (LowSegments < low) {
        LowSegments++;
    }
}

void PowerClass::AI(int & input, Point2D const & xy)
{
    if (Map.IsSidebarActive) {
        if (!IsAnimating && FlashCount > 0 && FlashTimer == 0) {
            IsToRedraw = true;
            FlashCount--;
            Map.IsToRedraw = true;
            Map.Flag_To_Redraw(false);
            FlashTimer = 3;
        }

        if (PlayerPtr->Power_Drain() != RecordedDrain || PlayerPtr->Power_Output() != RecordedOutput || IsAnimating) {
            IsToRedraw = true;
            Map.IsToRedraw = true;
            Map.Flag_To_Redraw(false);

            if (PlayerPtr->Power_Drain() != RecordedDrain || PlayerPtr->Power_Output() != RecordedOutput) {
                IsAnimating = true;
                Flash_Power();
            }
            RecordedDrain = PlayerPtr->Power_Drain();
            RecordedOutput = PlayerPtr->Power_Output();

            int high, low, drain;
            Desired_Segments(high, low, drain);

            if (AnimTimer == 0) {
                IsAnimating = false;
                if (DrainSegments != drain) {
                    IsAnimating = true;
                    if (DrainSegments > drain) {
                        DrainSegments--;
                        Grow_Segment();
                    } else {
                        DrainSegments++;
                        Shrink_Segment();
                    }
                } else if (HighSegments != high) {
                    IsAnimating = true;
                    if (HighSegments > high) {
                        HighSegments--;
                        Grow_Segment();
                    } else {
                        HighSegments++;
                        Shrink_Segment();
                    }
                } else if (LowSegments != low) {
                    IsAnimating = true;
                    if (LowSegments > low) {
                        LowSegments--;
                        Grow_Segment();
                    } else {
                        LowSegments++;
                        Shrink_Segment();
                    }
                }

                if (IsAnimating) {
                    AnimTimer = Animation_Delay();
                }
            }
        }
    }
    RadarClass::AI(input, xy);
}

void PowerClass::Set_Tool_Tips()
{
    RadarClass::Set_Tool_Tips();
    if (ToolTipHandler != NULL) {
        ToolTip tip;
        tip.ID = POWER_GADGET_ID;
        int shift = Scen->Field2239 ? 5 : 0;
        tip.Rect.Width = 8;
        tip.Rect.X = SidebarRect.X + shift;
        tip.Rect.Y = SidebarRect.Y + 0x45;
        tip.Rect.Height = PowerBarHeight;
        ToolTipHandler->Remove(POWER_GADGET_ID);
        ToolTipHandler->Add(tip);
    }
}

wchar_t const * PowerClass::Help_Text(int gadget_id)
{
    if (gadget_id == POWER_GADGET_ID) {
#line 662 "C:\\RA2\\Power.CPP"
        swprintf(HelpBuffer, Fetch_String("TXT_POWER_DRAIN", NULL, __FILE__, __LINE__), PlayerPtr->PowerOutput, PlayerPtr->PowerDrain);
        return HelpBuffer;
    }
    return RadarClass::Help_Text(gadget_id);
}
