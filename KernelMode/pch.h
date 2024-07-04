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
// https://doxygen.reactos.org/d9/d9f/ntoskrnl_2io_2iomgr_2driver_8c.html#a3b38bafeb96d588a0c1993af7c0e933b
extern "C" NTSTATUS NTAPI IoCreateDriver(_In_opt_ PUNICODE_STRING DriverName, _In_ PDRIVER_INITIALIZE InitializationFunction);
#endif // !KERNEL_LIB_H

///////////////////////////////
// CONSTANTS
///////////////////////////////
extern const WCHAR DRIVER_NAME[];

#endif // !PCH_H