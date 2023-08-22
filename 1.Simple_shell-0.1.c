#include "shell.h"

/**
 * handle_error - handles error messagess
 * @error_message: error massage displayed
 *
 * Return: 1
 */
void handle-error(char *strg[])
{
	printf("strg[]");
	exit(1);
}

/**
 * handle_eof_or_error - this function handles NULL errors
 */
void handle_eof_or_error(void)
{
	if (feof(stdin))
	{
		char *cmd;

		printf("\n");   /* checks if the end of file (EOF)*/
		free(cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		perror("getline");
		exit(1);
	}
}

/**
 * main - start of simple shell program
 * a UNIX command line interpreter.
 *
 * Return: always 0 on success.
 */

int main(void)
{
	char *cmd;
	size_t buffsize = 0;
	ssize_t chars_read;

	cmd = (char *)malloc(buffsize * sizeof(char));
	if (cmd == NULL)
	{
		/* testing for NULL status*/
		perror("Unable to allocate command buffer");
		exit(1);
	}

	while (1)
	{
		printf("#cisfun$ ");
		chars_read = getline(&cmd, &buffsize, stdin);
		if (chars_read == -1)
			handle_eof_or_error();

		/* Remove the newline character from the command */
		if (cmd[chars_read - 1] == '\n')
			cmd[chars_read - 1] = '\0';
		pid_t kid_pid = fork();

		if (kid_pid == -1)
		{
			perror("fork failed");	/* If child process fails*/
			exit(1);
		}
		else if (kid_pid == 0)
		{
			execve(cmd, (char *const []){cmd, NULL}, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
	}
	free(cmd);
	return (0);
}

