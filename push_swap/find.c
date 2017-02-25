#include "push_swap.h"

T       get_min(t_d_linklst *list)
{
	t_node  *tmp;
	T       min;

	tmp = list->head;
	min = list->head->value;
	list->elem_pos = 0;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
		list->elem_pos++;
	}
	return (min);
}