/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:44:18 by okres             #+#    #+#             */
/*   Updated: 2017/01/19 21:37:41 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// функция для поиска символа в массиве
int		find(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// функция заполнения сруктуры флагами, спец.,..итд
void	fill_struct(t_pf *st, va_list vl)
{
	int	i;
	int j;
	char spec[] = "diuoxXfFeEgGaAcspn";
	char sizes[] = "llLhlhhjzt";
	char flags[] = "-+ #0";
	
	st->flag = ft_strnew(4);
	st->width = ft_strnew(ft_strlen(st->str));
	st->precision = ft_strnew(ft_strlen(st->str));
	st->size = ft_strnew(2);

	i = 0;
	while (st->str[i] && (find(spec, st->str[i]) == 0))
	{
		j = 0;
		if (find (flags, st->str[i]) == 1)
		{
			while (find (flags, st->str[i]) == 1)
			{
				if (find(st->flag, st->str[i]) == 0)
				{
					st->flag[j] = st->str[i];
					j++;
				}
				i++;
			}
		}
		else if ((ft_isdigit(st->str[i]) == 1 || (st->str[i] == '*' )))
		{
			j = 0;
			while ((ft_isdigit(st->str[i]) == 1 || (st->str[i] == '*' )))
			{
				st->width[j] = st->str[i];
				j++;
				i++;
			}
		}
		else if (st->str[i] == '.')
		{
			j = 0;
			i++;
			while (st->str[i] == '*' || ft_isdigit(st->str[i]) == 1)
			{
				st->precision[j] = st->str[i];
				i++;
				j++;
			}
		}
		else if (find(sizes, st->str[i]) == 1)
		{
			j = 0;
			while (find(sizes, st->str[i]) == 1)
			{
				st->size[j] = st->str[i];
				i++;
				j++;
			}
		}
		else
			i++;
	}
	st->specifier = st->str[i];
	(st->str) += i;
	f_1(st->specifier, st->size, vl, &(st->buffer));
	printf("%s\n", st->flag);
	printf("%s\n", st->width);
	printf("%s\n", st->precision);
	printf("%s\n", st->size);
	printf("%c\n", st->specifier);
	ft_putnbr(*(st->buffer));
	ft_putnbr(ft_atoi(st->buffer));
	
}

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
