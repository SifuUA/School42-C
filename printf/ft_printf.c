/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:44:18 by okres             #+#    #+#             */
/*   Updated: 2017/01/20 16:27:40 by okres            ###   ########.fr       */
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

void	memory_allocate(t_pf *st)
{
	st->flag = ft_strnew(5);
	st->width = ft_strnew(ft_strlen(st->str));
	st->precision = ft_strnew(ft_strlen(st->str));
	st->size = ft_strnew(2);

}
// функция заполнения сруктуры флагами, спец.,..итд
void	fill_struct(t_pf *st, va_list vl)
{
	int		i;
	char	spec[] = "diuoxXfFeEgGaAcspn";
	char	sizes[] = "llLhlhhjzt";
	char	flags[] = "-+ #0";
	
	i = 0;
	memory_allocate(st);
	while (*(st->str) && (find(spec, *(st->str)) == 0))
	{
		fill_flags(&(st->str), flags, st->flag);
		fill_width(&(st->str), st->width);
		fill_precision(&(st->str), &i, &(st->flag));
		fill_size(&(st->str), &i, sizes, &(st->size));
		(st->str)++;
	}
	st->specifier = *(st->str);
	//f_1(st->specifier, st->size, vl, &(st->buffer));
	

	printf("f %s\n", st->flag);
	printf("w %s\n", st->width);
	printf("p %s\n", st->precision);
	printf("s %s\n", st->size);
	printf("c %c\n", st->specifier);
	//ft_putnbr(*(st->buffer));
	//ft_putnbr(ft_atoi(st->buffer));
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

void	fill_width(char **str, char *width)
{
	while (ft_isdigit(**str) == 1 || **str == '*')
	{
		*width = **str;
		width++;
		(*str)++;
	}
}

void    fill_precision(char **str, int *i, char **precision)
{	
	int j;

	j = 0;
	if (*str[*i] == '.')
	{
		(*i)++;
		while (*str[*i] == '*' || ft_isdigit(*str[*i]) == 1)
		{
			*precision[j] = *str[*i];
			(*i)++;
			j++;
		}
	}
}


void    fill_size(char **str, int *i, char *sizes, char **size)
{
	int j;

	j = 0;	
	while (find(sizes, *str[*i]) == 1)
	{
		*size[j] = *str[*i];
		(*i)++;
		j++;
	}
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
