#include "main.h"
/**
 * _strspn -  a function that gets the length of a prefix substring.
 * @s: This is the string to be scanned.
 * @accept:  accepted bytes to be compared.
 * Return: the number of bytes in the initial segment of @s which consist only
 * of bytes from @accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int a, b;
	int counter = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] != 32)
		{
			for (b = 0; accept[b] != '\0'; b++)
			{
				if (s[a] == accept[b])
					counter++;
			}
		}
		else
			return (counter);
	}
	return (counter);
}
