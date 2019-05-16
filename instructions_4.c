#include "monty.h"

/**
 *rotr_handler - rotate all stack.
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */
void rotr_handler(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	reverse_handler(stack, line_number);
	rotl_handler(stack, line_number);
	reverse_handler(stack, line_number);
}
/**
 *reverse_handler - rotate all stack.
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */
void reverse_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_i = *stack, *aux_f = *stack;
	int  aux_n;
	(void)line_number;

	if (*stack)
	{
		while (aux_f->next)
		 	aux_f= aux_f->next;
		while (aux_i != aux_f && aux_f->next != aux_i)
		{
			aux_n = aux_i->n;
			aux_i->n = aux_f->n;
			aux_f->n = aux_n;
			aux_i = aux_i->next;
			aux_f = aux_f->prev;
		}
	}
}
