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


int		print_buff(t_pf *st)
{
	int		str_w;
	int		num_l;
	int		space_c;
	int		zero_c;

	str_w = get_width(st);
	num_l = ft_strlen(st->buffer);
	space_c = str_w - st->precision;
	zero_c = str_w - space_c + num_l;
	while (space_c > 0)
	{
		ft_putchar(' ');
		space_c--;
	}
	while (zero_c > 0)
	{
		ft_putchar('0');
		zero_c--;
	}
	return (0);
}
