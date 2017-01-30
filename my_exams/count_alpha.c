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

char	*to_low(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
		i++;
	}
	return (s);
}

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
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			j = 0;
			count = 0;
			tmp = str;
			while(tmp[j])
			{
				if (tmp[j] == str[i])
				{
					count++;
					if (count != 1)
						tmp[j] = ' ';
				}	
				j++;
			}
			printf("%d%c", count, str[i]);
			if (find(&str[i + 1]) == 1)
				printf(", ");
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	*str;
	char	*copy;

	if (argc == 2)
	{
		str = to_low(argv[1]);
		alpha(str);
	}
	printf("\n");
}
