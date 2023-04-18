#ifndef _MAIN_H
#define _MAIN_H
#define MAX_COMMAND_LENGTH 100

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stddef.h>


char *strtok(char *str, const char *delim);
int execve(const char *filename, char *const argv[], char *const envp[]);










#endif
