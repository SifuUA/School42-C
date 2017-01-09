#include "inc.h"

int     *ft_rrange1(int start, int end, int *array)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = start;
	while (tmp != end)
	{
		i++;
		tmp++;
	}
	array = (int *)malloc(sizeof(int) * i);
	i = 0;
	while(start <= end)
	{
		array[i] = start;
		i++;
		start++;
	}
	return(array);
}
int     *ft_rrange2(int start, int end, int *array)
{
	int		tmp;
	int		i;

	tmp = end;
	while (tmp <= start)
	{
		i++;
		tmp++;
	}
	array = (int *)malloc(sizeof(int) * i);
	i = 0;
	while(end <= start)
	{
		array[i] = end;
		i++;
		end++;
	}
	return(array);
}

int     *ft_rrange(int start, int end)
{
	int		*array;

	array = (int *)malloc(sizeof(int) * 1);
	*array = start;
	if (start < end)
		return (ft_rrange1(start, end, array));
	else if (end < start)
		return (ft_rrange2(start, end, array));
	return (array);
}
int		main(void)
{
	int	*a = ft_rrange(5,5);
	int i = 0;
	while (i < 4)
	{
		printf("%d\n", a[i]);
		i++;
	}
}
