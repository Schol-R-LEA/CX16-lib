;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test of the Commander X16 ROM print routine
;; Time-stamp: <2019-09-29 22:56:04 schol-r-lea>

.include "../../src/sys.inc"

; macro to set the origin and executable header
CX16_HEADER

start:
	;; call macro to set ROM bank to Kernal ROM	
 	set_rombank RB::Kernal
	;;  test using the inline string print macro
	print "HELLO, WORLD,"
        println " GOODBYE, LINE!"
	println "GOODBYE, WORLD!"
exit:
	rts

