;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Minimal Commander X16 library
;; Time-stamp: <2019-10-17 10:21:25 schol-r-lea>

.include "sys.inc"

.import parsehex
	
.export newline
.export printsz
.export printhex
        
.proc newline
        lda #CR
        jsr BASOUT
        rts
.endproc


;;  print a null-delimited string
.proc printsz
        stx x_tmp       ; starting string index
        jmp test
loop:
        jsr BASOUT      ; print character
        iny             ; increment index
test:   
        lda x_tmp,y    ; get a character
        bne loop        ; if not end of string, print   
        
exit:
        rts             ; exit

x_tmp: .byte 0
y_tmp: .byte 0
.endproc        

.proc printhex
	jsr parsehex
	txa
	jsr BASOUT
skip_leading_zero:
	tya
	jsr BASOUT
	rts
.endproc
