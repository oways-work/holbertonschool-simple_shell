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

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			continue;
		}

		if (child_pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror(argv[0]);
				free(line);
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
	}

	free(line);
	return (0);
}
