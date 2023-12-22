#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash table
 * @ht: pointer to hash table
 * @key: key to add the element
 * @value: value to add the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *val_cpy, *key_cpy;
	hash_node_t  *bckt, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);

	val_cpy = strdup(value);
	if (!val_cpy)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	bckt = ht->array[index];

	while (bckt)
	{
		if (!strcmp(key, bckt->key))
		{
			free(bckt->value);
			bckt->value = val_cpy;
			return (1);
		}
		bckt = bckt->next;
	}
	new_node = calloc(1, sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(val_cpy);
		return (0);
	}
	key_cpy = strdup(key);
	if (!key_cpy)
		return (0);
	new_node->key = key_cpy;
	new_node->value = val_cpy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
