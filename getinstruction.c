#include "monty.h"
/**
 * getinstruction - get the instruction function
 * @opcode: name of the instruction
 *
 * Return: Nothing
 */
void (*getinstruction(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i_struct = 0;
	instruction_t instructions[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"nop", nop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"sub", sub_handler},
		{"div", div_handler},
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
