#include "monty.h"

/**
 *push_handler - add node at the beginning of a list
 *
 *@stack: head of the list
 *@line_number: number of the line with the instruction
 *Return: Nothing
 */

void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *line = NULL;
	(void) line_number;

	/*allocate memory for a new node*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/*put data in node,-- validate how send this value*/
	line = strtok(linevalue, " \n");
	line = strtok(NULL, " \n");
	if (line && is_number(line))
	{
		new_node->n = atoi(line);
	}
	else
	{
		printf("saliendo\n");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->next = *stack;
	new_node->prev = NULL;
	/*validate if a list is not empty, point tp new node*/
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 *pall_handler - print the stack
 *
 *@stack: head of the list
 *@line_number: number of line with the instruction
 *Return: Nothing
 */

void pall_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	(void)line_number;

	aux = *stack;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 *pint_handler - print the data on the top of the stack
 *
 *@stack: head of the list
 *@line_number: number of line with the instruction
 *Return: Nothing
 */

void pint_handler(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 *pop_handler - delete a top of the stack
 *
 *@stack: head of the list
 *@line_number: number of line with the instruction
 *Return: Nothing
 */

void pop_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *aux_node = *stack;
	unsigned int counter_idx;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	counter_idx = 0;
	/*validate lenght of the list*/
	while (aux_node)
	{
		counter_idx++;
		aux_node = aux_node->next;
	}
	if (counter_idx == 1)
	{
		free(current);
		*stack = NULL;
	}
	else
	{
		*stack = current->next;
		(*stack)->prev = NULL;
		free(current);
	}
}

/**
 *nop_handler - do nothing
 *
 *@stack: head of the list
 *@line_number: number of line with the instruction
 *Return: Nothing
 */

void nop_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	;
}
