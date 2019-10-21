;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test of the Commander X16 ROM print routine
;; Time-stamp: <2019-10-16 15:57:51 schol-r-lea>

.include "../../src/sys.inc"

; macro to set the origin and executable header
CX16_HEADER

start:
	;; call macro to set ROM bank to Kernal ROM	
 	set_rombank RB::Kernal
	;;  test using the inline string print macro
	

exit:
	rts

hello:	 .asciiz "HELLO, WORLD!"
line:	 .asciiz " GOODBYE, LINE!"
goodbye: .asciiz "GOODBYE, WORLD!"	
