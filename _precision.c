#include "main.h"

/**
 * _precision - handles the precision for non-custom conversion specifiers
 * @format: the format to print
 * @i: list of arguments to be printed
 * @list: the list of arguments passed
 * Return: printed characters
 */
int _precision(const char *format, int *i, va_list list)
{
	int current_char = *i + 1;
	int precision = -1;

	if (format[current_char] != '.')
		return (precision);

	precision = 0;

	for (current_char += 1; format[current_char] != '\0'; current_char++)
	{
		if (is_digit(format[current_char]))
		{
			precision *= 10;
			precision += format[current_char] - '0';
		}
		else
		if (format[current_char] == '*')
		{
			current_char++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current_char - 1;
	return (precision);
}

