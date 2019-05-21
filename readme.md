# Asmc Macro Assembler

### Asmc Macro Assembler Reference
- [Build Environment for Asmc](doc/build/readme.md)
- [Asmc Command-Line Reference](doc/command/readme.md)
- [Asmc Error Messages](doc/error/readme.md)
- [Directives Reference](doc/directive/readme.md)
- [Symbols Reference](doc/symbol/readme.md)
- [Operators Reference](doc/operator/readme.md)

### ChangeLog for Asmc

#### Changes in 2.31 - xx xxx 2019
- renamed .SWITCH NOTEST to [.SWITCH JMP](doc/directive/dot_switch.md)
- added ADC and SBB to mem2mem
- added [.gotosw](doc/directive/dot_gotosw.md)(_n_:_label_)
- removed directive .GOTOSW1, .GOTOSW2, .GOTOSW1
- added switch /nolib - ignore includelib directive
- renamed .CLASSDEF to [.CLASS](doc/directive/dot_class.md)
- removed directive .UNTILAXZ, .UNTILDXZ, .UNTILBXZ
- added [.NEW](doc/directive/dot_new.md) directive
- added reg(...) invocation
- added [MOV|ADD|SUB|OR|XOR|AND|CMP|TEST] mem,mem

#### Changes in 2.30 - 19 Apr 2019
- added .pragma asmc(push/pop)
- removed switch /Xc
- removed option ASMC
- renamed C to CCALL
- renamed TYPE to TYPEOF
- renamed SIZE, LENGTH, HIGH, LOW, THIS, and WIDTH to dot names
- renamed directive NAME, TITLE, PAGE, SUBTITLE, and SUBTTL to dot names
- changed invoke for 64-bit fastcall and vectorcall - args loaded right to left
- removed invoke error for mem-arg - foo([rsi])
- changed invoke arguments for 3,5,6,7 byte types
- fixed bug in invoke for 3 byte struct argument
- added switch /Ge - force stack checking for all funcs

#### Changes in 2.29 - 23 Mar 2019
- added .pragma warning(push)
- added .pragma warning(pop)
- added .pragma(warning(disable: _num_))
- added .pragma comment(lib, "name.lib"[, "name2.lib"])
- removed error "symbol not defined" from undef directive
- changed the @CStr() macro - use .const if in .data seg.
- fixed bug in define(...) macro
- added local names for calls to COM/CLASS members
- added MOVBE
- fixed .for ( [rdx+8] = rax :: )

#### Changes in 2.28 - 3 Oct 2018
- fixed bug bin.c - relative fixup error -- PE4.ASM
- added support for invoke(rdx::rax)
- added VEX-Encoded GPR Instructions
- added support for __int128 params in syscall (System V)
- fixed bug in .COMDEF -- directive error added in 2.28.01..
- added REAL2 in INVOKE as float for syscall, vectorcall, and fastcall
- added REAL2 - binary16 (half)
- fixed bug andpd, andnpd, xorpd, orpd -- m64 not accepted (HSE)
- added operator HIGH64 and LOW64
- fixed bug in System V :vararg
- added option cstack to System V
- fixed bug in System V epilogue -- uses registers error
- added xmm params for System V -- reg64[6] + reg128[8]
- added support for System V in .classdef
- added support for System V in Win-64
- added support for :vararg in System V (Linux)
- added optimization for 64-bit const args -- use 32-bit regs if possible

#### Changes in 2.27 - 31 Jul 2018
- added .switch [notest] [c|pascal] [...]
- removed option switch:notest
- fixed bug in .pragma(init(...))
- fixed bug in syscall 64-bit
- added asmc64
- removed .amd64 and .win64
- added fix for flags (ZERO? || CARRY?) in hll
- fixed bug in using double 0.0 as argument -- asin(0.0)
- allowed support for movq rax,xmm0
- added more support for 32-bit vectorcall
- added vector(16) return values (xmm0)
- fixed bug in float convertion routines
- fixed bug in vectorcall name mangling routines
- added a more portable implementation for class::member proc/proto
- added _if_ [...] defined(_SYM_) [...]
- added command line option /stackalign
- added command line option /autostack
- added command line option /homeparams
- added command line option /Gv for vectorcall
- added vectorcall calling convention
- added .pragma(cref(push, [1|0]))
- added .pragma(cref(pop))
- added REAL16 as xmm parameter
- added `mov rdx,rax` after `mov rdx,p.Proc()` -- missing
- added support for .comdef and .classdef to syscall -- use EDI/RDI
- added RETM for optional Macro Return
- added .pragma(list(push, <1|0>))
- added .pragma(list(pop))
- added support for float const: (2.0 / (1.0 + 3.0))
- added .pragma(pack(push, _alignment_))
- added .pragma(pack(pop))
- added support for externdef pointer:ptr class
- added .COMDEF directive
- added mov reg,0 test for args - convert to xor reg,reg
- removed some unnecessary stack adjustments in 64-bit if LEAVE used
- added use of PROC in struct member declarations
- added .CLASSDEF directive
- added .ENDS directive
- added .PRAGMA directive
- fixed bug in .if[d|w|b] proc() & imm
- added support for Class::Method proto
- added support for Class::Method proc
- added support for Class::Method(...)
- added support for com_ptr[Vtbl].proc_ptr(...)
- added support for com_ptr.proc_ptr(...)
- added support for - assume reg:ptr struct -- [reg].proc_ptr(...)
- added support for [reg].struct.proc_ptr(...)
- added support for struct.proc_ptr(...)
- AVX-512 update

#### Changes in 2.26 - 27 Nov 2017
- added define `__GUI__` if switch -gui used
- added define _UNICODE if switch -ws used
- added switch -assert -- same as .assert:on
- added public label::
- added {sae} {rn-sae} {ru-sae} {rd-sae} {rz-sae}
- added YWORD and ZWORD
- added {1ton} -- AVX512
- added ZMMWORD
- added mask registers k0..k7
- added {k1}{z} writemask for AVX512
- added switch -gui -- subsystem:windows for -pe
- added switch -cui -- subsystem:console for -pe (default)
- added combination of -pe -win64 switches
- added win64 longmode if model not set to -pe
- added win64 fastcall as default if missing model/lang
- added {evex} prefix
- added XMM16..31, YMM16..31, and ZMM registers
- added some changes to the 64-bit switch table
- added `__PE__` = 1 to switch -pe
- fixed bug in label:opcode break -- missing line from list file
- fixed stack-fail by uncommitted stack usage..
- fixed bug in FindResWord() > 8 byte (symbol.asm)
- fixed bug in 64-bit rip-relative relocation

#### Changes in 2.25 - 21 Sep 2017
- fixed bug in 64-bit table-switch
- added UNDEF directive
- added quadruple precision to all float numbers
- fixed bug in list output -- zero
- added .ifc and .ifnc (same as .ifb/.ifnb)
- added const float params to C/STDCALL/PASCAL for REAL10/REAL16
- added REAL16 128-bit quad float
- added switch /pf - Preserve Flags (Epilogue/Invoke)
- fixed bug in float input (tbyte.asm)
- fixed bug in float input (LIBC)
- added [: RSP | RBP | ALIGN | ...] to option win64
- fixed bug in local offset - 64-bit/cstack
- fixed bug in EIP-related offsets in 64-bit
- fixed bug in error output - wrong filename if error in macro

#### Changes in 2.24 - 18 Jun 2017
- fixed bug in win64/elf64 :vararg [reg] argument
- added _LINUX and _WIN64 to switch -elf, -elf64, and -win64
  -elf	 define _LINUX = 1
  -elf64 define _LINUX = 2 + _WIN64 = 1
  -win64 define _WIN64 = 1
- added 64-bit version of SYSCALL (-elf64)
- fixed bug in switch /Fo <file> -- path removed..
- added C source and make files for Linux and win64
- added & as alias for ADDR in proc( &args )
- added option cstack to C calling convention (32-bit)
- added switch -Sp[n] Set segment alignment
- added auto detect UTF-8 header (BOM)
- added to @CStr() - skip .data/.code if already in .data segment
- added to @CStr() - skip return value if @CStr is first token
- fixed bug in codepage:64001 (UTF-8 translation)
- added switch /ws[[=]_codepage_] - default = CP_ACP (0)
- added option codepage:_value_
- fixed bug in label: .while ..
- fixed bug in operator SHR
- fixed sizeof(unicode string)
- fixed bug in [reg + type reg] and [reg + type(reg)]

#### Changes in 2.23 - 10 Apr 2017
- added .win64[: RSP | RBP | ALIGN | NOALIGN | SAVE | NOSAVE | AUTO | NOAUTO | FRAME | NOFRAME]
- added .amd64 and .win64
- fixed bug in quoted file names -- "test".asm
- fixed bug in option:cstack + stackbase:esp
- added (L"Unicode") string macro
- added ("Multi" "Text" "Lines") for quoted strings
- added type check on function calls used as argument
- added convert reg = 0 --> xor reg,reg in .FOR loop
- added =&/=~ to .FOR _initialization_ :: _increment/decrement_
- removed .BREAKxx and CONTxx
- removed .ENDCxx
- added .break(1..n) -- removed .break[1|2|3]
- added .continue(0..n) -- removed .cont[0|1|2|3]
- added ++/--/+=/-= to "initialization" of .FOR loop
- removed "if the first operand is a register" in .FOR loop
- fixed error in proto fastcall :type -- fast32.asm
- fixed switch /zlp -- renamed from /zip
- added assign option to the .for loop inc/dec section:
	.for eax = table: [eax].t_next: eax = [eax].t_next

#### Changes in 2.22 - 11 Feb 2017
- added .FOR[S] [_initialization_] : [_condition_] : [_increment/decrement_]
- added .GOTOSW[1|2|3] [[(_case_val_)] | [.IF _condition_]]
- added .CONT[1|2|3] and .BREAK[1|2|3]
- added .CONT0[1|2|3]
- added .ENDCxx
- added .UNTIL[SB|SW|SD]
- added .WHILE[SB|SW|SD]
- added .UNTIL[B|W|D]
- added .WHILE[B|W|D]
- added .UNTILAXZ, DX, and BX
- added switch /h and /? -- went missing..
- added .BREAKxx, CONTxx, UNTILxx, and WHILExx
- added .IFxx
	.IFA	- if Above
	.IFB	- if Below
	.IFG	- if Greater (signed)
	.IFL	- if Less (signed)
	.IFO	- if Overflow (signed)
	.IFP	- if Parity
	.IFS	- if Signed (signed)
	.IFZ	- if Zero
	.IFNA	- if Not Above
	.IFNB	- if Not Below
	.IFNG	- if Not Greater (signed)
	.IFNL	- if Not Less (signed)
	.IFNO	- if Not Overflow (signed)
	.IFNP	- if No Parity
	.IFNS	- if Not Signed (signed)
	.IFNZ	- if Not Zero
- added Signed compare: .IFS, .IFSB, .IFSW, .IFSB
- extended .IFB/.IFW to 32-bit, .IFB to 16-bit
- added use of proto typedefs in HLL
- fixed bug in switch -D, -I and -Fi used with -I"quoted text"
- added command line switch /ws - Create Unicode strings
- added OPTION WSTRING:[ON|OFF] - Toggle ASCII/Unicode
- disabled asmc-added HLL directives when switch /Xc used
  Note: OPTION ASMC:OFF do not disable these keywords
- fixed bug in .WHILE (eax || edx) && ecx
- fixed bug in .WHILE !(eax || edx) && ecx

#### Changes in 2.21 - 12 Oct 2016
- added .ASSERT directive
- added .IFD to down-size a 64-bit function call return -- .ifd api() == -1
- added .IFW and .IFB -- cmp ax/al, -1
- added .ASSERTD, .ASSERTW, and .ASSERTB
- added OPTION CSTACK (-Cs) to 64-bit
- added OPTION LOOPALIGN:0|1|2|4|8|16
- added OPTION CASEALIGN:0|1|2|4|8|16
- /pe dllimport:_dll_ external proto _no args_ (call) error
   call error A2014: cannot define as public or external : _name_
   invoke handle import prefix ([`__imp_`]_name_), call do not
   if _name_() is dll-import invoke will be used in HLL()
- set OPTION SWITCH:NOTABLE as default
- removed OPTION SWITCH:AUTO
- removed command line switch /swa - Sets jump-table creation to Auto in .SWITCH
- added command line switch /swr - use register [R|E]AX in .SWITCH code
- added OPTION SWITCH:REGAX - use register [R|E]AX in .SWITCH code
- added OPTION SWITCH:NOREGS - use stack in .SWITCH code (default)
- added OPTION SWITCH:NOTEST - skip range test in switch-table jump
- added byte index to switch (64-bit)
- added error A3022: .CASE redefinition : A(val) : B(val)
- fixed bug in environ -- %AsmcDir% accepted as %Asmc%
- fixed bug in inline macro @CStr()

#### Changes in 2.20 - 15 May 2016
- added OPTION SWITCH:[ C | PASCAL | AUTO | TABLE | NOTABLE ]
- added command line switch /swa - Sets jump-table creation to Auto in .SWITCH
- added command line switch /swc - Emulate a C-switch with fall through
- added command line switch /swn - No jump-table creation in .SWITCH
- added command line switch /swp - Emulate a Pascal-switch
- added command line switch /swt - Force jump-table creation in .SWITCH
- added inline macro @CStr( string )
- changed macro @Date to yyyy-mm-dd

#### Changes in 2.19 - 7 Apr 2016
- CreateVariable() does not zero asym.value3264, if equate already exist.
  https://sourceforge.net/p/jwasm/bugs/303/
- fixed bug in _time() function -- day miscalculation
  after Feb the @Date macro failed: 04/05/16 --> 04/07/16

#### Changes in 2.18 - 3 Feb 2016
- corrected encodings for 4 AVX instructions:
  - vpermilpd xmm0, xmm1, 1
  - vpermilpd ymm0, ymm1, 1
  - vpermilps xmm0, xmm1, 1
  - vpermilps ymm0, ymm1, 1

#### Changes in 2.17 - 2 Feb 2016
- fixed command line switch -X -- used lower -x
- added command line switches -0..10[p] -- missing

#### Changes in 2.16 - 25 Jan 2016
- fixed: command line failed with more than 64 arguments.

#### Changes in 2.15 - 28 Nov 2015
- fixed bug in expansion of " \"quoted string\" "
- fixed %OUT directive -- didn't work
- fixed command line switch /D_tmacro_[=_value_] -- didn't work correctly

#### Changes in 2.14 - 16 Oct 2015
- ported some code to assembly and switched to a new C-library
- added .SWITCH, .CASE, .DEFAULT, and .ENDSW
- added switch -Xc: Disable ASMC extensions
  This will disable syntax extensions which aren't supported by JWasm
  Currently these are:
  - Delayed expansion of HLL expression in .WHILE, .ELSEIF, and .CASE
  - Use of procedures in HLL expression and INVOKE
  - Use of procedures without INVOKE
  - Use of "quoted strings" in procedures
- added OPTION ASMC: 0 (default is 1)
- added switch -Cs: C stack: push USER regs first
- added OPTION CSTACK: 1 (default is 0)
- removed use of "quoted strings" outside procedures( "" )

#### Changes in 2.12 - 30 Oct 2014
- Updated version from JWASM 2.12

#### Changes in 2.11 - 10 Sep 2014
- Updated version from JWASM 2.11

#### Changes in 2.10 - 06 Jun 2014
- Updated version from JWASM 2.10
  - added C-string -- invoke printf,"%s\n",eax

#### Changes in 2.09 - 10 Des 2012
- Updated version from JWASM 2.09
  - added label() call in HLL -- .while label() < 1
  - added proc() call in HLL  -- .while proc() < 1
  - added proc( " string " ) in HLL -- .if proc( "string" )
  - added invoke proc,"string"
  - Testing result use TEST REG,REG -- not AND/OR
  - The .UNTILCXZ do not use LOOPx but DEC ECX, JNZ .REPEAT

#### Changes in 2.06 - 15 Des 2011
- Made a modified version of JWASM used as a TASM clone. This was used for
  some DOS tools in WinXP. The changes from JWASM was:
  - Uses full or relative path on source files (as given)
  - Do not convert short file names (DOS) to long file names
  - A switch (-r) is added to compile a directory tree

