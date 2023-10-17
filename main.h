#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _printint(int num);

/**
 * struct prnt - a struct that deals with a specifier
 * @ch: a charater
 * @f: a function pointer
 * p - typedef
 */

typedef struct prnt
{
	char ch;
	void (*f)(va_list);
} p;

int _printstr(char *str);
int handle_format_specifier(char specifier, va_list list);

#endif
