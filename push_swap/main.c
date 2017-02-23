#include "push_swap.h"

static  void    write_in_list(t_d_linklst *list, char **s)
{
	T   i;
	T   j;
	T   tmp;

	i = 1;
	tmp = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			tmp = ft_atoi(s[i]);
			if (ft_strcmp(ft_itoa((int)tmp), s[i]) == 0)
				push_front(list, tmp);
			else
				exit(1);
			j++;
		}
		i++;
	}
}

static  int     check_if_num(char **s)
{
	T   i;
	T   j;

	i = 0;
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
			exit (1);
		write_in_list(list_a, argv);
	}
	return (0);
}