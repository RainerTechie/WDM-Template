#pragma once
#ifndef MENU_H
#define MENU_H

#include "stdafx.h"

class men
{
public:
	static void Run();
private:
	static void ShowMenu();
	static int AskOption();
	static bool DoRequest(int option);
};

#endif // !MENU_H