#include "ft_printf.h"

void		mod_sharp3(t_pf *st, char *tmp, int i)
{
    if (find(st->flag, '-'))
    {
        (st->buffer)++;
        if (st->width > st->precision && st->precision != 0)
        {
            tmp = ft_strjoin(st->buffer, " ");
            st->buffer = tmp;
        }
        if (st->buffer[0] != '0')
        {
            tmp = ft_strjoin("0", st->buffer);
            st->buffer = tmp;
        }
    }
    else
    {
        while (st->buffer[i] == ' ')
            i++;
        if (i > 0 && st->buffer[i] != '0')
            st->buffer[i - 1] = '0';
        else if (st->buffer[i] != '0')
            st->buffer = ft_strjoin("0x", st->buffer);
        else if (st->precision > st->width)
            (st->buffer)++;
    }
}

void		mod_sharp2(t_pf *st, char *zeros, char *spaces)
{
    char	*tmp;
    int		i;
    
    i = 0;
    if (st->specifier == 'x' || st->specifier == 'X')
    {
		if (ft_atoi(st->buffer) == 0)
		{
			st->buffer = "0";
			return ;
		}
        if (find(st->flag, '-') || find(st->flag, ' ') || find(st->flag, '0'))
        {
            if (find (st->flag, '-'))
            {
                    tmp = ft_strjoin("0x", st->buffer);
					i = ft_strlen(tmp);
                    st->buffer = tmp;
					if (st->buffer[i - 1] == ' ')
						st->buffer[i - 1] = '\0';
					if (st->buffer[i - 2] == ' ')
						st->buffer[i - 2] = '\0';
            }
            if (find (st->flag, ' '))
                mod_sharp3(st, tmp, i);
        }
        else
        {
            if (st->width > ft_strlen(st->buffer) && zeros == NULL)
            {
                tmp = ft_strjoin("0x", st->buffer);
                spaces += 2;
                st->buffer = ft_strjoin(spaces, tmp);
            }
            else if (st->precision > st->width)
            {
                tmp = ft_strjoin(zeros, st->buffer);
                st->buffer = ft_strjoin("0x", tmp);
            }
			else if (st->width > st->precision)
			{
				tmp = ft_strjoin(zeros, st->buffer);
				st->buffer = ft_strjoin("0x", tmp);
				spaces += 2;
				tmp = ft_strjoin(spaces, st->buffer);
				st->buffer = tmp;
			}
            else
                st->buffer = ft_strjoin("0x", st->buffer);
        }
    }
}

