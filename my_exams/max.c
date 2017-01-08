#include "inc.h"

int     max(int *tab, unsigned int len)
{
    unsigned int tmp;

    if (len == 0)
        return (0);
    tmp = tab[0];
    while (*tab)
    {
        if (*tab > tmp)
            tmp = *tab;
        tab++;
    }
    return (tmp);
}

int     main(void)
{
    int a[] = {1, 3, 6, 8, 12, 4, 7, 0};
    printf("%d\n", max(a, 8));
}
