#include "shell.h"

/**
 * print_string_to_stderr - Prints an input string to standard error.
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */
void print_string_to_stderr(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		write_char_to_stderr(str[i]);
		i++;
	}
}

/**
 * write_char_to_stderr - Writes the character c to standard error.
 * @c: The character to print.
 *
 * Return: On success, 1. On error, -1 is returned, and errno is set appropriately.
 */
int write_char_to_stderr(char c)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buffer, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buffer[i++] = c;

	return (1);
}

/**
 * write_char_to_fd - Writes the character c to the given file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Return: On success, 1. On error, -1 is returned, and errno is set appropriately.
 */
int write_char_to_fd(char c, int fd)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buffer[i++] = c;

	return (1);
}

/**
 * print_string_to_fd - Prints an input string to the specified file descriptor.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters written.
 */
int print_string_to_fd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str)
	{
		i += write_char_to_fd(*str++, fd);
	}

	return (i);
}

