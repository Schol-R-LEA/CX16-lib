;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Minimal Commander X16 library
;; Time-stamp: <2019-09-29 18:58:49 schol-r-lea>

#include "kernal.inc"

;; print a size-delimited string
printss:
	
	
;;  print a null-delimited string
printsz:
        ldy #0          ; starting string index
	bra test
.loop:
        jsr BASOUT      ; print character
        iny		; increment index
.test: 	
	lda x,y         ; get a character
        bne .loop 	; if not end of string, print	
	
.exit:
	rts                   ;exit

.x_tmp: .byte 
.y_tmp: .byte 
	
