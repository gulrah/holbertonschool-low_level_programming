#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>  /* for ssize_t */

/* Task 0 - read_textfile */
ssize_t read_textfile(const char *filename, size_t letters);

/* Task 1 - create_file */
int create_file(const char *filename, char *text_content);

/* Task 2 - append_text_to_file */
int append_text_to_file(const char *filename, char *text_content);

/* Add more function prototypes as needed for subsequent tasks */

void error_exit(int code, char *message, int fd);

#endif /* MAIN_H */
