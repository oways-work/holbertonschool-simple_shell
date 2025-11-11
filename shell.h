#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* Global environment variable */
extern char **environ;

/* === Main Functions === */
void execute_command(char **args, char **argv, char *command_path, char *line);

/* === Built-in Functions (builtins.c) === */
int handle_builtin(char **args, char *line);
void print_env(void);

/* === Environment Helpers (env_helpers.c) === */
char *_getenv(const char *name);

/* === Path Finder (find_path.c) === */
char *find_command_path(char *command);

/* === String Helpers (string_helpers.c) === */
char *_strdup(const char *str);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);

#endif /* _SHELL_H_ */