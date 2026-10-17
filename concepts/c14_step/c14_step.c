/*
 * c14_step: Direction as a small piece of state
 *
 * A range traversal needs a direction as well as a stopping point. A step of
 * +1 moves toward larger integers; a step of -1 moves toward smaller ones.
 * Keeping the step separate lets the same update describe both traversals.
 *
 * Example:
 *     Starting at 4, repeatedly adding -1 gives 4, 3, 2, 1.
 *     Starting at 1, repeatedly adding +1 gives 1, 2, 3, 4.
 * Adding the wrong sign moves farther away from the target.
 *
 * Direction is not the number of values to generate. Equal endpoints need no
 * movement to produce their single value, but the function still needs a
 * defined return value. This exercise chooses +1 for that case.
 *
 * GOAL: Make step return +1 when a <= b and -1 when a > b. Examples: (1, 4)
 * -> +1; (4, 1) -> -1; (2, 2) -> +1.
 */

int	step(int a, int b)
{
	if (a > b)
		return (-1);
	return (1);
}
