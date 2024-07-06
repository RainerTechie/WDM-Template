#pragma once
#ifndef PCH_H
#define PCH_H

///////////////////////////////
// LIBRARIES
///////////////////////////////
#ifndef NTDDK_LIB_H
#define NTDDK_LIB_H

#include <ntddk.h>

#endif // !NTDDK_LIB_H

#ifndef KERNEL_LIB
#define KERNEL_LIB

extern "C" NTSTATUS NTAPI IoCreateDriver(_In_opt_ PUNICODE_STRING DriverName, _In_ PDRIVER_INITIALIZE InitializationFunction);

#endif // !KERNEL_LIB_H

///////////////////////////////
// CONSTANTS
///////////////////////////////
const WCHAR DriverName[] =	L"\\Driver\\RainerDriver";
const WCHAR DeviceName[] =	L"\\Device\\RainerDriver";
const WCHAR SymLinkName[] =	L"\\??\\RainerDriver";
#endif // !PCH_H