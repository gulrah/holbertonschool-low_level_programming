#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Sets the given value for the given key in the hash table.
 *
 * @ht: Hash table
 * @key: Key (cannot be NULL)
 * @value: Value associated with the key
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
hash_node_t *new_node, *current;

if (!ht || !key)
return (0);

index = key_index((const unsigned char *)key, ht->size);
current = ht->array[index];

while (current)
{
if (!strcmp(current->key, key))
{
free(current->value);  /* Free old value */
current->value = strdup(value);  /* Update value */
return (1);
}
current = current->next;
}

new_node = malloc(sizeof(hash_node_t));
if (!new_node)
return (0);

new_node->value = strdup(value);
new_node->key = strdup(key);

if (!new_node->value || !new_node->key)
{
free(new_node->value);
free(new_node->key);
free(new_node);
return (0);
}

new_node->next = ht->array[index];
ht->array[index] = new_node;

return (1);
}
