#include "shell.h"

/**
 * get_path - function that handles env variable.
 * @cmd: user entered commands
 *
 * Return: 0.
 */

char *get_path(char *cmd)
{
	char *path_env = getenv("PATH");

	if (path_env == NULL)
		return (NULL);
	char *path = strtok(path_env, ":");

	while (path != NULL)
	{
		char *full_path = malloc(strlen(path) + strlen(cmd) + 2);

		if (full_path == NULL)
		{
			printf("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", path, cmd);

		if (access(full_path, X_OK) == 0)
			return (full_path);

		free(full_path);
		path = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * opt_chars_read - runs set checks if end of file
 * is not reached.
 *
 * Return: 1 on success
 */
int opt_chars_read(void)
{
	char *cmd;

	/* checks if the end of file (EOF)*/
	if (feof(stdin))
	{
		printf("\n");
		free(cmd);
		exit(1);
	}
	else
	{
		perror("getline");
		exit(1);
	}
}

/**
 * main - start of the program
 *
 * Return: 0
 */

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
			opt_chars_read();
		if (cmd[chars_read - 1] == '\n')	/* Removes newline char from the command */
			cmd[chars_read - 1] = '\0';

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
		if (child_pid == 0) /* Child process */
		{
			execve(full_path, (char *const[]){cmd, NULL}, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else /* Parent process */
			wait(NULL); /* Wait for the child process to finish */
		free(full_path);
	}
	free(cmd);
	return (0);
}
