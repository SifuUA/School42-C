#include "inc.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *ptr;
	t_list *ptr_n;
	t_list *tmp;

	ptr = *begin_list;
	while (ptr)
	{
		if (cmp(data_ref, ptr->data) == 0)
		{
			if (ptr == *begin_list)
				*begin_list = ptr->next;
			else
				ptr_n->next = ptr->next;
			tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
		else
		{
			ptr_n = ptr;
			ptr = ptr->next;
		}
	}
}
