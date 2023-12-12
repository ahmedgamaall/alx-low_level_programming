#include "main.h"
/**
 * _memset - fill memory with a constant byte
 * @s: a pointer
 * @b: constant byte
 * @n:  first bytes of the memory area pointed to by s
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a = 0;

	while (a < n)
	{
		s[a] = b;
		a++;
	}
	return (s);
}
