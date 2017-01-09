#include "inc.h"

int		pgcd(char *a, char *b)
{
	int 	num1;
	int 	num2;
	int 	i;
	int		tmp;
	int 	max;

	i = 1;
	tmp = 0;
	num1 = atoi(a);
	num2 = atoi(b);
	if (num1 > num2)
		max = num2;
	else
		max = num1;
	while (i <= max)
	{
		if (num1 % i == 0 && num2 % i == 0)
			tmp = i;
		i++;
	}
	return (tmp);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%d", pgcd(argv[1], argv[2]));			
	}
	printf("\n");
}
