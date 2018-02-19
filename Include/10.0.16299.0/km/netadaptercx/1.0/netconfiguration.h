/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    NetConfiguration.h

Abstract:

    This is the interfaces for the Net Adapter Configuration

Environment:

    kernel mode only

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _NETCONFIGURATION_H_
#define _NETCONFIGURATION_H_

#ifndef WDF_EXTERN_C
  #ifdef __cplusplus
    #define WDF_EXTERN_C       extern "C"
    #define WDF_EXTERN_C_START extern "C" {
    #define WDF_EXTERN_C_END   }
  #else
    #define WDF_EXTERN_C
    #define WDF_EXTERN_C_START
    #define WDF_EXTERN_C_END
  #endif
#endif

WDF_EXTERN_C_START



typedef enum _NET_CONFIGURATION_QUERY_ULONG_FLAGS {
    // No Special Flags
    // 
    NET_CONFIGURATION_QUERY_ULONG_NO_FLAGS = 0x00000000,
    // 
    // This flag indicates that the ULONG may be stored in the configuration
    // database as a string in hex format.
    // 
    NET_CONFIGURATION_QUERY_ULONG_MAY_BE_STORED_AS_HEX_STRING = 0x00000001,
} NET_CONFIGURATION_QUERY_ULONG_FLAGS;


//
// NET Function: NetConfigurationClose
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
VOID
(*PFN_NETCONFIGURATIONCLOSE)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
VOID
FORCEINLINE
NetConfigurationClose(
    _In_
    NETCONFIGURATION Configuration
    )
{
    ((PFN_NETCONFIGURATIONCLOSE) NetFunctions[NetConfigurationCloseTableIndex])(NetDriverGlobals, Configuration);
}

//
// NET Function: NetConfigurationOpenSubConfiguration
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONOPENSUBCONFIGURATION)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING SubConfigurationName,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES SubConfigurationAttributes,
    _Out_
    NETCONFIGURATION* SubConfiguration
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationOpenSubConfiguration(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING SubConfigurationName,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES SubConfigurationAttributes,
    _Out_
    NETCONFIGURATION* SubConfiguration
    )
{
    return ((PFN_NETCONFIGURATIONOPENSUBCONFIGURATION) NetFunctions[NetConfigurationOpenSubConfigurationTableIndex])(NetDriverGlobals, Configuration, SubConfigurationName, SubConfigurationAttributes, SubConfiguration);
}

//
// NET Function: NetConfigurationQueryUlong
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONQUERYULONG)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    NET_CONFIGURATION_QUERY_ULONG_FLAGS Flags,
    _In_
    PCUNICODE_STRING ValueName,
    _Out_
    PULONG Value
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationQueryUlong(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    NET_CONFIGURATION_QUERY_ULONG_FLAGS Flags,
    _In_
    PCUNICODE_STRING ValueName,
    _Out_
    PULONG Value
    )
{
    return ((PFN_NETCONFIGURATIONQUERYULONG) NetFunctions[NetConfigurationQueryUlongTableIndex])(NetDriverGlobals, Configuration, Flags, ValueName, Value);
}

//
// NET Function: NetConfigurationQueryString
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONQUERYSTRING)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES StringAttributes,
    _Out_
    WDFSTRING* WdfString
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationQueryString(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES StringAttributes,
    _Out_
    WDFSTRING* WdfString
    )
{
    return ((PFN_NETCONFIGURATIONQUERYSTRING) NetFunctions[NetConfigurationQueryStringTableIndex])(NetDriverGlobals, Configuration, ValueName, StringAttributes, WdfString);
}

//
// NET Function: NetConfigurationQueryMultiString
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONQUERYMULTISTRING)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES StringsAttributes,
    _Inout_
    WDFCOLLECTION Collection
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationQueryMultiString(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES StringsAttributes,
    _Inout_
    WDFCOLLECTION Collection
    )
{
    return ((PFN_NETCONFIGURATIONQUERYMULTISTRING) NetFunctions[NetConfigurationQueryMultiStringTableIndex])(NetDriverGlobals, Configuration, ValueName, StringsAttributes, Collection);
}

//
// NET Function: NetConfigurationQueryBinary
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONQUERYBINARY)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_
    _Strict_type_match_
    POOL_TYPE PoolType,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES MemoryAttributes,
    _Out_
    WDFMEMORY* Memory
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationQueryBinary(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_
    _Strict_type_match_
    POOL_TYPE PoolType,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES MemoryAttributes,
    _Out_
    WDFMEMORY* Memory
    )
{
    return ((PFN_NETCONFIGURATIONQUERYBINARY) NetFunctions[NetConfigurationQueryBinaryTableIndex])(NetDriverGlobals, Configuration, ValueName, PoolType, MemoryAttributes, Memory);
}

//
// NET Function: NetConfigurationQueryNetworkAddress
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONQUERYNETWORKADDRESS)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    ULONG BufferLength,
    _Out_writes_bytes_to_(BufferLength, *ResultLength)
    PVOID NetworkAddressBuffer,
    _Out_
    PULONG ResultLength
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationQueryNetworkAddress(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    ULONG BufferLength,
    _Out_writes_bytes_to_(BufferLength, *ResultLength)
    PVOID NetworkAddressBuffer,
    _Out_
    PULONG ResultLength
    )
{
    return ((PFN_NETCONFIGURATIONQUERYNETWORKADDRESS) NetFunctions[NetConfigurationQueryNetworkAddressTableIndex])(NetDriverGlobals, Configuration, BufferLength, NetworkAddressBuffer, ResultLength);
}

//
// NET Function: NetConfigurationAssignUlong
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONASSIGNULONG)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_
    ULONG Value
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationAssignUlong(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_
    ULONG Value
    )
{
    return ((PFN_NETCONFIGURATIONASSIGNULONG) NetFunctions[NetConfigurationAssignUlongTableIndex])(NetDriverGlobals, Configuration, ValueName, Value);
}

//
// NET Function: NetConfigurationAssignUnicodeString
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONASSIGNUNICODESTRING)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_
    PCUNICODE_STRING Value
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationAssignUnicodeString(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_
    PCUNICODE_STRING Value
    )
{
    return ((PFN_NETCONFIGURATIONASSIGNUNICODESTRING) NetFunctions[NetConfigurationAssignUnicodeStringTableIndex])(NetDriverGlobals, Configuration, ValueName, Value);
}

//
// NET Function: NetConfigurationAssignMultiString
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONASSIGNMULTISTRING)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_
    WDFCOLLECTION Collection
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationAssignMultiString(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_
    WDFCOLLECTION Collection
    )
{
    return ((PFN_NETCONFIGURATIONASSIGNMULTISTRING) NetFunctions[NetConfigurationAssignMultiStringTableIndex])(NetDriverGlobals, Configuration, ValueName, Collection);
}

//
// NET Function: NetConfigurationAssignBinary
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(*PFN_NETCONFIGURATIONASSIGNBINARY)(
    _In_
    PNET_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_reads_bytes_(BufferLength)
    PVOID Buffer,
    _In_
    ULONG BufferLength
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
FORCEINLINE
NetConfigurationAssignBinary(
    _In_
    NETCONFIGURATION Configuration,
    _In_
    PCUNICODE_STRING ValueName,
    _In_reads_bytes_(BufferLength)
    PVOID Buffer,
    _In_
    ULONG BufferLength
    )
{
    return ((PFN_NETCONFIGURATIONASSIGNBINARY) NetFunctions[NetConfigurationAssignBinaryTableIndex])(NetDriverGlobals, Configuration, ValueName, Buffer, BufferLength);
}



WDF_EXTERN_C_END

#endif // _NETCONFIGURATION_H_
