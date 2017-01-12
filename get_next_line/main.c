/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:12:35 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/12 14:38:48 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int				main(void)
{
    int			fd;
    int			fd1;
    int			ret;
    char		*file;
    char		*file1;
	char		*line;
    
	file = "gnl7_1.txt";
    fd = open(file, O_RDONLY);
	ret = get_next_line(fd, &line);

	printf("FD = %d RET = %d LINE = %s\n", fd, ret, line);
	ret = get_next_line(fd, &line);
	/*
	printf("FD1 = %d RET = %d LINE = %s\n", fd1, ret, line);
	ret = get_next_line(fd, &line);
	printf("FD = %d RET = %d LINE = %s\n", fd, ret, line);
	ret = get_next_line(fd1, &line);
	printf("FD1 = %d RET = %d LINE = %s\n", fd1, ret, line);
	ret = get_next_line(fd, &line);
	printf("FD = %d RET = %d LINE = %s\n", fd, ret, line);
	ret = get_next_line(fd1, &line);
	printf("FD1 = %d RET = %d LINE = %s\n", fd, ret, line);
	ret = get_next_line(fd, &line);
	printf("FD = %d RET = %d LINE = %s\n", fd, ret, line);
	ret = get_next_line(fd1, &line);
	printf("FD1 = %d RET = %d LINE = %s\n", fd, ret, line);
	*/
}
