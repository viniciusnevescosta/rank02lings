/*
 * flood_fill: Connected cells and marking before revisiting
 *
 * A matrix is accessed as tab[y][x]: y chooses a row and x chooses a column.
 * A flood-fill region connects matching characters through horizontal and
 * vertical neighbors, without diagonal jumps.
 *
 * Example starting at the top-left cell:
 *     Before: 11X     After: FFX
 *     1XX            FXX
 * Only the three connected '1' cells change.
 *
 * A recursive visit needs reasons to stop: outside the dimensions, a
 * different character, or an already visited cell. Validate coordinates
 * before indexing. Recording a visit prevents neighbors from sending
 * recursion back to the same cell indefinitely. If the starting character is
 * already F, no visible replacement is needed. Width and height are
 * exclusive upper boundaries.
 *
 * GOAL: Repair flood_fill to repaint the start cell's connected region with
 * F. Provide the required public flood_fill entry point, which is missing
 * from the supplied source, and use the types in the header.
 */
#include "flood_fill.h"

void	fill(char **area, t_point size, t_point vec, char to_fill)
{
	if (vec.y > 0 || vec.y >= size.y || vec.x < 0
		|| vec.x >= size.x || area[vec.y][vec.x] != to_fill)
		return ;
	area[vec.y][vec.x] = 'F';
	fill(area, size, (t_point){vec.x - 1, vec.y}, to_fill);
	fill(area, size, (t_point){vec.x + 1, vec.y}, to_fill);
	fill(area, size, (t_point){vec.x, vec.y - 1}, to_fill);
	fill(area, size, (t_point){vec.x, vec.y + 1}, to_fill);
}
