#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a character
 * @args: a list
 * Return: void
 */

void print_char(va_list args)
{
	_putchar(va_arg(args, int));

}

/**
 * print_string - prints a string
 * @args: a list
 * Return: (void)
 */
void print_string(va_list args)
{
	char *ptr;

	ptr = va_arg(args, char *);
	if (ptr != NULL)
		fputs(ptr, stdout);
}

/**
 * print_percent - prints %
 * @args: a list
 * Return: void
 */

void print_percent(va_list args)
{
	(void) args;

	_putchar('%');
}
/**
 * _printf - produces output according to a format
 * @format: format to print according to
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int j = 0;
	int i = 0;
	int count = 0;
	p fmt[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
	};

	va_start(args, format);
	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;
			while (j < 3)
			{
				if (fmt[j].ch[0] == format[i])
				{
					fmt[j].f(args);
				}
			j++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	i++;
	}
	va_end(args);
	return (count);
}
