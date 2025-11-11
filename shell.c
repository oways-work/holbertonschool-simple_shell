#include "shell.h"

/**
 * shell_loop - runs the shell loop for interactive mode
 */
void shell_loop(void)
{
	char *line, *expanded;
	char **args;
	int status = 1;
	int builtin_status;

	while (status)
	{
		printf("($) ");
		fflush(stdout);
		line = read_line();
		if (line == NULL)
			break;

		remove_comment(line);
		expanded = process_line_variables(line);
		args = split_line(expanded);

		if (args[0] != NULL)
		{
			builtin_status = check_builtin(args);
			if (builtin_status <= -2)
			{
				last_exit_status = -2 - builtin_status;
				if (expanded != line)
					free(expanded);
				free_args(args);
				break;
			}
			else if (builtin_status == -1)
			{
				if (expanded != line)
					free(expanded);
				free_args(args);
				break;
			}
			else if (builtin_status == 0)
			{
				last_exit_status = execute(args);
			}
		}

		if (expanded != line)
			free(expanded);
		free_args(args);
	}
}

/**
 * read_line - reads input from stdin
 * Return: pointer to line string or NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t read;

	read = getline(&line, &bufsize, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			free(line);
			return (NULL);
		}
		else
		{
			perror("readline");
			free(line);
			exit(1);
		}
	}

	return (line);
}

/**
 * split_line - splits a line into tokens
 * @line: input string
 * Return: array of tokens
 */
char **split_line(char *line)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[i++] = token;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("allocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;
	return (tokens);
}
