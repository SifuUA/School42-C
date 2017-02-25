#include "push_swap.h"

void       get_min(t_d_linklst *list)
{
	t_node  *tmp;
	T       min;
	T       i;

	i = 0;
	tmp = list->head;
	min = list->head->value;
	list->elem_pos = 0;
	while (tmp)
	{
		i++;
		if (tmp->value < min)
		{
			min = tmp->value;
			list->elem_pos = i;
		}
		tmp = tmp->next;
	}
}