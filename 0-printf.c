#include "main.h"
#include <stddef.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(list, int));
					printed_chars++;
					break;
				case 's':
					printed_chars += _printstr(va_arg(list, char *));
					break;
				case '%':
					_putchar('%');
					printed_chars++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					printed_chars += 2;
					break;
			}
		}
		format++;
	}
	va_end(list);
	return (printed_chars);
}

/**
 * _printstr - Prints a string
 * @str: String to print
 * Return: Number of characters printed
 */
int _printstr(char *str)
{
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		printed_chars++;
		str++;
	}

	return (printed_chars);
}
