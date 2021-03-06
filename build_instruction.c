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
	char *aux, *line = NULL;
	instruction_t execute;

	/*iterate over array to split the opcode and data*/
	aux = str_concat("", linevalue);
	line = strtok(aux, " \t");
	if (line != NULL)
	{
		/*handle if the line is empty*/
		if (line[0] != '\n')
		{
			line = strtok(line, "\n");
			if (line[0] == '#')
				execute.f = getinstruction("#");
			else
				execute.f = getinstruction(line);
			if (execute.f)
				execute.f(head, line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
				free(aux);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(aux);
}
