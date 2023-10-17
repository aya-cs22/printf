#include "main.h"

/**
 * printbin - prints a binary number
 *@num: input number
 * Return: binary number
 */

int _printbin(unsigned int num)
{
	int printed_chars = 0;

	if (num / 2)
	{
		printed_chars += _printbin(num / 2);
	}
	_putchar('0' + (num % 2));
	printed_chars++;
	return (printed_chars);
}
