;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Macros accompanying a minimal Commander X16 system library
;; Time-stamp: <2020-08-17 10:32:48 schol-r-lea>

.ifndef IO__INC
.define IO__INC


.include "kernal.inc"

;;; common constants
; Carriage Return and Line Feed
CR = $0D
LF = $0A


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

.macro ISO_mode
	lda #$0F
	jsr CHROUT
.endmacro

.macro PET_mode
	lda #$8F
	jsr CHROUT
.endmacro
	
;;; inline print call using the Kernal BASOUT function
;;; prints the argument, which should be a null-delimited
;;; PETSCII string.
;;; The string gets stored inline within the code itself.

.macro print src
.scope
    ldy #0          ; starting string index
	jmp test	    ; jump to test, bypassing string


str: 	.asciiz src
	     	     	; location of the inlined string

loop:
    jsr CHROUT      ; print character
    iny		        ; increment index
test:
	lda str, y      ; get a character
    bne loop 	    ; if not end of string, continue
.endscope
.endmacro


.macro println src
	print src
        lda #CR
	jsr CHROUT
.endmacro

.endif