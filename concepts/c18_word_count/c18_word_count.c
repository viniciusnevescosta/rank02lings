/*
 * c18_word_count: Counting entry into a word
 *
 * Several separators in a row still separate only two neighboring words.
 * Counting spaces would therefore depend on formatting instead of the number
 * of words. Track whether the current character belongs to a word.
 *
 * Trace:
 *     text:       " a  b "
 *     membership: outside, inside, outside, outside, inside, outside
 *     word starts:          ^                         ^
 * There are two transitions from outside to inside, so there are two words.
 *
 * A flag is a small variable describing state, such as currently_inside. Its
 * initial value matters for a word at index zero. Spaces and tabs are
 * separators here; punctuation belongs to the word. An empty string has no
 * transitions.
 *
 * GOAL: Make word_count count runs of characters separated by spaces or
 * tabs. Examples: " a  b " -> 2; "hi!" -> 1; " \t " -> 0; "" -> 0.
 */

int	word_count(char *s)
{
	int i;
	int count;
	int inside;

	i = 0;
	count = 0;
	inside = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			inside = 0;
		else if (inside == 0)
		{
			count++;
			inside = 1;
		}
		i++;
	}

	return (count);
}
