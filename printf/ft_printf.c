ft_strrchr.c/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:44:18 by okres             #+#    #+#             */
/*   Updated: 2017/02/02 15:32:03 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	 		ft_printf(const char * restrict format, ...)
{
	va_list 		vl;
	static t_pf 	*st;
	size_t			count;
	int				i;

	i = 0;
	va_start (vl, format);
	st = (t_pf *)malloc(sizeof(t_pf));
	memory_allocate(st);
	st->str = (char*) format;
	while (*(st->str))
	{
		if (*(st->str) == '%')
		{
			(st->str)++;
			if (fill_struct(st, vl) == 0)
				modif_buff(st);
			break;
		}
		else
		{
			st->buffer[ft_strlen(st->buffer)] = *(st->str);
			i++;
		}
		(st->str)++;
	}
    
	//printf("f %s\n", st->flag);
   // printf("w %d\n", st->width);
    //printf("p %d\n", st->precision);
   // printf("s %s\n", st->size);
   // printf("c %c\n", st->specifier);
    ft_putstr(st->buffer);
    //ft_putnbr(ft_atoi(st->buffer));
	return (ft_strlen(st->buffer) + i);
}
