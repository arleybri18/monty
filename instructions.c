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

	/*allocate memory for a new node*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/*put data in node,-- validate how send this value*/
	new_node->n = 1;
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

	aux = *stack;


	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
