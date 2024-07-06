#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include "driver.h"

///////////////////////////////
// PUBLIC
///////////////////////////////
void men::Run() {
    int option = -1;
    do {
        ShowMenu();
        option = AskOption();
        if (!DoRequest(option)) {
            std::cout << "[-] An error occurred while carrying out menu option: " << option << std::endl;
            std::cout << "[-] Please, press Enter to come back to the menu";
            std::cin.ignore();
            std::cin.get();
        }
    } while (option != 0);
}

///////////////////////////////
// PRIVATE
///////////////////////////////
void men::ShowMenu() {
    system("cls");

    std::cout << "============================" << std::endl;
    std::cout << "      RAINER USER MODE      " << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "0 - Exit                    " << std::endl;
    std::cout << "1 - Hello World             " << std::endl;
}
int men::AskOption() {
    int option;

    std::cout << "Choose an option: ";
    std::cin >> option;

    if (std::cin.fail() || option < 0 || option > 1) {
        option = -1;
    }

    return option;
}
bool men::DoRequest(int option) {
    bool state = true;

    switch (option)
    {
    case 1:
        if (!drv::DoRequest(IOCTL_HELLOWORLD))
            state = false;
        break;
    }

    return state;
}