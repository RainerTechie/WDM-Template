#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "menu.h"
#include "driver.h"

int main() {
	if (drv::LoadDrvResources()) {
		men::Run();
		drv::CleanDrvResources();
	}
	else {
		std::cout << "[-] Could not connect to the driver" << std::endl;
	}
	
	std::cout << "Press enter to exit...";
	std::cin.ignore();
	return 0;
}
