# 0xf85f0 ??0HouseTypeClass@@QAE@PBD@Z (src/m85/src/houstype.cpp)

Origin: history: w294_x.claims.json. Community source: none found.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,4 +1,5 @@
 HouseTypeClass::HouseTypeClass(char const * ininame) :
 	BASECLASS(ininame),
+	ParentCountry(NULL),
 	House(HOUSE_NONE),
 	HeapID(HOUSE_NONE),
```

## 2. Our matched form against the community form

```diff
(not available)
```

## 3. Our failed form against the community form

```diff
(not available)
```
