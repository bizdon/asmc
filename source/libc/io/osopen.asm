include io.inc

	.code

osopen	PROC fname:LPSTR, attrib:SIZE_T, mode:SIZE_T, action:SIZE_T
	mov	ecx,mode
	xor	eax,eax
	.if	ecx == M_RDONLY
		mov eax,SHARE_READ
	.endif
	_osopen( fname, ecx, eax, 0, action, attrib )
	ret
osopen	ENDP

	END