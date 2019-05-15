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
	line = str_concat("", linevalue);
	line = strtok(line, " ");
	if (line != NULL)
	{
		/*handle if the line is empty*/
		if (line[0] != '\n')
		{
			execute.f = getinstruction(line);
			if (execute.f)
				execute.f(head, line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction\n", line_number);
				free(line);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);
}
