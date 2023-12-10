#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a linked dlistint_t list.
 * @h: A pointer to the head of the doubly linked list.
 *
 * Return: The number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t node_count = 0;

while (h != NULL)
{
h = h->next;
node_count++;
}

return (node_count);
}
