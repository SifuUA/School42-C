#include "push_swap.h"

// sa
void    sa(t_d_linklst *list)
{
	T tmp;

	if (list->size > 1)
	{
		tmp = list->head->value;
		list->head->value = list->head->next->value;
		list->head->next->value = tmp;
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
