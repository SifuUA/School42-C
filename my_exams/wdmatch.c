#include "inc.h"

int     str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int     count_in_str(char *str, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}

int     wdmatch(char *a, char *b)
{
    int i;
    int j;

    i = 0;
    while (a[i])
    {
        j = 0;
        while (b[j])
        {
            if (a[i] == b[j] && count_in_str(b, b[j]) < count_in_str(a, a[i]))
                return (1);   
            j++;
        }
        i++;
    }
    return (0);   
}

int     main(int argc, char **argv)
{
    if (argc == 3)
    {
        if (wdmatch(argv[1], argv[2]) == 0)
                write(1, argv[1], str_len(argv[1]));
    }
    write(1, "\n", 1);
}
