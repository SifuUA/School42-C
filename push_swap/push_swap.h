#ifndef PUSHSWAP_PUSH_SWAP_H
# define PUSHSWAP_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define INIT_SIZE 10
# define MULTIPLIER 2

typedef long int T;

typedef struct      s_node
{
	T               value;
	struct s_node   *next;
	struct s_node   *prev;
}                   t_node;

typedef struct      s_d_linklst
{
	struct s_node   *head;
	struct s_node   *tail;
	size_t          size;
}                   t_d_linklst;

void				put(char *s);
void   				sa(t_d_linklst *list_a);
void   				sb(t_d_linklst *list_a);
void    			ss(t_d_linklst *list_a, t_d_linklst *list_b);

void            	push_front(t_d_linklst *list, int value);
t_d_linklst     	*creat(void);
void 				del_node(t_node *node);
#endif
