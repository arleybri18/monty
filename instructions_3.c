#include "monty.h"
/**
 *mod_handler - div the data of the top to second element
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */

void mod_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_node = *stack;
	int len = 0;

	while (aux_node)
	{
		len++;
		aux_node = aux_node->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux_node = (*stack)->next;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	free(*stack);
	aux_node->prev = NULL;
	(*stack) = aux_node;
}
