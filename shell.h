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

/* main.c */
/* (main function) */

/* find_path.c */
char *find_command_path(char *command);

/* env_helpers.c */
char *_getenv(const char *name);

/* string_helpers.c */
char *_strdup(const char *str);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);

/* string_helpers2.c */
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strchr(const char *s, int c);
int _strncmp(const char *s1, const char *s2, size_t n);


#endif /* SHELL_H */
