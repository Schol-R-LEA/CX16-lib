

;;; =====================================================================
;;; plot_red_5
;;; Commander X16/VERA test program using the ca65 assembler
;;; plots a single red pixel at the screen midpoint
;;; in screen mode 5 on Layer 0
;;; 

VERA_base =  $9f20
        
.struct VERA
    .org $9f20
    .struct Addr
        hi      .byte 
        lo      .byte
    .endstruct
    bank_ctrl   .byte
    .struct data
        bank0   .byte
        bank1   .byte
    .endstruct
    ctrl        .byte
    irq_ctrl    .byte
    irq         .byte
.endstruct      


    
	
	
; default entry point for Commander X16 programs 
.org $0801

        ;; binary executable file header
        .byte $0b,$08,$01,$00,$9e,$32,$30,$36,$31,$00,$00,$00   
        

start:

exit:
	brk
