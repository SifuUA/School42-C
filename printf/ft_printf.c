/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:44:18 by okres             #+#    #+#             */
/*   Updated: 2017/01/20 19:26:56 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	 		ft_printf(const char * restrict format, ...)
{
	va_list 		vl;
	static t_pf 	*st;
	size_t			count;

	va_start (vl, format);
	st = (t_pf *)malloc(sizeof(t_pf));
	st->str = (char*) format;
	while (*(st->str))
	{
		if (*(st->str) == '%')
		{
			(st->str)++;
			fill_struct(st, vl);
			print_buff(st);
		}
		else
			ft_putchar((*st->str));
		(st->str)++;
	}
    
	printf("f %s\n", st->flag);
    printf("w %d\n", st->width);
    printf("p %d\n", st->precision);
    printf("s %s\n", st->size);
    printf("c %c\n", st->specifier);
	ft_putstr("buffer = ");
    ft_putnbr(*(st->buffer));
	printf("\n");
    //ft_putnbr(ft_atoi(st->buffer));
	return (0);
}
