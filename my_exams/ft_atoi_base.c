#include "inc.h"

int		chek(char c, int base)
{
	if (base <= 10)
	{
		if (c >= '0' && c <= '9')
			return (1);
	}
	else if ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) ||
	(c >= 'a' && c <= ('a' + base - 10)))
		return (1);
	return (0);
}

int    ft_atoi_base(const char *str, int str_base)
{
	int		znak;
	int		value;
	int		tmp;

	znak = 1;
	value = 0;
	tmp = 1;
	while (*str < 32)
			str++;
	if (*str == '-')
	{
		znak = -znak;
		str++;
	}
	while ((tmp = chek(*str, str_base) > 0) && *str)
	{
		if (*str >= 'A' && *str <= 'Z')
			value = value * str_base + (*str - 'A' + 10);
		else if (*str >= 'a' && *str <= 'z')
			value = value * str_base + (*str - 'a' + 10);
		else
			value = value * str_base + *str -  '0';
		str++;
	}
	return (value);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("123a", 10));
}

