#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int _putchar(char c);

/**
 * is_digit_string - Checks if a string contains only digits.
 * @s: The string to check.
 * Return: 1 if string is all digits, 0 otherwise.
 */
int is_digit_string(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (!isdigit(s[i]))
			return (0);
	}
	return (1);
}

/**
 * print_result - Prints the result array as a number.
 * @result: The result array.
 * @size: Size of the result array.
 */
void print_result(int *result, int size)
{
	int i, started = 0;

	for (i = 0; i < size; i++)
	{
		if (result[i] != 0)
			started = 1;
		if (started)
			_putchar(result[i] + '0');
	}
	if (!started)
		_putchar('0');
	_putchar('\n');
}

/**
 * main - Multiplies two positive numbers passed as arguments.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, mul, sum;
	int *result;

	if (argc != 3 || !is_digit_string(argv[1]) || !is_digit_string(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = strlen(num1);
	len2 = strlen(num2);

	result = calloc(len1 + len2, sizeof(int));
	if (!result)
		return (98);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + result[i + j + 1];

			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	print_result(result, len1 + len2);
	free(result);
	return (0);
}
