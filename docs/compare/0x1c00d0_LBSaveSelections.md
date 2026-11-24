# 0x1c00d0 ?LBSaveSelections@@YIXPAUHWND__@@AAV?$Dictionary@VWideWstring@@_N@@@Z (src/m85/src/netshare.cpp)

Origin: history: w290_x.claims.json. Community source: gibbo1b47a1_netshare.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,35 +1,42 @@
-void LBSaveSelections(HWND listbox, Dictionary<WideWstring,bool> & lbdict) // RA2: 0x005C5FF0, the dictionary and the key are wide
+void LBSaveSelections(HWND listbox, Dictionary<WideWstring,bool> & lbdict)
 {
-	int count = ListBox_GetCount(listbox);
-	WideWstring key; // RA2: the key is a wide string
-	wchar_t wide[1024]; // RA2: the item text is fetched wide, through the narrow text when the list box has no wide text
-	char buffer[1024]; // RA2: as above
+    int count = ListBox_GetCount(listbox);
+    WideWstring key;
+    wchar_t wide[1024];
+    char buffer[1024];
 
-	if (count) {
-		int style = GetWindowLong(listbox, GWL_STYLE);
-		if (style & LBS_MULTIPLESEL) {
-			for (int i = 0; i < count; i++) {
-				if (ListBox_GetSel(listbox, i) != 0) {
-					Get_List_Row_Text(listbox, i, wide, buffer); // RA2: as above
-					key = wide; // RA2: as above
-					bool value = true;
-					lbdict.add(key, value);
-				}
-			}
-		} else if (!(style & LBS_NOSEL)) {
-			int index = ListBox_GetCurSel(listbox);
-			if (index >= 0) {
-				wide[0] = '\0'; // RA2: as above
-				if (SendMessage(listbox, WM_USER + 207, index, 0)) { // RA2: the text of the item is fetched wide, through the narrow text when the list box has no wide text
-					SendMessage(listbox, OD_GETTEXTW, index, (LPARAM)wide); // RA2: message 0x4B6, as Get_List_Item_Wide_Text
-				} else {
-					SendMessage(listbox, OD_GETTEXTA, index, (LPARAM)buffer); // RA2: message 0x4B7, as Get_List_Item_Text
-					Char_To_Wide(wide, buffer, -1); // RA2: 0x006FA0C0
-				}
-				key = wide; // RA2: as above
-				bool value = true;
-				lbdict.add(key, value);
-			}
-		}
-	}
+    if (count) {
+        int style = GetWindowLong(listbox, GWL_STYLE);
+        if (style & LBS_MULTIPLESEL) {
+            for (int i = 0; i < count; i++) {
+                if (ListBox_GetSel(listbox, i) != 0) {
+                    if (SendMessage(listbox, WM_USER + 207, i, 0)) {
+                        SendMessage(listbox, OD_GETTEXTW, i, (LPARAM)wide);
+                    } else {
+                        SendMessage(listbox, OD_GETTEXTA, i, (LPARAM)buffer);
+                        Char_To_Wide(wide, buffer, -1);
+                    }
+                    key = wide;
+                    bool value = true;
+                    lbdict.add(key, value);
+                }
+            }
+        } else if (!(style & LBS_NOSEL)) {
+            int index = ListBox_GetCurSel(listbox);
+            if (index < 0) {
+                return;
+            }
+            {
+                wide[0] = '\0';
+                if (List_Row_Is_Wide(listbox, index)) {
+                    SendMessage(listbox, OD_GETTEXTW, index, (LPARAM)wide);
+                } else {
+                    List_Row_Wide_Text(listbox, index, wide, buffer);
+                }
+                key = wide;
+                bool value = true;
+                lbdict.add(key, value);
+            }
+        }
+    }
 }
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -1,36 +1,42 @@
-void LBSaveSelections(HWND win, Dictionary<WideWstring,bool> & lbdict)
-{
-	int count = ListBox_GetCount(win);
-	WideWstring key;
-	wchar_t wide[0x400];
-	char narrow[0x400];
-
-	if (count == 0) {
-		return;
-	}
-	int style = GetWindowLong(win, GWL_STYLE);
-	if (style & LBS_MULTIPLESEL) {
-		for (int i = 0; i < count; i++) {
-			if (ListBox_GetSel(win, i) != 0) {
-				if (SendMessage(win, 0x4cf, i, 0) != 0) {
-					SendMessage(win, 0x4b6, i, (LPARAM)wide);
-				} else {
-					SendMessage(win, 0x4b7, i, (LPARAM)narrow);
-					FUN_00735060(wide, narrow, -1);
-				}
-				key = wide;
-				bool value = true;
-				lbdict.add(key, value);
-			}
-		}
-	} else if (!(style & LBS_NOSEL)) {
-		int index = ListBox_GetCurSel(win);
-		if (index >= 0) {
-			wide[0] = 0;
-			LBGetText(win, index, wide, narrow);
-			key = wide;
-			bool value = true;
-			lbdict.add(key, value);
-		}
-	}
+void LBSaveSelections(HWND listbox, Dictionary<WideWstring,bool> & lbdict)
+{
+    int count = ListBox_GetCount(listbox);
+    WideWstring key;
+    wchar_t wide[1024];
+    char buffer[1024];
+
+    if (count) {
+        int style = GetWindowLong(listbox, GWL_STYLE);
+        if (style & LBS_MULTIPLESEL) {
+            for (int i = 0; i < count; i++) {
+                if (ListBox_GetSel(listbox, i) != 0) {
+                    if (SendMessage(listbox, WM_USER + 207, i, 0)) {
+                        SendMessage(listbox, OD_GETTEXTW, i, (LPARAM)wide);
+                    } else {
+                        SendMessage(listbox, OD_GETTEXTA, i, (LPARAM)buffer);
+                        Char_To_Wide(wide, buffer, -1);
+                    }
+                    key = wide;
+                    bool value = true;
+                    lbdict.add(key, value);
+                }
+            }
+        } else if (!(style & LBS_NOSEL)) {
+            int index = ListBox_GetCurSel(listbox);
+            if (index < 0) {
+                return;
+            }
+            {
+                wide[0] = '\0';
+                if (List_Row_Is_Wide(listbox, index)) {
+                    SendMessage(listbox, OD_GETTEXTW, index, (LPARAM)wide);
+                } else {
+                    List_Row_Wide_Text(listbox, index, wide, buffer);
+                }
+                key = wide;
+                bool value = true;
+                lbdict.add(key, value);
+            }
+        }
+    }
 }
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,35 +1,36 @@
-void LBSaveSelections(HWND listbox, Dictionary<WideWstring,bool> & lbdict) // RA2: 0x005C5FF0, the dictionary and the key are wide
-{
-	int count = ListBox_GetCount(listbox);
-	WideWstring key; // RA2: the key is a wide string
-	wchar_t wide[1024]; // RA2: the item text is fetched wide, through the narrow text when the list box has no wide text
-	char buffer[1024]; // RA2: as above
-
-	if (count) {
-		int style = GetWindowLong(listbox, GWL_STYLE);
-		if (style & LBS_MULTIPLESEL) {
-			for (int i = 0; i < count; i++) {
-				if (ListBox_GetSel(listbox, i) != 0) {
-					Get_List_Row_Text(listbox, i, wide, buffer); // RA2: as above
-					key = wide; // RA2: as above
-					bool value = true;
-					lbdict.add(key, value);
-				}
-			}
-		} else if (!(style & LBS_NOSEL)) {
-			int index = ListBox_GetCurSel(listbox);
-			if (index >= 0) {
-				wide[0] = '\0'; // RA2: as above
-				if (SendMessage(listbox, WM_USER + 207, index, 0)) { // RA2: the text of the item is fetched wide, through the narrow text when the list box has no wide text
-					SendMessage(listbox, OD_GETTEXTW, index, (LPARAM)wide); // RA2: message 0x4B6, as Get_List_Item_Wide_Text
-				} else {
-					SendMessage(listbox, OD_GETTEXTA, index, (LPARAM)buffer); // RA2: message 0x4B7, as Get_List_Item_Text
-					Char_To_Wide(wide, buffer, -1); // RA2: 0x006FA0C0
-				}
-				key = wide; // RA2: as above
-				bool value = true;
-				lbdict.add(key, value);
-			}
-		}
-	}
+void LBSaveSelections(HWND win, Dictionary<WideWstring,bool> & lbdict)
+{
+	int count = ListBox_GetCount(win);
+	WideWstring key;
+	wchar_t wide[0x400];
+	char narrow[0x400];
+
+	if (count == 0) {
+		return;
+	}
+	int style = GetWindowLong(win, GWL_STYLE);
+	if (style & LBS_MULTIPLESEL) {
+		for (int i = 0; i < count; i++) {
+			if (ListBox_GetSel(win, i) != 0) {
+				if (SendMessage(win, 0x4cf, i, 0) != 0) {
+					SendMessage(win, 0x4b6, i, (LPARAM)wide);
+				} else {
+					SendMessage(win, 0x4b7, i, (LPARAM)narrow);
+					FUN_00735060(wide, narrow, -1);
+				}
+				key = wide;
+				bool value = true;
+				lbdict.add(key, value);
+			}
+		}
+	} else if (!(style & LBS_NOSEL)) {
+		int index = ListBox_GetCurSel(win);
+		if (index >= 0) {
+			wide[0] = 0;
+			LBGetText(win, index, wide, narrow);
+			key = wide;
+			bool value = true;
+			lbdict.add(key, value);
+		}
+	}
 }
```
