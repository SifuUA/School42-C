#include "ft_printf.h"

void		mod_zer(t_pf *st, char *spaces, char *zeros, char *ptr)
{
	char	*tmp;
	int		i;

	i = ft_strlen(ptr);
	if (find(st->flag, '0') == 1)
	{
		if (zeros != NULL && ft_strlen(zeros) > 0)
		{
			tmp = ft_strjoin(ptr, st->buffer);
			ft_strdel(&(st->buffer));
		}
		else
		{
			while (--i >= 0)
				ptr[i] = '0';
			tmp = ft_strjoin(ptr, st->buffer);
			ft_strdel(&(st->buffer));
		}
	}
	
}
void		mod_min(t_pf *st, char *spaces, char *zeros, char *ptr)
{
	char	*tmp;
	
	if (find(st->flag, '-') == 1)
	{
		if (!zeros)
		{
			tmp = ft_strjoin(st->buffer, ptr);
			ft_strdel(&(st->buffer));
		}
		else
		{
			tmp = ft_strjoin(ptr, st->buffer);
			ft_strdel(&(st->buffer));
		}
	}
	else 
		mod_zer(st, spaces, zeros, ptr);		
	st->buffer = tmp;
}


void		mod_sp(t_pf *st, char *spaces, char *zeros, char *ptr)
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
	char	*spaces;
	char	*zeros;
	char	*ptr;

	spaces = get_space(st);
	zeros = get_zero(st);
	ptr = ft_strjoin(spaces, zeros);
	if (find(st->flag, '-') == 1 || find(st->flag, '0') == 1)
		mod_min(st, spaces, zeros, ptr);
	if (find(st->flag, '+') == 1)
		mod_plus(st, spaces, zeros, ptr);
	else if (find(st->flag, ' ') == 1)
		mod_sp(st, spaces, zeros, ptr);
	if (st->flag[0] == '\0')
		st->buffer = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
}
