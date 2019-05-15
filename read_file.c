#include "monty.h"

/**
 * read_file - read a file sended
 *
 * @filename: file to read
 * Return: number of characters readed
 */
ssize_t read_file(const char *filename)
{
	FILE *fd;
	unsigned int line_number = 1;
	int read_text;
	size_t n = 0;
	stack_t *head = NULL;

	/*validate if filename is don't  send*/
	if (filename == NULL)
		return (0);
	/*open file read only*/
	fd = fopen(filename, "r");
	/*validate if open file fail */
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}

	/*read file*/
	while ((read_text = getline(&linevalue, &n, fd) != -1))
	{
		/*call to build the instruction*/
		build_instruction(&head, line_number);
		line_number++;
	}
	free(linevalue);
	return (read_text);
}
