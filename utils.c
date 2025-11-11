#include "shell.h"

/**
 * _getenv - gets environment variable value
 * @name: name of the environment variable
 *
 * Return: value of the environment variable or NULL
 */
char *_getenv(char *name)
{
	int i = 0, j;
	char *value;

	if (!name || !environ)
		return (NULL);

	while (environ[i])
	{
		j = 0;
		while (name[j] && environ[i][j] && name[j] == environ[i][j])
			j++;
		if (name[j] == '\0' && environ[i][j] == '=')
		{
			value = &environ[i][j + 1];
			return (value);
		}
		i++;
	}
	return (NULL);
}

/**
 * build_full_path - builds a full path string
 * @dir: directory name
 * @command: command name
 *
 * Return: malloc’d string containing dir/command or NULL
 */
char *build_full_path(char *dir, char *command)
{
	char *full_path;

	full_path = malloc(strlen(dir) + strlen(command) + 2);
	if (!full_path)
		return (NULL);

	sprintf(full_path, "%s/%s", dir, command);
	return (full_path);
}

/**
 * find_path - finds full path of a command
 * @command: the command to find
 *
 * Return: full path string or NULL if not found
 */
char *find_path(char *command)
{
	char *path, *path_copy, *dir, *full_path;
	struct stat st;

	if (!command)
		return (NULL);

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = _getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = build_full_path(dir, command);
		if (!full_path)
			break;

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
/**
 * free_args - frees the array of arguments
 * @args: array of strings to free
 */
void free_args(char **args)
{
	if (args)
		free(args);
}
