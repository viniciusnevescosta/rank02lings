/*
 * c16_digit_value: A hexadecimal symbol and its value
 *
 * Hexadecimal uses sixteen values. The symbols '0' through '9' represent 0
 * through 9; 'a' through 'f' represent 10 through 15. Uppercase letters
 * represent the same values as lowercase letters.
 *
 * Example:
 *     In hexadecimal, c means twelve.
 *     "2c" represents 2 * 16 + 12 = 44 in decimal.
 * The symbol's character code is not the quantity twelve.
 *
 * Use separate character intervals for numeric and alphabetic symbols.
 * Mapping a symbol to its value is a different task from checking whether
 * that value is allowed in a particular base: '8' maps to 8, but cannot be
 * used as an octal digit.
 *
 * GOAL: Make digit_value return 0 through 15 for 0-9, a-f, or A-F, and -1
 * otherwise. Examples: 'c' -> 12; 'C' -> 12; 'z' -> -1.
 */
#include <stdlib.h>
#include <string.h>

int	digit_value(char c)
{
	(void)c;
	return (-1);
}
