#include "main.h"

/**
 * _precision - handles the precision for non-custom conversion specifiers
 * @format: the format to print
 * @i: list of arguments to be printed
 * @list: the list of arguments passed
 * Returns: printed characters
 */

int _precision(const char *format, int *i, va_list list)
{
	int precision;
	char current_char;
	va_list list_cpy;

	va_copy(list_cpy, list);/*creat a copy of the list of arguments passed*/
	va_start(list_cpy, list);/*initializes the list*/
	precision = 0;/*this initializes the precision value to 0 and stores*/
	current_char = format[*i];/*then checks the current char in format str*/

	if (current_char != '.')/*if current char is a '.' it then skipps*/
	{
		va_end(list_cpy);/*frees list*/
		return (precision);
	}
	(*i)++;/*loops through the digits presented by i*/
	current_char = format[*i];
	while (current_char >= '0'&& current_char <= '9')/*loops over digits*/
	{
		precision = precision * 10 + current_char - '0';
		(*i)++;
		current_char = format[*i];
	}
	va_end(list_cpy);
	return (precision);
}
