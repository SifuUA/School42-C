/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:34:32 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/05 20:31:54 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_
# define BUFF_SIZE 3
# include "libft/libft.h"
typedef	struct		s_line
{
	char			*buff;
	t_list			*new;
	t_list			*head;
	t_list			*ptr;
	int				i;
}					t_line;

int		get_next_line(const int fd, char **line);
/*void                ft_bzero(void *s, size_t n);
void                *ft_memcpy(void *restrict dst, const void *restrict src,
		 	        size_t n);
void                *ft_memmove(void *dst, const void *src, size_t len);
int                 ft_isascii(int c);
void                ft_putchar(char c);
void                ft_putnbr(int n);
void                ft_putstr(char const *s);
char                *ft_strchr(const char *s, int c);
char                *ft_strdup(const char *str);
void                ft_strdel(char **as);
size_t              ft_strlen(char const *str);
size_t              ft_strlen(char const *str);
char                *ft_strnew(size_t size);*/

#endif
