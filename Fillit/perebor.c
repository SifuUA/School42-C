#include "inc.h"

void	ft_next_sadic_number(size_t *arr, size_t arr_len, size_t basis, int *its_zero)
{
	//Например: (при basis == 10)
	//0000 => 0001
	//0009 => 0010
	//9999 => 0000 (и its_zero = 1)
	size_t		i;
	int			plus1;

	(*its_zero) = 0;
	i = arr_len - 1;
	plus1 = 1;
	while (plus1 != 0)
	{
		arr[i]++;
		if (arr[i] == basis)
			arr[i] = 0;
		else
			plus1 = 0;
		if (plus1 == 1)
		{
			if(i > 0)
				i--;
			else
			{
				(*its_zero) = 1;
				plus1 = 0;
			}
		}
	}
	/*
	i = 0;
	while (i < arr_len)
		ft_putnbr(arr[i++]);
		*/
}

void ft_switch_sizet(size_t *a, size_t *b)
{
	size_t	buf;

	buf = (*a);
	(*a) = (*b);
	(*b) = buf;
}

void	ft_next_perestanovka(size_t *arr, size_t basis, int *its_zero)
{
	//Например: (при basis == 5)
	//01234 => 01243
	//43210 => 01234
	//ВАЖНО: в этой функции (в отличие от предыдущей) мы подразумеваем, 
	//												что basis == arr_len
	//
	size_t		i;
	size_t		m;
	size_t		j1;
	size_t		j2;

	(*its_zero) = 0;
	i = basis - 1;
	while (i > 0)
	{
		if (arr[i] > arr[i - 1])
			break ;
		else i--;
	}
	i--;
	if (i == (size_t)(0 - 1))
		(*its_zero) = 1;
	m = basis - 1;;
	while (m > i)
	{
		if (arr[m] > arr[i])
			break ;
		m--;
	}
	ft_switch_sizet(&(arr[m]), &(arr[i]));
	j1 = i + 1;
	j2 = basis - 1;
	while (j1 < j2)
		ft_switch_sizet(&(arr[j1++]), &(arr[j2--]));
}

void ft_int_array_to_coords(size_t *arr, t_point *coords, size_t arr_len, size_t field_size)
{
	size_t	i;

	i = 0;
	while (i < arr_len)
	{
		coords[i].x = arr[i] % field_size;
		coords[i].y = arr[i] / field_size;
		i++;
	}
}
