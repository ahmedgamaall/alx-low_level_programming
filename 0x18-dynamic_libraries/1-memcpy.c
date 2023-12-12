#include "main.h"
/**
 * _memcpy -  copies n bytes from memory area src to memory area dest.
 * @dest: This is pointer to the destination array.
 * @src: This is pointer to the source of data to be copied.
 * @n: This is the number of bytes to be copied.
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int a = 0;

	while (a < n)
	{
		dest[a] = src[a];
		a++;
	}
	return (dest);
}
