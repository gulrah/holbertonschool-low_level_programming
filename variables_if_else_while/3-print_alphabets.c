#include <stdio.h>

int main(void)
{
    char letter = 'a';

    /* Print the lowercase alphabet */
    while (letter <= 'z')
    {
        putchar(letter);
        letter++; /* Incrementing the character to move to the next one in ASCII sequence */
    }

    letter = 'A'; /* Resetting letter to 'A' for uppercase*/

    /* Print the uppercase alphabet */
    while (letter <= 'Z')
    {
        putchar(letter);
        letter++; /* Incrementing the character to move to the next one in ASCII sequence */
    }

    putchar('\n'); /* Print a new line after both lowercase and uppercase alphabets*/

    return 0;
}
