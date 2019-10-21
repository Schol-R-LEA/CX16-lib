;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; a minimal Commander X16 math library
;; Time-stamp: <2019-10-17 10:15:14 schol-r-lea>

.include "math.inc"
	
.export parsehex

.proc parsehex
	tay
	lsr a
	lsr a
	lsr a
	lsr a
        cmp #$0A
	bcs letterhi
	adc #$30
	jmp outhi
letterhi:
	adc #$36
outhi:
	tax
findlo:
	tya
	and #$0F
        cmp #$0A
	bcs letterlo
	adc #$30
	jmp outlo
letterlo:
	adc #$36
outlo:
	tay
exit:
	rts
.endproc


.proc add16
        fp = Math::ZP_Scratch
        tsx
        stx fp
     

.endproc
