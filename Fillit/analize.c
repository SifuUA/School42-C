#include "inc.h"

int		check_two_figures(t_figure fig1, t_figure fig2, t_point pt1, t_point pt2)
{
	size_t		i1;
	size_t		j1;

	i1 = 0;
	j1 = 0;
	while (i1 < 4)
	{
		while (j1 < 4)
		{
			if (fig1[i1].x + pt1.x == fig2[j1].x + pt2.x && 
					fig1[i1].y + pt1.y == fig2[j1].y + pt2.y)
				return (0);
			j1++;
		}
		i1++;
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
		if (ft_check_figure(figures[i], field_size) == 0)
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

int		ft_check_figure(t_figure fig, size_t field_size)
{
	size_t	i_pt;
	int		x;
	int		y;

	i_pt = 0;
	while (i_pt < 4)
	{
		x = fig[i_pt].x;
		y = fig[i_pt].y;
		if (x < 0 || x >= (int)field_size)
			return (0);
		if (y < 0 || y >= (int)field_size)
			return (0);
		i_pt++;
	}
	return (1);
}

int		test_size(size_t field_size, t_point *coords, t_figure *figs, size_t n_figs)
{
	size_t	*arr;
	size_t	i_arr;
	int		is_end;
	size_t	basis;

	arr = (size_t*)malloc(n_figs * sizeof(size_t));
	i_arr = 0;
	while (i_arr < n_figs)
		arr[i_arr++] = 0;
	is_end = 0;
	basis = (field_size - 2) * (field_size - 2) + 1;
	//printf("nfigs = %lu, basis = %lu \n", n_figs, basis);
	while (is_end == 0)
	{
		/*
		i_arr = 0;
		while (i_arr < n_figs)
			printf("%lu", arr[i_arr++]);
		printf("\n");
		*/
		ft_next_sadic_number(arr, n_figs, basis, &is_end);
		//printf("test_size: after next_sadic_number\n");
		ft_int_array_to_coords(arr, coords, n_figs, field_size);
		//printf("test_size: after int_array_to_coords\n");
		if (ft_check(figs, n_figs, coords, field_size) == 1)
			break ;
		//printf("test_size: after ft_check\n");
	}
	if (is_end == 0)
		return (1);
	else
		return (0);
}
