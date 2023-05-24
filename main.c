#include "shell.h"

/**
 * main - main function of the Shell
 * Return: 0 on success
 */
int main(void)
{
	int bytes_read = 0;
	char *string = NULL, *value = NULL, *pathname = NULL, **arv = NULL;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **) = NULL;

	signal(SIGINT, sig_handler); /*handler of ctrl+c*/
	while (1)
	{
		_isatty();
		fflush(stdin);
		bytes_read = getline(&string, &size, stdin); /*Read the line from user*/
		_EOF(bytes_read, string); /*error terminator*/
		arv = splitstring(string, " \n"); /*tokenize the string*/
		if (arv[0])
		{
			value = getenv("PATH");
			head = linkpath(value);
			pathname = _which(arv[0], head);
			free_list(head);
			f = checkbuild(arv); /*checking the bultins*/
			if (f)
			{
				f(arv);
			}
			if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
			}
			execute(arv);
		}
		else
			freearv(arv);
	}
	free_list(head);
	freearv(arv);
	free(string);
	return (0);
}
