# 0x20f6d0 ?Planning_Connect_Selection@@YAXXZ (src/m85/src/planmgr.cpp)

Origin: history: w285_x.claims.json. Community source: meastes1006_planmgr.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -8,9 +8,5 @@
 		for (int i = 0; i < count; i++) { // RA2: as above
 			ObjectClass * object = CurrentObject[i]; // RA2: as above
-			bool techno; // RA2: as above
-			if (object != NULL) { // RA2: as above
-				techno = object->AbstractFlags & 1; // RA2: as above
-			}
-			if (object != NULL && techno) { // RA2: as above
+			if (Planning_Is_Techno(object)) { // RA2: as above
 				TechnoClass * unit = (TechnoClass *)object; // RA2: as above
 				PlanningTokenClass * token = unit->Get_Planning_Token(); // RA2: as above
@@ -20,5 +16,5 @@
 						units.Add(unit); // RA2: as above
 					} else { // RA2: as above
-						int members = last->PlanningMembers.Count(); // RA2: as above
+						int members = last->Get_Count(); // RA2: as above
 						for (int j = 0; j < members; j++) { // RA2: as above
 							TechnoClass * owner = last->Member_Owner(j); // RA2: as above
@@ -42,5 +38,6 @@
 	} else { // RA2: as above
 		Planning_Set_Selected_Node(selected); // RA2: as above
-		Planning_Help(4); // RA2: as above
+		void (__fastcall *help)(int) = Planning_Help;
+		help(4); // RA2: as above
 	}
 }
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -8,5 +8,5 @@
 		for (int i = 0; i < count; i++) { // RA2: as above
 			ObjectClass * object = CurrentObject[i]; // RA2: as above
-			if (object->Is_Techno()) { // RA2: as above
+			if (Planning_Is_Techno(object)) { // RA2: as above
 				TechnoClass * unit = (TechnoClass *)object; // RA2: as above
 				PlanningTokenClass * token = unit->Get_Planning_Token(); // RA2: as above
@@ -38,5 +38,6 @@
 	} else { // RA2: as above
 		Planning_Set_Selected_Node(selected); // RA2: as above
-		Planning_Help(4); // RA2: as above
+		void (__fastcall *help)(int) = Planning_Help;
+		help(4); // RA2: as above
 	}
 }
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -8,9 +8,5 @@
 		for (int i = 0; i < count; i++) { // RA2: as above
 			ObjectClass * object = CurrentObject[i]; // RA2: as above
-			bool techno; // RA2: as above
-			if (object != NULL) { // RA2: as above
-				techno = object->AbstractFlags & 1; // RA2: as above
-			}
-			if (object != NULL && techno) { // RA2: as above
+			if (object->Is_Techno()) { // RA2: as above
 				TechnoClass * unit = (TechnoClass *)object; // RA2: as above
 				PlanningTokenClass * token = unit->Get_Planning_Token(); // RA2: as above
@@ -20,5 +16,5 @@
 						units.Add(unit); // RA2: as above
 					} else { // RA2: as above
-						int members = last->PlanningMembers.Count(); // RA2: as above
+						int members = last->Get_Count(); // RA2: as above
 						for (int j = 0; j < members; j++) { // RA2: as above
 							TechnoClass * owner = last->Member_Owner(j); // RA2: as above
```
