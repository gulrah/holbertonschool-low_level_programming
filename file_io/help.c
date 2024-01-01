#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * open_files - Open source and destination files
 * @file_from: Source file descriptor
 * @file_to: Destination file descriptor
 * @argv: Command-line arguments
 */
void open_files(int *file_from, int *file_to, char *argv[])
{
    *file_from = open(argv[1], O_RDONLY);
    if (*file_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    *file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
        | S_IRGRP | S_IWGRP | S_IROTH);
    if (*file_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close(*file_from), exit(99);
    }
}

/**
 * copy_data - Copy data from source to destination file
 * @file_from: Source file descriptor
 * @file_to: Destination file descriptor
 * @buf: Buffer for reading/writing
 */
void copy_data(int file_from, int file_to, char buf[])
{
    int num1 = 1024, num2;

    while (num1 == 1024)
    {
        num1 = read(file_from, buf, 1024);
        if (num1 == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't read from file\n");
            exit(98);
        }
        num2 = write(file_to, buf, num1);
        if (num2 < num1)
            dprintf(STDERR_FILENO, "Error: Can't write to file\n"), exit(99);
    }
}

/**
 * close_files - Close source and destination files
 * @file_from: Source file descriptor
 * @file_to: Destination file descriptor
 */
void close_files(int file_from, int file_to)
{
    if (close(file_from) == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

    if (close(file_to) == -1)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);
}
