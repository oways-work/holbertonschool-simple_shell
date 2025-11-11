Holberton Simple Shell Project (hsh)

This is a custom UNIX command-line interpreter (shell) written entirely in C. It is a foundational project for the Holberton School and ALX Software Engineering curriculum, designed to teach process management, system calls, and C programming in depth.

This shell mimics the core behavior of sh (/bin/sh).

Features Implemented

Interactive and Non-Interactive Modes: Works with a prompt or with piped input.

Command Execution: Parses command lines with arguments.

PATH Handling: Locates executables in the PATH environment variable.

Error Handling: Prints error messages (e.g., "not found") matching sh.

Built-in Commands:

exit: Exits the shell.

env: Prints the current environment.

Compilation

The project is compiled using gcc with strict flags:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


Usage

Interactive Mode

./hsh
($) /bin/ls -l
total 64
-rw-r--r-- 1 user group  442 Nov 11 15:30 AUTHORS
-rw-r--r-- 1 user group 1238 Nov 11 15:30 README.md
...
($) ls
README.md  AUTHORS  hsh  main.c ...
($) env
USER=user
PATH=/usr/local/bin:/usr/bin:/bin
...
($) exit


Non-Interactive Mode

echo "ls -l" | ./hsh
