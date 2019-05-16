#include "monty.h"

/**
 *swap_handler - swap data at the top of the list
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */

void swap_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_node = NULL;
	int aux = 0, len = 0;

	aux_node = *stack;
	while (aux_node)
	{
		len++;
		aux_node = aux_node->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = aux;


}
/**
 *add_handler - add the data of the top to second element
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */

void add_handler(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux_node = (*stack)->next;
	(*stack)->next->n += (*stack)->n;
	free(*stack);
	aux_node->prev = NULL;
	(*stack) = aux_node;
}
