#include <stdio.h>

int main(void)
{
  char digit, letter;
    /* Loop from '0' to '9' and 'a' to 'f', and print each character */
    for (digit = '0'; digit <= '9'; digit++)
    {
        putchar(digit);
    }

    for (letter = 'a'; letter <= 'f'; letter++)
    {
        putchar(letter);
    }

    putchar('\n');  /* Print a new line after the hexadecimal digits */

    return 0;
}
