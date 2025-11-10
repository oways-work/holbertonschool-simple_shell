#include "shell.h"

/**
 * main - Entry point for the simple shell.
 * @argc: Argument count (unused for this task).
 * @argv: Argument vector (used for printing the program's name in errors).
 *
 * Return: 0 on success, or 1 on error.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	pid_t child_pid;
	int status;
	(void)argc;
	
	while (1)
	{
		
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

	
		read_bytes = getline(&line, &len, stdin);


		if (read_bytes == -1)
		{
			if (isatty(STDIN_FILENO))
	
			break;
		}

	
		line[strcspn(line, "\n")] = '\0';


		if (line[0] == '\0')
			continue;


		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			continue;
		}

		if (child_pid == 0)
		{

			execve(args[0], args, environ)


			if (execve(line, exec_argv, environ) == -1)
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
