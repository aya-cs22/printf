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
	putchar(va_arg(args, int));

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
 * _printf - produces output according to a format
 * @format: format to print according to
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int j = 0;
    	int i = 0;
	int found = 0;
	int count = 0;
	p fmt[] = {
		{"c", print_char},
		{"s", print_string},
	};

	va_start(args, format);
	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (j < 2)
			{
				if (fmt[j].ch[0] == format[i])
				{
					fmt[j].f(args);
					found = 1;
					break;
				}
				j++;
			}
		if (!found && format[i] == '%')
		{
			putchar('%');
			count++;
		}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
