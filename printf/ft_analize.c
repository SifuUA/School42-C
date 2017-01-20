/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:05:11 by okres             #+#    #+#             */
/*   Updated: 2017/01/20 18:05:19 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	f_1(char cpecif, char *size, va_list vl, char **buffer)
{
	if (cpecif == 'd' || cpecif == 'i')
	{
		if (size[0] == '\0')
			*buffer = ft_itoa_base(va_arg(vl, int), 10);
		else if (size[0] == 'h' && size[1] == 'h')
			**buffer = (signed char)(va_arg(vl, int));
		else if (size[0] == 'h')
			**buffer = (short int)(va_arg(vl, int));
		else if (size[0] == )

	}
