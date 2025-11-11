#include "shell.h"

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	pid_t child_pid;
	int status;
	char *args[64];
	char *token;
	int i;
	const char *delim = " \t\n";
	char *command_path;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		read_bytes = getline(&line, &len, stdin);

		if (read_bytes == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		if (line[0] == '\0')
			continue;

		i = 0;
		token = strtok(line, delim);
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, delim);
		}
		args[i] = NULL;

		if (args[0] == NULL)
		{
			continue;
		}

		command_path = find_command_path(args[0]);

		if (command_path == NULL)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			continue;
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			continue;
		}

		if (child_pid == 0)
		{
			if (execve(command_path, args, environ) == -1)
			{
				perror(argv[0]);
				free(command_path);
				free(line);
				exit(1);
			}
		}
		else
		{
			wait(&status);
			if (command_path != args[0])
				free(command_path);
		}
	}

	free(line);
	return (0);
}
