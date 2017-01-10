#include "inc.h"

static void	my_putnbr(int a)
{
	int tmp;

	if (a > '9')
	{
		my_putnbr(a / 10);
		my_putnbr(a % 10);
	}
	else
	{
		tmp = a + '0';
		write(1, &tmp, 1);
	}
}

int			main(int argc, char **argv)
{
	if (argc > 1)
	{
		my_putnbr(argc - 1);
	}
	write(1, "\n", 1);
}
