#include "inc.h"

char	*convert_to_low(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

void	capitalizer(char *str)
{
	int i;
	int	tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
		{
				tmp = str[i] - 32;
				write(1, &tmp, 1);
		}
		else 
			write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		capitalizer(convert_to_low(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
