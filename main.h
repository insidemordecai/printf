#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

int _putchar(char c);
int _printf(const char *format, ...);
int printString(char *string);
int printInt(long int integer);
int toBin(unsigned int value);
int toOct(unsigned int value);
int toHex(unsigned int value, int uppercase);

#endif
