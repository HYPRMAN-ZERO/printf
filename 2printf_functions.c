#include "main.h"

/**
 * printf_unsigned - Prints unsigned number to stdout
 * @args: arguments
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Int, number of chars printed to stdout
 */
int printf_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (printf_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * printf_octal - Prints number in octal notation to stdout
 * @args: arguments
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Int, number of chars printed to stdout
 */
int printf_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int new_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && new_num != 0)
		buffer[i--] = '0';

	i++;
	return (printf_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * printf_hexadecimal - Prints number in hexadecimal notation to stdout
 * @args: arguments
 * @buffer: Buffer
 * @flags:  Flags
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Int, number of chars printed to stdout
 */
int printf_hexadecimal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printf_all_hex(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * printf_upper_hex - Prints number in upper hexadecimal notation to stdout
 * @args: arguments
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Int, number of chars printed to stdout.
 */
int printf_upper_hex(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printf_all_hex(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * printf_all_hex - Prints a hex number in lower or upper notation to stdout
 * @args: arguments
 * @arr: Array to map the number to
 * @buffer: Buffer
 * @flags:  Flags1
 * @flag_two: Flags2
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size1 parameter
 * @size: Size2 parameter
 * Return: Int, number of chars printed to stdout
 */
int printf_all_hex(va_list args, char arr[], char buffer[],
	int flags, char flag_two, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int new_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = arr[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && new_num != 0)
	{
		buffer[i--] = flag_two;
		buffer[i--] = '0';
	}
	i++;
	return (printf_write_unsgnd(0, i, buffer, flags, width, precision, size));
}

