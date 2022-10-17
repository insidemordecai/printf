#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	va_list arguments;
	int i, flag, total = 0;

	if (format == NULL)
		return (0);

	va_start(arguments, format);

	for (i = 0; *format && format[i] != '\0'; i++)
	{
		/* set flag to true (1) if encountered */
		if (format[i] == '%')
		{
			flag = 1;
			continue;
		}

		if (flag == 1)
		{
			flag = 0;

			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(arguments, int));
					total += 1;
					break;
				case 's':
					total += printString(va_arg(arguments, char *));
					break;
				case '%':
					_putchar('%');
					total += 1;
					break;
				case 'd':
					total += printInt((long)(va_arg(arguments, int)));
					break;
				case 'i':
					total += printInt((long)(va_arg(arguments, int)));
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					total += 2;
			}
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
