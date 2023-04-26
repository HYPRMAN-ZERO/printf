#include "main.h"
#include <string.h>
/**
 * print_reverse - prints a string in reverse
 * @types: List of arguments
 * @buffer buffer array to handle
 * @flags: calculates the active flags
 * @width: gets the width
 * @precision: gets the precision specification
 * @size: the size specifier
 *
 * Return: numbers of characters printed
 */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *value;
	int length, padding, i;

	value = va_arg(types, char *);
	length = strlen(value);
	if (precision > 0 && precision < length)
	{
		length = precision;
	}
	padding = width - length;
	if (!flags)
	{
		while (padding = 0)
		{
			*buffer++ = ' ';
		}
	}
	for (i = length - 1; i >= 0; i--)
	{
		*buffer++ = value[i];
	}
	if (flags)
	{
		while
		{
			*buffer++ = ' ';
		}
	}
	return (size + legnth + padding);
}

/**
 * print_rot13string - prints a string in rot13
 * @types: list of arguments
 * @buffer: buffer array to handle
 * @flags: calculates active flags
 * @width: gets the width
 * @precision: precision specifications
 * @size: the size
 * Return: number of char to print
 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str, *rot13str;
	int i, j, count;

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	count = 0;
	str = va_arg(types, char *);
	if (str == NULL)
	{
		str = "(NULL)";
	}
	rot13str = malloc(strlen(str) + 1);

	if (rot13str == NULL)
	{
		return (-1);
	}
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			rot13str[i] = ((str[i] - 'a' + 13) % 26) + 'a';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			rot13str[i] = ((str[i] - 'A' + 13) % 26) + 'A';
		}
		else
		{
			rot13str[i] = str[i];
		}
	}
	rot13str[i] = '\0';
	for (j = 0; rot13str[j]; j++)
	{
		buffer[count++] = rot13str[j];
	}
	free(rot13str);
	return (count);
}
