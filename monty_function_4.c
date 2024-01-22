#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - Rotates top value of stack_t list to bottom.
 * @stack: pointer to top mode node of stack_t list.
 * @line_number: current line number of a Monty file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *btm;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	btm = (*stack)->next;
	while (btm->next != NULL)
		btm = btm->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	btm->next = top;
	top->next = NULL;
	top->prev = btm;

	(void)line_number;
}

/**
 * monty_rotr - Rotates bottom value of a stack_t list to top.
 * @stack: pointer to top mode node of a stack_t list.
 * @line_number: current line number of a Monty file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *btm;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	btm = (*stack)->next;
	while (btm->next != NULL)
		btm = btm->next;

	btm->prev->next = NULL;
	(*stack)->next = btm;
	btm->prev = *stack;
	btm->next = top;
	top->prev = btm;

	(void)line_number;
}

/**
 * monty_stack - Converts queue to stack.
 * @stack: pointer to top mode node of stack_t list.
 * @line_number: current line number of Monty file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Converts stack to queue.
 * @stack: pointer to the top mode node of a stack_t list.
 * @line_number: current line number of a Monty file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
