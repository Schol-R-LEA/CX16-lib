;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test of the Commander X16 ROM print routine
;; Time-stamp: <2019-10-16 19:37:26 schol-r-lea>

.include "../../src/sys.inc"

.export petscii
	
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
