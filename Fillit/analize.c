#include "inc.h"

size_t min_size(size_t n_figs)
{
	size_t	res;
	size_t	n_cells;

	n_cells = n_figs * 4;
	res = 2;
	while (res * res < n_cells)
		res++;
	return (res);
}

int     test_size(size_t field_size, t_figure *figs, size_t n_figs)
{
	size_t		y;
	size_t		x;
	char		**pt_arr;
	int			is_ok;

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

	if (DEBUG_TEST_SIZE == 1) printf("test_size: before recur_func\n");
	is_ok = recur_func(pt_arr, figs, n_figs, field_size);
	if (DEBUG_TEST_SIZE == 1) printf("test_size: after recur_func\n");
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

t_point	get_possible_field(char** pt_arr, t_figure fig, size_t field_size)
{
	t_point		res;
	size_t		x;
	size_t		y;
	size_t		i_pt_in_fig;

	y = 0;
	while (y < field_size)
	{
		x = 0;
		while (x < field_size)
		{
			i_pt_in_fig = 0;
			while (i_pt_in_fig < 4)
			{
				size_t y1 = y + (size_t)fig[i_pt_in_fig].y;
				size_t x1 = x + (size_t)fig[i_pt_in_fig].x;
				if (x1 >= field_size || y1 >= field_size)
					break ;
				if (DEBUG_GET_POSSIBLE_FIELD == 1) printf("get_possible_field: x1 = %lu, y1 = %lu\n", x1, y1);
				if (pt_arr[y1][x1] != '.')
					break ;
				i_pt_in_fig++;
			}
			if (i_pt_in_fig == 4)
			{
				res.x = x;
				res.y = y;
				return (res);
			}
			x++;
		}
		y++;
	}
	res.x = -1;
	return (res);
}


void	put_figure_to_field(char **pt_arr, t_figure fig, size_t i_fig, t_point pt)
{
	int x;
	int y;
	size_t i_pt;
	size_t y0;
	size_t x0;
	char letter;

	x = 0;
	y = 0;
	i_pt = 0;
	letter = 'A' + i_fig;
	x0 = pt.x;
	y0 = pt.y;
	while (i_pt < 4)
	{
		x = fig[i_pt].x;
		y = fig[i_pt].y;
		pt_arr[y0 + y][x0 + x] = letter;
		i_pt++;
	}
}

void	remove_figure_from_field(char **pt_arr, t_figure fig, t_point pt)
{
	int x;
	int y;
	size_t i_pt;
	size_t y0;
	size_t x0;

	x = 0;
	y = 0;
	i_pt = 0;
	x0 = pt.x;
	y0 = pt.y;
	while (i_pt < 4)
	{
		x = fig[i_pt].x;
		y = fig[i_pt].y;
		pt_arr[y0 + y][x0 + x] = '.';
		i_pt++;
	}

}

int		recur_func(char **pt_arr, t_figure *figs, size_t n_figs, size_t field_size)
{
	size_t	i_fig;
	int		is_ok;
	t_point	possible_field;
	int		vse_figurki_postavleni;

	vse_figurki_postavleni = 1;
	is_ok = 0;
	i_fig = 0;
	while (i_fig < n_figs && is_ok != 1)
	{
		if (DEBUG_RECUR_FUNC == 1) printf("recur_func: i_fig = %lu\n", i_fig);
		if(figurka_postavlena(pt_arr, i_fig) == 0)
		{
			vse_figurki_postavleni = 0;
			possible_field = get_possible_field(pt_arr, figs[i_fig], field_size);
			if (DEBUG_RECUR_FUNC == 1) printf("recur_func: possible_field = (%d, %d)\n",
					possible_field.x, possible_field.y);
			if(possible_field.x != -1)
			{
				put_figure_to_field(pt_arr, figs[i_fig], i_fig, possible_field);
				is_ok = recur_func(pt_arr, figs, n_figs, field_size);
				if (is_ok == 1)
					break;
				else
				{
					remove_figure_from_field(pt_arr, figs[i_fig], possible_field);
				}
			}
		}
		i_fig++;
	}
	if (DEBUG_RECUR_FUNC == 1) printf("recur_func: is_ok = %d\n", is_ok);
	if (vse_figurki_postavleni)
		is_ok = 1;
	return (is_ok);
}
