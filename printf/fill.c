/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:58:33 by okres             #+#    #+#             */
/*   Updated: 2017/02/08 20:43:54 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// функция заполнения структуры флагами, спец.,..итд
int		fill_struct(t_pf *st, va_list vl)
{
    char	spec[] = "sSpdDioOuUxXcCdfFeEgGaApn%";
    char	sizes[] = "llLhlhhjzt";
    char	flags[] = "-+ #0";
    char	*ptr;
	
	/*if (check_flag(st->str, spec) == 0)
	{
		if (find(st->str, '%') == 1)
		{	
			if (two_perc(st) == 0)
				return (1);
		}
	}*/
	fill_flags(st->str, flags, &(st->flag));
    while (*(st->str) && (find(spec, *(st->str)) == 0))
    {
		st->p = 0;
		if (*(st->str) == '.')
		{
			st->point = 1;
			st->precision = 0;
		}
        fill_width(&(st->str), &(st->width), vl, st);
        fill_precision(&(st->str), &(st->precision), vl, st);
        fill_size(&(st->str), sizes, st->size, st);
		if (!ft_isdigit(*(st->str)) && !find_mod(spec, sizes, flags, *(st->str)) && st->p == 0)
			(st->str)++;
    }
    st->specifier = *(st->str);
	f_1(st->specifier, st->size, vl, &(st->buffer), st);
	st->last_buffer = st->buffer;
	return (0);
}

void	fill_flags(char *str, char *flags, char **flag)
{
	char *ptr;

	ptr = *flag;
    while (*str)
    {
		if (find(flags, *str) == 1 && find(*flag, *str) == 0)
		{
			if (*str == '0' && (ft_isdigit(*(str - 1)) || *(str - 1) == '.'))
				(*flag)++;
			else
            	**flag = *str;
			(*flag)++;
		}
        str++;
	}
	*flag = ptr;
}

void	fill_width(char **str, int *width, va_list vl, t_pf *st)
{
	while (**str == '*' || ft_isdigit(**str))
	{
		if (**str == '0')
		{
			(*str)++;
			return ;
		}
		if (**str == '*')
		{
        	*width = va_arg(vl, int);
       		(*str)++;
		}
		else if (ft_isdigit(**str))
		{
			while (ft_isdigit(**str))
			{
        		*width = *width * 10 + **str - '0';
       			(*str)++;
			}
    	}
	st->p = 1;
	}
}

void    fill_precision(char **str, int *precision, va_list vl, t_pf *st)
{
	if (**str == '.')
    {
		st->point = 1;
        (*str)++;
        if (**str == '*')
        {
			*precision = va_arg(vl, int);
			(*str)++;
        }
		else if (ft_isdigit(**str))
		{
			while(ft_isdigit(**str))
			{
            	*precision = *precision * 10 + **str - '0';
            	(*str)++;
			}
		}
	st->p = 1;
	}
}


void    fill_size(char **str, char *sizes, char *size, t_pf *st)
{
	char	*ptr;

	ptr = size;
    while (find(sizes, **str) == 1)
    {
        *ptr = **str;
        ptr++;
        (*str)++;
		st->p = 1;
    }
}
