/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:53:24 by okres             #+#    #+#             */
/*   Updated: 2016/12/02 17:07:22 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == 0 || s2 == 0)
		return (0);
	while (n > 0)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (0);
		n--;
	}
	return (1);
}
