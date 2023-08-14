# Simple Shell

![Simple Shell Logo](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcS7py0JpjWHwipKYyQSmMWHsuJ9jiyuf1YqLQ&usqp=CAU)

**Authors:** Joana Ehun, Samuel Zerd Ashigbui

**Project Start Date:** Aug 9, 2023 6:00 AM
**Project End Date:** Aug 24, 2023 6:00 AM

This project is a simple UNIX command interpreter implemented in C as part of the ALX Software Engineering program. It is a group project that challenges us to apply various concepts and skills related to programming, C, engineering mindset, group work, and learning strategies.

## Background

The Simple Shell project aims to create a basic command-line interpreter similar to the Unix shell. It is inspired by the concepts discussed in "The Gates of Shell" by Spencer Cheng, featuring Julien Barbier.

## Concepts Covered

- Basics of programming
- Basics of C programming
- Basics of thinking like an engineer
- Group work
- Learning how to learn

## Important Guidelines

- All project work must be original, no copying of code from other sources or students is allowed.
- Coding should be done independently after understanding the concepts.
- Use of AI tools like ChatGPT is allowed within the context of learning.
- Focus on understanding and creating solutions rather than looking for shortcuts.
- Group projects involve mutual responsibility, and both partners must contribute and understand the code.
- Proper communication is necessary if unable to contribute to the project.
- Plagiarism is strictly forbidden and will result in removal from the program.

## Learning Objectives

By the end of this project, we are expected to be able to explain and demonstrate:

- General understanding of Unix operating system and shell concepts
- How to create a simple command interpreter in C
- How to use system calls like `execve`, `fork`, `wait`, `read`, etc.
- How to manipulate the environment of a process
- How to work with processes and their IDs (PID and PPID)
- How to handle built-in commands like `exit`, `env`, `cd`, etc.

## Project Structure

- `main.c`: The main entry point of the shell.
- `shell.c`: Core logic of the shell implementation.
- `prompt.c`: Functions related to displaying the shell prompt.
- `exec.c`: Functions to handle command execution.
- `env-environ.c`: Handling environment variables.
- `cd.c`: Implementation of the built-in `cd` command.
- `helpers.c`: Helper functions used throughout the project.

## Compilation

To compile the shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

## Usage

Run the shell in interactive mode:

```bash
./simple_shell
```

Or execute commands from a file:

```bash
./simple_shell commands.txt
```

## Built-in Commands

The shell supports the following built-in commands:

- `exit [status]`: Exit the shell with an optional status code.
- `env`: Print the current environment variables.
- `cd [DIRECTORY]`: Change the current working directory.
- `alias [name[='value']]`: Manage aliases for commands.
- `setenv VARIABLE VALUE`: Set a new environment variable.
- `unsetenv VARIABLE`: Remove an environment variable.

## Project Status

The project is in progress and will be completed by the specified deadline. We aim to meet all the learning objectives and provide a functional and efficient shell implementation.

Feel free to reach out to us if you have any questions or suggestions!

## Resources

- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
- [Everything you need to know to start coding your own shell concept page](https://intranet.alxswe.com/concepts/64)
- Other resources as provided by the course.

---

This project is a valuable opportunity for us to deepen our understanding of programming, C, and software engineering concepts. We are excited to learn, collaborate, and complete this project successfully!
