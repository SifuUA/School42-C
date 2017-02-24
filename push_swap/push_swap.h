#ifndef PUSHSWAP_PUSH_SWAP_H
# define PUSHSWAP_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>

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


void   				sa(t_d_linklst *list_a);
void   				sb(t_d_linklst *list_a);
void    			ss(t_d_linklst *list_a, t_d_linklst *list_b);
void				pa(t_d_linklst *list_a, t_d_linklst *list_b);
void 				ra(t_d_linklst *list);
void 				rb(t_d_linklst *list);
void 				rr(t_d_linklst *list_a, t_d_linklst *list_b);
void 				rra(t_d_linklst *list);
void 				rra(t_d_linklst *list);
void 				rrr(t_d_linklst *list_a, t_d_linklst *list_b);

t_d_linklst     	*creat(void);
void				put(char *s);
void                printList(t_d_linklst *list);
void            	push_front(t_d_linklst *list, int value);
void 				del_node(t_d_linklst *list, t_node *node);

#endif
