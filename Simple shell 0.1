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
	(void)argc; /* We are not using argc, so we cast it to void */

	/* The main shell loop (Read-Execute-Print-Loop) */
	while (1)
	{
		/* Print prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		/* Read a line from standard input */
		read_bytes = getline(&line, &len, stdin);

		/* Handle "end of file" (Ctrl+D) or read error */
		if (read_bytes == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1); /* Print newline for clarity */
			break; /* Exit the loop */
		}

		/* Remove the newline character from the end of the line */
		line[strcspn(line, "\n")] = '\0';

		/* If the line is empty, just show the prompt again */
		if (line[0] == '\0')
			continue;

		/* Create a child process to execute the command */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork"); /* Handle fork failure */
			continue;
		}

		if (child_pid == 0)
		{
			/* --- This is the Child Process --- */
			char *exec_argv[] = {line, NULL};

			/* Try to execute the command */
			if (execve(line, exec_argv, environ) == -1)
			{
				/* If execve fails, print an error using the shell's name */
				perror(argv[0]);
				free(line); /* Free allocated memory before exiting */
				exit(1); /* Exit child with an error status */
			}
		}
		else
		{
			/* --- This is the Parent Process --- */
			/* Wait for the child process to terminate */
			wait(&status);
		}
	}

	/* Free the buffer allocated by getline */
	free(line);
	return (0);
}
