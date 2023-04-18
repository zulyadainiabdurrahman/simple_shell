#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>

extern char **environ;
char *strtok(char *str, const char *delim);
int execve(const char *filename, char *const argv[], char *const envp[]);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
pid_t fork(void);
pid_t waitpid(pid_t pid, int *status, int options);
void free(void *ptr);
void simple_shell(void);










#endif
