#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

/**
 * tokenizeCommand - Tokenize a command and print each token
 * @input_line: Input line containing the command
 */
void tokenizeCommand(char *input_line)
{
	char string[] = "My name is my name";
	char *token;
	const char *delim = " \t\n"; /* Delimiters include space, tab, and newline*/

	/*To tokenize the input line*/
	token = strtok(input_line, delim);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = strtok(NULL, delim);
	}
}

/**
 * main - Entry point of the program
 * Return: Always 0 (Success)
 */
int main(void)
{
	char input_line[MAX_INPUT_SIZE];

	while (1)
	{
		printf("==> ");
		fgets(input_line, sizeof(input_line), stdin);

		/* Check for the exit condition*/
		if (strcmp(input_line, "exit\n") == 0)
		{
			break;
		}

		/* Tokenize the input command*/
		tokenizeCommand(input_line);
	}

	return (0);
}

