#include "shell.h"

/**
 * _atoi - function that converts a string into an integer
 *@x: ptr to the string
 *Return: int
 */
int _atoi(char *x)
{
	int i = 0, integer = 0, sign = 1;

	while (!((x[i] >= '0') && (x[i] <= '9')) && (x[i] != '\0'))
	{
		if (x[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while ((x[i] >= '0') && (x[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (x[i] - '0'));
		i++;
	}
	return (integer);
}

/**
 * env - prints the current environment
 * @arv: array of arguments
 */
void env(char **arv __attribute__ ((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}

/**
 * exitt - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void exitt(char **arv)
{
	int i = 0, n = 0;

	if (arv[1])
	{
		n = _atoi(arv[1]);
		if (n <= -1)
			n = 2;
		freearv(arv);
		exit(n); /* exit with this exact status */
	}
	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
	exit(0);
}

/**
* checkbuild - checks if the command is a builtin command
* @arv: array of arguments
* Return: pointer to function
*/
void(*checkbuild(char **arv))(char **arv)
{
	int i = 0, j = 0;

	mybuild T[] = {
		{"exit", exitt},
		{"env", env},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		if (T[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (T[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (T[i].func);
		}
	}
	return (0);
}
