/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:12:35 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/05 22:29:04 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*int main(void)
{
    char		*line;
    int			fd;
    int			ret;
    int			count_lines;
    char		*filename;
    int			errors;
    
    filename = "gnl/gnl7_1.txt";
    fd = open(filename, O_RDONLY);
    if (fd > 2)
    {
        count_lines = 0;
        errors = 0;
        line = NULL;
        while ((ret = get_next_line(fd, &line)) > 0)
		{
            if (count_lines == 0 && strcmp(line, "12345678") != 0)
                errors++;
            count_lines++;
            if (count_lines > 50)
                break ;
        }
        close(fd);
        if (count_lines != 1)
            printf("count_lines = %d,  -> must have returned '1' once instead of %d time(s)\n", count_lines, count_lines);
        if (errors > 0)
            printf("-> must have read \"12345678\" instead of \"%s\"\n", line);
        if (count_lines == 1 && errors == 0)
            printf("OK\n");
    }
    else
        printf("An error occured while opening file %s\n", filename);
    return (0);
}
int 	main(void) 
{
	char *line;
	int i = 3;
	int fd;

	fd = open("gnl/gnl7_3.txt", O_RDONLY);
  //  while (i > 0)
//	{
		get_next_line(fd, &line);
			printf("%d. %s\n", i, line);
//			i--;
//	}
    return (0);
}*/
int				main(void)
{
    char		*line;
    int			fd;
    int			ret;
    int			count_lines;
    char		*filename;
    int			errors;
    
    filename = "gnl/gnl7_2.txt";
    fd = open(filename, O_RDONLY);
    if (fd > 2)
    {
        count_lines = 0;
        errors = 0;
        line = NULL;
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            if (count_lines == 0 && strcmp(line, "1234567") != 0)
                errors++;
            if (count_lines == 1 && strcmp(line, "abcdefgh") != 0)
                errors++;
            count_lines++;
            if (count_lines > 50)
                break ;
        }
        close(fd);
        if (count_lines != 2)
            printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
        if (errors > 0)
            printf("-> must have read \"1234567\" and \"abcdefgh\" errors = %d, line = %s\n", errors, line);
        if (count_lines == 2 && errors == 0)
            printf("OK\n");
    }
    else
        printf("An error occured while opening file %s\n", filename);
    return (0);
}
