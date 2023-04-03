;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Macros accompanying a minimal Commander X16 system library
;; Time-stamp: <2022-03-16 16:55:31 schol-r-lea>

.ifndef SYS__INC
.define SYS__INC


.include "io.inc"

;;; ROM Banks
.enum RB
	Kernal
	Keyboard
	CBDOS
	GEOS
	BASIC
	Monitor
    CHARSET
.endenum


;;; Entry point for a standard assembly program
PRG_BASE = $0801
PRG_START = $0810


.macro CX16_HEADER
; Assembled code should start at $0801 (where BASIC programs start)
; The real program starts at $0810 = 2064
; $080C - pointer to next line of BASIC code
; 2-byte line number ($000A = 10)

	.org PRG_BASE
	.byte $0b, $08          ; $080C - pointer to next line of BASIC code
        .byte $0A, $00          ; 2-byte line number ($000A = 10)
        .byte $9e               ; SYS BASIC token 
        .byte $32,$30,$36,$34   ; $32="2",$30="0",$36="6",$34="4"
        .byte $00               ; End of Line
        .byte $00,$00           ; 2-byte pointer to next line of BASIC code
			        ; ($0000 = end of program)
        .org PRG_START
.endmacro

.macro set_membank bank
	lda bank
	sta IO::VIA::Banks::Mem
.endmacro


.macro set_rombank bank
	lda bank
	sta IO::VIA::Banks::ROM
.endmacro

.endif