#include "shell.h"

/**
 * get_path -  A function that computes for
 * the path of file.
 *
 * Return: 0.
 */

char *get_path(char *cmd)
{
	// ... (same get_path function implementation as before)
}

int main(void)
{
	char *cmd = NULL;
	size_t buffsize = 0;
	ssize_t chars_read;

	while (1)
	{
		printf(":) ");
		chars_read = getline(&cmd, &buffsize, stdin);

		if (chars_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(cmd);
				exit(EXIT_SUCCESS);
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}

		/* Remove the newline character from the command */
		if (cmd[chars_read - 1] == '\n')
			cmd[chars_read - 1] = '\0';

		/* Handle the built-in exit command */
		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}

		char *full_path = get_path(cmd);

		if (full_path == NULL)
		{
			printf("Command not found: %s\n", cmd);
			continue;
		}

		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0) /* Child process*/
		{
			execve(full_path, (char *const[]){cmd, NULL}, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}

		else /* Parent process */
		{
			wait(NULL); /* Wait for the child process to finish */
		}

		free(full_path);
	}

	free(cmd);
	return (0);
}

