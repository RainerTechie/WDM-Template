#define _CRT_SECURE_NO_WARNINGS
#include "comms.h"
#include "messages.h"

///////////////////////////////
// PUBLIC
///////////////////////////////
NTSTATUS com::OnCreate(PDEVICE_OBJECT pDeviceObject, PIRP pIrp) {
    UNREFERENCED_PARAMETER(pDeviceObject);
    NTSTATUS Status = STATUS_SUCCESS;
    ULONG Information = 0;

    DebugMessage(INFORMATION "IRP_MJ Request: OnCreate");

    return CompleteRequest(Status, Information, pIrp);
}
NTSTATUS com::OnClose(PDEVICE_OBJECT pDeviceObject, PIRP pIrp) {
    UNREFERENCED_PARAMETER(pDeviceObject);
    NTSTATUS Status = STATUS_SUCCESS;
    ULONG Information = 0;

    DebugMessage(INFORMATION "IRP_MJ Request: OnClose");

    return CompleteRequest(Status, Information, pIrp);
}
NTSTATUS com::OnCleanUp(PDEVICE_OBJECT pDeviceObject, PIRP pIrp) {
    UNREFERENCED_PARAMETER(pDeviceObject);
    NTSTATUS Status = STATUS_SUCCESS;
    ULONG Information = 0;

    DebugMessage(INFORMATION "IRP_MJ Request: OnCleanUp");

    return CompleteRequest(Status, Information, pIrp);
}
NTSTATUS com::OnDeviceControl(PDEVICE_OBJECT pDeviceObject, PIRP pIrp) {
    UNREFERENCED_PARAMETER(pDeviceObject);
    PIO_STACK_LOCATION pStack = IoGetCurrentIrpStackLocation(pIrp);
    ULONG ControlCode = pStack->Parameters.DeviceIoControl.IoControlCode;
    NTSTATUS Status = STATUS_SUCCESS;
    ULONG Information = 0;

    switch (ControlCode)
    {
    case IOCTL_HELLOWORLD:
        DebugMessage(INFORMATION "IRP_MJ Request: IOCTL_HELLOWORLD");
        break;
    default:
        DebugMessage(WARNING "IRP_MJ Request: Unknown");
        break;
    }

    return CompleteRequest(Status, Information, pIrp);
}

///////////////////////////////
// PRIVATE
///////////////////////////////
NTSTATUS com::CompleteRequest(NTSTATUS status, ULONG information, PIRP pIrp) {
    pIrp->IoStatus.Status = status;
    pIrp->IoStatus.Information = information;
    IoCompleteRequest(pIrp, IO_NO_INCREMENT);
    return status;
}
