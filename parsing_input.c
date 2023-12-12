#include "shell.h"

/**
 * kash_read_line - Reads a line of input from stdin using getline()
 * Return: A pointer to the input line
 */
char *kash_read_line(void)
{
	char *line = NULL;
	 size_t buflen = 0;

	getline(&line, &buflen, stdin);
	return (line);
}

/**
 * kash_split_line - Divides a string into an array of tokens
 * @line: The input string to be divided
 * Returns: An array of tokens
 */
char **kash_split_line(char *line)
{
	int token_count = 0;
	int array_capacity = 16;
	char **token_array = malloc(array_capacity * sizeof(char *));

	char *delimiters = " \t\r\n";
	char *current_token = strtok(line, delimiters);

	while (current_token != NULL)
	{
	token_array[token_count] = current_token;
	token_count++;

	if (token_count >= array_capacity)
	{
		array_capacity = (int)(array_capacity * 1.5);
		token_array = realloc(token_array, array_capacity * sizeof(char *));
	}

	current_token = strtok(NULL, delimiters);
	}

	token_array[token_count] = NULL;
	return (token_array);
}

