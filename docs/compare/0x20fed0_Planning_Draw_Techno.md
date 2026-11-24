# 0x20fed0 ?Planning_Draw_Techno@@YIXPAVTechnoClass@@@Z (src/m85/src/planmgr.cpp)

Origin: history: w349_x.claims.json. Community source: meastes1006_planmgr.cpp.

## 1. What changed to make it match (ours before -> ours matched)

```diff
--- ours before
+++ ours matched
@@ -1,81 +1,64 @@
-void __fastcall Planning_Draw_Techno(TechnoClass * techno) // RA2: 0x006182F0; draws the order a techno follows now and the first node of its path as outlines
+void __fastcall Planning_Draw_Techno(TechnoClass * techno) // RA2: 0x006182F0; draws the path of a techno: the order under way, the current action and the line to the first node; ra2-decomp's whole twin text (Yuri's Revenge 0x0063B550, the separate source point included), the popped order copied with = and the frame read through RA2's member
 {
-	// level-2 1.001: forms adopted from meastes/redalert2-decomp src/recovered/planmgr.cpp @613e28e4e0
-	// (GPL-3.0-or-later; 1.006 0x006182F0; the same shape as gibbo101/ra2-decomp src/planmgr.cpp
-	// FUN_0063B550 @721d81e44f): the current-order test is the helper inline, the order target is a
-	// coordinate of its own, the midpoint frame is tested here and the first node is drawn in a block.
 	PlanningTokenClass * token = techno->Get_Planning_Token(); // RA2: as above
-	Coord here = techno->As_Coord(); // RA2: as above
-	Point2D start = Planning_Coord_Pixel(here); // RA2: as above
+	Coord origin = techno->As_Coord(); // RA2: as above
+	Point2D center = Planning_Coord_Pixel(origin); // RA2: as above
+	Point2D source; // RA2: as above
+	source.X = center.X; // RA2: as above
+	source.Y = center.Y; // RA2: as above
 	int color = Planning_Techno_Color(techno); // RA2: as above
-	struct {
-		bool has_nodes;
-		bool move;
-	} flags;
-	flags.has_nodes = (token == NULL ? 0 : token->PlanningNodes.Count()) > 0; // RA2: as above
-	bool current = Planning_Current_Order(techno, flags.has_nodes); // RA2: as above
-	int thickness = 4; // RA2: as above
-	if (token != NULL && token->Owner_Is_Mission()) { // RA2: as above
-		EventClass event = token->Popped; // RA2: as above
-		Coord target = Planning_Event_Or_Object_Coord(event, techno); // RA2: as above
-		Point2D end = Planning_Coord_Pixel(target); // RA2: as above
-		Planning_Draw_Dot(start, color); // RA2: as above
-		Planning_Draw_Thick_Line(start, end, 3, color); // RA2: as above
-		if (((PlanningFirstTarget const &)event).Get_Event_Frame() != -1) { // RA2: as above
-			Planning_Draw_Midpoint(start, end, color); // RA2: as above
-		}
-		Planning_Draw_Dot(end, color); // RA2: as above
+	bool has_nodes = Has_Planned_Nodes(token); // RA2: as above
+	bool draw_action = Planning_Current_Order(techno, has_nodes); // RA2: as above
+	int width = 4; // RA2: as above
+	if (token && token->Owner_Is_Mission()) { // RA2: as above
+		EventClass packet = token->Popped; // RA2: as above
+		Coord coord = Planning_Event_Or_Object_Coord(packet, techno); // RA2: as above
+		Point2D target = Planning_Coord_Pixel(coord); // RA2: as above
+		Planning_Draw_Dot(center, color); // RA2: as above
+		Planning_Draw_Thick_Line(center, target, 3, color); // RA2: as above
+		int frame = ((PlanningFirstTarget const &)packet).Get_Event_Frame(); // RA2: as above
+		if (frame != -1) Planning_Draw_Midpoint(center, target, color); // RA2: as above
+		Planning_Draw_Dot(target, color); // RA2: as above
 		return; // RA2: as above
 	}
-	if (current) { // RA2: as above
-		bool mega = techno->HaveMegaMission(); // RA2: as above
-		flags.move = techno->HaveAttackMoveTarget(); // RA2: as above
-		Coord target = techno->GetAttackCoordinates(); // RA2: as above
-		Point2D end = Planning_Coord_Pixel(target); // RA2: as above
+
+	if (draw_action) { // RA2: as above
+		bool mega_mission = techno->HaveMegaMission(); // RA2: as above
+		bool attack_move = techno->HaveAttackMoveTarget(); // RA2: as above
+		Coord coord = techno->GetAttackCoordinates(); // RA2: as above
+		Point2D action = Planning_Coord_Pixel(coord); // RA2: as above
 		if (techno->IsInLimbo) { // RA2: as above
-			Planning_Draw_Dot(end, color); // RA2: as above
+			Planning_Draw_Dot(action, color); // RA2: as above
 			return; // RA2: as above
 		}
-		Planning_Draw_Dot(start, color); // RA2: as above
-		Planning_Draw_Thick_Line(start, end, 3, color); // RA2: as above
-		int frame = (mega && !flags.move) ? Planning_Mega_Frame(techno) : Planning_Guard_Frame(techno); // RA2: as above
-		if (frame != -1) { // RA2: as above
-			Planning_Draw_Midpoint(start, end, color); // RA2: as above
-		}
-		Planning_Draw_Dot(end, color); // RA2: as above
-		if (flags.move) { // RA2: as above
-			Coord next_coord = techno->GetAttackMoveCoords(); // RA2: as above
-			Point2D next = Planning_Coord_Pixel(next_coord); // RA2: as above
-			Planning_Draw_Thick_Line(end, next, 3, color); // RA2: as above
-			if (techno->GetMegaMission() == MISSION_ATTACK_MOVE && Cursor_Start_Frame_77() != -1) { // RA2: as above
-				Planning_Draw_Midpoint(end, next, color); // RA2: as above
-			}
-			Planning_Draw_Dot(next, color); // RA2: as above
+		Planning_Draw_Dot(center, color); // RA2: as above
+		Planning_Draw_Thick_Line(center, action, 3, color); // RA2: as above
+		int frame = (mega_mission && !attack_move) ? Planning_Mega_Frame(techno) : Planning_Guard_Frame(techno); // RA2: as above
+		if (frame != -1) Planning_Draw_Midpoint(center, action, color); // RA2: as above
+		Planning_Draw_Dot(action, color); // RA2: as above
+		if (attack_move) { // RA2: as above
+			Coord attack_coord = techno->GetAttackMoveCoords(); // RA2: as above
+			Point2D dest = Planning_Coord_Pixel(attack_coord); // RA2: as above
+			Planning_Draw_Thick_Line(action, dest, 3, color); // RA2: as above
+			frame = Planning_Mega_Frame(techno); // RA2: as above
+			if (frame != -1) Planning_Draw_Midpoint(action, dest, color); // RA2: as above
+			Planning_Draw_Dot(dest, color); // RA2: as above
 			return; // RA2: as above
 		}
-		if (!flags.has_nodes) { // RA2: as above
-			return; // RA2: as above
-		}
-		start = end; // RA2: as above
-		thickness = 3; // RA2: as above
-	} else if (!flags.has_nodes) { // RA2: as above
+		if (!has_nodes) return; // RA2: as above
+		source = action; // RA2: as above
+		width = 3; // RA2: as above
+	} else if (!has_nodes) { // RA2: as above
 		return; // RA2: as above
 	}
-	{
-		PlanningNodeClass * node = token->Node_At(0); // RA2: as above
-		Point2D end = node->Lead_Pixel(); // RA2: as above
-		PlanningBranchClass * branch = node->Branch_Of(techno); // RA2: as above
-		if (branch != NULL) { // RA2: as above
-			end = Planning_Event_Pixel(&branch->Event, techno); // RA2: as above
-		}
-		Planning_Draw_Dot(start, color); // RA2: as above
-		Planning_Draw_Thick_Line(start, end, thickness, color); // RA2: as above
-		if (branch != NULL) { // RA2: as above
-			Planning_Draw_Dot(end, color); // RA2: as above
-		}
-		EventClass event = node->Get_Event_For(techno); // RA2: as above
-		if (((PlanningFirstTarget const &)event).Get_Event_Frame() != -1) { // RA2: as above
-			Planning_Draw_Midpoint(start, end, color); // RA2: as above
-		}
-	}
+
+	PlanningNodeClass * node = token->Node_At(0); // RA2: as above
+	Point2D target = node->Lead_Pixel(); // RA2: as above
+	PlanningBranchClass * branch = node->Branch_Of(techno); // RA2: as above
+	if (branch) target = Planning_Event_Pixel(&branch->Event, techno); // RA2: as above
+	Planning_Draw_Dot(source, color); // RA2: as above
+	Planning_Draw_Thick_Line(source, target, width, color); // RA2: as above
+	if (branch) Planning_Draw_Dot(target, color); // RA2: as above
+	int frame = Planned_Waypoint_Frame(node->Get_Event_For(techno)); // RA2: as above
+	if (frame != -1) Planning_Draw_Midpoint(source, target, color); // RA2: as above
 }
```

## 2. Our matched form against the community form

```diff
--- community
+++ ours matched
@@ -9,5 +9,5 @@
 	int color = Planning_Techno_Color(techno); // RA2: as above
 	bool has_nodes = Has_Planned_Nodes(token); // RA2: as above
-	bool draw_action = Should_Draw_Active_Action(techno, has_nodes); // RA2: as above
+	bool draw_action = Planning_Current_Order(techno, has_nodes); // RA2: as above
 	int width = 4; // RA2: as above
 	if (token && token->Owner_Is_Mission()) { // RA2: as above
@@ -17,5 +17,5 @@
 		Planning_Draw_Dot(center, color); // RA2: as above
 		Planning_Draw_Thick_Line(center, target, 3, color); // RA2: as above
-		int frame = packet.Get_Event_Frame(); // RA2: as above
+		int frame = ((PlanningFirstTarget const &)packet).Get_Event_Frame(); // RA2: as above
 		if (frame != -1) Planning_Draw_Midpoint(center, target, color); // RA2: as above
 		Planning_Draw_Dot(target, color); // RA2: as above
```

## 3. Our failed form against the community form

```diff
--- ours before
+++ community
@@ -1,81 +1,64 @@
-void __fastcall Planning_Draw_Techno(TechnoClass * techno) // RA2: 0x006182F0; draws the order a techno follows now and the first node of its path as outlines
+void __fastcall Planning_Draw_Techno(TechnoClass * techno) // RA2: 0x006182F0; draws the path of a techno: the order under way, the current action and the line to the first node; ra2-decomp's whole twin text (Yuri's Revenge 0x0063B550, the separate source point included), the popped order copied with = and the frame read through RA2's member
 {
-	// level-2 1.001: forms adopted from meastes/redalert2-decomp src/recovered/planmgr.cpp @613e28e4e0
-	// (GPL-3.0-or-later; 1.006 0x006182F0; the same shape as gibbo101/ra2-decomp src/planmgr.cpp
-	// FUN_0063B550 @721d81e44f): the current-order test is the helper inline, the order target is a
-	// coordinate of its own, the midpoint frame is tested here and the first node is drawn in a block.
 	PlanningTokenClass * token = techno->Get_Planning_Token(); // RA2: as above
-	Coord here = techno->As_Coord(); // RA2: as above
-	Point2D start = Planning_Coord_Pixel(here); // RA2: as above
+	Coord origin = techno->As_Coord(); // RA2: as above
+	Point2D center = Planning_Coord_Pixel(origin); // RA2: as above
+	Point2D source; // RA2: as above
+	source.X = center.X; // RA2: as above
+	source.Y = center.Y; // RA2: as above
 	int color = Planning_Techno_Color(techno); // RA2: as above
-	struct {
-		bool has_nodes;
-		bool move;
-	} flags;
-	flags.has_nodes = (token == NULL ? 0 : token->PlanningNodes.Count()) > 0; // RA2: as above
-	bool current = Planning_Current_Order(techno, flags.has_nodes); // RA2: as above
-	int thickness = 4; // RA2: as above
-	if (token != NULL && token->Owner_Is_Mission()) { // RA2: as above
-		EventClass event = token->Popped; // RA2: as above
-		Coord target = Planning_Event_Or_Object_Coord(event, techno); // RA2: as above
-		Point2D end = Planning_Coord_Pixel(target); // RA2: as above
-		Planning_Draw_Dot(start, color); // RA2: as above
-		Planning_Draw_Thick_Line(start, end, 3, color); // RA2: as above
-		if (((PlanningFirstTarget const &)event).Get_Event_Frame() != -1) { // RA2: as above
-			Planning_Draw_Midpoint(start, end, color); // RA2: as above
-		}
-		Planning_Draw_Dot(end, color); // RA2: as above
+	bool has_nodes = Has_Planned_Nodes(token); // RA2: as above
+	bool draw_action = Should_Draw_Active_Action(techno, has_nodes); // RA2: as above
+	int width = 4; // RA2: as above
+	if (token && token->Owner_Is_Mission()) { // RA2: as above
+		EventClass packet = token->Popped; // RA2: as above
+		Coord coord = Planning_Event_Or_Object_Coord(packet, techno); // RA2: as above
+		Point2D target = Planning_Coord_Pixel(coord); // RA2: as above
+		Planning_Draw_Dot(center, color); // RA2: as above
+		Planning_Draw_Thick_Line(center, target, 3, color); // RA2: as above
+		int frame = packet.Get_Event_Frame(); // RA2: as above
+		if (frame != -1) Planning_Draw_Midpoint(center, target, color); // RA2: as above
+		Planning_Draw_Dot(target, color); // RA2: as above
 		return; // RA2: as above
 	}
-	if (current) { // RA2: as above
-		bool mega = techno->HaveMegaMission(); // RA2: as above
-		flags.move = techno->HaveAttackMoveTarget(); // RA2: as above
-		Coord target = techno->GetAttackCoordinates(); // RA2: as above
-		Point2D end = Planning_Coord_Pixel(target); // RA2: as above
+
+	if (draw_action) { // RA2: as above
+		bool mega_mission = techno->HaveMegaMission(); // RA2: as above
+		bool attack_move = techno->HaveAttackMoveTarget(); // RA2: as above
+		Coord coord = techno->GetAttackCoordinates(); // RA2: as above
+		Point2D action = Planning_Coord_Pixel(coord); // RA2: as above
 		if (techno->IsInLimbo) { // RA2: as above
-			Planning_Draw_Dot(end, color); // RA2: as above
+			Planning_Draw_Dot(action, color); // RA2: as above
 			return; // RA2: as above
 		}
-		Planning_Draw_Dot(start, color); // RA2: as above
-		Planning_Draw_Thick_Line(start, end, 3, color); // RA2: as above
-		int frame = (mega && !flags.move) ? Planning_Mega_Frame(techno) : Planning_Guard_Frame(techno); // RA2: as above
-		if (frame != -1) { // RA2: as above
-			Planning_Draw_Midpoint(start, end, color); // RA2: as above
-		}
-		Planning_Draw_Dot(end, color); // RA2: as above
-		if (flags.move) { // RA2: as above
-			Coord next_coord = techno->GetAttackMoveCoords(); // RA2: as above
-			Point2D next = Planning_Coord_Pixel(next_coord); // RA2: as above
-			Planning_Draw_Thick_Line(end, next, 3, color); // RA2: as above
-			if (techno->GetMegaMission() == MISSION_ATTACK_MOVE && Cursor_Start_Frame_77() != -1) { // RA2: as above
-				Planning_Draw_Midpoint(end, next, color); // RA2: as above
-			}
-			Planning_Draw_Dot(next, color); // RA2: as above
+		Planning_Draw_Dot(center, color); // RA2: as above
+		Planning_Draw_Thick_Line(center, action, 3, color); // RA2: as above
+		int frame = (mega_mission && !attack_move) ? Planning_Mega_Frame(techno) : Planning_Guard_Frame(techno); // RA2: as above
+		if (frame != -1) Planning_Draw_Midpoint(center, action, color); // RA2: as above
+		Planning_Draw_Dot(action, color); // RA2: as above
+		if (attack_move) { // RA2: as above
+			Coord attack_coord = techno->GetAttackMoveCoords(); // RA2: as above
+			Point2D dest = Planning_Coord_Pixel(attack_coord); // RA2: as above
+			Planning_Draw_Thick_Line(action, dest, 3, color); // RA2: as above
+			frame = Planning_Mega_Frame(techno); // RA2: as above
+			if (frame != -1) Planning_Draw_Midpoint(action, dest, color); // RA2: as above
+			Planning_Draw_Dot(dest, color); // RA2: as above
 			return; // RA2: as above
 		}
-		if (!flags.has_nodes) { // RA2: as above
-			return; // RA2: as above
-		}
-		start = end; // RA2: as above
-		thickness = 3; // RA2: as above
-	} else if (!flags.has_nodes) { // RA2: as above
+		if (!has_nodes) return; // RA2: as above
+		source = action; // RA2: as above
+		width = 3; // RA2: as above
+	} else if (!has_nodes) { // RA2: as above
 		return; // RA2: as above
 	}
-	{
-		PlanningNodeClass * node = token->Node_At(0); // RA2: as above
-		Point2D end = node->Lead_Pixel(); // RA2: as above
-		PlanningBranchClass * branch = node->Branch_Of(techno); // RA2: as above
-		if (branch != NULL) { // RA2: as above
-			end = Planning_Event_Pixel(&branch->Event, techno); // RA2: as above
-		}
-		Planning_Draw_Dot(start, color); // RA2: as above
-		Planning_Draw_Thick_Line(start, end, thickness, color); // RA2: as above
-		if (branch != NULL) { // RA2: as above
-			Planning_Draw_Dot(end, color); // RA2: as above
-		}
-		EventClass event = node->Get_Event_For(techno); // RA2: as above
-		if (((PlanningFirstTarget const &)event).Get_Event_Frame() != -1) { // RA2: as above
-			Planning_Draw_Midpoint(start, end, color); // RA2: as above
-		}
-	}
+
+	PlanningNodeClass * node = token->Node_At(0); // RA2: as above
+	Point2D target = node->Lead_Pixel(); // RA2: as above
+	PlanningBranchClass * branch = node->Branch_Of(techno); // RA2: as above
+	if (branch) target = Planning_Event_Pixel(&branch->Event, techno); // RA2: as above
+	Planning_Draw_Dot(source, color); // RA2: as above
+	Planning_Draw_Thick_Line(source, target, width, color); // RA2: as above
+	if (branch) Planning_Draw_Dot(target, color); // RA2: as above
+	int frame = Planned_Waypoint_Frame(node->Get_Event_For(techno)); // RA2: as above
+	if (frame != -1) Planning_Draw_Midpoint(source, target, color); // RA2: as above
 }
```
