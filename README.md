The folder will contain all the files and functions required to make a simple shell work

1. The file managing_environ.c includes functions to manage and interact with the shell environment, allowing operations such as printing the environment, retrieving and setting environment variables, and populating the environment linked list.

2. In the file my_atoi.c, the provided code defines utility functions for determining interactive mode, checking if a character is a delimiter, verifying if a character is alphabetic, and converting a string to an integer.

3. In the file my_built_in2.c, The provided code includes functions related to managing command history and aliases. The `_myhistory` function displays the history list, and the `_myalias` function mimics the behavior of the alias builtin. Additionally, there are functions for setting and unsetting aliases, as well as printing alias strings.

4. In the file my_custom_getline.c, The provided code defines a custom `my_getline` function to read lines from a file stream, dynamically allocating memory for the buffer. The `main` function demonstrates the usage of this custom getline function by reading a line from the standard input. The program then prints the number of characters read and the content of the line. The code also ensures proper memory allocation and reallocation.

5. In the file shell.c, The provided code defines a simple shell that displays a prompt, reads commands from the user, and executes them in child processes. It uses the `fork()` and `execve()` system calls to create a new process and execute the specified command. The shell continues to run until the user enters "exit" or presses Ctrl+D. The `display_prompt` function prints the shell prompt, and the `execute_command` function handles the execution of commands.

6. In the file tokenization.c, The provided code defines a simple program that takes user input, tokenizes it, and prints each token. The `tokenizeCommand` function uses the `strtok` function to split the input line into tokens based on specified delimiters (space, tab, and newline). The main function repeatedly prompts the user for input until the user enters "exit.
