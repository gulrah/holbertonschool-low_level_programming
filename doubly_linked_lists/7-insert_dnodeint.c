#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a dlistint_t list.
 * @h: A pointer to the address of the head of the doubly linked list.
 * @idx: The index of the list where the new node should be added. Index starts at 0.
 * @n: The data to be added to the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *temp = *h;
    unsigned int i = 0;

    /* If index is 0, add at the beginning */
    if (idx == 0)
        return add_dnodeint(h, n);

    /* Find the node at the previous index */
    while (temp != NULL && i < idx - 1)
    {
        temp = temp->next;
        i++;
    }

    /* If the index is out of bounds, return NULL */
    if (temp == NULL)
        return NULL;

    /* Create a new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    /* Update the new node's data and pointers */
    new_node->n = n;
    new_node->next = temp->next;
    new_node->prev = temp;

    /* Update the next node's previous pointer */
    if (temp->next != NULL)
        temp->next->prev = new_node;

    /* Update the previous node's next pointer */
    temp->next = new_node;

    return new_node;
}
