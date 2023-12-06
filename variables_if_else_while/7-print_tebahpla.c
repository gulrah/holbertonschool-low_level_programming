#include <stdio.h>

int main(void)
{
  char letter;    /* Loop from 'z' to 'a' and print each letter in reverse */
    for (letter = 'z'; letter >= 'a'; letter--)
    {
        putchar(letter);
    }

    putchar('\n');  /* Print a new line after the reversed alphabet */

    return 0;
}
