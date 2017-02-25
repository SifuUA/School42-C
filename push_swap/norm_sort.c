#include "push_swap.h"

void    replace_to_a(t_d_linklst *list_a, t_d_linklst *list_b)
{
	while (list_b->size > 0)
		pa(list_a, list_b);
}

void    replace_to_b(t_d_linklst *list_a, t_d_linklst *list_b)
{
	size_t  i;

	while (list_a->size > 5)
	{
		i = 0;
		get_min(list_a);
		while (i < list_a->elem_pos - 1)
		{
			if (list_a->elem_pos >= list_a->size / 2)
				ra(list_a);
			else
				rra(list_a);
			i++;
		}
		pb(list_a, list_b);
	}
	little_sort(list_a, list_b);
}

void    check(t_d_linklst *list)
{
	if (list->head > list->head->next)
		sa(list);
	else if (list->tail < list->tail->prev && list->tail > list->head)
	{
		rra(list);
		rra(list);
		sa(list);
		ra(list);
		ra(list);
	}
	else if (list->head > list->head->next && list->tail < list->head)
		ra(list);
	else if (list->tail < list->head && list->tail < list->tail->prev)
		rra(list);
}

void    norm_sort(t_d_linklst *list_a, t_d_linklst *list_b)
{
	check(list_a);
	if (is_sort(list_a))
		return ;
	replace_to_b(list_a, list_b);
	replace_to_a(list_a, list_b);

}

