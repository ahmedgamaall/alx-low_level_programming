#include "hash_tables.h"

/**
 * hash_table_print - function to print the key:value from ht
 * @ht: pointer to hash table
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t  *bckt;
	int no_fin = 0;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		bckt = ht->array[i];
		while (bckt)
		{
			if (no_fin)
				printf(", ");
			printf("'%s': '%s'", bckt->key, bckt->value);
			no_fin = 1;
			bckt = bckt->next;
		}
	}
	printf("}\n");
}
