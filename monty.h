#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void (*getinstruction(char *opcode))(stack_t **, unsigned int);
void push_handler(stack_t **stack, unsigned int line_number);
void pall_handler(stack_t **stack, unsigned int line_number);
void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void nop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
void sub_handler(stack_t **stack, unsigned int line_number);
void div_handler(stack_t **stack, unsigned int line_number);
void mul_handler(stack_t **stack, unsigned int line_number);
void mod_handler(stack_t **stack, unsigned int line_number);
void comment_handler(stack_t **stack, unsigned int line_number);
void pchar_handler(stack_t **stack, unsigned int line_number);
void pstr_handler(stack_t **stack, unsigned int line_number);
void rotl_handler(stack_t **stack, unsigned int line_number);
ssize_t read_file(const char *filename);
void  build_instruction(stack_t **head, unsigned int line_number);
extern char *linevalue;
char is_digit(char c);
char is_number(char *str);
char *str_concat(char *s1, char *s2);
char _str_cmp(char *str1, char *str2);
void free_list(stack_t *head);
#endif /*MONTY_H*/
