#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

char *find_command_path(char *command);
char *_getenv(const char *name);
char *_strdup(const char *s);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(charT *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strchr(const char *s, int c);

#endif /* SHELL_H */
