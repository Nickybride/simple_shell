#include "shell.h"
/**
 * get_input - a funtion pointer to a funtion
 * implementation
 *
 * Return: 0 always
 */

char *get_input(void)
{
	/* ... (same get_input function implementation as before) */
}

int execute_command(char *cmd)
{
	char **args = custom_tokenize(cmd);

	/* Handle the built-in setenv, unsetenv, and cd commands */
	/* ... */

	/* Execute the command */
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0) /* Child process */
	{
		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else /* Parent process */
	{
		int status;

		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		return (-1);
	}
}

/**
 * main - entry point to the program calls other
 * funtions in it.
 *
 * Return: 0 always
 */

int main(void)
{
	char *input, *token;
	char *delimiters = ";&|";
	int prev_result = 0;
	/* Result of the previous command (0 for success, non-zero for failure)*/

	while (1)
	{
		printf("$ ");
		input = get_input();

		if (input == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		token = strtok(input, delimiters);

		while (token != NULL)
		{
			int result = execute_command(token);

			/* Handle logical operators based on the result */
			if (strcmp(token, "&&") == 0)
				prev_result = (result == 0) ? 1 : 0;
			else if (strcmp(token, "||") == 0)
				prev_result = (result == 0) ? 0 : 1;
			else
				prev_result = result;

			token = strtok(NULL, delimiters);
		}
		free(input);
	}

	return (0);
}
