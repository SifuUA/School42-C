/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:44:18 by okres             #+#    #+#             */
/*   Updated: 2017/01/17 17:17:36 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_choose()
{

}

void	ft_flags(char*)
{
	if ()
}

int 	ft_printf(const char * restrict format, ...)
{
	va_list 		vl;
	char 			*ptr;
	char 			*ptr_1;
	static t_pf 	*begin;

	ptr = format;
	begin = (t_pf *)malloc(sizeof(t_pf));
	fill_struct(&begin);
	va_start (vl, format);
	ptr_1 = ft_strchr(ptr, '%');
	while (*(++ptr_1))
	{
		if (*ptr_1 == '-' || *ptr_1 == '+' || *ptr_1 == ' ' || *ptr_1 == '#' || *ptr == '0')
			ft_flags(*ptr_1);
		if ()
	}
	
	return (0);
}
