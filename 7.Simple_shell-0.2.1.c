#include "shell.h"

char **custom_tokenize(char *input)
{
	static char *tokens[32]; /* Assuming max 31 tokens */
	int token_count = 0;
	char *token = input;
	char *next_token = NULL;

	while ((next_token = strchr(token, ' ')) != NULL)
	{
		*next_token = '\0';
		tokens[token_count++] = token;
		token = next_token + 1;
	}

	if (token != input)
		tokens[token_count++] = token;

	tokens[token_count] = NULL; /* Last element of the array must be NULL */

	return tokens;
}

int main(void)
{
	char *cmd;
	char **args;

	while (1)
	{
		printf("#cisfun$ ");
		cmd = get_input();

		if (cmd == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		args = custom_tokenize(command);
		/* Rest of your shell logic using args */
		/* ... */
	}

	return 0;
}

