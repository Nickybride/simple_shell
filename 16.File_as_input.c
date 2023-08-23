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
    // ... (same find_alias function implementation as before)
}

void print_aliases(void)
{
    // ... (same print_aliases function implementation as before)
}

void add_alias(char *name, char *value)
{
    // ... (same add_alias function implementation as before)
}

void replace_variables(char **args)
{
    // ... (same replace_variables function implementation as before)
}

void execute_commands_from_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Remove newline character at the end of the line
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, ";&| ");
        while (token != NULL)
        {
            if (token[0] != '#') // Skip comments
            {
                char **args = custom_tokenize(token);
                replace_variables(args);

                int result = execute_command(args);

                // Handle logical operators based on the result
                if (strcmp(args[0], "&&") == 0)
                    result = (result == 0) ? 1 : 0;
                else if (strcmp(args[0], "||") == 0)
                    result = (result == 0) ? 0 : 1;

                free(args);
            }

            token = strtok(NULL, ";&| ");
        }
    }

    fclose(file);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        execute_commands_from_file(argv[1]);
        return EXIT_SUCCESS;
    }

    // ... (same main function implementation as before)

    return 0;
}

