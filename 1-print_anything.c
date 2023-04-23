#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
/**
 * _printf - a function that prints anything
 * @format: pointer to a string that holds specifier
 * @...: variable arguments passed to function
 * Return: Always (0)
 */
int _printf(const char *format, ...)
{
	int i, len, printed_char, num;
	va_list args;

	va_start(args, format);
	len = strlen(format);
	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (i >= len)
			{
				va_end(args);
				return (-1);
			}
			if (format[i] == 'd' || format[i] == 'i')
			{
				num = va_arg(args, int);
				printed_char += printf("%d", num);
			}
			else
			{
				printed_char += _putchar('%');
				printed_char += _putchar(format[i]);
			}
		}
		else
		{
			printed_char += _putchar(format[i]);
		}
	}
	va_end(args);
	return (printed_char);
}
