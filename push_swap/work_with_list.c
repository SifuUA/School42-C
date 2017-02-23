#include "push_swap.h"

t_d_linklst     *creat(void) // создание листа
{
	t_d_linklst *tmp;

	tmp = (t_d_linklst *)malloc(sizeof(t_d_linklst));
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

void            push_front(t_d_linklst *list, int value) // добавление в глову
{
	t_node  *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		exit(1);
	node->value = value;
	node->next = list->head;
	node->prev = NULL;
	if (list->head)
		list->head->prev = node;
	if (list->tail == NULL)
		list->tail = node;
	list->head = node;
	list->size++;
}

void 			del_node(t_d_linklst *list, s_node *node)
{
	s_node	*tmp;

	if (node)
	{
		tmp = node->next;
		free(node);
		list->head = tmp;
		free(tmp);
		list->size--;
	}
}
