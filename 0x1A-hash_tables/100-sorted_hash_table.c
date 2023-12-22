#include "hash_tables.h"

/**
 * sorted_list - function for insert new node in sorted
 * @ht: pointer to sorted hash table
 * @new_node: pew node to insert
 *
 */
void sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *sbckt = ht->shead;

	if (sbckt == NULL)
	{
		ht->shead = ht->stail = new_node;
		new_node->snext = new_node->sprev = NULL;
		return;
	}
	do {
		if (strcmp(new_node->key, sbckt->key) < 0)
		{
			new_node->snext = sbckt;
			new_node->sprev = sbckt->sprev;

			if (!sbckt->sprev)
				ht->shead = new_node;
			else
				sbckt->sprev->snext = new_node;
			sbckt->sprev = new_node;
			return;
		}
		sbckt = sbckt->snext;
	} while (sbckt);
	new_node->sprev = ht->stail;
	new_node->snext = ht->stail->snext;
	ht->stail->snext = new_node;
	ht->stail = new_node;
}

/**
 * shash_table_create - creates a sorted hash tables
 * @size: size of the hash table
 *
 * Return: pointer to hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *tb;

	if (size == 0)
		return (NULL);

	tb = calloc(1, sizeof(shash_table_t));
	if (tb == NULL)
		return (NULL);

	tb->size = size;
	tb->array = calloc(size, sizeof(shash_node_t *));
	if (tb->array == NULL)
	{
		free(tb);
		return (NULL);
	}
	return (tb);
}

/**
 * shash_table_set - function that adds an element to the sorted hash table
 * @ht: pointer to sorted hash table
 * @key: key to add the element
 * @value: value to add the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *val_cpy, *key_cpy;
	shash_node_t  *bckt, *new_node;

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
	new_node = calloc(1, sizeof(shash_node_t));
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
	sorted_list(ht, new_node);
	return (1);
}
/**
 * shash_table_get - function to retrieve value associeted with key
 * @ht: pointer to hash table
 * @key: key to retrive value
 *
 * Return: value or NULL if key does not exit.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t  *bckt;

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

/**
 * shash_table_print - function to print the key:value from ht
 * @ht: pointer to hash table
 *
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *bckt;
	int n_fin = 0;

	if (!ht)
		return;
	bckt = ht->shead;
	printf("{");
	while (bckt)
	{
		if (n_fin)
			printf(", ");
		printf("'%s': '%s'", bckt->key, bckt->value);
		n_fin = 1;
		bckt = bckt->snext;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - function to print the key:value from ht in reverse
 * @ht: pointer to hash table
 *
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *bckt;
	int n_fin = 0;

	if (!ht)
		return;
	bckt = ht->stail;
	printf("{");
	while (bckt)
	{
		if (n_fin)
			printf(", ");
		printf("'%s': '%s'", bckt->key, bckt->value);
		n_fin = 1;
		bckt = bckt->sprev;
	}
	printf("}\n");
}
/**
 * shash_table_delete - free hash table and all nodes
 * @ht: pointer to hash table
 *
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *bckt, *a_free;
	unsigned long int index = 0;

	if (!ht)
		return;

	for (index = 0; index < ht->size; index++)
	{
		bckt = ht->array[index];
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
