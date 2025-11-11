#include "shell.h"

int last_exit_status = 0;

/**
 * main - Entry point for simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: exit status
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	int builtin_status;

	(void)argc;
	(void)argv;
	setup_signal_handlers();

	if (isatty(STDIN_FILENO))
	{
		shell_loop();
	}
	else
	{
		while (getline(&line, &len, stdin) != -1)
		{
			remove_comment(line);
			args = split_line(line);
			if (args[0] != NULL)
			{
				builtin_status = check_builtin(args);
				if (builtin_status <= -2)
				{
					last_exit_status = -2 - builtin_status;
					free_args(args);
					break;
				}
				else if (builtin_status == -1)
				{
					free_args(args);
					break;
				}
				else if (builtin_status == 0)
				{
					last_exit_status = execute(args);
				}
			}
			free_args(args);
		}
		free(line);
	}

	return (last_exit_status);
}
