;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Macros accompanying a minimal Commander X16 library
;; Time-stamp: <2019-09-30 13:30:25 schol-r-lea>

.include "kernal.inc"

;;; common constants
; Carriage Return and Line Feed 
CR = $0D
LF = $0A

;;; ROM Banks
.enum RB
	BASIC
	GEOS        = $04
	CBDOS
	Keymap	
	Kernal
.endenum


.scope IO
	.scope Audio
	Base        = $9F00
	.endscope
	;; 
	.scope VERA
	Base        = $9F20
	.endscope
	;; 
	.scope VIA
		Ctrl0_Base  = $9F60
	.enum Banks
			Mem = $9F60	
			ROM	
	.endenum
	Ctrl1_Base  = $9F70
	.endscope
	;; 
	.scope RTC
	Base        = $9F80
	.endscope
.endscope
	
;;; Entry point for a standard assembly program
PRG_BASE = $0801
	
.macro CX16_HEADER
	.org PRG_BASE
	.byte $0b,$08,$01,$00,$9e,$32,$30,$36,$31,$00,$00,$00
.endmacro

.macro set_membank bank
	lda bank
	sta IO::VIA::Banks::Mem
.endmacro
	
.macro set_rombank bank
	lda bank
	sta IO::VIA::Banks::ROM	
.endmacro

.macro ISO_mode
	lda #$0F
	jsr BASOUT
.endmacro

.macro PET_mode
	lda #$8F
	jsr BASOUT
.endmacro
	
;;; inline print call using the Kernal BASOUT function
;;; prints the argument, which should be a null-delimited
;;; PETSCII string.
;;; The string gets stored inline within the code itself.

.macro print src
.scope
        ldy #0          ; starting string index
	jmp test	; jump to test, bypassing string

				
str: 	.asciiz src
			; location of the inlined string
	
loop:
        jsr BASOUT      ; print character
        iny		; increment index
test: 	
	lda str, y      ; get a character
        bne loop 	; if not end of string, continue
.endscope
.endmacro	

	
.macro println src
	print src
        lda #CR
	jsr BASOUT
.endmacro	
