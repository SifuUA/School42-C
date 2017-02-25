#include "push_swap.h"

void    choos_sort(t_d_linklst *list_a, t_d_linklst *list_b)
{
	if (list_a->size == 2)
	{
		if (list_a->head > list_a->tail)
			sa(list_a);
	}
	list_b = NULL;
	/*else if (list_a->size == 3)
		sort_three(list_a);
	else if (list_a->size >= 4  list_a->size <= 5)
		sort_four_five(list_a, list_b);*/

}
