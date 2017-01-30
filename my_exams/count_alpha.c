/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:20:49 by okres             #+#    #+#             */
/*   Updated: 2017/01/30 20:47:48 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
char    *ft_strdup(char *src);

int		find(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			return (1);
		i++;
	}
	return (0);
}

void	alpha(char *str)
{
	int i;
	int j;
	int count;
	char *tmp;

	i = 0;
	count = 0;
	tmp = str;
	while (str[i])
	{
		j = 0;
		count = 0;
		while(tmp[j])
		{
			if (tmp[j] == str[i])
			{
			printf("tmp%c\n", tmp[j]);
				count++;
				tmp[j] = ' ';
			}
			j++;
		}
		if (count != 0)
			printf("%d%c", count, str[i]);
		if (find(&str[i + 1]))
			printf(", ");
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		alpha(argv[1]);
	else	
		printf("\n");
}
