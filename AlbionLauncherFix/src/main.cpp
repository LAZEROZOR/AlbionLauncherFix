#include "../core/memory/memory.h"

void fixLauncher()
{
	DWORD pid = mem::getPID(L"AlbionLauncher.exe");
	if (!pid) return;
	DWORD QtWebEngineProcessPID = mem::getPID(L"QtWebEngineProcess.exe");
	if (!QtWebEngineProcessPID) return;
	HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, QtWebEngineProcessPID);
	TerminateProcess(hProc, 0);
	return;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	while (true)
	{
		fixLauncher();
		Sleep(1000);
	}

	return 1;
}