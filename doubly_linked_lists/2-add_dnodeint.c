#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: A pointer to the head of the doubly linked list.
 * @n: The data for the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node;

    /* Check if head is NULL, allocate and assign the new node */
    if (head == NULL)
        return (NULL);

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize the new node */
    new_node->n = n;
    new_node->prev = NULL;

    /* If the list is not empty, update the previous of the current head */
    if (*head != NULL)
        (*head)->prev = new_node;

    /* Update the head to point to the new node */
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}
