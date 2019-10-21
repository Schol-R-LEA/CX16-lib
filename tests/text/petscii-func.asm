;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test of the Commander X16 ROM print routine
;; Time-stamp: <2019-10-16 19:42:59 schol-r-lea>

.include "../../src/sys.inc"
	
; macro to set the origin and executable header
CX16_HEADER

start:
	;; call macro to set ROM bank to Kernal ROM
 	set_rombank RB::BASIC
	jsr petscii
	rts


.proc petscii
	lda CR
	jsr BASOUT
	lda #$40
loop:	
	jsr BASOUT	
	adc #1
	cmp #$7F
	bne loop
exit:
	rts
.endproc
