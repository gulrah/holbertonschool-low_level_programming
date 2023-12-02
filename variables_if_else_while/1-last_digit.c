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

    // Generate a random number and assign it to variable n
    n = rand() - RAND_MAX / 2;

    // Extract the last digit of the random number
    int lastDigit = n % 10;

    // Print the last digit of the random number
    printf("Last digit of %d is %d and is ", n, lastDigit);

    // Check if the last digit is greater than 5, equal to 0, or less than 6 and not 0
    if (lastDigit > 5)
        printf("greater than 5\n");
    else if (lastDigit == 0)
        printf("0\n");
    else
        printf("less than 6 and not 0\n");

    return (0);
}
