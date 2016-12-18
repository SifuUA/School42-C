#include "inc.h"

int			main(int argc, char **argv)
{
	//t_figure *a;
	//a[0].x = 5;
	//a[3].y = 7;
	
	t_figure	*f_arr;
	int			n_f;

	if (argc != 2)
		ft_putstr("error\n");
	else
	{
		
		char *s = get_s_from_file(argv[1]);
		printf("%c\n", s[0]);
		printf("*************\n");
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
			int j = 0;
			printf("Figure %d:\n%s\n", i, arr[i]);
			while (j < 4)
			{
				printf("(%d,%d)", f_arr[i][j].x, f_arr[i][j].y);
				if (j < 3) printf(" - ");
				else printf("\n");
				j++;
			}
			i++;
		}
		t_point *answer;
		answer = (t_point*)malloc(n_f * sizeof(t_point));

		printf("Creating answer\n");
		/*
		int arr_len = 10;
		size_t *arr = (size_t*)malloc(arr_len * sizeof(size_t));

		int i = 0;
		while (i < arr_len)
		{
			arr[i] = i;
			i++;
		}
		int its_zero = 0;
		while (its_zero == 0)
		{
			i = 0;
			while (i < arr_len)
				printf("%lu", arr[i++]);
			printf("\n");
			//ft_next_sadic_number(arr, arr_len, arr_len, &its_zero);
			ft_next_perestanovka(arr, arr_len, &its_zero);
		}
		*/
	//ft_arr_putstr(array_of_figure(a, i));
	size_t size = 2;
	int	is_ok = 0;
	while (is_ok == 0)
	{
		printf("Testing size %lu\n", size);
		is_ok = test_size (size, answer, f_arr, n_f);
		if (is_ok == 0)
			size++;
	}
	char **answ1 = array_of_figure(size);
	print_answer(answ1, answer, f_arr, n_f);
	//	test_size(size, answer, is_ok);//Длинная рекурсивная функция, работающая по принципу судоку
	//	if (is_ok == 1)
			//все найдено, выводим ответ
	//	else
	//	{
	//		size++;
	//		test_size(size, answer, is_ok);
	//	}
	}
	//Задача Леше:
	//1) Придумать такой массив АНСВЕР, который содержит непересекающиеся фигурки из файла "01.тхт" (массив не обязательно оптимальный, можно взять при size = 8)
	//2) Написать функцию print_answer, которая будет по массиву answer выпечатывать ответ программы. Пример:
	//Фигуры: 
	//	(0,0) - (0,1) - (0,2) - (0,3)
	//	(2,1) - (3,1) - (1,2) - (2,2)
	//answer:
	//	(5,1) - (0,0)
	//Функция должна выдать:
	//......
	//..BB.A
	//...BBA
	//.....A
	//.....A
	//Прототип: print_answer(answer, figures, size);
}
