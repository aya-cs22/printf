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
	char buffer[20];
	int index = 0;
	int i;

	if (num == 0)
	{
		_putchar('0');
		printed_chars++;
		return (1);
	}
	if (num < 0)
	{
		_putchar('-');
		printed_chars++;
		num = -num;
	}
	while (num > 0)
	{
		buffer[index++] = '0' + (num % 10);
		num /= 10;
	}
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
		printed_chars++;
	}
	return (printed_chars);
}
