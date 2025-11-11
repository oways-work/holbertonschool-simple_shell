#include "shell.h"

/**
 * find_command_path - Finds the full path of a command in the PATH.
 * @command: The command to find (e.g., "ls").
 *
 * Return: A dynamically allocated string containing the full path
 * if found, or NULL if not found.
 */
char *find_command_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;
	struct stat st;

	/* If command is a path (e.g., /bin/ls), check it directly */
	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (_strdup(command));
		return (NULL);
	}

	/* Get the PATH environment variable */
	path_env = _getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	path_copy = _strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	/* Tokenize the PATH copy */
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		/* Allocate space for dir + / + command + \0 */
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		/* Construct the full path */
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		/* Check if this full path exists and is executable */
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
