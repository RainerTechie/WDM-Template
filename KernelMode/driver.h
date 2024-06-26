#pragma once
#ifndef DRIVER_H
#define DRIVER_H

#include "stdafx.h"

class drv
{
public:
	static NTSTATUS NormalModeDriverEntry();
	static NTSTATUS TestModeDriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);
private:
	static VOID DriverUnload(PDRIVER_OBJECT pDriverObject);
	static NTSTATUS InitDriver(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);
};


#endif // !DRIVER_H
