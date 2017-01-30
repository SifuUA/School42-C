#include <unistd.h>
#include <stdio.h>

int			   ft_strncmp(char *a, char *b, int c)
{
	while (*a && *b && c && *a == *b)
	{
		a++;
		b++;
		c--;
	}
	return (c != 0 ? 1 : 0);
}

int			   match_all(char **av, char *t, int len)
{
	int		   i = 1;
	int		   y = 0;
	
	while (av[i])
	{
		y = 0;
		while (av[i][y])
		{
			if (ft_strncmp(av[i] + y, t, len) == 0)
				break;
			y++;
		}
		if (!av[i][y])
			return (0);
		i++;
	}
	return (1);
}

int			   get_max_len(char **av, char *t)
{
	int		   len = 0;
	
	while (match_all(av, t, len))
		len++;
	return (len - 1);
}

int			   main(int argc, char **argv)
{
	int		i;
	int		y;
	int		maxlen;
	char	*start;
	int		len;
	
	i =	1;
	y =	0;
	maxlen = -1;
	(void)argc;
	while (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			len = get_max_len(argv, argv[i] + y);
			if (len > maxlen)
			{
				maxlen = len;
				start = argv[i] + y;
			}
			y++;
		}
		i++;
	}
	if (start)
		write(1, start, maxlen);
	write(1, "\n", 1);
	return (0);
}
