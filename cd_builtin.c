#include "shell.h"

/**
 * builtin_cd - changes the current directory
 * @args: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int builtin_cd(char **args)
{
	char *dir, *pwd, *oldpwd;
	char cwd[1024];

	if (args[1] == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (1);
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return (1);
		}
		printf("%s\n", dir);
	}
	else
	{
		dir = args[1];
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return (1);
	}

	if (chdir(dir) == -1)
	{
		perror("cd");
		return (1);
	}

	oldpwd = strdup(cwd);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		pwd = strdup(cwd);
	else
		pwd = strdup(dir);

	_setenv("OLDPWD", oldpwd, 1);
	_setenv("PWD", pwd, 1);

	free(oldpwd);
	free(pwd);

	return (0);
}
