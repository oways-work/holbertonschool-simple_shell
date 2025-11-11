#include "shell.h"

/**
 * builtin_env - prints the current environment
 *
 * Return: 0 on success
 */
int builtin_env(void)
{
	int i = 0;

	if (environ == NULL)
		return (1);

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}

/**
 * builtin_exit - exits the shell with optional status
 * @args: array of arguments
 *
 * Return: -2 to signal exit with custom status, -1 for normal exit
 */
int builtin_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		if (status < 0)
			status = 2;
	}

	return (-2 - status);
}

/**
 * check_builtin - checks if command is a builtin and executes it
 * @args: array of command arguments
 *
 * Return: exit status, -1 for normal exit, -2-status for exit with status,
 *         1 if builtin executed, 0 if not a builtin
 */
int check_builtin(char **args)
{
	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "env") == 0)
	{
		builtin_env();
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
		return (builtin_exit(args));

	if (strcmp(args[0], "setenv") == 0)
	{
		builtin_setenv(args);
		return (1);
	}

	if (strcmp(args[0], "unsetenv") == 0)
	{
		builtin_unsetenv(args);
		return (1);
	}

	if (strcmp(args[0], "cd") == 0)
	{
		builtin_cd(args);
		return (1);
	}

	if (strcmp(args[0], "help") == 0)
	{
		builtin_help(args);
		return (1);
	}

	return (0);
}
