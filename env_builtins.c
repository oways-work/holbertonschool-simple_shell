#include "shell.h"

/**
 * _setenv - sets or modifies an environment variable
 * @name: variable name
 * @value: variable value
 * @overwrite: whether to overwrite existing variable
 *
 * Return: 0 on success, -1 on error
 */
int _setenv(char *name, char *value, int overwrite)
{
	char **new_environ, *new_var;
	int i = 0, env_len = 0, name_len;

	if (!name || !value || name[0] == '\0' || strchr(name, '='))
		return (-1);

	name_len = strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			if (!overwrite)
				return (0);
			new_var = malloc(strlen(name) + strlen(value) + 2);
			if (!new_var)
				return (-1);
			sprintf(new_var, "%s=%s", name, value);
			free(environ[i]);
			environ[i] = new_var;
			return (0);
		}
		i++;
	}

	env_len = i;
	new_environ = malloc(sizeof(char *) * (env_len + 2));
	if (!new_environ)
		return (-1);

	for (i = 0; i < env_len; i++)
		new_environ[i] = environ[i];

	new_var = malloc(strlen(name) + strlen(value) + 2);
	if (!new_var)
	{
		free(new_environ);
		return (-1);
	}
	sprintf(new_var, "%s=%s", name, value);
	new_environ[env_len] = new_var;
	new_environ[env_len + 1] = NULL;
	environ = new_environ;
	return (0);
}

/**
 * _unsetenv - removes an environment variable
 * @name: variable name
 *
 * Return: 0 on success, -1 on error
 */
int _unsetenv(char *name)
{
	int i = 0, j, name_len;

	if (!name || name[0] == '\0' || strchr(name, '='))
		return (-1);

	name_len = strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			free(environ[i]);
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
			return (0);
		}
		i++;
	}
	return (0);
}

/**
 * builtin_setenv - setenv builtin command
 * @args: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int builtin_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}

	if (_setenv(args[1], args[2], 1) == -1)
	{
		fprintf(stderr, "setenv: failed to set variable\n");
		return (1);
	}

	return (0);
}

/**
 * builtin_unsetenv - unsetenv builtin command
 * @args: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int builtin_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}

	if (_unsetenv(args[1]) == -1)
	{
		fprintf(stderr, "unsetenv: failed to unset variable\n");
		return (1);
	}

	return (0);
}
