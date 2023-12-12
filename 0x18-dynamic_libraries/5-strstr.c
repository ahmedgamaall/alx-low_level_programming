#include "main.h"
/**
 * _strstr - a function that locates a substring.
 * @haystack: This is the string to be scanned.
 * @needle: This is the string containing the characters to match.
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int a;
	int b;

	if (needle[0] == '\0')
		return (haystack);
	for (a = 0; haystack[a] != '\0'; a++)
	{
		if (haystack[a] == needle[0])
		{
			for (b = 0; needle[b] != '\0'; b++)
			{
				if (haystack[a + b] != needle[b])
				break;
			}
			if (needle[b] == '\0')
				return (haystack + a);
		}
	}
	return ('\0');
}
