#define _CRT_SECURE_NO_WARNINGS
#include "driver.h"
#include "messages.h"
#include "comms.h"

///////////////////////////////
// PUBLIC
///////////////////////////////
NTSTATUS drv::NMDriverEntry() {
	UNICODE_STRING driverName = {};
	RtlInitUnicodeString(&driverName, DriverName);

	NTSTATUS status = IoCreateDriver(&driverName, &InitDriver);
	if (!NT_SUCCESS(status)) {
		DebugMessage(ERROR "Could not create the driver in NM, error: 0x%08X", status);
		return STATUS_UNSUCCESSFUL;
	}

	DebugMessage(INFORMATION "Driver created successfully in NM");
	return STATUS_SUCCESS;
}
NTSTATUS drv::TMDriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath) {
	// DriverName is the compiled .sys file name for Windows test mode
	NTSTATUS status = InitDriver(pDriverObject, pRegistryPath);
	if (!NT_SUCCESS(status)) {
		DebugMessage(ERROR "Could not create the driver in TM, error: 0x%08X", status);
		return STATUS_UNSUCCESSFUL;
	}

	DebugMessage(INFORMATION "Driver created successfully in TM");
	return STATUS_SUCCESS;
}

///////////////////////////////
// PRIVATE
///////////////////////////////
VOID drv::DriverUnload(PDRIVER_OBJECT pDriverObject) {
	UNICODE_STRING _symLinkName = RTL_CONSTANT_STRING(SymLinkName);
	IoDeleteSymbolicLink(&_symLinkName);
	IoDeleteDevice(pDriverObject->DeviceObject);

	DebugMessage(INFORMATION "Driver Unloaded");
}
NTSTATUS drv::InitDriver(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath) {
	UNREFERENCED_PARAMETER(pRegistryPath);

	// Driver Unload routine configuration
	pDriverObject->DriverUnload = DriverUnload;

	// Driver IRP_MJ routines configuration
	pDriverObject->MajorFunction[IRP_MJ_CREATE] = com::OnCreate;
	pDriverObject->MajorFunction[IRP_MJ_CLOSE] = com::OnClose;
	pDriverObject->MajorFunction[IRP_MJ_CLEANUP] = com::OnCleanUp;
	pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = com::OnDeviceControl;

	// Driver Device creation
	UNICODE_STRING _deviceName = RTL_CONSTANT_STRING(DeviceName);
	PDEVICE_OBJECT pDeviceObject = NULL;
	NTSTATUS status = IoCreateDevice(pDriverObject, 0, &_deviceName, FILE_DEVICE_UNKNOWN, 0, FALSE, &pDeviceObject);
	if (!NT_SUCCESS(status)) {
		DebugMessage(ERROR "Error creating device, error: 0x%0X0", status);
		return status;
	}

	// Driver SymLink creation
	UNICODE_STRING _symLinkName = RTL_CONSTANT_STRING(SymLinkName);
	status = IoCreateSymbolicLink(&_symLinkName, &_deviceName);
	if (!NT_SUCCESS(status)) {
		DebugMessage(ERROR "Error creating symLink, error: 0x%0X0", status);

		IoDeleteDevice(pDeviceObject);
		return status;
	}

	return STATUS_SUCCESS;
}
