#include "brainfuck.h"

char	*brainfuck(char **str, char *p)
{	
	char	*ptr;
	int		i;

	i = 0;
	while (*p != 0 && *p != ']')
	{
		if (*p == '>')
			(*str)++;
		else if (*p == '<')
			(*str)--;
		else if (*p == '+')
			(**str)++;
		else if (*p == '-')
			(**str)--;
		else if (*p == '.')
			write(1, *str, 1);
		else if (*p == '[')
		{
			if (**str == 0)
			{
				while (1)
				{
					if ((*p) == '[')
						i++;
					if ((*p) == ']')
						i--;
					if (i <= 0)
						break;
					p++;
				}
			}
			else
			{
				ptr = brainfuck(str, p + 1);
				if (ptr != NULL)
					p = ptr;
				else
					p--;
			}
		}
		p++;
	}
	if (**str == 0)
		return (p);
	return (NULL);
}

int		main(int argc, char **argv)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * 5000);
	while (i < 5000)
	{
		str[i] = '\0';
		i++;
	}
	if (argc == 2)
		brainfuck(&str, argv[1]);
	else
		write(1, "\n", 1);
}
