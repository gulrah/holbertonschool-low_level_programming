#include <stdio.h>

int main(void)
{
    char letter = 'a';

    while (letter <= 'z')
    {
        /* Check if the letter is 'e' or 'q', and skip them */
        if (letter != 'e' && letter != 'q')
        {
            putchar(letter);
        }
        letter++; /* Incrementing the character to move to the next one in ASCII sequence */
    }

    putchar('\n'); /* Print a new line after printing the alphabet */

    return 0;
}
