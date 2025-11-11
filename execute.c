#include "shell.h"

/**
 * execute_command - Forks and executes a command.
 * @args: The array of command and arguments.
 * @argv: The main argument vector (for program name).
 * @command_path: The full path to the command to execute.
 * @line: The original line buffer (for freeing on exec error).
 *
 * Return: Void.
 */
void execute_command(char **args, char **argv, char *command_path, char *line)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return;
	}

	if (child_pid == 0)
	{
		/* Child process */
		if (execve(command_path, args, environ) == -1)
		{
			perror(argv[0]);
			if (strcmp(command_path, args[0]) != 0)
				free(command_path);
			free(line);
			exit(1);
		}
	}
	else
	{
		/* Parent process */
		wait(&status);
		if (strcmp(command_path, args[0]) != 0)
			free(command_path);
	}
}
