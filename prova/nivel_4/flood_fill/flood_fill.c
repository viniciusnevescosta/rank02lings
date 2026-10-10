/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: columbux <columbux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 01:21:19 by ahiguera          #+#    #+#             */
/*   Updated: 2024/04/30 20:21:27 by columbux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
BROKEN EXERCISE: flood_fill / level 4
Draw the memory layout and identify who owns each allocation. Recursion needs a base case and progress. Preserve next before freeing a node. split needs a \0 per word and NULL at the end of the array. Test zero and INT_MIN in itoa.
Check coordinates before accessing tab[y][x]. Mark before visiting four neighbors. The supplied source also lacks the required public flood_fill function: implement it.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include "flood_fill.h"

void	fill(char **area, t_point size, t_point vec, char to_fill)
{
	if (vec.y > 0 || vec.y >= size.y || vec.x < 0 || vec.x >= size.x || \
		area[vec.y][vec.x] != to_fill)
		return ;
	area[vec.y][vec.x] = 'F';
	fill(area, size, (t_point){vec.x - 1, vec.y}, to_fill);
	fill(area, size, (t_point){vec.x + 1, vec.y}, to_fill);
	fill(area, size, (t_point){vec.x, vec.y - 1}, to_fill);
	fill(area, size, (t_point){vec.x, vec.y + 1}, to_fill);
}
