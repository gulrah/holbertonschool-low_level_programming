#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * free_hash_node - Frees memory allocated for a hash node.
 * @node: The hash node to be freed.
 */
void free_hash_node(hash_node_t *node)
{
free(node->key);
free(node->value);
free(node);
}

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table.
 * @key: The key.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
hash_node_t *new_node, *temp;

if (!ht || !key || *key == '\0' || !value)
return (0);

index = key_index((const unsigned char *)key, ht->size);

temp = ht->array[index];
while (temp)
{
if (strcmp(temp->key, key) == 0)
{
free(temp->value);
temp->value = strdup(value);
return (temp->value ? 1 : 0);
}
temp = temp->next;
}

new_node = malloc(sizeof(hash_node_t));
if (!new_node)
return (0);

new_node->key = strdup(key);
if (!new_node->key)
{
free(new_node);
return (0);
}

new_node->value = strdup(value);
if (!new_node->value)
{
free(new_node->key);
free(new_node);
return (0);
}

new_node->next = ht->array[index];
ht->array[index] = new_node;

return (1);
}
