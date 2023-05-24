#include "shell.h"

/**
 * _strdup - duplicate a string to a new pointer
 * @string: pointer to a string
 * Return: pointer to a string
 */
char *_strdup(char *string)
{
	int i = 0, l = 0;
	char *new = NULL;

	if (!string)
		return (NULL);
	for (l = 0; string[l] != '\0';)
		l++;

	new = my_calloc((sizeof(char) * l + 1), 1);
	if (!new)
		return (NULL);

	for (i = 0; i < l; i++)
		new[i] = string[i];
	new[l] = string[l];
	return (new);
}

/**
 * concat_all - concats 3 strings in newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *concat_all(char *name, char *sep, char *value)
{
	char *result = NULL;
	int l1 = 0, l2 = 0, l3 = 0, i = 0, k = 0;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = my_calloc((l1 + l2 + l3 + 1), 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * _strlen - is a function to calculate the length of string
 * @string: is an array of characters
 * Return: length of string
 */
int _strlen(char *string)
{
	int i = 0;
	
	while (string[i])
		i++;
		
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - prints a string
 * @str: String
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
