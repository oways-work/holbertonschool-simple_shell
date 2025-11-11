#include "shell.h"

/**
 * _atoi - converts string to integer
 * @str: string to convert
 *
 * Return: integer value
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	else if (str[0] == '+')
	{
		i = 1;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}

/**
 * is_number - checks if string is a valid number
 * @str: string to check
 *
 * Return: 1 if number, 0 if not
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL || str[0] == '\0')
		return (0);

	if (str[0] == '-' || str[0] == '+')
		i = 1;

	if (str[i] == '\0')
		return (0);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}
