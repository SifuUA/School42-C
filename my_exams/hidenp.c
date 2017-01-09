#include "inc.h"

static int		len(char *a)
{
	int i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int		hidenp(char *a, char *b)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (a[i])
	{	
		while (b[j])
		{
			if (b[j] == a[i])
			{
				flag++;
				j++;
				break;
			}
		j++;
		}
	i++;
	}
	return (flag);
}


int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (hidenp(argv[1], argv[2]) == len(argv[1]))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}
