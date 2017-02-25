#include "push_swap.h"

void    replace_to_a(t_d_linklst *list_a, t_d_linklst *list_b)
{

}

void    replace_to_b(t_d_linklst *list_a, t_d_linklst *list_b)
{

}

void    check(t_d_linklst *list)
{
	if (list->head > list->head->next)
		sa(list);
	else if (list->tail < list->tail->prev && list->tail > list->head)
		rra(list);
		rra(list);
		sa(list);
		ra(list);
		ra(list);
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

