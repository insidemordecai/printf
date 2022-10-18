#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _printfHelper(const char *format, int i, va_list arguments);
int printString(char *string);
int printInt(long int integer);
int printUnsignedInt(int value);
int toBin(unsigned int value);
int toOct(unsigned int value);
int toHex(unsigned int value, int uppercase);
int printS(char *str);
int charHex(char ch);
int printAddress(unsigned long addr);

#endif
