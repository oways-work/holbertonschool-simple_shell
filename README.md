**noting that most file were originally created in another repository than transfered here**

Simple Shell Project

A custom UNIX command-line interpreter built from scratch in C, as part of the ALX Software Engineering program curriculum.

This project aims to replicate the core functionality of the sh shell, including command execution, PATH handling, built-in commands, and error management.

Project Structure

shell.h: Main header file containing prototypes and includes.

main.c: The main entry point and REPL (Read-Execute-Print-Loop) for the shell.

More files will be added as the project grows...

Compilation

The shell is compiled using:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


Usage

Run the compiled executable:

./hsh


Or pipe commands to it:

echo "/bin/ls" | ./hsh
