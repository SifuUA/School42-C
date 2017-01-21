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
	
    memory_allocate(st);
	st->width = 0;
	st->precision = 0;
    while (*(st->str) && (find(spec, *(st->str)) == 0))
    {
		printf("Start %c\n", *(st->str));
        fill_flags((st->str), flags, st->flag);
		printf("F %c\n", *(st->flag));
        fill_width(&(st->str), &(st->width), vl);
        fill_precision(&(st->str), &(st->precision), vl);
        fill_size(&(st->str), sizes, st->size);
        (st->str)++;
    }
    st->specifier = *(st->str);
}

void	fill_flags(char *str, char *flags, char *flag)
{

    if (*str && find (flags, *str) == 1)
    {
            *flag = *str;
            flag++;
			}
        (str)++;
    }
}

void	fill_width(char **str, int *width, va_list vl)
{
	while (**str == '*' || ft_isdigit(**str))
	{
		if (**str == '*')
		{
        	*width = va_arg(vl, int);
       		(*str)++;
		}
		if (ft_isdigit(**str))
		{
			while (ft_isdigit(**str))
			{
        		*width = *width * 10 + **str - '0';
				printf("W%d\n", *width);
       			(*str)++;
			}
    	}
	}
}

void    fill_precision(char **str, int *precision, va_list vl)
{
	if (**str == '.')
    {
        (*str)++;
        if (**str == '*')
        {
			*precision = va_arg(vl, int);
			(*str)++;
        }
		else
		{
			while(ft_isdigit(**str))
			{
            	*precision = *precision * 10 + **str - '0';
            	(*str)++;
			}
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
