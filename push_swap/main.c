#include "push_swap.h"

static  int     check(char *s)
{
	T tmp;

	tmp = ft_atoi(s);
	if ((tmp <= 2147483647 && tmp >= -2147483648) || )
}

void            write_in_list(char **argv, int argc, t_d_linklst *list_a)
{
	T     i;
	char    **str_num;

	i = argc;
	while (i > 0)
	{
		check(argv[i]);
	}
	str_num = ft_strsplit(argv, ' ');
	while (*str_num[i])
	{
		if (ft_atoi(*str_num[i]))
		{

		}
	}
	while (argc > 0)
	{
		push_front(list_a, argv[argc]);
	}

}

int             main(int argc, char **argv)
{
	t_d_linklst     *list_a;
	t_d_linklst     *list_b;

	list_a = creat();
	list_b = creat();

	if (argc > 1)
	{
		write_in_list(**argv, argc, list_a);
	}
	return (0);
}