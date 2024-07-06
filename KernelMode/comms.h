#pragma once
#ifndef COMMS_H
#define COMMS_H

#include "pch.h"

#define IOCTL_HELLOWORLD CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

class com
{
public:
	static NTSTATUS OnCreate(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);
	static NTSTATUS OnClose(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);
	static NTSTATUS OnCleanUp(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);
	static NTSTATUS OnDeviceControl(PDEVICE_OBJECT pDeviceObject, PIRP pIrp);
private:
	static NTSTATUS CompleteRequest(NTSTATUS status, ULONG information, PIRP pIrp);
};


#endif // !COMMS_H