#include "push_swap.h"

void    swap(T *a, T *b)
{
	T tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_node  *partition(t_node *head, t_node *tail)
{
	t_node  *small;
	t_node  *piv;
	t_node  *curr;

	if (head == tail)
		return (head);
	small = head;
	piv  = tail;
	curr = head;
	while(curr != NULL && curr != tail)
	{
		if(curr->value < piv->value)
		{
			swap(&(small->value), &(curr->value));
			small = small->next;
		}
		curr = curr->next;
	}
	swap(&(piv->value), &(small->value));
	return small;
}

void    quick_sort(t_node *head, t_node *tail)
{
	t_node  *tmp;

	if (tail != NULL && tail != head && head != tail->next)
	{
		tmp = partition(head, tail);
		quick_sort(head, tmp->prev);
		quick_sort(tmp->next, tail);
	}
}

