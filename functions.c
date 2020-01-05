#include "monty.h"
/**
 * free_list - frees memory of a list
 * @head: pointer to head of singly linked list
 *
 * Return: No Return
 */
void free_list(stack_t *head)
{
	if (head)
	{
		free_list(head->next);
		free(head);
	}
}

/**
 *_push - push an int in the linked list
 *@stack: linked list with values
 *@line_number: line number of the command
 *
 *Return: Nothing, it's a void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (!new)
		write_errors(3, line_number);
	tmp = *stack;
	new->n = vglobal.n;
	if (!tmp)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		vglobal.status = 1;
		return;
	}
	new->prev = tmp->prev;
	new->next = tmp;
	*stack = new;
	vglobal.status = 1;
}

/**
 *_pall - print all the linked list
 *@stack: linked list with values
 *@line_number: line number of the command
 *
 *Return: Nothing, it's a void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (stack && tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	vglobal.status = 1;
}
