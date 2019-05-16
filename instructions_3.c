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


/**
 *comment_handler - Do anything if a lines is a comment
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */

void comment_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 *pchar_handler - Print a char ASCII value
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */

void pchar_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int len = 0;

	while (aux)
	{
		len++;
		aux = aux->next;

	}
	if (len == 0)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n <= 0 || (*stack)->n > 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", (*stack)->n);
}

/**
 *pstr_handler - Print a chars ASCII value of the all list
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */

void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	(void)line_number;

	while (aux)
	{
		if (aux->n <= 0 || aux->n > 128)
			exit(EXIT_SUCCESS);
		else
			printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}

/**
 *rotl_handler - rotates the stack to the bottom.
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */
void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int first_n;
	(void)line_number;

	if (*stack)
	{
		first_n = (*stack)->n;
		while (aux->next)
		{
			aux->n = aux->next->n;
			aux = aux->next;
		}
		aux->n = first_n;
	}
}
