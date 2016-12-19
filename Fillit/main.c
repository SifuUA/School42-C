#include "inc.h"

int			main(int argc, char **argv)
{
	t_figure	*f_arr;
	int			n_f;

	if (argc != 2)
		ft_putstr("error\n");
	else
	{
		char *s = get_s_from_file(argv[1]);
		if (check(s) == 1)
			return (0);
		char **arr = get_figure_from_string(s);
		int i = 0;
		while (arr[i] != NULL)
			i++;
		n_f = i;
		f_arr = (t_figure*)malloc(n_f*sizeof(t_figure));
		i = 0;
		while (arr[i] != NULL)
		{
		    read_figure(arr[i], f_arr[i]);
			norm_figure(f_arr[i]);
			i++;
		}
		t_point *answer;
		answer = (t_point*)malloc(n_f * sizeof(t_point));
		size_t size = min_size(n_f);
		int	is_ok = 0;
		while (is_ok == 0)
		{
			is_ok = test_size (size, f_arr, n_f);
			if (is_ok == 0)
				size++;
		}
	}
}
