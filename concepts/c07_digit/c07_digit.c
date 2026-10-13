/*
 * c07_digit: A digit character is not its numeric value
 *
 * The int value 6 and the char literal '6' are different representations. A
 * text digit is a character code; arithmetic usually needs the quantity
 * represented by that character.
 *
 * Example:
 *     '6' - '0' gives the integer 6.
 *     '0' - '0' gives the integer 0.
 * The subtraction works because ASCII decimal digit codes are consecutive.
 *
 * Validate membership in the range '0' through '9' before converting.
 * Subtracting '0' from an unrelated letter also produces a number, but that
 * number is not a valid decimal digit. A sentinel value can distinguish an
 * invalid character from the valid digit zero.
 *
 * GOAL: Make digit return 0 through 9 for decimal digit characters, and -1
 * for any other character. Examples: '6' -> 6; 'x' -> -1.
 */

int	digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}
