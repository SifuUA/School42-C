#ifndef PUSHSWAP_PUSH_SWAP_H
# define PUSHSWAP_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>

# define OUT_OF_MEM 1
# define WRONG_ARG 2
# define ALREDY_SORT 3

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
	size_t          elem_pos;
}                   t_d_linklst;


void   				sa(t_d_linklst *list_a);
void   				sb(t_d_linklst *list_a);
void    			ss(t_d_linklst *list_a, t_d_linklst *list_b);
void				pa(t_d_linklst *list_a, t_d_linklst *list_b);
void				pb(t_d_linklst *list_a, t_d_linklst *list_b);
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

void                push_swap(t_d_linklst *list_a, t_d_linklst *list_b);
int                 is_sort(t_d_linklst *list);
void                norm_sort(t_d_linklst *list_a, t_d_linklst *list_b);
T                   get_min(t_d_linklst *list);


#endif
