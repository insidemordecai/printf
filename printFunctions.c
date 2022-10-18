/**
 * CONTAINS: printString, printInt, printUnsignedInt
 */

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
		return (printString("(null)"));
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
 * printUnsignedInt - print an unsigned int
 * @value: number to print as unsigned int
 * Return: number of characters
 */
int printUnsignedInt(int value)
{
	unsigned int a[10], i, m, sum = 0;
	int length = 0;

	m = 1000000000; /* 10 power 9 */
	a[0] = value / m;

	for (i = 1; i < 10; i++)
	{
		m /= 10;
		a[i] = (value / m) % 10;
	}

	for (i = 0; i < 10; i++)
	{
		sum += a[i];

		if (sum || i == 9)
		{
			_putchar('0' + a[i]);
			length++;
		}
	}
	return (length);
}
