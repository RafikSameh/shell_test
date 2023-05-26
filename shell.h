#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

/**
 * The global variable environment
 */
extern char **environ;

/**
 * struct list_path - containing the PATH of directories
 * @dir: dir in path
 * @p: ptr to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;

/**
 * struct mybuild - pointer to function with corresponding builtin cmd
 * @name: builtin cmd
 * @func: execute the builtin cmd
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

/**
 * Functions
 */
void sig_handler(int sig_num);
void _puts(char *str);
int _putchar(char c);
void _EOF(int len, char *buff);
void _isatty(void);
int _strlen(char *string);
char *_strdup(char *string);
void *my_calloc(unsigned int nitems, unsigned int size);
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **splitstring(char *str, const char *delim);
void execute(char **argv);
void freearv(char **arv);
void free_list(list_path *head);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);
list_path *linkpath(char *path);
list_path *add_node_end(list_path **head, char *str);
void(*checkbuild(char **arv))(char **arv);
char *_which(char *filename, list_path *head);

#endif
