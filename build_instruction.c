#include "monty.h"

/**
 * read_lines - read line by line and analize structure
 *
 * @text: text to read
 * Return: number of characters readed
 */
void build_instruction(stack_t **head, unsigned int line_number)
{
	char *line = NULL;
	instruction_t execute;

	printf("%s\n", linevalue);
	/*iterate over array to split the opcode and data*/
	line = strtok(linevalue, " ");
	if (line != NULL)
	{
		execute.f = getinstruction(line);
		if (execute.f)
			execute.f(head, line_number);
		else{
			printf("NO existe el comando");
			exit(EXIT_FAILURE);
		}
	}
}
