/*
 * ft_split: Several allocations and two different terminators
 *
 * A split result is a pointer array containing pointers to independently
 * stored words. The pointer array ends with NULL; each word separately ends
 * with a '\0' byte.
 *
 * Example layout for "red  blue":
 *     result[0] -> ['r', 'e', 'd', '\0']
 *     result[1] -> ['b', 'l', 'u', 'e', '\0']
 *     result[2] -> NULL
 * A gap of several separators must not create extra empty words.
 *
 * Count pointer slots separately from bytes within a word. An input with no
 * words still returns an allocated pointer array containing NULL. The caller
 * later frees the word allocations and that array. Check each allocation
 * before writing through it; the word delimiters here include spaces, tabs,
 * and newlines.
 *
 * GOAL: Repair ft_split to return the words as a NULL-terminated allocated
 * char **, with a terminator in every word and no empty entries from
 * repeated separators. Follow SUBJECT.md's allowed functions.
 */
#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (0 && str[len])
		len++;
	return (len);
}

static char	*copy_word(char *str, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		start;
	int		word;

	split = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!split)
		return (NULL);
	i = 0;
	word = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !is_space(str[i]))
			i++;
		split[word] = copy_word(str + start, i - start);
		if (!split[word])
			return (NULL);
		word++;
	}
	split[word] = NULL;
	return (split);
}
