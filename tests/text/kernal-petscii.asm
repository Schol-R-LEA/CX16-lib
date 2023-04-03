;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test of the Commander X16 ROM print routine
;; Time-stamp: <2019-10-16 09:15:55 schol-r-lea>

.include "sys.inc"

.org $080D
.segment "STARTUP"
.segment "INIT"
.segment "ONCE"
.segment "CODE"

start:
	;; call macro to set ROM bank to Kernal ROM
 	set_rombank RB::BASIC
	lda CR
	jsr CHROUT
	lda #$40
loop:
	jsr CHROUT
	adc #1
	cmp #$7F
	bne loop
exit:
	rts
