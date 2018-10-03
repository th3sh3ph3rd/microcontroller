.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.global incrementU16
incrementU16:
    ; Backup memory pointer Z
    push    ZH
    push    ZL
    push    YH
    push    YL
    
    ; Copy stack pointer to memory pointer Z
    in      ZL, SPL
    in      ZH, SPH
    
    adiw    ZL, 4 + 2 + 2
    
    ; read counter
    ld      YH, Z
    ld      YL, -Z
    adiw    YL, 1
    st      Z+, YL
    st      Z,  YH
    
    ; Restore memory pointer Z
    pop     YL
    pop     YH
    pop     ZL
    pop     ZH
    
    ret

