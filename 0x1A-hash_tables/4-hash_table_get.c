#include "hash_tables.h"
/**
 * hash_table_get - function to retrieve value associeted with key
 * @ht: pointer to hash table
 * @key: key to retrive value
 *
 * Return: value or NULL if key does not exit.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t  *bckt;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	bckt = ht->array[index];
	while (bckt)
	{
		if (!strcmp(key, bckt->key))
			return (bckt->value);
		bckt = bckt->next;
	}
	return (NULL);
}
