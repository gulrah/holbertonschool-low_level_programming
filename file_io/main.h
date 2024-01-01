#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024

int _close(int fd);
ssize_t _read(const char *filename, int fd, char *buf, size_t count);
ssize_t _write(const char *filename, int fd, const char *buf, size_t count);
void open_files(int *file_from, int *file_to, char *argv[]);
void copy_data(int file_from, int file_to, char buf[]);
void close_files(int file_from, int file_to);

/* Task 0 - read_textfile */
ssize_t read_textfile(const char *filename, size_t letters);

/* Task 1 - create_file */
int create_file(const char *filename, char *text_content);

/* Task 2 - append_text_to_file */
int append_text_to_file(const char *filename, char *text_content);

/* Add more function prototypes as needed for subsequent tasks */

void error_exit(int code, char *message, int fd);

#endif /* MAIN_H */
