#include "main.h"
#include <string.h>
/**
 * _strncpy - function copies the string pointed to by src
 *
 * @dest: destination of copy
 * @src: source array to copy
 * @n: number of bytes from src
 * Return: a pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int len, i;

	len = strlen(src);
	for (i = 0; i < n; i++)
	{
		if (i < len)
			dest[i] = src[i];
		else
			dest[i] = '\0';
	}
	return (dest);

}
