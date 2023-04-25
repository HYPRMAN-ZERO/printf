#include "main.h"

void p_buffer(char buffer[], int *buff_index);

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 * Return: int, output according to a format
 */
int _printf(const char *format, ...)
{
	int i, prints = 0, b_chars = 0;
	int width, flags, size, precision, buff_index = 0;

	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				p_buffer(buffer, &buff_index);
			b_chars++;
		}
		else
		{
			p_buffer(buffer, &buff_index);
			flags = _flags(format, &i);
			width = _width(format, &i, list);
			precision = _precision(format, &i, list);
			size = _size(format, &i);
			++i;
			prints = printf_specifiers(format, &i, list, buffer, flags,
				width, precision, size);
			if (prints == -1)
				return (-1);
			b_chars += prints;
		}
	}
	p_buffer(buffer, &buff_index);

	va_end(list);

	return (b_chars);
}

/**
 * p_buffer - prints characters on to the buffer
 * @buffer: array of characters to be printed to the buffer
 * @buff_index: index/starting point thid depicts the length
 */
void p_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
