#include "monty.h"

/**
 * read_file - read a file sended
 *
 * @filename: file to read
 * @fsize: size of buffer to read
 * Return: number of characters readed
 */
ssize_t read_file(const char *filename)
{
	FILE *fd;
	int line_number = 1, read_text;
	char *line = NULL;
	char delim[] = "\n";
	size_t n = 0;

	/*validate if filename is don't  send*/
	if (filename == NULL)
		return (0);
	/*open file read only*/
	fd = fopen(filename, "r");
	/*validate if open file fail */
	if (fd == NULL)
	{
		exit(EXIT_FAILURE);
	}

	/*read file*/
	while (read_text = getline(&linevalue, &n, fd) != -1)
	{
		/*
		  to manipulate text with strtok to set linevalue
		 */
		build_instruction(line_number);
		printf("%s\n", linevalue);
		line_number++;
	}
	/*validate if read file fail*/
	free(linevalue);
	return (read_text);
}
