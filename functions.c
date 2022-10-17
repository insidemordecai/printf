/* FILE CONTAINS: printString, printInt, toBin */

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

/**
 * printInt - print an integer
 * @integer: the passed integer
 * Return: the length of the integer
 */
int printInt(long int integer)
{
	int length = 0;

	if (integer < 0)
	{
		_putchar('-');
		length++;
		integer = -integer;
	}

	if (integer / 10)
		length += printInt(integer / 10);

	_putchar((integer % 10) + '0');
	length++;

	return (length);
}

/**
 * toBin - convert unsigned int to binary (base 2)
 * @value: number to convert
 * Return: number of binary characters
 */
int toBin(unsigned int value)
{
	int binary[sizeof(unsigned int) * 8], mod, i, length = 0;

	if (value == 0)
	{
		length += _putchar('0');
		return (length);
	}

	if (value == 1)
	{
		length += _putchar('1');
		return(length);
	}

	mod = 0;

	while (value > 0)
	{
		binary[mod] = '0' + (value % 2);
		value /= 2;
		mod++;
	}

	for (i = mod - 1; i >= 0; i--)
		length += _putchar(binary[i]);

	return (length);
}
