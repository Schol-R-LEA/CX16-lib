;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Test of the Commander X16 ROM print routine
;; Time-stamp: <2019-09-29 22:56:04 schol-r-lea>

.include "sys.inc"

.org $080D
.segment "STARTUP"
.segment "INIT"
.segment "ONCE"
.segment "CODE"


start:
	;; call macro to set ROM bank to Kernal ROM
 	set_rombank RB::Kernal
	;;  test using the inline string print macro
	print "hello, world,"
    println " goodbye, line!"
	println "goodbye, world!"
exit:
	rts

