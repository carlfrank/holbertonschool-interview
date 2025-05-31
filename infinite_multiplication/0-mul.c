#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit_string - Checks if a string is composed only of digits
 * @s: The string to check
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit_string(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * print_result - Prints the result stored in an int array
 * @result: The result array
 * @len: The length of the array
 */
void print_result(int *result, int len)
{
	int i = 0, started = 0;

	while (i < len)
	{
		if (result[i] != 0)
			started = 1;
		if (started)
			_putchar(result[i] + '0');
		i++;
	}

	if (!started)
		_putchar('0');

	_putchar('\n');
}

/**
 * main - Multiplies two positive numbers passed as arguments
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, mul, sum;
	int *result;

	if (argc != 3 || !is_digit_string(argv[1]) || !is_digit_string(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = strlen(num1);
	len2 = strlen(num2);

	result = calloc(len1 + len2, sizeof(int));
	if (!result)
	{
		printf("Error\n");
		exit(98);
	}

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
