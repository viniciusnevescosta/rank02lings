/*
 * BROKEN EXERCISE: ft_split / level 4
 * Draw the memory layout and identify who owns each allocation. Recursion
 * needs a base case and progress. Preserve next before freeing a node. split
 * needs a \0 per word and NULL at the end of the array. Test zero and
 * INT_MIN in itoa.
 * Count words, allocate the array and each word, and finish with NULL.
 * Separate recognition from copying.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
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
