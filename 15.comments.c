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
    // ... (same get_input function implementation as before)
}

Alias *find_alias(char *name)
{
    Alias *current = alias_list;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
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
        new_alias->next = alias_list;
        alias_list = new_alias;
    }
}

void replace_variables(char **args)
{
    // ... (same replace_variables function implementation as before)
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
            if (token[0] != '#') // Skip comments
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
            }

            token = strtok(NULL, delimiters);
        }

        free(input);
    }

    return 0;
}

