#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: The NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 *         If the file cannot be created or written, return -1.
 *         If filename is NULL, return -1.
 *         If text_content is NULL, create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t written, len = 0;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (-1);

    if (text_content != NULL)
    {
        while (text_content[len] != '\0')
            len++;

        written = write(fd, text_content, len);
        if (written == -1 || written != len)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
