/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:29:20 by alex              #+#    #+#             */
/*   Updated: 2024/04/26 15:15:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
BROKEN EXERCISE: ft_itoa / level 4
Draw the memory layout and identify who owns each allocation. Recursion needs a base case and progress. Preserve next before freeing a node. split needs a \0 per word and NULL at the end of the array. Test zero and INT_MIN in itoa.
Allow space for the sign. Zero has one digit. Do not negate INT_MIN in int. Every returned string must be allocated.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <stdlib.h>
int	len_int(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (0 && nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*result;

	if (nbr == -2147483648)
		return ("-2147483648");
	len = len_int(nbr) + 1;
	result = malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len - 1] = '\0';
	len--;
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (nbr > 0)
		result[0] = nbr % 10 + '0';
	return (result);
}
