#include "push_swap.h"

void    sort_three(t_d_linklst *list_a, t_d_linklst *list_b)
{
	if (list_a->head->value > list_a->head->next->value &&
			list_a->head->value < list_a->tail)
		sa(list_a);
	else if (list_a->head->value > list_a->head->next->value &&
			list_a->tail->value > list_a->tail->prev->value)
		ra(list_a);
	else if (list_a->tail->value < list_a->tail->prev->value &&
			list_a->tail->value < list_a->head->value)
		rra(list_a);
	else if (list_a->head->value > list_a->tail &&
			list_a->tail->value < list_a->tail->prev->value)
	{
		sa(list_a);
		rra(list_a);
	}
	else if (list_a->head->value < list_a->tail->value &&
			list_a->tail->value < list_a->tail->prev->value)
	{
		rra(list_a);
		sa(list_a);
	}
}


void    sort_four_five(t_d_linklst *list_a, t_d_linklst *list_b)
{
	size_t i;
	size_t j

	i = 0;
	while (i < 2)
	{
		j = 0;
		get_min(list_a);
		while (j < list_b->elem_pos - 1)
		{
			if (list_a->elem_pos >= list_b->size / 2)
				ra(list_a;
			else
				rra(list_a);
			j++;
		}
		pb(list_a, list_b);
		i++;
	}
	little_sort(list_a, list_b);
}

void    little_sort(t_d_linklst *list_a, t_d_linklst *list_b)
{
	if (is_sort(list_a))
		return ;
	if (list_a->size == 2)
	{
		if (list_a->head > list_a->tail)
			sa(list_a);
	}
	else if (list_a->size == 3)
		sort_three(list_a, list_b);
	else if (list_a->size >= 4, list_a->size <= 5)
		sort_four_five(list_a, list_b);

}
