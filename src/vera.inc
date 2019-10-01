;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Commander X16
;; Declarations and macros for operating on the VERA video system
;; Time-stamp: <2019-09-30 22:49:27 schol-r-lea>

.scope VERA
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
    .enum Composer
        pallete = 1
        layer0
        layer2
        sprite_ctrl
        sprite_data
    .endenum

.macro set_bank bank
    lda Reg::select
    and #($F0 + bank)   ; combine high nibble with low nibble constant
    sta Reg::select
.endmacro


.macro set_stride stride
    lda Reg::select
    and #($0F + (stride << 4)) ; combine low nibble with high nibble constant
    sta Reg::select
.endmacro


.macro compose bank, data
    lda #VRAM::Composer_Base
    lda #bank << 6      ; shift the base constant to the high half-nibble
    ora .high #data     ; put the high nibble of the data into bits 4-6
    ldx .low  #data     
.endmacro

.endscope