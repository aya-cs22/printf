#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);

typedef struct prnt
{
	char *ch;
	void (*f)(va_list);
}p;

#endif
