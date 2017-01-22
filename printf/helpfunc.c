#include "ft_printf.h"

char	*upper_case(char **str)
{
	char	*ptr;

	ptr = *str;
	while (ptr)
	{
		if (**str >= 'a' && **str <= 'z')
			*ptr = *ptr + 32;
		ptr++;
	}
	return (*str);
}

int		find_mod(char *a, char *b, char *c, char tmp)
{
	int i;

	i = 0;
	while (a[i])
	{
		if (a[i] == tmp)
			return (1);
		i++;
	}
	i = 0;
	while (b[i])
	{
		if (b[i] == tmp)
			return (1);
		i++;
	}
	i = 0;
	while (c[i])
	{
		if (a[i] == tmp)
			return (1);
		i++;
	}
	return (0);
}

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
	st->width = 0;
	st->precision = 0;
	st->flag = ft_strnew(5);
	st->size = ft_strnew(2);
	st->buffer = ft_strnew(5);
}
