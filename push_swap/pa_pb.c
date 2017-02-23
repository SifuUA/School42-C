#include "push_swap.h"

void	pa(t_d_linklst *list_a, t_d_linklst *list_b)
{
	t_node	*tmp;

	if (list_b->size == 0)
		return ;
	push_front(list_a, list_b->head->value);
	del_node(list_b, list_b->head);
	put("pa");
}

void	pb(t_d_linklst *list_a, t_d_linklst *list_b)
{
	t_node	*tmp;

	if (list_a->size == 0)
		return ;
	push_front(list_b, list_a->head->value);
	del_node(list_a, list_a->head);
	put("pb");
}

