#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void error_exit(int code, const char *message) {
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(code);
}

void copy_file(const char *file_from, const char *file_to) {
    int fd_from, fd_to, read_count, write_count;
    char buffer[BUFFER_SIZE];

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file");

    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_to == -1)
        error_exit(99, "Error: Can't write to file");

    while ((read_count = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        write_count = write(fd_to, buffer, read_count);
        if (write_count != read_count)
            error_exit(99, "Error: Can't write to file");
    }

    if (read_count == -1)
        error_exit(98, "Error: Can't read from file");

    if (close(fd_from) == -1 || close(fd_to) == -1)
        error_exit(100, "Error: Can't close fd");
}

int main(int argc, char *argv[]) {
    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to");

    copy_file(argv[1], argv[2]);

    return 0;
}
