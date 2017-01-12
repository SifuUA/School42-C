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
	t_gnl		*ptr1;
    int         read_return;
	int		flag;

	flag = 0;
    if (fd < 0 || fd > 65534 || !line)
        return (-1);
		p = begin;
    if (begin == NULL)
	{
	   	begin = create(ft_strnew(0), fd);
		p = begin;
	}
	else 
	{
		while (p)
		{
			ptr1 = p;
			if (p->fd == fd)
			{
				flag = 1;
				break;
			}
			p = p->next;
		}
		if (flag == 0)
		{
			ptr1->next = create(ft_strnew(0), fd);
			p = ptr1->next;
		}
	}
    read_return = 1;
    while (read_return > 0)
    {
        read_in_buffer(fd, &(p->buff), &read_return);
        if ((ptr = ft_strchr(p->buff, '\n')) != NULL)
        {
            *ptr = '\0';
            *line = ft_strdup(p->buff);
            ft_memmove(p->buff, ptr + 1, ft_strlen(ptr + 1) + 1);
            return (1);
        }
		else if (read_return == 0)
            *line = ft_strdup(p->buff);
    }
    return (read_return);
}
