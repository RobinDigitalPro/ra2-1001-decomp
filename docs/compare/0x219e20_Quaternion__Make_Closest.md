# 0x219e20 ?Make_Closest@Quaternion@@QAEAAV1@ABV1@@Z (src/m85/src/quat.cpp)

Origin: recent port: batch_54_*. Community source: gibbo8c1df2_quat.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,19 +1,16 @@
-Quaternion & Quaternion::Make_Closest(const Quaternion & qto) // RA2: at 0x00622290, between operator= and operator*
+Quaternion & Quaternion::Make_Closest(const Quaternion & qto) // RA2: at 0x00619e20, between operator= and operator*
 {
-	Quaternion t = *this;
-	Quaternion rel1 = t * Inverse(qto);
+	Quaternion rel1 = Quaternion(*this) / qto;
+	Quaternion rel2 = -*this / qto;
 
-	Quaternion negthis = Quaternion(-X, -Y, -Z, -W);
-	Quaternion rel2 = negthis * Inverse(qto);
-
-	float dot1 = rel1.Length2();
-	float dot2 = rel2.Length2();
+	float dot1 = rel1[0] * rel1[0] + rel1[1] * rel1[1] + rel1[2] * rel1[2] + rel1[3] * rel1[3];
+	float dot2 = rel2[0] * rel2[0] + rel2[1] * rel2[1] + rel2[2] * rel2[2] + rel2[3] * rel2[3];
 
 	// if we are on opposite hemisphere from qto, negate ourselves
 	if (dot2 < dot1) {
-		X = -X;
-		Y = -Y;
-		Z = -Z;
-		W = -W;
+		(*this)[0] = -(*this)[0];
+		(*this)[1] = -(*this)[1];
+		(*this)[2] = -(*this)[2];
+		(*this)[3] = -(*this)[3];
 	}
 
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -1,3 +1,3 @@
-Quaternion & Quaternion::Make_Closest(const Quaternion & qto)
+Quaternion & Quaternion::Make_Closest(const Quaternion & qto) // RA2: at 0x00619e20, between operator= and operator*
 {
 	Quaternion rel1 = Quaternion(*this) / qto;
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,19 +1,16 @@
-Quaternion & Quaternion::Make_Closest(const Quaternion & qto) // RA2: at 0x00622290, between operator= and operator*
+Quaternion & Quaternion::Make_Closest(const Quaternion & qto)
 {
-	Quaternion t = *this;
-	Quaternion rel1 = t * Inverse(qto);
+	Quaternion rel1 = Quaternion(*this) / qto;
+	Quaternion rel2 = -*this / qto;
 
-	Quaternion negthis = Quaternion(-X, -Y, -Z, -W);
-	Quaternion rel2 = negthis * Inverse(qto);
-
-	float dot1 = rel1.Length2();
-	float dot2 = rel2.Length2();
+	float dot1 = rel1[0] * rel1[0] + rel1[1] * rel1[1] + rel1[2] * rel1[2] + rel1[3] * rel1[3];
+	float dot2 = rel2[0] * rel2[0] + rel2[1] * rel2[1] + rel2[2] * rel2[2] + rel2[3] * rel2[3];
 
 	// if we are on opposite hemisphere from qto, negate ourselves
 	if (dot2 < dot1) {
-		X = -X;
-		Y = -Y;
-		Z = -Z;
-		W = -W;
+		(*this)[0] = -(*this)[0];
+		(*this)[1] = -(*this)[1];
+		(*this)[2] = -(*this)[2];
+		(*this)[3] = -(*this)[3];
 	}
 
```
