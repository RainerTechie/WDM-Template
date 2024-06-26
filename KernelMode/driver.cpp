#define CRT_SECURE_NO_WARNINGS
#include "driver.h"
#include "messages.h"

const WCHAR DRIVER_NAME_STR[] = L"\\Driver\\RainerDriver";

///////////////////////////////
// PUBLIC
///////////////////////////////
/*
* Function: NormalModeDriverEntry
* Description: Entry point for the driver in normal mode. This function is called by the
*   system when the driver is being loaded. It initializes the UNICODE_STRING for the driver
*   name and attempts to create the driver object.
*
* Parameters:
*   PDRIVER_OBJECT pDriverObject - Pointer to the driver object for this instance of the
*     driver. This object is central to most driver operations. Not used directly in this function.
*   PUNICODE_STRING pRegistryPath - Pointer to a Unicode string representing the path to
*     the driver-specific key in the registry. Not used directly in this function.
*
* Returns:
*   NTSTATUS - The status code representing the outcome of the operation. STATUS_SUCCESS if
*     the driver is loaded successfully, STATUS_UNSUCCESSFUL if there was an error during
*     driver creation.
*/
NTSTATUS drv::NormalModeDriverEntry() {
	UNICODE_STRING driverName = {};
	RtlInitUnicodeString(&driverName, DRIVER_NAME_STR);

	if (!NT_SUCCESS(IoCreateDriver(&driverName, &InitDriver))) {
		DebugMessage("[ERROR] NormalModeDriverEntry: Could not create the driver");
		return STATUS_UNSUCCESSFUL;
	}

	DebugMessage("[INFO] Driver loaded");
	return STATUS_SUCCESS;
}
/*
* Function: TestModeDriverEntry
* Description: Serves as the entry point for the driver in test mode. This function performs
*   initial setup and validation by calling the initialization function and sets up the driver
*   in a state ready for operation or testing.
*
* Parameters:
*   PDRIVER_OBJECT pDriverObject - Pointer to the driver object for this instance of the
*     driver. Used for initialization and setup.
*   PUNICODE_STRING pRegistryPath - Pointer to a Unicode string representing the path to
*     the driver-specific key in the registry. Passed to the initialization function.
*
* Returns:
*   NTSTATUS - The status code representing the outcome of the initialization.
*     STATUS_SUCCESS if the initialization was successful, or STATUS_UNSUCCESSFUL if there was
*     an error during initialization.
*/
NTSTATUS drv::TestModeDriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath) {

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
/*
* Function: DriverUnload
* Description: Unload routine for the driver, designed to perform cleanup operations as the
*   driver is being unloaded from the system. Ensures that any system resources are properly
*   released and that the driver exits cleanly.
*
* Parameters:
*   PDRIVER_OBJECT pDriverObject - Pointer to the driver object representing the driver
*     being unloaded. Not used in this function, but necessary for compatibility with
*     driver unload routines.
*
* Note:
*   - This function may not be called in typical environments as it is designed for test
*     scenarios, particularly when using non-standard loading mechanisms (kdmapper).
*/
VOID drv::DriverUnload(PDRIVER_OBJECT pDriverObject) {
	UNREFERENCED_PARAMETER(pDriverObject);

	DebugMessage("[INFO] Driver unloaded");
}
/*
* Function: InitDriver
* Description: Initialization routine for the driver. Configures the driver's unload
*   routine and performs any necessary initial setup.
*
* Parameters:
*   PDRIVER_OBJECT pDriverObject - Pointer to the driver object, used here to set the
*     unload routine.
*   PUNICODE_STRING pRegistryPath - Pointer to a Unicode string representing the registry
*     path. Not used directly in this function.
*
* Returns:
*   NTSTATUS - The status code representing the outcome of the configuration.
*     STATUS_SUCCESS if the driver is configured properly.
*/
NTSTATUS drv::InitDriver(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath) {
	UNREFERENCED_PARAMETER(pRegistryPath);

	pDriverObject->DriverUnload = DriverUnload;
	DebugMessage("[INFO] Driver configurated");

	return STATUS_SUCCESS;
}