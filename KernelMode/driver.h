#pragma once
#ifndef DRIVER_H
#define DRIVER_H

#include "pch.h"

class drv
{
public:
	static NTSTATUS NMDriverEntry();
	static NTSTATUS TMDriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);
private:
	static VOID DriverUnload(PDRIVER_OBJECT pDriverObject);
	static NTSTATUS InitDriver(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);
};


#endif // !DRIVER_H
