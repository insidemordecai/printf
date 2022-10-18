#include "main.h"

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
