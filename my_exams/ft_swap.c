#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int     main(void)
{
    int a = 5;
    int b = 10;
    
    ft_swap(&a, &b);
    printf("a = %d b = %d", a, b);
}
