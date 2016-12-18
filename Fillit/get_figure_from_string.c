#include "inc.h"

void 	replace(char *s)
{
	while (*s)
	{
		if (*s == '\n' && *(s + 1) == '\n')
		{
			*s = 'a';
			*(s + 1) = 'a';
		}
		s++;
	}
}

char **get_figure_from_string(char *s)
{
	char const *tmp;

	replace(s);
	tmp = s;
	return (ft_strsplit(tmp, 'a'));
}

void read_figure(char *s, t_figure a)
{
	int x;
	int y;
	int i_f;
	int i_s;
	
	x = 0;
	y = 0;
	i_f = 0;
	i_s = 0;

	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s[i_s] == '#')
			{
				a[i_f].x = x;
				a[i_f].y = y;
				i_f++;
			}
			i_s++;
			x++;
		}
		i_s++;//Пропускаем "\n"
		y++;
	}
}

int min(void)
{
	return (2);
}

char	**array_of_figure(size_t field_size)
{
	char **answer;
	size_t x;
	size_t y;

	y = 0;
	answer = (char **)malloc(sizeof(char*) * field_size);
	while (y < field_size)
		answer[y++] = (char *)malloc(sizeof(char) * field_size);
	printf("arr_of_fig: after firts while\n");
	y = 0;
	while (y < field_size)
	{
		x = 0;
		while (x < field_size)
		{
			answer[y][x] = '.';
				x++;
		}
		y++;
	}
	printf("arr_of_fig: after_second_while\n");
	return (answer);
}

void	print_answer(char **answer, t_point *top_of_figure, t_figure *figures, size_t n_figs)
{
	size_t i_fig;
	size_t	i_pt;
	char letter;

	i_fig = 0;
	letter = 'A';
	printf("print_answ: before i_fig while\n");
	while (i_fig < n_figs)
	{
		int x0 = top_of_figure[i_fig].x;
		int y0 = top_of_figure[i_fig].y;
		i_pt = 0;
		printf("print_answ: before i_pt while\n");
		while (i_pt < 4)
		{
			int x = figures[i_fig][i_pt].x;
			int	y = figures[i_fig][i_pt].y;
			answer[y + y0][x + x0] = letter;
			printf("i_fig = %lu, i_pt = %lu, x = %d, y = %d, x0 = %d, y0 = %d\n", i_fig, i_pt, x,y,x0,y0);
			i_pt++;
		}
		letter++;
		i_fig++;
	}
	printf("print_answ: after i_fig while\n");
	ft_arr_putstr(answer);
}
	
