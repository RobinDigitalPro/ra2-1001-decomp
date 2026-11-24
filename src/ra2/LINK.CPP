// file name inferred from class name; not proven by a C:\RA2 string
// LINK.CPP (level-2 reconstruction of GAME.EXE 1.001)
//
// Doubly linked list node (RTTI .?AVLinkClass@@, vtable 0x78c8b4, 10 slots), the base of the
// gadget classes. All method and member names except the class name are provisional.
//
// TU span 0x537140..0x537343: no static initializer of its own. The TU before ends with the
// LightConvertClass scalar deleting destructor 0x537110 (vtable 0x7905bc); the GAMECONST block
// at 0x537350 starts the next TU. LinkClass's scalar deleting destructor (0x4cf2f0) was emitted
// as a COMDAT by GADGET.CPP, which comes earlier in link order.


// ---- local declarations (to be moved to headers by the integrator) ----

// RTTI .?AVLinkClass@@ (vtable 0x78c8b4, 10 slots).
class LinkClass {
public:
    LinkClass() : Next(0), Prev(0) {}
    LinkClass(LinkClass & link);                // 0x537140
    virtual ~LinkClass();                       // 0x537180, slot 0 (scalar deleting 0x4cf2f0)
    LinkClass & operator = (LinkClass & link);  // 0x5371e0

    virtual LinkClass * Get_Next() const;       // slot 1 (0x537200)
    virtual LinkClass * Get_Prev() const;       // slot 2 (0x537210)
    virtual LinkClass & Add(LinkClass & object);        // slot 3 (0x537280)
    virtual LinkClass & Add_Tail(LinkClass & object);   // slot 4 (0x5372c0)
    virtual LinkClass & Add_Head(LinkClass & object);   // slot 5 (0x5372a0)
    virtual LinkClass & Head_Of_List();         // slot 6 (+0x18, 0x537220)
    virtual LinkClass & Tail_Of_List();         // slot 7 (+0x1c, 0x537250)
    virtual void Zap();                         // slot 8 (0x5371d0)
    virtual LinkClass * Remove();               // slot 9 (+0x24, 0x5372f0)

    LinkClass * Next;                           // +0x04
    LinkClass * Prev;                           // +0x08
};

// ---- end of local declarations ----


// 0x537140
LinkClass::LinkClass(LinkClass & link) :
    Next(0),
    Prev(0)
{
    Add(link);
}


// 0x537180
LinkClass::~LinkClass()
{
    Remove();
}


// 0x5371d0
void LinkClass::Zap()
{
    Next = 0;
    Prev = 0;
}


// 0x5371e0
LinkClass & LinkClass::operator = (LinkClass & link)
{
    if (&link != this) {
        Remove();
        Add(link);
    }
    return *this;
}


// 0x537200
LinkClass * LinkClass::Get_Next() const
{
    return Next;
}


// 0x537210
LinkClass * LinkClass::Get_Prev() const
{
    return Prev;
}


// 0x537220
LinkClass & LinkClass::Head_Of_List()
{
    LinkClass * link = this;
    while (link->Prev) {
        link = link->Prev;
        if (link == this) break;
    }
    return *link;
}


// 0x537250
LinkClass & LinkClass::Tail_Of_List()
{
    LinkClass * link = this;
    while (link->Next) {
        link = link->Next;
        if (link == this) break;
    }
    return *link;
}


// 0x537280
LinkClass & LinkClass::Add(LinkClass & list)
{
    LinkClass * next = list.Next;
    list.Next = this;
    Prev = &list;
    Next = next;
    if (next) {
        next->Prev = this;
    }
    return Head_Of_List();
}


// 0x5372a0
LinkClass & LinkClass::Add_Head(LinkClass & list)
{
    LinkClass * head = &list.Head_Of_List();
    head->Prev = this;
    Next = head;
    Prev = 0;
    return *this;
}


// 0x5372c0
LinkClass & LinkClass::Add_Tail(LinkClass & list)
{
    LinkClass * tail = &list.Tail_Of_List();
    tail->Next = this;
    Prev = tail;
    Next = 0;
    return Head_Of_List();
}


// 0x5372f0
LinkClass * LinkClass::Remove()
{
    LinkClass * head = &Head_Of_List();
    LinkClass * tail = &Tail_Of_List();

    if (Prev) {
        Prev->Next = Next;
    }
    if (Next) {
        Next->Prev = Prev;
    }
    Prev = 0;
    Next = 0;

    if (head == this) {
        if (tail == this) {
            return 0;
        }
        return &tail->Head_Of_List();
    }
    return head;
}
