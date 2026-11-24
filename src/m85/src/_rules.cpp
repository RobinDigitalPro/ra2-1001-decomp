// SPDX-License-Identifier: GPL-3.0-or-later
// New file of the level-2 reconstruction of GAME.EXE 1.001 (not part of upstream mischa85/RedAlert2).
// It defines the global object(s) that the adopted upstream header _rules.h declares; the included headers are
// derived from Electronic Arts source code, EA's GPL Section 7 terms apply (LICENSE.md).
// level-2 1.001: ArtINI 0x821b30 (0xde40/0xded0), UIINI 0x821ba0 (0xdee0/0xdf70), AIINI 0x821ae0 (0xdf80/0xe010), INI_821A20 0x821a20 (0xe020/0xe0b0), ConfigINI 0x821a80 (0xe0c0/0xe150), in the 1.001 initializer order; UIINI and INI_821A20 are not declared by the upstream header

#include "always.h"
#include "ccini.h"
#include "_rules.h"

CCINIClass ArtINI;
CCINIClass UIINI;
CCINIClass AIINI;
CCINIClass INI_821A20;
CCINIClass ConfigINI;
