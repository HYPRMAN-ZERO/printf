#include "main.h"

/**
 * _size - generates the size to cast
 * @format: the formatted string to print into
 * @i: list of arguments to be printed
 * Return: size
 */
int _size(const char *format, int *i)
{
	int current_char = *i + 1;
	int size = 0;

	if (format[current_char] == 'l')
		size = S_LONG;

	else if (format[current_char] == 'h')
		size = S_SHORT;

	if (size == 0)
	{
		*i = current_char - 1;
	}
	else
	{
		*i = current_char;
	}
	return (size);
}
