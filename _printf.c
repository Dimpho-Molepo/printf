#include "main.h"

void print_array(char array[], int *array_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, char_ printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list roll;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(roll, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[arrat_index++] = format[i];
			if (array_index == BUFF_SIZE)
				print_buffer(buffer, &array_index);
			/* write(1, &format[i], 1);*/
			char_printed++;
		}
		else
		{
			print_buffer(buffer, &array_index);
			flags = get_flags(format, &a);
			width = get_width(format, &a, roll);
			precision = get_precision(format, &a, roll);
			size = get_size(format, &a);
			++a;
			printed = handle_print(format, &a, roll, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			char_printed += printed;
		}
	}

	print_array(array, &array_index);

	va_end(roll);

	return (char_printed);
}

/**
 * print_array - Prints the contents of the buffer if it exist
 * @array: Array of chars
 * @array_index: Index at which to add next char, represents the length.
 */
void print_array(char array[], int *array_index)
{
	if (*array_index > 0)
		write(1, &array[0], *array_index);

	*array_index = 0;
}
