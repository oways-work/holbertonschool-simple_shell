#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;
extern int last_exit_status;

/* shell.c */
void shell_loop(void);
char *read_line(void);
char **split_line(char *line);

/* execute.c */
int execute(char **args);

/* utils.c */
char *_getenv(char *name);
char *find_path(char *command);
void free_args(char **args);

/* string_utils.c */
int _atoi(char *str);
int is_number(char *str);

/* builtins.c */
int builtin_env(void);
int builtin_exit(char **args);
int check_builtin(char **args);

/* env_builtins.c */
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
int builtin_setenv(char **args);
int builtin_unsetenv(char **args);

/* cd_builtin.c */
int builtin_cd(char **args);

/* help.c */
int builtin_help(char **args);

/* signal_handler.c */
void sigint_handler(int sig);
void setup_signal_handlers(void);

/* comment_handler.c */
void remove_comment(char *line);

/* variable_expansion.c */
char *expand_variables(char *line);
char *process_line_variables(char *line);

/* error_handler.c */
void print_error(char *program_name, char *cmd, char *msg);
int get_exit_status(int status);

#endif /* SHELL_H */
