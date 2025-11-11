#include "shell.h"

/**
 * main - Entry point for the simple shell.
 * @argc: Argument count (unused).
 * @argv: Argument vector (for program name).
 *
 * Return: 0 on successful exit.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	char *args[64];
	char *token, *command_path;
	const char *delim = " \t\n";
	int i, built_in_status;

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
		if (line[0] == '\n')
			continue;
		i = 0;
		token = strtok(line, delim);
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, delim);
		}
		args[i] = NULL;
		if (args[0] == NULL)
			continue;
		built_in_status = handle_builtin(args, line);
		if (built_in_status == 1)
			continue;
		command_path = find_command_path(args[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			continue;
		}
		execute_command(args, argv, command_path, line);
	}
	free(line);
	return (0);
}
