#ifndef _SHELL_H_
#define _SHELL_H_

/*--- Libraries ---*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/*--- Global Variables ---*/
/**
 * extern char **environ - The global environment variables.
 * This is necessary for passing the environment to execve.
 */
extern char **environ;

#endif /* _SHELL_H_ */
