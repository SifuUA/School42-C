#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strdup(char *src)
{
    char    *str;
    int     i;

    i = 0;
    while (src[i])
        i++;
    str = (char*)malloc(sizeof(char) * i + 1);
    i = 0;
    while (src[i])
    {   
        str[i] = src[i];
        i++;
    }

    str[i] = '\0';
    return (str);
}

int     main(void)
{
    char *a = "abcdef";
    printf("my = %s\n", ft_strdup(a));
    printf("man = %s\n", strdup(a));

}
