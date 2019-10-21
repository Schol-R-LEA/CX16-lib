;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Commander X16
;; Declarations and macros for operating on the VERA video system
;; Time-stamp: <2019-10-01 16:57:48 schol-r-lea>

.scope VERA
    ; zero-page space for saving statuses during operations
    ZP_Scratch = $F0    ; reserved ZP mem for sratch

    Reg_Base = $9F20
    .enum Reg
        lo = Reg_Base
        hi
        select
        FB0
        FB1
        toggle
        enable_irq
        irq_flags
    .endenum
    .enum VRAM
        Bank0_Base
        Bank1_Base
        Composer_Base = $0F
    .endenum
    .enum Composer_Data
        pallete = 1
        layer0
        layer2
        sprite_ctrl
        sprite_data
    .endenum

    .macro set_bank bank
        lda Reg::select
        and #($F0 & bank)               ; combine hi nibble with lo nibble const
        sta Reg::select
    .endmacro

    .macro set_stride stride
        lda Reg::select
        and #($0F & (stride << 4))      ; combine lo nibble with hi nibble const
        sta Reg::select
    .endmacro



    .macro init
        
    .endmacro

.endscope