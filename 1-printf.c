#include "main.h"
#include <stddef.h>
#include <stdio.h>

/**
 * _printint - Prints an integer
 * @num: Integer to print
 * Return: Number of characters printed
 */
int _printint(int num)
{
	int printed_chars = 0;

	if (num < 0)
	{
		_putchar('-');
		printed_chars++;
		num = -num;
	}
	if (num / 10)
		printed_chars += _printint(num / 10);
	_putchar('0' + (num % 10));
	printed_chars++;
	return (printed_chars);
}
