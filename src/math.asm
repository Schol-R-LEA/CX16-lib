;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; a minimal Commander X16 math library
;; Time-stamp: <2022-03-18 15:46:36 schol-r-lea>

.include "kernal.inc"
.include "math.inc"
	
.export parsehex8
.export printhex8

;; parsehex8 - convert two hex characters to an integer byte 
.proc parsehex8
        pha
	lsr a
	lsr a
	lsr a
	lsr a
        jsr @parsehex4
        sta Math::ZP_Scratch
        pla
        and #$0F   ; mask the high bits
        jsr @parsehex4
        adc Math::ZP_Scratch
        rts
        
@parsehex4:
        cmp #$0A   ; 
	bpl @letter
	sbc #$30
        rts
@letter:
        sbc #$37
	rts
.endproc


.proc printhex8
        pha	   ; push original A to stack
	lsr a      ; shift off the low bits
	lsr a
	lsr a
	lsr a      ; A = A >> 4
        jsr @printhexdigit4
        pla        ; pull original A back from stack
        and #$0F   ; mask the high bits
        ; implicit tail returm
        
@printhexdigit4:
        cmp #$0A
	bpl @letter
	ora #$30     ; PETSCII numbers: 1=$31, 2=$32, etc.
	bra @print
@letter:
        clc
	adc #$37     ; PETSCII letters: A=$41, B=$42, etc.
     
@print:
        jsr CHROUT
        rts
.endproc


.proc add16
        fp = Math::ZP_Scratch
        tsx
        stx fp
        
        rts
.endproc
