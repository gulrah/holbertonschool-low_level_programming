#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: A pointer to the head of the doubly linked list.
 * @index: The index of the node, starting from 0.
 *
 * Return: If the node does not exist, return NULL. Otherwise, return the
 *         pointer to the nth node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int count = 0;

    /* Iterate through the list to find the nth node */
    while (head != NULL)
    {
        if (count == index)
            return (head);
        head = head->next;
        count++;
    }

    /* If the index is out of bounds, return NULL */
    return (NULL);
}
