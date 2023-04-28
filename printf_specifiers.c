#include "main.h"
/**
 * printf_specifiers - Prints to stdout according to specifier
 * @fmt: string that prints the arguments
 * @args: arguments
 * @ind: ind
 * @buffer: buffer
 * @flags: Flags
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: 1 or 2;
 */
int printf_specifiers(const char *fmt, int *ind, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int n, len = 0, p_chars = -1;
	fmt_t fmt_types[] = {
		{'c', printf_char}, {'s', printf_string}, {'%', printf_percent},
		{'i', printf_int}, {'d', printf_int}, {'b', printf_binary},
		{'u', printf_unsigned}, {'o', printf_octal}, {'x', printf_hexadecimal},
		{'X', printf_upper_hex}
	};
	for (n = 0; fmt_types[n].fmt != '\0'; n++)
		if (fmt[*ind] == fmt_types[n].fmt)
			return (fmt_types[n].fn(args, buffer, flags, width, precision, size));

	if (fmt_types[n].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);

		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (p_chars);
}

