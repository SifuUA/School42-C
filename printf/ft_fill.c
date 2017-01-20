#include "ft_printf.h"

// функция заполнения сруктуры флагами, спец.,..итд
void	fill_struct(t_pf *st, va_list vl)
{
    int		i;
    char	spec[] = "diuoxXfFeEgGaAcspn";
    char	sizes[] = "llLhlhhjzt";
    char	flags[] = "-+ #0";
    
    i = 0;
    memory_allocate(st);
    while (*(st->str) && (find(spec, *(st->str)) == 0))
    {
        (st->str)++;
        fill_flags(&(st->str), flags, st->flag);
        fill_width(&(st->str), st->width);
        fill_precision(&(st->str), st->precision);
        fill_size(&(st->str), sizes, st->size);
    }
    st->specifier = *(st->str);
    //f_1(st->specifier, st->size, vl, &(st->buffer));
    
    
    printf("f %s\n", st->flag);
    printf("w %s\n", st->width);
    printf("p %s\n", st->precision);
    printf("s %s\n", st->size);
    printf("c %c\n", st->specifier);
    //ft_putnbr(*(st->buffer));
    //ft_putnbr(ft_atoi(st->buffer));
}

void	fill_flags(char **str, char *flags, char *flag)
{
    char	*ptr;
    
    ptr = flag;
    while (find (flags, **str) == 1)
    {
        if (find(flag, **str) == 0)
        {
            *ptr = **str;
            ptr++;
        }
        (*str)++;
    }
}

void	fill_width(char **str, char *width)
{
    while (ft_isdigit(**str) == 1 || **str == '*')
    {
        *width = **str;
        width++;
        (*str)++;
    }
}

void    fill_precision(char **str, char *precision)
{
    if (**str == '.')
    {
        (*str)++;
        while (**str == '*' || ft_isdigit(**str) == 1)
        {
            *precision = **str;
            precision++;
            (*str)++;
        }
    }
}


void    fill_size(char **str, char *sizes, char *size)
{
    while (find(sizes, **str) == 1)
    {
        *size = **str;
        size++;
        (*str)++;
    }
}
