#include "shell.h"

/**
 * print_help_exit - prints help for exit command
 */
void print_help_exit(void)
{
	printf("exit: exit [n]\n");
	printf("    Exit the shell.\n\n");
	printf("    Exits the shell with a status of N. ");
	printf("If N is omitted, the exit status\n");
	printf("    is 0 (success).\n");
}

/**
 * print_help_env - prints help for env command
 */
void print_help_env(void)
{
	printf("env: env\n");
	printf("    Print the environment.\n\n");
	printf("    The env command displays all environment variables.\n");
}

/**
 * print_help_help - prints help for help command
 */
void print_help_help(void)
{
	printf("help: help [BUILTIN]\n");
	printf("    Display information about builtin commands.\n\n");
	printf("    Displays brief summaries of builtin commands.\n");
}

/**
 * builtin_help - displays help for builtins
 * @args: array of arguments
 *
 * Return: 0 on success
 */
int builtin_help(char **args)
{
	if (args[1] == NULL)
	{
		printf("Simple Shell - Available builtins:\n");
		printf("  exit [n]     Exit the shell with optional status\n");
		printf("  env          Display environment variables\n");
		printf("  help [cmd]   Display help for builtin commands\n");
		printf("\nUse 'help [command]' for more information.\n");
		return (0);
	}

	if (strcmp(args[1], "exit") == 0)
		print_help_exit();
	else if (strcmp(args[1], "env") == 0)
		print_help_env();
	else if (strcmp(args[1], "help") == 0)
		print_help_help();
	else
		printf("help: no help topics match '%s'\n", args[1]);

	return (0);
}
