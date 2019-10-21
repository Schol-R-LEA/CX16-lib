;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test of the Commander X16 hexidecimal print routine
;; Time-stamp: <2019-10-17 10:20:48 schol-r-lea>

.include "../../src/sys.inc"
.include "../../src/math.inc"	

.import printhex
	
 CX16_HEADER
	
start:
	;; call macro to set ROM bank to Kernal ROM	
 	set_rombank RB::Kernal	
	lda #0
next:
	pha
	jsr printhex
	lda #$20
	jsr BASOUT
	pla
	adc #1
	bcc next
exit:	
	rts
