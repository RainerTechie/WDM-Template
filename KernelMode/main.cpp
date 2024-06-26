#define CRT_SECURE_NO_WARNINGS
#include "driver.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath) {
	if (!pDriverObject) {
		// Normal mode Windows
		return drv::NormalModeDriverEntry();
	}
	else { 
		// Test mode windows
		return drv::TestModeDriverEntry(pDriverObject, pRegistryPath);
	}
}