ifndef _INC_RTCSUP
_INC_RTCSUP equ <>

ifdef _RTC
ifndef _WIN32
.err <ERROR: Only Win32 target supported!>
endif

include rtcapi.inc

RTCCALLBACK macro a, b
    endm

externdef _RTC_api_change_mutex:ptr

else

RTCCALLBACK macro a, b
    endm

endif
endif
