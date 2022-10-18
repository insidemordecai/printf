/* CONTAINS: printString, printInt, printUnsignedInt */

#include "main.h"
#include <math.h>

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

	m = (unsigned int)pow(10, 9);
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

/**
 * printAddress - prints an address in hex
 * @addr: address to print
 * Return: number of characters
 */
int printAddress(unsigned long addr)
{
	int length = 0;
	unsigned int a[16], i, sum = 0;
	unsigned long m;
	char *str = "(nil)";

	if (addr == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			length++;
		}
		return (length);
	}

	_putchar('0');
	_putchar('x');
	length = 2;
	m = (unsigned long)pow(16, 15);
	a[0] = addr / m;

	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (addr / m) % 16;
	}

	for (i = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			length++;
		}
	}
	return (length);
}
