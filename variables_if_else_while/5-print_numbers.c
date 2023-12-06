#include <stdio.h>

int main(void)
{
  int i;  /* Declare the variable outside the loop*/

    for (i = 0; i <= 9; i++)
    {
      putchar(i+'0');
    }

    putchar('\n');

    return 0;
}
