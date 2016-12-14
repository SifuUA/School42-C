/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:47:52 by oslutsky          #+#    #+#             */
/*   Updated: 2016/11/16 19:48:29 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

void	main_process(char *s)
{
	char	**tab;
	int		argc2;
	t_map	map;

	ft_split_newlines(s, &tab, &argc2);
	map = get_map2(argc2, tab);
	map.is_correct = test_map(map);
	if (map.is_correct == 1)
		get1_answer_for_map(&map);
	print_map(map);
}

int		main(int argc, char **argv)
{
	char	*s;
	int		i;

	if (argc == 1)
	{
		s = get_s_from_stream(0);
		main_process(s);
	}
	i = 1;
	while (i < argc)
	{
		s = get_s_from_file(argv[i]);
		main_process(s);
		i++;
	}
	return (0);
}
