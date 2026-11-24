;******************************************************************************
;* SPDX-License-Identifier: GPL-3.0-or-later
;* Level-2 reconstruction for RA2 GAME.EXE 1.001 (the upstream gibbo101/ra2-decomp src/ has no copy of
;* this HMI SOS ADPCM include file). The values are those of GAME.EXE 1.001 .data: the soscodec copy
;* at VA 0x812b94 and the identical vqa_sos copy at VA 0x816d10.
;******************************************************************************

; Nybble tables: low and high nybble of each byte, pre-shifted for the index lookup.
bNybbleTableLow	LABEL	BYTE
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh
		DB	000h, 002h, 004h, 006h, 008h, 00Ah, 00Ch, 00Eh, 010h, 012h, 014h, 016h, 018h, 01Ah, 01Ch, 01Eh

bNybbleTableHigh	LABEL	BYTE
		DB	000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
		DB	002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h, 002h
		DB	004h, 004h, 004h, 004h, 004h, 004h, 004h, 004h, 004h, 004h, 004h, 004h, 004h, 004h, 004h, 004h
		DB	006h, 006h, 006h, 006h, 006h, 006h, 006h, 006h, 006h, 006h, 006h, 006h, 006h, 006h, 006h, 006h
		DB	008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h, 008h
		DB	00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah, 00Ah
		DB	00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch, 00Ch
		DB	00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh, 00Eh
		DB	010h, 010h, 010h, 010h, 010h, 010h, 010h, 010h, 010h, 010h, 010h, 010h, 010h, 010h, 010h, 010h
		DB	012h, 012h, 012h, 012h, 012h, 012h, 012h, 012h, 012h, 012h, 012h, 012h, 012h, 012h, 012h, 012h
		DB	014h, 014h, 014h, 014h, 014h, 014h, 014h, 014h, 014h, 014h, 014h, 014h, 014h, 014h, 014h, 014h
		DB	016h, 016h, 016h, 016h, 016h, 016h, 016h, 016h, 016h, 016h, 016h, 016h, 016h, 016h, 016h, 016h
		DB	018h, 018h, 018h, 018h, 018h, 018h, 018h, 018h, 018h, 018h, 018h, 018h, 018h, 018h, 018h, 018h
		DB	01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah, 01Ah
		DB	01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch, 01Ch
		DB	01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh, 01Eh
