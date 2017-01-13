/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:12:35 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/13 13:44:00 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int				main(void)
{
    int			fd;
    int			fd1;
    int			fd2;
    int			fd3;
    int			ret = 1;
    char		*file;
    char		*file1;
    char		*file2;
    char		*file3;
	char		*line = NULL;
    
	file = "gnl1_2.txt";
    fd = open(file, O_RDONLY);
	
	file1 = "gnl1_3.txt";
    fd1 = open(file1, O_RDONLY);
	
	file2 = "gnl1_4.txt";
    fd2 = open(file2, O_RDONLY);
	
	file3 = "res.txt";
    fd3 = open(file3, O_RDONLY);
	

		ret = get_next_line(fd3, &line);
		printf("%s", line);
		
		ret = get_next_line(fd3, &line);
		printf("%s", line);

		ret = get_next_line(fd3, &line);
		printf("%s", line);
		
		ret = get_next_line(fd3, &line);
		printf("%s", line);

		ret = get_next_line(fd3, &line);
		printf("%s", line);
	/*while(ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("FD = %d RET = %d LINE = %s\n", fd, ret, line);
		ret = get_next_line(fd1, &line);
		printf("FD = %d RET = %d LINE = %s\n", fd1, ret, line);
		ret = get_next_line(fd2, &line);
		printf("FD = %d RET = %d LINE = %s\n", fd2, ret, line);
	}*/
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
