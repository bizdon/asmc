; __CVTQ_LD.ASM--
;
; Copyright (c) The Asmc Contributors. All rights reserved.
; Consult your license regarding permissions and restrictions.
;

include quadmath.inc

    .code

    option win64:rsp nosave noauto

__cvtq_ld proc ld:ptr, q:ptr

    mov     rax,[rdx]
    mov     rdx,[rdx+8]
    shld    r8,rdx,16
    shld    rdx,rax,16

    mov     eax,r8d
    and     eax,LD_EXPMASK
    neg     eax
    mov     rax,rdx
    rcr     rax,1

    ;; round result

    .ifc
        .if rax == -1
            mov rax,0x8000000000000000
            inc r8w
        .else
            add rax,1
        .endif
    .endif

    mov [rcx],rax
    mov [rcx+8],r8w
    ret

__cvtq_ld endp

    end
