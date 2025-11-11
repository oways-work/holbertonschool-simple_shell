#include "shell.h"

/**
 * search_path_dirs - Searches directories in PATH for a command.
 * @command: The command to find.
 * @path_copy: A writable copy of the PATH string.
 *
 * Return: Full path to the command if found, NULL otherwise.
 */
static char *search_path_dirs(char *command, char *path_copy)
{
	char *dir, *full_path;

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
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
 * find_command_path - Finds the full path of a command in the PATH.
 * @command: The command to find (e.g., "ls").
 *
 * Return: A pointer to the full path, or NULL if not found.
 */
char *find_command_path(char *command)
{
	char *path_env, *path_copy;

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (command);
		return (NULL);
	}

	path_env = _getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	path_copy = _strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	return (search_path_dirs(command, path_copy));
}
