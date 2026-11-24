// file name inferred from class name; not proven by a C:\RA2 string
// PIPE.CPP (level-2 reconstruction of GAME.EXE 1.001)
// Westwood's chainable data pipe base class (RTTI .?AVPipe@@, vtable 0x789a20).
// Code range 0x606640..0x6066ff; PIXELFX.CPP follows at 0x606700.
// Vtable slots: 0 scalar deleting dtor (0x49eae0, emitted elsewhere), 1 Flush, 2 End (0x46c780,
// inline, emitted elsewhere), 3 Put_To, 4 Put. Member names are provisional (Westwood style).

// ---- local declarations (to be moved to headers by the integrator) ----

class Pipe {
public:
    Pipe() : ChainTo(0), ChainFrom(0) {}
    virtual ~Pipe();
    virtual int Flush();
    virtual int End() { return Flush(); }
    virtual void Put_To(Pipe * pipe);
    void Put_To(Pipe & pipe) { Put_To(&pipe); }
    virtual int Put(void const * source, int slen);

    Pipe * ChainTo;         // +0x04
    Pipe * ChainFrom;       // +0x08
};

// ---- end of local declarations ----

// 0x606640
Pipe::~Pipe()
{
    if (ChainTo != 0) {
        ChainTo->ChainFrom = ChainFrom;
    }
    if (ChainFrom != 0) {
        ChainFrom->Put_To(ChainTo);
    }
    ChainFrom = 0;
    ChainTo = 0;
}

// 0x606680
void Pipe::Put_To(Pipe * pipe)
{
    if (ChainTo != pipe) {
        if (pipe != 0 && pipe->ChainFrom != 0) {
            pipe->ChainFrom->Put_To(0);
            pipe->ChainFrom = 0;
        }
        if (ChainTo != 0) {
            ChainTo->ChainFrom = 0;
            ChainTo->Flush();
        }
        ChainTo = pipe;
        if (ChainTo != 0) {
            ChainTo->ChainFrom = this;
        }
    }
}

// 0x6066d0
int Pipe::Put(void const * source, int slen)
{
    if (ChainTo != 0) {
        return ChainTo->Put(source, slen);
    }
    return slen;
}

// 0x6066f0
int Pipe::Flush()
{
    if (ChainTo != 0) {
        return ChainTo->Flush();
    }
    return 0;
}
