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
	int current_char;
	int width = 0;

	for (current_char = *i + 1; format[current_char] != '\0'; current_char++)
	{
		if (is_digit(format[current_char]))
		{
			width *= 10;
			width += format[current_char] - '0';
		}
		else
		if (format[current_char] == '*')
		{
			current_char++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = current_char - 1;
	return (width);
}

