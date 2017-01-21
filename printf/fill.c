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
	fill_flags(st->str, flags, &(st->flag));
    while (*(st->str) && (find(spec, *(st->str)) == 0))
    {
        fill_width(&(st->str), &(st->width), vl);
        fill_precision(&(st->str), &(st->precision), vl);
        fill_size(&(st->str), sizes, st->size);
		if (!ft_isdigit(*(st->str)) && !find_mod(spec, sizes, flags, *(st->str)))
			(st->str)++;
    }
    st->specifier = *(st->str);
	f_1(st->specifier, st->size, vl, &(st->buffer));

}

void	fill_flags(char *str, char *flags, char **flag)
{
	char *ptr;

	ptr = *flag;
    while (*str)
    {
		if (find(flags, *str) == 1 && find(*flag, *str) == 0)
		{
            *ptr = *str;
			ptr++;
		}
        str++;
	}
}

void	fill_width(char **str, int *width, va_list vl)
{
	while (**str == '*' || ft_isdigit(**str))
	{
		*width = 0;
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
		else if (ft_isdigit(**str))
		{
			while(ft_isdigit(**str))
			{
				printf("P%d\n", *precision);
            	*precision = *precision * 10 + **str - '0';
            	(*str)++;
			}
		}
	}
}


void    fill_size(char **str, char *sizes, char *size)
{
	char	*ptr;

	ptr = size;
    while (find(sizes, **str) == 1)
    {
        *ptr = **str;
        ptr++;
        (*str)++;
    }
}
