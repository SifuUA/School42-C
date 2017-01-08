#include "inc.h"

void    alpha(char *str)
{
    int     i;
    char     tmp;
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            tmp = 25 - (str[i] - 'a');
            tmp = tmp + 'a';
            write (1, &tmp, 1);
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            tmp = 25 - (str[i] - 'A');
            tmp = tmp + 'A';
            write (1, &tmp, 1);
        }
        else 
            write (1, &str[i], 1);
        i++;
    }
}

int     main(int argc, char **argv)
{
    if (argc == 2)
    {
        alpha(argv[1]);
    }
    write(1, "\n", 1);
}
