#include"main.h"
/**
*_puts - prints a string followed by a new line
*@str: character to be printed
*Return: returns a string followed by a new line
*/
void _puts(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
	{
		_putchar(str[index]);
	}
	_putchar('\n');
}
