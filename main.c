#include "monty.h"

char *linevalue = NULL;
/**
 * main - function main
 *
 *@argc: number of arguments
 *@argv: arguments passed to the function
 *Return: 0 its ok
 */

int main(int argc, char *argv[])
{
	struct stat st;

	if (argc == 2)
	{
		if (stat(argv[1], &st) != 0)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		read_file(argv[1]);
	}
	else
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	return (0);
}
