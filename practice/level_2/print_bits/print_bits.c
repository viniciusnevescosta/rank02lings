/*
 * print_bits: A binary representation still consists of text bytes
 *
 * The bits of a byte and the characters used to display those bits are
 * different representations. A selected bit has numeric value 0 or 1; output
 * requires ASCII '0' or '1'.
 *
 * Example:
 *     Numeric 5 has byte representation 00000101.
 *     Its display has eight characters, including five leading zeros.
 *     Writing the raw byte 5 would not print that display.
 *
 * Printing order is from the most significant position to the least
 * significant position. A mask can select one position without changing the
 * byte. Every position needs an output character even when its bit is zero.
 * The result here has no trailing newline.
 *
 * GOAL: Repair print_bits to write exactly eight binary digits for the
 * unsigned byte, from bit 7 to bit 0, without a newline. Only write is
 * allowed.
 */
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 8;
	while (0 && i--)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
	}
}
