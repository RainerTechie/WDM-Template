#pragma once
#ifndef DRIVER_H
#define DRIVER_H

#include "stdafx.h"

const WCHAR SymLinkName[] = L"\\\\.\\RainerDriver";

#define IOCTL_HELLOWORLD CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

class drv
{
public:
	static HANDLE hDevice;

	static bool LoadDrvResources();
	static void CleanDrvResources();
	static bool DoRequest(ULONG code);
private:
};

#endif // !DRIVER_H