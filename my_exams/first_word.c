#include "inc.h"

void    first(char *argv)
{
    while (*argv == ' ' || *argv == '\t')
        argv++;
    while (*argv != ' ' && *argv != '\t' && *argv)
        write(1, &*argv++, 1);
}

int     main(int argc, char **argv)
{
    if (argc == 2)
        first(argv[1]);
    write (1, "\n", 1);
    return (0);
}
