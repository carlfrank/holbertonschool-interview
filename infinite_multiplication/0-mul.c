#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * is_digit_string - Check if a string contains only digits
 * @s: string to check
 * Return: 1 if only digits, 0 otherwise
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
 * _calloc - allocates memory for an array of ints
 * @nmemb: number of elements
 * @size: size of each element
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *ptr;
    unsigned int i;

    if (nmemb == 0 || size == 0)
        return (NULL);

    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);

    for (i = 0; i < (nmemb * size); i++)
        ptr[i] = 0;

    return (ptr);
}

/**
 * print_result - Prints the result array as a number
 * @result: int array of the result
 * @len: length of the result array
 */
void print_result(int *result, int len)
{
    int i = 0;

    while (i < len && result[i] == 0)
        i++;

    if (i == len)
        putchar('0');
    else
    {
        for (; i < len; i++)
            putchar(result[i] + '0');
    }
    putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    char *num1, *num2;
    int len1, len2, i, j, mul, sum, carry;
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
    result = _calloc(len1 + len2, sizeof(int));
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
            sum = result[i + j + 1] + mul;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    print_result(result, len1 + len2);
    free(result);
    return (0);
}
