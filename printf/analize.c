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
		if (size[0] == '\0')
			*buffer = ft_itoa_base(va_arg(vl, int), 10);
		else if (size[0] == 'h' && size[1] == 'h')
			**buffer = (signed char)(va_arg(vl, int));
		else if (size[0] == 'h')
			*buffer = ft_itoa_base((short int)(va_arg(vl, int)) , 10);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base(va_arg(vl, long long int), 10);
	}
	else if (cpecif == 'u' || cpecif == 'o' || cpecif == 'x' || cpecif == 'X')
		f_2(cpecif, size, vl, buffer);
	else if (cpecif == 'f' || cpecif == 'F' || cpecif == 'e' || cpecif == 'E'
	|| cpecif == 'g' || cpecif == 'G' || cpecif == 'a' || cpecif == 'A')
		f_4(cpecif, size, vl, buffer);
}

void	f_2(char cpecif, char *size, va_list vl, char **buffer)
{
	if (cpecif == 'u')
	{
		if (size[0] == '\0')
			*buffer = ft_itoa_base(va_arg(vl, unsigned int), 10);
		else if (size[0] == 'h' && size[1] == 'h')
			**buffer = (unsigned char)(va_arg(vl, int));
		else if (size[0] == 'h')
			*buffer = ft_itoa_base((unsigned short int)(va_arg(vl, int)), 10);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 10);
	}
	else if (cpecif == 'o')
	{
		if (size[0] == '\0')
			*buffer = ft_itoa_base(va_arg(vl, unsigned int), 8);
		else if (size[0] == 'h' && size[1] == 'h')
			*buffer = ft_itoa_base_unsign((unsigned char)(va_arg(vl, int)), 8);
		else if (size[0] == 'h')
			*buffer = ft_itoa_base((unsigned short int)(va_arg(vl, int)), 8);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 8);
	}
	else
		f_3(cpecif, size, vl, buffer);
}

void	f_3(char cpecif, char *size, va_list vl, char **buffer)
{
	if (cpecif == 'x')
	{
		if (size[0] == '\0')
			*buffer = ft_itoa_base_low(va_arg(vl, unsigned int), 16);
		else if (size[0] == 'h' && size[1] == 'h')
			**buffer = (unsigned char)(va_arg(vl, int));
		else if (size[0] == 'h')
			*buffer = ft_itoa_base_low((unsigned short int)(va_arg(vl, int)), 16);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 16);
	}
	else if (cpecif == 'X')
	{
		if (size[0] == '\0')
			*buffer = ft_itoa_base(va_arg(vl, unsigned int), 16);
		else if (size[0] == 'h' && size[1] == 'h')
			*buffer = ft_itoa_base_unsign((unsigned char)(va_arg(vl, int)), 16);
		else if (size[0] == 'h')
			*buffer = ft_itoa_base((unsigned short int)(va_arg(vl, int)), 16);
		else if (size[0] == 'l' || size[0] == 'j' || size[0] == 'z' || size[0] == 't')
			*buffer = ft_itoa_base_unsign(va_arg(vl, unsigned long int), 16);
	}
}

void	f_4(char cpecif, char *size, va_list vl, char **buffer)
{
	double	tmp;
	int		value;

	if (cpecif == 'f')
	{
		if (size[0] == '\0')
		{
			tmp = (double)va_arg(vl, double);
			value = tmp;
			*buffer = ft_itoa(value);
			//*buffer = ft_itoa_base((tmp * ft_pow(10, num_len(tmp))), 10);
		}
		printf("---> %s <---\n", *buffer);
	}
	else
		f_4(cpecif, size, vl, buffer);
}
