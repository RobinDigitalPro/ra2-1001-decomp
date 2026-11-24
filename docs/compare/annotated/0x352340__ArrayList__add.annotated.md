# 0x352340 · WolUserArray::Insert (packet label ArrayList<User>::add)

## Diff 1 is unavailable · recovered insertion — **DECISIVE**

The packet supplies no hunk on any side. The archived `history_before_after.zip` contains paired `0x352340__wonline.cpp` translation units. The failed TU has no definition of the named insertion method. The winning TU adds a `WolUserArray` class deriving from `ArrayList<User>` and declares `bool Insert(const User &user, int index)`. Its body calls `add(const_cast<User &>(user), index) != FALSE`. The cast adapts the real template's non-const reference parameter to the const public contract; comparison converts its return to `bool`. The inherited member is inlined at the derived entry point. This creates a target to compare where a function-body extractor previously returned nothing.

**Community comparison.** The batch 24 input `src__recovered__wonline__WolUserArray_Insert.cpp` from meastes 1.006 (`613e28e4e0`) contains `WolUserArray::Insert_00765e90`. It clamps an index above Count, tests capacity and calls Grow conditionally, calls Grow again, shifts existing items, copy-constructs the User in place, increments Count and returns true. It supplies the operation, const input and method identity. The winning native source delegates those operations to the existing template inside a short derived-class wrapper. There is no forwarding expression in the donor to copy verbatim.

**Isolated rebuild.** With the native headers and VC6 level-2 flags, the archived failed TU emitted neither the packet's exact decorated `ArrayList<User>::add` symbol nor a `WolUserArray::Insert` candidate. Adding only the class declaration and method definition yielded zero masked differences in the 400-byte Insert section. The exact decorated add name remained absent as a standalone entry. Batch 24 reports a 390-byte body plus section padding and five resolved relocations. Thus the registered RVA matches the emitted wrapper body; using only the packet's template spelling as a lookup would miss the successful result as well as the baseline.

## Why we did not find it

**Partly.** Batch 24 is the first ledger row for this address. Its `STRATEGIES.md` records a direct `ArrayList<User>::add` specialization that matched the target but changed `OnChannelJoin`. Declaring it inline removed the required entry, while explicitly instantiating the entire template triggered unsupported ordering operations on `User`. Thus a matching insert algorithm was found before the accepted wrapper. The missing piece was an independently emitted entry that preserved its callers and siblings. Batch 24's caller check at RVA 0x34e15d tied the operation to the user array at VA 0xb0fc00. The concrete derived method from the donor's contract provided that entry. The six cached variants belong to the recovery batch; the supplied records show no earlier wrapper campaign.

## How they found it

The named meastes 1.006 recovery is available as source. No note explains how meastes originally recovered it. The caller cross-check, existing template reuse, const-reference adapter and native symbol binding are documented native batch 24 work. The supplied archive provides no Gibbo discovery attribution for this case.
