/*
 * c24_recursive_sum: A smaller problem and a base case
 *
 * Recursion means that a function calls itself with a smaller problem. Each
 * call waits for the smaller call's result before completing its own result.
 * A base case finishes without making another recursive call.
 *
 * Trace of the mathematical sum:
 *     sum(3) = 3 + sum(2)
 *     sum(2) = 2 + sum(1)
 *     sum(1) = 1 + sum(0)
 *     sum(0) = 0
 * Returning from those calls produces 1, then 3, then 6.
 *
 * Two decisions are necessary: what to return at the base case, and how to
 * reduce the argument toward it. Repeating the same argument creates more
 * calls without progress. Inputs are between 0 and 100 in this exercise.
 *
 * GOAL: Make recursive_sum return the sum of integers from 1 through n
 * recursively. Examples: 3 -> 6; 1 -> 1; 0 -> 0.
 */

int	recursive_sum(int n)
{
	return (n);
}
