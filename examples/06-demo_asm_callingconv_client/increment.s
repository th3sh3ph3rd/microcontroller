.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.global incrementU16
incrementU16:
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;   Insert your "Increment uint16" method here    ;;
    ;;                                                 ;;
    ;;   - Parameter 1: low value   (on top of stack)  ;;
    ;;   - Parameter 2: high value  (2nd element)      ;;
    ;;   - Return 1:    low value   (on top of stack)  ;;
    ;;   - Return 2:    high value  (2nd element)      ;;
    ;;                                                 ;;
    ;;   - Example call:                               ;;
    ;;      push    valHigh                            ;;
    ;;      push    valLow                             ;;
    ;;      call    incrementU16                       ;;
    ;;      pop     valLow                             ;;
    ;;      pop     valHigh                            ;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
    
    
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ret

