;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Commander X16
;; Declarations and macros for operating on the VERA video system
;; Time-stamp: <2022-03-15 02:07:25 schol-r-lea>

.scope VERA
    ; zero-page space for saving statuses during operations
    ZP_Scratch = $F0    ; reserved ZP mem for sratch

    Reg_Base = $9F20
    .enum Video
        ADDRx_L = Reg_Base
        ADDRx_M
        ADDRx_H
        DATA0
        DATA1
        CTRL
        IEN
        ISR
        IRQLINE_L
        DC_VIDEO
        DC_HSCALE
        DC_VSCALE
        DC_BORDER
        L0_CONFIG
        L0_MAPBASE
        L0_TILEBASE
        L0_HSCROLL_L
        L0_HSCROLL_H
        L0_VSCROLL_L
        L0_VSCROLL_H
        L1_CONFIG
        L1_MAPBASE
        L1_TILEBASE
        L1_HSCROLL_L
        L1_HSCROLL_H
        L1_VSCROLL_L
        L1_VSCROLL_H
    .endenum

    .enum DC_SEL_1
      	DC_HSTART = $9F29
        DC_HSTOP
      	DC_VSTART
        DC_VSTOP
    .endenum


    .enum AUDIO
        CTRL = $9F3B
        RATE
        DATA
        SPI_DATA
        SPI_CTRL
    .endenum

    .enum VRAM_ctrl
        VRAM_base
        VRAM_top = $1F9BF
        PSG_regs = $1F9C0
        pallette_base  = $1FA00
        sprite_attribs = $1FC00
    .endenum
    
    .enum Composer_Data
        pallete = 1
        layer0
        layer2
        sprite_ctrl
        sprite_data
    .endenum

    .enum Sprite_masks
        mode    = $80
        h_flip  = $01
        v_flip  = $02
        z-depth = $0C
        collisions = $F0
        height  = $30
        width   = $C0
        palette_offset = $0F
    .endenum
    
    .struct Sprite
        lo_address    .byte
        hi_addr_mode  .byte
        X_lo          .byte
        X_hi          .byte
        Y_lo          .byte
        Y_hi          .byte
        masks         .byte
        size_palette  .byte
    .endstruct

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
