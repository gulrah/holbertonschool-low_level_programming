#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n)
 * @head: A pointer to the head of the doubly linked list.
 *
 * Return: If the list is empty, return 0.
 */
int sum_dlistint(dlistint_t *head)
{
int sum = 0;

/* Iterate through the list to calculate the sum */
while (head != NULL)
{
sum += head->n;
head = head->next;
}

return (sum);
}
