/*
 * c22_in_bounds: Dimensions are exclusive upper boundaries
 *
 * A matrix of width w and height h uses x for the column and y for the row.
 * Counting starts at zero, so the width itself is not a valid column index.
 *
 * Example for width 3 and height 2:
 *     valid x: 0, 1, 2
 *     valid y: 0, 1
 *     (2, 1) is inside; (3, 1) and (-1, 0) are outside.
 *
 * Membership requires all four boundaries to hold at once. An OR between
 * them would accept a point that satisfies only one boundary. Check a
 * coordinate before using it in an expression such as rows[y][x]. With a
 * zero width or height, there is no valid coordinate.
 *
 * GOAL: Make in_bounds return true exactly when (x, y) is inside a matrix of
 * dimensions w and h. Reject negative coordinates and indexes equal to or
 * greater than their dimension.
 */

int	in_bounds(int x, int y, int w, int h)
{
	(void)x;
	(void)y;
	(void)w;
	(void)h;
	return (1);
}
