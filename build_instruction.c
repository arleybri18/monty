#include "monty.h"

/**
 * read_lines - read line by line and analize structure
 *
 * @text: text to read
 * Return: number of characters readed
 */
void build_instruction(int line_number)
{
	char *line = NULL;

	printf("%s\n", linevalue);
	/*iterate over array to split the opcode and data*/
	line = strtok(linevalue, " ");
	if (line != NULL)
		printf("command is %s line %d\n", line, line_number);
	while (line)
	{
		line = strtok(NULL, " ");
		if (line != NULL)
			printf("command is %s line %d\n", line, line_number);
	}
}
