#include "shell.h"

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
 * handle - a function that handle NULL errors
 */
void handle_error(char *error_message)
{
	char cmd;

	perror(error_message);
	free(cmd);
	exit(EXIT_FAILURE);
}

/**
 * remove_newline - Remove the newline character
 * from the command
 * @cmd: user commands in terminal
 * @chars_read: reads charaters elements bu user.
 *
 * Return: 0
 */

void remove_newline(char *cmd, ssize_t chars_read)
{

	/* Remove the newline character from the command */
	if (cmd[chars_read - 1] == '\n')
		cmd[chars_read - 1] = '\0';
}


/**
 * handleKid_pid - handles conditional statements
 * for to fork() kid_child
 * @cmd: user inputed command
 *
 * Return: kid_pid on success.
 */

void handleKid_pid(const char *cmd)
{
	execve(cmd, (char *const[]){(char *const)cmd, NULL}, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}


/**
 * get_path - function that handles env variable.
 * @cmd: CLI iputs or commands
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
 * hanndle_env_cmd - handle the built-in env command
 * in file 5.simple....c
 */
void hanndle_env_cmd(void)
{
	char **env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	continue;
}
