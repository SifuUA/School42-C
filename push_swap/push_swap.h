#ifndef PUSHSWAP_PUSH_SWAP_H
# define PUSHSWAP_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

#define INIT_SIZE 10
#define MULTIPLIER 2

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


#endif
