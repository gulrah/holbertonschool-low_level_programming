#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters it could read and print.
 *         If the file cannot be opened or read, return 0.
 *         If filename is NULL, return 0.
 *         If write fails or does not write the expected amount of bytes, return 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t rd;
char *buf;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(letters);
if (buf == NULL)
{
close(fd);
return (0);
}

rd = read(fd, buf, letters);
if (rd == -1)
{
free(buf);
close(fd);
return (0);
}

if (write(STDOUT_FILENO, buf, rd) != rd)
{
free(buf);
close(fd);
return (0);
}
/* Clean up and close the file */
free(buf);
close(fd);
return (rd);
}
