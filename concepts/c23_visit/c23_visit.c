/*
 * c23_visit: A function pointer lets the caller choose an operation
 *
 * A callback parameter refers to a function that the caller supplied. Its
 * type specifies what arguments you must pass. Here the callback expects the
 * address of one int, so it can change that element directly.
 *
 * Example:
 *     void double_one(int *p) { *p = *p * 2; }
 *     int value = 3;
 *     double_one(&value);     // value becomes 6
 * A function pointer with that signature can refer to double_one. Calling it
 * with an integer value instead of an address would be the wrong type.
 *
 * An array supplies several separate element addresses. Invoke the callback
 * once for each of the n elements, including index zero and excluding index
 * n. A zero-length visit makes no calls.
 *
 * GOAL: Make visit apply f to every element of the int array, using each
 * element's address. The callback decides the change; visit must not
 * hardcode an operation.
 */
#include <stdlib.h>
#include <string.h>

void	visit(int *a, int n, void (*f)(int *))
{
	(void)a;
	(void)n;
	(void)f;
	(void)a;
	(void)n;
	(void)f;
}
