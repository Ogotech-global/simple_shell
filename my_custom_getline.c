#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 64  /* Initial size for the buffer*/

/**
 * my_getline - Custom function to read lines from a stream
 * @lineptr: Pointer to the buffer storing the line
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: Number of characters read on success, -1 on failure
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int ch;

	if (*lineptr == NULL || *n == 0)
	{
		*n = INITIAL_BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
	if (*lineptr == NULL)
		{
		perror("Memory allocation failed");
		return (-1);
		}
	}

	while ((ch = fgetc(stream)) != EOF && ch != '\n')
	{
	if (pos + 1 >= *n)
	{
		*n *= 2;
		*lineptr = (char *)realloc(*lineptr, *n);
		if (*lineptr == NULL)
		{
		perror("Memory reallocation failed");
			return (-1);
		}
	}

		(*lineptr)[pos++] = (char)ch;
	}

	(*lineptr)[pos] = '\0';

	return (pos);
}

/**
 * main - Entry point of the program
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$: ");
	nread = my_getline(&line, &len, stdin);

	if (nread != -1)
	{
		printf("Read %lu\n characters: %s\n", nread, line);
	}

	free(line);

	return (0);
}

