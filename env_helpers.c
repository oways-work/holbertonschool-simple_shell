#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the variable to find (e.g., "PATH").
 *
 * Return: A pointer to the value of the variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t name_len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, name_len) == 0 &&
		    environ[i][name_len] == '=')
		{
			/* Return pointer to the value after the '=' */
			return (environ[i] + name_len + 1);
		}
		i++;
	}
	return (NULL);
}
