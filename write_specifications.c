#include "main.h"

/**
 * printf_write_char - Prints a string to stdout
 * @c: char types
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width parameter
 * @precision: precision parameter
 * @size: Size parameter
 * Return: Int, number of printed chars.
 */
int printf_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int n = 0;
	char var = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		var = '0';

	buffer[n++] = c;
	buffer[n] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (n = 0; n < width - 1; n++)
			buffer[BUFF_SIZE - n - 2] = var;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - n - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - n - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_num - Prints a string to stdout
 * @is_negative: arguments
 * @ind: types of characters
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width parameter
 * @precision: precision parameter
 * @size: Size parameter
 *
 * Return: Characters printed to stdout.
 */
int write_num(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char var = ' ', current_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		var = '0';
	if (is_negative)
		current_char = '-';
	else if (flags & F_PLUS)
		current_char = '+';
	else if (flags & F_SPACE)
		current_char = ' ';

	return (printf_buffer_num(ind, buffer, flags, width, precision,
		len, var, current_char));
}

/**
 * printf_buffer_num - prints a number using a bufffer
 * @ind: Index at which the number starts on the buffer, starting point
 * @buffer: Buffer
 * @flags: Flags
 * @width: width parameter
 * @prec: Precision parameter
 * @length: Length of the number
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: Int, number of printed chars
 */
int printf_buffer_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int n, var = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (n = 1; n < width - length + 1; n++)
			buffer[n] = padd;
		buffer[n] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], n - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], n - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--var] = extra_c;
			return (write(1, &buffer[var], n - var) +
				write(1, &buffer[ind], length - (1 - var)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * printf_write_unsgnd - Writes an unsigned number to stdout
 * @is_negative: negative number
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chararacters
 * @flags: Flags
 * @width: Width pararmeter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Int,Number of chars written to stdout
 */
int printf_write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, n = 0;
	char var = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		var = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		var = '0';

	if (width > len)
	{
		for (n = 0; n < width - len; n++)
			buffer[n] = var;

		buffer[n] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], n));
		}
		else
		{
			return (write(1, &buffer[0], n) + write(1, &buffer[ind], len));
		}
	}
	return (write(1, &buffer[ind], len));
}

/**
 * printf_write_pointer - Write a pointer
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: number length
 * @width: Width parameter
 * @flags: Flags
 * @padd: padding char
 * @extra_c: extra char
 * @padd_start: Index at which padding should start
 * Return: Int, number of written chars to stdout
 */
int printf_write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int n;

	if (width > length)
	{
		for (n = 3; n < width - length + 3; n++)
			buffer[n] = padd;
		buffer[n] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], n - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], n - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], n - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

