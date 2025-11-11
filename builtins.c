#include "shell.h"

/**
 * print_env - Prints the current environment variables.
 *
 * Return: Void.
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * handle_builtin - Checks for and handles built-in commands.
 * @args: The array of command and arguments.
 * @line: The original line buffer (to free on exit).
 * @last_status: The exit status of the previously executed command.
 *
 * Return: 1 if a built-in was handled, 0 otherwise.
 */
int handle_builtin(char **args, char *line, int last_status)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		exit(last_status); /* Exit with the last command's status */
	}

	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	return (0);
}
