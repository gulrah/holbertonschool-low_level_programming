#include <stdio.h>

int main(int argc, char *argv[]) {
  /* Check if the correct number of arguments is provided */
  char *program_name;

  if (argc != 2) {
        printf("%s" ERROR, argv[0]);
        return 1;  /* Indicate an error */
    }

  program_name = argv[1];
  /* Print the program's name */
    printf("%s\n", program_name);

    return 0;  /* Indicate success */
}
