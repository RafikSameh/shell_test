#include "shell.h"

/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */
char **splitstring(char *str, const char *delim)
{
	int i = 0, wn = 0; /* declared variables */
	char **array = NULL;
	char *token = NULL;
	char *copy = NULL;

	copy = calloc((strlen(str) + 1), 1); /* allocate the space in */
	if (!copy)					/*memory of the string received */
	{
		perror(getenv("_"));
		return (NULL);
	}
	while (str[i]) /* Copy the string received into anothe variable */
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	token = strtok(copy, delim); /* Use the strtok to tokenize the string */
	array = calloc((sizeof(char *)), 1); /* Allocate memory for the array */
	array[0] = _strdup(token); /* Copy the pointer of token into array */

	i = 1; /* index */
	wn = 2; /* variable to reallocate the memory */
	while ((token = strtok(NULL, delim)) != NULL) {
    		array = realloc(array, (sizeof(char *) * wn));
    		array[i] = _strdup(token);
    		i++;
    		wn++;
	}
	free(copy); /* Free allocated memory */
	return (array);
}


/**
 * execute - executes a command
 * @arv: array of arguments
 */
void execute(char **arv)
{
	int d = 0, status; /* declared variables */

	if (!arv || !arv[0])
		return;
	d = fork(); /* fork the process */
	if (d == -1) /* if the fork failed error*/
	{
		perror(getenv("_"));
	}
	if (d == 0) /* if the fork succeeded execute the command */
	{
		execve(arv[0], arv, environ); /* replace the child process */
			perror(arv[0]); /* if the execve failed error and exit*/
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
