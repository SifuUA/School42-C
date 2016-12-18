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

		answer[0].x = 0;
		answer[0].y = 0;

		answer[1].x = 1;
		answer[1].y = 0;
		
		answer[2].x = 1;
		answer[2].y = 2;

		answer[3].x = 3;
		answer[3].y = 2;
		
		answer[4].x = 0;
		answer[4].y = 4;


	printf ("*****************************\n");
	
	printf("before answ1\n");
	char **answ1=array_of_figure(9);
	printf("after answ1\n");

	print_answer(answ1, answer, f_arr, 5);
	//ft_arr_putstr(array_of_figure(a, i));
		//int n_f = i;//Количество фигур
	//	t_point *answer;
	//	answer = (t_point*)malloc(n_f * sizeof(t_point));
	//	int size = min_size();
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
