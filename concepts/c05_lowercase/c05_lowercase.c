/*
 * c05_lowercase: ASCII ranges and guarded conversion
 *
 * In the ASCII character set used by these exercises, letters within each
 * case have consecutive numeric values. A character variable can therefore
 * be compared with letter literals and used in arithmetic.
 *
 * Example:
 *     'D' - 'A' gives 3, the zero-based position of D.
 *     'd' - 'a' also gives 3.
 * The position within the alphabet is independent of the case.
 *
 * Only letters in the uppercase interval need conversion. Changing every
 * byte by a fixed amount would also change punctuation and digits. Decide
 * whether a character belongs to the relevant interval before transforming
 * it, and leave other characters unchanged.
 *
 * GOAL: Make lowercase convert an ASCII uppercase letter to lowercase.
 * Examples: D -> d; d -> d; ? -> ?. Return the resulting character.
 */

char	lowercase(char c)
{
	return (c);
}
