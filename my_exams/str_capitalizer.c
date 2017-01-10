#include "inc.h"

void	to_small(char *str)
{
	while(*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
}

void	str_cap(char *str)
{
	int tmp;

	if (str[0] >= 'a' && str[0] <= 'z')
	{
		tmp = str[0] - 32;
		write(1, &tmp, 1);
		str++;
	}
	while(*str)
	{
		if (*str != ' ' && *(str - 1) == ' ')
		{	
			tmp = *str - 32;
			write(1, &tmp, 1);
		}
		else
			write(1, &*str, 1);
		str++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			to_small(argv[i]);
			str_cap(argv[i]);
			i++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
