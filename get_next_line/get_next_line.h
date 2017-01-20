/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:22:14 by okres             #+#    #+#             */
/*   Updated: 2017/01/20 20:51:41 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

# define BUFF_SIZE -1
# include "libft/libft.h"

typedef	struct		s_gnl
{
	struct s_gnl	*next;
	char			*buff;
	int				fd;
}					t_gnl;

int		get_next_line(const int fd, char **line);
#endif
