#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - print an output based on a format
 * @format: a character string
 * Return: length of characters printed excluding null terminator
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int i, flag, total = 0;

	if (format == NULL)
		return (0);

	va_start(arguments, format);
	for (i = 0; *format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			flag = 1;
		}
		else if (flag == 1)
		{
			flag = 0;

			total += _printfHelper(format, i, arguments);
		}
		else
		{
			_putchar(format[i]);
			total += 1;
		}
	}
	va_end(arguments);

	return (total);
}
/**
 * _printfHelper - performs function based on format specifer passed
 * @format: the specifier
 * @arguments: va_list with all arguments
 * @i: position in the va_list
 * Return: total characters printed
 */
int _printfHelper(const char *format, int i, va_list arguments)
{
	int total = 0;

	switch (format[i])
	{
		case 'c':
			_putchar(va_arg(arguments, int));
			return (total += 1);
		case 's':
			return (total += printString(va_arg(arguments, char *)));
		case '%':
			_putchar('%');
			return (total += 1);
		case 'd':
			return (total += printInt((long)(va_arg(arguments, int))));
		case 'i':
			return (total += printInt((long)(va_arg(arguments, int))));
		case 'b':
			return (total += toBin(va_arg(arguments, unsigned int)));
		case 'u':
			return (total += printUnsignedInt(va_arg(arguments, int)));
		case 'o':
			return (total += toOct(va_arg(arguments, int)));
		case 'x':
			return (total += toHex(va_arg(arguments, int), 0));
		case 'X':
			return (total += toHex(va_arg(arguments, int), 1));
		case 'S':
			return (total += printS(va_arg(arguments, char *)));
		case 'p':
			return (total += printAddress(va_arg(arguments, unsigned long)));
		default:
			_putchar('%');
			_putchar(format[i]);
			return (total += 2);
	}
}
