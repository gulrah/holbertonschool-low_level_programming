#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
char *key;
char *value;
struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
unsigned long int size;
hash_node_t **array;
} hash_table_t;

/* Task 0 - Create a hash table */
hash_table_t *hash_table_create(unsigned long int size);

/* Task 1 - Implement the djb2 hash function */
unsigned long int hash_djb2(const unsigned char *str);

/* Task 2 - Get the index of a key in the hash table */
unsigned long int key_index(const unsigned char *key, unsigned long int size);

/* Task 3 - Add an element to the hash table */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/* Task 4 - Retrieve a value associated with a key */
char *hash_table_get(const hash_table_t *ht, const char *key);

/* Task 5 - Print the hash table */
void hash_table_print(const hash_table_t *ht);

/* Task 6 - Delete the hash table */
void hash_table_delete(hash_table_t *ht);

#endif /* HASH_TABLES_H */
