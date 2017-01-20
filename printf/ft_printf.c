/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:44:18 by okres             #+#    #+#             */
/*   Updated: 2017/01/20 17:16:00 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"





// основная ф-я
int	 		ft_printf(const char * restrict format, ...)
{
	va_list 		vl;
	char 			*str;
	char 			*ptr;
	static t_pf 	*st;
	int				i;

	//ptr_f [10];
	i = 0;
	va_start (vl, format);
	st = (t_pf *)malloc(sizeof(t_pf));
	st->str = (char*) format;
	while (*(st->str))
	{
		if (*(st->str) == '%')
			fill_struct(st, vl);
		else
			ft_putchar(st->str[i]);
		(st->str)++;
	}

	return (0);
}
