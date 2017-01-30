#include "ft_printf.h"

int		get_width(t_pf *st)
{
	int w_str;
	
	if (st->width > st->precision && st->width > ft_strlen(st->buffer))
		w_str = st->width;
	else if (st->precision > st->width && st->precision > ft_strlen(st->buffer))
		w_str = st->precision;
	else
		w_str = ft_strlen(st->buffer);
	return(w_str);
}

char		*get_zero(t_pf *st)
{
	int		space_c;
	int		zero_c;
	char	*n_str;
	char	*tmp;
	int		i;
   	
	i = 0;
	n_str = NULL;
	if (st->precision > ft_strlen(st->buffer))
		space_c = get_width(st) - st->precision;
	else
		space_c = get_width(st) - ft_strlen(st->buffer);
	zero_c = get_width(st) - (space_c + ft_strlen(st->buffer));
	//printf("Z%d W%d S%d L%zu SL%s", zero_c, get_width(st), space_c, ft_strlen(st->buffer), st->buffer);
	if (zero_c > 0)
	{
		n_str = ft_strnew(zero_c);
		while (i < zero_c)
		{
			n_str[i] = '0';
			i++;
		}
		return (n_str);
	}
	return (n_str);
}

char		*get_space(t_pf *st)
{
	int		space_c;
	int		zero_c;
	char	*n_str;
	char	*tmp;
	int		i;
   	
	i = 0;
	n_str = NULL;
	if (st->precision > ft_strlen(st->buffer))
		space_c = get_width(st) - st->precision;
	else
		space_c = get_width(st) - ft_strlen(st->buffer);
	n_str = ft_strnew(space_c);
	while (i < space_c)
	{
		n_str[i] = ' ';
		i++;
	}
	return (n_str);
}