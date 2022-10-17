/* CONTAINS: printString, printInt, toBin */

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
	int bin[sizeof(unsigned int) * 8], mod, i, length = 0;

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
		bin[mod] = '0' + (value % 2);
		value /= 2;
		mod++;
	}

	for (i = mod - 1; i >= 0; i--)
		length += _putchar(bin[i]);

	return (length);
}

/**
 * toOct - convert to octadecimal (base 8)
 * @value: number to convert
 * Return: number of octadecimal characters
 */
int toOct(unsigned int value)
{
	int oct[sizeof(unsigned int) * 8], mod, i = 0, j, length = 0;

	while (value != 0)
	{
		mod = value % 8;
		oct[i++] = '0' + mod;
		value /= 8;
	}

	for (j = i - 1; j >= 0; j--)
		length += _putchar(oct[j]);

	return (length);
}

/**
 * toHex - convert to hexadecimal (base 16)
 * @value: number to convert
 * Return: number of hexadecimal characters
 */
int toHex(unsigned int value)
{
	int hex[sizeof(unsigned int) * 8], mod, i = 0, j, length = 0;

	while (value != 0)
	{
		mod = value % 16;

		if (mod < 10)
			hex[i++] = 48 + mod; /* in ASCII, 48 is 0 */
		else 
			hex[i++] = 55 + mod; /* 55 + 10 = 65 which is A */

		value /= 16;
	}

	for (j = i - 1; j >= 0; j--)
		length += _putchar(hex[j]);

	return (length);
}
