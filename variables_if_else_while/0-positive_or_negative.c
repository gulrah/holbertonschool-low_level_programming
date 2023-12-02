#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int n;

    // Seed the random number generator with the current time
    srand(time(0));

    // Use the last digits of the current time as a random value
    n = time(0) % 200 - 100;

    // Print the random number
    printf("%d ", n);

    // Check if the number is positive, negative, or zero
    if (n > 0)
        printf("is positive\n");
    else if (n < 0)
        printf("is negative\n");
    else
        printf("is zero\n");

    return (0);
}
