/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:58:12 by alex              #+#    #+#             */
/*   Updated: 2024/03/15 13:02:13 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
BROKEN EXERCISE: ft_strlen / level 1
C strings end with \0. Start indexes at zero and stay within the string. Separate initialization, loop condition, and progress. Pointers hold addresses; *p accesses the pointed value. write outputs bytes without adding a newline.
Count characters before the terminator. The index is the number of visited characters.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] == '\0')
		len++;
	return (len);
}
