#pragma once
#include <Windows.h>
#include <tlhelp32.h>

namespace mem
{
	DWORD getPID(const wchar_t* processName);
}
