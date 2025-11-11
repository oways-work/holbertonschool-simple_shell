#include "shell.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to append.
 *
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = _strlen(dest);
	int i = 0;

	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if strings are equal, otherwise the difference.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to search.
 * @c: The character to find.
 *
 * Return: Pointer to first occurrence of c, or NULL if not found.
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/**
 * _strncmp - Compares the first n bytes of two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of bytes to compare.
 *
 * Return: 0 if equal, <0 if s1 < s2, >0 if s1 > s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] == '\0' || s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
