#include "ft_printf.h"

int	 		ft_printf(const char * restrict format, ...)
{
	va_list 		vl;
	static t_pf 	*st;
	size_t			count;
	int				i;
	int				j;
	char			*ptr;
	char			*ptr1;

	i = 0;
	j = 0;
	va_start (vl, format);
	st = (t_pf *)malloc(sizeof(t_pf));
	memory_allocate(st);
	st->str = ft_strdup((char*) format);
	while (*(st->str))
	{
		if (*(st->str) == '%')
		{
			(st->str)++;
			j = len_to_spec(st->str);
			/*if (j < 0)
			{
				st->buffer = va_arg(vl, char *);
				break;
			}*/
			ptr = ft_strdup(st->str);
			st->str[j] = '\0';
			if (fill_struct(st, vl) == 0)
				modif_buff(st);
			st->str = ptr + j;
			st->res = ft_strjoin(st->res, st->buffer);
			free_s(st);
		}
		else
		{
			j = lentoc(st->str, '%');
			ptr = ft_strsub(st->str, 0, j);
			st->res = ft_strjoin(st->res, ptr);
		(st->str) += j;
		}
	}
    ft_putstr(st->res);
	return (ft_strlen(st->res));
}
