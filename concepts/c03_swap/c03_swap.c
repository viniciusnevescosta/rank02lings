/*
 * c03_swap: Changing an integer through its address
 *
 * A normal int parameter holds a copy of an integer. An int * parameter
 * holds the address of an integer owned by the caller. &x obtains that
 * address; *p accesses the integer stored there.
 *
 * Example:
 *     int score = 4;
 *     int *p = &score;
 *     *p = 7;              // score is now 7
 *     p = NULL;            // changes p, not score
 *
 * An overwrite destroys the previous value unless you saved it somewhere.
 * For a pair [4, 7], writing 7 into the first position immediately changes
 * the pair to [7, 7]. Think about which original value must remain available
 * for the second write.
 *
 * GOAL: Make swap exchange the two pointed integers. For a = 4 and b = 7,
 * the caller must see a = 7 and b = 4. Do not just exchange the local
 * pointer variables.
 */

void	swap(int *a, int *b)
{
	(void)a;
	(void)b;
}
