#include "shell.h"

/**
 * sigint_handler - handles SIGINT (Ctrl+C)
 * @sig: signal number
 *
 * Return: void
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($) ", 5);
}

/**
 * setup_signal_handlers - sets up signal handlers
 *
 * Return: void
 */
void setup_signal_handlers(void)
{
	signal(SIGINT, sigint_handler);
}
