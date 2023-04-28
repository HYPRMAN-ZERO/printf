#include "main.h"

/**
 * is_printable - determines if a char is printable
 * @a: Char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char a)
{
	if (a >= 32 && a < 127)
	{
		return (1);
	}
	return (0);
}

/**
 * append_hexa_code - Appends hexadecimal code to buffer
 * @buffer: Array of chars
 * @n: Index at which to start appending
 * @num_ascii: ASSCI CODE
 * Return: Always 3
 */
int append_hexa_code(char num_ascii, char buffer[], int n)
{
	char arr_to_map[] = "0123456789ABCDEF";

	if (num_ascii < 0)
		num_ascii *= -1;

	buffer[n++] = '\\';
	buffer[n++] = 'x';

	buffer[n++] = arr_to_map[num_ascii / 16];
	buffer[n] = arr_to_map[num_ascii % 16];

	return (3);
}

/**
 * is_digit - Determines if a character is a digit
 * @a: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char a)
{
	if (a >= '0' && a <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - Allocates a number to a certain size
 * @n: Number to be evaluated
 * @size: Number which determines type
 * Return: long int, value of num
 */
long int convert_size_number(long int n, int size)
{
	if (size == S_LONG)
	{
		return (n);
	}
	else if (size == S_SHORT)
	{
		return ((short)n);
	}
	return ((int)n);
}

/**
 * convert_size_unsgnd - Allocates a number to a specified size
 * @n: Number to be evaluated
 * @size: Number which determines type
 * Return: long int, value of num
 */
long int convert_size_unsgnd(unsigned long int n, int size)
{
	if (size == S_LONG)
	{
		return (n);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)n);
	}
	return ((unsigned int)n);
}

