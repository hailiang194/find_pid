#include <stdio.h>
#include <stdlib.h>
#include "find_pid.h"

int main(int argc, char* argv[]) {
  int pid = 0; // process ID

  pid = find_pid(argv[1]);
  if (pid) 
  {
    printf("PID = %d\n", pid);
  } else
  {
    printf("%s not found", argv[1]);
  }
  return 0;
}