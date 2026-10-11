/*
 * first_word: Program arguments and a word boundary
 *
 * main receives argc and argv from the operating system. argv[0] names the
 * program; argv[1] is the first user argument, which can contain spaces when
 * quoted in the shell. Validate argc before accessing that argument.
 *
 * Example:
 *     ./first_word "  red blue" has argc == 2.
 *     The two leading spaces are not part of the first word.
 *     The first word consists of the three bytes r, e, d.
 *
 * A word ends at a space, tab, or the string terminator. Locate its
 * beginning and end independently from printing it. write(1, &c, 1) writes
 * one byte and adds no newline automatically. An empty or separator-only
 * input still needs the program's newline.
 *
 * GOAL: Repair first_word to print only the first word and a newline. With
 * an argument count other than one user argument, print just a newline. See
 * SUBJECT.md for the contract.
 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
