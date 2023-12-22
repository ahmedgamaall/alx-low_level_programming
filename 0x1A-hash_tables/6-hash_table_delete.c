#include "hash_tables.h"

/**
 * hash_table_delete - free hash table and all nodes
 * @ht: pointer to hash table
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *bckt, *a_free;
	unsigned long int i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		bckt = ht->array[i];
		while (bckt)
		{
			a_free = bckt;
			bckt = bckt->next;
			if (a_free->key)
				free(a_free->key);
			if (a_free->value)
				free(a_free->value);
			free(a_free);
		}
	}
	free(ht->array);
	free(ht);
}
