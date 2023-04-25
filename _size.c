#include "main.h"

/**
 * _size - generates the size to cast
 * @format: the formatted string to print into
 * @i: list of arguments to be printed
 * Return: size
 */
int _size(const char format,int *i)
{
	char current_char;
	int size;

	curernt_char = format[*i];
	size = 0;
	if (current_char == 'h')
	{
		size = S_SHORT;
	}
	else if (current_char == 'l')
	{
		size = S_LONG;
	}
	current_char = format[*i + 1];
	if (current_char == 'h' || current_char == 'l')
	{
		size += 1;
		*i = *i + 1;
	}
	return (size);
}
