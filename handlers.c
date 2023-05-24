#include <shell.h>

/**
 * _EOF - handles the End of File
 * @len: return value of getline function
 * @buff: buffer
 */
void _EOF(int len, __attribute__((unused))char *buff)
{
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buff);
		}
		exit(0);
	}
}

/**
 * _isatty - verif if is interactive
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}

/**
 * sig_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
		_puts("\n$ ");
}
