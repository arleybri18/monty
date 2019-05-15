#include "monty.h"

char *linevalue = NULL;

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		read_file(argv[1]);
	}
	return (0);
}
