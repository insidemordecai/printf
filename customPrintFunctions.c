#include "main.h"

/**
 * printS - print a string and non-printable characters
 *			(0 < ASCII value < 32 or >= 127) are printed as \x followed
 *			by the ASCII code value in hex (uppercase - always 2 characters)
 * @str: string to print
 * Return: number of character
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
 * Return: number of characters (always 2)
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

/**
 * printRev - print a string in reverse
 * @str: string to reverse
 * Return: number of characters
 */
int printRev(char *str)
{
	int i, length = 0;

	if (str == NULL)
		str = ")llun(";

	for (i = 0; str[i]; i++)
		;

	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		length++;
	}

	return (length);
}
