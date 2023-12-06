#include <stdio.h>


int main(void)
{
  int digit;
    /* Loop from 0 to 9 and print each digit followed by a comma and space */
    for (digit = 0; digit <= 9; digit++)
    {
      putchar(digit + '0');
        if (digit < 9) {
            putchar(',');    /* Print comma after the digit */
            putchar(' ');    /* Print space after the comma */
        }
    }

    putchar('\n');  /* Print a new line at the end */

    return 0;
}
