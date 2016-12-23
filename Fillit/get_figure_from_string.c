#include "inc.h"

void 	replace(char *s)// 2. Замена /n на а
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

char **get_figure_from_string(char *s)//1. Считываем все фигуры с файла в одну строку
{
	char const *tmp;

	replace(s);//2. Заменяем все /n которые повторяются 2 раза подряд на буквы а
	tmp = s;
	return (ft_strsplit(tmp, 'a'));
}

void read_figure(char *s, t_figure a)// Записываем координаты 4 точек каждой с фигур в массив
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
		while (x < 4)// Перебираем все елементы в отдельном квадрате 4 * 4
					// и каждый раз считываем 4 каждой фигуры
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

void	norm_figure(t_figure a)// Перемещаем фигуру "а" в верхний левый угол
{
	int		i_pt;
	int		x_min;
	int		y_min;

	x_min = 3;// Максимальные координат по х нижнего углового символа
	y_min = 3;// Максимальные координат по у нижнего углового символа
	i_pt = 0;
	while (i_pt < 4)
	{
		if (a[i_pt].x < x_min)
			x_min = a[i_pt].x;// Минимальные координаты фигуры по х
		if (a[i_pt].y < y_min)
			y_min = a[i_pt].y;// Минимальные координаты фигуры по y
		i_pt++;
	}
	if (x_min == 0 && y_min == 0)// Если мы дошли до левого верхнего угла то выходим с ф-и.
		return ;
	i_pt = 0;
	while (i_pt < 4)
	{
		a[i_pt].x -= x_min;// Отнимаем мин х от 4 координат по х  изаписываем новый координат
						   // в  "а"
		a[i_pt].y -= y_min;// Отнимаем мин y от 4 координат по y  изаписываем новый координат
		i_pt++;
	}
}

char	**array_of_figure(size_t field_size)
{
	char **answer;
	size_t x;
	size_t y;

	y = 0;
	answer = (char **)malloc(sizeof(char*) * (field_size + 1));
	while (y < field_size)
		answer[y++] = (char *)malloc(sizeof(char) * (field_size + 1));
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
		answer[y][x] = '\0';
		y++;
	}
	answer[y] = NULL;
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
	if (DEBUG_PRINT_ANSWER == 1) printf("print_answ: before i_fig while\n");
	while (i_fig < n_figs)
	{
		int x0 = top_of_figure[i_fig].x;
		int y0 = top_of_figure[i_fig].y;
		i_pt = 0;
		if (DEBUG_PRINT_ANSWER == 1) printf("print_answ: before i_pt while\n");
		while (i_pt < 4)
		{
			int x = figures[i_fig][i_pt].x;
			int	y = figures[i_fig][i_pt].y;
			answer[y + y0][x + x0] = letter;
			if (DEBUG_PRINT_ANSWER == 1) printf("i_fig = %lu, i_pt = %lu, x = %d, y = %d, x0 = %d, y0 = %d\n", i_fig, i_pt, x,y,x0,y0);
			i_pt++;
		}
		letter++;
		i_fig++;
	}
	if (DEBUG_PRINT_ANSWER == 1) printf("print_answ: after i_fig while\n");
	ft_arr_putstr(answer);
}
	
