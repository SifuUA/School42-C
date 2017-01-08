#include "inc.h"

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
void    arr_creat(char *arr)
{
    int i;

    i = 100;
    while (--i >= 0)
        arr[i] = '\0';
}

int    inter(char *a, char* b, char *dest)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    while (a[i])
    {
        j = 0;
        while (b[j])
        {
            if (b[j] == a[i])
            {
                if (check(dest, b[j]) == 0)
                {
                    dest[k] = b[j];
                    k++;
                }
            }
            j++;
        }
        i++;
    }
    return (k);
}

int     main(int argc, char **argv)
{
    int     len;
    char    p[100];
    if (argc == 3)
    {
        arr_creat(p);
        len = inter(argv[1], argv[2], p);
        write(1, p, len);
    }
    write (1, "\n", 1);
    return (0);
}
