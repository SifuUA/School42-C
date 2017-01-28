#include "ft_printf.h"

void		mod_zer(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak)
{
	char	*tmp;
	int		i;

	i = ft_strlen(ptr);
	if (find(st->flag, '0') == 1)
	{
		if (st->precision < ft_strlen(st->buffer) && st->precision != 0)
			tmp = ft_strjoin(ptr, st->buffer);
		else if (st->precision > ft_strlen(st->buffer) && st->precision < st->width)
			tmp = ft_strjoin(ptr, st->buffer);
		else
		{
			while (--i >= 0)
			ptr[i] = '0';
			tmp = ft_strjoin(ptr, st->buffer);
		}
			st->buffer = tmp;
		if (znak < 0)
		{
			tmp = ft_strjoin("-", st->buffer);
			st->buffer = tmp;
		}
	}
}
void		mod_min(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak)
{
	char	*tmp;
	char	*tmp1;

	if (find(st->flag, '-') == 1)
	{
		if (st->width > st->precision)
		{
			tmp = ft_strjoin(st->buffer, spaces);
			free(st->buffer);
			st->buffer = ft_strjoin(zeros, tmp);
			ft_strdel(&tmp);
		}
		else
		{
			tmp = ft_strjoin(ptr, st->buffer);
			free(st->buffer);
			st->buffer = tmp;
		}
	}
	else 
		mod_zer(st, spaces, zeros, ptr, znak);		
}


void		mod_sp(t_pf *st, char *spaces, char *zeros, char *ptr, long long znak)
{
	/*else if (find (st->flag, ' ') == 1)
	{
		i = ft_strlen(st->buffer);
		if (find(st->flag, '-') == 1 && st->buffer[i - 1] == ' ')
		{
			st->buffer[i - 1] = '\0';
			tmp = ft_strjoin(" ", st->buffer);
			st->buffer = tmp;
		}
		else if (ft_strlen(ptr) > 0)
		{
			tmp = ft_strjoin(ptr, st->buffer);
			st->buffer = tmp;
		}
	}*/
}

void		modif_buff(t_pf *st)
{
	char		*spaces;
	char		*zeros;
	char		*ptr;
	long long	znak;

	spaces = get_space(st);
	zeros = get_zero(st);
	znak = ft_atoi(st->buffer);
	if(znak < 0)
		(st->buffer)++;
	ptr = ft_strjoin(spaces, zeros);
	if (find(st->flag, '-') == 1 || find(st->flag, '0') == 1)
		mod_min(st, spaces, zeros, ptr, znak);
	if (find(st->flag, '+') == 1)
		mod_plus(st, spaces, zeros, ptr, znak);
	else if (find(st->flag, ' ') == 1)
		mod_sp(st, spaces, zeros, ptr, znak);
	//if (st->flag[0] == '\0')
	//	st->buffer = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
}
