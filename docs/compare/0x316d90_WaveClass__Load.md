# 0x316d90 ?Load@WaveClass@@UAGJPAUIStream@@@Z (src/m85/src/wave.cpp)

Origin: history: w286_x.claims.json. Community source: meastes1006_wave.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -11,7 +11,8 @@
 
 		int index;
+		WaveCellReader reader(stream);
 		int count;
 
-		result = stream->Read(&count, sizeof(count), NULL);
+		result = reader.Read(count);
 		if (FAILED(result)) {
 			return(result);
@@ -20,5 +21,5 @@
 		for (index = 0; index < count; index++) {
 			CellClass * obj;
-			result = stream->Read(&obj, sizeof(obj), NULL);
+			result = reader.Read(obj);
 			if (FAILED(result)) {
 				return(result);
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -5,5 +5,5 @@
 		new (this) WaveClass(NoInitClass());
 
-		WaveShape.Vertices = &ActiveWave.StartMiddle;
+		WaveShape.Vertices = &ActiveWaveStartMiddle;
 
 		Swizzle_Pointer(&Target);
@@ -11,7 +11,8 @@
 
 		int index;
+		WaveCellReader reader(stream);
 		int count;
 
-		result = stream->Read(&count, sizeof(count), NULL);
+		result = reader.Read(count);
 		if (FAILED(result)) {
 			return(result);
@@ -20,5 +21,5 @@
 		for (index = 0; index < count; index++) {
 			CellClass * obj;
-			result = stream->Read(&obj, sizeof(obj), NULL);
+			result = reader.Read(obj);
 			if (FAILED(result)) {
 				return(result);
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -5,5 +5,5 @@
 		new (this) WaveClass(NoInitClass());
 
-		WaveShape.Vertices = &ActiveWaveStartMiddle;
+		WaveShape.Vertices = &ActiveWave.StartMiddle;
 
 		Swizzle_Pointer(&Target);
```
