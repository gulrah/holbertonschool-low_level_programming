#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * error_exit - Print an error message to stderr and exit with a specific code.
 * @msg: The error message to print.
 * @file: The name of the file causing the error.
 * @exit_code: The exit code to use.
 */
void error_exit(const char *msg, const char *file, int exit_code)
{
    dprintf(STDERR_FILENO, "%s %s\n", msg, file);
    exit(exit_code);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, read_result, write_result;
    char buffer[1024];

    if (argc != 3)
        error_exit("Usage: cp file_from file_to", "", 97);

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit("Error: Can't read from file", argv[1], 98);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1)
        error_exit("Error: Can't write to file", argv[2], 99);

    while ((read_result = read(fd_from, buffer, sizeof(buffer))) > 0)
    {
        write_result = write(fd_to, buffer, read_result);
        if (write_result == -1 || write_result != read_result)
            error_exit("Error: Can't write to file", argv[2], 99);
    }

    if (read_result == -1)
        error_exit("Error: Can't read from file", argv[1], 98);

    if (close(fd_from) == -1 || close(fd_to) == -1)
        error_exit("Error: Can't close file descriptor", "", 100);

    return 0;
}
