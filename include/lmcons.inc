ifndef NETCONS_INCLUDED
NETCONS_INCLUDED equ <>

NET_API_STATUS		typedef DWORD

CNLEN			equ 15
LM20_CNLEN		equ 15
DNLEN			equ CNLEN
LM20_DNLEN		equ LM20_CNLEN

if (CNLEN NE DNLEN)
.err <CNLEN and DNLEN are not equal>
endif

UNCLEN			equ (CNLEN+2)
LM20_UNCLEN		equ (LM20_CNLEN+2)
NNLEN			equ 80
LM20_NNLEN		equ 12
RMLEN			equ (UNCLEN+1+NNLEN)
LM20_RMLEN		equ (LM20_UNCLEN+1+LM20_NNLEN)
SNLEN			equ 80
LM20_SNLEN		equ 15
STXTLEN			equ 256
LM20_STXTLEN		equ 63
PATHLEN			equ 256
LM20_PATHLEN		equ 256
DEVLEN			equ 80
LM20_DEVLEN		equ 8
EVLEN			equ 16
UNLEN			equ 256
LM20_UNLEN		equ 20
GNLEN			equ UNLEN
LM20_GNLEN		equ LM20_UNLEN
PWLEN			equ 256
LM20_PWLEN		equ 14
SHPWLEN			equ 8
CLTYPE_LEN		equ 12
MAXCOMMENTSZ		equ 256
LM20_MAXCOMMENTSZ	equ 48

QNLEN			equ NNLEN
LM20_QNLEN		equ LM20_NNLEN
if (QNLEN NE NNLEN)
.err <QNLEN and NNLEN are not equal>
endif

ALERTSZ			equ 128
MAXDEVENTRIES		equ (sizeof(SINT)*8)
NETBIOS_NAME_LEN	equ 16
MAX_PREFERRED_LENGTH	equ (-1)
CRYPT_KEY_LEN		equ 7
CRYPT_TXT_LEN		equ 8
ENCRYPTED_PWLEN		equ 16
SESSION_PWLEN		equ 24
SESSION_CRYPT_KLEN	equ 21

ifndef PARMNUM_ALL
PARMNUM_ALL		equ 0
endif

PARM_ERROR_UNKNOWN	equ (-1)
PARM_ERROR_NONE		equ 0
PARMNUM_BASE_INFOLEVEL	equ 1000

if defined( _WIN32_WINNT ) OR defined( WINNT ) OR defined( __midl ) OR defined( FORCE_UNICODE )
LMSTR			equ <LPWSTR>
LMCSTR			equ <LPCWSTR>
else
LMSTR			equ <LPSTR>
LMCSTR			equ <LPCSTR>
endif

MESSAGE_FILENAME	equ <"NETMSG">
OS2MSG_FILENAME		equ <"BASE">
HELP_MSG_FILENAME	equ <"NETH">
BACKUP_MSG_FILENAME	equ <"BAK.MSG">

ifndef NULL
NULL			equ 0
endif

PLATFORM_ID_DOS		equ 300
PLATFORM_ID_OS2		equ 400
PLATFORM_ID_NT		equ 500
PLATFORM_ID_OSF		equ 600
PLATFORM_ID_VMS		equ 700

MIN_LANMAN_MESSAGE_ID	equ NERR_BASE
MAX_LANMAN_MESSAGE_ID	equ 5899

endif ;; NETCONS_INCLUDED