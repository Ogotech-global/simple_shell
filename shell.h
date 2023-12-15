#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
#include <string.h>

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'

extern char **environ;

/* Forward declaration for list_t */
struct list_s;

/** 
 * struct info_s - Holds various information needed for shell functions.
 * @argv: Array of strings containing command-line arguments.
 * @argc: Number of command-line arguments.
 * @history: Linked list representing command history.
 * @alias: Linked list representing alias definitions.
 * @status: Exit status of the last executed command.
 * @err_num: Error number for reporting errors.
 * @readfd: File descriptor for reading.
 * @myenv: Pointer to the environment variables.
 * @pid: Process ID of the shell.
 */
typedef struct info_s
{
    char **argv;
    int argc;
    struct list_s *history;
    struct list_s *alias;
    struct list_s *env;
    int status;
    int err_num;
    int readfd;
    char **myenv;
    pid_t pid;
} info_t;

/**
 * struct list_s - Represents a linked list node.
 * @str: String data of the node.
 * @next: Pointer to the next node in the list.
 */
typedef struct list_s
{
    char *str;
    struct list_s *next;
} list_t;

/* Function prototypes */

/* Shell utility functions */
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

/* Shell built-in commands */
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

/* History related functions */
int _myhistory(info_t *info);

/* Alias related functions */
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);

int _print_env(info_t *info);
char *_get_env_value(info_t *info, const char *name);
int _set_env(info_t *info);
int _unset_env(info_t *info);
int _populate_env_list(info_t *info);
void print_list_str(list_t *head);
char *starts_with(const char *str, const char *prefix);
void _eputs(const char *str);
void _unsetenv(info_t *info, const char *name);
int _setenv(info_t *info, const char *name, const char *value);
void add_node_end(list_t **head, const char *str, int type);
char *kash_read_line(void);
char **kash_split_line(char *line);
int print_string_to_fd(char *str, int fd);
int write_char_to_fd(char c, int fd);
int write_char_to_stderr(char c);
void print_string_to_stderr(char *str);




#endif /* SHELL_H */

