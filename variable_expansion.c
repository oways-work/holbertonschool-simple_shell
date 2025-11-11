#include "shell.h"

/**
 * get_env_value - gets environment variable value
 * @name: variable name
 * @len: length of name
 *
 * Return: value or NULL
 */
char *get_env_value(char *name, int len)
{
	int i = 0;
	char temp[256];

	if (len >= 256)
		return (NULL);

	strncpy(temp, name, len);
	temp[len] = '\0';

	return (_getenv(temp));
}

/**
 * expand_variables - expands variables in a string
 * @line: the line containing variables
 *
 * Return: new string with variables expanded
 */
char *expand_variables(char *line)
{
	char *result, *var_val;
	int i = 0, j = 0, start;
	char pid_str[20], status_str[20];

	result = malloc(4096);
	if (!result)
		return (NULL);

	while (line[i])
	{
		if (line[i] == '$' && line[i + 1])
		{
			i++;
			if (line[i] == '?')
			{
				sprintf(status_str, "%d", last_exit_status);
				strcpy(&result[j], status_str);
				j += strlen(status_str);
				i++;
			}
			else if (line[i] == '$')
			{
				sprintf(pid_str, "%d", getpid());
				strcpy(&result[j], pid_str);
				j += strlen(pid_str);
				i++;
			}
			else if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\0')
			{
				result[j++] = '$';
			}
			else
			{
				start = i;
				while (line[i] && (line[i] == '_' ||
					(line[i] >= 'A' && line[i] <= 'Z') ||
					(line[i] >= 'a' && line[i] <= 'z') ||
					(line[i] >= '0' && line[i] <= '9')))
					i++;

				var_val = get_env_value(&line[start], i - start);
				if (var_val)
				{
					strcpy(&result[j], var_val);
					j += strlen(var_val);
				}
			}
		}
		else
		{
			result[j++] = line[i++];
		}
	}
	result[j] = '\0';
	return (result);
}

/**
 * process_line_variables - processes a line for variable expansion
 * @line: the line to process
 *
 * Return: expanded line (may be same as input if no variables)
 */
char *process_line_variables(char *line)
{
	char *expanded;

	if (!line || !strchr(line, '$'))
		return (line);

	expanded = expand_variables(line);
	if (expanded)
		return (expanded);

	return (line);
}
