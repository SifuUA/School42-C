#ifndef PUSHSWAP_PUSH_SWAP_H
# define PUSHSWAP_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/*# define INIT_SIZE 10
# define MULTIPLIER 2

typedef int T;

typedef struct          s_stack
{
				T       *data; //указатель на данные
				size_t  size; //размер массива(максимальный)
				size_t  top; //число єлементов в массиве и заодно вершина
}                       t_stack;

void                    sa(int *stack, int size);
void                    sb(int *stack, int size);
void                    ss(int *stack_a, int *stack_b, int size_a, int size_b);
size_t                  ft_intarr_len(int *arr);
stack_t                 *creat_stack();
void                    delete_stack(t_stack **stack);
void                    resize(t_stack *stack);
void                    push(t_stack *stack, T value);
*/

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
#endif
