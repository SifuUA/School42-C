#include "inc.h"

int	check(char *s)
{
	int i;
	int y;
	int n;
	int j;
	int sharps;

	i = 0;
	y = 0;
	n = 0;
	j = 0;
	while (s[j])
	{
		if (DEBUG_CHECK == 0)printf("Внешний цикл *s = %c\n", *s);
		i = 0;
		sharps = 0;
		while (i < 21)
		{
			if (DEBUG_CHECK == 0)printf("%d.Внутрениий цикл *s = %c\n",i, s[j]);
			if (s[j] != '.' && s[j] != '#' && s[j] != '\n')
			{
				if (DEBUG_CHECK == 1)printf("Первый if: *s = %c\n", s[j]);

				write(1, "aerror\n", 5);
				return (1);
			}
			if (i >= 21)
			{
				write(1, "berror\n", 5);
				return (1);
			}
			i++;
			if (s[j] == '#')
				n = j;
			if (s[j] == '#' && (s[j + 1] == '#' || s[j - 5] == '#' || s[j - 1] == '#' || s[j + 5] == '#'))  
			{
				if (DEBUG_CHECK == 1)printf("Проверка на валидность фигуры: *s = %c\n", s[j]);
				sharps++;
			}
			j++;
		}
		if (sharps != 4)
		{
			write(1, "cerror\n", 5);
			return (1);
		}
	}
	return (0);
}
