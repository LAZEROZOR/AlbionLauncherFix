#include "memory.h"

DWORD mem::getPID(const wchar_t* processName)
{
    DWORD pid = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap == INVALID_HANDLE_VALUE)
        return 0;

    PROCESSENTRY32W procEntry;
    procEntry.dwSize = sizeof(procEntry);

    if (Process32FirstW(hSnap, &procEntry))
    {
        do
        {
            if (!_wcsicmp(procEntry.szExeFile, processName))
            {
                pid = procEntry.th32ProcessID;
                break;
            }
        } while (Process32NextW(hSnap, &procEntry));
    }

    CloseHandle(hSnap);
    return pid;
}