#include "inc.h"

int		ft_list_size(t_list *begin_list)
{
	t_list 	*ptr;
	int		count;

	ptr = begin_list;
	count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

