#include "ft_printf.h"

void	free_s(t_pf *st)
{
	st->width = 0;
	st->precision = 0;
	ft_bzero(st->flag, ft_strlen(st->flag));
	st->znak = 0;
	ft_bzero(st->size, ft_strlen(st->size));
	st->specifier = '\0';
}
