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
	ft_bzero(tmp, BUFF_SIZE + 1);
    *read_return = read(fd, tmp, BUFF_SIZE);
	if (*read_return == 0)
		return ;
    tmp[*read_return] = '\0';
    p = ft_strjoin(*buffer, tmp);
	ft_strdel(buffer);
	*buffer = p;
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
        if (p->buff && ((ptr = ft_strchr(p->buff, '\n')) != NULL))
        {
            *ptr = '\0';
            *line = ft_strdup(p->buff);
            ft_memmove(p->buff, ptr + 1, ft_strlen(ptr + 1) + 1);
			if (**line != '\0')
				return (1);
        }
    }
	 if (read_return == 0 && p->buff && *(p->buff) != '\0' )
	 {
            *line = ft_strdup(p->buff);
			ft_strdel(&(p->buff));
			return (1);
	 }
	 else if (*line)
		 *line = ft_strnew(0);
    return (read_return);
}
