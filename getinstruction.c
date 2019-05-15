#include "monty.h"
/**
 * getinstruction - get the instruction function
 * @opcode: name of the instruction
 */
void (*getinstruction(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i_struct = 0;
	instruction_t instructions[] = {
		{"push", push_handler},
		{"pall", env_handler},
		{NULL, NULL}
	};

	while (instructions[i_struct].opcode != NULL)
	{
		if (_str_cmp(opcode, instructions[i_struct].opcode))
		{
			return (instructions[i_struct].f);
		}
		i_struct++;
	}
	return (NULL);
}