#include "inc.h"

static void my_putnbr(int num)
{
	int tmp;

	if (num > 9)
	{
		my_putnbr(num / 10);
		my_putnbr(num % 10);
	}
	else
	{
		tmp = num + '0';
		write (1, &tmp, 1);
	}
}

int			my_atoi(char *str)
{
	int	tmp;

	tmp = 0;
	while (*str >= '0' && *str <= '9')
		tmp = tmp * 10 + *(str++) - '0';
	return (tmp);
}

void		tab_mult(char *str)
{
	int i;
	int num;
	
	i = 1;
	num = my_atoi(str);
	while(i < 10)
	{
		my_putnbr(i);
		write(1, " x ", 3);
		my_putnbr(num);
		write(1, " = ", 3);
		my_putnbr(i * num);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(argv[1]);
	else
		write(1, "\n", 1);
}
