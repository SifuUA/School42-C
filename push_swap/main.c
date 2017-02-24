#include "push_swap.h"

static int      find_same(T num, t_d_linklst *list)
{
	t_node  *tmp;

	tmp = list->head;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void     write_in_list(t_d_linklst *list, char **s)
{
	T   i;
	T   tmp;

	i = 1;
	tmp = 0;
	while (s[i])
	{
		tmp = ft_atoi(s[i]);
		if (ft_strcmp(ft_itoa((int)tmp), s[i]) == 0 && find_same(tmp, list) == 0)
			push_front(list, tmp);
		else
		{
			put("Error");
			exit(2);
		}
		i++;
	}
}

static int      check_if_num(char **s)
{
	T   i;
	T   j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!ft_isdigit(s[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int             main(int argc, char **argv)
{
	t_d_linklst     *list_a;
	t_d_linklst     *list_b;
	char            **s;

	list_a = creat();
	list_b = creat();
	s = NULL;
	if (argc > 1)
	{
		if (check_if_num(argv))
		{
			put("Error");
			exit(1);
		}
		write_in_list(list_a, argv);
	}
	else
		write(1, "\n", 1);
	return (0);
}