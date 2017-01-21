#include "ft_printf.h"

int		find(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	memory_allocate(t_pf *st)
{
	st->flag = ft_strnew(5);
	st->size = ft_strnew(2);
}
