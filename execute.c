#include "shell.h"

/**
 * execute - executes a command with its arguments
 * @args: array of command arguments (NULL-terminated)
 *
 * Return: exit status of the command
 */
int execute(char **args)
{
	pid_t pid;
	int status;
	char *command_path;

	if (args == NULL || args[0] == NULL)
		return (0);

	command_path = find_path(args[0]);
	if (command_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			perror("execve");
			free(command_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		free(command_path);
		return (1);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(command_path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}
