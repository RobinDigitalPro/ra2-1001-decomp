# 0x2107e0 ?Planning_Draw_Filled_Techno@@YIXPAVTechnoClass@@@Z (src/m85/src/planmgr.cpp)

Origin: history: w349_x.claims.json. Community source: meastes1006_planmgr.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,82 +1,74 @@
-void __fastcall Planning_Draw_Filled_Techno(TechnoClass * techno) // RA2: 0x00618C00; draws the order a techno follows now and the first node of its path as dashed lines and filled dots
+void __fastcall Planning_Draw_Filled_Techno(TechnoClass * techno)
 {
-	PlanningTokenClass * token = techno->Get_Planning_Token(); // RA2: as above
-	Coord here = techno->As_Coord(); // RA2: as above
-	Point2D start = Planning_Coord_Pixel(here); // RA2: as above
-	int dim = Planning_Adjusted_Pixel(Planning_House_Color(techno), BlackColor, 0x50); // RA2: as above
-	int bright = Planning_Adjusted_Pixel(Planning_House_Color(techno), WhiteColor, 100); // RA2: as above
-	bool has_nodes = (token == NULL ? 0 : token->PlanningNodes.Count()) > 0; // RA2: as above
-	bool current = Planning_Current_Order(techno, has_nodes); // RA2: as above
-	int thickness = 4; // RA2: as above
-	int color = Planning_Techno_Color(techno); // RA2: as above
-	if (token != NULL && token->Owner_Is_Mission()) { // RA2: as above
-		EventClass event = token->Popped; // RA2: as above
-		Coord target = Planning_Event_Or_Object_Coord(event, techno); // RA2: as above
-		Point2D end = Planning_Coord_Pixel(target); // RA2: as above
-		Planning_Fill_Dot(start, dim); // RA2: as above
-		Planning_Draw_Dashed_Thick_Line(start, end, 3, dim); // RA2: as above
-		int frame = ((PlanningFirstTarget &)event).Get_Event_Frame(); // RA2: as above
-		if (frame != -1) { // RA2: as above
-			Planning_Draw_Midpoint_Shape(start, end, dim, color, frame); // RA2: as above
+	PlanningTokenClass * token = techno->Get_Planning_Token();
+	Coord origin = techno->As_Coord(); // RA2: as above
+	Point2D center = Planning_Coord_Pixel(origin); // RA2: as above
+	Point2D source; // RA2: as above
+	source = center; // RA2: assigned whole, as the family's other points and rectangles are (ra2-decomp's twin copies the two fields)
+	int color = Unit_Path_Tint(techno, WAYPOINT_NORMAL); // RA2: as above
+	int bright = Unit_Path_Tint(techno, WAYPOINT_BRIGHT); // RA2: as above
+	bool has_nodes = Has_Planned_Nodes(token); // RA2: as above
+	bool draw_action = Planning_Current_Order(techno, has_nodes); // RA2: as above
+	int width = 4; // RA2: as above
+	int fill = Waypoint_Fill_Color(techno); // RA2: as above
+	if (token && token->Owner_Is_Mission()) { // RA2: as above
+		EventClass packet(token->Popped); // RA2: as above
+		Coord coord = Planning_Event_Or_Object_Coord(packet, techno); // RA2: as above
+		Point2D target = Planning_Coord_Pixel(coord); // RA2: as above
+		Planning_Fill_Dot(center, color); // RA2: as above
+		Planning_Draw_Dashed_Thick_Line(center, target, 3, color); // RA2: as above
+		int frame = ((PlanningFirstTarget const &)packet).Get_Event_Frame(); // RA2: as above
+		if (frame != -1) Planning_Draw_Midpoint_Shape(center, target, color, fill, frame); // RA2: as above
+		Planning_Fill_Dot(target, color); // RA2: as above
+		return;
+	}
+
+	if (draw_action) { // RA2: as above
+		bool mega_mission = techno->HaveMegaMission(); // RA2: as above
+		bool attack_move = techno->HaveAttackMoveTarget(); // RA2: as above
+		Coord coord = techno->GetAttackCoordinates();
+		Point2D action = Planning_Coord_Pixel(coord); // RA2: as above
+		if (techno->IsInLimbo) {
+			Planning_Fill_Dot(action, color); // RA2: as above
+			return;
 		}
-		Planning_Fill_Dot(end, dim); // RA2: as above
-		return; // RA2: as above
+		Planning_Fill_Dot(center, color); // RA2: as above
+		Planning_Draw_Dashed_Thick_Line(center, action, 3, color); // RA2: as above
+		int frame = Active_Waypoint_Frame(techno, mega_mission, attack_move); // RA2: as above
+		if (frame != -1) Planning_Draw_Midpoint_Shape(center, action, color, fill, frame); // RA2: as above
+		Planning_Fill_Dot(action, color); // RA2: as above
+		if (attack_move) { // RA2: as above
+			Coord attack_coord = techno->GetAttackMoveCoords(); // RA2: as above
+			// level-2 1.001: STEERING
+			Point2D dest;
+			{
+				Point2D pixel;
+				TacticalMap->Coord_To_Pixel(attack_coord, pixel);
+				pixel.X += TacticalRect.X;
+				pixel.Y += TacticalRect.Y;
+				dest = pixel;
+			}
+			Planning_Draw_Line(action, dest, 0, color, true); // RA2: as above
+			frame = techno->GetMegaMission() == MISSION_ATTACK_MOVE ? Cursor_Start_Frame_77() : -1; // RA2: as above
+			if (frame != -1) Planning_Draw_Midpoint_Shape(action, dest, color, fill, frame); // RA2: as above
+			Planning_Fill_Dot(dest, color); // RA2: as above
+			return;
+		}
+		if (!has_nodes) return;
+		source = action; // RA2: as above
+		width = 3; // RA2: as above
+	} else if (!has_nodes) {
+		return;
 	}
-	if (current) { // RA2: as above
-		bool mega = techno->HaveMegaMission(); // RA2: as above
-		bool move = techno->HaveAttackMoveTarget(); // RA2: as above
-		Coord target = techno->GetAttackCoordinates();
-		Point2D end = Planning_Coord_Pixel(target); // RA2: as above
-		if (techno->IsInLimbo) { // RA2: as above
-			Planning_Fill_Dot(end, dim); // RA2: as above
-			return; // RA2: as above
-		}
-		Planning_Fill_Dot(start, dim); // RA2: as above
-		Planning_Draw_Dashed_Thick_Line(start, end, 3, dim); // RA2: as above
-		int __fastcall Planning_Guard_Frame(TechnoClass * techno);
-		int __fastcall Planning_Mega_Frame(TechnoClass * techno);
-		int frame = mega && !move ? Planning_Mega_Frame(techno) : Planning_Guard_Frame(techno);
-		if (frame != -1) { // RA2: as above
-			Planning_Draw_Midpoint_Shape(start, end, dim, color, frame); // RA2: as above
-		}
-		Planning_Fill_Dot(end, dim); // RA2: as above
-		if (move) { // RA2: as above
-			Coord next_coord = techno->GetAttackMoveCoords();
-			Point2D next = Planning_Coord_Pixel(next_coord); // RA2: as above
-			Planning_Draw_Dashed_Thick_Line(end, next, 3, dim); // RA2: as above
-			if (techno->GetMegaMission() == MISSION_ATTACK_MOVE) { // RA2: as above
-				frame = Cursor_Start_Frame_77(); // RA2: as above
-				if (frame != -1) { // RA2: as above
-					Planning_Draw_Midpoint_Shape(end, next, dim, color, frame); // RA2: as above
-				}
-			}
-			Planning_Fill_Dot(next, dim); // RA2: as above
-			return; // RA2: as above
-		}
-		if (!has_nodes) { // RA2: as above
-			return; // RA2: as above
-		}
-		start = end; // RA2: as above
-		thickness = 3; // RA2: as above
-	} else if (!has_nodes) { // RA2: as above
-		return; // RA2: as above
-	}
+
 	PlanningNodeClass * node = token->Node_At(0); // RA2: as above
-	Point2D end = node->Lead_Pixel(); // RA2: as above
+	Point2D target = node->Lead_Pixel(); // RA2: as above
 	PlanningBranchClass * branch = node->Branch_Of(techno); // RA2: as above
-	if (branch != NULL) { // RA2: as above
-		EventClass const & lead = branch->Event; // RA2: as above
-		end = Planning_Event_Pixel(&lead, techno); // RA2: as above
-	}
-	int dot = token->Reached(0) ? bright : dim; // RA2: as above
-	Planning_Fill_Dot(start, dot); // RA2: as above
-	Planning_Draw_Dashed_Thick_Line(start, end, thickness, dot); // RA2: as above
-	if (branch != NULL) { // RA2: as above
-		Planning_Fill_Dot(end, dot); // RA2: as above
-	}
-	EventClass event = node->Get_Event_For(techno); // RA2: as above
-	int frame = ((PlanningFirstTarget &)event).Get_Event_Frame(); // RA2: as above
-	if (frame != -1) { // RA2: as above
-		Planning_Draw_Midpoint_Shape(start, end, dot, color, frame); // RA2: as above
-	}
+	if (branch) target = Planning_Event_Pixel(&branch->Event, techno); // RA2: as above
+	int path_color = token->Reached(0) ? bright : color; // RA2: as above
+	Planning_Fill_Dot(source, path_color); // RA2: as above
+	Planning_Draw_Dashed_Thick_Line(source, target, width, path_color); // RA2: as above
+	if (branch) Planning_Fill_Dot(target, path_color); // RA2: as above
+	int frame = Planned_Waypoint_Frame(node->Get_Event_For(techno)); // RA2: as above
+	if (frame != -1) Planning_Draw_Midpoint_Shape(source, target, path_color, fill, frame); // RA2: as above
 }
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -9,5 +9,5 @@
 	int bright = Unit_Path_Tint(techno, WAYPOINT_BRIGHT); // RA2: as above
 	bool has_nodes = Has_Planned_Nodes(token); // RA2: as above
-	bool draw_action = Should_Draw_Active_Action(techno, has_nodes); // RA2: as above
+	bool draw_action = Planning_Current_Order(techno, has_nodes); // RA2: as above
 	int width = 4; // RA2: as above
 	int fill = Waypoint_Fill_Color(techno); // RA2: as above
@@ -18,5 +18,5 @@
 		Planning_Fill_Dot(center, color); // RA2: as above
 		Planning_Draw_Dashed_Thick_Line(center, target, 3, color); // RA2: as above
-		int frame = packet.Get_Event_Frame(); // RA2: as above
+		int frame = ((PlanningFirstTarget const &)packet).Get_Event_Frame(); // RA2: as above
 		if (frame != -1) Planning_Draw_Midpoint_Shape(center, target, color, fill, frame); // RA2: as above
 		Planning_Fill_Dot(target, color); // RA2: as above
@@ -40,5 +40,13 @@
 		if (attack_move) { // RA2: as above
 			Coord attack_coord = techno->GetAttackMoveCoords(); // RA2: as above
-			Point2D dest = Planning_Coord_Pixel(attack_coord); // RA2: as above
+			// level-2 1.001: STEERING
+			Point2D dest;
+			{
+				Point2D pixel;
+				TacticalMap->Coord_To_Pixel(attack_coord, pixel);
+				pixel.X += TacticalRect.X;
+				pixel.Y += TacticalRect.Y;
+				dest = pixel;
+			}
 			Planning_Draw_Line(action, dest, 0, color, true); // RA2: as above
 			frame = techno->GetMegaMission() == MISSION_ATTACK_MOVE ? Cursor_Start_Frame_77() : -1; // RA2: as above
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,82 +1,66 @@
-void __fastcall Planning_Draw_Filled_Techno(TechnoClass * techno) // RA2: 0x00618C00; draws the order a techno follows now and the first node of its path as dashed lines and filled dots
+void __fastcall Planning_Draw_Filled_Techno(TechnoClass * techno)
 {
-	PlanningTokenClass * token = techno->Get_Planning_Token(); // RA2: as above
-	Coord here = techno->As_Coord(); // RA2: as above
-	Point2D start = Planning_Coord_Pixel(here); // RA2: as above
-	int dim = Planning_Adjusted_Pixel(Planning_House_Color(techno), BlackColor, 0x50); // RA2: as above
-	int bright = Planning_Adjusted_Pixel(Planning_House_Color(techno), WhiteColor, 100); // RA2: as above
-	bool has_nodes = (token == NULL ? 0 : token->PlanningNodes.Count()) > 0; // RA2: as above
-	bool current = Planning_Current_Order(techno, has_nodes); // RA2: as above
-	int thickness = 4; // RA2: as above
-	int color = Planning_Techno_Color(techno); // RA2: as above
-	if (token != NULL && token->Owner_Is_Mission()) { // RA2: as above
-		EventClass event = token->Popped; // RA2: as above
-		Coord target = Planning_Event_Or_Object_Coord(event, techno); // RA2: as above
-		Point2D end = Planning_Coord_Pixel(target); // RA2: as above
-		Planning_Fill_Dot(start, dim); // RA2: as above
-		Planning_Draw_Dashed_Thick_Line(start, end, 3, dim); // RA2: as above
-		int frame = ((PlanningFirstTarget &)event).Get_Event_Frame(); // RA2: as above
-		if (frame != -1) { // RA2: as above
-			Planning_Draw_Midpoint_Shape(start, end, dim, color, frame); // RA2: as above
+	PlanningTokenClass * token = techno->Get_Planning_Token();
+	Coord origin = techno->As_Coord(); // RA2: as above
+	Point2D center = Planning_Coord_Pixel(origin); // RA2: as above
+	Point2D source; // RA2: as above
+	source = center; // RA2: assigned whole, as the family's other points and rectangles are (ra2-decomp's twin copies the two fields)
+	int color = Unit_Path_Tint(techno, WAYPOINT_NORMAL); // RA2: as above
+	int bright = Unit_Path_Tint(techno, WAYPOINT_BRIGHT); // RA2: as above
+	bool has_nodes = Has_Planned_Nodes(token); // RA2: as above
+	bool draw_action = Should_Draw_Active_Action(techno, has_nodes); // RA2: as above
+	int width = 4; // RA2: as above
+	int fill = Waypoint_Fill_Color(techno); // RA2: as above
+	if (token && token->Owner_Is_Mission()) { // RA2: as above
+		EventClass packet(token->Popped); // RA2: as above
+		Coord coord = Planning_Event_Or_Object_Coord(packet, techno); // RA2: as above
+		Point2D target = Planning_Coord_Pixel(coord); // RA2: as above
+		Planning_Fill_Dot(center, color); // RA2: as above
+		Planning_Draw_Dashed_Thick_Line(center, target, 3, color); // RA2: as above
+		int frame = packet.Get_Event_Frame(); // RA2: as above
+		if (frame != -1) Planning_Draw_Midpoint_Shape(center, target, color, fill, frame); // RA2: as above
+		Planning_Fill_Dot(target, color); // RA2: as above
+		return;
+	}
+
+	if (draw_action) { // RA2: as above
+		bool mega_mission = techno->HaveMegaMission(); // RA2: as above
+		bool attack_move = techno->HaveAttackMoveTarget(); // RA2: as above
+		Coord coord = techno->GetAttackCoordinates();
+		Point2D action = Planning_Coord_Pixel(coord); // RA2: as above
+		if (techno->IsInLimbo) {
+			Planning_Fill_Dot(action, color); // RA2: as above
+			return;
 		}
-		Planning_Fill_Dot(end, dim); // RA2: as above
-		return; // RA2: as above
+		Planning_Fill_Dot(center, color); // RA2: as above
+		Planning_Draw_Dashed_Thick_Line(center, action, 3, color); // RA2: as above
+		int frame = Active_Waypoint_Frame(techno, mega_mission, attack_move); // RA2: as above
+		if (frame != -1) Planning_Draw_Midpoint_Shape(center, action, color, fill, frame); // RA2: as above
+		Planning_Fill_Dot(action, color); // RA2: as above
+		if (attack_move) { // RA2: as above
+			Coord attack_coord = techno->GetAttackMoveCoords(); // RA2: as above
+			Point2D dest = Planning_Coord_Pixel(attack_coord); // RA2: as above
+			Planning_Draw_Line(action, dest, 0, color, true); // RA2: as above
+			frame = techno->GetMegaMission() == MISSION_ATTACK_MOVE ? Cursor_Start_Frame_77() : -1; // RA2: as above
+			if (frame != -1) Planning_Draw_Midpoint_Shape(action, dest, color, fill, frame); // RA2: as above
+			Planning_Fill_Dot(dest, color); // RA2: as above
+			return;
+		}
+		if (!has_nodes) return;
+		source = action; // RA2: as above
+		width = 3; // RA2: as above
+	} else if (!has_nodes) {
+		return;
 	}
-	if (current) { // RA2: as above
-		bool mega = techno->HaveMegaMission(); // RA2: as above
-		bool move = techno->HaveAttackMoveTarget(); // RA2: as above
-		Coord target = techno->GetAttackCoordinates();
-		Point2D end = Planning_Coord_Pixel(target); // RA2: as above
-		if (techno->IsInLimbo) { // RA2: as above
-			Planning_Fill_Dot(end, dim); // RA2: as above
-			return; // RA2: as above
-		}
-		Planning_Fill_Dot(start, dim); // RA2: as above
-		Planning_Draw_Dashed_Thick_Line(start, end, 3, dim); // RA2: as above
-		int __fastcall Planning_Guard_Frame(TechnoClass * techno);
-		int __fastcall Planning_Mega_Frame(TechnoClass * techno);
-		int frame = mega && !move ? Planning_Mega_Frame(techno) : Planning_Guard_Frame(techno);
-		if (frame != -1) { // RA2: as above
-			Planning_Draw_Midpoint_Shape(start, end, dim, color, frame); // RA2: as above
-		}
-		Planning_Fill_Dot(end, dim); // RA2: as above
-		if (move) { // RA2: as above
-			Coord next_coord = techno->GetAttackMoveCoords();
-			Point2D next = Planning_Coord_Pixel(next_coord); // RA2: as above
-			Planning_Draw_Dashed_Thick_Line(end, next, 3, dim); // RA2: as above
-			if (techno->GetMegaMission() == MISSION_ATTACK_MOVE) { // RA2: as above
-				frame = Cursor_Start_Frame_77(); // RA2: as above
-				if (frame != -1) { // RA2: as above
-					Planning_Draw_Midpoint_Shape(end, next, dim, color, frame); // RA2: as above
-				}
-			}
-			Planning_Fill_Dot(next, dim); // RA2: as above
-			return; // RA2: as above
-		}
-		if (!has_nodes) { // RA2: as above
-			return; // RA2: as above
-		}
-		start = end; // RA2: as above
-		thickness = 3; // RA2: as above
-	} else if (!has_nodes) { // RA2: as above
-		return; // RA2: as above
-	}
+
 	PlanningNodeClass * node = token->Node_At(0); // RA2: as above
-	Point2D end = node->Lead_Pixel(); // RA2: as above
+	Point2D target = node->Lead_Pixel(); // RA2: as above
 	PlanningBranchClass * branch = node->Branch_Of(techno); // RA2: as above
-	if (branch != NULL) { // RA2: as above
-		EventClass const & lead = branch->Event; // RA2: as above
-		end = Planning_Event_Pixel(&lead, techno); // RA2: as above
-	}
-	int dot = token->Reached(0) ? bright : dim; // RA2: as above
-	Planning_Fill_Dot(start, dot); // RA2: as above
-	Planning_Draw_Dashed_Thick_Line(start, end, thickness, dot); // RA2: as above
-	if (branch != NULL) { // RA2: as above
-		Planning_Fill_Dot(end, dot); // RA2: as above
-	}
-	EventClass event = node->Get_Event_For(techno); // RA2: as above
-	int frame = ((PlanningFirstTarget &)event).Get_Event_Frame(); // RA2: as above
-	if (frame != -1) { // RA2: as above
-		Planning_Draw_Midpoint_Shape(start, end, dot, color, frame); // RA2: as above
-	}
+	if (branch) target = Planning_Event_Pixel(&branch->Event, techno); // RA2: as above
+	int path_color = token->Reached(0) ? bright : color; // RA2: as above
+	Planning_Fill_Dot(source, path_color); // RA2: as above
+	Planning_Draw_Dashed_Thick_Line(source, target, width, path_color); // RA2: as above
+	if (branch) Planning_Fill_Dot(target, path_color); // RA2: as above
+	int frame = Planned_Waypoint_Frame(node->Get_Event_For(techno)); // RA2: as above
+	if (frame != -1) Planning_Draw_Midpoint_Shape(source, target, path_color, fill, frame); // RA2: as above
 }
```
