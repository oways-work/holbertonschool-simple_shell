#include "shell.h"

/**
 * find_command_path - Finds the full path of a command in the PATH.
 * @command: The command to find (e.g., "ls").
 *
 * Return: A pointer to the full path, or NULL if not found.
 * The caller must free this memory if it was dynamically allocated.
 */
char *find_command_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;

	/* If command is already a path (e.g., /bin/ls), check it */
	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (command); /* No need to _strdup, it's from the line */
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
		/* +2 for the '/' and '\0' */
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
			return (full_path); /* This was malloc'd, must be freed later */
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
