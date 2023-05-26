#include "shell.h"
#include <stdlib.h>
#include <stdint.h>

/**
 * splitstring - splits a string and makes it an array of pointers
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */
char **splitstring(char *str, const char *delim)
{
	int i = 0, wn = 0;
	char **array = NULL;
	char *token = NULL;
	char *copy = NULL;

	copy = my_calloc((_strlen(str) + 1), 1);
	if (!copy)
	{
		perror(getenv("_"));
		return (NULL);
	}
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim);
	array = my_calloc((sizeof(char *)), 1);
	array[0] = _strdup(token);

	i = 1;
	wn = 2;
	while ((token = strtok(NULL, delim)) != NULL)
	{
		array = my_realloc(array,
		(sizeof(char *) * (wn - 1)), (sizeof(char *) * wn));
		array[i] = _strdup(token);
		i++;
		wn++;
	}
	free(copy);
	return (array);
}

/**
 * my_calloc - allocates memory using malloc, and initializes it to zero
 * @size: size of the memory block to be allocated
 * @nitems: number of elements
 *
 * Return: pointer to the address of the memory block
 */
/*void *my_calloc(unsigned int nitems, unsigned int size)
{
	char *block = NULL;
	unsigned int i = 0;

	if (nitems == 0 || size == 0)
		return (NULL);
	block = malloc(nitems * size);
	if (block)
	{
		for (i = 0; i < (nitems * size); i++)
			block[i] = 0;
		return (block);
	}
	else
		return (NULL);
}*/



void *my_calloc(unsigned int nitems, unsigned int size)
{
    void *block = NULL;
    uintmax_t total_size = (uintmax_t)nitems * (uintmax_t)size;

    if (nitems == 0 || size == 0 || total_size > SIZE_MAX)
        return NULL;

    block = malloc(total_size);
    if (block != NULL) {
        memset(block, 0, total_size);
    }
    return block;
}

/**
 * my_realloc - it is a function to reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of pointer
 * @new_size: new size for pointer
 * Return: New resized Pointer
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new = NULL;
	char *old = NULL;

	unsigned int i;

	if (!ptr)
		return (my_calloc(new_size, 1));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	new = my_calloc(new_size, 1);
	old = ptr;
	if (!new)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
 * execute - executes a command
 * @arv: array of arguments
 */
void execute(char **arv)
{
	int d = 0, status;

	if (!arv || !arv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror(getenv("_"));
	}
	if (d == 0)
	{
		execve(arv[0], arv, environ);
			perror(arv[0]);
		exit(EXIT_FAILURE);
	}
	freearv(arv);
	wait(&status);
}

/**
 * freearv - frees the array of pointers arv
 *@arv: array of pointers
 */
void freearv(char **arv)
{
	int i = 0;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
