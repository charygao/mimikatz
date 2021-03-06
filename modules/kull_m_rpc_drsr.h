/*	Benjamin DELPY `gentilkiwi` ( benjamin@gentilkiwi.com / http://blog.gentilkiwi.com )
	Vincent LE TOUX ( vincent.letoux@gmail.com / http://www.mysmartlogon.com )
	Licence : https://creativecommons.org/licenses/by/4.0/
*/
#pragma once
#include "globals.h"
#include "../modules/kull_m_crypto_system.h"
#include "../modules/kull_m_crypto.h"
#include "kull_m_rpc_ms-drsr.h"
#include "kull_m_string.h"

typedef struct _DRS_EXTENSIONS_INT {
	DWORD cb;
	DWORD dwFlags;
	GUID SiteObjGuid;
	DWORD Pid;
	DWORD dwReplEpoch;
	DWORD dwFlagsExt;
	GUID ConfigObjGUID;
	DWORD dwExtCaps;
} DRS_EXTENSIONS_INT, *PDRS_EXTENSIONS_INT;

typedef struct _ENCRYPTED_PAYLOAD {
	UCHAR Salt[16];
	ULONG CheckSum;
	UCHAR EncryptedData[ANYSIZE_ARRAY];
} ENCRYPTED_PAYLOAD, *PENCRYPTED_PAYLOAD;

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t cBytes);
void __RPC_USER midl_user_free(void __RPC_FAR * p);

#define DRS_EXT_BASE								0x00000001
#define DRS_EXT_ASYNCREPL							0x00000002
#define DRS_EXT_REMOVEAPI							0x00000004
#define DRS_EXT_MOVEREQ_V2							0x00000008
#define DRS_EXT_GETCHG_DEFLATE						0x00000010
#define DRS_EXT_DCINFO_V1							0x00000020
#define DRS_EXT_RESTORE_USN_OPTIMIZATION			0x00000040
#define DRS_EXT_ADDENTRY							0x00000080
#define DRS_EXT_KCC_EXECUTE							0x00000100
#define DRS_EXT_ADDENTRY_V2							0x00000200
#define DRS_EXT_LINKED_VALUE_REPLICATION			0x00000400
#define DRS_EXT_DCINFO_V2							0x00000800
#define DRS_EXT_INSTANCE_TYPE_NOT_REQ_ON_MOD		0x00001000
#define DRS_EXT_CRYPTO_BIND							0x00002000
#define DRS_EXT_GET_REPL_INFO						0x00004000
#define DRS_EXT_STRONG_ENCRYPTION					0x00008000
#define DRS_EXT_DCINFO_VFFFFFFFF					0x00010000
#define DRS_EXT_TRANSITIVE_MEMBERSHIP				0x00020000
#define DRS_EXT_ADD_SID_HISTORY						0x00040000
#define DRS_EXT_POST_BETA3							0x00080000
#define DRS_EXT_GETCHGREQ_V5						0x00100000
#define DRS_EXT_GETMEMBERSHIPS2						0x00200000
#define DRS_EXT_GETCHGREQ_V6						0x00400000
#define DRS_EXT_NONDOMAIN_NCS						0x00800000
#define DRS_EXT_GETCHGREQ_V8						0x01000000
#define DRS_EXT_GETCHGREPLY_V5						0x02000000
#define DRS_EXT_GETCHGREPLY_V6						0x04000000
#define DRS_EXT_WHISTLER_BETA3						0x08000000
#define DRS_EXT_W2K3_DEFLATE						0x10000000
#define DRS_EXT_GETCHGREQ_V10						0x20000000
#define DRS_EXT_RESERVED_FOR_WIN2K_OR_DOTNET_PART2	0x40000000
#define DRS_EXT_RESERVED_FOR_WIN2K_OR_DOTNET_PART3	0x80000000

#define	DRS_EXT_ADAM								0x00000001
#define	DRS_EXT_LH_BETA2							0x00000002
#define	DRS_EXT_RECYCLE_BIN							0x00000004
#define DRS_EXT_GETCHGREPLY_V9						0x00000100
#define DRS_EXT_PAM									0x00000200

#define DRS_ASYNC_OP								0x00000001
#define DRS_GETCHG_CHECK							0x00000002
#define DRS_UPDATE_NOTIFICATION						0x00000002
#define DRS_ADD_REF									0x00000004
#define DRS_SYNC_ALL								0x00000008
#define DRS_DEL_REF									0x00000008
#define DRS_WRIT_REP								0x00000010
#define DRS_INIT_SYNC								0x00000020
#define DRS_PER_SYNC								0x00000040
#define DRS_MAIL_REP								0x00000080
#define DRS_ASYNC_REP								0x00000100
#define DRS_IGNORE_ERROR							0x00000100
#define DRS_TWOWAY_SYNC								0x00000200
#define DRS_CRITICAL_ONLY							0x00000400
#define DRS_GET_ANC									0x00000800
#define DRS_GET_NC_SIZE								0x00001000
#define DRS_LOCAL_ONLY								0x00001000
#define DRS_NONGC_RO_REP							0x00002000
#define DRS_SYNC_BYNAME								0x00004000
#define DRS_REF_OK									0x00004000
#define DRS_FULL_SYNC_NOW							0x00008000
#define DRS_NO_SOURCE								0x00008000
#define DRS_FULL_SYNC_IN_PROGRESS					0x00010000
#define DRS_FULL_SYNC_PACKET						0x00020000
#define DRS_SYNC_REQUEUE							0x00040000
#define DRS_SYNC_URGENT								0x00080000
#define DRS_REF_GCSPN								0x00100000
#define DRS_NO_DISCARD								0x00100000
#define DRS_NEVER_SYNCED							0x00200000
#define DRS_SPECIAL_SECRET_PROCESSING				0x00400000
#define DRS_INIT_SYNC_NOW							0x00800000
#define DRS_PREEMPTED								0x01000000
#define DRS_SYNC_FORCED								0x02000000
#define DRS_DISABLE_AUTO_SYNC						0x04000000
#define DRS_DISABLE_PERIODIC_SYNC					0x08000000
#define DRS_USE_COMPRESSION							0x10000000
#define DRS_NEVER_NOTIFY							0x20000000
#define DRS_SYNC_PAS								0x40000000
#define DRS_GET_ALL_GROUP_MEMBERSHIP				0x80000000

typedef enum {
	DS_UNKNOWN_NAME = 0,
	DS_FQDN_1779_NAME = 1,
	DS_NT4_ACCOUNT_NAME = 2,
	DS_DISPLAY_NAME = 3,
	DS_UNIQUE_ID_NAME = 6,
	DS_CANONICAL_NAME = 7,
	DS_USER_PRINCIPAL_NAME = 8,
	DS_CANONICAL_NAME_EX = 9,
	DS_SERVICE_PRINCIPAL_NAME = 10,
	DS_SID_OR_SID_HISTORY_NAME = 11,
	DS_DNS_DOMAIN_NAME = 12,

	DS_LIST_SITES = -1,
	DS_LIST_SERVERS_IN_SITE = -2,
	DS_LIST_DOMAINS_IN_SITE = -3,
	DS_LIST_SERVERS_FOR_DOMAIN_IN_SITE = -4,
	DS_LIST_INFO_FOR_SERVER = -5,
	DS_LIST_ROLES = -6,
	DS_NT4_ACCOUNT_NAME_SANS_DOMAIN = -7,
	DS_MAP_SCHEMA_GUID = -8,
	DS_LIST_DOMAINS = -9,
	DS_LIST_NCS = -10,
	DS_ALT_SECURITY_IDENTITIES_NAME = -11,
	DS_STRING_SID_NAME = -12,
	DS_LIST_SERVERS_WITH_DCS_IN_SITE = -13,
	DS_USER_PRINCIPAL_NAME_FOR_LOGON = -14,
	DS_LIST_GLOBAL_CATALOG_SERVERS = -15,
	DS_NT4_ACCOUNT_NAME_SANS_DOMAIN_EX = -16,
	DS_USER_PRINCIPAL_NAME_AND_ALTSECID = -17,
} DS_NAME_FORMAT;

typedef enum  { 
	DS_NAME_NO_ERROR = 0,
	DS_NAME_ERROR_RESOLVING = 1,
	DS_NAME_ERROR_NOT_FOUND = 2,
	DS_NAME_ERROR_NOT_UNIQUE = 3,
	DS_NAME_ERROR_NO_MAPPING = 4,
	DS_NAME_ERROR_DOMAIN_ONLY = 5,
	DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING = 6,
	DS_NAME_ERROR_TRUST_REFERRAL = 7
} DS_NAME_ERROR;

typedef enum {
	EXOP_FSMO_REQ_ROLE = 1,
	EXOP_FSMO_REQ_RID_ALLOC = 2,
	EXOP_FSMO_RID_REQ_ROLE = 3,
	EXOP_FSMO_REQ_PDC = 4,
	EXOP_FSMO_ABANDON_ROLE = 5,
	EXOP_REPL_OBJ = 6,
	EXOP_REPL_SECRETS = 7
} EXOP_REQ;

#define ATT_RDN							589825
#define ATT_OBJECT_SID					589970
#define ATT_WHEN_CREATED				131074
#define ATT_WHEN_CHANGED				131075

#define ATT_SAM_ACCOUNT_NAME			590045
#define ATT_USER_PRINCIPAL_NAME			590480
#define ATT_SERVICE_PRINCIPAL_NAME		590595
#define ATT_SID_HISTORY					590433
#define ATT_USER_ACCOUNT_CONTROL		589832
#define ATT_SAM_ACCOUNT_TYPE			590126
#define ATT_LOGON_HOURS					589888
#define ATT_LOGON_WORKSTATION			589889
#define ATT_LAST_LOGON					589876
#define ATT_PWD_LAST_SET				589920
#define ATT_ACCOUNT_EXPIRES				589983
#define ATT_LOCKOUT_TIME				590486

#define ATT_UNICODE_PWD					589914
#define ATT_NT_PWD_HISTORY				589918
#define ATT_DBCS_PWD					589879
#define ATT_LM_PWD_HISTORY				589984
#define ATT_SUPPLEMENTAL_CREDENTIALS	589949

#define ATT_CURRENT_VALUE				589851

#define ATT_TRUST_ATTRIBUTES			590294
#define ATT_TRUST_AUTH_INCOMING			589953
#define ATT_TRUST_AUTH_OUTGOING			589959
#define ATT_TRUST_DIRECTION				589956
#define ATT_TRUST_PARENT				590295
#define ATT_TRUST_PARTNER				589957
#define ATT_TRUST_TYPE					589960

void RPC_ENTRY  kull_m_rpc_drsr_RpcSecurityCallback(void *Context);
BOOL kull_m_rpc_drsr_createBinding(LPCWSTR server, RPC_BINDING_HANDLE *hBinding);
BOOL kull_m_rpc_drsr_deleteBinding(RPC_BINDING_HANDLE *hBinding);

BOOL kull_m_rpc_drsr_getDomainAndUserInfos(RPC_BINDING_HANDLE *hBinding, LPCWSTR ServerName, LPCWSTR Domain, GUID *DomainGUID, LPCWSTR User, LPCWSTR Guid, GUID *UserGuid, DRS_EXTENSIONS_INT *pDrsExtensionsInt);
BOOL kull_m_rpc_drsr_getDCBind(RPC_BINDING_HANDLE *hBinding, GUID *NtdsDsaObjectGuid, DRS_HANDLE *hDrs, DRS_EXTENSIONS_INT *pDrsExtensionsInt);
BOOL kull_m_rpc_drsr_CrackName(DRS_HANDLE hDrs, DS_NAME_FORMAT NameFormat, LPCWSTR Name, DS_NAME_FORMAT FormatWanted, LPWSTR *CrackedName, LPWSTR *CrackedDomain);
BOOL kull_m_rpc_drsr_ProcessGetNCChangesReply(REPLENTINFLIST *objects);
BOOL kull_m_rpc_drsr_ProcessGetNCChangesReply_decrypt(ATTRVAL *val);

#define DRS_EXCEPTION (RpcExceptionCode() != STATUS_ACCESS_VIOLATION) && \
	(RpcExceptionCode() != STATUS_DATATYPE_MISALIGNMENT) && \
	(RpcExceptionCode() != STATUS_PRIVILEGED_INSTRUCTION) && \
	(RpcExceptionCode() != STATUS_ILLEGAL_INSTRUCTION) && \
	(RpcExceptionCode() != STATUS_BREAKPOINT) && \
	(RpcExceptionCode() != STATUS_STACK_OVERFLOW) && \
	(RpcExceptionCode() != STATUS_IN_PAGE_ERROR) && \
	(RpcExceptionCode() != STATUS_ASSERTION_FAILURE) && \
	(RpcExceptionCode() != STATUS_STACK_BUFFER_OVERRUN) && \
	(RpcExceptionCode() != STATUS_GUARD_PAGE_VIOLATION)

void kull_m_rpc_drsr_free_DRS_MSG_DCINFOREPLY_data(DWORD dcOutVersion, DRS_MSG_DCINFOREPLY * reply);
void kull_m_rpc_drsr_free_DRS_MSG_CRACKREPLY_data(DWORD nameCrackOutVersion, DRS_MSG_CRACKREPLY * reply);
void kull_m_rpc_drsr_free_DRS_MSG_GETCHGREPLY_data(DWORD dwOutVersion, DRS_MSG_GETCHGREPLY * reply);