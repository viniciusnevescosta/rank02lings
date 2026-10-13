/*
 * c04_is_space: Boolean expressions and the meaning of OR
 *
 * A comparison such as c == ' ' produces a truth value. In C, zero is false
 * and nonzero is true. || means that either condition is enough; && requires
 * both conditions at once.
 *
 * Example:
 *     int is_vowel = (c == 'a' || c == 'e');
 * 'a' and 'e' satisfy this example. No single character can be both 'a' and
 * 'e' at the same time.
 *
 * Always use the exercise's definition of a separator. Some C library
 * functions consider several whitespace characters, but this exercise
 * recognizes only the space byte and the tab byte. A newline is a different
 * character.
 *
 * GOAL: Make is_space return true for ' ' and '\t', and false for other
 * characters, including '\n'.
 */

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}
