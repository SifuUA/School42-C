#include "inc.h"

int					answer(char *str, int index)
{
	while(str[index])
	{	
		if (str[index] != ' ')
			return (1);
		index++;
	}
	return (0);
}

static int			len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void 		del_spaces(char *str)
{
	int i;

	i = len(str) - 1;
	while (str[i] == ' ' || str[i] == '\t')
		str[i] = '\0';
	while (*str == ' ' || *str == '\t')
		str++;
}

void		trepple(char *str)
{
	int i;

	i = 0;
	del_spaces(str);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			write(1, &str[i], 1);
		if (str[i] != ' ' && str[i + 1] == ' ' && answer(str, i + 1) == 1)
			write(1, "   ", 3);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		trepple(argv[1]);	
	}
	write(1, "\n", 1);
	return (0);
}
