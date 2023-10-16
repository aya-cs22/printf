#include "main.h"
#include <stddef.h>

int handle_format_specifier(char specifier, va_list list);

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
			_putchar(*format++);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				va_end(list);
				return (-1);
			}
			printed_chars += handle_format_specifier(*format, list);
		format++;
		}
	}

	va_end(list);
	return (printed_chars);
}

/**
 * handle_format_specifier - Handle the format specifier
 * @specifier: The format specifier character
 * @list: The va_list
 * Return: Number of characters printed
 */
int handle_format_specifier(char specifier, va_list list)
{
	switch (specifier)
	{
		case 'c':
			_putchar(va_arg(list, int));
			return (1);
		case 's':
			return (_printstr(va_arg(list, char *)));
		case '%':
			_putchar('%');
			return (1);
		default:
			_putchar('%');
			_putchar(specifier);
			return (2);
	}
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
		_putchar(*str++);
		printed_chars++;
	}

	return (printed_chars);
}

