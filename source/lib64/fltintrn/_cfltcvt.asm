; _CFLTCVT.ASM--
;
; Copyright (c) The Asmc Contributors. All rights reserved.
; Consult your license regarding permissions and restrictions.
;
; _cfltcvt() - Converts double to string
;
include fltintrn.inc
include quadmath.inc

    .code

_cfltcvt proc d:ptr real8, buffer:LPSTR, ch_type:SINT, precision:SINT, flags:SINT

  local q:REAL16

    mov rcx,__cvtsd_q(&q, rcx)
    _cqcvt(rcx, buffer, ch_type, precision, flags)
    ret

_cfltcvt endp

    END
