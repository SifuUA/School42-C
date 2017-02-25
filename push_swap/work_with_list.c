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
		exit(OUT_OF_MEM);
	node->value = value;
	node->next = NULL;
	node->prev = list->tail;
	if (list->tail)
		list->tail->next = node;
	list->tail = node;
	if (list->head == NULL)
		list->head = node;
	list->size++;
}

void 			del_node(t_d_linklst *list, t_node *node)
{
	t_node	*tmp;

	if (node)
	{
		tmp = node->next;
		free(node);
		list->head = tmp;
		free(tmp);
		list->size--;
	}
}

void            printList(t_d_linklst *list)
{
	t_node  *tmp;

	tmp = list->head;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
