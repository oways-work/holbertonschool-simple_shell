#include "shell.h"

/**
 * remove_comment - removes comments from a line
 * @line: the line to process
 *
 * Return: void
 */
void remove_comment(char *line)
{
	int i = 0;

	if (line == NULL)
		return;

	while (line[i])
	{
		if (i == 0 && line[i] == '#')
		{
			line[i] = '\0';
			return;
		}
		if (line[i] == '#' && 
			(line[i - 1] == ' ' || line[i - 1] == '\t' || line[i - 1] == '\n'))
		{
			line[i - 1] = '\0';
			return;
		}
		i++;
	}
}
