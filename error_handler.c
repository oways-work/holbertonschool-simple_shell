#include "shell.h"

/**
 * print_error - prints error message to stderr
 * @program_name: name of the shell program
 * @cmd: command that failed
 * @msg: error message
 *
 * Return: void
 */
void print_error(char *program_name, char *cmd, char *msg)
{
	if (program_name && cmd && msg)
	{
		fprintf(stderr, "%s: 1: %s: %s\n", program_name, cmd, msg);
	}
}

/**
 * get_exit_status - converts status to exit code
 * @status: status from waitpid
 *
 * Return: exit status
 */
int get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}
