#include "monty.h"

/**
 * build_instruction - build the instructions
 *
 * @head: head of the stack
 * @line_number: number of the line
 * Return: Nothing
 */
void build_instruction(stack_t **head, unsigned int line_number)
{
	char *line = NULL;
	instruction_t execute;

	/*iterate over array to split the opcode and data*/
	line = strtok(linevalue, " ");
	if (line != NULL)
	{
		execute.f = getinstruction(line);
		if (execute.f)
			execute.f(head, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
}
