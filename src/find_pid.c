#include "./find_pid.h"

int find_pid(const char *proc)
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    //ref: https://cocomelonc.github.io/pentest/2021/09/29/findmyprocess.html
    HANDLE hSnapshot;
    PROCESSENTRY32 pe;
    int pid = 0;
    BOOL hResult;

    // snapshot of all processes in the system
    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnapshot)
        return 0;

    // initializing size: needed for using Process32First
    pe.dwSize = sizeof(PROCESSENTRY32);

    // info about first process encountered in a system snapshot
    hResult = Process32First(hSnapshot, &pe);

    // retrieve information about the processes
    // and exit if unsuccessful
    while (hResult)
    {
        // if we find the process: return process ID
        if (strcmp(proc, pe.szExeFile) == 0)
        {
            pid = pe.th32ProcessID;
            break;
        }
        hResult = Process32Next(hSnapshot, &pe);
    }

    // closes an open handle (CreateToolhelp32Snapshot)
    CloseHandle(hSnapshot);
    return pid;
#else
    char pId[10];

    char command[300];
    snprintf(command, 300, "pidof %s", proc);
    FILE *getPid = popen(command, "r");
    if (getPid == NULL)
    {
        return 0;
    }
    int pIdIndex = 0;
    while (1)
    {
        char c = fgetc(getPid);
        if (feof(getPid))
        {
            break;
        }
        pId[pIdIndex] = c;
        ++pIdIndex;
    }

    pId[pIdIndex] = '\0';
    pclose(getPid);

    return (strtoul(pId, 0L, 10));
#endif
}