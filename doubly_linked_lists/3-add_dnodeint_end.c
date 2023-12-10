#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: A pointer to the head of the doubly linked list.
 * @n: The data for the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new_node, *temp;

/* Check if head is NULL, allocate and assign the new node */
if (head == NULL)
return (NULL);

/* Allocate memory for the new node */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

/* Initialize the new node */
new_node->n = n;
new_node->next = NULL;

/* If the list is empty, update the head to point to the new node */
if (*head == NULL)
{
new_node->prev = NULL;
*head = new_node;
return (new_node);
}

/* Traverse the list to find the last node */
temp = *head;
while (temp->next != NULL)
temp = temp->next;

/* Update the next of the last node to point to the new node */
temp->next = new_node;
/* Update the previous of the new node to point to the last node */
new_node->prev = temp;

return (new_node);
}
