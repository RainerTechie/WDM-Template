#define _CRT_SECURE_NO_WARNINGS
#include "driver.h"

///////////////////////////////
// PUBLIC GLOBALS
///////////////////////////////
HANDLE drv::hDevice;

///////////////////////////////
// PUBLIC
///////////////////////////////
bool drv::LoadDrvResources() {
    hDevice = CreateFileW(SymLinkName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hDevice == INVALID_HANDLE_VALUE) {
        return false;
    }

	return true;
}
void drv::CleanDrvResources() {
    CloseHandle(hDevice);
}
bool drv::DoRequest(ULONG code) {
    bool state = true;

    LPVOID inBuffer = NULL;
    DWORD inBufferSize = 0;
    LPVOID outBuffer = NULL;
    DWORD outBufferSize = 0;
    DWORD bytesReturned = 0;
    LPOVERLAPPED overlapped = NULL;

    switch (code) {
    case IOCTL_HELLOWORLD:
        if (!DeviceIoControl(hDevice, IOCTL_HELLOWORLD, inBuffer, inBufferSize, outBuffer, outBufferSize, &bytesReturned, overlapped))
            state = false;
        break;
    default:
        state = false;
        break;
    }
    
    return state;
}