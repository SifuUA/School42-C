#include "ft_printf.h"

void		mod_zer_and_min(t_pf *st, char *spaces, char *zeros)
{
	int		i;
	char	*tmp;
	char	*ptr;
	
	i = 0;
	ptr = ft_strjoin(spaces, zeros);
	//printf("p%s",st->buffer );
	if (find(st->flag, '-') == 1)
	{
		tmp = ft_strjoin(st->buffer, ptr);
		free(st->buffer);
		st->buffer = tmp;
		ft_strdel(&tmp);
	printf("p%s",st->buffer );
	}
	else if (find(st->flag, '0') == 1)
	{
		i = ft_strlen(ptr);
		while (i - 1 >= 0)
		{
			i--;
			ptr[i] = '0';
		}
		tmp = ft_strjoin(ptr, st->buffer);
		st->buffer = tmp;
	}
}

void		mod_sp_and_plus(t_pf *st, char *spaces, char *zeros)
{
	/*if (find(st->flag, '+') == 1 && ft_atoi(st->buffer) > 0)
	{
		i = ft_strlen(ptr);
		if (find(st->flag, '-') == 1)
		{
			i = ft_strlen(st->buffer);
			if (st->buffer[i - 1] == ' ')
				st->buffer[i - 1] = '\0';
			tmp = ft_strjoin("+", st->buffer);
			st->buffer = tmp;

			free(tmp);
		}
		else if (i > 0 && )
		{
			//ptr[i - 1] = '+';
			st->buffer[0] = '+';
			//tmp = ft_strjoin(ptr,st->buffer);
			//st->buffer = tmp;
		}
	}
	else if (find (st->flag, ' ') == 1)
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

	spaces = get_space(st);
	zeros = get_zero(st);
	if (find(st->flag, '-') == 1 || find(st->flag, '0') == 1)
		mod_zer_and_min(st, spaces, zeros);
	if (find(st->flag, '+') == 1 || find(st->flag, ' ') == 1)
		mod_sp_and_plus(st, spaces, zeros);
	else
		st->buffer = ft_strjoin(ft_strjoin(spaces, zeros), st->buffer);
}
