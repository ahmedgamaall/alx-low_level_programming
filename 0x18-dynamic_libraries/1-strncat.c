#include "main.h"
/**
 * _strncat - concats two arrays
 *
 * @dest: destination of concat
 * @src: source array to concat
 * @n: number of bytes from src
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	for (j = 0; dest[j] != '\0'; j++)
	{}

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[j + i] = src[i];
	}

	return (dest);

}
