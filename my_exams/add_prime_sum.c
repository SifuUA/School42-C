#include <stdio.h>
#include <unistd.h>

void	print_num(int num)
{
	int tmp;
	if (num > 9)
	{
		print_num(num / 10);
		print_num(num % 10);
	}
	else
	{
		tmp = num + '0';
		write (1, &tmp, 1);
	}
}

int		my_atoi(char *str)
{
	int	znak;
	int num;

	num = 0;
	znak = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		str++;
		znak = -znak;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num * znak);
}
int		prime(int count)
{
	int i;

	i = 2;
	if (count == 1)
		return (0);
	if (count == 2)
		return (1);
	while (i < count && i < 46341)
	{
		if (count % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		sum(int num)
{
	int tmp;
	int	count;

	tmp = 0;
	count = 1;
	while (count <= num)
	{
		if (prime(count) == 1)
			tmp = tmp + count;
		count++;
	}
	return (tmp);
}

int		main(int argc, char **argv)
{		
	if (argc == 2)
	{
		print_num(sum(my_atoi(argv[1])));	
	}
	else
		print_num(0);
	write (1, "\n", 1);
}
