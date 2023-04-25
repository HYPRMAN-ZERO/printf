#include "main.h"

/**
 * _width - generates the width to print
 * @format: formatted string to print into
 * @i: list of arguments to print
 * @list: list of arguments
 * Return: width
 */
int _width(const char *format, int *i, va_list list)
{
	int width;
	int current_char;
	va_list list_cpy;

	va_copy(list_cpy, list);
	va_start(list_cpy, list);
	current_char = format[*i];
	width = 0;

	while (current_char == '0')
	{
		width = width * 10 + current_char - '0';
		*i = *i + 1
		current_char = format[*i];
	}
	va_end(list_cpy);
	return (width);
}
