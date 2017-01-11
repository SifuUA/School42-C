#include "get_next_line.h"
#include <stdio.h>

t_gnl *create(char *buff, int fd)
{
	t_gnl *ptr;
	
	ptr = (t_gnl *)malloc(sizeof(t_gnl));
	if (!ptr)
		return (NULL);
	if (!buff)
	{
		ptr->buff = NULL;
		fd = 0;
	}
	else
	{
		ptr->buff = buff;
		ptr->fd = fd;
		ptr->next = NULL;
	}
	return (ptr);
}

void		read_in_buffer(const int fd, char **buffer, int *read_return)
{
    char    tmp[BUFF_SIZE + 1];
	char	*p;

    *read_return = read(fd, tmp, BUFF_SIZE);
	//printf("Read = %d fd = %d\n", *read_return, fd);
    tmp[*read_return] = '\0';
	p = *buffer;
    *buffer = ft_strjoin(*buffer, tmp);
	ft_strdel(&p);
    //return (1);
}

int     get_next_line(const int fd, char **line)
{
	static		t_gnl *begin;
	t_gnl 		*p;
    char        *ptr;
    int         read_return;

    if (fd < 0 || fd > 65534 || !line)
        return (-1);
		p = begin;
    if (begin == NULL)
	{
		write(1, "N\n", 2);
	   	begin = create(ft_strnew(0), fd);
		p = begin;
	}
	else 
	{
		while (p)
		{
		write(1, "L\n", 2);

			if (p->fd == fd )
				break;
			p = p->next;
		}
	}
    read_return = 1;
    while (read_return > 0)
    {
	//	write(1, "A\n", 2);
        if ((ptr = ft_strchr(p->buff, '\n')) != NULL)
        {
			//printf("ptr = %s p->buf v nachale if = %s\n", ptr, p->buff);
            *ptr = '\0';
            *line = ft_strdup(p->buff);
            ft_memmove(p->buff, ptr + 1, ft_strlen(ptr + 1) + 1);
	//	printf("p->buff in if = %s read_reaturn = %d\n", p->buff, read_return);
	//	write(1, "B\n", 2);
            return (1);
        }
	//	write(1, "C\n", 2);
        read_in_buffer(fd, &(p->buff), &read_return);
	//	printf("p->buff = %s read_reaturn = %d\n", p->buff, read_return);
	//	printf ("3fd = %d\n", fd);
    }
    return (read_return);
}
