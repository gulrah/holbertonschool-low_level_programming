#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Program that copies the content of a file to another file
 * @argc: Num argument
 * @argv: String argument
 * Return: 0
 */
int main(int argc, char *argv[])
{
    int file_from, file_to;
    char buf[1024];

    if (argc != 3)
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

    open_files(&file_from, &file_to, argv);
    copy_data(file_from, file_to, buf);
    close_files(file_from, file_to);

    return (0);
}
