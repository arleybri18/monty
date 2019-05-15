
#include "monty.h"

char *linevalue = NULL;

int main(int argc, char *argv[])
{
	struct stat st;
	if (argc == 2)
	{
		if (stat(argv[1], &st) != 0)
		{
			write(STDERR_FILENO,"USAGE: monty file\n", 18);
			exit(EXIT_FAILURE);
		}
		read_file(argv[1]);
	}
	else
	{
		write(STDERR_FILENO,"USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	return (0);
}
