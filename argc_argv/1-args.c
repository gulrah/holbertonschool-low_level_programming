#include <stdio.h>

int main(int argc, char *argv[] __attribute__((unused))) {
  /* Print the number of arguments followed by a new line */
    printf("%d\n", argc - 1);

    return 0;  /* Indicate success */
}
