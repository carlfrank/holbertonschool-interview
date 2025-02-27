/**
 * is_palindrome - checks whether a given unsigned integer is a palindrome
 * @n: the number to be checked
 * 
 * Return: 1 if n is a palindrome, 0 otherwise
 */
 int is_palindrome(unsigned long n)
 {
     unsigned long reversed = 0;
     unsigned long original = n;
     unsigned long remainder;
 
     /* Special case for single-digit numbers */
     if (n < 10)
         return (1);
 
     /* Reverse the number */
     while (n > 0)
     {
         remainder = n % 10;
         reversed = reversed * 10 + remainder;
         n /= 10;
     }
 
     /* Check if the original number equals its reverse */
     return (original == reversed);
 }