#include "push_swap.h"

stack_t     *creat_stack()
{
	t_stack *out;

	out = (t_stack *)malloc(sizeof(t_stack));
	if (out == NULL)
		exit(1);
	out->size = INIT_SIZE;
	out->data = malloc(out->size * sizeof(T));
	if (out->data == NULL)
	{
		free(out);
		exit(1);
	}
	out->top = 0;
	return (out);
}

void    delete_stack(t_stack **stack)
{
	free((*stack)->data);
	ft_strdel(stack);
}

void    resize(t_stack *stack)
{
	stack->size *= MULTIPLIER;
	if (stack->data)
		free(stack->data);
	stack->data = malloc(stack->size * sizeof(T));
	if (stack->data == NULL)
		exit(1);
}
