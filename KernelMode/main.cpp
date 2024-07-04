#define _CRT_SECURE_NO_WARNINGS
#include "driver.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath) {
	if (!pDriverObject) {
		// Normal mode Windows
		return drv::NMDriverEntry();
	}
	else { 
		// Test mode windows
		return drv::TMDriverEntry(pDriverObject, pRegistryPath);
	}
}
