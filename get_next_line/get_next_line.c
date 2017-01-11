#include "get_next_line.h"
#include <stdio.h>

int		check(int const fd, char **line, char *buffer)
{
	if (buffer == NULL)
	{
	char	tmp[100];
	char	*p = ft_strnew(0);
	int i = 0;
	while ((i = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[i] = '\0';
		p = ft_strjoin(p,tmp);
	}
	i = 0;
	while (p[i])
	{
	   if (p[i] == '\n')
	   	i++;
	}	   
	*line = ft_strdup(p);
	if (ft_strchr(p, '\n') == NULL)
	{
			return (1);
	}
	}
	return (0);
}
char    *read_in_buffer(char *buffer, const int fd, int *read_return)
{
    char    str[BUFF_SIZE + 1];
    char    *p;

    *read_return = read(fd, str, BUFF_SIZE);
    str[*read_return] = '\0';
    p = buffer;
    buffer = ft_strjoin(buffer, str);
    ft_strdel(&p);
    return (buffer);
}

int     get_next_line(int const fd, char **line)
{
    static char *buffer;
    char        *ptr;
    int         read_return;
    int		count_of_enter;
    int		flag;

    if (fd < 0 || fd > 65534 || !line)
        return (-1);
	printf ("Begin: buff = %s enter = %d, flag = %d line = %s fd = %d\n", buffer, count_of_enter, flag, *line, fd);
    if (buffer == NULL )
	{
		buffer = ft_strnew(0);
	}
    else 
    	{
		count_of_enter = 0;
		flag = 1;
 	}
	printf ("After initial: buff = %s enter = %d, flag = %d\n", buffer, count_of_enter, flag);
    read_return = 1;
    while (read_return > 0)
    {
        if ((ptr = ft_strchr(buffer, '\n')) != NULL)
        {
			count_of_enter++;
            *ptr = '\0';
            *line = ft_strdup(buffer);
            ft_memmove(buffer, ptr + 1, ft_strlen(ptr + 1) + 1);
	    printf ("before return 1\n");
	    //buffer = NULL;
            return (1);
        }
        	buffer = read_in_buffer(buffer, fd, &read_return);
			printf ("buffer = %s read_return = %d\n", buffer, read_return);
	}
	printf ("*line = %s\n", *line);
	printf ("buffer = %s enter = %d\n", buffer, count_of_enter);
	if (count_of_enter == 0)
	{	
		printf ("IN ENTER buffer = %s\n", buffer);
		*line = ft_strdup(buffer);
		printf ("before return flag%d\n", flag);
		return (flag--);
	}
    return (read_return);
}
