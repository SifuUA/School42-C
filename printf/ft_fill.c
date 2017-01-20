/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:58:33 by okres             #+#    #+#             */
/*   Updated: 2017/01/20 19:50:15 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// функция заполнения структуры флагами, спец.,..итд
void	fill_struct(t_pf *st, va_list vl)
{
    char	spec[] = "diuoxXfFeEgGaAcspn";
    char	sizes[] = "llLhlhhjzt";
    char	flags[] = "-+ #0";
    char	*ptr;
	
	ptr = st->str;
    memory_allocate(st);
    while (*(st->str) && (find(spec, *(st->str)) == 0))
    {
        (st->str)++;
        fill_flags(&(ptr), flags, st->flag);
        fill_width(&(st->str), st->width_arg, &(st->width_num));
        fill_precision(&(st->str), st->precision);
        fill_size(&(st->str), sizes, st->size);
    }
    st->specifier = *(st->str);
}

void	fill_flags(char **str, char *flags, char *flag)
{
    char	*ptr;
    
    ptr = flag;
    while (find (flags, **str) == 1)
    {
        if (find(flag, **str) == 0)
        {
            *ptr = **str;
            ptr++;
        }
        (*str)++;
    }
}

void	fill_width(char **str, char *width_arg, int *width_num )
{
	if (ft_isdigit(**str) == 1)
	{
        	*width_num = ft_atoi(*str);
       		(*str)++;
    }
	else if (**str == '*')
	{
    	while (**str == '*')
   		{
        	*width_arg = **str;
       		 width_arg++;
       		 (*str)++;
		}
	}
}

void    fill_precision(char **str, char *precision)
{
    if (**str == '.')
    {
        (*str)++;
        while (**str == '*' || ft_isdigit(**str) == 1)
        {
            *precision = **str;
            precision++;
            (*str)++;
        }
    }
}


void    fill_size(char **str, char *sizes, char *size)
{
    while (find(sizes, **str) == 1)
    {
        *size = **str;
        size++;
        (*str)++;
    }
}
