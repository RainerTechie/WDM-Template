#pragma once
#ifndef MESSAGES_H
#define MESSAGES_H

#include "pch.h"

#define DebugMessage(Format, ...) DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, Format, __VA_ARGS__)

#endif // !MESSAGES_H
