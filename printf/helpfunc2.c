#include "ft_printf.h"

int		check_flag(char *str, char *flags)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (find(flags, str[i]))
		{
			if (str[i] == '0' && ft_isdigit(str[i - 1]))
				;
			else
				count++;
		}
		i++;
	}
	return (count > 0 ? 1 : 0);

}

int		find_num(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int		two_perc(t_pf *st)
{
	char	*tmp;

	st->buffer = "%";
	return (find_num(st->str) ? 1 : 0);
}
