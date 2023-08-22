#include "shell.h"

char *get_input(void)
{
	static char buffer[BUFFSIZE];
	static size_t position = 0;
	static ssize_t bytes_read = 0;

	if (position >= bytes_read)
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFFSIZE);
		if (bytes_read <= 0)
			return (NULL);
		position = 0;
	}

	while (position < bytes_read)
	{
		if (buffer[position] == '\n')
		{
			buffer[position] = '\0';
			char *input = strdup(buffer);
			position++;
			return (input);
		}
		position++;
	}

	return (NULL);
}

int main(void)
{
	char *cmd;

	while (1)
	{
		printf("#cisfun$ ");
		command = get_input();

		if (command == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		/* Rest of your shell logic */
		/* ... */
	}

	return (0);
}
