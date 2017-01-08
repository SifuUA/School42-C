#include "inc.h"

int		lenth(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	epur_str(char *str)
{
	int 	i;
	int		len;

	i = 0;
	len = lenth(str);
	while (str[len] == ' ' || str[len] == '\t')
		str[len] = '\0';
		len--;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		if (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0')
		{
			write(1, " ", 1);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		epur_str(argv[1]);		
	}
	write(1, "\n", 1);
}
