/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:11:41 by exam              #+#    #+#             */
/*   Updated: 2017/01/30 18:20:14 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		check(char *str, char c)
{
	int	i;

	i = 0;
	//printf("str%s\n", str);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

int		str_len(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*saym_str(char *str1, char *str2)
{
	int		i;
	int		j;
	int		k;
	char	*res;
	int		len;
	
	i = 0;
	k = 0;
	len = str_len(str1);
	res = (char *)malloc(sizeof(char) * len + 1);
	while (i <= len)
	{
		res[i] = '\0';
		i++;
	}
	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j])
			{
				res[k] = str2[j];
				k++;
				if (check(&str2[j], str1[i + 1]) == 1)
					str2 = str2 + j;
				break;
			}
			j++;
		}
		i++;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	char	*tmp1;
	char	*tmp2;
	int 	i;
	int		y;

	y = 1;
	i = 1;
	if (argc > 2)
	{
		tmp1 = saym_str(argv[i], argv[i + y]);
		y++;
		i++;
		while (i < argc)
		{
			tmp2 = saym_str(tmp1, argv[y]);
			printf("tmp2 = %s tmp1 = %s argv[%d] = %s\n", tmp2, tmp1,y, argv[y]);
			//if (str_len(tmp1) > str_len(tmp2))
			tmp1 = tmp2;
			i++;
			y++;
		}
		ft_putstr(tmp1);
		write(1, "\n", 1);
	}	

}
