#include "shell.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
	int len = 0;

	if (!s)
		return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - Copies a string.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicate string,
 * or NULL if malloc fails or str is NULL.
 */
char *_strdup(const char *str)
{
	char *dup;
	size_t len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	_strcpy(dup, str);
	return (dup);
}
