#include <stdio.h>
#include <stdlib.h>

int     ft_atoi(const char *str)
{
    long long   res;
    int         minus;

    minus = 1;
    while (*str == ' ')
        str++;
    if (*str == '-')
    {
        minus = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + *str - '0';
        str++;
    }
    return (int)res * minus;
}

int     main(void)
{
    char *a = "    -21479999999  ";
    printf("my = %d\n", ft_atoi(a));
    printf("man = %d\n", atoi(a));
}
