#include "inc.h"

static int	my_atoi(char *str)
{
	int tmp;

	tmp = 0;
	while (*str >= '0' && *str <= '9')
	{
		tmp = tmp * 10 + *str - '0';
		str++;
	}
	return (tmp);
}

char		get_char(int num)
{
	char	tmp;

	if (num < 10)
		tmp = num + '0';
	else if (num == 10)
		tmp = 'a';
	else if (num == 11)
		tmp = 'b';
	else if (num == 12)
		tmp = 'c';
	else if (num == 13)
		tmp = 'd';
	else if (num == 14)
		tmp = 'e';
	else if (num == 15)
		tmp = 'f';
	return (tmp);
}	

void		print_hex(int num)
{
	char	tmp;

	tmp = 0;
	if (num == 0)
		return ;
	tmp = get_char(num % 16);
	print_hex(num /= 16);
	write(1, &tmp, 1);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		print_hex(my_atoi(argv[1]));
	}
	write(1, "\n", 1);
}
