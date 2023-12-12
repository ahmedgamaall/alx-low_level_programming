#include "main.h"
#include <stddef.h>
/**
 * _strpbrk - a function that searches a string for any of a set of bytes.
 * @s: This is the string to be scanned.
 * @accept:  This is the C string containing the characters to match.
 * Return: a pointer to the byte in s that matches one of the bytes in
 * accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	const char *t;

	while (*s != '\0')
	{
		t = accept;
		while (*t != '\0')
		{
			if (*s == *t)
			{
				return (s);
			}
			t++;
		}
		s++;
	}
	return (NULL);
}
