#include "main.h"

/**
 * _flags - Gets flags to work accordinly
 * @format: string that prints the arguments.
 * @i: parameter
 * Return: Int, Flags:
 */
int _flags(const char *format, int *i)
{
	int n, current_char;
	int flags = 0;
	const char ARR_OF_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ARR_OF_FLAGS[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_char = *i + 1; format[current_char] != '\0'; current_char++)
	{
		for (n = 0; ARR_OF_CH[n] != '\0'; n++)
			if (format[current_char] == ARR_OF_CH[n])
			{
				flags |= ARR_OF_FLAGS[n];
				break;
			}

		if (ARR_OF_CH[n] == 0)
			break;
	}
	*i = current_char - 1;
	return (flags);
}

