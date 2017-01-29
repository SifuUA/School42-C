#include "inc.h"

void			conv_num(unsigned int value, int base, char **ptr)
{
	char	c;

	if(value >= base)
	{
		conv_num(value / base, base, ptr);
		conv_num(value % base, base, ptr);
	}
	else
	{
		if (value > 9)
			c = value + 'A' - 10;
		else
			c = value + '0';
		**ptr = c;
		(*ptr)++;
	}
	**ptr = '\0';
}

char    		*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*ptr;
	
	str = (char *)malloc(sizeof(char) * 33);
	ptr = str;
	*str = 0;
	if(value < 0)
	{
		if (base == 10)
		{
			*str = '-';
			str++;
		}
		value = -value;
	}
	if (base < 2 || base > 16)
		return (str);
	conv_num((unsigned int)value, base, &str);
	return (ptr);
}

int		main(void)
{
	printf("%s\n", ft_itoa_base(-2147483648, 10));
}
