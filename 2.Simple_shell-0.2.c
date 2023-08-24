#include "shell.h"

/**
 * prompt - prints cisfun$ on the stdio
 */

void prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * checks_chars_read - checks if EOF isnt reached
 * else return success.
 *
 * Return: 1 on completion
 */
int checks_chars_read(void)
{
	ssize_t chars_read;
	char *cmd;

	if (chars_read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(cmd);
			exit(0);
		}
		else
		{
			perror("getline");
			exit(1);
		}
	}
}

/**
 * main - entrace functions of the program
 * the program add checks of CLI arguements to
 * 1.simple_shell.c
 *
 * Return: 0 on success.
 */

int handle_CLI_argument(void)
{
	char *cmd = NULL;
	size_t buffsize = 0;
	ssize_t chars_read;

	while (1)
	{
		prompt();
		chars_read = getline(&cmd, &buffsize, stdin);
		checks_chars_read();

		/* Remove the newline character from the command(cmd) */
		if (cmd[chars_read - 1] == '\n')
			cmd[chars_read - 1] = '\0';

		/* Tokenize the command and arguments */
		char *args[40]; /* Assuming max 39 arguments */

		char *tokken = strtok(cmd, " ");
		int j = 0;

		while (token != NULL)
		{
			args[j++] = token;
			tokken = strtok(NULL, " ");
		}

		/* // Last element of the array must be NULL */
		args[j] = NULL;
		pid_t child_pid = fork();

		if (kid_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (kid_pid == 0)
			forkChild();

		/*Parent process waits for child process */
		wait(NULL);
	}

	free(cmd);
	return (EXIT_SUCCESS);
}


/**
 * forkChild - calls child process
 * @args: arguement number/count
 */
void forkChild(void)
{
	char * const*args;

	execve(args[0], args, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}
