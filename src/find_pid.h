#ifndef FIND_PID_H
#define FIND_PID_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <Windows.h>
#include <string.h>
#include <TlHelp32.h>
#else //NOT WINDOWS
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#endif

int find_pid(const char *proc);

#endif //!FIND_PID_H