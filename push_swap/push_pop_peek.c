#include "push_swap.h"

void    push(t_stack *stack, T value)
{
	if (stack->top >= stack->size)
		resize(stack);
	stack->data[stack->top] = value;
	stack->top++;
}