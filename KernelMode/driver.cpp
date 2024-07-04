#define CRT_SECURE_NO_WARNINGS
#include "driver.h"
#include "messages.h"

const WCHAR DRIVER_NAME_STR[] = L"\\Driver\\RainerDriver";

///////////////////////////////
// PUBLIC
///////////////////////////////
NTSTATUS drv::NMDriverEntry() {
	UNICODE_STRING driverName = {};
	RtlInitUnicodeString(&driverName, DRIVER_NAME_STR);

	if (!NT_SUCCESS(IoCreateDriver(&driverName, &InitDriver))) {
		DebugMessage("[ERROR] NormalModeDriverEntry: Could not create the driver");
		return STATUS_UNSUCCESSFUL;
	}

	DebugMessage("[INFO] Driver loaded");
	return STATUS_SUCCESS;
}
NTSTATUS drv::TMDriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath) {

	// DriverName is the compiled .sys file name for Windows test mode
	if (!NT_SUCCESS(InitDriver(pDriverObject, pRegistryPath))) {
		DebugMessage("[ERROR] TestModeDriverEntry: Error initializing driver");
		return STATUS_UNSUCCESSFUL;
	}

	DebugMessage("[INFO] Driver loaded (Test mode)");
	return STATUS_SUCCESS;
}

///////////////////////////////
// PRIVATE
///////////////////////////////
VOID drv::DriverUnload(PDRIVER_OBJECT pDriverObject) {
	UNREFERENCED_PARAMETER(pDriverObject);

	DebugMessage("[INFO] Driver unloaded");
}
NTSTATUS drv::InitDriver(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath) {
	UNREFERENCED_PARAMETER(pRegistryPath);

	pDriverObject->DriverUnload = DriverUnload;
	DebugMessage("[INFO] Driver configurated");

	return STATUS_SUCCESS;
}