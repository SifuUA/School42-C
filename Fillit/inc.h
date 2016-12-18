#ifndef INC_H
# define INC_H
# include "libft.h"
# include <stdio.h>

char   **get_figure_from_string(char *s);
void    ft_arr_putstr(char **str);

typedef struct	s_point{
	int		x;
	int		y;
}				t_point;

typedef t_point	t_figure[4];

void    ft_next_sadic_number(size_t *arr, size_t arr_len, size_t basis, int *its_zero);
void    ft_next_perestanovka(size_t *arr, size_t basis, int *its_zero);
int     ft_check(t_figure *figures, size_t nfigures, t_point *coords, size_t field_size);
int     check_two_figures(t_figure fig1, t_figure fig2, t_point pt1, t_point pt2);
int     ft_check_figure(t_figure fig, size_t field_size);
void    norm_figure(t_figure a);
int		min_size(void);
int     test_size(size_t field_size, t_point *coords, t_figure *figs, size_t n_figs);
void	ft_int_array_to_coords(size_t *arr, t_point *coords, size_t arr_len, size_t field_size);
void 	read_figure(char *s, t_figure a);
char    **array_of_figure(size_t field_size);
void    print_answer(char **answer, t_point *top_of_figure, t_figure *figures, size_t n_figs);
/* 
*Например:
 ##..
 .##.
 ....
 ....

 (0,0)
 (1,0)
 (1,1)
 (2,1)
 */

/*
 * Потом:
t_point*	figures;
figures = malloc (n*sizeof(t_figure));
i = 0;
while (i < n)
{
	figures[i] = get_figure_from_string(char *s);
	(Где s будет строкой вида "##..\n.##.\n....\n....")
}
*/

/*
 *План ввода:
 1) Разбивание строки на отдельные квадратики 4х4
 2) Чтение фигуры из отдельного квадратика
 3) Создание массива фигур (внутри нее будут вызываться функции 1 и 2)
 * */

#endif
