#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024

typedef struct Alias
{
	char *name;
	char *value;
	struct Alias *next;
} Alias;

Alias *alias_list = NULL;

char *get_input(void)
{
	/* ... (same get_input function implementation as before)*/
}

Alias *find_alias(char *name)
{
	Alias *current = alias_list;
	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void print_aliases(void)
{
	Alias *current = alias_list;
	while (current != NULL)
	{
		printf("%s='%s'\n", current->name, current->value);
		current = current->next;
	}
}

void add_alias(char *name, char *value)
{
	Alias *alias = find_alias(name);
	if (alias != NULL)
	{
		free(alias->value);
		alias->value = strdup(value);
	}
	else
	{
		Alias *new_alias = (Alias *)malloc(sizeof(Alias));
			new_alias->name = strdup(name);
			new_alias->value = strdup(value);
	    `new_alias->next = alias_list;
	    alias_list = new_alias;
    }
}

void replace_variables(char **args)
{
    char *dollar_question = "$?";
    char *dollar_dollar = "$$";

    for (int i = 0; args[i] != NULL; i++)
    {
        if (strcmp(args[i], dollar_question) == 0)
        {
            char exit_status[8]; // Assume exit status can be represented in 7 characters
            snprintf(exit_status, sizeof(exit_status), "%d", WEXITSTATUS(prev_result));
            free(args[i]);
            args[i] = strdup(exit_status);
        }
        else if (strcmp(args[i], dollar_dollar) == 0)
        {
            char pid_str[16]; // Assume process ID can be represented in 15 characters
            snprintf(pid_str, sizeof(pid_str), "%d", getpid());
            free(args[i]);
            args[i] = strdup(pid_str);
        }
    }
}

int main(void)
{
    char *input, *token;
    char *delimiters = ";&| ";
    int prev_result = 0; // Result of the previous command (0 for success, non-zero for failure)

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
            if (strcmp(token, "alias") == 0)
            {
                // Handle alias command
                // ...
            }
            else
            {
                char **args = custom_tokenize(token);
                replace_variables(args);

                int result = execute_command(args);

                // Handle logical operators based on the result
                if (strcmp(args[0], "&&") == 0)
                    prev_result = (result == 0) ? 1 : 0;
                else if (strcmp(args[0], "||") == 0)
                    prev_result = (result == 0) ? 0 : 1;
                else
                    prev_result = result;

                free(args);
            }

            token = strtok(NULL, delimiters);
        }

        free(input);
    }

    return 0;
}

