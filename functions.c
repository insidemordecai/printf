#include "main.h"

/**
 * printString - print a string
 * @string: the passed string
 * Return: the length of the string
 */
int printString(char *string)
{
	int length = 0;

	if (string != NULL)
	{
		while (*string)
		{
			_putchar(*string++);
			length++;
		}
	}
	else 
	{
		return (printString("null"));
	}

	return (length);
}
