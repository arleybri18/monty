#include "monty.h"

/**
 * free_list - free a list
 * @head: Head of the list
 */
void free_list(stack_t *head)
{
	if (head == NULL)
		;
	else
	{
		free_list(head->next);
		free(head);
	}
}
