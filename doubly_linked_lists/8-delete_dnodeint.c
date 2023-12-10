#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index index of a dlistint_t linked list.
 * @head: Pointer to the pointer to the beginning of the dlistint_t list.
 * @index: Index of the node to be deleted, starting from 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current, *temp;
unsigned int i;

if (*head == NULL)
return -1;

current = *head;

for (i = 0; i < index; i++)
{
if (current == NULL)
return -1;
current = current->next;
}

if (current == NULL)
return -1;

temp = current;
if (current->prev)
current->prev->next = current->next;

if (current->next)
current->next->prev = current->prev;

free(temp);

if (index == 0)
{
*head = (*head)->next;
if (*head)
(*head)->prev = NULL;
}

return 1;
}
