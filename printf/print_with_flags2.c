#include "ft_printf.h"

void		mod_plus2(t_pf *st, char *spaces, char *zeros, char *ptr)
{
	char	*tmp;
	
	(st->buffer)++;
	if (find(st->flag, '-'))
	{
		tmp = ft_strjoin("-", st->buffer);
		tmp[ft_strlen(tmp)] = '\0';
		st->buffer = tmp;
	}
		else if (ft_strlen(spaces) > 0 && zeros == NULL && spaces != NULL)
		{
			tmp = ft_strjoin("+", st->buffer);
			ft_strdel(&(st->buffer));
			ptr++;
			st->buffer = ft_strjoin(ptr, tmp);
			ft_strdel(&(tmp));
		}
		else
			mod_plus1(st, spaces, zeros, ptr);
}

void		mod_plus1(t_pf *st, char *spaces, char *zeros, char *ptr)
{
	char	*tmp;
	char	*tmp1;

	if (zeros != NULL && ft_strlen(zeros) > 0)
	{
		tmp = ft_strjoin("+", zeros);
		ft_strdel(&zeros);
		spaces++;
		tmp1 = ft_strjoin(spaces, tmp);
		ft_strdel(&tmp);
		tmp = ft_strjoin(tmp1, st->buffer);
		ft_strdel(&(st->buffer));
		ft_strdel(&tmp1);
		st->buffer = tmp;
	}
	else
	{
		tmp = ft_strjoin("+", st->buffer);
		ft_strdel(&(st->buffer));
		st->buffer = tmp;
	}
}

void		mod_plus(t_pf *st, char *spaces, char *zeros, char *ptr)
{
	char	*tmp;

	if (ft_atoi(st->buffer) > 0)
	{
		if (find(st->flag, '-'))
		{
			tmp = ft_strjoin("+", st->buffer);
			ft_strdel(&(st->buffer));
			tmp[ft_strlen(tmp) - 1] = '\0';
			st->buffer = tmp;
		}
		else if (ft_strlen(spaces) > 0 && zeros == NULL && spaces != NULL)
		{
			tmp = ft_strjoin("+", st->buffer);
			ft_strdel(&(st->buffer));
			ptr++;
			st->buffer = ft_strjoin(ptr, tmp);
			ft_strdel(&(tmp));
		}
		else
			mod_plus1(st, spaces, zeros, ptr);
	}
	else
		mod_plus2(st, spaces, zeros, ptr);
}

