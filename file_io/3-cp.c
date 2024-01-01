#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"
#define BUFFER_SIZE 1024

/**
 * error_exit - handles error and exits with the given code
 * @code: exit code
 * @message: error message
 * @fd: file descriptor
 */
void error_exit(int code, char *message, int fd)
{
    dprintf(STDERR_FILENO, message, fd);
    exit(code);
}

int main(int argc, char *argv[])
{
    int fd_from, fd_to, rd, wr;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to\n", -1);

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file %s\n", fd_from);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        error_exit(99, "Error: Can't write to %s\n", fd_to);

    do {
        rd = read(fd_from, buffer, BUFFER_SIZE);
        if (rd == -1)
            error_exit(98, "Error: Can't read from file %s\n", fd_from);

        wr = write(fd_to, buffer, rd);
        if (wr == -1)
            error_exit(99, "Error: Can't write to %s\n", fd_to);

    } while (rd > 0);

    if (close(fd_from) == -1)
        error_exit(100, "Error: Can't close fd %d\n", fd_from);

    if (close(fd_to) == -1)
        error_exit(100, "Error: Can't close fd %d\n", fd_to);

    return (0);
}
