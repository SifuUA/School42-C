#include "inc.h"

int     test_size(size_t field_size, t_figure *figs, size_t n_figs)
{
	size_t		y;
	size_t		x;
	char		**pt_arr;
	int			is_ok;
	t_point		pt;

	pt_arr = (char**)malloc((field_size + 1) * sizeof(char*));
	y = 0;
	while (y < field_size)
	{
		pt_arr[y] = (char*)malloc((field_size + 1) * sizeof(char));
		x = 0;
		while (x < field_size)
			pt_arr[y][x++] = '.';
		pt_arr[y][x] = '\0';
		y++;
	}
	pt_arr[y] = NULL;

	is_ok = recur_func(pt_arr, figs, n_figs, field_size);
	if (is_ok == 1)
	{
		y = 0;
		while (y < field_size)
			printf("%s\n", pt_arr[y++]);
	}
	return (is_ok);
}

int		figurka_postavlena(char **pt_arr, size_t i_fig)
{
	size_t	y;
	char	letter;

	letter = 'A' + i_fig;
	y = 0;
	while (pt_arr[y] != NULL)
	{
		if(ft_strchr(pt_arr[y++], letter) != NULL)
			return (1);
	}
	return (0);
}
/*
t_point	possible_field(char** pt_arr, t_figure fig, size_t field_size)
{
	int	
}
*/

void	put_figure_to_field(char **pt_arr, t_figure fig, size_t i_fig, t_point pt)
{

}

void	remove_figure_from_field(char **pt_arr, t_figure fig, size_t i_fig, t_point pt)
{

}

int		recur_func(char **pt_arr, t_figure *figs, size_t n_figs, size_t field_size)
{
	size_t	i_fig;
	int		is_ok;
	t_point	possible_field;

	is_ok = 0;
	i_fig = 0;
	while (i_fig < n_figs && is_ok != 1)
	{
		if(figurka_postavena(pt_arr, i_fig) == 0)
		{
			if(есть возможное полe)
			{
				Ставим фигурку на поле;
				is_ok = recur_func(pt_arr, figs, n_figs, field_size);
				if (is_ok == 1)
					break;
			}
		}
	}
	return (is_ok);
}

/*
int		check_two_figures(t_figure fig1, t_figure fig2, t_point pt1, t_point pt2)
{
	size_t		i1;
	size_t		j1;

	i1 = 0;
	j1 = 0;
	if (DEBUG_CHECK_TWO_FIGURES == 1)
		printf("check_tow_figures:\n");
	while (i1 < 4)
	{
		j1 = 0;
		while (j1 < 4)
		{
			int x1 = fig1[i1].x + pt1.x;
			int y1 = fig1[i1].y + pt1.y;
			int x2 = fig2[j1].x + pt2.x;
			int y2 = fig2[j1].y + pt2.y;
			if (DEBUG_CHECK_TWO_FIGURES == 1) printf("\t (%d, %d) == (%d, %d)?\n", x1, y1, x2, y2);
			if ((x1 == x2) && (y1 == y2))
				return (0);
			++j1;
		}
		++i1;
	}
	return (1);
}

int		ft_check(t_figure *figures, size_t nfigures, t_point *coords, size_t field_size)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < nfigures)
	{
		if (ft_check_figure(figures[i], coords[i], field_size) == 0)
			return (0);
		j = i + 1;
		while (j < nfigures)
		{
			if (check_two_figures(figures[i], figures[j], coords[i], coords[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_check_figure(t_figure fig, t_point top_left_point, size_t field_size)
{
	size_t	i_pt;
	int		x;
	int		y;

	if (DEBUG_CHECK_FIGURE == 1)
	{
		printf("ft_check_figure: field_size = %lu\n", field_size);
	}

	i_pt = 0;
	while (i_pt < 4)
	{
		x = fig[i_pt].x + top_left_point.x;
		y = fig[i_pt].y + top_left_point.y;
		if (x < 0 || x >= (int)field_size)
			return (0);
		if (y < 0 || y >= (int)field_size)
			return (0);
		i_pt++;
	}
	return (1);
}

int		array_has_povtors(size_t *arr, size_t n_arr)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < n_arr)
	{
		j = i + 1;
		while (j < n_arr)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		test_size(size_t field_size, t_point *coords, t_figure *figs, size_t n_figs)
	//Проверяет, можно ли в поле размером size x size запихать все заданные фигуры
{
	size_t	*arr;
	size_t	i_arr;
	int		is_end;
	size_t	basis;

	arr = (size_t*)malloc(n_figs * sizeof(size_t));
	i_arr = 0;
	while (i_arr < n_figs)
	{
		arr[i_arr] = i_arr;
		i_arr++;
	}

	is_end = 0;
	basis = field_size * field_size - 1;
	//printf("basis = %lu\n", basis);
	//printf("nfigs = %lu, basis = %lu \n", n_figs, basis);
	while (is_end == 0)
	{
		ft_next_sadic_number(arr, n_figs, basis, &is_end);
		//if (array_has_povtors(arr, n_figs) == 0)
		//{
			ft_int_array_to_coords(arr, coords, n_figs, field_size);
			if (ft_check(figs, n_figs, coords, field_size) == 1)
				break ;
		//}
		//printf("%lu\n", arr[5]);
	}
	if (is_end == 0)
	{
		if (DEBUG_TEST_SIZE == 1)
		{
			i_arr = 0;
			printf("Test_size found this array: ");
			while (i_arr < n_figs)
			{
				printf("(%d, %d)\t", coords[i_arr].x, coords[i_arr].y);
				i_arr++;
			}
			printf("\n");
		}
		return (1);
	}
	else
		return (0);
}
*/
