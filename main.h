#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);

typedef struct prnt
{
	char *ch;
	void (*f)(va_list);
}p;

int _printstr(char *str);

#endif
