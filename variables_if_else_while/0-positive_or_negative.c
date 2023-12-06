#include <stdlib.h>
#include <time.h>
#include <stdio.h>  /*  Added to include standard input/output functions */

/* more headers goes there */

/* betty style doc for function main goes there */
int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    /* your code goes there */

    /* Check if the number is positive, negative, or zero */
    if (n > 0)
    {
        printf("%d is positive\n", n);
    }
    else if (n < 0)
    {
        printf("%d is negative\n", n);
    }
    else
    {
        printf("0 is zero\n");
    }

    return (0);
}
