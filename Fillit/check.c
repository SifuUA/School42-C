#include "inc.h"

int	check(char *s)
{
	int i;
	int y;
	int sharps;

	i = 0;
	y = 0;
	while (*s)
	{
		if (DEBUG_CHECK == 0)printf("Внешний цикл *s = %c\n", *s);
		i = 0;
		sharps = 0;
		while (i < 21)
		{
			if (DEBUG_CHECK == 0)printf("%d.Внутрениий цикл *s = %c\n",i, *s);
			if (*s != '.' && *s != '#' && *s != '\n')
			{
				if (DEBUG_CHECK == 0)printf("Первый if: *s = %c\n", *s);

				write(1, "aerror\n", 5);
				return (1);
			}
			if (i >= 21)
			{
				write(1, "berror\n", 5);
				return (1);
			}
			if (*s == '#' && ((*(s + 1)) == '#' || (*(s - 1)) == '#' || (*(s + 5)) == '#' || (*(s - 5)) == '#'))
			{
				if (DEBUG_CHECK == 1)printf("Проверка на валидность фигуры: *s = %c\n", *s);
				sharps++;
			}
			i++;
			s++;
		}
		if (sharps != 4)
		{
			write(1, "cerror\n", 5);
			return (1);
		}
	}
	return (0);
}

/*int check_sharps(*s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == '.')
			s++;
		else if (*s == '#' && )
	}
}*/
