;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Commander X16 ROM functions
;; Time-stamp: <2019-09-29 20:09:12 schol-r-lea>


;;; Commander X16 native ROM routines
MONITOR  = $FF00   	 ; enter monitor
GETJOY   = $FF06 	 ; query joysticks
JSRFAR   = $FF6E	 ; gosub in another bank


;;; C64 compatible ROM routines
;; channel I/O
SETMSG   = $FF90	; set verbosity
READST   = $FFB7 	; return status byte
SETLFSA  = $FFB  	; set LA, FA and SA
SETNAME  = $FFBD	; set filename
OPEN     = $FFC0	; open a channel
CLOSE    = $FFC3	; close a channel
CHKIN    = $FFC6  	; set channel for character input
CHKOUT   = $FFC9	; set channel for character output
CLRCHN   = $FFCC	; restore character I/O to screen/keyboard
BASIN    = $FFCF	; get character
BASOUT   = $FFD2	; write character
LOAD     = $FFD5 	; load a file into memory
SAVE     = $FFD8 	; save a file from memory
CLALL    = $FFE7 	; close all channels

;; peripheral bus
TALK     = $FFB4	; send TALK command
LISTEN   = $FFB1 	; send LISTEN command
UNLSN    = $FFAE 	; send UNLISTEN command
UNTLK    = $FFAB 	; send UNTALK command
IECOUT   = $FFA8 	; send byte to serial bus
IECIN    = $FFA5 	; read byte from serial bus
SETTMO   = $FFA2 	; set timeout  = $FF96  TKSA ; send TALK secondary address
SECOND   = $FF93 	; send LISTEN secondary address

;; memory
MEMBOT   = $FF9C	; read/write address of start of usable RAM
MEMTOP   = $FF99 	; read/write address of end of usable RAM

;; time/date
RDTIM    = $FFDE	; read system clock
SETTIM   = $FFDB 	; write system clock
UDTIM    = $FFEA 	; advance clock

;; misc.
STOP     = $FFE1	; test for STOP key
GETIN    = $FFE4 	; get character from keyboard
SCREEN   = $FFED 	; get the screen resolution
PLOT     = $FFF0 	; read/write cursor position
IOBASE   = $FFF3 	; return start of I/O area


;;; C128 compatible routines
CLOSE_ALL = $FF4A	; close all files on a device
BOOT_CALL = $FF53   	; boot load program from disk [not yet implemented]
LKUPLA    = $FF8D 	; search tables for given LA
LKUPSA    = $FF8A 	; search tables for given SA
SWAPPER   = $FF5F 	; switch between 40 and 80 columns 
PFKEY     = $FF65 	; program a function key [not yet implemented]
FETCH     = $FF74 	; LDA (fetvec),Y from any bank
STASH     = $FF77 	; STA (stavec),Y to any bank
CMPARE    = $FF7A 	; CMP (cmpvec),Y to any bank
PRIMM     = $FF7D 	; print string following the caller’s code
