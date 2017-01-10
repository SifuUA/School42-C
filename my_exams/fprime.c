#include "inc.h"

void	fprime(int num)
{
	int i;

	i = 2;
	if (num == 1)
	{
		printf("1");
		return ;
	}
	else if (num < 1)
		return ;
	while (i <= num)
	{
		if (num % i == 0)
		{
			printf("%d", i);
			if (i == num)
				return ;
			printf("*");
			num = num / i;
			i = 1;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
}
