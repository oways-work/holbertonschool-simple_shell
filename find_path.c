#include "shell.h"

/**
 * find_command_path - Finds the full path of a command in the PATH.
 * @command: The command to find (e.g., "ls").
 *
 * Return: A pointer to the full path, or NULL if not found.
 * The caller must free this memory.
 */
char *find_command_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;

	if (_strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (_strdup(command));
		return (NULL);
	}

	path_env = _getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	path_copy = _strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);

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
