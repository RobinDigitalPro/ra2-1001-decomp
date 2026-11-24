# 0xf85f0 · HouseTypeClass::HouseTypeClass(char const *)

## Diff 1, hunk 1 · Construct the country-name member with a null string (old 1, new 1)

**DECISIVE with the companion type declaration and definition.** Before, the initializer list went from `BASECLASS(ininame)` to `House(HOUSE_NONE)`. After, `ParentCountry(NULL)` appears between them. This selects the string-taking overload on the embedded 25-byte `CountryName`. Its null path writes zero to `Buffer[0]` immediately after base construction. `ParentCountry` is declared before `House`, so construction takes place at the required point irrespective of initializer-list text order. Previously the empty default constructor selected at that point made no store.

The short body diff hides the prerequisite in `houstype.h`: `CountryName() {}` remains available and a new `explicit CountryName(char const * source)` is declared. The inline definition in houstype.cpp reuses `Country_Name_From(*this, source)`. This targeted overload leaves default construction in other contexts alone. Changing the constructor body or reordering scalar initializers cannot express selection of the missing overload.

Meastes 1.006, `src/recovered/houstype.cpp` at revision `613e28e4e0`, supplies evidence for an embedded string object. Its normal constructor leaves that member's initialization implicit. The no-init constructor explicitly passes `noinit` and the file also assigns a `FixedString<25>` value. The literal `ParentCountry(NULL)` is our adaptation to our existing helper. Gibbo's YR constructor is independent supporting evidence for an embedded member that clears its first byte.

**Compile check.** In the historical matched TU with the B25 header change, restoring the omitted initializer alone gave 303 differences in 608 bytes, first at +0x0f. Restoring the one line gave 0/608 with bindings open under VC6 8168 and the level-2 checker. The original has 600 body bytes and eight padding bytes. B25 checked all five direct calls, both constructor/destructor controls and 80 houstype siblings. With the old header the explicit string-taking constructor is unavailable.

## Why we did not find it

**Yes, before integration.** M2 did not reach the constructor. WORK_QUEUE M3 records that adding `CountryName` constructors already made this target byte-identical, but the shared declaration cost `Print_CRCs`. The search had an integration problem after it had found the source idea. B25's seven original-header variants bottomed out at hunk score 5. Its explicit-overload helper search under the patched header scored zero. B27 then examined declaration-order side effects, including `Zone_Reset`, `SelectClass::Action` and `WinMain`, with scoped repairs. Calling the original member directly from a later point in the body could not restore the placement of the first-byte store.

## How they found it

For YR VA 0x005113F0, gibbo's 12 October attempts entry credits a memory-order initializer list and a parent-country struct whose inline constructor stores the leading NUL. The archive gives the observation and the winning form, but no finer-grained search sequence for the string overload. B25 credited meastes for the 1.006 reference. The source demonstrates object semantics and the task records how the RA2 port recovered the write. Evidence: B25 report and header patch, WORK_QUEUE M2/M3, B27 report, recovered houstype.cpp and gibbo `data/attempts.csv` row 712.
