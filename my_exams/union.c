#include "inc.h"

int     len(char *a)
{
    int i;

    i = 0;
    while (a[i])
        i++;
    return (i);
}
void     clear_arr(char *arr)
{
    int i;

    i = 200;
    while (--i > 0)
        arr[i] = '\0';
}

int     check(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int     ft_union(char *a, char *dest)
{
    int i;
    int j;

    i = 0;
    j = len(dest);
    while (a[i])
    {
        if (check(dest, a[i]) == 0)
            dest[j++] = a[i];
        i++;
    }
    return (j);
}

int     main(int argc, char **argv)
{
    char    arr[200];
    int     len;

    if (argc == 3)
    {
        clear_arr(arr);
        ft_union(argv[1], arr);
        len = ft_union(argv[2], arr);
        write(1, arr, len);
    }
    write(1, "\n", 1);
}
