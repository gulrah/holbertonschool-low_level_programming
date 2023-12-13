#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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
