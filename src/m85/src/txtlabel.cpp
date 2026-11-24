/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2025 Electronic Arts Inc.
 * Copyright 2026 OpenTS contributors
 *
 * Contains material derived from Electronic Arts source code.
 * Modified by OpenTS contributors, 2026.
 * EA's GPLv3 Section 7 additional terms and supplemental warranty
 * disclaimers apply; see LICENSE.md.
 ******************************************************************************/

/* $Header: /CounterStrike/TXTLABEL.CPP 1     3/03/97 10:26a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : TXTLABEL.H                                                   *
 *                                                                                             *
 *                   Programmer : Bill Randolph                                                *
 *                                                                                             *
 *                   Start Date : 02/06/95                                                     *
 *                                                                                             *
 *                  Last Update : February 6, 1995 [BR]                                        *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   TextLableClass::Draw_Me -- Graphical update routine                                       *
 *   TextLableClass::TextLabelClass -- Constructor                                             *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "txtlabel.h"

#include "_surface.h"
#include "bitfont.h"
#include "dialog.h"
#include "dsurface.h"
#include "_rules.h"
#include "rules.h"
#include "scheme.h"
#include "vector.h"
#include "voc.h"
#include <mmsystem.h>

#include "color.hh"

// level-2 1.001: the label is drawn by OwnerDraw::Draw_Edit_Text (0x5F84D0, defined in ownrdraw.cpp), declared here as ownrdraw.cpp declares it
namespace OwnerDraw { void __fastcall Draw_Edit_Text(Surface *surface, Rect &rect, wchar_t const *text, int caret, BitFont *font, unsigned int color, int *scroll, int ime, int password, int frame, int unknown9); }


/***********************************************************************************************
 * TextLableClass::TextLabelClass -- Constructor                                               *
 *                                                                                             *
 * INPUT:                                                                                      *
 *      txt         pointer to text buffer to print from                                       *
 *      x            x-coord for text printing                                                 *
 *      y            y-coord for text printing                                                 *
 *      color         color to print in                                                        *
 *      style         style to print (determines the meaning of x & y)                         *
 *                                                                                             *
 * OUTPUT:                                                                                     *
 *      none.                                                                                  *
 *                                                                                             *
 * WARNINGS:                                                                                   *
 *      none.                                                                                  *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   03/24/1995 BRR : Created.                                                                 *
 *=============================================================================================*/
TextLabelClass::TextLabelClass(wchar_t *txt, int x, int y, int color, TextPrintType style) :
	BASECLASS(x, y, 1, 1, 0, 0),
	Text(txt),
	Color(color),
	Style(style),
	UserData1(0),
	UserData2(0),
	PixWidth(-1),
	FirstChar(0),
	SkipDraw(false),
	Animate(false),
	AnimPos(0),
	AnimTiming(0)
{

}


/***********************************************************************************************
 * TextLableClass::Draw_Me -- Graphical update routine                                         *
 *                                                                                             *
 * INPUT:                                                                                      *
 *      forced      true = draw regardless of the current redraw flag state                    *
 *                                                                                             *
 * OUTPUT:                                                                                     *
 *      true = gadget was redrawn, false = wasn't                                              *
 *                                                                                             *
 * WARNINGS:                                                                                   *
 *      none.                                                                                  *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   03/24/1995 BRR : Created.                                                                 *
 *=============================================================================================*/
int TextLabelClass::Draw_Me(int forced)
{
	/*
	**	RA2: the label is clipped to the right edge of the screen and drawn as a text field;
	**	when animated, the text is typed out one character every 16 milliseconds with a sound.
	*/
	if (!SkipDraw && BASECLASS::Draw_Me(forced)) {
		int color = Color; // level-2 1.001: the color is read before the scheme count is tested
		if (ColorSchemes.Count() != 0) {
			if (color <= 0 || color >= ColorSchemes.Count()) color = 0;
			ColorScheme * scheme = ColorSchemes[color];
			if (scheme != NULL) {
				BitFont * font = Font_From_TPF(Style);
				Rect rect;
				rect.X = X;
				rect.Y = Y;
				int width = PixWidth; // level-2 1.001: the width is worked out in a local and stored once
				if (width < 0) width = LogicalSurface->Get_Width();
				rect.Width = width;
				rect.Height = font->LineHeight;
				int overhang = rect.X + rect.Width - LogicalSurface->Get_Width();
				if (overhang > 0) {
					rect.Width -= overhang;
				}
				if (overhang <= 0 || rect.Is_Valid()) {
					RGBClass rgb = scheme->HSV;
					int textcolor = (((rgb.Get_Blue() << 8) | rgb.Get_Green()) << 8) | rgb.Get_Red();
					int len = wcslen(Text);

					if (Animate) {
						unsigned time = timeGetTime();
						int oldpos = AnimPos;
						if (oldpos == 0) {
							AnimPos = 1;
						} else {
							AnimPos = (time - AnimTiming) / 16 + oldpos;
						}
						AnimTiming = time; // level-2 1.001: stored unconditionally (1.006 stores it only when the position moved)
						if (AnimPos <= len) {
							VocClass::PlayGlobal(Rule->MessageCharTyped, 1.0f, 0x2000);
						}
					}

					OwnerDraw::Draw_Edit_Text(LogicalSurface, rect, Text, len, font, textcolor, &FirstChar, Has_Focus(), 0, 1, AnimPos); // level-2 1.001: Draw_Edit_Text instead of 1.006 Draw_Text_Field
					return(true);
				}
			}
		}
	}
	return(false);
}
