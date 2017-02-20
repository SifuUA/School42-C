#include "push_swap.h"

void    sa(int *stack, int size)
{
	int tmp;

	tmp = 0;
	if (stack && size > 1)
	{
		tmp = stack[size - 1];
		stack[size - 1] = stack[size - 2];
		stack[size - 2] = tmp;
	}
}

void    sb(int *stack, int size)
{
	int tmp;

	tmp = 0;
	if (stack && size > 1)
	{
		tmp = stack[size - 1];
		stack[size - 1] = stack[size - 2];
		stack[size - 2] = tmp;
	}
}

void    ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	sa(stack_a, size_a);
	sb(stack_b, size_b);
}
