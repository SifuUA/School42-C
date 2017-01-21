/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:05:11 by okres             #+#    #+#             */
/*   Updated: 2017/01/20 19:09:08 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_1(char cpecif, char *size, va_list vl, char **buffer)
{
	if (cpecif == 'd' || cpecif == 'i')
	{
				printf("S %s", size);
		if (size[0] == '\0')
			{
				*buffer = ft_itoa_base(va_arg(vl, int), 10);}
		else if (size[0] == 'h' && size[1] == 'h')
			**buffer = (signed char)(va_arg(vl, int));
		else if (size[0] == 'h')
			**buffer = (short int)(va_arg(vl, int));
		else if (size[0] == 'l')
			**buffer = (long int)(va_arg(vl, int));
		else if (size[0] == 'j')
			**buffer = (intmax_t)(va_arg(vl, int));
		else if (size[0] == 'z')
			**buffer = (size_t)(va_arg(vl, int));
		//else
		//	**buffer = (ptrdiff_t)(va_arg(vl, int));
	}
	//else
		//f_2(cpecif, size, vl, &buffer);
}
