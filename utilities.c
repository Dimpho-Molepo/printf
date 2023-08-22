#include "main.h"

/**
 * printable_check - Evaluates if a char is printable
 * @character: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int printable_check(char character)
{
	if (character >= 32 && character < 127)
		return (1);

	return (0);
}

/**
 * append_hexadecimal - Append ascci in hexadecimal code to buffer
 * @array: Array of chars.
 * @p: Index at which to start appending.
 * @ascii_table: ASSCI CODE.
 *
 * Return: Always 3
 */
int append_hexadecimal(char ascii_table, char array[], int p)
{
	char array_1[] = "0123456789ABCDEF";
	
	if (ascii_table < 0)
		ascii_table *= -1;

	array[p++] = '\\';
	array[p++] = 'x';

	array[p++] = array_1[ascii_table / 16];
	array[p] = array_1[ascii_table % 16];

	return (3);
}

/**
 * is_number - Verifies if a char is a digit
 * @z: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_number(char z)
{
	if (z >= '0' && z <= '9')
		return (1);

	return (0);
}

/**
 * cast_number_2size - Casts a number to the specified size
 * @number: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int cast_number_2size(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * cast_size_unsgnd - Casts a number to the specified size
 * @number: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int cast_size_unsgnd(unsigned long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
