/**
 * CONTAINS: 
 * printString, printInt, printUnsignedInt
 * toBin, toOct, toHex 
 * printS, charHex
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
		return (length);
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
 * @uppercase: to choose case to use for hex letters
 * Return: number of hexadecimal characters
 */
int toHex(unsigned int value, int uppercase)
{
	int hex[sizeof(unsigned int) * 8], mod, i = 0, j, length = 0;

	while (value != 0)
	{
		mod = value % 16;

		if (mod < 10)
		{
			hex[i++] = 48 + mod; /* in ASCII, 48 is 0 */
		}
		else
		{
			if (uppercase == 1)
				hex[i++] = 55 + mod; /* 55 + 10 = 65 which is A */
			else
				hex[i++] = 87 + mod; /* 87 + 10 = 97 which is a */
		}

		value /= 16;
	}

	for (j = i - 1; j >= 0; j--)
		length += _putchar(hex[j]);

	return (length);
}

/**
 * printS - print a string and non-printable characters
 *			(0 < ASCII value < 32 or >= 127) are printed as \x followed
 *			by the ASCII code value in hex (uppercase - always 2 characters)
 * @str: string to print
 * Return: number of character printed
 */
int printS(char *str)
{
	int i, length = 0; 

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			length += 2;
			length += charHex(str[i]);
		}
		else
		{
			_putchar(str[i]);
			length++;
		}
	}

	return (length);
}

/**
 * charHex - print a character's ASCII value in hex (uppercase) 
 * @ch: character to print its ASCII value
 * Return: number of characters printed (always 2)
 */
int charHex(char ch)
{
	int length = 0;
	char difference = 'A' - ':', d[2];

	d[0] = ch / 16;
	d[1] = ch % 16;

	for (length = 0; length < 2; length++)
	{
		if (d[length] >= 10)
			_putchar('0' + difference + d[length]);
		else
			_putchar('0' + d[length]);
	}
	return (length);
}
